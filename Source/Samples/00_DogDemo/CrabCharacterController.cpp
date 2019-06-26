#include <Bullet/btBulletDynamicsCommon.h>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <Bullet/BulletDynamics/Character/btKinematicCharacterController.h>

#include "CrabCharacterController.h"
#include "SmartSalvoLauncher.h"
#include "ModuleSocket.h"
#include "Global.h"

#undef new //???

const int CTRL_FORWARD = 1;
const int CTRL_BACK = 2;
const int CTRL_LEFT = 4;
const int CTRL_RIGHT = 8;
const int CTRL_JUMP = 16;
const int CTRL_ACTIVATEBACK = 32;
// Функция копирует значения X и Z из вектора from в вектор target.
// Эта функция используется, чтобы изменить горизонтальную скорость объекта, но не затронуть вертикальную.
/*static void SetXZ(Vector3& target, const Vector3& from)
{
	target.x_ = from.x_;
	target.z_ = from.z_;
}*/

CrabCharacterController::CrabCharacterController(Context* context) : LogicComponent(context) {
	SetUpdateEventMask(USE_FIXEDUPDATE | USE_UPDATE);

}

CrabCharacterController::~CrabCharacterController() {

}

void CrabCharacterController::RegisterObject(Context* context) {
	context->RegisterFactory<CrabCharacterController>();
	//TODO MOVE THESE GOONS
	ModuleSocket::RegisterObject(context);
	SmartSalvoLauncher::RegisterObject(context);
}

void CrabCharacterController::DelayedStart() {

	GetNode()->AddTag("player");

	animControl_ = GetNode()->CreateComponent<AnimationController>();
	//animControl_->PlayExclusive("Crab/Models/Walk.ani", 0, true, 0.2f);

	// Redundant now
	//node_->SetScale(0.02f);

	Node* backSocketNode = node_->CreateChild("Crab Back Socket");
	backSocket = backSocketNode->CreateComponent<ModuleSocket>();
	backSocket->SetSocketType(BACK);

	Node* launcherNode = GetScene()->CreateChild("Crab Salvo Launcher");
	SmartSalvoLauncher* launcher = launcherNode->CreateComponent<SmartSalvoLauncher>();
	launcherNode->SetWorldTransform(node_->GetWorldPosition(), node_->GetWorldRotation());
	//launcherNode->SetScale(0.2f);

	backSocket->Install(launcher);
}

void CrabCharacterController::FixedUpdate(float timeStep) {
	Vector3 dir;

	if (controls_.IsDown(CTRL_FORWARD)) {
		dir += Vector3::FORWARD;
	}
	if (controls_.IsDown(CTRL_BACK)) {
		dir += Vector3::BACK;
	}
	if (controls_.IsDown(CTRL_LEFT)) {
		dir += Vector3::LEFT;
		node_->Rotate(Quaternion(-100 * timeStep, Vector3::UP));
	}
	if (controls_.IsDown(CTRL_RIGHT)) {
		dir += Vector3::RIGHT;
		node_->Rotate(Quaternion(100 * timeStep, Vector3::UP));
	}
	if (dir != Vector3::ZERO) {
		dir.Normalize();
	}

	dir = node_->GetWorldRotation() * dir;

	/*	velocity_ += dir * timeStep * accelerationTime_ * (bulletController_->onGround() ? 1 : 0.01f);

		// Decelerate constantly
		velocity_ -= velocity_ * (bulletController_->onGround() ? 0.1f : 0.01f);

		// Cap move speed
		if (velocity_.Length() > MOVE_SPEED) {
			velocity_.Normalize();
			velocity_ *= MOVE_SPEED;
			//velocity_ -= (velocity_.Normalized()) * -0.1f;
		}

		//bulletController_->applyImpulse(btVector3(dir.x_, 0.0f, dir.z_));
		if (velocity_.Length() > 0.0001f) {
			bulletController_->setWalkDirection(ToBtVector3(velocity_ * timeStep * MOVE_SPEED));
			//bulletController_->setLinearVelocity(ToBtVector3(velocity_ * timeStep * MOVE_SPEED));

		} else {
			bulletController_->setWalkDirection(btVector3(0, 0, 0));
		}
	*/

	//if (dir != Vector3::ZERO)
	velocity_ = bulletController_->onGround() ? MoveGround(dir, velocity_, timeStep) : MoveAir(dir, velocity_, timeStep);
	bulletController_->setWalkDirection(ToBtVector3(velocity_));

	if (bulletController_->onGround()) {
		if (velocity_.Length() < 0.01f) {
			animControl_->PlayExclusive("Crab/Models/Idle.ani", 0, true, 0.2f);
		} else {
			if (!animControl_->IsPlaying("Crab/Models/Walk.ani")) {
				animControl_->PlayExclusive("Crab/Models/Walk.ani", 0, true, 0.2f);
			}
			//animControl_->PlayExclusive("Crab/Models/Walk.ani", 0, true, 0.2f);
			animControl_->SetSpeed("Crab/Models/Walk.ani", velocity_.Length() * 20.0f);
		}
	}

	if (controls_.IsDown(CTRL_JUMP)) {
		if (bulletController_->onGround()) {
			bulletController_->jump(btVector3(0, 6, 0));
			animControl_->PlayExclusive("Crab/Models/Jump.ani", 0, false, 0.0f);
			animControl_->SetTime("Crab/Models/Jump.ani", 0);

			// TEMPORARY
			//((ActiveCrabModule*)backSocket->GetInstalledModule())->Activate(); // This should cause WeaponModule's activate to call Launcher's activate to call fire!

		}
	}

	if (controls_.IsDown(CTRL_ACTIVATEBACK)) {
		((SmartSalvoLauncher*)backSocket->GetInstalledModule())->Activate(); // This should cause WeaponModule's activate to call Launcher's activate to call fire!
	}

	btTransform t;
	t = bulletController_->getGhostObject()->getWorldTransform();
	Vector3 newPos = ToVector3(t.getOrigin()) + Vector3::DOWN * height_ * 0.5f;
	node_->SetWorldPosition(newPos);
}

Vector3 CrabCharacterController::Accelerate(Vector3 accelDir, Vector3 prevVelocity, float accelerate, float max_velocity, float time) {
	float projVel = prevVelocity.DotProduct(accelDir); // Vector projection of Current velocity onto accelDir.
	float accelVel = accelerate * time; // Accelerated velocity in direction of movment

													   // If necessary, truncate the accelerated velocity so the vector projection does not exceed max_velocity
	if (projVel + accelVel > max_velocity) {
		accelVel = max_velocity - projVel;
	}

	return prevVelocity + accelDir * accelVel;
}

Vector3 CrabCharacterController::MoveGround(Vector3 accelDir, Vector3 prevVelocity, float time) {
	// Apply Friction
	float speed = prevVelocity.Length();
	if (speed != 0) {// To avoid divide by zero errors
		float drop = speed * friction * time;
		prevVelocity *= Max(speed - drop, 0) / speed; // Scale the velocity based on friction.
	}

	// ground_accelerate and max_velocity_ground are server-defined movement variables
	return Accelerate(accelDir, prevVelocity, ground_accelerate, MOVE_SPEED, time);
}

Vector3 CrabCharacterController::MoveAir(Vector3 accelDir, Vector3 prevVelocity, float time) {
	// air_accelerate and max_velocity_air are server-defined movement variables
	return Accelerate(accelDir, prevVelocity, air_accelerate, MOVE_SPEED_AIR, time);
}

void CrabCharacterController::Update(float timeStep) {
	// Может быть перенести это в общий класс, чтобы был доступ окна настроек клавиш
	controls_.Reset();

	controls_.Set(CTRL_FORWARD, input->GetKeyDown(KEY_W));
	controls_.Set(CTRL_BACK, input->GetKeyDown(KEY_S));
	controls_.Set(CTRL_LEFT, input->GetKeyDown(KEY_A));
	controls_.Set(CTRL_RIGHT, input->GetKeyDown(KEY_D));
	controls_.Set(CTRL_JUMP, input->GetKeyDown(KEY_SPACE));
	controls_.Set(CTRL_ACTIVATEBACK, input->GetKeyDown(KEY_E));

	btTransform t;
	t = bulletController_->getGhostObject()->getWorldTransform();
	t.setRotation(ToBtQuaternion(node_->GetRotation()));
	bulletController_->getGhostObject()->setWorldTransform(t);
}

void CrabCharacterController::CreatePhysComponents(float height, float diameter) {
	//   RigidBody* body = node_->CreateComponent<RigidBody>();
	 //  body->SetKinematic(true);
	 //  body->SetMass(1.0f);

	  // CollisionShape* shape = node_->CreateComponent<CollisionShape>();
	   //shape->SetCapsule(diameter, height, Vector3(0.0f, height * 0.5f, 0.0f));

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(btVector3(0, 10, 4));
	startTransform.setRotation(ToBtQuaternion(Quaternion(90, 0, 0)));

	btConvexShape* capsule = new btCapsuleShape(diameter * 0.5, height - diameter);
	//btConvexShape* capsule = new btSphereShape(height * diameter);
	height_ = height;
	diameter_ = diameter;
	accelerationTime_ = 2.0f;
	velocity_ = Vector3::ZERO;

	btDiscreteDynamicsWorld * world = GetScene()->GetComponent<PhysicsWorld>()->GetWorld();

	ghostObject_ = new btPairCachingGhostObject();
	ghostObject_->setWorldTransform(startTransform);
	world->getBroadphase()->getOverlappingPairCache()->setInternalGhostPairCallback(new btGhostPairCallback());
	ghostObject_->setCollisionShape(capsule);
	ghostObject_->setCollisionFlags(btCollisionObject::CF_CHARACTER_OBJECT/* + 0b00000001*/);


	bulletController_ = new btKinematicCharacterController(ghostObject_, capsule, 0.3f, btVector3(0, 0, 1));
	//bulletController_->setGravity(world->getGravity());
	bulletController_->setGravity(world->getGravity());
	bulletController_->setMaxPenetrationDepth(btScalar(0.0f));

	world->addCollisionObject(ghostObject_, btBroadphaseProxy::CharacterFilter + 0b00000001, 0b10111111);
	world->addAction(bulletController_);
	bulletController_->setMaxJumpHeight(1.5);

	//bulletController_->setLinearVelocity(ToBtVector3(Vector3(0.0f, 0.0f, 0.1f)));
	bulletController_->applyImpulse(ToBtVector3(Vector3(0.0f, 0.0f, 10.0f)));
}