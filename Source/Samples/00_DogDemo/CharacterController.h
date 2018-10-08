#pragma once
#include <Urho3D/Urho3DAll.h>

class btPairCachingGhostObject;
class btKinematicCharacterController;

class CharacterController : public LogicComponent {
	URHO3D_OBJECT(CharacterController, LogicComponent);

public:
	CharacterController(Context* context);
	virtual ~CharacterController() override;
	static void RegisterObject(Context* context);

	Controls controls_;

	// Добавляет к ноде RigidBody и Shape.
	void CreatePhysComponents(float height);

	btPairCachingGhostObject* ghostObject_;
	btKinematicCharacterController* bulletController_;

	float height_;
	float diameter_;
	float accelerationTime_;
	Vector3 velocity_;
	//Vector3 resultantPlaneVelocity_;

	Vector3 getDeltaVelocity();


private:
	virtual void Start() override;
	virtual void FixedUpdate(float timeStep) override;
	virtual void Update(float timeStep) override;

	Vector3 prevPos;
};
