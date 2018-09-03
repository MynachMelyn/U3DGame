#pragma once

#include <Urho3D/Scene/LogicComponent.h>

using namespace Urho3D;
/// Character component, responsible for physical movement according to controls, as well as animation.
class Lightning : public LogicComponent {
	URHO3D_OBJECT(Lightning, LogicComponent);

public:
	///Construct.
	explicit Lightning(Context* context);

	/// Register object factory and attributes.
	static void RegisterObject(Context* context);

	/// Handle startup. Called by LogicComponent base class.
	void Start() override;
	/// Handle physics world update. Called by LogicComponent base class.
	void FixedUpdate(float timeStep) override;


	/// Stretch to a world-space point, via lookAt and scaling the local Z
	void extendToPoint();

	void setLifeTime(float lifeTime);

	void setTarget(Vector3 target);

private:
	// Blender to Urho size (Divide scale by this to get scene units)
	//const float LIGHTNING_SIZE = 15.0f;

	Vector3 target;

	float lifeTime = 1.0f;
	float timeAlive = 0.0f;
};