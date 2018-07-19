/*
** Lua binding: CoreLuaAPI
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
TOLUA_API int tolua_CoreLuaAPI_open (lua_State* tolua_S);

#include "Core/Context.h"
#include "Core/Object.h"
#include "Core/ProcessUtils.h"
#include "Core/StringUtils.h"
#include "Core/Variant.h"
#include "IO/VectorBuffer.h"
#include "Core/Spline.h"
#include "Core/Timer.h"
using namespace Urho3D;
#pragma warning(disable:4800)


#define TOLUA_DISABLE_tolua_CoreLuaAPI_GetContext00
static int tolua_CoreLuaAPI_GetContext00(lua_State* tolua_S)
{
    tolua_pushusertype(tolua_S, (void*)GetContext(tolua_S), "Context");
    return 1;
}

#define TOLUA_DISABLE_tolua_get_context_ptr
static int tolua_get_context_ptr(lua_State* tolua_S)
{
    return tolua_CoreLuaAPI_GetContext00(tolua_S);
}

#define TOLUA_DISABLE_tolua_CoreLuaAPI_GetEventSender00
static int tolua_CoreLuaAPI_GetEventSender00(lua_State* tolua_S)
{
    // Could be null outside event handling
    Object* tolua_ret = GetContext(tolua_S)->GetEventSender();
    if (tolua_ret)
        tolua_pushusertype(tolua_S, (void*)tolua_ret, "Object");
    else
        lua_pushnil(tolua_S);
    return 1;
}

#define TOLUA_DISABLE_tolua_get_eventSender_ptr
static int tolua_get_eventSender_ptr(lua_State* tolua_S)
{
    return tolua_CoreLuaAPI_GetEventSender00(tolua_S);
}

#define TOLUA_DISABLE_tolua_CoreLuaAPI_GetEventHandler00
static int tolua_CoreLuaAPI_GetEventHandler00(lua_State* tolua_S)
{
    EventHandler* tolua_ret = GetContext(tolua_S)->GetEventHandler();
    if (tolua_ret)
        tolua_pushusertype(tolua_S, (void*)tolua_ret, "EventHandler");
    else
        lua_pushnil(tolua_S);
    return 1;
}

#define TOLUA_DISABLE_tolua_get_eventHandler_ptr
static int tolua_get_eventHandler_ptr(lua_State* tolua_S)
{
    return tolua_CoreLuaAPI_GetEventHandler00(tolua_S);
}

static void ObjectSendEvent(Object* object, const String eventName, VariantMap* eventData = 0)
{
    if (eventData)
        object->SendEvent(StringHash(eventName), *eventData);
    else
        object->SendEvent(StringHash(eventName));
}

static bool ObjectHasSubscribedToEvent(const Object* object, const String eventName)
{
    return object->HasSubscribedToEvent(StringHash(eventName));
}

static bool ObjectHasSubscribedToSenderEvent(const Object* object, Object* sender, const String eventName)
{
    return object->HasSubscribedToEvent(sender, StringHash(eventName));
}


static int VariantToStringEventHandler(lua_State* tolua_S)
{
    lua_pushstring(tolua_S, static_cast<Variant*>(tolua_tousertype(tolua_S, -1, 0))->ToString().CString());
    return 1;
}

static int VariantConcatEventHandler(lua_State* tolua_S)
{
    // __concat event handler has two operands, check whether the first operand is variant or the second is (one of them must be)
    // This event handler has two code branches to handle both cases differently based on the isFirst flag
    // In case of both operands are variant then the handler handles the case as if it is isFirst case then below lua_concat() call
    //   would in turn trigger the handler the second time to handle the second operand using the !isFirst code branch
    bool isFirst = lua_isuserdata(tolua_S, 1);
    if (isFirst)
        lua_pushvalue(tolua_S, 1);              // isFirst stack: variant1 operand2 variant1
    VariantToStringEventHandler(tolua_S);       // isFirst stack: variant1 operand2 variant1 string1 | !isFirst: operand1 variant2 string2
    if (isFirst)
    {
        lua_replace(tolua_S, 1);                // isFirst stack: string1 operand2 variant1
        lua_pop(tolua_S, 1);                    // isFirst stack: string1 operand2
    }
    else
        lua_remove(tolua_S, -2);                // !isFirst stack: operand1 string2
    lua_concat(tolua_S, 2);
    return 1;
}

#define TOLUA_DISABLE_tolua_CoreLuaAPI_Variant__Setup00
static int tolua_CoreLuaAPI_Variant__Setup00(lua_State* tolua_S)
{
    // Register our own version of metamethod to handle __tostring and __concat events
    luaL_getmetatable(tolua_S, tolua_tostring(tolua_S, 2, 0));
    lua_pushstring(tolua_S, "__tostring");
    lua_pushcfunction(tolua_S, VariantToStringEventHandler);
    lua_rawset(tolua_S, -3);
    lua_pushstring(tolua_S, "__concat");
    lua_pushcfunction(tolua_S, VariantConcatEventHandler);
    lua_rawset(tolua_S, -3);
    lua_pop(tolua_S, 1);
    return 0;
}

// NOTE: the index number must match with the above variant constructor overloads order)

// Forward declaration
static int tolua_CoreLuaAPI_Variant_new00(lua_State* tolua_S);
static int tolua_CoreLuaAPI_Variant_new00_local(lua_State* tolua_S);

static bool VariantNewImpl(lua_State* tolua_S, bool gc)
{
    tolua_Error tolua_err;
    if (tolua_isusertable(tolua_S, 1, "Variant", 0, &tolua_err) && lua_gettop(tolua_S) == 2)
    {
        Variant* tolua_ret = Mtolua_new(Variant());
        ToluaToVariant(tolua_S, 2, 0, *tolua_ret);
        tolua_pushusertype(tolua_S, static_cast<void*>(tolua_ret), "Variant");
        if (gc)
            tolua_register_gc(tolua_S, lua_gettop(tolua_S));
        return true;
    }
    return false;
}

#define TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_new01
static int tolua_CoreLuaAPI_Variant_new01(lua_State* tolua_S)
{
    return VariantNewImpl(tolua_S, false) ? 1 : tolua_CoreLuaAPI_Variant_new00(tolua_S);
}

#define TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_new01_local
static int tolua_CoreLuaAPI_Variant_new01_local(lua_State* tolua_S)
{
    return VariantNewImpl(tolua_S, true) ? 1 : tolua_CoreLuaAPI_Variant_new00_local(tolua_S);
}

#define TOLUA_DISABLE_tolua_CoreLuaAPI_Variant__eq00
static int tolua_CoreLuaAPI_Variant__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (tolua_isusertype(tolua_S, 1, "const Variant", 0, &tolua_err) && lua_gettop(tolua_S) == 2)
#endif
    {
        const Variant* self = static_cast<const Variant*>(tolua_tousertype(tolua_S, 1, 0));
        Variant rhs;
        ToluaToVariant(tolua_S, 2, 0, rhs);
#ifndef TOLUA_RELEASE
        if (!self)
            tolua_error(tolua_S, "invalid 'self' in function 'operator=='", NULL);
        else
#endif
        {
            tolua_pushboolean(tolua_S, self->operator ==(rhs));
            return 1;
        }
    }
#ifndef TOLUA_RELEASE
    tolua_error(tolua_S, "#ferror in function '.eq'.", &tolua_err);
    return 0;
#endif
}

#define TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_Set00
static int tolua_CoreLuaAPI_Variant_Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (tolua_isusertype(tolua_S, 1, "Variant", 0, &tolua_err) && lua_gettop(tolua_S) == 2)
#endif
    {
        Variant * self = static_cast<Variant*>(tolua_tousertype(tolua_S, 1, 0));
        Variant rhs;
        ToluaToVariant(tolua_S, 2, 0, rhs);
        const char* type = tolua_tostring(tolua_S, 3, 0);
#ifndef TOLUA_RELEASE
        if (!self)
            tolua_error(tolua_S, "invalid 'self' in function 'Set'", NULL);
        else
#endif
        {
            *self = rhs;
            return 0;
        }
    }
#ifndef TOLUA_RELEASE
    tolua_error(tolua_S, "#ferror in function 'Set'.", &tolua_err);
    return 0;
#endif
}

#define TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_Get00
static int tolua_CoreLuaAPI_Variant_Get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (tolua_isusertype(tolua_S, 1, "const Variant", 0, &tolua_err) && tolua_isstring(tolua_S, 2, 1, &tolua_err) &&
        tolua_isnoobj(tolua_S, 3, &tolua_err))
#endif
    {
        const Variant* self = static_cast<const Variant*>(tolua_tousertype(tolua_S, 1, 0));
        const char* type = tolua_tostring(tolua_S, 2, 0);
#ifndef TOLUA_RELEASE
        if (!self)
            tolua_error(tolua_S, "invalid 'self' in function 'Get'", NULL);
        else
#endif
        {
            ToluaPushVariant(tolua_S, self, type);
            return 1;
        }
    }
#ifndef TOLUA_RELEASE
    tolua_error(tolua_S, "#ferror in function 'Get'.", &tolua_err);
    return 0;
#endif
}

#define TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetVoidPtr00
static int tolua_CoreLuaAPI_Variant_GetVoidPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
  const char* type = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVoidPtr'", NULL);
#endif
 {
     // Use the safer version which first check the type provided through Lua script to prevent VM crashes on invalid type
     ToluaPushRegisteredUserType(tolua_S, static_cast<void*>(self->GetVoidPtr()), type);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVoidPtr'.",&tolua_err);
 return 0;
#endif
}

#define TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetPtr00
static int tolua_CoreLuaAPI_Variant_GetPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
  const char* type = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPtr'", NULL);
#endif
 {
     ToluaPushRegisteredUserType(tolua_S, static_cast<void*>(self->GetPtr()), type);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPtr'.",&tolua_err);
 return 0;
#endif
}


static int VariantMapIndexEventHandler(lua_State* tolua_S)
{
    int t = lua_type(tolua_S, 2);
    StringHash key;
    if (t == LUA_TSTRING)
        key = StringHash(lua_tostring(tolua_S, 2));
    else if (t == LUA_TNUMBER)
        key = StringHash((unsigned)lua_tonumber(tolua_S, 2));
    else if (t == LUA_TUSERDATA)
    {
        tolua_Error error;
        if (tolua_isusertype(tolua_S, 2, "StringHash", 0, &error))
            key = *static_cast<StringHash*>(tolua_tousertype(tolua_S, 2, 0));
    }
    Variant* variant = key ? static_cast<const VariantMap*>(tolua_tousertype(tolua_S, 1, 0))->operator [](key) : 0;
    if (variant)
        tolua_pushusertype(tolua_S, variant, "Variant");
    else
        lua_pushnil(tolua_S);
    return 1;
}

static int VariantMapNewIndexEventHandler(lua_State* tolua_S)
{
    int t = lua_type(tolua_S, 2);
    StringHash key;
    if (t == LUA_TSTRING)
        key = StringHash(lua_tostring(tolua_S, 2));
    else if (t == LUA_TNUMBER)
        key = StringHash((unsigned)lua_tonumber(tolua_S, 2));
    else if (t == LUA_TUSERDATA)
    {
        tolua_Error error;
        if (tolua_isusertype(tolua_S, 2, "StringHash", 0, &error))
            key = *static_cast<StringHash*>(tolua_tousertype(tolua_S, 2, 0));
        else
            return 0;
    }
    else
        return 0;
    Variant& variant = static_cast<VariantMap*>(tolua_tousertype(tolua_S, 1, 0))->operator [](key);     // autovivification
    ToluaToVariant(tolua_S, 3, 0, variant);
    return 0;
}

#define TOLUA_DISABLE_tolua_CoreLuaAPI_VariantMap__Setup00
static int tolua_CoreLuaAPI_VariantMap__Setup00(lua_State* tolua_S)
{
    // Register our own version of metamethod to handle __index and __newindex events
    luaL_getmetatable(tolua_S, tolua_tostring(tolua_S, 2, 0));
    lua_pushstring(tolua_S, "__index");
    lua_pushcfunction(tolua_S, VariantMapIndexEventHandler);
    lua_rawset(tolua_S, -3);
    lua_pushstring(tolua_S, "__newindex");
    lua_pushcfunction(tolua_S, VariantMapNewIndexEventHandler);
    lua_rawset(tolua_S, -3);
    lua_pop(tolua_S, 1);
    return 0;
}

#define TOLUA_DISABLE_tolua_CoreLuaAPI_GetTime00
static int tolua_CoreLuaAPI_GetTime00(lua_State* tolua_S)
{
    return ToluaGetSubsystem<Time>(tolua_S);
}

#define TOLUA_DISABLE_tolua_get_time_ptr
#define tolua_get_time_ptr tolua_CoreLuaAPI_GetTime00

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_VariantMap (lua_State* tolua_S)
{
 VariantMap* self = (VariantMap*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Matrix3x4 (lua_State* tolua_S)
{
 Matrix3x4* self = (Matrix3x4*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Color (lua_State* tolua_S)
{
 Color* self = (Color*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Variant (lua_State* tolua_S)
{
 Variant* self = (Variant*) tolua_tousertype(tolua_S,1,0);
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

static int tolua_collect_IntRect (lua_State* tolua_S)
{
 IntRect* self = (IntRect*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Spline (lua_State* tolua_S)
{
 Spline* self = (Spline*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Matrix3 (lua_State* tolua_S)
{
 Matrix3* self = (Matrix3*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Quaternion (lua_State* tolua_S)
{
 Quaternion* self = (Quaternion*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_IntVector3 (lua_State* tolua_S)
{
 IntVector3* self = (IntVector3*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_ResourceRef (lua_State* tolua_S)
{
 ResourceRef* self = (ResourceRef*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Rect (lua_State* tolua_S)
{
 Rect* self = (Rect*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_ResourceRefList (lua_State* tolua_S)
{
 ResourceRefList* self = (ResourceRefList*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Vector2 (lua_State* tolua_S)
{
 Vector2* self = (Vector2*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_StringHash (lua_State* tolua_S)
{
 StringHash* self = (StringHash*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Vector4 (lua_State* tolua_S)
{
 Vector4* self = (Vector4*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Matrix4 (lua_State* tolua_S)
{
 Matrix4* self = (Matrix4*) tolua_tousertype(tolua_S,1,0);
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
 tolua_usertype(tolua_S,"Quaternion");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"Vector<Variant>");
 tolua_usertype(tolua_S,"Vector<String>");
 tolua_usertype(tolua_S,"Spline");
 tolua_usertype(tolua_S,"Time");
 tolua_usertype(tolua_S,"Variant");
 tolua_usertype(tolua_S,"VectorBuffer");
 tolua_usertype(tolua_S,"PODVector<unsigned char>");
 tolua_usertype(tolua_S,"Context");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"ResourceRefList");
 tolua_usertype(tolua_S,"ResourceRef");
 tolua_usertype(tolua_S,"IntRect");
 tolua_usertype(tolua_S,"StringHash");
 tolua_usertype(tolua_S,"Matrix3x4");
 tolua_usertype(tolua_S,"Matrix3");
 tolua_usertype(tolua_S,"EventHandler");
 tolua_usertype(tolua_S,"IntVector3");
 tolua_usertype(tolua_S,"RefCounted");
 tolua_usertype(tolua_S,"Rect");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"EventSender");
 tolua_usertype(tolua_S,"Vector4");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"Matrix4");
 tolua_usertype(tolua_S,"IntVector2");
}

/* method: GetEventSender of class  Context */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Context_GetEventSender00
static int tolua_CoreLuaAPI_Context_GetEventSender00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Context* self = (const Context*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEventSender'", NULL);
#endif
 {
  Object* tolua_ret = (Object*)  self->GetEventSender();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Object");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEventSender'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEventHandler of class  Context */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Context_GetEventHandler00
static int tolua_CoreLuaAPI_Context_GetEventHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Context",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Context* self = (const Context*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEventHandler'", NULL);
#endif
 {
  EventHandler* tolua_ret = (EventHandler*)  self->GetEventHandler();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"EventHandler");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEventHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTypeName of class  Context */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Context_GetTypeName00
static int tolua_CoreLuaAPI_Context_GetTypeName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Context",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Context* self = (const Context*)  tolua_tousertype(tolua_S,1,0);
  StringHash objectType = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTypeName'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetTypeName(objectType);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTypeName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetContext */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_GetContext00
static int tolua_CoreLuaAPI_GetContext00(lua_State* tolua_S)
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
  Context* tolua_ret = (Context*)  GetContext();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Context");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetContext'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: context */
#ifndef TOLUA_DISABLE_tolua_get_context_ptr
static int tolua_get_context_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetContext(),"Context");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetEventSender */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_GetEventSender00
static int tolua_CoreLuaAPI_GetEventSender00(lua_State* tolua_S)
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
  Object* tolua_ret = (Object*)  GetEventSender();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Object");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEventSender'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: eventSender */
#ifndef TOLUA_DISABLE_tolua_get_eventSender_ptr
static int tolua_get_eventSender_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetEventSender(),"EventSender");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetEventHandler */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_GetEventHandler00
static int tolua_CoreLuaAPI_GetEventHandler00(lua_State* tolua_S)
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
  EventHandler* tolua_ret = (EventHandler*)  GetEventHandler();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"EventHandler");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEventHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: eventHandler */
#ifndef TOLUA_DISABLE_tolua_get_eventHandler_ptr
static int tolua_get_eventHandler_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetEventHandler(),"EventHandler");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetType of class  Object */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Object_GetType00
static int tolua_CoreLuaAPI_Object_GetType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Object* self = (const Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetType'", NULL);
#endif
 {
  StringHash tolua_ret = (StringHash)  self->GetType();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((StringHash)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"StringHash");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(StringHash));
  tolua_pushusertype(tolua_S,tolua_obj,"StringHash");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
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

/* method: GetTypeName of class  Object */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Object_GetTypeName00
static int tolua_CoreLuaAPI_Object_GetTypeName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Object* self = (const Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTypeName'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetTypeName();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTypeName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCategory of class  Object */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Object_GetCategory00
static int tolua_CoreLuaAPI_Object_GetCategory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Object* self = (const Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCategory'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetCategory();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCategory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBlockEvents of class  Object */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Object_SetBlockEvents00
static int tolua_CoreLuaAPI_Object_SetBlockEvents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
  bool block = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBlockEvents'", NULL);
#endif
 {
  self->SetBlockEvents(block);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBlockEvents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBlockEvents of class  Object */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Object_GetBlockEvents00
static int tolua_CoreLuaAPI_Object_GetBlockEvents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Object* self = (const Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBlockEvents'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetBlockEvents();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBlockEvents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ObjectSendEvent of class  Object */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Object_SendEvent00
static int tolua_CoreLuaAPI_Object_SendEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"VariantMap",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  VariantMap* eventData = ((VariantMap*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ObjectSendEvent'", NULL);
#endif
 {
  ObjectSendEvent(self,eventName,eventData);
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

/* method: ObjectHasSubscribedToEvent of class  Object */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Object_HasSubscribedToEvent00
static int tolua_CoreLuaAPI_Object_HasSubscribedToEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Object* self = (const Object*)  tolua_tousertype(tolua_S,1,0);
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ObjectHasSubscribedToEvent'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  ObjectHasSubscribedToEvent(self,eventName);
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

/* method: ObjectHasSubscribedToSenderEvent of class  Object */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Object_HasSubscribedToEvent01
static int tolua_CoreLuaAPI_Object_HasSubscribedToEvent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Object",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Object* self = (const Object*)  tolua_tousertype(tolua_S,1,0);
  Object* sender = ((Object*)  tolua_tousertype(tolua_S,2,0));
  const String eventName = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ObjectHasSubscribedToSenderEvent'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  ObjectHasSubscribedToSenderEvent(self,sender,eventName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_Object_HasSubscribedToEvent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: type of class  Object */
#ifndef TOLUA_DISABLE_tolua_get_Object_type
static int tolua_get_Object_type(lua_State* tolua_S)
{
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type'",NULL);
#endif
 StringHash tolua_ret = (StringHash)self->GetType();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((StringHash)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"StringHash");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(StringHash));
 tolua_pushusertype(tolua_S,tolua_obj,"StringHash");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: typeName of class  Object */
#ifndef TOLUA_DISABLE_tolua_get_Object_typeName
static int tolua_get_Object_typeName(lua_State* tolua_S)
{
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'typeName'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetTypeName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: category of class  Object */
#ifndef TOLUA_DISABLE_tolua_get_Object_category
static int tolua_get_Object_category(lua_State* tolua_S)
{
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'category'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetCategory());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: ErrorDialog */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ErrorDialog00
static int tolua_CoreLuaAPI_ErrorDialog00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isurho3dstring(tolua_S,1,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String title = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
  const String message = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
 {
  ErrorDialog(title,message);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ErrorDialog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ErrorExit */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ErrorExit00
static int tolua_CoreLuaAPI_ErrorExit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isurho3dstring(tolua_S,1,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String message = ((const String)  tolua_tourho3dstring(tolua_S,1,String::EMPTY));
  int exitCode = ((int)  tolua_tonumber(tolua_S,2,EXIT_FAILURE));
 {
  ErrorExit(message,exitCode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ErrorExit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: OpenConsoleWindow */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_OpenConsoleWindow00
static int tolua_CoreLuaAPI_OpenConsoleWindow00(lua_State* tolua_S)
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
  OpenConsoleWindow();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OpenConsoleWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: PrintLine */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_PrintLine00
static int tolua_CoreLuaAPI_PrintLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isurho3dstring(tolua_S,1,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String str = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
  bool error = ((bool)  tolua_toboolean(tolua_S,2,false));
 {
  PrintLine(str,error);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PrintLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: PrintLine */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_PrintLine01
static int tolua_CoreLuaAPI_PrintLine01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,1,0));
  bool error = ((bool)  tolua_toboolean(tolua_S,2,false));
 {
  PrintLine(str,error);
 }
 }
 return 0;
tolua_lerror:
 return tolua_CoreLuaAPI_PrintLine00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetArguments */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_GetArguments00
static int tolua_CoreLuaAPI_GetArguments00(lua_State* tolua_S)
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
  const Vector<String>& tolua_ret = (const Vector<String>&)  GetArguments();
  ToluaPushVector<String>(tolua_S,(void*)&tolua_ret,"String");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetArguments'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetConsoleInput */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_GetConsoleInput00
static int tolua_CoreLuaAPI_GetConsoleInput00(lua_State* tolua_S)
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
  String tolua_ret = (String)  GetConsoleInput();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetConsoleInput'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetPlatform */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_GetPlatform00
static int tolua_CoreLuaAPI_GetPlatform00(lua_State* tolua_S)
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
  String tolua_ret = (String)  GetPlatform();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlatform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetNumPhysicalCPUs */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_GetNumPhysicalCPUs00
static int tolua_CoreLuaAPI_GetNumPhysicalCPUs00(lua_State* tolua_S)
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
  unsigned tolua_ret = (unsigned)  GetNumPhysicalCPUs();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumPhysicalCPUs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetNumLogicalCPUs */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_GetNumLogicalCPUs00
static int tolua_CoreLuaAPI_GetNumLogicalCPUs00(lua_State* tolua_S)
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
  unsigned tolua_ret = (unsigned)  GetNumLogicalCPUs();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumLogicalCPUs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: SetMiniDumpDir */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_SetMiniDumpDir00
static int tolua_CoreLuaAPI_SetMiniDumpDir00(lua_State* tolua_S)
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
  const String pathName = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  SetMiniDumpDir(pathName);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMiniDumpDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetMiniDumpDir */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_GetMiniDumpDir00
static int tolua_CoreLuaAPI_GetMiniDumpDir00(lua_State* tolua_S)
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
  String tolua_ret = (String)  GetMiniDumpDir();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMiniDumpDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetTotalMemory */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_GetTotalMemory00
static int tolua_CoreLuaAPI_GetTotalMemory00(lua_State* tolua_S)
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
  unsigned long long tolua_ret = (unsigned long long)  GetTotalMemory();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTotalMemory'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetLoginName */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_GetLoginName00
static int tolua_CoreLuaAPI_GetLoginName00(lua_State* tolua_S)
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
  String tolua_ret = (String)  GetLoginName();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLoginName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetHostName */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_GetHostName00
static int tolua_CoreLuaAPI_GetHostName00(lua_State* tolua_S)
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
  String tolua_ret = (String)  GetHostName();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHostName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetOSVersion */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_GetOSVersion00
static int tolua_CoreLuaAPI_GetOSVersion00(lua_State* tolua_S)
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
  String tolua_ret = (String)  GetOSVersion();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOSVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToBool */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToBool00
static int tolua_CoreLuaAPI_ToBool00(lua_State* tolua_S)
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
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  bool tolua_ret = (bool)  ToBool(source);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToFloat */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToFloat00
static int tolua_CoreLuaAPI_ToFloat00(lua_State* tolua_S)
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
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  float tolua_ret = (float)  ToFloat(source);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToInt */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToInt00
static int tolua_CoreLuaAPI_ToInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isurho3dstring(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
  int base = ((int)  tolua_tonumber(tolua_S,2,10));
 {
  int tolua_ret = (int)  ToInt(source,base);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToUInt */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToUInt00
static int tolua_CoreLuaAPI_ToUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isurho3dstring(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
  int base = ((int)  tolua_tonumber(tolua_S,2,10));
 {
  unsigned tolua_ret = (unsigned)  ToUInt(source,base);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToUInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToInt64 */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToInt6400
static int tolua_CoreLuaAPI_ToInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isurho3dstring(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
  int base = ((int)  tolua_tonumber(tolua_S,2,10));
 {
  long long int tolua_ret = (long long int)  ToInt64(source,base);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToUInt64 */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToUInt6400
static int tolua_CoreLuaAPI_ToUInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isurho3dstring(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
  int base = ((int)  tolua_tonumber(tolua_S,2,10));
 {
  unsigned long long int tolua_ret = (unsigned long long int)  ToUInt64(source,base);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToUInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToColor */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToColor00
static int tolua_CoreLuaAPI_ToColor00(lua_State* tolua_S)
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
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  Color tolua_ret = (Color)  ToColor(source);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Color)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Color");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Color));
  tolua_pushusertype(tolua_S,tolua_obj,"Color");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToIntRect */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToIntRect00
static int tolua_CoreLuaAPI_ToIntRect00(lua_State* tolua_S)
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
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  IntRect tolua_ret = (IntRect)  ToIntRect(source);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntRect)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntRect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntRect));
  tolua_pushusertype(tolua_S,tolua_obj,"IntRect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToIntRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToIntVector2 */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToIntVector200
static int tolua_CoreLuaAPI_ToIntVector200(lua_State* tolua_S)
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
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  IntVector2 tolua_ret = (IntVector2)  ToIntVector2(source);
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
 tolua_error(tolua_S,"#ferror in function 'ToIntVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToIntVector3 */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToIntVector300
static int tolua_CoreLuaAPI_ToIntVector300(lua_State* tolua_S)
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
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  IntVector3 tolua_ret = (IntVector3)  ToIntVector3(source);
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
 tolua_error(tolua_S,"#ferror in function 'ToIntVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToQuaternion */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToQuaternion00
static int tolua_CoreLuaAPI_ToQuaternion00(lua_State* tolua_S)
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
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  Quaternion tolua_ret = (Quaternion)  ToQuaternion(source);
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
 tolua_error(tolua_S,"#ferror in function 'ToQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToRect */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToRect00
static int tolua_CoreLuaAPI_ToRect00(lua_State* tolua_S)
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
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  Rect tolua_ret = (Rect)  ToRect(source);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Rect)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Rect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Rect));
  tolua_pushusertype(tolua_S,tolua_obj,"Rect");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToVector2 */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToVector200
static int tolua_CoreLuaAPI_ToVector200(lua_State* tolua_S)
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
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  Vector2 tolua_ret = (Vector2)  ToVector2(source);
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
 tolua_error(tolua_S,"#ferror in function 'ToVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToVector3 */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToVector300
static int tolua_CoreLuaAPI_ToVector300(lua_State* tolua_S)
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
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  Vector3 tolua_ret = (Vector3)  ToVector3(source);
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
 tolua_error(tolua_S,"#ferror in function 'ToVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToVector4 */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToVector400
static int tolua_CoreLuaAPI_ToVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isurho3dstring(tolua_S,1,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
  bool allowMissingCoords = ((bool)  tolua_toboolean(tolua_S,2,false));
 {
  Vector4 tolua_ret = (Vector4)  ToVector4(source,allowMissingCoords);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
  tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToMatrix3 */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToMatrix300
static int tolua_CoreLuaAPI_ToMatrix300(lua_State* tolua_S)
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
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  Matrix3 tolua_ret = (Matrix3)  ToMatrix3(source);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToMatrix3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToMatrix3x4 */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToMatrix3x400
static int tolua_CoreLuaAPI_ToMatrix3x400(lua_State* tolua_S)
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
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  Matrix3x4 tolua_ret = (Matrix3x4)  ToMatrix3x4(source);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix3x4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3x4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToMatrix3x4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToMatrix4 */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToMatrix400
static int tolua_CoreLuaAPI_ToMatrix400(lua_State* tolua_S)
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
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  Matrix4 tolua_ret = (Matrix4)  ToMatrix4(source);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
  tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToMatrix4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToString */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToString00
static int tolua_CoreLuaAPI_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* value = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  String tolua_ret = (String)  ToString(value);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToStringHex */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToStringHex00
static int tolua_CoreLuaAPI_ToStringHex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,1,0));
 {
  String tolua_ret = (String)  ToStringHex(value);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToStringHex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: IsAlpha */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_IsAlpha00
static int tolua_CoreLuaAPI_IsAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned ch = ((unsigned)  tolua_tonumber(tolua_S,1,0));
 {
  bool tolua_ret = (bool)  IsAlpha(ch);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: IsDigit */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_IsDigit00
static int tolua_CoreLuaAPI_IsDigit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned ch = ((unsigned)  tolua_tonumber(tolua_S,1,0));
 {
  bool tolua_ret = (bool)  IsDigit(ch);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsDigit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToUpper */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToUpper00
static int tolua_CoreLuaAPI_ToUpper00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned ch = ((unsigned)  tolua_tonumber(tolua_S,1,0));
 {
  unsigned tolua_ret = (unsigned)  ToUpper(ch);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToUpper'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ToLower */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ToLower00
static int tolua_CoreLuaAPI_ToLower00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned ch = ((unsigned)  tolua_tonumber(tolua_S,1,0));
 {
  unsigned tolua_ret = (unsigned)  ToLower(ch);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToLower'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRef_new00
static int tolua_CoreLuaAPI_ResourceRef_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ResourceRef",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ResourceRef* tolua_ret = (ResourceRef*)  Mtolua_new((ResourceRef)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceRef");
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

/* method: new_local of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRef_new00_local
static int tolua_CoreLuaAPI_ResourceRef_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ResourceRef",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ResourceRef* tolua_ret = (ResourceRef*)  Mtolua_new((ResourceRef)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceRef");
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

/* method: new of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRef_new01
static int tolua_CoreLuaAPI_ResourceRef_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ResourceRef",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  StringHash type = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
 {
  ResourceRef* tolua_ret = (ResourceRef*)  Mtolua_new((ResourceRef)(type));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceRef");
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_ResourceRef_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRef_new01_local
static int tolua_CoreLuaAPI_ResourceRef_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ResourceRef",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  StringHash type = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
 {
  ResourceRef* tolua_ret = (ResourceRef*)  Mtolua_new((ResourceRef)(type));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceRef");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_ResourceRef_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRef_new02
static int tolua_CoreLuaAPI_ResourceRef_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ResourceRef",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  StringHash type = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
  String name = ((String)  tolua_tourho3dstring(tolua_S,3,0));
 {
  ResourceRef* tolua_ret = (ResourceRef*)  Mtolua_new((ResourceRef)(type,name));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceRef");
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_ResourceRef_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRef_new02_local
static int tolua_CoreLuaAPI_ResourceRef_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ResourceRef",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  StringHash type = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
  String name = ((String)  tolua_tourho3dstring(tolua_S,3,0));
 {
  ResourceRef* tolua_ret = (ResourceRef*)  Mtolua_new((ResourceRef)(type,name));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceRef");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_ResourceRef_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRef_new03
static int tolua_CoreLuaAPI_ResourceRef_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ResourceRef",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  String type = ((String)  tolua_tourho3dstring(tolua_S,2,0));
  String name = ((String)  tolua_tourho3dstring(tolua_S,3,0));
 {
  ResourceRef* tolua_ret = (ResourceRef*)  Mtolua_new((ResourceRef)(type,name));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceRef");
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_ResourceRef_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRef_new03_local
static int tolua_CoreLuaAPI_ResourceRef_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ResourceRef",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  String type = ((String)  tolua_tourho3dstring(tolua_S,2,0));
  String name = ((String)  tolua_tourho3dstring(tolua_S,3,0));
 {
  ResourceRef* tolua_ret = (ResourceRef*)  Mtolua_new((ResourceRef)(type,name));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceRef");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_ResourceRef_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRef_new04
static int tolua_CoreLuaAPI_ResourceRef_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ResourceRef",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ResourceRef",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const ResourceRef* rhs = ((const ResourceRef*)  tolua_tousertype(tolua_S,2,0));
 {
  ResourceRef* tolua_ret = (ResourceRef*)  Mtolua_new((ResourceRef)(*rhs));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceRef");
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_ResourceRef_new03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRef_new04_local
static int tolua_CoreLuaAPI_ResourceRef_new04_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ResourceRef",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ResourceRef",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const ResourceRef* rhs = ((const ResourceRef*)  tolua_tousertype(tolua_S,2,0));
 {
  ResourceRef* tolua_ret = (ResourceRef*)  Mtolua_new((ResourceRef)(*rhs));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceRef");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_ResourceRef_new03_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRef_delete00
static int tolua_CoreLuaAPI_ResourceRef_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceRef",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceRef* self = (ResourceRef*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: type_ of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_get_ResourceRef_type
static int tolua_get_ResourceRef_type(lua_State* tolua_S)
{
  ResourceRef* self = (ResourceRef*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->type_,"StringHash");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: type_ of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_set_ResourceRef_type
static int tolua_set_ResourceRef_type(lua_State* tolua_S)
{
  ResourceRef* self = (ResourceRef*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->type_ = *((StringHash*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name_ of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_get_ResourceRef_name
static int tolua_get_ResourceRef_name(lua_State* tolua_S)
{
  ResourceRef* self = (ResourceRef*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name_'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->name_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name_ of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_set_ResourceRef_name
static int tolua_set_ResourceRef_name(lua_State* tolua_S)
{
  ResourceRef* self = (ResourceRef*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name_'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->name_ = ((String)  tolua_tourho3dstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  ResourceRef */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRef__eq00
static int tolua_CoreLuaAPI_ResourceRef__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceRef",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ResourceRef",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceRef* self = (const ResourceRef*)  tolua_tousertype(tolua_S,1,0);
  const ResourceRef* rhs = ((const ResourceRef*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ResourceRefList */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRefList_new00
static int tolua_CoreLuaAPI_ResourceRefList_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ResourceRefList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ResourceRefList* tolua_ret = (ResourceRefList*)  Mtolua_new((ResourceRefList)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceRefList");
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

/* method: new_local of class  ResourceRefList */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRefList_new00_local
static int tolua_CoreLuaAPI_ResourceRefList_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ResourceRefList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ResourceRefList* tolua_ret = (ResourceRefList*)  Mtolua_new((ResourceRefList)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceRefList");
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

/* method: new of class  ResourceRefList */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRefList_new01
static int tolua_CoreLuaAPI_ResourceRefList_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ResourceRefList",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  StringHash type = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
 {
  ResourceRefList* tolua_ret = (ResourceRefList*)  Mtolua_new((ResourceRefList)(type));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceRefList");
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_ResourceRefList_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ResourceRefList */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRefList_new01_local
static int tolua_CoreLuaAPI_ResourceRefList_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ResourceRefList",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  StringHash type = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
 {
  ResourceRefList* tolua_ret = (ResourceRefList*)  Mtolua_new((ResourceRefList)(type));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceRefList");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_ResourceRefList_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ResourceRefList */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRefList_delete00
static int tolua_CoreLuaAPI_ResourceRefList_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceRefList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceRefList* self = (ResourceRefList*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: type_ of class  ResourceRefList */
#ifndef TOLUA_DISABLE_tolua_get_ResourceRefList_type
static int tolua_get_ResourceRefList_type(lua_State* tolua_S)
{
  ResourceRefList* self = (ResourceRefList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->type_,"StringHash");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: type_ of class  ResourceRefList */
#ifndef TOLUA_DISABLE_tolua_set_ResourceRefList_type
static int tolua_set_ResourceRefList_type(lua_State* tolua_S)
{
  ResourceRefList* self = (ResourceRefList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->type_ = *((StringHash*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  ResourceRefList */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_ResourceRefList__eq00
static int tolua_CoreLuaAPI_ResourceRefList__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceRefList",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ResourceRefList",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceRefList* self = (const ResourceRefList*)  tolua_tousertype(tolua_S,1,0);
  const ResourceRefList* rhs = ((const ResourceRefList*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: _Setup of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant__Setup00
static int tolua_CoreLuaAPI_Variant__Setup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Variant",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* type = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  Variant::_Setup(type);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '_Setup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_new00
static int tolua_CoreLuaAPI_Variant_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Variant* tolua_ret = (Variant*)  Mtolua_new((Variant)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Variant");
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

/* method: new_local of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_new00_local
static int tolua_CoreLuaAPI_Variant_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Variant* tolua_ret = (Variant*)  Mtolua_new((Variant)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Variant");
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

/* method: new of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_new01
static int tolua_CoreLuaAPI_Variant_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Variant",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
 {
  Variant* tolua_ret = (Variant*)  Mtolua_new((Variant)(*value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Variant");
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_Variant_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_new01_local
static int tolua_CoreLuaAPI_Variant_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Variant",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
 {
  Variant* tolua_ret = (Variant*)  Mtolua_new((Variant)(*value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Variant");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_Variant_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_new02
static int tolua_CoreLuaAPI_Variant_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Variant",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const char* type = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
 {
  Variant* tolua_ret = (Variant*)  Mtolua_new((Variant)(type,value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Variant");
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_Variant_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_new02_local
static int tolua_CoreLuaAPI_Variant_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Variant",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const char* type = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
 {
  Variant* tolua_ret = (Variant*)  Mtolua_new((Variant)(type,value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Variant");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_Variant_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_new03
static int tolua_CoreLuaAPI_Variant_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Variant",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  VariantType type = ((VariantType) (int)  tolua_tonumber(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
 {
  Variant* tolua_ret = (Variant*)  Mtolua_new((Variant)(type,value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Variant");
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_Variant_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_new03_local
static int tolua_CoreLuaAPI_Variant_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Variant",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  VariantType type = ((VariantType) (int)  tolua_tonumber(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
 {
  Variant* tolua_ret = (Variant*)  Mtolua_new((Variant)(type,value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Variant");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_Variant_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_delete00
static int tolua_CoreLuaAPI_Variant_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Variant* self = (Variant*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Clear of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_Clear00
static int tolua_CoreLuaAPI_Variant_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Variant* self = (Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
 {
  self->Clear();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant__eq00
static int tolua_CoreLuaAPI_Variant__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
  const Variant* rhs = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_Set00
static int tolua_CoreLuaAPI_Variant_Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Variant",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Variant* self = (Variant*)  tolua_tousertype(tolua_S,1,0);
  const Variant* rhs = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
 {
  self->Set(*rhs);
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

/* method: Get of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_Get00
static int tolua_CoreLuaAPI_Variant_Get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
  const char* type = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get'", NULL);
#endif
 {
  void* tolua_ret = (void*)  self->Get(type);
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Get'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInt of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetInt00
static int tolua_CoreLuaAPI_Variant_GetInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInt'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetInt();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUInt of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetUInt00
static int tolua_CoreLuaAPI_Variant_GetUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUInt'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetUInt();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInt64 of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetInt6400
static int tolua_CoreLuaAPI_Variant_GetInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInt64'", NULL);
#endif
 {
  long long int tolua_ret = (long long int)  self->GetInt64();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUInt64 of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetUInt6400
static int tolua_CoreLuaAPI_Variant_GetUInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUInt64'", NULL);
#endif
 {
  unsigned long long int tolua_ret = (unsigned long long int)  self->GetUInt64();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStringHash of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetStringHash00
static int tolua_CoreLuaAPI_Variant_GetStringHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStringHash'", NULL);
#endif
 {
  StringHash tolua_ret = (StringHash)  self->GetStringHash();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((StringHash)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"StringHash");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(StringHash));
  tolua_pushusertype(tolua_S,tolua_obj,"StringHash");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStringHash'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBool of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetBool00
static int tolua_CoreLuaAPI_Variant_GetBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBool'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetBool();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFloat of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetFloat00
static int tolua_CoreLuaAPI_Variant_GetFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFloat'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetFloat();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDouble of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetDouble00
static int tolua_CoreLuaAPI_Variant_GetDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDouble'", NULL);
#endif
 {
  double tolua_ret = (double)  self->GetDouble();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDouble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVector2 of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetVector200
static int tolua_CoreLuaAPI_Variant_GetVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVector2'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetVector2();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVector3 of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetVector300
static int tolua_CoreLuaAPI_Variant_GetVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVector3'", NULL);
#endif
 {
  const Vector3& tolua_ret = (const Vector3&)  self->GetVector3();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVector4 of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetVector400
static int tolua_CoreLuaAPI_Variant_GetVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVector4'", NULL);
#endif
 {
  const Vector4& tolua_ret = (const Vector4&)  self->GetVector4();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector4");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetQuaternion of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetQuaternion00
static int tolua_CoreLuaAPI_Variant_GetQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetQuaternion'", NULL);
#endif
 {
  const Quaternion& tolua_ret = (const Quaternion&)  self->GetQuaternion();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Quaternion");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetColor of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetColor00
static int tolua_CoreLuaAPI_Variant_GetColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetString of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetString00
static int tolua_CoreLuaAPI_Variant_GetString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetString'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBuffer of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetRawBuffer00
static int tolua_CoreLuaAPI_Variant_GetRawBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBuffer'", NULL);
#endif
 {
  const PODVector<unsigned char>& tolua_ret = (const PODVector<unsigned char>&)  self->GetBuffer();
  ToluaPushPODVector<unsigned char>(0.f,tolua_S,(void*)&tolua_ret,"unsigned char");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRawBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVectorBuffer of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetBuffer00
static int tolua_CoreLuaAPI_Variant_GetBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVectorBuffer'", NULL);
#endif
 {
  VectorBuffer tolua_ret = (VectorBuffer)  self->GetVectorBuffer();
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
 tolua_error(tolua_S,"#ferror in function 'GetBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVoidPtr of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetVoidPtr00
static int tolua_CoreLuaAPI_Variant_GetVoidPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
  const char* type = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVoidPtr'", NULL);
#endif
 {
  void* tolua_ret = (void*)  self->GetVoidPtr(type);
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVoidPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetResourceRef of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetResourceRef00
static int tolua_CoreLuaAPI_Variant_GetResourceRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetResourceRef'", NULL);
#endif
 {
  const ResourceRef& tolua_ret = (const ResourceRef&)  self->GetResourceRef();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const ResourceRef");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetResourceRef'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetResourceRefList of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetResourceRefList00
static int tolua_CoreLuaAPI_Variant_GetResourceRefList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetResourceRefList'", NULL);
#endif
 {
  const ResourceRefList& tolua_ret = (const ResourceRefList&)  self->GetResourceRefList();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const ResourceRefList");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetResourceRefList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVariantVector of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetVariantVector00
static int tolua_CoreLuaAPI_Variant_GetVariantVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVariantVector'", NULL);
#endif
 {
  const Vector<Variant>& tolua_ret = (const Vector<Variant>&)  self->GetVariantVector();
  ToluaPushVector<Variant>(tolua_S,(void*)&tolua_ret,"Variant");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVariantVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVariantMap of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetVariantMap00
static int tolua_CoreLuaAPI_Variant_GetVariantMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVariantMap'", NULL);
#endif
 {
  const VariantMap& tolua_ret = (const VariantMap&)  self->GetVariantMap();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const VariantMap");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVariantMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStringVector of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetStringVector00
static int tolua_CoreLuaAPI_Variant_GetStringVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStringVector'", NULL);
#endif
 {
  const Vector<String>& tolua_ret = (const Vector<String>&)  self->GetStringVector();
  ToluaPushVector<String>(tolua_S,(void*)&tolua_ret,"String");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStringVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRect of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetRect00
static int tolua_CoreLuaAPI_Variant_GetRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRect'", NULL);
#endif
 {
  const Rect& tolua_ret = (const Rect&)  self->GetRect();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Rect");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIntRect of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetIntRect00
static int tolua_CoreLuaAPI_Variant_GetIntRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIntRect'", NULL);
#endif
 {
  const IntRect& tolua_ret = (const IntRect&)  self->GetIntRect();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntRect");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIntRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIntVector2 of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetIntVector200
static int tolua_CoreLuaAPI_Variant_GetIntVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIntVector2'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetIntVector2();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIntVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIntVector3 of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetIntVector300
static int tolua_CoreLuaAPI_Variant_GetIntVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIntVector3'", NULL);
#endif
 {
  const IntVector3& tolua_ret = (const IntVector3&)  self->GetIntVector3();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIntVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPtr of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetPtr00
static int tolua_CoreLuaAPI_Variant_GetPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
  const char* type = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPtr'", NULL);
#endif
 {
  RefCounted* tolua_ret = (RefCounted*)  self->GetPtr(type);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"RefCounted");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMatrix3 of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetMatrix300
static int tolua_CoreLuaAPI_Variant_GetMatrix300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMatrix3'", NULL);
#endif
 {
  const Matrix3& tolua_ret = (const Matrix3&)  self->GetMatrix3();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Matrix3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMatrix3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMatrix3x4 of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetMatrix3x400
static int tolua_CoreLuaAPI_Variant_GetMatrix3x400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMatrix3x4'", NULL);
#endif
 {
  const Matrix3x4& tolua_ret = (const Matrix3x4&)  self->GetMatrix3x4();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Matrix3x4");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMatrix3x4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMatrix4 of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetMatrix400
static int tolua_CoreLuaAPI_Variant_GetMatrix400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMatrix4'", NULL);
#endif
 {
  const Matrix4& tolua_ret = (const Matrix4&)  self->GetMatrix4();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Matrix4");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMatrix4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetType of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetType00
static int tolua_CoreLuaAPI_Variant_GetType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetType'", NULL);
#endif
 {
  VariantType tolua_ret = (VariantType)  self->GetType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: GetTypeName of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_GetTypeName00
static int tolua_CoreLuaAPI_Variant_GetTypeName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTypeName'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetTypeName();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTypeName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_ToString00
static int tolua_CoreLuaAPI_Variant_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ToString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsZero of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_IsZero00
static int tolua_CoreLuaAPI_Variant_IsZero00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsZero'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsZero();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsEmpty of class  Variant */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Variant_IsEmpty00
static int tolua_CoreLuaAPI_Variant_IsEmpty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Variant",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Variant* self = (const Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsEmpty'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsEmpty();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsEmpty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: type of class  Variant */
#ifndef TOLUA_DISABLE_tolua_get_Variant_type
static int tolua_get_Variant_type(lua_State* tolua_S)
{
  Variant* self = (Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: typeName of class  Variant */
#ifndef TOLUA_DISABLE_tolua_get_Variant_typeName
static int tolua_get_Variant_typeName(lua_State* tolua_S)
{
  Variant* self = (Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'typeName'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetTypeName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: zero of class  Variant */
#ifndef TOLUA_DISABLE_tolua_get_Variant_zero
static int tolua_get_Variant_zero(lua_State* tolua_S)
{
  Variant* self = (Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'zero'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsZero());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: empty of class  Variant */
#ifndef TOLUA_DISABLE_tolua_get_Variant_empty
static int tolua_get_Variant_empty(lua_State* tolua_S)
{
  Variant* self = (Variant*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'empty'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsEmpty());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: _Setup of class  VariantMap */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_VariantMap__Setup00
static int tolua_CoreLuaAPI_VariantMap__Setup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"VariantMap",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* type = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  VariantMap::_Setup(type);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '_Setup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  VariantMap */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_VariantMap_new00
static int tolua_CoreLuaAPI_VariantMap_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"VariantMap",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  VariantMap* tolua_ret = (VariantMap*)  Mtolua_new((VariantMap)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"VariantMap");
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

/* method: new_local of class  VariantMap */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_VariantMap_new00_local
static int tolua_CoreLuaAPI_VariantMap_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"VariantMap",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  VariantMap* tolua_ret = (VariantMap*)  Mtolua_new((VariantMap)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"VariantMap");
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

/* method: delete of class  VariantMap */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_VariantMap_delete00
static int tolua_CoreLuaAPI_VariantMap_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VariantMap",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VariantMap* self = (VariantMap*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline_new00
static int tolua_CoreLuaAPI_Spline_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Spline",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Spline* tolua_ret = (Spline*)  Mtolua_new((Spline)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Spline");
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

/* method: new_local of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline_new00_local
static int tolua_CoreLuaAPI_Spline_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Spline",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Spline* tolua_ret = (Spline*)  Mtolua_new((Spline)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Spline");
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

/* method: new of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline_new01
static int tolua_CoreLuaAPI_Spline_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Spline",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  InterpolationMode mode = ((InterpolationMode) (int)  tolua_tonumber(tolua_S,2,0));
 {
  Spline* tolua_ret = (Spline*)  Mtolua_new((Spline)(mode));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Spline");
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_Spline_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline_new01_local
static int tolua_CoreLuaAPI_Spline_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Spline",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  InterpolationMode mode = ((InterpolationMode) (int)  tolua_tonumber(tolua_S,2,0));
 {
  Spline* tolua_ret = (Spline*)  Mtolua_new((Spline)(mode));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Spline");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_Spline_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline_new02
static int tolua_CoreLuaAPI_Spline_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Spline",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Spline",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Spline* rhs = ((const Spline*)  tolua_tousertype(tolua_S,2,0));
 {
  Spline* tolua_ret = (Spline*)  Mtolua_new((Spline)(*rhs));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Spline");
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_Spline_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline_new02_local
static int tolua_CoreLuaAPI_Spline_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Spline",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Spline",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Spline* rhs = ((const Spline*)  tolua_tousertype(tolua_S,2,0));
 {
  Spline* tolua_ret = (Spline*)  Mtolua_new((Spline)(*rhs));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Spline");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_CoreLuaAPI_Spline_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline_delete00
static int tolua_CoreLuaAPI_Spline_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Spline",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Spline* self = (Spline*)  tolua_tousertype(tolua_S,1,0);
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

/* method: operator== of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline__eq00
static int tolua_CoreLuaAPI_Spline__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Spline",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Spline",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Spline* self = (const Spline*)  tolua_tousertype(tolua_S,1,0);
  const Spline* rhs = ((const Spline*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator==(*rhs);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPoint of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline_GetPoint00
static int tolua_CoreLuaAPI_Spline_GetPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Spline",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Spline* self = (const Spline*)  tolua_tousertype(tolua_S,1,0);
  float f = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPoint'", NULL);
#endif
 {
  Variant tolua_ret = (Variant)  self->GetPoint(f);
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
 tolua_error(tolua_S,"#ferror in function 'GetPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetKnot of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline_GetKnot00
static int tolua_CoreLuaAPI_Spline_GetKnot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Spline",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Spline* self = (const Spline*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetKnot'", NULL);
#endif
 {
  Variant tolua_ret = (Variant)  self->GetKnot(index);
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
 tolua_error(tolua_S,"#ferror in function 'GetKnot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetKnot of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline_SetKnot00
static int tolua_CoreLuaAPI_Spline_SetKnot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Spline",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Spline* self = (Spline*)  tolua_tousertype(tolua_S,1,0);
  const Variant* knot = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
  unsigned tolua_var_1 = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetKnot'", NULL);
#endif
 {
  self->SetKnot(*knot,tolua_var_1);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetKnot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddKnot of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline_AddKnot00
static int tolua_CoreLuaAPI_Spline_AddKnot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Spline",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Spline* self = (Spline*)  tolua_tousertype(tolua_S,1,0);
  const Variant* knot = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddKnot'", NULL);
#endif
 {
  self->AddKnot(*knot);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddKnot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddKnot of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline_AddKnot01
static int tolua_CoreLuaAPI_Spline_AddKnot01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Spline",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Spline* self = (Spline*)  tolua_tousertype(tolua_S,1,0);
  const Variant* knot = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddKnot'", NULL);
#endif
 {
  self->AddKnot(*knot,index);
 }
 }
 return 0;
tolua_lerror:
 return tolua_CoreLuaAPI_Spline_AddKnot00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveKnot of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline_RemoveKnot00
static int tolua_CoreLuaAPI_Spline_RemoveKnot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Spline",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Spline* self = (Spline*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveKnot'", NULL);
#endif
 {
  self->RemoveKnot();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveKnot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveKnot of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline_RemoveKnot01
static int tolua_CoreLuaAPI_Spline_RemoveKnot01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Spline",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Spline* self = (Spline*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveKnot'", NULL);
#endif
 {
  self->RemoveKnot(index);
 }
 }
 return 0;
tolua_lerror:
 return tolua_CoreLuaAPI_Spline_RemoveKnot00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  Spline */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Spline_Clear00
static int tolua_CoreLuaAPI_Spline_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Spline",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Spline* self = (Spline*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
 {
  self->Clear();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: interpolationMode of class  Spline */
#ifndef TOLUA_DISABLE_tolua_get_Spline_interpolationMode
static int tolua_get_Spline_interpolationMode(lua_State* tolua_S)
{
  Spline* self = (Spline*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'interpolationMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetInterpolationMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: interpolationMode of class  Spline */
#ifndef TOLUA_DISABLE_tolua_set_Spline_interpolationMode
static int tolua_set_Spline_interpolationMode(lua_State* tolua_S)
{
  Spline* self = (Spline*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'interpolationMode'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetInterpolationMode(((InterpolationMode) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFrameNumber of class  Time */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Time_GetFrameNumber00
static int tolua_CoreLuaAPI_Time_GetFrameNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Time",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Time* self = (const Time*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFrameNumber'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetFrameNumber();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFrameNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTimeStep of class  Time */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Time_GetTimeStep00
static int tolua_CoreLuaAPI_Time_GetTimeStep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Time",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Time* self = (const Time*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTimeStep'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetTimeStep();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimeStep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTimerPeriod of class  Time */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Time_GetTimerPeriod00
static int tolua_CoreLuaAPI_Time_GetTimerPeriod00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Time",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Time* self = (const Time*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTimerPeriod'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetTimerPeriod();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimerPeriod'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetElapsedTime of class  Time */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Time_GetElapsedTime00
static int tolua_CoreLuaAPI_Time_GetElapsedTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Time",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Time* self = (Time*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetElapsedTime'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetElapsedTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetElapsedTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFramesPerSecond of class  Time */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Time_GetFramesPerSecond00
static int tolua_CoreLuaAPI_Time_GetFramesPerSecond00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Time",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Time* self = (const Time*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFramesPerSecond'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetFramesPerSecond();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFramesPerSecond'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSystemTime of class  Time */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Time_GetSystemTime00
static int tolua_CoreLuaAPI_Time_GetSystemTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Time",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  unsigned tolua_ret = (unsigned)  Time::GetSystemTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSystemTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTimeSinceEpoch of class  Time */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Time_GetTimeSinceEpoch00
static int tolua_CoreLuaAPI_Time_GetTimeSinceEpoch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Time",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  unsigned tolua_ret = (unsigned)  Time::GetTimeSinceEpoch();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimeSinceEpoch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTimeStamp of class  Time */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Time_GetTimeStamp00
static int tolua_CoreLuaAPI_Time_GetTimeStamp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Time",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  String tolua_ret = (String)  Time::GetTimeStamp();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimeStamp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Sleep of class  Time */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_Time_Sleep00
static int tolua_CoreLuaAPI_Time_Sleep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Time",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned mSec = ((unsigned)  tolua_tonumber(tolua_S,2,0));
 {
  Time::Sleep(mSec);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Sleep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: frameNumber of class  Time */
#ifndef TOLUA_DISABLE_tolua_get_Time_frameNumber
static int tolua_get_Time_frameNumber(lua_State* tolua_S)
{
  Time* self = (Time*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frameNumber'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFrameNumber());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: timeStep of class  Time */
#ifndef TOLUA_DISABLE_tolua_get_Time_timeStep
static int tolua_get_Time_timeStep(lua_State* tolua_S)
{
  Time* self = (Time*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeStep'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTimeStep());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: timerPeriod of class  Time */
#ifndef TOLUA_DISABLE_tolua_get_Time_timerPeriod
static int tolua_get_Time_timerPeriod(lua_State* tolua_S)
{
  Time* self = (Time*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timerPeriod'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTimerPeriod());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: elapsedTime of class  Time */
#ifndef TOLUA_DISABLE_tolua_get_Time_elapsedTime
static int tolua_get_Time_elapsedTime(lua_State* tolua_S)
{
  Time* self = (Time*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'elapsedTime'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetElapsedTime());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetTime */
#ifndef TOLUA_DISABLE_tolua_CoreLuaAPI_GetTime00
static int tolua_CoreLuaAPI_GetTime00(lua_State* tolua_S)
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
  Time* tolua_ret = (Time*)  GetTime();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Time");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: time */
#ifndef TOLUA_DISABLE_tolua_get_time_ptr
static int tolua_get_time_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetTime(),"Time");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_CoreLuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"Context","Context","",NULL);
 tolua_beginmodule(tolua_S,"Context");
  tolua_function(tolua_S,"GetEventSender",tolua_CoreLuaAPI_Context_GetEventSender00);
  tolua_function(tolua_S,"GetEventHandler",tolua_CoreLuaAPI_Context_GetEventHandler00);
  tolua_function(tolua_S,"GetTypeName",tolua_CoreLuaAPI_Context_GetTypeName00);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"GetContext",tolua_CoreLuaAPI_GetContext00);
 tolua_variable(tolua_S,"context",tolua_get_context_ptr,NULL);
 tolua_function(tolua_S,"GetEventSender",tolua_CoreLuaAPI_GetEventSender00);
 tolua_variable(tolua_S,"eventSender",tolua_get_eventSender_ptr,NULL);
 tolua_function(tolua_S,"GetEventHandler",tolua_CoreLuaAPI_GetEventHandler00);
 tolua_variable(tolua_S,"eventHandler",tolua_get_eventHandler_ptr,NULL);
 tolua_cclass(tolua_S,"Object","Object","RefCounted",NULL);
 tolua_beginmodule(tolua_S,"Object");
  tolua_function(tolua_S,"GetType",tolua_CoreLuaAPI_Object_GetType00);
  tolua_function(tolua_S,"GetTypeName",tolua_CoreLuaAPI_Object_GetTypeName00);
  tolua_function(tolua_S,"GetCategory",tolua_CoreLuaAPI_Object_GetCategory00);
  tolua_function(tolua_S,"SetBlockEvents",tolua_CoreLuaAPI_Object_SetBlockEvents00);
  tolua_function(tolua_S,"GetBlockEvents",tolua_CoreLuaAPI_Object_GetBlockEvents00);
  tolua_function(tolua_S,"SendEvent",tolua_CoreLuaAPI_Object_SendEvent00);
  tolua_function(tolua_S,"HasSubscribedToEvent",tolua_CoreLuaAPI_Object_HasSubscribedToEvent00);
  tolua_function(tolua_S,"HasSubscribedToEvent",tolua_CoreLuaAPI_Object_HasSubscribedToEvent01);
  tolua_variable(tolua_S,"type",tolua_get_Object_type,NULL);
  tolua_variable(tolua_S,"typeName",tolua_get_Object_typeName,NULL);
  tolua_variable(tolua_S,"category",tolua_get_Object_category,NULL);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"ErrorDialog",tolua_CoreLuaAPI_ErrorDialog00);
 tolua_function(tolua_S,"ErrorExit",tolua_CoreLuaAPI_ErrorExit00);
 tolua_function(tolua_S,"OpenConsoleWindow",tolua_CoreLuaAPI_OpenConsoleWindow00);
 tolua_function(tolua_S,"PrintLine",tolua_CoreLuaAPI_PrintLine00);
 tolua_function(tolua_S,"PrintLine",tolua_CoreLuaAPI_PrintLine01);
 tolua_function(tolua_S,"GetArguments",tolua_CoreLuaAPI_GetArguments00);
 tolua_function(tolua_S,"GetConsoleInput",tolua_CoreLuaAPI_GetConsoleInput00);
 tolua_function(tolua_S,"GetPlatform",tolua_CoreLuaAPI_GetPlatform00);
 tolua_function(tolua_S,"GetNumPhysicalCPUs",tolua_CoreLuaAPI_GetNumPhysicalCPUs00);
 tolua_function(tolua_S,"GetNumLogicalCPUs",tolua_CoreLuaAPI_GetNumLogicalCPUs00);
 tolua_function(tolua_S,"SetMiniDumpDir",tolua_CoreLuaAPI_SetMiniDumpDir00);
 tolua_function(tolua_S,"GetMiniDumpDir",tolua_CoreLuaAPI_GetMiniDumpDir00);
 tolua_function(tolua_S,"GetTotalMemory",tolua_CoreLuaAPI_GetTotalMemory00);
 tolua_function(tolua_S,"GetLoginName",tolua_CoreLuaAPI_GetLoginName00);
 tolua_function(tolua_S,"GetHostName",tolua_CoreLuaAPI_GetHostName00);
 tolua_function(tolua_S,"GetOSVersion",tolua_CoreLuaAPI_GetOSVersion00);
 tolua_function(tolua_S,"ToBool",tolua_CoreLuaAPI_ToBool00);
 tolua_function(tolua_S,"ToFloat",tolua_CoreLuaAPI_ToFloat00);
 tolua_function(tolua_S,"ToInt",tolua_CoreLuaAPI_ToInt00);
 tolua_function(tolua_S,"ToUInt",tolua_CoreLuaAPI_ToUInt00);
 tolua_function(tolua_S,"ToInt64",tolua_CoreLuaAPI_ToInt6400);
 tolua_function(tolua_S,"ToUInt64",tolua_CoreLuaAPI_ToUInt6400);
 tolua_function(tolua_S,"ToColor",tolua_CoreLuaAPI_ToColor00);
 tolua_function(tolua_S,"ToIntRect",tolua_CoreLuaAPI_ToIntRect00);
 tolua_function(tolua_S,"ToIntVector2",tolua_CoreLuaAPI_ToIntVector200);
 tolua_function(tolua_S,"ToIntVector3",tolua_CoreLuaAPI_ToIntVector300);
 tolua_function(tolua_S,"ToQuaternion",tolua_CoreLuaAPI_ToQuaternion00);
 tolua_function(tolua_S,"ToRect",tolua_CoreLuaAPI_ToRect00);
 tolua_function(tolua_S,"ToVector2",tolua_CoreLuaAPI_ToVector200);
 tolua_function(tolua_S,"ToVector3",tolua_CoreLuaAPI_ToVector300);
 tolua_function(tolua_S,"ToVector4",tolua_CoreLuaAPI_ToVector400);
 tolua_function(tolua_S,"ToMatrix3",tolua_CoreLuaAPI_ToMatrix300);
 tolua_function(tolua_S,"ToMatrix3x4",tolua_CoreLuaAPI_ToMatrix3x400);
 tolua_function(tolua_S,"ToMatrix4",tolua_CoreLuaAPI_ToMatrix400);
 tolua_function(tolua_S,"ToString",tolua_CoreLuaAPI_ToString00);
 tolua_function(tolua_S,"ToStringHex",tolua_CoreLuaAPI_ToStringHex00);
 tolua_function(tolua_S,"IsAlpha",tolua_CoreLuaAPI_IsAlpha00);
 tolua_function(tolua_S,"IsDigit",tolua_CoreLuaAPI_IsDigit00);
 tolua_function(tolua_S,"ToUpper",tolua_CoreLuaAPI_ToUpper00);
 tolua_function(tolua_S,"ToLower",tolua_CoreLuaAPI_ToLower00);
 tolua_constant(tolua_S,"VAR_NONE",VAR_NONE);
 tolua_constant(tolua_S,"VAR_INT",VAR_INT);
 tolua_constant(tolua_S,"VAR_BOOL",VAR_BOOL);
 tolua_constant(tolua_S,"VAR_FLOAT",VAR_FLOAT);
 tolua_constant(tolua_S,"VAR_VECTOR2",VAR_VECTOR2);
 tolua_constant(tolua_S,"VAR_VECTOR3",VAR_VECTOR3);
 tolua_constant(tolua_S,"VAR_VECTOR4",VAR_VECTOR4);
 tolua_constant(tolua_S,"VAR_QUATERNION",VAR_QUATERNION);
 tolua_constant(tolua_S,"VAR_COLOR",VAR_COLOR);
 tolua_constant(tolua_S,"VAR_STRING",VAR_STRING);
 tolua_constant(tolua_S,"VAR_BUFFER",VAR_BUFFER);
 tolua_constant(tolua_S,"VAR_VOIDPTR",VAR_VOIDPTR);
 tolua_constant(tolua_S,"VAR_RESOURCEREF",VAR_RESOURCEREF);
 tolua_constant(tolua_S,"VAR_RESOURCEREFLIST",VAR_RESOURCEREFLIST);
 tolua_constant(tolua_S,"VAR_VARIANTVECTOR",VAR_VARIANTVECTOR);
 tolua_constant(tolua_S,"VAR_VARIANTMAP",VAR_VARIANTMAP);
 tolua_constant(tolua_S,"VAR_INTRECT",VAR_INTRECT);
 tolua_constant(tolua_S,"VAR_INTVECTOR2",VAR_INTVECTOR2);
 tolua_constant(tolua_S,"VAR_PTR",VAR_PTR);
 tolua_constant(tolua_S,"VAR_MATRIX3",VAR_MATRIX3);
 tolua_constant(tolua_S,"VAR_MATRIX3X4",VAR_MATRIX3X4);
 tolua_constant(tolua_S,"VAR_MATRIX4",VAR_MATRIX4);
 tolua_constant(tolua_S,"VAR_DOUBLE",VAR_DOUBLE);
 tolua_constant(tolua_S,"VAR_STRINGVECTOR",VAR_STRINGVECTOR);
 tolua_constant(tolua_S,"VAR_RECT",VAR_RECT);
 tolua_constant(tolua_S,"VAR_INTVECTOR3",VAR_INTVECTOR3);
 tolua_constant(tolua_S,"VAR_INT64",VAR_INT64);
 tolua_constant(tolua_S,"MAX_VAR_TYPES",MAX_VAR_TYPES);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"ResourceRef","ResourceRef","",tolua_collect_ResourceRef);
 #else
 tolua_cclass(tolua_S,"ResourceRef","ResourceRef","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"ResourceRef");
  tolua_function(tolua_S,"new",tolua_CoreLuaAPI_ResourceRef_new00);
  tolua_function(tolua_S,"new_local",tolua_CoreLuaAPI_ResourceRef_new00_local);
  tolua_function(tolua_S,".call",tolua_CoreLuaAPI_ResourceRef_new00_local);
  tolua_function(tolua_S,"new",tolua_CoreLuaAPI_ResourceRef_new01);
  tolua_function(tolua_S,"new_local",tolua_CoreLuaAPI_ResourceRef_new01_local);
  tolua_function(tolua_S,".call",tolua_CoreLuaAPI_ResourceRef_new01_local);
  tolua_function(tolua_S,"new",tolua_CoreLuaAPI_ResourceRef_new02);
  tolua_function(tolua_S,"new_local",tolua_CoreLuaAPI_ResourceRef_new02_local);
  tolua_function(tolua_S,".call",tolua_CoreLuaAPI_ResourceRef_new02_local);
  tolua_function(tolua_S,"new",tolua_CoreLuaAPI_ResourceRef_new03);
  tolua_function(tolua_S,"new_local",tolua_CoreLuaAPI_ResourceRef_new03_local);
  tolua_function(tolua_S,".call",tolua_CoreLuaAPI_ResourceRef_new03_local);
  tolua_function(tolua_S,"new",tolua_CoreLuaAPI_ResourceRef_new04);
  tolua_function(tolua_S,"new_local",tolua_CoreLuaAPI_ResourceRef_new04_local);
  tolua_function(tolua_S,".call",tolua_CoreLuaAPI_ResourceRef_new04_local);
  tolua_function(tolua_S,"delete",tolua_CoreLuaAPI_ResourceRef_delete00);
  tolua_variable(tolua_S,"type",tolua_get_ResourceRef_type,tolua_set_ResourceRef_type);
  tolua_variable(tolua_S,"name",tolua_get_ResourceRef_name,tolua_set_ResourceRef_name);
  tolua_function(tolua_S,".eq",tolua_CoreLuaAPI_ResourceRef__eq00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"ResourceRefList","ResourceRefList","",tolua_collect_ResourceRefList);
 #else
 tolua_cclass(tolua_S,"ResourceRefList","ResourceRefList","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"ResourceRefList");
  tolua_function(tolua_S,"new",tolua_CoreLuaAPI_ResourceRefList_new00);
  tolua_function(tolua_S,"new_local",tolua_CoreLuaAPI_ResourceRefList_new00_local);
  tolua_function(tolua_S,".call",tolua_CoreLuaAPI_ResourceRefList_new00_local);
  tolua_function(tolua_S,"new",tolua_CoreLuaAPI_ResourceRefList_new01);
  tolua_function(tolua_S,"new_local",tolua_CoreLuaAPI_ResourceRefList_new01_local);
  tolua_function(tolua_S,".call",tolua_CoreLuaAPI_ResourceRefList_new01_local);
  tolua_function(tolua_S,"delete",tolua_CoreLuaAPI_ResourceRefList_delete00);
  tolua_variable(tolua_S,"type",tolua_get_ResourceRefList_type,tolua_set_ResourceRefList_type);
  tolua_function(tolua_S,".eq",tolua_CoreLuaAPI_ResourceRefList__eq00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Variant","Variant","",tolua_collect_Variant);
 #else
 tolua_cclass(tolua_S,"Variant","Variant","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Variant");
  tolua_function(tolua_S,"_Setup",tolua_CoreLuaAPI_Variant__Setup00);
  tolua_function(tolua_S,"new",tolua_CoreLuaAPI_Variant_new00);
  tolua_function(tolua_S,"new_local",tolua_CoreLuaAPI_Variant_new00_local);
  tolua_function(tolua_S,".call",tolua_CoreLuaAPI_Variant_new00_local);
  tolua_function(tolua_S,"new",tolua_CoreLuaAPI_Variant_new01);
  tolua_function(tolua_S,"new_local",tolua_CoreLuaAPI_Variant_new01_local);
  tolua_function(tolua_S,".call",tolua_CoreLuaAPI_Variant_new01_local);
  tolua_function(tolua_S,"new",tolua_CoreLuaAPI_Variant_new02);
  tolua_function(tolua_S,"new_local",tolua_CoreLuaAPI_Variant_new02_local);
  tolua_function(tolua_S,".call",tolua_CoreLuaAPI_Variant_new02_local);
  tolua_function(tolua_S,"new",tolua_CoreLuaAPI_Variant_new03);
  tolua_function(tolua_S,"new_local",tolua_CoreLuaAPI_Variant_new03_local);
  tolua_function(tolua_S,".call",tolua_CoreLuaAPI_Variant_new03_local);
  tolua_function(tolua_S,"delete",tolua_CoreLuaAPI_Variant_delete00);
  tolua_function(tolua_S,"Clear",tolua_CoreLuaAPI_Variant_Clear00);
  tolua_function(tolua_S,".eq",tolua_CoreLuaAPI_Variant__eq00);
  tolua_function(tolua_S,"Set",tolua_CoreLuaAPI_Variant_Set00);
  tolua_function(tolua_S,"Get",tolua_CoreLuaAPI_Variant_Get00);
  tolua_function(tolua_S,"GetInt",tolua_CoreLuaAPI_Variant_GetInt00);
  tolua_function(tolua_S,"GetUInt",tolua_CoreLuaAPI_Variant_GetUInt00);
  tolua_function(tolua_S,"GetInt64",tolua_CoreLuaAPI_Variant_GetInt6400);
  tolua_function(tolua_S,"GetUInt64",tolua_CoreLuaAPI_Variant_GetUInt6400);
  tolua_function(tolua_S,"GetStringHash",tolua_CoreLuaAPI_Variant_GetStringHash00);
  tolua_function(tolua_S,"GetBool",tolua_CoreLuaAPI_Variant_GetBool00);
  tolua_function(tolua_S,"GetFloat",tolua_CoreLuaAPI_Variant_GetFloat00);
  tolua_function(tolua_S,"GetDouble",tolua_CoreLuaAPI_Variant_GetDouble00);
  tolua_function(tolua_S,"GetVector2",tolua_CoreLuaAPI_Variant_GetVector200);
  tolua_function(tolua_S,"GetVector3",tolua_CoreLuaAPI_Variant_GetVector300);
  tolua_function(tolua_S,"GetVector4",tolua_CoreLuaAPI_Variant_GetVector400);
  tolua_function(tolua_S,"GetQuaternion",tolua_CoreLuaAPI_Variant_GetQuaternion00);
  tolua_function(tolua_S,"GetColor",tolua_CoreLuaAPI_Variant_GetColor00);
  tolua_function(tolua_S,"GetString",tolua_CoreLuaAPI_Variant_GetString00);
  tolua_function(tolua_S,"GetRawBuffer",tolua_CoreLuaAPI_Variant_GetRawBuffer00);
  tolua_function(tolua_S,"GetBuffer",tolua_CoreLuaAPI_Variant_GetBuffer00);
  tolua_function(tolua_S,"GetVoidPtr",tolua_CoreLuaAPI_Variant_GetVoidPtr00);
  tolua_function(tolua_S,"GetResourceRef",tolua_CoreLuaAPI_Variant_GetResourceRef00);
  tolua_function(tolua_S,"GetResourceRefList",tolua_CoreLuaAPI_Variant_GetResourceRefList00);
  tolua_function(tolua_S,"GetVariantVector",tolua_CoreLuaAPI_Variant_GetVariantVector00);
  tolua_function(tolua_S,"GetVariantMap",tolua_CoreLuaAPI_Variant_GetVariantMap00);
  tolua_function(tolua_S,"GetStringVector",tolua_CoreLuaAPI_Variant_GetStringVector00);
  tolua_function(tolua_S,"GetRect",tolua_CoreLuaAPI_Variant_GetRect00);
  tolua_function(tolua_S,"GetIntRect",tolua_CoreLuaAPI_Variant_GetIntRect00);
  tolua_function(tolua_S,"GetIntVector2",tolua_CoreLuaAPI_Variant_GetIntVector200);
  tolua_function(tolua_S,"GetIntVector3",tolua_CoreLuaAPI_Variant_GetIntVector300);
  tolua_function(tolua_S,"GetPtr",tolua_CoreLuaAPI_Variant_GetPtr00);
  tolua_function(tolua_S,"GetMatrix3",tolua_CoreLuaAPI_Variant_GetMatrix300);
  tolua_function(tolua_S,"GetMatrix3x4",tolua_CoreLuaAPI_Variant_GetMatrix3x400);
  tolua_function(tolua_S,"GetMatrix4",tolua_CoreLuaAPI_Variant_GetMatrix400);
  tolua_function(tolua_S,"GetType",tolua_CoreLuaAPI_Variant_GetType00);
  tolua_function(tolua_S,"GetTypeName",tolua_CoreLuaAPI_Variant_GetTypeName00);
  tolua_function(tolua_S,"ToString",tolua_CoreLuaAPI_Variant_ToString00);
  tolua_function(tolua_S,"IsZero",tolua_CoreLuaAPI_Variant_IsZero00);
  tolua_function(tolua_S,"IsEmpty",tolua_CoreLuaAPI_Variant_IsEmpty00);
  tolua_variable(tolua_S,"type",tolua_get_Variant_type,NULL);
  tolua_variable(tolua_S,"typeName",tolua_get_Variant_typeName,NULL);
  tolua_variable(tolua_S,"zero",tolua_get_Variant_zero,NULL);
  tolua_variable(tolua_S,"empty",tolua_get_Variant_empty,NULL);
 tolua_endmodule(tolua_S);

 { /* begin embedded lua code */
  int top = lua_gettop(tolua_S);
  static const unsigned char B[] = {
  10, 86, 97,114,105, 97,110,116, 58, 95, 83,101,116,117,112,
   40, 34, 86, 97,114,105, 97,110,116, 34, 41, 10, 86, 97,114,
  105, 97,110,116, 58, 95, 83,101,116,117,112, 40, 34, 99,111,
  110,115,116, 32, 86, 97,114,105, 97,110,116, 34, 41, 10, 86,
   97,114,105, 97,110,116, 46, 95, 83,101,116,117,112, 32, 61,
   32,110,105,108, 45,32
  };
  tolua_dobuffer(tolua_S,(char*)B,sizeof(B),"tolua: embedded Lua code 1");
  lua_settop(tolua_S, top);
 } /* end of embedded lua code */

 #ifdef __cplusplus
 tolua_cclass(tolua_S,"VariantMap","VariantMap","",tolua_collect_VariantMap);
 #else
 tolua_cclass(tolua_S,"VariantMap","VariantMap","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"VariantMap");
  tolua_function(tolua_S,"_Setup",tolua_CoreLuaAPI_VariantMap__Setup00);
  tolua_function(tolua_S,"new",tolua_CoreLuaAPI_VariantMap_new00);
  tolua_function(tolua_S,"new_local",tolua_CoreLuaAPI_VariantMap_new00_local);
  tolua_function(tolua_S,".call",tolua_CoreLuaAPI_VariantMap_new00_local);
  tolua_function(tolua_S,"delete",tolua_CoreLuaAPI_VariantMap_delete00);
 tolua_endmodule(tolua_S);

 { /* begin embedded lua code */
  int top = lua_gettop(tolua_S);
  static const unsigned char B[] = {
  10, 86, 97,114,105, 97,110,116, 77, 97,112, 58, 95, 83,101,
  116,117,112, 40, 34, 86, 97,114,105, 97,110,116, 77, 97,112,
   34, 41, 10, 86, 97,114,105, 97,110,116, 77, 97,112, 58, 95,
   83,101,116,117,112, 40, 34, 99,111,110,115,116, 32, 86, 97,
  114,105, 97,110,116, 77, 97,112, 34, 41, 10, 86, 97,114,105,
   97,110,116, 77, 97,112, 46, 95, 83,101,116,117,112, 32, 61,
   32,110,105,108, 45, 45,32
  };
  tolua_dobuffer(tolua_S,(char*)B,sizeof(B),"tolua: embedded Lua code 2");
  lua_settop(tolua_S, top);
 } /* end of embedded lua code */

 tolua_constant(tolua_S,"BEZIER_CURVE",BEZIER_CURVE);
 tolua_constant(tolua_S,"CATMULL_ROM_CURVE",CATMULL_ROM_CURVE);
 tolua_constant(tolua_S,"LINEAR_CURVE",LINEAR_CURVE);
 tolua_constant(tolua_S,"CATMULL_ROM_FULL_CURVE",CATMULL_ROM_FULL_CURVE);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Spline","Spline","",tolua_collect_Spline);
 #else
 tolua_cclass(tolua_S,"Spline","Spline","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Spline");
  tolua_function(tolua_S,"new",tolua_CoreLuaAPI_Spline_new00);
  tolua_function(tolua_S,"new_local",tolua_CoreLuaAPI_Spline_new00_local);
  tolua_function(tolua_S,".call",tolua_CoreLuaAPI_Spline_new00_local);
  tolua_function(tolua_S,"new",tolua_CoreLuaAPI_Spline_new01);
  tolua_function(tolua_S,"new_local",tolua_CoreLuaAPI_Spline_new01_local);
  tolua_function(tolua_S,".call",tolua_CoreLuaAPI_Spline_new01_local);
  tolua_function(tolua_S,"new",tolua_CoreLuaAPI_Spline_new02);
  tolua_function(tolua_S,"new_local",tolua_CoreLuaAPI_Spline_new02_local);
  tolua_function(tolua_S,".call",tolua_CoreLuaAPI_Spline_new02_local);
  tolua_function(tolua_S,"delete",tolua_CoreLuaAPI_Spline_delete00);
  tolua_function(tolua_S,".eq",tolua_CoreLuaAPI_Spline__eq00);
  tolua_function(tolua_S,"GetPoint",tolua_CoreLuaAPI_Spline_GetPoint00);
  tolua_function(tolua_S,"GetKnot",tolua_CoreLuaAPI_Spline_GetKnot00);
  tolua_function(tolua_S,"SetKnot",tolua_CoreLuaAPI_Spline_SetKnot00);
  tolua_function(tolua_S,"AddKnot",tolua_CoreLuaAPI_Spline_AddKnot00);
  tolua_function(tolua_S,"AddKnot",tolua_CoreLuaAPI_Spline_AddKnot01);
  tolua_function(tolua_S,"RemoveKnot",tolua_CoreLuaAPI_Spline_RemoveKnot00);
  tolua_function(tolua_S,"RemoveKnot",tolua_CoreLuaAPI_Spline_RemoveKnot01);
  tolua_function(tolua_S,"Clear",tolua_CoreLuaAPI_Spline_Clear00);
  tolua_variable(tolua_S,"interpolationMode",tolua_get_Spline_interpolationMode,tolua_set_Spline_interpolationMode);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Time","Time","Object",NULL);
 tolua_beginmodule(tolua_S,"Time");
  tolua_function(tolua_S,"GetFrameNumber",tolua_CoreLuaAPI_Time_GetFrameNumber00);
  tolua_function(tolua_S,"GetTimeStep",tolua_CoreLuaAPI_Time_GetTimeStep00);
  tolua_function(tolua_S,"GetTimerPeriod",tolua_CoreLuaAPI_Time_GetTimerPeriod00);
  tolua_function(tolua_S,"GetElapsedTime",tolua_CoreLuaAPI_Time_GetElapsedTime00);
  tolua_function(tolua_S,"GetFramesPerSecond",tolua_CoreLuaAPI_Time_GetFramesPerSecond00);
  tolua_function(tolua_S,"GetSystemTime",tolua_CoreLuaAPI_Time_GetSystemTime00);
  tolua_function(tolua_S,"GetTimeSinceEpoch",tolua_CoreLuaAPI_Time_GetTimeSinceEpoch00);
  tolua_function(tolua_S,"GetTimeStamp",tolua_CoreLuaAPI_Time_GetTimeStamp00);
  tolua_function(tolua_S,"Sleep",tolua_CoreLuaAPI_Time_Sleep00);
  tolua_variable(tolua_S,"frameNumber",tolua_get_Time_frameNumber,NULL);
  tolua_variable(tolua_S,"timeStep",tolua_get_Time_timeStep,NULL);
  tolua_variable(tolua_S,"timerPeriod",tolua_get_Time_timerPeriod,NULL);
  tolua_variable(tolua_S,"elapsedTime",tolua_get_Time_elapsedTime,NULL);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"GetTime",tolua_CoreLuaAPI_GetTime00);
 tolua_variable(tolua_S,"time",tolua_get_time_ptr,NULL);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_CoreLuaAPI (lua_State* tolua_S) {
 return tolua_CoreLuaAPI_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif