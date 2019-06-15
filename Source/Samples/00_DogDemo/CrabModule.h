#pragma once

#include <Urho3D/Scene/LogicComponent.h>
#include "ModuleSocketTypes.h"

using namespace Urho3D;

class CrabModule : public LogicComponent {
	URHO3D_OBJECT(CrabModule, LogicComponent);

public:
	///Construct.
	explicit CrabModule(Context* context);

	/// Register object factory and attributes.
	//static void RegisterObject(Context* context);

	virtual void onInstall() = 0;
	virtual void onUninstall() = 0;

	SocketType GetSocketType() { return acceptedSocket; };
	//void SetSocketType(SocketType type) {acceptedSocket = type;}
	/*static*/ SocketType acceptedSocket;

private:
	//Node * modelNode;
};