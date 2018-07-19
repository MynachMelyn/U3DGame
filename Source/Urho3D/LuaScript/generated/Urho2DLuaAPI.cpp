/*
** Lua binding: Urho2DLuaAPI
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
TOLUA_API int tolua_Urho2DLuaAPI_open (lua_State* tolua_S);

#include "Urho2D/Sprite2D.h"
#include "Urho2D/SpriteSheet2D.h"
#include "Urho2D/Drawable2D.h"
#include "Urho2D/StaticSprite2D.h"
#include "Urho2D/StretchableSprite2D.h"
#include "Urho2D/AnimationSet2D.h"
#include "Urho2D/AnimatedSprite2D.h"
#include "Urho2D/ParticleEffect2D.h"
#include "Urho2D/ParticleEmitter2D.h"
#include "Urho2D/TileMapDefs2D.h"
#include "Urho2D/TmxFile2D.h"
#include "Urho2D/TileMap2D.h"
#include "Urho2D/TileMapLayer2D.h"
#include "Urho2D/RigidBody2D.h"
#include "Urho2D/PhysicsWorld2D.h"
#include "Urho2D/CollisionShape2D.h"
#include "Urho2D/CollisionBox2D.h"
#include "Urho2D/CollisionChain2D.h"
#include "Urho2D/CollisionCircle2D.h"
#include "Urho2D/CollisionEdge2D.h"
#include "Urho2D/CollisionPolygon2D.h"
#include "Urho2D/Constraint2D.h"
#include "Urho2D/ConstraintDistance2D.h"
#include "Urho2D/ConstraintFriction2D.h"
#include "Urho2D/ConstraintGear2D.h"
#include "Urho2D/ConstraintMotor2D.h"
#include "Urho2D/ConstraintMouse2D.h"
#include "Urho2D/ConstraintPrismatic2D.h"
#include "Urho2D/ConstraintPulley2D.h"
#include "Urho2D/ConstraintRevolute2D.h"
#include "Urho2D/ConstraintRope2D.h"
#include "Urho2D/ConstraintWeld2D.h"
#include "Urho2D/ConstraintWheel2D.h"
using namespace Urho3D;
#pragma warning(disable:4800)

static ParticleEffect2D* ParticleEffect2DClone(const ParticleEffect2D* effect, const String& cloneName = String::EMPTY)
{
    if (!effect)
        return 0;

    return effect->Clone(cloneName).Detach();
}

static bool TileMap2DPositionToTileIndex(const TileMap2D* tileMap, const Vector2& position, int* x, int* y)
{
    return tileMap->PositionToTileIndex(*x, *y, position);
}

const PODVector<PhysicsRaycastResult2D>& PhysicsWorld2DRaycast(PhysicsWorld2D* physicsWorld, const Vector2& startPoint, const Vector2& endPoint, unsigned collisionMask = M_MAX_UNSIGNED)
{
    static PODVector<PhysicsRaycastResult2D> results;
    results.Clear();
    physicsWorld->Raycast(results, startPoint, endPoint, collisionMask);
    return results;
}

PhysicsRaycastResult2D PhysicsWorld2DRaycastSingle(PhysicsWorld2D* physicsWorld, const Vector2& startPoint, const Vector2& endPoint, unsigned collisionMask = M_MAX_UNSIGNED)
{
    PhysicsRaycastResult2D result;
    physicsWorld->RaycastSingle(result, startPoint, endPoint, collisionMask);
    return result;
}

const PODVector<RigidBody2D*>& PhysicsWorld2DGetRigidBodies(PhysicsWorld2D* physicsWorld, const Rect& aabb, unsigned collisionMask = M_MAX_UNSIGNED)
{
    static PODVector<RigidBody2D*> results;
    results.Clear();
    physicsWorld->GetRigidBodies(results, aabb, collisionMask);
    return results;
}

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_PhysicsRaycastResult2D (lua_State* tolua_S)
{
 PhysicsRaycastResult2D* self = (PhysicsRaycastResult2D*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Vector2 (lua_State* tolua_S)
{
 Vector2* self = (Vector2*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Tile2D");
 tolua_usertype(tolua_S,"CollisionCircle2D");
 tolua_usertype(tolua_S,"ConstraintGear2D");
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"TileMapObject2D");
 tolua_usertype(tolua_S,"ConstraintRevolute2D");
 tolua_usertype(tolua_S,"IntRect");
 tolua_usertype(tolua_S,"StretchableSprite2D");
 tolua_usertype(tolua_S,"ConstraintWheel2D");
 tolua_usertype(tolua_S,"AnimationSet2D");
 tolua_usertype(tolua_S,"RigidBody2D");
 tolua_usertype(tolua_S,"ConstraintFriction2D");
 tolua_usertype(tolua_S,"Sprite2D");
 tolua_usertype(tolua_S,"PhysicsRaycastResult2D");
 tolua_usertype(tolua_S,"ConstraintPrismatic2D");
 tolua_usertype(tolua_S,"CollisionBox2D");
 tolua_usertype(tolua_S,"ConstraintMotor2D");
 tolua_usertype(tolua_S,"TileMap2D");
 tolua_usertype(tolua_S,"IntVector2");
 tolua_usertype(tolua_S,"PropertySet2D");
 tolua_usertype(tolua_S,"ConstraintMouse2D");
 tolua_usertype(tolua_S,"Resource");
 tolua_usertype(tolua_S,"ConstraintRope2D");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"ConstraintDistance2D");
 tolua_usertype(tolua_S,"CollisionPolygon2D");
 tolua_usertype(tolua_S,"Constraint2D");
 tolua_usertype(tolua_S,"CollisionEdge2D");
 tolua_usertype(tolua_S,"Drawable2D");
 tolua_usertype(tolua_S,"Drawable");
 tolua_usertype(tolua_S,"TileMapInfo2D");
 tolua_usertype(tolua_S,"PODVector<Vector2>");
 tolua_usertype(tolua_S,"Material");
 tolua_usertype(tolua_S,"CollisionChain2D");
 tolua_usertype(tolua_S,"ParticleEffect2D");
 tolua_usertype(tolua_S,"PODVector<RigidBody2D*>");
 tolua_usertype(tolua_S,"PODVector<PhysicsRaycastResult2D>");
 tolua_usertype(tolua_S,"SpriteSheet2D");
 tolua_usertype(tolua_S,"PhysicsWorld2D");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"ParticleEmitter2D");
 tolua_usertype(tolua_S,"AnimatedSprite2D");
 tolua_usertype(tolua_S,"ConstraintWeld2D");
 tolua_usertype(tolua_S,"TmxFile2D");
 tolua_usertype(tolua_S,"Rect");
 tolua_usertype(tolua_S,"TileMapLayer2D");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"StaticSprite2D");
 tolua_usertype(tolua_S,"Texture2D");
 tolua_usertype(tolua_S,"CollisionShape2D");
 tolua_usertype(tolua_S,"ConstraintPulley2D");
}

/* method: SetTexture of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Sprite2D_SetTexture00
static int tolua_Urho2DLuaAPI_Sprite2D_SetTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Texture2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  Texture2D* texture = ((Texture2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTexture'", NULL);
#endif
 {
  self->SetTexture(texture);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRectangle of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Sprite2D_SetRectangle00
static int tolua_Urho2DLuaAPI_Sprite2D_SetRectangle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* rectangle = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRectangle'", NULL);
#endif
 {
  self->SetRectangle(*rectangle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRectangle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHotSpot of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Sprite2D_SetHotSpot00
static int tolua_Urho2DLuaAPI_Sprite2D_SetHotSpot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* hotSpot = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHotSpot'", NULL);
#endif
 {
  self->SetHotSpot(*hotSpot);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHotSpot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOffset of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Sprite2D_SetOffset00
static int tolua_Urho2DLuaAPI_Sprite2D_SetOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* offset = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOffset'", NULL);
#endif
 {
  self->SetOffset(*offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextureEdgeOffset of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Sprite2D_SetTextureEdgeOffset00
static int tolua_Urho2DLuaAPI_Sprite2D_SetTextureEdgeOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  float offset = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextureEdgeOffset'", NULL);
#endif
 {
  self->SetTextureEdgeOffset(offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextureEdgeOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSpriteSheet of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Sprite2D_SetSpriteSheet00
static int tolua_Urho2DLuaAPI_Sprite2D_SetSpriteSheet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite2D",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"SpriteSheet2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
  SpriteSheet2D* spriteSheet = ((SpriteSheet2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSpriteSheet'", NULL);
#endif
 {
  self->SetSpriteSheet(spriteSheet);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSpriteSheet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTexture of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Sprite2D_GetTexture00
static int tolua_Urho2DLuaAPI_Sprite2D_GetTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sprite2D* self = (const Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTexture'", NULL);
#endif
 {
  Texture2D* tolua_ret = (Texture2D*)  self->GetTexture();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRectangle of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Sprite2D_GetRectangle00
static int tolua_Urho2DLuaAPI_Sprite2D_GetRectangle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sprite2D* self = (const Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRectangle'", NULL);
#endif
 {
  const IntRect& tolua_ret = (const IntRect&)  self->GetRectangle();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntRect");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRectangle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHotSpot of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Sprite2D_GetHotSpot00
static int tolua_Urho2DLuaAPI_Sprite2D_GetHotSpot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sprite2D* self = (const Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHotSpot'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetHotSpot();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHotSpot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOffset of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Sprite2D_GetOffset00
static int tolua_Urho2DLuaAPI_Sprite2D_GetOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sprite2D* self = (const Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOffset'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetOffset();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextureEdgeOffset of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Sprite2D_GetTextureEdgeOffset00
static int tolua_Urho2DLuaAPI_Sprite2D_GetTextureEdgeOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sprite2D* self = (const Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextureEdgeOffset'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetTextureEdgeOffset();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextureEdgeOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSpriteSheet of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Sprite2D_GetSpriteSheet00
static int tolua_Urho2DLuaAPI_Sprite2D_GetSpriteSheet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sprite2D* self = (const Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSpriteSheet'", NULL);
#endif
 {
  SpriteSheet2D* tolua_ret = (SpriteSheet2D*)  self->GetSpriteSheet();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SpriteSheet2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSpriteSheet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: texture of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_get_Sprite2D_texture_ptr
static int tolua_get_Sprite2D_texture_ptr(lua_State* tolua_S)
{
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texture'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetTexture(),"Texture2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: texture of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_set_Sprite2D_texture_ptr
static int tolua_set_Sprite2D_texture_ptr(lua_State* tolua_S)
{
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texture'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Texture2D",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTexture(((Texture2D*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rectangle of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_get_Sprite2D_rectangle
static int tolua_get_Sprite2D_rectangle(lua_State* tolua_S)
{
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rectangle'",NULL);
#endif
 IntRect tolua_ret = (IntRect)self->GetRectangle();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((IntRect)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"IntRect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntRect));
 tolua_pushusertype(tolua_S,tolua_obj,"IntRect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rectangle of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_set_Sprite2D_rectangle
static int tolua_set_Sprite2D_rectangle(lua_State* tolua_S)
{
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rectangle'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntRect",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRectangle(*((IntRect*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: hotSpot of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_get_Sprite2D_hotSpot
static int tolua_get_Sprite2D_hotSpot(lua_State* tolua_S)
{
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hotSpot'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->GetHotSpot();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector2)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: hotSpot of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_set_Sprite2D_hotSpot
static int tolua_set_Sprite2D_hotSpot(lua_State* tolua_S)
{
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hotSpot'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetHotSpot(*((Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: offset of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_get_Sprite2D_offset
static int tolua_get_Sprite2D_offset(lua_State* tolua_S)
{
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'offset'",NULL);
#endif
 IntVector2 tolua_ret = (IntVector2)self->GetOffset();
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

/* set function: offset of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_set_Sprite2D_offset
static int tolua_set_Sprite2D_offset(lua_State* tolua_S)
{
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'offset'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOffset(*((IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: textureEdgeOffset of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_get_Sprite2D_textureEdgeOffset
static int tolua_get_Sprite2D_textureEdgeOffset(lua_State* tolua_S)
{
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textureEdgeOffset'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTextureEdgeOffset());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: textureEdgeOffset of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_set_Sprite2D_textureEdgeOffset
static int tolua_set_Sprite2D_textureEdgeOffset(lua_State* tolua_S)
{
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textureEdgeOffset'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTextureEdgeOffset(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: spriteSheet of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_get_Sprite2D_spriteSheet_ptr
static int tolua_get_Sprite2D_spriteSheet_ptr(lua_State* tolua_S)
{
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'spriteSheet'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetSpriteSheet(),"SpriteSheet2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: spriteSheet of class  Sprite2D */
#ifndef TOLUA_DISABLE_tolua_set_Sprite2D_spriteSheet_ptr
static int tolua_set_Sprite2D_spriteSheet_ptr(lua_State* tolua_S)
{
  Sprite2D* self = (Sprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'spriteSheet'",NULL);
 if (!tolua_isusertype(tolua_S,2,"SpriteSheet2D",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSpriteSheet(((SpriteSheet2D*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTexture of class  SpriteSheet2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_SpriteSheet2D_SetTexture00
static int tolua_Urho2DLuaAPI_SpriteSheet2D_SetTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SpriteSheet2D",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Texture2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SpriteSheet2D* self = (SpriteSheet2D*)  tolua_tousertype(tolua_S,1,0);
  Texture2D* texture = ((Texture2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTexture'", NULL);
#endif
 {
  self->SetTexture(texture);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTexture of class  SpriteSheet2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_SpriteSheet2D_GetTexture00
static int tolua_Urho2DLuaAPI_SpriteSheet2D_GetTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SpriteSheet2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SpriteSheet2D* self = (const SpriteSheet2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTexture'", NULL);
#endif
 {
  Texture2D* tolua_ret = (Texture2D*)  self->GetTexture();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSprite of class  SpriteSheet2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_SpriteSheet2D_GetSprite00
static int tolua_Urho2DLuaAPI_SpriteSheet2D_GetSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SpriteSheet2D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SpriteSheet2D* self = (const SpriteSheet2D*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSprite'", NULL);
#endif
 {
  Sprite2D* tolua_ret = (Sprite2D*)  self->GetSprite(name);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DefineSprite of class  SpriteSheet2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_SpriteSheet2D_DefineSprite00
static int tolua_Urho2DLuaAPI_SpriteSheet2D_DefineSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SpriteSheet2D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SpriteSheet2D* self = (SpriteSheet2D*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const IntRect* rectangle = ((const IntRect*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DefineSprite'", NULL);
#endif
 {
  self->DefineSprite(name,*rectangle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DefineSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DefineSprite of class  SpriteSheet2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_SpriteSheet2D_DefineSprite01
static int tolua_Urho2DLuaAPI_SpriteSheet2D_DefineSprite01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SpriteSheet2D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const IntRect",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  SpriteSheet2D* self = (SpriteSheet2D*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const IntRect* rectangle = ((const IntRect*)  tolua_tousertype(tolua_S,3,0));
  const Vector2* hotSpot = ((const Vector2*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DefineSprite'", NULL);
#endif
 {
  self->DefineSprite(name,*rectangle,*hotSpot);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Urho2DLuaAPI_SpriteSheet2D_DefineSprite00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: DefineSprite of class  SpriteSheet2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_SpriteSheet2D_DefineSprite02
static int tolua_Urho2DLuaAPI_SpriteSheet2D_DefineSprite02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SpriteSheet2D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const IntRect",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  SpriteSheet2D* self = (SpriteSheet2D*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const IntRect* rectangle = ((const IntRect*)  tolua_tousertype(tolua_S,3,0));
  const Vector2* hotSpot = ((const Vector2*)  tolua_tousertype(tolua_S,4,0));
  const IntVector2* originSize = ((const IntVector2*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DefineSprite'", NULL);
#endif
 {
  self->DefineSprite(name,*rectangle,*hotSpot,*originSize);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Urho2DLuaAPI_SpriteSheet2D_DefineSprite01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: texture of class  SpriteSheet2D */
#ifndef TOLUA_DISABLE_tolua_get_SpriteSheet2D_texture_ptr
static int tolua_get_SpriteSheet2D_texture_ptr(lua_State* tolua_S)
{
  SpriteSheet2D* self = (SpriteSheet2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texture'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetTexture(),"Texture2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: texture of class  SpriteSheet2D */
#ifndef TOLUA_DISABLE_tolua_set_SpriteSheet2D_texture_ptr
static int tolua_set_SpriteSheet2D_texture_ptr(lua_State* tolua_S)
{
  SpriteSheet2D* self = (SpriteSheet2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texture'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Texture2D",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTexture(((Texture2D*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: PIXEL_SIZE */
#ifndef TOLUA_DISABLE_tolua_get_PIXEL_SIZE
static int tolua_get_PIXEL_SIZE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)PIXEL_SIZE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLayer of class  Drawable2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Drawable2D_SetLayer00
static int tolua_Urho2DLuaAPI_Drawable2D_SetLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Drawable2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Drawable2D* self = (Drawable2D*)  tolua_tousertype(tolua_S,1,0);
  int layer = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLayer'", NULL);
#endif
 {
  self->SetLayer(layer);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOrderInLayer of class  Drawable2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Drawable2D_SetOrderInLayer00
static int tolua_Urho2DLuaAPI_Drawable2D_SetOrderInLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Drawable2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Drawable2D* self = (Drawable2D*)  tolua_tousertype(tolua_S,1,0);
  int orderInLayer = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOrderInLayer'", NULL);
#endif
 {
  self->SetOrderInLayer(orderInLayer);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOrderInLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLayer of class  Drawable2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Drawable2D_GetLayer00
static int tolua_Urho2DLuaAPI_Drawable2D_GetLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Drawable2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Drawable2D* self = (const Drawable2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLayer'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetLayer();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOrderInLayer of class  Drawable2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Drawable2D_GetOrderInLayer00
static int tolua_Urho2DLuaAPI_Drawable2D_GetOrderInLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Drawable2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Drawable2D* self = (const Drawable2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOrderInLayer'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetOrderInLayer();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOrderInLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: layer of class  Drawable2D */
#ifndef TOLUA_DISABLE_tolua_get_Drawable2D_layer
static int tolua_get_Drawable2D_layer(lua_State* tolua_S)
{
  Drawable2D* self = (Drawable2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layer'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLayer());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: layer of class  Drawable2D */
#ifndef TOLUA_DISABLE_tolua_set_Drawable2D_layer
static int tolua_set_Drawable2D_layer(lua_State* tolua_S)
{
  Drawable2D* self = (Drawable2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layer'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLayer(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: orderInLayer of class  Drawable2D */
#ifndef TOLUA_DISABLE_tolua_get_Drawable2D_orderInLayer
static int tolua_get_Drawable2D_orderInLayer(lua_State* tolua_S)
{
  Drawable2D* self = (Drawable2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'orderInLayer'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetOrderInLayer());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: orderInLayer of class  Drawable2D */
#ifndef TOLUA_DISABLE_tolua_set_Drawable2D_orderInLayer
static int tolua_set_Drawable2D_orderInLayer(lua_State* tolua_S)
{
  Drawable2D* self = (Drawable2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'orderInLayer'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOrderInLayer(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSprite of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_SetSprite00
static int tolua_Urho2DLuaAPI_StaticSprite2D_SetSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StaticSprite2D",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Sprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
  Sprite2D* sprite = ((Sprite2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSprite'", NULL);
#endif
 {
  self->SetSprite(sprite);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBlendMode of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_SetBlendMode00
static int tolua_Urho2DLuaAPI_StaticSprite2D_SetBlendMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StaticSprite2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
  BlendMode mode = ((BlendMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBlendMode'", NULL);
#endif
 {
  self->SetBlendMode(mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBlendMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFlip of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_SetFlip00
static int tolua_Urho2DLuaAPI_StaticSprite2D_SetFlip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StaticSprite2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
  bool flipX = ((bool)  tolua_toboolean(tolua_S,2,0));
  bool flipY = ((bool)  tolua_toboolean(tolua_S,3,0));
  bool swapXY = ((bool)  tolua_toboolean(tolua_S,4,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFlip'", NULL);
#endif
 {
  self->SetFlip(flipX,flipY,swapXY);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFlip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFlipX of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_SetFlipX00
static int tolua_Urho2DLuaAPI_StaticSprite2D_SetFlipX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StaticSprite2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
  bool flipX = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFlipX'", NULL);
#endif
 {
  self->SetFlipX(flipX);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFlipX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFlipY of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_SetFlipY00
static int tolua_Urho2DLuaAPI_StaticSprite2D_SetFlipY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StaticSprite2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
  bool flipY = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFlipY'", NULL);
#endif
 {
  self->SetFlipY(flipY);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFlipY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSwapXY of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_SetSwapXY00
static int tolua_Urho2DLuaAPI_StaticSprite2D_SetSwapXY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StaticSprite2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
  bool swapXY = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSwapXY'", NULL);
#endif
 {
  self->SetSwapXY(swapXY);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSwapXY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetColor of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_SetColor00
static int tolua_Urho2DLuaAPI_StaticSprite2D_SetColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StaticSprite2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
  const Color* color = ((const Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetColor'", NULL);
#endif
 {
  self->SetColor(*color);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAlpha of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_SetAlpha00
static int tolua_Urho2DLuaAPI_StaticSprite2D_SetAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StaticSprite2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
  float alpha = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAlpha'", NULL);
#endif
 {
  self->SetAlpha(alpha);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseHotSpot of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_SetUseHotSpot00
static int tolua_Urho2DLuaAPI_StaticSprite2D_SetUseHotSpot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StaticSprite2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
  bool useHotSpot = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseHotSpot'", NULL);
#endif
 {
  self->SetUseHotSpot(useHotSpot);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseHotSpot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHotSpot of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_SetHotSpot00
static int tolua_Urho2DLuaAPI_StaticSprite2D_SetHotSpot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StaticSprite2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* hotspot = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHotSpot'", NULL);
#endif
 {
  self->SetHotSpot(*hotspot);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHotSpot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseDrawRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_SetUseDrawRect00
static int tolua_Urho2DLuaAPI_StaticSprite2D_SetUseDrawRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StaticSprite2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
  bool useDrawRect = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseDrawRect'", NULL);
#endif
 {
  self->SetUseDrawRect(useDrawRect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseDrawRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDrawRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_SetDrawRect00
static int tolua_Urho2DLuaAPI_StaticSprite2D_SetDrawRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StaticSprite2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
  const Rect* rect = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDrawRect'", NULL);
#endif
 {
  self->SetDrawRect(*rect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDrawRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseTextureRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_SetUseTextureRect00
static int tolua_Urho2DLuaAPI_StaticSprite2D_SetUseTextureRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StaticSprite2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
  bool useTextureRect = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseTextureRect'", NULL);
#endif
 {
  self->SetUseTextureRect(useTextureRect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseTextureRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextureRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_SetTextureRect00
static int tolua_Urho2DLuaAPI_StaticSprite2D_SetTextureRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StaticSprite2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
  const Rect* rect = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextureRect'", NULL);
#endif
 {
  self->SetTextureRect(*rect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextureRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCustomMaterial of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_SetCustomMaterial00
static int tolua_Urho2DLuaAPI_StaticSprite2D_SetCustomMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StaticSprite2D",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Material",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
  Material* customMaterial = ((Material*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCustomMaterial'", NULL);
#endif
 {
  self->SetCustomMaterial(customMaterial);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCustomMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSprite of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_GetSprite00
static int tolua_Urho2DLuaAPI_StaticSprite2D_GetSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StaticSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StaticSprite2D* self = (const StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSprite'", NULL);
#endif
 {
  Sprite2D* tolua_ret = (Sprite2D*)  self->GetSprite();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBlendMode of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_GetBlendMode00
static int tolua_Urho2DLuaAPI_StaticSprite2D_GetBlendMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StaticSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StaticSprite2D* self = (const StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBlendMode'", NULL);
#endif
 {
  BlendMode tolua_ret = (BlendMode)  self->GetBlendMode();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBlendMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFlipX of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_GetFlipX00
static int tolua_Urho2DLuaAPI_StaticSprite2D_GetFlipX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StaticSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StaticSprite2D* self = (const StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFlipX'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetFlipX();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFlipX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFlipY of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_GetFlipY00
static int tolua_Urho2DLuaAPI_StaticSprite2D_GetFlipY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StaticSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StaticSprite2D* self = (const StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFlipY'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetFlipY();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFlipY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSwapXY of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_GetSwapXY00
static int tolua_Urho2DLuaAPI_StaticSprite2D_GetSwapXY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StaticSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StaticSprite2D* self = (const StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSwapXY'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetSwapXY();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSwapXY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetColor of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_GetColor00
static int tolua_Urho2DLuaAPI_StaticSprite2D_GetColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StaticSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StaticSprite2D* self = (const StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetColor'", NULL);
#endif
 {
  const Color& tolua_ret = (const Color&)  self->GetColor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Color");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAlpha of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_GetAlpha00
static int tolua_Urho2DLuaAPI_StaticSprite2D_GetAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StaticSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StaticSprite2D* self = (const StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAlpha'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAlpha();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUseHotSpot of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_GetUseHotSpot00
static int tolua_Urho2DLuaAPI_StaticSprite2D_GetUseHotSpot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StaticSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StaticSprite2D* self = (const StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUseHotSpot'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetUseHotSpot();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUseHotSpot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHotSpot of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_GetHotSpot00
static int tolua_Urho2DLuaAPI_StaticSprite2D_GetHotSpot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StaticSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StaticSprite2D* self = (const StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHotSpot'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetHotSpot();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHotSpot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUseDrawRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_GetUseDrawRect00
static int tolua_Urho2DLuaAPI_StaticSprite2D_GetUseDrawRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StaticSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StaticSprite2D* self = (const StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUseDrawRect'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetUseDrawRect();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUseDrawRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDrawRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_GetDrawRect00
static int tolua_Urho2DLuaAPI_StaticSprite2D_GetDrawRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StaticSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StaticSprite2D* self = (const StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDrawRect'", NULL);
#endif
 {
  const Rect& tolua_ret = (const Rect&)  self->GetDrawRect();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Rect");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDrawRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUseTextureRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_GetUseTextureRect00
static int tolua_Urho2DLuaAPI_StaticSprite2D_GetUseTextureRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StaticSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StaticSprite2D* self = (const StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUseTextureRect'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetUseTextureRect();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUseTextureRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextureRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_GetTextureRect00
static int tolua_Urho2DLuaAPI_StaticSprite2D_GetTextureRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StaticSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StaticSprite2D* self = (const StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextureRect'", NULL);
#endif
 {
  const Rect& tolua_ret = (const Rect&)  self->GetTextureRect();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Rect");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextureRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCustomMaterial of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StaticSprite2D_GetCustomMaterial00
static int tolua_Urho2DLuaAPI_StaticSprite2D_GetCustomMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StaticSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StaticSprite2D* self = (const StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCustomMaterial'", NULL);
#endif
 {
  Material* tolua_ret = (Material*)  self->GetCustomMaterial();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Material");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCustomMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sprite of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_StaticSprite2D_sprite_ptr
static int tolua_get_StaticSprite2D_sprite_ptr(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sprite'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetSprite(),"Sprite2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sprite of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_StaticSprite2D_sprite_ptr
static int tolua_set_StaticSprite2D_sprite_ptr(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sprite'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Sprite2D",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSprite(((Sprite2D*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: blendMode of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_StaticSprite2D_blendMode
static int tolua_get_StaticSprite2D_blendMode(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blendMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetBlendMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: blendMode of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_StaticSprite2D_blendMode
static int tolua_set_StaticSprite2D_blendMode(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blendMode'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetBlendMode(((BlendMode) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: flipX of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_StaticSprite2D_flipX
static int tolua_get_StaticSprite2D_flipX(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flipX'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetFlipX());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: flipX of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_StaticSprite2D_flipX
static int tolua_set_StaticSprite2D_flipX(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flipX'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFlipX(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: flipY of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_StaticSprite2D_flipY
static int tolua_get_StaticSprite2D_flipY(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flipY'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetFlipY());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: flipY of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_StaticSprite2D_flipY
static int tolua_set_StaticSprite2D_flipY(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flipY'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFlipY(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: swapXY of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_StaticSprite2D_swapXY
static int tolua_get_StaticSprite2D_swapXY(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'swapXY'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetSwapXY());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: swapXY of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_StaticSprite2D_swapXY
static int tolua_set_StaticSprite2D_swapXY(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'swapXY'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSwapXY(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: color of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_StaticSprite2D_color_ref
static int tolua_get_StaticSprite2D_color_ref(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'color'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetColor(),"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: color of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_StaticSprite2D_color_ref
static int tolua_set_StaticSprite2D_color_ref(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'color'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetColor((*(Color*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: alpha of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_StaticSprite2D_alpha
static int tolua_get_StaticSprite2D_alpha(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'alpha'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAlpha());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: alpha of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_StaticSprite2D_alpha
static int tolua_set_StaticSprite2D_alpha(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'alpha'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAlpha(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: useHotSpot of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_StaticSprite2D_useHotSpot
static int tolua_get_StaticSprite2D_useHotSpot(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useHotSpot'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetUseHotSpot());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: useHotSpot of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_StaticSprite2D_useHotSpot
static int tolua_set_StaticSprite2D_useHotSpot(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useHotSpot'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUseHotSpot(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: hotSpot of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_StaticSprite2D_hotSpot
static int tolua_get_StaticSprite2D_hotSpot(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hotSpot'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->GetHotSpot();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector2)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: hotSpot of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_StaticSprite2D_hotSpot
static int tolua_set_StaticSprite2D_hotSpot(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hotSpot'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetHotSpot(*((Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: customMaterial of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_StaticSprite2D_customMaterial_ptr
static int tolua_get_StaticSprite2D_customMaterial_ptr(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'customMaterial'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetCustomMaterial(),"Material");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: customMaterial of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_StaticSprite2D_customMaterial_ptr
static int tolua_set_StaticSprite2D_customMaterial_ptr(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'customMaterial'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Material",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCustomMaterial(((Material*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: drawRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_StaticSprite2D_drawRect
static int tolua_get_StaticSprite2D_drawRect(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawRect'",NULL);
#endif
 Rect tolua_ret = (Rect)self->GetDrawRect();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Rect)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Rect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Rect));
 tolua_pushusertype(tolua_S,tolua_obj,"Rect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: drawRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_StaticSprite2D_drawRect
static int tolua_set_StaticSprite2D_drawRect(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawRect'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Rect",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDrawRect(*((Rect*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: useDrawRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_StaticSprite2D_useDrawRect
static int tolua_get_StaticSprite2D_useDrawRect(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useDrawRect'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetUseDrawRect());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: useDrawRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_StaticSprite2D_useDrawRect
static int tolua_set_StaticSprite2D_useDrawRect(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useDrawRect'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUseDrawRect(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: textureRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_StaticSprite2D_textureRect
static int tolua_get_StaticSprite2D_textureRect(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textureRect'",NULL);
#endif
 Rect tolua_ret = (Rect)self->GetTextureRect();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Rect)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Rect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Rect));
 tolua_pushusertype(tolua_S,tolua_obj,"Rect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: textureRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_StaticSprite2D_textureRect
static int tolua_set_StaticSprite2D_textureRect(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textureRect'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Rect",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTextureRect(*((Rect*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: useTextureRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_StaticSprite2D_useTextureRect
static int tolua_get_StaticSprite2D_useTextureRect(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useTextureRect'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetUseTextureRect());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: useTextureRect of class  StaticSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_StaticSprite2D_useTextureRect
static int tolua_set_StaticSprite2D_useTextureRect(lua_State* tolua_S)
{
  StaticSprite2D* self = (StaticSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useTextureRect'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUseTextureRect(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBorder of class  StretchableSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StretchableSprite2D_SetBorder00
static int tolua_Urho2DLuaAPI_StretchableSprite2D_SetBorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"StretchableSprite2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  StretchableSprite2D* self = (StretchableSprite2D*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* border = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBorder'", NULL);
#endif
 {
  self->SetBorder(*border);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBorder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBorder of class  StretchableSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_StretchableSprite2D_GetBorder00
static int tolua_Urho2DLuaAPI_StretchableSprite2D_GetBorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const StretchableSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const StretchableSprite2D* self = (const StretchableSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBorder'", NULL);
#endif
 {
  const IntRect& tolua_ret = (const IntRect&)  self->GetBorder();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntRect");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBorder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: border of class  StretchableSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_StretchableSprite2D_border
static int tolua_get_StretchableSprite2D_border(lua_State* tolua_S)
{
  StretchableSprite2D* self = (StretchableSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'border'",NULL);
#endif
 IntRect tolua_ret = (IntRect)self->GetBorder();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((IntRect)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"IntRect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntRect));
 tolua_pushusertype(tolua_S,tolua_obj,"IntRect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: border of class  StretchableSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_StretchableSprite2D_border
static int tolua_set_StretchableSprite2D_border(lua_State* tolua_S)
{
  StretchableSprite2D* self = (StretchableSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'border'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntRect",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetBorder(*((IntRect*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumAnimations of class  AnimationSet2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_AnimationSet2D_GetNumAnimations00
static int tolua_Urho2DLuaAPI_AnimationSet2D_GetNumAnimations00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AnimationSet2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AnimationSet2D* self = (const AnimationSet2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumAnimations'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumAnimations();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumAnimations'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnimation of class  AnimationSet2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_AnimationSet2D_GetAnimation00
static int tolua_Urho2DLuaAPI_AnimationSet2D_GetAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AnimationSet2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AnimationSet2D* self = (const AnimationSet2D*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnimation'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetAnimation(index);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numAnimations of class  AnimationSet2D */
#ifndef TOLUA_DISABLE_tolua_get_AnimationSet2D_numAnimations
static int tolua_get_AnimationSet2D_numAnimations(lua_State* tolua_S)
{
  AnimationSet2D* self = (AnimationSet2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numAnimations'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumAnimations());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAnimationSet of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_AnimatedSprite2D_SetAnimationSet00
static int tolua_Urho2DLuaAPI_AnimatedSprite2D_SetAnimationSet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"AnimatedSprite2D",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"AnimationSet2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  AnimatedSprite2D* self = (AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
  AnimationSet2D* animationSet = ((AnimationSet2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnimationSet'", NULL);
#endif
 {
  self->SetAnimationSet(animationSet);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAnimationSet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEntity of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_AnimatedSprite2D_SetEntity00
static int tolua_Urho2DLuaAPI_AnimatedSprite2D_SetEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"AnimatedSprite2D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  AnimatedSprite2D* self = (AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
  const String entity = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEntity'", NULL);
#endif
 {
  self->SetEntity(entity);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEntity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAnimation of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_AnimatedSprite2D_SetAnimation00
static int tolua_Urho2DLuaAPI_AnimatedSprite2D_SetAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"AnimatedSprite2D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  AnimatedSprite2D* self = (AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  LoopMode2D loopMode = ((LoopMode2D) (int)  tolua_tonumber(tolua_S,3,LM_DEFAULT));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnimation'", NULL);
#endif
 {
  self->SetAnimation(name,loopMode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLoopMode of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_AnimatedSprite2D_SetLoopMode00
static int tolua_Urho2DLuaAPI_AnimatedSprite2D_SetLoopMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"AnimatedSprite2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  AnimatedSprite2D* self = (AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
  LoopMode2D loopMode = ((LoopMode2D) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLoopMode'", NULL);
#endif
 {
  self->SetLoopMode(loopMode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLoopMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSpeed of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_AnimatedSprite2D_SetSpeed00
static int tolua_Urho2DLuaAPI_AnimatedSprite2D_SetSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"AnimatedSprite2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  AnimatedSprite2D* self = (AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
  float speed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSpeed'", NULL);
#endif
 {
  self->SetSpeed(speed);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnimationSet of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_AnimatedSprite2D_GetAnimationSet00
static int tolua_Urho2DLuaAPI_AnimatedSprite2D_GetAnimationSet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AnimatedSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AnimatedSprite2D* self = (const AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnimationSet'", NULL);
#endif
 {
  AnimationSet2D* tolua_ret = (AnimationSet2D*)  self->GetAnimationSet();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"AnimationSet2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAnimationSet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEntity of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_AnimatedSprite2D_GetEntity00
static int tolua_Urho2DLuaAPI_AnimatedSprite2D_GetEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AnimatedSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AnimatedSprite2D* self = (const AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEntity'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetEntity();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEntity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnimation of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_AnimatedSprite2D_GetAnimation00
static int tolua_Urho2DLuaAPI_AnimatedSprite2D_GetAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AnimatedSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AnimatedSprite2D* self = (const AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnimation'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetAnimation();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLoopMode of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_AnimatedSprite2D_GetLoopMode00
static int tolua_Urho2DLuaAPI_AnimatedSprite2D_GetLoopMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AnimatedSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AnimatedSprite2D* self = (const AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLoopMode'", NULL);
#endif
 {
  LoopMode2D tolua_ret = (LoopMode2D)  self->GetLoopMode();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLoopMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSpeed of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_AnimatedSprite2D_GetSpeed00
static int tolua_Urho2DLuaAPI_AnimatedSprite2D_GetSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const AnimatedSprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const AnimatedSprite2D* self = (const AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSpeed'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetSpeed();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: speed of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_AnimatedSprite2D_speed
static int tolua_get_AnimatedSprite2D_speed(lua_State* tolua_S)
{
  AnimatedSprite2D* self = (AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'speed'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSpeed());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: speed of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_AnimatedSprite2D_speed
static int tolua_set_AnimatedSprite2D_speed(lua_State* tolua_S)
{
  AnimatedSprite2D* self = (AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'speed'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSpeed(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: entity of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_AnimatedSprite2D_entity
static int tolua_get_AnimatedSprite2D_entity(lua_State* tolua_S)
{
  AnimatedSprite2D* self = (AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'entity'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetEntity());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: entity of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_AnimatedSprite2D_entity
static int tolua_set_AnimatedSprite2D_entity(lua_State* tolua_S)
{
  AnimatedSprite2D* self = (AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'entity'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEntity(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: animation of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_AnimatedSprite2D_animation
static int tolua_get_AnimatedSprite2D_animation(lua_State* tolua_S)
{
  AnimatedSprite2D* self = (AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'animation'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetAnimation());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: animation of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_AnimatedSprite2D_animation
static int tolua_set_AnimatedSprite2D_animation(lua_State* tolua_S)
{
  AnimatedSprite2D* self = (AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'animation'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAnimation(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: animationSet of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_AnimatedSprite2D_animationSet_ptr
static int tolua_get_AnimatedSprite2D_animationSet_ptr(lua_State* tolua_S)
{
  AnimatedSprite2D* self = (AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'animationSet'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetAnimationSet(),"AnimationSet2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: animationSet of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_AnimatedSprite2D_animationSet_ptr
static int tolua_set_AnimatedSprite2D_animationSet_ptr(lua_State* tolua_S)
{
  AnimatedSprite2D* self = (AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'animationSet'",NULL);
 if (!tolua_isusertype(tolua_S,2,"AnimationSet2D",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAnimationSet(((AnimationSet2D*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: loopMode of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_get_AnimatedSprite2D_loopMode
static int tolua_get_AnimatedSprite2D_loopMode(lua_State* tolua_S)
{
  AnimatedSprite2D* self = (AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLoopMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: loopMode of class  AnimatedSprite2D */
#ifndef TOLUA_DISABLE_tolua_set_AnimatedSprite2D_loopMode
static int tolua_set_AnimatedSprite2D_loopMode(lua_State* tolua_S)
{
  AnimatedSprite2D* self = (AnimatedSprite2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopMode'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLoopMode(((LoopMode2D) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: ParticleEffect2DClone of class  ParticleEffect2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ParticleEffect2D_Clone00
static int tolua_Urho2DLuaAPI_ParticleEffect2D_Clone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ParticleEffect2D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ParticleEffect2D* self = (const ParticleEffect2D*)  tolua_tousertype(tolua_S,1,0);
  const String cloneName = ((const String)  tolua_tourho3dstring(tolua_S,2,String::EMPTY));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ParticleEffect2DClone'", NULL);
#endif
 {
  tolua_outside ParticleEffect2D* tolua_ret = (tolua_outside ParticleEffect2D*)  ParticleEffect2DClone(self,cloneName);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleEffect2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEffect of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ParticleEmitter2D_SetEffect00
static int tolua_Urho2DLuaAPI_ParticleEmitter2D_SetEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ParticleEmitter2D",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"ParticleEffect2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter2D* self = (ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
  ParticleEffect2D* effect = ((ParticleEffect2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEffect'", NULL);
#endif
 {
  self->SetEffect(effect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSprite of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ParticleEmitter2D_SetSprite00
static int tolua_Urho2DLuaAPI_ParticleEmitter2D_SetSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ParticleEmitter2D",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Sprite2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter2D* self = (ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
  Sprite2D* sprite = ((Sprite2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSprite'", NULL);
#endif
 {
  self->SetSprite(sprite);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBlendMode of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ParticleEmitter2D_SetBlendMode00
static int tolua_Urho2DLuaAPI_ParticleEmitter2D_SetBlendMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ParticleEmitter2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter2D* self = (ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
  BlendMode blendMode = ((BlendMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBlendMode'", NULL);
#endif
 {
  self->SetBlendMode(blendMode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBlendMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitting of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ParticleEmitter2D_SetEmitting00
static int tolua_Urho2DLuaAPI_ParticleEmitter2D_SetEmitting00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ParticleEmitter2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter2D* self = (ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
  bool emitting = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitting'", NULL);
#endif
 {
  self->SetEmitting(emitting);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitting'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEffect of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ParticleEmitter2D_GetEffect00
static int tolua_Urho2DLuaAPI_ParticleEmitter2D_GetEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ParticleEmitter2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter2D* self = (const ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEffect'", NULL);
#endif
 {
  ParticleEffect2D* tolua_ret = (ParticleEffect2D*)  self->GetEffect();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleEffect2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSprite of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ParticleEmitter2D_GetSprite00
static int tolua_Urho2DLuaAPI_ParticleEmitter2D_GetSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ParticleEmitter2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter2D* self = (const ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSprite'", NULL);
#endif
 {
  Sprite2D* tolua_ret = (Sprite2D*)  self->GetSprite();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBlendMode of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ParticleEmitter2D_GetBlendMode00
static int tolua_Urho2DLuaAPI_ParticleEmitter2D_GetBlendMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ParticleEmitter2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter2D* self = (const ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBlendMode'", NULL);
#endif
 {
  BlendMode tolua_ret = (BlendMode)  self->GetBlendMode();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBlendMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsEmitting of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ParticleEmitter2D_IsEmitting00
static int tolua_Urho2DLuaAPI_ParticleEmitter2D_IsEmitting00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ParticleEmitter2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter2D* self = (const ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsEmitting'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsEmitting();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsEmitting'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: effect of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_get_ParticleEmitter2D_effect_ptr
static int tolua_get_ParticleEmitter2D_effect_ptr(lua_State* tolua_S)
{
  ParticleEmitter2D* self = (ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effect'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetEffect(),"ParticleEffect2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: effect of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_set_ParticleEmitter2D_effect_ptr
static int tolua_set_ParticleEmitter2D_effect_ptr(lua_State* tolua_S)
{
  ParticleEmitter2D* self = (ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effect'",NULL);
 if (!tolua_isusertype(tolua_S,2,"ParticleEffect2D",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEffect(((ParticleEffect2D*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sprite of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_get_ParticleEmitter2D_sprite_ptr
static int tolua_get_ParticleEmitter2D_sprite_ptr(lua_State* tolua_S)
{
  ParticleEmitter2D* self = (ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sprite'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetSprite(),"Sprite2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sprite of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_set_ParticleEmitter2D_sprite_ptr
static int tolua_set_ParticleEmitter2D_sprite_ptr(lua_State* tolua_S)
{
  ParticleEmitter2D* self = (ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sprite'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Sprite2D",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSprite(((Sprite2D*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: blendMode of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_get_ParticleEmitter2D_blendMode
static int tolua_get_ParticleEmitter2D_blendMode(lua_State* tolua_S)
{
  ParticleEmitter2D* self = (ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blendMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetBlendMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: blendMode of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_set_ParticleEmitter2D_blendMode
static int tolua_set_ParticleEmitter2D_blendMode(lua_State* tolua_S)
{
  ParticleEmitter2D* self = (ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blendMode'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetBlendMode(((BlendMode) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: emitting of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_get_ParticleEmitter2D_emitting
static int tolua_get_ParticleEmitter2D_emitting(lua_State* tolua_S)
{
  ParticleEmitter2D* self = (ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'emitting'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsEmitting());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: emitting of class  ParticleEmitter2D */
#ifndef TOLUA_DISABLE_tolua_set_ParticleEmitter2D_emitting
static int tolua_set_ParticleEmitter2D_emitting(lua_State* tolua_S)
{
  ParticleEmitter2D* self = (ParticleEmitter2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'emitting'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEmitting(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: orientation_ of class  TileMapInfo2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapInfo2D_orientation
static int tolua_get_TileMapInfo2D_orientation(lua_State* tolua_S)
{
  TileMapInfo2D* self = (TileMapInfo2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'orientation_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->orientation_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: orientation_ of class  TileMapInfo2D */
#ifndef TOLUA_DISABLE_tolua_set_TileMapInfo2D_orientation
static int tolua_set_TileMapInfo2D_orientation(lua_State* tolua_S)
{
  TileMapInfo2D* self = (TileMapInfo2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'orientation_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->orientation_ = ((Orientation2D) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width_ of class  TileMapInfo2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapInfo2D_width
static int tolua_get_TileMapInfo2D_width(lua_State* tolua_S)
{
  TileMapInfo2D* self = (TileMapInfo2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->width_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width_ of class  TileMapInfo2D */
#ifndef TOLUA_DISABLE_tolua_set_TileMapInfo2D_width
static int tolua_set_TileMapInfo2D_width(lua_State* tolua_S)
{
  TileMapInfo2D* self = (TileMapInfo2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width_ = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height_ of class  TileMapInfo2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapInfo2D_height
static int tolua_get_TileMapInfo2D_height(lua_State* tolua_S)
{
  TileMapInfo2D* self = (TileMapInfo2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->height_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height_ of class  TileMapInfo2D */
#ifndef TOLUA_DISABLE_tolua_set_TileMapInfo2D_height
static int tolua_set_TileMapInfo2D_height(lua_State* tolua_S)
{
  TileMapInfo2D* self = (TileMapInfo2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height_ = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tileWidth_ of class  TileMapInfo2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapInfo2D_tileWidth
static int tolua_get_TileMapInfo2D_tileWidth(lua_State* tolua_S)
{
  TileMapInfo2D* self = (TileMapInfo2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileWidth_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->tileWidth_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tileWidth_ of class  TileMapInfo2D */
#ifndef TOLUA_DISABLE_tolua_set_TileMapInfo2D_tileWidth
static int tolua_set_TileMapInfo2D_tileWidth(lua_State* tolua_S)
{
  TileMapInfo2D* self = (TileMapInfo2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileWidth_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tileWidth_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tileHeight_ of class  TileMapInfo2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapInfo2D_tileHeight
static int tolua_get_TileMapInfo2D_tileHeight(lua_State* tolua_S)
{
  TileMapInfo2D* self = (TileMapInfo2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileHeight_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->tileHeight_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tileHeight_ of class  TileMapInfo2D */
#ifndef TOLUA_DISABLE_tolua_set_TileMapInfo2D_tileHeight
static int tolua_set_TileMapInfo2D_tileHeight(lua_State* tolua_S)
{
  TileMapInfo2D* self = (TileMapInfo2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileHeight_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tileHeight_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMapWidth of class  TileMapInfo2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapInfo2D_GetMapWidth00
static int tolua_Urho2DLuaAPI_TileMapInfo2D_GetMapWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapInfo2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapInfo2D* self = (const TileMapInfo2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMapWidth'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMapWidth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMapWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMapHeight of class  TileMapInfo2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapInfo2D_GetMapHeight00
static int tolua_Urho2DLuaAPI_TileMapInfo2D_GetMapHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapInfo2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapInfo2D* self = (const TileMapInfo2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMapHeight'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMapHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMapHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mapWidth of class  TileMapInfo2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapInfo2D_mapWidth
static int tolua_get_TileMapInfo2D_mapWidth(lua_State* tolua_S)
{
  TileMapInfo2D* self = (TileMapInfo2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapWidth'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMapWidth());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mapHeight of class  TileMapInfo2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapInfo2D_mapHeight
static int tolua_get_TileMapInfo2D_mapHeight(lua_State* tolua_S)
{
  TileMapInfo2D* self = (TileMapInfo2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapHeight'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMapHeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasProperty of class  PropertySet2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PropertySet2D_HasProperty00
static int tolua_Urho2DLuaAPI_PropertySet2D_HasProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PropertySet2D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PropertySet2D* self = (const PropertySet2D*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasProperty'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasProperty(name);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProperty of class  PropertySet2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PropertySet2D_GetProperty00
static int tolua_Urho2DLuaAPI_PropertySet2D_GetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PropertySet2D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PropertySet2D* self = (const PropertySet2D*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProperty'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetProperty(name);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FLIP_HORIZONTAL */
#ifndef TOLUA_DISABLE_tolua_get_FLIP_HORIZONTAL
static int tolua_get_FLIP_HORIZONTAL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)FLIP_HORIZONTAL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FLIP_VERTICAL */
#ifndef TOLUA_DISABLE_tolua_get_FLIP_VERTICAL
static int tolua_get_FLIP_VERTICAL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)FLIP_VERTICAL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FLIP_DIAGONAL */
#ifndef TOLUA_DISABLE_tolua_get_FLIP_DIAGONAL
static int tolua_get_FLIP_DIAGONAL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)FLIP_DIAGONAL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FLIP_RESERVED */
#ifndef TOLUA_DISABLE_tolua_get_FLIP_RESERVED
static int tolua_get_FLIP_RESERVED(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)FLIP_RESERVED);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FLIP_ALL */
#ifndef TOLUA_DISABLE_tolua_get_FLIP_ALL
static int tolua_get_FLIP_ALL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)FLIP_ALL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGid of class  Tile2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Tile2D_GetGid00
static int tolua_Urho2DLuaAPI_Tile2D_GetGid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Tile2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Tile2D* self = (const Tile2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGid'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetGid();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFlipX of class  Tile2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Tile2D_GetFlipX00
static int tolua_Urho2DLuaAPI_Tile2D_GetFlipX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Tile2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Tile2D* self = (const Tile2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFlipX'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetFlipX();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFlipX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFlipY of class  Tile2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Tile2D_GetFlipY00
static int tolua_Urho2DLuaAPI_Tile2D_GetFlipY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Tile2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Tile2D* self = (const Tile2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFlipY'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetFlipY();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFlipY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSwapXY of class  Tile2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Tile2D_GetSwapXY00
static int tolua_Urho2DLuaAPI_Tile2D_GetSwapXY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Tile2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Tile2D* self = (const Tile2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSwapXY'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetSwapXY();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSwapXY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSprite of class  Tile2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Tile2D_GetSprite00
static int tolua_Urho2DLuaAPI_Tile2D_GetSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Tile2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Tile2D* self = (const Tile2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSprite'", NULL);
#endif
 {
  Sprite2D* tolua_ret = (Sprite2D*)  self->GetSprite();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasProperty of class  Tile2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Tile2D_HasProperty00
static int tolua_Urho2DLuaAPI_Tile2D_HasProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Tile2D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Tile2D* self = (const Tile2D*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasProperty'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasProperty(name);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProperty of class  Tile2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Tile2D_GetProperty00
static int tolua_Urho2DLuaAPI_Tile2D_GetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Tile2D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Tile2D* self = (const Tile2D*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProperty'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetProperty(name);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: gid of class  Tile2D */
#ifndef TOLUA_DISABLE_tolua_get_Tile2D_gid
static int tolua_get_Tile2D_gid(lua_State* tolua_S)
{
  Tile2D* self = (Tile2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gid'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetGid());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sprite of class  Tile2D */
#ifndef TOLUA_DISABLE_tolua_get_Tile2D_sprite_ptr
static int tolua_get_Tile2D_sprite_ptr(lua_State* tolua_S)
{
  Tile2D* self = (Tile2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sprite'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetSprite(),"Sprite2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjectType of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapObject2D_GetObjectType00
static int tolua_Urho2DLuaAPI_TileMapObject2D_GetObjectType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapObject2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapObject2D* self = (const TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectType'", NULL);
#endif
 {
  TileMapObjectType2D tolua_ret = (TileMapObjectType2D)  self->GetObjectType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapObject2D_GetName00
static int tolua_Urho2DLuaAPI_TileMapObject2D_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapObject2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapObject2D* self = (const TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetName'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetName();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetType of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapObject2D_GetType00
static int tolua_Urho2DLuaAPI_TileMapObject2D_GetType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapObject2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapObject2D* self = (const TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetType'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetType();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPosition of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapObject2D_GetPosition00
static int tolua_Urho2DLuaAPI_TileMapObject2D_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapObject2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapObject2D* self = (const TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetPosition();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
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

/* method: GetSize of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapObject2D_GetSize00
static int tolua_Urho2DLuaAPI_TileMapObject2D_GetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapObject2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapObject2D* self = (const TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSize'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetSize();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
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

/* method: GetNumPoints of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapObject2D_GetNumPoints00
static int tolua_Urho2DLuaAPI_TileMapObject2D_GetNumPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapObject2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapObject2D* self = (const TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumPoints'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumPoints();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumPoints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPoint of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapObject2D_GetPoint00
static int tolua_Urho2DLuaAPI_TileMapObject2D_GetPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapObject2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapObject2D* self = (const TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPoint'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetPoint(index);
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTileGid of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapObject2D_GetTileGid00
static int tolua_Urho2DLuaAPI_TileMapObject2D_GetTileGid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapObject2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapObject2D* self = (const TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTileGid'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetTileGid();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTileGid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTileFlipX of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapObject2D_GetTileFlipX00
static int tolua_Urho2DLuaAPI_TileMapObject2D_GetTileFlipX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapObject2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapObject2D* self = (const TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTileFlipX'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetTileFlipX();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTileFlipX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTileFlipY of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapObject2D_GetTileFlipY00
static int tolua_Urho2DLuaAPI_TileMapObject2D_GetTileFlipY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapObject2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapObject2D* self = (const TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTileFlipY'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetTileFlipY();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTileFlipY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTileSwapXY of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapObject2D_GetTileSwapXY00
static int tolua_Urho2DLuaAPI_TileMapObject2D_GetTileSwapXY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapObject2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapObject2D* self = (const TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTileSwapXY'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetTileSwapXY();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTileSwapXY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTileSprite of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapObject2D_GetTileSprite00
static int tolua_Urho2DLuaAPI_TileMapObject2D_GetTileSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapObject2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapObject2D* self = (const TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTileSprite'", NULL);
#endif
 {
  Sprite2D* tolua_ret = (Sprite2D*)  self->GetTileSprite();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTileSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasProperty of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapObject2D_HasProperty00
static int tolua_Urho2DLuaAPI_TileMapObject2D_HasProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapObject2D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapObject2D* self = (const TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasProperty'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasProperty(name);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProperty of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapObject2D_GetProperty00
static int tolua_Urho2DLuaAPI_TileMapObject2D_GetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapObject2D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapObject2D* self = (const TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProperty'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetProperty(name);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: objectType of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapObject2D_objectType
static int tolua_get_TileMapObject2D_objectType(lua_State* tolua_S)
{
  TileMapObject2D* self = (TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'objectType'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetObjectType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapObject2D_name
static int tolua_get_TileMapObject2D_name(lua_State* tolua_S)
{
  TileMapObject2D* self = (TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: type of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapObject2D_type
static int tolua_get_TileMapObject2D_type(lua_State* tolua_S)
{
  TileMapObject2D* self = (TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: position of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapObject2D_position
static int tolua_get_TileMapObject2D_position(lua_State* tolua_S)
{
  TileMapObject2D* self = (TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->GetPosition();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector2)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: size of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapObject2D_size
static int tolua_get_TileMapObject2D_size(lua_State* tolua_S)
{
  TileMapObject2D* self = (TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->GetSize();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector2)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numPoints of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapObject2D_numPoints
static int tolua_get_TileMapObject2D_numPoints(lua_State* tolua_S)
{
  TileMapObject2D* self = (TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numPoints'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumPoints());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tileGid of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapObject2D_tileGid
static int tolua_get_TileMapObject2D_tileGid(lua_State* tolua_S)
{
  TileMapObject2D* self = (TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileGid'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTileGid());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tileSprite of class  TileMapObject2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapObject2D_tileSprite_ptr
static int tolua_get_TileMapObject2D_tileSprite_ptr(lua_State* tolua_S)
{
  TileMapObject2D* self = (TileMapObject2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tileSprite'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetTileSprite(),"Sprite2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSpriteTextureEdgeOffset of class  TmxFile2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TmxFile2D_SetSpriteTextureEdgeOffset00
static int tolua_Urho2DLuaAPI_TmxFile2D_SetSpriteTextureEdgeOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TmxFile2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TmxFile2D* self = (TmxFile2D*)  tolua_tousertype(tolua_S,1,0);
  float offset = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSpriteTextureEdgeOffset'", NULL);
#endif
 {
  self->SetSpriteTextureEdgeOffset(offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSpriteTextureEdgeOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSpriteTextureEdgeOffset of class  TmxFile2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TmxFile2D_GetSpriteTextureEdgeOffset00
static int tolua_Urho2DLuaAPI_TmxFile2D_GetSpriteTextureEdgeOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TmxFile2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TmxFile2D* self = (const TmxFile2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSpriteTextureEdgeOffset'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetSpriteTextureEdgeOffset();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSpriteTextureEdgeOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: spriteTextureEdgeOffset of class  TmxFile2D */
#ifndef TOLUA_DISABLE_tolua_get_TmxFile2D_edgeOffset
static int tolua_get_TmxFile2D_edgeOffset(lua_State* tolua_S)
{
  TmxFile2D* self = (TmxFile2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'spriteTextureEdgeOffset'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSpriteTextureEdgeOffset());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: spriteTextureEdgeOffset of class  TmxFile2D */
#ifndef TOLUA_DISABLE_tolua_set_TmxFile2D_edgeOffset
static int tolua_set_TmxFile2D_edgeOffset(lua_State* tolua_S)
{
  TmxFile2D* self = (TmxFile2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'spriteTextureEdgeOffset'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSpriteTextureEdgeOffset(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTmxFile of class  TileMap2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMap2D_SetTmxFile00
static int tolua_Urho2DLuaAPI_TileMap2D_SetTmxFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TileMap2D",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"TmxFile2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TileMap2D* self = (TileMap2D*)  tolua_tousertype(tolua_S,1,0);
  TmxFile2D* tmxFile = ((TmxFile2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTmxFile'", NULL);
#endif
 {
  self->SetTmxFile(tmxFile);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTmxFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTmxFile of class  TileMap2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMap2D_GetTmxFile00
static int tolua_Urho2DLuaAPI_TileMap2D_GetTmxFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMap2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMap2D* self = (const TileMap2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTmxFile'", NULL);
#endif
 {
  TmxFile2D* tolua_ret = (TmxFile2D*)  self->GetTmxFile();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"TmxFile2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTmxFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInfo of class  TileMap2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMap2D_GetInfo00
static int tolua_Urho2DLuaAPI_TileMap2D_GetInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMap2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMap2D* self = (const TileMap2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInfo'", NULL);
#endif
 {
  const TileMapInfo2D& tolua_ret = (const TileMapInfo2D&)  self->GetInfo();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const TileMapInfo2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumLayers of class  TileMap2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMap2D_GetNumLayers00
static int tolua_Urho2DLuaAPI_TileMap2D_GetNumLayers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMap2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMap2D* self = (const TileMap2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumLayers'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumLayers();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumLayers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLayer of class  TileMap2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMap2D_GetLayer00
static int tolua_Urho2DLuaAPI_TileMap2D_GetLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMap2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMap2D* self = (const TileMap2D*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLayer'", NULL);
#endif
 {
  TileMapLayer2D* tolua_ret = (TileMapLayer2D*)  self->GetLayer(index);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"TileMapLayer2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: TileIndexToPosition of class  TileMap2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMap2D_TileIndexToPosition00
static int tolua_Urho2DLuaAPI_TileMap2D_TileIndexToPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMap2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMap2D* self = (const TileMap2D*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TileIndexToPosition'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->TileIndexToPosition(x,y);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TileIndexToPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: TileMap2DPositionToTileIndex of class  TileMap2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMap2D_PositionToTileIndex00
static int tolua_Urho2DLuaAPI_TileMap2D_PositionToTileIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMap2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMap2D* self = (const TileMap2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* position = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TileMap2DPositionToTileIndex'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  TileMap2DPositionToTileIndex(self,*position,&x,&y);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 tolua_pushnumber(tolua_S,(lua_Number)x);
 tolua_pushnumber(tolua_S,(lua_Number)y);
 }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PositionToTileIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tmxFile of class  TileMap2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMap2D_tmxFile_ptr
static int tolua_get_TileMap2D_tmxFile_ptr(lua_State* tolua_S)
{
  TileMap2D* self = (TileMap2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tmxFile'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetTmxFile(),"TmxFile2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tmxFile of class  TileMap2D */
#ifndef TOLUA_DISABLE_tolua_set_TileMap2D_tmxFile_ptr
static int tolua_set_TileMap2D_tmxFile_ptr(lua_State* tolua_S)
{
  TileMap2D* self = (TileMap2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tmxFile'",NULL);
 if (!tolua_isusertype(tolua_S,2,"TmxFile2D",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTmxFile(((TmxFile2D*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: info of class  TileMap2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMap2D_info_ref
static int tolua_get_TileMap2D_info_ref(lua_State* tolua_S)
{
  TileMap2D* self = (TileMap2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'info'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetInfo(),"TileMapInfo2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numLayers of class  TileMap2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMap2D_numLayers
static int tolua_get_TileMap2D_numLayers(lua_State* tolua_S)
{
  TileMap2D* self = (TileMap2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numLayers'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumLayers());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDrawOrder of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapLayer2D_SetDrawOrder00
static int tolua_Urho2DLuaAPI_TileMapLayer2D_SetDrawOrder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TileMapLayer2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TileMapLayer2D* self = (TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
  int drawOrder = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDrawOrder'", NULL);
#endif
 {
  self->SetDrawOrder(drawOrder);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDrawOrder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisible of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapLayer2D_SetVisible00
static int tolua_Urho2DLuaAPI_TileMapLayer2D_SetVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TileMapLayer2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TileMapLayer2D* self = (TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
  bool visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisible'", NULL);
#endif
 {
  self->SetVisible(visible);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDrawOrder of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapLayer2D_GetDrawOrder00
static int tolua_Urho2DLuaAPI_TileMapLayer2D_GetDrawOrder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapLayer2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapLayer2D* self = (const TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDrawOrder'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetDrawOrder();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDrawOrder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsVisible of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapLayer2D_IsVisible00
static int tolua_Urho2DLuaAPI_TileMapLayer2D_IsVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapLayer2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapLayer2D* self = (const TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsVisible'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsVisible();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasProperty of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapLayer2D_HasProperty00
static int tolua_Urho2DLuaAPI_TileMapLayer2D_HasProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapLayer2D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapLayer2D* self = (const TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasProperty'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasProperty(name);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProperty of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapLayer2D_GetProperty00
static int tolua_Urho2DLuaAPI_TileMapLayer2D_GetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapLayer2D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapLayer2D* self = (const TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProperty'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetProperty(name);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLayerType of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapLayer2D_GetLayerType00
static int tolua_Urho2DLuaAPI_TileMapLayer2D_GetLayerType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapLayer2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapLayer2D* self = (const TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLayerType'", NULL);
#endif
 {
  TileMapLayerType2D tolua_ret = (TileMapLayerType2D)  self->GetLayerType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLayerType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidth of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapLayer2D_GetWidth00
static int tolua_Urho2DLuaAPI_TileMapLayer2D_GetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapLayer2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapLayer2D* self = (const TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWidth'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetWidth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeight of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapLayer2D_GetHeight00
static int tolua_Urho2DLuaAPI_TileMapLayer2D_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapLayer2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapLayer2D* self = (const TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeight'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetHeight();
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

/* method: GetTileNode of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapLayer2D_GetTileNode00
static int tolua_Urho2DLuaAPI_TileMapLayer2D_GetTileNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapLayer2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapLayer2D* self = (const TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTileNode'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->GetTileNode(x,y);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTileNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTile of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapLayer2D_GetTile00
static int tolua_Urho2DLuaAPI_TileMapLayer2D_GetTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapLayer2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapLayer2D* self = (const TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTile'", NULL);
#endif
 {
  Tile2D* tolua_ret = (Tile2D*)  self->GetTile(x,y);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Tile2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumObjects of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapLayer2D_GetNumObjects00
static int tolua_Urho2DLuaAPI_TileMapLayer2D_GetNumObjects00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapLayer2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapLayer2D* self = (const TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumObjects'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumObjects();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumObjects'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObject of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapLayer2D_GetObject00
static int tolua_Urho2DLuaAPI_TileMapLayer2D_GetObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapLayer2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapLayer2D* self = (const TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObject'", NULL);
#endif
 {
  TileMapObject2D* tolua_ret = (TileMapObject2D*)  self->GetObject(index);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"TileMapObject2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjectNode of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapLayer2D_GetObjectNode00
static int tolua_Urho2DLuaAPI_TileMapLayer2D_GetObjectNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapLayer2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapLayer2D* self = (const TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectNode'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->GetObjectNode(index);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetImageNode of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_TileMapLayer2D_GetImageNode00
static int tolua_Urho2DLuaAPI_TileMapLayer2D_GetImageNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const TileMapLayer2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const TileMapLayer2D* self = (const TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetImageNode'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->GetImageNode();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetImageNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: drawOrder of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapLayer2D_drawOrder
static int tolua_get_TileMapLayer2D_drawOrder(lua_State* tolua_S)
{
  TileMapLayer2D* self = (TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawOrder'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDrawOrder());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: visible of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapLayer2D_visible
static int tolua_get_TileMapLayer2D_visible(lua_State* tolua_S)
{
  TileMapLayer2D* self = (TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'visible'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsVisible());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: layerType of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapLayer2D_layerType
static int tolua_get_TileMapLayer2D_layerType(lua_State* tolua_S)
{
  TileMapLayer2D* self = (TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layerType'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLayerType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapLayer2D_width
static int tolua_get_TileMapLayer2D_width(lua_State* tolua_S)
{
  TileMapLayer2D* self = (TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetWidth());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapLayer2D_height
static int tolua_get_TileMapLayer2D_height(lua_State* tolua_S)
{
  TileMapLayer2D* self = (TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetHeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numObjects of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapLayer2D_numObjects
static int tolua_get_TileMapLayer2D_numObjects(lua_State* tolua_S)
{
  TileMapLayer2D* self = (TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numObjects'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumObjects());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: imageNode of class  TileMapLayer2D */
#ifndef TOLUA_DISABLE_tolua_get_TileMapLayer2D_imageNode_ptr
static int tolua_get_TileMapLayer2D_imageNode_ptr(lua_State* tolua_S)
{
  TileMapLayer2D* self = (TileMapLayer2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageNode'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetImageNode(),"Node");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBodyType of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_SetBodyType00
static int tolua_Urho2DLuaAPI_RigidBody2D_SetBodyType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  BodyType2D bodyType = ((BodyType2D) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBodyType'", NULL);
#endif
 {
  self->SetBodyType(bodyType);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBodyType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMass of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_SetMass00
static int tolua_Urho2DLuaAPI_RigidBody2D_SetMass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetInertia of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_SetInertia00
static int tolua_Urho2DLuaAPI_RigidBody2D_SetInertia00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  float inertia = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInertia'", NULL);
#endif
 {
  self->SetInertia(inertia);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInertia'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMassCenter of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_SetMassCenter00
static int tolua_Urho2DLuaAPI_RigidBody2D_SetMassCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* center = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMassCenter'", NULL);
#endif
 {
  self->SetMassCenter(*center);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMassCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseFixtureMass of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_SetUseFixtureMass00
static int tolua_Urho2DLuaAPI_RigidBody2D_SetUseFixtureMass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  bool useFixtureMass = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseFixtureMass'", NULL);
#endif
 {
  self->SetUseFixtureMass(useFixtureMass);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseFixtureMass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLinearDamping of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_SetLinearDamping00
static int tolua_Urho2DLuaAPI_RigidBody2D_SetLinearDamping00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  float linearDamping = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLinearDamping'", NULL);
#endif
 {
  self->SetLinearDamping(linearDamping);
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

/* method: SetAngularDamping of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_SetAngularDamping00
static int tolua_Urho2DLuaAPI_RigidBody2D_SetAngularDamping00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  float angularDamping = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngularDamping'", NULL);
#endif
 {
  self->SetAngularDamping(angularDamping);
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

/* method: SetAllowSleep of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_SetAllowSleep00
static int tolua_Urho2DLuaAPI_RigidBody2D_SetAllowSleep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  bool allowSleep = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAllowSleep'", NULL);
#endif
 {
  self->SetAllowSleep(allowSleep);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAllowSleep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFixedRotation of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_SetFixedRotation00
static int tolua_Urho2DLuaAPI_RigidBody2D_SetFixedRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  bool fixedRotation = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFixedRotation'", NULL);
#endif
 {
  self->SetFixedRotation(fixedRotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFixedRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBullet of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_SetBullet00
static int tolua_Urho2DLuaAPI_RigidBody2D_SetBullet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  bool bullet = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBullet'", NULL);
#endif
 {
  self->SetBullet(bullet);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBullet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetGravityScale of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_SetGravityScale00
static int tolua_Urho2DLuaAPI_RigidBody2D_SetGravityScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  float gravityScale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetGravityScale'", NULL);
#endif
 {
  self->SetGravityScale(gravityScale);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetGravityScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAwake of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_SetAwake00
static int tolua_Urho2DLuaAPI_RigidBody2D_SetAwake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  bool awake = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAwake'", NULL);
#endif
 {
  self->SetAwake(awake);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAwake'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLinearVelocity of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_SetLinearVelocity00
static int tolua_Urho2DLuaAPI_RigidBody2D_SetLinearVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* linearVelocity = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLinearVelocity'", NULL);
#endif
 {
  self->SetLinearVelocity(*linearVelocity);
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

/* method: SetAngularVelocity of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_SetAngularVelocity00
static int tolua_Urho2DLuaAPI_RigidBody2D_SetAngularVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  float angularVelocity = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngularVelocity'", NULL);
#endif
 {
  self->SetAngularVelocity(angularVelocity);
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

/* method: ApplyForce of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_ApplyForce00
static int tolua_Urho2DLuaAPI_RigidBody2D_ApplyForce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* force = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* point = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  bool wake = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyForce'", NULL);
#endif
 {
  self->ApplyForce(*force,*point,wake);
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

/* method: ApplyForceToCenter of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_ApplyForceToCenter00
static int tolua_Urho2DLuaAPI_RigidBody2D_ApplyForceToCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* force = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  bool wake = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyForceToCenter'", NULL);
#endif
 {
  self->ApplyForceToCenter(*force,wake);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyForceToCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyTorque of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_ApplyTorque00
static int tolua_Urho2DLuaAPI_RigidBody2D_ApplyTorque00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  float torque = ((float)  tolua_tonumber(tolua_S,2,0));
  bool wake = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyTorque'", NULL);
#endif
 {
  self->ApplyTorque(torque,wake);
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

/* method: ApplyLinearImpulse of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_ApplyLinearImpulse00
static int tolua_Urho2DLuaAPI_RigidBody2D_ApplyLinearImpulse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* impulse = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* point = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  bool wake = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyLinearImpulse'", NULL);
#endif
 {
  self->ApplyLinearImpulse(*impulse,*point,wake);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyLinearImpulse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyLinearImpulseToCenter of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_ApplyLinearImpulseToCenter00
static int tolua_Urho2DLuaAPI_RigidBody2D_ApplyLinearImpulseToCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* impulse = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  bool wake = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyLinearImpulseToCenter'", NULL);
#endif
 {
  self->ApplyLinearImpulseToCenter(*impulse,wake);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyLinearImpulseToCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyAngularImpulse of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_ApplyAngularImpulse00
static int tolua_Urho2DLuaAPI_RigidBody2D_ApplyAngularImpulse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"RigidBody2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
  float impulse = ((float)  tolua_tonumber(tolua_S,2,0));
  bool wake = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyAngularImpulse'", NULL);
#endif
 {
  self->ApplyAngularImpulse(impulse,wake);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyAngularImpulse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBodyType of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_GetBodyType00
static int tolua_Urho2DLuaAPI_RigidBody2D_GetBodyType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody2D* self = (const RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBodyType'", NULL);
#endif
 {
  BodyType2D tolua_ret = (BodyType2D)  self->GetBodyType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBodyType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMass of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_GetMass00
static int tolua_Urho2DLuaAPI_RigidBody2D_GetMass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody2D* self = (const RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetInertia of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_GetInertia00
static int tolua_Urho2DLuaAPI_RigidBody2D_GetInertia00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody2D* self = (const RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInertia'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetInertia();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInertia'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMassCenter of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_GetMassCenter00
static int tolua_Urho2DLuaAPI_RigidBody2D_GetMassCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody2D* self = (const RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMassCenter'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->GetMassCenter();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMassCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUseFixtureMass of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_GetUseFixtureMass00
static int tolua_Urho2DLuaAPI_RigidBody2D_GetUseFixtureMass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody2D* self = (const RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUseFixtureMass'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetUseFixtureMass();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUseFixtureMass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLinearDamping of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_GetLinearDamping00
static int tolua_Urho2DLuaAPI_RigidBody2D_GetLinearDamping00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody2D* self = (const RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetAngularDamping of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_GetAngularDamping00
static int tolua_Urho2DLuaAPI_RigidBody2D_GetAngularDamping00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody2D* self = (const RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsAllowSleep of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_IsAllowSleep00
static int tolua_Urho2DLuaAPI_RigidBody2D_IsAllowSleep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody2D* self = (const RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsAllowSleep'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsAllowSleep();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsAllowSleep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsFixedRotation of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_IsFixedRotation00
static int tolua_Urho2DLuaAPI_RigidBody2D_IsFixedRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody2D* self = (const RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsFixedRotation'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsFixedRotation();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsFixedRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsBullet of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_IsBullet00
static int tolua_Urho2DLuaAPI_RigidBody2D_IsBullet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody2D* self = (const RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsBullet'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsBullet();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsBullet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGravityScale of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_GetGravityScale00
static int tolua_Urho2DLuaAPI_RigidBody2D_GetGravityScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody2D* self = (const RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGravityScale'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetGravityScale();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGravityScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsAwake of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_IsAwake00
static int tolua_Urho2DLuaAPI_RigidBody2D_IsAwake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody2D* self = (const RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsAwake'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsAwake();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsAwake'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLinearVelocity of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_GetLinearVelocity00
static int tolua_Urho2DLuaAPI_RigidBody2D_GetLinearVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody2D* self = (const RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLinearVelocity'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->GetLinearVelocity();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
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

/* method: GetAngularVelocity of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_RigidBody2D_GetAngularVelocity00
static int tolua_Urho2DLuaAPI_RigidBody2D_GetAngularVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const RigidBody2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const RigidBody2D* self = (const RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAngularVelocity'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAngularVelocity();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* get function: bodyType of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody2D_bodyType
static int tolua_get_RigidBody2D_bodyType(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bodyType'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetBodyType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bodyType of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody2D_bodyType
static int tolua_set_RigidBody2D_bodyType(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bodyType'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetBodyType(((BodyType2D) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mass of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody2D_mass
static int tolua_get_RigidBody2D_mass(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mass'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMass());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mass of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody2D_mass
static int tolua_set_RigidBody2D_mass(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: inertia of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody2D_inertia
static int tolua_get_RigidBody2D_inertia(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'inertia'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetInertia());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: inertia of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody2D_inertia
static int tolua_set_RigidBody2D_inertia(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'inertia'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetInertia(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: massCenter of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody2D_massCenter
static int tolua_get_RigidBody2D_massCenter(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'massCenter'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->GetMassCenter();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector2)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: massCenter of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody2D_massCenter
static int tolua_set_RigidBody2D_massCenter(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'massCenter'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMassCenter(*((Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: useFixtureMass of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody2D_useFixtureMass
static int tolua_get_RigidBody2D_useFixtureMass(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useFixtureMass'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetUseFixtureMass());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: useFixtureMass of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody2D_useFixtureMass
static int tolua_set_RigidBody2D_useFixtureMass(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useFixtureMass'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUseFixtureMass(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: linearDamping of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody2D_linearDamping
static int tolua_get_RigidBody2D_linearDamping(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'linearDamping'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLinearDamping());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: linearDamping of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody2D_linearDamping
static int tolua_set_RigidBody2D_linearDamping(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: angularDamping of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody2D_angularDamping
static int tolua_get_RigidBody2D_angularDamping(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'angularDamping'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAngularDamping());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: angularDamping of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody2D_angularDamping
static int tolua_set_RigidBody2D_angularDamping(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: allowSleep of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody2D_allowSleep
static int tolua_get_RigidBody2D_allowSleep(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'allowSleep'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsAllowSleep());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: allowSleep of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody2D_allowSleep
static int tolua_set_RigidBody2D_allowSleep(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'allowSleep'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAllowSleep(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fixedRotation of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody2D_fixedRotation
static int tolua_get_RigidBody2D_fixedRotation(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fixedRotation'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsFixedRotation());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: fixedRotation of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody2D_fixedRotation
static int tolua_set_RigidBody2D_fixedRotation(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fixedRotation'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFixedRotation(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bullet of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody2D_bullet
static int tolua_get_RigidBody2D_bullet(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bullet'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsBullet());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bullet of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody2D_bullet
static int tolua_set_RigidBody2D_bullet(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bullet'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetBullet(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: gravityScale of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody2D_gravityScale
static int tolua_get_RigidBody2D_gravityScale(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gravityScale'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetGravityScale());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: gravityScale of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody2D_gravityScale
static int tolua_set_RigidBody2D_gravityScale(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gravityScale'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetGravityScale(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: awake of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody2D_awake
static int tolua_get_RigidBody2D_awake(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'awake'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsAwake());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: awake of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody2D_awake
static int tolua_set_RigidBody2D_awake(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'awake'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAwake(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: linearVelocity of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody2D_linearVelocity
static int tolua_get_RigidBody2D_linearVelocity(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'linearVelocity'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->GetLinearVelocity();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector2)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: linearVelocity of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody2D_linearVelocity
static int tolua_set_RigidBody2D_linearVelocity(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'linearVelocity'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLinearVelocity(*((Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: angularVelocity of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_get_RigidBody2D_angularVelocity
static int tolua_get_RigidBody2D_angularVelocity(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'angularVelocity'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAngularVelocity());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: angularVelocity of class  RigidBody2D */
#ifndef TOLUA_DISABLE_tolua_set_RigidBody2D_angularVelocity
static int tolua_set_RigidBody2D_angularVelocity(lua_State* tolua_S)
{
  RigidBody2D* self = (RigidBody2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'angularVelocity'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAngularVelocity(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  PhysicsRaycastResult2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsRaycastResult2D_new00
static int tolua_Urho2DLuaAPI_PhysicsRaycastResult2D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PhysicsRaycastResult2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PhysicsRaycastResult2D* tolua_ret = (PhysicsRaycastResult2D*)  Mtolua_new((PhysicsRaycastResult2D)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"PhysicsRaycastResult2D");
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

/* method: new_local of class  PhysicsRaycastResult2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsRaycastResult2D_new00_local
static int tolua_Urho2DLuaAPI_PhysicsRaycastResult2D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PhysicsRaycastResult2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PhysicsRaycastResult2D* tolua_ret = (PhysicsRaycastResult2D*)  Mtolua_new((PhysicsRaycastResult2D)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"PhysicsRaycastResult2D");
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

/* method: delete of class  PhysicsRaycastResult2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsRaycastResult2D_delete00
static int tolua_Urho2DLuaAPI_PhysicsRaycastResult2D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsRaycastResult2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsRaycastResult2D* self = (PhysicsRaycastResult2D*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: position_ of class  PhysicsRaycastResult2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsRaycastResult2D_position
static int tolua_get_PhysicsRaycastResult2D_position(lua_State* tolua_S)
{
  PhysicsRaycastResult2D* self = (PhysicsRaycastResult2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->position_,"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: position_ of class  PhysicsRaycastResult2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsRaycastResult2D_position
static int tolua_set_PhysicsRaycastResult2D_position(lua_State* tolua_S)
{
  PhysicsRaycastResult2D* self = (PhysicsRaycastResult2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->position_ = *((Vector2*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: normal_ of class  PhysicsRaycastResult2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsRaycastResult2D_normal
static int tolua_get_PhysicsRaycastResult2D_normal(lua_State* tolua_S)
{
  PhysicsRaycastResult2D* self = (PhysicsRaycastResult2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'normal_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->normal_,"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: normal_ of class  PhysicsRaycastResult2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsRaycastResult2D_normal
static int tolua_set_PhysicsRaycastResult2D_normal(lua_State* tolua_S)
{
  PhysicsRaycastResult2D* self = (PhysicsRaycastResult2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'normal_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->normal_ = *((Vector2*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: distance_ of class  PhysicsRaycastResult2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsRaycastResult2D_distance
static int tolua_get_PhysicsRaycastResult2D_distance(lua_State* tolua_S)
{
  PhysicsRaycastResult2D* self = (PhysicsRaycastResult2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'distance_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->distance_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: distance_ of class  PhysicsRaycastResult2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsRaycastResult2D_distance
static int tolua_set_PhysicsRaycastResult2D_distance(lua_State* tolua_S)
{
  PhysicsRaycastResult2D* self = (PhysicsRaycastResult2D*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: body_ of class  PhysicsRaycastResult2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsRaycastResult2D_body_ptr
static int tolua_get_PhysicsRaycastResult2D_body_ptr(lua_State* tolua_S)
{
  PhysicsRaycastResult2D* self = (PhysicsRaycastResult2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'body_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->body_,"RigidBody2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: body_ of class  PhysicsRaycastResult2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsRaycastResult2D_body_ptr
static int tolua_set_PhysicsRaycastResult2D_body_ptr(lua_State* tolua_S)
{
  PhysicsRaycastResult2D* self = (PhysicsRaycastResult2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'body_'",NULL);
 if (!tolua_isusertype(tolua_S,2,"RigidBody2D",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->body_ = ((RigidBody2D*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawDebugGeometry of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_DrawDebugGeometry00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_DrawDebugGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawDebugGeometry'", NULL);
#endif
 {
  self->DrawDebugGeometry();
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

/* method: SetUpdateEnabled of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_SetUpdateEnabled00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_SetUpdateEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetDrawShape of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_SetDrawShape00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_SetDrawShape00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  bool drawShape = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDrawShape'", NULL);
#endif
 {
  self->SetDrawShape(drawShape);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDrawShape'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDrawJoint of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_SetDrawJoint00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_SetDrawJoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  bool drawJoint = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDrawJoint'", NULL);
#endif
 {
  self->SetDrawJoint(drawJoint);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDrawJoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDrawAabb of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_SetDrawAabb00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_SetDrawAabb00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  bool drawAabb = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDrawAabb'", NULL);
#endif
 {
  self->SetDrawAabb(drawAabb);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDrawAabb'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDrawPair of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_SetDrawPair00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_SetDrawPair00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  bool drawPair = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDrawPair'", NULL);
#endif
 {
  self->SetDrawPair(drawPair);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDrawPair'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDrawCenterOfMass of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_SetDrawCenterOfMass00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_SetDrawCenterOfMass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  bool drawCenterOfMass = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDrawCenterOfMass'", NULL);
#endif
 {
  self->SetDrawCenterOfMass(drawCenterOfMass);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDrawCenterOfMass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAllowSleeping of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_SetAllowSleeping00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_SetAllowSleeping00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAllowSleeping'", NULL);
#endif
 {
  self->SetAllowSleeping(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAllowSleeping'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWarmStarting of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_SetWarmStarting00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_SetWarmStarting00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWarmStarting'", NULL);
#endif
 {
  self->SetWarmStarting(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWarmStarting'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetContinuousPhysics of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_SetContinuousPhysics00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_SetContinuousPhysics00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetContinuousPhysics'", NULL);
#endif
 {
  self->SetContinuousPhysics(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetContinuousPhysics'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSubStepping of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_SetSubStepping00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_SetSubStepping00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSubStepping'", NULL);
#endif
 {
  self->SetSubStepping(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSubStepping'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetGravity of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_SetGravity00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_SetGravity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* gravity = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
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

/* method: SetAutoClearForces of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_SetAutoClearForces00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_SetAutoClearForces00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAutoClearForces'", NULL);
#endif
 {
  self->SetAutoClearForces(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAutoClearForces'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVelocityIterations of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_SetVelocityIterations00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_SetVelocityIterations00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  int velocityIterations = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVelocityIterations'", NULL);
#endif
 {
  self->SetVelocityIterations(velocityIterations);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVelocityIterations'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPositionIterations of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_SetPositionIterations00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_SetPositionIterations00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  int positionIterations = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPositionIterations'", NULL);
#endif
 {
  self->SetPositionIterations(positionIterations);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPositionIterations'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PhysicsWorld2DRaycast of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_Raycast00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_Raycast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* startPoint = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* endPoint = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  unsigned collisionMask = ((unsigned)  tolua_tonumber(tolua_S,4,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PhysicsWorld2DRaycast'", NULL);
#endif
 {
  tolua_outside  const PODVector<PhysicsRaycastResult2D>& tolua_ret = (tolua_outside  const PODVector<PhysicsRaycastResult2D>&)  PhysicsWorld2DRaycast(self,*startPoint,*endPoint,collisionMask);
  ToluaPushPODVector<PhysicsRaycastResult2D>(tolua_S,(void*)&tolua_ret,"PhysicsRaycastResult2D");
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

/* method: PhysicsWorld2DRaycastSingle of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_RaycastSingle00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_RaycastSingle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* startPoint = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* endPoint = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  unsigned collisionMask = ((unsigned)  tolua_tonumber(tolua_S,4,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PhysicsWorld2DRaycastSingle'", NULL);
#endif
 {
  tolua_outside PhysicsRaycastResult2D tolua_ret = (tolua_outside PhysicsRaycastResult2D)  PhysicsWorld2DRaycastSingle(self,*startPoint,*endPoint,collisionMask);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((PhysicsRaycastResult2D)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"PhysicsRaycastResult2D");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(PhysicsRaycastResult2D));
  tolua_pushusertype(tolua_S,tolua_obj,"PhysicsRaycastResult2D");
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

/* method: GetRigidBody of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetRigidBody00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetRigidBody00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* point = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  unsigned collisionMask = ((unsigned)  tolua_tonumber(tolua_S,3,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRigidBody'", NULL);
#endif
 {
  RigidBody2D* tolua_ret = (RigidBody2D*)  self->GetRigidBody(*point,collisionMask);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"RigidBody2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRigidBody'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRigidBody of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetRigidBody01
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetRigidBody01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  int screenX = ((int)  tolua_tonumber(tolua_S,2,0));
  int screenY = ((int)  tolua_tonumber(tolua_S,3,0));
  unsigned collisionMask = ((unsigned)  tolua_tonumber(tolua_S,4,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRigidBody'", NULL);
#endif
 {
  RigidBody2D* tolua_ret = (RigidBody2D*)  self->GetRigidBody(screenX,screenY,collisionMask);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"RigidBody2D");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Urho2DLuaAPI_PhysicsWorld2D_GetRigidBody00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: PhysicsWorld2DGetRigidBodies of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetRigidBodies00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetRigidBodies00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PhysicsWorld2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
  const Rect* aabb = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
  unsigned collisionMask = ((unsigned)  tolua_tonumber(tolua_S,3,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PhysicsWorld2DGetRigidBodies'", NULL);
#endif
 {
  tolua_outside  const PODVector<RigidBody2D*>& tolua_ret = (tolua_outside  const PODVector<RigidBody2D*>&)  PhysicsWorld2DGetRigidBodies(self,*aabb,collisionMask);
  ToluaPushPODVector<RigidBody2D*>("",tolua_S,(void*)&tolua_ret,"RigidBody2D");
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

/* method: IsUpdateEnabled of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_IsUpdateEnabled00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_IsUpdateEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld2D* self = (const PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetDrawShape of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetDrawShape00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetDrawShape00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld2D* self = (const PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDrawShape'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetDrawShape();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDrawShape'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDrawJoint of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetDrawJoint00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetDrawJoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld2D* self = (const PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDrawJoint'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetDrawJoint();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDrawJoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDrawAabb of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetDrawAabb00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetDrawAabb00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld2D* self = (const PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDrawAabb'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetDrawAabb();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDrawAabb'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDrawPair of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetDrawPair00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetDrawPair00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld2D* self = (const PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDrawPair'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetDrawPair();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDrawPair'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDrawCenterOfMass of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetDrawCenterOfMass00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetDrawCenterOfMass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld2D* self = (const PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDrawCenterOfMass'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetDrawCenterOfMass();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDrawCenterOfMass'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllowSleeping of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetAllowSleeping00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetAllowSleeping00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld2D* self = (const PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllowSleeping'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetAllowSleeping();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllowSleeping'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWarmStarting of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetWarmStarting00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetWarmStarting00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld2D* self = (const PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWarmStarting'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetWarmStarting();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWarmStarting'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetContinuousPhysics of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetContinuousPhysics00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetContinuousPhysics00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld2D* self = (const PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetContinuousPhysics'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetContinuousPhysics();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetContinuousPhysics'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSubStepping of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetSubStepping00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetSubStepping00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld2D* self = (const PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSubStepping'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetSubStepping();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSubStepping'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAutoClearForces of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetAutoClearForces00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetAutoClearForces00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld2D* self = (const PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAutoClearForces'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetAutoClearForces();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAutoClearForces'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGravity of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetGravity00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetGravity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld2D* self = (const PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGravity'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetGravity();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
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

/* method: GetVelocityIterations of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetVelocityIterations00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetVelocityIterations00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld2D* self = (const PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVelocityIterations'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetVelocityIterations();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVelocityIterations'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPositionIterations of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_PhysicsWorld2D_GetPositionIterations00
static int tolua_Urho2DLuaAPI_PhysicsWorld2D_GetPositionIterations00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PhysicsWorld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PhysicsWorld2D* self = (const PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPositionIterations'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetPositionIterations();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPositionIterations'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: updateEnabled of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld2D_updateEnabled
static int tolua_get_PhysicsWorld2D_updateEnabled(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'updateEnabled'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsUpdateEnabled());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: updateEnabled of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld2D_updateEnabled
static int tolua_set_PhysicsWorld2D_updateEnabled(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: drawShape of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld2D_drawShape
static int tolua_get_PhysicsWorld2D_drawShape(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawShape'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetDrawShape());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: drawShape of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld2D_drawShape
static int tolua_set_PhysicsWorld2D_drawShape(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawShape'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDrawShape(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: drawJoint of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld2D_drawJoint
static int tolua_get_PhysicsWorld2D_drawJoint(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawJoint'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetDrawJoint());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: drawJoint of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld2D_drawJoint
static int tolua_set_PhysicsWorld2D_drawJoint(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawJoint'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDrawJoint(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: drawAabb of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld2D_drawAabb
static int tolua_get_PhysicsWorld2D_drawAabb(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawAabb'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetDrawAabb());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: drawAabb of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld2D_drawAabb
static int tolua_set_PhysicsWorld2D_drawAabb(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawAabb'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDrawAabb(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: drawPair of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld2D_drawPair
static int tolua_get_PhysicsWorld2D_drawPair(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawPair'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetDrawPair());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: drawPair of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld2D_drawPair
static int tolua_set_PhysicsWorld2D_drawPair(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawPair'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDrawPair(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: drawCenterOfMass of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld2D_drawCenterOfMass
static int tolua_get_PhysicsWorld2D_drawCenterOfMass(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawCenterOfMass'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetDrawCenterOfMass());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: drawCenterOfMass of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld2D_drawCenterOfMass
static int tolua_set_PhysicsWorld2D_drawCenterOfMass(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'drawCenterOfMass'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDrawCenterOfMass(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: allowSleeping of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld2D_allowSleeping
static int tolua_get_PhysicsWorld2D_allowSleeping(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'allowSleeping'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetAllowSleeping());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: allowSleeping of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld2D_allowSleeping
static int tolua_set_PhysicsWorld2D_allowSleeping(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'allowSleeping'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAllowSleeping(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: warmStarting of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld2D_warmStarting
static int tolua_get_PhysicsWorld2D_warmStarting(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'warmStarting'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetWarmStarting());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: warmStarting of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld2D_warmStarting
static int tolua_set_PhysicsWorld2D_warmStarting(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'warmStarting'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetWarmStarting(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: continuousPhysics of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld2D_continuousPhysics
static int tolua_get_PhysicsWorld2D_continuousPhysics(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'continuousPhysics'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetContinuousPhysics());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: continuousPhysics of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld2D_continuousPhysics
static int tolua_set_PhysicsWorld2D_continuousPhysics(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'continuousPhysics'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetContinuousPhysics(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: subStepping of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld2D_subStepping
static int tolua_get_PhysicsWorld2D_subStepping(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'subStepping'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetSubStepping());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: subStepping of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld2D_subStepping
static int tolua_set_PhysicsWorld2D_subStepping(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'subStepping'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSubStepping(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: autoClearForces of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld2D_autoClearForces
static int tolua_get_PhysicsWorld2D_autoClearForces(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'autoClearForces'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetAutoClearForces());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: autoClearForces of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld2D_autoClearForces
static int tolua_set_PhysicsWorld2D_autoClearForces(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'autoClearForces'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAutoClearForces(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: gravity of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld2D_gravity_ref
static int tolua_get_PhysicsWorld2D_gravity_ref(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gravity'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetGravity(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: gravity of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld2D_gravity_ref
static int tolua_set_PhysicsWorld2D_gravity_ref(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gravity'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetGravity((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: velocityIterations of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld2D_velocityIterations
static int tolua_get_PhysicsWorld2D_velocityIterations(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'velocityIterations'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetVelocityIterations());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: velocityIterations of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld2D_velocityIterations
static int tolua_set_PhysicsWorld2D_velocityIterations(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'velocityIterations'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetVelocityIterations(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: positionIterations of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_get_PhysicsWorld2D_positionIterations
static int tolua_get_PhysicsWorld2D_positionIterations(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'positionIterations'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetPositionIterations());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: positionIterations of class  PhysicsWorld2D */
#ifndef TOLUA_DISABLE_tolua_set_PhysicsWorld2D_positionIterations
static int tolua_set_PhysicsWorld2D_positionIterations(lua_State* tolua_S)
{
  PhysicsWorld2D* self = (PhysicsWorld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'positionIterations'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPositionIterations(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTrigger of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_SetTrigger00
static int tolua_Urho2DLuaAPI_CollisionShape2D_SetTrigger00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
  bool trigger = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTrigger'", NULL);
#endif
 {
  self->SetTrigger(trigger);
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

/* method: SetCategoryBits of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_SetCategoryBits00
static int tolua_Urho2DLuaAPI_CollisionShape2D_SetCategoryBits00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
  int categoryBits = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCategoryBits'", NULL);
#endif
 {
  self->SetCategoryBits(categoryBits);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCategoryBits'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaskBits of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_SetMaskBits00
static int tolua_Urho2DLuaAPI_CollisionShape2D_SetMaskBits00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
  int maskBits = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaskBits'", NULL);
#endif
 {
  self->SetMaskBits(maskBits);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaskBits'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetGroupIndex of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_SetGroupIndex00
static int tolua_Urho2DLuaAPI_CollisionShape2D_SetGroupIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
  int groupIndex = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetGroupIndex'", NULL);
#endif
 {
  self->SetGroupIndex(groupIndex);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetGroupIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDensity of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_SetDensity00
static int tolua_Urho2DLuaAPI_CollisionShape2D_SetDensity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
  float density = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDensity'", NULL);
#endif
 {
  self->SetDensity(density);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDensity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFriction of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_SetFriction00
static int tolua_Urho2DLuaAPI_CollisionShape2D_SetFriction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetRestitution of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_SetRestitution00
static int tolua_Urho2DLuaAPI_CollisionShape2D_SetRestitution00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionShape2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsTrigger of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_IsTrigger00
static int tolua_Urho2DLuaAPI_CollisionShape2D_IsTrigger00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape2D* self = (const CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetCategoryBits of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_GetCategoryBits00
static int tolua_Urho2DLuaAPI_CollisionShape2D_GetCategoryBits00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape2D* self = (const CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCategoryBits'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetCategoryBits();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCategoryBits'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaskBits of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_GetMaskBits00
static int tolua_Urho2DLuaAPI_CollisionShape2D_GetMaskBits00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape2D* self = (const CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaskBits'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetMaskBits();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaskBits'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGroupIndex of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_GetGroupIndex00
static int tolua_Urho2DLuaAPI_CollisionShape2D_GetGroupIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape2D* self = (const CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGroupIndex'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetGroupIndex();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGroupIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDensity of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_GetDensity00
static int tolua_Urho2DLuaAPI_CollisionShape2D_GetDensity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape2D* self = (const CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDensity'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDensity();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDensity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFriction of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_GetFriction00
static int tolua_Urho2DLuaAPI_CollisionShape2D_GetFriction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape2D* self = (const CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetRestitution of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_GetRestitution00
static int tolua_Urho2DLuaAPI_CollisionShape2D_GetRestitution00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape2D* self = (const CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetMass of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_GetMass00
static int tolua_Urho2DLuaAPI_CollisionShape2D_GetMass00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape2D* self = (const CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetInertia of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_GetInertia00
static int tolua_Urho2DLuaAPI_CollisionShape2D_GetInertia00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape2D* self = (const CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInertia'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetInertia();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInertia'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMassCenter of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionShape2D_GetMassCenter00
static int tolua_Urho2DLuaAPI_CollisionShape2D_GetMassCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionShape2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionShape2D* self = (const CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMassCenter'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->GetMassCenter();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMassCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: trigger of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape2D_trigger
static int tolua_get_CollisionShape2D_trigger(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'trigger'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsTrigger());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: trigger of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionShape2D_trigger
static int tolua_set_CollisionShape2D_trigger(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: categoryBits of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape2D_categoryBits
static int tolua_get_CollisionShape2D_categoryBits(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'categoryBits'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetCategoryBits());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: categoryBits of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionShape2D_categoryBits
static int tolua_set_CollisionShape2D_categoryBits(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'categoryBits'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCategoryBits(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maskBits of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape2D_maskBits
static int tolua_get_CollisionShape2D_maskBits(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maskBits'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaskBits());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maskBits of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionShape2D_maskBits
static int tolua_set_CollisionShape2D_maskBits(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maskBits'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaskBits(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: groupIndex of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape2D_groupIndex
static int tolua_get_CollisionShape2D_groupIndex(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'groupIndex'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetGroupIndex());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: groupIndex of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionShape2D_groupIndex
static int tolua_set_CollisionShape2D_groupIndex(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'groupIndex'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetGroupIndex(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: density of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape2D_density
static int tolua_get_CollisionShape2D_density(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'density'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDensity());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: density of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionShape2D_density
static int tolua_set_CollisionShape2D_density(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'density'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDensity(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: friction of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape2D_friction
static int tolua_get_CollisionShape2D_friction(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'friction'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFriction());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: friction of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionShape2D_friction
static int tolua_set_CollisionShape2D_friction(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: restitution of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape2D_restitution
static int tolua_get_CollisionShape2D_restitution(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'restitution'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRestitution());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: restitution of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionShape2D_restitution
static int tolua_set_CollisionShape2D_restitution(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: mass of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape2D_mass
static int tolua_get_CollisionShape2D_mass(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mass'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMass());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: inertia of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape2D_inertia
static int tolua_get_CollisionShape2D_inertia(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'inertia'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetInertia());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: massCenter of class  CollisionShape2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionShape2D_massCenter
static int tolua_get_CollisionShape2D_massCenter(lua_State* tolua_S)
{
  CollisionShape2D* self = (CollisionShape2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'massCenter'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->GetMassCenter();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Vector2)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  CollisionBox2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionBox2D_SetSize00
static int tolua_Urho2DLuaAPI_CollisionBox2D_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionBox2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionBox2D* self = (CollisionBox2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* size = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
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

/* method: SetSize of class  CollisionBox2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionBox2D_SetSize01
static int tolua_Urho2DLuaAPI_CollisionBox2D_SetSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionBox2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionBox2D* self = (CollisionBox2D*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
 {
  self->SetSize(width,height);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Urho2DLuaAPI_CollisionBox2D_SetSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCenter of class  CollisionBox2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionBox2D_SetCenter00
static int tolua_Urho2DLuaAPI_CollisionBox2D_SetCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionBox2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionBox2D* self = (CollisionBox2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* center = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCenter'", NULL);
#endif
 {
  self->SetCenter(*center);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCenter of class  CollisionBox2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionBox2D_SetCenter01
static int tolua_Urho2DLuaAPI_CollisionBox2D_SetCenter01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionBox2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionBox2D* self = (CollisionBox2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCenter'", NULL);
#endif
 {
  self->SetCenter(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Urho2DLuaAPI_CollisionBox2D_SetCenter00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAngle of class  CollisionBox2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionBox2D_SetAngle00
static int tolua_Urho2DLuaAPI_CollisionBox2D_SetAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionBox2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionBox2D* self = (CollisionBox2D*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngle'", NULL);
#endif
 {
  self->SetAngle(angle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSize of class  CollisionBox2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionBox2D_GetSize00
static int tolua_Urho2DLuaAPI_CollisionBox2D_GetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionBox2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionBox2D* self = (const CollisionBox2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSize'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetSize();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
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

/* method: GetCenter of class  CollisionBox2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionBox2D_GetCenter00
static int tolua_Urho2DLuaAPI_CollisionBox2D_GetCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionBox2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionBox2D* self = (const CollisionBox2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCenter'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetCenter();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAngle of class  CollisionBox2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionBox2D_GetAngle00
static int tolua_Urho2DLuaAPI_CollisionBox2D_GetAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionBox2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionBox2D* self = (const CollisionBox2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAngle'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAngle();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: size of class  CollisionBox2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionBox2D_size_ref
static int tolua_get_CollisionBox2D_size_ref(lua_State* tolua_S)
{
  CollisionBox2D* self = (CollisionBox2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetSize(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: size of class  CollisionBox2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionBox2D_size_ref
static int tolua_set_CollisionBox2D_size_ref(lua_State* tolua_S)
{
  CollisionBox2D* self = (CollisionBox2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSize((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: center of class  CollisionBox2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionBox2D_center_ref
static int tolua_get_CollisionBox2D_center_ref(lua_State* tolua_S)
{
  CollisionBox2D* self = (CollisionBox2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'center'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetCenter(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: center of class  CollisionBox2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionBox2D_center_ref
static int tolua_set_CollisionBox2D_center_ref(lua_State* tolua_S)
{
  CollisionBox2D* self = (CollisionBox2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'center'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCenter((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: angle of class  CollisionBox2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionBox2D_angle
static int tolua_get_CollisionBox2D_angle(lua_State* tolua_S)
{
  CollisionBox2D* self = (CollisionBox2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'angle'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAngle());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: angle of class  CollisionBox2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionBox2D_angle
static int tolua_set_CollisionBox2D_angle(lua_State* tolua_S)
{
  CollisionBox2D* self = (CollisionBox2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'angle'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAngle(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLoop of class  CollisionChain2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionChain2D_SetLoop00
static int tolua_Urho2DLuaAPI_CollisionChain2D_SetLoop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionChain2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionChain2D* self = (CollisionChain2D*)  tolua_tousertype(tolua_S,1,0);
  bool loop = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLoop'", NULL);
#endif
 {
  self->SetLoop(loop);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLoop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVertexCount of class  CollisionChain2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionChain2D_SetVertexCount00
static int tolua_Urho2DLuaAPI_CollisionChain2D_SetVertexCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionChain2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionChain2D* self = (CollisionChain2D*)  tolua_tousertype(tolua_S,1,0);
  unsigned count = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVertexCount'", NULL);
#endif
 {
  self->SetVertexCount(count);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVertexCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVertex of class  CollisionChain2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionChain2D_SetVertex00
static int tolua_Urho2DLuaAPI_CollisionChain2D_SetVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionChain2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionChain2D* self = (CollisionChain2D*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  const Vector2* vertex = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVertex'", NULL);
#endif
 {
  self->SetVertex(index,*vertex);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVertex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVertices of class  CollisionChain2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionChain2D_SetVertices00
static int tolua_Urho2DLuaAPI_CollisionChain2D_SetVertices00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionChain2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !ToluaIsPODVector<Vector2>(tolua_S,2,"Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionChain2D* self = (CollisionChain2D*)  tolua_tousertype(tolua_S,1,0);
  const PODVector<Vector2>* vertices = ((const PODVector<Vector2>*)  ToluaToPODVector<Vector2>(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVertices'", NULL);
#endif
 {
  self->SetVertices(*vertices);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVertices'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLoop of class  CollisionChain2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionChain2D_GetLoop00
static int tolua_Urho2DLuaAPI_CollisionChain2D_GetLoop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionChain2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionChain2D* self = (const CollisionChain2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLoop'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetLoop();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLoop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVertexCount of class  CollisionChain2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionChain2D_GetVertexCount00
static int tolua_Urho2DLuaAPI_CollisionChain2D_GetVertexCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionChain2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionChain2D* self = (const CollisionChain2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVertexCount'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetVertexCount();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVertexCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVertex of class  CollisionChain2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionChain2D_GetVertex00
static int tolua_Urho2DLuaAPI_CollisionChain2D_GetVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionChain2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionChain2D* self = (const CollisionChain2D*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVertex'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetVertex(index);
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVertex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: loop of class  CollisionChain2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionChain2D_loop
static int tolua_get_CollisionChain2D_loop(lua_State* tolua_S)
{
  CollisionChain2D* self = (CollisionChain2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loop'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetLoop());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: loop of class  CollisionChain2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionChain2D_loop
static int tolua_set_CollisionChain2D_loop(lua_State* tolua_S)
{
  CollisionChain2D* self = (CollisionChain2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loop'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLoop(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: vertexCount of class  CollisionChain2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionChain2D_vertexCount
static int tolua_get_CollisionChain2D_vertexCount(lua_State* tolua_S)
{
  CollisionChain2D* self = (CollisionChain2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'vertexCount'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetVertexCount());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: vertexCount of class  CollisionChain2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionChain2D_vertexCount
static int tolua_set_CollisionChain2D_vertexCount(lua_State* tolua_S)
{
  CollisionChain2D* self = (CollisionChain2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'vertexCount'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetVertexCount(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRadius of class  CollisionCircle2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionCircle2D_SetRadius00
static int tolua_Urho2DLuaAPI_CollisionCircle2D_SetRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionCircle2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionCircle2D* self = (CollisionCircle2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetCenter of class  CollisionCircle2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionCircle2D_SetCenter00
static int tolua_Urho2DLuaAPI_CollisionCircle2D_SetCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionCircle2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionCircle2D* self = (CollisionCircle2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* center = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCenter'", NULL);
#endif
 {
  self->SetCenter(*center);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCenter of class  CollisionCircle2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionCircle2D_SetCenter01
static int tolua_Urho2DLuaAPI_CollisionCircle2D_SetCenter01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionCircle2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CollisionCircle2D* self = (CollisionCircle2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCenter'", NULL);
#endif
 {
  self->SetCenter(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Urho2DLuaAPI_CollisionCircle2D_SetCenter00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRadius of class  CollisionCircle2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionCircle2D_GetRadius00
static int tolua_Urho2DLuaAPI_CollisionCircle2D_GetRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionCircle2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionCircle2D* self = (const CollisionCircle2D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetCenter of class  CollisionCircle2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionCircle2D_GetCenter00
static int tolua_Urho2DLuaAPI_CollisionCircle2D_GetCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionCircle2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionCircle2D* self = (const CollisionCircle2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCenter'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetCenter();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: radius of class  CollisionCircle2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionCircle2D_radius
static int tolua_get_CollisionCircle2D_radius(lua_State* tolua_S)
{
  CollisionCircle2D* self = (CollisionCircle2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radius'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRadius());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: radius of class  CollisionCircle2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionCircle2D_radius
static int tolua_set_CollisionCircle2D_radius(lua_State* tolua_S)
{
  CollisionCircle2D* self = (CollisionCircle2D*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: center of class  CollisionCircle2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionCircle2D_center_ref
static int tolua_get_CollisionCircle2D_center_ref(lua_State* tolua_S)
{
  CollisionCircle2D* self = (CollisionCircle2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'center'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetCenter(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: center of class  CollisionCircle2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionCircle2D_center_ref
static int tolua_set_CollisionCircle2D_center_ref(lua_State* tolua_S)
{
  CollisionCircle2D* self = (CollisionCircle2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'center'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCenter((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVertex1 of class  CollisionEdge2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionEdge2D_SetVertex100
static int tolua_Urho2DLuaAPI_CollisionEdge2D_SetVertex100(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionEdge2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionEdge2D* self = (CollisionEdge2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* vertex = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVertex1'", NULL);
#endif
 {
  self->SetVertex1(*vertex);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVertex1'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVertex2 of class  CollisionEdge2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionEdge2D_SetVertex200
static int tolua_Urho2DLuaAPI_CollisionEdge2D_SetVertex200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionEdge2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionEdge2D* self = (CollisionEdge2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* vertex = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVertex2'", NULL);
#endif
 {
  self->SetVertex2(*vertex);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVertex2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVertices of class  CollisionEdge2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionEdge2D_SetVertices00
static int tolua_Urho2DLuaAPI_CollisionEdge2D_SetVertices00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionEdge2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionEdge2D* self = (CollisionEdge2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* vertex1 = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* vertex2 = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVertices'", NULL);
#endif
 {
  self->SetVertices(*vertex1,*vertex2);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVertices'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVertex1 of class  CollisionEdge2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionEdge2D_GetVertex100
static int tolua_Urho2DLuaAPI_CollisionEdge2D_GetVertex100(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionEdge2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionEdge2D* self = (const CollisionEdge2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVertex1'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetVertex1();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVertex1'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVertex2 of class  CollisionEdge2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionEdge2D_GetVertex200
static int tolua_Urho2DLuaAPI_CollisionEdge2D_GetVertex200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionEdge2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionEdge2D* self = (const CollisionEdge2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVertex2'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetVertex2();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVertex2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: vertex1 of class  CollisionEdge2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionEdge2D_vertex1_ref
static int tolua_get_CollisionEdge2D_vertex1_ref(lua_State* tolua_S)
{
  CollisionEdge2D* self = (CollisionEdge2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'vertex1'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetVertex1(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: vertex1 of class  CollisionEdge2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionEdge2D_vertex1_ref
static int tolua_set_CollisionEdge2D_vertex1_ref(lua_State* tolua_S)
{
  CollisionEdge2D* self = (CollisionEdge2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'vertex1'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetVertex1((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: vertex2 of class  CollisionEdge2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionEdge2D_vertex2_ref
static int tolua_get_CollisionEdge2D_vertex2_ref(lua_State* tolua_S)
{
  CollisionEdge2D* self = (CollisionEdge2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'vertex2'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetVertex2(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: vertex2 of class  CollisionEdge2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionEdge2D_vertex2_ref
static int tolua_set_CollisionEdge2D_vertex2_ref(lua_State* tolua_S)
{
  CollisionEdge2D* self = (CollisionEdge2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'vertex2'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetVertex2((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVertexCount of class  CollisionPolygon2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionPolygon2D_SetVertexCount00
static int tolua_Urho2DLuaAPI_CollisionPolygon2D_SetVertexCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionPolygon2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionPolygon2D* self = (CollisionPolygon2D*)  tolua_tousertype(tolua_S,1,0);
  unsigned count = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVertexCount'", NULL);
#endif
 {
  self->SetVertexCount(count);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVertexCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVertex of class  CollisionPolygon2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionPolygon2D_SetVertex00
static int tolua_Urho2DLuaAPI_CollisionPolygon2D_SetVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionPolygon2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionPolygon2D* self = (CollisionPolygon2D*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  const Vector2* vertex = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVertex'", NULL);
#endif
 {
  self->SetVertex(index,*vertex);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVertex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVertices of class  CollisionPolygon2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionPolygon2D_SetVertices00
static int tolua_Urho2DLuaAPI_CollisionPolygon2D_SetVertices00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CollisionPolygon2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !ToluaIsPODVector<Vector2>(tolua_S,2,"Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CollisionPolygon2D* self = (CollisionPolygon2D*)  tolua_tousertype(tolua_S,1,0);
  const PODVector<Vector2>* vertices = ((const PODVector<Vector2>*)  ToluaToPODVector<Vector2>(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVertices'", NULL);
#endif
 {
  self->SetVertices(*vertices);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVertices'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVertexCount of class  CollisionPolygon2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionPolygon2D_GetVertexCount00
static int tolua_Urho2DLuaAPI_CollisionPolygon2D_GetVertexCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionPolygon2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionPolygon2D* self = (const CollisionPolygon2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVertexCount'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetVertexCount();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVertexCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVertex of class  CollisionPolygon2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_CollisionPolygon2D_GetVertex00
static int tolua_Urho2DLuaAPI_CollisionPolygon2D_GetVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CollisionPolygon2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CollisionPolygon2D* self = (const CollisionPolygon2D*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVertex'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetVertex(index);
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVertex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: vertexCount of class  CollisionPolygon2D */
#ifndef TOLUA_DISABLE_tolua_get_CollisionPolygon2D_vertexCount
static int tolua_get_CollisionPolygon2D_vertexCount(lua_State* tolua_S)
{
  CollisionPolygon2D* self = (CollisionPolygon2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'vertexCount'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetVertexCount());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: vertexCount of class  CollisionPolygon2D */
#ifndef TOLUA_DISABLE_tolua_set_CollisionPolygon2D_vertexCount
static int tolua_set_CollisionPolygon2D_vertexCount(lua_State* tolua_S)
{
  CollisionPolygon2D* self = (CollisionPolygon2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'vertexCount'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetVertexCount(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOtherBody of class  Constraint2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Constraint2D_SetOtherBody00
static int tolua_Urho2DLuaAPI_Constraint2D_SetOtherBody00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint2D",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"RigidBody2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint2D* self = (Constraint2D*)  tolua_tousertype(tolua_S,1,0);
  RigidBody2D* body = ((RigidBody2D*)  tolua_tousertype(tolua_S,2,0));
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

/* method: SetCollideConnected of class  Constraint2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Constraint2D_SetCollideConnected00
static int tolua_Urho2DLuaAPI_Constraint2D_SetCollideConnected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Constraint2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Constraint2D* self = (Constraint2D*)  tolua_tousertype(tolua_S,1,0);
  bool collideConnected = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCollideConnected'", NULL);
#endif
 {
  self->SetCollideConnected(collideConnected);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCollideConnected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOwnerBody of class  Constraint2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Constraint2D_GetOwnerBody00
static int tolua_Urho2DLuaAPI_Constraint2D_GetOwnerBody00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint2D* self = (const Constraint2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOwnerBody'", NULL);
#endif
 {
  RigidBody2D* tolua_ret = (RigidBody2D*)  self->GetOwnerBody();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"RigidBody2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOwnerBody'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOtherBody of class  Constraint2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Constraint2D_GetOtherBody00
static int tolua_Urho2DLuaAPI_Constraint2D_GetOtherBody00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint2D* self = (const Constraint2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOtherBody'", NULL);
#endif
 {
  RigidBody2D* tolua_ret = (RigidBody2D*)  self->GetOtherBody();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"RigidBody2D");
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

/* method: GetCollideConnected of class  Constraint2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_Constraint2D_GetCollideConnected00
static int tolua_Urho2DLuaAPI_Constraint2D_GetCollideConnected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Constraint2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Constraint2D* self = (const Constraint2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCollideConnected'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetCollideConnected();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCollideConnected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ownerBody of class  Constraint2D */
#ifndef TOLUA_DISABLE_tolua_get_Constraint2D_ownerBody_ptr
static int tolua_get_Constraint2D_ownerBody_ptr(lua_State* tolua_S)
{
  Constraint2D* self = (Constraint2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ownerBody'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetOwnerBody(),"RigidBody2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: otherBody of class  Constraint2D */
#ifndef TOLUA_DISABLE_tolua_get_Constraint2D_otherBody_ptr
static int tolua_get_Constraint2D_otherBody_ptr(lua_State* tolua_S)
{
  Constraint2D* self = (Constraint2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherBody'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetOtherBody(),"RigidBody2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: otherBody of class  Constraint2D */
#ifndef TOLUA_DISABLE_tolua_set_Constraint2D_otherBody_ptr
static int tolua_set_Constraint2D_otherBody_ptr(lua_State* tolua_S)
{
  Constraint2D* self = (Constraint2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherBody'",NULL);
 if (!tolua_isusertype(tolua_S,2,"RigidBody2D",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOtherBody(((RigidBody2D*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: collideConnected of class  Constraint2D */
#ifndef TOLUA_DISABLE_tolua_get_Constraint2D_collideConnected
static int tolua_get_Constraint2D_collideConnected(lua_State* tolua_S)
{
  Constraint2D* self = (Constraint2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'collideConnected'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetCollideConnected());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: collideConnected of class  Constraint2D */
#ifndef TOLUA_DISABLE_tolua_set_Constraint2D_collideConnected
static int tolua_set_Constraint2D_collideConnected(lua_State* tolua_S)
{
  Constraint2D* self = (Constraint2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'collideConnected'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCollideConnected(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOwnerBodyAnchor of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintDistance2D_SetOwnerBodyAnchor00
static int tolua_Urho2DLuaAPI_ConstraintDistance2D_SetOwnerBodyAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintDistance2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintDistance2D* self = (ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* anchor = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOwnerBodyAnchor'", NULL);
#endif
 {
  self->SetOwnerBodyAnchor(*anchor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOwnerBodyAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOtherBodyAnchor of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintDistance2D_SetOtherBodyAnchor00
static int tolua_Urho2DLuaAPI_ConstraintDistance2D_SetOtherBodyAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintDistance2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintDistance2D* self = (ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* anchor = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOtherBodyAnchor'", NULL);
#endif
 {
  self->SetOtherBodyAnchor(*anchor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOtherBodyAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFrequencyHz of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintDistance2D_SetFrequencyHz00
static int tolua_Urho2DLuaAPI_ConstraintDistance2D_SetFrequencyHz00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintDistance2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintDistance2D* self = (ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
  float frequencyHz = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFrequencyHz'", NULL);
#endif
 {
  self->SetFrequencyHz(frequencyHz);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFrequencyHz'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDampingRatio of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintDistance2D_SetDampingRatio00
static int tolua_Urho2DLuaAPI_ConstraintDistance2D_SetDampingRatio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintDistance2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintDistance2D* self = (ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
  float dampingRatio = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDampingRatio'", NULL);
#endif
 {
  self->SetDampingRatio(dampingRatio);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDampingRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLength of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintDistance2D_SetLength00
static int tolua_Urho2DLuaAPI_ConstraintDistance2D_SetLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintDistance2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintDistance2D* self = (ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
  float length = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLength'", NULL);
#endif
 {
  self->SetLength(length);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOwnerBodyAnchor of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintDistance2D_GetOwnerBodyAnchor00
static int tolua_Urho2DLuaAPI_ConstraintDistance2D_GetOwnerBodyAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintDistance2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintDistance2D* self = (const ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOwnerBodyAnchor'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetOwnerBodyAnchor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOwnerBodyAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOtherBodyAnchor of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintDistance2D_GetOtherBodyAnchor00
static int tolua_Urho2DLuaAPI_ConstraintDistance2D_GetOtherBodyAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintDistance2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintDistance2D* self = (const ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOtherBodyAnchor'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetOtherBodyAnchor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOtherBodyAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFrequencyHz of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintDistance2D_GetFrequencyHz00
static int tolua_Urho2DLuaAPI_ConstraintDistance2D_GetFrequencyHz00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintDistance2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintDistance2D* self = (const ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFrequencyHz'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetFrequencyHz();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFrequencyHz'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDampingRatio of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintDistance2D_GetDampingRatio00
static int tolua_Urho2DLuaAPI_ConstraintDistance2D_GetDampingRatio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintDistance2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintDistance2D* self = (const ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDampingRatio'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDampingRatio();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDampingRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLength of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintDistance2D_GetLength00
static int tolua_Urho2DLuaAPI_ConstraintDistance2D_GetLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintDistance2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintDistance2D* self = (const ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLength'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ownerBodyAnchor of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintDistance2D_ownerBodyAnchor_ref
static int tolua_get_ConstraintDistance2D_ownerBodyAnchor_ref(lua_State* tolua_S)
{
  ConstraintDistance2D* self = (ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ownerBodyAnchor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetOwnerBodyAnchor(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ownerBodyAnchor of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintDistance2D_ownerBodyAnchor_ref
static int tolua_set_ConstraintDistance2D_ownerBodyAnchor_ref(lua_State* tolua_S)
{
  ConstraintDistance2D* self = (ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ownerBodyAnchor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOwnerBodyAnchor((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: otherBodyAnchor of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintDistance2D_otherBodyAnchor_ref
static int tolua_get_ConstraintDistance2D_otherBodyAnchor_ref(lua_State* tolua_S)
{
  ConstraintDistance2D* self = (ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherBodyAnchor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetOtherBodyAnchor(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: otherBodyAnchor of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintDistance2D_otherBodyAnchor_ref
static int tolua_set_ConstraintDistance2D_otherBodyAnchor_ref(lua_State* tolua_S)
{
  ConstraintDistance2D* self = (ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherBodyAnchor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOtherBodyAnchor((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: frequencyHz of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintDistance2D_frequencyHz
static int tolua_get_ConstraintDistance2D_frequencyHz(lua_State* tolua_S)
{
  ConstraintDistance2D* self = (ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frequencyHz'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFrequencyHz());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: frequencyHz of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintDistance2D_frequencyHz
static int tolua_set_ConstraintDistance2D_frequencyHz(lua_State* tolua_S)
{
  ConstraintDistance2D* self = (ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frequencyHz'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFrequencyHz(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dampingRatio of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintDistance2D_dampingRatio
static int tolua_get_ConstraintDistance2D_dampingRatio(lua_State* tolua_S)
{
  ConstraintDistance2D* self = (ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dampingRatio'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDampingRatio());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dampingRatio of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintDistance2D_dampingRatio
static int tolua_set_ConstraintDistance2D_dampingRatio(lua_State* tolua_S)
{
  ConstraintDistance2D* self = (ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dampingRatio'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDampingRatio(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: length of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintDistance2D_length
static int tolua_get_ConstraintDistance2D_length(lua_State* tolua_S)
{
  ConstraintDistance2D* self = (ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'length'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLength());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: length of class  ConstraintDistance2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintDistance2D_length
static int tolua_set_ConstraintDistance2D_length(lua_State* tolua_S)
{
  ConstraintDistance2D* self = (ConstraintDistance2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'length'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLength(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAnchor of class  ConstraintFriction2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintFriction2D_SetAnchor00
static int tolua_Urho2DLuaAPI_ConstraintFriction2D_SetAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintFriction2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintFriction2D* self = (ConstraintFriction2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* anchor = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnchor'", NULL);
#endif
 {
  self->SetAnchor(*anchor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxForce of class  ConstraintFriction2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintFriction2D_SetMaxForce00
static int tolua_Urho2DLuaAPI_ConstraintFriction2D_SetMaxForce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintFriction2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintFriction2D* self = (ConstraintFriction2D*)  tolua_tousertype(tolua_S,1,0);
  float maxForce = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxForce'", NULL);
#endif
 {
  self->SetMaxForce(maxForce);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxForce'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxTorque of class  ConstraintFriction2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintFriction2D_SetMaxTorque00
static int tolua_Urho2DLuaAPI_ConstraintFriction2D_SetMaxTorque00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintFriction2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintFriction2D* self = (ConstraintFriction2D*)  tolua_tousertype(tolua_S,1,0);
  float maxTorque = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxTorque'", NULL);
#endif
 {
  self->SetMaxTorque(maxTorque);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxTorque'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnchor of class  ConstraintFriction2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintFriction2D_GetAnchor00
static int tolua_Urho2DLuaAPI_ConstraintFriction2D_GetAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintFriction2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintFriction2D* self = (const ConstraintFriction2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnchor'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetAnchor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxForce of class  ConstraintFriction2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintFriction2D_GetMaxForce00
static int tolua_Urho2DLuaAPI_ConstraintFriction2D_GetMaxForce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintFriction2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintFriction2D* self = (const ConstraintFriction2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxForce'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxForce();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxForce'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxTorque of class  ConstraintFriction2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintFriction2D_GetMaxTorque00
static int tolua_Urho2DLuaAPI_ConstraintFriction2D_GetMaxTorque00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintFriction2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintFriction2D* self = (const ConstraintFriction2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxTorque'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxTorque();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxTorque'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: anchor of class  ConstraintFriction2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintFriction2D_anchor_ref
static int tolua_get_ConstraintFriction2D_anchor_ref(lua_State* tolua_S)
{
  ConstraintFriction2D* self = (ConstraintFriction2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'anchor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetAnchor(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: anchor of class  ConstraintFriction2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintFriction2D_anchor_ref
static int tolua_set_ConstraintFriction2D_anchor_ref(lua_State* tolua_S)
{
  ConstraintFriction2D* self = (ConstraintFriction2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'anchor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAnchor((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxForce of class  ConstraintFriction2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintFriction2D_maxForce
static int tolua_get_ConstraintFriction2D_maxForce(lua_State* tolua_S)
{
  ConstraintFriction2D* self = (ConstraintFriction2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxForce'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxForce());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxForce of class  ConstraintFriction2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintFriction2D_maxForce
static int tolua_set_ConstraintFriction2D_maxForce(lua_State* tolua_S)
{
  ConstraintFriction2D* self = (ConstraintFriction2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxForce'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxForce(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxTorque of class  ConstraintFriction2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintFriction2D_maxTorque
static int tolua_get_ConstraintFriction2D_maxTorque(lua_State* tolua_S)
{
  ConstraintFriction2D* self = (ConstraintFriction2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxTorque'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxTorque());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxTorque of class  ConstraintFriction2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintFriction2D_maxTorque
static int tolua_set_ConstraintFriction2D_maxTorque(lua_State* tolua_S)
{
  ConstraintFriction2D* self = (ConstraintFriction2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxTorque'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxTorque(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOwnerConstraint of class  ConstraintGear2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintGear2D_SetOwnerConstraint00
static int tolua_Urho2DLuaAPI_ConstraintGear2D_SetOwnerConstraint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintGear2D",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Constraint2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintGear2D* self = (ConstraintGear2D*)  tolua_tousertype(tolua_S,1,0);
  Constraint2D* constraint = ((Constraint2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOwnerConstraint'", NULL);
#endif
 {
  self->SetOwnerConstraint(constraint);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOwnerConstraint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOtherConstraint of class  ConstraintGear2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintGear2D_SetOtherConstraint00
static int tolua_Urho2DLuaAPI_ConstraintGear2D_SetOtherConstraint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintGear2D",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Constraint2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintGear2D* self = (ConstraintGear2D*)  tolua_tousertype(tolua_S,1,0);
  Constraint2D* constraint = ((Constraint2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOtherConstraint'", NULL);
#endif
 {
  self->SetOtherConstraint(constraint);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOtherConstraint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRatio of class  ConstraintGear2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintGear2D_SetRatio00
static int tolua_Urho2DLuaAPI_ConstraintGear2D_SetRatio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintGear2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintGear2D* self = (ConstraintGear2D*)  tolua_tousertype(tolua_S,1,0);
  float ratio = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRatio'", NULL);
#endif
 {
  self->SetRatio(ratio);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOwnerConstraint of class  ConstraintGear2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintGear2D_GetOwnerConstraint00
static int tolua_Urho2DLuaAPI_ConstraintGear2D_GetOwnerConstraint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintGear2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintGear2D* self = (const ConstraintGear2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOwnerConstraint'", NULL);
#endif
 {
  Constraint2D* tolua_ret = (Constraint2D*)  self->GetOwnerConstraint();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Constraint2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOwnerConstraint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOtherConstraint of class  ConstraintGear2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintGear2D_GetOtherConstraint00
static int tolua_Urho2DLuaAPI_ConstraintGear2D_GetOtherConstraint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintGear2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintGear2D* self = (const ConstraintGear2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOtherConstraint'", NULL);
#endif
 {
  Constraint2D* tolua_ret = (Constraint2D*)  self->GetOtherConstraint();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Constraint2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOtherConstraint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRatio of class  ConstraintGear2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintGear2D_GetRatio00
static int tolua_Urho2DLuaAPI_ConstraintGear2D_GetRatio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintGear2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintGear2D* self = (const ConstraintGear2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRatio'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRatio();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ownerConstraint of class  ConstraintGear2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintGear2D_ownerConstraint_ptr
static int tolua_get_ConstraintGear2D_ownerConstraint_ptr(lua_State* tolua_S)
{
  ConstraintGear2D* self = (ConstraintGear2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ownerConstraint'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetOwnerConstraint(),"Constraint2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ownerConstraint of class  ConstraintGear2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintGear2D_ownerConstraint_ptr
static int tolua_set_ConstraintGear2D_ownerConstraint_ptr(lua_State* tolua_S)
{
  ConstraintGear2D* self = (ConstraintGear2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ownerConstraint'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Constraint2D",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOwnerConstraint(((Constraint2D*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: otherConstraint of class  ConstraintGear2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintGear2D_otherConstraint_ptr
static int tolua_get_ConstraintGear2D_otherConstraint_ptr(lua_State* tolua_S)
{
  ConstraintGear2D* self = (ConstraintGear2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherConstraint'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetOtherConstraint(),"Constraint2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: otherConstraint of class  ConstraintGear2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintGear2D_otherConstraint_ptr
static int tolua_set_ConstraintGear2D_otherConstraint_ptr(lua_State* tolua_S)
{
  ConstraintGear2D* self = (ConstraintGear2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherConstraint'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Constraint2D",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOtherConstraint(((Constraint2D*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ratio of class  ConstraintGear2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintGear2D_ratio
static int tolua_get_ConstraintGear2D_ratio(lua_State* tolua_S)
{
  ConstraintGear2D* self = (ConstraintGear2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ratio'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRatio());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ratio of class  ConstraintGear2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintGear2D_ratio
static int tolua_set_ConstraintGear2D_ratio(lua_State* tolua_S)
{
  ConstraintGear2D* self = (ConstraintGear2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ratio'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRatio(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLinearOffset of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMotor2D_SetLinearOffset00
static int tolua_Urho2DLuaAPI_ConstraintMotor2D_SetLinearOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintMotor2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintMotor2D* self = (ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* linearOffset = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLinearOffset'", NULL);
#endif
 {
  self->SetLinearOffset(*linearOffset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLinearOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAngularOffset of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMotor2D_SetAngularOffset00
static int tolua_Urho2DLuaAPI_ConstraintMotor2D_SetAngularOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintMotor2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintMotor2D* self = (ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
  float angularOffset = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngularOffset'", NULL);
#endif
 {
  self->SetAngularOffset(angularOffset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAngularOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxForce of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMotor2D_SetMaxForce00
static int tolua_Urho2DLuaAPI_ConstraintMotor2D_SetMaxForce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintMotor2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintMotor2D* self = (ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
  float maxForce = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxForce'", NULL);
#endif
 {
  self->SetMaxForce(maxForce);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxForce'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxTorque of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMotor2D_SetMaxTorque00
static int tolua_Urho2DLuaAPI_ConstraintMotor2D_SetMaxTorque00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintMotor2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintMotor2D* self = (ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
  float maxTorque = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxTorque'", NULL);
#endif
 {
  self->SetMaxTorque(maxTorque);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxTorque'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCorrectionFactor of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMotor2D_SetCorrectionFactor00
static int tolua_Urho2DLuaAPI_ConstraintMotor2D_SetCorrectionFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintMotor2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintMotor2D* self = (ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
  float correctionFactor = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCorrectionFactor'", NULL);
#endif
 {
  self->SetCorrectionFactor(correctionFactor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCorrectionFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLinearOffset of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMotor2D_GetLinearOffset00
static int tolua_Urho2DLuaAPI_ConstraintMotor2D_GetLinearOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintMotor2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintMotor2D* self = (const ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLinearOffset'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetLinearOffset();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLinearOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAngularOffset of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMotor2D_GetAngularOffset00
static int tolua_Urho2DLuaAPI_ConstraintMotor2D_GetAngularOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintMotor2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintMotor2D* self = (const ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAngularOffset'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAngularOffset();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAngularOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxForce of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMotor2D_GetMaxForce00
static int tolua_Urho2DLuaAPI_ConstraintMotor2D_GetMaxForce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintMotor2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintMotor2D* self = (const ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxForce'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxForce();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxForce'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxTorque of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMotor2D_GetMaxTorque00
static int tolua_Urho2DLuaAPI_ConstraintMotor2D_GetMaxTorque00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintMotor2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintMotor2D* self = (const ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxTorque'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxTorque();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxTorque'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCorrectionFactor of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMotor2D_GetCorrectionFactor00
static int tolua_Urho2DLuaAPI_ConstraintMotor2D_GetCorrectionFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintMotor2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintMotor2D* self = (const ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCorrectionFactor'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetCorrectionFactor();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCorrectionFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: linearOffset of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintMotor2D_linearOffset_ref
static int tolua_get_ConstraintMotor2D_linearOffset_ref(lua_State* tolua_S)
{
  ConstraintMotor2D* self = (ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'linearOffset'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetLinearOffset(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: linearOffset of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintMotor2D_linearOffset_ref
static int tolua_set_ConstraintMotor2D_linearOffset_ref(lua_State* tolua_S)
{
  ConstraintMotor2D* self = (ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'linearOffset'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLinearOffset((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: angularOffset of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintMotor2D_angularOffset
static int tolua_get_ConstraintMotor2D_angularOffset(lua_State* tolua_S)
{
  ConstraintMotor2D* self = (ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'angularOffset'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAngularOffset());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: angularOffset of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintMotor2D_angularOffset
static int tolua_set_ConstraintMotor2D_angularOffset(lua_State* tolua_S)
{
  ConstraintMotor2D* self = (ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'angularOffset'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAngularOffset(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxForce of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintMotor2D_maxForce
static int tolua_get_ConstraintMotor2D_maxForce(lua_State* tolua_S)
{
  ConstraintMotor2D* self = (ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxForce'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxForce());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxForce of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintMotor2D_maxForce
static int tolua_set_ConstraintMotor2D_maxForce(lua_State* tolua_S)
{
  ConstraintMotor2D* self = (ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxForce'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxForce(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxTorque of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintMotor2D_maxTorque
static int tolua_get_ConstraintMotor2D_maxTorque(lua_State* tolua_S)
{
  ConstraintMotor2D* self = (ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxTorque'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxTorque());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxTorque of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintMotor2D_maxTorque
static int tolua_set_ConstraintMotor2D_maxTorque(lua_State* tolua_S)
{
  ConstraintMotor2D* self = (ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxTorque'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxTorque(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: correctionFactor of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintMotor2D_correctionFactor
static int tolua_get_ConstraintMotor2D_correctionFactor(lua_State* tolua_S)
{
  ConstraintMotor2D* self = (ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'correctionFactor'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetCorrectionFactor());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: correctionFactor of class  ConstraintMotor2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintMotor2D_correctionFactor
static int tolua_set_ConstraintMotor2D_correctionFactor(lua_State* tolua_S)
{
  ConstraintMotor2D* self = (ConstraintMotor2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'correctionFactor'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCorrectionFactor(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTarget of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMouse2D_SetTarget00
static int tolua_Urho2DLuaAPI_ConstraintMouse2D_SetTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintMouse2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintMouse2D* self = (ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* target = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTarget'", NULL);
#endif
 {
  self->SetTarget(*target);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxForce of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMouse2D_SetMaxForce00
static int tolua_Urho2DLuaAPI_ConstraintMouse2D_SetMaxForce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintMouse2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintMouse2D* self = (ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
  float maxForce = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxForce'", NULL);
#endif
 {
  self->SetMaxForce(maxForce);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxForce'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFrequencyHz of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMouse2D_SetFrequencyHz00
static int tolua_Urho2DLuaAPI_ConstraintMouse2D_SetFrequencyHz00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintMouse2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintMouse2D* self = (ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
  float frequencyHz = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFrequencyHz'", NULL);
#endif
 {
  self->SetFrequencyHz(frequencyHz);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFrequencyHz'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDampingRatio of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMouse2D_SetDampingRatio00
static int tolua_Urho2DLuaAPI_ConstraintMouse2D_SetDampingRatio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintMouse2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintMouse2D* self = (ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
  float dampingRatio = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDampingRatio'", NULL);
#endif
 {
  self->SetDampingRatio(dampingRatio);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDampingRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTarget of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMouse2D_GetTarget00
static int tolua_Urho2DLuaAPI_ConstraintMouse2D_GetTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintMouse2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintMouse2D* self = (const ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTarget'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetTarget();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxForce of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMouse2D_GetMaxForce00
static int tolua_Urho2DLuaAPI_ConstraintMouse2D_GetMaxForce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintMouse2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintMouse2D* self = (const ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxForce'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxForce();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxForce'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFrequencyHz of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMouse2D_GetFrequencyHz00
static int tolua_Urho2DLuaAPI_ConstraintMouse2D_GetFrequencyHz00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintMouse2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintMouse2D* self = (const ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFrequencyHz'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetFrequencyHz();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFrequencyHz'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDampingRatio of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintMouse2D_GetDampingRatio00
static int tolua_Urho2DLuaAPI_ConstraintMouse2D_GetDampingRatio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintMouse2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintMouse2D* self = (const ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDampingRatio'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDampingRatio();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDampingRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: target of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintMouse2D_target_ref
static int tolua_get_ConstraintMouse2D_target_ref(lua_State* tolua_S)
{
  ConstraintMouse2D* self = (ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'target'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetTarget(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: target of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintMouse2D_target_ref
static int tolua_set_ConstraintMouse2D_target_ref(lua_State* tolua_S)
{
  ConstraintMouse2D* self = (ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'target'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTarget((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxForce of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintMouse2D_maxForce
static int tolua_get_ConstraintMouse2D_maxForce(lua_State* tolua_S)
{
  ConstraintMouse2D* self = (ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxForce'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxForce());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxForce of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintMouse2D_maxForce
static int tolua_set_ConstraintMouse2D_maxForce(lua_State* tolua_S)
{
  ConstraintMouse2D* self = (ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxForce'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxForce(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: frequencyHz of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintMouse2D_frequencyHz
static int tolua_get_ConstraintMouse2D_frequencyHz(lua_State* tolua_S)
{
  ConstraintMouse2D* self = (ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frequencyHz'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFrequencyHz());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: frequencyHz of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintMouse2D_frequencyHz
static int tolua_set_ConstraintMouse2D_frequencyHz(lua_State* tolua_S)
{
  ConstraintMouse2D* self = (ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frequencyHz'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFrequencyHz(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dampingRatio of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintMouse2D_dampingRatio
static int tolua_get_ConstraintMouse2D_dampingRatio(lua_State* tolua_S)
{
  ConstraintMouse2D* self = (ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dampingRatio'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDampingRatio());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dampingRatio of class  ConstraintMouse2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintMouse2D_dampingRatio
static int tolua_set_ConstraintMouse2D_dampingRatio(lua_State* tolua_S)
{
  ConstraintMouse2D* self = (ConstraintMouse2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dampingRatio'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDampingRatio(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAnchor of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetAnchor00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintPrismatic2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* anchor = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnchor'", NULL);
#endif
 {
  self->SetAnchor(*anchor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAxis of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetAxis00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintPrismatic2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* axis = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
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

/* method: SetEnableLimit of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetEnableLimit00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetEnableLimit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintPrismatic2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
  bool enableLimit = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEnableLimit'", NULL);
#endif
 {
  self->SetEnableLimit(enableLimit);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEnableLimit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLowerTranslation of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetLowerTranslation00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetLowerTranslation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintPrismatic2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
  float lowerTranslation = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLowerTranslation'", NULL);
#endif
 {
  self->SetLowerTranslation(lowerTranslation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLowerTranslation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUpperTranslation of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetUpperTranslation00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetUpperTranslation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintPrismatic2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
  float upperTranslation = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUpperTranslation'", NULL);
#endif
 {
  self->SetUpperTranslation(upperTranslation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUpperTranslation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEnableMotor of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetEnableMotor00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetEnableMotor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintPrismatic2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
  bool enableMotor = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEnableMotor'", NULL);
#endif
 {
  self->SetEnableMotor(enableMotor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEnableMotor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxMotorForce of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetMaxMotorForce00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetMaxMotorForce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintPrismatic2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
  float maxMotorForce = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxMotorForce'", NULL);
#endif
 {
  self->SetMaxMotorForce(maxMotorForce);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxMotorForce'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMotorSpeed of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetMotorSpeed00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetMotorSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintPrismatic2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
  float motorSpeed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMotorSpeed'", NULL);
#endif
 {
  self->SetMotorSpeed(motorSpeed);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMotorSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnchor of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetAnchor00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintPrismatic2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintPrismatic2D* self = (const ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnchor'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetAnchor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAxis of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetAxis00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintPrismatic2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintPrismatic2D* self = (const ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAxis'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetAxis();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEnableLimit of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetEnableLimit00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetEnableLimit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintPrismatic2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintPrismatic2D* self = (const ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEnableLimit'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetEnableLimit();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEnableLimit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLowerTranslation of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetLowerTranslation00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetLowerTranslation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintPrismatic2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintPrismatic2D* self = (const ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLowerTranslation'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetLowerTranslation();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLowerTranslation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUpperTranslation of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetUpperTranslation00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetUpperTranslation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintPrismatic2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintPrismatic2D* self = (const ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUpperTranslation'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetUpperTranslation();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUpperTranslation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEnableMotor of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetEnableMotor00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetEnableMotor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintPrismatic2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintPrismatic2D* self = (const ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEnableMotor'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetEnableMotor();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEnableMotor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxMotorForce of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetMaxMotorForce00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetMaxMotorForce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintPrismatic2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintPrismatic2D* self = (const ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxMotorForce'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxMotorForce();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxMotorForce'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMotorSpeed of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetMotorSpeed00
static int tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetMotorSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintPrismatic2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintPrismatic2D* self = (const ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMotorSpeed'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMotorSpeed();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMotorSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: anchor of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintPrismatic2D_anchor_ref
static int tolua_get_ConstraintPrismatic2D_anchor_ref(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'anchor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetAnchor(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: anchor of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintPrismatic2D_anchor_ref
static int tolua_set_ConstraintPrismatic2D_anchor_ref(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'anchor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAnchor((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: axis of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintPrismatic2D_axis_ref
static int tolua_get_ConstraintPrismatic2D_axis_ref(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'axis'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetAxis(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: axis of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintPrismatic2D_axis_ref
static int tolua_set_ConstraintPrismatic2D_axis_ref(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'axis'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAxis((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: enableLimit of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintPrismatic2D_enableLimit
static int tolua_get_ConstraintPrismatic2D_enableLimit(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enableLimit'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetEnableLimit());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: enableLimit of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintPrismatic2D_enableLimit
static int tolua_set_ConstraintPrismatic2D_enableLimit(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enableLimit'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEnableLimit(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: lowerTranslation of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintPrismatic2D_lowerTranslation
static int tolua_get_ConstraintPrismatic2D_lowerTranslation(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lowerTranslation'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLowerTranslation());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: lowerTranslation of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintPrismatic2D_lowerTranslation
static int tolua_set_ConstraintPrismatic2D_lowerTranslation(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lowerTranslation'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLowerTranslation(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: upperTranslation of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintPrismatic2D_upperTranslation
static int tolua_get_ConstraintPrismatic2D_upperTranslation(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upperTranslation'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetUpperTranslation());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: upperTranslation of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintPrismatic2D_upperTranslation
static int tolua_set_ConstraintPrismatic2D_upperTranslation(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upperTranslation'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUpperTranslation(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: enableMotor of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintPrismatic2D_enableMotor
static int tolua_get_ConstraintPrismatic2D_enableMotor(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enableMotor'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetEnableMotor());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: enableMotor of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintPrismatic2D_enableMotor
static int tolua_set_ConstraintPrismatic2D_enableMotor(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enableMotor'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEnableMotor(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxMotorForce of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintPrismatic2D_maxMotorForce
static int tolua_get_ConstraintPrismatic2D_maxMotorForce(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxMotorForce'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxMotorForce());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxMotorForce of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintPrismatic2D_maxMotorForce
static int tolua_set_ConstraintPrismatic2D_maxMotorForce(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxMotorForce'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxMotorForce(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: motorSpeed of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintPrismatic2D_motorSpeed
static int tolua_get_ConstraintPrismatic2D_motorSpeed(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'motorSpeed'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMotorSpeed());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: motorSpeed of class  ConstraintPrismatic2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintPrismatic2D_motorSpeed
static int tolua_set_ConstraintPrismatic2D_motorSpeed(lua_State* tolua_S)
{
  ConstraintPrismatic2D* self = (ConstraintPrismatic2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'motorSpeed'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMotorSpeed(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOwnerBodyGroundAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPulley2D_SetOwnerBodyGroundAnchor00
static int tolua_Urho2DLuaAPI_ConstraintPulley2D_SetOwnerBodyGroundAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintPulley2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintPulley2D* self = (ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* groundAnchor = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOwnerBodyGroundAnchor'", NULL);
#endif
 {
  self->SetOwnerBodyGroundAnchor(*groundAnchor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOwnerBodyGroundAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOtherBodyGroundAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPulley2D_SetOtherBodyGroundAnchor00
static int tolua_Urho2DLuaAPI_ConstraintPulley2D_SetOtherBodyGroundAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintPulley2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintPulley2D* self = (ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* groundAnchor = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOtherBodyGroundAnchor'", NULL);
#endif
 {
  self->SetOtherBodyGroundAnchor(*groundAnchor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOtherBodyGroundAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOwnerBodyAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPulley2D_SetOwnerBodyAnchor00
static int tolua_Urho2DLuaAPI_ConstraintPulley2D_SetOwnerBodyAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintPulley2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintPulley2D* self = (ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* anchor = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOwnerBodyAnchor'", NULL);
#endif
 {
  self->SetOwnerBodyAnchor(*anchor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOwnerBodyAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOtherBodyAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPulley2D_SetOtherBodyAnchor00
static int tolua_Urho2DLuaAPI_ConstraintPulley2D_SetOtherBodyAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintPulley2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintPulley2D* self = (ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* anchor = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOtherBodyAnchor'", NULL);
#endif
 {
  self->SetOtherBodyAnchor(*anchor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOtherBodyAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRatio of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPulley2D_SetRatio00
static int tolua_Urho2DLuaAPI_ConstraintPulley2D_SetRatio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintPulley2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintPulley2D* self = (ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
  float ratio = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRatio'", NULL);
#endif
 {
  self->SetRatio(ratio);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOwnerBodyGroundAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPulley2D_GetOwnerBodyGroundAnchor00
static int tolua_Urho2DLuaAPI_ConstraintPulley2D_GetOwnerBodyGroundAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintPulley2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintPulley2D* self = (const ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOwnerBodyGroundAnchor'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetOwnerBodyGroundAnchor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOwnerBodyGroundAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOtherBodyGroundAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPulley2D_GetOtherBodyGroundAnchor00
static int tolua_Urho2DLuaAPI_ConstraintPulley2D_GetOtherBodyGroundAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintPulley2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintPulley2D* self = (const ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOtherBodyGroundAnchor'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetOtherBodyGroundAnchor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOtherBodyGroundAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOwnerBodyAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPulley2D_GetOwnerBodyAnchor00
static int tolua_Urho2DLuaAPI_ConstraintPulley2D_GetOwnerBodyAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintPulley2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintPulley2D* self = (const ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOwnerBodyAnchor'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetOwnerBodyAnchor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOwnerBodyAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOtherBodyAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPulley2D_GetOtherBodyAnchor00
static int tolua_Urho2DLuaAPI_ConstraintPulley2D_GetOtherBodyAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintPulley2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintPulley2D* self = (const ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOtherBodyAnchor'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetOtherBodyAnchor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOtherBodyAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRatio of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintPulley2D_GetRatio00
static int tolua_Urho2DLuaAPI_ConstraintPulley2D_GetRatio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintPulley2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintPulley2D* self = (const ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRatio'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRatio();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ownerBodyGroundAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintPulley2D_ownerBodyGroundAnchor_ref
static int tolua_get_ConstraintPulley2D_ownerBodyGroundAnchor_ref(lua_State* tolua_S)
{
  ConstraintPulley2D* self = (ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ownerBodyGroundAnchor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetOwnerBodyGroundAnchor(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ownerBodyGroundAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintPulley2D_ownerBodyGroundAnchor_ref
static int tolua_set_ConstraintPulley2D_ownerBodyGroundAnchor_ref(lua_State* tolua_S)
{
  ConstraintPulley2D* self = (ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ownerBodyGroundAnchor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOwnerBodyGroundAnchor((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: otherBodyGroundAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintPulley2D_otherBodyGroundAnchor_ref
static int tolua_get_ConstraintPulley2D_otherBodyGroundAnchor_ref(lua_State* tolua_S)
{
  ConstraintPulley2D* self = (ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherBodyGroundAnchor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetOtherBodyGroundAnchor(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: otherBodyGroundAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintPulley2D_otherBodyGroundAnchor_ref
static int tolua_set_ConstraintPulley2D_otherBodyGroundAnchor_ref(lua_State* tolua_S)
{
  ConstraintPulley2D* self = (ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherBodyGroundAnchor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOtherBodyGroundAnchor((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ownerBodyAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintPulley2D_ownerBodyAnchor_ref
static int tolua_get_ConstraintPulley2D_ownerBodyAnchor_ref(lua_State* tolua_S)
{
  ConstraintPulley2D* self = (ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ownerBodyAnchor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetOwnerBodyAnchor(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ownerBodyAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintPulley2D_ownerBodyAnchor_ref
static int tolua_set_ConstraintPulley2D_ownerBodyAnchor_ref(lua_State* tolua_S)
{
  ConstraintPulley2D* self = (ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ownerBodyAnchor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOwnerBodyAnchor((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: otherBodyAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintPulley2D_otherBodyAnchor_ref
static int tolua_get_ConstraintPulley2D_otherBodyAnchor_ref(lua_State* tolua_S)
{
  ConstraintPulley2D* self = (ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherBodyAnchor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetOtherBodyAnchor(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: otherBodyAnchor of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintPulley2D_otherBodyAnchor_ref
static int tolua_set_ConstraintPulley2D_otherBodyAnchor_ref(lua_State* tolua_S)
{
  ConstraintPulley2D* self = (ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherBodyAnchor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOtherBodyAnchor((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ratio of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintPulley2D_ratio
static int tolua_get_ConstraintPulley2D_ratio(lua_State* tolua_S)
{
  ConstraintPulley2D* self = (ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ratio'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRatio());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ratio of class  ConstraintPulley2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintPulley2D_ratio
static int tolua_set_ConstraintPulley2D_ratio(lua_State* tolua_S)
{
  ConstraintPulley2D* self = (ConstraintPulley2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ratio'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRatio(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAnchor of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetAnchor00
static int tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintRevolute2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* anchor = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnchor'", NULL);
#endif
 {
  self->SetAnchor(*anchor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEnableLimit of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetEnableLimit00
static int tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetEnableLimit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintRevolute2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
  bool enableLimit = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEnableLimit'", NULL);
#endif
 {
  self->SetEnableLimit(enableLimit);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEnableLimit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLowerAngle of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetLowerAngle00
static int tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetLowerAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintRevolute2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
  float lowerAngle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLowerAngle'", NULL);
#endif
 {
  self->SetLowerAngle(lowerAngle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLowerAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUpperAngle of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetUpperAngle00
static int tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetUpperAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintRevolute2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
  float upperAngle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUpperAngle'", NULL);
#endif
 {
  self->SetUpperAngle(upperAngle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUpperAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEnableMotor of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetEnableMotor00
static int tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetEnableMotor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintRevolute2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
  bool enableMotor = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEnableMotor'", NULL);
#endif
 {
  self->SetEnableMotor(enableMotor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEnableMotor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMotorSpeed of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetMotorSpeed00
static int tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetMotorSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintRevolute2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
  float motorSpeed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMotorSpeed'", NULL);
#endif
 {
  self->SetMotorSpeed(motorSpeed);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMotorSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxMotorTorque of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetMaxMotorTorque00
static int tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetMaxMotorTorque00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintRevolute2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
  float maxMotorTorque = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxMotorTorque'", NULL);
#endif
 {
  self->SetMaxMotorTorque(maxMotorTorque);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxMotorTorque'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnchor of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetAnchor00
static int tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintRevolute2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintRevolute2D* self = (const ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnchor'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetAnchor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEnableLimit of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetEnableLimit00
static int tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetEnableLimit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintRevolute2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintRevolute2D* self = (const ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEnableLimit'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetEnableLimit();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEnableLimit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLowerAngle of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetLowerAngle00
static int tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetLowerAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintRevolute2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintRevolute2D* self = (const ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLowerAngle'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetLowerAngle();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLowerAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUpperAngle of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetUpperAngle00
static int tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetUpperAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintRevolute2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintRevolute2D* self = (const ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUpperAngle'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetUpperAngle();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUpperAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEnableMotor of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetEnableMotor00
static int tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetEnableMotor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintRevolute2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintRevolute2D* self = (const ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEnableMotor'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetEnableMotor();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEnableMotor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMotorSpeed of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetMotorSpeed00
static int tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetMotorSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintRevolute2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintRevolute2D* self = (const ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMotorSpeed'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMotorSpeed();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMotorSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxMotorTorque of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetMaxMotorTorque00
static int tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetMaxMotorTorque00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintRevolute2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintRevolute2D* self = (const ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxMotorTorque'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxMotorTorque();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxMotorTorque'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: anchor of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintRevolute2D_anchor_ref
static int tolua_get_ConstraintRevolute2D_anchor_ref(lua_State* tolua_S)
{
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'anchor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetAnchor(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: anchor of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintRevolute2D_anchor_ref
static int tolua_set_ConstraintRevolute2D_anchor_ref(lua_State* tolua_S)
{
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'anchor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAnchor((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: enableLimit of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintRevolute2D_enableLimit
static int tolua_get_ConstraintRevolute2D_enableLimit(lua_State* tolua_S)
{
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enableLimit'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetEnableLimit());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: enableLimit of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintRevolute2D_enableLimit
static int tolua_set_ConstraintRevolute2D_enableLimit(lua_State* tolua_S)
{
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enableLimit'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEnableLimit(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: lowerAngle of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintRevolute2D_lowerAngle
static int tolua_get_ConstraintRevolute2D_lowerAngle(lua_State* tolua_S)
{
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lowerAngle'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLowerAngle());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: lowerAngle of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintRevolute2D_lowerAngle
static int tolua_set_ConstraintRevolute2D_lowerAngle(lua_State* tolua_S)
{
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lowerAngle'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLowerAngle(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: upperAngle of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintRevolute2D_upperAngle
static int tolua_get_ConstraintRevolute2D_upperAngle(lua_State* tolua_S)
{
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upperAngle'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetUpperAngle());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: upperAngle of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintRevolute2D_upperAngle
static int tolua_set_ConstraintRevolute2D_upperAngle(lua_State* tolua_S)
{
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upperAngle'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUpperAngle(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: enableMotor of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintRevolute2D_enableMotor
static int tolua_get_ConstraintRevolute2D_enableMotor(lua_State* tolua_S)
{
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enableMotor'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetEnableMotor());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: enableMotor of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintRevolute2D_enableMotor
static int tolua_set_ConstraintRevolute2D_enableMotor(lua_State* tolua_S)
{
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enableMotor'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEnableMotor(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: motorSpeed of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintRevolute2D_motorSpeed
static int tolua_get_ConstraintRevolute2D_motorSpeed(lua_State* tolua_S)
{
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'motorSpeed'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMotorSpeed());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: motorSpeed of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintRevolute2D_motorSpeed
static int tolua_set_ConstraintRevolute2D_motorSpeed(lua_State* tolua_S)
{
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'motorSpeed'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMotorSpeed(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxMotorTorque of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintRevolute2D_maxMotorTorque
static int tolua_get_ConstraintRevolute2D_maxMotorTorque(lua_State* tolua_S)
{
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxMotorTorque'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxMotorTorque());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxMotorTorque of class  ConstraintRevolute2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintRevolute2D_maxMotorTorque
static int tolua_set_ConstraintRevolute2D_maxMotorTorque(lua_State* tolua_S)
{
  ConstraintRevolute2D* self = (ConstraintRevolute2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxMotorTorque'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxMotorTorque(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOwnerBodyAnchor of class  ConstraintRope2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRope2D_SetOwnerBodyAnchor00
static int tolua_Urho2DLuaAPI_ConstraintRope2D_SetOwnerBodyAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintRope2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintRope2D* self = (ConstraintRope2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* anchor = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOwnerBodyAnchor'", NULL);
#endif
 {
  self->SetOwnerBodyAnchor(*anchor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOwnerBodyAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOtherBodyAnchor of class  ConstraintRope2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRope2D_SetOtherBodyAnchor00
static int tolua_Urho2DLuaAPI_ConstraintRope2D_SetOtherBodyAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintRope2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintRope2D* self = (ConstraintRope2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* anchor = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOtherBodyAnchor'", NULL);
#endif
 {
  self->SetOtherBodyAnchor(*anchor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOtherBodyAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxLength of class  ConstraintRope2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRope2D_SetMaxLength00
static int tolua_Urho2DLuaAPI_ConstraintRope2D_SetMaxLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintRope2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintRope2D* self = (ConstraintRope2D*)  tolua_tousertype(tolua_S,1,0);
  float maxLength = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxLength'", NULL);
#endif
 {
  self->SetMaxLength(maxLength);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOwnerBodyAnchor of class  ConstraintRope2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRope2D_GetOwnerBodyAnchor00
static int tolua_Urho2DLuaAPI_ConstraintRope2D_GetOwnerBodyAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintRope2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintRope2D* self = (const ConstraintRope2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOwnerBodyAnchor'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetOwnerBodyAnchor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOwnerBodyAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOtherBodyAnchor of class  ConstraintRope2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRope2D_GetOtherBodyAnchor00
static int tolua_Urho2DLuaAPI_ConstraintRope2D_GetOtherBodyAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintRope2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintRope2D* self = (const ConstraintRope2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOtherBodyAnchor'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetOtherBodyAnchor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOtherBodyAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxLength of class  ConstraintRope2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintRope2D_GetMaxLength00
static int tolua_Urho2DLuaAPI_ConstraintRope2D_GetMaxLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintRope2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintRope2D* self = (const ConstraintRope2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxLength'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ownerBodyAnchor of class  ConstraintRope2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintRope2D_ownerBodyAnchor_ref
static int tolua_get_ConstraintRope2D_ownerBodyAnchor_ref(lua_State* tolua_S)
{
  ConstraintRope2D* self = (ConstraintRope2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ownerBodyAnchor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetOwnerBodyAnchor(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ownerBodyAnchor of class  ConstraintRope2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintRope2D_ownerBodyAnchor_ref
static int tolua_set_ConstraintRope2D_ownerBodyAnchor_ref(lua_State* tolua_S)
{
  ConstraintRope2D* self = (ConstraintRope2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ownerBodyAnchor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOwnerBodyAnchor((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: otherBodyAnchor of class  ConstraintRope2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintRope2D_otherBodyAnchor_ref
static int tolua_get_ConstraintRope2D_otherBodyAnchor_ref(lua_State* tolua_S)
{
  ConstraintRope2D* self = (ConstraintRope2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherBodyAnchor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetOtherBodyAnchor(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: otherBodyAnchor of class  ConstraintRope2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintRope2D_otherBodyAnchor_ref
static int tolua_set_ConstraintRope2D_otherBodyAnchor_ref(lua_State* tolua_S)
{
  ConstraintRope2D* self = (ConstraintRope2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'otherBodyAnchor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOtherBodyAnchor((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxLength of class  ConstraintRope2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintRope2D_maxLength
static int tolua_get_ConstraintRope2D_maxLength(lua_State* tolua_S)
{
  ConstraintRope2D* self = (ConstraintRope2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxLength'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxLength());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxLength of class  ConstraintRope2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintRope2D_maxLength
static int tolua_set_ConstraintRope2D_maxLength(lua_State* tolua_S)
{
  ConstraintRope2D* self = (ConstraintRope2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxLength'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxLength(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAnchor of class  ConstraintWeld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWeld2D_SetAnchor00
static int tolua_Urho2DLuaAPI_ConstraintWeld2D_SetAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintWeld2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintWeld2D* self = (ConstraintWeld2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* anchor = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnchor'", NULL);
#endif
 {
  self->SetAnchor(*anchor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFrequencyHz of class  ConstraintWeld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWeld2D_SetFrequencyHz00
static int tolua_Urho2DLuaAPI_ConstraintWeld2D_SetFrequencyHz00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintWeld2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintWeld2D* self = (ConstraintWeld2D*)  tolua_tousertype(tolua_S,1,0);
  float frequencyHz = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFrequencyHz'", NULL);
#endif
 {
  self->SetFrequencyHz(frequencyHz);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFrequencyHz'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDampingRatio of class  ConstraintWeld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWeld2D_SetDampingRatio00
static int tolua_Urho2DLuaAPI_ConstraintWeld2D_SetDampingRatio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintWeld2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintWeld2D* self = (ConstraintWeld2D*)  tolua_tousertype(tolua_S,1,0);
  float dampingRatio = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDampingRatio'", NULL);
#endif
 {
  self->SetDampingRatio(dampingRatio);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDampingRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnchor of class  ConstraintWeld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWeld2D_GetAnchor00
static int tolua_Urho2DLuaAPI_ConstraintWeld2D_GetAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintWeld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintWeld2D* self = (const ConstraintWeld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnchor'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetAnchor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFrequencyHz of class  ConstraintWeld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWeld2D_GetFrequencyHz00
static int tolua_Urho2DLuaAPI_ConstraintWeld2D_GetFrequencyHz00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintWeld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintWeld2D* self = (const ConstraintWeld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFrequencyHz'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetFrequencyHz();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFrequencyHz'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDampingRatio of class  ConstraintWeld2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWeld2D_GetDampingRatio00
static int tolua_Urho2DLuaAPI_ConstraintWeld2D_GetDampingRatio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintWeld2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintWeld2D* self = (const ConstraintWeld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDampingRatio'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDampingRatio();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDampingRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: anchor of class  ConstraintWeld2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintWeld2D_anchor_ref
static int tolua_get_ConstraintWeld2D_anchor_ref(lua_State* tolua_S)
{
  ConstraintWeld2D* self = (ConstraintWeld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'anchor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetAnchor(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: anchor of class  ConstraintWeld2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintWeld2D_anchor_ref
static int tolua_set_ConstraintWeld2D_anchor_ref(lua_State* tolua_S)
{
  ConstraintWeld2D* self = (ConstraintWeld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'anchor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAnchor((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: frequencyHz of class  ConstraintWeld2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintWeld2D_frequencyHz
static int tolua_get_ConstraintWeld2D_frequencyHz(lua_State* tolua_S)
{
  ConstraintWeld2D* self = (ConstraintWeld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frequencyHz'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFrequencyHz());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: frequencyHz of class  ConstraintWeld2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintWeld2D_frequencyHz
static int tolua_set_ConstraintWeld2D_frequencyHz(lua_State* tolua_S)
{
  ConstraintWeld2D* self = (ConstraintWeld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frequencyHz'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFrequencyHz(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dampingRatio of class  ConstraintWeld2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintWeld2D_dampingRatio
static int tolua_get_ConstraintWeld2D_dampingRatio(lua_State* tolua_S)
{
  ConstraintWeld2D* self = (ConstraintWeld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dampingRatio'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDampingRatio());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dampingRatio of class  ConstraintWeld2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintWeld2D_dampingRatio
static int tolua_set_ConstraintWeld2D_dampingRatio(lua_State* tolua_S)
{
  ConstraintWeld2D* self = (ConstraintWeld2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dampingRatio'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDampingRatio(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAnchor of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWheel2D_SetAnchor00
static int tolua_Urho2DLuaAPI_ConstraintWheel2D_SetAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintWheel2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* anchor = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnchor'", NULL);
#endif
 {
  self->SetAnchor(*anchor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAxis of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWheel2D_SetAxis00
static int tolua_Urho2DLuaAPI_ConstraintWheel2D_SetAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintWheel2D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* axis = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
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

/* method: SetEnableMotor of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWheel2D_SetEnableMotor00
static int tolua_Urho2DLuaAPI_ConstraintWheel2D_SetEnableMotor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintWheel2D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
  bool enableMotor = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEnableMotor'", NULL);
#endif
 {
  self->SetEnableMotor(enableMotor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEnableMotor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxMotorTorque of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWheel2D_SetMaxMotorTorque00
static int tolua_Urho2DLuaAPI_ConstraintWheel2D_SetMaxMotorTorque00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintWheel2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
  float maxMotorTorque = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxMotorTorque'", NULL);
#endif
 {
  self->SetMaxMotorTorque(maxMotorTorque);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxMotorTorque'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMotorSpeed of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWheel2D_SetMotorSpeed00
static int tolua_Urho2DLuaAPI_ConstraintWheel2D_SetMotorSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintWheel2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
  float motorSpeed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMotorSpeed'", NULL);
#endif
 {
  self->SetMotorSpeed(motorSpeed);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMotorSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFrequencyHz of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWheel2D_SetFrequencyHz00
static int tolua_Urho2DLuaAPI_ConstraintWheel2D_SetFrequencyHz00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintWheel2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
  float frequencyHz = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFrequencyHz'", NULL);
#endif
 {
  self->SetFrequencyHz(frequencyHz);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFrequencyHz'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDampingRatio of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWheel2D_SetDampingRatio00
static int tolua_Urho2DLuaAPI_ConstraintWheel2D_SetDampingRatio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ConstraintWheel2D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
  float dampingRatio = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDampingRatio'", NULL);
#endif
 {
  self->SetDampingRatio(dampingRatio);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDampingRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnchor of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWheel2D_GetAnchor00
static int tolua_Urho2DLuaAPI_ConstraintWheel2D_GetAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintWheel2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintWheel2D* self = (const ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnchor'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetAnchor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAxis of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWheel2D_GetAxis00
static int tolua_Urho2DLuaAPI_ConstraintWheel2D_GetAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintWheel2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintWheel2D* self = (const ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAxis'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetAxis();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEnableMotor of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWheel2D_GetEnableMotor00
static int tolua_Urho2DLuaAPI_ConstraintWheel2D_GetEnableMotor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintWheel2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintWheel2D* self = (const ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEnableMotor'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetEnableMotor();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEnableMotor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxMotorTorque of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWheel2D_GetMaxMotorTorque00
static int tolua_Urho2DLuaAPI_ConstraintWheel2D_GetMaxMotorTorque00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintWheel2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintWheel2D* self = (const ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxMotorTorque'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxMotorTorque();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxMotorTorque'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMotorSpeed of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWheel2D_GetMotorSpeed00
static int tolua_Urho2DLuaAPI_ConstraintWheel2D_GetMotorSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintWheel2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintWheel2D* self = (const ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMotorSpeed'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMotorSpeed();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMotorSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFrequencyHz of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWheel2D_GetFrequencyHz00
static int tolua_Urho2DLuaAPI_ConstraintWheel2D_GetFrequencyHz00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintWheel2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintWheel2D* self = (const ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFrequencyHz'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetFrequencyHz();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFrequencyHz'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDampingRatio of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_Urho2DLuaAPI_ConstraintWheel2D_GetDampingRatio00
static int tolua_Urho2DLuaAPI_ConstraintWheel2D_GetDampingRatio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ConstraintWheel2D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ConstraintWheel2D* self = (const ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDampingRatio'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDampingRatio();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDampingRatio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: anchor of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintWheel2D_anchor_ref
static int tolua_get_ConstraintWheel2D_anchor_ref(lua_State* tolua_S)
{
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'anchor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetAnchor(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: anchor of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintWheel2D_anchor_ref
static int tolua_set_ConstraintWheel2D_anchor_ref(lua_State* tolua_S)
{
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'anchor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAnchor((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: axis of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintWheel2D_axis_ref
static int tolua_get_ConstraintWheel2D_axis_ref(lua_State* tolua_S)
{
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'axis'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetAxis(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: axis of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintWheel2D_axis_ref
static int tolua_set_ConstraintWheel2D_axis_ref(lua_State* tolua_S)
{
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'axis'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAxis((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: enableMotor of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintWheel2D_enableMotor
static int tolua_get_ConstraintWheel2D_enableMotor(lua_State* tolua_S)
{
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enableMotor'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetEnableMotor());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: enableMotor of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintWheel2D_enableMotor
static int tolua_set_ConstraintWheel2D_enableMotor(lua_State* tolua_S)
{
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enableMotor'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEnableMotor(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxMotorTorque of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintWheel2D_maxMotorTorque
static int tolua_get_ConstraintWheel2D_maxMotorTorque(lua_State* tolua_S)
{
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxMotorTorque'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxMotorTorque());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxMotorTorque of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintWheel2D_maxMotorTorque
static int tolua_set_ConstraintWheel2D_maxMotorTorque(lua_State* tolua_S)
{
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxMotorTorque'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxMotorTorque(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: motorSpeed of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintWheel2D_motorSpeed
static int tolua_get_ConstraintWheel2D_motorSpeed(lua_State* tolua_S)
{
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'motorSpeed'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMotorSpeed());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: motorSpeed of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintWheel2D_motorSpeed
static int tolua_set_ConstraintWheel2D_motorSpeed(lua_State* tolua_S)
{
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'motorSpeed'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMotorSpeed(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: frequencyHz of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintWheel2D_frequencyHz
static int tolua_get_ConstraintWheel2D_frequencyHz(lua_State* tolua_S)
{
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frequencyHz'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFrequencyHz());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: frequencyHz of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintWheel2D_frequencyHz
static int tolua_set_ConstraintWheel2D_frequencyHz(lua_State* tolua_S)
{
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frequencyHz'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFrequencyHz(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dampingRatio of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_get_ConstraintWheel2D_dampingRatio
static int tolua_get_ConstraintWheel2D_dampingRatio(lua_State* tolua_S)
{
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dampingRatio'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDampingRatio());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dampingRatio of class  ConstraintWheel2D */
#ifndef TOLUA_DISABLE_tolua_set_ConstraintWheel2D_dampingRatio
static int tolua_set_ConstraintWheel2D_dampingRatio(lua_State* tolua_S)
{
  ConstraintWheel2D* self = (ConstraintWheel2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dampingRatio'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDampingRatio(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Urho2DLuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"Sprite2D","Sprite2D","Resource",NULL);
 tolua_beginmodule(tolua_S,"Sprite2D");
  tolua_function(tolua_S,"SetTexture",tolua_Urho2DLuaAPI_Sprite2D_SetTexture00);
  tolua_function(tolua_S,"SetRectangle",tolua_Urho2DLuaAPI_Sprite2D_SetRectangle00);
  tolua_function(tolua_S,"SetHotSpot",tolua_Urho2DLuaAPI_Sprite2D_SetHotSpot00);
  tolua_function(tolua_S,"SetOffset",tolua_Urho2DLuaAPI_Sprite2D_SetOffset00);
  tolua_function(tolua_S,"SetTextureEdgeOffset",tolua_Urho2DLuaAPI_Sprite2D_SetTextureEdgeOffset00);
  tolua_function(tolua_S,"SetSpriteSheet",tolua_Urho2DLuaAPI_Sprite2D_SetSpriteSheet00);
  tolua_function(tolua_S,"GetTexture",tolua_Urho2DLuaAPI_Sprite2D_GetTexture00);
  tolua_function(tolua_S,"GetRectangle",tolua_Urho2DLuaAPI_Sprite2D_GetRectangle00);
  tolua_function(tolua_S,"GetHotSpot",tolua_Urho2DLuaAPI_Sprite2D_GetHotSpot00);
  tolua_function(tolua_S,"GetOffset",tolua_Urho2DLuaAPI_Sprite2D_GetOffset00);
  tolua_function(tolua_S,"GetTextureEdgeOffset",tolua_Urho2DLuaAPI_Sprite2D_GetTextureEdgeOffset00);
  tolua_function(tolua_S,"GetSpriteSheet",tolua_Urho2DLuaAPI_Sprite2D_GetSpriteSheet00);
  tolua_variable(tolua_S,"texture",tolua_get_Sprite2D_texture_ptr,tolua_set_Sprite2D_texture_ptr);
  tolua_variable(tolua_S,"rectangle",tolua_get_Sprite2D_rectangle,tolua_set_Sprite2D_rectangle);
  tolua_variable(tolua_S,"hotSpot",tolua_get_Sprite2D_hotSpot,tolua_set_Sprite2D_hotSpot);
  tolua_variable(tolua_S,"offset",tolua_get_Sprite2D_offset,tolua_set_Sprite2D_offset);
  tolua_variable(tolua_S,"textureEdgeOffset",tolua_get_Sprite2D_textureEdgeOffset,tolua_set_Sprite2D_textureEdgeOffset);
  tolua_variable(tolua_S,"spriteSheet",tolua_get_Sprite2D_spriteSheet_ptr,tolua_set_Sprite2D_spriteSheet_ptr);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"SpriteSheet2D","SpriteSheet2D","Resource",NULL);
 tolua_beginmodule(tolua_S,"SpriteSheet2D");
  tolua_function(tolua_S,"SetTexture",tolua_Urho2DLuaAPI_SpriteSheet2D_SetTexture00);
  tolua_function(tolua_S,"GetTexture",tolua_Urho2DLuaAPI_SpriteSheet2D_GetTexture00);
  tolua_function(tolua_S,"GetSprite",tolua_Urho2DLuaAPI_SpriteSheet2D_GetSprite00);
  tolua_function(tolua_S,"DefineSprite",tolua_Urho2DLuaAPI_SpriteSheet2D_DefineSprite00);
  tolua_function(tolua_S,"DefineSprite",tolua_Urho2DLuaAPI_SpriteSheet2D_DefineSprite01);
  tolua_function(tolua_S,"DefineSprite",tolua_Urho2DLuaAPI_SpriteSheet2D_DefineSprite02);
  tolua_variable(tolua_S,"texture",tolua_get_SpriteSheet2D_texture_ptr,tolua_set_SpriteSheet2D_texture_ptr);
 tolua_endmodule(tolua_S);
 tolua_variable(tolua_S,"PIXEL_SIZE",tolua_get_PIXEL_SIZE,NULL);
 tolua_cclass(tolua_S,"Drawable2D","Drawable2D","Drawable",NULL);
 tolua_beginmodule(tolua_S,"Drawable2D");
  tolua_function(tolua_S,"SetLayer",tolua_Urho2DLuaAPI_Drawable2D_SetLayer00);
  tolua_function(tolua_S,"SetOrderInLayer",tolua_Urho2DLuaAPI_Drawable2D_SetOrderInLayer00);
  tolua_function(tolua_S,"GetLayer",tolua_Urho2DLuaAPI_Drawable2D_GetLayer00);
  tolua_function(tolua_S,"GetOrderInLayer",tolua_Urho2DLuaAPI_Drawable2D_GetOrderInLayer00);
  tolua_variable(tolua_S,"layer",tolua_get_Drawable2D_layer,tolua_set_Drawable2D_layer);
  tolua_variable(tolua_S,"orderInLayer",tolua_get_Drawable2D_orderInLayer,tolua_set_Drawable2D_orderInLayer);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"StaticSprite2D","StaticSprite2D","Drawable2D",NULL);
 tolua_beginmodule(tolua_S,"StaticSprite2D");
  tolua_function(tolua_S,"SetSprite",tolua_Urho2DLuaAPI_StaticSprite2D_SetSprite00);
  tolua_function(tolua_S,"SetBlendMode",tolua_Urho2DLuaAPI_StaticSprite2D_SetBlendMode00);
  tolua_function(tolua_S,"SetFlip",tolua_Urho2DLuaAPI_StaticSprite2D_SetFlip00);
  tolua_function(tolua_S,"SetFlipX",tolua_Urho2DLuaAPI_StaticSprite2D_SetFlipX00);
  tolua_function(tolua_S,"SetFlipY",tolua_Urho2DLuaAPI_StaticSprite2D_SetFlipY00);
  tolua_function(tolua_S,"SetSwapXY",tolua_Urho2DLuaAPI_StaticSprite2D_SetSwapXY00);
  tolua_function(tolua_S,"SetColor",tolua_Urho2DLuaAPI_StaticSprite2D_SetColor00);
  tolua_function(tolua_S,"SetAlpha",tolua_Urho2DLuaAPI_StaticSprite2D_SetAlpha00);
  tolua_function(tolua_S,"SetUseHotSpot",tolua_Urho2DLuaAPI_StaticSprite2D_SetUseHotSpot00);
  tolua_function(tolua_S,"SetHotSpot",tolua_Urho2DLuaAPI_StaticSprite2D_SetHotSpot00);
  tolua_function(tolua_S,"SetUseDrawRect",tolua_Urho2DLuaAPI_StaticSprite2D_SetUseDrawRect00);
  tolua_function(tolua_S,"SetDrawRect",tolua_Urho2DLuaAPI_StaticSprite2D_SetDrawRect00);
  tolua_function(tolua_S,"SetUseTextureRect",tolua_Urho2DLuaAPI_StaticSprite2D_SetUseTextureRect00);
  tolua_function(tolua_S,"SetTextureRect",tolua_Urho2DLuaAPI_StaticSprite2D_SetTextureRect00);
  tolua_function(tolua_S,"SetCustomMaterial",tolua_Urho2DLuaAPI_StaticSprite2D_SetCustomMaterial00);
  tolua_function(tolua_S,"GetSprite",tolua_Urho2DLuaAPI_StaticSprite2D_GetSprite00);
  tolua_function(tolua_S,"GetBlendMode",tolua_Urho2DLuaAPI_StaticSprite2D_GetBlendMode00);
  tolua_function(tolua_S,"GetFlipX",tolua_Urho2DLuaAPI_StaticSprite2D_GetFlipX00);
  tolua_function(tolua_S,"GetFlipY",tolua_Urho2DLuaAPI_StaticSprite2D_GetFlipY00);
  tolua_function(tolua_S,"GetSwapXY",tolua_Urho2DLuaAPI_StaticSprite2D_GetSwapXY00);
  tolua_function(tolua_S,"GetColor",tolua_Urho2DLuaAPI_StaticSprite2D_GetColor00);
  tolua_function(tolua_S,"GetAlpha",tolua_Urho2DLuaAPI_StaticSprite2D_GetAlpha00);
  tolua_function(tolua_S,"GetUseHotSpot",tolua_Urho2DLuaAPI_StaticSprite2D_GetUseHotSpot00);
  tolua_function(tolua_S,"GetHotSpot",tolua_Urho2DLuaAPI_StaticSprite2D_GetHotSpot00);
  tolua_function(tolua_S,"GetUseDrawRect",tolua_Urho2DLuaAPI_StaticSprite2D_GetUseDrawRect00);
  tolua_function(tolua_S,"GetDrawRect",tolua_Urho2DLuaAPI_StaticSprite2D_GetDrawRect00);
  tolua_function(tolua_S,"GetUseTextureRect",tolua_Urho2DLuaAPI_StaticSprite2D_GetUseTextureRect00);
  tolua_function(tolua_S,"GetTextureRect",tolua_Urho2DLuaAPI_StaticSprite2D_GetTextureRect00);
  tolua_function(tolua_S,"GetCustomMaterial",tolua_Urho2DLuaAPI_StaticSprite2D_GetCustomMaterial00);
  tolua_variable(tolua_S,"sprite",tolua_get_StaticSprite2D_sprite_ptr,tolua_set_StaticSprite2D_sprite_ptr);
  tolua_variable(tolua_S,"blendMode",tolua_get_StaticSprite2D_blendMode,tolua_set_StaticSprite2D_blendMode);
  tolua_variable(tolua_S,"flipX",tolua_get_StaticSprite2D_flipX,tolua_set_StaticSprite2D_flipX);
  tolua_variable(tolua_S,"flipY",tolua_get_StaticSprite2D_flipY,tolua_set_StaticSprite2D_flipY);
  tolua_variable(tolua_S,"swapXY",tolua_get_StaticSprite2D_swapXY,tolua_set_StaticSprite2D_swapXY);
  tolua_variable(tolua_S,"color",tolua_get_StaticSprite2D_color_ref,tolua_set_StaticSprite2D_color_ref);
  tolua_variable(tolua_S,"alpha",tolua_get_StaticSprite2D_alpha,tolua_set_StaticSprite2D_alpha);
  tolua_variable(tolua_S,"useHotSpot",tolua_get_StaticSprite2D_useHotSpot,tolua_set_StaticSprite2D_useHotSpot);
  tolua_variable(tolua_S,"hotSpot",tolua_get_StaticSprite2D_hotSpot,tolua_set_StaticSprite2D_hotSpot);
  tolua_variable(tolua_S,"customMaterial",tolua_get_StaticSprite2D_customMaterial_ptr,tolua_set_StaticSprite2D_customMaterial_ptr);
  tolua_variable(tolua_S,"drawRect",tolua_get_StaticSprite2D_drawRect,tolua_set_StaticSprite2D_drawRect);
  tolua_variable(tolua_S,"useDrawRect",tolua_get_StaticSprite2D_useDrawRect,tolua_set_StaticSprite2D_useDrawRect);
  tolua_variable(tolua_S,"textureRect",tolua_get_StaticSprite2D_textureRect,tolua_set_StaticSprite2D_textureRect);
  tolua_variable(tolua_S,"useTextureRect",tolua_get_StaticSprite2D_useTextureRect,tolua_set_StaticSprite2D_useTextureRect);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"StretchableSprite2D","StretchableSprite2D","StaticSprite2D",NULL);
 tolua_beginmodule(tolua_S,"StretchableSprite2D");
  tolua_function(tolua_S,"SetBorder",tolua_Urho2DLuaAPI_StretchableSprite2D_SetBorder00);
  tolua_function(tolua_S,"GetBorder",tolua_Urho2DLuaAPI_StretchableSprite2D_GetBorder00);
  tolua_variable(tolua_S,"border",tolua_get_StretchableSprite2D_border,tolua_set_StretchableSprite2D_border);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"AnimationSet2D","AnimationSet2D","Resource",NULL);
 tolua_beginmodule(tolua_S,"AnimationSet2D");
  tolua_function(tolua_S,"GetNumAnimations",tolua_Urho2DLuaAPI_AnimationSet2D_GetNumAnimations00);
  tolua_function(tolua_S,"GetAnimation",tolua_Urho2DLuaAPI_AnimationSet2D_GetAnimation00);
  tolua_variable(tolua_S,"numAnimations",tolua_get_AnimationSet2D_numAnimations,NULL);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"LM_DEFAULT",LM_DEFAULT);
 tolua_constant(tolua_S,"LM_FORCE_LOOPED",LM_FORCE_LOOPED);
 tolua_constant(tolua_S,"LM_FORCE_CLAMPED",LM_FORCE_CLAMPED);
 tolua_cclass(tolua_S,"AnimatedSprite2D","AnimatedSprite2D","StaticSprite2D",NULL);
 tolua_beginmodule(tolua_S,"AnimatedSprite2D");
  tolua_function(tolua_S,"SetAnimationSet",tolua_Urho2DLuaAPI_AnimatedSprite2D_SetAnimationSet00);
  tolua_function(tolua_S,"SetEntity",tolua_Urho2DLuaAPI_AnimatedSprite2D_SetEntity00);
  tolua_function(tolua_S,"SetAnimation",tolua_Urho2DLuaAPI_AnimatedSprite2D_SetAnimation00);
  tolua_function(tolua_S,"SetLoopMode",tolua_Urho2DLuaAPI_AnimatedSprite2D_SetLoopMode00);
  tolua_function(tolua_S,"SetSpeed",tolua_Urho2DLuaAPI_AnimatedSprite2D_SetSpeed00);
  tolua_function(tolua_S,"GetAnimationSet",tolua_Urho2DLuaAPI_AnimatedSprite2D_GetAnimationSet00);
  tolua_function(tolua_S,"GetEntity",tolua_Urho2DLuaAPI_AnimatedSprite2D_GetEntity00);
  tolua_function(tolua_S,"GetAnimation",tolua_Urho2DLuaAPI_AnimatedSprite2D_GetAnimation00);
  tolua_function(tolua_S,"GetLoopMode",tolua_Urho2DLuaAPI_AnimatedSprite2D_GetLoopMode00);
  tolua_function(tolua_S,"GetSpeed",tolua_Urho2DLuaAPI_AnimatedSprite2D_GetSpeed00);
  tolua_variable(tolua_S,"speed",tolua_get_AnimatedSprite2D_speed,tolua_set_AnimatedSprite2D_speed);
  tolua_variable(tolua_S,"entity",tolua_get_AnimatedSprite2D_entity,tolua_set_AnimatedSprite2D_entity);
  tolua_variable(tolua_S,"animation",tolua_get_AnimatedSprite2D_animation,tolua_set_AnimatedSprite2D_animation);
  tolua_variable(tolua_S,"animationSet",tolua_get_AnimatedSprite2D_animationSet_ptr,tolua_set_AnimatedSprite2D_animationSet_ptr);
  tolua_variable(tolua_S,"loopMode",tolua_get_AnimatedSprite2D_loopMode,tolua_set_AnimatedSprite2D_loopMode);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"EMITTER_TYPE_GRAVITY",EMITTER_TYPE_GRAVITY);
 tolua_constant(tolua_S,"EMITTER_TYPE_RADIAL",EMITTER_TYPE_RADIAL);
 tolua_cclass(tolua_S,"ParticleEffect2D","ParticleEffect2D","Resource",NULL);
 tolua_beginmodule(tolua_S,"ParticleEffect2D");
  tolua_function(tolua_S,"Clone",tolua_Urho2DLuaAPI_ParticleEffect2D_Clone00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"ParticleEmitter2D","ParticleEmitter2D","Drawable2D",NULL);
 tolua_beginmodule(tolua_S,"ParticleEmitter2D");
  tolua_function(tolua_S,"SetEffect",tolua_Urho2DLuaAPI_ParticleEmitter2D_SetEffect00);
  tolua_function(tolua_S,"SetSprite",tolua_Urho2DLuaAPI_ParticleEmitter2D_SetSprite00);
  tolua_function(tolua_S,"SetBlendMode",tolua_Urho2DLuaAPI_ParticleEmitter2D_SetBlendMode00);
  tolua_function(tolua_S,"SetEmitting",tolua_Urho2DLuaAPI_ParticleEmitter2D_SetEmitting00);
  tolua_function(tolua_S,"GetEffect",tolua_Urho2DLuaAPI_ParticleEmitter2D_GetEffect00);
  tolua_function(tolua_S,"GetSprite",tolua_Urho2DLuaAPI_ParticleEmitter2D_GetSprite00);
  tolua_function(tolua_S,"GetBlendMode",tolua_Urho2DLuaAPI_ParticleEmitter2D_GetBlendMode00);
  tolua_function(tolua_S,"IsEmitting",tolua_Urho2DLuaAPI_ParticleEmitter2D_IsEmitting00);
  tolua_variable(tolua_S,"effect",tolua_get_ParticleEmitter2D_effect_ptr,tolua_set_ParticleEmitter2D_effect_ptr);
  tolua_variable(tolua_S,"sprite",tolua_get_ParticleEmitter2D_sprite_ptr,tolua_set_ParticleEmitter2D_sprite_ptr);
  tolua_variable(tolua_S,"blendMode",tolua_get_ParticleEmitter2D_blendMode,tolua_set_ParticleEmitter2D_blendMode);
  tolua_variable(tolua_S,"emitting",tolua_get_ParticleEmitter2D_emitting,tolua_set_ParticleEmitter2D_emitting);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"O_ORTHOGONAL",O_ORTHOGONAL);
 tolua_constant(tolua_S,"O_ISOMETRIC",O_ISOMETRIC);
 tolua_constant(tolua_S,"O_STAGGERED",O_STAGGERED);
 tolua_constant(tolua_S,"O_HEXAGONAL",O_HEXAGONAL);
 tolua_cclass(tolua_S,"TileMapInfo2D","TileMapInfo2D","",NULL);
 tolua_beginmodule(tolua_S,"TileMapInfo2D");
  tolua_variable(tolua_S,"orientation",tolua_get_TileMapInfo2D_orientation,tolua_set_TileMapInfo2D_orientation);
  tolua_variable(tolua_S,"width",tolua_get_TileMapInfo2D_width,tolua_set_TileMapInfo2D_width);
  tolua_variable(tolua_S,"height",tolua_get_TileMapInfo2D_height,tolua_set_TileMapInfo2D_height);
  tolua_variable(tolua_S,"tileWidth",tolua_get_TileMapInfo2D_tileWidth,tolua_set_TileMapInfo2D_tileWidth);
  tolua_variable(tolua_S,"tileHeight",tolua_get_TileMapInfo2D_tileHeight,tolua_set_TileMapInfo2D_tileHeight);
  tolua_function(tolua_S,"GetMapWidth",tolua_Urho2DLuaAPI_TileMapInfo2D_GetMapWidth00);
  tolua_function(tolua_S,"GetMapHeight",tolua_Urho2DLuaAPI_TileMapInfo2D_GetMapHeight00);
  tolua_variable(tolua_S,"mapWidth",tolua_get_TileMapInfo2D_mapWidth,NULL);
  tolua_variable(tolua_S,"mapHeight",tolua_get_TileMapInfo2D_mapHeight,NULL);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"LT_TILE_LAYER",LT_TILE_LAYER);
 tolua_constant(tolua_S,"LT_OBJECT_GROUP",LT_OBJECT_GROUP);
 tolua_constant(tolua_S,"LT_IMAGE_LAYER",LT_IMAGE_LAYER);
 tolua_constant(tolua_S,"LT_INVALID",LT_INVALID);
 tolua_constant(tolua_S,"OT_RECTANGLE",OT_RECTANGLE);
 tolua_constant(tolua_S,"OT_ELLIPSE",OT_ELLIPSE);
 tolua_constant(tolua_S,"OT_POLYGON",OT_POLYGON);
 tolua_constant(tolua_S,"OT_POLYLINE",OT_POLYLINE);
 tolua_constant(tolua_S,"OT_TILE",OT_TILE);
 tolua_constant(tolua_S,"OT_INVALID",OT_INVALID);
 tolua_cclass(tolua_S,"PropertySet2D","PropertySet2D","",NULL);
 tolua_beginmodule(tolua_S,"PropertySet2D");
  tolua_function(tolua_S,"HasProperty",tolua_Urho2DLuaAPI_PropertySet2D_HasProperty00);
  tolua_function(tolua_S,"GetProperty",tolua_Urho2DLuaAPI_PropertySet2D_GetProperty00);
 tolua_endmodule(tolua_S);
 tolua_variable(tolua_S,"FLIP_HORIZONTAL",tolua_get_FLIP_HORIZONTAL,NULL);
 tolua_variable(tolua_S,"FLIP_VERTICAL",tolua_get_FLIP_VERTICAL,NULL);
 tolua_variable(tolua_S,"FLIP_DIAGONAL",tolua_get_FLIP_DIAGONAL,NULL);
 tolua_variable(tolua_S,"FLIP_RESERVED",tolua_get_FLIP_RESERVED,NULL);
 tolua_variable(tolua_S,"FLIP_ALL",tolua_get_FLIP_ALL,NULL);
 tolua_cclass(tolua_S,"Tile2D","Tile2D","",NULL);
 tolua_beginmodule(tolua_S,"Tile2D");
  tolua_function(tolua_S,"GetGid",tolua_Urho2DLuaAPI_Tile2D_GetGid00);
  tolua_function(tolua_S,"GetFlipX",tolua_Urho2DLuaAPI_Tile2D_GetFlipX00);
  tolua_function(tolua_S,"GetFlipY",tolua_Urho2DLuaAPI_Tile2D_GetFlipY00);
  tolua_function(tolua_S,"GetSwapXY",tolua_Urho2DLuaAPI_Tile2D_GetSwapXY00);
  tolua_function(tolua_S,"GetSprite",tolua_Urho2DLuaAPI_Tile2D_GetSprite00);
  tolua_function(tolua_S,"HasProperty",tolua_Urho2DLuaAPI_Tile2D_HasProperty00);
  tolua_function(tolua_S,"GetProperty",tolua_Urho2DLuaAPI_Tile2D_GetProperty00);
  tolua_variable(tolua_S,"gid",tolua_get_Tile2D_gid,NULL);
  tolua_variable(tolua_S,"sprite",tolua_get_Tile2D_sprite_ptr,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"TileMapObject2D","TileMapObject2D","",NULL);
 tolua_beginmodule(tolua_S,"TileMapObject2D");
  tolua_function(tolua_S,"GetObjectType",tolua_Urho2DLuaAPI_TileMapObject2D_GetObjectType00);
  tolua_function(tolua_S,"GetName",tolua_Urho2DLuaAPI_TileMapObject2D_GetName00);
  tolua_function(tolua_S,"GetType",tolua_Urho2DLuaAPI_TileMapObject2D_GetType00);
  tolua_function(tolua_S,"GetPosition",tolua_Urho2DLuaAPI_TileMapObject2D_GetPosition00);
  tolua_function(tolua_S,"GetSize",tolua_Urho2DLuaAPI_TileMapObject2D_GetSize00);
  tolua_function(tolua_S,"GetNumPoints",tolua_Urho2DLuaAPI_TileMapObject2D_GetNumPoints00);
  tolua_function(tolua_S,"GetPoint",tolua_Urho2DLuaAPI_TileMapObject2D_GetPoint00);
  tolua_function(tolua_S,"GetTileGid",tolua_Urho2DLuaAPI_TileMapObject2D_GetTileGid00);
  tolua_function(tolua_S,"GetTileFlipX",tolua_Urho2DLuaAPI_TileMapObject2D_GetTileFlipX00);
  tolua_function(tolua_S,"GetTileFlipY",tolua_Urho2DLuaAPI_TileMapObject2D_GetTileFlipY00);
  tolua_function(tolua_S,"GetTileSwapXY",tolua_Urho2DLuaAPI_TileMapObject2D_GetTileSwapXY00);
  tolua_function(tolua_S,"GetTileSprite",tolua_Urho2DLuaAPI_TileMapObject2D_GetTileSprite00);
  tolua_function(tolua_S,"HasProperty",tolua_Urho2DLuaAPI_TileMapObject2D_HasProperty00);
  tolua_function(tolua_S,"GetProperty",tolua_Urho2DLuaAPI_TileMapObject2D_GetProperty00);
  tolua_variable(tolua_S,"objectType",tolua_get_TileMapObject2D_objectType,NULL);
  tolua_variable(tolua_S,"name",tolua_get_TileMapObject2D_name,NULL);
  tolua_variable(tolua_S,"type",tolua_get_TileMapObject2D_type,NULL);
  tolua_variable(tolua_S,"position",tolua_get_TileMapObject2D_position,NULL);
  tolua_variable(tolua_S,"size",tolua_get_TileMapObject2D_size,NULL);
  tolua_variable(tolua_S,"numPoints",tolua_get_TileMapObject2D_numPoints,NULL);
  tolua_variable(tolua_S,"tileGid",tolua_get_TileMapObject2D_tileGid,NULL);
  tolua_variable(tolua_S,"tileSprite",tolua_get_TileMapObject2D_tileSprite_ptr,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"TmxFile2D","TmxFile2D","Resource",NULL);
 tolua_beginmodule(tolua_S,"TmxFile2D");
  tolua_function(tolua_S,"SetSpriteTextureEdgeOffset",tolua_Urho2DLuaAPI_TmxFile2D_SetSpriteTextureEdgeOffset00);
  tolua_function(tolua_S,"GetSpriteTextureEdgeOffset",tolua_Urho2DLuaAPI_TmxFile2D_GetSpriteTextureEdgeOffset00);
  tolua_variable(tolua_S,"edgeOffset",tolua_get_TmxFile2D_edgeOffset,tolua_set_TmxFile2D_edgeOffset);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"TileMap2D","TileMap2D","Component",NULL);
 tolua_beginmodule(tolua_S,"TileMap2D");
  tolua_function(tolua_S,"SetTmxFile",tolua_Urho2DLuaAPI_TileMap2D_SetTmxFile00);
  tolua_function(tolua_S,"GetTmxFile",tolua_Urho2DLuaAPI_TileMap2D_GetTmxFile00);
  tolua_function(tolua_S,"GetInfo",tolua_Urho2DLuaAPI_TileMap2D_GetInfo00);
  tolua_function(tolua_S,"GetNumLayers",tolua_Urho2DLuaAPI_TileMap2D_GetNumLayers00);
  tolua_function(tolua_S,"GetLayer",tolua_Urho2DLuaAPI_TileMap2D_GetLayer00);
  tolua_function(tolua_S,"TileIndexToPosition",tolua_Urho2DLuaAPI_TileMap2D_TileIndexToPosition00);
  tolua_function(tolua_S,"PositionToTileIndex",tolua_Urho2DLuaAPI_TileMap2D_PositionToTileIndex00);
  tolua_variable(tolua_S,"tmxFile",tolua_get_TileMap2D_tmxFile_ptr,tolua_set_TileMap2D_tmxFile_ptr);
  tolua_variable(tolua_S,"info",tolua_get_TileMap2D_info_ref,NULL);
  tolua_variable(tolua_S,"numLayers",tolua_get_TileMap2D_numLayers,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"TileMapLayer2D","TileMapLayer2D","Component",NULL);
 tolua_beginmodule(tolua_S,"TileMapLayer2D");
  tolua_function(tolua_S,"SetDrawOrder",tolua_Urho2DLuaAPI_TileMapLayer2D_SetDrawOrder00);
  tolua_function(tolua_S,"SetVisible",tolua_Urho2DLuaAPI_TileMapLayer2D_SetVisible00);
  tolua_function(tolua_S,"GetDrawOrder",tolua_Urho2DLuaAPI_TileMapLayer2D_GetDrawOrder00);
  tolua_function(tolua_S,"IsVisible",tolua_Urho2DLuaAPI_TileMapLayer2D_IsVisible00);
  tolua_function(tolua_S,"HasProperty",tolua_Urho2DLuaAPI_TileMapLayer2D_HasProperty00);
  tolua_function(tolua_S,"GetProperty",tolua_Urho2DLuaAPI_TileMapLayer2D_GetProperty00);
  tolua_function(tolua_S,"GetLayerType",tolua_Urho2DLuaAPI_TileMapLayer2D_GetLayerType00);
  tolua_function(tolua_S,"GetWidth",tolua_Urho2DLuaAPI_TileMapLayer2D_GetWidth00);
  tolua_function(tolua_S,"GetHeight",tolua_Urho2DLuaAPI_TileMapLayer2D_GetHeight00);
  tolua_function(tolua_S,"GetTileNode",tolua_Urho2DLuaAPI_TileMapLayer2D_GetTileNode00);
  tolua_function(tolua_S,"GetTile",tolua_Urho2DLuaAPI_TileMapLayer2D_GetTile00);
  tolua_function(tolua_S,"GetNumObjects",tolua_Urho2DLuaAPI_TileMapLayer2D_GetNumObjects00);
  tolua_function(tolua_S,"GetObject",tolua_Urho2DLuaAPI_TileMapLayer2D_GetObject00);
  tolua_function(tolua_S,"GetObjectNode",tolua_Urho2DLuaAPI_TileMapLayer2D_GetObjectNode00);
  tolua_function(tolua_S,"GetImageNode",tolua_Urho2DLuaAPI_TileMapLayer2D_GetImageNode00);
  tolua_variable(tolua_S,"drawOrder",tolua_get_TileMapLayer2D_drawOrder,NULL);
  tolua_variable(tolua_S,"visible",tolua_get_TileMapLayer2D_visible,NULL);
  tolua_variable(tolua_S,"layerType",tolua_get_TileMapLayer2D_layerType,NULL);
  tolua_variable(tolua_S,"width",tolua_get_TileMapLayer2D_width,NULL);
  tolua_variable(tolua_S,"height",tolua_get_TileMapLayer2D_height,NULL);
  tolua_variable(tolua_S,"numObjects",tolua_get_TileMapLayer2D_numObjects,NULL);
  tolua_variable(tolua_S,"imageNode",tolua_get_TileMapLayer2D_imageNode_ptr,NULL);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"BT_STATIC",BT_STATIC);
 tolua_constant(tolua_S,"BT_KINEMATIC",BT_KINEMATIC);
 tolua_constant(tolua_S,"BT_DYNAMIC",BT_DYNAMIC);
 tolua_cclass(tolua_S,"RigidBody2D","RigidBody2D","Component",NULL);
 tolua_beginmodule(tolua_S,"RigidBody2D");
  tolua_function(tolua_S,"SetBodyType",tolua_Urho2DLuaAPI_RigidBody2D_SetBodyType00);
  tolua_function(tolua_S,"SetMass",tolua_Urho2DLuaAPI_RigidBody2D_SetMass00);
  tolua_function(tolua_S,"SetInertia",tolua_Urho2DLuaAPI_RigidBody2D_SetInertia00);
  tolua_function(tolua_S,"SetMassCenter",tolua_Urho2DLuaAPI_RigidBody2D_SetMassCenter00);
  tolua_function(tolua_S,"SetUseFixtureMass",tolua_Urho2DLuaAPI_RigidBody2D_SetUseFixtureMass00);
  tolua_function(tolua_S,"SetLinearDamping",tolua_Urho2DLuaAPI_RigidBody2D_SetLinearDamping00);
  tolua_function(tolua_S,"SetAngularDamping",tolua_Urho2DLuaAPI_RigidBody2D_SetAngularDamping00);
  tolua_function(tolua_S,"SetAllowSleep",tolua_Urho2DLuaAPI_RigidBody2D_SetAllowSleep00);
  tolua_function(tolua_S,"SetFixedRotation",tolua_Urho2DLuaAPI_RigidBody2D_SetFixedRotation00);
  tolua_function(tolua_S,"SetBullet",tolua_Urho2DLuaAPI_RigidBody2D_SetBullet00);
  tolua_function(tolua_S,"SetGravityScale",tolua_Urho2DLuaAPI_RigidBody2D_SetGravityScale00);
  tolua_function(tolua_S,"SetAwake",tolua_Urho2DLuaAPI_RigidBody2D_SetAwake00);
  tolua_function(tolua_S,"SetLinearVelocity",tolua_Urho2DLuaAPI_RigidBody2D_SetLinearVelocity00);
  tolua_function(tolua_S,"SetAngularVelocity",tolua_Urho2DLuaAPI_RigidBody2D_SetAngularVelocity00);
  tolua_function(tolua_S,"ApplyForce",tolua_Urho2DLuaAPI_RigidBody2D_ApplyForce00);
  tolua_function(tolua_S,"ApplyForceToCenter",tolua_Urho2DLuaAPI_RigidBody2D_ApplyForceToCenter00);
  tolua_function(tolua_S,"ApplyTorque",tolua_Urho2DLuaAPI_RigidBody2D_ApplyTorque00);
  tolua_function(tolua_S,"ApplyLinearImpulse",tolua_Urho2DLuaAPI_RigidBody2D_ApplyLinearImpulse00);
  tolua_function(tolua_S,"ApplyLinearImpulseToCenter",tolua_Urho2DLuaAPI_RigidBody2D_ApplyLinearImpulseToCenter00);
  tolua_function(tolua_S,"ApplyAngularImpulse",tolua_Urho2DLuaAPI_RigidBody2D_ApplyAngularImpulse00);
  tolua_function(tolua_S,"GetBodyType",tolua_Urho2DLuaAPI_RigidBody2D_GetBodyType00);
  tolua_function(tolua_S,"GetMass",tolua_Urho2DLuaAPI_RigidBody2D_GetMass00);
  tolua_function(tolua_S,"GetInertia",tolua_Urho2DLuaAPI_RigidBody2D_GetInertia00);
  tolua_function(tolua_S,"GetMassCenter",tolua_Urho2DLuaAPI_RigidBody2D_GetMassCenter00);
  tolua_function(tolua_S,"GetUseFixtureMass",tolua_Urho2DLuaAPI_RigidBody2D_GetUseFixtureMass00);
  tolua_function(tolua_S,"GetLinearDamping",tolua_Urho2DLuaAPI_RigidBody2D_GetLinearDamping00);
  tolua_function(tolua_S,"GetAngularDamping",tolua_Urho2DLuaAPI_RigidBody2D_GetAngularDamping00);
  tolua_function(tolua_S,"IsAllowSleep",tolua_Urho2DLuaAPI_RigidBody2D_IsAllowSleep00);
  tolua_function(tolua_S,"IsFixedRotation",tolua_Urho2DLuaAPI_RigidBody2D_IsFixedRotation00);
  tolua_function(tolua_S,"IsBullet",tolua_Urho2DLuaAPI_RigidBody2D_IsBullet00);
  tolua_function(tolua_S,"GetGravityScale",tolua_Urho2DLuaAPI_RigidBody2D_GetGravityScale00);
  tolua_function(tolua_S,"IsAwake",tolua_Urho2DLuaAPI_RigidBody2D_IsAwake00);
  tolua_function(tolua_S,"GetLinearVelocity",tolua_Urho2DLuaAPI_RigidBody2D_GetLinearVelocity00);
  tolua_function(tolua_S,"GetAngularVelocity",tolua_Urho2DLuaAPI_RigidBody2D_GetAngularVelocity00);
  tolua_variable(tolua_S,"bodyType",tolua_get_RigidBody2D_bodyType,tolua_set_RigidBody2D_bodyType);
  tolua_variable(tolua_S,"mass",tolua_get_RigidBody2D_mass,tolua_set_RigidBody2D_mass);
  tolua_variable(tolua_S,"inertia",tolua_get_RigidBody2D_inertia,tolua_set_RigidBody2D_inertia);
  tolua_variable(tolua_S,"massCenter",tolua_get_RigidBody2D_massCenter,tolua_set_RigidBody2D_massCenter);
  tolua_variable(tolua_S,"useFixtureMass",tolua_get_RigidBody2D_useFixtureMass,tolua_set_RigidBody2D_useFixtureMass);
  tolua_variable(tolua_S,"linearDamping",tolua_get_RigidBody2D_linearDamping,tolua_set_RigidBody2D_linearDamping);
  tolua_variable(tolua_S,"angularDamping",tolua_get_RigidBody2D_angularDamping,tolua_set_RigidBody2D_angularDamping);
  tolua_variable(tolua_S,"allowSleep",tolua_get_RigidBody2D_allowSleep,tolua_set_RigidBody2D_allowSleep);
  tolua_variable(tolua_S,"fixedRotation",tolua_get_RigidBody2D_fixedRotation,tolua_set_RigidBody2D_fixedRotation);
  tolua_variable(tolua_S,"bullet",tolua_get_RigidBody2D_bullet,tolua_set_RigidBody2D_bullet);
  tolua_variable(tolua_S,"gravityScale",tolua_get_RigidBody2D_gravityScale,tolua_set_RigidBody2D_gravityScale);
  tolua_variable(tolua_S,"awake",tolua_get_RigidBody2D_awake,tolua_set_RigidBody2D_awake);
  tolua_variable(tolua_S,"linearVelocity",tolua_get_RigidBody2D_linearVelocity,tolua_set_RigidBody2D_linearVelocity);
  tolua_variable(tolua_S,"angularVelocity",tolua_get_RigidBody2D_angularVelocity,tolua_set_RigidBody2D_angularVelocity);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"PhysicsRaycastResult2D","PhysicsRaycastResult2D","",tolua_collect_PhysicsRaycastResult2D);
 #else
 tolua_cclass(tolua_S,"PhysicsRaycastResult2D","PhysicsRaycastResult2D","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"PhysicsRaycastResult2D");
  tolua_function(tolua_S,"new",tolua_Urho2DLuaAPI_PhysicsRaycastResult2D_new00);
  tolua_function(tolua_S,"new_local",tolua_Urho2DLuaAPI_PhysicsRaycastResult2D_new00_local);
  tolua_function(tolua_S,".call",tolua_Urho2DLuaAPI_PhysicsRaycastResult2D_new00_local);
  tolua_function(tolua_S,"delete",tolua_Urho2DLuaAPI_PhysicsRaycastResult2D_delete00);
  tolua_variable(tolua_S,"position",tolua_get_PhysicsRaycastResult2D_position,tolua_set_PhysicsRaycastResult2D_position);
  tolua_variable(tolua_S,"normal",tolua_get_PhysicsRaycastResult2D_normal,tolua_set_PhysicsRaycastResult2D_normal);
  tolua_variable(tolua_S,"distance",tolua_get_PhysicsRaycastResult2D_distance,tolua_set_PhysicsRaycastResult2D_distance);
  tolua_variable(tolua_S,"body",tolua_get_PhysicsRaycastResult2D_body_ptr,tolua_set_PhysicsRaycastResult2D_body_ptr);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"PhysicsWorld2D","PhysicsWorld2D","Component",NULL);
 tolua_beginmodule(tolua_S,"PhysicsWorld2D");
  tolua_function(tolua_S,"DrawDebugGeometry",tolua_Urho2DLuaAPI_PhysicsWorld2D_DrawDebugGeometry00);
  tolua_function(tolua_S,"SetUpdateEnabled",tolua_Urho2DLuaAPI_PhysicsWorld2D_SetUpdateEnabled00);
  tolua_function(tolua_S,"SetDrawShape",tolua_Urho2DLuaAPI_PhysicsWorld2D_SetDrawShape00);
  tolua_function(tolua_S,"SetDrawJoint",tolua_Urho2DLuaAPI_PhysicsWorld2D_SetDrawJoint00);
  tolua_function(tolua_S,"SetDrawAabb",tolua_Urho2DLuaAPI_PhysicsWorld2D_SetDrawAabb00);
  tolua_function(tolua_S,"SetDrawPair",tolua_Urho2DLuaAPI_PhysicsWorld2D_SetDrawPair00);
  tolua_function(tolua_S,"SetDrawCenterOfMass",tolua_Urho2DLuaAPI_PhysicsWorld2D_SetDrawCenterOfMass00);
  tolua_function(tolua_S,"SetAllowSleeping",tolua_Urho2DLuaAPI_PhysicsWorld2D_SetAllowSleeping00);
  tolua_function(tolua_S,"SetWarmStarting",tolua_Urho2DLuaAPI_PhysicsWorld2D_SetWarmStarting00);
  tolua_function(tolua_S,"SetContinuousPhysics",tolua_Urho2DLuaAPI_PhysicsWorld2D_SetContinuousPhysics00);
  tolua_function(tolua_S,"SetSubStepping",tolua_Urho2DLuaAPI_PhysicsWorld2D_SetSubStepping00);
  tolua_function(tolua_S,"SetGravity",tolua_Urho2DLuaAPI_PhysicsWorld2D_SetGravity00);
  tolua_function(tolua_S,"SetAutoClearForces",tolua_Urho2DLuaAPI_PhysicsWorld2D_SetAutoClearForces00);
  tolua_function(tolua_S,"SetVelocityIterations",tolua_Urho2DLuaAPI_PhysicsWorld2D_SetVelocityIterations00);
  tolua_function(tolua_S,"SetPositionIterations",tolua_Urho2DLuaAPI_PhysicsWorld2D_SetPositionIterations00);
  tolua_function(tolua_S,"Raycast",tolua_Urho2DLuaAPI_PhysicsWorld2D_Raycast00);
  tolua_function(tolua_S,"RaycastSingle",tolua_Urho2DLuaAPI_PhysicsWorld2D_RaycastSingle00);
  tolua_function(tolua_S,"GetRigidBody",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetRigidBody00);
  tolua_function(tolua_S,"GetRigidBody",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetRigidBody01);
  tolua_function(tolua_S,"GetRigidBodies",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetRigidBodies00);
  tolua_function(tolua_S,"IsUpdateEnabled",tolua_Urho2DLuaAPI_PhysicsWorld2D_IsUpdateEnabled00);
  tolua_function(tolua_S,"GetDrawShape",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetDrawShape00);
  tolua_function(tolua_S,"GetDrawJoint",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetDrawJoint00);
  tolua_function(tolua_S,"GetDrawAabb",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetDrawAabb00);
  tolua_function(tolua_S,"GetDrawPair",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetDrawPair00);
  tolua_function(tolua_S,"GetDrawCenterOfMass",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetDrawCenterOfMass00);
  tolua_function(tolua_S,"GetAllowSleeping",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetAllowSleeping00);
  tolua_function(tolua_S,"GetWarmStarting",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetWarmStarting00);
  tolua_function(tolua_S,"GetContinuousPhysics",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetContinuousPhysics00);
  tolua_function(tolua_S,"GetSubStepping",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetSubStepping00);
  tolua_function(tolua_S,"GetAutoClearForces",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetAutoClearForces00);
  tolua_function(tolua_S,"GetGravity",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetGravity00);
  tolua_function(tolua_S,"GetVelocityIterations",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetVelocityIterations00);
  tolua_function(tolua_S,"GetPositionIterations",tolua_Urho2DLuaAPI_PhysicsWorld2D_GetPositionIterations00);
  tolua_variable(tolua_S,"updateEnabled",tolua_get_PhysicsWorld2D_updateEnabled,tolua_set_PhysicsWorld2D_updateEnabled);
  tolua_variable(tolua_S,"drawShape",tolua_get_PhysicsWorld2D_drawShape,tolua_set_PhysicsWorld2D_drawShape);
  tolua_variable(tolua_S,"drawJoint",tolua_get_PhysicsWorld2D_drawJoint,tolua_set_PhysicsWorld2D_drawJoint);
  tolua_variable(tolua_S,"drawAabb",tolua_get_PhysicsWorld2D_drawAabb,tolua_set_PhysicsWorld2D_drawAabb);
  tolua_variable(tolua_S,"drawPair",tolua_get_PhysicsWorld2D_drawPair,tolua_set_PhysicsWorld2D_drawPair);
  tolua_variable(tolua_S,"drawCenterOfMass",tolua_get_PhysicsWorld2D_drawCenterOfMass,tolua_set_PhysicsWorld2D_drawCenterOfMass);
  tolua_variable(tolua_S,"allowSleeping",tolua_get_PhysicsWorld2D_allowSleeping,tolua_set_PhysicsWorld2D_allowSleeping);
  tolua_variable(tolua_S,"warmStarting",tolua_get_PhysicsWorld2D_warmStarting,tolua_set_PhysicsWorld2D_warmStarting);
  tolua_variable(tolua_S,"continuousPhysics",tolua_get_PhysicsWorld2D_continuousPhysics,tolua_set_PhysicsWorld2D_continuousPhysics);
  tolua_variable(tolua_S,"subStepping",tolua_get_PhysicsWorld2D_subStepping,tolua_set_PhysicsWorld2D_subStepping);
  tolua_variable(tolua_S,"autoClearForces",tolua_get_PhysicsWorld2D_autoClearForces,tolua_set_PhysicsWorld2D_autoClearForces);
  tolua_variable(tolua_S,"gravity",tolua_get_PhysicsWorld2D_gravity_ref,tolua_set_PhysicsWorld2D_gravity_ref);
  tolua_variable(tolua_S,"velocityIterations",tolua_get_PhysicsWorld2D_velocityIterations,tolua_set_PhysicsWorld2D_velocityIterations);
  tolua_variable(tolua_S,"positionIterations",tolua_get_PhysicsWorld2D_positionIterations,tolua_set_PhysicsWorld2D_positionIterations);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"CollisionShape2D","CollisionShape2D","Component",NULL);
 tolua_beginmodule(tolua_S,"CollisionShape2D");
  tolua_function(tolua_S,"SetTrigger",tolua_Urho2DLuaAPI_CollisionShape2D_SetTrigger00);
  tolua_function(tolua_S,"SetCategoryBits",tolua_Urho2DLuaAPI_CollisionShape2D_SetCategoryBits00);
  tolua_function(tolua_S,"SetMaskBits",tolua_Urho2DLuaAPI_CollisionShape2D_SetMaskBits00);
  tolua_function(tolua_S,"SetGroupIndex",tolua_Urho2DLuaAPI_CollisionShape2D_SetGroupIndex00);
  tolua_function(tolua_S,"SetDensity",tolua_Urho2DLuaAPI_CollisionShape2D_SetDensity00);
  tolua_function(tolua_S,"SetFriction",tolua_Urho2DLuaAPI_CollisionShape2D_SetFriction00);
  tolua_function(tolua_S,"SetRestitution",tolua_Urho2DLuaAPI_CollisionShape2D_SetRestitution00);
  tolua_function(tolua_S,"IsTrigger",tolua_Urho2DLuaAPI_CollisionShape2D_IsTrigger00);
  tolua_function(tolua_S,"GetCategoryBits",tolua_Urho2DLuaAPI_CollisionShape2D_GetCategoryBits00);
  tolua_function(tolua_S,"GetMaskBits",tolua_Urho2DLuaAPI_CollisionShape2D_GetMaskBits00);
  tolua_function(tolua_S,"GetGroupIndex",tolua_Urho2DLuaAPI_CollisionShape2D_GetGroupIndex00);
  tolua_function(tolua_S,"GetDensity",tolua_Urho2DLuaAPI_CollisionShape2D_GetDensity00);
  tolua_function(tolua_S,"GetFriction",tolua_Urho2DLuaAPI_CollisionShape2D_GetFriction00);
  tolua_function(tolua_S,"GetRestitution",tolua_Urho2DLuaAPI_CollisionShape2D_GetRestitution00);
  tolua_function(tolua_S,"GetMass",tolua_Urho2DLuaAPI_CollisionShape2D_GetMass00);
  tolua_function(tolua_S,"GetInertia",tolua_Urho2DLuaAPI_CollisionShape2D_GetInertia00);
  tolua_function(tolua_S,"GetMassCenter",tolua_Urho2DLuaAPI_CollisionShape2D_GetMassCenter00);
  tolua_variable(tolua_S,"trigger",tolua_get_CollisionShape2D_trigger,tolua_set_CollisionShape2D_trigger);
  tolua_variable(tolua_S,"categoryBits",tolua_get_CollisionShape2D_categoryBits,tolua_set_CollisionShape2D_categoryBits);
  tolua_variable(tolua_S,"maskBits",tolua_get_CollisionShape2D_maskBits,tolua_set_CollisionShape2D_maskBits);
  tolua_variable(tolua_S,"groupIndex",tolua_get_CollisionShape2D_groupIndex,tolua_set_CollisionShape2D_groupIndex);
  tolua_variable(tolua_S,"density",tolua_get_CollisionShape2D_density,tolua_set_CollisionShape2D_density);
  tolua_variable(tolua_S,"friction",tolua_get_CollisionShape2D_friction,tolua_set_CollisionShape2D_friction);
  tolua_variable(tolua_S,"restitution",tolua_get_CollisionShape2D_restitution,tolua_set_CollisionShape2D_restitution);
  tolua_variable(tolua_S,"mass",tolua_get_CollisionShape2D_mass,NULL);
  tolua_variable(tolua_S,"inertia",tolua_get_CollisionShape2D_inertia,NULL);
  tolua_variable(tolua_S,"massCenter",tolua_get_CollisionShape2D_massCenter,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"CollisionBox2D","CollisionBox2D","CollisionShape2D",NULL);
 tolua_beginmodule(tolua_S,"CollisionBox2D");
  tolua_function(tolua_S,"SetSize",tolua_Urho2DLuaAPI_CollisionBox2D_SetSize00);
  tolua_function(tolua_S,"SetSize",tolua_Urho2DLuaAPI_CollisionBox2D_SetSize01);
  tolua_function(tolua_S,"SetCenter",tolua_Urho2DLuaAPI_CollisionBox2D_SetCenter00);
  tolua_function(tolua_S,"SetCenter",tolua_Urho2DLuaAPI_CollisionBox2D_SetCenter01);
  tolua_function(tolua_S,"SetAngle",tolua_Urho2DLuaAPI_CollisionBox2D_SetAngle00);
  tolua_function(tolua_S,"GetSize",tolua_Urho2DLuaAPI_CollisionBox2D_GetSize00);
  tolua_function(tolua_S,"GetCenter",tolua_Urho2DLuaAPI_CollisionBox2D_GetCenter00);
  tolua_function(tolua_S,"GetAngle",tolua_Urho2DLuaAPI_CollisionBox2D_GetAngle00);
  tolua_variable(tolua_S,"size",tolua_get_CollisionBox2D_size_ref,tolua_set_CollisionBox2D_size_ref);
  tolua_variable(tolua_S,"center",tolua_get_CollisionBox2D_center_ref,tolua_set_CollisionBox2D_center_ref);
  tolua_variable(tolua_S,"angle",tolua_get_CollisionBox2D_angle,tolua_set_CollisionBox2D_angle);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"CollisionChain2D","CollisionChain2D","CollisionShape2D",NULL);
 tolua_beginmodule(tolua_S,"CollisionChain2D");
  tolua_function(tolua_S,"SetLoop",tolua_Urho2DLuaAPI_CollisionChain2D_SetLoop00);
  tolua_function(tolua_S,"SetVertexCount",tolua_Urho2DLuaAPI_CollisionChain2D_SetVertexCount00);
  tolua_function(tolua_S,"SetVertex",tolua_Urho2DLuaAPI_CollisionChain2D_SetVertex00);
  tolua_function(tolua_S,"SetVertices",tolua_Urho2DLuaAPI_CollisionChain2D_SetVertices00);
  tolua_function(tolua_S,"GetLoop",tolua_Urho2DLuaAPI_CollisionChain2D_GetLoop00);
  tolua_function(tolua_S,"GetVertexCount",tolua_Urho2DLuaAPI_CollisionChain2D_GetVertexCount00);
  tolua_function(tolua_S,"GetVertex",tolua_Urho2DLuaAPI_CollisionChain2D_GetVertex00);
  tolua_variable(tolua_S,"loop",tolua_get_CollisionChain2D_loop,tolua_set_CollisionChain2D_loop);
  tolua_variable(tolua_S,"vertexCount",tolua_get_CollisionChain2D_vertexCount,tolua_set_CollisionChain2D_vertexCount);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"CollisionCircle2D","CollisionCircle2D","CollisionShape2D",NULL);
 tolua_beginmodule(tolua_S,"CollisionCircle2D");
  tolua_function(tolua_S,"SetRadius",tolua_Urho2DLuaAPI_CollisionCircle2D_SetRadius00);
  tolua_function(tolua_S,"SetCenter",tolua_Urho2DLuaAPI_CollisionCircle2D_SetCenter00);
  tolua_function(tolua_S,"SetCenter",tolua_Urho2DLuaAPI_CollisionCircle2D_SetCenter01);
  tolua_function(tolua_S,"GetRadius",tolua_Urho2DLuaAPI_CollisionCircle2D_GetRadius00);
  tolua_function(tolua_S,"GetCenter",tolua_Urho2DLuaAPI_CollisionCircle2D_GetCenter00);
  tolua_variable(tolua_S,"radius",tolua_get_CollisionCircle2D_radius,tolua_set_CollisionCircle2D_radius);
  tolua_variable(tolua_S,"center",tolua_get_CollisionCircle2D_center_ref,tolua_set_CollisionCircle2D_center_ref);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"CollisionEdge2D","CollisionEdge2D","CollisionShape2D",NULL);
 tolua_beginmodule(tolua_S,"CollisionEdge2D");
  tolua_function(tolua_S,"SetVertex1",tolua_Urho2DLuaAPI_CollisionEdge2D_SetVertex100);
  tolua_function(tolua_S,"SetVertex2",tolua_Urho2DLuaAPI_CollisionEdge2D_SetVertex200);
  tolua_function(tolua_S,"SetVertices",tolua_Urho2DLuaAPI_CollisionEdge2D_SetVertices00);
  tolua_function(tolua_S,"GetVertex1",tolua_Urho2DLuaAPI_CollisionEdge2D_GetVertex100);
  tolua_function(tolua_S,"GetVertex2",tolua_Urho2DLuaAPI_CollisionEdge2D_GetVertex200);
  tolua_variable(tolua_S,"vertex1",tolua_get_CollisionEdge2D_vertex1_ref,tolua_set_CollisionEdge2D_vertex1_ref);
  tolua_variable(tolua_S,"vertex2",tolua_get_CollisionEdge2D_vertex2_ref,tolua_set_CollisionEdge2D_vertex2_ref);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"CollisionPolygon2D","CollisionPolygon2D","CollisionShape2D",NULL);
 tolua_beginmodule(tolua_S,"CollisionPolygon2D");
  tolua_function(tolua_S,"SetVertexCount",tolua_Urho2DLuaAPI_CollisionPolygon2D_SetVertexCount00);
  tolua_function(tolua_S,"SetVertex",tolua_Urho2DLuaAPI_CollisionPolygon2D_SetVertex00);
  tolua_function(tolua_S,"SetVertices",tolua_Urho2DLuaAPI_CollisionPolygon2D_SetVertices00);
  tolua_function(tolua_S,"GetVertexCount",tolua_Urho2DLuaAPI_CollisionPolygon2D_GetVertexCount00);
  tolua_function(tolua_S,"GetVertex",tolua_Urho2DLuaAPI_CollisionPolygon2D_GetVertex00);
  tolua_variable(tolua_S,"vertexCount",tolua_get_CollisionPolygon2D_vertexCount,tolua_set_CollisionPolygon2D_vertexCount);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Constraint2D","Constraint2D","Component",NULL);
 tolua_beginmodule(tolua_S,"Constraint2D");
  tolua_function(tolua_S,"SetOtherBody",tolua_Urho2DLuaAPI_Constraint2D_SetOtherBody00);
  tolua_function(tolua_S,"SetCollideConnected",tolua_Urho2DLuaAPI_Constraint2D_SetCollideConnected00);
  tolua_function(tolua_S,"GetOwnerBody",tolua_Urho2DLuaAPI_Constraint2D_GetOwnerBody00);
  tolua_function(tolua_S,"GetOtherBody",tolua_Urho2DLuaAPI_Constraint2D_GetOtherBody00);
  tolua_function(tolua_S,"GetCollideConnected",tolua_Urho2DLuaAPI_Constraint2D_GetCollideConnected00);
  tolua_variable(tolua_S,"ownerBody",tolua_get_Constraint2D_ownerBody_ptr,NULL);
  tolua_variable(tolua_S,"otherBody",tolua_get_Constraint2D_otherBody_ptr,tolua_set_Constraint2D_otherBody_ptr);
  tolua_variable(tolua_S,"collideConnected",tolua_get_Constraint2D_collideConnected,tolua_set_Constraint2D_collideConnected);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"ConstraintDistance2D","ConstraintDistance2D","Constraint2D",NULL);
 tolua_beginmodule(tolua_S,"ConstraintDistance2D");
  tolua_function(tolua_S,"SetOwnerBodyAnchor",tolua_Urho2DLuaAPI_ConstraintDistance2D_SetOwnerBodyAnchor00);
  tolua_function(tolua_S,"SetOtherBodyAnchor",tolua_Urho2DLuaAPI_ConstraintDistance2D_SetOtherBodyAnchor00);
  tolua_function(tolua_S,"SetFrequencyHz",tolua_Urho2DLuaAPI_ConstraintDistance2D_SetFrequencyHz00);
  tolua_function(tolua_S,"SetDampingRatio",tolua_Urho2DLuaAPI_ConstraintDistance2D_SetDampingRatio00);
  tolua_function(tolua_S,"SetLength",tolua_Urho2DLuaAPI_ConstraintDistance2D_SetLength00);
  tolua_function(tolua_S,"GetOwnerBodyAnchor",tolua_Urho2DLuaAPI_ConstraintDistance2D_GetOwnerBodyAnchor00);
  tolua_function(tolua_S,"GetOtherBodyAnchor",tolua_Urho2DLuaAPI_ConstraintDistance2D_GetOtherBodyAnchor00);
  tolua_function(tolua_S,"GetFrequencyHz",tolua_Urho2DLuaAPI_ConstraintDistance2D_GetFrequencyHz00);
  tolua_function(tolua_S,"GetDampingRatio",tolua_Urho2DLuaAPI_ConstraintDistance2D_GetDampingRatio00);
  tolua_function(tolua_S,"GetLength",tolua_Urho2DLuaAPI_ConstraintDistance2D_GetLength00);
  tolua_variable(tolua_S,"ownerBodyAnchor",tolua_get_ConstraintDistance2D_ownerBodyAnchor_ref,tolua_set_ConstraintDistance2D_ownerBodyAnchor_ref);
  tolua_variable(tolua_S,"otherBodyAnchor",tolua_get_ConstraintDistance2D_otherBodyAnchor_ref,tolua_set_ConstraintDistance2D_otherBodyAnchor_ref);
  tolua_variable(tolua_S,"frequencyHz",tolua_get_ConstraintDistance2D_frequencyHz,tolua_set_ConstraintDistance2D_frequencyHz);
  tolua_variable(tolua_S,"dampingRatio",tolua_get_ConstraintDistance2D_dampingRatio,tolua_set_ConstraintDistance2D_dampingRatio);
  tolua_variable(tolua_S,"length",tolua_get_ConstraintDistance2D_length,tolua_set_ConstraintDistance2D_length);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"ConstraintFriction2D","ConstraintFriction2D","Constraint2D",NULL);
 tolua_beginmodule(tolua_S,"ConstraintFriction2D");
  tolua_function(tolua_S,"SetAnchor",tolua_Urho2DLuaAPI_ConstraintFriction2D_SetAnchor00);
  tolua_function(tolua_S,"SetMaxForce",tolua_Urho2DLuaAPI_ConstraintFriction2D_SetMaxForce00);
  tolua_function(tolua_S,"SetMaxTorque",tolua_Urho2DLuaAPI_ConstraintFriction2D_SetMaxTorque00);
  tolua_function(tolua_S,"GetAnchor",tolua_Urho2DLuaAPI_ConstraintFriction2D_GetAnchor00);
  tolua_function(tolua_S,"GetMaxForce",tolua_Urho2DLuaAPI_ConstraintFriction2D_GetMaxForce00);
  tolua_function(tolua_S,"GetMaxTorque",tolua_Urho2DLuaAPI_ConstraintFriction2D_GetMaxTorque00);
  tolua_variable(tolua_S,"anchor",tolua_get_ConstraintFriction2D_anchor_ref,tolua_set_ConstraintFriction2D_anchor_ref);
  tolua_variable(tolua_S,"maxForce",tolua_get_ConstraintFriction2D_maxForce,tolua_set_ConstraintFriction2D_maxForce);
  tolua_variable(tolua_S,"maxTorque",tolua_get_ConstraintFriction2D_maxTorque,tolua_set_ConstraintFriction2D_maxTorque);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"ConstraintGear2D","ConstraintGear2D","Constraint2D",NULL);
 tolua_beginmodule(tolua_S,"ConstraintGear2D");
  tolua_function(tolua_S,"SetOwnerConstraint",tolua_Urho2DLuaAPI_ConstraintGear2D_SetOwnerConstraint00);
  tolua_function(tolua_S,"SetOtherConstraint",tolua_Urho2DLuaAPI_ConstraintGear2D_SetOtherConstraint00);
  tolua_function(tolua_S,"SetRatio",tolua_Urho2DLuaAPI_ConstraintGear2D_SetRatio00);
  tolua_function(tolua_S,"GetOwnerConstraint",tolua_Urho2DLuaAPI_ConstraintGear2D_GetOwnerConstraint00);
  tolua_function(tolua_S,"GetOtherConstraint",tolua_Urho2DLuaAPI_ConstraintGear2D_GetOtherConstraint00);
  tolua_function(tolua_S,"GetRatio",tolua_Urho2DLuaAPI_ConstraintGear2D_GetRatio00);
  tolua_variable(tolua_S,"ownerConstraint",tolua_get_ConstraintGear2D_ownerConstraint_ptr,tolua_set_ConstraintGear2D_ownerConstraint_ptr);
  tolua_variable(tolua_S,"otherConstraint",tolua_get_ConstraintGear2D_otherConstraint_ptr,tolua_set_ConstraintGear2D_otherConstraint_ptr);
  tolua_variable(tolua_S,"ratio",tolua_get_ConstraintGear2D_ratio,tolua_set_ConstraintGear2D_ratio);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"ConstraintMotor2D","ConstraintMotor2D","Constraint2D",NULL);
 tolua_beginmodule(tolua_S,"ConstraintMotor2D");
  tolua_function(tolua_S,"SetLinearOffset",tolua_Urho2DLuaAPI_ConstraintMotor2D_SetLinearOffset00);
  tolua_function(tolua_S,"SetAngularOffset",tolua_Urho2DLuaAPI_ConstraintMotor2D_SetAngularOffset00);
  tolua_function(tolua_S,"SetMaxForce",tolua_Urho2DLuaAPI_ConstraintMotor2D_SetMaxForce00);
  tolua_function(tolua_S,"SetMaxTorque",tolua_Urho2DLuaAPI_ConstraintMotor2D_SetMaxTorque00);
  tolua_function(tolua_S,"SetCorrectionFactor",tolua_Urho2DLuaAPI_ConstraintMotor2D_SetCorrectionFactor00);
  tolua_function(tolua_S,"GetLinearOffset",tolua_Urho2DLuaAPI_ConstraintMotor2D_GetLinearOffset00);
  tolua_function(tolua_S,"GetAngularOffset",tolua_Urho2DLuaAPI_ConstraintMotor2D_GetAngularOffset00);
  tolua_function(tolua_S,"GetMaxForce",tolua_Urho2DLuaAPI_ConstraintMotor2D_GetMaxForce00);
  tolua_function(tolua_S,"GetMaxTorque",tolua_Urho2DLuaAPI_ConstraintMotor2D_GetMaxTorque00);
  tolua_function(tolua_S,"GetCorrectionFactor",tolua_Urho2DLuaAPI_ConstraintMotor2D_GetCorrectionFactor00);
  tolua_variable(tolua_S,"linearOffset",tolua_get_ConstraintMotor2D_linearOffset_ref,tolua_set_ConstraintMotor2D_linearOffset_ref);
  tolua_variable(tolua_S,"angularOffset",tolua_get_ConstraintMotor2D_angularOffset,tolua_set_ConstraintMotor2D_angularOffset);
  tolua_variable(tolua_S,"maxForce",tolua_get_ConstraintMotor2D_maxForce,tolua_set_ConstraintMotor2D_maxForce);
  tolua_variable(tolua_S,"maxTorque",tolua_get_ConstraintMotor2D_maxTorque,tolua_set_ConstraintMotor2D_maxTorque);
  tolua_variable(tolua_S,"correctionFactor",tolua_get_ConstraintMotor2D_correctionFactor,tolua_set_ConstraintMotor2D_correctionFactor);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"ConstraintMouse2D","ConstraintMouse2D","Constraint2D",NULL);
 tolua_beginmodule(tolua_S,"ConstraintMouse2D");
  tolua_function(tolua_S,"SetTarget",tolua_Urho2DLuaAPI_ConstraintMouse2D_SetTarget00);
  tolua_function(tolua_S,"SetMaxForce",tolua_Urho2DLuaAPI_ConstraintMouse2D_SetMaxForce00);
  tolua_function(tolua_S,"SetFrequencyHz",tolua_Urho2DLuaAPI_ConstraintMouse2D_SetFrequencyHz00);
  tolua_function(tolua_S,"SetDampingRatio",tolua_Urho2DLuaAPI_ConstraintMouse2D_SetDampingRatio00);
  tolua_function(tolua_S,"GetTarget",tolua_Urho2DLuaAPI_ConstraintMouse2D_GetTarget00);
  tolua_function(tolua_S,"GetMaxForce",tolua_Urho2DLuaAPI_ConstraintMouse2D_GetMaxForce00);
  tolua_function(tolua_S,"GetFrequencyHz",tolua_Urho2DLuaAPI_ConstraintMouse2D_GetFrequencyHz00);
  tolua_function(tolua_S,"GetDampingRatio",tolua_Urho2DLuaAPI_ConstraintMouse2D_GetDampingRatio00);
  tolua_variable(tolua_S,"target",tolua_get_ConstraintMouse2D_target_ref,tolua_set_ConstraintMouse2D_target_ref);
  tolua_variable(tolua_S,"maxForce",tolua_get_ConstraintMouse2D_maxForce,tolua_set_ConstraintMouse2D_maxForce);
  tolua_variable(tolua_S,"frequencyHz",tolua_get_ConstraintMouse2D_frequencyHz,tolua_set_ConstraintMouse2D_frequencyHz);
  tolua_variable(tolua_S,"dampingRatio",tolua_get_ConstraintMouse2D_dampingRatio,tolua_set_ConstraintMouse2D_dampingRatio);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"ConstraintPrismatic2D","ConstraintPrismatic2D","Constraint2D",NULL);
 tolua_beginmodule(tolua_S,"ConstraintPrismatic2D");
  tolua_function(tolua_S,"SetAnchor",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetAnchor00);
  tolua_function(tolua_S,"SetAxis",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetAxis00);
  tolua_function(tolua_S,"SetEnableLimit",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetEnableLimit00);
  tolua_function(tolua_S,"SetLowerTranslation",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetLowerTranslation00);
  tolua_function(tolua_S,"SetUpperTranslation",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetUpperTranslation00);
  tolua_function(tolua_S,"SetEnableMotor",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetEnableMotor00);
  tolua_function(tolua_S,"SetMaxMotorForce",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetMaxMotorForce00);
  tolua_function(tolua_S,"SetMotorSpeed",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_SetMotorSpeed00);
  tolua_function(tolua_S,"GetAnchor",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetAnchor00);
  tolua_function(tolua_S,"GetAxis",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetAxis00);
  tolua_function(tolua_S,"GetEnableLimit",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetEnableLimit00);
  tolua_function(tolua_S,"GetLowerTranslation",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetLowerTranslation00);
  tolua_function(tolua_S,"GetUpperTranslation",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetUpperTranslation00);
  tolua_function(tolua_S,"GetEnableMotor",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetEnableMotor00);
  tolua_function(tolua_S,"GetMaxMotorForce",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetMaxMotorForce00);
  tolua_function(tolua_S,"GetMotorSpeed",tolua_Urho2DLuaAPI_ConstraintPrismatic2D_GetMotorSpeed00);
  tolua_variable(tolua_S,"anchor",tolua_get_ConstraintPrismatic2D_anchor_ref,tolua_set_ConstraintPrismatic2D_anchor_ref);
  tolua_variable(tolua_S,"axis",tolua_get_ConstraintPrismatic2D_axis_ref,tolua_set_ConstraintPrismatic2D_axis_ref);
  tolua_variable(tolua_S,"enableLimit",tolua_get_ConstraintPrismatic2D_enableLimit,tolua_set_ConstraintPrismatic2D_enableLimit);
  tolua_variable(tolua_S,"lowerTranslation",tolua_get_ConstraintPrismatic2D_lowerTranslation,tolua_set_ConstraintPrismatic2D_lowerTranslation);
  tolua_variable(tolua_S,"upperTranslation",tolua_get_ConstraintPrismatic2D_upperTranslation,tolua_set_ConstraintPrismatic2D_upperTranslation);
  tolua_variable(tolua_S,"enableMotor",tolua_get_ConstraintPrismatic2D_enableMotor,tolua_set_ConstraintPrismatic2D_enableMotor);
  tolua_variable(tolua_S,"maxMotorForce",tolua_get_ConstraintPrismatic2D_maxMotorForce,tolua_set_ConstraintPrismatic2D_maxMotorForce);
  tolua_variable(tolua_S,"motorSpeed",tolua_get_ConstraintPrismatic2D_motorSpeed,tolua_set_ConstraintPrismatic2D_motorSpeed);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"ConstraintPulley2D","ConstraintPulley2D","Constraint2D",NULL);
 tolua_beginmodule(tolua_S,"ConstraintPulley2D");
  tolua_function(tolua_S,"SetOwnerBodyGroundAnchor",tolua_Urho2DLuaAPI_ConstraintPulley2D_SetOwnerBodyGroundAnchor00);
  tolua_function(tolua_S,"SetOtherBodyGroundAnchor",tolua_Urho2DLuaAPI_ConstraintPulley2D_SetOtherBodyGroundAnchor00);
  tolua_function(tolua_S,"SetOwnerBodyAnchor",tolua_Urho2DLuaAPI_ConstraintPulley2D_SetOwnerBodyAnchor00);
  tolua_function(tolua_S,"SetOtherBodyAnchor",tolua_Urho2DLuaAPI_ConstraintPulley2D_SetOtherBodyAnchor00);
  tolua_function(tolua_S,"SetRatio",tolua_Urho2DLuaAPI_ConstraintPulley2D_SetRatio00);
  tolua_function(tolua_S,"GetOwnerBodyGroundAnchor",tolua_Urho2DLuaAPI_ConstraintPulley2D_GetOwnerBodyGroundAnchor00);
  tolua_function(tolua_S,"GetOtherBodyGroundAnchor",tolua_Urho2DLuaAPI_ConstraintPulley2D_GetOtherBodyGroundAnchor00);
  tolua_function(tolua_S,"GetOwnerBodyAnchor",tolua_Urho2DLuaAPI_ConstraintPulley2D_GetOwnerBodyAnchor00);
  tolua_function(tolua_S,"GetOtherBodyAnchor",tolua_Urho2DLuaAPI_ConstraintPulley2D_GetOtherBodyAnchor00);
  tolua_function(tolua_S,"GetRatio",tolua_Urho2DLuaAPI_ConstraintPulley2D_GetRatio00);
  tolua_variable(tolua_S,"ownerBodyGroundAnchor",tolua_get_ConstraintPulley2D_ownerBodyGroundAnchor_ref,tolua_set_ConstraintPulley2D_ownerBodyGroundAnchor_ref);
  tolua_variable(tolua_S,"otherBodyGroundAnchor",tolua_get_ConstraintPulley2D_otherBodyGroundAnchor_ref,tolua_set_ConstraintPulley2D_otherBodyGroundAnchor_ref);
  tolua_variable(tolua_S,"ownerBodyAnchor",tolua_get_ConstraintPulley2D_ownerBodyAnchor_ref,tolua_set_ConstraintPulley2D_ownerBodyAnchor_ref);
  tolua_variable(tolua_S,"otherBodyAnchor",tolua_get_ConstraintPulley2D_otherBodyAnchor_ref,tolua_set_ConstraintPulley2D_otherBodyAnchor_ref);
  tolua_variable(tolua_S,"ratio",tolua_get_ConstraintPulley2D_ratio,tolua_set_ConstraintPulley2D_ratio);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"ConstraintRevolute2D","ConstraintRevolute2D","Constraint2D",NULL);
 tolua_beginmodule(tolua_S,"ConstraintRevolute2D");
  tolua_function(tolua_S,"SetAnchor",tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetAnchor00);
  tolua_function(tolua_S,"SetEnableLimit",tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetEnableLimit00);
  tolua_function(tolua_S,"SetLowerAngle",tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetLowerAngle00);
  tolua_function(tolua_S,"SetUpperAngle",tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetUpperAngle00);
  tolua_function(tolua_S,"SetEnableMotor",tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetEnableMotor00);
  tolua_function(tolua_S,"SetMotorSpeed",tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetMotorSpeed00);
  tolua_function(tolua_S,"SetMaxMotorTorque",tolua_Urho2DLuaAPI_ConstraintRevolute2D_SetMaxMotorTorque00);
  tolua_function(tolua_S,"GetAnchor",tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetAnchor00);
  tolua_function(tolua_S,"GetEnableLimit",tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetEnableLimit00);
  tolua_function(tolua_S,"GetLowerAngle",tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetLowerAngle00);
  tolua_function(tolua_S,"GetUpperAngle",tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetUpperAngle00);
  tolua_function(tolua_S,"GetEnableMotor",tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetEnableMotor00);
  tolua_function(tolua_S,"GetMotorSpeed",tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetMotorSpeed00);
  tolua_function(tolua_S,"GetMaxMotorTorque",tolua_Urho2DLuaAPI_ConstraintRevolute2D_GetMaxMotorTorque00);
  tolua_variable(tolua_S,"anchor",tolua_get_ConstraintRevolute2D_anchor_ref,tolua_set_ConstraintRevolute2D_anchor_ref);
  tolua_variable(tolua_S,"enableLimit",tolua_get_ConstraintRevolute2D_enableLimit,tolua_set_ConstraintRevolute2D_enableLimit);
  tolua_variable(tolua_S,"lowerAngle",tolua_get_ConstraintRevolute2D_lowerAngle,tolua_set_ConstraintRevolute2D_lowerAngle);
  tolua_variable(tolua_S,"upperAngle",tolua_get_ConstraintRevolute2D_upperAngle,tolua_set_ConstraintRevolute2D_upperAngle);
  tolua_variable(tolua_S,"enableMotor",tolua_get_ConstraintRevolute2D_enableMotor,tolua_set_ConstraintRevolute2D_enableMotor);
  tolua_variable(tolua_S,"motorSpeed",tolua_get_ConstraintRevolute2D_motorSpeed,tolua_set_ConstraintRevolute2D_motorSpeed);
  tolua_variable(tolua_S,"maxMotorTorque",tolua_get_ConstraintRevolute2D_maxMotorTorque,tolua_set_ConstraintRevolute2D_maxMotorTorque);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"ConstraintRope2D","ConstraintRope2D","Constraint2D",NULL);
 tolua_beginmodule(tolua_S,"ConstraintRope2D");
  tolua_function(tolua_S,"SetOwnerBodyAnchor",tolua_Urho2DLuaAPI_ConstraintRope2D_SetOwnerBodyAnchor00);
  tolua_function(tolua_S,"SetOtherBodyAnchor",tolua_Urho2DLuaAPI_ConstraintRope2D_SetOtherBodyAnchor00);
  tolua_function(tolua_S,"SetMaxLength",tolua_Urho2DLuaAPI_ConstraintRope2D_SetMaxLength00);
  tolua_function(tolua_S,"GetOwnerBodyAnchor",tolua_Urho2DLuaAPI_ConstraintRope2D_GetOwnerBodyAnchor00);
  tolua_function(tolua_S,"GetOtherBodyAnchor",tolua_Urho2DLuaAPI_ConstraintRope2D_GetOtherBodyAnchor00);
  tolua_function(tolua_S,"GetMaxLength",tolua_Urho2DLuaAPI_ConstraintRope2D_GetMaxLength00);
  tolua_variable(tolua_S,"ownerBodyAnchor",tolua_get_ConstraintRope2D_ownerBodyAnchor_ref,tolua_set_ConstraintRope2D_ownerBodyAnchor_ref);
  tolua_variable(tolua_S,"otherBodyAnchor",tolua_get_ConstraintRope2D_otherBodyAnchor_ref,tolua_set_ConstraintRope2D_otherBodyAnchor_ref);
  tolua_variable(tolua_S,"maxLength",tolua_get_ConstraintRope2D_maxLength,tolua_set_ConstraintRope2D_maxLength);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"ConstraintWeld2D","ConstraintWeld2D","Constraint2D",NULL);
 tolua_beginmodule(tolua_S,"ConstraintWeld2D");
  tolua_function(tolua_S,"SetAnchor",tolua_Urho2DLuaAPI_ConstraintWeld2D_SetAnchor00);
  tolua_function(tolua_S,"SetFrequencyHz",tolua_Urho2DLuaAPI_ConstraintWeld2D_SetFrequencyHz00);
  tolua_function(tolua_S,"SetDampingRatio",tolua_Urho2DLuaAPI_ConstraintWeld2D_SetDampingRatio00);
  tolua_function(tolua_S,"GetAnchor",tolua_Urho2DLuaAPI_ConstraintWeld2D_GetAnchor00);
  tolua_function(tolua_S,"GetFrequencyHz",tolua_Urho2DLuaAPI_ConstraintWeld2D_GetFrequencyHz00);
  tolua_function(tolua_S,"GetDampingRatio",tolua_Urho2DLuaAPI_ConstraintWeld2D_GetDampingRatio00);
  tolua_variable(tolua_S,"anchor",tolua_get_ConstraintWeld2D_anchor_ref,tolua_set_ConstraintWeld2D_anchor_ref);
  tolua_variable(tolua_S,"frequencyHz",tolua_get_ConstraintWeld2D_frequencyHz,tolua_set_ConstraintWeld2D_frequencyHz);
  tolua_variable(tolua_S,"dampingRatio",tolua_get_ConstraintWeld2D_dampingRatio,tolua_set_ConstraintWeld2D_dampingRatio);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"ConstraintWheel2D","ConstraintWheel2D","Constraint2D",NULL);
 tolua_beginmodule(tolua_S,"ConstraintWheel2D");
  tolua_function(tolua_S,"SetAnchor",tolua_Urho2DLuaAPI_ConstraintWheel2D_SetAnchor00);
  tolua_function(tolua_S,"SetAxis",tolua_Urho2DLuaAPI_ConstraintWheel2D_SetAxis00);
  tolua_function(tolua_S,"SetEnableMotor",tolua_Urho2DLuaAPI_ConstraintWheel2D_SetEnableMotor00);
  tolua_function(tolua_S,"SetMaxMotorTorque",tolua_Urho2DLuaAPI_ConstraintWheel2D_SetMaxMotorTorque00);
  tolua_function(tolua_S,"SetMotorSpeed",tolua_Urho2DLuaAPI_ConstraintWheel2D_SetMotorSpeed00);
  tolua_function(tolua_S,"SetFrequencyHz",tolua_Urho2DLuaAPI_ConstraintWheel2D_SetFrequencyHz00);
  tolua_function(tolua_S,"SetDampingRatio",tolua_Urho2DLuaAPI_ConstraintWheel2D_SetDampingRatio00);
  tolua_function(tolua_S,"GetAnchor",tolua_Urho2DLuaAPI_ConstraintWheel2D_GetAnchor00);
  tolua_function(tolua_S,"GetAxis",tolua_Urho2DLuaAPI_ConstraintWheel2D_GetAxis00);
  tolua_function(tolua_S,"GetEnableMotor",tolua_Urho2DLuaAPI_ConstraintWheel2D_GetEnableMotor00);
  tolua_function(tolua_S,"GetMaxMotorTorque",tolua_Urho2DLuaAPI_ConstraintWheel2D_GetMaxMotorTorque00);
  tolua_function(tolua_S,"GetMotorSpeed",tolua_Urho2DLuaAPI_ConstraintWheel2D_GetMotorSpeed00);
  tolua_function(tolua_S,"GetFrequencyHz",tolua_Urho2DLuaAPI_ConstraintWheel2D_GetFrequencyHz00);
  tolua_function(tolua_S,"GetDampingRatio",tolua_Urho2DLuaAPI_ConstraintWheel2D_GetDampingRatio00);
  tolua_variable(tolua_S,"anchor",tolua_get_ConstraintWheel2D_anchor_ref,tolua_set_ConstraintWheel2D_anchor_ref);
  tolua_variable(tolua_S,"axis",tolua_get_ConstraintWheel2D_axis_ref,tolua_set_ConstraintWheel2D_axis_ref);
  tolua_variable(tolua_S,"enableMotor",tolua_get_ConstraintWheel2D_enableMotor,tolua_set_ConstraintWheel2D_enableMotor);
  tolua_variable(tolua_S,"maxMotorTorque",tolua_get_ConstraintWheel2D_maxMotorTorque,tolua_set_ConstraintWheel2D_maxMotorTorque);
  tolua_variable(tolua_S,"motorSpeed",tolua_get_ConstraintWheel2D_motorSpeed,tolua_set_ConstraintWheel2D_motorSpeed);
  tolua_variable(tolua_S,"frequencyHz",tolua_get_ConstraintWheel2D_frequencyHz,tolua_set_ConstraintWheel2D_frequencyHz);
  tolua_variable(tolua_S,"dampingRatio",tolua_get_ConstraintWheel2D_dampingRatio,tolua_set_ConstraintWheel2D_dampingRatio);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Urho2DLuaAPI (lua_State* tolua_S) {
 return tolua_Urho2DLuaAPI_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif