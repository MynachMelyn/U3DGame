#include <Urho3D/Core/Context.h>
#include <Urho3D/Graphics/AnimationController.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Graphics/Geometry.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/AnimatedModel.h>
#include <Urho3D/Graphics/Skeleton.h>


#include <KinematicDog.h>
#include <CharacterController.h>

KinematicDog::KinematicDog(Context* context) :
	LogicComponent(context) {
	// Only the physics update event is needed: unsubscribe from the rest for optimisation
	SetUpdateEventMask(USE_FIXEDUPDATE);
}

void KinematicDog::RegisterObject(Context* context) {
	context->RegisterFactory<KinematicDog>();
	context->RegisterFactory<CharacterController>();
}

void KinematicDog::Start() {

	auto* cache = GetSubsystem<ResourceCache>();

	modelNode = node_->CreateChild("Model Node");
	modelNode->SetPosition(Vector3(0.0f, 0.0f, 2.0f)); // Offset, to get the collider at the rear feet
	controller = node_->CreateComponent<CharacterController>();
	controller->CreatePhysComponents(1.0f); // 0.5

	auto* model = modelNode->CreateComponent<AnimatedModel>();
	model->SetModel(cache->GetResource<Model>("Beagle/Models/Geo_Beagle.mdl"));
	model->SetMaterial(cache->GetResource<Material>("Beagle/Materials/lambert2SGUnlit.xml"));
	model->SetCastShadows(true);
	modelNode->CreateComponent<AnimationController>();
	auto* animCtrl = modelNode->GetComponent<AnimationController>(true);
}

void KinematicDog::DelayedStart() {
	auto* cache = GetSubsystem<ResourceCache>();


	// Find the model adjustment node, don't do it recursively (should be top level)
	//SubscribeToEvent(modelNode, E_ANIMATIONTRIGGER, URHO3D_HANDLER(KinematicDog, HandleAnimationTrigger));
}


void KinematicDog::FixedUpdate(float timeStep) {
	auto* animCtrl = modelNode->GetComponent<AnimationController>(true);
	Vector3 planeVelocity = Vector3(controller->getDeltaVelocity().x_, 0.0f, controller->getDeltaVelocity().z_);

	// Load these anims
	if (!animCtrl->IsPlaying("Beagle/Models/RotateRight.ani")) {
		animCtrl->PlayExclusive("Beagle/Models/RotateRight.ani", 1, true, 0.0f);
		animCtrl->PlayExclusive("Beagle/Models/RotateLeft.ani", 1, true, 0.0f);
		animCtrl->SetBlendMode("Beagle/Models/RotateRight.ani", AnimationBlendMode::ABM_ADDITIVE);
		animCtrl->SetBlendMode("Beagle/Models/RotateLeft.ani", AnimationBlendMode::ABM_ADDITIVE);
		animCtrl->SetWeight("Beagle/Models/RotateRight.ani", 0.0f);
		animCtrl->SetWeight("Beagle/Models/RotateLeft.ani", 0.0f);
		animCtrl->SetRemoveOnCompletion("Beagle/Models/RotateRight.ani", false);
		animCtrl->SetRemoveOnCompletion("Beagle/Models/RotateLeft.ani", false);
	}
}

//void KinematicDog::HandleAnimationTrigger(StringHash eventType, VariantMap& eventData) {
//	using namespace AnimationTrigger;
//
//	AnimatedModel* model = modelNode->GetComponent<AnimatedModel>();
//	AnimationState* state = model->GetAnimationState(eventData[P_NAME].GetString());
//	if (!state) {
//		return;
//	}
//	//If the footstep is blended with a high enough weight, enable the particle effect
//
//	if (eventData[P_DATA].GetString().Contains("JUMP")) {
//		//auto* body = GetComponent<RigidBody>();
//		//body->ApplyImpulse(Vector3::UP * JUMP_FORCE + (node_->GetRotation() * Vector3::FORWARD * JUMP_FORCE * jumpBonus));
//		//jumpBonus = 0.0f;
//		//manualJumpAngling = true;
//
//	} else if (eventData[P_DATA].GetString().Contains("CANLAND")) {
//		//manualJumpAngling = false;
//		//canLand = true;
//
//	} else if (eventData[P_DATA].GetString().Contains("CANWALK")) {
//		//canLand = false;
//		//canWalk = true;
//
//	} else if (state->GetWeight() > 0.5f) {
//		String eventName = eventData[P_DATA].GetString();
//		for (Bone bone : model->GetSkeleton().GetBones()) {
//			if (bone.name_.Compare(eventName) == 0) {
//				Node* emitterNode = bone.node_->GetChild(bone.name_);
//				emitterNode->GetComponent<ParticleEmitter>()->SetEmitting(true);
//				emitterNode->GetComponent<SelfEmitToggler>()->resetTimer();
//			}
//		}
//	}
//}