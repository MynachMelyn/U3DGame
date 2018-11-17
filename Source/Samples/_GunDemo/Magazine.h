//#pragma once

#include <Urho3D/Input/Controls.h>
#include <Urho3D/Scene/LogicComponent.h>
#include <Urho3D/Graphics/AnimatedModel.h>

using namespace Urho3D;


class Magazine : public LogicComponent {
	URHO3D_OBJECT(Magazine, LogicComponent);
public:
	explicit Magazine(Context* context);
	//Magazine(int capacity, int loaded);
	//~Magazine();

	static void RegisterObject(Context* context);

	/// Handle startup. Called by LogicComponent base class.
	void Start() override;
	/// Handle physics world update. Called by LogicComponent base class.
	void FixedUpdate(float timeStep) override;

	bool loadRound();
	bool removeRound();

	int maximumCapacity;
	int roundsLoaded;

	void setRoundsLoaded(int loaded);
	void setMaximumCapacity(int max);

	AnimatedModel* magazineModel;
	Node* magBoneNode;

	// Necessary to remove all translations n shit
	Node* parent;
	void moveToParent();
	void setParentBone(Node* parentBone);
	void disconnectFromParent();
	void slideOut();

	RigidBody* body;

	// Controlled externally, currently - bad design?
	//bool isLoaded;
};