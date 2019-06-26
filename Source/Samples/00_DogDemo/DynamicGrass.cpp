#include <Urho3D/Core/Context.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Physics/CollisionShape.h>
#include <Urho3D/Physics/RigidBody.h>
#include <Urho3D/Graphics/ParticleEmitter.h>
#include <Urho3D/Graphics/AnimatedModel.h>
#include <Urho3D/Physics/PhysicsEvents.h>
#include <Urho3D/IO/MemoryBuffer.h>
#include <DynamicGrass.h>


DynamicGrass::DynamicGrass(Context* context) : LogicComponent(context) {
	//SetUpdateEventMask(USE_POSTUPDATE);
	collidedThisFrame = false;
}

void DynamicGrass::RegisterObject(Context* context) {
	context->RegisterFactory<DynamicGrass>();
}

void DynamicGrass::Start() {
	SubscribeToEvent(node_, E_NODECOLLISION, URHO3D_HANDLER(DynamicGrass, HandleNodeCollision));


	body = node_->CreateComponent<RigidBody>();
	// Prevent it being a physical box, and more of a volume trigger
	body->SetTrigger(true);
	// Prevent collision checks with typical objects, use a special last layer
	//body->SetCollisionLayer(0b00000001); // Only other things on last layer can collide with us
	//body->SetCollisionMask(0b00000001); // Only collide us with things on this layer

	body->SetCollisionLayer(0b1111111); // TEMP
	body->SetCollisionMask(0b11111111);

	collision = node_->CreateComponent<CollisionShape>();
	String name = node_->GetComponent<StaticModel>()->GetModel()->GetName();

	//collision->SetBox(Vector3(1.1f, 0.5f, 1.1f), Vector3(0.0f, 0.25f, 0.0f));
	if (name.Contains("Blades")) {
		collision->SetBox(Vector3(1.1f, 0.5f, 1.1f), Vector3(0.0f, 0.25f, 0.0f));
	} else if (name.Contains("Wheat")) {
		collision->SetBox(Vector3(2.0f, 0.3f, 1.0f), Vector3(0.0f, 0.15f, 0.0f));
	} else if (name.Contains("Circle")) {
		collision->SetBox(Vector3(0.6f, 0.6f, 0.6f), Vector3(0.0f, 0.15f, 0.0f));
	} else {
		collision->SetBox(Vector3(2.2f, 1.0f, 2.2f), Vector3(0.0f, 0.25f, 0.0f));
	}


	varvec = new VariantVector();
	sizevec = new VariantVector();
}

void DynamicGrass::Update(float timeStep) {
	Time += timeStep;
	//if (Time > 360) { Time = 0.0f; }

	if (grassMaterial) {
		grassMaterial->SetShaderParameter("GrassTime", Time);
	}
}
void DynamicGrass::SetGrassMaterial(Material* material) {
	grassMaterial = material;
	material->SetShaderParameter("MaxWidth", maxWidth * node_->GetScale().x_);
	material->SetShaderParameter("GrassYStart", node_->LocalToWorld(Vector3(0.0f, yStart, 0.0f)).y_);
	material->SetShaderParameter("GrassYEnd", node_->LocalToWorld(Vector3(0.0f, yEnd, 0.0f)).y_);
	material->SetShaderParameter("GrassSpeed", grassSpeed);
	material->SetShaderParameter("SwayMax", swayMax);
	material->SetShaderParameter("GrassRigidity", grassRigidity);
}

void DynamicGrass::HandleNodeCollision(StringHash eventType, VariantMap& eventData) {
	using namespace NodeCollision;

	Node* contactNode = (Node*)eventData[P_OTHERNODE].GetPtr();
	RigidBody* rigidBody = contactNode->GetComponent<RigidBody>();
	// No kinematics allowed (i.e. no trees)
	if (grassMaterial/* && (!rigidBody->IsKinematic() || rigidBody->GetNode()->GetTags().Contains(String("player")))*/) {

		//temp
		String name = contactNode->GetName();


		/*StaticModel* model = contactNode->GetComponent<StaticModel>(true);
		Vector3 modelSize = model->GetWorldBoundingBox().Size();
		varvec->Push(contactNode->GetWorldPosition() + Vector3(0.0f, yOffset, 0.0f));
		sizevec->Push((float)(modelSize.x_ * modelSize.z_));
		sizevec->Push(1.0f);
		collidedThisFrame = true;*/

		CollisionShape* col = rigidBody->GetNode()->GetComponent<CollisionShape>();
		// allows simple boxes to push the grass accurately
		if (col->GetShapeType() == ShapeType::SHAPE_BOX) {
			sizevec->Push(col->GetSize().x_ * col->GetSize().z_ * contactNode->GetScale().x_ * contactNode->GetScale().y_);
			varvec->Push(contactNode->GetWorldPosition());
		} else {
			sizevec->Push(1.0f);
			varvec->Push(contactNode->GetWorldPosition() + Vector3(0.0f, yOffset, 0.0f));
		}

		collidedThisFrame = true;

	}

}


void DynamicGrass::FixedPostUpdate(float timeStep) {
	// Clear
	if (collidedThisFrame) {
		//Variant varvarbinks = grassMaterial->GetShaderParameter("ObjectPositionArray");

		grassMaterial->SetShaderParameter("ObjectPositionArray", *varvec);
		grassMaterial->SetShaderParameter("ObjectSizeArray", *sizevec);
		grassMaterial->SetShaderParameter("NumberOfObjects", varvec->Size());
		//grassMaterial->SetShaderParameter("NumberOfObjects", 1);
		varvec->Clear();
		sizevec->Clear();
		//collidedThisFrame = false;
	}
}
/*
if (grassMaterial) {
VariantVector varvec;
varvec.Push(node_->LocalToWorld(Vector3(-0.1f, 0.0, 0.0f)));
varvec.Push(node_->LocalToWorld(Vector3(1.0f, 0.5f, 0.0f)));
varvec.Push(node_->LocalToWorld(Vector3(1.0f, 0.5f, 1.0f)));
varvec.Push(node_->LocalToWorld(Vector3(0.0f, 0.75f, 1.0f)));
grassMaterial->SetShaderParameter("ObjectPositionArray", varvec);
}
*/

DynamicGrass::~DynamicGrass() {
	delete varvec;
	delete sizevec;
}