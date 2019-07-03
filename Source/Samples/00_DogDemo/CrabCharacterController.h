#pragma once
#include <Urho3D/Urho3DAll.h>
#include <ModuleSocket.h>

class btPairCachingGhostObject;
class btKinematicCharacterController;

class CrabCharacterController : public LogicComponent {
	URHO3D_OBJECT(CrabCharacterController, LogicComponent);

public:
	CrabCharacterController(Context* context);
	virtual ~CrabCharacterController() override;
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

	AnimationController* animControl_;

	void HandleNodeCollision(StringHash eventType, VariantMap& eventData);
	void DebugGhostCollision(StringHash eventType, VariantMap& eventData);

private:
	virtual void DelayedStart() override;
	virtual void FixedUpdate(float timeStep) override;
	virtual void Update(float timeStep) override;

	Vector3 Accelerate(Vector3 accelDir, Vector3 prevVelocity, float accelerate, float max_velocity, float time);
	Vector3 MoveGround(Vector3 accelDir, Vector3 prevVelocity, float time);
	Vector3 MoveAir(Vector3 accelDir, Vector3 prevVelocity, float time);

	//const float friction = 10.0f; //10.0f; // 5.0f; //10.0f;
	const float friction = 10.0f; //10.0f; // 5.0f; //10.0f;
	 // 100 // 0.1f?
	const float MOVE_SPEED_AIR = 0.1f; // 0.1f


	const float air_accelerate_default = 0.1f;
	const float air_accelerate_rockets = 2.0f;
	float air_accelerate = air_accelerate_default; // 16 //2.0f; // 0.1f

	const float ground_accelerate_default = 0.8f; // 2.0f
	const float ground_accelerate_advanced = 2.0f;
	float ground_accelerate = ground_accelerate_default; // 16.0f;
	const float MOVE_SPEED_DEFAULT = 0.1f;
	const float MOVE_SPEED_ADVANCED = 0.15f;
	float MOVE_SPEED = MOVE_SPEED_DEFAULT;

	const float velocityWalkSpeedFactor = 20.0f; //20.0f

	ModuleSocket* backSocket;

};
