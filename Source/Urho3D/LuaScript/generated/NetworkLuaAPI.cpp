/*
** Lua binding: NetworkLuaAPI
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
TOLUA_API int tolua_NetworkLuaAPI_open (lua_State* tolua_S);

#include "Network/Connection.h"
#include "Network/HttpRequest.h"
#include "Network/Network.h"
#include "Network/NetworkPriority.h"
using namespace Urho3D;
#pragma warning(disable:4800)

static VectorBuffer HttpRequestRead(HttpRequest* request, unsigned size)
{
    unsigned char* data = new unsigned char[size];
    request->Read(data, size);
    VectorBuffer buffer(data, size);
    delete [] data;
    return buffer;
}

#define TOLUA_DISABLE_tolua_NetworkLuaAPI_GetNetwork00
static int tolua_NetworkLuaAPI_GetNetwork00(lua_State* tolua_S)
{
    return ToluaGetSubsystem<Network>(tolua_S);
}

#define TOLUA_DISABLE_tolua_get_network_ptr
#define tolua_get_network_ptr tolua_NetworkLuaAPI_GetNetwork00

static HttpRequest* NetworkMakeHttpRequest(Network* network, const String& url, const String& verb = String::EMPTY, const Vector<String>& headers = Vector<String>(), const String postData = String::EMPTY)
{
    if (!network)
        return 0;

    return network->MakeHttpRequest(url, verb, headers, postData).Detach();
}

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

static int tolua_collect_VariantVector (lua_State* tolua_S)
{
 VariantVector* self = (VariantVector*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_StringHash (lua_State* tolua_S)
{
 StringHash* self = (StringHash*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Matrix3 (lua_State* tolua_S)
{
 Matrix3* self = (Matrix3*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_ResourceRef (lua_State* tolua_S)
{
 ResourceRef* self = (ResourceRef*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_IntVector3 (lua_State* tolua_S)
{
 IntVector3* self = (IntVector3*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Quaternion (lua_State* tolua_S)
{
 Quaternion* self = (Quaternion*) tolua_tousertype(tolua_S,1,0);
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

static int tolua_collect_BoundingBox (lua_State* tolua_S)
{
 BoundingBox* self = (BoundingBox*) tolua_tousertype(tolua_S,1,0);
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
 tolua_usertype(tolua_S,"Matrix3x4");
 tolua_usertype(tolua_S,"Vector<String>");
 tolua_usertype(tolua_S,"Variant");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"Controls");
 tolua_usertype(tolua_S,"VariantType");
 tolua_usertype(tolua_S,"IntRect");
 tolua_usertype(tolua_S,"VariantVector");
 tolua_usertype(tolua_S,"Matrix3");
 tolua_usertype(tolua_S,"IntVector3");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"Matrix4");
 tolua_usertype(tolua_S,"IntVector2");
 tolua_usertype(tolua_S,"RemoteEvent");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"VectorBuffer");
 tolua_usertype(tolua_S,"Vector4");
 tolua_usertype(tolua_S,"PackageFile");
 tolua_usertype(tolua_S,"NetworkPriority");
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"Connection");
 tolua_usertype(tolua_S,"Quaternion");
 tolua_usertype(tolua_S,"BoundingBox");
 tolua_usertype(tolua_S,"Network");
 tolua_usertype(tolua_S,"Rect");
 tolua_usertype(tolua_S,"HttpRequest");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"Scene");
 tolua_usertype(tolua_S,"ResourceRefList");
 tolua_usertype(tolua_S,"ResourceRef");
 tolua_usertype(tolua_S,"StringHash");
}

/* get function: senderID_ of class  RemoteEvent */
#ifndef TOLUA_DISABLE_tolua_get_RemoteEvent_senderID
static int tolua_get_RemoteEvent_senderID(lua_State* tolua_S)
{
  RemoteEvent* self = (RemoteEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'senderID_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->senderID_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: senderID_ of class  RemoteEvent */
#ifndef TOLUA_DISABLE_tolua_set_RemoteEvent_senderID
static int tolua_set_RemoteEvent_senderID(lua_State* tolua_S)
{
  RemoteEvent* self = (RemoteEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'senderID_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->senderID_ = ((unsigned)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: eventType_ of class  RemoteEvent */
#ifndef TOLUA_DISABLE_tolua_get_RemoteEvent_eventType
static int tolua_get_RemoteEvent_eventType(lua_State* tolua_S)
{
  RemoteEvent* self = (RemoteEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eventType_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->eventType_,"StringHash");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: eventType_ of class  RemoteEvent */
#ifndef TOLUA_DISABLE_tolua_set_RemoteEvent_eventType
static int tolua_set_RemoteEvent_eventType(lua_State* tolua_S)
{
  RemoteEvent* self = (RemoteEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eventType_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->eventType_ = *((StringHash*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: eventData_ of class  RemoteEvent */
#ifndef TOLUA_DISABLE_tolua_get_RemoteEvent_eventData
static int tolua_get_RemoteEvent_eventData(lua_State* tolua_S)
{
  RemoteEvent* self = (RemoteEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eventData_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->eventData_,"VariantMap");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: eventData_ of class  RemoteEvent */
#ifndef TOLUA_DISABLE_tolua_set_RemoteEvent_eventData
static int tolua_set_RemoteEvent_eventData(lua_State* tolua_S)
{
  RemoteEvent* self = (RemoteEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eventData_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"VariantMap",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->eventData_ = *((VariantMap*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: inOrder_ of class  RemoteEvent */
#ifndef TOLUA_DISABLE_tolua_get_RemoteEvent_inOrder
static int tolua_get_RemoteEvent_inOrder(lua_State* tolua_S)
{
  RemoteEvent* self = (RemoteEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'inOrder_'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->inOrder_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: inOrder_ of class  RemoteEvent */
#ifndef TOLUA_DISABLE_tolua_set_RemoteEvent_inOrder
static int tolua_set_RemoteEvent_inOrder(lua_State* tolua_S)
{
  RemoteEvent* self = (RemoteEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'inOrder_'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->inOrder_ = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendMessage of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SendMessage00
static int tolua_NetworkLuaAPI_Connection_SendMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const VectorBuffer",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  int msgID = ((int)  tolua_tonumber(tolua_S,2,0));
  bool reliable = ((bool)  tolua_toboolean(tolua_S,3,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,4,0));
  const VectorBuffer* msg = ((const VectorBuffer*)  tolua_tousertype(tolua_S,5,0));
  unsigned contentID = ((unsigned)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendMessage'", NULL);
#endif
 {
  self->SendMessage(msgID,reliable,inOrder,*msg,contentID);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SendMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendRemoteEvent of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SendRemoteEvent00
static int tolua_NetworkLuaAPI_Connection_SendRemoteEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  StringHash eventType = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendRemoteEvent'", NULL);
#endif
 {
  self->SendRemoteEvent(eventType,inOrder);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SendRemoteEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendRemoteEvent of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SendRemoteEvent01
static int tolua_NetworkLuaAPI_Connection_SendRemoteEvent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  StringHash eventType = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,3,0));
  const VariantMap* eventData = ((const VariantMap*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendRemoteEvent'", NULL);
#endif
 {
  self->SendRemoteEvent(eventType,inOrder,*eventData);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Connection_SendRemoteEvent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendRemoteEvent of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SendRemoteEvent02
static int tolua_NetworkLuaAPI_Connection_SendRemoteEvent02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  const String eventType = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendRemoteEvent'", NULL);
#endif
 {
  self->SendRemoteEvent(eventType,inOrder);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Connection_SendRemoteEvent01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendRemoteEvent of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SendRemoteEvent03
static int tolua_NetworkLuaAPI_Connection_SendRemoteEvent03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  const String eventType = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,3,0));
  const VariantMap* eventData = ((const VariantMap*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendRemoteEvent'", NULL);
#endif
 {
  self->SendRemoteEvent(eventType,inOrder,*eventData);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Connection_SendRemoteEvent02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendRemoteEvent of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SendRemoteEvent04
static int tolua_NetworkLuaAPI_Connection_SendRemoteEvent04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"StringHash",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
  StringHash eventType = *((StringHash*)  tolua_tousertype(tolua_S,3,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendRemoteEvent'", NULL);
#endif
 {
  self->SendRemoteEvent(node,eventType,inOrder);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Connection_SendRemoteEvent03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendRemoteEvent of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SendRemoteEvent05
static int tolua_NetworkLuaAPI_Connection_SendRemoteEvent05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"StringHash",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
  StringHash eventType = *((StringHash*)  tolua_tousertype(tolua_S,3,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,4,0));
  const VariantMap* eventData = ((const VariantMap*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendRemoteEvent'", NULL);
#endif
 {
  self->SendRemoteEvent(node,eventType,inOrder,*eventData);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Connection_SendRemoteEvent04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendRemoteEvent of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SendRemoteEvent06
static int tolua_NetworkLuaAPI_Connection_SendRemoteEvent06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const String eventType = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendRemoteEvent'", NULL);
#endif
 {
  self->SendRemoteEvent(node,eventType,inOrder);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Connection_SendRemoteEvent05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendRemoteEvent of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SendRemoteEvent07
static int tolua_NetworkLuaAPI_Connection_SendRemoteEvent07(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const String eventType = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,4,0));
  const VariantMap* eventData = ((const VariantMap*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendRemoteEvent'", NULL);
#endif
 {
  self->SendRemoteEvent(node,eventType,inOrder,*eventData);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Connection_SendRemoteEvent06(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScene of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SetScene00
static int tolua_NetworkLuaAPI_Connection_SetScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  Scene* newScene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScene'", NULL);
#endif
 {
  self->SetScene(newScene);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIdentity of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SetIdentity00
static int tolua_NetworkLuaAPI_Connection_SetIdentity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  const VariantMap* identity = ((const VariantMap*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIdentity'", NULL);
#endif
 {
  self->SetIdentity(*identity);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetControls of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SetControls00
static int tolua_NetworkLuaAPI_Connection_SetControls00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Controls",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  const Controls* newControls = ((const Controls*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetControls'", NULL);
#endif
 {
  self->SetControls(*newControls);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetControls'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SetPosition00
static int tolua_NetworkLuaAPI_Connection_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetRotation of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SetRotation00
static int tolua_NetworkLuaAPI_Connection_SetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetConnectPending of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SetConnectPending00
static int tolua_NetworkLuaAPI_Connection_SetConnectPending00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  bool connectPending = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetConnectPending'", NULL);
#endif
 {
  self->SetConnectPending(connectPending);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetConnectPending'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLogStatistics of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SetLogStatistics00
static int tolua_NetworkLuaAPI_Connection_SetLogStatistics00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLogStatistics'", NULL);
#endif
 {
  self->SetLogStatistics(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLogStatistics'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Disconnect of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_Disconnect00
static int tolua_NetworkLuaAPI_Connection_Disconnect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  int waitMSec = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Disconnect'", NULL);
#endif
 {
  self->Disconnect(waitMSec);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Disconnect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendPackageToClient of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_SendPackageToClient00
static int tolua_NetworkLuaAPI_Connection_SendPackageToClient00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"PackageFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
  PackageFile* package = ((PackageFile*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendPackageToClient'", NULL);
#endif
 {
  self->SendPackageToClient(package);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SendPackageToClient'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIdentity of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetIdentity00
static int tolua_NetworkLuaAPI_Connection_GetIdentity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIdentity'", NULL);
#endif
 {
  VariantMap& tolua_ret = (VariantMap&)  self->GetIdentity();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"VariantMap");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScene of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetScene00
static int tolua_NetworkLuaAPI_Connection_GetScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScene'", NULL);
#endif
 {
  Scene* tolua_ret = (Scene*)  self->GetScene();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Scene");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetControls of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetControls00
static int tolua_NetworkLuaAPI_Connection_GetControls00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetControls'", NULL);
#endif
 {
  const Controls& tolua_ret = (const Controls&)  self->GetControls();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Controls");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetControls'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTimeStamp of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetTimeStamp00
static int tolua_NetworkLuaAPI_Connection_GetTimeStamp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTimeStamp'", NULL);
#endif
 {
  unsigned char tolua_ret = (unsigned char)  self->GetTimeStamp();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: GetPosition of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetPosition00
static int tolua_NetworkLuaAPI_Connection_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetRotation of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetRotation00
static int tolua_NetworkLuaAPI_Connection_GetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsClient of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_IsClient00
static int tolua_NetworkLuaAPI_Connection_IsClient00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsClient'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsClient();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsClient'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsConnected of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_IsConnected00
static int tolua_NetworkLuaAPI_Connection_IsConnected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsConnected'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsConnected();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsConnected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsConnectPending of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_IsConnectPending00
static int tolua_NetworkLuaAPI_Connection_IsConnectPending00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsConnectPending'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsConnectPending();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsConnectPending'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsSceneLoaded of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_IsSceneLoaded00
static int tolua_NetworkLuaAPI_Connection_IsSceneLoaded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsSceneLoaded'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsSceneLoaded();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsSceneLoaded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLogStatistics of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetLogStatistics00
static int tolua_NetworkLuaAPI_Connection_GetLogStatistics00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLogStatistics'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetLogStatistics();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLogStatistics'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAddress of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetAddress00
static int tolua_NetworkLuaAPI_Connection_GetAddress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAddress'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetAddress();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAddress'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPort of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetPort00
static int tolua_NetworkLuaAPI_Connection_GetPort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPort'", NULL);
#endif
 {
  unsigned short tolua_ret = (unsigned short)  self->GetPort();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRoundTripTime of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetRoundTripTime00
static int tolua_NetworkLuaAPI_Connection_GetRoundTripTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRoundTripTime'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRoundTripTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRoundTripTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLastHeardTime of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetLastHeardTime00
static int tolua_NetworkLuaAPI_Connection_GetLastHeardTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLastHeardTime'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetLastHeardTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLastHeardTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBytesInPerSec of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetBytesInPerSec00
static int tolua_NetworkLuaAPI_Connection_GetBytesInPerSec00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBytesInPerSec'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetBytesInPerSec();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBytesInPerSec'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBytesOutPerSec of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetBytesOutPerSec00
static int tolua_NetworkLuaAPI_Connection_GetBytesOutPerSec00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBytesOutPerSec'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetBytesOutPerSec();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBytesOutPerSec'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPacketsInPerSec of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetPacketsInPerSec00
static int tolua_NetworkLuaAPI_Connection_GetPacketsInPerSec00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPacketsInPerSec'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetPacketsInPerSec();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPacketsInPerSec'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPacketsOutPerSec of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetPacketsOutPerSec00
static int tolua_NetworkLuaAPI_Connection_GetPacketsOutPerSec00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPacketsOutPerSec'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetPacketsOutPerSec();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPacketsOutPerSec'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_ToString00
static int tolua_NetworkLuaAPI_Connection_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetNumDownloads of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetNumDownloads00
static int tolua_NetworkLuaAPI_Connection_GetNumDownloads00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumDownloads'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumDownloads();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumDownloads'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDownloadName of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetDownloadName00
static int tolua_NetworkLuaAPI_Connection_GetDownloadName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDownloadName'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetDownloadName();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDownloadName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDownloadProgress of class  Connection */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Connection_GetDownloadProgress00
static int tolua_NetworkLuaAPI_Connection_GetDownloadProgress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Connection* self = (const Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDownloadProgress'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDownloadProgress();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDownloadProgress'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: identity of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_identity_ref
static int tolua_get_Connection_identity_ref(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'identity'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetIdentity(),"VariantMap");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: identity of class  Connection */
#ifndef TOLUA_DISABLE_tolua_set_Connection_identity_ref
static int tolua_set_Connection_identity_ref(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'identity'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"VariantMap",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetIdentity((*(VariantMap*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scene of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_scene_ptr
static int tolua_get_Connection_scene_ptr(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scene'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetScene(),"Scene");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scene of class  Connection */
#ifndef TOLUA_DISABLE_tolua_set_Connection_scene_ptr
static int tolua_set_Connection_scene_ptr(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scene'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetScene(((Scene*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: controls of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_controls_ref
static int tolua_get_Connection_controls_ref(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'controls'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetControls(),"Controls");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: controls of class  Connection */
#ifndef TOLUA_DISABLE_tolua_set_Connection_controls_ref
static int tolua_set_Connection_controls_ref(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'controls'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Controls",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetControls((*(Controls*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: timeStamp of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_unsigned_timeStamp
static int tolua_get_Connection_unsigned_timeStamp(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeStamp'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTimeStamp());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: position of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_position_ref
static int tolua_get_Connection_position_ref(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetPosition(),"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: position of class  Connection */
#ifndef TOLUA_DISABLE_tolua_set_Connection_position_ref
static int tolua_set_Connection_position_ref(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: rotation of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_rotation_ref
static int tolua_get_Connection_rotation_ref(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetRotation(),"Quaternion");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rotation of class  Connection */
#ifndef TOLUA_DISABLE_tolua_set_Connection_rotation_ref
static int tolua_set_Connection_rotation_ref(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: client of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_client
static int tolua_get_Connection_client(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'client'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsClient());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: connected of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_connected
static int tolua_get_Connection_connected(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'connected'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsConnected());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: connectPending of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_connectPending
static int tolua_get_Connection_connectPending(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'connectPending'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsConnectPending());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: connectPending of class  Connection */
#ifndef TOLUA_DISABLE_tolua_set_Connection_connectPending
static int tolua_set_Connection_connectPending(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'connectPending'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetConnectPending(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sceneLoaded of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_sceneLoaded
static int tolua_get_Connection_sceneLoaded(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sceneLoaded'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsSceneLoaded());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: logStatistics of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_logStatistics
static int tolua_get_Connection_logStatistics(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'logStatistics'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetLogStatistics());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: logStatistics of class  Connection */
#ifndef TOLUA_DISABLE_tolua_set_Connection_logStatistics
static int tolua_set_Connection_logStatistics(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'logStatistics'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLogStatistics(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: address of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_address
static int tolua_get_Connection_address(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'address'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetAddress());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: port of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_unsigned_port
static int tolua_get_Connection_unsigned_port(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'port'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetPort());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: roundTripTime of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_roundTripTime
static int tolua_get_Connection_roundTripTime(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'roundTripTime'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRoundTripTime());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: lastHeardTime of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_lastHeardTime
static int tolua_get_Connection_lastHeardTime(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'lastHeardTime'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLastHeardTime());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bytesInPerSec of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_bytesInPerSec
static int tolua_get_Connection_bytesInPerSec(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bytesInPerSec'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetBytesInPerSec());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bytesOutPerSec of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_bytesOutPerSec
static int tolua_get_Connection_bytesOutPerSec(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bytesOutPerSec'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetBytesOutPerSec());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: packetsInPerSec of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_packetsInPerSec
static int tolua_get_Connection_packetsInPerSec(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'packetsInPerSec'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetPacketsInPerSec());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: packetsOutPerSec of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_packetsOutPerSec
static int tolua_get_Connection_packetsOutPerSec(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'packetsOutPerSec'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetPacketsOutPerSec());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numDownloads of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_numDownloads
static int tolua_get_Connection_numDownloads(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numDownloads'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumDownloads());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: downloadName of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_downloadName
static int tolua_get_Connection_downloadName(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downloadName'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetDownloadName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: downloadProgress of class  Connection */
#ifndef TOLUA_DISABLE_tolua_get_Connection_downloadProgress
static int tolua_get_Connection_downloadProgress(lua_State* tolua_S)
{
  Connection* self = (Connection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downloadProgress'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDownloadProgress());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetURL of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_GetURL00
static int tolua_NetworkLuaAPI_HttpRequest_GetURL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const HttpRequest* self = (const HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetURL'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetURL();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetURL'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVerb of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_GetVerb00
static int tolua_NetworkLuaAPI_HttpRequest_GetVerb00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const HttpRequest* self = (const HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVerb'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetVerb();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVerb'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetError of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_GetError00
static int tolua_NetworkLuaAPI_HttpRequest_GetError00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const HttpRequest* self = (const HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetError'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetError();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetError'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetState of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_GetState00
static int tolua_NetworkLuaAPI_HttpRequest_GetState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const HttpRequest* self = (const HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetState'", NULL);
#endif
 {
  HttpRequestState tolua_ret = (HttpRequestState)  self->GetState();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAvailableSize of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_GetAvailableSize00
static int tolua_NetworkLuaAPI_HttpRequest_GetAvailableSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const HttpRequest* self = (const HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAvailableSize'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetAvailableSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAvailableSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsOpen of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_IsOpen00
static int tolua_NetworkLuaAPI_HttpRequest_IsOpen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const HttpRequest* self = (const HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsOpen'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsOpen();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsOpen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HttpRequestRead of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_Read00
static int tolua_NetworkLuaAPI_HttpRequest_Read00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
  unsigned size = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HttpRequestRead'", NULL);
#endif
 {
  tolua_outside VectorBuffer tolua_ret = (tolua_outside VectorBuffer)  HttpRequestRead(self,size);
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
 tolua_error(tolua_S,"#ferror in function 'Read'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsEof of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_IsEof00
static int tolua_NetworkLuaAPI_HttpRequest_IsEof00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const HttpRequest* self = (const HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsEof'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsEof();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsEof'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadInt of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadInt00
static int tolua_NetworkLuaAPI_HttpRequest_ReadInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadInt'", NULL);
#endif
 {
  int tolua_ret = (int)  self->ReadInt();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadShort of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadShort00
static int tolua_NetworkLuaAPI_HttpRequest_ReadShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadShort'", NULL);
#endif
 {
  short tolua_ret = (short)  self->ReadShort();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadShort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadByte of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadByte00
static int tolua_NetworkLuaAPI_HttpRequest_ReadByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadByte'", NULL);
#endif
 {
  signed char tolua_ret = (signed char)  self->ReadByte();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadByte'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadUInt of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadUInt00
static int tolua_NetworkLuaAPI_HttpRequest_ReadUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadUInt'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->ReadUInt();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadUInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadUShort of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadUShort00
static int tolua_NetworkLuaAPI_HttpRequest_ReadUShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadUShort'", NULL);
#endif
 {
  unsigned short tolua_ret = (unsigned short)  self->ReadUShort();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadUShort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadUByte of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadUByte00
static int tolua_NetworkLuaAPI_HttpRequest_ReadUByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadUByte'", NULL);
#endif
 {
  unsigned char tolua_ret = (unsigned char)  self->ReadUByte();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadUByte'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadBool of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadBool00
static int tolua_NetworkLuaAPI_HttpRequest_ReadBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadBool'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->ReadBool();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadFloat of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadFloat00
static int tolua_NetworkLuaAPI_HttpRequest_ReadFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadFloat'", NULL);
#endif
 {
  float tolua_ret = (float)  self->ReadFloat();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadDouble of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadDouble00
static int tolua_NetworkLuaAPI_HttpRequest_ReadDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadDouble'", NULL);
#endif
 {
  double tolua_ret = (double)  self->ReadDouble();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadDouble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadIntRect of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadIntRect00
static int tolua_NetworkLuaAPI_HttpRequest_ReadIntRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadIntRect'", NULL);
#endif
 {
  IntRect tolua_ret = (IntRect)  self->ReadIntRect();
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
 tolua_error(tolua_S,"#ferror in function 'ReadIntRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadIntVector2 of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadIntVector200
static int tolua_NetworkLuaAPI_HttpRequest_ReadIntVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadIntVector2'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->ReadIntVector2();
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
 tolua_error(tolua_S,"#ferror in function 'ReadIntVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadIntVector3 of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadIntVector300
static int tolua_NetworkLuaAPI_HttpRequest_ReadIntVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadIntVector3'", NULL);
#endif
 {
  IntVector3 tolua_ret = (IntVector3)  self->ReadIntVector3();
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
 tolua_error(tolua_S,"#ferror in function 'ReadIntVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadRect of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadRect00
static int tolua_NetworkLuaAPI_HttpRequest_ReadRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadRect'", NULL);
#endif
 {
  Rect tolua_ret = (Rect)  self->ReadRect();
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
 tolua_error(tolua_S,"#ferror in function 'ReadRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadVector2 of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadVector200
static int tolua_NetworkLuaAPI_HttpRequest_ReadVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadVector2'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->ReadVector2();
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
 tolua_error(tolua_S,"#ferror in function 'ReadVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadVector3 of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadVector300
static int tolua_NetworkLuaAPI_HttpRequest_ReadVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadVector3'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->ReadVector3();
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
 tolua_error(tolua_S,"#ferror in function 'ReadVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadPackedVector3 of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadPackedVector300
static int tolua_NetworkLuaAPI_HttpRequest_ReadPackedVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
  float maxAbsCoord = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadPackedVector3'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->ReadPackedVector3(maxAbsCoord);
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
 tolua_error(tolua_S,"#ferror in function 'ReadPackedVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadVector4 of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadVector400
static int tolua_NetworkLuaAPI_HttpRequest_ReadVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadVector4'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->ReadVector4();
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
 tolua_error(tolua_S,"#ferror in function 'ReadVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadQuaternion of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadQuaternion00
static int tolua_NetworkLuaAPI_HttpRequest_ReadQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadQuaternion'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->ReadQuaternion();
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
 tolua_error(tolua_S,"#ferror in function 'ReadQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadPackedQuaternion of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadPackedQuaternion00
static int tolua_NetworkLuaAPI_HttpRequest_ReadPackedQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadPackedQuaternion'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->ReadPackedQuaternion();
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
 tolua_error(tolua_S,"#ferror in function 'ReadPackedQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadMatrix3 of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadMatrix300
static int tolua_NetworkLuaAPI_HttpRequest_ReadMatrix300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadMatrix3'", NULL);
#endif
 {
  Matrix3 tolua_ret = (Matrix3)  self->ReadMatrix3();
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
 tolua_error(tolua_S,"#ferror in function 'ReadMatrix3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadMatrix3x4 of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadMatrix3x400
static int tolua_NetworkLuaAPI_HttpRequest_ReadMatrix3x400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadMatrix3x4'", NULL);
#endif
 {
  Matrix3x4 tolua_ret = (Matrix3x4)  self->ReadMatrix3x4();
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
 tolua_error(tolua_S,"#ferror in function 'ReadMatrix3x4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadMatrix4 of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadMatrix400
static int tolua_NetworkLuaAPI_HttpRequest_ReadMatrix400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadMatrix4'", NULL);
#endif
 {
  Matrix4 tolua_ret = (Matrix4)  self->ReadMatrix4();
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
 tolua_error(tolua_S,"#ferror in function 'ReadMatrix4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadColor of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadColor00
static int tolua_NetworkLuaAPI_HttpRequest_ReadColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadColor'", NULL);
#endif
 {
  Color tolua_ret = (Color)  self->ReadColor();
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
 tolua_error(tolua_S,"#ferror in function 'ReadColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadBoundingBox of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadBoundingBox00
static int tolua_NetworkLuaAPI_HttpRequest_ReadBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadBoundingBox'", NULL);
#endif
 {
  BoundingBox tolua_ret = (BoundingBox)  self->ReadBoundingBox();
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
 tolua_error(tolua_S,"#ferror in function 'ReadBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadString of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadString00
static int tolua_NetworkLuaAPI_HttpRequest_ReadString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ReadString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadFileID of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadFileID00
static int tolua_NetworkLuaAPI_HttpRequest_ReadFileID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadFileID'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ReadFileID();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadFileID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadStringHash of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadStringHash00
static int tolua_NetworkLuaAPI_HttpRequest_ReadStringHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadStringHash'", NULL);
#endif
 {
  StringHash tolua_ret = (StringHash)  self->ReadStringHash();
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
 tolua_error(tolua_S,"#ferror in function 'ReadStringHash'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadBuffer of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadBuffer00
static int tolua_NetworkLuaAPI_HttpRequest_ReadBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadBuffer'", NULL);
#endif
 {
  VectorBuffer tolua_ret = (VectorBuffer)  self->ReadBuffer();
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
 tolua_error(tolua_S,"#ferror in function 'ReadBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadResourceRef of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadResourceRef00
static int tolua_NetworkLuaAPI_HttpRequest_ReadResourceRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadResourceRef'", NULL);
#endif
 {
  ResourceRef tolua_ret = (ResourceRef)  self->ReadResourceRef();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((ResourceRef)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"ResourceRef");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(ResourceRef));
  tolua_pushusertype(tolua_S,tolua_obj,"ResourceRef");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadResourceRef'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadResourceRefList of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadResourceRefList00
static int tolua_NetworkLuaAPI_HttpRequest_ReadResourceRefList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadResourceRefList'", NULL);
#endif
 {
  ResourceRefList tolua_ret = (ResourceRefList)  self->ReadResourceRefList();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((ResourceRefList)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"ResourceRefList");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(ResourceRefList));
  tolua_pushusertype(tolua_S,tolua_obj,"ResourceRefList");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadResourceRefList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadVariant of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadVariant00
static int tolua_NetworkLuaAPI_HttpRequest_ReadVariant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadVariant'", NULL);
#endif
 {
  Variant tolua_ret = (Variant)  self->ReadVariant();
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
 tolua_error(tolua_S,"#ferror in function 'ReadVariant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadVariant of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadVariant01
static int tolua_NetworkLuaAPI_HttpRequest_ReadVariant01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"VariantType",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
  VariantType type = *((VariantType*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadVariant'", NULL);
#endif
 {
  Variant tolua_ret = (Variant)  self->ReadVariant(type);
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
tolua_lerror:
 return tolua_NetworkLuaAPI_HttpRequest_ReadVariant00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadVariantVector of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadVariantVector00
static int tolua_NetworkLuaAPI_HttpRequest_ReadVariantVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadVariantVector'", NULL);
#endif
 {
  VariantVector tolua_ret = (VariantVector)  self->ReadVariantVector();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((VariantVector)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"VariantVector");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(VariantVector));
  tolua_pushusertype(tolua_S,tolua_obj,"VariantVector");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadVariantVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadVariantMap of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadVariantMap00
static int tolua_NetworkLuaAPI_HttpRequest_ReadVariantMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadVariantMap'", NULL);
#endif
 {
  VariantMap tolua_ret = (VariantMap)  self->ReadVariantMap();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((VariantMap)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"VariantMap");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(VariantMap));
  tolua_pushusertype(tolua_S,tolua_obj,"VariantMap");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadVariantMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadVLE of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadVLE00
static int tolua_NetworkLuaAPI_HttpRequest_ReadVLE00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadVLE'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->ReadVLE();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadVLE'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadNetID of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadNetID00
static int tolua_NetworkLuaAPI_HttpRequest_ReadNetID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadNetID'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->ReadNetID();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadNetID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadLine of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_HttpRequest_ReadLine00
static int tolua_NetworkLuaAPI_HttpRequest_ReadLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"HttpRequest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadLine'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ReadLine();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: URL of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_get_HttpRequest_URL
static int tolua_get_HttpRequest_URL(lua_State* tolua_S)
{
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'URL'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetURL());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: verb of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_get_HttpRequest_verb
static int tolua_get_HttpRequest_verb(lua_State* tolua_S)
{
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'verb'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetVerb());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: error of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_get_HttpRequest_error
static int tolua_get_HttpRequest_error(lua_State* tolua_S)
{
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'error'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetError());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: state of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_get_HttpRequest_state
static int tolua_get_HttpRequest_state(lua_State* tolua_S)
{
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'state'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetState());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: availableSize of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_get_HttpRequest_availableSize
static int tolua_get_HttpRequest_availableSize(lua_State* tolua_S)
{
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'availableSize'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAvailableSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: open of class  HttpRequest */
#ifndef TOLUA_DISABLE_tolua_get_HttpRequest_open
static int tolua_get_HttpRequest_open(lua_State* tolua_S)
{
  HttpRequest* self = (HttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'open'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsOpen());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Connect of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_Connect00
static int tolua_NetworkLuaAPI_Network_Connect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,4,"Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  const String address = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  unsigned short port = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Connect'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Connect(address,port,scene);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Connect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Connect of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_Connect01
static int tolua_NetworkLuaAPI_Network_Connect01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,4,"Scene",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  const String address = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  unsigned short port = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,4,0));
  const VariantMap* identity = ((const VariantMap*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Connect'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Connect(address,port,scene,*identity);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_NetworkLuaAPI_Network_Connect00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Disconnect of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_Disconnect00
static int tolua_NetworkLuaAPI_Network_Disconnect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  int waitMSec = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Disconnect'", NULL);
#endif
 {
  self->Disconnect(waitMSec);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Disconnect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StartServer of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_StartServer00
static int tolua_NetworkLuaAPI_Network_StartServer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  unsigned short port = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StartServer'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->StartServer(port);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StartServer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StopServer of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_StopServer00
static int tolua_NetworkLuaAPI_Network_StopServer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StopServer'", NULL);
#endif
 {
  self->StopServer();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StopServer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BroadcastMessage of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_BroadcastMessage00
static int tolua_NetworkLuaAPI_Network_BroadcastMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const VectorBuffer",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  int msgID = ((int)  tolua_tonumber(tolua_S,2,0));
  bool reliable = ((bool)  tolua_toboolean(tolua_S,3,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,4,0));
  const VectorBuffer* msg = ((const VectorBuffer*)  tolua_tousertype(tolua_S,5,0));
  unsigned contentID = ((unsigned)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BroadcastMessage'", NULL);
#endif
 {
  self->BroadcastMessage(msgID,reliable,inOrder,*msg,contentID);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BroadcastMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BroadcastRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent00
static int tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  StringHash eventType = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BroadcastRemoteEvent'", NULL);
#endif
 {
  self->BroadcastRemoteEvent(eventType,inOrder);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BroadcastRemoteEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BroadcastRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent01
static int tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  StringHash eventType = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,3,0));
  const VariantMap* eventData = ((const VariantMap*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BroadcastRemoteEvent'", NULL);
#endif
 {
  self->BroadcastRemoteEvent(eventType,inOrder,*eventData);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BroadcastRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent02
static int tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  const String eventType = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BroadcastRemoteEvent'", NULL);
#endif
 {
  self->BroadcastRemoteEvent(eventType,inOrder);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BroadcastRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent03
static int tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  const String eventType = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,3,0));
  const VariantMap* eventData = ((const VariantMap*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BroadcastRemoteEvent'", NULL);
#endif
 {
  self->BroadcastRemoteEvent(eventType,inOrder,*eventData);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BroadcastRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent04
static int tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"StringHash",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  StringHash eventType = *((StringHash*)  tolua_tousertype(tolua_S,3,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BroadcastRemoteEvent'", NULL);
#endif
 {
  self->BroadcastRemoteEvent(scene,eventType,inOrder);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BroadcastRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent05
static int tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"StringHash",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  StringHash eventType = *((StringHash*)  tolua_tousertype(tolua_S,3,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,4,0));
  const VariantMap* eventData = ((const VariantMap*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BroadcastRemoteEvent'", NULL);
#endif
 {
  self->BroadcastRemoteEvent(scene,eventType,inOrder,*eventData);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BroadcastRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent06
static int tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  const String eventType = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BroadcastRemoteEvent'", NULL);
#endif
 {
  self->BroadcastRemoteEvent(scene,eventType,inOrder);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BroadcastRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent07
static int tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent07(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  const String eventType = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,4,0));
  const VariantMap* eventData = ((const VariantMap*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BroadcastRemoteEvent'", NULL);
#endif
 {
  self->BroadcastRemoteEvent(scene,eventType,inOrder,*eventData);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent06(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BroadcastRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent08
static int tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent08(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"StringHash",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
  StringHash eventType = *((StringHash*)  tolua_tousertype(tolua_S,3,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BroadcastRemoteEvent'", NULL);
#endif
 {
  self->BroadcastRemoteEvent(node,eventType,inOrder);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent07(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BroadcastRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent09
static int tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent09(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"StringHash",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
  StringHash eventType = *((StringHash*)  tolua_tousertype(tolua_S,3,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,4,0));
  const VariantMap* eventData = ((const VariantMap*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BroadcastRemoteEvent'", NULL);
#endif
 {
  self->BroadcastRemoteEvent(node,eventType,inOrder,*eventData);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent08(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BroadcastRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent10
static int tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent10(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const String eventType = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BroadcastRemoteEvent'", NULL);
#endif
 {
  self->BroadcastRemoteEvent(node,eventType,inOrder);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent09(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BroadcastRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent11
static int tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent11(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const String eventType = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
  bool inOrder = ((bool)  tolua_toboolean(tolua_S,4,0));
  const VariantMap* eventData = ((const VariantMap*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BroadcastRemoteEvent'", NULL);
#endif
 {
  self->BroadcastRemoteEvent(node,eventType,inOrder,*eventData);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent10(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUpdateFps of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_SetUpdateFps00
static int tolua_NetworkLuaAPI_Network_SetUpdateFps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  int fps = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUpdateFps'", NULL);
#endif
 {
  self->SetUpdateFps(fps);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUpdateFps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSimulatedLatency of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_SetSimulatedLatency00
static int tolua_NetworkLuaAPI_Network_SetSimulatedLatency00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  int ms = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSimulatedLatency'", NULL);
#endif
 {
  self->SetSimulatedLatency(ms);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSimulatedLatency'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSimulatedPacketLoss of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_SetSimulatedPacketLoss00
static int tolua_NetworkLuaAPI_Network_SetSimulatedPacketLoss00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  float loss = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSimulatedPacketLoss'", NULL);
#endif
 {
  self->SetSimulatedPacketLoss(loss);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSimulatedPacketLoss'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_RegisterRemoteEvent00
static int tolua_NetworkLuaAPI_Network_RegisterRemoteEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  StringHash eventType = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterRemoteEvent'", NULL);
#endif
 {
  self->RegisterRemoteEvent(eventType);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterRemoteEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_RegisterRemoteEvent01
static int tolua_NetworkLuaAPI_Network_RegisterRemoteEvent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  const String eventType = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterRemoteEvent'", NULL);
#endif
 {
  self->RegisterRemoteEvent(eventType);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Network_RegisterRemoteEvent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnregisterRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_UnregisterRemoteEvent00
static int tolua_NetworkLuaAPI_Network_UnregisterRemoteEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  StringHash eventType = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UnregisterRemoteEvent'", NULL);
#endif
 {
  self->UnregisterRemoteEvent(eventType);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnregisterRemoteEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnregisterRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_UnregisterRemoteEvent01
static int tolua_NetworkLuaAPI_Network_UnregisterRemoteEvent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  const String eventType = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UnregisterRemoteEvent'", NULL);
#endif
 {
  self->UnregisterRemoteEvent(eventType);
 }
 }
 return 0;
tolua_lerror:
 return tolua_NetworkLuaAPI_Network_UnregisterRemoteEvent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnregisterAllRemoteEvents of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_UnregisterAllRemoteEvents00
static int tolua_NetworkLuaAPI_Network_UnregisterAllRemoteEvents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UnregisterAllRemoteEvents'", NULL);
#endif
 {
  self->UnregisterAllRemoteEvents();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnregisterAllRemoteEvents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPackageCacheDir of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_SetPackageCacheDir00
static int tolua_NetworkLuaAPI_Network_SetPackageCacheDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  const String path = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPackageCacheDir'", NULL);
#endif
 {
  self->SetPackageCacheDir(path);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPackageCacheDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendPackageToClients of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_SendPackageToClients00
static int tolua_NetworkLuaAPI_Network_SendPackageToClients00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"PackageFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  PackageFile* package = ((PackageFile*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendPackageToClients'", NULL);
#endif
 {
  self->SendPackageToClients(scene,package);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SendPackageToClients'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NetworkMakeHttpRequest of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_MakeHttpRequest00
static int tolua_NetworkLuaAPI_Network_MakeHttpRequest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  const String url = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String verb = ((const String)  tolua_tourho3dstring(tolua_S,3,String::EMPTY));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NetworkMakeHttpRequest'", NULL);
#endif
 {
  tolua_outside HttpRequest* tolua_ret = (tolua_outside HttpRequest*)  NetworkMakeHttpRequest(self,url,verb);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"HttpRequest");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MakeHttpRequest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NetworkMakeHttpRequest of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_MakeHttpRequest01
static int tolua_NetworkLuaAPI_Network_MakeHttpRequest01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Network",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !ToluaIsVector<String>(tolua_S,4,"String",0,&tolua_err)) ||
 !tolua_isurho3dstring(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
  const String url = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String verb = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
  const Vector<String>* headers = ((const Vector<String>*)  ToluaToVector<String>(tolua_S,4,0));
  const String postData = ((const String)  tolua_tourho3dstring(tolua_S,5,String::EMPTY));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NetworkMakeHttpRequest'", NULL);
#endif
 {
  tolua_outside HttpRequest* tolua_ret = (tolua_outside HttpRequest*)  NetworkMakeHttpRequest(self,url,verb,*headers,postData);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"HttpRequest");
 }
 }
 return 1;
tolua_lerror:
 return tolua_NetworkLuaAPI_Network_MakeHttpRequest00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUpdateFps of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_GetUpdateFps00
static int tolua_NetworkLuaAPI_Network_GetUpdateFps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Network",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Network* self = (const Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUpdateFps'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetUpdateFps();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUpdateFps'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSimulatedLatency of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_GetSimulatedLatency00
static int tolua_NetworkLuaAPI_Network_GetSimulatedLatency00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Network",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Network* self = (const Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSimulatedLatency'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetSimulatedLatency();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSimulatedLatency'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSimulatedPacketLoss of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_GetSimulatedPacketLoss00
static int tolua_NetworkLuaAPI_Network_GetSimulatedPacketLoss00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Network",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Network* self = (const Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSimulatedPacketLoss'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetSimulatedPacketLoss();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSimulatedPacketLoss'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetServerConnection of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_GetServerConnection00
static int tolua_NetworkLuaAPI_Network_GetServerConnection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Network",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Network* self = (const Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetServerConnection'", NULL);
#endif
 {
  Connection* tolua_ret = (Connection*)  self->GetServerConnection();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Connection");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetServerConnection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsServerRunning of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_IsServerRunning00
static int tolua_NetworkLuaAPI_Network_IsServerRunning00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Network",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Network* self = (const Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsServerRunning'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsServerRunning();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsServerRunning'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CheckRemoteEvent of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_CheckRemoteEvent00
static int tolua_NetworkLuaAPI_Network_CheckRemoteEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Network",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Network* self = (const Network*)  tolua_tousertype(tolua_S,1,0);
  StringHash eventType = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CheckRemoteEvent'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->CheckRemoteEvent(eventType);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CheckRemoteEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPackageCacheDir of class  Network */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_Network_GetPackageCacheDir00
static int tolua_NetworkLuaAPI_Network_GetPackageCacheDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Network",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Network* self = (const Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPackageCacheDir'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetPackageCacheDir();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPackageCacheDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: updateFps of class  Network */
#ifndef TOLUA_DISABLE_tolua_get_Network_updateFps
static int tolua_get_Network_updateFps(lua_State* tolua_S)
{
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'updateFps'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetUpdateFps());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: updateFps of class  Network */
#ifndef TOLUA_DISABLE_tolua_set_Network_updateFps
static int tolua_set_Network_updateFps(lua_State* tolua_S)
{
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'updateFps'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUpdateFps(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: simulatedLatency of class  Network */
#ifndef TOLUA_DISABLE_tolua_get_Network_simulatedLatency
static int tolua_get_Network_simulatedLatency(lua_State* tolua_S)
{
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'simulatedLatency'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSimulatedLatency());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: simulatedLatency of class  Network */
#ifndef TOLUA_DISABLE_tolua_set_Network_simulatedLatency
static int tolua_set_Network_simulatedLatency(lua_State* tolua_S)
{
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'simulatedLatency'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSimulatedLatency(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: simulatedPacketLoss of class  Network */
#ifndef TOLUA_DISABLE_tolua_get_Network_simulatedPacketLoss
static int tolua_get_Network_simulatedPacketLoss(lua_State* tolua_S)
{
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'simulatedPacketLoss'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSimulatedPacketLoss());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: simulatedPacketLoss of class  Network */
#ifndef TOLUA_DISABLE_tolua_set_Network_simulatedPacketLoss
static int tolua_set_Network_simulatedPacketLoss(lua_State* tolua_S)
{
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'simulatedPacketLoss'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSimulatedPacketLoss(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: serverConnection of class  Network */
#ifndef TOLUA_DISABLE_tolua_get_Network_serverConnection_ptr
static int tolua_get_Network_serverConnection_ptr(lua_State* tolua_S)
{
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'serverConnection'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetServerConnection(),"Connection");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: serverRunning of class  Network */
#ifndef TOLUA_DISABLE_tolua_get_Network_serverRunning
static int tolua_get_Network_serverRunning(lua_State* tolua_S)
{
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'serverRunning'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsServerRunning());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: packageCacheDir of class  Network */
#ifndef TOLUA_DISABLE_tolua_get_Network_packageCacheDir
static int tolua_get_Network_packageCacheDir(lua_State* tolua_S)
{
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'packageCacheDir'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetPackageCacheDir());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: packageCacheDir of class  Network */
#ifndef TOLUA_DISABLE_tolua_set_Network_packageCacheDir
static int tolua_set_Network_packageCacheDir(lua_State* tolua_S)
{
  Network* self = (Network*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'packageCacheDir'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPackageCacheDir(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetNetwork */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_GetNetwork00
static int tolua_NetworkLuaAPI_GetNetwork00(lua_State* tolua_S)
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
  Network* tolua_ret = (Network*)  GetNetwork();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Network");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNetwork'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: network */
#ifndef TOLUA_DISABLE_tolua_get_network_ptr
static int tolua_get_network_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetNetwork(),"Network");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBasePriority of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_NetworkPriority_SetBasePriority00
static int tolua_NetworkLuaAPI_NetworkPriority_SetBasePriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NetworkPriority",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NetworkPriority* self = (NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
  float priority = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBasePriority'", NULL);
#endif
 {
  self->SetBasePriority(priority);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBasePriority'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDistanceFactor of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_NetworkPriority_SetDistanceFactor00
static int tolua_NetworkLuaAPI_NetworkPriority_SetDistanceFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NetworkPriority",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NetworkPriority* self = (NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
  float factor = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDistanceFactor'", NULL);
#endif
 {
  self->SetDistanceFactor(factor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDistanceFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMinPriority of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_NetworkPriority_SetMinPriority00
static int tolua_NetworkLuaAPI_NetworkPriority_SetMinPriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NetworkPriority",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NetworkPriority* self = (NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
  float priority = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMinPriority'", NULL);
#endif
 {
  self->SetMinPriority(priority);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMinPriority'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAlwaysUpdateOwner of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_NetworkPriority_SetAlwaysUpdateOwner00
static int tolua_NetworkLuaAPI_NetworkPriority_SetAlwaysUpdateOwner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NetworkPriority",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NetworkPriority* self = (NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAlwaysUpdateOwner'", NULL);
#endif
 {
  self->SetAlwaysUpdateOwner(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAlwaysUpdateOwner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBasePriority of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_NetworkPriority_GetBasePriority00
static int tolua_NetworkLuaAPI_NetworkPriority_GetBasePriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NetworkPriority",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NetworkPriority* self = (const NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBasePriority'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetBasePriority();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBasePriority'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDistanceFactor of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_NetworkPriority_GetDistanceFactor00
static int tolua_NetworkLuaAPI_NetworkPriority_GetDistanceFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NetworkPriority",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NetworkPriority* self = (const NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDistanceFactor'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDistanceFactor();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDistanceFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMinPriority of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_NetworkPriority_GetMinPriority00
static int tolua_NetworkLuaAPI_NetworkPriority_GetMinPriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NetworkPriority",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NetworkPriority* self = (const NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMinPriority'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMinPriority();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMinPriority'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAlwaysUpdateOwner of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_NetworkPriority_GetAlwaysUpdateOwner00
static int tolua_NetworkLuaAPI_NetworkPriority_GetAlwaysUpdateOwner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NetworkPriority",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NetworkPriority* self = (const NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAlwaysUpdateOwner'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetAlwaysUpdateOwner();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAlwaysUpdateOwner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CheckUpdate of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_NetworkLuaAPI_NetworkPriority_CheckUpdate00
static int tolua_NetworkLuaAPI_NetworkPriority_CheckUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NetworkPriority",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NetworkPriority* self = (NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
  float distance = ((float)  tolua_tonumber(tolua_S,2,0));
  float accumulator = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CheckUpdate'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->CheckUpdate(distance,accumulator);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 tolua_pushnumber(tolua_S,(lua_Number)accumulator);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CheckUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: basePriority of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_get_NetworkPriority_basePriority
static int tolua_get_NetworkPriority_basePriority(lua_State* tolua_S)
{
  NetworkPriority* self = (NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'basePriority'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetBasePriority());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: basePriority of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_set_NetworkPriority_basePriority
static int tolua_set_NetworkPriority_basePriority(lua_State* tolua_S)
{
  NetworkPriority* self = (NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'basePriority'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetBasePriority(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: distanceFactor of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_get_NetworkPriority_distanceFactor
static int tolua_get_NetworkPriority_distanceFactor(lua_State* tolua_S)
{
  NetworkPriority* self = (NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'distanceFactor'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDistanceFactor());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: distanceFactor of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_set_NetworkPriority_distanceFactor
static int tolua_set_NetworkPriority_distanceFactor(lua_State* tolua_S)
{
  NetworkPriority* self = (NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'distanceFactor'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDistanceFactor(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: minPriority of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_get_NetworkPriority_minPriority
static int tolua_get_NetworkPriority_minPriority(lua_State* tolua_S)
{
  NetworkPriority* self = (NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minPriority'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMinPriority());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: minPriority of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_set_NetworkPriority_minPriority
static int tolua_set_NetworkPriority_minPriority(lua_State* tolua_S)
{
  NetworkPriority* self = (NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minPriority'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMinPriority(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: alwaysUpdateOwner of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_get_NetworkPriority_alwaysUpdateOwner
static int tolua_get_NetworkPriority_alwaysUpdateOwner(lua_State* tolua_S)
{
  NetworkPriority* self = (NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'alwaysUpdateOwner'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetAlwaysUpdateOwner());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: alwaysUpdateOwner of class  NetworkPriority */
#ifndef TOLUA_DISABLE_tolua_set_NetworkPriority_alwaysUpdateOwner
static int tolua_set_NetworkPriority_alwaysUpdateOwner(lua_State* tolua_S)
{
  NetworkPriority* self = (NetworkPriority*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'alwaysUpdateOwner'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAlwaysUpdateOwner(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_NetworkLuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"RemoteEvent","RemoteEvent","",NULL);
 tolua_beginmodule(tolua_S,"RemoteEvent");
  tolua_variable(tolua_S,"senderID",tolua_get_RemoteEvent_senderID,tolua_set_RemoteEvent_senderID);
  tolua_variable(tolua_S,"eventType",tolua_get_RemoteEvent_eventType,tolua_set_RemoteEvent_eventType);
  tolua_variable(tolua_S,"eventData",tolua_get_RemoteEvent_eventData,tolua_set_RemoteEvent_eventData);
  tolua_variable(tolua_S,"inOrder",tolua_get_RemoteEvent_inOrder,tolua_set_RemoteEvent_inOrder);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Connection","Connection","Object",NULL);
 tolua_beginmodule(tolua_S,"Connection");
  tolua_function(tolua_S,"SendMessage",tolua_NetworkLuaAPI_Connection_SendMessage00);
  tolua_function(tolua_S,"SendRemoteEvent",tolua_NetworkLuaAPI_Connection_SendRemoteEvent00);
  tolua_function(tolua_S,"SendRemoteEvent",tolua_NetworkLuaAPI_Connection_SendRemoteEvent01);
  tolua_function(tolua_S,"SendRemoteEvent",tolua_NetworkLuaAPI_Connection_SendRemoteEvent02);
  tolua_function(tolua_S,"SendRemoteEvent",tolua_NetworkLuaAPI_Connection_SendRemoteEvent03);
  tolua_function(tolua_S,"SendRemoteEvent",tolua_NetworkLuaAPI_Connection_SendRemoteEvent04);
  tolua_function(tolua_S,"SendRemoteEvent",tolua_NetworkLuaAPI_Connection_SendRemoteEvent05);
  tolua_function(tolua_S,"SendRemoteEvent",tolua_NetworkLuaAPI_Connection_SendRemoteEvent06);
  tolua_function(tolua_S,"SendRemoteEvent",tolua_NetworkLuaAPI_Connection_SendRemoteEvent07);
  tolua_function(tolua_S,"SetScene",tolua_NetworkLuaAPI_Connection_SetScene00);
  tolua_function(tolua_S,"SetIdentity",tolua_NetworkLuaAPI_Connection_SetIdentity00);
  tolua_function(tolua_S,"SetControls",tolua_NetworkLuaAPI_Connection_SetControls00);
  tolua_function(tolua_S,"SetPosition",tolua_NetworkLuaAPI_Connection_SetPosition00);
  tolua_function(tolua_S,"SetRotation",tolua_NetworkLuaAPI_Connection_SetRotation00);
  tolua_function(tolua_S,"SetConnectPending",tolua_NetworkLuaAPI_Connection_SetConnectPending00);
  tolua_function(tolua_S,"SetLogStatistics",tolua_NetworkLuaAPI_Connection_SetLogStatistics00);
  tolua_function(tolua_S,"Disconnect",tolua_NetworkLuaAPI_Connection_Disconnect00);
  tolua_function(tolua_S,"SendPackageToClient",tolua_NetworkLuaAPI_Connection_SendPackageToClient00);
  tolua_function(tolua_S,"GetIdentity",tolua_NetworkLuaAPI_Connection_GetIdentity00);
  tolua_function(tolua_S,"GetScene",tolua_NetworkLuaAPI_Connection_GetScene00);
  tolua_function(tolua_S,"GetControls",tolua_NetworkLuaAPI_Connection_GetControls00);
  tolua_function(tolua_S,"GetTimeStamp",tolua_NetworkLuaAPI_Connection_GetTimeStamp00);
  tolua_function(tolua_S,"GetPosition",tolua_NetworkLuaAPI_Connection_GetPosition00);
  tolua_function(tolua_S,"GetRotation",tolua_NetworkLuaAPI_Connection_GetRotation00);
  tolua_function(tolua_S,"IsClient",tolua_NetworkLuaAPI_Connection_IsClient00);
  tolua_function(tolua_S,"IsConnected",tolua_NetworkLuaAPI_Connection_IsConnected00);
  tolua_function(tolua_S,"IsConnectPending",tolua_NetworkLuaAPI_Connection_IsConnectPending00);
  tolua_function(tolua_S,"IsSceneLoaded",tolua_NetworkLuaAPI_Connection_IsSceneLoaded00);
  tolua_function(tolua_S,"GetLogStatistics",tolua_NetworkLuaAPI_Connection_GetLogStatistics00);
  tolua_function(tolua_S,"GetAddress",tolua_NetworkLuaAPI_Connection_GetAddress00);
  tolua_function(tolua_S,"GetPort",tolua_NetworkLuaAPI_Connection_GetPort00);
  tolua_function(tolua_S,"GetRoundTripTime",tolua_NetworkLuaAPI_Connection_GetRoundTripTime00);
  tolua_function(tolua_S,"GetLastHeardTime",tolua_NetworkLuaAPI_Connection_GetLastHeardTime00);
  tolua_function(tolua_S,"GetBytesInPerSec",tolua_NetworkLuaAPI_Connection_GetBytesInPerSec00);
  tolua_function(tolua_S,"GetBytesOutPerSec",tolua_NetworkLuaAPI_Connection_GetBytesOutPerSec00);
  tolua_function(tolua_S,"GetPacketsInPerSec",tolua_NetworkLuaAPI_Connection_GetPacketsInPerSec00);
  tolua_function(tolua_S,"GetPacketsOutPerSec",tolua_NetworkLuaAPI_Connection_GetPacketsOutPerSec00);
  tolua_function(tolua_S,"ToString",tolua_NetworkLuaAPI_Connection_ToString00);
  tolua_function(tolua_S,"GetNumDownloads",tolua_NetworkLuaAPI_Connection_GetNumDownloads00);
  tolua_function(tolua_S,"GetDownloadName",tolua_NetworkLuaAPI_Connection_GetDownloadName00);
  tolua_function(tolua_S,"GetDownloadProgress",tolua_NetworkLuaAPI_Connection_GetDownloadProgress00);
  tolua_variable(tolua_S,"identity",tolua_get_Connection_identity_ref,tolua_set_Connection_identity_ref);
  tolua_variable(tolua_S,"scene",tolua_get_Connection_scene_ptr,tolua_set_Connection_scene_ptr);
  tolua_variable(tolua_S,"controls",tolua_get_Connection_controls_ref,tolua_set_Connection_controls_ref);
  tolua_variable(tolua_S,"timeStamp",tolua_get_Connection_unsigned_timeStamp,NULL);
  tolua_variable(tolua_S,"position",tolua_get_Connection_position_ref,tolua_set_Connection_position_ref);
  tolua_variable(tolua_S,"rotation",tolua_get_Connection_rotation_ref,tolua_set_Connection_rotation_ref);
  tolua_variable(tolua_S,"client",tolua_get_Connection_client,NULL);
  tolua_variable(tolua_S,"connected",tolua_get_Connection_connected,NULL);
  tolua_variable(tolua_S,"connectPending",tolua_get_Connection_connectPending,tolua_set_Connection_connectPending);
  tolua_variable(tolua_S,"sceneLoaded",tolua_get_Connection_sceneLoaded,NULL);
  tolua_variable(tolua_S,"logStatistics",tolua_get_Connection_logStatistics,tolua_set_Connection_logStatistics);
  tolua_variable(tolua_S,"address",tolua_get_Connection_address,NULL);
  tolua_variable(tolua_S,"port",tolua_get_Connection_unsigned_port,NULL);
  tolua_variable(tolua_S,"roundTripTime",tolua_get_Connection_roundTripTime,NULL);
  tolua_variable(tolua_S,"lastHeardTime",tolua_get_Connection_lastHeardTime,NULL);
  tolua_variable(tolua_S,"bytesInPerSec",tolua_get_Connection_bytesInPerSec,NULL);
  tolua_variable(tolua_S,"bytesOutPerSec",tolua_get_Connection_bytesOutPerSec,NULL);
  tolua_variable(tolua_S,"packetsInPerSec",tolua_get_Connection_packetsInPerSec,NULL);
  tolua_variable(tolua_S,"packetsOutPerSec",tolua_get_Connection_packetsOutPerSec,NULL);
  tolua_variable(tolua_S,"numDownloads",tolua_get_Connection_numDownloads,NULL);
  tolua_variable(tolua_S,"downloadName",tolua_get_Connection_downloadName,NULL);
  tolua_variable(tolua_S,"downloadProgress",tolua_get_Connection_downloadProgress,NULL);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"HTTP_INITIALIZING",HTTP_INITIALIZING);
 tolua_constant(tolua_S,"HTTP_ERROR",HTTP_ERROR);
 tolua_constant(tolua_S,"HTTP_OPEN",HTTP_OPEN);
 tolua_constant(tolua_S,"HTTP_CLOSED",HTTP_CLOSED);
 tolua_cclass(tolua_S,"HttpRequest","HttpRequest","",NULL);
 tolua_beginmodule(tolua_S,"HttpRequest");
  tolua_function(tolua_S,"GetURL",tolua_NetworkLuaAPI_HttpRequest_GetURL00);
  tolua_function(tolua_S,"GetVerb",tolua_NetworkLuaAPI_HttpRequest_GetVerb00);
  tolua_function(tolua_S,"GetError",tolua_NetworkLuaAPI_HttpRequest_GetError00);
  tolua_function(tolua_S,"GetState",tolua_NetworkLuaAPI_HttpRequest_GetState00);
  tolua_function(tolua_S,"GetAvailableSize",tolua_NetworkLuaAPI_HttpRequest_GetAvailableSize00);
  tolua_function(tolua_S,"IsOpen",tolua_NetworkLuaAPI_HttpRequest_IsOpen00);
  tolua_function(tolua_S,"Read",tolua_NetworkLuaAPI_HttpRequest_Read00);
  tolua_function(tolua_S,"IsEof",tolua_NetworkLuaAPI_HttpRequest_IsEof00);
  tolua_function(tolua_S,"ReadInt",tolua_NetworkLuaAPI_HttpRequest_ReadInt00);
  tolua_function(tolua_S,"ReadShort",tolua_NetworkLuaAPI_HttpRequest_ReadShort00);
  tolua_function(tolua_S,"ReadByte",tolua_NetworkLuaAPI_HttpRequest_ReadByte00);
  tolua_function(tolua_S,"ReadUInt",tolua_NetworkLuaAPI_HttpRequest_ReadUInt00);
  tolua_function(tolua_S,"ReadUShort",tolua_NetworkLuaAPI_HttpRequest_ReadUShort00);
  tolua_function(tolua_S,"ReadUByte",tolua_NetworkLuaAPI_HttpRequest_ReadUByte00);
  tolua_function(tolua_S,"ReadBool",tolua_NetworkLuaAPI_HttpRequest_ReadBool00);
  tolua_function(tolua_S,"ReadFloat",tolua_NetworkLuaAPI_HttpRequest_ReadFloat00);
  tolua_function(tolua_S,"ReadDouble",tolua_NetworkLuaAPI_HttpRequest_ReadDouble00);
  tolua_function(tolua_S,"ReadIntRect",tolua_NetworkLuaAPI_HttpRequest_ReadIntRect00);
  tolua_function(tolua_S,"ReadIntVector2",tolua_NetworkLuaAPI_HttpRequest_ReadIntVector200);
  tolua_function(tolua_S,"ReadIntVector3",tolua_NetworkLuaAPI_HttpRequest_ReadIntVector300);
  tolua_function(tolua_S,"ReadRect",tolua_NetworkLuaAPI_HttpRequest_ReadRect00);
  tolua_function(tolua_S,"ReadVector2",tolua_NetworkLuaAPI_HttpRequest_ReadVector200);
  tolua_function(tolua_S,"ReadVector3",tolua_NetworkLuaAPI_HttpRequest_ReadVector300);
  tolua_function(tolua_S,"ReadPackedVector3",tolua_NetworkLuaAPI_HttpRequest_ReadPackedVector300);
  tolua_function(tolua_S,"ReadVector4",tolua_NetworkLuaAPI_HttpRequest_ReadVector400);
  tolua_function(tolua_S,"ReadQuaternion",tolua_NetworkLuaAPI_HttpRequest_ReadQuaternion00);
  tolua_function(tolua_S,"ReadPackedQuaternion",tolua_NetworkLuaAPI_HttpRequest_ReadPackedQuaternion00);
  tolua_function(tolua_S,"ReadMatrix3",tolua_NetworkLuaAPI_HttpRequest_ReadMatrix300);
  tolua_function(tolua_S,"ReadMatrix3x4",tolua_NetworkLuaAPI_HttpRequest_ReadMatrix3x400);
  tolua_function(tolua_S,"ReadMatrix4",tolua_NetworkLuaAPI_HttpRequest_ReadMatrix400);
  tolua_function(tolua_S,"ReadColor",tolua_NetworkLuaAPI_HttpRequest_ReadColor00);
  tolua_function(tolua_S,"ReadBoundingBox",tolua_NetworkLuaAPI_HttpRequest_ReadBoundingBox00);
  tolua_function(tolua_S,"ReadString",tolua_NetworkLuaAPI_HttpRequest_ReadString00);
  tolua_function(tolua_S,"ReadFileID",tolua_NetworkLuaAPI_HttpRequest_ReadFileID00);
  tolua_function(tolua_S,"ReadStringHash",tolua_NetworkLuaAPI_HttpRequest_ReadStringHash00);
  tolua_function(tolua_S,"ReadBuffer",tolua_NetworkLuaAPI_HttpRequest_ReadBuffer00);
  tolua_function(tolua_S,"ReadResourceRef",tolua_NetworkLuaAPI_HttpRequest_ReadResourceRef00);
  tolua_function(tolua_S,"ReadResourceRefList",tolua_NetworkLuaAPI_HttpRequest_ReadResourceRefList00);
  tolua_function(tolua_S,"ReadVariant",tolua_NetworkLuaAPI_HttpRequest_ReadVariant00);
  tolua_function(tolua_S,"ReadVariant",tolua_NetworkLuaAPI_HttpRequest_ReadVariant01);
  tolua_function(tolua_S,"ReadVariantVector",tolua_NetworkLuaAPI_HttpRequest_ReadVariantVector00);
  tolua_function(tolua_S,"ReadVariantMap",tolua_NetworkLuaAPI_HttpRequest_ReadVariantMap00);
  tolua_function(tolua_S,"ReadVLE",tolua_NetworkLuaAPI_HttpRequest_ReadVLE00);
  tolua_function(tolua_S,"ReadNetID",tolua_NetworkLuaAPI_HttpRequest_ReadNetID00);
  tolua_function(tolua_S,"ReadLine",tolua_NetworkLuaAPI_HttpRequest_ReadLine00);
  tolua_variable(tolua_S,"URL",tolua_get_HttpRequest_URL,NULL);
  tolua_variable(tolua_S,"verb",tolua_get_HttpRequest_verb,NULL);
  tolua_variable(tolua_S,"error",tolua_get_HttpRequest_error,NULL);
  tolua_variable(tolua_S,"state",tolua_get_HttpRequest_state,NULL);
  tolua_variable(tolua_S,"availableSize",tolua_get_HttpRequest_availableSize,NULL);
  tolua_variable(tolua_S,"open",tolua_get_HttpRequest_open,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Network","Network","",NULL);
 tolua_beginmodule(tolua_S,"Network");
  tolua_function(tolua_S,"Connect",tolua_NetworkLuaAPI_Network_Connect00);
  tolua_function(tolua_S,"Connect",tolua_NetworkLuaAPI_Network_Connect01);
  tolua_function(tolua_S,"Disconnect",tolua_NetworkLuaAPI_Network_Disconnect00);
  tolua_function(tolua_S,"StartServer",tolua_NetworkLuaAPI_Network_StartServer00);
  tolua_function(tolua_S,"StopServer",tolua_NetworkLuaAPI_Network_StopServer00);
  tolua_function(tolua_S,"BroadcastMessage",tolua_NetworkLuaAPI_Network_BroadcastMessage00);
  tolua_function(tolua_S,"BroadcastRemoteEvent",tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent00);
  tolua_function(tolua_S,"BroadcastRemoteEvent",tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent01);
  tolua_function(tolua_S,"BroadcastRemoteEvent",tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent02);
  tolua_function(tolua_S,"BroadcastRemoteEvent",tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent03);
  tolua_function(tolua_S,"BroadcastRemoteEvent",tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent04);
  tolua_function(tolua_S,"BroadcastRemoteEvent",tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent05);
  tolua_function(tolua_S,"BroadcastRemoteEvent",tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent06);
  tolua_function(tolua_S,"BroadcastRemoteEvent",tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent07);
  tolua_function(tolua_S,"BroadcastRemoteEvent",tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent08);
  tolua_function(tolua_S,"BroadcastRemoteEvent",tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent09);
  tolua_function(tolua_S,"BroadcastRemoteEvent",tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent10);
  tolua_function(tolua_S,"BroadcastRemoteEvent",tolua_NetworkLuaAPI_Network_BroadcastRemoteEvent11);
  tolua_function(tolua_S,"SetUpdateFps",tolua_NetworkLuaAPI_Network_SetUpdateFps00);
  tolua_function(tolua_S,"SetSimulatedLatency",tolua_NetworkLuaAPI_Network_SetSimulatedLatency00);
  tolua_function(tolua_S,"SetSimulatedPacketLoss",tolua_NetworkLuaAPI_Network_SetSimulatedPacketLoss00);
  tolua_function(tolua_S,"RegisterRemoteEvent",tolua_NetworkLuaAPI_Network_RegisterRemoteEvent00);
  tolua_function(tolua_S,"RegisterRemoteEvent",tolua_NetworkLuaAPI_Network_RegisterRemoteEvent01);
  tolua_function(tolua_S,"UnregisterRemoteEvent",tolua_NetworkLuaAPI_Network_UnregisterRemoteEvent00);
  tolua_function(tolua_S,"UnregisterRemoteEvent",tolua_NetworkLuaAPI_Network_UnregisterRemoteEvent01);
  tolua_function(tolua_S,"UnregisterAllRemoteEvents",tolua_NetworkLuaAPI_Network_UnregisterAllRemoteEvents00);
  tolua_function(tolua_S,"SetPackageCacheDir",tolua_NetworkLuaAPI_Network_SetPackageCacheDir00);
  tolua_function(tolua_S,"SendPackageToClients",tolua_NetworkLuaAPI_Network_SendPackageToClients00);
  tolua_function(tolua_S,"MakeHttpRequest",tolua_NetworkLuaAPI_Network_MakeHttpRequest00);
  tolua_function(tolua_S,"MakeHttpRequest",tolua_NetworkLuaAPI_Network_MakeHttpRequest01);
  tolua_function(tolua_S,"GetUpdateFps",tolua_NetworkLuaAPI_Network_GetUpdateFps00);
  tolua_function(tolua_S,"GetSimulatedLatency",tolua_NetworkLuaAPI_Network_GetSimulatedLatency00);
  tolua_function(tolua_S,"GetSimulatedPacketLoss",tolua_NetworkLuaAPI_Network_GetSimulatedPacketLoss00);
  tolua_function(tolua_S,"GetServerConnection",tolua_NetworkLuaAPI_Network_GetServerConnection00);
  tolua_function(tolua_S,"IsServerRunning",tolua_NetworkLuaAPI_Network_IsServerRunning00);
  tolua_function(tolua_S,"CheckRemoteEvent",tolua_NetworkLuaAPI_Network_CheckRemoteEvent00);
  tolua_function(tolua_S,"GetPackageCacheDir",tolua_NetworkLuaAPI_Network_GetPackageCacheDir00);
  tolua_variable(tolua_S,"updateFps",tolua_get_Network_updateFps,tolua_set_Network_updateFps);
  tolua_variable(tolua_S,"simulatedLatency",tolua_get_Network_simulatedLatency,tolua_set_Network_simulatedLatency);
  tolua_variable(tolua_S,"simulatedPacketLoss",tolua_get_Network_simulatedPacketLoss,tolua_set_Network_simulatedPacketLoss);
  tolua_variable(tolua_S,"serverConnection",tolua_get_Network_serverConnection_ptr,NULL);
  tolua_variable(tolua_S,"serverRunning",tolua_get_Network_serverRunning,NULL);
  tolua_variable(tolua_S,"packageCacheDir",tolua_get_Network_packageCacheDir,tolua_set_Network_packageCacheDir);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"GetNetwork",tolua_NetworkLuaAPI_GetNetwork00);
 tolua_variable(tolua_S,"network",tolua_get_network_ptr,NULL);
 tolua_cclass(tolua_S,"NetworkPriority","NetworkPriority","Component",NULL);
 tolua_beginmodule(tolua_S,"NetworkPriority");
  tolua_function(tolua_S,"SetBasePriority",tolua_NetworkLuaAPI_NetworkPriority_SetBasePriority00);
  tolua_function(tolua_S,"SetDistanceFactor",tolua_NetworkLuaAPI_NetworkPriority_SetDistanceFactor00);
  tolua_function(tolua_S,"SetMinPriority",tolua_NetworkLuaAPI_NetworkPriority_SetMinPriority00);
  tolua_function(tolua_S,"SetAlwaysUpdateOwner",tolua_NetworkLuaAPI_NetworkPriority_SetAlwaysUpdateOwner00);
  tolua_function(tolua_S,"GetBasePriority",tolua_NetworkLuaAPI_NetworkPriority_GetBasePriority00);
  tolua_function(tolua_S,"GetDistanceFactor",tolua_NetworkLuaAPI_NetworkPriority_GetDistanceFactor00);
  tolua_function(tolua_S,"GetMinPriority",tolua_NetworkLuaAPI_NetworkPriority_GetMinPriority00);
  tolua_function(tolua_S,"GetAlwaysUpdateOwner",tolua_NetworkLuaAPI_NetworkPriority_GetAlwaysUpdateOwner00);
  tolua_function(tolua_S,"CheckUpdate",tolua_NetworkLuaAPI_NetworkPriority_CheckUpdate00);
  tolua_variable(tolua_S,"basePriority",tolua_get_NetworkPriority_basePriority,tolua_set_NetworkPriority_basePriority);
  tolua_variable(tolua_S,"distanceFactor",tolua_get_NetworkPriority_distanceFactor,tolua_set_NetworkPriority_distanceFactor);
  tolua_variable(tolua_S,"minPriority",tolua_get_NetworkPriority_minPriority,tolua_set_NetworkPriority_minPriority);
  tolua_variable(tolua_S,"alwaysUpdateOwner",tolua_get_NetworkPriority_alwaysUpdateOwner,tolua_set_NetworkPriority_alwaysUpdateOwner);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_NetworkLuaAPI (lua_State* tolua_S) {
 return tolua_NetworkLuaAPI_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif