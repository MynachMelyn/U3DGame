#include <Urho3D/Core/Context.h>
#include <CrabModule.h>

CrabModule::CrabModule(Context* context) : LogicComponent(context) {
	//SetUpdateEventMask(USE_UPDATE);
}

/*void CrabModule::RegisterObject(Context* context) {
	context->RegisterFactory<CrabModule>();
}*/