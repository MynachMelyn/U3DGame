#include <Urho3D/Core/Context.h>
#include "Global.h"
#include <SmartMissile.h>

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

	collision = node_->CreateComponent<CollisionShape>();
	collision->SetBox(Vector3(0.1f, 0.1f, 0.4f));
	rigidBody = node_->CreateComponent<RigidBody>();
	rigidBody->SetMass(mass);
	rigidBody->SetLinearDamping(0.75f);

	// Rockets are on 2nd layer, don't collide with layer 4th layer
	//rigidBody->SetCollisionLayerAndMask(2, Urho3D::M_MAX_UNSIGNED);
	rigidBody->SetCollisionLayerAndMask(2, 1 < 2 < 3 < 4 < 6 < 7 < 8);

	//rigidBody->SetAngularDamping(5.0f);
	//rigidBody->SetAngularFactor(Vector3::ZERO);

	//rigidBody->ApplyImpulse(Vector3::UP * 10.0f);

	// For now
	rigidBody->SetUseGravity(true);

	StaticModel* model = node_->CreateComponent<StaticModel>();
	model->SetModel(modelNoWings);
	//model->SetModel(cache->GetResource<Model>("Missiles/Models/MissileNoWings.mdl"));
	model->SetModel(SmartMissile::modelNoWings);

	target = GetScene()->GetChild("target", true);

}
void SmartMissile::DelayedStart() {
	SetRandomSeed(time->GetSystemTime());
	node_->LookAt(Vector3(Random() - 0.5f, 0.0f, Random() - 0.5f) + node_->GetWorldPosition() + Vector3::UP * 2.0f, Vector3::UP, TS_WORLD);
	rigidBody->ApplyImpulse((GetNode()->GetRotation() * Vector3::FORWARD) * 10.0f);
	rigidBody->ApplyTorque(GetNode()->GetRotation() * Vector3(0.0f, 0.0f, (Random() + 0.1f) * 10.0f));
}

/// Handle physics world update. Called by LogicComponent base class.
void SmartMissile::Update(float timeStep) {
	if (!engaged) {
		if (timeSinceInit < timeToEngage) {
			timeSinceInit += timeStep;
		} else {
			engaged = true;
			// Now that we have engaged, change the model to the winged model ONCE.
			this->GetComponent<StaticModel>()->SetModel(SmartMissile::modelWithWings);
		}
	} else {
		if (target != nullptr) {
			rigidBody->SetUseGravity(false);

			// Calculate own acceleration
			//float acc = thrustForce / rigidBody->GetMass();


			// For now, targeting is instant and simply points at the target.
			node_->LookAt(target->GetWorldPosition(), Vector3::UP, TS_WORLD);
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