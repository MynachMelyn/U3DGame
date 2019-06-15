#pragma once

#include <Urho3D/Scene/LogicComponent.h>
#include "ModuleSocketTypes.h"
#include "CrabModule.h"

using namespace Urho3D;

class ModuleSocket : public LogicComponent {
	URHO3D_OBJECT(ModuleSocket, LogicComponent);

public:
	///Construct.
	explicit ModuleSocket(Context* context);

	/// Register object factory and attributes.
	static void RegisterObject(Context* context);

	/// Handle startup. Called by LogicComponent base class.
	//virtual void Start() override = 0;
	//virtual void DelayedStart() override = 0; //After first frame

											  /// Handle physics world update. Called by LogicComponent base class.
	//virtual void Update(float timeStep) override = 0;

	bool Install(CrabModule* module);
	void Uninstall();
	void SetSocketType(SocketType type);
	SocketType GetSocketType() { return type; };
	CrabModule* GetInstalledModule();

private:
	SocketType type;
	CrabModule* installedModule;
};