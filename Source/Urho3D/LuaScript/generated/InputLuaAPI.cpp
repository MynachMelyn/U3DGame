/*
** Lua binding: InputLuaAPI
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
TOLUA_API int tolua_InputLuaAPI_open (lua_State* tolua_S);

#include "Input/Controls.h"
#include "IO/File.h"
#include "Input/Input.h"
#include "Input/InputEvents.h"
using namespace Urho3D;
#pragma warning(disable:4800)

static bool InputSaveGestures(Input* input, File* file)
{
    return file ? input->SaveGestures(*file) : false;
}

static bool InputSaveGesture(Input* input, File* file, unsigned gestureID)
{
    return file ? input->SaveGesture(*file, gestureID) : false;
}

static unsigned InputLoadGestures(Input* input, File* file)
{
    return file ? input->LoadGestures(*file) : 0;
}

static bool InputSaveGestures(Input* input, const String& fileName)
{
    File file(input->GetContext(), fileName, FILE_WRITE);
    return file.IsOpen() ? input->SaveGestures(file) : false;
}

static bool InputSaveGesture(Input* input, const String& fileName, unsigned gestureID)
{
    File file(input->GetContext(), fileName, FILE_WRITE);
    return file.IsOpen() ? input->SaveGesture(file, gestureID) : false;
}

static unsigned InputLoadGestures(Input* input, const String& fileName)
{
    File file(input->GetContext(), fileName, FILE_READ);
    return file.IsOpen() ? input->LoadGestures(file) : 0;
}

#define TOLUA_DISABLE_tolua_InputLuaAPI_GetInput00
static int tolua_InputLuaAPI_GetInput00(lua_State* tolua_S)
{
    return ToluaGetSubsystem<Input>(tolua_S);
}

#define TOLUA_DISABLE_tolua_get_input_ptr
#define tolua_get_input_ptr tolua_InputLuaAPI_GetInput00

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Controls (lua_State* tolua_S)
{
 Controls* self = (Controls*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Vector2 (lua_State* tolua_S)
{
 Vector2* self = (Vector2*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_IntVector2 (lua_State* tolua_S)
{
 IntVector2* self = (IntVector2*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"VariantMap");
 tolua_usertype(tolua_S,"XMLFile");
 tolua_usertype(tolua_S,"UIElement");
 tolua_usertype(tolua_S,"JoystickState");
 tolua_usertype(tolua_S,"TouchState");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"Input");
 tolua_usertype(tolua_S,"File");
 tolua_usertype(tolua_S,"Controls");
 tolua_usertype(tolua_S,"IntVector2");
}

/* method: new of class  Controls */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Controls_new00
static int tolua_InputLuaAPI_Controls_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Controls",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Controls* tolua_ret = (Controls*)  Mtolua_new((Controls)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Controls");
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

/* method: new_local of class  Controls */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Controls_new00_local
static int tolua_InputLuaAPI_Controls_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Controls",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Controls* tolua_ret = (Controls*)  Mtolua_new((Controls)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Controls");
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

/* method: delete of class  Controls */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Controls_delete00
static int tolua_InputLuaAPI_Controls_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Controls",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Controls* self = (Controls*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Reset of class  Controls */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Controls_Reset00
static int tolua_InputLuaAPI_Controls_Reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Controls",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Controls* self = (Controls*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Reset'", NULL);
#endif
 {
  self->Reset();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set of class  Controls */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Controls_Set00
static int tolua_InputLuaAPI_Controls_Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Controls",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Controls* self = (Controls*)  tolua_tousertype(tolua_S,1,0);
  unsigned buttons = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  bool down = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
 {
  self->Set(buttons,down);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsDown of class  Controls */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Controls_IsDown00
static int tolua_InputLuaAPI_Controls_IsDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Controls",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Controls* self = (const Controls*)  tolua_tousertype(tolua_S,1,0);
  unsigned button = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsDown'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsDown(button);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsPressed of class  Controls */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Controls_IsPressed00
static int tolua_InputLuaAPI_Controls_IsPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Controls",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Controls",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Controls* self = (const Controls*)  tolua_tousertype(tolua_S,1,0);
  unsigned button = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  const Controls* previousControls = ((const Controls*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsPressed'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsPressed(button,*previousControls);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsPressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: buttons_ of class  Controls */
#ifndef TOLUA_DISABLE_tolua_get_Controls_buttons
static int tolua_get_Controls_buttons(lua_State* tolua_S)
{
  Controls* self = (Controls*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'buttons_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->buttons_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: buttons_ of class  Controls */
#ifndef TOLUA_DISABLE_tolua_set_Controls_buttons
static int tolua_set_Controls_buttons(lua_State* tolua_S)
{
  Controls* self = (Controls*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'buttons_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->buttons_ = ((unsigned)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: yaw_ of class  Controls */
#ifndef TOLUA_DISABLE_tolua_get_Controls_yaw
static int tolua_get_Controls_yaw(lua_State* tolua_S)
{
  Controls* self = (Controls*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'yaw_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->yaw_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: yaw_ of class  Controls */
#ifndef TOLUA_DISABLE_tolua_set_Controls_yaw
static int tolua_set_Controls_yaw(lua_State* tolua_S)
{
  Controls* self = (Controls*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'yaw_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->yaw_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pitch_ of class  Controls */
#ifndef TOLUA_DISABLE_tolua_get_Controls_pitch
static int tolua_get_Controls_pitch(lua_State* tolua_S)
{
  Controls* self = (Controls*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pitch_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->pitch_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pitch_ of class  Controls */
#ifndef TOLUA_DISABLE_tolua_set_Controls_pitch
static int tolua_set_Controls_pitch(lua_State* tolua_S)
{
  Controls* self = (Controls*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pitch_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pitch_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: extraData_ of class  Controls */
#ifndef TOLUA_DISABLE_tolua_get_Controls_extraData
static int tolua_get_Controls_extraData(lua_State* tolua_S)
{
  Controls* self = (Controls*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'extraData_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->extraData_,"VariantMap");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: extraData_ of class  Controls */
#ifndef TOLUA_DISABLE_tolua_set_Controls_extraData
static int tolua_set_Controls_extraData(lua_State* tolua_S)
{
  Controls* self = (Controls*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'extraData_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"VariantMap",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->extraData_ = *((VariantMap*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTouchedElement of class  TouchState */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_TouchState_GetTouchedElement00
static int tolua_InputLuaAPI_TouchState_GetTouchedElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TouchState",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TouchState* self = (TouchState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTouchedElement'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetTouchedElement();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTouchedElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: touchID_ of class  TouchState */
#ifndef TOLUA_DISABLE_tolua_get_TouchState_touchID
static int tolua_get_TouchState_touchID(lua_State* tolua_S)
{
  TouchState* self = (TouchState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'touchID_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->touchID_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: touchID_ of class  TouchState */
#ifndef TOLUA_DISABLE_tolua_set_TouchState_touchID
static int tolua_set_TouchState_touchID(lua_State* tolua_S)
{
  TouchState* self = (TouchState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'touchID_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->touchID_ = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: position_ of class  TouchState */
#ifndef TOLUA_DISABLE_tolua_get_TouchState_position
static int tolua_get_TouchState_position(lua_State* tolua_S)
{
  TouchState* self = (TouchState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->position_,"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: position_ of class  TouchState */
#ifndef TOLUA_DISABLE_tolua_set_TouchState_position
static int tolua_set_TouchState_position(lua_State* tolua_S)
{
  TouchState* self = (TouchState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->position_ = *((IntVector2*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: lastPosition_ of class  TouchState */
#ifndef TOLUA_DISABLE_tolua_get_TouchState_lastPosition
static int tolua_get_TouchState_lastPosition(lua_State* tolua_S)
{
  TouchState* self = (TouchState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lastPosition_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->lastPosition_,"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: lastPosition_ of class  TouchState */
#ifndef TOLUA_DISABLE_tolua_set_TouchState_lastPosition
static int tolua_set_TouchState_lastPosition(lua_State* tolua_S)
{
  TouchState* self = (TouchState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lastPosition_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->lastPosition_ = *((IntVector2*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: delta_ of class  TouchState */
#ifndef TOLUA_DISABLE_tolua_get_TouchState_delta
static int tolua_get_TouchState_delta(lua_State* tolua_S)
{
  TouchState* self = (TouchState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'delta_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->delta_,"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: delta_ of class  TouchState */
#ifndef TOLUA_DISABLE_tolua_set_TouchState_delta
static int tolua_set_TouchState_delta(lua_State* tolua_S)
{
  TouchState* self = (TouchState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'delta_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->delta_ = *((IntVector2*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pressure_ of class  TouchState */
#ifndef TOLUA_DISABLE_tolua_get_TouchState_pressure
static int tolua_get_TouchState_pressure(lua_State* tolua_S)
{
  TouchState* self = (TouchState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pressure_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->pressure_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pressure_ of class  TouchState */
#ifndef TOLUA_DISABLE_tolua_set_TouchState_pressure
static int tolua_set_TouchState_pressure(lua_State* tolua_S)
{
  TouchState* self = (TouchState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pressure_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pressure_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: touchedElement of class  TouchState */
#ifndef TOLUA_DISABLE_tolua_get_TouchState_touchedElement_ptr
static int tolua_get_TouchState_touchedElement_ptr(lua_State* tolua_S)
{
  TouchState* self = (TouchState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'touchedElement'",NULL);
#endif
  ToluaPushObject(tolua_S,(void*)self->GetTouchedElement(),"UIElement");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name_ of class  JoystickState */
#ifndef TOLUA_DISABLE_tolua_get_JoystickState_name
static int tolua_get_JoystickState_name(lua_State* tolua_S)
{
  JoystickState* self = (JoystickState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name_'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->name_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: joystickID_ of class  JoystickState */
#ifndef TOLUA_DISABLE_tolua_get_JoystickState_joystickID
static int tolua_get_JoystickState_joystickID(lua_State* tolua_S)
{
  JoystickState* self = (JoystickState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'joystickID_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->joystickID_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsController of class  JoystickState */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_JoystickState_IsController00
static int tolua_InputLuaAPI_JoystickState_IsController00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JoystickState",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JoystickState* self = (const JoystickState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsController'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsController();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsController'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumButtons of class  JoystickState */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_JoystickState_GetNumButtons00
static int tolua_InputLuaAPI_JoystickState_GetNumButtons00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JoystickState",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JoystickState* self = (const JoystickState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumButtons'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumButtons();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumButtons'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumAxes of class  JoystickState */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_JoystickState_GetNumAxes00
static int tolua_InputLuaAPI_JoystickState_GetNumAxes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JoystickState",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JoystickState* self = (const JoystickState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumAxes'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumAxes();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumAxes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumHats of class  JoystickState */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_JoystickState_GetNumHats00
static int tolua_InputLuaAPI_JoystickState_GetNumHats00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JoystickState",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JoystickState* self = (const JoystickState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumHats'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumHats();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumHats'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetButtonDown of class  JoystickState */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_JoystickState_GetButtonDown00
static int tolua_InputLuaAPI_JoystickState_GetButtonDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JoystickState",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JoystickState* self = (const JoystickState*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetButtonDown'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetButtonDown(index);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetButtonDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetButtonPress of class  JoystickState */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_JoystickState_GetButtonPress00
static int tolua_InputLuaAPI_JoystickState_GetButtonPress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JoystickState",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JoystickState* self = (const JoystickState*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetButtonPress'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetButtonPress(index);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetButtonPress'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAxisPosition of class  JoystickState */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_JoystickState_GetAxisPosition00
static int tolua_InputLuaAPI_JoystickState_GetAxisPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JoystickState",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JoystickState* self = (const JoystickState*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAxisPosition'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAxisPosition(index);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAxisPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHatPosition of class  JoystickState */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_JoystickState_GetHatPosition00
static int tolua_InputLuaAPI_JoystickState_GetHatPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JoystickState",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JoystickState* self = (const JoystickState*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHatPosition'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetHatPosition(index);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHatPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: controller of class  JoystickState */
#ifndef TOLUA_DISABLE_tolua_get_JoystickState_controller
static int tolua_get_JoystickState_controller(lua_State* tolua_S)
{
  JoystickState* self = (JoystickState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'controller'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsController());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numButtons of class  JoystickState */
#ifndef TOLUA_DISABLE_tolua_get_JoystickState_numButtons
static int tolua_get_JoystickState_numButtons(lua_State* tolua_S)
{
  JoystickState* self = (JoystickState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numButtons'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumButtons());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numAxes of class  JoystickState */
#ifndef TOLUA_DISABLE_tolua_get_JoystickState_numAxes
static int tolua_get_JoystickState_numAxes(lua_State* tolua_S)
{
  JoystickState* self = (JoystickState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numAxes'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumAxes());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numHats of class  JoystickState */
#ifndef TOLUA_DISABLE_tolua_get_JoystickState_numHats
static int tolua_get_JoystickState_numHats(lua_State* tolua_S)
{
  JoystickState* self = (JoystickState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numHats'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumHats());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetToggleFullscreen of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_SetToggleFullscreen00
static int tolua_InputLuaAPI_Input_SetToggleFullscreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetToggleFullscreen'", NULL);
#endif
 {
  self->SetToggleFullscreen(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetToggleFullscreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMouseVisible of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_SetMouseVisible00
static int tolua_InputLuaAPI_Input_SetMouseVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
  bool suppressEvent = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMouseVisible'", NULL);
#endif
 {
  self->SetMouseVisible(enable,suppressEvent);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMouseVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMouseGrabbed of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_SetMouseGrabbed00
static int tolua_InputLuaAPI_Input_SetMouseGrabbed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  bool grab = ((bool)  tolua_toboolean(tolua_S,2,0));
  bool suppressEvent = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMouseGrabbed'", NULL);
#endif
 {
  self->SetMouseGrabbed(grab,suppressEvent);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMouseGrabbed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMouseMode of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_SetMouseMode00
static int tolua_InputLuaAPI_Input_SetMouseMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  MouseMode mode = ((MouseMode) (int)  tolua_tonumber(tolua_S,2,0));
  bool suppressEvent = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMouseMode'", NULL);
#endif
 {
  self->SetMouseMode(mode,suppressEvent);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMouseMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsMouseLocked of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_IsMouseLocked00
static int tolua_InputLuaAPI_Input_IsMouseLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsMouseLocked'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsMouseLocked();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsMouseLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddScreenJoystick of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_AddScreenJoystick00
static int tolua_InputLuaAPI_Input_AddScreenJoystick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"XMLFile",1,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"XMLFile",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  XMLFile* layoutFile = ((XMLFile*)  tolua_tousertype(tolua_S,2,0));
  XMLFile* styleFile = ((XMLFile*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddScreenJoystick'", NULL);
#endif
 {
  int tolua_ret = (int)  self->AddScreenJoystick(layoutFile,styleFile);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddScreenJoystick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveScreenJoystick of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_RemoveScreenJoystick00
static int tolua_InputLuaAPI_Input_RemoveScreenJoystick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveScreenJoystick'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->RemoveScreenJoystick(id);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveScreenJoystick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScreenJoystickVisible of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_SetScreenJoystickVisible00
static int tolua_InputLuaAPI_Input_SetScreenJoystickVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
  bool enable = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScreenJoystickVisible'", NULL);
#endif
 {
  self->SetScreenJoystickVisible(id,enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScreenJoystickVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScreenKeyboardVisible of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_SetScreenKeyboardVisible00
static int tolua_InputLuaAPI_Input_SetScreenKeyboardVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScreenKeyboardVisible'", NULL);
#endif
 {
  self->SetScreenKeyboardVisible(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScreenKeyboardVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTouchEmulation of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_SetTouchEmulation00
static int tolua_InputLuaAPI_Input_SetTouchEmulation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTouchEmulation'", NULL);
#endif
 {
  self->SetTouchEmulation(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTouchEmulation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RecordGesture of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_RecordGesture00
static int tolua_InputLuaAPI_Input_RecordGesture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RecordGesture'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->RecordGesture();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RecordGesture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InputSaveGestures of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_SaveGestures00
static int tolua_InputLuaAPI_Input_SaveGestures00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  File* dest = ((File*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InputSaveGestures'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  InputSaveGestures(self,dest);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveGestures'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InputSaveGesture of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_SaveGesture00
static int tolua_InputLuaAPI_Input_SaveGesture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  File* dest = ((File*)  tolua_tousertype(tolua_S,2,0));
  unsigned gestureID = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InputSaveGesture'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  InputSaveGesture(self,dest,gestureID);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveGesture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InputLoadGestures of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_LoadGestures00
static int tolua_InputLuaAPI_Input_LoadGestures00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  File* source = ((File*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InputLoadGestures'", NULL);
#endif
 {
  tolua_outside unsigned tolua_ret = (tolua_outside unsigned)  InputLoadGestures(self,source);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadGestures'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InputSaveGestures of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_SaveGestures01
static int tolua_InputLuaAPI_Input_SaveGestures01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InputSaveGestures'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  InputSaveGestures(self,fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_InputLuaAPI_Input_SaveGestures00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: InputSaveGesture of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_SaveGesture01
static int tolua_InputLuaAPI_Input_SaveGesture01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  unsigned gestureID = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InputSaveGesture'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  InputSaveGesture(self,fileName,gestureID);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_InputLuaAPI_Input_SaveGesture00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: InputLoadGestures of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_LoadGestures01
static int tolua_InputLuaAPI_Input_LoadGestures01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InputLoadGestures'", NULL);
#endif
 {
  tolua_outside unsigned tolua_ret = (tolua_outside unsigned)  InputLoadGestures(self,fileName);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_InputLuaAPI_Input_LoadGestures00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveGesture of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_RemoveGesture00
static int tolua_InputLuaAPI_Input_RemoveGesture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  unsigned gestureID = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveGesture'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->RemoveGesture(gestureID);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveGesture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllGestures of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_RemoveAllGestures00
static int tolua_InputLuaAPI_Input_RemoveAllGestures00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllGestures'", NULL);
#endif
 {
  self->RemoveAllGestures();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllGestures'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMousePosition of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_SetMousePosition00
static int tolua_InputLuaAPI_Input_SetMousePosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* position = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMousePosition'", NULL);
#endif
 {
  self->SetMousePosition(*position);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMousePosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CenterMousePosition of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_CenterMousePosition00
static int tolua_InputLuaAPI_Input_CenterMousePosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CenterMousePosition'", NULL);
#endif
 {
  self->CenterMousePosition();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CenterMousePosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetKeyFromName of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetKeyFromName00
static int tolua_InputLuaAPI_Input_GetKeyFromName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetKeyFromName'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetKeyFromName(name);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetKeyFromName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetKeyFromScancode of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetKeyFromScancode00
static int tolua_InputLuaAPI_Input_GetKeyFromScancode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  int scancode = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetKeyFromScancode'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetKeyFromScancode(scancode);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetKeyFromScancode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetKeyName of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetKeyName00
static int tolua_InputLuaAPI_Input_GetKeyName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  int key = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetKeyName'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetKeyName(key);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetKeyName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScancodeFromKey of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetScancodeFromKey00
static int tolua_InputLuaAPI_Input_GetScancodeFromKey00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  int key = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScancodeFromKey'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetScancodeFromKey(key);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScancodeFromKey'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScancodeFromName of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetScancodeFromName00
static int tolua_InputLuaAPI_Input_GetScancodeFromName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScancodeFromName'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetScancodeFromName(name);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScancodeFromName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScancodeName of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetScancodeName00
static int tolua_InputLuaAPI_Input_GetScancodeName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  int scancode = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScancodeName'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetScancodeName(scancode);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScancodeName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetKeyDown of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetKeyDown00
static int tolua_InputLuaAPI_Input_GetKeyDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  int key = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetKeyDown'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetKeyDown(key);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetKeyDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetKeyPress of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetKeyPress00
static int tolua_InputLuaAPI_Input_GetKeyPress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  int key = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetKeyPress'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetKeyPress(key);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetKeyPress'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScancodeDown of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetScancodeDown00
static int tolua_InputLuaAPI_Input_GetScancodeDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  int scancode = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScancodeDown'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetScancodeDown(scancode);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScancodeDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScancodePress of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetScancodePress00
static int tolua_InputLuaAPI_Input_GetScancodePress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  int scancode = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScancodePress'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetScancodePress(scancode);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScancodePress'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMouseButtonDown of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetMouseButtonDown00
static int tolua_InputLuaAPI_Input_GetMouseButtonDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  int button = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMouseButtonDown'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetMouseButtonDown(button);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMouseButtonDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMouseButtonPress of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetMouseButtonPress00
static int tolua_InputLuaAPI_Input_GetMouseButtonPress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  int button = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMouseButtonPress'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetMouseButtonPress(button);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMouseButtonPress'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetQualifierDown of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetQualifierDown00
static int tolua_InputLuaAPI_Input_GetQualifierDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  int qualifier = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetQualifierDown'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetQualifierDown(qualifier);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetQualifierDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetQualifierPress of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetQualifierPress00
static int tolua_InputLuaAPI_Input_GetQualifierPress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  int qualifier = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetQualifierPress'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetQualifierPress(qualifier);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetQualifierPress'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetQualifiers of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetQualifiers00
static int tolua_InputLuaAPI_Input_GetQualifiers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetQualifiers'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetQualifiers();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetQualifiers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMousePosition of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetMousePosition00
static int tolua_InputLuaAPI_Input_GetMousePosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMousePosition'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->GetMousePosition();
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
 tolua_error(tolua_S,"#ferror in function 'GetMousePosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMouseMove of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetMouseMove00
static int tolua_InputLuaAPI_Input_GetMouseMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMouseMove'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->GetMouseMove();
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
 tolua_error(tolua_S,"#ferror in function 'GetMouseMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMouseMoveX of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetMouseMoveX00
static int tolua_InputLuaAPI_Input_GetMouseMoveX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMouseMoveX'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetMouseMoveX();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMouseMoveX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMouseMoveY of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetMouseMoveY00
static int tolua_InputLuaAPI_Input_GetMouseMoveY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMouseMoveY'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetMouseMoveY();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMouseMoveY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMouseMoveWheel of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetMouseMoveWheel00
static int tolua_InputLuaAPI_Input_GetMouseMoveWheel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMouseMoveWheel'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetMouseMoveWheel();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMouseMoveWheel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInputScale of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetInputScale00
static int tolua_InputLuaAPI_Input_GetInputScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInputScale'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->GetInputScale();
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
 tolua_error(tolua_S,"#ferror in function 'GetInputScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumTouches of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetNumTouches00
static int tolua_InputLuaAPI_Input_GetNumTouches00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumTouches'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumTouches();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumTouches'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTouch of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetTouch00
static int tolua_InputLuaAPI_Input_GetTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTouch'", NULL);
#endif
 {
  TouchState* tolua_ret = (TouchState*)  self->GetTouch(index);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"TouchState");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumJoysticks of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetNumJoysticks00
static int tolua_InputLuaAPI_Input_GetNumJoysticks00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumJoysticks'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumJoysticks();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumJoysticks'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetJoystick of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetJoystick00
static int tolua_InputLuaAPI_Input_GetJoystick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetJoystick'", NULL);
#endif
 {
  JoystickState* tolua_ret = (JoystickState*)  self->GetJoystick(id);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JoystickState");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetJoystick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetJoystickByIndex of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetJoystickByIndex00
static int tolua_InputLuaAPI_Input_GetJoystickByIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetJoystickByIndex'", NULL);
#endif
 {
  JoystickState* tolua_ret = (JoystickState*)  self->GetJoystickByIndex(index);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JoystickState");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetJoystickByIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetJoystickByName of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetJoystickByName00
static int tolua_InputLuaAPI_Input_GetJoystickByName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetJoystickByName'", NULL);
#endif
 {
  JoystickState* tolua_ret = (JoystickState*)  self->GetJoystickByName(name);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JoystickState");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetJoystickByName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetToggleFullscreen of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetToggleFullscreen00
static int tolua_InputLuaAPI_Input_GetToggleFullscreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetToggleFullscreen'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetToggleFullscreen();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetToggleFullscreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScreenKeyboardSupport of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetScreenKeyboardSupport00
static int tolua_InputLuaAPI_Input_GetScreenKeyboardSupport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScreenKeyboardSupport'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetScreenKeyboardSupport();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScreenKeyboardSupport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsScreenJoystickVisible of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_IsScreenJoystickVisible00
static int tolua_InputLuaAPI_Input_IsScreenJoystickVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsScreenJoystickVisible'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsScreenJoystickVisible(id);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsScreenJoystickVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsScreenKeyboardVisible of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_IsScreenKeyboardVisible00
static int tolua_InputLuaAPI_Input_IsScreenKeyboardVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsScreenKeyboardVisible'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsScreenKeyboardVisible();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsScreenKeyboardVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTouchEmulation of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetTouchEmulation00
static int tolua_InputLuaAPI_Input_GetTouchEmulation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTouchEmulation'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetTouchEmulation();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTouchEmulation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsMouseVisible of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_IsMouseVisible00
static int tolua_InputLuaAPI_Input_IsMouseVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsMouseVisible'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsMouseVisible();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsMouseVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsMouseGrabbed of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_IsMouseGrabbed00
static int tolua_InputLuaAPI_Input_IsMouseGrabbed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsMouseGrabbed'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsMouseGrabbed();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsMouseGrabbed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMouseMode of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_GetMouseMode00
static int tolua_InputLuaAPI_Input_GetMouseMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMouseMode'", NULL);
#endif
 {
  MouseMode tolua_ret = (MouseMode)  self->GetMouseMode();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMouseMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasFocus of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_HasFocus00
static int tolua_InputLuaAPI_Input_HasFocus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasFocus'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasFocus();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasFocus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsMinimized of class  Input */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_Input_IsMinimized00
static int tolua_InputLuaAPI_Input_IsMinimized00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Input* self = (const Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsMinimized'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsMinimized();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsMinimized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: qualifiers of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_qualifiers
static int tolua_get_Input_qualifiers(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'qualifiers'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetQualifiers());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mousePosition of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_mousePosition
static int tolua_get_Input_mousePosition(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mousePosition'",NULL);
#endif
 IntVector2 tolua_ret = (IntVector2)self->GetMousePosition();
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

/* set function: mousePosition of class  Input */
#ifndef TOLUA_DISABLE_tolua_set_Input_mousePosition
static int tolua_set_Input_mousePosition(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mousePosition'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMousePosition(*((IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mouseMove of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_mouseMove
static int tolua_get_Input_mouseMove(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mouseMove'",NULL);
#endif
 IntVector2 tolua_ret = (IntVector2)self->GetMouseMove();
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

/* get function: mouseMoveX of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_mouseMoveX
static int tolua_get_Input_mouseMoveX(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mouseMoveX'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMouseMoveX());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mouseMoveY of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_mouseMoveY
static int tolua_get_Input_mouseMoveY(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mouseMoveY'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMouseMoveY());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mouseMoveWheel of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_mouseMoveWheel
static int tolua_get_Input_mouseMoveWheel(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mouseMoveWheel'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMouseMoveWheel());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: inputScale of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_inputScale
static int tolua_get_Input_inputScale(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'inputScale'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->GetInputScale();
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

/* get function: numTouches of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_numTouches
static int tolua_get_Input_numTouches(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numTouches'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumTouches());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numJoysticks of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_numJoysticks
static int tolua_get_Input_numJoysticks(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numJoysticks'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumJoysticks());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: toggleFullscreen of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_toggleFullscreen
static int tolua_get_Input_toggleFullscreen(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'toggleFullscreen'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetToggleFullscreen());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: screenKeyboardSupport of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_screenKeyboardSupport
static int tolua_get_Input_screenKeyboardSupport(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'screenKeyboardSupport'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetScreenKeyboardSupport());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mouseMode of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_mouseMode
static int tolua_get_Input_mouseMode(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mouseMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMouseMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mouseMode of class  Input */
#ifndef TOLUA_DISABLE_tolua_set_Input_mouseMode
static int tolua_set_Input_mouseMode(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mouseMode'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMouseMode(((MouseMode) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: screenKeyboardVisible of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_screenKeyboardVisible
static int tolua_get_Input_screenKeyboardVisible(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'screenKeyboardVisible'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsScreenKeyboardVisible());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: screenKeyboardVisible of class  Input */
#ifndef TOLUA_DISABLE_tolua_set_Input_screenKeyboardVisible
static int tolua_set_Input_screenKeyboardVisible(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'screenKeyboardVisible'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetScreenKeyboardVisible(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: touchEmulation of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_touchEmulation
static int tolua_get_Input_touchEmulation(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'touchEmulation'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetTouchEmulation());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: touchEmulation of class  Input */
#ifndef TOLUA_DISABLE_tolua_set_Input_touchEmulation
static int tolua_set_Input_touchEmulation(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'touchEmulation'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTouchEmulation(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mouseVisible of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_mouseVisible
static int tolua_get_Input_mouseVisible(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mouseVisible'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsMouseVisible());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mouseVisible of class  Input */
#ifndef TOLUA_DISABLE_tolua_set_Input_mouseVisible
static int tolua_set_Input_mouseVisible(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mouseVisible'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMouseVisible(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mouseGrabbed of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_mouseGrabbed
static int tolua_get_Input_mouseGrabbed(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mouseGrabbed'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsMouseGrabbed());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mouseGrabbed of class  Input */
#ifndef TOLUA_DISABLE_tolua_set_Input_mouseGrabbed
static int tolua_set_Input_mouseGrabbed(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mouseGrabbed'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMouseGrabbed(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mouseLocked of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_mouseLocked
static int tolua_get_Input_mouseLocked(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mouseLocked'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsMouseLocked());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: focus of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_focus
static int tolua_get_Input_focus(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'focus'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->HasFocus());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: minimized of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_minimized
static int tolua_get_Input_minimized(lua_State* tolua_S)
{
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minimized'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsMinimized());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetInput */
#ifndef TOLUA_DISABLE_tolua_InputLuaAPI_GetInput00
static int tolua_InputLuaAPI_GetInput00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Input* tolua_ret = (Input*)  GetInput();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Input");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInput'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: input */
#ifndef TOLUA_DISABLE_tolua_get_input_ptr
static int tolua_get_input_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetInput(),"Input");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MOUSEB_LEFT */
#ifndef TOLUA_DISABLE_tolua_get_MOUSEB_LEFT
static int tolua_get_MOUSEB_LEFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)MOUSEB_LEFT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MOUSEB_MIDDLE */
#ifndef TOLUA_DISABLE_tolua_get_MOUSEB_MIDDLE
static int tolua_get_MOUSEB_MIDDLE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)MOUSEB_MIDDLE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MOUSEB_RIGHT */
#ifndef TOLUA_DISABLE_tolua_get_MOUSEB_RIGHT
static int tolua_get_MOUSEB_RIGHT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)MOUSEB_RIGHT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: QUAL_SHIFT */
#ifndef TOLUA_DISABLE_tolua_get_QUAL_SHIFT
static int tolua_get_QUAL_SHIFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)QUAL_SHIFT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: QUAL_CTRL */
#ifndef TOLUA_DISABLE_tolua_get_QUAL_CTRL
static int tolua_get_QUAL_CTRL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)QUAL_CTRL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: QUAL_ALT */
#ifndef TOLUA_DISABLE_tolua_get_QUAL_ALT
static int tolua_get_QUAL_ALT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)QUAL_ALT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: QUAL_ANY */
#ifndef TOLUA_DISABLE_tolua_get_QUAL_ANY
static int tolua_get_QUAL_ANY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)QUAL_ANY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_UNKNOWN */
#ifndef TOLUA_DISABLE_tolua_get_KEY_UNKNOWN
static int tolua_get_KEY_UNKNOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_UNKNOWN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_A */
#ifndef TOLUA_DISABLE_tolua_get_KEY_A
static int tolua_get_KEY_A(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_A);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_B */
#ifndef TOLUA_DISABLE_tolua_get_KEY_B
static int tolua_get_KEY_B(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_B);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_C */
#ifndef TOLUA_DISABLE_tolua_get_KEY_C
static int tolua_get_KEY_C(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_C);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_D */
#ifndef TOLUA_DISABLE_tolua_get_KEY_D
static int tolua_get_KEY_D(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_D);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_E */
#ifndef TOLUA_DISABLE_tolua_get_KEY_E
static int tolua_get_KEY_E(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_E);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F
static int tolua_get_KEY_F(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_G */
#ifndef TOLUA_DISABLE_tolua_get_KEY_G
static int tolua_get_KEY_G(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_G);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_H */
#ifndef TOLUA_DISABLE_tolua_get_KEY_H
static int tolua_get_KEY_H(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_H);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_I */
#ifndef TOLUA_DISABLE_tolua_get_KEY_I
static int tolua_get_KEY_I(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_I);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_J */
#ifndef TOLUA_DISABLE_tolua_get_KEY_J
static int tolua_get_KEY_J(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_J);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_K */
#ifndef TOLUA_DISABLE_tolua_get_KEY_K
static int tolua_get_KEY_K(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_K);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_L */
#ifndef TOLUA_DISABLE_tolua_get_KEY_L
static int tolua_get_KEY_L(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_L);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_M */
#ifndef TOLUA_DISABLE_tolua_get_KEY_M
static int tolua_get_KEY_M(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_M);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_N */
#ifndef TOLUA_DISABLE_tolua_get_KEY_N
static int tolua_get_KEY_N(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_N);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_O */
#ifndef TOLUA_DISABLE_tolua_get_KEY_O
static int tolua_get_KEY_O(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_O);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_P */
#ifndef TOLUA_DISABLE_tolua_get_KEY_P
static int tolua_get_KEY_P(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_P);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_Q */
#ifndef TOLUA_DISABLE_tolua_get_KEY_Q
static int tolua_get_KEY_Q(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_Q);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_R */
#ifndef TOLUA_DISABLE_tolua_get_KEY_R
static int tolua_get_KEY_R(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_R);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_S */
#ifndef TOLUA_DISABLE_tolua_get_KEY_S
static int tolua_get_KEY_S(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_S);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_T */
#ifndef TOLUA_DISABLE_tolua_get_KEY_T
static int tolua_get_KEY_T(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_T);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_U */
#ifndef TOLUA_DISABLE_tolua_get_KEY_U
static int tolua_get_KEY_U(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_U);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_V */
#ifndef TOLUA_DISABLE_tolua_get_KEY_V
static int tolua_get_KEY_V(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_V);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_W */
#ifndef TOLUA_DISABLE_tolua_get_KEY_W
static int tolua_get_KEY_W(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_W);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_X */
#ifndef TOLUA_DISABLE_tolua_get_KEY_X
static int tolua_get_KEY_X(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_X);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_Y */
#ifndef TOLUA_DISABLE_tolua_get_KEY_Y
static int tolua_get_KEY_Y(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_Y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_Z */
#ifndef TOLUA_DISABLE_tolua_get_KEY_Z
static int tolua_get_KEY_Z(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_Z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_0 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_0
static int tolua_get_KEY_0(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_1 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_1
static int tolua_get_KEY_1(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_2 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_2
static int tolua_get_KEY_2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_3 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_3
static int tolua_get_KEY_3(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_3);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_4 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_4
static int tolua_get_KEY_4(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_4);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_5 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_5
static int tolua_get_KEY_5(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_5);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_6 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_6
static int tolua_get_KEY_6(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_6);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_7 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_7
static int tolua_get_KEY_7(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_7);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_8 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_8
static int tolua_get_KEY_8(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_8);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_9 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_9
static int tolua_get_KEY_9(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_9);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_BACKSPACE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_BACKSPACE
static int tolua_get_KEY_BACKSPACE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_BACKSPACE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_TAB */
#ifndef TOLUA_DISABLE_tolua_get_KEY_TAB
static int tolua_get_KEY_TAB(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_TAB);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_RETURN */
#ifndef TOLUA_DISABLE_tolua_get_KEY_RETURN
static int tolua_get_KEY_RETURN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_RETURN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_RETURN2 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_RETURN2
static int tolua_get_KEY_RETURN2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_RETURN2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_ENTER */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_ENTER
static int tolua_get_KEY_KP_ENTER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_ENTER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_SHIFT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_SHIFT
static int tolua_get_KEY_SHIFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_SHIFT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_CTRL */
#ifndef TOLUA_DISABLE_tolua_get_KEY_CTRL
static int tolua_get_KEY_CTRL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_CTRL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_ALT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_ALT
static int tolua_get_KEY_ALT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_ALT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_GUI */
#ifndef TOLUA_DISABLE_tolua_get_KEY_GUI
static int tolua_get_KEY_GUI(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_GUI);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_PAUSE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_PAUSE
static int tolua_get_KEY_PAUSE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_PAUSE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_CAPSLOCK */
#ifndef TOLUA_DISABLE_tolua_get_KEY_CAPSLOCK
static int tolua_get_KEY_CAPSLOCK(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_CAPSLOCK);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_ESCAPE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_ESCAPE
static int tolua_get_KEY_ESCAPE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_ESCAPE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_SPACE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_SPACE
static int tolua_get_KEY_SPACE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_SPACE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_PAGEUP */
#ifndef TOLUA_DISABLE_tolua_get_KEY_PAGEUP
static int tolua_get_KEY_PAGEUP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_PAGEUP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_PAGEDOWN */
#ifndef TOLUA_DISABLE_tolua_get_KEY_PAGEDOWN
static int tolua_get_KEY_PAGEDOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_PAGEDOWN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_END */
#ifndef TOLUA_DISABLE_tolua_get_KEY_END
static int tolua_get_KEY_END(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_END);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_HOME */
#ifndef TOLUA_DISABLE_tolua_get_KEY_HOME
static int tolua_get_KEY_HOME(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_HOME);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_LEFT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_LEFT
static int tolua_get_KEY_LEFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_LEFT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_UP */
#ifndef TOLUA_DISABLE_tolua_get_KEY_UP
static int tolua_get_KEY_UP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_UP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_RIGHT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_RIGHT
static int tolua_get_KEY_RIGHT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_RIGHT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_DOWN */
#ifndef TOLUA_DISABLE_tolua_get_KEY_DOWN
static int tolua_get_KEY_DOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_DOWN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_SELECT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_SELECT
static int tolua_get_KEY_SELECT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_SELECT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_PRINTSCREEN */
#ifndef TOLUA_DISABLE_tolua_get_KEY_PRINTSCREEN
static int tolua_get_KEY_PRINTSCREEN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_PRINTSCREEN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_INSERT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_INSERT
static int tolua_get_KEY_INSERT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_INSERT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_DELETE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_DELETE
static int tolua_get_KEY_DELETE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_DELETE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_LGUI */
#ifndef TOLUA_DISABLE_tolua_get_KEY_LGUI
static int tolua_get_KEY_LGUI(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_LGUI);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_RGUI */
#ifndef TOLUA_DISABLE_tolua_get_KEY_RGUI
static int tolua_get_KEY_RGUI(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_RGUI);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_APPLICATION */
#ifndef TOLUA_DISABLE_tolua_get_KEY_APPLICATION
static int tolua_get_KEY_APPLICATION(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_APPLICATION);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_0 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_0
static int tolua_get_KEY_KP_0(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_1 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_1
static int tolua_get_KEY_KP_1(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_2 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_2
static int tolua_get_KEY_KP_2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_3 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_3
static int tolua_get_KEY_KP_3(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_3);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_4 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_4
static int tolua_get_KEY_KP_4(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_4);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_5 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_5
static int tolua_get_KEY_KP_5(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_5);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_6 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_6
static int tolua_get_KEY_KP_6(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_6);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_7 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_7
static int tolua_get_KEY_KP_7(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_7);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_8 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_8
static int tolua_get_KEY_KP_8(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_8);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_9 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_9
static int tolua_get_KEY_KP_9(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_9);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_MULTIPLY */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_MULTIPLY
static int tolua_get_KEY_KP_MULTIPLY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_MULTIPLY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_PLUS */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_PLUS
static int tolua_get_KEY_KP_PLUS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_PLUS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_MINUS */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_MINUS
static int tolua_get_KEY_KP_MINUS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_MINUS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_PERIOD */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_PERIOD
static int tolua_get_KEY_KP_PERIOD(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_PERIOD);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_DIVIDE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_DIVIDE
static int tolua_get_KEY_KP_DIVIDE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_DIVIDE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F1 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F1
static int tolua_get_KEY_F1(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F2 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F2
static int tolua_get_KEY_F2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F3 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F3
static int tolua_get_KEY_F3(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F3);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F4 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F4
static int tolua_get_KEY_F4(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F4);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F5 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F5
static int tolua_get_KEY_F5(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F5);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F6 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F6
static int tolua_get_KEY_F6(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F6);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F7 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F7
static int tolua_get_KEY_F7(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F7);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F8 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F8
static int tolua_get_KEY_F8(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F8);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F9 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F9
static int tolua_get_KEY_F9(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F9);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F10 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F10
static int tolua_get_KEY_F10(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F10);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F11 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F11
static int tolua_get_KEY_F11(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F11);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F12 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F12
static int tolua_get_KEY_F12(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F12);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F13 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F13
static int tolua_get_KEY_F13(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F13);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F14 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F14
static int tolua_get_KEY_F14(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F14);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F15 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F15
static int tolua_get_KEY_F15(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F15);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F16 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F16
static int tolua_get_KEY_F16(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F16);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F17 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F17
static int tolua_get_KEY_F17(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F17);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F18 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F18
static int tolua_get_KEY_F18(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F18);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F19 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F19
static int tolua_get_KEY_F19(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F19);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F20 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F20
static int tolua_get_KEY_F20(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F20);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F21 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F21
static int tolua_get_KEY_F21(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F21);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F22 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F22
static int tolua_get_KEY_F22(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F22);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F23 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F23
static int tolua_get_KEY_F23(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F23);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_F24 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_F24
static int tolua_get_KEY_F24(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_F24);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_NUMLOCKCLEAR */
#ifndef TOLUA_DISABLE_tolua_get_KEY_NUMLOCKCLEAR
static int tolua_get_KEY_NUMLOCKCLEAR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_NUMLOCKCLEAR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_SCROLLLOCK */
#ifndef TOLUA_DISABLE_tolua_get_KEY_SCROLLLOCK
static int tolua_get_KEY_SCROLLLOCK(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_SCROLLLOCK);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_LSHIFT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_LSHIFT
static int tolua_get_KEY_LSHIFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_LSHIFT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_RSHIFT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_RSHIFT
static int tolua_get_KEY_RSHIFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_RSHIFT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_LCTRL */
#ifndef TOLUA_DISABLE_tolua_get_KEY_LCTRL
static int tolua_get_KEY_LCTRL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_LCTRL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_RCTRL */
#ifndef TOLUA_DISABLE_tolua_get_KEY_RCTRL
static int tolua_get_KEY_RCTRL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_RCTRL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_LALT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_LALT
static int tolua_get_KEY_LALT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_LALT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_RALT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_RALT
static int tolua_get_KEY_RALT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_RALT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_AC_BACK */
#ifndef TOLUA_DISABLE_tolua_get_KEY_AC_BACK
static int tolua_get_KEY_AC_BACK(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_AC_BACK);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_AC_BOOKMARKS */
#ifndef TOLUA_DISABLE_tolua_get_KEY_AC_BOOKMARKS
static int tolua_get_KEY_AC_BOOKMARKS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_AC_BOOKMARKS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_AC_FORWARD */
#ifndef TOLUA_DISABLE_tolua_get_KEY_AC_FORWARD
static int tolua_get_KEY_AC_FORWARD(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_AC_FORWARD);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_AC_HOME */
#ifndef TOLUA_DISABLE_tolua_get_KEY_AC_HOME
static int tolua_get_KEY_AC_HOME(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_AC_HOME);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_AC_REFRESH */
#ifndef TOLUA_DISABLE_tolua_get_KEY_AC_REFRESH
static int tolua_get_KEY_AC_REFRESH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_AC_REFRESH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_AC_SEARCH */
#ifndef TOLUA_DISABLE_tolua_get_KEY_AC_SEARCH
static int tolua_get_KEY_AC_SEARCH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_AC_SEARCH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_AC_STOP */
#ifndef TOLUA_DISABLE_tolua_get_KEY_AC_STOP
static int tolua_get_KEY_AC_STOP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_AC_STOP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_AGAIN */
#ifndef TOLUA_DISABLE_tolua_get_KEY_AGAIN
static int tolua_get_KEY_AGAIN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_AGAIN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_ALTERASE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_ALTERASE
static int tolua_get_KEY_ALTERASE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_ALTERASE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_AMPERSAND */
#ifndef TOLUA_DISABLE_tolua_get_KEY_AMPERSAND
static int tolua_get_KEY_AMPERSAND(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_AMPERSAND);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_ASTERISK */
#ifndef TOLUA_DISABLE_tolua_get_KEY_ASTERISK
static int tolua_get_KEY_ASTERISK(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_ASTERISK);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_AT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_AT
static int tolua_get_KEY_AT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_AT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_AUDIOMUTE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_AUDIOMUTE
static int tolua_get_KEY_AUDIOMUTE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_AUDIOMUTE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_AUDIONEXT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_AUDIONEXT
static int tolua_get_KEY_AUDIONEXT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_AUDIONEXT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_AUDIOPLAY */
#ifndef TOLUA_DISABLE_tolua_get_KEY_AUDIOPLAY
static int tolua_get_KEY_AUDIOPLAY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_AUDIOPLAY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_AUDIOPREV */
#ifndef TOLUA_DISABLE_tolua_get_KEY_AUDIOPREV
static int tolua_get_KEY_AUDIOPREV(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_AUDIOPREV);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_AUDIOSTOP */
#ifndef TOLUA_DISABLE_tolua_get_KEY_AUDIOSTOP
static int tolua_get_KEY_AUDIOSTOP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_AUDIOSTOP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_BACKQUOTE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_BACKQUOTE
static int tolua_get_KEY_BACKQUOTE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_BACKQUOTE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_BACKSLASH */
#ifndef TOLUA_DISABLE_tolua_get_KEY_BACKSLASH
static int tolua_get_KEY_BACKSLASH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_BACKSLASH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_BRIGHTNESSDOWN */
#ifndef TOLUA_DISABLE_tolua_get_KEY_BRIGHTNESSDOWN
static int tolua_get_KEY_BRIGHTNESSDOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_BRIGHTNESSDOWN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_BRIGHTNESSUP */
#ifndef TOLUA_DISABLE_tolua_get_KEY_BRIGHTNESSUP
static int tolua_get_KEY_BRIGHTNESSUP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_BRIGHTNESSUP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_CALCULATOR */
#ifndef TOLUA_DISABLE_tolua_get_KEY_CALCULATOR
static int tolua_get_KEY_CALCULATOR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_CALCULATOR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_CANCEL */
#ifndef TOLUA_DISABLE_tolua_get_KEY_CANCEL
static int tolua_get_KEY_CANCEL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_CANCEL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_CARET */
#ifndef TOLUA_DISABLE_tolua_get_KEY_CARET
static int tolua_get_KEY_CARET(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_CARET);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_CLEAR */
#ifndef TOLUA_DISABLE_tolua_get_KEY_CLEAR
static int tolua_get_KEY_CLEAR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_CLEAR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_CLEARAGAIN */
#ifndef TOLUA_DISABLE_tolua_get_KEY_CLEARAGAIN
static int tolua_get_KEY_CLEARAGAIN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_CLEARAGAIN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_COLON */
#ifndef TOLUA_DISABLE_tolua_get_KEY_COLON
static int tolua_get_KEY_COLON(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_COLON);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_COMMA */
#ifndef TOLUA_DISABLE_tolua_get_KEY_COMMA
static int tolua_get_KEY_COMMA(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_COMMA);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_COMPUTER */
#ifndef TOLUA_DISABLE_tolua_get_KEY_COMPUTER
static int tolua_get_KEY_COMPUTER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_COMPUTER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_COPY */
#ifndef TOLUA_DISABLE_tolua_get_KEY_COPY
static int tolua_get_KEY_COPY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_COPY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_CRSEL */
#ifndef TOLUA_DISABLE_tolua_get_KEY_CRSEL
static int tolua_get_KEY_CRSEL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_CRSEL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_CURRENCYSUBUNIT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_CURRENCYSUBUNIT
static int tolua_get_KEY_CURRENCYSUBUNIT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_CURRENCYSUBUNIT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_CURRENCYUNIT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_CURRENCYUNIT
static int tolua_get_KEY_CURRENCYUNIT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_CURRENCYUNIT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_CUT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_CUT
static int tolua_get_KEY_CUT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_CUT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_DECIMALSEPARATOR */
#ifndef TOLUA_DISABLE_tolua_get_KEY_DECIMALSEPARATOR
static int tolua_get_KEY_DECIMALSEPARATOR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_DECIMALSEPARATOR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_DISPLAYSWITCH */
#ifndef TOLUA_DISABLE_tolua_get_KEY_DISPLAYSWITCH
static int tolua_get_KEY_DISPLAYSWITCH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_DISPLAYSWITCH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_DOLLAR */
#ifndef TOLUA_DISABLE_tolua_get_KEY_DOLLAR
static int tolua_get_KEY_DOLLAR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_DOLLAR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_EJECT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_EJECT
static int tolua_get_KEY_EJECT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_EJECT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_EQUALS */
#ifndef TOLUA_DISABLE_tolua_get_KEY_EQUALS
static int tolua_get_KEY_EQUALS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_EQUALS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_EXCLAIM */
#ifndef TOLUA_DISABLE_tolua_get_KEY_EXCLAIM
static int tolua_get_KEY_EXCLAIM(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_EXCLAIM);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_EXSEL */
#ifndef TOLUA_DISABLE_tolua_get_KEY_EXSEL
static int tolua_get_KEY_EXSEL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_EXSEL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_FIND */
#ifndef TOLUA_DISABLE_tolua_get_KEY_FIND
static int tolua_get_KEY_FIND(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_FIND);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_GREATER */
#ifndef TOLUA_DISABLE_tolua_get_KEY_GREATER
static int tolua_get_KEY_GREATER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_GREATER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_HASH */
#ifndef TOLUA_DISABLE_tolua_get_KEY_HASH
static int tolua_get_KEY_HASH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_HASH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_HELP */
#ifndef TOLUA_DISABLE_tolua_get_KEY_HELP
static int tolua_get_KEY_HELP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_HELP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KBDILLUMDOWN */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KBDILLUMDOWN
static int tolua_get_KEY_KBDILLUMDOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KBDILLUMDOWN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KBDILLUMTOGGLE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KBDILLUMTOGGLE
static int tolua_get_KEY_KBDILLUMTOGGLE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KBDILLUMTOGGLE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KBDILLUMUP */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KBDILLUMUP
static int tolua_get_KEY_KBDILLUMUP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KBDILLUMUP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_00 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_00
static int tolua_get_KEY_KP_00(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_00);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_000 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_000
static int tolua_get_KEY_KP_000(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_000);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_A */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_A
static int tolua_get_KEY_KP_A(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_A);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_AMPERSAND */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_AMPERSAND
static int tolua_get_KEY_KP_AMPERSAND(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_AMPERSAND);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_AT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_AT
static int tolua_get_KEY_KP_AT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_AT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_B */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_B
static int tolua_get_KEY_KP_B(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_B);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_BACKSPACE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_BACKSPACE
static int tolua_get_KEY_KP_BACKSPACE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_BACKSPACE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_BINARY */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_BINARY
static int tolua_get_KEY_KP_BINARY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_BINARY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_C */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_C
static int tolua_get_KEY_KP_C(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_C);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_CLEAR */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_CLEAR
static int tolua_get_KEY_KP_CLEAR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_CLEAR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_CLEARENTRY */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_CLEARENTRY
static int tolua_get_KEY_KP_CLEARENTRY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_CLEARENTRY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_COLON */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_COLON
static int tolua_get_KEY_KP_COLON(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_COLON);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_COMMA */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_COMMA
static int tolua_get_KEY_KP_COMMA(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_COMMA);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_D */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_D
static int tolua_get_KEY_KP_D(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_D);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_DBLAMPERSAND */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_DBLAMPERSAND
static int tolua_get_KEY_KP_DBLAMPERSAND(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_DBLAMPERSAND);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_DBLVERTICALBAR */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_DBLVERTICALBAR
static int tolua_get_KEY_KP_DBLVERTICALBAR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_DBLVERTICALBAR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_DECIMAL */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_DECIMAL
static int tolua_get_KEY_KP_DECIMAL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_DECIMAL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_E */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_E
static int tolua_get_KEY_KP_E(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_E);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_EQUALS */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_EQUALS
static int tolua_get_KEY_KP_EQUALS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_EQUALS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_EQUALSAS400 */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_EQUALSAS400
static int tolua_get_KEY_KP_EQUALSAS400(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_EQUALSAS400);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_EXCLAM */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_EXCLAM
static int tolua_get_KEY_KP_EXCLAM(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_EXCLAM);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_F */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_F
static int tolua_get_KEY_KP_F(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_F);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_GREATER */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_GREATER
static int tolua_get_KEY_KP_GREATER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_GREATER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_HASH */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_HASH
static int tolua_get_KEY_KP_HASH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_HASH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_HEXADECIMAL */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_HEXADECIMAL
static int tolua_get_KEY_KP_HEXADECIMAL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_HEXADECIMAL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_LEFTBRACE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_LEFTBRACE
static int tolua_get_KEY_KP_LEFTBRACE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_LEFTBRACE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_LEFTPAREN */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_LEFTPAREN
static int tolua_get_KEY_KP_LEFTPAREN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_LEFTPAREN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_LESS */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_LESS
static int tolua_get_KEY_KP_LESS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_LESS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_MEMADD */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_MEMADD
static int tolua_get_KEY_KP_MEMADD(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_MEMADD);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_MEMCLEAR */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_MEMCLEAR
static int tolua_get_KEY_KP_MEMCLEAR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_MEMCLEAR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_MEMDIVIDE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_MEMDIVIDE
static int tolua_get_KEY_KP_MEMDIVIDE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_MEMDIVIDE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_MEMMULTIPLY */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_MEMMULTIPLY
static int tolua_get_KEY_KP_MEMMULTIPLY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_MEMMULTIPLY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_MEMRECALL */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_MEMRECALL
static int tolua_get_KEY_KP_MEMRECALL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_MEMRECALL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_MEMSTORE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_MEMSTORE
static int tolua_get_KEY_KP_MEMSTORE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_MEMSTORE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_MEMSUBTRACT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_MEMSUBTRACT
static int tolua_get_KEY_KP_MEMSUBTRACT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_MEMSUBTRACT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_OCTAL */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_OCTAL
static int tolua_get_KEY_KP_OCTAL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_OCTAL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_PERCENT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_PERCENT
static int tolua_get_KEY_KP_PERCENT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_PERCENT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_PLUSMINUS */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_PLUSMINUS
static int tolua_get_KEY_KP_PLUSMINUS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_PLUSMINUS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_POWER */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_POWER
static int tolua_get_KEY_KP_POWER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_POWER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_RIGHTBRACE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_RIGHTBRACE
static int tolua_get_KEY_KP_RIGHTBRACE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_RIGHTBRACE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_RIGHTPAREN */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_RIGHTPAREN
static int tolua_get_KEY_KP_RIGHTPAREN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_RIGHTPAREN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_SPACE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_SPACE
static int tolua_get_KEY_KP_SPACE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_SPACE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_TAB */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_TAB
static int tolua_get_KEY_KP_TAB(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_TAB);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_VERTICALBAR */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_VERTICALBAR
static int tolua_get_KEY_KP_VERTICALBAR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_VERTICALBAR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_KP_XOR */
#ifndef TOLUA_DISABLE_tolua_get_KEY_KP_XOR
static int tolua_get_KEY_KP_XOR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_KP_XOR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_LEFTBRACKET */
#ifndef TOLUA_DISABLE_tolua_get_KEY_LEFTBRACKET
static int tolua_get_KEY_LEFTBRACKET(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_LEFTBRACKET);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_LEFTPAREN */
#ifndef TOLUA_DISABLE_tolua_get_KEY_LEFTPAREN
static int tolua_get_KEY_LEFTPAREN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_LEFTPAREN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_LESS */
#ifndef TOLUA_DISABLE_tolua_get_KEY_LESS
static int tolua_get_KEY_LESS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_LESS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_MAIL */
#ifndef TOLUA_DISABLE_tolua_get_KEY_MAIL
static int tolua_get_KEY_MAIL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_MAIL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_MEDIASELECT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_MEDIASELECT
static int tolua_get_KEY_MEDIASELECT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_MEDIASELECT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_MENU */
#ifndef TOLUA_DISABLE_tolua_get_KEY_MENU
static int tolua_get_KEY_MENU(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_MENU);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_MINUS */
#ifndef TOLUA_DISABLE_tolua_get_KEY_MINUS
static int tolua_get_KEY_MINUS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_MINUS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_MODE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_MODE
static int tolua_get_KEY_MODE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_MODE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_MUTE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_MUTE
static int tolua_get_KEY_MUTE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_MUTE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_OPER */
#ifndef TOLUA_DISABLE_tolua_get_KEY_OPER
static int tolua_get_KEY_OPER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_OPER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_OUT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_OUT
static int tolua_get_KEY_OUT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_OUT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_PASTE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_PASTE
static int tolua_get_KEY_PASTE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_PASTE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_PERCENT */
#ifndef TOLUA_DISABLE_tolua_get_KEY_PERCENT
static int tolua_get_KEY_PERCENT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_PERCENT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_PERIOD */
#ifndef TOLUA_DISABLE_tolua_get_KEY_PERIOD
static int tolua_get_KEY_PERIOD(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_PERIOD);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_PLUS */
#ifndef TOLUA_DISABLE_tolua_get_KEY_PLUS
static int tolua_get_KEY_PLUS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_PLUS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_POWER */
#ifndef TOLUA_DISABLE_tolua_get_KEY_POWER
static int tolua_get_KEY_POWER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_POWER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_PRIOR */
#ifndef TOLUA_DISABLE_tolua_get_KEY_PRIOR
static int tolua_get_KEY_PRIOR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_PRIOR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_QUESTION */
#ifndef TOLUA_DISABLE_tolua_get_KEY_QUESTION
static int tolua_get_KEY_QUESTION(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_QUESTION);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_QUOTE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_QUOTE
static int tolua_get_KEY_QUOTE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_QUOTE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_QUOTEDBL */
#ifndef TOLUA_DISABLE_tolua_get_KEY_QUOTEDBL
static int tolua_get_KEY_QUOTEDBL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_QUOTEDBL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_RIGHTBRACKET */
#ifndef TOLUA_DISABLE_tolua_get_KEY_RIGHTBRACKET
static int tolua_get_KEY_RIGHTBRACKET(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_RIGHTBRACKET);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_RIGHTPAREN */
#ifndef TOLUA_DISABLE_tolua_get_KEY_RIGHTPAREN
static int tolua_get_KEY_RIGHTPAREN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_RIGHTPAREN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_SEMICOLON */
#ifndef TOLUA_DISABLE_tolua_get_KEY_SEMICOLON
static int tolua_get_KEY_SEMICOLON(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_SEMICOLON);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_SEPARATOR */
#ifndef TOLUA_DISABLE_tolua_get_KEY_SEPARATOR
static int tolua_get_KEY_SEPARATOR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_SEPARATOR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_SLASH */
#ifndef TOLUA_DISABLE_tolua_get_KEY_SLASH
static int tolua_get_KEY_SLASH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_SLASH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_SLEEP */
#ifndef TOLUA_DISABLE_tolua_get_KEY_SLEEP
static int tolua_get_KEY_SLEEP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_SLEEP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_STOP */
#ifndef TOLUA_DISABLE_tolua_get_KEY_STOP
static int tolua_get_KEY_STOP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_STOP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_SYSREQ */
#ifndef TOLUA_DISABLE_tolua_get_KEY_SYSREQ
static int tolua_get_KEY_SYSREQ(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_SYSREQ);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_THOUSANDSSEPARATOR */
#ifndef TOLUA_DISABLE_tolua_get_KEY_THOUSANDSSEPARATOR
static int tolua_get_KEY_THOUSANDSSEPARATOR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_THOUSANDSSEPARATOR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_UNDERSCORE */
#ifndef TOLUA_DISABLE_tolua_get_KEY_UNDERSCORE
static int tolua_get_KEY_UNDERSCORE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_UNDERSCORE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_UNDO */
#ifndef TOLUA_DISABLE_tolua_get_KEY_UNDO
static int tolua_get_KEY_UNDO(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_UNDO);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_VOLUMEDOWN */
#ifndef TOLUA_DISABLE_tolua_get_KEY_VOLUMEDOWN
static int tolua_get_KEY_VOLUMEDOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_VOLUMEDOWN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_VOLUMEUP */
#ifndef TOLUA_DISABLE_tolua_get_KEY_VOLUMEUP
static int tolua_get_KEY_VOLUMEUP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_VOLUMEUP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: KEY_WWW */
#ifndef TOLUA_DISABLE_tolua_get_KEY_WWW
static int tolua_get_KEY_WWW(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)KEY_WWW);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_UNKNOWN */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_UNKNOWN
static int tolua_get_SCANCODE_UNKNOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_UNKNOWN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_CTRL */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_CTRL
static int tolua_get_SCANCODE_CTRL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_CTRL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_SHIFT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_SHIFT
static int tolua_get_SCANCODE_SHIFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_SHIFT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_ALT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_ALT
static int tolua_get_SCANCODE_ALT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_ALT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_GUI */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_GUI
static int tolua_get_SCANCODE_GUI(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_GUI);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_A */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_A
static int tolua_get_SCANCODE_A(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_A);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_B */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_B
static int tolua_get_SCANCODE_B(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_B);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_C */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_C
static int tolua_get_SCANCODE_C(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_C);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_D */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_D
static int tolua_get_SCANCODE_D(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_D);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_E */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_E
static int tolua_get_SCANCODE_E(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_E);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F
static int tolua_get_SCANCODE_F(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_G */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_G
static int tolua_get_SCANCODE_G(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_G);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_H */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_H
static int tolua_get_SCANCODE_H(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_H);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_I */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_I
static int tolua_get_SCANCODE_I(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_I);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_J */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_J
static int tolua_get_SCANCODE_J(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_J);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_K */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_K
static int tolua_get_SCANCODE_K(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_K);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_L */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_L
static int tolua_get_SCANCODE_L(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_L);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_M */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_M
static int tolua_get_SCANCODE_M(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_M);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_N */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_N
static int tolua_get_SCANCODE_N(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_N);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_O */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_O
static int tolua_get_SCANCODE_O(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_O);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_P */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_P
static int tolua_get_SCANCODE_P(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_P);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_Q */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_Q
static int tolua_get_SCANCODE_Q(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_Q);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_R */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_R
static int tolua_get_SCANCODE_R(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_R);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_S */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_S
static int tolua_get_SCANCODE_S(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_S);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_T */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_T
static int tolua_get_SCANCODE_T(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_T);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_U */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_U
static int tolua_get_SCANCODE_U(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_U);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_V */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_V
static int tolua_get_SCANCODE_V(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_V);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_W */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_W
static int tolua_get_SCANCODE_W(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_W);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_X */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_X
static int tolua_get_SCANCODE_X(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_X);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_Y */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_Y
static int tolua_get_SCANCODE_Y(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_Y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_Z */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_Z
static int tolua_get_SCANCODE_Z(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_Z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_1 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_1
static int tolua_get_SCANCODE_1(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_2 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_2
static int tolua_get_SCANCODE_2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_3 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_3
static int tolua_get_SCANCODE_3(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_3);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_4 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_4
static int tolua_get_SCANCODE_4(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_4);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_5 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_5
static int tolua_get_SCANCODE_5(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_5);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_6 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_6
static int tolua_get_SCANCODE_6(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_6);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_7 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_7
static int tolua_get_SCANCODE_7(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_7);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_8 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_8
static int tolua_get_SCANCODE_8(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_8);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_9 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_9
static int tolua_get_SCANCODE_9(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_9);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_0 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_0
static int tolua_get_SCANCODE_0(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_RETURN */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_RETURN
static int tolua_get_SCANCODE_RETURN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_RETURN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_ESCAPE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_ESCAPE
static int tolua_get_SCANCODE_ESCAPE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_ESCAPE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_BACKSPACE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_BACKSPACE
static int tolua_get_SCANCODE_BACKSPACE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_BACKSPACE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_TAB */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_TAB
static int tolua_get_SCANCODE_TAB(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_TAB);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_SPACE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_SPACE
static int tolua_get_SCANCODE_SPACE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_SPACE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_MINUS */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_MINUS
static int tolua_get_SCANCODE_MINUS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_MINUS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_EQUALS */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_EQUALS
static int tolua_get_SCANCODE_EQUALS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_EQUALS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_LEFTBRACKET */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_LEFTBRACKET
static int tolua_get_SCANCODE_LEFTBRACKET(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_LEFTBRACKET);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_RIGHTBRACKET */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_RIGHTBRACKET
static int tolua_get_SCANCODE_RIGHTBRACKET(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_RIGHTBRACKET);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_BACKSLASH */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_BACKSLASH
static int tolua_get_SCANCODE_BACKSLASH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_BACKSLASH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_NONUSHASH */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_NONUSHASH
static int tolua_get_SCANCODE_NONUSHASH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_NONUSHASH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_SEMICOLON */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_SEMICOLON
static int tolua_get_SCANCODE_SEMICOLON(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_SEMICOLON);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_APOSTROPHE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_APOSTROPHE
static int tolua_get_SCANCODE_APOSTROPHE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_APOSTROPHE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_GRAVE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_GRAVE
static int tolua_get_SCANCODE_GRAVE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_GRAVE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_COMMA */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_COMMA
static int tolua_get_SCANCODE_COMMA(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_COMMA);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_PERIOD */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_PERIOD
static int tolua_get_SCANCODE_PERIOD(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_PERIOD);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_SLASH */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_SLASH
static int tolua_get_SCANCODE_SLASH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_SLASH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_CAPSLOCK */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_CAPSLOCK
static int tolua_get_SCANCODE_CAPSLOCK(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_CAPSLOCK);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F1 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F1
static int tolua_get_SCANCODE_F1(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F2 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F2
static int tolua_get_SCANCODE_F2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F3 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F3
static int tolua_get_SCANCODE_F3(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F3);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F4 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F4
static int tolua_get_SCANCODE_F4(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F4);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F5 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F5
static int tolua_get_SCANCODE_F5(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F5);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F6 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F6
static int tolua_get_SCANCODE_F6(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F6);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F7 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F7
static int tolua_get_SCANCODE_F7(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F7);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F8 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F8
static int tolua_get_SCANCODE_F8(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F8);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F9 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F9
static int tolua_get_SCANCODE_F9(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F9);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F10 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F10
static int tolua_get_SCANCODE_F10(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F10);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F11 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F11
static int tolua_get_SCANCODE_F11(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F11);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F12 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F12
static int tolua_get_SCANCODE_F12(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F12);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_PRINTSCREEN */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_PRINTSCREEN
static int tolua_get_SCANCODE_PRINTSCREEN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_PRINTSCREEN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_SCROLLLOCK */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_SCROLLLOCK
static int tolua_get_SCANCODE_SCROLLLOCK(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_SCROLLLOCK);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_PAUSE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_PAUSE
static int tolua_get_SCANCODE_PAUSE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_PAUSE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_INSERT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_INSERT
static int tolua_get_SCANCODE_INSERT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_INSERT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_HOME */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_HOME
static int tolua_get_SCANCODE_HOME(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_HOME);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_PAGEUP */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_PAGEUP
static int tolua_get_SCANCODE_PAGEUP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_PAGEUP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_DELETE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_DELETE
static int tolua_get_SCANCODE_DELETE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_DELETE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_END */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_END
static int tolua_get_SCANCODE_END(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_END);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_PAGEDOWN */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_PAGEDOWN
static int tolua_get_SCANCODE_PAGEDOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_PAGEDOWN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_RIGHT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_RIGHT
static int tolua_get_SCANCODE_RIGHT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_RIGHT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_LEFT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_LEFT
static int tolua_get_SCANCODE_LEFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_LEFT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_DOWN */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_DOWN
static int tolua_get_SCANCODE_DOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_DOWN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_UP */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_UP
static int tolua_get_SCANCODE_UP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_UP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_NUMLOCKCLEAR */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_NUMLOCKCLEAR
static int tolua_get_SCANCODE_NUMLOCKCLEAR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_NUMLOCKCLEAR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_DIVIDE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_DIVIDE
static int tolua_get_SCANCODE_KP_DIVIDE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_DIVIDE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_MULTIPLY */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_MULTIPLY
static int tolua_get_SCANCODE_KP_MULTIPLY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_MULTIPLY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_MINUS */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_MINUS
static int tolua_get_SCANCODE_KP_MINUS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_MINUS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_PLUS */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_PLUS
static int tolua_get_SCANCODE_KP_PLUS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_PLUS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_ENTER */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_ENTER
static int tolua_get_SCANCODE_KP_ENTER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_ENTER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_1 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_1
static int tolua_get_SCANCODE_KP_1(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_2 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_2
static int tolua_get_SCANCODE_KP_2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_3 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_3
static int tolua_get_SCANCODE_KP_3(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_3);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_4 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_4
static int tolua_get_SCANCODE_KP_4(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_4);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_5 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_5
static int tolua_get_SCANCODE_KP_5(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_5);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_6 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_6
static int tolua_get_SCANCODE_KP_6(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_6);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_7 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_7
static int tolua_get_SCANCODE_KP_7(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_7);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_8 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_8
static int tolua_get_SCANCODE_KP_8(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_8);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_9 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_9
static int tolua_get_SCANCODE_KP_9(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_9);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_0 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_0
static int tolua_get_SCANCODE_KP_0(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_PERIOD */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_PERIOD
static int tolua_get_SCANCODE_KP_PERIOD(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_PERIOD);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_NONUSBACKSLASH */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_NONUSBACKSLASH
static int tolua_get_SCANCODE_NONUSBACKSLASH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_NONUSBACKSLASH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_APPLICATION */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_APPLICATION
static int tolua_get_SCANCODE_APPLICATION(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_APPLICATION);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_POWER */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_POWER
static int tolua_get_SCANCODE_POWER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_POWER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_EQUALS */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_EQUALS
static int tolua_get_SCANCODE_KP_EQUALS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_EQUALS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F13 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F13
static int tolua_get_SCANCODE_F13(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F13);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F14 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F14
static int tolua_get_SCANCODE_F14(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F14);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F15 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F15
static int tolua_get_SCANCODE_F15(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F15);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F16 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F16
static int tolua_get_SCANCODE_F16(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F16);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F17 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F17
static int tolua_get_SCANCODE_F17(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F17);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F18 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F18
static int tolua_get_SCANCODE_F18(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F18);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F19 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F19
static int tolua_get_SCANCODE_F19(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F19);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F20 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F20
static int tolua_get_SCANCODE_F20(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F20);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F21 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F21
static int tolua_get_SCANCODE_F21(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F21);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F22 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F22
static int tolua_get_SCANCODE_F22(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F22);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F23 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F23
static int tolua_get_SCANCODE_F23(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F23);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_F24 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_F24
static int tolua_get_SCANCODE_F24(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_F24);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_EXECUTE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_EXECUTE
static int tolua_get_SCANCODE_EXECUTE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_EXECUTE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_HELP */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_HELP
static int tolua_get_SCANCODE_HELP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_HELP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_MENU */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_MENU
static int tolua_get_SCANCODE_MENU(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_MENU);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_SELECT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_SELECT
static int tolua_get_SCANCODE_SELECT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_SELECT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_STOP */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_STOP
static int tolua_get_SCANCODE_STOP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_STOP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_AGAIN */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_AGAIN
static int tolua_get_SCANCODE_AGAIN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_AGAIN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_UNDO */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_UNDO
static int tolua_get_SCANCODE_UNDO(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_UNDO);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_CUT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_CUT
static int tolua_get_SCANCODE_CUT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_CUT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_COPY */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_COPY
static int tolua_get_SCANCODE_COPY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_COPY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_PASTE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_PASTE
static int tolua_get_SCANCODE_PASTE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_PASTE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_FIND */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_FIND
static int tolua_get_SCANCODE_FIND(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_FIND);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_MUTE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_MUTE
static int tolua_get_SCANCODE_MUTE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_MUTE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_VOLUMEUP */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_VOLUMEUP
static int tolua_get_SCANCODE_VOLUMEUP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_VOLUMEUP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_VOLUMEDOWN */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_VOLUMEDOWN
static int tolua_get_SCANCODE_VOLUMEDOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_VOLUMEDOWN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_COMMA */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_COMMA
static int tolua_get_SCANCODE_KP_COMMA(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_COMMA);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_EQUALSAS400 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_EQUALSAS400
static int tolua_get_SCANCODE_KP_EQUALSAS400(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_EQUALSAS400);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_INTERNATIONAL1 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_INTERNATIONAL1
static int tolua_get_SCANCODE_INTERNATIONAL1(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_INTERNATIONAL1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_INTERNATIONAL2 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_INTERNATIONAL2
static int tolua_get_SCANCODE_INTERNATIONAL2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_INTERNATIONAL2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_INTERNATIONAL3 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_INTERNATIONAL3
static int tolua_get_SCANCODE_INTERNATIONAL3(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_INTERNATIONAL3);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_INTERNATIONAL4 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_INTERNATIONAL4
static int tolua_get_SCANCODE_INTERNATIONAL4(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_INTERNATIONAL4);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_INTERNATIONAL5 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_INTERNATIONAL5
static int tolua_get_SCANCODE_INTERNATIONAL5(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_INTERNATIONAL5);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_INTERNATIONAL6 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_INTERNATIONAL6
static int tolua_get_SCANCODE_INTERNATIONAL6(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_INTERNATIONAL6);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_INTERNATIONAL7 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_INTERNATIONAL7
static int tolua_get_SCANCODE_INTERNATIONAL7(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_INTERNATIONAL7);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_INTERNATIONAL8 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_INTERNATIONAL8
static int tolua_get_SCANCODE_INTERNATIONAL8(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_INTERNATIONAL8);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_INTERNATIONAL9 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_INTERNATIONAL9
static int tolua_get_SCANCODE_INTERNATIONAL9(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_INTERNATIONAL9);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_LANG1 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_LANG1
static int tolua_get_SCANCODE_LANG1(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_LANG1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_LANG2 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_LANG2
static int tolua_get_SCANCODE_LANG2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_LANG2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_LANG3 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_LANG3
static int tolua_get_SCANCODE_LANG3(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_LANG3);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_LANG4 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_LANG4
static int tolua_get_SCANCODE_LANG4(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_LANG4);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_LANG5 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_LANG5
static int tolua_get_SCANCODE_LANG5(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_LANG5);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_LANG6 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_LANG6
static int tolua_get_SCANCODE_LANG6(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_LANG6);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_LANG7 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_LANG7
static int tolua_get_SCANCODE_LANG7(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_LANG7);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_LANG8 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_LANG8
static int tolua_get_SCANCODE_LANG8(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_LANG8);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_LANG9 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_LANG9
static int tolua_get_SCANCODE_LANG9(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_LANG9);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_ALTERASE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_ALTERASE
static int tolua_get_SCANCODE_ALTERASE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_ALTERASE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_SYSREQ */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_SYSREQ
static int tolua_get_SCANCODE_SYSREQ(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_SYSREQ);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_CANCEL */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_CANCEL
static int tolua_get_SCANCODE_CANCEL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_CANCEL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_CLEAR */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_CLEAR
static int tolua_get_SCANCODE_CLEAR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_CLEAR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_PRIOR */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_PRIOR
static int tolua_get_SCANCODE_PRIOR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_PRIOR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_RETURN2 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_RETURN2
static int tolua_get_SCANCODE_RETURN2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_RETURN2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_SEPARATOR */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_SEPARATOR
static int tolua_get_SCANCODE_SEPARATOR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_SEPARATOR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_OUT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_OUT
static int tolua_get_SCANCODE_OUT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_OUT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_OPER */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_OPER
static int tolua_get_SCANCODE_OPER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_OPER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_CLEARAGAIN */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_CLEARAGAIN
static int tolua_get_SCANCODE_CLEARAGAIN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_CLEARAGAIN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_CRSEL */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_CRSEL
static int tolua_get_SCANCODE_CRSEL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_CRSEL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_EXSEL */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_EXSEL
static int tolua_get_SCANCODE_EXSEL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_EXSEL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_00 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_00
static int tolua_get_SCANCODE_KP_00(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_00);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_000 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_000
static int tolua_get_SCANCODE_KP_000(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_000);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_THOUSANDSSEPARATOR */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_THOUSANDSSEPARATOR
static int tolua_get_SCANCODE_THOUSANDSSEPARATOR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_THOUSANDSSEPARATOR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_DECIMALSEPARATOR */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_DECIMALSEPARATOR
static int tolua_get_SCANCODE_DECIMALSEPARATOR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_DECIMALSEPARATOR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_CURRENCYUNIT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_CURRENCYUNIT
static int tolua_get_SCANCODE_CURRENCYUNIT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_CURRENCYUNIT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_CURRENCYSUBUNIT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_CURRENCYSUBUNIT
static int tolua_get_SCANCODE_CURRENCYSUBUNIT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_CURRENCYSUBUNIT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_LEFTPAREN */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_LEFTPAREN
static int tolua_get_SCANCODE_KP_LEFTPAREN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_LEFTPAREN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_RIGHTPAREN */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_RIGHTPAREN
static int tolua_get_SCANCODE_KP_RIGHTPAREN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_RIGHTPAREN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_LEFTBRACE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_LEFTBRACE
static int tolua_get_SCANCODE_KP_LEFTBRACE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_LEFTBRACE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_RIGHTBRACE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_RIGHTBRACE
static int tolua_get_SCANCODE_KP_RIGHTBRACE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_RIGHTBRACE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_TAB */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_TAB
static int tolua_get_SCANCODE_KP_TAB(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_TAB);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_BACKSPACE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_BACKSPACE
static int tolua_get_SCANCODE_KP_BACKSPACE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_BACKSPACE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_A */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_A
static int tolua_get_SCANCODE_KP_A(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_A);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_B */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_B
static int tolua_get_SCANCODE_KP_B(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_B);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_C */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_C
static int tolua_get_SCANCODE_KP_C(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_C);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_D */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_D
static int tolua_get_SCANCODE_KP_D(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_D);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_E */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_E
static int tolua_get_SCANCODE_KP_E(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_E);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_F */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_F
static int tolua_get_SCANCODE_KP_F(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_F);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_XOR */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_XOR
static int tolua_get_SCANCODE_KP_XOR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_XOR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_POWER */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_POWER
static int tolua_get_SCANCODE_KP_POWER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_POWER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_PERCENT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_PERCENT
static int tolua_get_SCANCODE_KP_PERCENT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_PERCENT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_LESS */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_LESS
static int tolua_get_SCANCODE_KP_LESS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_LESS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_GREATER */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_GREATER
static int tolua_get_SCANCODE_KP_GREATER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_GREATER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_AMPERSAND */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_AMPERSAND
static int tolua_get_SCANCODE_KP_AMPERSAND(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_AMPERSAND);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_DBLAMPERSAND */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_DBLAMPERSAND
static int tolua_get_SCANCODE_KP_DBLAMPERSAND(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_DBLAMPERSAND);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_VERTICALBAR */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_VERTICALBAR
static int tolua_get_SCANCODE_KP_VERTICALBAR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_VERTICALBAR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_DBLVERTICALBAR */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_DBLVERTICALBAR
static int tolua_get_SCANCODE_KP_DBLVERTICALBAR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_DBLVERTICALBAR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_COLON */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_COLON
static int tolua_get_SCANCODE_KP_COLON(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_COLON);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_HASH */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_HASH
static int tolua_get_SCANCODE_KP_HASH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_HASH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_SPACE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_SPACE
static int tolua_get_SCANCODE_KP_SPACE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_SPACE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_AT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_AT
static int tolua_get_SCANCODE_KP_AT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_AT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_EXCLAM */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_EXCLAM
static int tolua_get_SCANCODE_KP_EXCLAM(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_EXCLAM);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_MEMSTORE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_MEMSTORE
static int tolua_get_SCANCODE_KP_MEMSTORE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_MEMSTORE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_MEMRECALL */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_MEMRECALL
static int tolua_get_SCANCODE_KP_MEMRECALL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_MEMRECALL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_MEMCLEAR */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_MEMCLEAR
static int tolua_get_SCANCODE_KP_MEMCLEAR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_MEMCLEAR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_MEMADD */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_MEMADD
static int tolua_get_SCANCODE_KP_MEMADD(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_MEMADD);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_MEMSUBTRACT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_MEMSUBTRACT
static int tolua_get_SCANCODE_KP_MEMSUBTRACT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_MEMSUBTRACT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_MEMMULTIPLY */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_MEMMULTIPLY
static int tolua_get_SCANCODE_KP_MEMMULTIPLY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_MEMMULTIPLY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_MEMDIVIDE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_MEMDIVIDE
static int tolua_get_SCANCODE_KP_MEMDIVIDE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_MEMDIVIDE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_PLUSMINUS */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_PLUSMINUS
static int tolua_get_SCANCODE_KP_PLUSMINUS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_PLUSMINUS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_CLEAR */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_CLEAR
static int tolua_get_SCANCODE_KP_CLEAR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_CLEAR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_CLEARENTRY */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_CLEARENTRY
static int tolua_get_SCANCODE_KP_CLEARENTRY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_CLEARENTRY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_BINARY */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_BINARY
static int tolua_get_SCANCODE_KP_BINARY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_BINARY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_OCTAL */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_OCTAL
static int tolua_get_SCANCODE_KP_OCTAL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_OCTAL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_DECIMAL */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_DECIMAL
static int tolua_get_SCANCODE_KP_DECIMAL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_DECIMAL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KP_HEXADECIMAL */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KP_HEXADECIMAL
static int tolua_get_SCANCODE_KP_HEXADECIMAL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KP_HEXADECIMAL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_LCTRL */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_LCTRL
static int tolua_get_SCANCODE_LCTRL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_LCTRL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_LSHIFT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_LSHIFT
static int tolua_get_SCANCODE_LSHIFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_LSHIFT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_LALT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_LALT
static int tolua_get_SCANCODE_LALT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_LALT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_LGUI */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_LGUI
static int tolua_get_SCANCODE_LGUI(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_LGUI);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_RCTRL */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_RCTRL
static int tolua_get_SCANCODE_RCTRL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_RCTRL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_RSHIFT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_RSHIFT
static int tolua_get_SCANCODE_RSHIFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_RSHIFT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_RALT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_RALT
static int tolua_get_SCANCODE_RALT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_RALT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_RGUI */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_RGUI
static int tolua_get_SCANCODE_RGUI(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_RGUI);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_MODE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_MODE
static int tolua_get_SCANCODE_MODE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_MODE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_AUDIONEXT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_AUDIONEXT
static int tolua_get_SCANCODE_AUDIONEXT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_AUDIONEXT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_AUDIOPREV */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_AUDIOPREV
static int tolua_get_SCANCODE_AUDIOPREV(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_AUDIOPREV);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_AUDIOSTOP */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_AUDIOSTOP
static int tolua_get_SCANCODE_AUDIOSTOP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_AUDIOSTOP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_AUDIOPLAY */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_AUDIOPLAY
static int tolua_get_SCANCODE_AUDIOPLAY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_AUDIOPLAY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_AUDIOMUTE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_AUDIOMUTE
static int tolua_get_SCANCODE_AUDIOMUTE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_AUDIOMUTE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_MEDIASELECT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_MEDIASELECT
static int tolua_get_SCANCODE_MEDIASELECT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_MEDIASELECT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_WWW */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_WWW
static int tolua_get_SCANCODE_WWW(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_WWW);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_MAIL */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_MAIL
static int tolua_get_SCANCODE_MAIL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_MAIL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_CALCULATOR */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_CALCULATOR
static int tolua_get_SCANCODE_CALCULATOR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_CALCULATOR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_COMPUTER */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_COMPUTER
static int tolua_get_SCANCODE_COMPUTER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_COMPUTER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_AC_SEARCH */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_AC_SEARCH
static int tolua_get_SCANCODE_AC_SEARCH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_AC_SEARCH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_AC_HOME */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_AC_HOME
static int tolua_get_SCANCODE_AC_HOME(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_AC_HOME);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_AC_BACK */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_AC_BACK
static int tolua_get_SCANCODE_AC_BACK(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_AC_BACK);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_AC_FORWARD */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_AC_FORWARD
static int tolua_get_SCANCODE_AC_FORWARD(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_AC_FORWARD);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_AC_STOP */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_AC_STOP
static int tolua_get_SCANCODE_AC_STOP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_AC_STOP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_AC_REFRESH */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_AC_REFRESH
static int tolua_get_SCANCODE_AC_REFRESH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_AC_REFRESH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_AC_BOOKMARKS */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_AC_BOOKMARKS
static int tolua_get_SCANCODE_AC_BOOKMARKS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_AC_BOOKMARKS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_BRIGHTNESSDOWN */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_BRIGHTNESSDOWN
static int tolua_get_SCANCODE_BRIGHTNESSDOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_BRIGHTNESSDOWN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_BRIGHTNESSUP */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_BRIGHTNESSUP
static int tolua_get_SCANCODE_BRIGHTNESSUP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_BRIGHTNESSUP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_DISPLAYSWITCH */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_DISPLAYSWITCH
static int tolua_get_SCANCODE_DISPLAYSWITCH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_DISPLAYSWITCH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KBDILLUMTOGGLE */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KBDILLUMTOGGLE
static int tolua_get_SCANCODE_KBDILLUMTOGGLE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KBDILLUMTOGGLE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KBDILLUMDOWN */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KBDILLUMDOWN
static int tolua_get_SCANCODE_KBDILLUMDOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KBDILLUMDOWN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_KBDILLUMUP */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_KBDILLUMUP
static int tolua_get_SCANCODE_KBDILLUMUP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_KBDILLUMUP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_EJECT */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_EJECT
static int tolua_get_SCANCODE_EJECT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_EJECT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_SLEEP */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_SLEEP
static int tolua_get_SCANCODE_SLEEP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_SLEEP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_APP1 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_APP1
static int tolua_get_SCANCODE_APP1(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_APP1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCANCODE_APP2 */
#ifndef TOLUA_DISABLE_tolua_get_SCANCODE_APP2
static int tolua_get_SCANCODE_APP2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCANCODE_APP2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: HAT_CENTER */
#ifndef TOLUA_DISABLE_tolua_get_HAT_CENTER
static int tolua_get_HAT_CENTER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)HAT_CENTER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: HAT_UP */
#ifndef TOLUA_DISABLE_tolua_get_HAT_UP
static int tolua_get_HAT_UP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)HAT_UP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: HAT_RIGHT */
#ifndef TOLUA_DISABLE_tolua_get_HAT_RIGHT
static int tolua_get_HAT_RIGHT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)HAT_RIGHT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: HAT_DOWN */
#ifndef TOLUA_DISABLE_tolua_get_HAT_DOWN
static int tolua_get_HAT_DOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)HAT_DOWN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: HAT_LEFT */
#ifndef TOLUA_DISABLE_tolua_get_HAT_LEFT
static int tolua_get_HAT_LEFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)HAT_LEFT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_BUTTON_A */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_BUTTON_A
static int tolua_get_CONTROLLER_BUTTON_A(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_BUTTON_A);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_BUTTON_B */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_BUTTON_B
static int tolua_get_CONTROLLER_BUTTON_B(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_BUTTON_B);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_BUTTON_X */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_BUTTON_X
static int tolua_get_CONTROLLER_BUTTON_X(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_BUTTON_X);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_BUTTON_Y */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_BUTTON_Y
static int tolua_get_CONTROLLER_BUTTON_Y(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_BUTTON_Y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_BUTTON_BACK */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_BUTTON_BACK
static int tolua_get_CONTROLLER_BUTTON_BACK(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_BUTTON_BACK);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_BUTTON_GUIDE */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_BUTTON_GUIDE
static int tolua_get_CONTROLLER_BUTTON_GUIDE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_BUTTON_GUIDE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_BUTTON_START */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_BUTTON_START
static int tolua_get_CONTROLLER_BUTTON_START(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_BUTTON_START);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_BUTTON_LEFTSTICK */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_BUTTON_LEFTSTICK
static int tolua_get_CONTROLLER_BUTTON_LEFTSTICK(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_BUTTON_LEFTSTICK);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_BUTTON_RIGHTSTICK */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_BUTTON_RIGHTSTICK
static int tolua_get_CONTROLLER_BUTTON_RIGHTSTICK(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_BUTTON_RIGHTSTICK);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_BUTTON_LEFTSHOULDER */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_BUTTON_LEFTSHOULDER
static int tolua_get_CONTROLLER_BUTTON_LEFTSHOULDER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_BUTTON_LEFTSHOULDER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_BUTTON_RIGHTSHOULDER */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_BUTTON_RIGHTSHOULDER
static int tolua_get_CONTROLLER_BUTTON_RIGHTSHOULDER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_BUTTON_RIGHTSHOULDER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_BUTTON_DPAD_UP */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_BUTTON_DPAD_UP
static int tolua_get_CONTROLLER_BUTTON_DPAD_UP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_BUTTON_DPAD_UP);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_BUTTON_DPAD_DOWN */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_BUTTON_DPAD_DOWN
static int tolua_get_CONTROLLER_BUTTON_DPAD_DOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_BUTTON_DPAD_DOWN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_BUTTON_DPAD_LEFT */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_BUTTON_DPAD_LEFT
static int tolua_get_CONTROLLER_BUTTON_DPAD_LEFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_BUTTON_DPAD_LEFT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_BUTTON_DPAD_RIGHT */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_BUTTON_DPAD_RIGHT
static int tolua_get_CONTROLLER_BUTTON_DPAD_RIGHT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_BUTTON_DPAD_RIGHT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_AXIS_LEFTX */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_AXIS_LEFTX
static int tolua_get_CONTROLLER_AXIS_LEFTX(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_AXIS_LEFTX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_AXIS_LEFTY */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_AXIS_LEFTY
static int tolua_get_CONTROLLER_AXIS_LEFTY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_AXIS_LEFTY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_AXIS_RIGHTX */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_AXIS_RIGHTX
static int tolua_get_CONTROLLER_AXIS_RIGHTX(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_AXIS_RIGHTX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_AXIS_RIGHTY */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_AXIS_RIGHTY
static int tolua_get_CONTROLLER_AXIS_RIGHTY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_AXIS_RIGHTY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_AXIS_TRIGGERLEFT */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_AXIS_TRIGGERLEFT
static int tolua_get_CONTROLLER_AXIS_TRIGGERLEFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_AXIS_TRIGGERLEFT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CONTROLLER_AXIS_TRIGGERRIGHT */
#ifndef TOLUA_DISABLE_tolua_get_CONTROLLER_AXIS_TRIGGERRIGHT
static int tolua_get_CONTROLLER_AXIS_TRIGGERRIGHT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)CONTROLLER_AXIS_TRIGGERRIGHT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_InputLuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Controls","Controls","",tolua_collect_Controls);
 #else
 tolua_cclass(tolua_S,"Controls","Controls","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Controls");
  tolua_function(tolua_S,"new",tolua_InputLuaAPI_Controls_new00);
  tolua_function(tolua_S,"new_local",tolua_InputLuaAPI_Controls_new00_local);
  tolua_function(tolua_S,".call",tolua_InputLuaAPI_Controls_new00_local);
  tolua_function(tolua_S,"delete",tolua_InputLuaAPI_Controls_delete00);
  tolua_function(tolua_S,"Reset",tolua_InputLuaAPI_Controls_Reset00);
  tolua_function(tolua_S,"Set",tolua_InputLuaAPI_Controls_Set00);
  tolua_function(tolua_S,"IsDown",tolua_InputLuaAPI_Controls_IsDown00);
  tolua_function(tolua_S,"IsPressed",tolua_InputLuaAPI_Controls_IsPressed00);
  tolua_variable(tolua_S,"buttons",tolua_get_Controls_buttons,tolua_set_Controls_buttons);
  tolua_variable(tolua_S,"yaw",tolua_get_Controls_yaw,tolua_set_Controls_yaw);
  tolua_variable(tolua_S,"pitch",tolua_get_Controls_pitch,tolua_set_Controls_pitch);
  tolua_variable(tolua_S,"extraData",tolua_get_Controls_extraData,tolua_set_Controls_extraData);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"MM_ABSOLUTE",MM_ABSOLUTE);
 tolua_constant(tolua_S,"MM_RELATIVE",MM_RELATIVE);
 tolua_constant(tolua_S,"MM_WRAP",MM_WRAP);
 tolua_constant(tolua_S,"MM_FREE",MM_FREE);
 tolua_cclass(tolua_S,"TouchState","TouchState","",NULL);
 tolua_beginmodule(tolua_S,"TouchState");
  tolua_function(tolua_S,"GetTouchedElement",tolua_InputLuaAPI_TouchState_GetTouchedElement00);
  tolua_variable(tolua_S,"touchID",tolua_get_TouchState_touchID,tolua_set_TouchState_touchID);
  tolua_variable(tolua_S,"position",tolua_get_TouchState_position,tolua_set_TouchState_position);
  tolua_variable(tolua_S,"lastPosition",tolua_get_TouchState_lastPosition,tolua_set_TouchState_lastPosition);
  tolua_variable(tolua_S,"delta",tolua_get_TouchState_delta,tolua_set_TouchState_delta);
  tolua_variable(tolua_S,"pressure",tolua_get_TouchState_pressure,tolua_set_TouchState_pressure);
  tolua_variable(tolua_S,"touchedElement",tolua_get_TouchState_touchedElement_ptr,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"JoystickState","JoystickState","",NULL);
 tolua_beginmodule(tolua_S,"JoystickState");
  tolua_variable(tolua_S,"name",tolua_get_JoystickState_name,NULL);
  tolua_variable(tolua_S,"joystickID",tolua_get_JoystickState_joystickID,NULL);
  tolua_function(tolua_S,"IsController",tolua_InputLuaAPI_JoystickState_IsController00);
  tolua_function(tolua_S,"GetNumButtons",tolua_InputLuaAPI_JoystickState_GetNumButtons00);
  tolua_function(tolua_S,"GetNumAxes",tolua_InputLuaAPI_JoystickState_GetNumAxes00);
  tolua_function(tolua_S,"GetNumHats",tolua_InputLuaAPI_JoystickState_GetNumHats00);
  tolua_function(tolua_S,"GetButtonDown",tolua_InputLuaAPI_JoystickState_GetButtonDown00);
  tolua_function(tolua_S,"GetButtonPress",tolua_InputLuaAPI_JoystickState_GetButtonPress00);
  tolua_function(tolua_S,"GetAxisPosition",tolua_InputLuaAPI_JoystickState_GetAxisPosition00);
  tolua_function(tolua_S,"GetHatPosition",tolua_InputLuaAPI_JoystickState_GetHatPosition00);
  tolua_variable(tolua_S,"controller",tolua_get_JoystickState_controller,NULL);
  tolua_variable(tolua_S,"numButtons",tolua_get_JoystickState_numButtons,NULL);
  tolua_variable(tolua_S,"numAxes",tolua_get_JoystickState_numAxes,NULL);
  tolua_variable(tolua_S,"numHats",tolua_get_JoystickState_numHats,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Input","Input","Object",NULL);
 tolua_beginmodule(tolua_S,"Input");
  tolua_function(tolua_S,"SetToggleFullscreen",tolua_InputLuaAPI_Input_SetToggleFullscreen00);
  tolua_function(tolua_S,"SetMouseVisible",tolua_InputLuaAPI_Input_SetMouseVisible00);
  tolua_function(tolua_S,"SetMouseGrabbed",tolua_InputLuaAPI_Input_SetMouseGrabbed00);
  tolua_function(tolua_S,"SetMouseMode",tolua_InputLuaAPI_Input_SetMouseMode00);
  tolua_function(tolua_S,"IsMouseLocked",tolua_InputLuaAPI_Input_IsMouseLocked00);
  tolua_function(tolua_S,"AddScreenJoystick",tolua_InputLuaAPI_Input_AddScreenJoystick00);
  tolua_function(tolua_S,"RemoveScreenJoystick",tolua_InputLuaAPI_Input_RemoveScreenJoystick00);
  tolua_function(tolua_S,"SetScreenJoystickVisible",tolua_InputLuaAPI_Input_SetScreenJoystickVisible00);
  tolua_function(tolua_S,"SetScreenKeyboardVisible",tolua_InputLuaAPI_Input_SetScreenKeyboardVisible00);
  tolua_function(tolua_S,"SetTouchEmulation",tolua_InputLuaAPI_Input_SetTouchEmulation00);
  tolua_function(tolua_S,"RecordGesture",tolua_InputLuaAPI_Input_RecordGesture00);
  tolua_function(tolua_S,"SaveGestures",tolua_InputLuaAPI_Input_SaveGestures00);
  tolua_function(tolua_S,"SaveGesture",tolua_InputLuaAPI_Input_SaveGesture00);
  tolua_function(tolua_S,"LoadGestures",tolua_InputLuaAPI_Input_LoadGestures00);
  tolua_function(tolua_S,"SaveGestures",tolua_InputLuaAPI_Input_SaveGestures01);
  tolua_function(tolua_S,"SaveGesture",tolua_InputLuaAPI_Input_SaveGesture01);
  tolua_function(tolua_S,"LoadGestures",tolua_InputLuaAPI_Input_LoadGestures01);
  tolua_function(tolua_S,"RemoveGesture",tolua_InputLuaAPI_Input_RemoveGesture00);
  tolua_function(tolua_S,"RemoveAllGestures",tolua_InputLuaAPI_Input_RemoveAllGestures00);
  tolua_function(tolua_S,"SetMousePosition",tolua_InputLuaAPI_Input_SetMousePosition00);
  tolua_function(tolua_S,"CenterMousePosition",tolua_InputLuaAPI_Input_CenterMousePosition00);
  tolua_function(tolua_S,"GetKeyFromName",tolua_InputLuaAPI_Input_GetKeyFromName00);
  tolua_function(tolua_S,"GetKeyFromScancode",tolua_InputLuaAPI_Input_GetKeyFromScancode00);
  tolua_function(tolua_S,"GetKeyName",tolua_InputLuaAPI_Input_GetKeyName00);
  tolua_function(tolua_S,"GetScancodeFromKey",tolua_InputLuaAPI_Input_GetScancodeFromKey00);
  tolua_function(tolua_S,"GetScancodeFromName",tolua_InputLuaAPI_Input_GetScancodeFromName00);
  tolua_function(tolua_S,"GetScancodeName",tolua_InputLuaAPI_Input_GetScancodeName00);
  tolua_function(tolua_S,"GetKeyDown",tolua_InputLuaAPI_Input_GetKeyDown00);
  tolua_function(tolua_S,"GetKeyPress",tolua_InputLuaAPI_Input_GetKeyPress00);
  tolua_function(tolua_S,"GetScancodeDown",tolua_InputLuaAPI_Input_GetScancodeDown00);
  tolua_function(tolua_S,"GetScancodePress",tolua_InputLuaAPI_Input_GetScancodePress00);
  tolua_function(tolua_S,"GetMouseButtonDown",tolua_InputLuaAPI_Input_GetMouseButtonDown00);
  tolua_function(tolua_S,"GetMouseButtonPress",tolua_InputLuaAPI_Input_GetMouseButtonPress00);
  tolua_function(tolua_S,"GetQualifierDown",tolua_InputLuaAPI_Input_GetQualifierDown00);
  tolua_function(tolua_S,"GetQualifierPress",tolua_InputLuaAPI_Input_GetQualifierPress00);
  tolua_function(tolua_S,"GetQualifiers",tolua_InputLuaAPI_Input_GetQualifiers00);
  tolua_function(tolua_S,"GetMousePosition",tolua_InputLuaAPI_Input_GetMousePosition00);
  tolua_function(tolua_S,"GetMouseMove",tolua_InputLuaAPI_Input_GetMouseMove00);
  tolua_function(tolua_S,"GetMouseMoveX",tolua_InputLuaAPI_Input_GetMouseMoveX00);
  tolua_function(tolua_S,"GetMouseMoveY",tolua_InputLuaAPI_Input_GetMouseMoveY00);
  tolua_function(tolua_S,"GetMouseMoveWheel",tolua_InputLuaAPI_Input_GetMouseMoveWheel00);
  tolua_function(tolua_S,"GetInputScale",tolua_InputLuaAPI_Input_GetInputScale00);
  tolua_function(tolua_S,"GetNumTouches",tolua_InputLuaAPI_Input_GetNumTouches00);
  tolua_function(tolua_S,"GetTouch",tolua_InputLuaAPI_Input_GetTouch00);
  tolua_function(tolua_S,"GetNumJoysticks",tolua_InputLuaAPI_Input_GetNumJoysticks00);
  tolua_function(tolua_S,"GetJoystick",tolua_InputLuaAPI_Input_GetJoystick00);
  tolua_function(tolua_S,"GetJoystickByIndex",tolua_InputLuaAPI_Input_GetJoystickByIndex00);
  tolua_function(tolua_S,"GetJoystickByName",tolua_InputLuaAPI_Input_GetJoystickByName00);
  tolua_function(tolua_S,"GetToggleFullscreen",tolua_InputLuaAPI_Input_GetToggleFullscreen00);
  tolua_function(tolua_S,"GetScreenKeyboardSupport",tolua_InputLuaAPI_Input_GetScreenKeyboardSupport00);
  tolua_function(tolua_S,"IsScreenJoystickVisible",tolua_InputLuaAPI_Input_IsScreenJoystickVisible00);
  tolua_function(tolua_S,"IsScreenKeyboardVisible",tolua_InputLuaAPI_Input_IsScreenKeyboardVisible00);
  tolua_function(tolua_S,"GetTouchEmulation",tolua_InputLuaAPI_Input_GetTouchEmulation00);
  tolua_function(tolua_S,"IsMouseVisible",tolua_InputLuaAPI_Input_IsMouseVisible00);
  tolua_function(tolua_S,"IsMouseGrabbed",tolua_InputLuaAPI_Input_IsMouseGrabbed00);
  tolua_function(tolua_S,"GetMouseMode",tolua_InputLuaAPI_Input_GetMouseMode00);
  tolua_function(tolua_S,"HasFocus",tolua_InputLuaAPI_Input_HasFocus00);
  tolua_function(tolua_S,"IsMinimized",tolua_InputLuaAPI_Input_IsMinimized00);
  tolua_variable(tolua_S,"qualifiers",tolua_get_Input_qualifiers,NULL);
  tolua_variable(tolua_S,"mousePosition",tolua_get_Input_mousePosition,tolua_set_Input_mousePosition);
  tolua_variable(tolua_S,"mouseMove",tolua_get_Input_mouseMove,NULL);
  tolua_variable(tolua_S,"mouseMoveX",tolua_get_Input_mouseMoveX,NULL);
  tolua_variable(tolua_S,"mouseMoveY",tolua_get_Input_mouseMoveY,NULL);
  tolua_variable(tolua_S,"mouseMoveWheel",tolua_get_Input_mouseMoveWheel,NULL);
  tolua_variable(tolua_S,"inputScale",tolua_get_Input_inputScale,NULL);
  tolua_variable(tolua_S,"numTouches",tolua_get_Input_numTouches,NULL);
  tolua_variable(tolua_S,"numJoysticks",tolua_get_Input_numJoysticks,NULL);
  tolua_variable(tolua_S,"toggleFullscreen",tolua_get_Input_toggleFullscreen,NULL);
  tolua_variable(tolua_S,"screenKeyboardSupport",tolua_get_Input_screenKeyboardSupport,NULL);
  tolua_variable(tolua_S,"mouseMode",tolua_get_Input_mouseMode,tolua_set_Input_mouseMode);
  tolua_variable(tolua_S,"screenKeyboardVisible",tolua_get_Input_screenKeyboardVisible,tolua_set_Input_screenKeyboardVisible);
  tolua_variable(tolua_S,"touchEmulation",tolua_get_Input_touchEmulation,tolua_set_Input_touchEmulation);
  tolua_variable(tolua_S,"mouseVisible",tolua_get_Input_mouseVisible,tolua_set_Input_mouseVisible);
  tolua_variable(tolua_S,"mouseGrabbed",tolua_get_Input_mouseGrabbed,tolua_set_Input_mouseGrabbed);
  tolua_variable(tolua_S,"mouseLocked",tolua_get_Input_mouseLocked,NULL);
  tolua_variable(tolua_S,"focus",tolua_get_Input_focus,NULL);
  tolua_variable(tolua_S,"minimized",tolua_get_Input_minimized,NULL);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"GetInput",tolua_InputLuaAPI_GetInput00);
 tolua_variable(tolua_S,"input",tolua_get_input_ptr,NULL);
 tolua_variable(tolua_S,"MOUSEB_LEFT",tolua_get_MOUSEB_LEFT,NULL);
 tolua_variable(tolua_S,"MOUSEB_MIDDLE",tolua_get_MOUSEB_MIDDLE,NULL);
 tolua_variable(tolua_S,"MOUSEB_RIGHT",tolua_get_MOUSEB_RIGHT,NULL);
 tolua_variable(tolua_S,"QUAL_SHIFT",tolua_get_QUAL_SHIFT,NULL);
 tolua_variable(tolua_S,"QUAL_CTRL",tolua_get_QUAL_CTRL,NULL);
 tolua_variable(tolua_S,"QUAL_ALT",tolua_get_QUAL_ALT,NULL);
 tolua_variable(tolua_S,"QUAL_ANY",tolua_get_QUAL_ANY,NULL);
 tolua_variable(tolua_S,"KEY_UNKNOWN",tolua_get_KEY_UNKNOWN,NULL);
 tolua_variable(tolua_S,"KEY_A",tolua_get_KEY_A,NULL);
 tolua_variable(tolua_S,"KEY_B",tolua_get_KEY_B,NULL);
 tolua_variable(tolua_S,"KEY_C",tolua_get_KEY_C,NULL);
 tolua_variable(tolua_S,"KEY_D",tolua_get_KEY_D,NULL);
 tolua_variable(tolua_S,"KEY_E",tolua_get_KEY_E,NULL);
 tolua_variable(tolua_S,"KEY_F",tolua_get_KEY_F,NULL);
 tolua_variable(tolua_S,"KEY_G",tolua_get_KEY_G,NULL);
 tolua_variable(tolua_S,"KEY_H",tolua_get_KEY_H,NULL);
 tolua_variable(tolua_S,"KEY_I",tolua_get_KEY_I,NULL);
 tolua_variable(tolua_S,"KEY_J",tolua_get_KEY_J,NULL);
 tolua_variable(tolua_S,"KEY_K",tolua_get_KEY_K,NULL);
 tolua_variable(tolua_S,"KEY_L",tolua_get_KEY_L,NULL);
 tolua_variable(tolua_S,"KEY_M",tolua_get_KEY_M,NULL);
 tolua_variable(tolua_S,"KEY_N",tolua_get_KEY_N,NULL);
 tolua_variable(tolua_S,"KEY_O",tolua_get_KEY_O,NULL);
 tolua_variable(tolua_S,"KEY_P",tolua_get_KEY_P,NULL);
 tolua_variable(tolua_S,"KEY_Q",tolua_get_KEY_Q,NULL);
 tolua_variable(tolua_S,"KEY_R",tolua_get_KEY_R,NULL);
 tolua_variable(tolua_S,"KEY_S",tolua_get_KEY_S,NULL);
 tolua_variable(tolua_S,"KEY_T",tolua_get_KEY_T,NULL);
 tolua_variable(tolua_S,"KEY_U",tolua_get_KEY_U,NULL);
 tolua_variable(tolua_S,"KEY_V",tolua_get_KEY_V,NULL);
 tolua_variable(tolua_S,"KEY_W",tolua_get_KEY_W,NULL);
 tolua_variable(tolua_S,"KEY_X",tolua_get_KEY_X,NULL);
 tolua_variable(tolua_S,"KEY_Y",tolua_get_KEY_Y,NULL);
 tolua_variable(tolua_S,"KEY_Z",tolua_get_KEY_Z,NULL);
 tolua_variable(tolua_S,"KEY_0",tolua_get_KEY_0,NULL);
 tolua_variable(tolua_S,"KEY_1",tolua_get_KEY_1,NULL);
 tolua_variable(tolua_S,"KEY_2",tolua_get_KEY_2,NULL);
 tolua_variable(tolua_S,"KEY_3",tolua_get_KEY_3,NULL);
 tolua_variable(tolua_S,"KEY_4",tolua_get_KEY_4,NULL);
 tolua_variable(tolua_S,"KEY_5",tolua_get_KEY_5,NULL);
 tolua_variable(tolua_S,"KEY_6",tolua_get_KEY_6,NULL);
 tolua_variable(tolua_S,"KEY_7",tolua_get_KEY_7,NULL);
 tolua_variable(tolua_S,"KEY_8",tolua_get_KEY_8,NULL);
 tolua_variable(tolua_S,"KEY_9",tolua_get_KEY_9,NULL);
 tolua_variable(tolua_S,"KEY_BACKSPACE",tolua_get_KEY_BACKSPACE,NULL);
 tolua_variable(tolua_S,"KEY_TAB",tolua_get_KEY_TAB,NULL);
 tolua_variable(tolua_S,"KEY_RETURN",tolua_get_KEY_RETURN,NULL);
 tolua_variable(tolua_S,"KEY_RETURN2",tolua_get_KEY_RETURN2,NULL);
 tolua_variable(tolua_S,"KEY_KP_ENTER",tolua_get_KEY_KP_ENTER,NULL);
 tolua_variable(tolua_S,"KEY_SHIFT",tolua_get_KEY_SHIFT,NULL);
 tolua_variable(tolua_S,"KEY_CTRL",tolua_get_KEY_CTRL,NULL);
 tolua_variable(tolua_S,"KEY_ALT",tolua_get_KEY_ALT,NULL);
 tolua_variable(tolua_S,"KEY_GUI",tolua_get_KEY_GUI,NULL);
 tolua_variable(tolua_S,"KEY_PAUSE",tolua_get_KEY_PAUSE,NULL);
 tolua_variable(tolua_S,"KEY_CAPSLOCK",tolua_get_KEY_CAPSLOCK,NULL);
 tolua_variable(tolua_S,"KEY_ESCAPE",tolua_get_KEY_ESCAPE,NULL);
 tolua_variable(tolua_S,"KEY_SPACE",tolua_get_KEY_SPACE,NULL);
 tolua_variable(tolua_S,"KEY_PAGEUP",tolua_get_KEY_PAGEUP,NULL);
 tolua_variable(tolua_S,"KEY_PAGEDOWN",tolua_get_KEY_PAGEDOWN,NULL);
 tolua_variable(tolua_S,"KEY_END",tolua_get_KEY_END,NULL);
 tolua_variable(tolua_S,"KEY_HOME",tolua_get_KEY_HOME,NULL);
 tolua_variable(tolua_S,"KEY_LEFT",tolua_get_KEY_LEFT,NULL);
 tolua_variable(tolua_S,"KEY_UP",tolua_get_KEY_UP,NULL);
 tolua_variable(tolua_S,"KEY_RIGHT",tolua_get_KEY_RIGHT,NULL);
 tolua_variable(tolua_S,"KEY_DOWN",tolua_get_KEY_DOWN,NULL);
 tolua_variable(tolua_S,"KEY_SELECT",tolua_get_KEY_SELECT,NULL);
 tolua_variable(tolua_S,"KEY_PRINTSCREEN",tolua_get_KEY_PRINTSCREEN,NULL);
 tolua_variable(tolua_S,"KEY_INSERT",tolua_get_KEY_INSERT,NULL);
 tolua_variable(tolua_S,"KEY_DELETE",tolua_get_KEY_DELETE,NULL);
 tolua_variable(tolua_S,"KEY_LGUI",tolua_get_KEY_LGUI,NULL);
 tolua_variable(tolua_S,"KEY_RGUI",tolua_get_KEY_RGUI,NULL);
 tolua_variable(tolua_S,"KEY_APPLICATION",tolua_get_KEY_APPLICATION,NULL);
 tolua_variable(tolua_S,"KEY_KP_0",tolua_get_KEY_KP_0,NULL);
 tolua_variable(tolua_S,"KEY_KP_1",tolua_get_KEY_KP_1,NULL);
 tolua_variable(tolua_S,"KEY_KP_2",tolua_get_KEY_KP_2,NULL);
 tolua_variable(tolua_S,"KEY_KP_3",tolua_get_KEY_KP_3,NULL);
 tolua_variable(tolua_S,"KEY_KP_4",tolua_get_KEY_KP_4,NULL);
 tolua_variable(tolua_S,"KEY_KP_5",tolua_get_KEY_KP_5,NULL);
 tolua_variable(tolua_S,"KEY_KP_6",tolua_get_KEY_KP_6,NULL);
 tolua_variable(tolua_S,"KEY_KP_7",tolua_get_KEY_KP_7,NULL);
 tolua_variable(tolua_S,"KEY_KP_8",tolua_get_KEY_KP_8,NULL);
 tolua_variable(tolua_S,"KEY_KP_9",tolua_get_KEY_KP_9,NULL);
 tolua_variable(tolua_S,"KEY_KP_MULTIPLY",tolua_get_KEY_KP_MULTIPLY,NULL);
 tolua_variable(tolua_S,"KEY_KP_PLUS",tolua_get_KEY_KP_PLUS,NULL);
 tolua_variable(tolua_S,"KEY_KP_MINUS",tolua_get_KEY_KP_MINUS,NULL);
 tolua_variable(tolua_S,"KEY_KP_PERIOD",tolua_get_KEY_KP_PERIOD,NULL);
 tolua_variable(tolua_S,"KEY_KP_DIVIDE",tolua_get_KEY_KP_DIVIDE,NULL);
 tolua_variable(tolua_S,"KEY_F1",tolua_get_KEY_F1,NULL);
 tolua_variable(tolua_S,"KEY_F2",tolua_get_KEY_F2,NULL);
 tolua_variable(tolua_S,"KEY_F3",tolua_get_KEY_F3,NULL);
 tolua_variable(tolua_S,"KEY_F4",tolua_get_KEY_F4,NULL);
 tolua_variable(tolua_S,"KEY_F5",tolua_get_KEY_F5,NULL);
 tolua_variable(tolua_S,"KEY_F6",tolua_get_KEY_F6,NULL);
 tolua_variable(tolua_S,"KEY_F7",tolua_get_KEY_F7,NULL);
 tolua_variable(tolua_S,"KEY_F8",tolua_get_KEY_F8,NULL);
 tolua_variable(tolua_S,"KEY_F9",tolua_get_KEY_F9,NULL);
 tolua_variable(tolua_S,"KEY_F10",tolua_get_KEY_F10,NULL);
 tolua_variable(tolua_S,"KEY_F11",tolua_get_KEY_F11,NULL);
 tolua_variable(tolua_S,"KEY_F12",tolua_get_KEY_F12,NULL);
 tolua_variable(tolua_S,"KEY_F13",tolua_get_KEY_F13,NULL);
 tolua_variable(tolua_S,"KEY_F14",tolua_get_KEY_F14,NULL);
 tolua_variable(tolua_S,"KEY_F15",tolua_get_KEY_F15,NULL);
 tolua_variable(tolua_S,"KEY_F16",tolua_get_KEY_F16,NULL);
 tolua_variable(tolua_S,"KEY_F17",tolua_get_KEY_F17,NULL);
 tolua_variable(tolua_S,"KEY_F18",tolua_get_KEY_F18,NULL);
 tolua_variable(tolua_S,"KEY_F19",tolua_get_KEY_F19,NULL);
 tolua_variable(tolua_S,"KEY_F20",tolua_get_KEY_F20,NULL);
 tolua_variable(tolua_S,"KEY_F21",tolua_get_KEY_F21,NULL);
 tolua_variable(tolua_S,"KEY_F22",tolua_get_KEY_F22,NULL);
 tolua_variable(tolua_S,"KEY_F23",tolua_get_KEY_F23,NULL);
 tolua_variable(tolua_S,"KEY_F24",tolua_get_KEY_F24,NULL);
 tolua_variable(tolua_S,"KEY_NUMLOCKCLEAR",tolua_get_KEY_NUMLOCKCLEAR,NULL);
 tolua_variable(tolua_S,"KEY_SCROLLLOCK",tolua_get_KEY_SCROLLLOCK,NULL);
 tolua_variable(tolua_S,"KEY_LSHIFT",tolua_get_KEY_LSHIFT,NULL);
 tolua_variable(tolua_S,"KEY_RSHIFT",tolua_get_KEY_RSHIFT,NULL);
 tolua_variable(tolua_S,"KEY_LCTRL",tolua_get_KEY_LCTRL,NULL);
 tolua_variable(tolua_S,"KEY_RCTRL",tolua_get_KEY_RCTRL,NULL);
 tolua_variable(tolua_S,"KEY_LALT",tolua_get_KEY_LALT,NULL);
 tolua_variable(tolua_S,"KEY_RALT",tolua_get_KEY_RALT,NULL);
 tolua_variable(tolua_S,"KEY_AC_BACK",tolua_get_KEY_AC_BACK,NULL);
 tolua_variable(tolua_S,"KEY_AC_BOOKMARKS",tolua_get_KEY_AC_BOOKMARKS,NULL);
 tolua_variable(tolua_S,"KEY_AC_FORWARD",tolua_get_KEY_AC_FORWARD,NULL);
 tolua_variable(tolua_S,"KEY_AC_HOME",tolua_get_KEY_AC_HOME,NULL);
 tolua_variable(tolua_S,"KEY_AC_REFRESH",tolua_get_KEY_AC_REFRESH,NULL);
 tolua_variable(tolua_S,"KEY_AC_SEARCH",tolua_get_KEY_AC_SEARCH,NULL);
 tolua_variable(tolua_S,"KEY_AC_STOP",tolua_get_KEY_AC_STOP,NULL);
 tolua_variable(tolua_S,"KEY_AGAIN",tolua_get_KEY_AGAIN,NULL);
 tolua_variable(tolua_S,"KEY_ALTERASE",tolua_get_KEY_ALTERASE,NULL);
 tolua_variable(tolua_S,"KEY_AMPERSAND",tolua_get_KEY_AMPERSAND,NULL);
 tolua_variable(tolua_S,"KEY_ASTERISK",tolua_get_KEY_ASTERISK,NULL);
 tolua_variable(tolua_S,"KEY_AT",tolua_get_KEY_AT,NULL);
 tolua_variable(tolua_S,"KEY_AUDIOMUTE",tolua_get_KEY_AUDIOMUTE,NULL);
 tolua_variable(tolua_S,"KEY_AUDIONEXT",tolua_get_KEY_AUDIONEXT,NULL);
 tolua_variable(tolua_S,"KEY_AUDIOPLAY",tolua_get_KEY_AUDIOPLAY,NULL);
 tolua_variable(tolua_S,"KEY_AUDIOPREV",tolua_get_KEY_AUDIOPREV,NULL);
 tolua_variable(tolua_S,"KEY_AUDIOSTOP",tolua_get_KEY_AUDIOSTOP,NULL);
 tolua_variable(tolua_S,"KEY_BACKQUOTE",tolua_get_KEY_BACKQUOTE,NULL);
 tolua_variable(tolua_S,"KEY_BACKSLASH",tolua_get_KEY_BACKSLASH,NULL);
 tolua_variable(tolua_S,"KEY_BRIGHTNESSDOWN",tolua_get_KEY_BRIGHTNESSDOWN,NULL);
 tolua_variable(tolua_S,"KEY_BRIGHTNESSUP",tolua_get_KEY_BRIGHTNESSUP,NULL);
 tolua_variable(tolua_S,"KEY_CALCULATOR",tolua_get_KEY_CALCULATOR,NULL);
 tolua_variable(tolua_S,"KEY_CANCEL",tolua_get_KEY_CANCEL,NULL);
 tolua_variable(tolua_S,"KEY_CARET",tolua_get_KEY_CARET,NULL);
 tolua_variable(tolua_S,"KEY_CLEAR",tolua_get_KEY_CLEAR,NULL);
 tolua_variable(tolua_S,"KEY_CLEARAGAIN",tolua_get_KEY_CLEARAGAIN,NULL);
 tolua_variable(tolua_S,"KEY_COLON",tolua_get_KEY_COLON,NULL);
 tolua_variable(tolua_S,"KEY_COMMA",tolua_get_KEY_COMMA,NULL);
 tolua_variable(tolua_S,"KEY_COMPUTER",tolua_get_KEY_COMPUTER,NULL);
 tolua_variable(tolua_S,"KEY_COPY",tolua_get_KEY_COPY,NULL);
 tolua_variable(tolua_S,"KEY_CRSEL",tolua_get_KEY_CRSEL,NULL);
 tolua_variable(tolua_S,"KEY_CURRENCYSUBUNIT",tolua_get_KEY_CURRENCYSUBUNIT,NULL);
 tolua_variable(tolua_S,"KEY_CURRENCYUNIT",tolua_get_KEY_CURRENCYUNIT,NULL);
 tolua_variable(tolua_S,"KEY_CUT",tolua_get_KEY_CUT,NULL);
 tolua_variable(tolua_S,"KEY_DECIMALSEPARATOR",tolua_get_KEY_DECIMALSEPARATOR,NULL);
 tolua_variable(tolua_S,"KEY_DISPLAYSWITCH",tolua_get_KEY_DISPLAYSWITCH,NULL);
 tolua_variable(tolua_S,"KEY_DOLLAR",tolua_get_KEY_DOLLAR,NULL);
 tolua_variable(tolua_S,"KEY_EJECT",tolua_get_KEY_EJECT,NULL);
 tolua_variable(tolua_S,"KEY_EQUALS",tolua_get_KEY_EQUALS,NULL);
 tolua_variable(tolua_S,"KEY_EXCLAIM",tolua_get_KEY_EXCLAIM,NULL);
 tolua_variable(tolua_S,"KEY_EXSEL",tolua_get_KEY_EXSEL,NULL);
 tolua_variable(tolua_S,"KEY_FIND",tolua_get_KEY_FIND,NULL);
 tolua_variable(tolua_S,"KEY_GREATER",tolua_get_KEY_GREATER,NULL);
 tolua_variable(tolua_S,"KEY_HASH",tolua_get_KEY_HASH,NULL);
 tolua_variable(tolua_S,"KEY_HELP",tolua_get_KEY_HELP,NULL);
 tolua_variable(tolua_S,"KEY_KBDILLUMDOWN",tolua_get_KEY_KBDILLUMDOWN,NULL);
 tolua_variable(tolua_S,"KEY_KBDILLUMTOGGLE",tolua_get_KEY_KBDILLUMTOGGLE,NULL);
 tolua_variable(tolua_S,"KEY_KBDILLUMUP",tolua_get_KEY_KBDILLUMUP,NULL);
 tolua_variable(tolua_S,"KEY_KP_00",tolua_get_KEY_KP_00,NULL);
 tolua_variable(tolua_S,"KEY_KP_000",tolua_get_KEY_KP_000,NULL);
 tolua_variable(tolua_S,"KEY_KP_A",tolua_get_KEY_KP_A,NULL);
 tolua_variable(tolua_S,"KEY_KP_AMPERSAND",tolua_get_KEY_KP_AMPERSAND,NULL);
 tolua_variable(tolua_S,"KEY_KP_AT",tolua_get_KEY_KP_AT,NULL);
 tolua_variable(tolua_S,"KEY_KP_B",tolua_get_KEY_KP_B,NULL);
 tolua_variable(tolua_S,"KEY_KP_BACKSPACE",tolua_get_KEY_KP_BACKSPACE,NULL);
 tolua_variable(tolua_S,"KEY_KP_BINARY",tolua_get_KEY_KP_BINARY,NULL);
 tolua_variable(tolua_S,"KEY_KP_C",tolua_get_KEY_KP_C,NULL);
 tolua_variable(tolua_S,"KEY_KP_CLEAR",tolua_get_KEY_KP_CLEAR,NULL);
 tolua_variable(tolua_S,"KEY_KP_CLEARENTRY",tolua_get_KEY_KP_CLEARENTRY,NULL);
 tolua_variable(tolua_S,"KEY_KP_COLON",tolua_get_KEY_KP_COLON,NULL);
 tolua_variable(tolua_S,"KEY_KP_COMMA",tolua_get_KEY_KP_COMMA,NULL);
 tolua_variable(tolua_S,"KEY_KP_D",tolua_get_KEY_KP_D,NULL);
 tolua_variable(tolua_S,"KEY_KP_DBLAMPERSAND",tolua_get_KEY_KP_DBLAMPERSAND,NULL);
 tolua_variable(tolua_S,"KEY_KP_DBLVERTICALBAR",tolua_get_KEY_KP_DBLVERTICALBAR,NULL);
 tolua_variable(tolua_S,"KEY_KP_DECIMAL",tolua_get_KEY_KP_DECIMAL,NULL);
 tolua_variable(tolua_S,"KEY_KP_E",tolua_get_KEY_KP_E,NULL);
 tolua_variable(tolua_S,"KEY_KP_EQUALS",tolua_get_KEY_KP_EQUALS,NULL);
 tolua_variable(tolua_S,"KEY_KP_EQUALSAS400",tolua_get_KEY_KP_EQUALSAS400,NULL);
 tolua_variable(tolua_S,"KEY_KP_EXCLAM",tolua_get_KEY_KP_EXCLAM,NULL);
 tolua_variable(tolua_S,"KEY_KP_F",tolua_get_KEY_KP_F,NULL);
 tolua_variable(tolua_S,"KEY_KP_GREATER",tolua_get_KEY_KP_GREATER,NULL);
 tolua_variable(tolua_S,"KEY_KP_HASH",tolua_get_KEY_KP_HASH,NULL);
 tolua_variable(tolua_S,"KEY_KP_HEXADECIMAL",tolua_get_KEY_KP_HEXADECIMAL,NULL);
 tolua_variable(tolua_S,"KEY_KP_LEFTBRACE",tolua_get_KEY_KP_LEFTBRACE,NULL);
 tolua_variable(tolua_S,"KEY_KP_LEFTPAREN",tolua_get_KEY_KP_LEFTPAREN,NULL);
 tolua_variable(tolua_S,"KEY_KP_LESS",tolua_get_KEY_KP_LESS,NULL);
 tolua_variable(tolua_S,"KEY_KP_MEMADD",tolua_get_KEY_KP_MEMADD,NULL);
 tolua_variable(tolua_S,"KEY_KP_MEMCLEAR",tolua_get_KEY_KP_MEMCLEAR,NULL);
 tolua_variable(tolua_S,"KEY_KP_MEMDIVIDE",tolua_get_KEY_KP_MEMDIVIDE,NULL);
 tolua_variable(tolua_S,"KEY_KP_MEMMULTIPLY",tolua_get_KEY_KP_MEMMULTIPLY,NULL);
 tolua_variable(tolua_S,"KEY_KP_MEMRECALL",tolua_get_KEY_KP_MEMRECALL,NULL);
 tolua_variable(tolua_S,"KEY_KP_MEMSTORE",tolua_get_KEY_KP_MEMSTORE,NULL);
 tolua_variable(tolua_S,"KEY_KP_MEMSUBTRACT",tolua_get_KEY_KP_MEMSUBTRACT,NULL);
 tolua_variable(tolua_S,"KEY_KP_OCTAL",tolua_get_KEY_KP_OCTAL,NULL);
 tolua_variable(tolua_S,"KEY_KP_PERCENT",tolua_get_KEY_KP_PERCENT,NULL);
 tolua_variable(tolua_S,"KEY_KP_PLUSMINUS",tolua_get_KEY_KP_PLUSMINUS,NULL);
 tolua_variable(tolua_S,"KEY_KP_POWER",tolua_get_KEY_KP_POWER,NULL);
 tolua_variable(tolua_S,"KEY_KP_RIGHTBRACE",tolua_get_KEY_KP_RIGHTBRACE,NULL);
 tolua_variable(tolua_S,"KEY_KP_RIGHTPAREN",tolua_get_KEY_KP_RIGHTPAREN,NULL);
 tolua_variable(tolua_S,"KEY_KP_SPACE",tolua_get_KEY_KP_SPACE,NULL);
 tolua_variable(tolua_S,"KEY_KP_TAB",tolua_get_KEY_KP_TAB,NULL);
 tolua_variable(tolua_S,"KEY_KP_VERTICALBAR",tolua_get_KEY_KP_VERTICALBAR,NULL);
 tolua_variable(tolua_S,"KEY_KP_XOR",tolua_get_KEY_KP_XOR,NULL);
 tolua_variable(tolua_S,"KEY_LEFTBRACKET",tolua_get_KEY_LEFTBRACKET,NULL);
 tolua_variable(tolua_S,"KEY_LEFTPAREN",tolua_get_KEY_LEFTPAREN,NULL);
 tolua_variable(tolua_S,"KEY_LESS",tolua_get_KEY_LESS,NULL);
 tolua_variable(tolua_S,"KEY_MAIL",tolua_get_KEY_MAIL,NULL);
 tolua_variable(tolua_S,"KEY_MEDIASELECT",tolua_get_KEY_MEDIASELECT,NULL);
 tolua_variable(tolua_S,"KEY_MENU",tolua_get_KEY_MENU,NULL);
 tolua_variable(tolua_S,"KEY_MINUS",tolua_get_KEY_MINUS,NULL);
 tolua_variable(tolua_S,"KEY_MODE",tolua_get_KEY_MODE,NULL);
 tolua_variable(tolua_S,"KEY_MUTE",tolua_get_KEY_MUTE,NULL);
 tolua_variable(tolua_S,"KEY_OPER",tolua_get_KEY_OPER,NULL);
 tolua_variable(tolua_S,"KEY_OUT",tolua_get_KEY_OUT,NULL);
 tolua_variable(tolua_S,"KEY_PASTE",tolua_get_KEY_PASTE,NULL);
 tolua_variable(tolua_S,"KEY_PERCENT",tolua_get_KEY_PERCENT,NULL);
 tolua_variable(tolua_S,"KEY_PERIOD",tolua_get_KEY_PERIOD,NULL);
 tolua_variable(tolua_S,"KEY_PLUS",tolua_get_KEY_PLUS,NULL);
 tolua_variable(tolua_S,"KEY_POWER",tolua_get_KEY_POWER,NULL);
 tolua_variable(tolua_S,"KEY_PRIOR",tolua_get_KEY_PRIOR,NULL);
 tolua_variable(tolua_S,"KEY_QUESTION",tolua_get_KEY_QUESTION,NULL);
 tolua_variable(tolua_S,"KEY_QUOTE",tolua_get_KEY_QUOTE,NULL);
 tolua_variable(tolua_S,"KEY_QUOTEDBL",tolua_get_KEY_QUOTEDBL,NULL);
 tolua_variable(tolua_S,"KEY_RIGHTBRACKET",tolua_get_KEY_RIGHTBRACKET,NULL);
 tolua_variable(tolua_S,"KEY_RIGHTPAREN",tolua_get_KEY_RIGHTPAREN,NULL);
 tolua_variable(tolua_S,"KEY_SEMICOLON",tolua_get_KEY_SEMICOLON,NULL);
 tolua_variable(tolua_S,"KEY_SEPARATOR",tolua_get_KEY_SEPARATOR,NULL);
 tolua_variable(tolua_S,"KEY_SLASH",tolua_get_KEY_SLASH,NULL);
 tolua_variable(tolua_S,"KEY_SLEEP",tolua_get_KEY_SLEEP,NULL);
 tolua_variable(tolua_S,"KEY_STOP",tolua_get_KEY_STOP,NULL);
 tolua_variable(tolua_S,"KEY_SYSREQ",tolua_get_KEY_SYSREQ,NULL);
 tolua_variable(tolua_S,"KEY_THOUSANDSSEPARATOR",tolua_get_KEY_THOUSANDSSEPARATOR,NULL);
 tolua_variable(tolua_S,"KEY_UNDERSCORE",tolua_get_KEY_UNDERSCORE,NULL);
 tolua_variable(tolua_S,"KEY_UNDO",tolua_get_KEY_UNDO,NULL);
 tolua_variable(tolua_S,"KEY_VOLUMEDOWN",tolua_get_KEY_VOLUMEDOWN,NULL);
 tolua_variable(tolua_S,"KEY_VOLUMEUP",tolua_get_KEY_VOLUMEUP,NULL);
 tolua_variable(tolua_S,"KEY_WWW",tolua_get_KEY_WWW,NULL);
 tolua_variable(tolua_S,"SCANCODE_UNKNOWN",tolua_get_SCANCODE_UNKNOWN,NULL);
 tolua_variable(tolua_S,"SCANCODE_CTRL",tolua_get_SCANCODE_CTRL,NULL);
 tolua_variable(tolua_S,"SCANCODE_SHIFT",tolua_get_SCANCODE_SHIFT,NULL);
 tolua_variable(tolua_S,"SCANCODE_ALT",tolua_get_SCANCODE_ALT,NULL);
 tolua_variable(tolua_S,"SCANCODE_GUI",tolua_get_SCANCODE_GUI,NULL);
 tolua_variable(tolua_S,"SCANCODE_A",tolua_get_SCANCODE_A,NULL);
 tolua_variable(tolua_S,"SCANCODE_B",tolua_get_SCANCODE_B,NULL);
 tolua_variable(tolua_S,"SCANCODE_C",tolua_get_SCANCODE_C,NULL);
 tolua_variable(tolua_S,"SCANCODE_D",tolua_get_SCANCODE_D,NULL);
 tolua_variable(tolua_S,"SCANCODE_E",tolua_get_SCANCODE_E,NULL);
 tolua_variable(tolua_S,"SCANCODE_F",tolua_get_SCANCODE_F,NULL);
 tolua_variable(tolua_S,"SCANCODE_G",tolua_get_SCANCODE_G,NULL);
 tolua_variable(tolua_S,"SCANCODE_H",tolua_get_SCANCODE_H,NULL);
 tolua_variable(tolua_S,"SCANCODE_I",tolua_get_SCANCODE_I,NULL);
 tolua_variable(tolua_S,"SCANCODE_J",tolua_get_SCANCODE_J,NULL);
 tolua_variable(tolua_S,"SCANCODE_K",tolua_get_SCANCODE_K,NULL);
 tolua_variable(tolua_S,"SCANCODE_L",tolua_get_SCANCODE_L,NULL);
 tolua_variable(tolua_S,"SCANCODE_M",tolua_get_SCANCODE_M,NULL);
 tolua_variable(tolua_S,"SCANCODE_N",tolua_get_SCANCODE_N,NULL);
 tolua_variable(tolua_S,"SCANCODE_O",tolua_get_SCANCODE_O,NULL);
 tolua_variable(tolua_S,"SCANCODE_P",tolua_get_SCANCODE_P,NULL);
 tolua_variable(tolua_S,"SCANCODE_Q",tolua_get_SCANCODE_Q,NULL);
 tolua_variable(tolua_S,"SCANCODE_R",tolua_get_SCANCODE_R,NULL);
 tolua_variable(tolua_S,"SCANCODE_S",tolua_get_SCANCODE_S,NULL);
 tolua_variable(tolua_S,"SCANCODE_T",tolua_get_SCANCODE_T,NULL);
 tolua_variable(tolua_S,"SCANCODE_U",tolua_get_SCANCODE_U,NULL);
 tolua_variable(tolua_S,"SCANCODE_V",tolua_get_SCANCODE_V,NULL);
 tolua_variable(tolua_S,"SCANCODE_W",tolua_get_SCANCODE_W,NULL);
 tolua_variable(tolua_S,"SCANCODE_X",tolua_get_SCANCODE_X,NULL);
 tolua_variable(tolua_S,"SCANCODE_Y",tolua_get_SCANCODE_Y,NULL);
 tolua_variable(tolua_S,"SCANCODE_Z",tolua_get_SCANCODE_Z,NULL);
 tolua_variable(tolua_S,"SCANCODE_1",tolua_get_SCANCODE_1,NULL);
 tolua_variable(tolua_S,"SCANCODE_2",tolua_get_SCANCODE_2,NULL);
 tolua_variable(tolua_S,"SCANCODE_3",tolua_get_SCANCODE_3,NULL);
 tolua_variable(tolua_S,"SCANCODE_4",tolua_get_SCANCODE_4,NULL);
 tolua_variable(tolua_S,"SCANCODE_5",tolua_get_SCANCODE_5,NULL);
 tolua_variable(tolua_S,"SCANCODE_6",tolua_get_SCANCODE_6,NULL);
 tolua_variable(tolua_S,"SCANCODE_7",tolua_get_SCANCODE_7,NULL);
 tolua_variable(tolua_S,"SCANCODE_8",tolua_get_SCANCODE_8,NULL);
 tolua_variable(tolua_S,"SCANCODE_9",tolua_get_SCANCODE_9,NULL);
 tolua_variable(tolua_S,"SCANCODE_0",tolua_get_SCANCODE_0,NULL);
 tolua_variable(tolua_S,"SCANCODE_RETURN",tolua_get_SCANCODE_RETURN,NULL);
 tolua_variable(tolua_S,"SCANCODE_ESCAPE",tolua_get_SCANCODE_ESCAPE,NULL);
 tolua_variable(tolua_S,"SCANCODE_BACKSPACE",tolua_get_SCANCODE_BACKSPACE,NULL);
 tolua_variable(tolua_S,"SCANCODE_TAB",tolua_get_SCANCODE_TAB,NULL);
 tolua_variable(tolua_S,"SCANCODE_SPACE",tolua_get_SCANCODE_SPACE,NULL);
 tolua_variable(tolua_S,"SCANCODE_MINUS",tolua_get_SCANCODE_MINUS,NULL);
 tolua_variable(tolua_S,"SCANCODE_EQUALS",tolua_get_SCANCODE_EQUALS,NULL);
 tolua_variable(tolua_S,"SCANCODE_LEFTBRACKET",tolua_get_SCANCODE_LEFTBRACKET,NULL);
 tolua_variable(tolua_S,"SCANCODE_RIGHTBRACKET",tolua_get_SCANCODE_RIGHTBRACKET,NULL);
 tolua_variable(tolua_S,"SCANCODE_BACKSLASH",tolua_get_SCANCODE_BACKSLASH,NULL);
 tolua_variable(tolua_S,"SCANCODE_NONUSHASH",tolua_get_SCANCODE_NONUSHASH,NULL);
 tolua_variable(tolua_S,"SCANCODE_SEMICOLON",tolua_get_SCANCODE_SEMICOLON,NULL);
 tolua_variable(tolua_S,"SCANCODE_APOSTROPHE",tolua_get_SCANCODE_APOSTROPHE,NULL);
 tolua_variable(tolua_S,"SCANCODE_GRAVE",tolua_get_SCANCODE_GRAVE,NULL);
 tolua_variable(tolua_S,"SCANCODE_COMMA",tolua_get_SCANCODE_COMMA,NULL);
 tolua_variable(tolua_S,"SCANCODE_PERIOD",tolua_get_SCANCODE_PERIOD,NULL);
 tolua_variable(tolua_S,"SCANCODE_SLASH",tolua_get_SCANCODE_SLASH,NULL);
 tolua_variable(tolua_S,"SCANCODE_CAPSLOCK",tolua_get_SCANCODE_CAPSLOCK,NULL);
 tolua_variable(tolua_S,"SCANCODE_F1",tolua_get_SCANCODE_F1,NULL);
 tolua_variable(tolua_S,"SCANCODE_F2",tolua_get_SCANCODE_F2,NULL);
 tolua_variable(tolua_S,"SCANCODE_F3",tolua_get_SCANCODE_F3,NULL);
 tolua_variable(tolua_S,"SCANCODE_F4",tolua_get_SCANCODE_F4,NULL);
 tolua_variable(tolua_S,"SCANCODE_F5",tolua_get_SCANCODE_F5,NULL);
 tolua_variable(tolua_S,"SCANCODE_F6",tolua_get_SCANCODE_F6,NULL);
 tolua_variable(tolua_S,"SCANCODE_F7",tolua_get_SCANCODE_F7,NULL);
 tolua_variable(tolua_S,"SCANCODE_F8",tolua_get_SCANCODE_F8,NULL);
 tolua_variable(tolua_S,"SCANCODE_F9",tolua_get_SCANCODE_F9,NULL);
 tolua_variable(tolua_S,"SCANCODE_F10",tolua_get_SCANCODE_F10,NULL);
 tolua_variable(tolua_S,"SCANCODE_F11",tolua_get_SCANCODE_F11,NULL);
 tolua_variable(tolua_S,"SCANCODE_F12",tolua_get_SCANCODE_F12,NULL);
 tolua_variable(tolua_S,"SCANCODE_PRINTSCREEN",tolua_get_SCANCODE_PRINTSCREEN,NULL);
 tolua_variable(tolua_S,"SCANCODE_SCROLLLOCK",tolua_get_SCANCODE_SCROLLLOCK,NULL);
 tolua_variable(tolua_S,"SCANCODE_PAUSE",tolua_get_SCANCODE_PAUSE,NULL);
 tolua_variable(tolua_S,"SCANCODE_INSERT",tolua_get_SCANCODE_INSERT,NULL);
 tolua_variable(tolua_S,"SCANCODE_HOME",tolua_get_SCANCODE_HOME,NULL);
 tolua_variable(tolua_S,"SCANCODE_PAGEUP",tolua_get_SCANCODE_PAGEUP,NULL);
 tolua_variable(tolua_S,"SCANCODE_DELETE",tolua_get_SCANCODE_DELETE,NULL);
 tolua_variable(tolua_S,"SCANCODE_END",tolua_get_SCANCODE_END,NULL);
 tolua_variable(tolua_S,"SCANCODE_PAGEDOWN",tolua_get_SCANCODE_PAGEDOWN,NULL);
 tolua_variable(tolua_S,"SCANCODE_RIGHT",tolua_get_SCANCODE_RIGHT,NULL);
 tolua_variable(tolua_S,"SCANCODE_LEFT",tolua_get_SCANCODE_LEFT,NULL);
 tolua_variable(tolua_S,"SCANCODE_DOWN",tolua_get_SCANCODE_DOWN,NULL);
 tolua_variable(tolua_S,"SCANCODE_UP",tolua_get_SCANCODE_UP,NULL);
 tolua_variable(tolua_S,"SCANCODE_NUMLOCKCLEAR",tolua_get_SCANCODE_NUMLOCKCLEAR,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_DIVIDE",tolua_get_SCANCODE_KP_DIVIDE,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_MULTIPLY",tolua_get_SCANCODE_KP_MULTIPLY,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_MINUS",tolua_get_SCANCODE_KP_MINUS,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_PLUS",tolua_get_SCANCODE_KP_PLUS,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_ENTER",tolua_get_SCANCODE_KP_ENTER,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_1",tolua_get_SCANCODE_KP_1,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_2",tolua_get_SCANCODE_KP_2,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_3",tolua_get_SCANCODE_KP_3,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_4",tolua_get_SCANCODE_KP_4,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_5",tolua_get_SCANCODE_KP_5,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_6",tolua_get_SCANCODE_KP_6,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_7",tolua_get_SCANCODE_KP_7,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_8",tolua_get_SCANCODE_KP_8,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_9",tolua_get_SCANCODE_KP_9,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_0",tolua_get_SCANCODE_KP_0,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_PERIOD",tolua_get_SCANCODE_KP_PERIOD,NULL);
 tolua_variable(tolua_S,"SCANCODE_NONUSBACKSLASH",tolua_get_SCANCODE_NONUSBACKSLASH,NULL);
 tolua_variable(tolua_S,"SCANCODE_APPLICATION",tolua_get_SCANCODE_APPLICATION,NULL);
 tolua_variable(tolua_S,"SCANCODE_POWER",tolua_get_SCANCODE_POWER,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_EQUALS",tolua_get_SCANCODE_KP_EQUALS,NULL);
 tolua_variable(tolua_S,"SCANCODE_F13",tolua_get_SCANCODE_F13,NULL);
 tolua_variable(tolua_S,"SCANCODE_F14",tolua_get_SCANCODE_F14,NULL);
 tolua_variable(tolua_S,"SCANCODE_F15",tolua_get_SCANCODE_F15,NULL);
 tolua_variable(tolua_S,"SCANCODE_F16",tolua_get_SCANCODE_F16,NULL);
 tolua_variable(tolua_S,"SCANCODE_F17",tolua_get_SCANCODE_F17,NULL);
 tolua_variable(tolua_S,"SCANCODE_F18",tolua_get_SCANCODE_F18,NULL);
 tolua_variable(tolua_S,"SCANCODE_F19",tolua_get_SCANCODE_F19,NULL);
 tolua_variable(tolua_S,"SCANCODE_F20",tolua_get_SCANCODE_F20,NULL);
 tolua_variable(tolua_S,"SCANCODE_F21",tolua_get_SCANCODE_F21,NULL);
 tolua_variable(tolua_S,"SCANCODE_F22",tolua_get_SCANCODE_F22,NULL);
 tolua_variable(tolua_S,"SCANCODE_F23",tolua_get_SCANCODE_F23,NULL);
 tolua_variable(tolua_S,"SCANCODE_F24",tolua_get_SCANCODE_F24,NULL);
 tolua_variable(tolua_S,"SCANCODE_EXECUTE",tolua_get_SCANCODE_EXECUTE,NULL);
 tolua_variable(tolua_S,"SCANCODE_HELP",tolua_get_SCANCODE_HELP,NULL);
 tolua_variable(tolua_S,"SCANCODE_MENU",tolua_get_SCANCODE_MENU,NULL);
 tolua_variable(tolua_S,"SCANCODE_SELECT",tolua_get_SCANCODE_SELECT,NULL);
 tolua_variable(tolua_S,"SCANCODE_STOP",tolua_get_SCANCODE_STOP,NULL);
 tolua_variable(tolua_S,"SCANCODE_AGAIN",tolua_get_SCANCODE_AGAIN,NULL);
 tolua_variable(tolua_S,"SCANCODE_UNDO",tolua_get_SCANCODE_UNDO,NULL);
 tolua_variable(tolua_S,"SCANCODE_CUT",tolua_get_SCANCODE_CUT,NULL);
 tolua_variable(tolua_S,"SCANCODE_COPY",tolua_get_SCANCODE_COPY,NULL);
 tolua_variable(tolua_S,"SCANCODE_PASTE",tolua_get_SCANCODE_PASTE,NULL);
 tolua_variable(tolua_S,"SCANCODE_FIND",tolua_get_SCANCODE_FIND,NULL);
 tolua_variable(tolua_S,"SCANCODE_MUTE",tolua_get_SCANCODE_MUTE,NULL);
 tolua_variable(tolua_S,"SCANCODE_VOLUMEUP",tolua_get_SCANCODE_VOLUMEUP,NULL);
 tolua_variable(tolua_S,"SCANCODE_VOLUMEDOWN",tolua_get_SCANCODE_VOLUMEDOWN,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_COMMA",tolua_get_SCANCODE_KP_COMMA,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_EQUALSAS400",tolua_get_SCANCODE_KP_EQUALSAS400,NULL);
 tolua_variable(tolua_S,"SCANCODE_INTERNATIONAL1",tolua_get_SCANCODE_INTERNATIONAL1,NULL);
 tolua_variable(tolua_S,"SCANCODE_INTERNATIONAL2",tolua_get_SCANCODE_INTERNATIONAL2,NULL);
 tolua_variable(tolua_S,"SCANCODE_INTERNATIONAL3",tolua_get_SCANCODE_INTERNATIONAL3,NULL);
 tolua_variable(tolua_S,"SCANCODE_INTERNATIONAL4",tolua_get_SCANCODE_INTERNATIONAL4,NULL);
 tolua_variable(tolua_S,"SCANCODE_INTERNATIONAL5",tolua_get_SCANCODE_INTERNATIONAL5,NULL);
 tolua_variable(tolua_S,"SCANCODE_INTERNATIONAL6",tolua_get_SCANCODE_INTERNATIONAL6,NULL);
 tolua_variable(tolua_S,"SCANCODE_INTERNATIONAL7",tolua_get_SCANCODE_INTERNATIONAL7,NULL);
 tolua_variable(tolua_S,"SCANCODE_INTERNATIONAL8",tolua_get_SCANCODE_INTERNATIONAL8,NULL);
 tolua_variable(tolua_S,"SCANCODE_INTERNATIONAL9",tolua_get_SCANCODE_INTERNATIONAL9,NULL);
 tolua_variable(tolua_S,"SCANCODE_LANG1",tolua_get_SCANCODE_LANG1,NULL);
 tolua_variable(tolua_S,"SCANCODE_LANG2",tolua_get_SCANCODE_LANG2,NULL);
 tolua_variable(tolua_S,"SCANCODE_LANG3",tolua_get_SCANCODE_LANG3,NULL);
 tolua_variable(tolua_S,"SCANCODE_LANG4",tolua_get_SCANCODE_LANG4,NULL);
 tolua_variable(tolua_S,"SCANCODE_LANG5",tolua_get_SCANCODE_LANG5,NULL);
 tolua_variable(tolua_S,"SCANCODE_LANG6",tolua_get_SCANCODE_LANG6,NULL);
 tolua_variable(tolua_S,"SCANCODE_LANG7",tolua_get_SCANCODE_LANG7,NULL);
 tolua_variable(tolua_S,"SCANCODE_LANG8",tolua_get_SCANCODE_LANG8,NULL);
 tolua_variable(tolua_S,"SCANCODE_LANG9",tolua_get_SCANCODE_LANG9,NULL);
 tolua_variable(tolua_S,"SCANCODE_ALTERASE",tolua_get_SCANCODE_ALTERASE,NULL);
 tolua_variable(tolua_S,"SCANCODE_SYSREQ",tolua_get_SCANCODE_SYSREQ,NULL);
 tolua_variable(tolua_S,"SCANCODE_CANCEL",tolua_get_SCANCODE_CANCEL,NULL);
 tolua_variable(tolua_S,"SCANCODE_CLEAR",tolua_get_SCANCODE_CLEAR,NULL);
 tolua_variable(tolua_S,"SCANCODE_PRIOR",tolua_get_SCANCODE_PRIOR,NULL);
 tolua_variable(tolua_S,"SCANCODE_RETURN2",tolua_get_SCANCODE_RETURN2,NULL);
 tolua_variable(tolua_S,"SCANCODE_SEPARATOR",tolua_get_SCANCODE_SEPARATOR,NULL);
 tolua_variable(tolua_S,"SCANCODE_OUT",tolua_get_SCANCODE_OUT,NULL);
 tolua_variable(tolua_S,"SCANCODE_OPER",tolua_get_SCANCODE_OPER,NULL);
 tolua_variable(tolua_S,"SCANCODE_CLEARAGAIN",tolua_get_SCANCODE_CLEARAGAIN,NULL);
 tolua_variable(tolua_S,"SCANCODE_CRSEL",tolua_get_SCANCODE_CRSEL,NULL);
 tolua_variable(tolua_S,"SCANCODE_EXSEL",tolua_get_SCANCODE_EXSEL,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_00",tolua_get_SCANCODE_KP_00,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_000",tolua_get_SCANCODE_KP_000,NULL);
 tolua_variable(tolua_S,"SCANCODE_THOUSANDSSEPARATOR",tolua_get_SCANCODE_THOUSANDSSEPARATOR,NULL);
 tolua_variable(tolua_S,"SCANCODE_DECIMALSEPARATOR",tolua_get_SCANCODE_DECIMALSEPARATOR,NULL);
 tolua_variable(tolua_S,"SCANCODE_CURRENCYUNIT",tolua_get_SCANCODE_CURRENCYUNIT,NULL);
 tolua_variable(tolua_S,"SCANCODE_CURRENCYSUBUNIT",tolua_get_SCANCODE_CURRENCYSUBUNIT,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_LEFTPAREN",tolua_get_SCANCODE_KP_LEFTPAREN,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_RIGHTPAREN",tolua_get_SCANCODE_KP_RIGHTPAREN,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_LEFTBRACE",tolua_get_SCANCODE_KP_LEFTBRACE,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_RIGHTBRACE",tolua_get_SCANCODE_KP_RIGHTBRACE,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_TAB",tolua_get_SCANCODE_KP_TAB,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_BACKSPACE",tolua_get_SCANCODE_KP_BACKSPACE,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_A",tolua_get_SCANCODE_KP_A,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_B",tolua_get_SCANCODE_KP_B,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_C",tolua_get_SCANCODE_KP_C,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_D",tolua_get_SCANCODE_KP_D,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_E",tolua_get_SCANCODE_KP_E,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_F",tolua_get_SCANCODE_KP_F,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_XOR",tolua_get_SCANCODE_KP_XOR,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_POWER",tolua_get_SCANCODE_KP_POWER,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_PERCENT",tolua_get_SCANCODE_KP_PERCENT,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_LESS",tolua_get_SCANCODE_KP_LESS,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_GREATER",tolua_get_SCANCODE_KP_GREATER,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_AMPERSAND",tolua_get_SCANCODE_KP_AMPERSAND,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_DBLAMPERSAND",tolua_get_SCANCODE_KP_DBLAMPERSAND,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_VERTICALBAR",tolua_get_SCANCODE_KP_VERTICALBAR,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_DBLVERTICALBAR",tolua_get_SCANCODE_KP_DBLVERTICALBAR,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_COLON",tolua_get_SCANCODE_KP_COLON,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_HASH",tolua_get_SCANCODE_KP_HASH,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_SPACE",tolua_get_SCANCODE_KP_SPACE,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_AT",tolua_get_SCANCODE_KP_AT,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_EXCLAM",tolua_get_SCANCODE_KP_EXCLAM,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_MEMSTORE",tolua_get_SCANCODE_KP_MEMSTORE,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_MEMRECALL",tolua_get_SCANCODE_KP_MEMRECALL,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_MEMCLEAR",tolua_get_SCANCODE_KP_MEMCLEAR,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_MEMADD",tolua_get_SCANCODE_KP_MEMADD,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_MEMSUBTRACT",tolua_get_SCANCODE_KP_MEMSUBTRACT,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_MEMMULTIPLY",tolua_get_SCANCODE_KP_MEMMULTIPLY,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_MEMDIVIDE",tolua_get_SCANCODE_KP_MEMDIVIDE,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_PLUSMINUS",tolua_get_SCANCODE_KP_PLUSMINUS,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_CLEAR",tolua_get_SCANCODE_KP_CLEAR,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_CLEARENTRY",tolua_get_SCANCODE_KP_CLEARENTRY,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_BINARY",tolua_get_SCANCODE_KP_BINARY,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_OCTAL",tolua_get_SCANCODE_KP_OCTAL,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_DECIMAL",tolua_get_SCANCODE_KP_DECIMAL,NULL);
 tolua_variable(tolua_S,"SCANCODE_KP_HEXADECIMAL",tolua_get_SCANCODE_KP_HEXADECIMAL,NULL);
 tolua_variable(tolua_S,"SCANCODE_LCTRL",tolua_get_SCANCODE_LCTRL,NULL);
 tolua_variable(tolua_S,"SCANCODE_LSHIFT",tolua_get_SCANCODE_LSHIFT,NULL);
 tolua_variable(tolua_S,"SCANCODE_LALT",tolua_get_SCANCODE_LALT,NULL);
 tolua_variable(tolua_S,"SCANCODE_LGUI",tolua_get_SCANCODE_LGUI,NULL);
 tolua_variable(tolua_S,"SCANCODE_RCTRL",tolua_get_SCANCODE_RCTRL,NULL);
 tolua_variable(tolua_S,"SCANCODE_RSHIFT",tolua_get_SCANCODE_RSHIFT,NULL);
 tolua_variable(tolua_S,"SCANCODE_RALT",tolua_get_SCANCODE_RALT,NULL);
 tolua_variable(tolua_S,"SCANCODE_RGUI",tolua_get_SCANCODE_RGUI,NULL);
 tolua_variable(tolua_S,"SCANCODE_MODE",tolua_get_SCANCODE_MODE,NULL);
 tolua_variable(tolua_S,"SCANCODE_AUDIONEXT",tolua_get_SCANCODE_AUDIONEXT,NULL);
 tolua_variable(tolua_S,"SCANCODE_AUDIOPREV",tolua_get_SCANCODE_AUDIOPREV,NULL);
 tolua_variable(tolua_S,"SCANCODE_AUDIOSTOP",tolua_get_SCANCODE_AUDIOSTOP,NULL);
 tolua_variable(tolua_S,"SCANCODE_AUDIOPLAY",tolua_get_SCANCODE_AUDIOPLAY,NULL);
 tolua_variable(tolua_S,"SCANCODE_AUDIOMUTE",tolua_get_SCANCODE_AUDIOMUTE,NULL);
 tolua_variable(tolua_S,"SCANCODE_MEDIASELECT",tolua_get_SCANCODE_MEDIASELECT,NULL);
 tolua_variable(tolua_S,"SCANCODE_WWW",tolua_get_SCANCODE_WWW,NULL);
 tolua_variable(tolua_S,"SCANCODE_MAIL",tolua_get_SCANCODE_MAIL,NULL);
 tolua_variable(tolua_S,"SCANCODE_CALCULATOR",tolua_get_SCANCODE_CALCULATOR,NULL);
 tolua_variable(tolua_S,"SCANCODE_COMPUTER",tolua_get_SCANCODE_COMPUTER,NULL);
 tolua_variable(tolua_S,"SCANCODE_AC_SEARCH",tolua_get_SCANCODE_AC_SEARCH,NULL);
 tolua_variable(tolua_S,"SCANCODE_AC_HOME",tolua_get_SCANCODE_AC_HOME,NULL);
 tolua_variable(tolua_S,"SCANCODE_AC_BACK",tolua_get_SCANCODE_AC_BACK,NULL);
 tolua_variable(tolua_S,"SCANCODE_AC_FORWARD",tolua_get_SCANCODE_AC_FORWARD,NULL);
 tolua_variable(tolua_S,"SCANCODE_AC_STOP",tolua_get_SCANCODE_AC_STOP,NULL);
 tolua_variable(tolua_S,"SCANCODE_AC_REFRESH",tolua_get_SCANCODE_AC_REFRESH,NULL);
 tolua_variable(tolua_S,"SCANCODE_AC_BOOKMARKS",tolua_get_SCANCODE_AC_BOOKMARKS,NULL);
 tolua_variable(tolua_S,"SCANCODE_BRIGHTNESSDOWN",tolua_get_SCANCODE_BRIGHTNESSDOWN,NULL);
 tolua_variable(tolua_S,"SCANCODE_BRIGHTNESSUP",tolua_get_SCANCODE_BRIGHTNESSUP,NULL);
 tolua_variable(tolua_S,"SCANCODE_DISPLAYSWITCH",tolua_get_SCANCODE_DISPLAYSWITCH,NULL);
 tolua_variable(tolua_S,"SCANCODE_KBDILLUMTOGGLE",tolua_get_SCANCODE_KBDILLUMTOGGLE,NULL);
 tolua_variable(tolua_S,"SCANCODE_KBDILLUMDOWN",tolua_get_SCANCODE_KBDILLUMDOWN,NULL);
 tolua_variable(tolua_S,"SCANCODE_KBDILLUMUP",tolua_get_SCANCODE_KBDILLUMUP,NULL);
 tolua_variable(tolua_S,"SCANCODE_EJECT",tolua_get_SCANCODE_EJECT,NULL);
 tolua_variable(tolua_S,"SCANCODE_SLEEP",tolua_get_SCANCODE_SLEEP,NULL);
 tolua_variable(tolua_S,"SCANCODE_APP1",tolua_get_SCANCODE_APP1,NULL);
 tolua_variable(tolua_S,"SCANCODE_APP2",tolua_get_SCANCODE_APP2,NULL);
 tolua_variable(tolua_S,"HAT_CENTER",tolua_get_HAT_CENTER,NULL);
 tolua_variable(tolua_S,"HAT_UP",tolua_get_HAT_UP,NULL);
 tolua_variable(tolua_S,"HAT_RIGHT",tolua_get_HAT_RIGHT,NULL);
 tolua_variable(tolua_S,"HAT_DOWN",tolua_get_HAT_DOWN,NULL);
 tolua_variable(tolua_S,"HAT_LEFT",tolua_get_HAT_LEFT,NULL);
 tolua_variable(tolua_S,"CONTROLLER_BUTTON_A",tolua_get_CONTROLLER_BUTTON_A,NULL);
 tolua_variable(tolua_S,"CONTROLLER_BUTTON_B",tolua_get_CONTROLLER_BUTTON_B,NULL);
 tolua_variable(tolua_S,"CONTROLLER_BUTTON_X",tolua_get_CONTROLLER_BUTTON_X,NULL);
 tolua_variable(tolua_S,"CONTROLLER_BUTTON_Y",tolua_get_CONTROLLER_BUTTON_Y,NULL);
 tolua_variable(tolua_S,"CONTROLLER_BUTTON_BACK",tolua_get_CONTROLLER_BUTTON_BACK,NULL);
 tolua_variable(tolua_S,"CONTROLLER_BUTTON_GUIDE",tolua_get_CONTROLLER_BUTTON_GUIDE,NULL);
 tolua_variable(tolua_S,"CONTROLLER_BUTTON_START",tolua_get_CONTROLLER_BUTTON_START,NULL);
 tolua_variable(tolua_S,"CONTROLLER_BUTTON_LEFTSTICK",tolua_get_CONTROLLER_BUTTON_LEFTSTICK,NULL);
 tolua_variable(tolua_S,"CONTROLLER_BUTTON_RIGHTSTICK",tolua_get_CONTROLLER_BUTTON_RIGHTSTICK,NULL);
 tolua_variable(tolua_S,"CONTROLLER_BUTTON_LEFTSHOULDER",tolua_get_CONTROLLER_BUTTON_LEFTSHOULDER,NULL);
 tolua_variable(tolua_S,"CONTROLLER_BUTTON_RIGHTSHOULDER",tolua_get_CONTROLLER_BUTTON_RIGHTSHOULDER,NULL);
 tolua_variable(tolua_S,"CONTROLLER_BUTTON_DPAD_UP",tolua_get_CONTROLLER_BUTTON_DPAD_UP,NULL);
 tolua_variable(tolua_S,"CONTROLLER_BUTTON_DPAD_DOWN",tolua_get_CONTROLLER_BUTTON_DPAD_DOWN,NULL);
 tolua_variable(tolua_S,"CONTROLLER_BUTTON_DPAD_LEFT",tolua_get_CONTROLLER_BUTTON_DPAD_LEFT,NULL);
 tolua_variable(tolua_S,"CONTROLLER_BUTTON_DPAD_RIGHT",tolua_get_CONTROLLER_BUTTON_DPAD_RIGHT,NULL);
 tolua_variable(tolua_S,"CONTROLLER_AXIS_LEFTX",tolua_get_CONTROLLER_AXIS_LEFTX,NULL);
 tolua_variable(tolua_S,"CONTROLLER_AXIS_LEFTY",tolua_get_CONTROLLER_AXIS_LEFTY,NULL);
 tolua_variable(tolua_S,"CONTROLLER_AXIS_RIGHTX",tolua_get_CONTROLLER_AXIS_RIGHTX,NULL);
 tolua_variable(tolua_S,"CONTROLLER_AXIS_RIGHTY",tolua_get_CONTROLLER_AXIS_RIGHTY,NULL);
 tolua_variable(tolua_S,"CONTROLLER_AXIS_TRIGGERLEFT",tolua_get_CONTROLLER_AXIS_TRIGGERLEFT,NULL);
 tolua_variable(tolua_S,"CONTROLLER_AXIS_TRIGGERRIGHT",tolua_get_CONTROLLER_AXIS_TRIGGERRIGHT,NULL);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_InputLuaAPI (lua_State* tolua_S) {
 return tolua_InputLuaAPI_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif