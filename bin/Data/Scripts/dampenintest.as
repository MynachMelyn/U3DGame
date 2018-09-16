#include "Scripts/NinjaSnowWar/GameObject.as"

class Ninja : GameObject
{
    Ninja()
    {
    }

    void FixedUpdate(float timeStep)
    {
		RigidBody@ body = node.GetComponent("RigidBody");
        body.ApplyForce(Vector3(250.0f, 0.0f, 0.0f));
    }
}