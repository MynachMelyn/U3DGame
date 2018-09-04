#include <Urho3D/Core/Context.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/Material.h>

#include <array>
#include <Lightning.h>


Lightning::Lightning(Context* context) : LogicComponent(context) {
	// Only the physics update event is needed: unsubscribe from the rest for optimisation
	SetUpdateEventMask(USE_FIXEDUPDATE);
}

void Lightning::RegisterObject(Context* context) {
	context->RegisterFactory<Lightning>();
}

const std::string Lightning::thinNames[] = { "Lightning/Models/Lightning_1.mdl", "Lightning/Models/Lightning_2.mdl", "Lightning/Models/Lightning_3.mdl" };
const std::string Lightning::thickNames[] = { "Lightning/Models/Lightning_1Thick.mdl", "Lightning/Models/Lightning_2Thick.mdl", "Lightning/Models/Lightning_3Thick.mdl" };
std::array<Model*, 3> Lightning::thinModels = {};
std::array<Model*, 3> Lightning::thickModels = {};
Material* Lightning::lightningMat = nullptr;

void Lightning::Start() {
	auto* cache = GetSubsystem<ResourceCache>();

	//Load the models!
	if (Lightning::thinModels[0] == nullptr || Lightning::thickModels[0] == nullptr) {
		int i = 0;
		for (auto fileName : Lightning::thickNames) {
			// Load the model, get its pointer and stick it in the list
			Lightning::thickModels[i] = cache->GetResource<Model>(String(fileName.c_str()));
			i++;
		}
		i = 0;
		for (auto fileName : Lightning::thinNames) {
			Lightning::thinModels[i] = cache->GetResource<Model>(String(fileName.c_str()));
			i++;
		}
	}

	if (Lightning::lightningMat == nullptr) {
		Lightning::lightningMat = cache->GetResource<Material>("Lightning/Materials/Lightning.xml");
	}


	// Component has been inserted into its scene node. Subscribe to events now
	//SubscribeToEvent(GetNode(), E_NODECOLLISION, URHO3D_HANDLER(NewCharacter, HandleNodeCollision));

	SetRandomSeed(Time::GetSystemTime());

	auto* visuals = node_->CreateComponent<StaticModel>();

	// 40% chance of THICC lightning
	if (Random(0.0f, 1.0f) < 0.4f) {
		thiccLightning = true;
		//visuals->SetModel(thickModels[Random(0, thickModels.size())]);
	} else {
		//visuals->SetModel(thinModels[Random(0, thinModels.size())]);
	}
}

void Lightning::extendToPoint() {
	node_->LookAt(target, Vector3::UP, Urho3D::TS_WORLD);
	// Stretch toward the point. Could add a small 15%ish x and y scaling as well?
	float scale = (node_->GetPosition() - target).Length();

	// Different x-y scaling depending on distance zapping and on lightning thickness
	float zigzagginess = (thiccLightning) ? Max(Min((-scale / 2) + 2.5f, 2), 0.4) : Max(Min((-scale / 2) + 4.5f, 4), 0.8);

	node_->SetScale(Vector3(zigzagginess, zigzagginess, scale));
}

void Lightning::FixedUpdate(float timeStep) {
	extendToPoint();

	timeAlive += timeStep;
	if (timeAlive > lifeTime) {
		node_->Remove();
	}

	modelTime += timeStep;
	if (modelTime > modelCycleTime) {
		if (visuals == nullptr) {
			visuals = node_->GetComponent<StaticModel>();
		}

		int prevModelIndex = currentModelIndex;
		while (currentModelIndex == prevModelIndex) {
			currentModelIndex = Random(0, thiccLightning ? thickModels.size() : thinModels.size());
		}
		visuals->SetModel(
			(thiccLightning) ?
			Lightning::thickModels[currentModelIndex] :
			Lightning::thinModels[currentModelIndex]
		);

		visuals->SetMaterial(Lightning::lightningMat);
		modelTime = 0.0f;
	}
}

void Lightning::setLifeTime(float lifeTime) {
	this->lifeTime = lifeTime;
}

void Lightning::setTarget(Vector3 target) {
	this->target = target;
}