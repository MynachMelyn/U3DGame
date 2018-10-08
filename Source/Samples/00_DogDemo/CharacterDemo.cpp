//
// Copyright (c) 2008-2018 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Core/ProcessUtils.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Engine/EngineDefs.h>
#include <Urho3D/Graphics/AnimatedModel.h>
#include <Urho3D/Graphics/AnimationController.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Light.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/Zone.h>
#include <Urho3D/Input/Controls.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/Physics/CollisionShape.h>
#include <Urho3D/Physics/PhysicsWorld.h>
#include <Urho3D/Physics/Constraint.h>
#include <Urho3D/Physics/RigidBody.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/UI/Font.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/Window.h>
#include <Urho3D/Graphics/RenderPath.h>
#include <Urho3D/Graphics/Geometry.h>


#include "KinematicDog.h"
#include "CharacterDemo.h"
#include "Touch.h"
#include <DynamicGrass.h>


// Debug stuff
#include <iostream>
#include <fstream>

#include <Urho3D/DebugNew.h>

// Expands to this example's entry-point
URHO3D_DEFINE_APPLICATION_MAIN(CharacterDemo)

CharacterDemo::CharacterDemo(Context* context) :
	Sample(context),
	firstPerson_(false) {
	// Register factory and attributes for the Character component so it can be created via CreateComponent, and loaded / saved
	KinematicDog::RegisterObject(context);
	DynamicGrass::RegisterObject(context);
}

CharacterDemo::~CharacterDemo() = default;

void CharacterDemo::Setup() {
	engineParameters_[EP_FULL_SCREEN] = false;
	engineParameters_[EP_WINDOW_TITLE] = "Unbenanntes Fenster";
	//engineParameters_[“VSync”] = true;
	engineParameters_[EP_WINDOW_WIDTH] = 1800;
	engineParameters_[EP_WINDOW_HEIGHT] = 980;
}

void CharacterDemo::Start() {
	// Execute base class startup
	Sample::Start();

	if (touchEnabled_)
		touch_ = new Touch(context_, TOUCH_SENSITIVITY);

	// Create static scene content
	CreateScene();

	// Create the controllable character
	CreateCharacter();

	// Create the UI content
	//CreateInstructions();

	//Hide logo
	SetLogoVisible(false);

	// Subscribe to necessary events
	SubscribeToEvents();

	SetupViewport();

	// Set the mouse mode to use in the sample
	Sample::InitMouseMode(MM_RELATIVE);
}

void CharacterDemo::SetupViewport() {
	auto* cache = GetSubsystem<ResourceCache>();
	//RenderSurface* surface = renderTexture->GetRenderSurface();

	// NEW
	auto* graphics = GetSubsystem<Graphics>();
	auto* renderer = GetSubsystem<Renderer>();

	SharedPtr<Viewport> rttViewport(new Viewport(context_, scene_, cameraNode_->GetComponent<Camera>(), IntRect(0.0f, 0.0f, 1920.0f, 1080.0f)));

	// THIS IS FOR TOGGLING THE DOWNSAMPLING
	//rttViewport->SetRenderPath(cache->GetResource<XMLFile>("CoreData/RenderPaths/ForwardHWDepth_lowres.xml"));
	rttViewport->SetRenderPath(cache->GetResource<XMLFile>("CoreData/RenderPaths/ForwardHWDepth.xml"));

	// DO NOT DO THESE
	//rttViewport->GetRenderPath()->Append(cache->GetResource<XMLFile>("PostProcess/Dither.xml"));
	//rttViewport->GetRenderPath()->Append(cache->GetResource<XMLFile>("PostProcess/Downscaler.xml"));
	//rttViewport->GetRenderPath()->Append(cache->GetResource<XMLFile>("PostProcess/SpriteShader.xml"));
	//rttViewport->GetRenderPath()->SetShaderParameter("RTDimensions", Vector2(rttViewport->GetRect().Width(), rttViewport->GetRect().Height()));
	//rttViewport->GetRenderPath()->SetShaderParameter("LowResDimensions", Vector2(6.0f, 6.0f));

	rttViewport->GetRenderPath()->Append(cache->GetResource<XMLFile>("PostProcess/Bloom.xml"));

	rttViewport->GetRenderPath()->Append(cache->GetResource<XMLFile>("PostProcess/DoFBlog.xml"));
	rttViewport->GetRenderPath()->SetShaderParameter("Far", rttViewport->GetCamera()->GetFarClip());
	rttViewport->GetRenderPath()->SetShaderParameter("ResWidth", 1920.0);
	//rttViewport->GetRenderPath()->SetShaderParameter("FWheel", 0.86); // for (0, 10, 10) camera pos with lookat
	rttViewport->GetRenderPath()->SetShaderParameter("FWheel", 0.934f);
	rttViewport->GetRenderPath()->SetShaderParameter("FocalLengthMM", 70.0);
	//rttViewport->GetRenderPath()->SetShaderParameter("Aperture", 1.3f);
	rttViewport->GetRenderPath()->SetShaderParameter("Aperture", 0.5f);

	renderer->SetViewport(0, rttViewport);
}

void CharacterDemo::CreateScene() {
	auto* cache = GetSubsystem<ResourceCache>();
	auto* renderer = GetSubsystem<Renderer>();
	auto* graphics = GetSubsystem<Graphics>(); //for ortho

	renderer->SetHDRRendering(true);

	scene_ = new Scene(context_);

	///////////////////
	SharedPtr<File> file = cache->GetFile("Scenes/Forest_demo.xml");
	scene_->LoadXML(*file);
	///////////////////

	// Create scene subsystem components
	scene_->CreateComponent<Octree>();
	scene_->CreateComponent<PhysicsWorld>();

	// Create camera and define viewport. We will be doing load / save, so it's convenient to create the camera outside the scene,
	// so that it won't be destroyed and recreated, and we don't have to redefine the viewport on load
	cameraNode_ = new Node(context_);
	auto* camera = cameraNode_->CreateComponent<Camera>();
	camera->SetFarClip(300.0f);
	cameraNode_->SetPosition(Vector3(0.0f, 10.0f, -10.0f));

	camera->SetOrthographic(true); // Set camera orthographic
	camera->SetOrthoSize((float)graphics->GetHeight() * 0.012); // Set camera ortho size (the value of PIXEL_SIZE is 0.01)

	// Set up a viewport to the Renderer subsystem so that the 3D scene can be seen
	//SharedPtr<Viewport> viewport(new Viewport(context_, scene_, cameraNode_->GetComponent<Camera>()));
	//viewport->SetRenderPath(cache->GetResource<XMLFile>("CoreData/RenderPaths/ForwardHWDepth.xml"));
	//renderer->SetViewport(0, viewport);
	//// Add post-processing effects appropriate with the example scene

	//SharedPtr<RenderPath> effectRenderPath = viewport->GetRenderPath()->Clone();
	////effectRenderPath->Append(cache->GetResource<XMLFile>("PostProcess/FXAA2.xml"));
	////effectRenderPath->Append(cache->GetResource<XMLFile>("PostProcess/GammaCorrection.xml"));
	////effectRenderPath->Append(cache->GetResource<XMLFile>("PostProcess/Tonemap.xml"));
	////effectRenderPath->Append(cache->GetResource<XMLFile>("PostProcess/AutoExposure.xml"));

	////effectRenderPath->Append(cache->GetResource<XMLFile>("PostProcess/Blur.xml"));
	////effectRenderPath->SetShaderParameter("BlurClamp", 0.0f);
	//effectRenderPath->Append(cache->GetResource<XMLFile>("PostProcess/DoFBlogDebug.xml"));
	//effectRenderPath->SetShaderParameter("Far", viewport->GetCamera()->GetFarClip());
	//effectRenderPath->SetShaderParameter("ResWidth", viewport->GetRect().Width());
	//effectRenderPath->SetShaderParameter("FocalPlane", 0.05);
	//effectRenderPath->SetShaderParameter("Aperture", 4.0f);
	//viewport->SetRenderPath(effectRenderPath);
	//renderer->SetViewport(0, viewport);



	// Create static scene content. First create a zone for ambient lighting and fog control
	//Node* zoneNode = scene_->CreateChild("Zone");
	//auto* zone = zoneNode->CreateComponent<Zone>();
	//zone->SetAmbientColor(Color(0.15f, 0.15f, 0.15f));
	//zone->SetFogColor(Color(0.5f, 0.5f, 0.7f));
	//zone->SetFogStart(100.0f);
	//zone->SetFogEnd(300.0f);
	//zone->SetBoundingBox(BoundingBox(-1000.0f, 1000.0f));

	// Create a directional light with cascaded shadow mapping
	//Node* lightNode = scene_->CreateChild("DirectionalLight");
	//lightNode->SetDirection(Vector3(0.3f, -0.5f, 0.425f));
	//auto* light = lightNode->CreateComponent<Light>();
	//light->SetLightType(LIGHT_DIRECTIONAL);
	//light->SetCastShadows(true);
	//light->SetShadowBias(BiasParameters(0.00025f, 0.5f));
	//light->SetShadowCascade(CascadeParameters(10.0f, 50.0f, 200.0f, 0.0f, 0.8f));
	//light->SetSpecularIntensity(0.5f);

	// Create the floor object
	//Node* floorNode = scene_->CreateChild("Floor");
	//floorNode->SetPosition(Vector3(0.0f, -0.5f, 0.0f));
	//floorNode->SetScale(Vector3(200.0f, 1.0f, 200.0f));
	//auto* object = floorNode->CreateComponent<StaticModel>();
	//object->SetModel(cache->GetResource<Model>("Models/Box.mdl"));
	//object->SetMaterial(cache->GetResource<Material>("Materials/Stone.xml"));

	//auto* body = floorNode->CreateComponent<RigidBody>();
	//// Use collision layer bit 2 to mark world scenery. This is what we will raycast against to prevent camera from going
	//// inside geometry
	//body->SetCollisionLayer(2);
	//auto* shape = floorNode->CreateComponent<CollisionShape>();
	//shape->SetBox(Vector3::ONE);

	// Create mushrooms of varying sizes
	//const unsigned NUM_MUSHROOMS = 60;
	//for (unsigned i = 0; i < NUM_MUSHROOMS; ++i) {
	//	Node* objectNode = scene_->CreateChild("Mushroom");
	//	objectNode->SetPosition(Vector3(Random(180.0f) - 90.0f, 0.0f, Random(180.0f) - 90.0f));
	//	objectNode->SetRotation(Quaternion(0.0f, Random(360.0f), 0.0f));
	//	objectNode->SetScale(0.2f + Random(0.5f));
	//	auto* object = objectNode->CreateComponent<StaticModel>();
	//	object->SetModel(cache->GetResource<Model>("Models/Mushroom.mdl"));
	//	object->SetMaterial(cache->GetResource<Material>("Materials/Mushroom.xml"));
	//	object->SetCastShadows(true);

	//	/*auto* body = objectNode->CreateComponent<RigidBody>();
	//	body->SetCollisionLayer(2);
	//	auto* shape = objectNode->CreateComponent<CollisionShape>();
	//	shape->SetConvexHull(object->GetModel(), 0);*/
	//}

	// Create movable boxes. Let them fall from the sky at first
	//const unsigned NUM_BOXES = 5;
	//for (unsigned i = 0; i < NUM_BOXES; ++i) {
	//	float scale = Random(2.0f) + 0.5f;

	//	Node* objectNode = scene_->CreateChild("Box");
	//	objectNode->SetPosition(Vector3(Random(40.0f) - 20.0f, Random(10.0f) + 10.0f, Random(40.0f) - 20.0f));
	//	objectNode->SetRotation(Quaternion(Random(360.0f), Random(360.0f), Random(360.0f)));
	//	objectNode->SetScale(scale);
	//	auto* object = objectNode->CreateComponent<StaticModel>();
	//	object->SetModel(cache->GetResource<Model>("Models/Box.mdl"));
	//	object->SetMaterial(cache->GetResource<Material>("Materials/Stone.xml"));
	//	object->SetCastShadows(true);

	//	auto* body = objectNode->CreateComponent<RigidBody>();
	//	body->SetCollisionLayer(130); //2nd and 8th
	//	// Bigger boxes will be heavier and harder to move
	//	body->SetMass(scale * 2.0f);
	//	auto* shape = objectNode->CreateComponent<CollisionShape>();
	//	shape->SetBox(Vector3::ONE);
	//}

	//{
	//	Node* grassNode = scene_->CreateChild("GrassFlat");
	//	grassNode->SetPosition(Vector3(-12.0f, 0.0f, 0.0f));
	//	grassNode->SetScale(7.0f);
	//	StaticModel* model = grassNode->CreateComponent<StaticModel>();
	//	model->SetModel(cache->GetResource<Model>("GrassDynamic/Models/PlaneGrassBlades.mdl"));
	//	Material* material = cache->GetResource<Material>("GrassDynamic/dynamicgrass.xml");
	//	model->SetMaterial(material);

	//	if (grassNode) {
	//		DynamicGrass* grassLogic = grassNode->CreateComponent<DynamicGrass>();
	//		grassLogic->SetGrassMaterial(material);
	//	}
	//}

	{
		PODVector<Node*> grassBearers;
		scene_->GetNodesWithTag(grassBearers, "GrassBearer");
		for (Node* grassBearerNode : grassBearers) {
			if (grassBearerNode->HasComponent<StaticModel>()) {
				if (grassBearerNode->GetComponent<StaticModel>()->GetMaterial()->GetName().Contains("dynamicgrass")) {
					// Clone the material to ensure shader uniforms are per-object
					grassBearerNode->GetComponent<StaticModel>()->SetMaterial(grassBearerNode->GetComponent<StaticModel>()->GetMaterial()->Clone());
					DynamicGrass* grassLogic = grassBearerNode->CreateComponent<DynamicGrass>();
					grassLogic->SetGrassMaterial(grassBearerNode->GetComponent<StaticModel>()->GetMaterial());
				}
			}
		}
	}
}

void CharacterDemo::CreateCharacter() {
	auto* cache = GetSubsystem<ResourceCache>();


	Node* objectNode = scene_->CreateChild("Beagle");
	objectNode->SetScale(0.22f);

	// Set position to level spawn point (if multiple exist, use first)
	{
		PODVector<Node*> tagged;
		scene_->GetNodesWithTag(tagged, "playerspawn");
		objectNode->SetPosition(tagged.Front()->GetPosition());
		//lifter->SetPosition(tagged.Front()->GetPosition());
	}

	character_ = objectNode->CreateComponent<KinematicDog>();
}

void CharacterDemo::CreateInstructions() {
	auto* cache = GetSubsystem<ResourceCache>();
	auto* ui = GetSubsystem<UI>();

	// Construct new Text object, set string to display and font to use
	auto* instructionText = ui->GetRoot()->CreateChild<Text>();
	instructionText->SetText(
		"Use WASD keys and mouse/touch to move\n"
		"Space to jump, F to toggle 1st/3rd person\n"
		"F5 to save scene, F7 to load"
	);
	instructionText->SetFont(cache->GetResource<Font>("Fonts/Anonymous Pro.ttf"), 15);
	// The text has multiple rows. Center them in relation to each other
	instructionText->SetTextAlignment(HA_CENTER);

	// Position the text relative to the screen center
	instructionText->SetHorizontalAlignment(HA_CENTER);
	instructionText->SetVerticalAlignment(VA_CENTER);
	instructionText->SetPosition(0, ui->GetRoot()->GetHeight() / 4);
}

void CharacterDemo::SubscribeToEvents() {
	// Subscribe to Update event for setting the character controls before physics simulation
	SubscribeToEvent(E_UPDATE, URHO3D_HANDLER(CharacterDemo, HandleUpdate));

	// Subscribe to PostUpdate event for updating the camera position after physics simulation
	SubscribeToEvent(E_POSTUPDATE, URHO3D_HANDLER(CharacterDemo, HandlePostUpdate));

	SubscribeToEvent(E_POSTRENDERUPDATE, URHO3D_HANDLER(CharacterDemo, HandlePostRenderUpdate));

	// Unsubscribe the SceneUpdate event from base class as the camera node is being controlled in HandlePostUpdate() in this sample
	UnsubscribeFromEvent(E_SCENEUPDATE);
}


void CharacterDemo::HandleUpdate(StringHash eventType, VariantMap& eventData) {}

void CharacterDemo::HandlePostUpdate(StringHash eventType, VariantMap& eventData) {
	if (!character_)
		return;

	Node* characterNode = character_->GetNode();

	//// Get camera lookat dir from character yaw + pitch
	//const Quaternion& rot = characterNode->GetRotation();
	//Quaternion dir = rot * Quaternion(character_->controls_.pitch_, Vector3::RIGHT);

	// Turn head to camera pitch, but limit to avoid unnatural animation
	/*Node* headNode = characterNode->GetChild("Mutant:Head", true);
	float limitPitch = Clamp(character_->controls_.pitch_, -45.0f, 45.0f);
	Quaternion headDir = rot * Quaternion(limitPitch, Vector3(1.0f, 0.0f, 0.0f));
	// This could be expanded to look at an arbitrary target, now just look at a point in front
	Vector3 headWorldTarget = headNode->GetWorldPosition() + headDir * Vector3(0.0f, 0.0f, -1.0f);
	headNode->LookAt(headWorldTarget, Vector3(0.0f, 1.0f, 0.0f));
	*/ // add this back in when bone names are found TODO

	//if (firstPerson_) {
	//	//TODO add this back in
	//	//cameraNode_->SetPosition(headNode->GetWorldPosition() + rot * Vector3(0.0f, 0.15f, 0.2f));
	//	cameraNode_->SetRotation(dir);
	//} else {
	//	// Third person camera: position behind the character
	//	Vector3 aimPoint = characterNode->GetPosition() + rot * Vector3(0.0f, 1.70f, 0.0f);

	//	// Collide camera ray with static physics objects (layer bitmask 2) to ensure we see the character properly
	//	Vector3 rayDir = dir * Vector3::BACK;
	//	float rayDistance = touch_ ? touch_->cameraDistance_ : CAMERA_INITIAL_DIST;
	//	PhysicsRaycastResult result;
	//	scene_->GetComponent<PhysicsWorld>()->RaycastSingle(result, Ray(aimPoint, rayDir), rayDistance, 2);
	//	if (result.body_)
	//		rayDistance = Min(rayDistance, result.distance_);
	//	rayDistance = Clamp(rayDistance, CAMERA_MIN_DIST, CAMERA_MAX_DIST);

	//	cameraNode_->SetPosition(aimPoint + rayDir * rayDistance);
	//	cameraNode_->SetRotation(dir);
	//}

	cameraNode_->SetPosition(characterNode->GetPosition() + Vector3(0.0f, 20.0f, -20.0f));
	cameraNode_->LookAt(characterNode->GetPosition(), Vector3(0.0f, 1.0f, 0.0f));

	/*auto* renderer = GetSubsystem<Renderer>();
	renderer->SetShadowQuality(ShadowQuality::SHADOWQUALITY_BLUR_VSM);
	renderer->SetShadowSoftness(2.5f);*/
}

void CharacterDemo::HandlePostRenderUpdate(StringHash eventType, VariantMap& eventData) {
	//if (drawDebug_)
	scene_->GetComponent<PhysicsWorld>()->DrawDebugGeometry(false);
}