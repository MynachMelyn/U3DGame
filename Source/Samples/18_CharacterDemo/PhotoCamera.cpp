#include <Urho3D/Core/Context.h>
#include <Urho3D/Graphics/AnimationController.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/AnimatedModel.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/Technique.h>
#include <Urho3D/Graphics/RenderPath.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/Graphics/Renderer.h>


#include "PhotoCamera.h"

PhotoCamera::PhotoCamera(Context* context) :
	LogicComponent(context) {
	// Only the physics update event is needed: unsubscribe from the rest for optimisation
	SetUpdateEventMask(USE_FIXEDUPDATE);
}

void PhotoCamera::RegisterObject(Context* context) {
	context->RegisterFactory<PhotoCamera>();
}

void PhotoCamera::Start() {
	// this gets autocalled unfortunately
}

void PhotoCamera::Setup() {
	// Component has been inserted into its scene node. Subscribe to events now
	//SubscribeToEvent(GetNode(), E_NODECOLLISION, URHO3D_HANDLER(PhotoCamera, HandleNodeCollision));

	//renderer->SetNumViewports(2);

	// When making the camera, get the cameraNode and make it a child of the scene or whatever the parent is

	auto* cache = GetSubsystem<ResourceCache>();

	// Create a camera for the render-to-texture scene. Simply leave it at the world origin and let it observe the scene
	rttCameraNode = cameraNode->GetComponent<AnimatedModel>(false)->GetSkeleton().GetBone("Root")->node_->CreateChild("Camera");
	rttCameraNode->SetPosition(Vector3(0.0f, 0.0f, -1.0f));
	rttCameraNode->SetRotation(Quaternion(180, Vector3(0, 1, 0)));
	auto* camera = rttCameraNode->CreateComponent<Camera>();
	camera->SetFarClip(300.0f);
	// Because the rear viewport is rather small, disable occlusion culling from it. Use the camera's
	// "view override flags" for this. We could also disable eg. shadows or force low material quality
	// if we wanted
	camera->SetViewOverrideFlags(VO_DISABLE_OCCLUSION);


	// Create a "screen" like object for viewing the second scene. Construct it from two StaticModels, a box for the frame
	// and a plane for the actual view
	/*{
		Node* boxNode = GetScene()->CreateChild("ScreenBox");
		boxNode->SetPosition(Vector3(0.0f, 10.0f, 0.0f));
		boxNode->SetScale(Vector3(21.0f, 16.0f, 0.5f));
		auto* boxObject = boxNode->CreateComponent<StaticModel>();
		boxObject->SetModel(cache->GetResource<Model>("Models/Box.mdl"));
		boxObject->SetMaterial(cache->GetResource<Material>("Materials/Stone.xml"));

		Node* screenNode = GetScene()->CreateChild("Screen");
		screenNode->SetPosition(Vector3(0.0f, 10.0f, -0.27f));
		screenNode->SetRotation(Quaternion(-90.0f, 0.0f, 0.0f));
		screenNode->SetScale(Vector3(20.0f, 0.0f, 15.0f));
		auto* screenObject = screenNode->CreateComponent<StaticModel>();
		screenObject->SetModel(cache->GetResource<Model>("Models/Plane.mdl"));

		// Create a renderable texture (1024x768, RGB format), enable bilinear filtering on it
		renderTexture = new Texture2D(context_);
		renderTexture->SetSize(1024, 768, Graphics::GetRGBFormat(), TEXTURE_RENDERTARGET);
		renderTexture->SetFilterMode(FILTER_BILINEAR);

		// Create a new material from scratch, use the diffuse unlit technique, assign the render texture
		// as its diffuse texture, then assign the material to the screen plane object
		SharedPtr<Material> renderMaterial(new Material(context_));
		renderMaterial->SetTechnique(0, cache->GetResource<Technique>("Techniques/DiffUnlit.xml"));
		renderMaterial->SetTexture(TU_DIFFUSE, renderTexture);
		// Since the screen material is on top of the box model and may Z-fight, use negative depth bias
		// to push it forward (particularly necessary on mobiles with possibly less Z resolution)
		renderMaterial->SetDepthBias(BiasParameters(-0.001f, 0.0f));
		screenObject->SetMaterial(renderMaterial);
	}*/

	MakeViewport();
}

void PhotoCamera::FixedUpdate(float timeStep) {
	//todo Could cache the components for faster access instead of finding them each frame
	//auto* body = GetComponent<RigidBody>();
	//auto* animCtrl = node_->GetComponent<AnimationController>(true);

	if (focusChange != 0) {
		if (!changeAperture) {
			// First, get the value as a proportion of how many seconds have passed this step
			float currentValue = cameraRenderPath->GetShaderParameter("Focus").GetFloat();
			currentValue += focusChange * timeStep;
			currentValue = Clamp(currentValue, 0.0f, 1.0f);
			cameraRenderPath->SetShaderParameter("Focus", currentValue);
			cameraRenderPathDebug->SetShaderParameter("Focus", currentValue);
			focusChange = 0;
		} else {
			float currentValue = cameraRenderPath->GetShaderParameter("Bias").GetFloat();
			currentValue += focusChange * timeStep * 20;
			currentValue = Clamp(currentValue, 0.5f, 15.0f);
			cameraRenderPath->SetShaderParameter("Bias", currentValue);
			cameraRenderPathDebug->SetShaderParameter("Bias", currentValue);
		}
		focusChange = 0;
	}
}

void PhotoCamera::MakeViewport() {
	// Get the texture's RenderSurface object (exists when the texture has been created in rendertarget mode)
	// and define the viewport for rendering the second scene, similarly as how backbuffer viewports are defined
	// to the Renderer subsystem. By default the texture viewport will be updated when the texture is visible
	// in the main view
	auto* cache = GetSubsystem<ResourceCache>();
	//RenderSurface* surface = renderTexture->GetRenderSurface();

	// NEW
	auto* graphics = GetSubsystem<Graphics>();
	auto* renderer = GetSubsystem<Renderer>();
	SharedPtr<Viewport> rttViewport(new Viewport(this->GetContext(), this->GetScene(), rttCameraNode->GetComponent<Camera>(),
		IntRect(graphics->GetWidth() * 2 / 3,
			32,
			graphics->GetWidth() - 32,
			graphics->GetHeight() / 3)
	));

	SharedPtr<Viewport> rttViewportDebug(new Viewport(this->GetContext(), this->GetScene(), rttCameraNode->GetComponent<Camera>(),
		IntRect(graphics->GetWidth() * 2 / 3,
			graphics->GetHeight() / 3,
			graphics->GetWidth() - 32,
			graphics->GetHeight() * 2 / 3)
	));


	float blurClamp = 1.0f;
	float bias = 8.0f;
	float focus = 0.3f;
	float proximityMultiplier = 1.5f;

	rttViewport->SetRenderPath(cache->GetResource<XMLFile>("CoreData/RenderPaths/ForwardHWDepth.xml"));
	rttViewport->GetRenderPath()->Append(cache->GetResource<XMLFile>("PostProcess/DoFFinal.xml"));
	//rttViewport->GetRenderPath()->Append(cache->GetResource<XMLFile>("PostProcess/Blur.xml"));
	rttViewport->GetRenderPath()->SetShaderParameter("BlurClamp", blurClamp);
	rttViewport->GetRenderPath()->SetShaderParameter("Bias", bias);
	rttViewport->GetRenderPath()->SetShaderParameter("Focus", focus);
	rttViewport->GetRenderPath()->SetShaderParameter("ProximityMultiplier", proximityMultiplier);


	rttViewportDebug->SetRenderPath(cache->GetResource<XMLFile>("CoreData/RenderPaths/ForwardHWDepth.xml"));
	rttViewportDebug->GetRenderPath()->Append(cache->GetResource<XMLFile>("PostProcess/DoFFinalDebug.xml"));
	rttViewportDebug->GetRenderPath()->SetShaderParameter("BlurClamp", blurClamp);
	rttViewportDebug->GetRenderPath()->SetShaderParameter("Bias", bias);
	rttViewportDebug->GetRenderPath()->SetShaderParameter("Focus", focus);
	rttViewportDebug->GetRenderPath()->SetShaderParameter("ProximityMultiplier", proximityMultiplier);
	//surface->SetViewport(0, rttViewport);

	renderer->SetNumViewports(3);
	renderer->SetViewport(1, rttViewport);
	renderer->SetViewport(2, rttViewportDebug);

	cameraRenderPath = rttViewport->GetRenderPath();
	cameraRenderPathDebug = rttViewportDebug->GetRenderPath();
}

void PhotoCamera::snapAPhoto() {
	//wow!
	//float currentValue = cameraRenderPath->GetShaderParameter("Focus").GetFloat();
	//currentValue += 0.1f;
	//currentValue = Clamp(currentValue, 0.0f, 1.0f);
	//cameraRenderPath->SetShaderParameter("Focus", currentValue);
	//cameraRenderPathDebug->SetShaderParameter("Focus", currentValue);
}

void PhotoCamera::changeFocus(float valuePerSecond, float timeStep) {

}

