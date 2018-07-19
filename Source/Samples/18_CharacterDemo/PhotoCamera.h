#pragma once

#include <Urho3D/Scene/LogicComponent.h>
#include <Urho3D/Graphics/AnimatedModel.h>
#include <Urho3D/Graphics/RenderPath.h>

using namespace Urho3D;

class PhotoCamera : public LogicComponent {
	URHO3D_OBJECT(PhotoCamera, LogicComponent);

public:
	///Construct.
	explicit PhotoCamera(Context* context);

	/// Register object factory and attributes.
	static void RegisterObject(Context* context);

	/// Handle startup. Called by LogicComponent base class.
	void Start() override;
	/// Handle physics world update. Called by LogicComponent base class.
	void FixedUpdate(float timeStep) override;

	void snapAPhoto();
	void changeFocus(float valuePerSecond, float timeStep);

	void MakeViewport();

	void Setup();

	Node* rttCameraNode;
	AnimatedModel* cameraModel;
	Node* cameraNode;
	Scene* scene;
	SharedPtr<Texture2D> renderTexture;
	SharedPtr<RenderPath> cameraRenderPath;
	SharedPtr<RenderPath> cameraRenderPathDebug;

	int focusChange = 0;
	bool changeAperture = false;
};