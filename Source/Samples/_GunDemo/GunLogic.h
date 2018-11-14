#pragma once

#include <Urho3D/Input/Controls.h>
#include <Urho3D/Scene/LogicComponent.h>

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

private:
	/// Grounded flag for movement.
	bool onGround_;
	/// Jump flag.
	bool okToJump_;
	/// In air timer. Due to possible physics inaccuracy, character can be off ground for max. 1/10 second and still be allowed to move.
	float inAirTimer_;

	// Values are min and max, controlled by a 0 to 1 scale to determine rotations, positions along axes etc.
	Vector2 trigger_values; // Degrees on local X axis
	Vector2 hammer_values; // Degrees on local X axis
	Vector2 safety_values; // Degrees on local X axis - should control both sides 
	Vector2 slide_values = Vector2(0.0f, -0.4f); // Along local Y axis
	Vector2 round0_values; // Not used yet
	Vector2 round1_values; // Not used yet
	Vector2 roundCh_values; // Not used yet
	Vector2 magazine_values; // Along local Y axis

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
