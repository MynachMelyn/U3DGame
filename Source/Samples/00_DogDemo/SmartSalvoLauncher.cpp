//#include <Urho3D/Core/Context.h>
#include <Global.h>
#include <PhysicalProjectile.h>
#include <SmartSalvoLauncher.h>
#include <SmartMissile.h>

SmartSalvoLauncher::SmartSalvoLauncher(Context* context) :
	WeaponModule(context) {
	SetUpdateEventMask(USE_UPDATE);

	//CrabModule::acceptedSocket = BACK;
	acceptedSocket = BACK;
}

void SmartSalvoLauncher::RegisterObject(Context* context) {
	context->RegisterFactory<SmartSalvoLauncher>();
	context->RegisterFactory<SmartMissile>();
}

void SmartSalvoLauncher::Start() {
	StaticModel* model = node_->CreateComponent<StaticModel>();
	model->SetModel(cache->GetResource<Model>("Missiles/Models/Salvo Launcher.mdl"));
	model->SetMaterial(cache->GetResource<Material>("Materials/Stone.xml"));
}
void SmartSalvoLauncher::DelayedStart() {

}

/// Handle physics world update. Called by LogicComponent base class.
void SmartSalvoLauncher::Update(float timeStep) {

}

void SmartSalvoLauncher::onInstall() {

}
void SmartSalvoLauncher::onUninstall() {

}

void SmartSalvoLauncher::Activate() {
	Fire();
}
/// Adds to clip
void SmartSalvoLauncher::Reload() {

}

void SmartSalvoLauncher::Fire() {

	//node_->SetPosition(node_->GetPosition() + Vector3(0.0f, 0.25f, 0.0f));

	Node* missile = GetScene()->CreateChild("Missile");
	missile->SetWorldTransform(node_->GetWorldPosition() + (Vector3::UP * 3.0f), node_->GetWorldRotation());
	//missile->SetPosition(missile->GetPosition() + (missile->GetRotation() * Vector3::UP * 3)); // Move upward by 3 units to avoid collision
	missile->CreateComponent<SmartMissile>();
}

/// Adds to ammo reserve
void SmartSalvoLauncher::FeedAmmo() {

}