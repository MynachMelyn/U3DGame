#include <Urho3D/Scene/Node.h>
#include <Mortal.h>

/*Mortal::Mortal() {

}*/

/*void Mortal::RegisterObject(Context* context) {
	context->RegisterFactory<Mortal>();
}*/

void Mortal::Damage(int dmg) {
	hp -= dmg;
	if (hp <= 0) {
		hp = 0;
		Kill();
	}
}

void Mortal::Heal(int points) {
	hp += points;
	if (hp > maxHp) {
		hp = maxHp;
	}
}

void Mortal::Kill() {
	Destroy();
}

void Mortal::Destroy() {
	//this->GetNode()->Remove();
}