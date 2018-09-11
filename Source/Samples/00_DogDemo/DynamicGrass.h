#pragma once

#include <Urho3D/Scene/LogicComponent.h>
#include <Urho3D/Graphics/Material.h>

using namespace Urho3D;

class DynamicGrass : public LogicComponent {
	URHO3D_OBJECT(DynamicGrass, LogicComponent);

public:
	///Construct.
	DynamicGrass(Context* context);
	~DynamicGrass();

	/// Register object factory and attributes.
	static void RegisterObject(Context* context);

	/// Handle startup. Called by LogicComponent base class.
	void Start() override;
	void Update(float timeStep) override;
	void PostUpdate(float timeStep) override;

	void SetGrassMaterial(Material* material);
	void HandleNodeCollision(StringHash eventType, VariantMap& eventData);
protected:
	CollisionShape * collision = nullptr;
	Material * grassMaterial = nullptr;
	RigidBody* body = nullptr;
	VariantVector* varvec;
	VariantVector* sizevec;
	bool collidedThisFrame = false;

	const float yOffset = 2.0f; // Colliding object offset
	const float yStart = 0.05f;
	const float yEnd = 0.2f;
	const float maxWidth = 0.04f;
	const float grassSpeed = 1.0f;
	const float swayMax = 0.15f;
	const float grassRigidity = 1.4f;

	float Time = 0.0f;
};
