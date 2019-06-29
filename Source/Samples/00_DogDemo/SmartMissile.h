#pragma once

#include <PhysicalProjectile.h>
#include <Urho3D/Physics/RigidBody.h>
#include <Urho3D/Physics/CollisionShape.h>
#include <Urho3D/Graphics/ParticleEmitter.h>
#include <Urho3D/Graphics/ParticleEffect.h>

using namespace Urho3D;

class SmartMissile : public PhysicalProjectile, public LogicComponent {
	URHO3D_OBJECT(SmartMissile, LogicComponent);

public:
	///Construct.
	explicit SmartMissile(Context* context);

	/// Register object factory and attributes.
	static void RegisterObject(Context* context);

	/// Handle startup. Called by LogicComponent base class.
	void Start() override;
	void DelayedStart() override; //After first frame

											  /// Handle physics world update. Called by LogicComponent base class.
	void Update(float timeStep) override;

	void Damage(int dmg);
	void Heal(int heal);

	/// Once health reaches 0
	void Kill();

	/// Removes node from world etc.
	void Destroy();

	void OnHit();

private:
	//Node * modelNode;
	int hp = 100;
	int maxHp = 100;
	bool invincible = false;
	bool intangible = false;

	float mass = 1.0f;

	float thrustForce = 25.0f;
	//float constantDeceleration = 5.0f; //Should help prevent overshooting later on

	RigidBody* rigidBody = nullptr;
	CollisionShape* collision = nullptr;

	Node* target = nullptr;

	float timeSinceInit = 0.0f;
	float timeToEngage = 1.0f;

	bool engaged = false;

	Model* modelNoWings;
	Model* modelWithWings;

	ParticleEmitter* emitter;

	Node* modelNode;

	const float UPWARD_LAUNCH_FORCE = 15.0f; //10

	float timeAlive = 0.0f; // Time this rocket has existed - used to slowly increase tracking strength
	const float trackingTimeMax = 2.0f;
	float timeFactor = 1.0f;
	float trackingMultiplier = 8.0f;
};