#include <Urho3D/Core/Context.h>
#include "Global.h"
#include <SmartMissile.h>
#include <Layers.h>

SmartMissile::SmartMissile(Context* context) :
	PhysicalProjectile(), LogicComponent(context) {
	SetUpdateEventMask(USE_UPDATE);
}


// Otherwise we get unresolved extern. symbols?? These refer to the static model definitions we have in the header
void SmartMissile::RegisterObject(Context* context) {
	context->RegisterFactory<SmartMissile>();
}

void SmartMissile::Start() {
	SmartMissile::modelNoWings = cache->GetResource<Model>("Missiles/Models/MissileNoWings.mdl");
	SmartMissile::modelWithWings = cache->GetResource<Model>("Missiles/Models/Missile.mdl");

	modelNode = node_->CreateChild("Rocket Model");

	collision = node_->CreateComponent<CollisionShape>();
	collision->SetBox(Vector3(0.1f, 0.1f, 0.4f));
	rigidBody = node_->CreateComponent<RigidBody>();
	rigidBody->SetMass(mass);
	rigidBody->SetLinearDamping(0.9f);

	// Rockets are on 2nd layer, don't collide with layer 4th layer
	//rigidBody->SetCollisionLayerAndMask(2, Urho3D::M_MAX_UNSIGNED);
	//rigidBody->SetCollisionLayerAndMask(2, 1 < 2 < 3 < 4 < 6 < 7);
	//rigidBody->SetCollisionLayerAndMask(0b01000000, 0b11011111); // Don't collide with player on 5th layer (layer 4)
	rigidBody->SetCollisionLayerAndMask(PROJECTILE_LAYER, 0b11111111 & !PLAYER_LAYER); // Don't collide with player on 5th layer (layer 4)
	//rigidBody->SetCollisionLayerAndMask(1, 1 < 2 < 3 < 4 < 6 < 7 < 8);

	//rigidBody->SetAngularDamping(5.0f);
	//rigidBody->SetAngularFactor(Vector3::ZERO);

	//rigidBody->ApplyImpulse(Vector3::UP * 10.0f);

	// For now
	rigidBody->SetUseGravity(true);

	StaticModel* model = modelNode->CreateComponent<StaticModel>();
	model->SetModel(modelNoWings);
	//model->SetModel(cache->GetResource<Model>("Missiles/Models/MissileNoWings.mdl"));
	model->SetModel(SmartMissile::modelNoWings);

	target = GetScene()->GetChild("target", true);

	emitter = GetNode()->CreateComponent<ParticleEmitter>();
	emitter->SetEffect(cache->GetResource<ParticleEffect>("Particle/SmokeMissile.xml"));
	emitter->SetEmitting(false);

}
void SmartMissile::DelayedStart() {
	SetRandomSeed(time->GetSystemTime());
	//node_->LookAt(Vector3(Random() - 0.5f, 0.0f, Random() - 0.5f) + node_->GetWorldPosition() + Vector3::UP * 2.0f, Vector3::UP, TS_WORLD);
	node_->LookAt(
		(Vector3(Random() - 0.5f, 0.0f, Random() - 0.5f) / 3.0f)
		+ node_->GetWorldPosition() + Vector3::UP * 2.0f, Vector3::UP, TS_WORLD);
	rigidBody->ApplyImpulse((GetNode()->GetRotation() * Vector3::FORWARD) * UPWARD_LAUNCH_FORCE);

	// For now don't spin - it wrecks the tracking stuff
	//rigidBody->ApplyTorque(GetNode()->GetRotation() * Vector3(0.0f, 0.0f, (Random() + 0.1f) * 3.0f));
	rigidBody->SetAngularFactor(Vector3(0.0f, 0.0f, 0.0f));
}

/// Handle physics world update. Called by LogicComponent base class.
void SmartMissile::Update(float timeStep) {
	if (!engaged) {
		if (timeSinceInit < timeToEngage) {
			timeSinceInit += timeStep;
		} else {
			engaged = true;
			// Now that we have engaged, change the model to the winged model ONCE.
			//this->GetComponent<StaticModel>()->SetModel(SmartMissile::modelWithWings);
			modelNode->GetComponent<StaticModel>()->SetModel(SmartMissile::modelWithWings);
			emitter->SetEmitting(true);
		}
	} else {
		if (target != nullptr) {
			rigidBody->SetUseGravity(false);

			if (timeAlive < trackingTimeMax) {
				timeAlive += timeStep;
				timeFactor = (timeAlive / trackingTimeMax);
			}

			Vector3 forwardDir = (node_->GetRotation() * Vector3::FORWARD).Normalized();
			Vector3 targetDir = (target->GetWorldPosition() - node_->GetWorldPosition()).Normalized();

			Vector3 axis = forwardDir.CrossProduct(targetDir);

			float angleBetweenVectors = Acos(forwardDir.DotProduct(targetDir));

			// Turn faster when closer
			float dist = (target->GetWorldPosition() - node_->GetWorldPosition()).Length();
			float turnFactor = 1.0f + (timeFactor * trackingMultiplier);

			float angle = 50.0f * turnFactor * timeStep; // 5.0f deg per sec

			Quaternion rotation = Quaternion::IDENTITY;
			rotation.FromAngleAxis(angle, axis);

			if (angle < angleBetweenVectors) { // If amount we're gonna rotate is less than the distance, just do LookAt
				node_->Rotate(rotation, Urho3D::TS_WORLD);
			} else {
				node_->LookAt(target->GetWorldPosition());
			}


			// SORTA WORKS, LOOKS TOO SHARP
			//node_->LookAt(node_->GetWorldPosition() + rigidBody->GetLinearVelocity());
			//rigidBody->ApplyForce((target->GetWorldPosition() - node_->GetWorldPosition()).Normalized() * thrustForce); // Apply force forward
		}
		rigidBody->ApplyForce(node_->GetRotation() * Vector3::FORWARD * thrustForce); // Apply force forward
	}
}

void SmartMissile::Kill() {

	// CREATE EXPLOSION OBJ HERE

	Mortal::Kill();
}

void SmartMissile::OnHit() {
	// DMG target hit?
	Kill();
}