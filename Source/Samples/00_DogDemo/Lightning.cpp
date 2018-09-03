#include <Urho3D/Core/Context.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/Material.h>

#include "Lightning.h"

Lightning::Lightning(Context* context) : LogicComponent(context) {
	// Only the physics update event is needed: unsubscribe from the rest for optimisation
	SetUpdateEventMask(USE_FIXEDUPDATE);
}

void Lightning::RegisterObject(Context* context) {
	context->RegisterFactory<Lightning>();
}

void Lightning::Start() {
	// Component has been inserted into its scene node. Subscribe to events now
	//SubscribeToEvent(GetNode(), E_NODECOLLISION, URHO3D_HANDLER(NewCharacter, HandleNodeCollision));
	auto* cache = GetSubsystem<ResourceCache>();

	auto* visuals = node_->CreateComponent<StaticModel>();
	visuals->SetModel(cache->GetResource<Model>("Lightning/Models/Lightning1Thick.mdl"));
	//visuals->SetModel(cache->GetResource<Model>("Lightning/Models/Line.mdl"));

	visuals->SetMaterial(cache->GetResource<Material>("Lightning/Materials/Lightning.xml"));
}

void Lightning::extendToPoint() {
	node_->LookAt(target, Vector3::UP, Urho3D::TS_WORLD);
	// Stretch toward the point. Could add a small 15%ish x and y scaling as well?
	float scale = (node_->GetPosition() - target).Length();
	//float scale = (node_->GetPosition() - target).Length();
	node_->SetScale(Vector3(0.7f * scale, 0.7f * scale, scale));
}

void Lightning::FixedUpdate(float timeStep) {
	extendToPoint();

	timeAlive += timeStep;
	if (timeAlive > lifeTime) {
		node_->Remove();
	}
}

void Lightning::setLifeTime(float lifeTime) {
	this->lifeTime = lifeTime;
}

void Lightning::setTarget(Vector3 target) {
	this->target = target;
}