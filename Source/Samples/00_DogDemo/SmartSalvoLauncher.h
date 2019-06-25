#pragma once

#include "WeaponModule.h"

using namespace Urho3D;

class SmartSalvoLauncher : public WeaponModule /* , public LogicComponent */ {
	URHO3D_OBJECT(SmartSalvoLauncher, LogicComponent);

public:
	///Construct.
	explicit SmartSalvoLauncher(Context* context);

	/// Register object factory and attributes.
	static void RegisterObject(Context* context);

	void Start() override;
	void DelayedStart() override; //After first frame

											  /// Handle physics world update. Called by LogicComponent base class.
	void Update(float timeStep) override;

	void onInstall();
	void onUninstall();

	void Activate();


	void Reload(); /// Adds to clip
	void Fire();
	void FeedAmmo(); /// Adds to ammo reserve

	void Kill(); ///Overriden from Mortal

private:
	int magSize = 18;
	int ammoReserveSize = 36;

	// Start with full ammo by default
	int ammoInMag = magSize;
	int ammoInReserve = ammoReserveSize;

	bool isFiring = false;			// are we in the middle of a barrage?
	const float coolDownBetweenShots = 0.2f;	// time to wait between shots
	float coolDownProgress = 0.0f;	// time into cooldown between shots
	int shotsFired = 0;				// progress into volley
	static const int maxShots = 8;	// volley size

	//static const SocketType acceptedSocket = BACK;
};