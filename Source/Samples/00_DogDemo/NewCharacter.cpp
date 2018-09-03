#include <Urho3D/Core/Context.h>
#include <Urho3D/Graphics/AnimationController.h>
#include <Urho3D/IO/MemoryBuffer.h>
#include <Urho3D/Physics/PhysicsEvents.h>
#include <Urho3D/Physics/PhysicsWorld.h>
#include <Urho3D/Physics/RigidBody.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Graphics/Geometry.h>
#include <Urho3D/Graphics/VertexBuffer.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Physics/CollisionShape.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/AnimatedModel.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Graphics/OctreeQuery.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/Skeleton.h>
#include <Lightning.h>

#include "NewCharacter.h"

NewCharacter::NewCharacter(Context* context) :
	LogicComponent(context),
	onGround_(false),
	okToJump_(true),
	inAirTimer_(0.0f) {
	// Only the physics update event is needed: unsubscribe from the rest for optimisation
	SetUpdateEventMask(USE_FIXEDUPDATE);
}

void NewCharacter::RegisterObject(Context* context) {
	context->RegisterFactory<NewCharacter>();

	// These macros register the class attributes to the Context for automatic load / save handling.
	// We specify the Default attribute mode which means it will be used both for saving into file, and network replication
	URHO3D_ATTRIBUTE("Controls Yaw", float, controls_.yaw_, 0.0f, AM_DEFAULT);
	URHO3D_ATTRIBUTE("Controls Pitch", float, controls_.pitch_, 0.0f, AM_DEFAULT);
	URHO3D_ATTRIBUTE("On Ground", bool, onGround_, false, AM_DEFAULT);
	URHO3D_ATTRIBUTE("OK To Jump", bool, okToJump_, true, AM_DEFAULT);
	URHO3D_ATTRIBUTE("In Air Timer", float, inAirTimer_, 0.0f, AM_DEFAULT);
}

void NewCharacter::Start() {
	// Component has been inserted into its scene node. Subscribe to events now
	SubscribeToEvent(GetNode(), E_NODECOLLISION, URHO3D_HANDLER(NewCharacter, HandleNodeCollision));

	// Find the model adjustment node, don't do it recursively (should be top level)
	modelAdjustmentNode_ = node_->GetChild("AdjNode", false);

	Lightning::RegisterObject(context_);
}


void NewCharacter::FixedUpdate(float timeStep) {
	/// \todo Could cache the components for faster access instead of finding them each frame
	auto* body = GetComponent<RigidBody>();
	auto* animCtrl = node_->GetComponent<AnimationController>(true);

	// Update the in air timer. Reset if grounded
	if (!onGround_)
		inAirTimer_ += timeStep;
	else
		inAirTimer_ = 0.0f;
	// When character has been in air less than 1/10 second, it's still interpreted as being on ground
	bool softGrounded = inAirTimer_ < INAIR_THRESHOLD_TIME;

	// Update movement & animation
	//const Quaternion& rot = node_->GetRotation();
	Vector3 moveDir = Vector3::ZERO;
	const Vector3& velocity = body->GetLinearVelocity();
	// Velocity on the XZ plane
	Vector3 planeVelocity(velocity.x_, 0.0f, velocity.z_);

	if (controls_.IsDown(CTRL_FORWARD))
		moveDir += Vector3::FORWARD;
	if (controls_.IsDown(CTRL_BACK))
		moveDir += Vector3::BACK;
	if (controls_.IsDown(CTRL_LEFT))
		moveDir += Vector3::LEFT;
	if (controls_.IsDown(CTRL_RIGHT)) {
		moveDir += Vector3::RIGHT;
	}
	if (controls_.IsDown(CTRL_SPRINT)) {
		//isSprinting = true;
		MOVE_FORCE = SPRINT_FORCE;
		ACCELERATION_FRICTION = SPRINT_FRICTION;
		MAX_SPEED = MAX_SPRINT_SPEED;
	} else {
		//isSprinting = false;
		MOVE_FORCE = WALK_FORCE;
		ACCELERATION_FRICTION = WALK_FRICTION;
		MAX_SPEED = MAX_WALK_SPEED;
	}


	// Normalize move vector so that diagonal strafing is not faster
	if (moveDir.LengthSquared() > 0.0f)
		moveDir.Normalize();

	// If in air, allow control, but slower than when on ground - using tertiary syntax
	//body->ApplyImpulse(rot * moveDir * (softGrounded ? MOVE_FORCE : INAIR_MOVE_FORCE));
	body->ApplyForce(moveDir * (softGrounded ? MOVE_FORCE : INAIR_MOVE_FORCE));

	// If we're trying to move, lower the friction
	if (moveDir != Vector3::ZERO) {
		body->SetFriction(ACCELERATION_FRICTION);
	} else {
		body->SetFriction(BRAKING_FRICTION);
	}


	Vector3 forwardCurrent = node_->GetRotation() * Vector3::FORWARD;

	// Lerp between current and target (move dir, kinda) using time since last "turn". Capped at 1.0 using that tertiary expression
	if (planeVelocity.Length() > 0.0f && moveDir != Vector3::ZERO) {
		if (moveDir.Equals(lastMoveDir)) {
			deltaSinceLastTurn += deltaSinceLastTurn > 1.0f ? 0.0f : timeStep;
		} else {
			if (moveDir.Equals(lastMoveDir * -1)) {
				// Rotate CW just a tiny bit to assist the LERP (1°)
				//forwardCurrent = Quaternion(1, Vector3(0.0, 1.0, 0.0)) * forwardCurrent;
				//body->ApplyImpulse(Vector3(0.0, 40.0, 0.0));
			}
			deltaSinceLastTurn = 0.0f;
		}
		lastMoveDir = (moveDir == Vector3::ZERO) ? lastMoveDir : moveDir;

		// 90° sideways? Could be nice to have some rolling about the feet to change direction
		//Vector3 sideVector = Vector3(-moveDir.z_, moveDir.y_, moveDir.x_);
		//Vector3 newUp = Vector3(sideVector).Lerp(node_->GetRotation() * Vector3::UP, timeStep);
		node_->LookAt(node_->GetPosition() + forwardCurrent.Lerp(moveDir, 10.0f * timeStep), /*newUp*/node_->GetRotation() * Vector3::UP); // Could simply use World::UP
	}


	// Calculate the rotation angle for that thing that animals do to keep their centre of gravity (genauso wie Overgrowth)
	// 45° * difference between accel and velo vectors, unless we're STATIONARY OR CLOSE ENOUGH 
	if (moveDir != Vector3::ZERO || moveDir.AbsDotProduct(planeVelocity.Normalized()) < 0.98f) {
		// Figure out which "side" we're on
		signRotCoM = Sign(moveDir.CrossProduct(planeVelocity.Normalized()).y_);
		// Hit max CoM compensation angle at 24u/s, any more and ignore
		speedFactorCoM = Max(Min(1 / (MAX_SPRINT_SPEED - planeVelocity.Length()), 1.0f), 0.0f);
		modelAdjustmentNode_->SetRotation(
			modelAdjustmentNode_->GetRotation().Slerp(
				Quaternion(signRotCoM * speedFactorCoM * 35 * (1 - moveDir.DotProduct(planeVelocity.Normalized())), modelAdjustmentNode_->GetRotation() * Vector3::FORWARD)
				, 15.0f * timeStep)
		);
	} else {
		if (modelAdjustmentNode_->GetRotation().DotProduct(Quaternion::IDENTITY) < 0.99f) {
			modelAdjustmentNode_->SetRotation(modelAdjustmentNode_->GetRotation().Slerp(Quaternion::IDENTITY, 5.0f * timeStep));
		} else {
			modelAdjustmentNode_->SetRotation(Quaternion::IDENTITY);
		}
	}
	//modelAdjustmentNode_->SetRotation(Quaternion(modelAdjustmentNode_->GetRotation().Angle() + timeStep * 30, modelAdjustmentNode_->GetRotation() * Vector3::FORWARD));

	// LIGHTNING STUFF
	if (planeVelocity.Length() > 0) {
		// If we're travelling faster than walking pace + a buffer (to stop lightning on near-run), ZAP
		if (planeVelocity.Length() > MAX_WALK_SPEED + 2.0f) {
			lightning_elapsedTime += timeStep;
			if (lightning_elapsedTime > 0.5f / planeVelocity.Length()) {
				//makeLightning();
				makeLightningBones();
				lightning_elapsedTime = 0.0f;
			}
		}
	}

	if (softGrounded) {
		// When on ground, apply a braking force to limit maximum ground velocity
		//Vector3 brakeForce = -planeVelocity * BRAKE_FORCE * (planeVelocity.Length() / 16);
		//Vector3 brakeForce = -planeVelocity * (1 / (8 - planeVelocity.Length())) * BRAKE_FORCE;
		//body->ApplyImpulse(brakeForce);

		if (planeVelocity.Length() > MAX_SPEED) {
			body->ApplyForce(-planeVelocity * ARTIFICIAL_BRAKING_FORCE);
		}

		// Jump. Must release jump control between jumps
		if (controls_.IsDown(CTRL_JUMP)) {
			if (okToJump_) {
				body->ApplyImpulse(Vector3::UP * JUMP_FORCE);
				okToJump_ = false;
				//TODO make this a jump ani
				animCtrl->PlayExclusive("Beagle/Models/Walk.ani", 0, true, 1.0f);
				animCtrl->SetStartBone("Beagle/Models/Walk.ani", "Root");

				//DEBUG: ZAP
				//makeLightning();
			}
		} else {
			okToJump_ = true;
		}
	}

	if (!onGround_) {
		//TODO falling ani?
		animCtrl->PlayExclusive("Beagle/Models/Walk.ani", 0, true, 0.1f);
		//animCtrl->SetStartBone("Beagle/Models/Walk.ani", "Root");
	} else {
		// Play walk animation if moving on ground, otherwise fade it out
		if (softGrounded && !moveDir.Equals(Vector3::ZERO)) {
			if (planeVelocity.Length() < WALK_TO_SPRINT_SPEED_ANIM) {
				animCtrl->PlayExclusive("Beagle/Models/Walk.ani", 0, true, 0.1f);
			} else {
				animCtrl->PlayExclusive("Beagle/Models/Run.ani", 0, true, 0.2f);
			}
		} else {
			animCtrl->PlayExclusive("Beagle/Models/IdleLoop.ani", 0, true, 0.5f);
			//animCtrl->SetStartBone("Beagle/Models/IdleLoop.ani", "Root");
		}

		// Set walk animation speed proportional to velocity
		animCtrl->SetSpeed("Beagle/Models/Walk.ani", planeVelocity.Length() * 0.55f);
		animCtrl->SetSpeed("Beagle/Models/Run.ani", planeVelocity.Length() * 0.1f);
	}

	// Reset grounded flag for next frame
	onGround_ = false;
}

void NewCharacter::HandleNodeCollision(StringHash eventType, VariantMap& eventData) {
	// Check collision contacts and see if character is standing on ground (look for a contact that has near vertical normal)
	using namespace NodeCollision;

	MemoryBuffer contacts(eventData[P_CONTACTS].GetBuffer());

	while (!contacts.IsEof()) {
		Vector3 contactPosition = contacts.ReadVector3();
		Vector3 contactNormal = contacts.ReadVector3();
		/*float contactDistance = */contacts.ReadFloat();
		/*float contactImpulse = */contacts.ReadFloat();

		// If contact is below node center and pointing up, assume it's a ground contact
		if (contactPosition.y_ < (node_->GetPosition().y_ + 1.0f)) {
			float level = contactNormal.y_;
			if (level > 0.75)
				onGround_ = true;
		}
	}
}


void NewCharacter::makeLightning() {
	PODVector<RayQueryResult> results;
	Vector3 surfacePoint;
	Vector3 targetPos = Vector3::ZERO;
	bool hitSomethingOtherThanDoggy = false;
	int maxTries = 5;
	int attempts = 0;


	Node* adjNode = node_->GetChild("AdjNode");

	while (results.Size() < 1 || !hitSomethingOtherThanDoggy) {
		// Could square this to bias it toward the far end? Maybe
		Vector3 dirVec = Vector3(Random(-1.0f, 1.0f), Random(-1.0f, 1.0f), Random(-1.0f, 1.0f)) * 3.0f;

		// Get random vertex
		{
			// Get a random surface point
			//Model* model = node_->GetComponent<AnimatedModel>()->GetModel();
			//Geometry* geom = model->GetGeometry(0, 0);
			Geometry* geom = ((AnimatedModel*)adjNode->GetComponent<AnimatedModel>())->GetLodGeometry(0, 0);

			const unsigned char* vertexData;
			const unsigned char* indexData;
			unsigned vertexSize;
			unsigned indexSize;
			const PODVector<VertexElement>* elements;

			geom->GetRawData(vertexData, vertexSize, indexData, indexSize, elements);

			// If data is bad:
			if (!vertexData || !elements || VertexBuffer::GetElementOffset(*elements, TYPE_VECTOR3, SEM_POSITION) != 0) {
				return;
			}
			const auto* vertices = (const unsigned char*)vertexData;



			// 16-bit indices ; short
			if (vertexSize != sizeof(unsigned short)) {
				//surfacePoint = *(Vector3*)(&vertices[(short)Random(0, (int)vertexSize)]);
				surfacePoint = *(Vector3*)(&vertices[0]);
				//surfacePoint = Vector3(0.0f, 3.23084f, -7.89709f);

				// Centre to surfacepoint, plus some random angle
				//dirVec = (surfacePoint.Normalized() + dirVec);
				//dirVec.Normalize();

				// Rotate
				surfacePoint = adjNode->GetWorldRotation() * surfacePoint;
				// Scale
				surfacePoint *= adjNode->GetWorldScale();
				// Position
				surfacePoint = surfacePoint + adjNode->GetWorldPosition();

			}
		}


		Ray ray = Ray(surfacePoint, dirVec);
		RayOctreeQuery query(results, ray, Urho3D::RAY_TRIANGLE, dirVec.Length(), Urho3D::DRAWABLE_GEOMETRY, -1);
		node_->GetScene()->GetComponent<Urho3D::Octree>()->Raycast(query);

		for (RayQueryResult result : results) {
			if (result.node_->GetName().Compare("AdjNode") != 0) {
				targetPos = result.position_;
				hitSomethingOtherThanDoggy = true;
				break;
			}
		}

		attempts++;
		if (attempts > maxTries) {
			return;
		}
	}


	// This may be unnecessary
	//int i = 0;
	//int closestIdx = 0;
	//float shortestDist = results.At(0).distance_;
	//for (RayQueryResult result : results) {
	//	if (result.distance_ < shortestDist) {
	//		shortestDist = result.distance_;
	//		closestIdx = i;
	//	}
	//	i++;
	//}

	//Vector3 targetPos = results.At(closestIdx).position_;


	Node* objectNode = GetScene()->CreateChild("LightningBolt");

	// Should work with local space
	objectNode->SetPosition(surfacePoint);

	Lightning* lightning_ = objectNode->CreateComponent<Lightning>();
	lightning_->Start();
	lightning_->setLifeTime(0.1f);
	lightning_->setTarget(targetPos);
	lightning_->extendToPoint();
}

void NewCharacter::makeLightningBones() {
	PODVector<RayQueryResult> results;
	Vector3 bonePoint;
	Vector3 bonePointWorld;
	Node* boneChosen;

	Vector3 targetPos = Vector3::ZERO;
	bool hitSomethingOtherThanDoggy = false;
	int maxTries = 5;
	int attempts = 0;


	Node* adjNode = node_->GetChild("AdjNode");

	while (results.Size() < 1 || !hitSomethingOtherThanDoggy) {
		// Could square this to bias it toward the far end? Maybe
		//Vector3 dirVec = Vector3(Random(-1.0f, 1.0f), Random(-1.0f, 1.0f), Random(-1.0f, 1.0f)) * 5.0f;
		Vector3 dirVec = Vector3(Random(-1.0f, 1.0f), Random(-1.0f, 1.0f), Random(-1.0f, 1.0f)) * 0.25f;

		// Get random bone
		{
			Vector<Bone> boneList = adjNode->GetComponent<AnimatedModel>()->GetSkeleton().GetBones();

		boneLoop:
			{
				boneChosen = boneList.At(Random(0, boneList.Size() - 1)).node_;
				String boneName = boneChosen->GetName();

				// DO NOT pick any Poles, roots, or tail-bones (unless tail-tip)
				if (boneName.Contains("Pole", false) || boneName.Compare("Root", false) == 0) {
					goto boneLoop;
				} else if (boneName.Contains("Tail", false) && !boneName.Contains("Tip", false)) {
					goto boneLoop;
				}
			}

			bonePointWorld = boneChosen->GetWorldPosition();
			bonePoint = boneChosen->GetPosition();

			// Test: dirVec is bone relative to root + 1y, but slightly random
			dirVec = (dirVec + (Vector3(0, -1, 0) + bonePointWorld - node_->GetWorldPosition()).Normalized()).Normalized() * 5.0f;
		}



		Ray ray = Ray(bonePointWorld, dirVec);
		RayOctreeQuery query(results, ray, Urho3D::RAY_TRIANGLE, dirVec.Length(), Urho3D::DRAWABLE_GEOMETRY, -1);
		node_->GetScene()->GetComponent<Urho3D::Octree>()->Raycast(query);

		for (RayQueryResult result : results) {
			if (result.node_->GetName().Compare("AdjNode") != 0) {
				targetPos = result.position_;
				hitSomethingOtherThanDoggy = true;
				break;
			}
		}

		attempts++;
		if (attempts > maxTries) {
			return;
		}
	}


	//Node* objectNode = boneChosen->CreateChild("LightningBolt");
	//objectNode->SetPosition(Vector3::ZERO);

	Node* objectNode = GetScene()->CreateChild("LightningBolt");
	objectNode->SetPosition(bonePointWorld);


	Lightning* lightning_ = objectNode->CreateComponent<Lightning>();
	lightning_->Start();
	lightning_->setLifeTime(0.1f);
	lightning_->setTarget(targetPos);
	lightning_->extendToPoint();
}