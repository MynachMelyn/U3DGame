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

#include "CharacterDemo.h"
#include "GunLogic.h"


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
	GunLogic::RegisterObject(context);
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

	// Create static scene content
	CreateScene();

	SetupGun();

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

	/*rttViewport->GetRenderPath()->Append(cache->GetResource<XMLFile>("PostProcess/DoFBlog.xml"));
	rttViewport->GetRenderPath()->SetShaderParameter("Far", rttViewport->GetCamera()->GetFarClip());
	rttViewport->GetRenderPath()->SetShaderParameter("ResWidth", 1920.0);
	rttViewport->GetRenderPath()->SetShaderParameter("FWheel", 0.934f);
	rttViewport->GetRenderPath()->SetShaderParameter("FocalLengthMM", 70.0);
	rttViewport->GetRenderPath()->SetShaderParameter("Aperture", 0.5f);*/

	renderer->SetViewport(0, rttViewport);
}

void CharacterDemo::CreateScene() {
	auto* cache = GetSubsystem<ResourceCache>();
	auto* renderer = GetSubsystem<Renderer>();
	auto* graphics = GetSubsystem<Graphics>(); //for ortho

	renderer->SetHDRRendering(true);

	scene_ = new Scene(context_);

	///////////////////
	SharedPtr<File> file = cache->GetFile("Scenes/GunTest.xml");
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
	cameraNode_->SetPosition(Vector3(2.5f, 2.5f, 0.0f));

	camera->SetOrthographic(false); // Set camera orthographic
	camera->SetFov(75.0f);
	cameraNode_->LookAt(Vector3(0, 1.5f, 0));
}

void CharacterDemo::SetupGun() {
	auto* cache = GetSubsystem<ResourceCache>();

	// Set position to level spawn point (if multiple exist, use first)
	{
		PODVector<Node*> tagged;
		scene_->GetNodesWithTag(tagged, "gun");
		gunNode_ = tagged.Front()->GetChild("M9");
		gunLogic_ = gunNode_->CreateComponent<GunLogic>();
	}

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


void CharacterDemo::HandleUpdate(StringHash eventType, VariantMap& eventData) {

}

void CharacterDemo::HandlePostUpdate(StringHash eventType, VariantMap& eventData) {

}

void CharacterDemo::HandlePostRenderUpdate(StringHash eventType, VariantMap& eventData) {
	//if (drawDebug_)
	scene_->GetComponent<PhysicsWorld>()->DrawDebugGeometry(false);
}