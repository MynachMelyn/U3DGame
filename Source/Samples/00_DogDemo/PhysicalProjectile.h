#pragma once

#include <Mortal.h>
#include <Urho3D/Physics/RigidBody.h>
#include <Urho3D/Physics/CollisionShape.h>

using namespace Urho3D;

class PhysicalProjectile : public Mortal {
	//URHO3D_OBJECT(PhysicalProjectile, Mortal);

public:
	///Construct.
	//explicit PhysicalProjectile();


	//void Damage(int dmg);
	//void Heal(int heal);

	/// Once health reaches 0
	//void Kill();

	/// Removes node from world etc.
	//void Destroy();

	virtual void OnHit() = 0;

private:
	//Node * modelNode;
	int hp;
	int maxHp;
	bool invincible = false;
	bool intangible = false;

	float mass;

	RigidBody* rigidBody = nullptr;
	CollisionShape* collision = nullptr;
};