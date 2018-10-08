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
	void CreatePhysComponents(float height, float diameter);

	btPairCachingGhostObject* ghostObject_;
	btKinematicCharacterController* bulletController_;

	float height_;
	float diameter_;
	float accelerationTime_;
	Vector3 velocity_;


private:
	virtual void Start() override;
	virtual void FixedUpdate(float timeStep) override;
	virtual void Update(float timeStep) override;

	Vector3 Accelerate(Vector3 accelDir, Vector3 prevVelocity, float accelerate, float max_velocity, float time);
	Vector3 MoveGround(Vector3 accelDir, Vector3 prevVelocity, float time);
	Vector3 MoveAir(Vector3 accelDir, Vector3 prevVelocity, float time);

	const float friction = 10.0f;
	const float MOVE_SPEED = 10.0f;
	const float air_accelerate = 0.02f;
	const float ground_accelerate = 1.0f;

};
