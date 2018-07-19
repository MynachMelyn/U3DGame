/*
** Lua binding: LuaScriptLuaAPI
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
TOLUA_API int tolua_LuaScriptLuaAPI_open (lua_State* tolua_S);

#include "LuaScript/LuaScript.h"
#include "LuaScript/LuaScriptInstance.h"
using namespace Urho3D;
#pragma warning(disable:4800)


static void RegisterEventName(const String eventName)
{
    GetEventNameRegister().RegisterString(eventName.CString());
}

static LuaScript* GetLuaScript(lua_State* L)
{
    return GetContext(L)->GetSubsystem<LuaScript>();
}

#define LuaScriptAddEventHandler GetLuaScript(tolua_S)->AddEventHandler
#define LuaScriptRemoveEventHandler GetLuaScript(tolua_S)->RemoveEventHandler
#define LuaScriptRemoveEventHandlers GetLuaScript(tolua_S)->RemoveEventHandlers
#define LuaScriptRemoveAllEventHandlers GetLuaScript(tolua_S)->RemoveAllEventHandlers
#define LuaScriptRemoveEventHandlersExcept GetLuaScript(tolua_S)->RemoveEventHandlersExcept
#define LuaScriptHasSubscribedToEvent GetLuaScript(tolua_S)->HasEventHandler

#define LuaScriptSendEvent GetLuaScript(tolua_S)->SendEvent
#define LuaScriptSetExecuteConsoleCommands GetLuaScript(tolua_S)->SetExecuteConsoleCommands
#define LuaScriptGetExecuteConsoleCommands GetLuaScript(tolua_S)->GetExecuteConsoleCommands

#define LuaScriptSetGlobalVar GetLuaScript(tolua_S)->SetGlobalVar
#define LuaScriptGetGlobalVar GetLuaScript(tolua_S)->GetGlobalVar
#define LuaScriptGetGlobalVars GetLuaScript(tolua_S)->GetGlobalVars

static bool tolua_isfunctionorurho3dstring(lua_State* L, int lo, int def, tolua_Error* err)
{
    return lua_isfunction(L, lo) || tolua_isurho3dstring(L, lo, def, err);
}
static int tolua_LuaScriptLuaAPI_SubscribeToEvent(lua_State* tolua_S)
{
    int args = lua_gettop(tolua_S);
    tolua_Error tolua_err;

#ifndef TOLUA_RELEASE
    if (args == 2)
    {   
        // SubscribeToEvent(const String eventName, void* functionOrFunctionName);
        if (!tolua_isurho3dstring(tolua_S,1,0,&tolua_err) || 
            !tolua_isfunctionorurho3dstring(tolua_S,2,0,&tolua_err))
            goto tolua_lerror;
    }
    else if (args == 3)
    {
        // SubscribeToEvent(Object* sender, const String eventName, void* functionOrFunctionName);
        if (!tolua_isuserdata(tolua_S,1,0,&tolua_err) ||
            !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
            !tolua_isfunctionorurho3dstring(tolua_S,3,0,&tolua_err))
            goto tolua_lerror;
    }
    else
        goto tolua_lerror;
#endif

    if (args == 2)
    {
        // SubscribeToEvent(const String eventName, void* functionOrFunctionName);
        const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
        if (lua_isfunction(tolua_S,2))
            LuaScriptAddEventHandler(eventName,2);
        else
        {
            const String functionName = (const String)tolua_tourho3dstring(tolua_S,2,0);
            LuaScriptAddEventHandler(eventName,functionName);
        }        
    }
    else if (args == 3)
    {
        // SubscribeToEvent(Object* sender, const String eventName, void* functionOrFunctionName);
        Object* sender = ((Object*)  tolua_touserdata(tolua_S,1,0));
        const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
        if (lua_isfunction(tolua_S,3))
            LuaScriptAddEventHandler(sender,eventName,3);
        else
        {
            const String functionName = (const String)tolua_tourho3dstring(tolua_S,3,0);
            LuaScriptAddEventHandler(sender,eventName,functionName);
        }
    }

    return 0;

#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'SubscribeToEvent'.",&tolua_err);
    return 0;
#endif    
}

#define TOLUA_DISABLE_tolua_LuaScriptLuaAPI_SubscribeToEvent00
static int tolua_LuaScriptLuaAPI_SubscribeToEvent00(lua_State* tolua_S)
{
    return tolua_LuaScriptLuaAPI_SubscribeToEvent(tolua_S);
}

#define TOLUA_DISABLE_tolua_LuaScriptLuaAPI_SubscribeToEvent01
static int tolua_LuaScriptLuaAPI_SubscribeToEvent01(lua_State* tolua_S)
{
    return tolua_LuaScriptLuaAPI_SubscribeToEvent(tolua_S);
}

static int tolua_LuaScriptLuaAPI_UnsubscribeFromEvent(lua_State* tolua_S)
{
    int args = lua_gettop(tolua_S);
    tolua_Error tolua_err;
    
#ifndef TOLUA_RELEASE
    if (args == 1)
    {
        // UnsubscribeFromEvent(const String eventName);
        if (!tolua_isurho3dstring(tolua_S,1,0,&tolua_err))
            goto tolua_lerror;
    }
    else if (args == 2)
    {
        // UnsubscribeFromEvent(Object* sender, const String eventName);
        if (!tolua_isuserdata(tolua_S,1,0,&tolua_err) ||
            !tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
                goto tolua_lerror;
    }
    else
        goto tolua_lerror;
#endif

    if (args == 1)
    {
        // UnsubscribeFromEvent(const String eventName);
        const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
        LuaScriptRemoveEventHandler(eventName);
    }
    else if (args == 2)
    {
        // UnsubscribeFromEvent(Object* sender, const String eventName);
        Object* sender = ((Object*)  tolua_touserdata(tolua_S,1,0));
        const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
        LuaScriptRemoveEventHandler(sender, eventName);
    }

    return 0;

#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'UnsubscribeFromEvent'.",&tolua_err);
    return 0;
#endif
}

#define TOLUA_DISABLE_tolua_LuaScriptLuaAPI_UnsubscribeFromEvent00
static int tolua_LuaScriptLuaAPI_UnsubscribeFromEvent00(lua_State* tolua_S)
{
    return tolua_LuaScriptLuaAPI_UnsubscribeFromEvent(tolua_S);
}

#define TOLUA_DISABLE_tolua_LuaScriptLuaAPI_UnsubscribeFromEvent01
static int tolua_LuaScriptLuaAPI_UnsubscribeFromEvent01(lua_State* tolua_S)
{
    return tolua_LuaScriptLuaAPI_UnsubscribeFromEvent(tolua_S);
}

static int tolua_LuaScriptLuaAPI_LuaScriptInstance_SubscribeToEvent(lua_State* tolua_S)
{
    int args = lua_gettop(tolua_S);
    tolua_Error tolua_err;
    LuaScriptInstance* self = 0;

#ifndef TOLUA_RELEASE
    if (args == 3)
    {   
        // LuaScriptInstance::AddEventHandler(const String eventName, void* functionOrFunctionName);
        if (!tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
            !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) || 
            !tolua_isfunctionorurho3dstring(tolua_S,3,0,&tolua_err))
            goto tolua_lerror;
    }
    else if (args == 4)
    {
        // LuaScriptInstance::AddEventHandler(Object* sender, const String eventName, void* functionOrFunctionName);
        if (!tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) || 
            !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
            !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
            !tolua_isfunctionorurho3dstring(tolua_S,4,0,&tolua_err))
            goto tolua_lerror;
    }
    else
        goto tolua_lerror;
#endif

    self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);

    if (args == 3)
    {
        // LuaScriptInstance::AddEventHandler(const String eventName, void* functionOrFunctionName);
        const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
        if (lua_isfunction(tolua_S,3))
            self->AddEventHandler(eventName,3);
        else
        {
            const String functionName = (const String)tolua_tourho3dstring(tolua_S,3,0);
            self->AddEventHandler(eventName,functionName);
        }        
    }
    else if (args == 4)
    {
        // LuaScriptInstance::AddEventHandler(Object* sender, const String eventName, void* functionOrFunctionName);
        Object* sender = ((Object*)  tolua_touserdata(tolua_S,2,0));
        const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
        if (lua_isfunction(tolua_S,4))
            self->AddEventHandler(sender,eventName,4);
        else
        {
            const String functionName = (const String)tolua_tourho3dstring(tolua_S,4,0);
            self->AddEventHandler(sender,eventName,functionName);
        }
    }

    return 0;

#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'LuaScriptInstance::AddEventHandler'.",&tolua_err);
    return 0;
#endif
}

#define TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_SubscribeToEvent00
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_SubscribeToEvent00(lua_State* tolua_S)
{
    return tolua_LuaScriptLuaAPI_LuaScriptInstance_SubscribeToEvent(tolua_S);
}

#define TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_SubscribeToEvent01
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_SubscribeToEvent01(lua_State* tolua_S)
{
    return tolua_LuaScriptLuaAPI_LuaScriptInstance_SubscribeToEvent(tolua_S);
}

static int tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvent(lua_State* tolua_S)
{
    int args = lua_gettop(tolua_S);
    tolua_Error tolua_err;
    LuaScriptInstance* self = 0;

#ifndef TOLUA_RELEASE
    if (args == 2)
    {
        // LuaScriptInstance::RemoveEventHandler(const String eventName);
        if (!tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
            !tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
            goto tolua_lerror;
    }
    else if (args == 3)
    {
       // LuaScriptInstance::RemoveEventHandler(Object* sender, const String eventName);
        if (!tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
            !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
            !tolua_isurho3dstring(tolua_S,3,0,&tolua_err))
                goto tolua_lerror;
    }
    else
        goto tolua_lerror;
#endif

    self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);

    if (args == 2)
    {
        // LuaScriptInstance::RemoveEventHandler(const String eventName);
        const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
        self->RemoveEventHandler(eventName);
    }
    else if (args == 3)
    {
        // LuaScriptInstance::RemoveEventHandler(Object* sender, const String eventName);
        Object* sender = ((Object*)  tolua_touserdata(tolua_S,2,0));
        const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
        self->RemoveEventHandler(sender, eventName);
    }

    return 0;

#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'UnsubscribeFromEvent'.",&tolua_err);
    return 0;
#endif
}

#define TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvent00
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvent00(lua_State* tolua_S)
{
    return tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvent(tolua_S);
}

#define TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvent01
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvent01(lua_State* tolua_S)
{
    return tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvent(tolua_S);
}

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Variant (lua_State* tolua_S)
{
 Variant* self = (Variant*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"VariantMap");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"Variant");
 tolua_usertype(tolua_S,"LuaFile");
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"LuaScriptInstance");
 tolua_usertype(tolua_S,"Vector<String>");
}

/* function: LuaScriptAddEventHandler */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_SubscribeToEvent00
static int tolua_LuaScriptLuaAPI_SubscribeToEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isurho3dstring(tolua_S,1,0,&tolua_err) ||
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
  void* functionOrFunctionName = ((void*)  tolua_touserdata(tolua_S,2,0));
 {
  LuaScriptAddEventHandler(eventName,functionOrFunctionName);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SubscribeToEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: LuaScriptAddEventHandler */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_SubscribeToEvent01
static int tolua_LuaScriptLuaAPI_SubscribeToEvent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  void* sender = ((void*)  tolua_touserdata(tolua_S,1,0));
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  void* functionOrFunctionName = ((void*)  tolua_touserdata(tolua_S,3,0));
 {
  LuaScriptAddEventHandler(sender,eventName,functionOrFunctionName);
 }
 }
 return 0;
tolua_lerror:
 return tolua_LuaScriptLuaAPI_SubscribeToEvent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: LuaScriptRemoveEventHandler */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_UnsubscribeFromEvent00
static int tolua_LuaScriptLuaAPI_UnsubscribeFromEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isurho3dstring(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  LuaScriptRemoveEventHandler(eventName);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnsubscribeFromEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: LuaScriptRemoveEventHandler */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_UnsubscribeFromEvent01
static int tolua_LuaScriptLuaAPI_UnsubscribeFromEvent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Object* sender = ((Object*)  tolua_tousertype(tolua_S,1,0));
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
 {
  LuaScriptRemoveEventHandler(sender,eventName);
 }
 }
 return 0;
tolua_lerror:
 return tolua_LuaScriptLuaAPI_UnsubscribeFromEvent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: LuaScriptRemoveEventHandlers */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_UnsubscribeFromEvents00
static int tolua_LuaScriptLuaAPI_UnsubscribeFromEvents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Object* sender = ((Object*)  tolua_tousertype(tolua_S,1,0));
 {
  LuaScriptRemoveEventHandlers(sender);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnsubscribeFromEvents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: LuaScriptRemoveAllEventHandlers */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_UnsubscribeFromAllEvents00
static int tolua_LuaScriptLuaAPI_UnsubscribeFromAllEvents00(lua_State* tolua_S)
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
  LuaScriptRemoveAllEventHandlers();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnsubscribeFromAllEvents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: LuaScriptRemoveEventHandlersExcept */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_UnsubscribeFromAllEventsExcept00
static int tolua_LuaScriptLuaAPI_UnsubscribeFromAllEventsExcept00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !ToluaIsVector<String>(tolua_S,1,"String",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Vector<String>* exceptionNames = ((const Vector<String>*)  ToluaToVector<String>(tolua_S,1,0));
 {
  LuaScriptRemoveEventHandlersExcept(*exceptionNames);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnsubscribeFromAllEventsExcept'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: LuaScriptHasSubscribedToEvent */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_HasSubscribedToEvent00
static int tolua_LuaScriptLuaAPI_HasSubscribedToEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isurho3dstring(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  bool tolua_ret = (bool)  LuaScriptHasSubscribedToEvent(eventName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasSubscribedToEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: LuaScriptHasSubscribedToEvent */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_HasSubscribedToEvent01
static int tolua_LuaScriptLuaAPI_HasSubscribedToEvent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Object* sender = ((Object*)  tolua_tousertype(tolua_S,1,0));
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
 {
  bool tolua_ret = (bool)  LuaScriptHasSubscribedToEvent(sender,eventName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_LuaScriptLuaAPI_HasSubscribedToEvent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: LuaScriptSendEvent */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_SendEvent00
static int tolua_LuaScriptLuaAPI_SendEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isurho3dstring(tolua_S,1,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
  VariantMap* eventData = ((VariantMap*)  tolua_tousertype(tolua_S,2,0));
 {
  LuaScriptSendEvent(eventName,*eventData);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SendEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: LuaScriptSetExecuteConsoleCommands */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_SetExecuteConsoleCommands00
static int tolua_LuaScriptLuaAPI_SetExecuteConsoleCommands00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isboolean(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  bool enable = ((bool)  tolua_toboolean(tolua_S,1,0));
 {
  LuaScriptSetExecuteConsoleCommands(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetExecuteConsoleCommands'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: LuaScriptGetExecuteConsoleCommands */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_GetExecuteConsoleCommands00
static int tolua_LuaScriptLuaAPI_GetExecuteConsoleCommands00(lua_State* tolua_S)
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
  bool tolua_ret = (bool)  LuaScriptGetExecuteConsoleCommands();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetExecuteConsoleCommands'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: LuaScriptSetGlobalVar */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_SetGlobalVar00
static int tolua_LuaScriptLuaAPI_SetGlobalVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isurho3dstring(tolua_S,1,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String key = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
  Variant value = *((Variant*)  tolua_tousertype(tolua_S,2,0));
 {
  LuaScriptSetGlobalVar(key,value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetGlobalVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: LuaScriptGetGlobalVar */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_GetGlobalVar00
static int tolua_LuaScriptLuaAPI_GetGlobalVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isurho3dstring(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String key = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  Variant tolua_ret = (Variant)  LuaScriptGetGlobalVar(key);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Variant)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Variant");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Variant));
  tolua_pushusertype(tolua_S,tolua_obj,"Variant");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGlobalVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: LuaScriptGetGlobalVars */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_GetGlobalVars00
static int tolua_LuaScriptLuaAPI_GetGlobalVars00(lua_State* tolua_S)
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
  VariantMap& tolua_ret = (VariantMap&)  LuaScriptGetGlobalVars();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"VariantMap");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGlobalVars'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: RegisterEventName */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_RegisterEventName00
static int tolua_LuaScriptLuaAPI_RegisterEventName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isurho3dstring(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  RegisterEventName(eventName);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterEventName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateObject of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_CreateObject00
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_CreateObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaScriptInstance* self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
  const String scriptObjectType = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateObject'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->CreateObject(scriptObjectType);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateObject of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_CreateObject01
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_CreateObject01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"LuaFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  LuaScriptInstance* self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
  LuaFile* scriptFile = ((LuaFile*)  tolua_tousertype(tolua_S,2,0));
  const String scriptObjectType = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateObject'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->CreateObject(scriptFile,scriptObjectType);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_LuaScriptLuaAPI_LuaScriptInstance_CreateObject00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScriptFile of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_SetScriptFile00
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_SetScriptFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"LuaFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaScriptInstance* self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
  LuaFile* scriptFile = ((LuaFile*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScriptFile'", NULL);
#endif
 {
  self->SetScriptFile(scriptFile);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScriptFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScriptObjectType of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_SetScriptObjectType00
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_SetScriptObjectType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaScriptInstance* self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
  const String scriptObjectType = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScriptObjectType'", NULL);
#endif
 {
  self->SetScriptObjectType(scriptObjectType);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScriptObjectType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddEventHandler of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_SubscribeToEvent00
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_SubscribeToEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaScriptInstance* self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  void* functionOrFunctionName = ((void*)  tolua_touserdata(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddEventHandler'", NULL);
#endif
 {
  self->AddEventHandler(eventName,functionOrFunctionName);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SubscribeToEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddEventHandler of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_SubscribeToEvent01
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_SubscribeToEvent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isuserdata(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  LuaScriptInstance* self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
  void* sender = ((void*)  tolua_touserdata(tolua_S,2,0));
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
  void* functionOrFunctionName = ((void*)  tolua_touserdata(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddEventHandler'", NULL);
#endif
 {
  self->AddEventHandler(sender,eventName,functionOrFunctionName);
 }
 }
 return 0;
tolua_lerror:
 return tolua_LuaScriptLuaAPI_LuaScriptInstance_SubscribeToEvent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveEventHandler of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvent00
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaScriptInstance* self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveEventHandler'", NULL);
#endif
 {
  self->RemoveEventHandler(eventName);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnsubscribeFromEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveEventHandler of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvent01
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Object",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  LuaScriptInstance* self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
  Object* sender = ((Object*)  tolua_tousertype(tolua_S,2,0));
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveEventHandler'", NULL);
#endif
 {
  self->RemoveEventHandler(sender,eventName);
 }
 }
 return 0;
tolua_lerror:
 return tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveEventHandlers of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvents00
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaScriptInstance* self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
  Object* sender = ((Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveEventHandlers'", NULL);
#endif
 {
  self->RemoveEventHandlers(sender);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnsubscribeFromEvents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllEventHandlers of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromAllEvents00
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromAllEvents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaScriptInstance* self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllEventHandlers'", NULL);
#endif
 {
  self->RemoveAllEventHandlers();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnsubscribeFromAllEvents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveEventHandlersExcept of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromAllEventsExcept00
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromAllEventsExcept00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !ToluaIsVector<String>(tolua_S,2,"String",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaScriptInstance* self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
  const Vector<String>* exceptionNames = ((const Vector<String>*)  ToluaToVector<String>(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveEventHandlersExcept'", NULL);
#endif
 {
  self->RemoveEventHandlersExcept(*exceptionNames);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnsubscribeFromAllEventsExcept'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasEventHandler of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_HasSubscribedToEvent00
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_HasSubscribedToEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaScriptInstance* self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasEventHandler'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasEventHandler(eventName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasSubscribedToEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasEventHandler of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_HasSubscribedToEvent01
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_HasSubscribedToEvent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaScriptInstance",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Object",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  LuaScriptInstance* self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
  Object* sender = ((Object*)  tolua_tousertype(tolua_S,2,0));
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasEventHandler'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasEventHandler(sender,eventName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_LuaScriptLuaAPI_LuaScriptInstance_HasSubscribedToEvent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScriptFile of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_GetScriptFile00
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_GetScriptFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const LuaScriptInstance",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const LuaScriptInstance* self = (const LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScriptFile'", NULL);
#endif
 {
  LuaFile* tolua_ret = (LuaFile*)  self->GetScriptFile();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaFile");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScriptFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScriptObjectType of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_LuaScriptLuaAPI_LuaScriptInstance_GetScriptObjectType00
static int tolua_LuaScriptLuaAPI_LuaScriptInstance_GetScriptObjectType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const LuaScriptInstance",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const LuaScriptInstance* self = (const LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScriptObjectType'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetScriptObjectType();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScriptObjectType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scriptFile of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_get_LuaScriptInstance_scriptFile_ptr
static int tolua_get_LuaScriptInstance_scriptFile_ptr(lua_State* tolua_S)
{
  LuaScriptInstance* self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scriptFile'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetScriptFile(),"const LuaFile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scriptObjectType of class  LuaScriptInstance */
#ifndef TOLUA_DISABLE_tolua_get_LuaScriptInstance_scriptObjectType
static int tolua_get_LuaScriptInstance_scriptObjectType(lua_State* tolua_S)
{
  LuaScriptInstance* self = (LuaScriptInstance*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scriptObjectType'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetScriptObjectType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_LuaScriptLuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);

 { /* begin embedded lua code */
  int top = lua_gettop(tolua_S);
  static const unsigned char B[] = {
  10,108,111, 99, 97,108, 32,116,111,116, 97,108, 84,105,109,
  101, 95, 32, 61, 32, 48, 10,108,111, 99, 97,108, 32,115,108,
  101,101,112,101,100, 67,111,114,111,117,116,105,110,101,115,
   95, 32, 61, 32,123,125, 10,108,111, 99, 97,108, 32,119, 97,
  105,116, 69,118,101,110,116, 67,111,114,111,117,116,105,110,
  101,115, 95, 32, 61, 32,123,125, 10,102,117,110, 99,116,105,
  111,110, 32, 99,111,114,111,117,116,105,110,101, 46,115,116,
   97,114,116, 40,102,117,110, 99, 41, 10,105,102, 32,102,117,
  110, 99, 32, 61, 61, 32,110,105,108, 32,116,104,101,110, 10,
  114,101,116,117,114,110, 32,110,105,108, 10,101,110,100, 10,
  108,111, 99, 97,108, 32, 99,111, 32, 61, 32, 99,111,114,111,
  117,116,105,110,101, 46, 99,114,101, 97,116,101, 40,102,117,
  110, 99, 41, 10,114,101,116,117,114,110, 32, 99,111,114,111,
  117,116,105,110,101, 46,114,101,115,117,109,101, 40, 99,111,
   41, 10,101,110,100, 10,102,117,110, 99,116,105,111,110, 32,
   99,111,114,111,117,116,105,110,101, 46,115,108,101,101,112,
   40,116,105,109,101, 41, 10,108,111, 99, 97,108, 32, 99,111,
   32, 61, 32, 99,111,114,111,117,116,105,110,101, 46,114,117,
  110,110,105,110,103, 40, 41, 10,105,102, 32, 99,111, 32, 61,
   61, 32,110,105,108, 32,116,104,101,110, 10,114,101,116,117,
  114,110, 10,101,110,100, 10,115,108,101,101,112,101,100, 67,
  111,114,111,117,116,105,110,101,115, 95, 91, 99,111, 93, 32,
   61, 32,116,111,116, 97,108, 84,105,109,101, 95, 32, 43, 32,
  116,105,109,101, 10,114,101,116,117,114,110, 32, 99,111,114,
  111,117,116,105,110,101, 46,121,105,101,108,100, 40, 99,111,
   41, 10,101,110,100, 10,102,117,110, 99,116,105,111,110, 32,
   99,111,114,111,117,116,105,110,101, 46,117,112,100, 97,116,
  101, 40,115,116,101,112,116,105,109,101, 41, 10,116,111,116,
   97,108, 84,105,109,101, 95, 32, 61, 32,116,111,116, 97,108,
   84,105,109,101, 95, 32, 43, 32,115,116,101,112,116,105,109,
  101, 10,108,111, 99, 97,108, 32, 99,111,114,111,117,116,105,
  110,101,115, 32, 61, 32,123,125, 10,102,111,114, 32, 99,111,
   44, 32,119, 97,107,101,117,112, 84,105,109,101, 32,105,110,
   32,112, 97,105,114,115, 40,115,108,101,101,112,101,100, 67,
  111,114,111,117,116,105,110,101,115, 95, 41, 32,100,111, 10,
  105,102, 32,119, 97,107,101,117,112, 84,105,109,101, 32, 60,
   32,116,111,116, 97,108, 84,105,109,101, 95, 32,116,104,101,
  110, 10,116, 97, 98,108,101, 46,105,110,115,101,114,116, 40,
   99,111,114,111,117,116,105,110,101,115, 44, 32, 99,111, 41,
   10,101,110,100, 10,101,110,100, 10,102,111,114, 32, 95, 44,
   32, 99,111, 32,105,110, 32,105,112, 97,105,114,115, 40, 99,
  111,114,111,117,116,105,110,101,115, 41, 32,100,111, 10,115,
  108,101,101,112,101,100, 67,111,114,111,117,116,105,110,101,
  115, 95, 91, 99,111, 93, 32, 61, 32,110,105,108, 10, 99,111,
  114,111,117,116,105,110,101, 46,114,101,115,117,109,101, 40,
   99,111, 41, 10,101,110,100, 10,101,110,100, 10,102,117,110,
   99,116,105,111,110, 32, 99,111,114,111,117,116,105,110,101,
   46,119, 97,105,116,101,118,101,110,116, 40,101,118,101,110,
  116, 41, 10,108,111, 99, 97,108, 32, 99,111, 32, 61, 32, 99,
  111,114,111,117,116,105,110,101, 46,114,117,110,110,105,110,
  103, 40, 41, 10,105,102, 32, 99,111, 32, 61, 61, 32,110,105,
  108, 32,116,104,101,110, 10,114,101,116,117,114,110, 10,101,
  110,100, 10,105,102, 32,119, 97,105,116, 69,118,101,110,116,
   67,111,114,111,117,116,105,110,101,115, 95, 91,101,118,101,
  110,116, 93, 32, 61, 61, 32,110,105,108, 32,116,104,101,110,
   10,119, 97,105,116, 69,118,101,110,116, 67,111,114,111,117,
  116,105,110,101,115, 95, 91,101,118,101,110,116, 93, 32, 61,
   32,123, 32, 99,111, 32,125, 10,101,108,115,101, 10,116, 97,
   98,108,101, 46,105,110,115,101,114,116, 40,119, 97,105,116,
   69,118,101,110,116, 67,111,114,111,117,116,105,110,101,115,
   95, 91,101,118,101,110,116, 93, 44, 32, 99,111, 41, 10,101,
  110,100, 10,114,101,116,117,114,110, 32, 99,111,114,111,117,
  116,105,110,101, 46,121,105,101,108,100, 40, 99,111, 41, 10,
  101,110,100, 10,102,117,110, 99,116,105,111,110, 32, 99,111,
  114,111,117,116,105,110,101, 46,115,101,110,100,101,118,101,
  110,116, 40,101,118,101,110,116, 41, 10,108,111, 99, 97,108,
   32, 99,111,114,111,117,116,105,110,101,115, 32, 61, 32,119,
   97,105,116, 69,118,101,110,116, 67,111,114,111,117,116,105,
  110,101,115, 95, 91,101,118,101,110,116, 93, 10,105,102, 32,
   99,111,114,111,117,116,105,110,101,115, 32, 61, 61, 32,110,
  105,108, 32,116,104,101,110, 10,114,101,116,117,114,110, 10,
  101,110,100, 10,119, 97,105,116, 69,118,101,110,116, 67,111,
  114,111,117,116,105,110,101,115, 95, 91,101,118,101,110,116,
   93, 32, 61, 32,110,105,108, 10,102,111,114, 32, 95, 44, 32,
   99,111, 32,105,110, 32,105,112, 97,105,114,115, 40, 99,111,
  114,111,117,116,105,110,101,115, 41, 32,100,111, 10, 99,111,
  114,111,117,116,105,110,101, 46,114,101,115,117,109,101, 40,
   99,111, 41, 10,101,110,100, 10,101,110,100, 45, 45,32
  };
  tolua_dobuffer(tolua_S,(char*)B,sizeof(B),"tolua: embedded Lua code 1");
  lua_settop(tolua_S, top);
 } /* end of embedded lua code */

 tolua_function(tolua_S,"SubscribeToEvent",tolua_LuaScriptLuaAPI_SubscribeToEvent00);
 tolua_function(tolua_S,"SubscribeToEvent",tolua_LuaScriptLuaAPI_SubscribeToEvent01);
 tolua_function(tolua_S,"UnsubscribeFromEvent",tolua_LuaScriptLuaAPI_UnsubscribeFromEvent00);
 tolua_function(tolua_S,"UnsubscribeFromEvent",tolua_LuaScriptLuaAPI_UnsubscribeFromEvent01);
 tolua_function(tolua_S,"UnsubscribeFromEvents",tolua_LuaScriptLuaAPI_UnsubscribeFromEvents00);
 tolua_function(tolua_S,"UnsubscribeFromAllEvents",tolua_LuaScriptLuaAPI_UnsubscribeFromAllEvents00);
 tolua_function(tolua_S,"UnsubscribeFromAllEventsExcept",tolua_LuaScriptLuaAPI_UnsubscribeFromAllEventsExcept00);
 tolua_function(tolua_S,"HasSubscribedToEvent",tolua_LuaScriptLuaAPI_HasSubscribedToEvent00);
 tolua_function(tolua_S,"HasSubscribedToEvent",tolua_LuaScriptLuaAPI_HasSubscribedToEvent01);
 tolua_function(tolua_S,"SendEvent",tolua_LuaScriptLuaAPI_SendEvent00);
 tolua_function(tolua_S,"SetExecuteConsoleCommands",tolua_LuaScriptLuaAPI_SetExecuteConsoleCommands00);
 tolua_function(tolua_S,"GetExecuteConsoleCommands",tolua_LuaScriptLuaAPI_GetExecuteConsoleCommands00);
 tolua_function(tolua_S,"SetGlobalVar",tolua_LuaScriptLuaAPI_SetGlobalVar00);
 tolua_function(tolua_S,"GetGlobalVar",tolua_LuaScriptLuaAPI_GetGlobalVar00);
 tolua_function(tolua_S,"GetGlobalVars",tolua_LuaScriptLuaAPI_GetGlobalVars00);
 tolua_function(tolua_S,"RegisterEventName",tolua_LuaScriptLuaAPI_RegisterEventName00);
 tolua_cclass(tolua_S,"LuaScriptInstance","LuaScriptInstance","Component",NULL);
 tolua_beginmodule(tolua_S,"LuaScriptInstance");
  tolua_function(tolua_S,"CreateObject",tolua_LuaScriptLuaAPI_LuaScriptInstance_CreateObject00);
  tolua_function(tolua_S,"CreateObject",tolua_LuaScriptLuaAPI_LuaScriptInstance_CreateObject01);
  tolua_function(tolua_S,"SetScriptFile",tolua_LuaScriptLuaAPI_LuaScriptInstance_SetScriptFile00);
  tolua_function(tolua_S,"SetScriptObjectType",tolua_LuaScriptLuaAPI_LuaScriptInstance_SetScriptObjectType00);
  tolua_function(tolua_S,"SubscribeToEvent",tolua_LuaScriptLuaAPI_LuaScriptInstance_SubscribeToEvent00);
  tolua_function(tolua_S,"SubscribeToEvent",tolua_LuaScriptLuaAPI_LuaScriptInstance_SubscribeToEvent01);
  tolua_function(tolua_S,"UnsubscribeFromEvent",tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvent00);
  tolua_function(tolua_S,"UnsubscribeFromEvent",tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvent01);
  tolua_function(tolua_S,"UnsubscribeFromEvents",tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromEvents00);
  tolua_function(tolua_S,"UnsubscribeFromAllEvents",tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromAllEvents00);
  tolua_function(tolua_S,"UnsubscribeFromAllEventsExcept",tolua_LuaScriptLuaAPI_LuaScriptInstance_UnsubscribeFromAllEventsExcept00);
  tolua_function(tolua_S,"HasSubscribedToEvent",tolua_LuaScriptLuaAPI_LuaScriptInstance_HasSubscribedToEvent00);
  tolua_function(tolua_S,"HasSubscribedToEvent",tolua_LuaScriptLuaAPI_LuaScriptInstance_HasSubscribedToEvent01);
  tolua_function(tolua_S,"GetScriptFile",tolua_LuaScriptLuaAPI_LuaScriptInstance_GetScriptFile00);
  tolua_function(tolua_S,"GetScriptObjectType",tolua_LuaScriptLuaAPI_LuaScriptInstance_GetScriptObjectType00);
  tolua_variable(tolua_S,"scriptFile",tolua_get_LuaScriptInstance_scriptFile_ptr,NULL);
  tolua_variable(tolua_S,"scriptObjectType",tolua_get_LuaScriptInstance_scriptObjectType,NULL);
 tolua_endmodule(tolua_S);

 { /* begin embedded lua code */
  int top = lua_gettop(tolua_S);
  static const unsigned char B[] = {
  10, 76,117, 97, 83, 99,114,105,112,116, 79, 98,106,101, 99,
  116, 32, 61, 32,123,125, 10,102,117,110, 99,116,105,111,110,
   32, 76,117, 97, 83, 99,114,105,112,116, 79, 98,106,101, 99,
  116, 58, 83,116, 97,114,116, 40, 41, 10,101,110,100, 10,102,
  117,110, 99,116,105,111,110, 32, 76,117, 97, 83, 99,114,105,
  112,116, 79, 98,106,101, 99,116, 58, 83,116,111,112, 40, 41,
   10,101,110,100, 10,102,117,110, 99,116,105,111,110, 32, 76,
  117, 97, 83, 99,114,105,112,116, 79, 98,106,101, 99,116, 58,
   71,101,116, 78,111,100,101, 40, 41, 10,114,101,116,117,114,
  110, 32,115,101,108,102, 46,110,111,100,101, 10,101,110,100,
   10,102,117,110, 99,116,105,111,110, 32, 76,117, 97, 83, 99,
  114,105,112,116, 79, 98,106,101, 99,116, 58, 83,117, 98,115,
   99,114,105, 98,101, 84,111, 69,118,101,110,116, 40,112, 97,
  114, 97,109, 49, 44, 32,112, 97,114, 97,109, 50, 44, 32,112,
   97,114, 97,109, 51, 41, 10,108,111, 99, 97,108, 32,105,110,
  115,116, 97,110, 99,101, 32, 61, 32,115,101,108,102, 46,105,
  110,115,116, 97,110, 99,101, 10,105,102, 32,105,110,115,116,
   97,110, 99,101, 32, 61, 61, 32,110,105,108, 32,116,104,101,
  110, 10,114,101,116,117,114,110, 10,101,110,100, 10,105,102,
   32,112, 97,114, 97,109, 51, 32, 61, 61, 32,110,105,108, 32,
  116,104,101,110, 10,105,110,115,116, 97,110, 99,101, 58, 83,
  117, 98,115, 99,114,105, 98,101, 84,111, 69,118,101,110,116,
   40,112, 97,114, 97,109, 49, 44, 32,112, 97,114, 97,109, 50,
   41, 10,101,108,115,101, 10,105,110,115,116, 97,110, 99,101,
   58, 83,117, 98,115, 99,114,105, 98,101, 84,111, 69,118,101,
  110,116, 40,112, 97,114, 97,109, 49, 44, 32,112, 97,114, 97,
  109, 50, 44, 32,112, 97,114, 97,109, 51, 41, 10,101,110,100,
   10,101,110,100, 10,102,117,110, 99,116,105,111,110, 32, 76,
  117, 97, 83, 99,114,105,112,116, 79, 98,106,101, 99,116, 58,
   85,110,115,117, 98,115, 99,114,105, 98,101, 70,114,111,109,
   69,118,101,110,116, 40,112, 97,114, 97,109, 49, 44, 32,112,
   97,114, 97,109, 50, 41, 10,108,111, 99, 97,108, 32,105,110,
  115,116, 97,110, 99,101, 32, 61, 32,115,101,108,102, 46,105,
  110,115,116, 97,110, 99,101, 10,105,102, 32,105,110,115,116,
   97,110, 99,101, 32, 61, 61, 32,110,105,108, 32,116,104,101,
  110, 10,114,101,116,117,114,110, 10,101,110,100, 10,105,102,
   32,112, 97,114, 97,109, 50, 32, 61, 61, 32,110,105,108, 32,
  116,104,101,110, 10,105,110,115,116, 97,110, 99,101, 58, 85,
  110,115,117, 98,115, 99,114,105, 98,101, 70,114,111,109, 69,
  118,101,110,116, 40,112, 97,114, 97,109, 49, 41, 10,101,108,
  115,101, 10,105,110,115,116, 97,110, 99,101, 58, 85,110,115,
  117, 98,115, 99,114,105, 98,101, 70,114,111,109, 69,118,101,
  110,116, 40,112, 97,114, 97,109, 49, 44, 32,112, 97,114, 97,
  109, 50, 41, 10,101,110,100, 10,101,110,100, 10,102,117,110,
   99,116,105,111,110, 32, 76,117, 97, 83, 99,114,105,112,116,
   79, 98,106,101, 99,116, 58, 85,110,115,117, 98,115, 99,114,
  105, 98,101, 70,114,111,109, 69,118,101,110,116,115, 40,115,
  101,110,100,101,114, 41, 10,108,111, 99, 97,108, 32,105,110,
  115,116, 97,110, 99,101, 32, 61, 32,115,101,108,102, 46,105,
  110,115,116, 97,110, 99,101, 10,105,102, 32,105,110,115,116,
   97,110, 99,101, 32, 61, 61, 32,110,105,108, 32,116,104,101,
  110, 10,114,101,116,117,114,110, 10,101,110,100, 10,105,110,
  115,116, 97,110, 99,101, 58, 85,110,115,117, 98,115, 99,114,
  105, 98,101, 70,114,111,109, 69,118,101,110,116,115, 40,115,
  101,110,100,101,114, 41, 10,101,110,100, 10,102,117,110, 99,
  116,105,111,110, 32, 76,117, 97, 83, 99,114,105,112,116, 79,
   98,106,101, 99,116, 58, 85,110,115,117, 98,115, 99,114,105,
   98,101, 70,114,111,109, 65,108,108, 69,118,101,110,116,115,
   40, 41, 10,108,111, 99, 97,108, 32,105,110,115,116, 97,110,
   99,101, 32, 61, 32,115,101,108,102, 46,105,110,115,116, 97,
  110, 99,101, 10,105,102, 32,105,110,115,116, 97,110, 99,101,
   32, 61, 61, 32,110,105,108, 32,116,104,101,110, 10,114,101,
  116,117,114,110, 10,101,110,100, 10,105,110,115,116, 97,110,
   99,101, 58, 85,110,115,117, 98,115, 99,114,105, 98,101, 70,
  114,111,109, 65,108,108, 69,118,101,110,116,115, 40, 41, 10,
  101,110,100, 10,102,117,110, 99,116,105,111,110, 32, 76,117,
   97, 83, 99,114,105,112,116, 79, 98,106,101, 99,116, 58, 85,
  110,115,117, 98,115, 99,114,105, 98,101, 70,114,111,109, 65,
  108,108, 69,118,101,110,116,115, 69,120, 99,101,112,116, 40,
   41, 10,108,111, 99, 97,108, 32,105,110,115,116, 97,110, 99,
  101, 32, 61, 32,115,101,108,102, 46,105,110,115,116, 97,110,
   99,101, 10,105,102, 32,105,110,115,116, 97,110, 99,101, 32,
   61, 61, 32,110,105,108, 32,116,104,101,110, 10,114,101,116,
  117,114,110, 10,101,110,100, 10,105,110,115,116, 97,110, 99,
  101, 58, 85,110,115,117, 98,115, 99,114,105, 98,101, 70,114,
  111,109, 65,108,108, 69,118,101,110,116,115, 69,120, 99,101,
  112,116, 40, 41, 10,101,110,100, 10,102,117,110, 99,116,105,
  111,110, 32, 76,117, 97, 83, 99,114,105,112,116, 79, 98,106,
  101, 99,116, 58, 72, 97,115, 83,117, 98,115, 99,114,105, 98,
  101,100, 84,111, 69,118,101,110,116, 40,112, 97,114, 97,109,
   49, 44, 32,112, 97,114, 97,109, 50, 41, 10,108,111, 99, 97,
  108, 32,105,110,115,116, 97,110, 99,101, 32, 61, 32,115,101,
  108,102, 46,105,110,115,116, 97,110, 99,101, 10,105,102, 32,
  105,110,115,116, 97,110, 99,101, 32, 61, 61, 32,110,105,108,
   32,116,104,101,110, 10,114,101,116,117,114,110, 10,101,110,
  100, 10,105,102, 32,112, 97,114, 97,109, 50, 32, 61, 61, 32,
  110,105,108, 32,116,104,101,110, 10,114,101,116,117,114,110,
   32,105,110,115,116, 97,110, 99,101, 58, 72, 97,115, 83,117,
   98,115, 99,114,105, 98,101,100, 84,111, 69,118,101,110,116,
   40,112, 97,114, 97,109, 49, 41, 10,101,108,115,101, 10,114,
  101,116,117,114,110, 32,105,110,115,116, 97,110, 99,101, 58,
   72, 97,115, 83,117, 98,115, 99,114,105, 98,101,100, 84,111,
   69,118,101,110,116, 40,112, 97,114, 97,109, 49, 44, 32,112,
   97,114, 97,109, 50, 41, 10,101,110,100, 10,101,110,100, 10,
  102,117,110, 99,116,105,111,110, 32, 83, 99,114,105,112,116,
   79, 98,106,101, 99,116, 40, 41, 10,108,111, 99, 97,108, 32,
  111, 32, 61, 32,123,125, 10,115,101,116,109,101,116, 97,116,
   97, 98,108,101, 40,111, 44, 32, 76,117, 97, 83, 99,114,105,
  112,116, 79, 98,106,101, 99,116, 41, 10, 76,117, 97, 83, 99,
  114,105,112,116, 79, 98,106,101, 99,116, 46, 95, 95,105,110,
  100,101,120, 32, 61, 32, 76,117, 97, 83, 99,114,105,112,116,
   79, 98,106,101, 99,116, 10,114,101,116,117,114,110, 32,111,
   10,101,110,100, 10,102,117,110, 99,116,105,111,110, 32, 67,
  114,101, 97,116,101, 83, 99,114,105,112,116, 79, 98,106,101,
   99,116, 73,110,115,116, 97,110, 99,101, 40,111, 98,106,101,
   99,116, 44, 32,105,110,115,116, 97,110, 99,101, 41, 10,108,
  111, 99, 97,108, 32,111, 32, 61, 32,123,125, 10,115,101,116,
  109,101,116, 97,116, 97, 98,108,101, 40,111, 44, 32,111, 98,
  106,101, 99,116, 41, 10,111, 98,106,101, 99,116, 46, 95, 95,
  105,110,100,101,120, 32, 61, 32,111, 98,106,101, 99,116, 10,
  105,110,115,116, 97,110, 99,101, 46,111, 98,106,101, 99,116,
   32, 61, 32,111, 10,111, 46,105,110,115,116, 97,110, 99,101,
   32, 61, 32,105,110,115,116, 97,110, 99,101, 10,111, 46,110,
  111,100,101, 32, 61, 32,105,110,115,116, 97,110, 99,101, 58,
   71,101,116, 78,111,100,101, 40, 41, 10,108,111, 99, 97,108,
   32,107,101,121,115, 32, 61, 32,123,125, 10,102,111,114, 32,
  107, 44, 32,118, 32,105,110, 32,112, 97,105,114,115, 40,111,
   41, 32,100,111, 10,107,101,121,115, 91,107, 93, 32, 61, 32,
  116,114,117,101, 10,101,110,100, 10,111, 58, 83,116, 97,114,
  116, 40, 41, 10,108,111, 99, 97,108, 32, 97,116,116,114, 78,
   97,109,101,115, 32, 61, 32,123,125, 10,102,111,114, 32,107,
   44, 32,118, 32,105,110, 32,112, 97,105,114,115, 40,111, 41,
   32,100,111, 10,105,102, 32,107,101,121,115, 91,107, 93, 32,
   61, 61, 32,110,105,108, 32,116,104,101,110, 10,116, 97, 98,
  108,101, 46,105,110,115,101,114,116, 40, 97,116,116,114, 78,
   97,109,101,115, 44, 32,107, 41, 10,101,110,100, 10,101,110,
  100, 10,114,101,116,117,114,110, 32,111, 44, 32, 97,116,116,
  114, 78, 97,109,101,115, 10,101,110,100, 10,102,117,110, 99,
  116,105,111,110, 32, 68,101,115,116,114,111,121, 83, 99,114,
  105,112,116, 79, 98,106,101, 99,116, 73,110,115,116, 97,110,
   99,101, 40,105,110,115,116, 97,110, 99,101, 41, 10,108,111,
   99, 97,108, 32,111, 98,106,101, 99,116, 32, 61, 32,105,110,
  115,116, 97,110, 99,101, 46,111, 98,106,101, 99,116, 10,105,
  102, 32,111, 98,106,101, 99,116, 32, 61, 61, 32,110,105,108,
   32,116,104,101,110, 10,114,101,116,117,114,110, 10,101,110,
  100, 10,111, 98,106,101, 99,116, 58, 83,116,111,112, 40, 41,
   10,111, 98,106,101, 99,116, 46,110,111,100,101, 32, 61, 32,
  110,105,108, 10,111, 98,106,101, 99,116, 46,105,110,115,116,
   97,110, 99,101, 32, 61, 32,110,105,108, 10,105,110,115,116,
   97,110, 99,101, 46,111, 98,106,101, 99,116, 32, 61, 32,110,
  105,108, 10,101,110,100, 45, 45, 45, 45, 45, 45,32
  };
  tolua_dobuffer(tolua_S,(char*)B,sizeof(B),"tolua: embedded Lua code 2");
  lua_settop(tolua_S, top);
 } /* end of embedded lua code */

 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_LuaScriptLuaAPI (lua_State* tolua_S) {
 return tolua_LuaScriptLuaAPI_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif