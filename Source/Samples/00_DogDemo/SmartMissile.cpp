#include <Urho3D/Core/Context.h>
#include "Global.h"
#include <SmartMissile.h>

SmartMissile::SmartMissile(Context* context) :
	PhysicalProjectile(), LogicComponent(context) {
	SetUpdateEventMask(USE_UPDATE);
}

void SmartMissile::RegisterObject(Context* context) {
	context->RegisterFactory<SmartMissile>();
}

void SmartMissile::Start() {
	node_->SetScale(0.1f);

	collision = node_->CreateComponent<CollisionShape>();
	collision->SetBox(Vector3(2.5f, 2.5f, 2.5f));
	rigidBody = node_->CreateComponent<RigidBody>();
	rigidBody->SetMass(mass);
	//rigidBody->SetLinearDamping(0.5f);
	//rigidBody->SetAngularDamping(5.0f);
	//rigidBody->SetAngularFactor(Vector3::ZERO);

	//rigidBody->ApplyImpulse(Vector3::UP * 10.0f);

	// For now
	//rigidBody->SetUseGravity(false);

	StaticModel* model = node_->CreateComponent<StaticModel>();
	model->SetModel(cache->GetResource<Model>("Missiles/Models/Missile.mdl"));

	target = GetScene()->GetChild("target", true);

}
void SmartMissile::DelayedStart() {

}

/// Handle physics world update. Called by LogicComponent base class.
void SmartMissile::Update(float timeStep) {
	if (target != nullptr) {
		// For now, targeting is instant and simply points at the target.
		node_->LookAt(Vector3::ZERO, Vector3::UP, TS_WORLD);
		//rigidBody->SetRotation
	}

	// Thrust forward
	rigidBody->ApplyForce(node_->GetRotation() * Vector3::FORWARD * thrustForce); // Apply force forward

	// Apply magic Friction
	//rigidBody->ApplyForce(rigidBody->GetLinearVelocity)
}

void SmartMissile::Kill() {

	// CREATE EXPLOSION OBJ HERE

	Mortal::Kill();
}

void SmartMissile::OnHit() {
	// DMG target hit?
	Kill();
}