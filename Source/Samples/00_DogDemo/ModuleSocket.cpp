#include <Global.h>
#include <ModuleSocket.h>

ModuleSocket::ModuleSocket(Context* context) :
	LogicComponent(context) {
	SetUpdateEventMask(USE_UPDATE);
}

void ModuleSocket::RegisterObject(Context* context) {
	context->RegisterFactory<ModuleSocket>();
}

bool ModuleSocket::Install(CrabModule* module) {
	if (module->GetSocketType() == type) {
		installedModule = module;
		installedModule->GetNode()->SetParent(GetNode());
		installedModule->GetNode()->SetPosition(Vector3::ZERO);
		installedModule->GetNode()->SetRotation(Quaternion::IDENTITY);
		installedModule->GetNode()->SetScale(Vector3::ONE);
		module->onInstall();
		return true;
	}
	return false;
}

void ModuleSocket::Uninstall() {
	if (installedModule != nullptr) {
		installedModule->onUninstall();
		installedModule = nullptr;
	}
}

void ModuleSocket::SetSocketType(SocketType type) {
	this->type = type;
}

CrabModule* ModuleSocket::GetInstalledModule() {
	return installedModule;
}