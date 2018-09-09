#include <Urho3D/Core/Context.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Graphics/ParticleEmitter.h>
#include <SelfDestructor.h>


SelfDestructor::SelfDestructor(Context* context) : LogicComponent(context) {
	SetUpdateEventMask(USE_UPDATE);
}

void SelfDestructor::RegisterObject(Context* context) {
	context->RegisterFactory<SelfDestructor>();
}

void SelfDestructor::Start() {

}

void SelfDestructor::setTimer(float t) {
	timeMax = t;
	time = 0.0f;
	complete = false;
}

void SelfDestructor::resetTimer() {
	time = 0.0f;
	complete = false;
}

void SelfDestructor::Update(float timeStep) {
	if (!complete) {
		time += timeStep;
		if (time >= timeMax) {
			Destruct();
		}
	}
}


SelfEmitToggler::SelfEmitToggler(Context* context) : SelfDestructor(context) {
	SetUpdateEventMask(USE_UPDATE);
}

void SelfEmitToggler::RegisterObject(Context* context) {
	context->RegisterFactory<SelfEmitToggler>();
}

void SelfEmitToggler::Destruct() {
	ParticleEmitter* emitter = node_->GetComponent<ParticleEmitter>();
	if (emitter) {
		emitter->SetEmitting(false);
	}
}


SelfNodeRemover::SelfNodeRemover(Context* context) : SelfDestructor(context) {
	SetUpdateEventMask(USE_UPDATE);
}

void SelfNodeRemover::RegisterObject(Context* context) {
	context->RegisterFactory<SelfNodeRemover>();
}

void SelfNodeRemover::Destruct() {
	node_->Remove();
}