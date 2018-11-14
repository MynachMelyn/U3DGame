#include <Urho3D/Core/Context.h>
#include <Urho3D/Graphics/AnimationController.h>
#include <Urho3D/IO/MemoryBuffer.h>
#include <Urho3D/Physics/PhysicsEvents.h>
#include <Urho3D/Physics/PhysicsWorld.h>
#include <Urho3D/Graphics/AnimatedModel.h>
#include <Urho3D/Physics/RigidBody.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>

#include "GunLogic.h"

GunLogic::GunLogic(Context* context) :
	LogicComponent(context),
	onGround_(false),
	okToJump_(true),
	inAirTimer_(0.0f) {
	// Only the physics update event is needed: unsubscribe from the rest for optimization
	SetUpdateEventMask(USE_FIXEDUPDATE);
}

void GunLogic::RegisterObject(Context* context) {
	context->RegisterFactory<GunLogic>();
}

void GunLogic::Start() {
	// Component has been inserted into its scene node. Subscribe to events now
}

void GunLogic::DelayedStart() {

	// First, acquire the node names of the bones.
	Skeleton gunSkeleton = node_->GetComponent<AnimatedModel>()->GetSkeleton();
	Vector<Bone> bones = gunSkeleton.GetBones();
	Node* gripBone;
	for (Bone bone : bones) {
		// Allow manual control
		bone.animated_ = false;
		if (bone.name_ == "Grip") {
			gripBone = bone.node_;
		}
	}

	trigger = gripBone->GetChild(String("Trigger"), true);
	hammer = gripBone->GetChild(String("Hammer"), true);
	slide = gripBone->GetChild(String("Slide"), true);
	magazine = gripBone->GetChild(String("Magazine"), true);
	safety = gripBone->GetChild(String("Safety"), true);
	round0 = gripBone->GetChild(String("ROUND0"), true);
	round1 = gripBone->GetChild(String("ROUND1"), true);
	roundCh = gripBone->GetChild(String("ROUNDCHAMBERED"), true);
	decocker = gripBone->GetChild(String("Decocker"), true);

	trigger_rotation = trigger->GetRotation();
	hammer_rotation = hammer->GetRotation();
	slide_position = slide->GetPosition();
	magazine_position = magazine->GetPosition();
	safety_rotation = safety->GetRotation();
	round0_position = round0->GetPosition();
	round1_position = round1->GetPosition();
	roundCh_position = roundCh->GetPosition();
	decocker_rotation = decocker->GetRotation();
}

float time;
void GunLogic::FixedUpdate(float timeStep) {
	time += timeStep;
	moveComponent(Component::slide_component, (Sin(time * 60.0f) / 2) + 0.5f);
}

void GunLogic::moveComponent(Node* node, Vector3 origin, Vector2 values, Vector3 mask, float scale) {
	Vector3 pos = mask * (values.x_ + scale * (values.y_ - values.x_));
	pos = node->GetRotation() * pos;
	node->SetPosition(
		origin + pos
	);
}

void GunLogic::rotateComponent(Node* node, Quaternion origin, Vector2 values, Vector3 mask, float scale) {
	Vector3 angle = mask * (values.x_ + scale * (values.y_ - values.x_));
	Quaternion q = Quaternion();
	q.FromEulerAngles(angle.x_, angle.y_, angle.z_);
	node->SetRotation(origin * q);
}

void GunLogic::moveComponent(Component component, float percent) {

	switch (component) {
	case Component::magazine_component:
		moveComponent(magazine, magazine_position, magazine_values, magazine_axismask, percent);
		break;
	case Component::slide_component:
		moveComponent(slide, slide_position, slide_values, slide_axismask, percent);
		break;
	case Component::trigger_component:
		rotateComponent(trigger, trigger_rotation, trigger_values, trigger_axismask, percent);
		break;
	case Component::hammer_component:
		rotateComponent(hammer, hammer_rotation, hammer_values, hammer_axismask, percent);
		break;
	case Component::safety_component:
		rotateComponent(safety, safety_rotation, safety_values, safety_axismask, percent);
		break;
	}
}
