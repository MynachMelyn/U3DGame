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
	if (isFiring) {
		coolDownProgress += timeStep;
		if (coolDownProgress > coolDownBetweenShots) {
			Node* missile = GetScene()->CreateChild("Missile");
			missile->SetWorldTransform(node_->GetWorldPosition() + (Vector3::UP * 2.0f), node_->GetWorldRotation());
			missile->CreateComponent<SmartMissile>();

			coolDownProgress = 0.0f;
			shotsFired++;
			if (shotsFired >= maxShots) {
				shotsFired = 0;
				isFiring = false;
			}
		}
	}
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
	if (!isFiring) {
		isFiring = true;
	}
}

/// Adds to ammo reserve
void SmartSalvoLauncher::FeedAmmo() {

}