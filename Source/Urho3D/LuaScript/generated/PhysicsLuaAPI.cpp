/*
** Lua binding: PhysicsLuaAPI
*/

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

#include "Precompiled.h"

#include <toluapp/tolua++.h>
#include "LuaScript/ToluaUtils.h"

#if __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#endif

/* Exported function */
TOLUA_API int tolua_PhysicsLuaAPI_open (lua_State* tolua_S);

#include "Physics/CollisionShape.h"
#include "Physics/Constraint.h"
#include "Physics/PhysicsWorld.h"
#include "Physics/RigidBody.h"
#include "Physics/RaycastVehicle.h"
using namespace Urho3D;
#pragma warning(disable:4800)

#define TOLUA_DISABLE_tolua_get_Constraint_axis_ref
#define tolua_get_Constraint_axis_ref NULL

#define TOLUA_DISABLE_tolua_get_Constraint_otherAxis_ref
#define tolua_get_Constraint_otherAxis_ref NULL

static const PODVector<PhysicsRaycastResult>& PhysicsWorldRaycast(PhysicsWorld* physicsWorld, const Ray& ray, float maxDistance, unsigned collisionMask = M_MAX_UNSIGNED)
{
    static PODVector<PhysicsRaycastResult> result;
    result.Clear();
    physicsWorld->Raycast(result, ray, maxDistance, collisionMask);
    return result;
}

static PhysicsRaycastResult PhysicsWorldRaycastSingle(PhysicsWorld* physicsWorld, const Ray& ray, float maxDistance, unsigned collisionMask = M_MAX_UNSIGNED)
{
    PhysicsRaycastResult result;
    physicsWorld->RaycastSingle(result, ray, maxDistance, collisionMask);
    return result;
}

static PhysicsRaycastResult PhysicsWorldRaycastSingleSegmented(PhysicsWorld* physicsWorld, const Ray& ray, float maxDistance, float segmentDistance, unsigned collisionMask = M_MAX_UNSIGNED, float overlapDistance = 0.1f)
{
    PhysicsRaycastResult result;
    physicsWorld->RaycastSingleSegmented(result, ray, maxDistance, segmentDistance, collisionMask, overlapDistance);
    return result;
}

PhysicsRaycastResult PhysicsWorldSphereCast(PhysicsWorld* physicsWorld, const Ray& ray, float radius, float maxDistance, unsigned collisionMask = M_MAX_UNSIGNED)
{
    PhysicsRaycastResult result;
    physicsWorld->SphereCast(result, ray, radius, maxDistance, collisionMask);
    return result;
}

PhysicsRaycastResult PhysicsWorldConvexCast(PhysicsWorld* physicsWorld, CollisionShape* shape, const Vector3& startPos, const Quaternion& startRot, const Vector3& endPos, const Quaternion& endRot, unsigned collisionMask = M_MAX_UNSIGNED)
{
    PhysicsRaycastResult result;
    physicsWorld->ConvexCast(result, shape, startPos, startRot, endPos, endRot, collisionMask);
    return result;
}

static const PODVector<RigidBody*>& PhysicsWorldGetRigidBodiesSphere(PhysicsWorld* physicsWorld, const Sphere& sphere, unsigned collisionMask = M_MAX_UNSIGNED)
{
    static PODVector<RigidBody*> result;
    result.Clear();
    physicsWorld->GetRigidBodies(result, sphere, collisionMask);
    return result;
}

static const PODVector<RigidBody*>& PhysicsWorldGetRigidBodiesBox(PhysicsWorld* physicsWorld, const BoundingBox& box, unsigned collisionMask = M_MAX_UNSIGNED)
{
    static PODVector<RigidBody*> result;
    result.Clear();
    physicsWorld->GetRigidBodies(result, box, collisionMask);
    return result;
}

static const PODVector<RigidBody*>& PhysicsWorldGetRigidBodiesBody(PhysicsWorld* physicsWorld, const RigidBody* body)
{
    static PODVector<RigidBody*> result;
    result.Clear();
    physicsWorld->GetRigidBodies(result, body);
    return result;
}

static const PODVector<RigidBody*>& PhysicsWorldGetCollidingBodies(PhysicsWorld* physicsWorld, const RigidBody* body)
{
    static PODVector<RigidBody*> result;
    result.Clear();
    physicsWorld->GetCollidingBodies(result, body);
    return result;
}

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Quaternion (lua_State* tolua_S)
{
 Quaternion* self = (Quaternion*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_PhysicsRaycastResult (lua_State* tolua_S)
{
 PhysicsRaycastResult* self = (PhysicsRaycastResult*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_RaycastVehicle (lua_State* tolua_S)
{
 RaycastVehicle* self = (RaycastVehicle*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_IntVector3 (lua_State* tolua_S)
{
 IntVector3* self = (IntVector3*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Vector3 (lua_State* tolua_S)
{
 Vector3* self = (Vector3*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_BoundingBox (lua_State* tolua_S)
{
 BoundingBox* self = (BoundingBox*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Quaternion");
 tolua_usertype(tolua_S,"CustomGeometry");
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"RaycastVehicle");
 tolua_usertype(tolua_S,"PODVector<PhysicsRaycastResult>");
 tolua_usertype(tolua_S,"Context");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"PhysicsWorld");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"Urho3D::Context");
 tolua_usertype(tolua_S,"LogicComponent");
 tolua_usertype(tolua_S,"RigidBody");
 tolua_usertype(tolua_S,"PODVector<RigidBody*>");
 tolua_usertype(tolua_S,"Sphere");
 tolua_usertype(tolua_S,"IntVector3");
 tolua_usertype(tolua_S,"Ray");
 tolua_usertype(tolua_S,"CollisionShape");
 tolua_usertype(tolua_S,"PhysicsRaycastResult");
 tolua_usertype(tolua_S,"Model");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"BoundingBox");
 tolua_usertype(tolua_S,"Constraint");
 tolua_usertype(tolua_S,"ResourceRef");
}

/* method: SetBox of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetBox00
static int tolua_PhysicsLuaAPI_CollisionShape_SetBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* size = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBox'", NULL);
#endif
 {
  self->SetBox(*size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBox of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetBox01
static int tolua_PhysicsLuaAPI_CollisionShape_SetBox01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* size = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBox'", NULL);
#endif
 {
  self->SetBox(*size,*position);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetBox00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBox of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetBox02
static int tolua_PhysicsLuaAPI_CollisionShape_SetBox02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* size = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBox'", NULL);
#endif
 {
  self->SetBox(*size,*position,*rotation);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetBox01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSphere of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetSphere00
static int tolua_PhysicsLuaAPI_CollisionShape_SetSphere00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  float diameter = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSphere'", NULL);
#endif
 {
  self->SetSphere(diameter);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSphere'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSphere of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetSphere01
static int tolua_PhysicsLuaAPI_CollisionShape_SetSphere01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  float diameter = ((float)  tolua_tonumber(tolua_S,2,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSphere'", NULL);
#endif
 {
  self->SetSphere(diameter,*position);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetSphere00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSphere of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetSphere02
static int tolua_PhysicsLuaAPI_CollisionShape_SetSphere02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  float diameter = ((float)  tolua_tonumber(tolua_S,2,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSphere'", NULL);
#endif
 {
  self->SetSphere(diameter,*position,*rotation);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetSphere01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetStaticPlane of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetStaticPlane00
static int tolua_PhysicsLuaAPI_CollisionShape_SetStaticPlane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetStaticPlane'", NULL);
#endif
 {
  self->SetStaticPlane();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetStaticPlane'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetStaticPlane of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetStaticPlane01
static int tolua_PhysicsLuaAPI_CollisionShape_SetStaticPlane01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetStaticPlane'", NULL);
#endif
 {
  self->SetStaticPlane(*position);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetStaticPlane00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetStaticPlane of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetStaticPlane02
static int tolua_PhysicsLuaAPI_CollisionShape_SetStaticPlane02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetStaticPlane'", NULL);
#endif
 {
  self->SetStaticPlane(*position,*rotation);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetStaticPlane01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCylinder of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCylinder00
static int tolua_PhysicsLuaAPI_CollisionShape_SetCylinder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  float diameter = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCylinder'", NULL);
#endif
 {
  self->SetCylinder(diameter,height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCylinder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCylinder of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCylinder01
static int tolua_PhysicsLuaAPI_CollisionShape_SetCylinder01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  float diameter = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCylinder'", NULL);
#endif
 {
  self->SetCylinder(diameter,height,*position);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetCylinder00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCylinder of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCylinder02
static int tolua_PhysicsLuaAPI_CollisionShape_SetCylinder02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  float diameter = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCylinder'", NULL);
#endif
 {
  self->SetCylinder(diameter,height,*position,*rotation);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetCylinder01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCapsule of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCapsule00
static int tolua_PhysicsLuaAPI_CollisionShape_SetCapsule00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  float diameter = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCapsule'", NULL);
#endif
 {
  self->SetCapsule(diameter,height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCapsule'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCapsule of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCapsule01
static int tolua_PhysicsLuaAPI_CollisionShape_SetCapsule01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  float diameter = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCapsule'", NULL);
#endif
 {
  self->SetCapsule(diameter,height,*position);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetCapsule00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCapsule of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCapsule02
static int tolua_PhysicsLuaAPI_CollisionShape_SetCapsule02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  float diameter = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCapsule'", NULL);
#endif
 {
  self->SetCapsule(diameter,height,*position,*rotation);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetCapsule01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCone of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCone00
static int tolua_PhysicsLuaAPI_CollisionShape_SetCone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  float diameter = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCone'", NULL);
#endif
 {
  self->SetCone(diameter,height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCone of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCone01
static int tolua_PhysicsLuaAPI_CollisionShape_SetCone01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  float diameter = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCone'", NULL);
#endif
 {
  self->SetCone(diameter,height,*position);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetCone00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCone of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCone02
static int tolua_PhysicsLuaAPI_CollisionShape_SetCone02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  float diameter = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCone'", NULL);
#endif
 {
  self->SetCone(diameter,height,*position,*rotation);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetCone01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTriangleMesh of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetTriangleMesh00
static int tolua_PhysicsLuaAPI_CollisionShape_SetTriangleMesh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Model",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  Model* model = ((Model*)  tolua_tousertype(tolua_S,2,0));
  unsigned lodLevel = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTriangleMesh'", NULL);
#endif
 {
  self->SetTriangleMesh(model,lodLevel);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTriangleMesh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTriangleMesh of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetTriangleMesh01
static int tolua_PhysicsLuaAPI_CollisionShape_SetTriangleMesh01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Model",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  Model* model = ((Model*)  tolua_tousertype(tolua_S,2,0));
  unsigned lodLevel = ((unsigned)  tolua_tonumber(tolua_S,3,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTriangleMesh'", NULL);
#endif
 {
  self->SetTriangleMesh(model,lodLevel,*scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetTriangleMesh00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTriangleMesh of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetTriangleMesh02
static int tolua_PhysicsLuaAPI_CollisionShape_SetTriangleMesh02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Model",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  Model* model = ((Model*)  tolua_tousertype(tolua_S,2,0));
  unsigned lodLevel = ((unsigned)  tolua_tonumber(tolua_S,3,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTriangleMesh'", NULL);
#endif
 {
  self->SetTriangleMesh(model,lodLevel,*scale,*position);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetTriangleMesh01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTriangleMesh of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetTriangleMesh03
static int tolua_PhysicsLuaAPI_CollisionShape_SetTriangleMesh03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Model",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  Model* model = ((Model*)  tolua_tousertype(tolua_S,2,0));
  unsigned lodLevel = ((unsigned)  tolua_tonumber(tolua_S,3,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,5,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTriangleMesh'", NULL);
#endif
 {
  self->SetTriangleMesh(model,lodLevel,*scale,*position,*rotation);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetTriangleMesh02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCustomTriangleMesh of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCustomTriangleMesh00
static int tolua_PhysicsLuaAPI_CollisionShape_SetCustomTriangleMesh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CustomGeometry",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  CustomGeometry* custom = ((CustomGeometry*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCustomTriangleMesh'", NULL);
#endif
 {
  self->SetCustomTriangleMesh(custom);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCustomTriangleMesh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCustomTriangleMesh of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCustomTriangleMesh01
static int tolua_PhysicsLuaAPI_CollisionShape_SetCustomTriangleMesh01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CustomGeometry",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  CustomGeometry* custom = ((CustomGeometry*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCustomTriangleMesh'", NULL);
#endif
 {
  self->SetCustomTriangleMesh(custom,*scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetCustomTriangleMesh00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCustomTriangleMesh of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCustomTriangleMesh02
static int tolua_PhysicsLuaAPI_CollisionShape_SetCustomTriangleMesh02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CustomGeometry",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  CustomGeometry* custom = ((CustomGeometry*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCustomTriangleMesh'", NULL);
#endif
 {
  self->SetCustomTriangleMesh(custom,*scale,*position);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetCustomTriangleMesh01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCustomTriangleMesh of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCustomTriangleMesh03
static int tolua_PhysicsLuaAPI_CollisionShape_SetCustomTriangleMesh03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CustomGeometry",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  CustomGeometry* custom = ((CustomGeometry*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCustomTriangleMesh'", NULL);
#endif
 {
  self->SetCustomTriangleMesh(custom,*scale,*position,*rotation);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetCustomTriangleMesh02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetConvexHull of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetConvexHull00
static int tolua_PhysicsLuaAPI_CollisionShape_SetConvexHull00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Model",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  Model* model = ((Model*)  tolua_tousertype(tolua_S,2,0));
  unsigned lodLevel = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetConvexHull'", NULL);
#endif
 {
  self->SetConvexHull(model,lodLevel);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetConvexHull'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetConvexHull of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetConvexHull01
static int tolua_PhysicsLuaAPI_CollisionShape_SetConvexHull01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Model",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  Model* model = ((Model*)  tolua_tousertype(tolua_S,2,0));
  unsigned lodLevel = ((unsigned)  tolua_tonumber(tolua_S,3,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetConvexHull'", NULL);
#endif
 {
  self->SetConvexHull(model,lodLevel,*scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetConvexHull00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetConvexHull of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetConvexHull02
static int tolua_PhysicsLuaAPI_CollisionShape_SetConvexHull02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Model",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  Model* model = ((Model*)  tolua_tousertype(tolua_S,2,0));
  unsigned lodLevel = ((unsigned)  tolua_tonumber(tolua_S,3,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetConvexHull'", NULL);
#endif
 {
  self->SetConvexHull(model,lodLevel,*scale,*position);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetConvexHull01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetConvexHull of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetConvexHull03
static int tolua_PhysicsLuaAPI_CollisionShape_SetConvexHull03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Model",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  Model* model = ((Model*)  tolua_tousertype(tolua_S,2,0));
  unsigned lodLevel = ((unsigned)  tolua_tonumber(tolua_S,3,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,5,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetConvexHull'", NULL);
#endif
 {
  self->SetConvexHull(model,lodLevel,*scale,*position,*rotation);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetConvexHull02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCustomConvexHull of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCustomConvexHull00
static int tolua_PhysicsLuaAPI_CollisionShape_SetCustomConvexHull00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CustomGeometry",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  CustomGeometry* custom = ((CustomGeometry*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCustomConvexHull'", NULL);
#endif
 {
  self->SetCustomConvexHull(custom);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCustomConvexHull'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCustomConvexHull of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCustomConvexHull01
static int tolua_PhysicsLuaAPI_CollisionShape_SetCustomConvexHull01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CustomGeometry",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  CustomGeometry* custom = ((CustomGeometry*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCustomConvexHull'", NULL);
#endif
 {
  self->SetCustomConvexHull(custom,*scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetCustomConvexHull00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCustomConvexHull of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCustomConvexHull02
static int tolua_PhysicsLuaAPI_CollisionShape_SetCustomConvexHull02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CustomGeometry",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  CustomGeometry* custom = ((CustomGeometry*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCustomConvexHull'", NULL);
#endif
 {
  self->SetCustomConvexHull(custom,*scale,*position);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetCustomConvexHull01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCustomConvexHull of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetCustomConvexHull03
static int tolua_PhysicsLuaAPI_CollisionShape_SetCustomConvexHull03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CustomGeometry",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  CustomGeometry* custom = ((CustomGeometry*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCustomConvexHull'", NULL);
#endif
 {
  self->SetCustomConvexHull(custom,*scale,*position,*rotation);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_CollisionShape_SetCustomConvexHull02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTerrain of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetTerrain00
static int tolua_PhysicsLuaAPI_CollisionShape_SetTerrain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  unsigned lodLevel = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTerrain'", NULL);
#endif
 {
  self->SetTerrain(lodLevel);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTerrain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetShapeType of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetShapeType00
static int tolua_PhysicsLuaAPI_CollisionShape_SetShapeType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  ShapeType type = ((ShapeType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetShapeType'", NULL);
#endif
 {
  self->SetShapeType(type);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetShapeType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetSize00
static int tolua_PhysicsLuaAPI_CollisionShape_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* size = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
 {
  self->SetSize(*size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetPosition00
static int tolua_PhysicsLuaAPI_CollisionShape_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
 {
  self->SetPosition(*position);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRotation of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetRotation00
static int tolua_PhysicsLuaAPI_CollisionShape_SetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRotation'", NULL);
#endif
 {
  self->SetRotation(*rotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTransform of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetTransform00
static int tolua_PhysicsLuaAPI_CollisionShape_SetTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTransform'", NULL);
#endif
 {
  self->SetTransform(*position,*rotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMargin of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetMargin00
static int tolua_PhysicsLuaAPI_CollisionShape_SetMargin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  float margin = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMargin'", NULL);
#endif
 {
  self->SetMargin(margin);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMargin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetModel of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetModel00
static int tolua_PhysicsLuaAPI_CollisionShape_SetModel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Model",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  Model* model = ((Model*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetModel'", NULL);
#endif
 {
  self->SetModel(model);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetModel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLodLevel of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_SetLodLevel00
static int tolua_PhysicsLuaAPI_CollisionShape_SetLodLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
  unsigned lodLevel = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLodLevel'", NULL);
#endif
 {
  self->SetLodLevel(lodLevel);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLodLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPhysicsWorld of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_GetPhysicsWorld00
static int tolua_PhysicsLuaAPI_CollisionShape_GetPhysicsWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape* self = (const CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPhysicsWorld'", NULL);
#endif
 {
  PhysicsWorld* tolua_ret = (PhysicsWorld*)  self->GetPhysicsWorld();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"PhysicsWorld");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPhysicsWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetShapeType of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_GetShapeType00
static int tolua_PhysicsLuaAPI_CollisionShape_GetShapeType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape* self = (const CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetShapeType'", NULL);
#endif
 {
  ShapeType tolua_ret = (ShapeType)  self->GetShapeType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetShapeType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSize of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_GetSize00
static int tolua_PhysicsLuaAPI_CollisionShape_GetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape* self = (const CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSize'", NULL);
#endif
 {
  const Vector3& tolua_ret = (const Vector3&)  self->GetSize();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPosition of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_GetPosition00
static int tolua_PhysicsLuaAPI_CollisionShape_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape* self = (const CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition'", NULL);
#endif
 {
  const Vector3& tolua_ret = (const Vector3&)  self->GetPosition();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRotation of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_GetRotation00
static int tolua_PhysicsLuaAPI_CollisionShape_GetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape* self = (const CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRotation'", NULL);
#endif
 {
  const Quaternion& tolua_ret = (const Quaternion&)  self->GetRotation();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Quaternion");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMargin of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_GetMargin00
static int tolua_PhysicsLuaAPI_CollisionShape_GetMargin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape* self = (const CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMargin'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMargin();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMargin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetModel of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_GetModel00
static int tolua_PhysicsLuaAPI_CollisionShape_GetModel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape* self = (const CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetModel'", NULL);
#endif
 {
  Model* tolua_ret = (Model*)  self->GetModel();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Model");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetModel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLodLevel of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_GetLodLevel00
static int tolua_PhysicsLuaAPI_CollisionShape_GetLodLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape* self = (const CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLodLevel'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetLodLevel();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLodLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldBoundingBox of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_CollisionShape_GetWorldBoundingBox00
static int tolua_PhysicsLuaAPI_CollisionShape_GetWorldBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape* self = (const CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldBoundingBox'", NULL);
#endif
 {
  BoundingBox tolua_ret = (BoundingBox)  self->GetWorldBoundingBox();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((BoundingBox)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(BoundingBox));
  tolua_pushusertype(tolua_S,tolua_obj,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWorldBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: physicsWorld of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape_physicsWorld_ptr
static int tolua_get_CollisionShape_physicsWorld_ptr(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'physicsWorld'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetPhysicsWorld(),"PhysicsWorld");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: shapeType of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape_shapeType
static int tolua_get_CollisionShape_shapeType(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'shapeType'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetShapeType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: shapeType of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_set_CollisionShape_shapeType
static int tolua_set_CollisionShape_shapeType(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'shapeType'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetShapeType(((ShapeType) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: size of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape_size_ref
static int tolua_get_CollisionShape_size_ref(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetSize(),"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: size of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_set_CollisionShape_size_ref
static int tolua_set_CollisionShape_size_ref(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSize((*(Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: position of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape_position_ref
static int tolua_get_CollisionShape_position_ref(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetPosition(),"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: position of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_set_CollisionShape_position_ref
static int tolua_set_CollisionShape_position_ref(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPosition((*(Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rotation of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape_rotation_ref
static int tolua_get_CollisionShape_rotation_ref(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetRotation(),"Quaternion");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rotation of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_set_CollisionShape_rotation_ref
static int tolua_set_CollisionShape_rotation_ref(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRotation((*(Quaternion*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: margin of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape_margin
static int tolua_get_CollisionShape_margin(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'margin'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMargin());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: margin of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_set_CollisionShape_margin
static int tolua_set_CollisionShape_margin(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'margin'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMargin(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: model of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape_model_ptr
static int tolua_get_CollisionShape_model_ptr(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'model'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetModel(),"Model");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: model of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_set_CollisionShape_model_ptr
static int tolua_set_CollisionShape_model_ptr(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'model'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Model",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetModel(((Model*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: lodLevel of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape_lodLevel
static int tolua_get_CollisionShape_lodLevel(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lodLevel'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLodLevel());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: lodLevel of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_set_CollisionShape_lodLevel
static int tolua_set_CollisionShape_lodLevel(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lodLevel'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLodLevel(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: worldBoundingBox of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape_worldBoundingBox
static int tolua_get_CollisionShape_worldBoundingBox(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldBoundingBox'",NULL);
#endif
 BoundingBox tolua_ret = (BoundingBox)self->GetWorldBoundingBox();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((BoundingBox)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(BoundingBox));
 tolua_pushusertype(tolua_S,tolua_obj,"BoundingBox");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: modelAttr of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape_modelAttr
static int tolua_get_CollisionShape_modelAttr(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modelAttr'",NULL);
#endif
 ResourceRef tolua_ret = (ResourceRef)self->GetModelAttr();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((ResourceRef)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"ResourceRef");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(ResourceRef));
 tolua_pushusertype(tolua_S,tolua_obj,"ResourceRef");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: modelAttr of class  CollisionShape */
#ifndef TOLUA_DISABLE_tolua_set_CollisionShape_modelAttr
static int tolua_set_CollisionShape_modelAttr(lua_State* tolua_S)
{
  CollisionShape* self = (CollisionShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modelAttr'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ResourceRef",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetModelAttr(*((ResourceRef*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetConstraintType of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_SetConstraintType00
static int tolua_PhysicsLuaAPI_Constraint_SetConstraintType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
  ConstraintType type = ((ConstraintType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetConstraintType'", NULL);
#endif
 {
  self->SetConstraintType(type);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetConstraintType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOtherBody of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_SetOtherBody00
static int tolua_PhysicsLuaAPI_Constraint_SetOtherBody00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
  RigidBody* body = ((RigidBody*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOtherBody'", NULL);
#endif
 {
  self->SetOtherBody(body);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOtherBody'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_SetPosition00
static int tolua_PhysicsLuaAPI_Constraint_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
 {
  self->SetPosition(*position);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRotation of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_SetRotation00
static int tolua_PhysicsLuaAPI_Constraint_SetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRotation'", NULL);
#endif
 {
  self->SetRotation(*rotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAxis of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_SetAxis00
static int tolua_PhysicsLuaAPI_Constraint_SetAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAxis'", NULL);
#endif
 {
  self->SetAxis(*axis);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOtherPosition of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_SetOtherPosition00
static int tolua_PhysicsLuaAPI_Constraint_SetOtherPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOtherPosition'", NULL);
#endif
 {
  self->SetOtherPosition(*position);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOtherPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOtherRotation of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_SetOtherRotation00
static int tolua_PhysicsLuaAPI_Constraint_SetOtherRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOtherRotation'", NULL);
#endif
 {
  self->SetOtherRotation(*rotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOtherRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOtherAxis of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_SetOtherAxis00
static int tolua_PhysicsLuaAPI_Constraint_SetOtherAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOtherAxis'", NULL);
#endif
 {
  self->SetOtherAxis(*axis);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOtherAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldPosition of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_SetWorldPosition00
static int tolua_PhysicsLuaAPI_Constraint_SetWorldPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldPosition'", NULL);
#endif
 {
  self->SetWorldPosition(*position);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWorldPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHighLimit of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_SetHighLimit00
static int tolua_PhysicsLuaAPI_Constraint_SetHighLimit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* limit = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHighLimit'", NULL);
#endif
 {
  self->SetHighLimit(*limit);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHighLimit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLowLimit of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_SetLowLimit00
static int tolua_PhysicsLuaAPI_Constraint_SetLowLimit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* limit = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLowLimit'", NULL);
#endif
 {
  self->SetLowLimit(*limit);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLowLimit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetERP of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_SetERP00
static int tolua_PhysicsLuaAPI_Constraint_SetERP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
  float erp = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetERP'", NULL);
#endif
 {
  self->SetERP(erp);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetERP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCFM of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_SetCFM00
static int tolua_PhysicsLuaAPI_Constraint_SetCFM00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
  float cfm = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCFM'", NULL);
#endif
 {
  self->SetCFM(cfm);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCFM'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDisableCollision of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_SetDisableCollision00
static int tolua_PhysicsLuaAPI_Constraint_SetDisableCollision00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
  bool disable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDisableCollision'", NULL);
#endif
 {
  self->SetDisableCollision(disable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDisableCollision'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPhysicsWorld of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_GetPhysicsWorld00
static int tolua_PhysicsLuaAPI_Constraint_GetPhysicsWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint* self = (const Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPhysicsWorld'", NULL);
#endif
 {
  PhysicsWorld* tolua_ret = (PhysicsWorld*)  self->GetPhysicsWorld();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"PhysicsWorld");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPhysicsWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetConstraintType of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_GetConstraintType00
static int tolua_PhysicsLuaAPI_Constraint_GetConstraintType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint* self = (const Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetConstraintType'", NULL);
#endif
 {
  ConstraintType tolua_ret = (ConstraintType)  self->GetConstraintType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetConstraintType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOwnBody of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_GetOwnBody00
static int tolua_PhysicsLuaAPI_Constraint_GetOwnBody00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint* self = (const Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOwnBody'", NULL);
#endif
 {
  RigidBody* tolua_ret = (RigidBody*)  self->GetOwnBody();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"RigidBody");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOwnBody'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOtherBody of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_GetOtherBody00
static int tolua_PhysicsLuaAPI_Constraint_GetOtherBody00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint* self = (const Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOtherBody'", NULL);
#endif
 {
  RigidBody* tolua_ret = (RigidBody*)  self->GetOtherBody();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"RigidBody");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOtherBody'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPosition of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_GetPosition00
static int tolua_PhysicsLuaAPI_Constraint_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint* self = (const Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition'", NULL);
#endif
 {
  const Vector3& tolua_ret = (const Vector3&)  self->GetPosition();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRotation of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_GetRotation00
static int tolua_PhysicsLuaAPI_Constraint_GetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint* self = (const Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRotation'", NULL);
#endif
 {
  const Quaternion& tolua_ret = (const Quaternion&)  self->GetRotation();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Quaternion");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOtherPosition of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_GetOtherPosition00
static int tolua_PhysicsLuaAPI_Constraint_GetOtherPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint* self = (const Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOtherPosition'", NULL);
#endif
 {
  const Vector3& tolua_ret = (const Vector3&)  self->GetOtherPosition();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOtherPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOtherRotation of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_GetOtherRotation00
static int tolua_PhysicsLuaAPI_Constraint_GetOtherRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint* self = (const Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOtherRotation'", NULL);
#endif
 {
  const Quaternion& tolua_ret = (const Quaternion&)  self->GetOtherRotation();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Quaternion");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOtherRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldPosition of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_GetWorldPosition00
static int tolua_PhysicsLuaAPI_Constraint_GetWorldPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint* self = (const Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldPosition'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetWorldPosition();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWorldPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHighLimit of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_GetHighLimit00
static int tolua_PhysicsLuaAPI_Constraint_GetHighLimit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint* self = (const Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHighLimit'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetHighLimit();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHighLimit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLowLimit of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_GetLowLimit00
static int tolua_PhysicsLuaAPI_Constraint_GetLowLimit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint* self = (const Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLowLimit'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetLowLimit();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLowLimit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetERP of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_GetERP00
static int tolua_PhysicsLuaAPI_Constraint_GetERP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint* self = (const Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetERP'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetERP();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetERP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCFM of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_GetCFM00
static int tolua_PhysicsLuaAPI_Constraint_GetCFM00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint* self = (const Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCFM'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetCFM();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCFM'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDisableCollision of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_Constraint_GetDisableCollision00
static int tolua_PhysicsLuaAPI_Constraint_GetDisableCollision00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint* self = (const Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDisableCollision'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetDisableCollision();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDisableCollision'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: physicsWorld of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_physicsWorld_ptr
static int tolua_get_Constraint_physicsWorld_ptr(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'physicsWorld'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetPhysicsWorld(),"PhysicsWorld");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: constraintType of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_constraintType
static int tolua_get_Constraint_constraintType(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'constraintType'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetConstraintType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: constraintType of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_set_Constraint_constraintType
static int tolua_set_Constraint_constraintType(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'constraintType'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetConstraintType(((ConstraintType) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ownBody of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_ownBody_ptr
static int tolua_get_Constraint_ownBody_ptr(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ownBody'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetOwnBody(),"RigidBody");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: otherBody of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_otherBody_ptr
static int tolua_get_Constraint_otherBody_ptr(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherBody'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetOtherBody(),"RigidBody");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: otherBody of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_set_Constraint_otherBody_ptr
static int tolua_set_Constraint_otherBody_ptr(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherBody'",NULL);
 if (!tolua_isusertype(tolua_S,2,"RigidBody",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOtherBody(((RigidBody*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: position of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_position_ref
static int tolua_get_Constraint_position_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetPosition(),"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: position of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_set_Constraint_position_ref
static int tolua_set_Constraint_position_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPosition((*(Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rotation of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_rotation_ref
static int tolua_get_Constraint_rotation_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetRotation(),"Quaternion");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rotation of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_set_Constraint_rotation_ref
static int tolua_set_Constraint_rotation_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRotation((*(Quaternion*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: axis of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_axis_ref
static int tolua_get_Constraint_axis_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'axis'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetAxis(),"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: axis of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_set_Constraint_axis_ref
static int tolua_set_Constraint_axis_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'axis'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAxis((*(Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: otherPosition of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_otherPosition_ref
static int tolua_get_Constraint_otherPosition_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherPosition'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetOtherPosition(),"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: otherPosition of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_set_Constraint_otherPosition_ref
static int tolua_set_Constraint_otherPosition_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherPosition'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOtherPosition((*(Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: otherRotation of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_otherRotation_ref
static int tolua_get_Constraint_otherRotation_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherRotation'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetOtherRotation(),"Quaternion");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: otherRotation of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_set_Constraint_otherRotation_ref
static int tolua_set_Constraint_otherRotation_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherRotation'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOtherRotation((*(Quaternion*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: otherAxis of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_otherAxis_ref
static int tolua_get_Constraint_otherAxis_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherAxis'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetOtherAxis(),"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: otherAxis of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_set_Constraint_otherAxis_ref
static int tolua_set_Constraint_otherAxis_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherAxis'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOtherAxis((*(Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: worldPosition of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_worldPosition
static int tolua_get_Constraint_worldPosition(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldPosition'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetWorldPosition();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector3)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: worldPosition of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_set_Constraint_worldPosition
static int tolua_set_Constraint_worldPosition(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldPosition'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetWorldPosition(*((Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: highLimit of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_highLimit_ref
static int tolua_get_Constraint_highLimit_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'highLimit'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetHighLimit(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: highLimit of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_set_Constraint_highLimit_ref
static int tolua_set_Constraint_highLimit_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'highLimit'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetHighLimit((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: lowLimit of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_lowLimit_ref
static int tolua_get_Constraint_lowLimit_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lowLimit'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetLowLimit(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: lowLimit of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_set_Constraint_lowLimit_ref
static int tolua_set_Constraint_lowLimit_ref(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lowLimit'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLowLimit((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ERP of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_ERP
static int tolua_get_Constraint_ERP(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ERP'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetERP());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ERP of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_set_Constraint_ERP
static int tolua_set_Constraint_ERP(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ERP'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetERP(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CFM of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_CFM
static int tolua_get_Constraint_CFM(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CFM'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetCFM());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: CFM of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_set_Constraint_CFM
static int tolua_set_Constraint_CFM(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CFM'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCFM(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: disableCollision of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_get_Constraint_disableCollision
static int tolua_get_Constraint_disableCollision(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'disableCollision'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetDisableCollision());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: disableCollision of class  Constraint */
#ifndef TOLUA_DISABLE_tolua_set_Constraint_disableCollision
static int tolua_set_Constraint_disableCollision(lua_State* tolua_S)
{
  Constraint* self = (Constraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'disableCollision'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDisableCollision(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  PhysicsRaycastResult */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsRaycastResult_new00
static int tolua_PhysicsLuaAPI_PhysicsRaycastResult_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PhysicsRaycastResult",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PhysicsRaycastResult* tolua_ret = (PhysicsRaycastResult*)  Mtolua_new((PhysicsRaycastResult)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"PhysicsRaycastResult");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  PhysicsRaycastResult */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsRaycastResult_new00_local
static int tolua_PhysicsLuaAPI_PhysicsRaycastResult_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PhysicsRaycastResult",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PhysicsRaycastResult* tolua_ret = (PhysicsRaycastResult*)  Mtolua_new((PhysicsRaycastResult)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"PhysicsRaycastResult");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  PhysicsRaycastResult */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsRaycastResult_delete00
static int tolua_PhysicsLuaAPI_PhysicsRaycastResult_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsRaycastResult",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsRaycastResult* self = (PhysicsRaycastResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: position_ of class  PhysicsRaycastResult */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsRaycastResult_position
static int tolua_get_PhysicsRaycastResult_position(lua_State* tolua_S)
{
  PhysicsRaycastResult* self = (PhysicsRaycastResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->position_,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: position_ of class  PhysicsRaycastResult */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsRaycastResult_position
static int tolua_set_PhysicsRaycastResult_position(lua_State* tolua_S)
{
  PhysicsRaycastResult* self = (PhysicsRaycastResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->position_ = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: normal_ of class  PhysicsRaycastResult */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsRaycastResult_normal
static int tolua_get_PhysicsRaycastResult_normal(lua_State* tolua_S)
{
  PhysicsRaycastResult* self = (PhysicsRaycastResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'normal_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->normal_,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: normal_ of class  PhysicsRaycastResult */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsRaycastResult_normal
static int tolua_set_PhysicsRaycastResult_normal(lua_State* tolua_S)
{
  PhysicsRaycastResult* self = (PhysicsRaycastResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'normal_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->normal_ = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: distance_ of class  PhysicsRaycastResult */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsRaycastResult_distance
static int tolua_get_PhysicsRaycastResult_distance(lua_State* tolua_S)
{
  PhysicsRaycastResult* self = (PhysicsRaycastResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'distance_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->distance_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: distance_ of class  PhysicsRaycastResult */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsRaycastResult_distance
static int tolua_set_PhysicsRaycastResult_distance(lua_State* tolua_S)
{
  PhysicsRaycastResult* self = (PhysicsRaycastResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'distance_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->distance_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: hitFraction_ of class  PhysicsRaycastResult */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsRaycastResult_hitFraction
static int tolua_get_PhysicsRaycastResult_hitFraction(lua_State* tolua_S)
{
  PhysicsRaycastResult* self = (PhysicsRaycastResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hitFraction_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->hitFraction_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: hitFraction_ of class  PhysicsRaycastResult */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsRaycastResult_hitFraction
static int tolua_set_PhysicsRaycastResult_hitFraction(lua_State* tolua_S)
{
  PhysicsRaycastResult* self = (PhysicsRaycastResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hitFraction_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->hitFraction_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: body_ of class  PhysicsRaycastResult */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsRaycastResult_body_ptr
static int tolua_get_PhysicsRaycastResult_body_ptr(lua_State* tolua_S)
{
  PhysicsRaycastResult* self = (PhysicsRaycastResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'body_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->body_,"RigidBody");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: body_ of class  PhysicsRaycastResult */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsRaycastResult_body_ptr
static int tolua_set_PhysicsRaycastResult_body_ptr(lua_State* tolua_S)
{
  PhysicsRaycastResult* self = (PhysicsRaycastResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'body_'",NULL);
 if (!tolua_isusertype(tolua_S,2,"RigidBody",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->body_ = ((RigidBody*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_Update00
static int tolua_PhysicsLuaAPI_PhysicsWorld_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  float timeStep = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
 {
  self->Update(timeStep);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateCollisions of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_UpdateCollisions00
static int tolua_PhysicsLuaAPI_PhysicsWorld_UpdateCollisions00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UpdateCollisions'", NULL);
#endif
 {
  self->UpdateCollisions();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdateCollisions'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFps of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_SetFps00
static int tolua_PhysicsLuaAPI_PhysicsWorld_SetFps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  int fps = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFps'", NULL);
#endif
 {
  self->SetFps(fps);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetGravity of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_SetGravity00
static int tolua_PhysicsLuaAPI_PhysicsWorld_SetGravity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* gravity = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetGravity'", NULL);
#endif
 {
  self->SetGravity(*gravity);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetGravity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxSubSteps of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_SetMaxSubSteps00
static int tolua_PhysicsLuaAPI_PhysicsWorld_SetMaxSubSteps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  int num = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxSubSteps'", NULL);
#endif
 {
  self->SetMaxSubSteps(num);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxSubSteps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetNumIterations of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_SetNumIterations00
static int tolua_PhysicsLuaAPI_PhysicsWorld_SetNumIterations00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  int num = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNumIterations'", NULL);
#endif
 {
  self->SetNumIterations(num);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNumIterations'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUpdateEnabled of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_SetUpdateEnabled00
static int tolua_PhysicsLuaAPI_PhysicsWorld_SetUpdateEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUpdateEnabled'", NULL);
#endif
 {
  self->SetUpdateEnabled(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUpdateEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetInterpolation of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_SetInterpolation00
static int tolua_PhysicsLuaAPI_PhysicsWorld_SetInterpolation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInterpolation'", NULL);
#endif
 {
  self->SetInterpolation(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInterpolation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetInternalEdge of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_SetInternalEdge00
static int tolua_PhysicsLuaAPI_PhysicsWorld_SetInternalEdge00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInternalEdge'", NULL);
#endif
 {
  self->SetInternalEdge(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInternalEdge'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSplitImpulse of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_SetSplitImpulse00
static int tolua_PhysicsLuaAPI_PhysicsWorld_SetSplitImpulse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSplitImpulse'", NULL);
#endif
 {
  self->SetSplitImpulse(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSplitImpulse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxNetworkAngularVelocity of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_SetMaxNetworkAngularVelocity00
static int tolua_PhysicsLuaAPI_PhysicsWorld_SetMaxNetworkAngularVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  float velocity = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxNetworkAngularVelocity'", NULL);
#endif
 {
  self->SetMaxNetworkAngularVelocity(velocity);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxNetworkAngularVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PhysicsWorldRaycast of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_Raycast00
static int tolua_PhysicsLuaAPI_PhysicsWorld_Raycast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ray",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  const Ray* ray = ((const Ray*)  tolua_tousertype(tolua_S,2,0));
  float maxDistance = ((float)  tolua_tonumber(tolua_S,3,0));
  unsigned collisionMask = ((unsigned)  tolua_tonumber(tolua_S,4,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PhysicsWorldRaycast'", NULL);
#endif
 {
  tolua_outside  const PODVector<PhysicsRaycastResult>& tolua_ret = (tolua_outside  const PODVector<PhysicsRaycastResult>&)  PhysicsWorldRaycast(self,*ray,maxDistance,collisionMask);
  ToluaPushPODVector<PhysicsRaycastResult>(tolua_S,(void*)&tolua_ret,"PhysicsRaycastResult");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Raycast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PhysicsWorldRaycastSingle of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_RaycastSingle00
static int tolua_PhysicsLuaAPI_PhysicsWorld_RaycastSingle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ray",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  const Ray* ray = ((const Ray*)  tolua_tousertype(tolua_S,2,0));
  float maxDistance = ((float)  tolua_tonumber(tolua_S,3,0));
  unsigned collisionMask = ((unsigned)  tolua_tonumber(tolua_S,4,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PhysicsWorldRaycastSingle'", NULL);
#endif
 {
  tolua_outside PhysicsRaycastResult tolua_ret = (tolua_outside PhysicsRaycastResult)  PhysicsWorldRaycastSingle(self,*ray,maxDistance,collisionMask);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((PhysicsRaycastResult)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"PhysicsRaycastResult");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(PhysicsRaycastResult));
  tolua_pushusertype(tolua_S,tolua_obj,"PhysicsRaycastResult");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RaycastSingle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PhysicsWorldRaycastSingleSegmented of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_RaycastSingleSegmented00
static int tolua_PhysicsLuaAPI_PhysicsWorld_RaycastSingleSegmented00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ray",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  const Ray* ray = ((const Ray*)  tolua_tousertype(tolua_S,2,0));
  float maxDistance = ((float)  tolua_tonumber(tolua_S,3,0));
  float segmentDistance = ((float)  tolua_tonumber(tolua_S,4,0));
  unsigned collisionMask = ((unsigned)  tolua_tonumber(tolua_S,5,M_MAX_UNSIGNED));
  float overlapDistance = ((float)  tolua_tonumber(tolua_S,6,0.1f));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PhysicsWorldRaycastSingleSegmented'", NULL);
#endif
 {
  tolua_outside PhysicsRaycastResult tolua_ret = (tolua_outside PhysicsRaycastResult)  PhysicsWorldRaycastSingleSegmented(self,*ray,maxDistance,segmentDistance,collisionMask,overlapDistance);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((PhysicsRaycastResult)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"PhysicsRaycastResult");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(PhysicsRaycastResult));
  tolua_pushusertype(tolua_S,tolua_obj,"PhysicsRaycastResult");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RaycastSingleSegmented'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PhysicsWorldSphereCast of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_SphereCast00
static int tolua_PhysicsLuaAPI_PhysicsWorld_SphereCast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ray",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  const Ray* ray = ((const Ray*)  tolua_tousertype(tolua_S,2,0));
  float radius = ((float)  tolua_tonumber(tolua_S,3,0));
  float maxDistance = ((float)  tolua_tonumber(tolua_S,4,0));
  unsigned collisionMask = ((unsigned)  tolua_tonumber(tolua_S,5,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PhysicsWorldSphereCast'", NULL);
#endif
 {
  tolua_outside PhysicsRaycastResult tolua_ret = (tolua_outside PhysicsRaycastResult)  PhysicsWorldSphereCast(self,*ray,radius,maxDistance,collisionMask);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((PhysicsRaycastResult)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"PhysicsRaycastResult");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(PhysicsRaycastResult));
  tolua_pushusertype(tolua_S,tolua_obj,"PhysicsRaycastResult");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SphereCast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PhysicsWorldConvexCast of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_ConvexCast00
static int tolua_PhysicsLuaAPI_PhysicsWorld_ConvexCast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CollisionShape",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Quaternion",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  CollisionShape* shape = ((CollisionShape*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* startPos = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Quaternion* startRot = ((const Quaternion*)  tolua_tousertype(tolua_S,4,0));
  const Vector3* endPos = ((const Vector3*)  tolua_tousertype(tolua_S,5,0));
  const Quaternion* endRot = ((const Quaternion*)  tolua_tousertype(tolua_S,6,0));
  unsigned collisionMask = ((unsigned)  tolua_tonumber(tolua_S,7,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PhysicsWorldConvexCast'", NULL);
#endif
 {
  tolua_outside PhysicsRaycastResult tolua_ret = (tolua_outside PhysicsRaycastResult)  PhysicsWorldConvexCast(self,shape,*startPos,*startRot,*endPos,*endRot,collisionMask);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((PhysicsRaycastResult)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"PhysicsRaycastResult");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(PhysicsRaycastResult));
  tolua_pushusertype(tolua_S,tolua_obj,"PhysicsRaycastResult");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ConvexCast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PhysicsWorldGetRigidBodiesSphere of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_GetRigidBodies00
static int tolua_PhysicsLuaAPI_PhysicsWorld_GetRigidBodies00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sphere",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  const Sphere* sphere = ((const Sphere*)  tolua_tousertype(tolua_S,2,0));
  unsigned collisionMask = ((unsigned)  tolua_tonumber(tolua_S,3,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PhysicsWorldGetRigidBodiesSphere'", NULL);
#endif
 {
  tolua_outside  const PODVector<RigidBody*>& tolua_ret = (tolua_outside  const PODVector<RigidBody*>&)  PhysicsWorldGetRigidBodiesSphere(self,*sphere,collisionMask);
  ToluaPushPODVector<RigidBody*>("",tolua_S,(void*)&tolua_ret,"RigidBody");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRigidBodies'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PhysicsWorldGetRigidBodiesBox of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_GetRigidBodies01
static int tolua_PhysicsLuaAPI_PhysicsWorld_GetRigidBodies01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* box = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
  unsigned collisionMask = ((unsigned)  tolua_tonumber(tolua_S,3,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PhysicsWorldGetRigidBodiesBox'", NULL);
#endif
 {
  tolua_outside  const PODVector<RigidBody*>& tolua_ret = (tolua_outside  const PODVector<RigidBody*>&)  PhysicsWorldGetRigidBodiesBox(self,*box,collisionMask);
  ToluaPushPODVector<RigidBody*>("",tolua_S,(void*)&tolua_ret,"RigidBody");
 }
 }
 return 1;
tolua_lerror:
 return tolua_PhysicsLuaAPI_PhysicsWorld_GetRigidBodies00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: PhysicsWorldGetRigidBodiesBody of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_GetRigidBodies02
static int tolua_PhysicsLuaAPI_PhysicsWorld_GetRigidBodies02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  const RigidBody* body = ((const RigidBody*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PhysicsWorldGetRigidBodiesBody'", NULL);
#endif
 {
  tolua_outside  const PODVector<RigidBody*>& tolua_ret = (tolua_outside  const PODVector<RigidBody*>&)  PhysicsWorldGetRigidBodiesBody(self,body);
  ToluaPushPODVector<RigidBody*>("",tolua_S,(void*)&tolua_ret,"RigidBody");
 }
 }
 return 1;
tolua_lerror:
 return tolua_PhysicsLuaAPI_PhysicsWorld_GetRigidBodies01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: PhysicsWorldGetCollidingBodies of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_GetCollidingBodies00
static int tolua_PhysicsLuaAPI_PhysicsWorld_GetCollidingBodies00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  const RigidBody* body = ((const RigidBody*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PhysicsWorldGetCollidingBodies'", NULL);
#endif
 {
  tolua_outside  const PODVector<RigidBody*>& tolua_ret = (tolua_outside  const PODVector<RigidBody*>&)  PhysicsWorldGetCollidingBodies(self,body);
  ToluaPushPODVector<RigidBody*>("",tolua_S,(void*)&tolua_ret,"RigidBody");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCollidingBodies'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawDebugGeometry of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_DrawDebugGeometry00
static int tolua_PhysicsLuaAPI_PhysicsWorld_DrawDebugGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  bool depthTest = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawDebugGeometry'", NULL);
#endif
 {
  self->DrawDebugGeometry(depthTest);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawDebugGeometry'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveCachedGeometry of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_RemoveCachedGeometry00
static int tolua_PhysicsLuaAPI_PhysicsWorld_RemoveCachedGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Model",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
  Model* model = ((Model*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveCachedGeometry'", NULL);
#endif
 {
  self->RemoveCachedGeometry(model);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveCachedGeometry'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGravity of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_GetGravity00
static int tolua_PhysicsLuaAPI_PhysicsWorld_GetGravity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld* self = (const PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGravity'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetGravity();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGravity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxSubSteps of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_GetMaxSubSteps00
static int tolua_PhysicsLuaAPI_PhysicsWorld_GetMaxSubSteps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld* self = (const PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxSubSteps'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetMaxSubSteps();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxSubSteps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumIterations of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_GetNumIterations00
static int tolua_PhysicsLuaAPI_PhysicsWorld_GetNumIterations00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld* self = (const PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumIterations'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetNumIterations();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumIterations'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsUpdateEnabled of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_IsUpdateEnabled00
static int tolua_PhysicsLuaAPI_PhysicsWorld_IsUpdateEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld* self = (const PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsUpdateEnabled'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsUpdateEnabled();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsUpdateEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInterpolation of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_GetInterpolation00
static int tolua_PhysicsLuaAPI_PhysicsWorld_GetInterpolation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld* self = (const PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInterpolation'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetInterpolation();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInterpolation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInternalEdge of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_GetInternalEdge00
static int tolua_PhysicsLuaAPI_PhysicsWorld_GetInternalEdge00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld* self = (const PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInternalEdge'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetInternalEdge();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInternalEdge'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSplitImpulse of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_GetSplitImpulse00
static int tolua_PhysicsLuaAPI_PhysicsWorld_GetSplitImpulse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld* self = (const PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSplitImpulse'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetSplitImpulse();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSplitImpulse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFps of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_GetFps00
static int tolua_PhysicsLuaAPI_PhysicsWorld_GetFps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld* self = (const PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFps'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetFps();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxNetworkAngularVelocity of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_PhysicsWorld_GetMaxNetworkAngularVelocity00
static int tolua_PhysicsLuaAPI_PhysicsWorld_GetMaxNetworkAngularVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld* self = (const PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxNetworkAngularVelocity'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxNetworkAngularVelocity();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxNetworkAngularVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: gravity of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld_gravity
static int tolua_get_PhysicsWorld_gravity(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gravity'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetGravity();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector3)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: gravity of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld_gravity
static int tolua_set_PhysicsWorld_gravity(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gravity'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetGravity(*((Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxSubSteps of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld_maxSubSteps
static int tolua_get_PhysicsWorld_maxSubSteps(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxSubSteps'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxSubSteps());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxSubSteps of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld_maxSubSteps
static int tolua_set_PhysicsWorld_maxSubSteps(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxSubSteps'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxSubSteps(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numIterations of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld_numIterations
static int tolua_get_PhysicsWorld_numIterations(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numIterations'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumIterations());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: numIterations of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld_numIterations
static int tolua_set_PhysicsWorld_numIterations(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numIterations'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetNumIterations(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: updateEnabled of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld_updateEnabled
static int tolua_get_PhysicsWorld_updateEnabled(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'updateEnabled'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsUpdateEnabled());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: updateEnabled of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld_updateEnabled
static int tolua_set_PhysicsWorld_updateEnabled(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'updateEnabled'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUpdateEnabled(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: interpolation of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld_interpolation
static int tolua_get_PhysicsWorld_interpolation(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'interpolation'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetInterpolation());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: interpolation of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld_interpolation
static int tolua_set_PhysicsWorld_interpolation(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'interpolation'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetInterpolation(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: internalEdge of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld_internalEdge
static int tolua_get_PhysicsWorld_internalEdge(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'internalEdge'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetInternalEdge());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: internalEdge of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld_internalEdge
static int tolua_set_PhysicsWorld_internalEdge(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'internalEdge'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetInternalEdge(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: splitImpulse of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld_splitImpulse
static int tolua_get_PhysicsWorld_splitImpulse(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'splitImpulse'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetSplitImpulse());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: splitImpulse of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld_splitImpulse
static int tolua_set_PhysicsWorld_splitImpulse(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'splitImpulse'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSplitImpulse(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fps of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld_fps
static int tolua_get_PhysicsWorld_fps(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fps'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFps());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: fps of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld_fps
static int tolua_set_PhysicsWorld_fps(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fps'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFps(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxNetworkAngularVelocity of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld_maxNetworkAngularVelocity
static int tolua_get_PhysicsWorld_maxNetworkAngularVelocity(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxNetworkAngularVelocity'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxNetworkAngularVelocity());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxNetworkAngularVelocity of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld_maxNetworkAngularVelocity
static int tolua_set_PhysicsWorld_maxNetworkAngularVelocity(lua_State* tolua_S)
{
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxNetworkAngularVelocity'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxNetworkAngularVelocity(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMass of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetMass00
static int tolua_PhysicsLuaAPI_RigidBody_SetMass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  float mass = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMass'", NULL);
#endif
 {
  self->SetMass(mass);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetPosition00
static int tolua_PhysicsLuaAPI_RigidBody_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
 {
  self->SetPosition(*position);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRotation of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetRotation00
static int tolua_PhysicsLuaAPI_RigidBody_SetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRotation'", NULL);
#endif
 {
  self->SetRotation(*rotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTransform of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetTransform00
static int tolua_PhysicsLuaAPI_RigidBody_SetTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTransform'", NULL);
#endif
 {
  self->SetTransform(*position,*rotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLinearVelocity of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetLinearVelocity00
static int tolua_PhysicsLuaAPI_RigidBody_SetLinearVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* velocity = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLinearVelocity'", NULL);
#endif
 {
  self->SetLinearVelocity(*velocity);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLinearVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLinearFactor of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetLinearFactor00
static int tolua_PhysicsLuaAPI_RigidBody_SetLinearFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* factor = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLinearFactor'", NULL);
#endif
 {
  self->SetLinearFactor(*factor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLinearFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLinearRestThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetLinearRestThreshold00
static int tolua_PhysicsLuaAPI_RigidBody_SetLinearRestThreshold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  float threshold = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLinearRestThreshold'", NULL);
#endif
 {
  self->SetLinearRestThreshold(threshold);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLinearRestThreshold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLinearDamping of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetLinearDamping00
static int tolua_PhysicsLuaAPI_RigidBody_SetLinearDamping00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  float damping = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLinearDamping'", NULL);
#endif
 {
  self->SetLinearDamping(damping);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLinearDamping'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAngularVelocity of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetAngularVelocity00
static int tolua_PhysicsLuaAPI_RigidBody_SetAngularVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* angularVelocity = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngularVelocity'", NULL);
#endif
 {
  self->SetAngularVelocity(*angularVelocity);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAngularVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAngularFactor of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetAngularFactor00
static int tolua_PhysicsLuaAPI_RigidBody_SetAngularFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* factor = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngularFactor'", NULL);
#endif
 {
  self->SetAngularFactor(*factor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAngularFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAngularRestThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetAngularRestThreshold00
static int tolua_PhysicsLuaAPI_RigidBody_SetAngularRestThreshold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  float threshold = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngularRestThreshold'", NULL);
#endif
 {
  self->SetAngularRestThreshold(threshold);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAngularRestThreshold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAngularDamping of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetAngularDamping00
static int tolua_PhysicsLuaAPI_RigidBody_SetAngularDamping00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  float factor = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngularDamping'", NULL);
#endif
 {
  self->SetAngularDamping(factor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAngularDamping'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFriction of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetFriction00
static int tolua_PhysicsLuaAPI_RigidBody_SetFriction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  float friction = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFriction'", NULL);
#endif
 {
  self->SetFriction(friction);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFriction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAnisotropicFriction of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetAnisotropicFriction00
static int tolua_PhysicsLuaAPI_RigidBody_SetAnisotropicFriction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* friction = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnisotropicFriction'", NULL);
#endif
 {
  self->SetAnisotropicFriction(*friction);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAnisotropicFriction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRollingFriction of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetRollingFriction00
static int tolua_PhysicsLuaAPI_RigidBody_SetRollingFriction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  float friction = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRollingFriction'", NULL);
#endif
 {
  self->SetRollingFriction(friction);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRollingFriction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRestitution of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetRestitution00
static int tolua_PhysicsLuaAPI_RigidBody_SetRestitution00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  float restitution = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRestitution'", NULL);
#endif
 {
  self->SetRestitution(restitution);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRestitution'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetContactProcessingThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetContactProcessingThreshold00
static int tolua_PhysicsLuaAPI_RigidBody_SetContactProcessingThreshold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  float threshold = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetContactProcessingThreshold'", NULL);
#endif
 {
  self->SetContactProcessingThreshold(threshold);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetContactProcessingThreshold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCcdRadius of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetCcdRadius00
static int tolua_PhysicsLuaAPI_RigidBody_SetCcdRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  float radius = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCcdRadius'", NULL);
#endif
 {
  self->SetCcdRadius(radius);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCcdRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCcdMotionThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetCcdMotionThreshold00
static int tolua_PhysicsLuaAPI_RigidBody_SetCcdMotionThreshold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  float threshold = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCcdMotionThreshold'", NULL);
#endif
 {
  self->SetCcdMotionThreshold(threshold);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCcdMotionThreshold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseGravity of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetUseGravity00
static int tolua_PhysicsLuaAPI_RigidBody_SetUseGravity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseGravity'", NULL);
#endif
 {
  self->SetUseGravity(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseGravity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetGravityOverride of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetGravityOverride00
static int tolua_PhysicsLuaAPI_RigidBody_SetGravityOverride00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* gravity = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetGravityOverride'", NULL);
#endif
 {
  self->SetGravityOverride(*gravity);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetGravityOverride'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetKinematic of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetKinematic00
static int tolua_PhysicsLuaAPI_RigidBody_SetKinematic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetKinematic'", NULL);
#endif
 {
  self->SetKinematic(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetKinematic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTrigger of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetTrigger00
static int tolua_PhysicsLuaAPI_RigidBody_SetTrigger00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTrigger'", NULL);
#endif
 {
  self->SetTrigger(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTrigger'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCollisionLayer of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetCollisionLayer00
static int tolua_PhysicsLuaAPI_RigidBody_SetCollisionLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  unsigned layer = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCollisionLayer'", NULL);
#endif
 {
  self->SetCollisionLayer(layer);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCollisionLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCollisionMask of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetCollisionMask00
static int tolua_PhysicsLuaAPI_RigidBody_SetCollisionMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  unsigned mask = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCollisionMask'", NULL);
#endif
 {
  self->SetCollisionMask(mask);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCollisionMask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCollisionLayerAndMask of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetCollisionLayerAndMask00
static int tolua_PhysicsLuaAPI_RigidBody_SetCollisionLayerAndMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  unsigned layer = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  unsigned mask = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCollisionLayerAndMask'", NULL);
#endif
 {
  self->SetCollisionLayerAndMask(layer,mask);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCollisionLayerAndMask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCollisionEventMode of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_SetCollisionEventMode00
static int tolua_PhysicsLuaAPI_RigidBody_SetCollisionEventMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  CollisionEventMode mode = ((CollisionEventMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCollisionEventMode'", NULL);
#endif
 {
  self->SetCollisionEventMode(mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCollisionEventMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DisableMassUpdate of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_DisableMassUpdate00
static int tolua_PhysicsLuaAPI_RigidBody_DisableMassUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DisableMassUpdate'", NULL);
#endif
 {
  self->DisableMassUpdate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DisableMassUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: EnableMassUpdate of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_EnableMassUpdate00
static int tolua_PhysicsLuaAPI_RigidBody_EnableMassUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'EnableMassUpdate'", NULL);
#endif
 {
  self->EnableMassUpdate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EnableMassUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyForce of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_ApplyForce00
static int tolua_PhysicsLuaAPI_RigidBody_ApplyForce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* force = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyForce'", NULL);
#endif
 {
  self->ApplyForce(*force);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyForce'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyForce of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_ApplyForce01
static int tolua_PhysicsLuaAPI_RigidBody_ApplyForce01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* force = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyForce'", NULL);
#endif
 {
  self->ApplyForce(*force,*position);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_RigidBody_ApplyForce00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyTorque of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_ApplyTorque00
static int tolua_PhysicsLuaAPI_RigidBody_ApplyTorque00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* torque = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyTorque'", NULL);
#endif
 {
  self->ApplyTorque(*torque);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyTorque'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyImpulse of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_ApplyImpulse00
static int tolua_PhysicsLuaAPI_RigidBody_ApplyImpulse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* impulse = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyImpulse'", NULL);
#endif
 {
  self->ApplyImpulse(*impulse);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyImpulse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyImpulse of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_ApplyImpulse01
static int tolua_PhysicsLuaAPI_RigidBody_ApplyImpulse01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* impulse = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyImpulse'", NULL);
#endif
 {
  self->ApplyImpulse(*impulse,*position);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_RigidBody_ApplyImpulse00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyTorqueImpulse of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_ApplyTorqueImpulse00
static int tolua_PhysicsLuaAPI_RigidBody_ApplyTorqueImpulse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* torque = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyTorqueImpulse'", NULL);
#endif
 {
  self->ApplyTorqueImpulse(*torque);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyTorqueImpulse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResetForces of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_ResetForces00
static int tolua_PhysicsLuaAPI_RigidBody_ResetForces00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResetForces'", NULL);
#endif
 {
  self->ResetForces();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResetForces'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Activate of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_Activate00
static int tolua_PhysicsLuaAPI_RigidBody_Activate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Activate'", NULL);
#endif
 {
  self->Activate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Activate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReAddBodyToWorld of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_ReAddBodyToWorld00
static int tolua_PhysicsLuaAPI_RigidBody_ReAddBodyToWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReAddBodyToWorld'", NULL);
#endif
 {
  self->ReAddBodyToWorld();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReAddBodyToWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPhysicsWorld of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetPhysicsWorld00
static int tolua_PhysicsLuaAPI_RigidBody_GetPhysicsWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPhysicsWorld'", NULL);
#endif
 {
  PhysicsWorld* tolua_ret = (PhysicsWorld*)  self->GetPhysicsWorld();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"PhysicsWorld");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPhysicsWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMass of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetMass00
static int tolua_PhysicsLuaAPI_RigidBody_GetMass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMass'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMass();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPosition of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetPosition00
static int tolua_PhysicsLuaAPI_RigidBody_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetPosition();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRotation of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetRotation00
static int tolua_PhysicsLuaAPI_RigidBody_GetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRotation'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->GetRotation();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLinearVelocity of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetLinearVelocity00
static int tolua_PhysicsLuaAPI_RigidBody_GetLinearVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLinearVelocity'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetLinearVelocity();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLinearVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLinearFactor of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetLinearFactor00
static int tolua_PhysicsLuaAPI_RigidBody_GetLinearFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLinearFactor'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetLinearFactor();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLinearFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVelocityAtPoint of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetVelocityAtPoint00
static int tolua_PhysicsLuaAPI_RigidBody_GetVelocityAtPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVelocityAtPoint'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetVelocityAtPoint(*position);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVelocityAtPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLinearRestThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetLinearRestThreshold00
static int tolua_PhysicsLuaAPI_RigidBody_GetLinearRestThreshold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLinearRestThreshold'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetLinearRestThreshold();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLinearRestThreshold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLinearDamping of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetLinearDamping00
static int tolua_PhysicsLuaAPI_RigidBody_GetLinearDamping00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLinearDamping'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetLinearDamping();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLinearDamping'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAngularVelocity of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetAngularVelocity00
static int tolua_PhysicsLuaAPI_RigidBody_GetAngularVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAngularVelocity'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetAngularVelocity();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAngularVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAngularFactor of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetAngularFactor00
static int tolua_PhysicsLuaAPI_RigidBody_GetAngularFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAngularFactor'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetAngularFactor();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAngularFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAngularRestThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetAngularRestThreshold00
static int tolua_PhysicsLuaAPI_RigidBody_GetAngularRestThreshold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAngularRestThreshold'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAngularRestThreshold();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAngularRestThreshold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAngularDamping of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetAngularDamping00
static int tolua_PhysicsLuaAPI_RigidBody_GetAngularDamping00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAngularDamping'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAngularDamping();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAngularDamping'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFriction of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetFriction00
static int tolua_PhysicsLuaAPI_RigidBody_GetFriction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFriction'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetFriction();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFriction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnisotropicFriction of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetAnisotropicFriction00
static int tolua_PhysicsLuaAPI_RigidBody_GetAnisotropicFriction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnisotropicFriction'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetAnisotropicFriction();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAnisotropicFriction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRollingFriction of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetRollingFriction00
static int tolua_PhysicsLuaAPI_RigidBody_GetRollingFriction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRollingFriction'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRollingFriction();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRollingFriction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRestitution of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetRestitution00
static int tolua_PhysicsLuaAPI_RigidBody_GetRestitution00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRestitution'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRestitution();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRestitution'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetContactProcessingThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetContactProcessingThreshold00
static int tolua_PhysicsLuaAPI_RigidBody_GetContactProcessingThreshold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetContactProcessingThreshold'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetContactProcessingThreshold();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetContactProcessingThreshold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCcdRadius of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetCcdRadius00
static int tolua_PhysicsLuaAPI_RigidBody_GetCcdRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCcdRadius'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetCcdRadius();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCcdRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCcdMotionThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetCcdMotionThreshold00
static int tolua_PhysicsLuaAPI_RigidBody_GetCcdMotionThreshold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCcdMotionThreshold'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetCcdMotionThreshold();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCcdMotionThreshold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUseGravity of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetUseGravity00
static int tolua_PhysicsLuaAPI_RigidBody_GetUseGravity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUseGravity'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetUseGravity();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUseGravity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGravityOverride of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetGravityOverride00
static int tolua_PhysicsLuaAPI_RigidBody_GetGravityOverride00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGravityOverride'", NULL);
#endif
 {
  const Vector3& tolua_ret = (const Vector3&)  self->GetGravityOverride();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGravityOverride'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCenterOfMass of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetCenterOfMass00
static int tolua_PhysicsLuaAPI_RigidBody_GetCenterOfMass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCenterOfMass'", NULL);
#endif
 {
  const Vector3& tolua_ret = (const Vector3&)  self->GetCenterOfMass();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCenterOfMass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsKinematic of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_IsKinematic00
static int tolua_PhysicsLuaAPI_RigidBody_IsKinematic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsKinematic'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsKinematic();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsKinematic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsTrigger of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_IsTrigger00
static int tolua_PhysicsLuaAPI_RigidBody_IsTrigger00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsTrigger'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsTrigger();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsTrigger'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsActive of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_IsActive00
static int tolua_PhysicsLuaAPI_RigidBody_IsActive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsActive'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsActive();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsActive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCollisionLayer of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetCollisionLayer00
static int tolua_PhysicsLuaAPI_RigidBody_GetCollisionLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCollisionLayer'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetCollisionLayer();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCollisionLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCollisionMask of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetCollisionMask00
static int tolua_PhysicsLuaAPI_RigidBody_GetCollisionMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCollisionMask'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetCollisionMask();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCollisionMask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCollisionEventMode of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RigidBody_GetCollisionEventMode00
static int tolua_PhysicsLuaAPI_RigidBody_GetCollisionEventMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody* self = (const RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCollisionEventMode'", NULL);
#endif
 {
  CollisionEventMode tolua_ret = (CollisionEventMode)  self->GetCollisionEventMode();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCollisionEventMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: physicsWorld of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_physicsWorld_ptr
static int tolua_get_RigidBody_physicsWorld_ptr(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'physicsWorld'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetPhysicsWorld(),"PhysicsWorld");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mass of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_mass
static int tolua_get_RigidBody_mass(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mass'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMass());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mass of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_mass
static int tolua_set_RigidBody_mass(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mass'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMass(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: position of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_position
static int tolua_get_RigidBody_position(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetPosition();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector3)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: position of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_position
static int tolua_set_RigidBody_position(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPosition(*((Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rotation of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_rotation
static int tolua_get_RigidBody_rotation(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
#endif
 Quaternion tolua_ret = (Quaternion)self->GetRotation();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Quaternion)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
 tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rotation of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_rotation
static int tolua_set_RigidBody_rotation(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRotation(*((Quaternion*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: linearVelocity of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_linearVelocity
static int tolua_get_RigidBody_linearVelocity(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'linearVelocity'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetLinearVelocity();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector3)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: linearVelocity of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_linearVelocity
static int tolua_set_RigidBody_linearVelocity(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'linearVelocity'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLinearVelocity(*((Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: linearFactor of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_linearFactor
static int tolua_get_RigidBody_linearFactor(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'linearFactor'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetLinearFactor();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector3)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: linearFactor of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_linearFactor
static int tolua_set_RigidBody_linearFactor(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'linearFactor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLinearFactor(*((Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: linearRestThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_linearRestThreshold
static int tolua_get_RigidBody_linearRestThreshold(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'linearRestThreshold'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLinearRestThreshold());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: linearRestThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_linearRestThreshold
static int tolua_set_RigidBody_linearRestThreshold(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'linearRestThreshold'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLinearRestThreshold(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: linearDamping of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_linearDamping
static int tolua_get_RigidBody_linearDamping(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'linearDamping'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLinearDamping());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: linearDamping of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_linearDamping
static int tolua_set_RigidBody_linearDamping(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'linearDamping'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLinearDamping(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: angularVelocity of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_angularVelocity
static int tolua_get_RigidBody_angularVelocity(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'angularVelocity'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetAngularVelocity();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector3)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: angularVelocity of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_angularVelocity
static int tolua_set_RigidBody_angularVelocity(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'angularVelocity'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAngularVelocity(*((Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: angularFactor of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_angularFactor
static int tolua_get_RigidBody_angularFactor(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'angularFactor'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetAngularFactor();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector3)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: angularFactor of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_angularFactor
static int tolua_set_RigidBody_angularFactor(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'angularFactor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAngularFactor(*((Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: angularRestThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_angularRestThreshold
static int tolua_get_RigidBody_angularRestThreshold(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'angularRestThreshold'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAngularRestThreshold());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: angularRestThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_angularRestThreshold
static int tolua_set_RigidBody_angularRestThreshold(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'angularRestThreshold'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAngularRestThreshold(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: angularDamping of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_angularDamping
static int tolua_get_RigidBody_angularDamping(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'angularDamping'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAngularDamping());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: angularDamping of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_angularDamping
static int tolua_set_RigidBody_angularDamping(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'angularDamping'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAngularDamping(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: friction of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_friction
static int tolua_get_RigidBody_friction(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'friction'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFriction());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: friction of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_friction
static int tolua_set_RigidBody_friction(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'friction'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFriction(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: anisotropicFriction of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_anisotropicFriction
static int tolua_get_RigidBody_anisotropicFriction(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'anisotropicFriction'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetAnisotropicFriction();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector3)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: anisotropicFriction of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_anisotropicFriction
static int tolua_set_RigidBody_anisotropicFriction(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'anisotropicFriction'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAnisotropicFriction(*((Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rollingFriction of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_rollingFriction
static int tolua_get_RigidBody_rollingFriction(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rollingFriction'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRollingFriction());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rollingFriction of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_rollingFriction
static int tolua_set_RigidBody_rollingFriction(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rollingFriction'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRollingFriction(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: restitution of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_restitution
static int tolua_get_RigidBody_restitution(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'restitution'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRestitution());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: restitution of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_restitution
static int tolua_set_RigidBody_restitution(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'restitution'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRestitution(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: contactProcessingThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_contactProcessingThreshold
static int tolua_get_RigidBody_contactProcessingThreshold(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'contactProcessingThreshold'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetContactProcessingThreshold());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: contactProcessingThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_contactProcessingThreshold
static int tolua_set_RigidBody_contactProcessingThreshold(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'contactProcessingThreshold'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetContactProcessingThreshold(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ccdRadius of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_ccdRadius
static int tolua_get_RigidBody_ccdRadius(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ccdRadius'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetCcdRadius());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ccdRadius of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_ccdRadius
static int tolua_set_RigidBody_ccdRadius(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ccdRadius'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCcdRadius(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ccdMotionThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_ccdMotionThreshold
static int tolua_get_RigidBody_ccdMotionThreshold(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ccdMotionThreshold'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetCcdMotionThreshold());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ccdMotionThreshold of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_ccdMotionThreshold
static int tolua_set_RigidBody_ccdMotionThreshold(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ccdMotionThreshold'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCcdMotionThreshold(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: useGravity of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_useGravity
static int tolua_get_RigidBody_useGravity(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useGravity'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetUseGravity());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: useGravity of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_useGravity
static int tolua_set_RigidBody_useGravity(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useGravity'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUseGravity(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: gravityOverride of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_gravityOverride_ref
static int tolua_get_RigidBody_gravityOverride_ref(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gravityOverride'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetGravityOverride(),"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: gravityOverride of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_gravityOverride_ref
static int tolua_set_RigidBody_gravityOverride_ref(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gravityOverride'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetGravityOverride((*(Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: centerOfMass of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_centerOfMass_ref
static int tolua_get_RigidBody_centerOfMass_ref(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'centerOfMass'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetCenterOfMass(),"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: kinematic of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_kinematic
static int tolua_get_RigidBody_kinematic(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'kinematic'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsKinematic());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: kinematic of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_kinematic
static int tolua_set_RigidBody_kinematic(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'kinematic'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetKinematic(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: trigger of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_trigger
static int tolua_get_RigidBody_trigger(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'trigger'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsTrigger());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: trigger of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_trigger
static int tolua_set_RigidBody_trigger(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'trigger'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTrigger(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: active of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_active
static int tolua_get_RigidBody_active(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'active'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsActive());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: collisionLayer of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_collisionLayer
static int tolua_get_RigidBody_collisionLayer(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'collisionLayer'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetCollisionLayer());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: collisionLayer of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_collisionLayer
static int tolua_set_RigidBody_collisionLayer(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'collisionLayer'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCollisionLayer(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: collisionMask of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_collisionMask
static int tolua_get_RigidBody_collisionMask(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'collisionMask'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetCollisionMask());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: collisionMask of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_collisionMask
static int tolua_set_RigidBody_collisionMask(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'collisionMask'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCollisionMask(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: collisionEventMode of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody_collisionEventMode
static int tolua_get_RigidBody_collisionEventMode(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'collisionEventMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetCollisionEventMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: collisionEventMode of class  RigidBody */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody_collisionEventMode
static int tolua_set_RigidBody_collisionEventMode(lua_State* tolua_S)
{
  RigidBody* self = (RigidBody*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'collisionEventMode'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCollisionEventMode(((CollisionEventMode) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_new00
static int tolua_PhysicsLuaAPI_RaycastVehicle_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Urho3D::Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Urho3D::Context* context = ((Urho3D::Context*)  tolua_tousertype(tolua_S,2,0));
 {
  RaycastVehicle* tolua_ret = (RaycastVehicle*)  Mtolua_new((RaycastVehicle)(context));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"RaycastVehicle");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_new00_local
static int tolua_PhysicsLuaAPI_RaycastVehicle_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Urho3D::Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Urho3D::Context* context = ((Urho3D::Context*)  tolua_tousertype(tolua_S,2,0));
 {
  RaycastVehicle* tolua_ret = (RaycastVehicle*)  Mtolua_new((RaycastVehicle)(context));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"RaycastVehicle");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_delete00
static int tolua_PhysicsLuaAPI_RaycastVehicle_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
 Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterObject of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_RegisterObject00
static int tolua_PhysicsLuaAPI_RaycastVehicle_RegisterObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Context* context = ((Context*)  tolua_tousertype(tolua_S,2,0));
 {
  RaycastVehicle::RegisterObject(context);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyAttributes of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_ApplyAttributes00
static int tolua_PhysicsLuaAPI_RaycastVehicle_ApplyAttributes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyAttributes'", NULL);
#endif
 {
  self->ApplyAttributes();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyAttributes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddWheel of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_AddWheel00
static int tolua_PhysicsLuaAPI_RaycastVehicle_AddWheel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  Node* wheelNode = ((Node*)  tolua_tousertype(tolua_S,2,0));
  Vector3 wheelDirection = *((Vector3*)  tolua_tousertype(tolua_S,3,0));
  Vector3 wheelAxle = *((Vector3*)  tolua_tousertype(tolua_S,4,0));
  float restLength = ((float)  tolua_tonumber(tolua_S,5,0));
  float wheelRadius = ((float)  tolua_tonumber(tolua_S,6,0));
  bool frontWheel = ((bool)  tolua_toboolean(tolua_S,7,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddWheel'", NULL);
#endif
 {
  self->AddWheel(wheelNode,wheelDirection,wheelAxle,restLength,wheelRadius,frontWheel);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddWheel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResetSuspension of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_ResetSuspension00
static int tolua_PhysicsLuaAPI_RaycastVehicle_ResetSuspension00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResetSuspension'", NULL);
#endif
 {
  self->ResetSuspension();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResetSuspension'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateWheelTransform of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_UpdateWheelTransform00
static int tolua_PhysicsLuaAPI_RaycastVehicle_UpdateWheelTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  bool interpolated = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UpdateWheelTransform'", NULL);
#endif
 {
  self->UpdateWheelTransform(wheel,interpolated);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdateWheelTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSteeringValue of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetSteeringValue00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetSteeringValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  float steeringValue = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSteeringValue'", NULL);
#endif
 {
  self->SetSteeringValue(wheel,steeringValue);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSteeringValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWheelSuspensionStiffness of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelSuspensionStiffness00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelSuspensionStiffness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  float stiffness = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWheelSuspensionStiffness'", NULL);
#endif
 {
  self->SetWheelSuspensionStiffness(wheel,stiffness);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWheelSuspensionStiffness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWheelDampingRelaxation of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelDampingRelaxation00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelDampingRelaxation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  float damping = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWheelDampingRelaxation'", NULL);
#endif
 {
  self->SetWheelDampingRelaxation(wheel,damping);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWheelDampingRelaxation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWheelDampingCompression of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelDampingCompression00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelDampingCompression00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  float compression = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWheelDampingCompression'", NULL);
#endif
 {
  self->SetWheelDampingCompression(wheel,compression);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWheelDampingCompression'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWheelFrictionSlip of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelFrictionSlip00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelFrictionSlip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  float slip = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWheelFrictionSlip'", NULL);
#endif
 {
  self->SetWheelFrictionSlip(wheel,slip);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWheelFrictionSlip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWheelRollInfluence of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelRollInfluence00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelRollInfluence00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  float rollInfluence = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWheelRollInfluence'", NULL);
#endif
 {
  self->SetWheelRollInfluence(wheel,rollInfluence);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWheelRollInfluence'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEngineForce of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetEngineForce00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetEngineForce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  float force = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEngineForce'", NULL);
#endif
 {
  self->SetEngineForce(wheel,force);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEngineForce'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBrake of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetBrake00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetBrake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  float force = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBrake'", NULL);
#endif
 {
  self->SetBrake(wheel,force);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBrake'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWheelRadius of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelRadius00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  float wheelRadius = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWheelRadius'", NULL);
#endif
 {
  self->SetWheelRadius(wheel,wheelRadius);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWheelRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResetWheels of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_ResetWheels00
static int tolua_PhysicsLuaAPI_RaycastVehicle_ResetWheels00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResetWheels'", NULL);
#endif
 {
  self->ResetWheels();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResetWheels'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWheelRestLength of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelRestLength00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelRestLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  float length = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWheelRestLength'", NULL);
#endif
 {
  self->SetWheelRestLength(wheel,length);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWheelRestLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWheelSkidInfo of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelSkidInfo00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelSkidInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  float factor = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWheelSkidInfo'", NULL);
#endif
 {
  self->SetWheelSkidInfo(wheel,factor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWheelSkidInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WheelIsGrounded of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_WheelIsGrounded00
static int tolua_PhysicsLuaAPI_RaycastVehicle_WheelIsGrounded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WheelIsGrounded'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WheelIsGrounded(wheel);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WheelIsGrounded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxSuspensionTravel of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetMaxSuspensionTravel00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetMaxSuspensionTravel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  float maxSuspensionTravel = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxSuspensionTravel'", NULL);
#endif
 {
  self->SetMaxSuspensionTravel(wheel,maxSuspensionTravel);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxSuspensionTravel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWheelDirection of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelDirection00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  Vector3 direction = *((Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWheelDirection'", NULL);
#endif
 {
  self->SetWheelDirection(wheel,direction);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWheelDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWheelAxle of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelAxle00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelAxle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  Vector3 axle = *((Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWheelAxle'", NULL);
#endif
 {
  self->SetWheelAxle(wheel,axle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWheelAxle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxSideSlipSpeed of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetMaxSideSlipSpeed00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetMaxSideSlipSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  float speed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxSideSlipSpeed'", NULL);
#endif
 {
  self->SetMaxSideSlipSpeed(speed);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxSideSlipSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWheelSkidInfoCumulative of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelSkidInfoCumulative00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelSkidInfoCumulative00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
  float skid = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWheelSkidInfoCumulative'", NULL);
#endif
 {
  self->SetWheelSkidInfoCumulative(wheel,skid);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWheelSkidInfoCumulative'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetInAirRPM of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetInAirRPM00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetInAirRPM00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  float rpm = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInAirRPM'", NULL);
#endif
 {
  self->SetInAirRPM(rpm);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInAirRPM'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoordinateSystem of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetCoordinateSystem00
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetCoordinateSystem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoordinateSystem'", NULL);
#endif
 {
  self->SetCoordinateSystem();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCoordinateSystem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoordinateSystem of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_SetCoordinateSystem01
static int tolua_PhysicsLuaAPI_RaycastVehicle_SetCoordinateSystem01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  const IntVector3* coordinateSystem = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoordinateSystem'", NULL);
#endif
 {
  self->SetCoordinateSystem(*coordinateSystem);
 }
 }
 return 0;
tolua_lerror:
 return tolua_PhysicsLuaAPI_RaycastVehicle_SetCoordinateSystem00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Init of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_Init00
static int tolua_PhysicsLuaAPI_RaycastVehicle_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
 {
  self->Init();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelPosition of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelPosition00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelPosition'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetWheelPosition(wheel);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelRotation of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelRotation00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelRotation'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->GetWheelRotation(wheel);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
  tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelConnectionPoint of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelConnectionPoint00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelConnectionPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelConnectionPoint'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetWheelConnectionPoint(wheel);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelConnectionPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumWheels of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetNumWheels00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetNumWheels00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumWheels'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetNumWheels();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumWheels'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelNode of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelNode00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelNode'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->GetWheelNode(wheel);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSteeringValue of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetSteeringValue00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetSteeringValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSteeringValue'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetSteeringValue(wheel);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSteeringValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelSuspensionStiffness of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelSuspensionStiffness00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelSuspensionStiffness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelSuspensionStiffness'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetWheelSuspensionStiffness(wheel);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelSuspensionStiffness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelDampingRelaxation of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelDampingRelaxation00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelDampingRelaxation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelDampingRelaxation'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetWheelDampingRelaxation(wheel);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelDampingRelaxation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelDampingCompression of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelDampingCompression00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelDampingCompression00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelDampingCompression'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetWheelDampingCompression(wheel);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelDampingCompression'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelFrictionSlip of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelFrictionSlip00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelFrictionSlip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelFrictionSlip'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetWheelFrictionSlip(wheel);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelFrictionSlip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelRollInfluence of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelRollInfluence00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelRollInfluence00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelRollInfluence'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetWheelRollInfluence(wheel);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelRollInfluence'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEngineForce of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetEngineForce00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetEngineForce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEngineForce'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetEngineForce(wheel);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEngineForce'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBrake of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetBrake00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetBrake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBrake'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetBrake(wheel);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBrake'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelRadius of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelRadius00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelRadius'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetWheelRadius(wheel);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelRestLength of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelRestLength00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelRestLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelRestLength'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetWheelRestLength(wheel);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelRestLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelSkidInfo of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelSkidInfo00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelSkidInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelSkidInfo'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetWheelSkidInfo(wheel);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelSkidInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxSuspensionTravel of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetMaxSuspensionTravel00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetMaxSuspensionTravel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RaycastVehicle* self = (RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxSuspensionTravel'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxSuspensionTravel(wheel);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxSuspensionTravel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelSideSlipSpeed of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelSideSlipSpeed00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelSideSlipSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelSideSlipSpeed'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetWheelSideSlipSpeed(wheel);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelSideSlipSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxSideSlipSpeed of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetMaxSideSlipSpeed00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetMaxSideSlipSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxSideSlipSpeed'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxSideSlipSpeed();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxSideSlipSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelSkidInfoCumulative of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelSkidInfoCumulative00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelSkidInfoCumulative00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelSkidInfoCumulative'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetWheelSkidInfoCumulative(wheel);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelSkidInfoCumulative'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelDirection of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelDirection00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelDirection'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetWheelDirection(wheel);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsFrontWheel of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_IsFrontWheel00
static int tolua_PhysicsLuaAPI_RaycastVehicle_IsFrontWheel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsFrontWheel'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsFrontWheel(wheel);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsFrontWheel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWheelAxle of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelAxle00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelAxle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWheelAxle'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetWheelAxle(wheel);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWheelAxle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetContactPosition of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetContactPosition00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetContactPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetContactPosition'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetContactPosition(wheel);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetContactPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetContactNormal of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetContactNormal00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetContactNormal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
  int wheel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetContactNormal'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetContactNormal(wheel);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetContactNormal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInAirRPM of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetInAirRPM00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetInAirRPM00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInAirRPM'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetInAirRPM();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInAirRPM'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCoordinateSystem of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_PhysicsLuaAPI_RaycastVehicle_GetCoordinateSystem00
static int tolua_PhysicsLuaAPI_RaycastVehicle_GetCoordinateSystem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RaycastVehicle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RaycastVehicle* self = (const RaycastVehicle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCoordinateSystem'", NULL);
#endif
 {
  IntVector3 tolua_ret = (IntVector3)  self->GetCoordinateSystem();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector3));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCoordinateSystem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: RIGHT_UP_FORWARD of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_get_RaycastVehicle_RIGHT_UP_FORWARD
static int tolua_get_RaycastVehicle_RIGHT_UP_FORWARD(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&RaycastVehicle::RIGHT_UP_FORWARD,"const IntVector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: RIGHT_FORWARD_UP of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_get_RaycastVehicle_RIGHT_FORWARD_UP
static int tolua_get_RaycastVehicle_RIGHT_FORWARD_UP(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&RaycastVehicle::RIGHT_FORWARD_UP,"const IntVector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UP_FORWARD_RIGHT of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_get_RaycastVehicle_UP_FORWARD_RIGHT
static int tolua_get_RaycastVehicle_UP_FORWARD_RIGHT(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&RaycastVehicle::UP_FORWARD_RIGHT,"const IntVector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UP_RIGHT_FORWARD of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_get_RaycastVehicle_UP_RIGHT_FORWARD
static int tolua_get_RaycastVehicle_UP_RIGHT_FORWARD(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&RaycastVehicle::UP_RIGHT_FORWARD,"const IntVector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FORWARD_RIGHT_UP of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_get_RaycastVehicle_FORWARD_RIGHT_UP
static int tolua_get_RaycastVehicle_FORWARD_RIGHT_UP(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&RaycastVehicle::FORWARD_RIGHT_UP,"const IntVector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FORWARD_UP_RIGHT of class  RaycastVehicle */
#ifndef TOLUA_DISABLE_tolua_get_RaycastVehicle_FORWARD_UP_RIGHT
static int tolua_get_RaycastVehicle_FORWARD_UP_RIGHT(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&RaycastVehicle::FORWARD_UP_RIGHT,"const IntVector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_PhysicsLuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_constant(tolua_S,"SHAPE_BOX",SHAPE_BOX);
 tolua_constant(tolua_S,"SHAPE_SPHERE",SHAPE_SPHERE);
 tolua_constant(tolua_S,"SHAPE_STATICPLANE",SHAPE_STATICPLANE);
 tolua_constant(tolua_S,"SHAPE_CYLINDER",SHAPE_CYLINDER);
 tolua_constant(tolua_S,"SHAPE_CAPSULE",SHAPE_CAPSULE);
 tolua_constant(tolua_S,"SHAPE_CONE",SHAPE_CONE);
 tolua_constant(tolua_S,"SHAPE_TRIANGLEMESH",SHAPE_TRIANGLEMESH);
 tolua_constant(tolua_S,"SHAPE_CONVEXHULL",SHAPE_CONVEXHULL);
 tolua_constant(tolua_S,"SHAPE_TERRAIN",SHAPE_TERRAIN);
 tolua_cclass(tolua_S,"CollisionShape","CollisionShape","Component",NULL);
 tolua_beginmodule(tolua_S,"CollisionShape");
  tolua_function(tolua_S,"SetBox",tolua_PhysicsLuaAPI_CollisionShape_SetBox00);
  tolua_function(tolua_S,"SetBox",tolua_PhysicsLuaAPI_CollisionShape_SetBox01);
  tolua_function(tolua_S,"SetBox",tolua_PhysicsLuaAPI_CollisionShape_SetBox02);
  tolua_function(tolua_S,"SetSphere",tolua_PhysicsLuaAPI_CollisionShape_SetSphere00);
  tolua_function(tolua_S,"SetSphere",tolua_PhysicsLuaAPI_CollisionShape_SetSphere01);
  tolua_function(tolua_S,"SetSphere",tolua_PhysicsLuaAPI_CollisionShape_SetSphere02);
  tolua_function(tolua_S,"SetStaticPlane",tolua_PhysicsLuaAPI_CollisionShape_SetStaticPlane00);
  tolua_function(tolua_S,"SetStaticPlane",tolua_PhysicsLuaAPI_CollisionShape_SetStaticPlane01);
  tolua_function(tolua_S,"SetStaticPlane",tolua_PhysicsLuaAPI_CollisionShape_SetStaticPlane02);
  tolua_function(tolua_S,"SetCylinder",tolua_PhysicsLuaAPI_CollisionShape_SetCylinder00);
  tolua_function(tolua_S,"SetCylinder",tolua_PhysicsLuaAPI_CollisionShape_SetCylinder01);
  tolua_function(tolua_S,"SetCylinder",tolua_PhysicsLuaAPI_CollisionShape_SetCylinder02);
  tolua_function(tolua_S,"SetCapsule",tolua_PhysicsLuaAPI_CollisionShape_SetCapsule00);
  tolua_function(tolua_S,"SetCapsule",tolua_PhysicsLuaAPI_CollisionShape_SetCapsule01);
  tolua_function(tolua_S,"SetCapsule",tolua_PhysicsLuaAPI_CollisionShape_SetCapsule02);
  tolua_function(tolua_S,"SetCone",tolua_PhysicsLuaAPI_CollisionShape_SetCone00);
  tolua_function(tolua_S,"SetCone",tolua_PhysicsLuaAPI_CollisionShape_SetCone01);
  tolua_function(tolua_S,"SetCone",tolua_PhysicsLuaAPI_CollisionShape_SetCone02);
  tolua_function(tolua_S,"SetTriangleMesh",tolua_PhysicsLuaAPI_CollisionShape_SetTriangleMesh00);
  tolua_function(tolua_S,"SetTriangleMesh",tolua_PhysicsLuaAPI_CollisionShape_SetTriangleMesh01);
  tolua_function(tolua_S,"SetTriangleMesh",tolua_PhysicsLuaAPI_CollisionShape_SetTriangleMesh02);
  tolua_function(tolua_S,"SetTriangleMesh",tolua_PhysicsLuaAPI_CollisionShape_SetTriangleMesh03);
  tolua_function(tolua_S,"SetCustomTriangleMesh",tolua_PhysicsLuaAPI_CollisionShape_SetCustomTriangleMesh00);
  tolua_function(tolua_S,"SetCustomTriangleMesh",tolua_PhysicsLuaAPI_CollisionShape_SetCustomTriangleMesh01);
  tolua_function(tolua_S,"SetCustomTriangleMesh",tolua_PhysicsLuaAPI_CollisionShape_SetCustomTriangleMesh02);
  tolua_function(tolua_S,"SetCustomTriangleMesh",tolua_PhysicsLuaAPI_CollisionShape_SetCustomTriangleMesh03);
  tolua_function(tolua_S,"SetConvexHull",tolua_PhysicsLuaAPI_CollisionShape_SetConvexHull00);
  tolua_function(tolua_S,"SetConvexHull",tolua_PhysicsLuaAPI_CollisionShape_SetConvexHull01);
  tolua_function(tolua_S,"SetConvexHull",tolua_PhysicsLuaAPI_CollisionShape_SetConvexHull02);
  tolua_function(tolua_S,"SetConvexHull",tolua_PhysicsLuaAPI_CollisionShape_SetConvexHull03);
  tolua_function(tolua_S,"SetCustomConvexHull",tolua_PhysicsLuaAPI_CollisionShape_SetCustomConvexHull00);
  tolua_function(tolua_S,"SetCustomConvexHull",tolua_PhysicsLuaAPI_CollisionShape_SetCustomConvexHull01);
  tolua_function(tolua_S,"SetCustomConvexHull",tolua_PhysicsLuaAPI_CollisionShape_SetCustomConvexHull02);
  tolua_function(tolua_S,"SetCustomConvexHull",tolua_PhysicsLuaAPI_CollisionShape_SetCustomConvexHull03);
  tolua_function(tolua_S,"SetTerrain",tolua_PhysicsLuaAPI_CollisionShape_SetTerrain00);
  tolua_function(tolua_S,"SetShapeType",tolua_PhysicsLuaAPI_CollisionShape_SetShapeType00);
  tolua_function(tolua_S,"SetSize",tolua_PhysicsLuaAPI_CollisionShape_SetSize00);
  tolua_function(tolua_S,"SetPosition",tolua_PhysicsLuaAPI_CollisionShape_SetPosition00);
  tolua_function(tolua_S,"SetRotation",tolua_PhysicsLuaAPI_CollisionShape_SetRotation00);
  tolua_function(tolua_S,"SetTransform",tolua_PhysicsLuaAPI_CollisionShape_SetTransform00);
  tolua_function(tolua_S,"SetMargin",tolua_PhysicsLuaAPI_CollisionShape_SetMargin00);
  tolua_function(tolua_S,"SetModel",tolua_PhysicsLuaAPI_CollisionShape_SetModel00);
  tolua_function(tolua_S,"SetLodLevel",tolua_PhysicsLuaAPI_CollisionShape_SetLodLevel00);
  tolua_function(tolua_S,"GetPhysicsWorld",tolua_PhysicsLuaAPI_CollisionShape_GetPhysicsWorld00);
  tolua_function(tolua_S,"GetShapeType",tolua_PhysicsLuaAPI_CollisionShape_GetShapeType00);
  tolua_function(tolua_S,"GetSize",tolua_PhysicsLuaAPI_CollisionShape_GetSize00);
  tolua_function(tolua_S,"GetPosition",tolua_PhysicsLuaAPI_CollisionShape_GetPosition00);
  tolua_function(tolua_S,"GetRotation",tolua_PhysicsLuaAPI_CollisionShape_GetRotation00);
  tolua_function(tolua_S,"GetMargin",tolua_PhysicsLuaAPI_CollisionShape_GetMargin00);
  tolua_function(tolua_S,"GetModel",tolua_PhysicsLuaAPI_CollisionShape_GetModel00);
  tolua_function(tolua_S,"GetLodLevel",tolua_PhysicsLuaAPI_CollisionShape_GetLodLevel00);
  tolua_function(tolua_S,"GetWorldBoundingBox",tolua_PhysicsLuaAPI_CollisionShape_GetWorldBoundingBox00);
  tolua_variable(tolua_S,"physicsWorld",tolua_get_CollisionShape_physicsWorld_ptr,NULL);
  tolua_variable(tolua_S,"shapeType",tolua_get_CollisionShape_shapeType,tolua_set_CollisionShape_shapeType);
  tolua_variable(tolua_S,"size",tolua_get_CollisionShape_size_ref,tolua_set_CollisionShape_size_ref);
  tolua_variable(tolua_S,"position",tolua_get_CollisionShape_position_ref,tolua_set_CollisionShape_position_ref);
  tolua_variable(tolua_S,"rotation",tolua_get_CollisionShape_rotation_ref,tolua_set_CollisionShape_rotation_ref);
  tolua_variable(tolua_S,"margin",tolua_get_CollisionShape_margin,tolua_set_CollisionShape_margin);
  tolua_variable(tolua_S,"model",tolua_get_CollisionShape_model_ptr,tolua_set_CollisionShape_model_ptr);
  tolua_variable(tolua_S,"lodLevel",tolua_get_CollisionShape_lodLevel,tolua_set_CollisionShape_lodLevel);
  tolua_variable(tolua_S,"worldBoundingBox",tolua_get_CollisionShape_worldBoundingBox,NULL);
  tolua_variable(tolua_S,"modelAttr",tolua_get_CollisionShape_modelAttr,tolua_set_CollisionShape_modelAttr);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"CONSTRAINT_POINT",CONSTRAINT_POINT);
 tolua_constant(tolua_S,"CONSTRAINT_HINGE",CONSTRAINT_HINGE);
 tolua_constant(tolua_S,"CONSTRAINT_SLIDER",CONSTRAINT_SLIDER);
 tolua_constant(tolua_S,"CONSTRAINT_CONETWIST",CONSTRAINT_CONETWIST);
 tolua_cclass(tolua_S,"Constraint","Constraint","Component",NULL);
 tolua_beginmodule(tolua_S,"Constraint");
  tolua_function(tolua_S,"SetConstraintType",tolua_PhysicsLuaAPI_Constraint_SetConstraintType00);
  tolua_function(tolua_S,"SetOtherBody",tolua_PhysicsLuaAPI_Constraint_SetOtherBody00);
  tolua_function(tolua_S,"SetPosition",tolua_PhysicsLuaAPI_Constraint_SetPosition00);
  tolua_function(tolua_S,"SetRotation",tolua_PhysicsLuaAPI_Constraint_SetRotation00);
  tolua_function(tolua_S,"SetAxis",tolua_PhysicsLuaAPI_Constraint_SetAxis00);
  tolua_function(tolua_S,"SetOtherPosition",tolua_PhysicsLuaAPI_Constraint_SetOtherPosition00);
  tolua_function(tolua_S,"SetOtherRotation",tolua_PhysicsLuaAPI_Constraint_SetOtherRotation00);
  tolua_function(tolua_S,"SetOtherAxis",tolua_PhysicsLuaAPI_Constraint_SetOtherAxis00);
  tolua_function(tolua_S,"SetWorldPosition",tolua_PhysicsLuaAPI_Constraint_SetWorldPosition00);
  tolua_function(tolua_S,"SetHighLimit",tolua_PhysicsLuaAPI_Constraint_SetHighLimit00);
  tolua_function(tolua_S,"SetLowLimit",tolua_PhysicsLuaAPI_Constraint_SetLowLimit00);
  tolua_function(tolua_S,"SetERP",tolua_PhysicsLuaAPI_Constraint_SetERP00);
  tolua_function(tolua_S,"SetCFM",tolua_PhysicsLuaAPI_Constraint_SetCFM00);
  tolua_function(tolua_S,"SetDisableCollision",tolua_PhysicsLuaAPI_Constraint_SetDisableCollision00);
  tolua_function(tolua_S,"GetPhysicsWorld",tolua_PhysicsLuaAPI_Constraint_GetPhysicsWorld00);
  tolua_function(tolua_S,"GetConstraintType",tolua_PhysicsLuaAPI_Constraint_GetConstraintType00);
  tolua_function(tolua_S,"GetOwnBody",tolua_PhysicsLuaAPI_Constraint_GetOwnBody00);
  tolua_function(tolua_S,"GetOtherBody",tolua_PhysicsLuaAPI_Constraint_GetOtherBody00);
  tolua_function(tolua_S,"GetPosition",tolua_PhysicsLuaAPI_Constraint_GetPosition00);
  tolua_function(tolua_S,"GetRotation",tolua_PhysicsLuaAPI_Constraint_GetRotation00);
  tolua_function(tolua_S,"GetOtherPosition",tolua_PhysicsLuaAPI_Constraint_GetOtherPosition00);
  tolua_function(tolua_S,"GetOtherRotation",tolua_PhysicsLuaAPI_Constraint_GetOtherRotation00);
  tolua_function(tolua_S,"GetWorldPosition",tolua_PhysicsLuaAPI_Constraint_GetWorldPosition00);
  tolua_function(tolua_S,"GetHighLimit",tolua_PhysicsLuaAPI_Constraint_GetHighLimit00);
  tolua_function(tolua_S,"GetLowLimit",tolua_PhysicsLuaAPI_Constraint_GetLowLimit00);
  tolua_function(tolua_S,"GetERP",tolua_PhysicsLuaAPI_Constraint_GetERP00);
  tolua_function(tolua_S,"GetCFM",tolua_PhysicsLuaAPI_Constraint_GetCFM00);
  tolua_function(tolua_S,"GetDisableCollision",tolua_PhysicsLuaAPI_Constraint_GetDisableCollision00);
  tolua_variable(tolua_S,"physicsWorld",tolua_get_Constraint_physicsWorld_ptr,NULL);
  tolua_variable(tolua_S,"constraintType",tolua_get_Constraint_constraintType,tolua_set_Constraint_constraintType);
  tolua_variable(tolua_S,"ownBody",tolua_get_Constraint_ownBody_ptr,NULL);
  tolua_variable(tolua_S,"otherBody",tolua_get_Constraint_otherBody_ptr,tolua_set_Constraint_otherBody_ptr);
  tolua_variable(tolua_S,"position",tolua_get_Constraint_position_ref,tolua_set_Constraint_position_ref);
  tolua_variable(tolua_S,"rotation",tolua_get_Constraint_rotation_ref,tolua_set_Constraint_rotation_ref);
  tolua_variable(tolua_S,"axis",tolua_get_Constraint_axis_ref,tolua_set_Constraint_axis_ref);
  tolua_variable(tolua_S,"otherPosition",tolua_get_Constraint_otherPosition_ref,tolua_set_Constraint_otherPosition_ref);
  tolua_variable(tolua_S,"otherRotation",tolua_get_Constraint_otherRotation_ref,tolua_set_Constraint_otherRotation_ref);
  tolua_variable(tolua_S,"otherAxis",tolua_get_Constraint_otherAxis_ref,tolua_set_Constraint_otherAxis_ref);
  tolua_variable(tolua_S,"worldPosition",tolua_get_Constraint_worldPosition,tolua_set_Constraint_worldPosition);
  tolua_variable(tolua_S,"highLimit",tolua_get_Constraint_highLimit_ref,tolua_set_Constraint_highLimit_ref);
  tolua_variable(tolua_S,"lowLimit",tolua_get_Constraint_lowLimit_ref,tolua_set_Constraint_lowLimit_ref);
  tolua_variable(tolua_S,"ERP",tolua_get_Constraint_ERP,tolua_set_Constraint_ERP);
  tolua_variable(tolua_S,"CFM",tolua_get_Constraint_CFM,tolua_set_Constraint_CFM);
  tolua_variable(tolua_S,"disableCollision",tolua_get_Constraint_disableCollision,tolua_set_Constraint_disableCollision);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"PhysicsRaycastResult","PhysicsRaycastResult","",tolua_collect_PhysicsRaycastResult);
 #else
 tolua_cclass(tolua_S,"PhysicsRaycastResult","PhysicsRaycastResult","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"PhysicsRaycastResult");
  tolua_function(tolua_S,"new",tolua_PhysicsLuaAPI_PhysicsRaycastResult_new00);
  tolua_function(tolua_S,"new_local",tolua_PhysicsLuaAPI_PhysicsRaycastResult_new00_local);
  tolua_function(tolua_S,".call",tolua_PhysicsLuaAPI_PhysicsRaycastResult_new00_local);
  tolua_function(tolua_S,"delete",tolua_PhysicsLuaAPI_PhysicsRaycastResult_delete00);
  tolua_variable(tolua_S,"position",tolua_get_PhysicsRaycastResult_position,tolua_set_PhysicsRaycastResult_position);
  tolua_variable(tolua_S,"normal",tolua_get_PhysicsRaycastResult_normal,tolua_set_PhysicsRaycastResult_normal);
  tolua_variable(tolua_S,"distance",tolua_get_PhysicsRaycastResult_distance,tolua_set_PhysicsRaycastResult_distance);
  tolua_variable(tolua_S,"hitFraction",tolua_get_PhysicsRaycastResult_hitFraction,tolua_set_PhysicsRaycastResult_hitFraction);
  tolua_variable(tolua_S,"body",tolua_get_PhysicsRaycastResult_body_ptr,tolua_set_PhysicsRaycastResult_body_ptr);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"PhysicsWorld","PhysicsWorld","Component",NULL);
 tolua_beginmodule(tolua_S,"PhysicsWorld");
  tolua_function(tolua_S,"Update",tolua_PhysicsLuaAPI_PhysicsWorld_Update00);
  tolua_function(tolua_S,"UpdateCollisions",tolua_PhysicsLuaAPI_PhysicsWorld_UpdateCollisions00);
  tolua_function(tolua_S,"SetFps",tolua_PhysicsLuaAPI_PhysicsWorld_SetFps00);
  tolua_function(tolua_S,"SetGravity",tolua_PhysicsLuaAPI_PhysicsWorld_SetGravity00);
  tolua_function(tolua_S,"SetMaxSubSteps",tolua_PhysicsLuaAPI_PhysicsWorld_SetMaxSubSteps00);
  tolua_function(tolua_S,"SetNumIterations",tolua_PhysicsLuaAPI_PhysicsWorld_SetNumIterations00);
  tolua_function(tolua_S,"SetUpdateEnabled",tolua_PhysicsLuaAPI_PhysicsWorld_SetUpdateEnabled00);
  tolua_function(tolua_S,"SetInterpolation",tolua_PhysicsLuaAPI_PhysicsWorld_SetInterpolation00);
  tolua_function(tolua_S,"SetInternalEdge",tolua_PhysicsLuaAPI_PhysicsWorld_SetInternalEdge00);
  tolua_function(tolua_S,"SetSplitImpulse",tolua_PhysicsLuaAPI_PhysicsWorld_SetSplitImpulse00);
  tolua_function(tolua_S,"SetMaxNetworkAngularVelocity",tolua_PhysicsLuaAPI_PhysicsWorld_SetMaxNetworkAngularVelocity00);
  tolua_function(tolua_S,"Raycast",tolua_PhysicsLuaAPI_PhysicsWorld_Raycast00);
  tolua_function(tolua_S,"RaycastSingle",tolua_PhysicsLuaAPI_PhysicsWorld_RaycastSingle00);
  tolua_function(tolua_S,"RaycastSingleSegmented",tolua_PhysicsLuaAPI_PhysicsWorld_RaycastSingleSegmented00);
  tolua_function(tolua_S,"SphereCast",tolua_PhysicsLuaAPI_PhysicsWorld_SphereCast00);
  tolua_function(tolua_S,"ConvexCast",tolua_PhysicsLuaAPI_PhysicsWorld_ConvexCast00);
  tolua_function(tolua_S,"GetRigidBodies",tolua_PhysicsLuaAPI_PhysicsWorld_GetRigidBodies00);
  tolua_function(tolua_S,"GetRigidBodies",tolua_PhysicsLuaAPI_PhysicsWorld_GetRigidBodies01);
  tolua_function(tolua_S,"GetRigidBodies",tolua_PhysicsLuaAPI_PhysicsWorld_GetRigidBodies02);
  tolua_function(tolua_S,"GetCollidingBodies",tolua_PhysicsLuaAPI_PhysicsWorld_GetCollidingBodies00);
  tolua_function(tolua_S,"DrawDebugGeometry",tolua_PhysicsLuaAPI_PhysicsWorld_DrawDebugGeometry00);
  tolua_function(tolua_S,"RemoveCachedGeometry",tolua_PhysicsLuaAPI_PhysicsWorld_RemoveCachedGeometry00);
  tolua_function(tolua_S,"GetGravity",tolua_PhysicsLuaAPI_PhysicsWorld_GetGravity00);
  tolua_function(tolua_S,"GetMaxSubSteps",tolua_PhysicsLuaAPI_PhysicsWorld_GetMaxSubSteps00);
  tolua_function(tolua_S,"GetNumIterations",tolua_PhysicsLuaAPI_PhysicsWorld_GetNumIterations00);
  tolua_function(tolua_S,"IsUpdateEnabled",tolua_PhysicsLuaAPI_PhysicsWorld_IsUpdateEnabled00);
  tolua_function(tolua_S,"GetInterpolation",tolua_PhysicsLuaAPI_PhysicsWorld_GetInterpolation00);
  tolua_function(tolua_S,"GetInternalEdge",tolua_PhysicsLuaAPI_PhysicsWorld_GetInternalEdge00);
  tolua_function(tolua_S,"GetSplitImpulse",tolua_PhysicsLuaAPI_PhysicsWorld_GetSplitImpulse00);
  tolua_function(tolua_S,"GetFps",tolua_PhysicsLuaAPI_PhysicsWorld_GetFps00);
  tolua_function(tolua_S,"GetMaxNetworkAngularVelocity",tolua_PhysicsLuaAPI_PhysicsWorld_GetMaxNetworkAngularVelocity00);
  tolua_variable(tolua_S,"gravity",tolua_get_PhysicsWorld_gravity,tolua_set_PhysicsWorld_gravity);
  tolua_variable(tolua_S,"maxSubSteps",tolua_get_PhysicsWorld_maxSubSteps,tolua_set_PhysicsWorld_maxSubSteps);
  tolua_variable(tolua_S,"numIterations",tolua_get_PhysicsWorld_numIterations,tolua_set_PhysicsWorld_numIterations);
  tolua_variable(tolua_S,"updateEnabled",tolua_get_PhysicsWorld_updateEnabled,tolua_set_PhysicsWorld_updateEnabled);
  tolua_variable(tolua_S,"interpolation",tolua_get_PhysicsWorld_interpolation,tolua_set_PhysicsWorld_interpolation);
  tolua_variable(tolua_S,"internalEdge",tolua_get_PhysicsWorld_internalEdge,tolua_set_PhysicsWorld_internalEdge);
  tolua_variable(tolua_S,"splitImpulse",tolua_get_PhysicsWorld_splitImpulse,tolua_set_PhysicsWorld_splitImpulse);
  tolua_variable(tolua_S,"fps",tolua_get_PhysicsWorld_fps,tolua_set_PhysicsWorld_fps);
  tolua_variable(tolua_S,"maxNetworkAngularVelocity",tolua_get_PhysicsWorld_maxNetworkAngularVelocity,tolua_set_PhysicsWorld_maxNetworkAngularVelocity);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"COLLISION_NEVER",COLLISION_NEVER);
 tolua_constant(tolua_S,"COLLISION_ACTIVE",COLLISION_ACTIVE);
 tolua_constant(tolua_S,"COLLISION_ALWAYS",COLLISION_ALWAYS);
 tolua_cclass(tolua_S,"RigidBody","RigidBody","Component",NULL);
 tolua_beginmodule(tolua_S,"RigidBody");
  tolua_function(tolua_S,"SetMass",tolua_PhysicsLuaAPI_RigidBody_SetMass00);
  tolua_function(tolua_S,"SetPosition",tolua_PhysicsLuaAPI_RigidBody_SetPosition00);
  tolua_function(tolua_S,"SetRotation",tolua_PhysicsLuaAPI_RigidBody_SetRotation00);
  tolua_function(tolua_S,"SetTransform",tolua_PhysicsLuaAPI_RigidBody_SetTransform00);
  tolua_function(tolua_S,"SetLinearVelocity",tolua_PhysicsLuaAPI_RigidBody_SetLinearVelocity00);
  tolua_function(tolua_S,"SetLinearFactor",tolua_PhysicsLuaAPI_RigidBody_SetLinearFactor00);
  tolua_function(tolua_S,"SetLinearRestThreshold",tolua_PhysicsLuaAPI_RigidBody_SetLinearRestThreshold00);
  tolua_function(tolua_S,"SetLinearDamping",tolua_PhysicsLuaAPI_RigidBody_SetLinearDamping00);
  tolua_function(tolua_S,"SetAngularVelocity",tolua_PhysicsLuaAPI_RigidBody_SetAngularVelocity00);
  tolua_function(tolua_S,"SetAngularFactor",tolua_PhysicsLuaAPI_RigidBody_SetAngularFactor00);
  tolua_function(tolua_S,"SetAngularRestThreshold",tolua_PhysicsLuaAPI_RigidBody_SetAngularRestThreshold00);
  tolua_function(tolua_S,"SetAngularDamping",tolua_PhysicsLuaAPI_RigidBody_SetAngularDamping00);
  tolua_function(tolua_S,"SetFriction",tolua_PhysicsLuaAPI_RigidBody_SetFriction00);
  tolua_function(tolua_S,"SetAnisotropicFriction",tolua_PhysicsLuaAPI_RigidBody_SetAnisotropicFriction00);
  tolua_function(tolua_S,"SetRollingFriction",tolua_PhysicsLuaAPI_RigidBody_SetRollingFriction00);
  tolua_function(tolua_S,"SetRestitution",tolua_PhysicsLuaAPI_RigidBody_SetRestitution00);
  tolua_function(tolua_S,"SetContactProcessingThreshold",tolua_PhysicsLuaAPI_RigidBody_SetContactProcessingThreshold00);
  tolua_function(tolua_S,"SetCcdRadius",tolua_PhysicsLuaAPI_RigidBody_SetCcdRadius00);
  tolua_function(tolua_S,"SetCcdMotionThreshold",tolua_PhysicsLuaAPI_RigidBody_SetCcdMotionThreshold00);
  tolua_function(tolua_S,"SetUseGravity",tolua_PhysicsLuaAPI_RigidBody_SetUseGravity00);
  tolua_function(tolua_S,"SetGravityOverride",tolua_PhysicsLuaAPI_RigidBody_SetGravityOverride00);
  tolua_function(tolua_S,"SetKinematic",tolua_PhysicsLuaAPI_RigidBody_SetKinematic00);
  tolua_function(tolua_S,"SetTrigger",tolua_PhysicsLuaAPI_RigidBody_SetTrigger00);
  tolua_function(tolua_S,"SetCollisionLayer",tolua_PhysicsLuaAPI_RigidBody_SetCollisionLayer00);
  tolua_function(tolua_S,"SetCollisionMask",tolua_PhysicsLuaAPI_RigidBody_SetCollisionMask00);
  tolua_function(tolua_S,"SetCollisionLayerAndMask",tolua_PhysicsLuaAPI_RigidBody_SetCollisionLayerAndMask00);
  tolua_function(tolua_S,"SetCollisionEventMode",tolua_PhysicsLuaAPI_RigidBody_SetCollisionEventMode00);
  tolua_function(tolua_S,"DisableMassUpdate",tolua_PhysicsLuaAPI_RigidBody_DisableMassUpdate00);
  tolua_function(tolua_S,"EnableMassUpdate",tolua_PhysicsLuaAPI_RigidBody_EnableMassUpdate00);
  tolua_function(tolua_S,"ApplyForce",tolua_PhysicsLuaAPI_RigidBody_ApplyForce00);
  tolua_function(tolua_S,"ApplyForce",tolua_PhysicsLuaAPI_RigidBody_ApplyForce01);
  tolua_function(tolua_S,"ApplyTorque",tolua_PhysicsLuaAPI_RigidBody_ApplyTorque00);
  tolua_function(tolua_S,"ApplyImpulse",tolua_PhysicsLuaAPI_RigidBody_ApplyImpulse00);
  tolua_function(tolua_S,"ApplyImpulse",tolua_PhysicsLuaAPI_RigidBody_ApplyImpulse01);
  tolua_function(tolua_S,"ApplyTorqueImpulse",tolua_PhysicsLuaAPI_RigidBody_ApplyTorqueImpulse00);
  tolua_function(tolua_S,"ResetForces",tolua_PhysicsLuaAPI_RigidBody_ResetForces00);
  tolua_function(tolua_S,"Activate",tolua_PhysicsLuaAPI_RigidBody_Activate00);
  tolua_function(tolua_S,"ReAddBodyToWorld",tolua_PhysicsLuaAPI_RigidBody_ReAddBodyToWorld00);
  tolua_function(tolua_S,"GetPhysicsWorld",tolua_PhysicsLuaAPI_RigidBody_GetPhysicsWorld00);
  tolua_function(tolua_S,"GetMass",tolua_PhysicsLuaAPI_RigidBody_GetMass00);
  tolua_function(tolua_S,"GetPosition",tolua_PhysicsLuaAPI_RigidBody_GetPosition00);
  tolua_function(tolua_S,"GetRotation",tolua_PhysicsLuaAPI_RigidBody_GetRotation00);
  tolua_function(tolua_S,"GetLinearVelocity",tolua_PhysicsLuaAPI_RigidBody_GetLinearVelocity00);
  tolua_function(tolua_S,"GetLinearFactor",tolua_PhysicsLuaAPI_RigidBody_GetLinearFactor00);
  tolua_function(tolua_S,"GetVelocityAtPoint",tolua_PhysicsLuaAPI_RigidBody_GetVelocityAtPoint00);
  tolua_function(tolua_S,"GetLinearRestThreshold",tolua_PhysicsLuaAPI_RigidBody_GetLinearRestThreshold00);
  tolua_function(tolua_S,"GetLinearDamping",tolua_PhysicsLuaAPI_RigidBody_GetLinearDamping00);
  tolua_function(tolua_S,"GetAngularVelocity",tolua_PhysicsLuaAPI_RigidBody_GetAngularVelocity00);
  tolua_function(tolua_S,"GetAngularFactor",tolua_PhysicsLuaAPI_RigidBody_GetAngularFactor00);
  tolua_function(tolua_S,"GetAngularRestThreshold",tolua_PhysicsLuaAPI_RigidBody_GetAngularRestThreshold00);
  tolua_function(tolua_S,"GetAngularDamping",tolua_PhysicsLuaAPI_RigidBody_GetAngularDamping00);
  tolua_function(tolua_S,"GetFriction",tolua_PhysicsLuaAPI_RigidBody_GetFriction00);
  tolua_function(tolua_S,"GetAnisotropicFriction",tolua_PhysicsLuaAPI_RigidBody_GetAnisotropicFriction00);
  tolua_function(tolua_S,"GetRollingFriction",tolua_PhysicsLuaAPI_RigidBody_GetRollingFriction00);
  tolua_function(tolua_S,"GetRestitution",tolua_PhysicsLuaAPI_RigidBody_GetRestitution00);
  tolua_function(tolua_S,"GetContactProcessingThreshold",tolua_PhysicsLuaAPI_RigidBody_GetContactProcessingThreshold00);
  tolua_function(tolua_S,"GetCcdRadius",tolua_PhysicsLuaAPI_RigidBody_GetCcdRadius00);
  tolua_function(tolua_S,"GetCcdMotionThreshold",tolua_PhysicsLuaAPI_RigidBody_GetCcdMotionThreshold00);
  tolua_function(tolua_S,"GetUseGravity",tolua_PhysicsLuaAPI_RigidBody_GetUseGravity00);
  tolua_function(tolua_S,"GetGravityOverride",tolua_PhysicsLuaAPI_RigidBody_GetGravityOverride00);
  tolua_function(tolua_S,"GetCenterOfMass",tolua_PhysicsLuaAPI_RigidBody_GetCenterOfMass00);
  tolua_function(tolua_S,"IsKinematic",tolua_PhysicsLuaAPI_RigidBody_IsKinematic00);
  tolua_function(tolua_S,"IsTrigger",tolua_PhysicsLuaAPI_RigidBody_IsTrigger00);
  tolua_function(tolua_S,"IsActive",tolua_PhysicsLuaAPI_RigidBody_IsActive00);
  tolua_function(tolua_S,"GetCollisionLayer",tolua_PhysicsLuaAPI_RigidBody_GetCollisionLayer00);
  tolua_function(tolua_S,"GetCollisionMask",tolua_PhysicsLuaAPI_RigidBody_GetCollisionMask00);
  tolua_function(tolua_S,"GetCollisionEventMode",tolua_PhysicsLuaAPI_RigidBody_GetCollisionEventMode00);
  tolua_variable(tolua_S,"physicsWorld",tolua_get_RigidBody_physicsWorld_ptr,NULL);
  tolua_variable(tolua_S,"mass",tolua_get_RigidBody_mass,tolua_set_RigidBody_mass);
  tolua_variable(tolua_S,"position",tolua_get_RigidBody_position,tolua_set_RigidBody_position);
  tolua_variable(tolua_S,"rotation",tolua_get_RigidBody_rotation,tolua_set_RigidBody_rotation);
  tolua_variable(tolua_S,"linearVelocity",tolua_get_RigidBody_linearVelocity,tolua_set_RigidBody_linearVelocity);
  tolua_variable(tolua_S,"linearFactor",tolua_get_RigidBody_linearFactor,tolua_set_RigidBody_linearFactor);
  tolua_variable(tolua_S,"linearRestThreshold",tolua_get_RigidBody_linearRestThreshold,tolua_set_RigidBody_linearRestThreshold);
  tolua_variable(tolua_S,"linearDamping",tolua_get_RigidBody_linearDamping,tolua_set_RigidBody_linearDamping);
  tolua_variable(tolua_S,"angularVelocity",tolua_get_RigidBody_angularVelocity,tolua_set_RigidBody_angularVelocity);
  tolua_variable(tolua_S,"angularFactor",tolua_get_RigidBody_angularFactor,tolua_set_RigidBody_angularFactor);
  tolua_variable(tolua_S,"angularRestThreshold",tolua_get_RigidBody_angularRestThreshold,tolua_set_RigidBody_angularRestThreshold);
  tolua_variable(tolua_S,"angularDamping",tolua_get_RigidBody_angularDamping,tolua_set_RigidBody_angularDamping);
  tolua_variable(tolua_S,"friction",tolua_get_RigidBody_friction,tolua_set_RigidBody_friction);
  tolua_variable(tolua_S,"anisotropicFriction",tolua_get_RigidBody_anisotropicFriction,tolua_set_RigidBody_anisotropicFriction);
  tolua_variable(tolua_S,"rollingFriction",tolua_get_RigidBody_rollingFriction,tolua_set_RigidBody_rollingFriction);
  tolua_variable(tolua_S,"restitution",tolua_get_RigidBody_restitution,tolua_set_RigidBody_restitution);
  tolua_variable(tolua_S,"contactProcessingThreshold",tolua_get_RigidBody_contactProcessingThreshold,tolua_set_RigidBody_contactProcessingThreshold);
  tolua_variable(tolua_S,"ccdRadius",tolua_get_RigidBody_ccdRadius,tolua_set_RigidBody_ccdRadius);
  tolua_variable(tolua_S,"ccdMotionThreshold",tolua_get_RigidBody_ccdMotionThreshold,tolua_set_RigidBody_ccdMotionThreshold);
  tolua_variable(tolua_S,"useGravity",tolua_get_RigidBody_useGravity,tolua_set_RigidBody_useGravity);
  tolua_variable(tolua_S,"gravityOverride",tolua_get_RigidBody_gravityOverride_ref,tolua_set_RigidBody_gravityOverride_ref);
  tolua_variable(tolua_S,"centerOfMass",tolua_get_RigidBody_centerOfMass_ref,NULL);
  tolua_variable(tolua_S,"kinematic",tolua_get_RigidBody_kinematic,tolua_set_RigidBody_kinematic);
  tolua_variable(tolua_S,"trigger",tolua_get_RigidBody_trigger,tolua_set_RigidBody_trigger);
  tolua_variable(tolua_S,"active",tolua_get_RigidBody_active,NULL);
  tolua_variable(tolua_S,"collisionLayer",tolua_get_RigidBody_collisionLayer,tolua_set_RigidBody_collisionLayer);
  tolua_variable(tolua_S,"collisionMask",tolua_get_RigidBody_collisionMask,tolua_set_RigidBody_collisionMask);
  tolua_variable(tolua_S,"collisionEventMode",tolua_get_RigidBody_collisionEventMode,tolua_set_RigidBody_collisionEventMode);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"RaycastVehicle","RaycastVehicle","LogicComponent",tolua_collect_RaycastVehicle);
 #else
 tolua_cclass(tolua_S,"RaycastVehicle","RaycastVehicle","LogicComponent",NULL);
 #endif
 tolua_beginmodule(tolua_S,"RaycastVehicle");
  tolua_function(tolua_S,"new",tolua_PhysicsLuaAPI_RaycastVehicle_new00);
  tolua_function(tolua_S,"new_local",tolua_PhysicsLuaAPI_RaycastVehicle_new00_local);
  tolua_function(tolua_S,".call",tolua_PhysicsLuaAPI_RaycastVehicle_new00_local);
  tolua_function(tolua_S,"delete",tolua_PhysicsLuaAPI_RaycastVehicle_delete00);
  tolua_function(tolua_S,"RegisterObject",tolua_PhysicsLuaAPI_RaycastVehicle_RegisterObject00);
  tolua_function(tolua_S,"ApplyAttributes",tolua_PhysicsLuaAPI_RaycastVehicle_ApplyAttributes00);
  tolua_function(tolua_S,"AddWheel",tolua_PhysicsLuaAPI_RaycastVehicle_AddWheel00);
  tolua_function(tolua_S,"ResetSuspension",tolua_PhysicsLuaAPI_RaycastVehicle_ResetSuspension00);
  tolua_function(tolua_S,"UpdateWheelTransform",tolua_PhysicsLuaAPI_RaycastVehicle_UpdateWheelTransform00);
  tolua_function(tolua_S,"SetSteeringValue",tolua_PhysicsLuaAPI_RaycastVehicle_SetSteeringValue00);
  tolua_function(tolua_S,"SetWheelSuspensionStiffness",tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelSuspensionStiffness00);
  tolua_function(tolua_S,"SetWheelDampingRelaxation",tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelDampingRelaxation00);
  tolua_function(tolua_S,"SetWheelDampingCompression",tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelDampingCompression00);
  tolua_function(tolua_S,"SetWheelFrictionSlip",tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelFrictionSlip00);
  tolua_function(tolua_S,"SetWheelRollInfluence",tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelRollInfluence00);
  tolua_function(tolua_S,"SetEngineForce",tolua_PhysicsLuaAPI_RaycastVehicle_SetEngineForce00);
  tolua_function(tolua_S,"SetBrake",tolua_PhysicsLuaAPI_RaycastVehicle_SetBrake00);
  tolua_function(tolua_S,"SetWheelRadius",tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelRadius00);
  tolua_function(tolua_S,"ResetWheels",tolua_PhysicsLuaAPI_RaycastVehicle_ResetWheels00);
  tolua_function(tolua_S,"SetWheelRestLength",tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelRestLength00);
  tolua_function(tolua_S,"SetWheelSkidInfo",tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelSkidInfo00);
  tolua_function(tolua_S,"WheelIsGrounded",tolua_PhysicsLuaAPI_RaycastVehicle_WheelIsGrounded00);
  tolua_function(tolua_S,"SetMaxSuspensionTravel",tolua_PhysicsLuaAPI_RaycastVehicle_SetMaxSuspensionTravel00);
  tolua_function(tolua_S,"SetWheelDirection",tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelDirection00);
  tolua_function(tolua_S,"SetWheelAxle",tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelAxle00);
  tolua_function(tolua_S,"SetMaxSideSlipSpeed",tolua_PhysicsLuaAPI_RaycastVehicle_SetMaxSideSlipSpeed00);
  tolua_function(tolua_S,"SetWheelSkidInfoCumulative",tolua_PhysicsLuaAPI_RaycastVehicle_SetWheelSkidInfoCumulative00);
  tolua_function(tolua_S,"SetInAirRPM",tolua_PhysicsLuaAPI_RaycastVehicle_SetInAirRPM00);
  tolua_function(tolua_S,"SetCoordinateSystem",tolua_PhysicsLuaAPI_RaycastVehicle_SetCoordinateSystem00);
  tolua_function(tolua_S,"SetCoordinateSystem",tolua_PhysicsLuaAPI_RaycastVehicle_SetCoordinateSystem01);
  tolua_function(tolua_S,"Init",tolua_PhysicsLuaAPI_RaycastVehicle_Init00);
  tolua_function(tolua_S,"GetWheelPosition",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelPosition00);
  tolua_function(tolua_S,"GetWheelRotation",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelRotation00);
  tolua_function(tolua_S,"GetWheelConnectionPoint",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelConnectionPoint00);
  tolua_function(tolua_S,"GetNumWheels",tolua_PhysicsLuaAPI_RaycastVehicle_GetNumWheels00);
  tolua_function(tolua_S,"GetWheelNode",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelNode00);
  tolua_function(tolua_S,"GetSteeringValue",tolua_PhysicsLuaAPI_RaycastVehicle_GetSteeringValue00);
  tolua_function(tolua_S,"GetWheelSuspensionStiffness",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelSuspensionStiffness00);
  tolua_function(tolua_S,"GetWheelDampingRelaxation",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelDampingRelaxation00);
  tolua_function(tolua_S,"GetWheelDampingCompression",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelDampingCompression00);
  tolua_function(tolua_S,"GetWheelFrictionSlip",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelFrictionSlip00);
  tolua_function(tolua_S,"GetWheelRollInfluence",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelRollInfluence00);
  tolua_function(tolua_S,"GetEngineForce",tolua_PhysicsLuaAPI_RaycastVehicle_GetEngineForce00);
  tolua_function(tolua_S,"GetBrake",tolua_PhysicsLuaAPI_RaycastVehicle_GetBrake00);
  tolua_function(tolua_S,"GetWheelRadius",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelRadius00);
  tolua_function(tolua_S,"GetWheelRestLength",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelRestLength00);
  tolua_function(tolua_S,"GetWheelSkidInfo",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelSkidInfo00);
  tolua_function(tolua_S,"GetMaxSuspensionTravel",tolua_PhysicsLuaAPI_RaycastVehicle_GetMaxSuspensionTravel00);
  tolua_function(tolua_S,"GetWheelSideSlipSpeed",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelSideSlipSpeed00);
  tolua_function(tolua_S,"GetMaxSideSlipSpeed",tolua_PhysicsLuaAPI_RaycastVehicle_GetMaxSideSlipSpeed00);
  tolua_function(tolua_S,"GetWheelSkidInfoCumulative",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelSkidInfoCumulative00);
  tolua_function(tolua_S,"GetWheelDirection",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelDirection00);
  tolua_function(tolua_S,"IsFrontWheel",tolua_PhysicsLuaAPI_RaycastVehicle_IsFrontWheel00);
  tolua_function(tolua_S,"GetWheelAxle",tolua_PhysicsLuaAPI_RaycastVehicle_GetWheelAxle00);
  tolua_function(tolua_S,"GetContactPosition",tolua_PhysicsLuaAPI_RaycastVehicle_GetContactPosition00);
  tolua_function(tolua_S,"GetContactNormal",tolua_PhysicsLuaAPI_RaycastVehicle_GetContactNormal00);
  tolua_function(tolua_S,"GetInAirRPM",tolua_PhysicsLuaAPI_RaycastVehicle_GetInAirRPM00);
  tolua_function(tolua_S,"GetCoordinateSystem",tolua_PhysicsLuaAPI_RaycastVehicle_GetCoordinateSystem00);
  tolua_variable(tolua_S,"RIGHT_UP_FORWARD",tolua_get_RaycastVehicle_RIGHT_UP_FORWARD,NULL);
  tolua_variable(tolua_S,"RIGHT_FORWARD_UP",tolua_get_RaycastVehicle_RIGHT_FORWARD_UP,NULL);
  tolua_variable(tolua_S,"UP_FORWARD_RIGHT",tolua_get_RaycastVehicle_UP_FORWARD_RIGHT,NULL);
  tolua_variable(tolua_S,"UP_RIGHT_FORWARD",tolua_get_RaycastVehicle_UP_RIGHT_FORWARD,NULL);
  tolua_variable(tolua_S,"FORWARD_RIGHT_UP",tolua_get_RaycastVehicle_FORWARD_RIGHT_UP,NULL);
  tolua_variable(tolua_S,"FORWARD_UP_RIGHT",tolua_get_RaycastVehicle_FORWARD_UP_RIGHT,NULL);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_PhysicsLuaAPI (lua_State* tolua_S) {
 return tolua_PhysicsLuaAPI_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif