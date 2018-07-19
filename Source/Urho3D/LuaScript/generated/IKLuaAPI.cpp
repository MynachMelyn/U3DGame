/*
** Lua binding: IKLuaAPI
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
TOLUA_API int tolua_IKLuaAPI_open (lua_State* tolua_S);

#include "IK/IKSolver.h"
#include "IK/IKConstraint.h"
#include "IK/IKEffector.h"
using namespace Urho3D;
#pragma warning(disable:4800)

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"Quaternion");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"IKEffector");
 tolua_usertype(tolua_S,"IKSolver");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"IKConstraint");
}

/* method: RebuildChainTrees of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKSolver_RebuildChainTrees00
static int tolua_IKLuaAPI_IKSolver_RebuildChainTrees00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKSolver",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RebuildChainTrees'", NULL);
#endif
 {
  self->RebuildChainTrees();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RebuildChainTrees'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RecalculateSegmentLengths of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKSolver_RecalculateSegmentLengths00
static int tolua_IKLuaAPI_IKSolver_RecalculateSegmentLengths00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKSolver",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RecalculateSegmentLengths'", NULL);
#endif
 {
  self->RecalculateSegmentLengths();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RecalculateSegmentLengths'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CalculateJointRotations of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKSolver_CalculateJointRotations00
static int tolua_IKLuaAPI_IKSolver_CalculateJointRotations00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKSolver",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CalculateJointRotations'", NULL);
#endif
 {
  self->CalculateJointRotations();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CalculateJointRotations'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Solve of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKSolver_Solve00
static int tolua_IKLuaAPI_IKSolver_Solve00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKSolver",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Solve'", NULL);
#endif
 {
  self->Solve();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Solve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyOriginalPoseToScene of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKSolver_ApplyOriginalPoseToScene00
static int tolua_IKLuaAPI_IKSolver_ApplyOriginalPoseToScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKSolver",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyOriginalPoseToScene'", NULL);
#endif
 {
  self->ApplyOriginalPoseToScene();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyOriginalPoseToScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplySceneToOriginalPose of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKSolver_ApplySceneToOriginalPose00
static int tolua_IKLuaAPI_IKSolver_ApplySceneToOriginalPose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKSolver",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplySceneToOriginalPose'", NULL);
#endif
 {
  self->ApplySceneToOriginalPose();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplySceneToOriginalPose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyActivePoseToScene of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKSolver_ApplyActivePoseToScene00
static int tolua_IKLuaAPI_IKSolver_ApplyActivePoseToScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKSolver",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyActivePoseToScene'", NULL);
#endif
 {
  self->ApplyActivePoseToScene();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyActivePoseToScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplySceneToActivePose of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKSolver_ApplySceneToActivePose00
static int tolua_IKLuaAPI_IKSolver_ApplySceneToActivePose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKSolver",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplySceneToActivePose'", NULL);
#endif
 {
  self->ApplySceneToActivePose();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplySceneToActivePose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyOriginalPoseToActivePose of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKSolver_ApplyOriginalPoseToActivePose00
static int tolua_IKLuaAPI_IKSolver_ApplyOriginalPoseToActivePose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKSolver",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyOriginalPoseToActivePose'", NULL);
#endif
 {
  self->ApplyOriginalPoseToActivePose();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyOriginalPoseToActivePose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawDebugGeometry of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKSolver_DrawDebugGeometry00
static int tolua_IKLuaAPI_IKSolver_DrawDebugGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKSolver",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: algorithm of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_get_IKSolver_algorithm
static int tolua_get_IKSolver_algorithm(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'algorithm'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAlgorithm());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: algorithm of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_set_IKSolver_algorithm
static int tolua_set_IKSolver_algorithm(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'algorithm'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAlgorithm(((IKSolver::Algorithm) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maximumIterations of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_get_IKSolver_maximumIterations
static int tolua_get_IKSolver_maximumIterations(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maximumIterations'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaximumIterations());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maximumIterations of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_set_IKSolver_maximumIterations
static int tolua_set_IKSolver_maximumIterations(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maximumIterations'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaximumIterations(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tolerance of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_get_IKSolver_tolerance
static int tolua_get_IKSolver_tolerance(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tolerance'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTolerance());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tolerance of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_set_IKSolver_tolerance
static int tolua_set_IKSolver_tolerance(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tolerance'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTolerance(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: JOINT_ROTATIONS of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_get_IKSolver_JOINT_ROTATIONS
static int tolua_get_IKSolver_JOINT_ROTATIONS(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'JOINT_ROTATIONS'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetJOINT_ROTATIONS());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: JOINT_ROTATIONS of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_set_IKSolver_JOINT_ROTATIONS
static int tolua_set_IKSolver_JOINT_ROTATIONS(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'JOINT_ROTATIONS'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetJOINT_ROTATIONS(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: TARGET_ROTATIONS of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_get_IKSolver_TARGET_ROTATIONS
static int tolua_get_IKSolver_TARGET_ROTATIONS(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TARGET_ROTATIONS'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetTARGET_ROTATIONS());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: TARGET_ROTATIONS of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_set_IKSolver_TARGET_ROTATIONS
static int tolua_set_IKSolver_TARGET_ROTATIONS(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TARGET_ROTATIONS'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTARGET_ROTATIONS(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UPDATE_ORIGINAL_POSE of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_get_IKSolver_UPDATE_ORIGINAL_POSE
static int tolua_get_IKSolver_UPDATE_ORIGINAL_POSE(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'UPDATE_ORIGINAL_POSE'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetUPDATE_ORIGINAL_POSE());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: UPDATE_ORIGINAL_POSE of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_set_IKSolver_UPDATE_ORIGINAL_POSE
static int tolua_set_IKSolver_UPDATE_ORIGINAL_POSE(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'UPDATE_ORIGINAL_POSE'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUPDATE_ORIGINAL_POSE(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UPDATE_ACTIVE_POSE of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_get_IKSolver_UPDATE_ACTIVE_POSE
static int tolua_get_IKSolver_UPDATE_ACTIVE_POSE(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'UPDATE_ACTIVE_POSE'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetUPDATE_ACTIVE_POSE());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: UPDATE_ACTIVE_POSE of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_set_IKSolver_UPDATE_ACTIVE_POSE
static int tolua_set_IKSolver_UPDATE_ACTIVE_POSE(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'UPDATE_ACTIVE_POSE'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUPDATE_ACTIVE_POSE(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: USE_ORIGINAL_POSE of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_get_IKSolver_USE_ORIGINAL_POSE
static int tolua_get_IKSolver_USE_ORIGINAL_POSE(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'USE_ORIGINAL_POSE'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetUSE_ORIGINAL_POSE());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: USE_ORIGINAL_POSE of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_set_IKSolver_USE_ORIGINAL_POSE
static int tolua_set_IKSolver_USE_ORIGINAL_POSE(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'USE_ORIGINAL_POSE'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUSE_ORIGINAL_POSE(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONSTRAINTS of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_get_IKSolver_CONSTRAINTS
static int tolua_get_IKSolver_CONSTRAINTS(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CONSTRAINTS'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetCONSTRAINTS());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: CONSTRAINTS of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_set_IKSolver_CONSTRAINTS
static int tolua_set_IKSolver_CONSTRAINTS(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CONSTRAINTS'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCONSTRAINTS(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: AUTO_SOLVE of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_get_IKSolver_AUTO_SOLVE
static int tolua_get_IKSolver_AUTO_SOLVE(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AUTO_SOLVE'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetAUTO_SOLVE());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: AUTO_SOLVE of class  IKSolver */
#ifndef TOLUA_DISABLE_tolua_set_IKSolver_AUTO_SOLVE
static int tolua_set_IKSolver_AUTO_SOLVE(lua_State* tolua_S)
{
  IKSolver* self = (IKSolver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AUTO_SOLVE'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAUTO_SOLVE(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStiffness of class  IKConstraint */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKConstraint_GetStiffness00
static int tolua_IKLuaAPI_IKConstraint_GetStiffness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IKConstraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IKConstraint* self = (const IKConstraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStiffness'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetStiffness();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStiffness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetStiffness of class  IKConstraint */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKConstraint_SetStiffness00
static int tolua_IKLuaAPI_IKConstraint_SetStiffness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKConstraint",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKConstraint* self = (IKConstraint*)  tolua_tousertype(tolua_S,1,0);
  float stiffness = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetStiffness'", NULL);
#endif
 {
  self->SetStiffness(stiffness);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetStiffness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStretchiness of class  IKConstraint */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKConstraint_GetStretchiness00
static int tolua_IKLuaAPI_IKConstraint_GetStretchiness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IKConstraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IKConstraint* self = (const IKConstraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStretchiness'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetStretchiness();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStretchiness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetStretchiness of class  IKConstraint */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKConstraint_SetStretchiness00
static int tolua_IKLuaAPI_IKConstraint_SetStretchiness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKConstraint",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKConstraint* self = (IKConstraint*)  tolua_tousertype(tolua_S,1,0);
  float stretchiness = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetStretchiness'", NULL);
#endif
 {
  self->SetStretchiness(stretchiness);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetStretchiness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLengthConstraints of class  IKConstraint */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKConstraint_GetLengthConstraints00
static int tolua_IKLuaAPI_IKConstraint_GetLengthConstraints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IKConstraint",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IKConstraint* self = (const IKConstraint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLengthConstraints'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetLengthConstraints();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLengthConstraints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLengthConstraints of class  IKConstraint */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKConstraint_SetLengthConstraints00
static int tolua_IKLuaAPI_IKConstraint_SetLengthConstraints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKConstraint",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKConstraint* self = (IKConstraint*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* lengthConstraints = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLengthConstraints'", NULL);
#endif
 {
  self->SetLengthConstraints(*lengthConstraints);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLengthConstraints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTargetNode of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_GetTargetNode00
static int tolua_IKLuaAPI_IKEffector_GetTargetNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IKEffector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IKEffector* self = (const IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTargetNode'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->GetTargetNode();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTargetNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTargetNode of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_SetTargetNode00
static int tolua_IKLuaAPI_IKEffector_SetTargetNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKEffector",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
  Node* targetNode = ((Node*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTargetNode'", NULL);
#endif
 {
  self->SetTargetNode(targetNode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTargetNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTargetName of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_GetTargetName00
static int tolua_IKLuaAPI_IKEffector_GetTargetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IKEffector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IKEffector* self = (const IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTargetName'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetTargetName();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTargetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTargetName of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_SetTargetName00
static int tolua_IKLuaAPI_IKEffector_SetTargetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKEffector",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
  const String nodeName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTargetName'", NULL);
#endif
 {
  self->SetTargetName(nodeName);
 tolua_pushurho3dstring(tolua_S,(const char*)nodeName);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTargetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTargetPosition of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_GetTargetPosition00
static int tolua_IKLuaAPI_IKEffector_GetTargetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IKEffector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IKEffector* self = (const IKEffector*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetTargetPosition of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_SetTargetPosition00
static int tolua_IKLuaAPI_IKEffector_SetTargetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKEffector",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* targetPosition = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTargetPosition'", NULL);
#endif
 {
  self->SetTargetPosition(*targetPosition);
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

/* method: GetTargetRotation of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_GetTargetRotation00
static int tolua_IKLuaAPI_IKEffector_GetTargetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IKEffector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IKEffector* self = (const IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTargetRotation'", NULL);
#endif
 {
  const Quaternion& tolua_ret = (const Quaternion&)  self->GetTargetRotation();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Quaternion");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTargetRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTargetRotation of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_SetTargetRotation00
static int tolua_IKLuaAPI_IKEffector_SetTargetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKEffector",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* targetRotation = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTargetRotation'", NULL);
#endif
 {
  self->SetTargetRotation(*targetRotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTargetRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetChainLength of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_GetChainLength00
static int tolua_IKLuaAPI_IKEffector_GetChainLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IKEffector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IKEffector* self = (const IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChainLength'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetChainLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetChainLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetChainLength of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_SetChainLength00
static int tolua_IKLuaAPI_IKEffector_SetChainLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKEffector",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
  unsigned chainLength = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetChainLength'", NULL);
#endif
 {
  self->SetChainLength(chainLength);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetChainLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWeight of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_GetWeight00
static int tolua_IKLuaAPI_IKEffector_GetWeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IKEffector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IKEffector* self = (const IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWeight'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetWeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWeight of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_SetWeight00
static int tolua_IKLuaAPI_IKEffector_SetWeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKEffector",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
  float weight = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWeight'", NULL);
#endif
 {
  self->SetWeight(weight);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRotationWeight of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_GetRotationWeight00
static int tolua_IKLuaAPI_IKEffector_GetRotationWeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IKEffector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IKEffector* self = (const IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRotationWeight'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRotationWeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRotationWeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRotationWeight of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_SetRotationWeight00
static int tolua_IKLuaAPI_IKEffector_SetRotationWeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKEffector",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
  float weight = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRotationWeight'", NULL);
#endif
 {
  self->SetRotationWeight(weight);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRotationWeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRotationDecay of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_GetRotationDecay00
static int tolua_IKLuaAPI_IKEffector_GetRotationDecay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const IKEffector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const IKEffector* self = (const IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRotationDecay'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRotationDecay();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRotationDecay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRotationDecay of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_IKLuaAPI_IKEffector_SetRotationDecay00
static int tolua_IKLuaAPI_IKEffector_SetRotationDecay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"IKEffector",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
  float decay = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRotationDecay'", NULL);
#endif
 {
  self->SetRotationDecay(decay);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRotationDecay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: targetNode of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_get_IKEffector_targetNode_ptr
static int tolua_get_IKEffector_targetNode_ptr(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'targetNode'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetTargetNode(),"Node");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: targetNode of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_set_IKEffector_targetNode_ptr
static int tolua_set_IKEffector_targetNode_ptr(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'targetNode'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Node",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTargetNode(((Node*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: targetName of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_get_IKEffector_targetName
static int tolua_get_IKEffector_targetName(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'targetName'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetTargetName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: targetName of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_set_IKEffector_targetName
static int tolua_set_IKEffector_targetName(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'targetName'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTargetName(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: targetPosition of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_get_IKEffector_targetPosition
static int tolua_get_IKEffector_targetPosition(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
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

/* set function: targetPosition of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_set_IKEffector_targetPosition
static int tolua_set_IKEffector_targetPosition(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: targetRotation of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_get_IKEffector_targetRotation
static int tolua_get_IKEffector_targetRotation(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'targetRotation'",NULL);
#endif
 Quaternion tolua_ret = (Quaternion)self->GetTargetRotation();
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

/* set function: targetRotation of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_set_IKEffector_targetRotation
static int tolua_set_IKEffector_targetRotation(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'targetRotation'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTargetRotation(*((Quaternion*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: chainLength of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_get_IKEffector_chainLength
static int tolua_get_IKEffector_chainLength(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'chainLength'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetChainLength());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: chainLength of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_set_IKEffector_chainLength
static int tolua_set_IKEffector_chainLength(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'chainLength'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetChainLength(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: weight of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_get_IKEffector_weight
static int tolua_get_IKEffector_weight(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'weight'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetWeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: weight of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_set_IKEffector_weight
static int tolua_set_IKEffector_weight(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'weight'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetWeight(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rotationWeight of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_get_IKEffector_rotationWeight
static int tolua_get_IKEffector_rotationWeight(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotationWeight'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRotationWeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rotationWeight of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_set_IKEffector_rotationWeight
static int tolua_set_IKEffector_rotationWeight(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotationWeight'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRotationWeight(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rotationDecay of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_get_IKEffector_rotationDecay
static int tolua_get_IKEffector_rotationDecay(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotationDecay'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRotationDecay());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rotationDecay of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_set_IKEffector_rotationDecay
static int tolua_set_IKEffector_rotationDecay(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotationDecay'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRotationDecay(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WEIGHT_NLERP of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_get_IKEffector_WEIGHT_NLERP
static int tolua_get_IKEffector_WEIGHT_NLERP(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WEIGHT_NLERP'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetWEIGHT_NLERP());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WEIGHT_NLERP of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_set_IKEffector_WEIGHT_NLERP
static int tolua_set_IKEffector_WEIGHT_NLERP(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WEIGHT_NLERP'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetWEIGHT_NLERP(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: INHERIT_PARENT_ROTATION of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_get_IKEffector_INHERIT_PARENT_ROTATION
static int tolua_get_IKEffector_INHERIT_PARENT_ROTATION(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'INHERIT_PARENT_ROTATION'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetINHERIT_PARENT_ROTATION());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: INHERIT_PARENT_ROTATION of class  IKEffector */
#ifndef TOLUA_DISABLE_tolua_set_IKEffector_INHERIT_PARENT_ROTATION
static int tolua_set_IKEffector_INHERIT_PARENT_ROTATION(lua_State* tolua_S)
{
  IKEffector* self = (IKEffector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'INHERIT_PARENT_ROTATION'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetINHERIT_PARENT_ROTATION(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_IKLuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"IKSolver","IKSolver","Component",NULL);
 tolua_beginmodule(tolua_S,"IKSolver");
  tolua_constant(tolua_S,"ONE_BONE",IKSolver::ONE_BONE);
  tolua_constant(tolua_S,"TWO_BONE",IKSolver::TWO_BONE);
  tolua_constant(tolua_S,"FABRIK",IKSolver::FABRIK);
  tolua_constant(tolua_S,"JOINT_ROTATIONS",IKSolver::JOINT_ROTATIONS);
  tolua_constant(tolua_S,"TARGET_ROTATIONS",IKSolver::TARGET_ROTATIONS);
  tolua_constant(tolua_S,"UPDATE_ORIGINAL_POSE",IKSolver::UPDATE_ORIGINAL_POSE);
  tolua_constant(tolua_S,"UPDATE_ACTIVE_POSE",IKSolver::UPDATE_ACTIVE_POSE);
  tolua_constant(tolua_S,"USE_ORIGINAL_POSE",IKSolver::USE_ORIGINAL_POSE);
  tolua_constant(tolua_S,"CONSTRAINTS",IKSolver::CONSTRAINTS);
  tolua_constant(tolua_S,"AUTO_SOLVE",IKSolver::AUTO_SOLVE);
  tolua_function(tolua_S,"RebuildChainTrees",tolua_IKLuaAPI_IKSolver_RebuildChainTrees00);
  tolua_function(tolua_S,"RecalculateSegmentLengths",tolua_IKLuaAPI_IKSolver_RecalculateSegmentLengths00);
  tolua_function(tolua_S,"CalculateJointRotations",tolua_IKLuaAPI_IKSolver_CalculateJointRotations00);
  tolua_function(tolua_S,"Solve",tolua_IKLuaAPI_IKSolver_Solve00);
  tolua_function(tolua_S,"ApplyOriginalPoseToScene",tolua_IKLuaAPI_IKSolver_ApplyOriginalPoseToScene00);
  tolua_function(tolua_S,"ApplySceneToOriginalPose",tolua_IKLuaAPI_IKSolver_ApplySceneToOriginalPose00);
  tolua_function(tolua_S,"ApplyActivePoseToScene",tolua_IKLuaAPI_IKSolver_ApplyActivePoseToScene00);
  tolua_function(tolua_S,"ApplySceneToActivePose",tolua_IKLuaAPI_IKSolver_ApplySceneToActivePose00);
  tolua_function(tolua_S,"ApplyOriginalPoseToActivePose",tolua_IKLuaAPI_IKSolver_ApplyOriginalPoseToActivePose00);
  tolua_function(tolua_S,"DrawDebugGeometry",tolua_IKLuaAPI_IKSolver_DrawDebugGeometry00);
  tolua_variable(tolua_S,"algorithm",tolua_get_IKSolver_algorithm,tolua_set_IKSolver_algorithm);
  tolua_variable(tolua_S,"maximumIterations",tolua_get_IKSolver_maximumIterations,tolua_set_IKSolver_maximumIterations);
  tolua_variable(tolua_S,"tolerance",tolua_get_IKSolver_tolerance,tolua_set_IKSolver_tolerance);
  tolua_variable(tolua_S,"JOINT_ROTATIONS",tolua_get_IKSolver_JOINT_ROTATIONS,tolua_set_IKSolver_JOINT_ROTATIONS);
  tolua_variable(tolua_S,"TARGET_ROTATIONS",tolua_get_IKSolver_TARGET_ROTATIONS,tolua_set_IKSolver_TARGET_ROTATIONS);
  tolua_variable(tolua_S,"UPDATE_ORIGINAL_POSE",tolua_get_IKSolver_UPDATE_ORIGINAL_POSE,tolua_set_IKSolver_UPDATE_ORIGINAL_POSE);
  tolua_variable(tolua_S,"UPDATE_ACTIVE_POSE",tolua_get_IKSolver_UPDATE_ACTIVE_POSE,tolua_set_IKSolver_UPDATE_ACTIVE_POSE);
  tolua_variable(tolua_S,"USE_ORIGINAL_POSE",tolua_get_IKSolver_USE_ORIGINAL_POSE,tolua_set_IKSolver_USE_ORIGINAL_POSE);
  tolua_variable(tolua_S,"CONSTRAINTS",tolua_get_IKSolver_CONSTRAINTS,tolua_set_IKSolver_CONSTRAINTS);
  tolua_variable(tolua_S,"AUTO_SOLVE",tolua_get_IKSolver_AUTO_SOLVE,tolua_set_IKSolver_AUTO_SOLVE);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"IKConstraint","IKConstraint","Component",NULL);
 tolua_beginmodule(tolua_S,"IKConstraint");
  tolua_function(tolua_S,"GetStiffness",tolua_IKLuaAPI_IKConstraint_GetStiffness00);
  tolua_function(tolua_S,"SetStiffness",tolua_IKLuaAPI_IKConstraint_SetStiffness00);
  tolua_function(tolua_S,"GetStretchiness",tolua_IKLuaAPI_IKConstraint_GetStretchiness00);
  tolua_function(tolua_S,"SetStretchiness",tolua_IKLuaAPI_IKConstraint_SetStretchiness00);
  tolua_function(tolua_S,"GetLengthConstraints",tolua_IKLuaAPI_IKConstraint_GetLengthConstraints00);
  tolua_function(tolua_S,"SetLengthConstraints",tolua_IKLuaAPI_IKConstraint_SetLengthConstraints00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"IKEffector","IKEffector","Component",NULL);
 tolua_beginmodule(tolua_S,"IKEffector");
  tolua_constant(tolua_S,"WEIGHT_NLERP",IKEffector::WEIGHT_NLERP);
  tolua_constant(tolua_S,"INHERIT_PARENT_ROTATION",IKEffector::INHERIT_PARENT_ROTATION);
  tolua_function(tolua_S,"GetTargetNode",tolua_IKLuaAPI_IKEffector_GetTargetNode00);
  tolua_function(tolua_S,"SetTargetNode",tolua_IKLuaAPI_IKEffector_SetTargetNode00);
  tolua_function(tolua_S,"GetTargetName",tolua_IKLuaAPI_IKEffector_GetTargetName00);
  tolua_function(tolua_S,"SetTargetName",tolua_IKLuaAPI_IKEffector_SetTargetName00);
  tolua_function(tolua_S,"GetTargetPosition",tolua_IKLuaAPI_IKEffector_GetTargetPosition00);
  tolua_function(tolua_S,"SetTargetPosition",tolua_IKLuaAPI_IKEffector_SetTargetPosition00);
  tolua_function(tolua_S,"GetTargetRotation",tolua_IKLuaAPI_IKEffector_GetTargetRotation00);
  tolua_function(tolua_S,"SetTargetRotation",tolua_IKLuaAPI_IKEffector_SetTargetRotation00);
  tolua_function(tolua_S,"GetChainLength",tolua_IKLuaAPI_IKEffector_GetChainLength00);
  tolua_function(tolua_S,"SetChainLength",tolua_IKLuaAPI_IKEffector_SetChainLength00);
  tolua_function(tolua_S,"GetWeight",tolua_IKLuaAPI_IKEffector_GetWeight00);
  tolua_function(tolua_S,"SetWeight",tolua_IKLuaAPI_IKEffector_SetWeight00);
  tolua_function(tolua_S,"GetRotationWeight",tolua_IKLuaAPI_IKEffector_GetRotationWeight00);
  tolua_function(tolua_S,"SetRotationWeight",tolua_IKLuaAPI_IKEffector_SetRotationWeight00);
  tolua_function(tolua_S,"GetRotationDecay",tolua_IKLuaAPI_IKEffector_GetRotationDecay00);
  tolua_function(tolua_S,"SetRotationDecay",tolua_IKLuaAPI_IKEffector_SetRotationDecay00);
  tolua_variable(tolua_S,"targetNode",tolua_get_IKEffector_targetNode_ptr,tolua_set_IKEffector_targetNode_ptr);
  tolua_variable(tolua_S,"targetName",tolua_get_IKEffector_targetName,tolua_set_IKEffector_targetName);
  tolua_variable(tolua_S,"targetPosition",tolua_get_IKEffector_targetPosition,tolua_set_IKEffector_targetPosition);
  tolua_variable(tolua_S,"targetRotation",tolua_get_IKEffector_targetRotation,tolua_set_IKEffector_targetRotation);
  tolua_variable(tolua_S,"chainLength",tolua_get_IKEffector_chainLength,tolua_set_IKEffector_chainLength);
  tolua_variable(tolua_S,"weight",tolua_get_IKEffector_weight,tolua_set_IKEffector_weight);
  tolua_variable(tolua_S,"rotationWeight",tolua_get_IKEffector_rotationWeight,tolua_set_IKEffector_rotationWeight);
  tolua_variable(tolua_S,"rotationDecay",tolua_get_IKEffector_rotationDecay,tolua_set_IKEffector_rotationDecay);
  tolua_variable(tolua_S,"WEIGHT_NLERP",tolua_get_IKEffector_WEIGHT_NLERP,tolua_set_IKEffector_WEIGHT_NLERP);
  tolua_variable(tolua_S,"INHERIT_PARENT_ROTATION",tolua_get_IKEffector_INHERIT_PARENT_ROTATION,tolua_set_IKEffector_INHERIT_PARENT_ROTATION);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_IKLuaAPI (lua_State* tolua_S) {
 return tolua_IKLuaAPI_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif