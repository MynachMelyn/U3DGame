#include <Urho3D/Core/Context.h>
#include <Urho3D/Graphics/AnimationController.h>
#include <Urho3D/IO/MemoryBuffer.h>
#include <Urho3D/Physics/PhysicsEvents.h>
#include <Urho3D/Physics/PhysicsWorld.h>
#include <Urho3D/Physics/CollisionShape.h>
#include <Urho3D/Graphics/AnimatedModel.h>
#include <Urho3D/Physics/RigidBody.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>


#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Graphics/AnimatedModel.h>

#include "Magazine.h"



//Magazine::Magazine(int capacity = 0, int loaded = 0) {
//	maximumCapacity = capacity;
//	roundsLoaded = loaded;
//}

Magazine::Magazine(Context* context) :
	LogicComponent(context) {
	// Only the physics update event is needed: unsubscribe from the rest for optimization
	SetUpdateEventMask(USE_FIXEDUPDATE);
	maximumCapacity = 0;
	roundsLoaded = 0;
	parent = nullptr;
}

void Magazine::RegisterObject(Context* context) {
	context->RegisterFactory<Magazine>();
}

void Magazine::Start() {
	auto* cache = GetSubsystem<ResourceCache>();
	magazineModel = GetNode()->CreateComponent<AnimatedModel>();
	magazineModel->SetModel(cache->GetResource<Model>("Firearms/Models/MAG.mdl"));

	Skeleton magSkeleton = magazineModel->GetSkeleton();
	Vector<Bone> bones = magSkeleton.GetBones();
	for (Bone bone : bones) {
		// Allow manual control
		bone.animated_ = false;
		if (bone.name_ == "Magazine") {
			magBoneNode = bone.node_;
		}
	}

	body = magBoneNode->CreateComponent<RigidBody>();
	body->SetMass(1.0f);
	CollisionShape* shape = magBoneNode->CreateComponent<CollisionShape>();
	shape->SetBox(Vector3(0.2f, 1.2f, 0.3f), Vector3(0.0f, 0.05f, 0.0f), Quaternion(-5.0f, 0.0f, 0.0f));
}


void Magazine::FixedUpdate(float timeStep) {
	moveToParent();
}

void Magazine::moveToParent() {
	// This is causing issues in reading??
	if (nullptr != parent) {
		//magBoneNode->SetWorldTransform(parent->GetWorldTransform());
		magBoneNode->SetParent(parent);
		magBoneNode->SetTransform(Matrix3x4::IDENTITY);
	}
}

void Magazine::slideOut() {
	// used to slide it out - could be in gun?

	// THIS PART IS TEMPORARY - RRRRRRRRRRRGGGGHHH
	disconnectFromParent();
}

void Magazine::disconnectFromParent() {
	magBoneNode->SetTransform(magBoneNode->GetWorldTransform()); // Keep in same place
	setParentBone(nullptr);
	node_->SetParent(GetScene());
	body->SetEnabled(true);
	body->SetTransform(magBoneNode->GetPosition(), magBoneNode->GetRotation());
}

void Magazine::setParentBone(Node* parentBone) {
	parent = parentBone;
	if (parentBone != nullptr) {
		body->SetEnabled(false);
	} else {
		body->SetEnabled(true);
	}
}

bool Magazine::loadRound() {
	if (roundsLoaded++ > maximumCapacity) {
		roundsLoaded--;
		return false;
	}
	return true;
}

bool Magazine::removeRound() {
	if (roundsLoaded-- < 0) {
		roundsLoaded = 0;
		return false;
	}
	return true;
}

void Magazine::setRoundsLoaded(int loaded) {
	roundsLoaded = loaded;
}

void Magazine::setMaximumCapacity(int max) {
	maximumCapacity = max;
}
//Magazine::~Magazine() {
//}
