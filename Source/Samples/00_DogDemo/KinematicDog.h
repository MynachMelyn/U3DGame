#pragma once

#include <Urho3D/Input/Controls.h>
#include <Urho3D/Scene/LogicComponent.h>
#include <CharacterController.h>

using namespace Urho3D;

/// Character component, responsible for physical movement according to controls, as well as animation.
class KinematicDog : public LogicComponent {
	URHO3D_OBJECT(KinematicDog, LogicComponent);

public:
	///Construct.
	explicit KinematicDog(Context* context);

	/// Register object factory and attributes.
	static void RegisterObject(Context* context);

	/// Handle startup. Called by LogicComponent base class.
	void Start() override;
	void DelayedStart() override; //After first frame

								  /// Handle physics world update. Called by LogicComponent base class.
	void FixedUpdate(float timeStep) override;
	//void Update(float timeStep) override; //TEMP

	//void Update(float timeStep) override;

	/// Movement controls. Assigned by the main program each frame.
	Controls controls_;

private:
	/// Handle footsteps and foot particles
	void HandleAnimationTrigger(StringHash eventType, VariantMap& eventData);
	Node* modelNode;
	CharacterController* controller;
};