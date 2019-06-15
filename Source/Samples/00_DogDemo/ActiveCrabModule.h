#pragma once

#include "CrabModule.h"

using namespace Urho3D;

class ActiveCrabModule : public CrabModule {
	//URHO3D_OBJECT(ActiveCrabModule, CrabModule);

public:
	///Construct.
	explicit ActiveCrabModule(Context* context);

	/// Register object factory and attributes.
	//static void RegisterObject(Context* context);

	virtual void onInstall() = 0;
	virtual void onUninstall() = 0;

	virtual void Activate() = 0;

private:
	//Node * modelNode;
};