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
#include <Urho3D/Graphics/DrawableEvents.h>

#include <Urho3D/Graphics/ParticleEffect.h>
#include <Urho3D/Graphics/ParticleEmitter.h>
#include <SelfDestructor.h>

#include <Lightning.h>

#include <NewCharacter.h>

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
	Lightning::RegisterObject(context_);
	SelfDestructor::RegisterObject(context_);
}

void NewCharacter::DelayedStart() {
	auto* cache = GetSubsystem<ResourceCache>();

	// Find the model adjustment node, don't do it recursively (should be top level)
	modelAdjustmentNode_ = node_->GetChild("AdjNode", false);
	SubscribeToEvent(modelAdjustmentNode_, E_ANIMATIONTRIGGER, URHO3D_HANDLER(NewCharacter, HandleAnimationTrigger));

	for (Bone bone : modelAdjustmentNode_->GetComponent<AnimatedModel>()->GetSkeleton().GetBones()) {
		if (bone.name_.Contains("PawIK", false)) {
			Node* particleNode = bone.node_->CreateChild();
			particleNode->SetName(bone.name_);

			SelfDestructor* destroyer = particleNode->CreateComponent<SelfDestructor>();
			destroyer->setTimer(0.1f);

			ParticleEmitter* particleEmitter = particleNode->CreateComponent<ParticleEmitter>();
			particleEmitter->SetEffect(cache->GetResource<ParticleEffect>("Particle/DustDog.xml"));
			particleEmitter->SetEmitting(true);
		}
	}

	// Create the zap node that fakes the lightning shadows
	/*Node* lightNode = node_->CreateChild();
	fakeShadowLightning = lightNode->CreateComponent<Light>();
	fakeShadowLightning->SetLightType(LIGHT_POINT);
	fakeShadowLightning->SetRange(10.0f);
	fakeShadowLightning->SetRadius(1.0f);
	fakeShadowLightning->SetCastShadows(true);
	fakeShadowLightning->SetColor(Color(1.0f, 1.0f, 0.8f));
	fakeShadowLightning->SetEnabled(false);*/
}

/*void NewCharacter::Update(float timeStep) {

}*/


void NewCharacter::FixedUpdate(float timeStep) {
	/// \todo Could cache the components for faster access instead of finding them each frame
	auto* body = GetComponent<RigidBody>();
	auto* animCtrl = node_->GetComponent<AnimationController>(true);

	// Load these anims
	if (!animCtrl->IsPlaying("Beagle/Models/RotateRight.ani")) {
		animCtrl->PlayExclusive("Beagle/Models/RotateRight.ani", 1, true, 0.0f);
		animCtrl->PlayExclusive("Beagle/Models/RotateLeft.ani", 1, true, 0.0f);
		animCtrl->SetBlendMode("Beagle/Models/RotateRight.ani", AnimationBlendMode::ABM_ADDITIVE);
		animCtrl->SetBlendMode("Beagle/Models/RotateLeft.ani", AnimationBlendMode::ABM_ADDITIVE);
		animCtrl->SetWeight("Beagle/Models/RotateRight.ani", 0.0f);
		animCtrl->SetWeight("Beagle/Models/RotateLeft.ani", 0.0f);
		animCtrl->SetRemoveOnCompletion("Beagle/Models/RotateRight.ani", false);
		animCtrl->SetRemoveOnCompletion("Beagle/Models/RotateLeft.ani", false);
	}

	// Update the in air timer. Reset if grounded
	if (!onGround_) {
		inAirTimer_ += timeStep;
	} else {
		inAirTimer_ = 0.0f;
	}
	// When character has been in air less than 1/10 second, it's still interpreted as being on ground
	bool softGrounded = inAirTimer_ < INAIR_THRESHOLD_TIME;

	//if (!inAir) {
	//	if (!onGround_ && !softGrounded) {
	//		inAir = true;
	//	}
	//}

	// Update movement & animation
	//const Quaternion& rot = node_->GetRotation();
	Vector3 moveDir = Vector3::ZERO;
	const Vector3& velocity = body->GetLinearVelocity();
	// Velocity on the XZ plane
	Vector3 planeVelocity(velocity.x_, 0.0f, velocity.z_);
	if (canWalk) {
		if (controls_.IsDown(CTRL_FORWARD))
			moveDir += Vector3::FORWARD;
		if (controls_.IsDown(CTRL_BACK))
			moveDir += Vector3::BACK;
		if (controls_.IsDown(CTRL_LEFT))
			moveDir += Vector3::LEFT;
		if (controls_.IsDown(CTRL_RIGHT)) {
			moveDir += Vector3::RIGHT;
		}
	}

	// Slow the player when charging a jump
	if (jumpChargeTime > 0.25f) {
		MOVE_FORCE = CHARGE_IMPEDED_FORCE;
		ACCELERATION_FRICTION = CHARGE_IMPEDED_FRICTION;
		MAX_SPEED = MAX_CHARGE_IMPEDED_SPEED;
	} else if (controls_.IsDown(CTRL_SPRINT)) {
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
	body->ApplyForce(moveDir * (softGrounded ? MOVE_FORCE : INAIR_MOVE_FORCE));
	//body->ApplyForce(node_->GetRotation() * Vector3::FORWARD * (softGrounded ? MOVE_FORCE : INAIR_MOVE_FORCE));

	// If we're trying to move, lower the friction
	if (moveDir != Vector3::ZERO || !canWalk) {
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
				forwardCurrent = Quaternion(1, Vector3(0.0, 1.0, 0.0)) * forwardCurrent;
				//body->ApplyImpulse(Vector3(0.0, 40.0, 0.0));
			}
			deltaSinceLastTurn = 0.0f;
		}
		lastMoveDir = (moveDir == Vector3::ZERO) ? lastMoveDir : moveDir;

		// 90° sideways? Could be nice to have some rolling about the feet to change direction
		//Vector3 sideVector = Vector3(-moveDir.z_, moveDir.y_, moveDir.x_);
		//Vector3 newUp = Vector3(sideVector).Lerp(node_->GetRotation() * Vector3::UP, timeStep);
		node_->LookAt(node_->GetPosition() + forwardCurrent.Lerp(moveDir, TURN_MATCH_RATE * timeStep), node_->GetRotation() * Vector3::UP); // Could simply use World::UP
	}


	// Speed based rotations
	{
		// Figure out which "side" we're on
		signRotCoM = Sign(moveDir.CrossProduct(planeVelocity.Normalized()).y_);
		//signRotCoM = Sign(moveDir.CrossProduct(node_->GetRotation() * Vector3::FORWARD).y_);
		// Calculate the rotation angle for that thing that animals do to keep their centre of gravity (genauso wie Overgrowth)
		// 45° * difference between accel and velo vectors, unless we're STATIONARY OR CLOSE ENOUGH 
		if (moveDir != Vector3::ZERO && moveDir.AbsDotProduct(planeVelocity.Normalized()) < 0.98f) {
			if (planeVelocity.Length() > MAX_WALK_SPEED) {
				// Hit max CoM compensation angle at 24u/s, any more and ignore
				//speedFactorCoM = Max(Min(1 / (MAX_SPRINT_SPEED - planeVelocity.Length()), 1.0f), 0.0f);
				speedFactorCoM = Max(Min(planeVelocity.Length() / MAX_SPRINT_SPEED, 1.0f), 0.0f);

				modelAdjustmentNode_->SetRotation(
					modelAdjustmentNode_->GetRotation().Slerp(
						Quaternion(signRotCoM * speedFactorCoM * 45 * (1 - moveDir.DotProduct(planeVelocity.Normalized())), modelAdjustmentNode_->GetRotation() * Vector3::FORWARD)
						, 10.0f * timeStep)
				);

			} else {
				// Only try and rotate if we're quick enough, otherwise begin to reset,
				// but keep the head movement
				goto resetlerp;
			}
		} else {
		resetlerp:
			if (modelAdjustmentNode_->GetRotation().w_ > 0.01) {
				modelAdjustmentNode_->SetRotation(modelAdjustmentNode_->GetRotation().Slerp(Quaternion::IDENTITY, 3.0f * timeStep));
			} else {
				modelAdjustmentNode_->SetRotation(Quaternion::IDENTITY);
			}
		}


		float weightR = animCtrl->GetWeight("Beagle/Models/RotateRight.ani");
		float weightL = animCtrl->GetWeight("Beagle/Models/RotateLeft.ani");
		// Head look and spine twist
		if (planeVelocity.Length() > 0.05f || moveDir != Vector3::ZERO) {
			signRotCoM = Sign(moveDir.CrossProduct(node_->GetRotation() * Vector3::FORWARD).y_);

			// Direction Factor - hit max at X°
			speedFactorBodyTwist = Min(Acos(moveDir.AbsDotProduct(node_->GetRotation() * Vector3::FORWARD)) / 45, 1.0); // 0 to 1

			if (signRotCoM == -1) {
				if (weightR < speedFactorBodyTwist) {
					animCtrl->SetWeight("Beagle/Models/RotateRight.ani", Min(weightR + HEAD_TURN_RATE * speedFactorBodyTwist * timeStep, speedFactorBodyTwist));
				} else if (weightR > speedFactorBodyTwist) {
					animCtrl->SetWeight("Beagle/Models/RotateRight.ani", Max(weightR - HEAD_TURN_RATE * speedFactorBodyTwist * timeStep, speedFactorBodyTwist));
				} else {
					animCtrl->SetWeight("Beagle/Models/RotateRight.ani", speedFactorBodyTwist);
				}
				animCtrl->SetWeight("Beagle/Models/RotateLeft.ani", 0);
			} else if (signRotCoM == 1) {
				if (weightL < speedFactorBodyTwist) {
					animCtrl->SetWeight("Beagle/Models/RotateLeft.ani", Min(weightL + HEAD_TURN_RATE * speedFactorBodyTwist * timeStep, speedFactorBodyTwist));
				} else if (weightL > speedFactorBodyTwist) {
					animCtrl->SetWeight("Beagle/Models/RotateLeft.ani", Max(weightL - HEAD_TURN_RATE * speedFactorBodyTwist * timeStep, speedFactorBodyTwist));
				} else {
					animCtrl->SetWeight("Beagle/Models/RotateLeft.ani", speedFactorBodyTwist);
				}
				animCtrl->SetWeight("Beagle/Models/RotateRight.ani", 0);
			} else {
				animCtrl->SetWeight("Beagle/Models/RotateRight.ani", 0);
				animCtrl->SetWeight("Beagle/Models/RotateLeft.ani", 0);
			}

		} else {
			if (weightR > 0) {
				animCtrl->SetWeight("Beagle/Models/RotateRight.ani", Max(weightR - HEAD_TURN_RATE * timeStep, 0));
			}
			if (weightL > 0) {
				animCtrl->SetWeight("Beagle/Models/RotateLeft.ani", Max(weightL - HEAD_TURN_RATE * timeStep, 0));
			}
		}
	}


	//modelAdjustmentNode_->SetRotation(Quaternion(modelAdjustmentNode_->GetRotation().Angle() + timeStep * 30, modelAdjustmentNode_->GetRotation() * Vector3::FORWARD));

	 //LIGHTNING STUFF
	if (planeVelocity.Length() > 0.5f) {
		// If we're travelling faster than walking pace + a buffer (to stop lightning on near-run), ZAP
		if (planeVelocity.Length() > LIGHTNING_SPEED) {
			lightning_elapsedTime += timeStep;
			if (lightning_elapsedTime > lightningRun_maxTime) {
				//makeLightning();
				makeLightningBones(FEET_ONLY);
				lightning_elapsedTime = 0.0f;
				lightningRun_maxTime = Random(0.8f, 2.6f) / planeVelocity.Length();
			}
		}
	} else if (lightning_elapsedTime > lightning_maxTime) {
		makeLightningBones(TORSO_ONLY);
		lightning_elapsedTime = 0.0f;
		SetRandomSeed(Time::GetSystemTime());
		lightning_maxTime = Random(0.04f, 4.5f);
	}
	lightning_elapsedTime += timeStep;

	//if (lightningShadowLightMaxTime > 0.0f) {
	//	lightningShadowLightOnTime += timeStep;
	//	if (lightningShadowLightOnTime >= lightningShadowLightMaxTime) {
	//		lightningShadowLightMaxTime = 0.0f;
	//		lightningShadowLightOnTime = 0.0f;
	//		fakeShadowLightning->SetEnabled(false);
	//	} else if (jitterLight) {
	//		// Copy the position of the most recent lightning
	//		fakeShadowLightning->GetNode()->SetWorldPosition(lightningShadowCopyPos);
	//		jitterLight = false;
	//	}
	//}


	if (onGround_) {
		if (canWalk) {
			// Play walk animation if moving on ground, otherwise fade it out
			if (!moveDir.Equals(Vector3::ZERO)) {
				if (planeVelocity.Length() < WALK_TO_SPRINT_SPEED_ANIM) {
					animCtrl->PlayExclusive("Beagle/Models/Walk.ani", 0, true, 0.1f);
				} else if (planeVelocity.Length() < SPRINT_TO_GALLOP_SPEED_ANIM) {
					animCtrl->PlayExclusive("Beagle/Models/Run.ani", 0, true, 0.2f);
				} else {
					animCtrl->PlayExclusive("Beagle/Models/Gallop.ani", 0, true, 0.2f);
				}
			} else {
				if (moveDir == Vector3::ZERO && planeVelocity.Length() > MAX_WALK_SPEED + 0.05f) {
					animCtrl->PlayExclusive("Beagle/Models/Brake.ani", 0, true, 0.1f); // Fade in does not work with manually-set weights
					animCtrl->SetSpeed("Beagle/Models/Brake.ani", 2.0f); // Fade in does not work with manually-set weights
				} else {
					animCtrl->PlayExclusive("Beagle/Models/IdleLoop.ani", 0, true, 0.5f);
				}
				//animCtrl->SetStartBone("Beagle/Models/IdleLoop.ani", "Root");
			}

			// Set walk animation speed proportional to velocity
			animCtrl->SetSpeed("Beagle/Models/Walk.ani", planeVelocity.Length() * 0.55f);
			animCtrl->SetSpeed("Beagle/Models/Run.ani", planeVelocity.Length() * 0.1f);
			animCtrl->SetSpeed("Beagle/Models/Gallop.ani", planeVelocity.Length() * 0.07f);
		} else if (canLand) {
			animCtrl->PlayExclusive("Beagle/Models/Land.ani", 0, false, 0.0f);
			animCtrl->SetSpeed("Beagle/Models/Land.ani", 2.0f);
		}
	}

	if (softGrounded && canWalk) {
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
				jumpChargeTime += timeStep;
				animCtrl->PlayExclusive("Beagle/Models/Jump.ani", 0, false, 0.1f);
				animCtrl->SetSpeed("Beagle/Models/Jump.ani", 0.0f);

				if (jumpChargeTime > MAX_JUMP_CHARGE_TIME) {
					goto doajump;
				}
			}
		} else if (jumpChargeTime > 0.0f) {
		doajump:
			okToJump_ = false;
			//TODO make this a jump ani
			animCtrl->PlayExclusive("Beagle/Models/Jump.ani", 0, false, 0.0f);
			animCtrl->SetSpeed("Beagle/Models/Jump.ani", 1.0f);
			canWalk = false;
			canLand = false;
			jumpBonus = jumpChargeTime / MAX_JUMP_CHARGE_TIME; // 0% to 100% bonus
			jumpChargeTime = 0.0f;
		} else {
			okToJump_ = true;
		}
	}

	if (!canWalk && manualJumpAngling && !canLand) {
		animCtrl->SetSpeed("Beagle/Models/Jump.ani", 0.0f);
		float divisor = 10.0f;
		//float speed = Pow(body->GetLinearVelocity().y_ / 3.0f, 3.0f); //* Sign(body->GetLinearVelocity().y_);
		//float factor = 0.25 + Clamp((-speed + divisor / 2.0f) / divisor, 0.0f, 1.0f) * 0.75; //Adjusted to stop it from incorporating the initial part of the jump
		float factor = 0.25 + Clamp((-body->GetLinearVelocity().y_ + divisor / 2.0f) / divisor, 0.0f, 1.0f) * 0.75; //Adjusted to stop it from incorporating the initial part of the jump

		animCtrl->SetTime("Beagle/Models/Jump.ani", Lerp(animCtrl->GetTime("Beagle/Models/Jump.ani"), factor, 15.0f * timeStep));

		if (factor >= 1.0f || (onGround_ && factor > 0.525f)) {
			manualJumpAngling = false;
			canLand = true;
			inAir = false;
		}
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

void NewCharacter::HandleAnimationTrigger(StringHash eventType, VariantMap& eventData) {
	using namespace AnimationTrigger;

	AnimatedModel* model = modelAdjustmentNode_->GetComponent<AnimatedModel>();
	AnimationState* state = model->GetAnimationState(eventData[P_NAME].GetString());
	if (!state) {
		return;
	}
	//If the footstep is blended with a high enough weight, enable the particle effect

	if (eventData[P_DATA].GetString().Contains("JUMP")) {
		auto* body = GetComponent<RigidBody>();
		body->ApplyImpulse(Vector3::UP * JUMP_FORCE + (node_->GetRotation() * Vector3::FORWARD * JUMP_FORCE * jumpBonus));
		jumpBonus = 0.0f;
		manualJumpAngling = true;

	} else if (eventData[P_DATA].GetString().Contains("CANLAND")) {
		manualJumpAngling = false;
		canLand = true;

	} else if (eventData[P_DATA].GetString().Contains("CANWALK")) {
		canLand = false;
		canWalk = true;

	} else if (state->GetWeight() > 0.5f) {
		String eventName = eventData[P_DATA].GetString();
		for (Bone bone : model->GetSkeleton().GetBones()) {
			if (bone.name_.Compare(eventName) == 0) {
				Node* emitterNode = bone.node_->GetChild(bone.name_);
				emitterNode->GetComponent<ParticleEmitter>()->SetEmitting(true);
				emitterNode->GetComponent<SelfDestructor>()->resetTimer();
			}
		}
	}
}


/*
void NewCharacter::makeLightning() {
	PODVector<RayQueryResult> results;
	Vector3 surfacePoint;
	Vector3 targetPos = Vector3::ZERO;
	bool hitSomethingOtherThanDoggy = false;
	int maxTries = 5;
	int attempts = 0;


	Node* adjNode = node_->GetChild("AdjNode");
	adjNode->GetComponent<AnimatedModel>()->GetModel();

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
				surfacePoint = *(Vector3*)(&vertices[(short)Random(0, (int)geom->GetVertexCount()) * vertexSize]);
				// To World
				surfacePoint = adjNode->GetWorldTransform() * surfacePoint;
			} else {
				//surfacePoint = *(Vector3*)(&vertices[(short)Random(0, (int)vertexSize)]);
				surfacePoint = *(Vector3*)(&vertices[Random(0, (int)geom->GetVertexCount()) * vertexSize]);
				//surfacePoint = *(Vector3*)(&vertices[0]);

				// To World
				surfacePoint = adjNode->GetWorldTransform() * surfacePoint;
			}
		}


		Ray ray = Ray(surfacePoint, dirVec);
		RayOctreeQuery query(results, ray, Urho3D::RAY_TRIANGLE, dirVec.Length(), Urho3D::DRAWABLE_GEOMETRY, -1);
		node_->GetScene()->GetComponent<Urho3D::Octree>()->Raycast(query);

		for (RayQueryResult result : results) {
			String gg = result.node_->GetName();
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

	Node* objectNode = GetScene()->CreateChild("LightningBolt");

	// Should work with local space
	objectNode->SetPosition(surfacePoint);

	//Lightning* lightning_ = objectNode->CreateComponent<Lightning>();
	//lightning_->Start();
	//lightning_->setLifeTime(0.1f);
	//lightning_->setTarget(targetPos);
	//lightning_->extendToPoint();

	StaticModel* mdl = objectNode->CreateComponent<StaticModel>();
	mdl->SetModel(GetSubsystem<ResourceCache>()->GetResource<Model>("Models/Sphere.mdl"));
	objectNode->SetScale(0.15f);
}
*/

// TODO: Add octree search/ cell search
void NewCharacter::makeLightningBones(NewCharacter::LIGHTNING_TYPE lightningType) {
	PODVector<RayQueryResult> results;
	Vector3 bonePoint;
	Vector3 bonePointWorld;
	Node* boneChosen;

	Vector3 targetPos = Vector3::ZERO;
	bool hitSomethingOtherThanDoggy = false;
	int maxTries = 9;
	int attempts = 0;


	Node* adjNode = node_->GetChild("AdjNode");

	while (results.Size() < 1 || !hitSomethingOtherThanDoggy) {
		// Could square this to bias it toward the far end? Maybe
		Vector3 dirVec;// = Vector3(Random(-1.0f, 1.0f), Random(-1.0f, 1.0f), Random(-1.0f, 1.0f)) * 0.25f;

		// Get random bone
		{
			Vector<Bone> boneList = adjNode->GetComponent<AnimatedModel>()->GetSkeleton().GetBones();

		boneLoop:
			{
				boneChosen = boneList.At(Random(0, boneList.Size() - 1)).node_;
				String boneName = boneChosen->GetName();

				// DO NOT pick any Poles, roots, or tail-bones (unless tail-tip)
				//if (boneName.Contains("Pole", false) || boneName.Contains("Root", false) || (boneName.Contains("Tail", false) && !boneName.Contains("Tip", false))) {
				//	goto boneLoop;
				//}

				switch (lightningType) {
				case FULL_BODY:
					if (boneName.Contains("Pole", false) || boneName.Contains("Root", false) || (boneName.Contains("Tail", false) && !boneName.Contains("Tip", false))) {
						goto boneLoop;
					}
					break;
				case FEET_ONLY:
					if (!boneName.Contains("PawIK", false)) {
						goto boneLoop;
					}
					break;
				case HEAD_ONLY:
					if (!boneName.Contains("Head", false)) {
						goto boneLoop;
					}
					break;
				case TAIL_ONLY:
					if (!boneName.Contains("Tail", false)) {
						goto boneLoop;
					}
					break;
				case TORSO_ONLY:
					if (!(boneName.Compare("Pelvis", false) || boneName.Compare("Body", false) || boneName.Compare("Chest", false) || boneName.Compare("Shoulder", false) || boneName.Compare("Neck", false))) {
						goto boneLoop;
					}
					break;
				default:
					break;
				}
			}

			bonePointWorld = boneChosen->GetWorldPosition();
			bonePoint = boneChosen->GetPosition();

			// Test: dirVec is bone relative to root + 1y, but slightly random. Multiplied to increase range
			// TODO: This ought to allow upward/sideward checks too! Rather than just forcing it downward
			//dirVec = (dirVec + (Vector3(0, -1, 0) + bonePointWorld - node_->GetWorldPosition()).Normalized()).Normalized() * 7.0f;

			dirVec = Vector3(Random(-1.0f, 1.0f), Random(-1.0f, 0.0f), Random(-1.0f, 1.0f)).Normalized();
			dirVec *= 3.0f;
			// Get a random point in a circle of radius 1 about Node's Centre (+0.5f upward)
		}



		Ray ray = Ray(bonePointWorld, dirVec);
		RayOctreeQuery query(results, ray, Urho3D::RAY_TRIANGLE, dirVec.Length(), Urho3D::DRAWABLE_GEOMETRY, -1);
		node_->GetScene()->GetComponent<Urho3D::Octree>()->Raycast(query);

		// Only zap things that a. Aren't the dog, and b. Have a visual model
		for (RayQueryResult result : results) {
			if (result.node_->GetName().Compare("AdjNode") != 0 && (result.node_->HasComponent<AnimatedModel>() || result.node_->HasComponent<StaticModel>())) {
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
	//lightning_->Start();
	lightning_->setLifeTime(Random(0.1f, 0.25f));
	lightning_->setTarget(targetPos);
	lightning_->extendToPoint();

	/*lightningShadowLightMaxTime += lightning_->getLifeTime();
	fakeShadowLightning->SetEnabled(true);
	lightningShadowCopyPos = objectNode->GetWorldPosition() + (objectNode->GetRotation() * Vector3::FORWARD * 0.5f * objectNode->GetScale().z_);
	jitterLight = true;*/
}