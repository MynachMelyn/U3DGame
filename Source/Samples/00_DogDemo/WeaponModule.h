#pragma once

#include "ActiveCrabModule.h"

using namespace Urho3D;

class WeaponModule : public ActiveCrabModule {
	//URHO3D_OBJECT(WeaponModule, ActiveCrabModule);

public:
	///Construct.
	explicit WeaponModule(Context* context) : ActiveCrabModule(context) {
		//SetUpdateEventMask(USE_UPDATE);
	};

	virtual void onInstall() = 0;
	virtual void onUninstall() = 0;

	virtual void Activate() = 0;

	virtual void Reload() = 0; /// Adds to clip
	virtual void Fire() = 0;
	virtual void FeedAmmo() = 0; /// Adds to ammo reserve


private:
	int magSize;
	int ammoReserveSize;
	int ammoInMag;
	int ammoInReserve;
};