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
	AnimatedModel* model = node_->CreateComponent<AnimatedModel>();
	model->SetModel(cache->GetResource<Model>("Missiles/Models/Salvo Launcher.mdl"));
	model->SetMaterial(cache->GetResource<Material>("Materials/Stone.xml"));
}

//bool compareFunction(Node* bone1, Node* bone2) { return bone1->GetName() > bone2->GetName(); }

void SmartSalvoLauncher::DelayedStart() {
	for (Bone bone : node_->GetComponent<AnimatedModel>()->GetSkeleton().GetBones()) {
		boneList.push_back(bone.node_);
	}

	// Sort these bones by List
	//std::sort(boneList.begin(), boneList.end(), compareFunction);

	// Put rocket placeholders in the barrel
	for (int i = 0; i < boneList.size(); i++) {
		Urho3D::String str = boneList.at(i)->GetName();
		CreateRocketInBarrel(i);
	}
}

/// Handle physics world update. Called by LogicComponent base class.
void SmartSalvoLauncher::Update(float timeStep) {

	//TODO: Keep cooldown & timer logic in here, but move Fire() logic to Fire, and the stuff currently in Fire() to Activate

	if (isFiring) {
		coolDownProgress += timeStep;
		if (coolDownProgress > coolDownBetweenShots) {
			if (ammoInMag > 0) {
				Node* missile = GetScene()->CreateChild("Missile");
				//missile->SetWorldTransform(node_->GetWorldPosition() + (Vector3::UP * 2.0f), node_->GetWorldRotation());
				missile->SetWorldTransform(rocketPlaceholders.at(ammoInMag - 1)->GetWorldPosition(), node_->GetWorldRotation());
				missile->LookAt(missile->GetWorldPosition() + Vector3::UP, Vector3::UP, TS_WORLD);
				missile->CreateComponent<SmartMissile>();

				RemoveRocketFromBarrel(); //Remove our current rocket placeholder (the visible rocket in the tube)

				coolDownProgress = 0.0f;
				shotsFired++;
				ammoInMag--;
			}
			if (shotsFired >= maxShots || ammoInMag <= 0) {
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
	int i = ammoInMag;
	while (ammoInReserve > 0 && ammoInMag < magSize) {
		ammoInMag++;
		ammoInReserve--;

		CreateRocketInBarrel(i + 1);
		i++;
	}
}

void SmartSalvoLauncher::Fire() {
	if (!isFiring) {
		isFiring = true;
	}
}

/// Adds to ammo reserve
void SmartSalvoLauncher::FeedAmmo() {

}


void SmartSalvoLauncher::CreateRocketInBarrel(int i) {
	// The bones in boneList are essentially markers for the positions for the rockets in each barrel,
	// allowing us to create simple missile models at each of them and align them with the barrels easily

	Node* rocketPlaceholder = boneList.at(i)->CreateChild("Placeholder Rocket");
	StaticModel* rocketModel = rocketPlaceholder->CreateComponent<StaticModel>();
	rocketModel->SetModel(cache->GetResource<Model>("Missiles/Models/MissileNoWings.mdl"));
	rocketPlaceholder->LookAt(rocketPlaceholder->GetWorldPosition() + Vector3::UP, Vector3::UP, TS_WORLD);

	rocketPlaceholders.push_back(rocketPlaceholder);
}

void SmartSalvoLauncher::RemoveRocketFromBarrel() {
	Node* rocketPlaceholder = rocketPlaceholders.back();
	rocketPlaceholder->Remove();
	rocketPlaceholders.pop_back();
}