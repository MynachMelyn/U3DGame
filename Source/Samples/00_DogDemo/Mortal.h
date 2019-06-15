#pragma once

class Mortal {
	//URHO3D_OBJECT(Mortal, LogicComponent);

public:
	///Construct.
	//explicit Mortal();

	/// Register object factory and attributes.
	//static void RegisterObject(Context* context);

	void Damage(int dmg);
	void Heal(int heal);

	/// Once health reaches 0
	void Kill();

	/// Removes node from world etc.
	void Destroy();

private:
	//Node * modelNode;
	int hp;
	int maxHp;
	bool invincible = false;
	bool intangible = false;
};