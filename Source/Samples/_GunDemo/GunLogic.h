#pragma once

#include <Urho3D/Input/Controls.h>
#include <Urho3D/Scene/LogicComponent.h>
#include "Magazine.h"

using namespace Urho3D;

const unsigned CTRL_FORWARD = 1;
const unsigned CTRL_BACK = 2;
const unsigned CTRL_LEFT = 4;
const unsigned CTRL_RIGHT = 8;
const unsigned CTRL_JUMP = 16;


class GunLogic : public LogicComponent {
	URHO3D_OBJECT(GunLogic, LogicComponent);

public:
	/// Construct.
	explicit GunLogic(Context* context);

	/// Register object factory and attributes.
	static void RegisterObject(Context* context);

	/// Handle startup. Called by LogicComponent base class.
	void Start() override;
	/// Handle physics world update. Called by LogicComponent base class.
	void FixedUpdate(float timeStep) override;

	void DelayedStart();

	/// Movement controls. Assigned by the main program each frame.
	Controls controls_;

	enum Component {
		trigger_component, hammer_component, safety_component, slide_component, magazine_component
	};

	void moveComponent(Component component, float percent);

	void rackSlideBack();
	//void letGoOfSlide();
	void inspectChamber();
	void blastBackSlide();
	void cockHammer(float speed = 0.5f);
	void turnSafetyOn();
	void pullTrigger();
	void releaseTrigger();
	void releaseHammer();
	void releaseSlide();

	void fireBullet();
	void ejectShell();
	void chamberRound();

	bool hammer_being_moved = false;
	float hammer_speed = 0.0f;
	bool hammer_cocked = false;

	bool slide_being_moved = false;
	bool slideLocked = false;
	float slide_speed = 0.0f;

	bool safety_on = false;

	bool trigger_being_pulled = false;
	bool trigger_in_motion = false;
	float trigger_speed = 0.2f;

	Magazine* magazine_logic;
	bool is_round_chambered = false;

	Node* gunMagBone;

private:
	void insertMagazine(Magazine* mag);
	void ejectMagazine();

	// Values are min and max, controlled by a 0 to 1 scale to determine rotations, positions along axes etc.
	Vector2 trigger_values = Vector2(0.0f, 55.0f); // Degrees on local X axis
	Vector2 hammer_values = Vector2(0.0f, -55.0f); // Degrees on local X axis
	Vector2 safety_values; // Degrees on local X axis - should control both sides 
	Vector2 slide_values = Vector2(0.0f, -0.4f); // Along local Y axis
	Vector2 round0_values; // Not used yet
	Vector2 round1_values; // Not used yet
	Vector2 roundCh_values; // Not used yet
	Vector2 magazine_values = Vector2(0.0f, -1.0f); // Along local Y axis

	// Masks for the above values, to be multiplied. Local axes only.
	const Vector3 trigger_axismask = Vector3(1, 0, 0);
	const Vector3 hammer_axismask = Vector3(1, 0, 0);
	const Vector3 safety_axismask = Vector3(1, 0, 0);
	const Vector3 slide_axismask = Vector3(0, 1, 0);
	const Vector3 round0_axismask = Vector3();
	const Vector3 round1_axismask = Vector3();
	const Vector3 roundCh_axismask = Vector3();
	const Vector3 magazine_axismask = Vector3(0, 1, 0);

	Vector3 slide_position, round0_position, round1_position, roundCh_position, magazine_position;

	Quaternion trigger_rotation, hammer_rotation, safety_rotation, decocker_rotation;

	// Controls the 0 to 1 scale for progressing between the two values specified above (pos or rot)
	float slide_percent = 0.0f, trigger_percent = 0.0f, hammer_percent = 0.0f, safety_percent = 0.0f, decocker_percent = 0.0f, magazine_percent = 0.0f;

	Node *trigger,
		*hammer,
		*slide,
		*decocker,
		*magazine,
		*safety,
		*round0,
		*round1,
		*roundCh;

	void moveComponent(Node* node, Vector3 origin, Vector2 values, Vector3 mask, float scale);
	void rotateComponent(Node* node, Quaternion origin, Vector2 values, Vector3 mask, float scale);
};
