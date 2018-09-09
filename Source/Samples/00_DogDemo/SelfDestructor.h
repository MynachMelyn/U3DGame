#pragma once

#include <Urho3D/Scene/LogicComponent.h>

using namespace Urho3D;

class SelfDestructor : public LogicComponent {
	URHO3D_OBJECT(SelfDestructor, LogicComponent);

public:
	///Construct.
	SelfDestructor(Context* context);

	/// Register object factory and attributes.
	static void RegisterObject(Context* context);

	/// Handle startup. Called by LogicComponent base class.
	void Start() override;
	void Update(float timeStep) override;


	void setTimer(float t);

	void resetTimer();

	virtual void Destruct() {}; //Only to be overriden, no base.

protected:
	float time = 0.0f;
	float timeMax = 0.0f;
	bool complete = false;
};

class SelfEmitToggler : public SelfDestructor {
	URHO3D_OBJECT(SelfEmitToggler, SelfDestructor);
public:
	SelfEmitToggler(Context* context);
	static void RegisterObject(Context* context);
protected:
	void Destruct() override;
};

class SelfNodeRemover : public SelfDestructor {
	URHO3D_OBJECT(SelfNodeRemover, SelfDestructor);
public:
	SelfNodeRemover(Context* context);
	static void RegisterObject(Context* context);
protected:
	void Destruct() override;
};