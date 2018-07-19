/*
** Lua binding: NavigationLuaAPI
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
TOLUA_API int tolua_NavigationLuaAPI_open (lua_State* tolua_S);

#include "Navigation/CrowdAgent.h"
#include "Navigation/CrowdManager.h"
#include "Navigation/DynamicNavigationMesh.h"
#include "Navigation/NavArea.h"
#include "Navigation/Navigable.h"
#include "Navigation/NavigationMesh.h"
#include "IO/VectorBuffer.h"
#include "Navigation/Obstacle.h"
#include "Navigation/OffMeshConnection.h"
using namespace Urho3D;
#pragma warning(disable:4800)

const PODVector<Vector3>& CrowdManagerFindPath(CrowdManager* crowdManager, const Vector3& start, const Vector3& end, int queryFilterType)
{
    static PODVector<Vector3> dest;
    dest.Clear();
    crowdManager->FindPath(dest, start, end, queryFilterType);
    return dest;
}

VectorBuffer NavigationMeshGetTileData(const NavigationMesh* navMesh, const IntVector2& tile)
{
    VectorBuffer buffer;
    buffer.SetData(navMesh->GetTileData(tile));
    return buffer;
}

bool NavigationMeshAddTile(NavigationMesh* navMesh, const VectorBuffer& tileData)
{
    return navMesh->AddTile(tileData.GetBuffer());
}

const PODVector<Vector3>& NavigationMeshFindPath(NavigationMesh* navMesh, const Vector3& start, const Vector3& end, const Vector3& extents = Vector3::ONE)
{
    static PODVector<Vector3> dest;
    dest.Clear();
    navMesh->FindPath(dest, start, end, extents);
    return dest;
}

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_PODVector_CrowdAgent__ (lua_State* tolua_S)
{
 PODVector<CrowdAgent*>* self = (PODVector<CrowdAgent*>*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_IntVector2 (lua_State* tolua_S)
{
 IntVector2* self = (IntVector2*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_BoundingBox (lua_State* tolua_S)
{
 BoundingBox* self = (BoundingBox*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_VectorBuffer (lua_State* tolua_S)
{
 VectorBuffer* self = (VectorBuffer*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Vector3 (lua_State* tolua_S)
{
 Vector3* self = (Vector3*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Matrix3x4");
 tolua_usertype(tolua_S,"DynamicNavigationMesh");
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"NavigationGeometryInfo");
 tolua_usertype(tolua_S,"NavArea");
 tolua_usertype(tolua_S,"CrowdManager");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"CrowdAgent");
 tolua_usertype(tolua_S,"VectorBuffer");
 tolua_usertype(tolua_S,"NavigationMesh");
 tolua_usertype(tolua_S,"OffMeshConnection");
 tolua_usertype(tolua_S,"IntVector2");
 tolua_usertype(tolua_S,"PODVector<CrowdAgent*>");
 tolua_usertype(tolua_S,"Obstacle");
 tolua_usertype(tolua_S,"Navigable");
 tolua_usertype(tolua_S,"BoundingBox");
 tolua_usertype(tolua_S,"PODVector<Vector3>");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"CrowdObstacleAvoidanceParams");
}

/* method: DrawDebugGeometry of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_DrawDebugGeometry00
static int tolua_NavigationLuaAPI_CrowdAgent_DrawDebugGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdAgent",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetTargetPosition of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_SetTargetPosition00
static int tolua_NavigationLuaAPI_CrowdAgent_SetTargetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdAgent",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTargetPosition'", NULL);
#endif
 {
  self->SetTargetPosition(*position);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTargetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTargetVelocity of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_SetTargetVelocity00
static int tolua_NavigationLuaAPI_CrowdAgent_SetTargetVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdAgent",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* velocity = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTargetVelocity'", NULL);
#endif
 {
  self->SetTargetVelocity(*velocity);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTargetVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResetTarget of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_ResetTarget00
static int tolua_NavigationLuaAPI_CrowdAgent_ResetTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResetTarget'", NULL);
#endif
 {
  self->ResetTarget();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResetTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUpdateNodePosition of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_SetUpdateNodePosition00
static int tolua_NavigationLuaAPI_CrowdAgent_SetUpdateNodePosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdAgent",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
  bool unodepos = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUpdateNodePosition'", NULL);
#endif
 {
  self->SetUpdateNodePosition(unodepos);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUpdateNodePosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxAccel of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_SetMaxAccel00
static int tolua_NavigationLuaAPI_CrowdAgent_SetMaxAccel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdAgent",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
  float maxAccel = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxAccel'", NULL);
#endif
 {
  self->SetMaxAccel(maxAccel);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxAccel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxSpeed of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_SetMaxSpeed00
static int tolua_NavigationLuaAPI_CrowdAgent_SetMaxSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdAgent",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
  float maxSpeed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxSpeed'", NULL);
#endif
 {
  self->SetMaxSpeed(maxSpeed);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRadius of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_SetRadius00
static int tolua_NavigationLuaAPI_CrowdAgent_SetRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdAgent",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
  float radius = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRadius'", NULL);
#endif
 {
  self->SetRadius(radius);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHeight of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_SetHeight00
static int tolua_NavigationLuaAPI_CrowdAgent_SetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdAgent",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
  float height = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHeight'", NULL);
#endif
 {
  self->SetHeight(height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetQueryFilterType of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_SetQueryFilterType00
static int tolua_NavigationLuaAPI_CrowdAgent_SetQueryFilterType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdAgent",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
  unsigned queryFilterType = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetQueryFilterType'", NULL);
#endif
 {
  self->SetQueryFilterType(queryFilterType);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetQueryFilterType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetObstacleAvoidanceType of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_SetObstacleAvoidanceType00
static int tolua_NavigationLuaAPI_CrowdAgent_SetObstacleAvoidanceType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdAgent",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
  unsigned obstacleOvoidanceType = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetObstacleAvoidanceType'", NULL);
#endif
 {
  self->SetObstacleAvoidanceType(obstacleOvoidanceType);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetObstacleAvoidanceType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetNavigationQuality of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_SetNavigationQuality00
static int tolua_NavigationLuaAPI_CrowdAgent_SetNavigationQuality00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdAgent",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
  NavigationQuality val = ((NavigationQuality) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNavigationQuality'", NULL);
#endif
 {
  self->SetNavigationQuality(val);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNavigationQuality'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetNavigationPushiness of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_SetNavigationPushiness00
static int tolua_NavigationLuaAPI_CrowdAgent_SetNavigationPushiness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdAgent",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
  NavigationPushiness val = ((NavigationPushiness) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNavigationPushiness'", NULL);
#endif
 {
  self->SetNavigationPushiness(val);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNavigationPushiness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPosition of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetPosition00
static int tolua_NavigationLuaAPI_CrowdAgent_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetDesiredVelocity of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetDesiredVelocity00
static int tolua_NavigationLuaAPI_CrowdAgent_GetDesiredVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDesiredVelocity'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetDesiredVelocity();
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
 tolua_error(tolua_S,"#ferror in function 'GetDesiredVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetActualVelocity of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetActualVelocity00
static int tolua_NavigationLuaAPI_CrowdAgent_GetActualVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetActualVelocity'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetActualVelocity();
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
 tolua_error(tolua_S,"#ferror in function 'GetActualVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTargetPosition of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetTargetPosition00
static int tolua_NavigationLuaAPI_CrowdAgent_GetTargetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTargetPosition'", NULL);
#endif
 {
  const Vector3& tolua_ret = (const Vector3&)  self->GetTargetPosition();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTargetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTargetVelocity of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetTargetVelocity00
static int tolua_NavigationLuaAPI_CrowdAgent_GetTargetVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTargetVelocity'", NULL);
#endif
 {
  const Vector3& tolua_ret = (const Vector3&)  self->GetTargetVelocity();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTargetVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRequestedTargetType of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetRequestedTargetType00
static int tolua_NavigationLuaAPI_CrowdAgent_GetRequestedTargetType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRequestedTargetType'", NULL);
#endif
 {
  CrowdAgentRequestedTarget tolua_ret = (CrowdAgentRequestedTarget)  self->GetRequestedTargetType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRequestedTargetType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAgentState of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetAgentState00
static int tolua_NavigationLuaAPI_CrowdAgent_GetAgentState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAgentState'", NULL);
#endif
 {
  CrowdAgentState tolua_ret = (CrowdAgentState)  self->GetAgentState();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAgentState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTargetState of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetTargetState00
static int tolua_NavigationLuaAPI_CrowdAgent_GetTargetState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTargetState'", NULL);
#endif
 {
  CrowdAgentTargetState tolua_ret = (CrowdAgentTargetState)  self->GetTargetState();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTargetState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUpdateNodePosition of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetUpdateNodePosition00
static int tolua_NavigationLuaAPI_CrowdAgent_GetUpdateNodePosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUpdateNodePosition'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetUpdateNodePosition();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUpdateNodePosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxAccel of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetMaxAccel00
static int tolua_NavigationLuaAPI_CrowdAgent_GetMaxAccel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxAccel'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxAccel();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxAccel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxSpeed of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetMaxSpeed00
static int tolua_NavigationLuaAPI_CrowdAgent_GetMaxSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxSpeed'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxSpeed();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRadius of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetRadius00
static int tolua_NavigationLuaAPI_CrowdAgent_GetRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRadius'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRadius();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeight of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetHeight00
static int tolua_NavigationLuaAPI_CrowdAgent_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeight'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetQueryFilterType of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetQueryFilterType00
static int tolua_NavigationLuaAPI_CrowdAgent_GetQueryFilterType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetQueryFilterType'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetQueryFilterType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetQueryFilterType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObstacleAvoidanceType of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetObstacleAvoidanceType00
static int tolua_NavigationLuaAPI_CrowdAgent_GetObstacleAvoidanceType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObstacleAvoidanceType'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetObstacleAvoidanceType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObstacleAvoidanceType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNavigationQuality of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetNavigationQuality00
static int tolua_NavigationLuaAPI_CrowdAgent_GetNavigationQuality00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNavigationQuality'", NULL);
#endif
 {
  NavigationQuality tolua_ret = (NavigationQuality)  self->GetNavigationQuality();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNavigationQuality'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNavigationPushiness of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_GetNavigationPushiness00
static int tolua_NavigationLuaAPI_CrowdAgent_GetNavigationPushiness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNavigationPushiness'", NULL);
#endif
 {
  NavigationPushiness tolua_ret = (NavigationPushiness)  self->GetNavigationPushiness();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNavigationPushiness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasRequestedTarget of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_HasRequestedTarget00
static int tolua_NavigationLuaAPI_CrowdAgent_HasRequestedTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasRequestedTarget'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasRequestedTarget();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasRequestedTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasArrived of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_HasArrived00
static int tolua_NavigationLuaAPI_CrowdAgent_HasArrived00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasArrived'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasArrived();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasArrived'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInCrowd of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdAgent_IsInCrowd00
static int tolua_NavigationLuaAPI_CrowdAgent_IsInCrowd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdAgent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdAgent* self = (const CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInCrowd'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsInCrowd();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInCrowd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: targetPosition of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_targetPosition
static int tolua_get_CrowdAgent_targetPosition(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'targetPosition'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetTargetPosition();
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

/* set function: targetPosition of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_set_CrowdAgent_targetPosition
static int tolua_set_CrowdAgent_targetPosition(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'targetPosition'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTargetPosition(*((Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: targetVelocity of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_targetVelocity
static int tolua_get_CrowdAgent_targetVelocity(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'targetVelocity'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetTargetVelocity();
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

/* set function: targetVelocity of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_set_CrowdAgent_targetVelocity
static int tolua_set_CrowdAgent_targetVelocity(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'targetVelocity'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTargetVelocity(*((Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: updateNodePosition of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_updateNodePosition
static int tolua_get_CrowdAgent_updateNodePosition(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'updateNodePosition'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetUpdateNodePosition());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: updateNodePosition of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_set_CrowdAgent_updateNodePosition
static int tolua_set_CrowdAgent_updateNodePosition(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'updateNodePosition'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUpdateNodePosition(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxAccel of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_maxAccel
static int tolua_get_CrowdAgent_maxAccel(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxAccel'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxAccel());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxAccel of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_set_CrowdAgent_maxAccel
static int tolua_set_CrowdAgent_maxAccel(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxAccel'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxAccel(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxSpeed of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_maxSpeed
static int tolua_get_CrowdAgent_maxSpeed(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxSpeed'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxSpeed());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxSpeed of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_set_CrowdAgent_maxSpeed
static int tolua_set_CrowdAgent_maxSpeed(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxSpeed'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxSpeed(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: radius of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_radius
static int tolua_get_CrowdAgent_radius(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radius'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRadius());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: radius of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_set_CrowdAgent_radius
static int tolua_set_CrowdAgent_radius(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radius'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRadius(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_height
static int tolua_get_CrowdAgent_height(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetHeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_set_CrowdAgent_height
static int tolua_set_CrowdAgent_height(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetHeight(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: queryFilterType of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_queryFilterType
static int tolua_get_CrowdAgent_queryFilterType(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'queryFilterType'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetQueryFilterType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: queryFilterType of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_set_CrowdAgent_queryFilterType
static int tolua_set_CrowdAgent_queryFilterType(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'queryFilterType'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetQueryFilterType(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: obstacleAvoidanceType of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_obstacleAvoidanceType
static int tolua_get_CrowdAgent_obstacleAvoidanceType(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'obstacleAvoidanceType'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetObstacleAvoidanceType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: obstacleAvoidanceType of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_set_CrowdAgent_obstacleAvoidanceType
static int tolua_set_CrowdAgent_obstacleAvoidanceType(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'obstacleAvoidanceType'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetObstacleAvoidanceType(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: navigationQuality of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_navigationQuality
static int tolua_get_CrowdAgent_navigationQuality(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'navigationQuality'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNavigationQuality());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: navigationQuality of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_set_CrowdAgent_navigationQuality
static int tolua_set_CrowdAgent_navigationQuality(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'navigationQuality'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetNavigationQuality(((NavigationQuality) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: navigationPushiness of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_navigationPushiness
static int tolua_get_CrowdAgent_navigationPushiness(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'navigationPushiness'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNavigationPushiness());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: navigationPushiness of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_set_CrowdAgent_navigationPushiness
static int tolua_set_CrowdAgent_navigationPushiness(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'navigationPushiness'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetNavigationPushiness(((NavigationPushiness) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: position of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_position
static int tolua_get_CrowdAgent_position(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: desiredVelocity of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_desiredVelocity
static int tolua_get_CrowdAgent_desiredVelocity(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'desiredVelocity'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetDesiredVelocity();
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

/* get function: actualVelocity of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_actualVelocity
static int tolua_get_CrowdAgent_actualVelocity(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'actualVelocity'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetActualVelocity();
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

/* get function: requestedTargetType of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_requestedTargetType
static int tolua_get_CrowdAgent_requestedTargetType(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'requestedTargetType'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRequestedTargetType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: agentState of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_agentState
static int tolua_get_CrowdAgent_agentState(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'agentState'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAgentState());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: targetState of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_targetState
static int tolua_get_CrowdAgent_targetState(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'targetState'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTargetState());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: requestedTarget of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_requestedTarget
static int tolua_get_CrowdAgent_requestedTarget(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'requestedTarget'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->HasRequestedTarget());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: arrived of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_arrived
static int tolua_get_CrowdAgent_arrived(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'arrived'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->HasArrived());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: inCrowd of class  CrowdAgent */
#ifndef TOLUA_DISABLE_tolua_get_CrowdAgent_inCrowd
static int tolua_get_CrowdAgent_inCrowd(lua_State* tolua_S)
{
  CrowdAgent* self = (CrowdAgent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'inCrowd'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsInCrowd());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawDebugGeometry of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_DrawDebugGeometry00
static int tolua_NavigationLuaAPI_CrowdManager_DrawDebugGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetCrowdTarget of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_SetCrowdTarget00
static int tolua_NavigationLuaAPI_CrowdManager_SetCrowdTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isusertype(tolua_S,3,"Node",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  Node* node = ((Node*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCrowdTarget'", NULL);
#endif
 {
  self->SetCrowdTarget(*position,node);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCrowdTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCrowdVelocity of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_SetCrowdVelocity00
static int tolua_NavigationLuaAPI_CrowdManager_SetCrowdVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isusertype(tolua_S,3,"Node",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* velocity = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  Node* node = ((Node*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCrowdVelocity'", NULL);
#endif
 {
  self->SetCrowdVelocity(*velocity,node);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCrowdVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResetCrowdTarget of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_ResetCrowdTarget00
static int tolua_NavigationLuaAPI_CrowdManager_ResetCrowdTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResetCrowdTarget'", NULL);
#endif
 {
  self->ResetCrowdTarget(node);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResetCrowdTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxAgents of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_SetMaxAgents00
static int tolua_NavigationLuaAPI_CrowdManager_SetMaxAgents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned agentCt = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxAgents'", NULL);
#endif
 {
  self->SetMaxAgents(agentCt);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxAgents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxAgentRadius of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_SetMaxAgentRadius00
static int tolua_NavigationLuaAPI_CrowdManager_SetMaxAgentRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  float maxAgentRadius = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxAgentRadius'", NULL);
#endif
 {
  self->SetMaxAgentRadius(maxAgentRadius);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxAgentRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetNavigationMesh of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_SetNavigationMesh00
static int tolua_NavigationLuaAPI_CrowdManager_SetNavigationMesh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  NavigationMesh* navMesh = ((NavigationMesh*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNavigationMesh'", NULL);
#endif
 {
  self->SetNavigationMesh(navMesh);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNavigationMesh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIncludeFlags of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_SetIncludeFlags00
static int tolua_NavigationLuaAPI_CrowdManager_SetIncludeFlags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned queryFilterType = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  unsigned short flags = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIncludeFlags'", NULL);
#endif
 {
  self->SetIncludeFlags(queryFilterType,flags);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIncludeFlags'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetExcludeFlags of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_SetExcludeFlags00
static int tolua_NavigationLuaAPI_CrowdManager_SetExcludeFlags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned queryFilterType = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  unsigned short flags = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetExcludeFlags'", NULL);
#endif
 {
  self->SetExcludeFlags(queryFilterType,flags);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetExcludeFlags'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAreaCost of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_SetAreaCost00
static int tolua_NavigationLuaAPI_CrowdManager_SetAreaCost00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned queryFilterType = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  unsigned areaID = ((unsigned)  tolua_tonumber(tolua_S,3,0));
  float cost = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAreaCost'", NULL);
#endif
 {
  self->SetAreaCost(queryFilterType,areaID,cost);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAreaCost'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetObstacleAvoidanceParams of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_SetObstacleAvoidanceParams00
static int tolua_NavigationLuaAPI_CrowdManager_SetObstacleAvoidanceParams00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CrowdObstacleAvoidanceParams",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned obstacleAvoidanceType = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  const CrowdObstacleAvoidanceParams* params = ((const CrowdObstacleAvoidanceParams*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetObstacleAvoidanceParams'", NULL);
#endif
 {
  self->SetObstacleAvoidanceParams(obstacleAvoidanceType,*params);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetObstacleAvoidanceParams'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAgents of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_GetAgents00
static int tolua_NavigationLuaAPI_CrowdManager_GetAgents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdManager",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",1,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdManager* self = (const CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
  bool inCrowdFilter = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAgents'", NULL);
#endif
 {
  PODVector<CrowdAgent*> tolua_ret = (PODVector<CrowdAgent*>)  self->GetAgents(node,inCrowdFilter);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((PODVector<CrowdAgent*>)(tolua_ret));
  ToluaPushPODVector<CrowdAgent*>("",tolua_S,tolua_obj,"CrowdAgent");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(PODVector<CrowdAgent*>));
  ToluaPushPODVector<CrowdAgent*>("",tolua_S,tolua_obj,"CrowdAgent");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAgents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindNearestPoint of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_FindNearestPoint00
static int tolua_NavigationLuaAPI_CrowdManager_FindNearestPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  int queryFilterType = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindNearestPoint'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->FindNearestPoint(*point,queryFilterType);
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
 tolua_error(tolua_S,"#ferror in function 'FindNearestPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MoveAlongSurface of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_MoveAlongSurface00
static int tolua_NavigationLuaAPI_CrowdManager_MoveAlongSurface00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* start = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* end = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  int queryFilterType = ((int)  tolua_tonumber(tolua_S,4,0));
  int maxVisited = ((int)  tolua_tonumber(tolua_S,5,3));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MoveAlongSurface'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->MoveAlongSurface(*start,*end,queryFilterType,maxVisited);
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
 tolua_error(tolua_S,"#ferror in function 'MoveAlongSurface'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CrowdManagerFindPath of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_FindPath00
static int tolua_NavigationLuaAPI_CrowdManager_FindPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* start = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* end = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  int queryFilterType = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CrowdManagerFindPath'", NULL);
#endif
 {
  tolua_outside  const PODVector<Vector3>& tolua_ret = (tolua_outside  const PODVector<Vector3>&)  CrowdManagerFindPath(self,*start,*end,queryFilterType);
  ToluaPushPODVector<Vector3>(tolua_S,(void*)&tolua_ret,"Vector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRandomPoint of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_GetRandomPoint00
static int tolua_NavigationLuaAPI_CrowdManager_GetRandomPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  int queryFilterType = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRandomPoint'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetRandomPoint(queryFilterType);
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
 tolua_error(tolua_S,"#ferror in function 'GetRandomPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRandomPointInCircle of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_GetRandomPointInCircle00
static int tolua_NavigationLuaAPI_CrowdManager_GetRandomPointInCircle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* center = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float radius = ((float)  tolua_tonumber(tolua_S,3,0));
  int queryFilterType = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRandomPointInCircle'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetRandomPointInCircle(*center,radius,queryFilterType);
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
 tolua_error(tolua_S,"#ferror in function 'GetRandomPointInCircle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDistanceToWall of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_GetDistanceToWall00
static int tolua_NavigationLuaAPI_CrowdManager_GetDistanceToWall00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,5,"Vector3",1,&tolua_err) ||
 !tolua_isusertype(tolua_S,6,"Vector3",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float radius = ((float)  tolua_tonumber(tolua_S,3,0));
  int queryFilterType = ((int)  tolua_tonumber(tolua_S,4,0));
  Vector3* hitPos = ((Vector3*)  tolua_tousertype(tolua_S,5,0));
  Vector3* hitNormal = ((Vector3*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDistanceToWall'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDistanceToWall(*point,radius,queryFilterType,hitPos,hitNormal);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDistanceToWall'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Raycast of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_Raycast00
static int tolua_NavigationLuaAPI_CrowdManager_Raycast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CrowdManager",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,5,"Vector3",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* start = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* end = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  int queryFilterType = ((int)  tolua_tonumber(tolua_S,4,0));
  Vector3* hitNormal = ((Vector3*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Raycast'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Raycast(*start,*end,queryFilterType,hitNormal);
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
 tolua_error(tolua_S,"#ferror in function 'Raycast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxAgents of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_GetMaxAgents00
static int tolua_NavigationLuaAPI_CrowdManager_GetMaxAgents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdManager* self = (const CrowdManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxAgents'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetMaxAgents();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxAgents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxAgentRadius of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_GetMaxAgentRadius00
static int tolua_NavigationLuaAPI_CrowdManager_GetMaxAgentRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdManager* self = (const CrowdManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxAgentRadius'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxAgentRadius();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxAgentRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNavigationMesh of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_GetNavigationMesh00
static int tolua_NavigationLuaAPI_CrowdManager_GetNavigationMesh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdManager* self = (const CrowdManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNavigationMesh'", NULL);
#endif
 {
  NavigationMesh* tolua_ret = (NavigationMesh*)  self->GetNavigationMesh();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"NavigationMesh");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNavigationMesh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumQueryFilterTypes of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_GetNumQueryFilterTypes00
static int tolua_NavigationLuaAPI_CrowdManager_GetNumQueryFilterTypes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdManager* self = (const CrowdManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumQueryFilterTypes'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumQueryFilterTypes();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumQueryFilterTypes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumAreas of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_GetNumAreas00
static int tolua_NavigationLuaAPI_CrowdManager_GetNumAreas00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdManager",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdManager* self = (const CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned queryFilterType = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumAreas'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumAreas(queryFilterType);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumAreas'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIncludeFlags of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_GetIncludeFlags00
static int tolua_NavigationLuaAPI_CrowdManager_GetIncludeFlags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdManager",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdManager* self = (const CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned queryFilterType = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIncludeFlags'", NULL);
#endif
 {
  unsigned short tolua_ret = (unsigned short)  self->GetIncludeFlags(queryFilterType);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIncludeFlags'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetExcludeFlags of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_GetExcludeFlags00
static int tolua_NavigationLuaAPI_CrowdManager_GetExcludeFlags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdManager",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdManager* self = (const CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned queryFilterType = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetExcludeFlags'", NULL);
#endif
 {
  unsigned short tolua_ret = (unsigned short)  self->GetExcludeFlags(queryFilterType);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetExcludeFlags'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAreaCost of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_GetAreaCost00
static int tolua_NavigationLuaAPI_CrowdManager_GetAreaCost00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdManager",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdManager* self = (const CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned queryFilterType = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  unsigned areaID = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAreaCost'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAreaCost(queryFilterType,areaID);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAreaCost'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumObstacleAvoidanceTypes of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_GetNumObstacleAvoidanceTypes00
static int tolua_NavigationLuaAPI_CrowdManager_GetNumObstacleAvoidanceTypes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdManager",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdManager* self = (const CrowdManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumObstacleAvoidanceTypes'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumObstacleAvoidanceTypes();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumObstacleAvoidanceTypes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObstacleAvoidanceParams of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_CrowdManager_GetObstacleAvoidanceParams00
static int tolua_NavigationLuaAPI_CrowdManager_GetObstacleAvoidanceParams00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CrowdManager",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CrowdManager* self = (const CrowdManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned obstacleAvoidanceType = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObstacleAvoidanceParams'", NULL);
#endif
 {
  const CrowdObstacleAvoidanceParams& tolua_ret = (const CrowdObstacleAvoidanceParams&)  self->GetObstacleAvoidanceParams(obstacleAvoidanceType);
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const CrowdObstacleAvoidanceParams");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObstacleAvoidanceParams'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxAgents of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_get_CrowdManager_maxAgents
static int tolua_get_CrowdManager_maxAgents(lua_State* tolua_S)
{
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxAgents'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxAgents());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxAgents of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_set_CrowdManager_maxAgents
static int tolua_set_CrowdManager_maxAgents(lua_State* tolua_S)
{
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxAgents'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxAgents(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxAgentRadius of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_get_CrowdManager_maxAgentRadius
static int tolua_get_CrowdManager_maxAgentRadius(lua_State* tolua_S)
{
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxAgentRadius'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxAgentRadius());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxAgentRadius of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_set_CrowdManager_maxAgentRadius
static int tolua_set_CrowdManager_maxAgentRadius(lua_State* tolua_S)
{
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxAgentRadius'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxAgentRadius(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: navigationMesh of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_get_CrowdManager_navigationMesh_ptr
static int tolua_get_CrowdManager_navigationMesh_ptr(lua_State* tolua_S)
{
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'navigationMesh'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetNavigationMesh(),"NavigationMesh");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: navigationMesh of class  CrowdManager */
#ifndef TOLUA_DISABLE_tolua_set_CrowdManager_navigationMesh_ptr
static int tolua_set_CrowdManager_navigationMesh_ptr(lua_State* tolua_S)
{
  CrowdManager* self = (CrowdManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'navigationMesh'",NULL);
 if (!tolua_isusertype(tolua_S,2,"NavigationMesh",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetNavigationMesh(((NavigationMesh*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDrawObstacles of class  DynamicNavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_DynamicNavigationMesh_SetDrawObstacles00
static int tolua_NavigationLuaAPI_DynamicNavigationMesh_SetDrawObstacles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DynamicNavigationMesh",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DynamicNavigationMesh* self = (DynamicNavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDrawObstacles'", NULL);
#endif
 {
  self->SetDrawObstacles(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDrawObstacles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxLayers of class  DynamicNavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_DynamicNavigationMesh_SetMaxLayers00
static int tolua_NavigationLuaAPI_DynamicNavigationMesh_SetMaxLayers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DynamicNavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DynamicNavigationMesh* self = (DynamicNavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  unsigned maxLayers = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxLayers'", NULL);
#endif
 {
  self->SetMaxLayers(maxLayers);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxLayers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxObstacles of class  DynamicNavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_DynamicNavigationMesh_SetMaxObstacles00
static int tolua_NavigationLuaAPI_DynamicNavigationMesh_SetMaxObstacles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DynamicNavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DynamicNavigationMesh* self = (DynamicNavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  unsigned maxObstacles = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxObstacles'", NULL);
#endif
 {
  self->SetMaxObstacles(maxObstacles);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxObstacles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDrawObstacles of class  DynamicNavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_DynamicNavigationMesh_GetDrawObstacles00
static int tolua_NavigationLuaAPI_DynamicNavigationMesh_GetDrawObstacles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DynamicNavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DynamicNavigationMesh* self = (const DynamicNavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDrawObstacles'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetDrawObstacles();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDrawObstacles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxLayers of class  DynamicNavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_DynamicNavigationMesh_GetMaxLayers00
static int tolua_NavigationLuaAPI_DynamicNavigationMesh_GetMaxLayers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DynamicNavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DynamicNavigationMesh* self = (const DynamicNavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxLayers'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetMaxLayers();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxLayers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxObstacles of class  DynamicNavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_DynamicNavigationMesh_GetMaxObstacles00
static int tolua_NavigationLuaAPI_DynamicNavigationMesh_GetMaxObstacles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DynamicNavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DynamicNavigationMesh* self = (const DynamicNavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxObstacles'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetMaxObstacles();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxObstacles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: drawObstacles of class  DynamicNavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_DynamicNavigationMesh_drawObstacles
static int tolua_get_DynamicNavigationMesh_drawObstacles(lua_State* tolua_S)
{
  DynamicNavigationMesh* self = (DynamicNavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawObstacles'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetDrawObstacles());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: drawObstacles of class  DynamicNavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_DynamicNavigationMesh_drawObstacles
static int tolua_set_DynamicNavigationMesh_drawObstacles(lua_State* tolua_S)
{
  DynamicNavigationMesh* self = (DynamicNavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawObstacles'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDrawObstacles(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxObstacles of class  DynamicNavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_DynamicNavigationMesh_maxObstacles
static int tolua_get_DynamicNavigationMesh_maxObstacles(lua_State* tolua_S)
{
  DynamicNavigationMesh* self = (DynamicNavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxObstacles'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxObstacles());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxObstacles of class  DynamicNavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_DynamicNavigationMesh_maxObstacles
static int tolua_set_DynamicNavigationMesh_maxObstacles(lua_State* tolua_S)
{
  DynamicNavigationMesh* self = (DynamicNavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxObstacles'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxObstacles(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxLayers of class  DynamicNavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_DynamicNavigationMesh_maxLayers
static int tolua_get_DynamicNavigationMesh_maxLayers(lua_State* tolua_S)
{
  DynamicNavigationMesh* self = (DynamicNavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxLayers'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxLayers());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxLayers of class  DynamicNavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_DynamicNavigationMesh_maxLayers
static int tolua_set_DynamicNavigationMesh_maxLayers(lua_State* tolua_S)
{
  DynamicNavigationMesh* self = (DynamicNavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxLayers'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxLayers(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAreaID of class  NavArea */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavArea_GetAreaID00
static int tolua_NavigationLuaAPI_NavArea_GetAreaID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavArea",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavArea* self = (const NavArea*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAreaID'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetAreaID();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAreaID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAreaID of class  NavArea */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavArea_SetAreaID00
static int tolua_NavigationLuaAPI_NavArea_SetAreaID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavArea",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavArea* self = (NavArea*)  tolua_tousertype(tolua_S,1,0);
  unsigned tolua_var_1 = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAreaID'", NULL);
#endif
 {
  self->SetAreaID(tolua_var_1);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAreaID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBoundingBox of class  NavArea */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavArea_GetBoundingBox00
static int tolua_NavigationLuaAPI_NavArea_GetBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavArea",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavArea* self = (NavArea*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBoundingBox'", NULL);
#endif
 {
  BoundingBox tolua_ret = (BoundingBox)  self->GetBoundingBox();
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
 tolua_error(tolua_S,"#ferror in function 'GetBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBoundingBox of class  NavArea */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavArea_SetBoundingBox00
static int tolua_NavigationLuaAPI_NavArea_SetBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavArea",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavArea* self = (NavArea*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* bnds = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBoundingBox'", NULL);
#endif
 {
  self->SetBoundingBox(*bnds);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldBoundingBox of class  NavArea */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavArea_GetWorldBoundingBox00
static int tolua_NavigationLuaAPI_NavArea_GetWorldBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavArea",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavArea* self = (const NavArea*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: areaID of class  NavArea */
#ifndef TOLUA_DISABLE_tolua_get_NavArea_areaID
static int tolua_get_NavArea_areaID(lua_State* tolua_S)
{
  NavArea* self = (NavArea*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'areaID'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAreaID());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: areaID of class  NavArea */
#ifndef TOLUA_DISABLE_tolua_set_NavArea_areaID
static int tolua_set_NavArea_areaID(lua_State* tolua_S)
{
  NavArea* self = (NavArea*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'areaID'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAreaID(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: boundingBox of class  NavArea */
#ifndef TOLUA_DISABLE_tolua_get_NavArea_boundingBox
static int tolua_get_NavArea_boundingBox(lua_State* tolua_S)
{
  NavArea* self = (NavArea*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'boundingBox'",NULL);
#endif
 BoundingBox tolua_ret = (BoundingBox)self->GetBoundingBox();
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

/* set function: boundingBox of class  NavArea */
#ifndef TOLUA_DISABLE_tolua_set_NavArea_boundingBox
static int tolua_set_NavArea_boundingBox(lua_State* tolua_S)
{
  NavArea* self = (NavArea*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'boundingBox'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"BoundingBox",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetBoundingBox(*((BoundingBox*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: worldBoundingBox of class  NavArea */
#ifndef TOLUA_DISABLE_tolua_get_NavArea_worldBoundingBox
static int tolua_get_NavArea_worldBoundingBox(lua_State* tolua_S)
{
  NavArea* self = (NavArea*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetRecursive of class  Navigable */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_Navigable_SetRecursive00
static int tolua_NavigationLuaAPI_Navigable_SetRecursive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Navigable",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Navigable* self = (Navigable*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRecursive'", NULL);
#endif
 {
  self->SetRecursive(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRecursive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsRecursive of class  Navigable */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_Navigable_IsRecursive00
static int tolua_NavigationLuaAPI_Navigable_IsRecursive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Navigable",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Navigable* self = (const Navigable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsRecursive'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsRecursive();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsRecursive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: recursive of class  Navigable */
#ifndef TOLUA_DISABLE_tolua_get_Navigable_recursive
static int tolua_get_Navigable_recursive(lua_State* tolua_S)
{
  Navigable* self = (Navigable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'recursive'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsRecursive());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: recursive of class  Navigable */
#ifndef TOLUA_DISABLE_tolua_set_Navigable_recursive
static int tolua_set_Navigable_recursive(lua_State* tolua_S)
{
  Navigable* self = (Navigable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'recursive'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRecursive(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: component_ of class  NavigationGeometryInfo */
#ifndef TOLUA_DISABLE_tolua_get_NavigationGeometryInfo_component_ptr
static int tolua_get_NavigationGeometryInfo_component_ptr(lua_State* tolua_S)
{
  NavigationGeometryInfo* self = (NavigationGeometryInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'component_'",NULL);
#endif
  ToluaPushObject(tolua_S,(void*)self->component_,"Component");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: component_ of class  NavigationGeometryInfo */
#ifndef TOLUA_DISABLE_tolua_set_NavigationGeometryInfo_component_ptr
static int tolua_set_NavigationGeometryInfo_component_ptr(lua_State* tolua_S)
{
  NavigationGeometryInfo* self = (NavigationGeometryInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'component_'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Component",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->component_ = ((Component*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: lodLevel_ of class  NavigationGeometryInfo */
#ifndef TOLUA_DISABLE_tolua_get_NavigationGeometryInfo_lodLevel
static int tolua_get_NavigationGeometryInfo_lodLevel(lua_State* tolua_S)
{
  NavigationGeometryInfo* self = (NavigationGeometryInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lodLevel_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->lodLevel_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: lodLevel_ of class  NavigationGeometryInfo */
#ifndef TOLUA_DISABLE_tolua_set_NavigationGeometryInfo_lodLevel
static int tolua_set_NavigationGeometryInfo_lodLevel(lua_State* tolua_S)
{
  NavigationGeometryInfo* self = (NavigationGeometryInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lodLevel_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->lodLevel_ = ((unsigned)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: transform_ of class  NavigationGeometryInfo */
#ifndef TOLUA_DISABLE_tolua_get_NavigationGeometryInfo_transform
static int tolua_get_NavigationGeometryInfo_transform(lua_State* tolua_S)
{
  NavigationGeometryInfo* self = (NavigationGeometryInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'transform_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->transform_,"Matrix3x4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: transform_ of class  NavigationGeometryInfo */
#ifndef TOLUA_DISABLE_tolua_set_NavigationGeometryInfo_transform
static int tolua_set_NavigationGeometryInfo_transform(lua_State* tolua_S)
{
  NavigationGeometryInfo* self = (NavigationGeometryInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'transform_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Matrix3x4",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->transform_ = *((Matrix3x4*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: boundingBox_ of class  NavigationGeometryInfo */
#ifndef TOLUA_DISABLE_tolua_get_NavigationGeometryInfo_boundingBox
static int tolua_get_NavigationGeometryInfo_boundingBox(lua_State* tolua_S)
{
  NavigationGeometryInfo* self = (NavigationGeometryInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'boundingBox_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->boundingBox_,"BoundingBox");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: boundingBox_ of class  NavigationGeometryInfo */
#ifndef TOLUA_DISABLE_tolua_set_NavigationGeometryInfo_boundingBox
static int tolua_set_NavigationGeometryInfo_boundingBox(lua_State* tolua_S)
{
  NavigationGeometryInfo* self = (NavigationGeometryInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'boundingBox_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"BoundingBox",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->boundingBox_ = *((BoundingBox*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTileSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetTileSize00
static int tolua_NavigationLuaAPI_NavigationMesh_SetTileSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  int size = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTileSize'", NULL);
#endif
 {
  self->SetTileSize(size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTileSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCellSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetCellSize00
static int tolua_NavigationLuaAPI_NavigationMesh_SetCellSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  float size = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCellSize'", NULL);
#endif
 {
  self->SetCellSize(size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCellSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCellHeight of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetCellHeight00
static int tolua_NavigationLuaAPI_NavigationMesh_SetCellHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  float height = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCellHeight'", NULL);
#endif
 {
  self->SetCellHeight(height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCellHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAgentHeight of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetAgentHeight00
static int tolua_NavigationLuaAPI_NavigationMesh_SetAgentHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  float height = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAgentHeight'", NULL);
#endif
 {
  self->SetAgentHeight(height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAgentHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAgentRadius of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetAgentRadius00
static int tolua_NavigationLuaAPI_NavigationMesh_SetAgentRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  float radius = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAgentRadius'", NULL);
#endif
 {
  self->SetAgentRadius(radius);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAgentRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAgentMaxClimb of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetAgentMaxClimb00
static int tolua_NavigationLuaAPI_NavigationMesh_SetAgentMaxClimb00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  float maxClimb = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAgentMaxClimb'", NULL);
#endif
 {
  self->SetAgentMaxClimb(maxClimb);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAgentMaxClimb'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAgentMaxSlope of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetAgentMaxSlope00
static int tolua_NavigationLuaAPI_NavigationMesh_SetAgentMaxSlope00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  float maxSlope = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAgentMaxSlope'", NULL);
#endif
 {
  self->SetAgentMaxSlope(maxSlope);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAgentMaxSlope'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRegionMinSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetRegionMinSize00
static int tolua_NavigationLuaAPI_NavigationMesh_SetRegionMinSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  float size = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRegionMinSize'", NULL);
#endif
 {
  self->SetRegionMinSize(size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRegionMinSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRegionMergeSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetRegionMergeSize00
static int tolua_NavigationLuaAPI_NavigationMesh_SetRegionMergeSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  float size = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRegionMergeSize'", NULL);
#endif
 {
  self->SetRegionMergeSize(size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRegionMergeSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEdgeMaxLength of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetEdgeMaxLength00
static int tolua_NavigationLuaAPI_NavigationMesh_SetEdgeMaxLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  float length = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEdgeMaxLength'", NULL);
#endif
 {
  self->SetEdgeMaxLength(length);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEdgeMaxLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEdgeMaxError of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetEdgeMaxError00
static int tolua_NavigationLuaAPI_NavigationMesh_SetEdgeMaxError00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  float error = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEdgeMaxError'", NULL);
#endif
 {
  self->SetEdgeMaxError(error);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEdgeMaxError'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDetailSampleDistance of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetDetailSampleDistance00
static int tolua_NavigationLuaAPI_NavigationMesh_SetDetailSampleDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  float distance = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDetailSampleDistance'", NULL);
#endif
 {
  self->SetDetailSampleDistance(distance);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDetailSampleDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDetailSampleMaxError of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetDetailSampleMaxError00
static int tolua_NavigationLuaAPI_NavigationMesh_SetDetailSampleMaxError00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  float error = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDetailSampleMaxError'", NULL);
#endif
 {
  self->SetDetailSampleMaxError(error);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDetailSampleMaxError'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPadding of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetPadding00
static int tolua_NavigationLuaAPI_NavigationMesh_SetPadding00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* padding = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPadding'", NULL);
#endif
 {
  self->SetPadding(*padding);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPadding'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAreaCost of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetAreaCost00
static int tolua_NavigationLuaAPI_NavigationMesh_SetAreaCost00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  unsigned areaID = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  float cost = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAreaCost'", NULL);
#endif
 {
  self->SetAreaCost(areaID,cost);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAreaCost'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Allocate of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_Allocate00
static int tolua_NavigationLuaAPI_NavigationMesh_Allocate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* boundingBox = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
  unsigned maxTiles = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Allocate'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Allocate(*boundingBox,maxTiles);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Allocate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Build of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_Build00
static int tolua_NavigationLuaAPI_NavigationMesh_Build00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Build'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Build();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Build'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Build of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_Build01
static int tolua_NavigationLuaAPI_NavigationMesh_Build01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* boundingBox = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Build'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Build(*boundingBox);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_NavigationLuaAPI_NavigationMesh_Build00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Build of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_Build02
static int tolua_NavigationLuaAPI_NavigationMesh_Build02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* from = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
  const IntVector2* to = ((const IntVector2*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Build'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Build(*from,*to);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_NavigationLuaAPI_NavigationMesh_Build01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: NavigationMeshGetTileData of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetTileData00
static int tolua_NavigationLuaAPI_NavigationMesh_GetTileData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* tile = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NavigationMeshGetTileData'", NULL);
#endif
 {
  tolua_outside VectorBuffer tolua_ret = (tolua_outside VectorBuffer)  NavigationMeshGetTileData(self,*tile);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((VectorBuffer)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"VectorBuffer");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(VectorBuffer));
  tolua_pushusertype(tolua_S,tolua_obj,"VectorBuffer");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTileData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NavigationMeshAddTile of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_AddTile00
static int tolua_NavigationLuaAPI_NavigationMesh_AddTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VectorBuffer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const VectorBuffer* tileData = ((const VectorBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NavigationMeshAddTile'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  NavigationMeshAddTile(self,*tileData);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddTile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveTile of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_RemoveTile00
static int tolua_NavigationLuaAPI_NavigationMesh_RemoveTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* tile = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveTile'", NULL);
#endif
 {
  self->RemoveTile(*tile);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveTile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllTiles of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_RemoveAllTiles00
static int tolua_NavigationLuaAPI_NavigationMesh_RemoveAllTiles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllTiles'", NULL);
#endif
 {
  self->RemoveAllTiles();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllTiles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasTile of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_HasTile00
static int tolua_NavigationLuaAPI_NavigationMesh_HasTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* tile = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasTile'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasTile(*tile);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasTile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTileBoudningBox of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetTileBoudningBox00
static int tolua_NavigationLuaAPI_NavigationMesh_GetTileBoudningBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* tile = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTileBoudningBox'", NULL);
#endif
 {
  BoundingBox tolua_ret = (BoundingBox)  self->GetTileBoudningBox(*tile);
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
 tolua_error(tolua_S,"#ferror in function 'GetTileBoudningBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTileIndex of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetTileIndex00
static int tolua_NavigationLuaAPI_NavigationMesh_GetTileIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTileIndex'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->GetTileIndex(*position);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTileIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPartitionType of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetPartitionType00
static int tolua_NavigationLuaAPI_NavigationMesh_SetPartitionType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  NavmeshPartitionType aType = ((NavmeshPartitionType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPartitionType'", NULL);
#endif
 {
  self->SetPartitionType(aType);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPartitionType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDrawOffMeshConnections of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetDrawOffMeshConnections00
static int tolua_NavigationLuaAPI_NavigationMesh_SetDrawOffMeshConnections00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDrawOffMeshConnections'", NULL);
#endif
 {
  self->SetDrawOffMeshConnections(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDrawOffMeshConnections'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDrawNavAreas of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_SetDrawNavAreas00
static int tolua_NavigationLuaAPI_NavigationMesh_SetDrawNavAreas00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDrawNavAreas'", NULL);
#endif
 {
  self->SetDrawNavAreas(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDrawNavAreas'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindNearestPoint of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_FindNearestPoint00
static int tolua_NavigationLuaAPI_NavigationMesh_FindNearestPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindNearestPoint'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->FindNearestPoint(*point);
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
 tolua_error(tolua_S,"#ferror in function 'FindNearestPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindNearestPoint of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_FindNearestPoint01
static int tolua_NavigationLuaAPI_NavigationMesh_FindNearestPoint01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* extents = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindNearestPoint'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->FindNearestPoint(*point,*extents);
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
tolua_lerror:
 return tolua_NavigationLuaAPI_NavigationMesh_FindNearestPoint00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: MoveAlongSurface of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_MoveAlongSurface00
static int tolua_NavigationLuaAPI_NavigationMesh_MoveAlongSurface00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* start = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* end = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MoveAlongSurface'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->MoveAlongSurface(*start,*end);
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
 tolua_error(tolua_S,"#ferror in function 'MoveAlongSurface'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MoveAlongSurface of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_MoveAlongSurface01
static int tolua_NavigationLuaAPI_NavigationMesh_MoveAlongSurface01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* start = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* end = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* extents = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  int maxVisited = ((int)  tolua_tonumber(tolua_S,5,3));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MoveAlongSurface'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->MoveAlongSurface(*start,*end,*extents,maxVisited);
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
tolua_lerror:
 return tolua_NavigationLuaAPI_NavigationMesh_MoveAlongSurface00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: NavigationMeshFindPath of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_FindPath00
static int tolua_NavigationLuaAPI_NavigationMesh_FindPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* start = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* end = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NavigationMeshFindPath'", NULL);
#endif
 {
  tolua_outside  const PODVector<Vector3>& tolua_ret = (tolua_outside  const PODVector<Vector3>&)  NavigationMeshFindPath(self,*start,*end);
  ToluaPushPODVector<Vector3>(tolua_S,(void*)&tolua_ret,"Vector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NavigationMeshFindPath of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_FindPath01
static int tolua_NavigationLuaAPI_NavigationMesh_FindPath01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* start = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* end = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* extents = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NavigationMeshFindPath'", NULL);
#endif
 {
  tolua_outside  const PODVector<Vector3>& tolua_ret = (tolua_outside  const PODVector<Vector3>&)  NavigationMeshFindPath(self,*start,*end,*extents);
  ToluaPushPODVector<Vector3>(tolua_S,(void*)&tolua_ret,"Vector3");
 }
 }
 return 1;
tolua_lerror:
 return tolua_NavigationLuaAPI_NavigationMesh_FindPath00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRandomPoint of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetRandomPoint00
static int tolua_NavigationLuaAPI_NavigationMesh_GetRandomPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRandomPoint'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetRandomPoint();
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
 tolua_error(tolua_S,"#ferror in function 'GetRandomPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRandomPointInCircle of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetRandomPointInCircle00
static int tolua_NavigationLuaAPI_NavigationMesh_GetRandomPointInCircle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* center = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float radius = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRandomPointInCircle'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetRandomPointInCircle(*center,radius);
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
 tolua_error(tolua_S,"#ferror in function 'GetRandomPointInCircle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRandomPointInCircle of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetRandomPointInCircle01
static int tolua_NavigationLuaAPI_NavigationMesh_GetRandomPointInCircle01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* center = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float radius = ((float)  tolua_tonumber(tolua_S,3,0));
  const Vector3* extents = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRandomPointInCircle'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetRandomPointInCircle(*center,radius,*extents);
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
tolua_lerror:
 return tolua_NavigationLuaAPI_NavigationMesh_GetRandomPointInCircle00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDistanceToWall of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetDistanceToWall00
static int tolua_NavigationLuaAPI_NavigationMesh_GetDistanceToWall00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float radius = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDistanceToWall'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDistanceToWall(*point,radius);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDistanceToWall'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDistanceToWall of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetDistanceToWall01
static int tolua_NavigationLuaAPI_NavigationMesh_GetDistanceToWall01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float radius = ((float)  tolua_tonumber(tolua_S,3,0));
  const Vector3* extents = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDistanceToWall'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDistanceToWall(*point,radius,*extents);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_NavigationLuaAPI_NavigationMesh_GetDistanceToWall00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Raycast of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_Raycast00
static int tolua_NavigationLuaAPI_NavigationMesh_Raycast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* start = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* end = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Raycast'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Raycast(*start,*end);
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
 tolua_error(tolua_S,"#ferror in function 'Raycast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Raycast of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_Raycast01
static int tolua_NavigationLuaAPI_NavigationMesh_Raycast01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* start = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* end = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* extents = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Raycast'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->Raycast(*start,*end,*extents);
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
tolua_lerror:
 return tolua_NavigationLuaAPI_NavigationMesh_Raycast00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawDebugGeometry of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_DrawDebugGeometry00
static int tolua_NavigationLuaAPI_NavigationMesh_DrawDebugGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetTileSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetTileSize00
static int tolua_NavigationLuaAPI_NavigationMesh_GetTileSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTileSize'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetTileSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTileSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCellSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetCellSize00
static int tolua_NavigationLuaAPI_NavigationMesh_GetCellSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCellSize'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetCellSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCellSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCellHeight of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetCellHeight00
static int tolua_NavigationLuaAPI_NavigationMesh_GetCellHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCellHeight'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetCellHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCellHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAgentHeight of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetAgentHeight00
static int tolua_NavigationLuaAPI_NavigationMesh_GetAgentHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAgentHeight'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAgentHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAgentHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAgentRadius of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetAgentRadius00
static int tolua_NavigationLuaAPI_NavigationMesh_GetAgentRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAgentRadius'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAgentRadius();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAgentRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAgentMaxClimb of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetAgentMaxClimb00
static int tolua_NavigationLuaAPI_NavigationMesh_GetAgentMaxClimb00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAgentMaxClimb'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAgentMaxClimb();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAgentMaxClimb'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAgentMaxSlope of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetAgentMaxSlope00
static int tolua_NavigationLuaAPI_NavigationMesh_GetAgentMaxSlope00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAgentMaxSlope'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAgentMaxSlope();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAgentMaxSlope'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRegionMinSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetRegionMinSize00
static int tolua_NavigationLuaAPI_NavigationMesh_GetRegionMinSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRegionMinSize'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRegionMinSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRegionMinSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRegionMergeSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetRegionMergeSize00
static int tolua_NavigationLuaAPI_NavigationMesh_GetRegionMergeSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRegionMergeSize'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRegionMergeSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRegionMergeSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEdgeMaxLength of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetEdgeMaxLength00
static int tolua_NavigationLuaAPI_NavigationMesh_GetEdgeMaxLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEdgeMaxLength'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetEdgeMaxLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEdgeMaxLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEdgeMaxError of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetEdgeMaxError00
static int tolua_NavigationLuaAPI_NavigationMesh_GetEdgeMaxError00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEdgeMaxError'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetEdgeMaxError();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEdgeMaxError'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDetailSampleDistance of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetDetailSampleDistance00
static int tolua_NavigationLuaAPI_NavigationMesh_GetDetailSampleDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDetailSampleDistance'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDetailSampleDistance();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDetailSampleDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDetailSampleMaxError of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetDetailSampleMaxError00
static int tolua_NavigationLuaAPI_NavigationMesh_GetDetailSampleMaxError00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDetailSampleMaxError'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDetailSampleMaxError();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDetailSampleMaxError'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPadding of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetPadding00
static int tolua_NavigationLuaAPI_NavigationMesh_GetPadding00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPadding'", NULL);
#endif
 {
  const Vector3& tolua_ret = (const Vector3&)  self->GetPadding();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPadding'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAreaCost of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetAreaCost00
static int tolua_NavigationLuaAPI_NavigationMesh_GetAreaCost00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
  unsigned areaID = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAreaCost'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAreaCost(areaID);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAreaCost'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInitialized of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_IsInitialized00
static int tolua_NavigationLuaAPI_NavigationMesh_IsInitialized00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInitialized'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsInitialized();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInitialized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBoundingBox of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetBoundingBox00
static int tolua_NavigationLuaAPI_NavigationMesh_GetBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBoundingBox'", NULL);
#endif
 {
  const BoundingBox& tolua_ret = (const BoundingBox&)  self->GetBoundingBox();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const BoundingBox");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldBoundingBox of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetWorldBoundingBox00
static int tolua_NavigationLuaAPI_NavigationMesh_GetWorldBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetNumTiles of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetNumTiles00
static int tolua_NavigationLuaAPI_NavigationMesh_GetNumTiles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumTiles'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->GetNumTiles();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumTiles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPartitionType of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetPartitionType00
static int tolua_NavigationLuaAPI_NavigationMesh_GetPartitionType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPartitionType'", NULL);
#endif
 {
  NavmeshPartitionType tolua_ret = (NavmeshPartitionType)  self->GetPartitionType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPartitionType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDrawOffMeshConnections of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetDrawOffMeshConnections00
static int tolua_NavigationLuaAPI_NavigationMesh_GetDrawOffMeshConnections00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDrawOffMeshConnections'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetDrawOffMeshConnections();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDrawOffMeshConnections'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDrawNavAreas of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_NavigationMesh_GetDrawNavAreas00
static int tolua_NavigationLuaAPI_NavigationMesh_GetDrawNavAreas00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NavigationMesh",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NavigationMesh* self = (const NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDrawNavAreas'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetDrawNavAreas();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDrawNavAreas'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tileSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_tileSize
static int tolua_get_NavigationMesh_tileSize(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileSize'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTileSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tileSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_tileSize
static int tolua_set_NavigationMesh_tileSize(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileSize'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTileSize(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cellSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_cellSize
static int tolua_get_NavigationMesh_cellSize(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellSize'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetCellSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cellSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_cellSize
static int tolua_set_NavigationMesh_cellSize(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellSize'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCellSize(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cellHeight of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_cellHeight
static int tolua_get_NavigationMesh_cellHeight(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellHeight'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetCellHeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cellHeight of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_cellHeight
static int tolua_set_NavigationMesh_cellHeight(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellHeight'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCellHeight(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: agentHeight of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_agentHeight
static int tolua_get_NavigationMesh_agentHeight(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'agentHeight'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAgentHeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: agentHeight of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_agentHeight
static int tolua_set_NavigationMesh_agentHeight(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'agentHeight'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAgentHeight(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: agentRadius of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_agentRadius
static int tolua_get_NavigationMesh_agentRadius(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'agentRadius'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAgentRadius());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: agentRadius of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_agentRadius
static int tolua_set_NavigationMesh_agentRadius(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'agentRadius'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAgentRadius(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: agentMaxClimb of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_agentMaxClimb
static int tolua_get_NavigationMesh_agentMaxClimb(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'agentMaxClimb'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAgentMaxClimb());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: agentMaxClimb of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_agentMaxClimb
static int tolua_set_NavigationMesh_agentMaxClimb(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'agentMaxClimb'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAgentMaxClimb(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: agentMaxSlope of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_agentMaxSlope
static int tolua_get_NavigationMesh_agentMaxSlope(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'agentMaxSlope'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAgentMaxSlope());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: agentMaxSlope of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_agentMaxSlope
static int tolua_set_NavigationMesh_agentMaxSlope(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'agentMaxSlope'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAgentMaxSlope(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: regionMinSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_regionMinSize
static int tolua_get_NavigationMesh_regionMinSize(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'regionMinSize'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRegionMinSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: regionMinSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_regionMinSize
static int tolua_set_NavigationMesh_regionMinSize(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'regionMinSize'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRegionMinSize(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: regionMergeSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_regionMergeSize
static int tolua_get_NavigationMesh_regionMergeSize(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'regionMergeSize'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRegionMergeSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: regionMergeSize of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_regionMergeSize
static int tolua_set_NavigationMesh_regionMergeSize(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'regionMergeSize'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRegionMergeSize(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: edgeMaxLength of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_edgeMaxLength
static int tolua_get_NavigationMesh_edgeMaxLength(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'edgeMaxLength'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetEdgeMaxLength());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: edgeMaxLength of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_edgeMaxLength
static int tolua_set_NavigationMesh_edgeMaxLength(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'edgeMaxLength'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEdgeMaxLength(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: edgeMaxError of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_edgeMaxError
static int tolua_get_NavigationMesh_edgeMaxError(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'edgeMaxError'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetEdgeMaxError());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: edgeMaxError of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_edgeMaxError
static int tolua_set_NavigationMesh_edgeMaxError(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'edgeMaxError'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEdgeMaxError(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: detailSampleDistance of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_detailSampleDistance
static int tolua_get_NavigationMesh_detailSampleDistance(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'detailSampleDistance'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDetailSampleDistance());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: detailSampleDistance of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_detailSampleDistance
static int tolua_set_NavigationMesh_detailSampleDistance(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'detailSampleDistance'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDetailSampleDistance(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: detailSampleMaxError of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_detailSampleMaxError
static int tolua_get_NavigationMesh_detailSampleMaxError(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'detailSampleMaxError'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDetailSampleMaxError());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: detailSampleMaxError of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_detailSampleMaxError
static int tolua_set_NavigationMesh_detailSampleMaxError(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'detailSampleMaxError'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDetailSampleMaxError(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: padding of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_padding_ref
static int tolua_get_NavigationMesh_padding_ref(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'padding'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetPadding(),"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: padding of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_padding_ref
static int tolua_set_NavigationMesh_padding_ref(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'padding'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPadding((*(Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: partitionType of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_partitionType
static int tolua_get_NavigationMesh_partitionType(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'partitionType'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetPartitionType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: partitionType of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_partitionType
static int tolua_set_NavigationMesh_partitionType(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'partitionType'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPartitionType(((NavmeshPartitionType) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: drawOffMeshConnections of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_drawOffMeshConnections
static int tolua_get_NavigationMesh_drawOffMeshConnections(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawOffMeshConnections'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetDrawOffMeshConnections());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: drawOffMeshConnections of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_drawOffMeshConnections
static int tolua_set_NavigationMesh_drawOffMeshConnections(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawOffMeshConnections'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDrawOffMeshConnections(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: drawNavAreas of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_drawNavAreas
static int tolua_get_NavigationMesh_drawNavAreas(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawNavAreas'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetDrawNavAreas());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: drawNavAreas of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_set_NavigationMesh_drawNavAreas
static int tolua_set_NavigationMesh_drawNavAreas(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawNavAreas'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDrawNavAreas(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: initialized of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_initialized
static int tolua_get_NavigationMesh_initialized(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'initialized'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsInitialized());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: boundingBox of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_boundingBox_ref
static int tolua_get_NavigationMesh_boundingBox_ref(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'boundingBox'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetBoundingBox(),"BoundingBox");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: worldBoundingBox of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_worldBoundingBox
static int tolua_get_NavigationMesh_worldBoundingBox(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: numTiles of class  NavigationMesh */
#ifndef TOLUA_DISABLE_tolua_get_NavigationMesh_numTiles
static int tolua_get_NavigationMesh_numTiles(lua_State* tolua_S)
{
  NavigationMesh* self = (NavigationMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numTiles'",NULL);
#endif
 IntVector2 tolua_ret = (IntVector2)self->GetNumTiles();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((IntVector2)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
 tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawDebugGeometry of class  Obstacle */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_Obstacle_DrawDebugGeometry00
static int tolua_NavigationLuaAPI_Obstacle_DrawDebugGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Obstacle",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Obstacle* self = (Obstacle*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetRadius of class  Obstacle */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_Obstacle_SetRadius00
static int tolua_NavigationLuaAPI_Obstacle_SetRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Obstacle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Obstacle* self = (Obstacle*)  tolua_tousertype(tolua_S,1,0);
  float radius = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRadius'", NULL);
#endif
 {
  self->SetRadius(radius);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHeight of class  Obstacle */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_Obstacle_SetHeight00
static int tolua_NavigationLuaAPI_Obstacle_SetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Obstacle",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Obstacle* self = (Obstacle*)  tolua_tousertype(tolua_S,1,0);
  float height = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHeight'", NULL);
#endif
 {
  self->SetHeight(height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRadius of class  Obstacle */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_Obstacle_GetRadius00
static int tolua_NavigationLuaAPI_Obstacle_GetRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Obstacle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Obstacle* self = (const Obstacle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRadius'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRadius();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeight of class  Obstacle */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_Obstacle_GetHeight00
static int tolua_NavigationLuaAPI_Obstacle_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Obstacle",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Obstacle* self = (const Obstacle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeight'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: radius of class  Obstacle */
#ifndef TOLUA_DISABLE_tolua_get_Obstacle_radius
static int tolua_get_Obstacle_radius(lua_State* tolua_S)
{
  Obstacle* self = (Obstacle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radius'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRadius());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: radius of class  Obstacle */
#ifndef TOLUA_DISABLE_tolua_set_Obstacle_radius
static int tolua_set_Obstacle_radius(lua_State* tolua_S)
{
  Obstacle* self = (Obstacle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radius'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRadius(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  Obstacle */
#ifndef TOLUA_DISABLE_tolua_get_Obstacle_height
static int tolua_get_Obstacle_height(lua_State* tolua_S)
{
  Obstacle* self = (Obstacle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetHeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  Obstacle */
#ifndef TOLUA_DISABLE_tolua_set_Obstacle_height
static int tolua_set_Obstacle_height(lua_State* tolua_S)
{
  Obstacle* self = (Obstacle*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetHeight(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEndPoint of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_OffMeshConnection_SetEndPoint00
static int tolua_NavigationLuaAPI_OffMeshConnection_SetEndPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"OffMeshConnection",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  OffMeshConnection* self = (OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEndPoint'", NULL);
#endif
 {
  self->SetEndPoint(node);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEndPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRadius of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_OffMeshConnection_SetRadius00
static int tolua_NavigationLuaAPI_OffMeshConnection_SetRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"OffMeshConnection",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  OffMeshConnection* self = (OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
  float radius = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRadius'", NULL);
#endif
 {
  self->SetRadius(radius);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBidirectional of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_OffMeshConnection_SetBidirectional00
static int tolua_NavigationLuaAPI_OffMeshConnection_SetBidirectional00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"OffMeshConnection",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  OffMeshConnection* self = (OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBidirectional'", NULL);
#endif
 {
  self->SetBidirectional(enabled);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBidirectional'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMask of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_OffMeshConnection_SetMask00
static int tolua_NavigationLuaAPI_OffMeshConnection_SetMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"OffMeshConnection",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  OffMeshConnection* self = (OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
  unsigned newMask = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMask'", NULL);
#endif
 {
  self->SetMask(newMask);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAreaID of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_OffMeshConnection_SetAreaID00
static int tolua_NavigationLuaAPI_OffMeshConnection_SetAreaID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"OffMeshConnection",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  OffMeshConnection* self = (OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
  unsigned newAreaID = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAreaID'", NULL);
#endif
 {
  self->SetAreaID(newAreaID);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAreaID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEndPoint of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_OffMeshConnection_GetEndPoint00
static int tolua_NavigationLuaAPI_OffMeshConnection_GetEndPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const OffMeshConnection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const OffMeshConnection* self = (const OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEndPoint'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->GetEndPoint();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEndPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRadius of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_OffMeshConnection_GetRadius00
static int tolua_NavigationLuaAPI_OffMeshConnection_GetRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const OffMeshConnection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const OffMeshConnection* self = (const OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRadius'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRadius();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsBidirectional of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_OffMeshConnection_IsBidirectional00
static int tolua_NavigationLuaAPI_OffMeshConnection_IsBidirectional00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const OffMeshConnection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const OffMeshConnection* self = (const OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsBidirectional'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsBidirectional();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsBidirectional'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMask of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_OffMeshConnection_GetMask00
static int tolua_NavigationLuaAPI_OffMeshConnection_GetMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const OffMeshConnection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const OffMeshConnection* self = (const OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMask'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetMask();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAreaID of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_NavigationLuaAPI_OffMeshConnection_GetAreaID00
static int tolua_NavigationLuaAPI_OffMeshConnection_GetAreaID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const OffMeshConnection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const OffMeshConnection* self = (const OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAreaID'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetAreaID();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAreaID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: endPoint of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_get_OffMeshConnection_endPoint_ptr
static int tolua_get_OffMeshConnection_endPoint_ptr(lua_State* tolua_S)
{
  OffMeshConnection* self = (OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endPoint'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetEndPoint(),"Node");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: endPoint of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_set_OffMeshConnection_endPoint_ptr
static int tolua_set_OffMeshConnection_endPoint_ptr(lua_State* tolua_S)
{
  OffMeshConnection* self = (OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endPoint'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Node",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEndPoint(((Node*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: radius of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_get_OffMeshConnection_radius
static int tolua_get_OffMeshConnection_radius(lua_State* tolua_S)
{
  OffMeshConnection* self = (OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radius'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRadius());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: radius of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_set_OffMeshConnection_radius
static int tolua_set_OffMeshConnection_radius(lua_State* tolua_S)
{
  OffMeshConnection* self = (OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radius'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRadius(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bidirectional of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_get_OffMeshConnection_bidirectional
static int tolua_get_OffMeshConnection_bidirectional(lua_State* tolua_S)
{
  OffMeshConnection* self = (OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bidirectional'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsBidirectional());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bidirectional of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_set_OffMeshConnection_bidirectional
static int tolua_set_OffMeshConnection_bidirectional(lua_State* tolua_S)
{
  OffMeshConnection* self = (OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bidirectional'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetBidirectional(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mask of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_get_OffMeshConnection_mask
static int tolua_get_OffMeshConnection_mask(lua_State* tolua_S)
{
  OffMeshConnection* self = (OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mask'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMask());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mask of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_set_OffMeshConnection_mask
static int tolua_set_OffMeshConnection_mask(lua_State* tolua_S)
{
  OffMeshConnection* self = (OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mask'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMask(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: areaID of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_get_OffMeshConnection_areaID
static int tolua_get_OffMeshConnection_areaID(lua_State* tolua_S)
{
  OffMeshConnection* self = (OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'areaID'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAreaID());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: areaID of class  OffMeshConnection */
#ifndef TOLUA_DISABLE_tolua_set_OffMeshConnection_areaID
static int tolua_set_OffMeshConnection_areaID(lua_State* tolua_S)
{
  OffMeshConnection* self = (OffMeshConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'areaID'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAreaID(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_NavigationLuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_constant(tolua_S,"CA_REQUESTEDTARGET_NONE",CA_REQUESTEDTARGET_NONE);
 tolua_constant(tolua_S,"CA_REQUESTEDTARGET_POSITION",CA_REQUESTEDTARGET_POSITION);
 tolua_constant(tolua_S,"CA_REQUESTEDTARGET_VELOCITY",CA_REQUESTEDTARGET_VELOCITY);
 tolua_constant(tolua_S,"CA_TARGET_NONE",CA_TARGET_NONE);
 tolua_constant(tolua_S,"CA_TARGET_FAILED",CA_TARGET_FAILED);
 tolua_constant(tolua_S,"CA_TARGET_VALID",CA_TARGET_VALID);
 tolua_constant(tolua_S,"CA_TARGET_REQUESTING",CA_TARGET_REQUESTING);
 tolua_constant(tolua_S,"CA_TARGET_WAITINGFORQUEUE",CA_TARGET_WAITINGFORQUEUE);
 tolua_constant(tolua_S,"CA_TARGET_WAITINGFORPATH",CA_TARGET_WAITINGFORPATH);
 tolua_constant(tolua_S,"CA_TARGET_VELOCITY",CA_TARGET_VELOCITY);
 tolua_constant(tolua_S,"CA_STATE_INVALID",CA_STATE_INVALID);
 tolua_constant(tolua_S,"CA_STATE_WALKING",CA_STATE_WALKING);
 tolua_constant(tolua_S,"CA_STATE_OFFMESH",CA_STATE_OFFMESH);
 tolua_constant(tolua_S,"NAVIGATIONQUALITY_LOW",NAVIGATIONQUALITY_LOW);
 tolua_constant(tolua_S,"NAVIGATIONQUALITY_MEDIUM",NAVIGATIONQUALITY_MEDIUM);
 tolua_constant(tolua_S,"NAVIGATIONQUALITY_HIGH",NAVIGATIONQUALITY_HIGH);
 tolua_constant(tolua_S,"NAVIGATIONPUSHINESS_LOW",NAVIGATIONPUSHINESS_LOW);
 tolua_constant(tolua_S,"NAVIGATIONPUSHINESS_MEDIUM",NAVIGATIONPUSHINESS_MEDIUM);
 tolua_constant(tolua_S,"NAVIGATIONPUSHINESS_HIGH",NAVIGATIONPUSHINESS_HIGH);
 tolua_constant(tolua_S,"NAVIGATIONPUSHINESS_NONE",NAVIGATIONPUSHINESS_NONE);
 tolua_cclass(tolua_S,"CrowdAgent","CrowdAgent","Component",NULL);
 tolua_beginmodule(tolua_S,"CrowdAgent");
  tolua_function(tolua_S,"DrawDebugGeometry",tolua_NavigationLuaAPI_CrowdAgent_DrawDebugGeometry00);
  tolua_function(tolua_S,"SetTargetPosition",tolua_NavigationLuaAPI_CrowdAgent_SetTargetPosition00);
  tolua_function(tolua_S,"SetTargetVelocity",tolua_NavigationLuaAPI_CrowdAgent_SetTargetVelocity00);
  tolua_function(tolua_S,"ResetTarget",tolua_NavigationLuaAPI_CrowdAgent_ResetTarget00);
  tolua_function(tolua_S,"SetUpdateNodePosition",tolua_NavigationLuaAPI_CrowdAgent_SetUpdateNodePosition00);
  tolua_function(tolua_S,"SetMaxAccel",tolua_NavigationLuaAPI_CrowdAgent_SetMaxAccel00);
  tolua_function(tolua_S,"SetMaxSpeed",tolua_NavigationLuaAPI_CrowdAgent_SetMaxSpeed00);
  tolua_function(tolua_S,"SetRadius",tolua_NavigationLuaAPI_CrowdAgent_SetRadius00);
  tolua_function(tolua_S,"SetHeight",tolua_NavigationLuaAPI_CrowdAgent_SetHeight00);
  tolua_function(tolua_S,"SetQueryFilterType",tolua_NavigationLuaAPI_CrowdAgent_SetQueryFilterType00);
  tolua_function(tolua_S,"SetObstacleAvoidanceType",tolua_NavigationLuaAPI_CrowdAgent_SetObstacleAvoidanceType00);
  tolua_function(tolua_S,"SetNavigationQuality",tolua_NavigationLuaAPI_CrowdAgent_SetNavigationQuality00);
  tolua_function(tolua_S,"SetNavigationPushiness",tolua_NavigationLuaAPI_CrowdAgent_SetNavigationPushiness00);
  tolua_function(tolua_S,"GetPosition",tolua_NavigationLuaAPI_CrowdAgent_GetPosition00);
  tolua_function(tolua_S,"GetDesiredVelocity",tolua_NavigationLuaAPI_CrowdAgent_GetDesiredVelocity00);
  tolua_function(tolua_S,"GetActualVelocity",tolua_NavigationLuaAPI_CrowdAgent_GetActualVelocity00);
  tolua_function(tolua_S,"GetTargetPosition",tolua_NavigationLuaAPI_CrowdAgent_GetTargetPosition00);
  tolua_function(tolua_S,"GetTargetVelocity",tolua_NavigationLuaAPI_CrowdAgent_GetTargetVelocity00);
  tolua_function(tolua_S,"GetRequestedTargetType",tolua_NavigationLuaAPI_CrowdAgent_GetRequestedTargetType00);
  tolua_function(tolua_S,"GetAgentState",tolua_NavigationLuaAPI_CrowdAgent_GetAgentState00);
  tolua_function(tolua_S,"GetTargetState",tolua_NavigationLuaAPI_CrowdAgent_GetTargetState00);
  tolua_function(tolua_S,"GetUpdateNodePosition",tolua_NavigationLuaAPI_CrowdAgent_GetUpdateNodePosition00);
  tolua_function(tolua_S,"GetMaxAccel",tolua_NavigationLuaAPI_CrowdAgent_GetMaxAccel00);
  tolua_function(tolua_S,"GetMaxSpeed",tolua_NavigationLuaAPI_CrowdAgent_GetMaxSpeed00);
  tolua_function(tolua_S,"GetRadius",tolua_NavigationLuaAPI_CrowdAgent_GetRadius00);
  tolua_function(tolua_S,"GetHeight",tolua_NavigationLuaAPI_CrowdAgent_GetHeight00);
  tolua_function(tolua_S,"GetQueryFilterType",tolua_NavigationLuaAPI_CrowdAgent_GetQueryFilterType00);
  tolua_function(tolua_S,"GetObstacleAvoidanceType",tolua_NavigationLuaAPI_CrowdAgent_GetObstacleAvoidanceType00);
  tolua_function(tolua_S,"GetNavigationQuality",tolua_NavigationLuaAPI_CrowdAgent_GetNavigationQuality00);
  tolua_function(tolua_S,"GetNavigationPushiness",tolua_NavigationLuaAPI_CrowdAgent_GetNavigationPushiness00);
  tolua_function(tolua_S,"HasRequestedTarget",tolua_NavigationLuaAPI_CrowdAgent_HasRequestedTarget00);
  tolua_function(tolua_S,"HasArrived",tolua_NavigationLuaAPI_CrowdAgent_HasArrived00);
  tolua_function(tolua_S,"IsInCrowd",tolua_NavigationLuaAPI_CrowdAgent_IsInCrowd00);
  tolua_variable(tolua_S,"targetPosition",tolua_get_CrowdAgent_targetPosition,tolua_set_CrowdAgent_targetPosition);
  tolua_variable(tolua_S,"targetVelocity",tolua_get_CrowdAgent_targetVelocity,tolua_set_CrowdAgent_targetVelocity);
  tolua_variable(tolua_S,"updateNodePosition",tolua_get_CrowdAgent_updateNodePosition,tolua_set_CrowdAgent_updateNodePosition);
  tolua_variable(tolua_S,"maxAccel",tolua_get_CrowdAgent_maxAccel,tolua_set_CrowdAgent_maxAccel);
  tolua_variable(tolua_S,"maxSpeed",tolua_get_CrowdAgent_maxSpeed,tolua_set_CrowdAgent_maxSpeed);
  tolua_variable(tolua_S,"radius",tolua_get_CrowdAgent_radius,tolua_set_CrowdAgent_radius);
  tolua_variable(tolua_S,"height",tolua_get_CrowdAgent_height,tolua_set_CrowdAgent_height);
  tolua_variable(tolua_S,"queryFilterType",tolua_get_CrowdAgent_queryFilterType,tolua_set_CrowdAgent_queryFilterType);
  tolua_variable(tolua_S,"obstacleAvoidanceType",tolua_get_CrowdAgent_obstacleAvoidanceType,tolua_set_CrowdAgent_obstacleAvoidanceType);
  tolua_variable(tolua_S,"navigationQuality",tolua_get_CrowdAgent_navigationQuality,tolua_set_CrowdAgent_navigationQuality);
  tolua_variable(tolua_S,"navigationPushiness",tolua_get_CrowdAgent_navigationPushiness,tolua_set_CrowdAgent_navigationPushiness);
  tolua_variable(tolua_S,"position",tolua_get_CrowdAgent_position,NULL);
  tolua_variable(tolua_S,"desiredVelocity",tolua_get_CrowdAgent_desiredVelocity,NULL);
  tolua_variable(tolua_S,"actualVelocity",tolua_get_CrowdAgent_actualVelocity,NULL);
  tolua_variable(tolua_S,"requestedTargetType",tolua_get_CrowdAgent_requestedTargetType,NULL);
  tolua_variable(tolua_S,"agentState",tolua_get_CrowdAgent_agentState,NULL);
  tolua_variable(tolua_S,"targetState",tolua_get_CrowdAgent_targetState,NULL);
  tolua_variable(tolua_S,"requestedTarget",tolua_get_CrowdAgent_requestedTarget,NULL);
  tolua_variable(tolua_S,"arrived",tolua_get_CrowdAgent_arrived,NULL);
  tolua_variable(tolua_S,"inCrowd",tolua_get_CrowdAgent_inCrowd,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"CrowdManager","CrowdManager","Component",NULL);
 tolua_beginmodule(tolua_S,"CrowdManager");
  tolua_function(tolua_S,"DrawDebugGeometry",tolua_NavigationLuaAPI_CrowdManager_DrawDebugGeometry00);
  tolua_function(tolua_S,"SetCrowdTarget",tolua_NavigationLuaAPI_CrowdManager_SetCrowdTarget00);
  tolua_function(tolua_S,"SetCrowdVelocity",tolua_NavigationLuaAPI_CrowdManager_SetCrowdVelocity00);
  tolua_function(tolua_S,"ResetCrowdTarget",tolua_NavigationLuaAPI_CrowdManager_ResetCrowdTarget00);
  tolua_function(tolua_S,"SetMaxAgents",tolua_NavigationLuaAPI_CrowdManager_SetMaxAgents00);
  tolua_function(tolua_S,"SetMaxAgentRadius",tolua_NavigationLuaAPI_CrowdManager_SetMaxAgentRadius00);
  tolua_function(tolua_S,"SetNavigationMesh",tolua_NavigationLuaAPI_CrowdManager_SetNavigationMesh00);
  tolua_function(tolua_S,"SetIncludeFlags",tolua_NavigationLuaAPI_CrowdManager_SetIncludeFlags00);
  tolua_function(tolua_S,"SetExcludeFlags",tolua_NavigationLuaAPI_CrowdManager_SetExcludeFlags00);
  tolua_function(tolua_S,"SetAreaCost",tolua_NavigationLuaAPI_CrowdManager_SetAreaCost00);
  tolua_function(tolua_S,"SetObstacleAvoidanceParams",tolua_NavigationLuaAPI_CrowdManager_SetObstacleAvoidanceParams00);
  tolua_function(tolua_S,"GetAgents",tolua_NavigationLuaAPI_CrowdManager_GetAgents00);
  tolua_function(tolua_S,"FindNearestPoint",tolua_NavigationLuaAPI_CrowdManager_FindNearestPoint00);
  tolua_function(tolua_S,"MoveAlongSurface",tolua_NavigationLuaAPI_CrowdManager_MoveAlongSurface00);
  tolua_function(tolua_S,"FindPath",tolua_NavigationLuaAPI_CrowdManager_FindPath00);
  tolua_function(tolua_S,"GetRandomPoint",tolua_NavigationLuaAPI_CrowdManager_GetRandomPoint00);
  tolua_function(tolua_S,"GetRandomPointInCircle",tolua_NavigationLuaAPI_CrowdManager_GetRandomPointInCircle00);
  tolua_function(tolua_S,"GetDistanceToWall",tolua_NavigationLuaAPI_CrowdManager_GetDistanceToWall00);
  tolua_function(tolua_S,"Raycast",tolua_NavigationLuaAPI_CrowdManager_Raycast00);
  tolua_function(tolua_S,"GetMaxAgents",tolua_NavigationLuaAPI_CrowdManager_GetMaxAgents00);
  tolua_function(tolua_S,"GetMaxAgentRadius",tolua_NavigationLuaAPI_CrowdManager_GetMaxAgentRadius00);
  tolua_function(tolua_S,"GetNavigationMesh",tolua_NavigationLuaAPI_CrowdManager_GetNavigationMesh00);
  tolua_function(tolua_S,"GetNumQueryFilterTypes",tolua_NavigationLuaAPI_CrowdManager_GetNumQueryFilterTypes00);
  tolua_function(tolua_S,"GetNumAreas",tolua_NavigationLuaAPI_CrowdManager_GetNumAreas00);
  tolua_function(tolua_S,"GetIncludeFlags",tolua_NavigationLuaAPI_CrowdManager_GetIncludeFlags00);
  tolua_function(tolua_S,"GetExcludeFlags",tolua_NavigationLuaAPI_CrowdManager_GetExcludeFlags00);
  tolua_function(tolua_S,"GetAreaCost",tolua_NavigationLuaAPI_CrowdManager_GetAreaCost00);
  tolua_function(tolua_S,"GetNumObstacleAvoidanceTypes",tolua_NavigationLuaAPI_CrowdManager_GetNumObstacleAvoidanceTypes00);
  tolua_function(tolua_S,"GetObstacleAvoidanceParams",tolua_NavigationLuaAPI_CrowdManager_GetObstacleAvoidanceParams00);
  tolua_variable(tolua_S,"maxAgents",tolua_get_CrowdManager_maxAgents,tolua_set_CrowdManager_maxAgents);
  tolua_variable(tolua_S,"maxAgentRadius",tolua_get_CrowdManager_maxAgentRadius,tolua_set_CrowdManager_maxAgentRadius);
  tolua_variable(tolua_S,"navigationMesh",tolua_get_CrowdManager_navigationMesh_ptr,tolua_set_CrowdManager_navigationMesh_ptr);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"DynamicNavigationMesh","DynamicNavigationMesh","NavigationMesh",NULL);
 tolua_beginmodule(tolua_S,"DynamicNavigationMesh");
  tolua_function(tolua_S,"SetDrawObstacles",tolua_NavigationLuaAPI_DynamicNavigationMesh_SetDrawObstacles00);
  tolua_function(tolua_S,"SetMaxLayers",tolua_NavigationLuaAPI_DynamicNavigationMesh_SetMaxLayers00);
  tolua_function(tolua_S,"SetMaxObstacles",tolua_NavigationLuaAPI_DynamicNavigationMesh_SetMaxObstacles00);
  tolua_function(tolua_S,"GetDrawObstacles",tolua_NavigationLuaAPI_DynamicNavigationMesh_GetDrawObstacles00);
  tolua_function(tolua_S,"GetMaxLayers",tolua_NavigationLuaAPI_DynamicNavigationMesh_GetMaxLayers00);
  tolua_function(tolua_S,"GetMaxObstacles",tolua_NavigationLuaAPI_DynamicNavigationMesh_GetMaxObstacles00);
  tolua_variable(tolua_S,"drawObstacles",tolua_get_DynamicNavigationMesh_drawObstacles,tolua_set_DynamicNavigationMesh_drawObstacles);
  tolua_variable(tolua_S,"maxObstacles",tolua_get_DynamicNavigationMesh_maxObstacles,tolua_set_DynamicNavigationMesh_maxObstacles);
  tolua_variable(tolua_S,"maxLayers",tolua_get_DynamicNavigationMesh_maxLayers,tolua_set_DynamicNavigationMesh_maxLayers);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"NavArea","NavArea","Component",NULL);
 tolua_beginmodule(tolua_S,"NavArea");
  tolua_function(tolua_S,"GetAreaID",tolua_NavigationLuaAPI_NavArea_GetAreaID00);
  tolua_function(tolua_S,"SetAreaID",tolua_NavigationLuaAPI_NavArea_SetAreaID00);
  tolua_function(tolua_S,"GetBoundingBox",tolua_NavigationLuaAPI_NavArea_GetBoundingBox00);
  tolua_function(tolua_S,"SetBoundingBox",tolua_NavigationLuaAPI_NavArea_SetBoundingBox00);
  tolua_function(tolua_S,"GetWorldBoundingBox",tolua_NavigationLuaAPI_NavArea_GetWorldBoundingBox00);
  tolua_variable(tolua_S,"areaID",tolua_get_NavArea_areaID,tolua_set_NavArea_areaID);
  tolua_variable(tolua_S,"boundingBox",tolua_get_NavArea_boundingBox,tolua_set_NavArea_boundingBox);
  tolua_variable(tolua_S,"worldBoundingBox",tolua_get_NavArea_worldBoundingBox,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Navigable","Navigable","Component",NULL);
 tolua_beginmodule(tolua_S,"Navigable");
  tolua_function(tolua_S,"SetRecursive",tolua_NavigationLuaAPI_Navigable_SetRecursive00);
  tolua_function(tolua_S,"IsRecursive",tolua_NavigationLuaAPI_Navigable_IsRecursive00);
  tolua_variable(tolua_S,"recursive",tolua_get_Navigable_recursive,tolua_set_Navigable_recursive);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"NAVMESH_PARTITION_WATERSHED",NAVMESH_PARTITION_WATERSHED);
 tolua_constant(tolua_S,"NAVMESH_PARTITION_MONOTONE",NAVMESH_PARTITION_MONOTONE);
 tolua_cclass(tolua_S,"NavigationGeometryInfo","NavigationGeometryInfo","",NULL);
 tolua_beginmodule(tolua_S,"NavigationGeometryInfo");
  tolua_variable(tolua_S,"component",tolua_get_NavigationGeometryInfo_component_ptr,tolua_set_NavigationGeometryInfo_component_ptr);
  tolua_variable(tolua_S,"lodLevel",tolua_get_NavigationGeometryInfo_lodLevel,tolua_set_NavigationGeometryInfo_lodLevel);
  tolua_variable(tolua_S,"transform",tolua_get_NavigationGeometryInfo_transform,tolua_set_NavigationGeometryInfo_transform);
  tolua_variable(tolua_S,"boundingBox",tolua_get_NavigationGeometryInfo_boundingBox,tolua_set_NavigationGeometryInfo_boundingBox);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"NavigationMesh","NavigationMesh","Component",NULL);
 tolua_beginmodule(tolua_S,"NavigationMesh");
  tolua_function(tolua_S,"SetTileSize",tolua_NavigationLuaAPI_NavigationMesh_SetTileSize00);
  tolua_function(tolua_S,"SetCellSize",tolua_NavigationLuaAPI_NavigationMesh_SetCellSize00);
  tolua_function(tolua_S,"SetCellHeight",tolua_NavigationLuaAPI_NavigationMesh_SetCellHeight00);
  tolua_function(tolua_S,"SetAgentHeight",tolua_NavigationLuaAPI_NavigationMesh_SetAgentHeight00);
  tolua_function(tolua_S,"SetAgentRadius",tolua_NavigationLuaAPI_NavigationMesh_SetAgentRadius00);
  tolua_function(tolua_S,"SetAgentMaxClimb",tolua_NavigationLuaAPI_NavigationMesh_SetAgentMaxClimb00);
  tolua_function(tolua_S,"SetAgentMaxSlope",tolua_NavigationLuaAPI_NavigationMesh_SetAgentMaxSlope00);
  tolua_function(tolua_S,"SetRegionMinSize",tolua_NavigationLuaAPI_NavigationMesh_SetRegionMinSize00);
  tolua_function(tolua_S,"SetRegionMergeSize",tolua_NavigationLuaAPI_NavigationMesh_SetRegionMergeSize00);
  tolua_function(tolua_S,"SetEdgeMaxLength",tolua_NavigationLuaAPI_NavigationMesh_SetEdgeMaxLength00);
  tolua_function(tolua_S,"SetEdgeMaxError",tolua_NavigationLuaAPI_NavigationMesh_SetEdgeMaxError00);
  tolua_function(tolua_S,"SetDetailSampleDistance",tolua_NavigationLuaAPI_NavigationMesh_SetDetailSampleDistance00);
  tolua_function(tolua_S,"SetDetailSampleMaxError",tolua_NavigationLuaAPI_NavigationMesh_SetDetailSampleMaxError00);
  tolua_function(tolua_S,"SetPadding",tolua_NavigationLuaAPI_NavigationMesh_SetPadding00);
  tolua_function(tolua_S,"SetAreaCost",tolua_NavigationLuaAPI_NavigationMesh_SetAreaCost00);
  tolua_function(tolua_S,"Allocate",tolua_NavigationLuaAPI_NavigationMesh_Allocate00);
  tolua_function(tolua_S,"Build",tolua_NavigationLuaAPI_NavigationMesh_Build00);
  tolua_function(tolua_S,"Build",tolua_NavigationLuaAPI_NavigationMesh_Build01);
  tolua_function(tolua_S,"Build",tolua_NavigationLuaAPI_NavigationMesh_Build02);
  tolua_function(tolua_S,"GetTileData",tolua_NavigationLuaAPI_NavigationMesh_GetTileData00);
  tolua_function(tolua_S,"AddTile",tolua_NavigationLuaAPI_NavigationMesh_AddTile00);
  tolua_function(tolua_S,"RemoveTile",tolua_NavigationLuaAPI_NavigationMesh_RemoveTile00);
  tolua_function(tolua_S,"RemoveAllTiles",tolua_NavigationLuaAPI_NavigationMesh_RemoveAllTiles00);
  tolua_function(tolua_S,"HasTile",tolua_NavigationLuaAPI_NavigationMesh_HasTile00);
  tolua_function(tolua_S,"GetTileBoudningBox",tolua_NavigationLuaAPI_NavigationMesh_GetTileBoudningBox00);
  tolua_function(tolua_S,"GetTileIndex",tolua_NavigationLuaAPI_NavigationMesh_GetTileIndex00);
  tolua_function(tolua_S,"SetPartitionType",tolua_NavigationLuaAPI_NavigationMesh_SetPartitionType00);
  tolua_function(tolua_S,"SetDrawOffMeshConnections",tolua_NavigationLuaAPI_NavigationMesh_SetDrawOffMeshConnections00);
  tolua_function(tolua_S,"SetDrawNavAreas",tolua_NavigationLuaAPI_NavigationMesh_SetDrawNavAreas00);
  tolua_function(tolua_S,"FindNearestPoint",tolua_NavigationLuaAPI_NavigationMesh_FindNearestPoint00);
  tolua_function(tolua_S,"FindNearestPoint",tolua_NavigationLuaAPI_NavigationMesh_FindNearestPoint01);
  tolua_function(tolua_S,"MoveAlongSurface",tolua_NavigationLuaAPI_NavigationMesh_MoveAlongSurface00);
  tolua_function(tolua_S,"MoveAlongSurface",tolua_NavigationLuaAPI_NavigationMesh_MoveAlongSurface01);
  tolua_function(tolua_S,"FindPath",tolua_NavigationLuaAPI_NavigationMesh_FindPath00);
  tolua_function(tolua_S,"FindPath",tolua_NavigationLuaAPI_NavigationMesh_FindPath01);
  tolua_function(tolua_S,"GetRandomPoint",tolua_NavigationLuaAPI_NavigationMesh_GetRandomPoint00);
  tolua_function(tolua_S,"GetRandomPointInCircle",tolua_NavigationLuaAPI_NavigationMesh_GetRandomPointInCircle00);
  tolua_function(tolua_S,"GetRandomPointInCircle",tolua_NavigationLuaAPI_NavigationMesh_GetRandomPointInCircle01);
  tolua_function(tolua_S,"GetDistanceToWall",tolua_NavigationLuaAPI_NavigationMesh_GetDistanceToWall00);
  tolua_function(tolua_S,"GetDistanceToWall",tolua_NavigationLuaAPI_NavigationMesh_GetDistanceToWall01);
  tolua_function(tolua_S,"Raycast",tolua_NavigationLuaAPI_NavigationMesh_Raycast00);
  tolua_function(tolua_S,"Raycast",tolua_NavigationLuaAPI_NavigationMesh_Raycast01);
  tolua_function(tolua_S,"DrawDebugGeometry",tolua_NavigationLuaAPI_NavigationMesh_DrawDebugGeometry00);
  tolua_function(tolua_S,"GetTileSize",tolua_NavigationLuaAPI_NavigationMesh_GetTileSize00);
  tolua_function(tolua_S,"GetCellSize",tolua_NavigationLuaAPI_NavigationMesh_GetCellSize00);
  tolua_function(tolua_S,"GetCellHeight",tolua_NavigationLuaAPI_NavigationMesh_GetCellHeight00);
  tolua_function(tolua_S,"GetAgentHeight",tolua_NavigationLuaAPI_NavigationMesh_GetAgentHeight00);
  tolua_function(tolua_S,"GetAgentRadius",tolua_NavigationLuaAPI_NavigationMesh_GetAgentRadius00);
  tolua_function(tolua_S,"GetAgentMaxClimb",tolua_NavigationLuaAPI_NavigationMesh_GetAgentMaxClimb00);
  tolua_function(tolua_S,"GetAgentMaxSlope",tolua_NavigationLuaAPI_NavigationMesh_GetAgentMaxSlope00);
  tolua_function(tolua_S,"GetRegionMinSize",tolua_NavigationLuaAPI_NavigationMesh_GetRegionMinSize00);
  tolua_function(tolua_S,"GetRegionMergeSize",tolua_NavigationLuaAPI_NavigationMesh_GetRegionMergeSize00);
  tolua_function(tolua_S,"GetEdgeMaxLength",tolua_NavigationLuaAPI_NavigationMesh_GetEdgeMaxLength00);
  tolua_function(tolua_S,"GetEdgeMaxError",tolua_NavigationLuaAPI_NavigationMesh_GetEdgeMaxError00);
  tolua_function(tolua_S,"GetDetailSampleDistance",tolua_NavigationLuaAPI_NavigationMesh_GetDetailSampleDistance00);
  tolua_function(tolua_S,"GetDetailSampleMaxError",tolua_NavigationLuaAPI_NavigationMesh_GetDetailSampleMaxError00);
  tolua_function(tolua_S,"GetPadding",tolua_NavigationLuaAPI_NavigationMesh_GetPadding00);
  tolua_function(tolua_S,"GetAreaCost",tolua_NavigationLuaAPI_NavigationMesh_GetAreaCost00);
  tolua_function(tolua_S,"IsInitialized",tolua_NavigationLuaAPI_NavigationMesh_IsInitialized00);
  tolua_function(tolua_S,"GetBoundingBox",tolua_NavigationLuaAPI_NavigationMesh_GetBoundingBox00);
  tolua_function(tolua_S,"GetWorldBoundingBox",tolua_NavigationLuaAPI_NavigationMesh_GetWorldBoundingBox00);
  tolua_function(tolua_S,"GetNumTiles",tolua_NavigationLuaAPI_NavigationMesh_GetNumTiles00);
  tolua_function(tolua_S,"GetPartitionType",tolua_NavigationLuaAPI_NavigationMesh_GetPartitionType00);
  tolua_function(tolua_S,"GetDrawOffMeshConnections",tolua_NavigationLuaAPI_NavigationMesh_GetDrawOffMeshConnections00);
  tolua_function(tolua_S,"GetDrawNavAreas",tolua_NavigationLuaAPI_NavigationMesh_GetDrawNavAreas00);
  tolua_variable(tolua_S,"tileSize",tolua_get_NavigationMesh_tileSize,tolua_set_NavigationMesh_tileSize);
  tolua_variable(tolua_S,"cellSize",tolua_get_NavigationMesh_cellSize,tolua_set_NavigationMesh_cellSize);
  tolua_variable(tolua_S,"cellHeight",tolua_get_NavigationMesh_cellHeight,tolua_set_NavigationMesh_cellHeight);
  tolua_variable(tolua_S,"agentHeight",tolua_get_NavigationMesh_agentHeight,tolua_set_NavigationMesh_agentHeight);
  tolua_variable(tolua_S,"agentRadius",tolua_get_NavigationMesh_agentRadius,tolua_set_NavigationMesh_agentRadius);
  tolua_variable(tolua_S,"agentMaxClimb",tolua_get_NavigationMesh_agentMaxClimb,tolua_set_NavigationMesh_agentMaxClimb);
  tolua_variable(tolua_S,"agentMaxSlope",tolua_get_NavigationMesh_agentMaxSlope,tolua_set_NavigationMesh_agentMaxSlope);
  tolua_variable(tolua_S,"regionMinSize",tolua_get_NavigationMesh_regionMinSize,tolua_set_NavigationMesh_regionMinSize);
  tolua_variable(tolua_S,"regionMergeSize",tolua_get_NavigationMesh_regionMergeSize,tolua_set_NavigationMesh_regionMergeSize);
  tolua_variable(tolua_S,"edgeMaxLength",tolua_get_NavigationMesh_edgeMaxLength,tolua_set_NavigationMesh_edgeMaxLength);
  tolua_variable(tolua_S,"edgeMaxError",tolua_get_NavigationMesh_edgeMaxError,tolua_set_NavigationMesh_edgeMaxError);
  tolua_variable(tolua_S,"detailSampleDistance",tolua_get_NavigationMesh_detailSampleDistance,tolua_set_NavigationMesh_detailSampleDistance);
  tolua_variable(tolua_S,"detailSampleMaxError",tolua_get_NavigationMesh_detailSampleMaxError,tolua_set_NavigationMesh_detailSampleMaxError);
  tolua_variable(tolua_S,"padding",tolua_get_NavigationMesh_padding_ref,tolua_set_NavigationMesh_padding_ref);
  tolua_variable(tolua_S,"partitionType",tolua_get_NavigationMesh_partitionType,tolua_set_NavigationMesh_partitionType);
  tolua_variable(tolua_S,"drawOffMeshConnections",tolua_get_NavigationMesh_drawOffMeshConnections,tolua_set_NavigationMesh_drawOffMeshConnections);
  tolua_variable(tolua_S,"drawNavAreas",tolua_get_NavigationMesh_drawNavAreas,tolua_set_NavigationMesh_drawNavAreas);
  tolua_variable(tolua_S,"initialized",tolua_get_NavigationMesh_initialized,NULL);
  tolua_variable(tolua_S,"boundingBox",tolua_get_NavigationMesh_boundingBox_ref,NULL);
  tolua_variable(tolua_S,"worldBoundingBox",tolua_get_NavigationMesh_worldBoundingBox,NULL);
  tolua_variable(tolua_S,"numTiles",tolua_get_NavigationMesh_numTiles,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Obstacle","Obstacle","Component",NULL);
 tolua_beginmodule(tolua_S,"Obstacle");
  tolua_function(tolua_S,"DrawDebugGeometry",tolua_NavigationLuaAPI_Obstacle_DrawDebugGeometry00);
  tolua_function(tolua_S,"SetRadius",tolua_NavigationLuaAPI_Obstacle_SetRadius00);
  tolua_function(tolua_S,"SetHeight",tolua_NavigationLuaAPI_Obstacle_SetHeight00);
  tolua_function(tolua_S,"GetRadius",tolua_NavigationLuaAPI_Obstacle_GetRadius00);
  tolua_function(tolua_S,"GetHeight",tolua_NavigationLuaAPI_Obstacle_GetHeight00);
  tolua_variable(tolua_S,"radius",tolua_get_Obstacle_radius,tolua_set_Obstacle_radius);
  tolua_variable(tolua_S,"height",tolua_get_Obstacle_height,tolua_set_Obstacle_height);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"OffMeshConnection","OffMeshConnection","Component",NULL);
 tolua_beginmodule(tolua_S,"OffMeshConnection");
  tolua_function(tolua_S,"SetEndPoint",tolua_NavigationLuaAPI_OffMeshConnection_SetEndPoint00);
  tolua_function(tolua_S,"SetRadius",tolua_NavigationLuaAPI_OffMeshConnection_SetRadius00);
  tolua_function(tolua_S,"SetBidirectional",tolua_NavigationLuaAPI_OffMeshConnection_SetBidirectional00);
  tolua_function(tolua_S,"SetMask",tolua_NavigationLuaAPI_OffMeshConnection_SetMask00);
  tolua_function(tolua_S,"SetAreaID",tolua_NavigationLuaAPI_OffMeshConnection_SetAreaID00);
  tolua_function(tolua_S,"GetEndPoint",tolua_NavigationLuaAPI_OffMeshConnection_GetEndPoint00);
  tolua_function(tolua_S,"GetRadius",tolua_NavigationLuaAPI_OffMeshConnection_GetRadius00);
  tolua_function(tolua_S,"IsBidirectional",tolua_NavigationLuaAPI_OffMeshConnection_IsBidirectional00);
  tolua_function(tolua_S,"GetMask",tolua_NavigationLuaAPI_OffMeshConnection_GetMask00);
  tolua_function(tolua_S,"GetAreaID",tolua_NavigationLuaAPI_OffMeshConnection_GetAreaID00);
  tolua_variable(tolua_S,"endPoint",tolua_get_OffMeshConnection_endPoint_ptr,tolua_set_OffMeshConnection_endPoint_ptr);
  tolua_variable(tolua_S,"radius",tolua_get_OffMeshConnection_radius,tolua_set_OffMeshConnection_radius);
  tolua_variable(tolua_S,"bidirectional",tolua_get_OffMeshConnection_bidirectional,tolua_set_OffMeshConnection_bidirectional);
  tolua_variable(tolua_S,"mask",tolua_get_OffMeshConnection_mask,tolua_set_OffMeshConnection_mask);
  tolua_variable(tolua_S,"areaID",tolua_get_OffMeshConnection_areaID,tolua_set_OffMeshConnection_areaID);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_NavigationLuaAPI (lua_State* tolua_S) {
 return tolua_NavigationLuaAPI_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif