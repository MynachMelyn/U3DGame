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
	magazineLogic = new Magazine(7, 7);
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

	rackSlideBack();
}

float time = -3.0f;
float time2 = -2.0f;
float time3 = 10.0f;
void GunLogic::FixedUpdate(float timeStep) {
	time += timeStep;
	time2 += timeStep;
	time3 += timeStep;

	//moveComponent(Component::hammer_component, (Sin(time * 60.0f) / 2) + 0.5f);
	//moveComponent(Component::slide_component, (Sin(time * 60.0f) / 2) + 0.5f);
	//moveComponent(Component::trigger_component, (Sin(time * 60.0f) / 2) + 0.5f);
	//moveComponent(Component::magazine_component, (Sin(time * 60.0f) / 2) + 0.5f);

	if (time3 > 12.0f) {
		releaseSlide();
	}

	if (time > 3.0f) {
		time = 0;
		//blastBackSlide();
		releaseTrigger();
	}

	if (time2 > 3.0f) {
		time2 = 0;
		pullTrigger();
	}

	// TODO 
	// Blast back slide or rack it
	if (slide_being_moved) {

		// Doesn't currently check for below zero.
		slide_percent = (slide_percent + slide_speed > 1.0f) ? 1.0f : slide_percent + slide_speed;

		// Use slide lock to prevent spring of slide from bringing it back to front - used to racking manually too!
		if (!slideLocked) {
			slide_speed -= 0.03f;
		}

		if (slide_percent <= 0.0f) {
			slide_speed = 0.0f;
			slide_percent = 0.0f;
			slide_being_moved = false;
		}

		if (slide_percent >= 1.0f && !slideLocked) {
			if (magazineLogic->roundsLoaded > 0) {
				slide_speed = -slide_speed * 0.05f; // Fake restitution.
				is_round_chambered = true;
				magazineLogic->removeRound();
			} else {
				slideLocked = true;
				slide_being_moved = true;
				slide_speed = 0.0f;
			}
		}

		if (slide_percent > 0.5f && !hammer_being_moved && !hammer_cocked) {
			cockHammer(0.6f);
		}

		moveComponent(Component::slide_component, slide_percent);
	}

	if (hammer_being_moved) {
		//hammer_percent = (hammer_percent + hammer_speed > 1.0f) ? 1.0f : hammer_percent + hammer_speed;
		hammer_percent += hammer_speed;

		if (hammer_percent >= 1.0f || hammer_percent <= 0.0f) {
			hammer_percent = Clamp(hammer_percent, 0.0f, 1.0f);
			hammer_cocked = hammer_percent == 1.0f; // Cock hammer if appropriate, otherwise set to 0
			hammer_being_moved = false; // Fix hammer in place

			if (!safety_on && hammer_percent <= 0.0f && Abs(hammer_speed) >= 0.7f) {
				fireBullet();
			}

			hammer_speed = 0.0f; // Stop hammer
		}

		moveComponent(Component::hammer_component, hammer_percent);
	}

	if (trigger_in_motion) {
		if (trigger_being_pulled) {
			trigger_percent += trigger_speed;
			if (trigger_percent >= 1.0f && !slideLocked) {
				trigger_in_motion = false;
				releaseHammer();
			}
		} else {
			trigger_percent -= trigger_speed;
			if (trigger_percent <= 0.0f) {
				trigger_in_motion = false;
			}
		}

		trigger_percent = Clamp(trigger_percent, 0.0f, 1.0f);

		moveComponent(Component::trigger_component, trigger_percent);
	}
}

void GunLogic::blastBackSlide() {
	slide_being_moved = true;
	slide_speed = 0.5f; // Send backwards
}

// Should work for cock and decock safely
void GunLogic::cockHammer(float speed) {
	if (!hammer_being_moved) {
		hammer_being_moved = true;
		hammer_speed = hammer_cocked ? -speed : speed;
		//hammer_speed = speed;
	}
}
void GunLogic::turnSafetyOn() {}

void GunLogic::pullTrigger() {
	trigger_being_pulled = true;
	trigger_in_motion = true;
}

void GunLogic::releaseTrigger() {
	trigger_being_pulled = false;
	trigger_in_motion = true;
}

void GunLogic::releaseHammer() {
	if (!hammer_being_moved && hammer_cocked) {
		hammer_being_moved = true;
		hammer_speed = -0.8f;
	}
}
void GunLogic::releaseSlide() {
	slideLocked = false;
	slide_being_moved = true;
	// Simply let it fall
}

void GunLogic::fireBullet() {
	if (is_round_chambered) {
		// BOOM!
		blastBackSlide();
		is_round_chambered = false;
	}
}

void GunLogic::rackSlideBack() {
	// release slide
	slide_being_moved = true;
	slide_speed = 0.05f;
	slideLocked = true;
}

void GunLogic::ejectShell() {}
void GunLogic::chamberRound() {}

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
