/*
** Lua binding: EngineLuaAPI
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
TOLUA_API int tolua_EngineLuaAPI_open (lua_State* tolua_S);

#include "Engine/Console.h"
#include "Engine/DebugHud.h"
#include "Engine/Engine.h"
using namespace Urho3D;
#pragma warning(disable:4800)

#define TOLUA_DISABLE_tolua_EngineLuaAPI_GetConsole00
static int tolua_EngineLuaAPI_GetConsole00(lua_State* tolua_S)
{
    return ToluaGetSubsystem<Console>(tolua_S);
}

#define TOLUA_DISABLE_tolua_get_console_ptr
#define tolua_get_console_ptr tolua_EngineLuaAPI_GetConsole00

#define TOLUA_DISABLE_tolua_EngineLuaAPI_GetDebugHud00
static int tolua_EngineLuaAPI_GetDebugHud00(lua_State* tolua_S)
{
    return ToluaGetSubsystem<DebugHud>(tolua_S);
}

#define TOLUA_DISABLE_tolua_get_debugHud_ptr
#define tolua_get_debugHud_ptr tolua_EngineLuaAPI_GetDebugHud00

#define TOLUA_DISABLE_tolua_EngineLuaAPI_GetEngine00
static int tolua_EngineLuaAPI_GetEngine00(lua_State* tolua_S)
{
    return ToluaGetSubsystem<Engine>(tolua_S);
}

#define TOLUA_DISABLE_tolua_get_engine_ptr
#define tolua_get_engine_ptr tolua_EngineLuaAPI_GetEngine00

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"DebugHud");
 tolua_usertype(tolua_S,"XMLFile");
 tolua_usertype(tolua_S,"Text");
 tolua_usertype(tolua_S,"Engine");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"Variant");
 tolua_usertype(tolua_S,"Button");
 tolua_usertype(tolua_S,"Console");
 tolua_usertype(tolua_S,"LineEdit");
 tolua_usertype(tolua_S,"BorderImage");
}

/* method: SetDefaultStyle of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_SetDefaultStyle00
static int tolua_EngineLuaAPI_Console_SetDefaultStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Console",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"XMLFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
  XMLFile* style = ((XMLFile*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDefaultStyle'", NULL);
#endif
 {
  self->SetDefaultStyle(style);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDefaultStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisible of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_SetVisible00
static int tolua_EngineLuaAPI_Console_SetVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Console",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisible'", NULL);
#endif
 {
  self->SetVisible(enable);
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

/* method: Toggle of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_Toggle00
static int tolua_EngineLuaAPI_Console_Toggle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Console",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Toggle'", NULL);
#endif
 {
  self->Toggle();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Toggle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAutoVisibleOnError of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_SetAutoVisibleOnError00
static int tolua_EngineLuaAPI_Console_SetAutoVisibleOnError00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Console",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAutoVisibleOnError'", NULL);
#endif
 {
  self->SetAutoVisibleOnError(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAutoVisibleOnError'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCommandInterpreter of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_SetCommandInterpreter00
static int tolua_EngineLuaAPI_Console_SetCommandInterpreter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Console",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
  const String interpreter = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCommandInterpreter'", NULL);
#endif
 {
  self->SetCommandInterpreter(interpreter);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCommandInterpreter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetNumBufferedRows of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_SetNumBufferedRows00
static int tolua_EngineLuaAPI_Console_SetNumBufferedRows00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Console",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
  unsigned rows = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNumBufferedRows'", NULL);
#endif
 {
  self->SetNumBufferedRows(rows);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNumBufferedRows'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetNumRows of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_SetNumRows00
static int tolua_EngineLuaAPI_Console_SetNumRows00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Console",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
  unsigned rows = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNumRows'", NULL);
#endif
 {
  self->SetNumRows(rows);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNumRows'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetNumHistoryRows of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_SetNumHistoryRows00
static int tolua_EngineLuaAPI_Console_SetNumHistoryRows00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Console",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
  unsigned rows = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNumHistoryRows'", NULL);
#endif
 {
  self->SetNumHistoryRows(rows);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNumHistoryRows'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFocusOnShow of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_SetFocusOnShow00
static int tolua_EngineLuaAPI_Console_SetFocusOnShow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Console",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFocusOnShow'", NULL);
#endif
 {
  self->SetFocusOnShow(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFocusOnShow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddAutoComplete of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_AddAutoComplete00
static int tolua_EngineLuaAPI_Console_AddAutoComplete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Console",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
  const String option = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddAutoComplete'", NULL);
#endif
 {
  self->AddAutoComplete(option);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddAutoComplete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAutoComplete of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_RemoveAutoComplete00
static int tolua_EngineLuaAPI_Console_RemoveAutoComplete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Console",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
  const String option = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAutoComplete'", NULL);
#endif
 {
  self->RemoveAutoComplete(option);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAutoComplete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateElements of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_UpdateElements00
static int tolua_EngineLuaAPI_Console_UpdateElements00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Console",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UpdateElements'", NULL);
#endif
 {
  self->UpdateElements();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdateElements'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDefaultStyle of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_GetDefaultStyle00
static int tolua_EngineLuaAPI_Console_GetDefaultStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Console",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Console* self = (const Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDefaultStyle'", NULL);
#endif
 {
  XMLFile* tolua_ret = (XMLFile*)  self->GetDefaultStyle();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"XMLFile");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDefaultStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBackground of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_GetBackground00
static int tolua_EngineLuaAPI_Console_GetBackground00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Console",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Console* self = (const Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBackground'", NULL);
#endif
 {
  BorderImage* tolua_ret = (BorderImage*)  self->GetBackground();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BorderImage");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBackground'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLineEdit of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_GetLineEdit00
static int tolua_EngineLuaAPI_Console_GetLineEdit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Console",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Console* self = (const Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLineEdit'", NULL);
#endif
 {
  LineEdit* tolua_ret = (LineEdit*)  self->GetLineEdit();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"LineEdit");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLineEdit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCloseButton of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_GetCloseButton00
static int tolua_EngineLuaAPI_Console_GetCloseButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Console",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Console* self = (const Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCloseButton'", NULL);
#endif
 {
  Button* tolua_ret = (Button*)  self->GetCloseButton();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Button");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCloseButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsVisible of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_IsVisible00
static int tolua_EngineLuaAPI_Console_IsVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Console",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Console* self = (const Console*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsAutoVisibleOnError of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_IsAutoVisibleOnError00
static int tolua_EngineLuaAPI_Console_IsAutoVisibleOnError00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Console",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Console* self = (const Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsAutoVisibleOnError'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsAutoVisibleOnError();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsAutoVisibleOnError'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCommandInterpreter of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_GetCommandInterpreter00
static int tolua_EngineLuaAPI_Console_GetCommandInterpreter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Console",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Console* self = (const Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCommandInterpreter'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetCommandInterpreter();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCommandInterpreter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumBufferedRows of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_GetNumBufferedRows00
static int tolua_EngineLuaAPI_Console_GetNumBufferedRows00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Console",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Console* self = (const Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumBufferedRows'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumBufferedRows();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumBufferedRows'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumRows of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_GetNumRows00
static int tolua_EngineLuaAPI_Console_GetNumRows00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Console",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Console* self = (const Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumRows'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumRows();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumRows'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CopySelectedRows of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_CopySelectedRows00
static int tolua_EngineLuaAPI_Console_CopySelectedRows00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Console",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Console* self = (const Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CopySelectedRows'", NULL);
#endif
 {
  self->CopySelectedRows();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CopySelectedRows'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumHistoryRows of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_GetNumHistoryRows00
static int tolua_EngineLuaAPI_Console_GetNumHistoryRows00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Console",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Console* self = (const Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumHistoryRows'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumHistoryRows();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumHistoryRows'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHistoryPosition of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_GetHistoryPosition00
static int tolua_EngineLuaAPI_Console_GetHistoryPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Console",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Console* self = (const Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHistoryPosition'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetHistoryPosition();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHistoryPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHistoryRow of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_GetHistoryRow00
static int tolua_EngineLuaAPI_Console_GetHistoryRow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Console",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Console* self = (const Console*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHistoryRow'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetHistoryRow(index);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHistoryRow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFocusOnShow of class  Console */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Console_GetFocusOnShow00
static int tolua_EngineLuaAPI_Console_GetFocusOnShow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Console",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Console* self = (const Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFocusOnShow'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetFocusOnShow();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFocusOnShow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: defaultStyle of class  Console */
#ifndef TOLUA_DISABLE_tolua_get_Console_defaultStyle_ptr
static int tolua_get_Console_defaultStyle_ptr(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'defaultStyle'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetDefaultStyle(),"XMLFile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: defaultStyle of class  Console */
#ifndef TOLUA_DISABLE_tolua_set_Console_defaultStyle_ptr
static int tolua_set_Console_defaultStyle_ptr(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'defaultStyle'",NULL);
 if (!tolua_isusertype(tolua_S,2,"XMLFile",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDefaultStyle(((XMLFile*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: background of class  Console */
#ifndef TOLUA_DISABLE_tolua_get_Console_background_ptr
static int tolua_get_Console_background_ptr(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'background'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetBackground(),"BorderImage");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: lineEdit of class  Console */
#ifndef TOLUA_DISABLE_tolua_get_Console_lineEdit_ptr
static int tolua_get_Console_lineEdit_ptr(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lineEdit'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetLineEdit(),"LineEdit");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: closeButton of class  Console */
#ifndef TOLUA_DISABLE_tolua_get_Console_closeButton_ptr
static int tolua_get_Console_closeButton_ptr(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'closeButton'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetCloseButton(),"Button");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: visible of class  Console */
#ifndef TOLUA_DISABLE_tolua_get_Console_visible
static int tolua_get_Console_visible(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'visible'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsVisible());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: visible of class  Console */
#ifndef TOLUA_DISABLE_tolua_set_Console_visible
static int tolua_set_Console_visible(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'visible'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetVisible(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: autoVisibleOnError of class  Console */
#ifndef TOLUA_DISABLE_tolua_get_Console_autoVisibleOnError
static int tolua_get_Console_autoVisibleOnError(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'autoVisibleOnError'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsAutoVisibleOnError());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: autoVisibleOnError of class  Console */
#ifndef TOLUA_DISABLE_tolua_set_Console_autoVisibleOnError
static int tolua_set_Console_autoVisibleOnError(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'autoVisibleOnError'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAutoVisibleOnError(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: commandInterpreter of class  Console */
#ifndef TOLUA_DISABLE_tolua_get_Console_commandInterpreter
static int tolua_get_Console_commandInterpreter(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'commandInterpreter'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetCommandInterpreter());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: commandInterpreter of class  Console */
#ifndef TOLUA_DISABLE_tolua_set_Console_commandInterpreter
static int tolua_set_Console_commandInterpreter(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'commandInterpreter'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCommandInterpreter(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numBufferedRows of class  Console */
#ifndef TOLUA_DISABLE_tolua_get_Console_numBufferedRows
static int tolua_get_Console_numBufferedRows(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numBufferedRows'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumBufferedRows());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: numBufferedRows of class  Console */
#ifndef TOLUA_DISABLE_tolua_set_Console_numBufferedRows
static int tolua_set_Console_numBufferedRows(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numBufferedRows'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetNumBufferedRows(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numRows of class  Console */
#ifndef TOLUA_DISABLE_tolua_get_Console_numRows
static int tolua_get_Console_numRows(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numRows'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumRows());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: numRows of class  Console */
#ifndef TOLUA_DISABLE_tolua_set_Console_numRows
static int tolua_set_Console_numRows(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numRows'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetNumRows(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numHistoryRows of class  Console */
#ifndef TOLUA_DISABLE_tolua_get_Console_numHistoryRows
static int tolua_get_Console_numHistoryRows(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numHistoryRows'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumHistoryRows());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: numHistoryRows of class  Console */
#ifndef TOLUA_DISABLE_tolua_set_Console_numHistoryRows
static int tolua_set_Console_numHistoryRows(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numHistoryRows'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetNumHistoryRows(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: historyPosition of class  Console */
#ifndef TOLUA_DISABLE_tolua_get_Console_historyPosition
static int tolua_get_Console_historyPosition(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'historyPosition'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetHistoryPosition());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: focusOnShow of class  Console */
#ifndef TOLUA_DISABLE_tolua_get_Console_focusOnShow
static int tolua_get_Console_focusOnShow(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'focusOnShow'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetFocusOnShow());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: focusOnShow of class  Console */
#ifndef TOLUA_DISABLE_tolua_set_Console_focusOnShow
static int tolua_set_Console_focusOnShow(lua_State* tolua_S)
{
  Console* self = (Console*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'focusOnShow'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFocusOnShow(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetConsole */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_GetConsole00
static int tolua_EngineLuaAPI_GetConsole00(lua_State* tolua_S)
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
  Console* tolua_ret = (Console*)  GetConsole();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Console");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetConsole'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: console */
#ifndef TOLUA_DISABLE_tolua_get_console_ptr
static int tolua_get_console_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetConsole(),"Console");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEBUGHUD_SHOW_NONE */
#ifndef TOLUA_DISABLE_tolua_get_DEBUGHUD_SHOW_NONE
static int tolua_get_DEBUGHUD_SHOW_NONE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)DEBUGHUD_SHOW_NONE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEBUGHUD_SHOW_STATS */
#ifndef TOLUA_DISABLE_tolua_get_DEBUGHUD_SHOW_STATS
static int tolua_get_DEBUGHUD_SHOW_STATS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)DEBUGHUD_SHOW_STATS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEBUGHUD_SHOW_MODE */
#ifndef TOLUA_DISABLE_tolua_get_DEBUGHUD_SHOW_MODE
static int tolua_get_DEBUGHUD_SHOW_MODE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)DEBUGHUD_SHOW_MODE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEBUGHUD_SHOW_PROFILER */
#ifndef TOLUA_DISABLE_tolua_get_DEBUGHUD_SHOW_PROFILER
static int tolua_get_DEBUGHUD_SHOW_PROFILER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)DEBUGHUD_SHOW_PROFILER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEBUGHUD_SHOW_MEMORY */
#ifndef TOLUA_DISABLE_tolua_get_DEBUGHUD_SHOW_MEMORY
static int tolua_get_DEBUGHUD_SHOW_MEMORY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)DEBUGHUD_SHOW_MEMORY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEBUGHUD_SHOW_EVENTPROFILER */
#ifndef TOLUA_DISABLE_tolua_get_DEBUGHUD_SHOW_EVENTPROFILER
static int tolua_get_DEBUGHUD_SHOW_EVENTPROFILER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)DEBUGHUD_SHOW_EVENTPROFILER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEBUGHUD_SHOW_ALL */
#ifndef TOLUA_DISABLE_tolua_get_DEBUGHUD_SHOW_ALL
static int tolua_get_DEBUGHUD_SHOW_ALL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)DEBUGHUD_SHOW_ALL);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_Update00
static int tolua_EngineLuaAPI_DebugHud_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DebugHud",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
 {
  self->Update();
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

/* method: SetDefaultStyle of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_SetDefaultStyle00
static int tolua_EngineLuaAPI_DebugHud_SetDefaultStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DebugHud",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"XMLFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
  XMLFile* style = ((XMLFile*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDefaultStyle'", NULL);
#endif
 {
  self->SetDefaultStyle(style);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDefaultStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMode of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_SetMode00
static int tolua_EngineLuaAPI_DebugHud_SetMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DebugHud",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
  unsigned mode = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMode'", NULL);
#endif
 {
  self->SetMode(mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProfilerMaxDepth of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_SetProfilerMaxDepth00
static int tolua_EngineLuaAPI_DebugHud_SetProfilerMaxDepth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DebugHud",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
  unsigned depth = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProfilerMaxDepth'", NULL);
#endif
 {
  self->SetProfilerMaxDepth(depth);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProfilerMaxDepth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProfilerInterval of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_SetProfilerInterval00
static int tolua_EngineLuaAPI_DebugHud_SetProfilerInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DebugHud",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
  float interval = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProfilerInterval'", NULL);
#endif
 {
  self->SetProfilerInterval(interval);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProfilerInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseRendererStats of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_SetUseRendererStats00
static int tolua_EngineLuaAPI_DebugHud_SetUseRendererStats00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DebugHud",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseRendererStats'", NULL);
#endif
 {
  self->SetUseRendererStats(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseRendererStats'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Toggle of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_Toggle00
static int tolua_EngineLuaAPI_DebugHud_Toggle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DebugHud",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
  unsigned mode = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Toggle'", NULL);
#endif
 {
  self->Toggle(mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Toggle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToggleAll of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_ToggleAll00
static int tolua_EngineLuaAPI_DebugHud_ToggleAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DebugHud",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToggleAll'", NULL);
#endif
 {
  self->ToggleAll();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToggleAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDefaultStyle of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_GetDefaultStyle00
static int tolua_EngineLuaAPI_DebugHud_GetDefaultStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DebugHud",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DebugHud* self = (const DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDefaultStyle'", NULL);
#endif
 {
  XMLFile* tolua_ret = (XMLFile*)  self->GetDefaultStyle();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"XMLFile");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDefaultStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStatsText of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_GetStatsText00
static int tolua_EngineLuaAPI_DebugHud_GetStatsText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DebugHud",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DebugHud* self = (const DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStatsText'", NULL);
#endif
 {
  Text* tolua_ret = (Text*)  self->GetStatsText();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Text");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStatsText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetModeText of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_GetModeText00
static int tolua_EngineLuaAPI_DebugHud_GetModeText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DebugHud",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DebugHud* self = (const DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetModeText'", NULL);
#endif
 {
  Text* tolua_ret = (Text*)  self->GetModeText();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Text");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetModeText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProfilerText of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_GetProfilerText00
static int tolua_EngineLuaAPI_DebugHud_GetProfilerText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DebugHud",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DebugHud* self = (const DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProfilerText'", NULL);
#endif
 {
  Text* tolua_ret = (Text*)  self->GetProfilerText();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Text");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProfilerText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMode of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_GetMode00
static int tolua_EngineLuaAPI_DebugHud_GetMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DebugHud",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DebugHud* self = (const DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMode'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetMode();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProfilerMaxDepth of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_GetProfilerMaxDepth00
static int tolua_EngineLuaAPI_DebugHud_GetProfilerMaxDepth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DebugHud",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DebugHud* self = (const DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProfilerMaxDepth'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetProfilerMaxDepth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProfilerMaxDepth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProfilerInterval of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_GetProfilerInterval00
static int tolua_EngineLuaAPI_DebugHud_GetProfilerInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DebugHud",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DebugHud* self = (const DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProfilerInterval'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetProfilerInterval();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProfilerInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUseRendererStats of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_GetUseRendererStats00
static int tolua_EngineLuaAPI_DebugHud_GetUseRendererStats00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DebugHud",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DebugHud* self = (const DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUseRendererStats'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetUseRendererStats();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUseRendererStats'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAppStats of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_SetAppStats00
static int tolua_EngineLuaAPI_DebugHud_SetAppStats00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DebugHud",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
  const String label = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Variant stats = *((const Variant*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAppStats'", NULL);
#endif
 {
  self->SetAppStats(label,stats);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAppStats'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAppStats of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_SetAppStats01
static int tolua_EngineLuaAPI_DebugHud_SetAppStats01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DebugHud",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
  const String label = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String stats = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAppStats'", NULL);
#endif
 {
  self->SetAppStats(label,stats);
 }
 }
 return 0;
tolua_lerror:
 return tolua_EngineLuaAPI_DebugHud_SetAppStats00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResetAppStats of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_ResetAppStats00
static int tolua_EngineLuaAPI_DebugHud_ResetAppStats00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DebugHud",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
  const String label = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResetAppStats'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->ResetAppStats(label);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResetAppStats'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearAppStats of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_DebugHud_ClearAppStats00
static int tolua_EngineLuaAPI_DebugHud_ClearAppStats00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DebugHud",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearAppStats'", NULL);
#endif
 {
  self->ClearAppStats();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearAppStats'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: defaultStyle of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_get_DebugHud_defaultStyle_ptr
static int tolua_get_DebugHud_defaultStyle_ptr(lua_State* tolua_S)
{
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'defaultStyle'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetDefaultStyle(),"XMLFile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: defaultStyle of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_set_DebugHud_defaultStyle_ptr
static int tolua_set_DebugHud_defaultStyle_ptr(lua_State* tolua_S)
{
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'defaultStyle'",NULL);
 if (!tolua_isusertype(tolua_S,2,"XMLFile",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDefaultStyle(((XMLFile*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: statsText of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_get_DebugHud_statsText_ptr
static int tolua_get_DebugHud_statsText_ptr(lua_State* tolua_S)
{
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'statsText'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetStatsText(),"Text");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: modeText of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_get_DebugHud_modeText_ptr
static int tolua_get_DebugHud_modeText_ptr(lua_State* tolua_S)
{
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modeText'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetModeText(),"Text");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: profilerText of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_get_DebugHud_profilerText_ptr
static int tolua_get_DebugHud_profilerText_ptr(lua_State* tolua_S)
{
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'profilerText'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetProfilerText(),"Text");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mode of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_get_DebugHud_mode
static int tolua_get_DebugHud_mode(lua_State* tolua_S)
{
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mode of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_set_DebugHud_mode
static int tolua_set_DebugHud_mode(lua_State* tolua_S)
{
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mode'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMode(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: profilerMaxDepth of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_get_DebugHud_profilerMaxDepth
static int tolua_get_DebugHud_profilerMaxDepth(lua_State* tolua_S)
{
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'profilerMaxDepth'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetProfilerMaxDepth());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: profilerMaxDepth of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_set_DebugHud_profilerMaxDepth
static int tolua_set_DebugHud_profilerMaxDepth(lua_State* tolua_S)
{
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'profilerMaxDepth'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetProfilerMaxDepth(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: profilerInterval of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_get_DebugHud_profilerInterval
static int tolua_get_DebugHud_profilerInterval(lua_State* tolua_S)
{
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'profilerInterval'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetProfilerInterval());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: profilerInterval of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_set_DebugHud_profilerInterval
static int tolua_set_DebugHud_profilerInterval(lua_State* tolua_S)
{
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'profilerInterval'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetProfilerInterval(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: useRendererStats of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_get_DebugHud_useRendererStats
static int tolua_get_DebugHud_useRendererStats(lua_State* tolua_S)
{
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useRendererStats'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetUseRendererStats());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: useRendererStats of class  DebugHud */
#ifndef TOLUA_DISABLE_tolua_set_DebugHud_useRendererStats
static int tolua_set_DebugHud_useRendererStats(lua_State* tolua_S)
{
  DebugHud* self = (DebugHud*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useRendererStats'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUseRendererStats(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetDebugHud */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_GetDebugHud00
static int tolua_EngineLuaAPI_GetDebugHud00(lua_State* tolua_S)
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
  DebugHud* tolua_ret = (DebugHud*)  GetDebugHud();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"DebugHud");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDebugHud'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: debugHud */
#ifndef TOLUA_DISABLE_tolua_get_debugHud_ptr
static int tolua_get_debugHud_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetDebugHud(),"DebugHud");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: RunFrame of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_RunFrame00
static int tolua_EngineLuaAPI_Engine_RunFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Engine",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RunFrame'", NULL);
#endif
 {
  self->RunFrame();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RunFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateConsole of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_CreateConsole00
static int tolua_EngineLuaAPI_Engine_CreateConsole00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Engine",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateConsole'", NULL);
#endif
 {
  Console* tolua_ret = (Console*)  self->CreateConsole();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Console");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateConsole'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateDebugHud of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_CreateDebugHud00
static int tolua_EngineLuaAPI_Engine_CreateDebugHud00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Engine",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateDebugHud'", NULL);
#endif
 {
  DebugHud* tolua_ret = (DebugHud*)  self->CreateDebugHud();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"DebugHud");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateDebugHud'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMinFps of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_SetMinFps00
static int tolua_EngineLuaAPI_Engine_SetMinFps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Engine",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
  int fps = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMinFps'", NULL);
#endif
 {
  self->SetMinFps(fps);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMinFps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxFps of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_SetMaxFps00
static int tolua_EngineLuaAPI_Engine_SetMaxFps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Engine",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
  int fps = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxFps'", NULL);
#endif
 {
  self->SetMaxFps(fps);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxFps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxInactiveFps of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_SetMaxInactiveFps00
static int tolua_EngineLuaAPI_Engine_SetMaxInactiveFps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Engine",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
  int fps = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxInactiveFps'", NULL);
#endif
 {
  self->SetMaxInactiveFps(fps);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxInactiveFps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTimeStepSmoothing of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_SetTimeStepSmoothing00
static int tolua_EngineLuaAPI_Engine_SetTimeStepSmoothing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Engine",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
  int frames = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTimeStepSmoothing'", NULL);
#endif
 {
  self->SetTimeStepSmoothing(frames);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTimeStepSmoothing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPauseMinimized of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_SetPauseMinimized00
static int tolua_EngineLuaAPI_Engine_SetPauseMinimized00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Engine",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPauseMinimized'", NULL);
#endif
 {
  self->SetPauseMinimized(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPauseMinimized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAutoExit of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_SetAutoExit00
static int tolua_EngineLuaAPI_Engine_SetAutoExit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Engine",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAutoExit'", NULL);
#endif
 {
  self->SetAutoExit(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAutoExit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Exit of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_Exit00
static int tolua_EngineLuaAPI_Engine_Exit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Engine",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exit'", NULL);
#endif
 {
  self->Exit();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DumpProfiler of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_DumpProfiler00
static int tolua_EngineLuaAPI_Engine_DumpProfiler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Engine",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DumpProfiler'", NULL);
#endif
 {
  self->DumpProfiler();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DumpProfiler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DumpResources of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_DumpResources00
static int tolua_EngineLuaAPI_Engine_DumpResources00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Engine",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
  bool dumpFileName = ((bool)  tolua_toboolean(tolua_S,2,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DumpResources'", NULL);
#endif
 {
  self->DumpResources(dumpFileName);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DumpResources'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DumpMemory of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_DumpMemory00
static int tolua_EngineLuaAPI_Engine_DumpMemory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Engine",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DumpMemory'", NULL);
#endif
 {
  self->DumpMemory();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DumpMemory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMinFps of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_GetMinFps00
static int tolua_EngineLuaAPI_Engine_GetMinFps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Engine",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Engine* self = (const Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMinFps'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetMinFps();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMinFps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxFps of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_GetMaxFps00
static int tolua_EngineLuaAPI_Engine_GetMaxFps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Engine",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Engine* self = (const Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxFps'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetMaxFps();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxFps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxInactiveFps of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_GetMaxInactiveFps00
static int tolua_EngineLuaAPI_Engine_GetMaxInactiveFps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Engine",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Engine* self = (const Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxInactiveFps'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetMaxInactiveFps();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxInactiveFps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTimeStepSmoothing of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_GetTimeStepSmoothing00
static int tolua_EngineLuaAPI_Engine_GetTimeStepSmoothing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Engine",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Engine* self = (const Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTimeStepSmoothing'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetTimeStepSmoothing();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimeStepSmoothing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPauseMinimized of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_GetPauseMinimized00
static int tolua_EngineLuaAPI_Engine_GetPauseMinimized00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Engine",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Engine* self = (const Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPauseMinimized'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetPauseMinimized();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPauseMinimized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAutoExit of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_GetAutoExit00
static int tolua_EngineLuaAPI_Engine_GetAutoExit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Engine",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Engine* self = (const Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAutoExit'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetAutoExit();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAutoExit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInitialized of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_IsInitialized00
static int tolua_EngineLuaAPI_Engine_IsInitialized00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Engine",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Engine* self = (const Engine*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsExiting of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_IsExiting00
static int tolua_EngineLuaAPI_Engine_IsExiting00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Engine",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Engine* self = (const Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsExiting'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsExiting();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsExiting'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsHeadless of class  Engine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_Engine_IsHeadless00
static int tolua_EngineLuaAPI_Engine_IsHeadless00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Engine",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Engine* self = (const Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsHeadless'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsHeadless();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsHeadless'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: minFps of class  Engine */
#ifndef TOLUA_DISABLE_tolua_get_Engine_minFps
static int tolua_get_Engine_minFps(lua_State* tolua_S)
{
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minFps'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMinFps());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: minFps of class  Engine */
#ifndef TOLUA_DISABLE_tolua_set_Engine_minFps
static int tolua_set_Engine_minFps(lua_State* tolua_S)
{
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minFps'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMinFps(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxFps of class  Engine */
#ifndef TOLUA_DISABLE_tolua_get_Engine_maxFps
static int tolua_get_Engine_maxFps(lua_State* tolua_S)
{
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxFps'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxFps());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxFps of class  Engine */
#ifndef TOLUA_DISABLE_tolua_set_Engine_maxFps
static int tolua_set_Engine_maxFps(lua_State* tolua_S)
{
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxFps'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxFps(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxInactiveFps of class  Engine */
#ifndef TOLUA_DISABLE_tolua_get_Engine_maxInactiveFps
static int tolua_get_Engine_maxInactiveFps(lua_State* tolua_S)
{
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxInactiveFps'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxInactiveFps());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxInactiveFps of class  Engine */
#ifndef TOLUA_DISABLE_tolua_set_Engine_maxInactiveFps
static int tolua_set_Engine_maxInactiveFps(lua_State* tolua_S)
{
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxInactiveFps'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxInactiveFps(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: timeStepSmoothing of class  Engine */
#ifndef TOLUA_DISABLE_tolua_get_Engine_timeStepSmoothing
static int tolua_get_Engine_timeStepSmoothing(lua_State* tolua_S)
{
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeStepSmoothing'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTimeStepSmoothing());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: timeStepSmoothing of class  Engine */
#ifndef TOLUA_DISABLE_tolua_set_Engine_timeStepSmoothing
static int tolua_set_Engine_timeStepSmoothing(lua_State* tolua_S)
{
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeStepSmoothing'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTimeStepSmoothing(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pauseMinimized of class  Engine */
#ifndef TOLUA_DISABLE_tolua_get_Engine_pauseMinimized
static int tolua_get_Engine_pauseMinimized(lua_State* tolua_S)
{
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pauseMinimized'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetPauseMinimized());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pauseMinimized of class  Engine */
#ifndef TOLUA_DISABLE_tolua_set_Engine_pauseMinimized
static int tolua_set_Engine_pauseMinimized(lua_State* tolua_S)
{
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pauseMinimized'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPauseMinimized(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: autoExit of class  Engine */
#ifndef TOLUA_DISABLE_tolua_get_Engine_autoExit
static int tolua_get_Engine_autoExit(lua_State* tolua_S)
{
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'autoExit'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetAutoExit());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: autoExit of class  Engine */
#ifndef TOLUA_DISABLE_tolua_set_Engine_autoExit
static int tolua_set_Engine_autoExit(lua_State* tolua_S)
{
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'autoExit'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAutoExit(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: initialized of class  Engine */
#ifndef TOLUA_DISABLE_tolua_get_Engine_initialized
static int tolua_get_Engine_initialized(lua_State* tolua_S)
{
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'initialized'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsInitialized());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: exiting of class  Engine */
#ifndef TOLUA_DISABLE_tolua_get_Engine_exiting
static int tolua_get_Engine_exiting(lua_State* tolua_S)
{
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'exiting'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsExiting());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: headless of class  Engine */
#ifndef TOLUA_DISABLE_tolua_get_Engine_headless
static int tolua_get_Engine_headless(lua_State* tolua_S)
{
  Engine* self = (Engine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'headless'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsHeadless());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetEngine */
#ifndef TOLUA_DISABLE_tolua_EngineLuaAPI_GetEngine00
static int tolua_EngineLuaAPI_GetEngine00(lua_State* tolua_S)
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
  Engine* tolua_ret = (Engine*)  GetEngine();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Engine");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEngine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: engine */
#ifndef TOLUA_DISABLE_tolua_get_engine_ptr
static int tolua_get_engine_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetEngine(),"Engine");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_EngineLuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"Console","Console","Object",NULL);
 tolua_beginmodule(tolua_S,"Console");
  tolua_function(tolua_S,"SetDefaultStyle",tolua_EngineLuaAPI_Console_SetDefaultStyle00);
  tolua_function(tolua_S,"SetVisible",tolua_EngineLuaAPI_Console_SetVisible00);
  tolua_function(tolua_S,"Toggle",tolua_EngineLuaAPI_Console_Toggle00);
  tolua_function(tolua_S,"SetAutoVisibleOnError",tolua_EngineLuaAPI_Console_SetAutoVisibleOnError00);
  tolua_function(tolua_S,"SetCommandInterpreter",tolua_EngineLuaAPI_Console_SetCommandInterpreter00);
  tolua_function(tolua_S,"SetNumBufferedRows",tolua_EngineLuaAPI_Console_SetNumBufferedRows00);
  tolua_function(tolua_S,"SetNumRows",tolua_EngineLuaAPI_Console_SetNumRows00);
  tolua_function(tolua_S,"SetNumHistoryRows",tolua_EngineLuaAPI_Console_SetNumHistoryRows00);
  tolua_function(tolua_S,"SetFocusOnShow",tolua_EngineLuaAPI_Console_SetFocusOnShow00);
  tolua_function(tolua_S,"AddAutoComplete",tolua_EngineLuaAPI_Console_AddAutoComplete00);
  tolua_function(tolua_S,"RemoveAutoComplete",tolua_EngineLuaAPI_Console_RemoveAutoComplete00);
  tolua_function(tolua_S,"UpdateElements",tolua_EngineLuaAPI_Console_UpdateElements00);
  tolua_function(tolua_S,"GetDefaultStyle",tolua_EngineLuaAPI_Console_GetDefaultStyle00);
  tolua_function(tolua_S,"GetBackground",tolua_EngineLuaAPI_Console_GetBackground00);
  tolua_function(tolua_S,"GetLineEdit",tolua_EngineLuaAPI_Console_GetLineEdit00);
  tolua_function(tolua_S,"GetCloseButton",tolua_EngineLuaAPI_Console_GetCloseButton00);
  tolua_function(tolua_S,"IsVisible",tolua_EngineLuaAPI_Console_IsVisible00);
  tolua_function(tolua_S,"IsAutoVisibleOnError",tolua_EngineLuaAPI_Console_IsAutoVisibleOnError00);
  tolua_function(tolua_S,"GetCommandInterpreter",tolua_EngineLuaAPI_Console_GetCommandInterpreter00);
  tolua_function(tolua_S,"GetNumBufferedRows",tolua_EngineLuaAPI_Console_GetNumBufferedRows00);
  tolua_function(tolua_S,"GetNumRows",tolua_EngineLuaAPI_Console_GetNumRows00);
  tolua_function(tolua_S,"CopySelectedRows",tolua_EngineLuaAPI_Console_CopySelectedRows00);
  tolua_function(tolua_S,"GetNumHistoryRows",tolua_EngineLuaAPI_Console_GetNumHistoryRows00);
  tolua_function(tolua_S,"GetHistoryPosition",tolua_EngineLuaAPI_Console_GetHistoryPosition00);
  tolua_function(tolua_S,"GetHistoryRow",tolua_EngineLuaAPI_Console_GetHistoryRow00);
  tolua_function(tolua_S,"GetFocusOnShow",tolua_EngineLuaAPI_Console_GetFocusOnShow00);
  tolua_variable(tolua_S,"defaultStyle",tolua_get_Console_defaultStyle_ptr,tolua_set_Console_defaultStyle_ptr);
  tolua_variable(tolua_S,"background",tolua_get_Console_background_ptr,NULL);
  tolua_variable(tolua_S,"lineEdit",tolua_get_Console_lineEdit_ptr,NULL);
  tolua_variable(tolua_S,"closeButton",tolua_get_Console_closeButton_ptr,NULL);
  tolua_variable(tolua_S,"visible",tolua_get_Console_visible,tolua_set_Console_visible);
  tolua_variable(tolua_S,"autoVisibleOnError",tolua_get_Console_autoVisibleOnError,tolua_set_Console_autoVisibleOnError);
  tolua_variable(tolua_S,"commandInterpreter",tolua_get_Console_commandInterpreter,tolua_set_Console_commandInterpreter);
  tolua_variable(tolua_S,"numBufferedRows",tolua_get_Console_numBufferedRows,tolua_set_Console_numBufferedRows);
  tolua_variable(tolua_S,"numRows",tolua_get_Console_numRows,tolua_set_Console_numRows);
  tolua_variable(tolua_S,"numHistoryRows",tolua_get_Console_numHistoryRows,tolua_set_Console_numHistoryRows);
  tolua_variable(tolua_S,"historyPosition",tolua_get_Console_historyPosition,NULL);
  tolua_variable(tolua_S,"focusOnShow",tolua_get_Console_focusOnShow,tolua_set_Console_focusOnShow);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"GetConsole",tolua_EngineLuaAPI_GetConsole00);
 tolua_variable(tolua_S,"console",tolua_get_console_ptr,NULL);
 tolua_variable(tolua_S,"DEBUGHUD_SHOW_NONE",tolua_get_DEBUGHUD_SHOW_NONE,NULL);
 tolua_variable(tolua_S,"DEBUGHUD_SHOW_STATS",tolua_get_DEBUGHUD_SHOW_STATS,NULL);
 tolua_variable(tolua_S,"DEBUGHUD_SHOW_MODE",tolua_get_DEBUGHUD_SHOW_MODE,NULL);
 tolua_variable(tolua_S,"DEBUGHUD_SHOW_PROFILER",tolua_get_DEBUGHUD_SHOW_PROFILER,NULL);
 tolua_variable(tolua_S,"DEBUGHUD_SHOW_MEMORY",tolua_get_DEBUGHUD_SHOW_MEMORY,NULL);
 tolua_variable(tolua_S,"DEBUGHUD_SHOW_EVENTPROFILER",tolua_get_DEBUGHUD_SHOW_EVENTPROFILER,NULL);
 tolua_variable(tolua_S,"DEBUGHUD_SHOW_ALL",tolua_get_DEBUGHUD_SHOW_ALL,NULL);
 tolua_cclass(tolua_S,"DebugHud","DebugHud","Object",NULL);
 tolua_beginmodule(tolua_S,"DebugHud");
  tolua_function(tolua_S,"Update",tolua_EngineLuaAPI_DebugHud_Update00);
  tolua_function(tolua_S,"SetDefaultStyle",tolua_EngineLuaAPI_DebugHud_SetDefaultStyle00);
  tolua_function(tolua_S,"SetMode",tolua_EngineLuaAPI_DebugHud_SetMode00);
  tolua_function(tolua_S,"SetProfilerMaxDepth",tolua_EngineLuaAPI_DebugHud_SetProfilerMaxDepth00);
  tolua_function(tolua_S,"SetProfilerInterval",tolua_EngineLuaAPI_DebugHud_SetProfilerInterval00);
  tolua_function(tolua_S,"SetUseRendererStats",tolua_EngineLuaAPI_DebugHud_SetUseRendererStats00);
  tolua_function(tolua_S,"Toggle",tolua_EngineLuaAPI_DebugHud_Toggle00);
  tolua_function(tolua_S,"ToggleAll",tolua_EngineLuaAPI_DebugHud_ToggleAll00);
  tolua_function(tolua_S,"GetDefaultStyle",tolua_EngineLuaAPI_DebugHud_GetDefaultStyle00);
  tolua_function(tolua_S,"GetStatsText",tolua_EngineLuaAPI_DebugHud_GetStatsText00);
  tolua_function(tolua_S,"GetModeText",tolua_EngineLuaAPI_DebugHud_GetModeText00);
  tolua_function(tolua_S,"GetProfilerText",tolua_EngineLuaAPI_DebugHud_GetProfilerText00);
  tolua_function(tolua_S,"GetMode",tolua_EngineLuaAPI_DebugHud_GetMode00);
  tolua_function(tolua_S,"GetProfilerMaxDepth",tolua_EngineLuaAPI_DebugHud_GetProfilerMaxDepth00);
  tolua_function(tolua_S,"GetProfilerInterval",tolua_EngineLuaAPI_DebugHud_GetProfilerInterval00);
  tolua_function(tolua_S,"GetUseRendererStats",tolua_EngineLuaAPI_DebugHud_GetUseRendererStats00);
  tolua_function(tolua_S,"SetAppStats",tolua_EngineLuaAPI_DebugHud_SetAppStats00);
  tolua_function(tolua_S,"SetAppStats",tolua_EngineLuaAPI_DebugHud_SetAppStats01);
  tolua_function(tolua_S,"ResetAppStats",tolua_EngineLuaAPI_DebugHud_ResetAppStats00);
  tolua_function(tolua_S,"ClearAppStats",tolua_EngineLuaAPI_DebugHud_ClearAppStats00);
  tolua_variable(tolua_S,"defaultStyle",tolua_get_DebugHud_defaultStyle_ptr,tolua_set_DebugHud_defaultStyle_ptr);
  tolua_variable(tolua_S,"statsText",tolua_get_DebugHud_statsText_ptr,NULL);
  tolua_variable(tolua_S,"modeText",tolua_get_DebugHud_modeText_ptr,NULL);
  tolua_variable(tolua_S,"profilerText",tolua_get_DebugHud_profilerText_ptr,NULL);
  tolua_variable(tolua_S,"mode",tolua_get_DebugHud_mode,tolua_set_DebugHud_mode);
  tolua_variable(tolua_S,"profilerMaxDepth",tolua_get_DebugHud_profilerMaxDepth,tolua_set_DebugHud_profilerMaxDepth);
  tolua_variable(tolua_S,"profilerInterval",tolua_get_DebugHud_profilerInterval,tolua_set_DebugHud_profilerInterval);
  tolua_variable(tolua_S,"useRendererStats",tolua_get_DebugHud_useRendererStats,tolua_set_DebugHud_useRendererStats);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"GetDebugHud",tolua_EngineLuaAPI_GetDebugHud00);
 tolua_variable(tolua_S,"debugHud",tolua_get_debugHud_ptr,NULL);
 tolua_cclass(tolua_S,"Engine","Engine","Object",NULL);
 tolua_beginmodule(tolua_S,"Engine");
  tolua_function(tolua_S,"RunFrame",tolua_EngineLuaAPI_Engine_RunFrame00);
  tolua_function(tolua_S,"CreateConsole",tolua_EngineLuaAPI_Engine_CreateConsole00);
  tolua_function(tolua_S,"CreateDebugHud",tolua_EngineLuaAPI_Engine_CreateDebugHud00);
  tolua_function(tolua_S,"SetMinFps",tolua_EngineLuaAPI_Engine_SetMinFps00);
  tolua_function(tolua_S,"SetMaxFps",tolua_EngineLuaAPI_Engine_SetMaxFps00);
  tolua_function(tolua_S,"SetMaxInactiveFps",tolua_EngineLuaAPI_Engine_SetMaxInactiveFps00);
  tolua_function(tolua_S,"SetTimeStepSmoothing",tolua_EngineLuaAPI_Engine_SetTimeStepSmoothing00);
  tolua_function(tolua_S,"SetPauseMinimized",tolua_EngineLuaAPI_Engine_SetPauseMinimized00);
  tolua_function(tolua_S,"SetAutoExit",tolua_EngineLuaAPI_Engine_SetAutoExit00);
  tolua_function(tolua_S,"Exit",tolua_EngineLuaAPI_Engine_Exit00);
  tolua_function(tolua_S,"DumpProfiler",tolua_EngineLuaAPI_Engine_DumpProfiler00);
  tolua_function(tolua_S,"DumpResources",tolua_EngineLuaAPI_Engine_DumpResources00);
  tolua_function(tolua_S,"DumpMemory",tolua_EngineLuaAPI_Engine_DumpMemory00);
  tolua_function(tolua_S,"GetMinFps",tolua_EngineLuaAPI_Engine_GetMinFps00);
  tolua_function(tolua_S,"GetMaxFps",tolua_EngineLuaAPI_Engine_GetMaxFps00);
  tolua_function(tolua_S,"GetMaxInactiveFps",tolua_EngineLuaAPI_Engine_GetMaxInactiveFps00);
  tolua_function(tolua_S,"GetTimeStepSmoothing",tolua_EngineLuaAPI_Engine_GetTimeStepSmoothing00);
  tolua_function(tolua_S,"GetPauseMinimized",tolua_EngineLuaAPI_Engine_GetPauseMinimized00);
  tolua_function(tolua_S,"GetAutoExit",tolua_EngineLuaAPI_Engine_GetAutoExit00);
  tolua_function(tolua_S,"IsInitialized",tolua_EngineLuaAPI_Engine_IsInitialized00);
  tolua_function(tolua_S,"IsExiting",tolua_EngineLuaAPI_Engine_IsExiting00);
  tolua_function(tolua_S,"IsHeadless",tolua_EngineLuaAPI_Engine_IsHeadless00);
  tolua_variable(tolua_S,"minFps",tolua_get_Engine_minFps,tolua_set_Engine_minFps);
  tolua_variable(tolua_S,"maxFps",tolua_get_Engine_maxFps,tolua_set_Engine_maxFps);
  tolua_variable(tolua_S,"maxInactiveFps",tolua_get_Engine_maxInactiveFps,tolua_set_Engine_maxInactiveFps);
  tolua_variable(tolua_S,"timeStepSmoothing",tolua_get_Engine_timeStepSmoothing,tolua_set_Engine_timeStepSmoothing);
  tolua_variable(tolua_S,"pauseMinimized",tolua_get_Engine_pauseMinimized,tolua_set_Engine_pauseMinimized);
  tolua_variable(tolua_S,"autoExit",tolua_get_Engine_autoExit,tolua_set_Engine_autoExit);
  tolua_variable(tolua_S,"initialized",tolua_get_Engine_initialized,NULL);
  tolua_variable(tolua_S,"exiting",tolua_get_Engine_exiting,NULL);
  tolua_variable(tolua_S,"headless",tolua_get_Engine_headless,NULL);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"GetEngine",tolua_EngineLuaAPI_GetEngine00);
 tolua_variable(tolua_S,"engine",tolua_get_engine_ptr,NULL);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_EngineLuaAPI (lua_State* tolua_S) {
 return tolua_EngineLuaAPI_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif