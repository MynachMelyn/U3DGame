/*
** Lua binding: ResourceLuaAPI
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
TOLUA_API int tolua_ResourceLuaAPI_open (lua_State* tolua_S);

#include "Resource/Resource.h"
#include "Resource/Image.h"
#include "Resource/JSONValue.h"
#include "Resource/JSONFile.h"
#include "Resource/XMLElement.h"
#include "Resource/XMLFile.h"
#include "Resource/ResourceCache.h"
#include "Resource/Localization.h"
using namespace Urho3D;
#pragma warning(disable:4800)

static bool ResourceLoad(Resource* resource, const String& fileName)
{
    return resource->LoadFile(fileName);
}

static bool ResourceSave(const Resource* resource, const String& fileName)
{
    return resource->SaveFile(fileName);
}

#define TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_new00
static int tolua_ResourceLuaAPI_Image_new00(lua_State* tolua_S)
{
    return ToluaNewObject<Image>(tolua_S);
}

#define TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_new00_local
static int tolua_ResourceLuaAPI_Image_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<Image>(tolua_S);
}

static bool ImageLoadColorLUT(Image* image, const String& fileName)
{
    if (!image)
        return false;

    File file(image->GetContext());
    if (!file.Open(fileName, FILE_READ))
        return false;

    return image->LoadColorLUT(file);
}

static void JSONValueSetBool(JSONValue* jsonValue, bool value)
{
    (*jsonValue) = value;
}

static void JSONValueSetInt(JSONValue* jsonValue, int value)
{
    (*jsonValue) = value;
}

static void JSONValueSetUint(JSONValue* jsonValue, unsigned value)
{
    (*jsonValue) = value;
}

static void JSONValueSetFloat(JSONValue* jsonValue, float value)
{
    (*jsonValue) = value;
}

static void JSONValueSetDouble(JSONValue* jsonValue, double value)
{
    (*jsonValue) = value;
}

static void JSONValueSetString(JSONValue* jsonValue, const String& value)
{
    (*jsonValue) = value;
}

static void JSONValueSetArray(JSONValue* jsonValue, const JSONArray& value)
{
    (*jsonValue) = value;
}

static void JSONValueSetObject(JSONValue* jsonValue, const JSONObject& value)
{
    (*jsonValue) = value;
}

#define TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_SetVariant00
static int tolua_ResourceLuaAPI_JSONValue_SetVariant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVariant'", NULL);
#endif
 {
  self->SetVariant(*value, GetContext(tolua_S));
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVariant'.",&tolua_err);
 return 0;
#endif
}

#define TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_SetVariantMap00
static int tolua_ResourceLuaAPI_JSONValue_SetVariantMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  const VariantMap* value = ((const VariantMap*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVariantMap'", NULL);
#endif
 {
  self->SetVariantMap(*value, GetContext(tolua_S));
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVariantMap'.",&tolua_err);
 return 0;
#endif
}

#define TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONFile_new00
static int tolua_ResourceLuaAPI_JSONFile_new00(lua_State* tolua_S)
{
    return ToluaNewObject<JSONFile>(tolua_S);
}

#define TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONFile_new00_local
static int tolua_ResourceLuaAPI_JSONFile_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<JSONFile>(tolua_S);
}

static bool JSONFileSave(const JSONFile* resource, const String& fileName, const String& indentation)
{
    if (!resource)
        return false;

    File file(resource->GetContext());
    return file.Open(fileName, FILE_WRITE) && resource->Save(file, indentation);
}

#define TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLFile_new00
static int tolua_ResourceLuaAPI_XMLFile_new00(lua_State* tolua_S)
{
    return ToluaNewObject<XMLFile>(tolua_S);
}

#define TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLFile_new00_local
static int tolua_ResourceLuaAPI_XMLFile_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<XMLFile>(tolua_S);
}

static bool XMLFileSave(const XMLFile* resource, const String& fileName, const String& indentation)
{
    if (!resource)
        return false;

    File file(resource->GetContext());
    return file.Open(fileName, FILE_WRITE) && resource->Save(file, indentation);
}

#define TOLUA_DISABLE_tolua_ResourceLuaAPI_GetCache00
static int tolua_ResourceLuaAPI_GetCache00(lua_State* tolua_S)
{
    return ToluaGetSubsystem<ResourceCache>(tolua_S);
}

#define TOLUA_DISABLE_tolua_get_cache_ptr
#define tolua_get_cache_ptr tolua_ResourceLuaAPI_GetCache00

static File* ResourceCacheGetFile(ResourceCache* cache, const String& fileName)
{
    return cache->GetFile(fileName).Detach();
}

static bool ResourceCacheBackgroundLoadResource(ResourceCache* cache, StringHash type, const String& fileName, bool sendEventOnFailure)
{
    return cache->BackgroundLoadResource(type, fileName, sendEventOnFailure);
}


#define TOLUA_DISABLE_tolua_ResourceLuaAPI_GetLocalization00
static int tolua_ResourceLuaAPI_GetLocalization00(lua_State* tolua_S)
{
    return ToluaGetSubsystem<Localization>(tolua_S);
}

#define TOLUA_DISABLE_tolua_get_localization_ptr
#define tolua_get_localization_ptr tolua_ResourceLuaAPI_GetLocalization00

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_VariantMap (lua_State* tolua_S)
{
 VariantMap* self = (VariantMap*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Quaternion (lua_State* tolua_S)
{
 Quaternion* self = (Quaternion*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Color (lua_State* tolua_S)
{
 Color* self = (Color*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Vector_String_ (lua_State* tolua_S)
{
 Vector<String>* self = (Vector<String>*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Image (lua_State* tolua_S)
{
 Image* self = (Image*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Variant (lua_State* tolua_S)
{
 Variant* self = (Variant*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_XMLFile (lua_State* tolua_S)
{
 XMLFile* self = (XMLFile*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_BoundingBox (lua_State* tolua_S)
{
 BoundingBox* self = (BoundingBox*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_IntVector2 (lua_State* tolua_S)
{
 IntVector2* self = (IntVector2*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Matrix3x4 (lua_State* tolua_S)
{
 Matrix3x4* self = (Matrix3x4*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_IntRect (lua_State* tolua_S)
{
 IntRect* self = (IntRect*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Vector3 (lua_State* tolua_S)
{
 Vector3* self = (Vector3*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Vector4 (lua_State* tolua_S)
{
 Vector4* self = (Vector4*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Matrix3 (lua_State* tolua_S)
{
 Matrix3* self = (Matrix3*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_JSONValue (lua_State* tolua_S)
{
 JSONValue* self = (JSONValue*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_IntVector3 (lua_State* tolua_S)
{
 IntVector3* self = (IntVector3*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_JSONFile (lua_State* tolua_S)
{
 JSONFile* self = (JSONFile*) tolua_tousertype(tolua_S,1,0);
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

static int tolua_collect_ResourceRef (lua_State* tolua_S)
{
 ResourceRef* self = (ResourceRef*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_StringHash (lua_State* tolua_S)
{
 StringHash* self = (StringHash*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Matrix4 (lua_State* tolua_S)
{
 Matrix4* self = (Matrix4*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_XMLElement (lua_State* tolua_S)
{
 XMLElement* self = (XMLElement*) tolua_tousertype(tolua_S,1,0);
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
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"VariantType");
 tolua_usertype(tolua_S,"IntRect");
 tolua_usertype(tolua_S,"JSONArray");
 tolua_usertype(tolua_S,"Matrix3");
 tolua_usertype(tolua_S,"JSONValue");
 tolua_usertype(tolua_S,"IntVector3");
 tolua_usertype(tolua_S,"JSONFile");
 tolua_usertype(tolua_S,"ResourceRefList");
 tolua_usertype(tolua_S,"Matrix4");
 tolua_usertype(tolua_S,"IntVector2");
 tolua_usertype(tolua_S,"XMLFile");
 tolua_usertype(tolua_S,"Serializer");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"Image");
 tolua_usertype(tolua_S,"ResourceWithMetadata");
 tolua_usertype(tolua_S,"Deserializer");
 tolua_usertype(tolua_S,"JSONObject");
 tolua_usertype(tolua_S,"BoundingBox");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"Vector4");
 tolua_usertype(tolua_S,"ResourceRef");
 tolua_usertype(tolua_S,"Quaternion");
 tolua_usertype(tolua_S,"Resource");
 tolua_usertype(tolua_S,"Rect");
 tolua_usertype(tolua_S,"ResourceCache");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"Localization");
 tolua_usertype(tolua_S,"File");
 tolua_usertype(tolua_S,"StringHash");
 tolua_usertype(tolua_S,"XMLElement");
}

/* method: Load of class  Resource */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Resource_Load00
static int tolua_ResourceLuaAPI_Resource_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Resource",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Deserializer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Resource* self = (Resource*)  tolua_tousertype(tolua_S,1,0);
  Deserializer* source = ((Deserializer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Load'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Load(*source);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Save of class  Resource */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Resource_Save00
static int tolua_ResourceLuaAPI_Resource_Save00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Resource",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Serializer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Resource* self = (const Resource*)  tolua_tousertype(tolua_S,1,0);
  Serializer* dest = ((Serializer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Save'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Save(*dest);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Save'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResourceLoad of class  Resource */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Resource_Load01
static int tolua_ResourceLuaAPI_Resource_Load01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Resource",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Resource* self = (Resource*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResourceLoad'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  ResourceLoad(self,fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 tolua_pushurho3dstring(tolua_S,(const char*)fileName);
 }
 }
 return 2;
tolua_lerror:
 return tolua_ResourceLuaAPI_Resource_Load00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResourceSave of class  Resource */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Resource_Save01
static int tolua_ResourceLuaAPI_Resource_Save01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Resource",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Resource* self = (const Resource*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResourceSave'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  ResourceSave(self,fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 tolua_pushurho3dstring(tolua_S,(const char*)fileName);
 }
 }
 return 2;
tolua_lerror:
 return tolua_ResourceLuaAPI_Resource_Save00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  Resource */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Resource_GetName00
static int tolua_ResourceLuaAPI_Resource_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Resource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Resource* self = (const Resource*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetNameHash of class  Resource */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Resource_GetNameHash00
static int tolua_ResourceLuaAPI_Resource_GetNameHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Resource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Resource* self = (const Resource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNameHash'", NULL);
#endif
 {
  StringHash tolua_ret = (StringHash)  self->GetNameHash();
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
 tolua_error(tolua_S,"#ferror in function 'GetNameHash'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMemoryUse of class  Resource */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Resource_GetMemoryUse00
static int tolua_ResourceLuaAPI_Resource_GetMemoryUse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Resource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Resource* self = (const Resource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMemoryUse'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetMemoryUse();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMemoryUse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  Resource */
#ifndef TOLUA_DISABLE_tolua_get_Resource_name
static int tolua_get_Resource_name(lua_State* tolua_S)
{
  Resource* self = (Resource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nameHash of class  Resource */
#ifndef TOLUA_DISABLE_tolua_get_Resource_nameHash
static int tolua_get_Resource_nameHash(lua_State* tolua_S)
{
  Resource* self = (Resource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nameHash'",NULL);
#endif
 StringHash tolua_ret = (StringHash)self->GetNameHash();
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

/* get function: memoryUse of class  Resource */
#ifndef TOLUA_DISABLE_tolua_get_Resource_memoryUse
static int tolua_get_Resource_memoryUse(lua_State* tolua_S)
{
  Resource* self = (Resource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'memoryUse'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMemoryUse());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddMetadata of class  ResourceWithMetadata */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceWithMetadata_AddMetadata00
static int tolua_ResourceLuaAPI_ResourceWithMetadata_AddMetadata00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceWithMetadata",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceWithMetadata* self = (ResourceWithMetadata*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddMetadata'", NULL);
#endif
 {
  self->AddMetadata(name,*value);
 tolua_pushurho3dstring(tolua_S,(const char*)name);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddMetadata'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveMetadata of class  ResourceWithMetadata */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceWithMetadata_RemoveMetadata00
static int tolua_ResourceLuaAPI_ResourceWithMetadata_RemoveMetadata00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceWithMetadata",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceWithMetadata* self = (ResourceWithMetadata*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveMetadata'", NULL);
#endif
 {
  self->RemoveMetadata(name);
 tolua_pushurho3dstring(tolua_S,(const char*)name);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveMetadata'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllMetadata of class  ResourceWithMetadata */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceWithMetadata_RemoveAllMetadata00
static int tolua_ResourceLuaAPI_ResourceWithMetadata_RemoveAllMetadata00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceWithMetadata",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceWithMetadata* self = (ResourceWithMetadata*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllMetadata'", NULL);
#endif
 {
  self->RemoveAllMetadata();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllMetadata'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMetadata of class  ResourceWithMetadata */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceWithMetadata_GetMetadata00
static int tolua_ResourceLuaAPI_ResourceWithMetadata_GetMetadata00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceWithMetadata",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceWithMetadata* self = (const ResourceWithMetadata*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMetadata'", NULL);
#endif
 {
  const Variant& tolua_ret = (const Variant&)  self->GetMetadata(name);
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Variant");
 tolua_pushurho3dstring(tolua_S,(const char*)name);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMetadata'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasMetadata of class  ResourceWithMetadata */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceWithMetadata_HasMetadata00
static int tolua_ResourceLuaAPI_ResourceWithMetadata_HasMetadata00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceWithMetadata",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceWithMetadata* self = (const ResourceWithMetadata*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasMetadata'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasMetadata();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasMetadata'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_new00
static int tolua_ResourceLuaAPI_Image_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Image* tolua_ret = (Image*)  Mtolua_new((Image)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Image");
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

/* method: new_local of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_new00_local
static int tolua_ResourceLuaAPI_Image_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Image* tolua_ret = (Image*)  Mtolua_new((Image)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Image");
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

/* method: delete of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_delete00
static int tolua_ResourceLuaAPI_Image_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetSize of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_SetSize00
static int tolua_ResourceLuaAPI_Image_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
  unsigned components = ((unsigned)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetSize(width,height,components);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_SetSize01
static int tolua_ResourceLuaAPI_Image_SetSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
  int depth = ((int)  tolua_tonumber(tolua_S,4,0));
  unsigned components = ((unsigned)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetSize(width,height,depth,components);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_Image_SetSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPixel of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_SetPixel00
static int tolua_ResourceLuaAPI_Image_SetPixel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  const Color* color = ((const Color*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPixel'", NULL);
#endif
 {
  self->SetPixel(x,y,*color);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPixel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPixel of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_SetPixel01
static int tolua_ResourceLuaAPI_Image_SetPixel01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int z = ((int)  tolua_tonumber(tolua_S,4,0));
  const Color* color = ((const Color*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPixel'", NULL);
#endif
 {
  self->SetPixel(x,y,z,*color);
 }
 }
 return 0;
tolua_lerror:
 return tolua_ResourceLuaAPI_Image_SetPixel00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPixelInt of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_SetPixelInt00
static int tolua_ResourceLuaAPI_Image_SetPixelInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  unsigned uintColor = ((unsigned)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPixelInt'", NULL);
#endif
 {
  self->SetPixelInt(x,y,uintColor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPixelInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPixelInt of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_SetPixelInt01
static int tolua_ResourceLuaAPI_Image_SetPixelInt01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int z = ((int)  tolua_tonumber(tolua_S,4,0));
  unsigned uintColor = ((unsigned)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPixelInt'", NULL);
#endif
 {
  self->SetPixelInt(x,y,z,uintColor);
 }
 }
 return 0;
tolua_lerror:
 return tolua_ResourceLuaAPI_Image_SetPixelInt00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadColorLUT of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_LoadColorLUT00
static int tolua_ResourceLuaAPI_Image_LoadColorLUT00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Deserializer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  Deserializer* source = ((Deserializer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadColorLUT'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->LoadColorLUT(*source);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadColorLUT'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ImageLoadColorLUT of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_LoadColorLUT01
static int tolua_ResourceLuaAPI_Image_LoadColorLUT01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ImageLoadColorLUT'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  ImageLoadColorLUT(self,fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_Image_LoadColorLUT00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: FlipHorizontal of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_FlipHorizontal00
static int tolua_ResourceLuaAPI_Image_FlipHorizontal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FlipHorizontal'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->FlipHorizontal();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FlipHorizontal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FlipVertical of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_FlipVertical00
static int tolua_ResourceLuaAPI_Image_FlipVertical00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FlipVertical'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->FlipVertical();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FlipVertical'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Resize of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_Resize00
static int tolua_ResourceLuaAPI_Image_Resize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Resize'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Resize(width,height);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Resize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_Clear00
static int tolua_ResourceLuaAPI_Image_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  const Color* color = ((const Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
 {
  self->Clear(*color);
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

/* method: ClearInt of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_ClearInt00
static int tolua_ResourceLuaAPI_Image_ClearInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  unsigned uintColor = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearInt'", NULL);
#endif
 {
  self->ClearInt(uintColor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveBMP of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_SaveBMP00
static int tolua_ResourceLuaAPI_Image_SaveBMP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveBMP'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SaveBMP(fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveBMP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SavePNG of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_SavePNG00
static int tolua_ResourceLuaAPI_Image_SavePNG00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SavePNG'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SavePNG(fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SavePNG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveTGA of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_SaveTGA00
static int tolua_ResourceLuaAPI_Image_SaveTGA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveTGA'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SaveTGA(fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveTGA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveJPG of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_SaveJPG00
static int tolua_ResourceLuaAPI_Image_SaveJPG00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  int quality = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveJPG'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SaveJPG(fileName,quality);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveJPG'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveDDS of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_SaveDDS00
static int tolua_ResourceLuaAPI_Image_SaveDDS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveDDS'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SaveDDS(fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveDDS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveWEBP of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_SaveWEBP00
static int tolua_ResourceLuaAPI_Image_SaveWEBP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  float compression = ((float)  tolua_tonumber(tolua_S,3,0.0f));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveWEBP'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SaveWEBP(fileName,compression);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveWEBP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPixel of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_GetPixel00
static int tolua_ResourceLuaAPI_Image_GetPixel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPixel'", NULL);
#endif
 {
  Color tolua_ret = (Color)  self->GetPixel(x,y);
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
 tolua_error(tolua_S,"#ferror in function 'GetPixel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPixel of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_GetPixel01
static int tolua_ResourceLuaAPI_Image_GetPixel01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int z = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPixel'", NULL);
#endif
 {
  Color tolua_ret = (Color)  self->GetPixel(x,y,z);
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
tolua_lerror:
 return tolua_ResourceLuaAPI_Image_GetPixel00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPixelInt of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_GetPixelInt00
static int tolua_ResourceLuaAPI_Image_GetPixelInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPixelInt'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetPixelInt(x,y);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPixelInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPixelInt of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_GetPixelInt01
static int tolua_ResourceLuaAPI_Image_GetPixelInt01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int z = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPixelInt'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetPixelInt(x,y,z);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_Image_GetPixelInt00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPixelBilinear of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_GetPixelBilinear00
static int tolua_ResourceLuaAPI_Image_GetPixelBilinear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPixelBilinear'", NULL);
#endif
 {
  Color tolua_ret = (Color)  self->GetPixelBilinear(x,y);
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
 tolua_error(tolua_S,"#ferror in function 'GetPixelBilinear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPixelTrilinear of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_GetPixelTrilinear00
static int tolua_ResourceLuaAPI_Image_GetPixelTrilinear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPixelTrilinear'", NULL);
#endif
 {
  Color tolua_ret = (Color)  self->GetPixelTrilinear(x,y,z);
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
 tolua_error(tolua_S,"#ferror in function 'GetPixelTrilinear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidth of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_GetWidth00
static int tolua_ResourceLuaAPI_Image_GetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetHeight of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_GetHeight00
static int tolua_ResourceLuaAPI_Image_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetDepth of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_GetDepth00
static int tolua_ResourceLuaAPI_Image_GetDepth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDepth'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetDepth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDepth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetComponents of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_GetComponents00
static int tolua_ResourceLuaAPI_Image_GetComponents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetComponents'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetComponents();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetComponents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsCompressed of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_IsCompressed00
static int tolua_ResourceLuaAPI_Image_IsCompressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsCompressed'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsCompressed();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsCompressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCompressedFormat of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_GetCompressedFormat00
static int tolua_ResourceLuaAPI_Image_GetCompressedFormat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCompressedFormat'", NULL);
#endif
 {
  CompressedFormat tolua_ret = (CompressedFormat)  self->GetCompressedFormat();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCompressedFormat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumCompressedLevels of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_GetNumCompressedLevels00
static int tolua_ResourceLuaAPI_Image_GetNumCompressedLevels00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumCompressedLevels'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumCompressedLevels();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumCompressedLevels'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSubimage of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_GetSubimage00
static int tolua_ResourceLuaAPI_Image_GetSubimage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* rect = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSubimage'", NULL);
#endif
 {
  Image* tolua_ret = (Image*)  self->GetSubimage(*rect);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Image");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSubimage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSubimage of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_SetSubimage00
static int tolua_ResourceLuaAPI_Image_SetSubimage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"const Image",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  const Image* image = ((const Image*)  tolua_tousertype(tolua_S,2,0));
  const IntRect rect = *((const IntRect*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSubimage'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetSubimage(image,rect);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSubimage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsCubemap of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_IsCubemap00
static int tolua_ResourceLuaAPI_Image_IsCubemap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsCubemap'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsCubemap();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsCubemap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsArray of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_IsArray00
static int tolua_ResourceLuaAPI_Image_IsArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsArray'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsArray();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsSRGB of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_IsSRGB00
static int tolua_ResourceLuaAPI_Image_IsSRGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsSRGB'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsSRGB();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsSRGB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasAlphaChannel of class  Image */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Image_HasAlphaChannel00
static int tolua_ResourceLuaAPI_Image_HasAlphaChannel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Image",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Image* self = (const Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasAlphaChannel'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasAlphaChannel();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasAlphaChannel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  Image */
#ifndef TOLUA_DISABLE_tolua_get_Image_width
static int tolua_get_Image_width(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetWidth());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  Image */
#ifndef TOLUA_DISABLE_tolua_get_Image_height
static int tolua_get_Image_height(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetHeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: depth of class  Image */
#ifndef TOLUA_DISABLE_tolua_get_Image_depth
static int tolua_get_Image_depth(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'depth'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDepth());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: components of class  Image */
#ifndef TOLUA_DISABLE_tolua_get_Image_components
static int tolua_get_Image_components(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'components'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetComponents());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: compressed of class  Image */
#ifndef TOLUA_DISABLE_tolua_get_Image_compressed
static int tolua_get_Image_compressed(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'compressed'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsCompressed());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: compressedFormat of class  Image */
#ifndef TOLUA_DISABLE_tolua_get_Image_compressedFormat
static int tolua_get_Image_compressedFormat(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'compressedFormat'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetCompressedFormat());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numCompressedLevels of class  Image */
#ifndef TOLUA_DISABLE_tolua_get_Image_numCompressedLevels
static int tolua_get_Image_numCompressedLevels(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numCompressedLevels'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumCompressedLevels());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cubemap of class  Image */
#ifndef TOLUA_DISABLE_tolua_get_Image_cubemap
static int tolua_get_Image_cubemap(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cubemap'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsCubemap());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: array of class  Image */
#ifndef TOLUA_DISABLE_tolua_get_Image_array
static int tolua_get_Image_array(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'array'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsArray());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sRGB of class  Image */
#ifndef TOLUA_DISABLE_tolua_get_Image_sRGB
static int tolua_get_Image_sRGB(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sRGB'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsSRGB());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_new00
static int tolua_ResourceLuaAPI_JSONValue_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  JSONValue* tolua_ret = (JSONValue*)  Mtolua_new((JSONValue)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONValue");
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

/* method: new_local of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_new00_local
static int tolua_ResourceLuaAPI_JSONValue_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  JSONValue* tolua_ret = (JSONValue*)  Mtolua_new((JSONValue)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONValue");
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

/* method: new of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_new01
static int tolua_ResourceLuaAPI_JSONValue_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
 {
  JSONValue* tolua_ret = (JSONValue*)  Mtolua_new((JSONValue)(value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONValue");
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_JSONValue_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_new01_local
static int tolua_ResourceLuaAPI_JSONValue_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
 {
  JSONValue* tolua_ret = (JSONValue*)  Mtolua_new((JSONValue)(value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONValue");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_JSONValue_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_new02
static int tolua_ResourceLuaAPI_JSONValue_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const char* value = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  JSONValue* tolua_ret = (JSONValue*)  Mtolua_new((JSONValue)(value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONValue");
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_JSONValue_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_new02_local
static int tolua_ResourceLuaAPI_JSONValue_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const char* value = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  JSONValue* tolua_ret = (JSONValue*)  Mtolua_new((JSONValue)(value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONValue");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_JSONValue_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_new03
static int tolua_ResourceLuaAPI_JSONValue_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  double value = ((double)  tolua_tonumber(tolua_S,2,0));
 {
  JSONValue* tolua_ret = (JSONValue*)  Mtolua_new((JSONValue)(value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONValue");
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_JSONValue_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_new03_local
static int tolua_ResourceLuaAPI_JSONValue_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  double value = ((double)  tolua_tonumber(tolua_S,2,0));
 {
  JSONValue* tolua_ret = (JSONValue*)  Mtolua_new((JSONValue)(value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONValue");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_JSONValue_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_new04
static int tolua_ResourceLuaAPI_JSONValue_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONValue",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const JSONArray",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const JSONArray* value = ((const JSONArray*)  tolua_tousertype(tolua_S,2,0));
 {
  JSONValue* tolua_ret = (JSONValue*)  Mtolua_new((JSONValue)(*value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONValue");
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_JSONValue_new03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_new04_local
static int tolua_ResourceLuaAPI_JSONValue_new04_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONValue",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const JSONArray",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const JSONArray* value = ((const JSONArray*)  tolua_tousertype(tolua_S,2,0));
 {
  JSONValue* tolua_ret = (JSONValue*)  Mtolua_new((JSONValue)(*value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONValue");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_JSONValue_new03_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_new05
static int tolua_ResourceLuaAPI_JSONValue_new05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONValue",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const JSONObject",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const JSONObject* value = ((const JSONObject*)  tolua_tousertype(tolua_S,2,0));
 {
  JSONValue* tolua_ret = (JSONValue*)  Mtolua_new((JSONValue)(*value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONValue");
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_JSONValue_new04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_new05_local
static int tolua_ResourceLuaAPI_JSONValue_new05_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONValue",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const JSONObject",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const JSONObject* value = ((const JSONObject*)  tolua_tousertype(tolua_S,2,0));
 {
  JSONValue* tolua_ret = (JSONValue*)  Mtolua_new((JSONValue)(*value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONValue");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_JSONValue_new04_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_new06
static int tolua_ResourceLuaAPI_JSONValue_new06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONValue",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const JSONValue",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const JSONValue* value = ((const JSONValue*)  tolua_tousertype(tolua_S,2,0));
 {
  JSONValue* tolua_ret = (JSONValue*)  Mtolua_new((JSONValue)(*value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONValue");
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_JSONValue_new05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_new06_local
static int tolua_ResourceLuaAPI_JSONValue_new06_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONValue",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const JSONValue",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const JSONValue* value = ((const JSONValue*)  tolua_tousertype(tolua_S,2,0));
 {
  JSONValue* tolua_ret = (JSONValue*)  Mtolua_new((JSONValue)(*value));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONValue");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_JSONValue_new05_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_delete00
static int tolua_ResourceLuaAPI_JSONValue_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
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

/* method: JSONValueSetBool of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_SetBool00
static int tolua_ResourceLuaAPI_JSONValue_SetBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'JSONValueSetBool'", NULL);
#endif
 {
  JSONValueSetBool(self,value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: JSONValueSetInt of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_SetInt00
static int tolua_ResourceLuaAPI_JSONValue_SetInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'JSONValueSetInt'", NULL);
#endif
 {
  JSONValueSetInt(self,value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: JSONValueSetUint of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_SetUint00
static int tolua_ResourceLuaAPI_JSONValue_SetUint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'JSONValueSetUint'", NULL);
#endif
 {
  JSONValueSetUint(self,value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: JSONValueSetFloat of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_SetFloat00
static int tolua_ResourceLuaAPI_JSONValue_SetFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'JSONValueSetFloat'", NULL);
#endif
 {
  JSONValueSetFloat(self,value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: JSONValueSetDouble of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_SetDouble00
static int tolua_ResourceLuaAPI_JSONValue_SetDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  double value = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'JSONValueSetDouble'", NULL);
#endif
 {
  JSONValueSetDouble(self,value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDouble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: JSONValueSetString of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_SetString00
static int tolua_ResourceLuaAPI_JSONValue_SetString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'JSONValueSetString'", NULL);
#endif
 {
  JSONValueSetString(self,value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: JSONValueSetArray of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_SetArray00
static int tolua_ResourceLuaAPI_JSONValue_SetArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const JSONArray",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  const JSONArray* value = ((const JSONArray*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'JSONValueSetArray'", NULL);
#endif
 {
  JSONValueSetArray(self,*value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: JSONValueSetObject of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_SetObject00
static int tolua_ResourceLuaAPI_JSONValue_SetObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const JSONObject",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  const JSONObject* value = ((const JSONObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'JSONValueSetObject'", NULL);
#endif
 {
  JSONValueSetObject(self,*value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVariant of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_SetVariant00
static int tolua_ResourceLuaAPI_JSONValue_SetVariant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVariant'", NULL);
#endif
 {
  self->SetVariant(*value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVariant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVariantMap of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_SetVariantMap00
static int tolua_ResourceLuaAPI_JSONValue_SetVariantMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  const VariantMap* value = ((const VariantMap*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVariantMap'", NULL);
#endif
 {
  self->SetVariantMap(*value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVariantMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetValueType of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_GetValueType00
static int tolua_ResourceLuaAPI_JSONValue_GetValueType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetValueType'", NULL);
#endif
 {
  JSONValueType tolua_ret = (JSONValueType)  self->GetValueType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetValueType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumberType of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_GetNumberType00
static int tolua_ResourceLuaAPI_JSONValue_GetNumberType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumberType'", NULL);
#endif
 {
  JSONNumberType tolua_ret = (JSONNumberType)  self->GetNumberType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumberType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetValueTypeName of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_GetValueTypeName00
static int tolua_ResourceLuaAPI_JSONValue_GetValueTypeName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetValueTypeName'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetValueTypeName();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetValueTypeName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumberTypeName of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_GetNumberTypeName00
static int tolua_ResourceLuaAPI_JSONValue_GetNumberTypeName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumberTypeName'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetNumberTypeName();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumberTypeName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsNull of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_IsNull00
static int tolua_ResourceLuaAPI_JSONValue_IsNull00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsNull'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsNull();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsNull'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsBool of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_IsBool00
static int tolua_ResourceLuaAPI_JSONValue_IsBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsBool'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsBool();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsNumber of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_IsNumber00
static int tolua_ResourceLuaAPI_JSONValue_IsNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsNumber'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsNumber();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsString of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_IsString00
static int tolua_ResourceLuaAPI_JSONValue_IsString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsString'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsString();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsArray of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_IsArray00
static int tolua_ResourceLuaAPI_JSONValue_IsArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsArray'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsArray();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsObject of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_IsObject00
static int tolua_ResourceLuaAPI_JSONValue_IsObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsObject'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsObject();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBool of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_GetBool00
static int tolua_ResourceLuaAPI_JSONValue_GetBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetInt of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_GetInt00
static int tolua_ResourceLuaAPI_JSONValue_GetInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetUInt of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_GetUInt00
static int tolua_ResourceLuaAPI_JSONValue_GetUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetFloat of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_GetFloat00
static int tolua_ResourceLuaAPI_JSONValue_GetFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetDouble of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_GetDouble00
static int tolua_ResourceLuaAPI_JSONValue_GetDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetString of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_GetString00
static int tolua_ResourceLuaAPI_JSONValue_GetString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetArray of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_GetArray00
static int tolua_ResourceLuaAPI_JSONValue_GetArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetArray'", NULL);
#endif
 {
  const JSONArray& tolua_ret = (const JSONArray&)  self->GetArray();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const JSONArray");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObject of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_GetObject00
static int tolua_ResourceLuaAPI_JSONValue_GetObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObject'", NULL);
#endif
 {
  const JSONObject& tolua_ret = (const JSONObject&)  self->GetObject();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const JSONObject");
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

/* method: GetVariant of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_GetVariant00
static int tolua_ResourceLuaAPI_JSONValue_GetVariant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVariant'", NULL);
#endif
 {
  Variant tolua_ret = (Variant)  self->GetVariant();
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
 tolua_error(tolua_S,"#ferror in function 'GetVariant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVariantMap of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_GetVariantMap00
static int tolua_ResourceLuaAPI_JSONValue_GetVariantMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVariantMap'", NULL);
#endif
 {
  VariantMap tolua_ret = (VariantMap)  self->GetVariantMap();
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
 tolua_error(tolua_S,"#ferror in function 'GetVariantMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator&[] of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue__seti00
static int tolua_ResourceLuaAPI_JSONValue__seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"JSONValue",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  JSONValue tolua_value = *((JSONValue*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'", NULL);
#endif
 self->operator[](index) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue__geti00
static int tolua_ResourceLuaAPI_JSONValue__geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
 {
  JSONValue tolua_ret = (JSONValue)  self->operator[](index);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((JSONValue)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"JSONValue");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(JSONValue));
  tolua_pushusertype(tolua_S,tolua_obj,"JSONValue");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue__geti01
static int tolua_ResourceLuaAPI_JSONValue__geti01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
 {
  const JSONValue tolua_ret = (const JSONValue)  self->operator[](index);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((JSONValue)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"const JSONValue");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(const JSONValue));
  tolua_pushusertype(tolua_S,tolua_obj,"const JSONValue");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_JSONValue__geti00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Push of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_Push00
static int tolua_ResourceLuaAPI_JSONValue_Push00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const JSONValue",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  const JSONValue* value = ((const JSONValue*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Push'", NULL);
#endif
 {
  self->Push(*value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Push'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Pop of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_Pop00
static int tolua_ResourceLuaAPI_JSONValue_Pop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Pop'", NULL);
#endif
 {
  self->Pop();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Pop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Insert of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_Insert00
static int tolua_ResourceLuaAPI_JSONValue_Insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const JSONValue",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  unsigned pos = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  const JSONValue* value = ((const JSONValue*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Insert'", NULL);
#endif
 {
  self->Insert(pos,*value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Insert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Erase of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_Erase00
static int tolua_ResourceLuaAPI_JSONValue_Erase00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  unsigned pos = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  unsigned length = ((unsigned)  tolua_tonumber(tolua_S,3,1));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Erase'", NULL);
#endif
 {
  self->Erase(pos,length);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Erase'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Resize of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_Resize00
static int tolua_ResourceLuaAPI_JSONValue_Resize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  unsigned newSize = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Resize'", NULL);
#endif
 {
  self->Resize(newSize);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Resize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Size of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_Size00
static int tolua_ResourceLuaAPI_JSONValue_Size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Size'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->Size();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_Set00
static int tolua_ResourceLuaAPI_JSONValue_Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const JSONValue",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  const String key = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const JSONValue* value = ((const JSONValue*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'", NULL);
#endif
 {
  self->Set(key,*value);
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

/* method: Get of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_Get00
static int tolua_ResourceLuaAPI_JSONValue_Get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
  const String key = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get'", NULL);
#endif
 {
  const JSONValue& tolua_ret = (const JSONValue&)  self->Get(key);
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const JSONValue");
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

/* method: Erase of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_Erase01
static int tolua_ResourceLuaAPI_JSONValue_Erase01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
  const String key = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Erase'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Erase(key);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_JSONValue_Erase00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Contains of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_Contains00
static int tolua_ResourceLuaAPI_JSONValue_Contains00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONValue",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONValue* self = (const JSONValue*)  tolua_tousertype(tolua_S,1,0);
  const String key = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Contains'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Contains(key);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Contains'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONValue_Clear00
static int tolua_ResourceLuaAPI_JSONValue_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONValue",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: EMPTY of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_get_JSONValue_EMPTY
static int tolua_get_JSONValue_EMPTY(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&JSONValue::EMPTY,"const JSONValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: emptyArray of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_get_JSONValue_emptyArray
static int tolua_get_JSONValue_emptyArray(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&JSONValue::emptyArray,"const JSONArray");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: emptyObject of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_get_JSONValue_emptyObject
static int tolua_get_JSONValue_emptyObject(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&JSONValue::emptyObject,"const JSONObject");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: null of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_get_JSONValue_null
static int tolua_get_JSONValue_null(lua_State* tolua_S)
{
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'null'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsNull());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: valueType of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_get_JSONValue_valueType
static int tolua_get_JSONValue_valueType(lua_State* tolua_S)
{
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'valueType'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetValueType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numberType of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_get_JSONValue_numberType
static int tolua_get_JSONValue_numberType(lua_State* tolua_S)
{
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numberType'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumberType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: valueTypeName of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_get_JSONValue_valueTypeName
static int tolua_get_JSONValue_valueTypeName(lua_State* tolua_S)
{
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'valueTypeName'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetValueTypeName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numberTypeName of class  JSONValue */
#ifndef TOLUA_DISABLE_tolua_get_JSONValue_numberTypeName
static int tolua_get_JSONValue_numberTypeName(lua_State* tolua_S)
{
  JSONValue* self = (JSONValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numberTypeName'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetNumberTypeName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  JSONFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONFile_new00
static int tolua_ResourceLuaAPI_JSONFile_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  JSONFile* tolua_ret = (JSONFile*)  Mtolua_new((JSONFile)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONFile");
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

/* method: new_local of class  JSONFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONFile_new00_local
static int tolua_ResourceLuaAPI_JSONFile_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"JSONFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  JSONFile* tolua_ret = (JSONFile*)  Mtolua_new((JSONFile)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONFile");
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

/* method: delete of class  JSONFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONFile_delete00
static int tolua_ResourceLuaAPI_JSONFile_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONFile* self = (JSONFile*)  tolua_tousertype(tolua_S,1,0);
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

/* method: FromString of class  JSONFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONFile_FromString00
static int tolua_ResourceLuaAPI_JSONFile_FromString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"JSONFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  JSONFile* self = (JSONFile*)  tolua_tousertype(tolua_S,1,0);
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FromString'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->FromString(source);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FromString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRoot of class  JSONFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONFile_GetRoot00
static int tolua_ResourceLuaAPI_JSONFile_GetRoot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONFile* self = (const JSONFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRoot'", NULL);
#endif
 {
  const JSONValue& tolua_ret = (const JSONValue&)  self->GetRoot();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const JSONValue");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRoot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: JSONFileSave of class  JSONFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_JSONFile_Save00
static int tolua_ResourceLuaAPI_JSONFile_Save00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const JSONFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const JSONFile* self = (const JSONFile*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String indentation = ((const String)  tolua_tourho3dstring(tolua_S,3,"\t"));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'JSONFileSave'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  JSONFileSave(self,fileName,indentation);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Save'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AppendChild of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_AppendChild00
static int tolua_ResourceLuaAPI_XMLElement_AppendChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"XMLElement",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  XMLElement element = *((XMLElement*)  tolua_tousertype(tolua_S,2,0));
  bool asCopy = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AppendChild'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->AppendChild(element,asCopy);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AppendChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateChild of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_CreateChild00
static int tolua_ResourceLuaAPI_XMLElement_CreateChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateChild'", NULL);
#endif
 {
  XMLElement tolua_ret = (XMLElement)  self->CreateChild(name);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((XMLElement)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(XMLElement));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOrCreateChild of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetOrCreateChild00
static int tolua_ResourceLuaAPI_XMLElement_GetOrCreateChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOrCreateChild'", NULL);
#endif
 {
  XMLElement tolua_ret = (XMLElement)  self->GetOrCreateChild(name);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((XMLElement)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(XMLElement));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOrCreateChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveChild of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_RemoveChild00
static int tolua_ResourceLuaAPI_XMLElement_RemoveChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const XMLElement",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const XMLElement* element = ((const XMLElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveChild'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->RemoveChild(*element);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveChild of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_RemoveChild01
static int tolua_ResourceLuaAPI_XMLElement_RemoveChild01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveChild'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->RemoveChild(name);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_XMLElement_RemoveChild00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveChildren of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_RemoveChildren00
static int tolua_ResourceLuaAPI_XMLElement_RemoveChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,String::EMPTY));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveChildren'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->RemoveChildren(name);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAttribute of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_RemoveAttribute00
static int tolua_ResourceLuaAPI_XMLElement_RemoveAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,String::EMPTY));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAttribute'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->RemoveAttribute(name);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAttribute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Remove of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_Remove00
static int tolua_ResourceLuaAPI_XMLElement_Remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Remove'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Remove();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetValue of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetValue00
static int tolua_ResourceLuaAPI_XMLElement_SetValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetValue'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetValue(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAttribute of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetAttribute00
static int tolua_ResourceLuaAPI_XMLElement_SetAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAttribute'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetAttribute(name,value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAttribute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAttribute of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetAttribute01
static int tolua_ResourceLuaAPI_XMLElement_SetAttribute01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAttribute'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetAttribute(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_XMLElement_SetAttribute00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBool of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetBool00
static int tolua_ResourceLuaAPI_XMLElement_SetBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool value = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBool'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetBool(name,value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBoundingBox of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetBoundingBox00
static int tolua_ResourceLuaAPI_XMLElement_SetBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* value = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBoundingBox'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetBoundingBox(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetColor of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetColor00
static int tolua_ResourceLuaAPI_XMLElement_SetColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Color* value = ((const Color*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetColor'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetColor(name,*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFloat of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetFloat00
static int tolua_ResourceLuaAPI_XMLElement_SetFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  float value = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFloat'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetFloat(name,value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDouble of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetDouble00
static int tolua_ResourceLuaAPI_XMLElement_SetDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  double value = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDouble'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetDouble(name,value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDouble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUInt of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetUInt00
static int tolua_ResourceLuaAPI_XMLElement_SetUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUInt'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetUInt(name,value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetInt of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetInt00
static int tolua_ResourceLuaAPI_XMLElement_SetInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  int value = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInt'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetInt(name,value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUInt64 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetUInt6400
static int tolua_ResourceLuaAPI_XMLElement_SetUInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  unsigned long long value = ((unsigned long long)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUInt64'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetUInt64(name,value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetInt64 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetInt6400
static int tolua_ResourceLuaAPI_XMLElement_SetInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  long long value = ((long long)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInt64'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetInt64(name,value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIntRect of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetIntRect00
static int tolua_ResourceLuaAPI_XMLElement_SetIntRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const IntRect* value = ((const IntRect*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIntRect'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetIntRect(name,*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIntRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIntVector2 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetIntVector200
static int tolua_ResourceLuaAPI_XMLElement_SetIntVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const IntVector2* value = ((const IntVector2*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIntVector2'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetIntVector2(name,*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIntVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIntVector3 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetIntVector300
static int tolua_ResourceLuaAPI_XMLElement_SetIntVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const IntVector3* value = ((const IntVector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIntVector3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetIntVector3(name,*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIntVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRect of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetRect00
static int tolua_ResourceLuaAPI_XMLElement_SetRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Rect* value = ((const Rect*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRect'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetRect(name,*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetQuaternion of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetQuaternion00
static int tolua_ResourceLuaAPI_XMLElement_SetQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Quaternion* value = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetQuaternion'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetQuaternion(name,*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetString of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetString00
static int tolua_ResourceLuaAPI_XMLElement_SetString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetString'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetString(name,value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVariant of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetVariant00
static int tolua_ResourceLuaAPI_XMLElement_SetVariant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVariant'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetVariant(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVariant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVariantValue of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetVariantValue00
static int tolua_ResourceLuaAPI_XMLElement_SetVariantValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVariantValue'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetVariantValue(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVariantValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetResourceRef of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetResourceRef00
static int tolua_ResourceLuaAPI_XMLElement_SetResourceRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ResourceRef",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const ResourceRef* value = ((const ResourceRef*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetResourceRef'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetResourceRef(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetResourceRef'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetResourceRefList of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetResourceRefList00
static int tolua_ResourceLuaAPI_XMLElement_SetResourceRefList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ResourceRefList",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const ResourceRefList* value = ((const ResourceRefList*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetResourceRefList'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetResourceRefList(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetResourceRefList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVector2 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetVector200
static int tolua_ResourceLuaAPI_XMLElement_SetVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Vector2* value = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVector2'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetVector2(name,*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVector3 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetVector300
static int tolua_ResourceLuaAPI_XMLElement_SetVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Vector3* value = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVector3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetVector3(name,*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVector4 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetVector400
static int tolua_ResourceLuaAPI_XMLElement_SetVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Vector4* value = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVector4'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetVector4(name,*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVectorVariant of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetVectorVariant00
static int tolua_ResourceLuaAPI_XMLElement_SetVectorVariant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVectorVariant'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetVectorVariant(name,*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVectorVariant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMatrix3 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetMatrix300
static int tolua_ResourceLuaAPI_XMLElement_SetMatrix300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Matrix3* value = ((const Matrix3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMatrix3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetMatrix3(name,*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMatrix3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMatrix3x4 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetMatrix3x400
static int tolua_ResourceLuaAPI_XMLElement_SetMatrix3x400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Matrix3x4* value = ((const Matrix3x4*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMatrix3x4'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetMatrix3x4(name,*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMatrix3x4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMatrix4 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_SetMatrix400
static int tolua_ResourceLuaAPI_XMLElement_SetMatrix400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Matrix4* value = ((const Matrix4*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMatrix4'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetMatrix4(name,*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMatrix4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsNull of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_IsNull00
static int tolua_ResourceLuaAPI_XMLElement_IsNull00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsNull'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsNull();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsNull'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NotNull of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_NotNull00
static int tolua_ResourceLuaAPI_XMLElement_NotNull00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NotNull'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->NotNull();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NotNull'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operatorbool of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement__bool00
static int tolua_ResourceLuaAPI_XMLElement__bool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operatorbool'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->operator  bool();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.bool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetName00
static int tolua_ResourceLuaAPI_XMLElement_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetName'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetName();
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

/* method: HasChild of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_HasChild00
static int tolua_ResourceLuaAPI_XMLElement_HasChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasChild'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasChild(name);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetChild of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetChild00
static int tolua_ResourceLuaAPI_XMLElement_GetChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,String::EMPTY));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChild'", NULL);
#endif
 {
  XMLElement tolua_ret = (XMLElement)  self->GetChild(name);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((XMLElement)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(XMLElement));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNext of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetNext00
static int tolua_ResourceLuaAPI_XMLElement_GetNext00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,String::EMPTY));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNext'", NULL);
#endif
 {
  XMLElement tolua_ret = (XMLElement)  self->GetNext(name);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((XMLElement)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(XMLElement));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNext'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetParent of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetParent00
static int tolua_ResourceLuaAPI_XMLElement_GetParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetParent'", NULL);
#endif
 {
  XMLElement tolua_ret = (XMLElement)  self->GetParent();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((XMLElement)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(XMLElement));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumAttributes of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetNumAttributes00
static int tolua_ResourceLuaAPI_XMLElement_GetNumAttributes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumAttributes'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumAttributes();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumAttributes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasAttribute of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_HasAttribute00
static int tolua_ResourceLuaAPI_XMLElement_HasAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasAttribute'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasAttribute(name);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasAttribute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetValue of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetValue00
static int tolua_ResourceLuaAPI_XMLElement_GetValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetValue'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetValue();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAttribute of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetAttribute00
static int tolua_ResourceLuaAPI_XMLElement_GetAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,String::EMPTY));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttribute'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetAttribute(name);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttribute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAttributeLower of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetAttributeLower00
static int tolua_ResourceLuaAPI_XMLElement_GetAttributeLower00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeLower'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetAttributeLower(name);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeLower'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAttributeUpper of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetAttributeUpper00
static int tolua_ResourceLuaAPI_XMLElement_GetAttributeUpper00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeUpper'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetAttributeUpper(name);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeUpper'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAttributeNames of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetAttributeNames00
static int tolua_ResourceLuaAPI_XMLElement_GetAttributeNames00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeNames'", NULL);
#endif
 {
  Vector<String> tolua_ret = (Vector<String>)  self->GetAttributeNames();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((Vector<String>)(tolua_ret));
  ToluaPushVector<String>(tolua_S,tolua_obj,"String");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector<String>));
  ToluaPushVector<String>(tolua_S,tolua_obj,"String");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeNames'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBool of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetBool00
static int tolua_ResourceLuaAPI_XMLElement_GetBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBool'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetBool(name);
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

/* method: GetBoundingBox of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetBoundingBox00
static int tolua_ResourceLuaAPI_XMLElement_GetBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetColor of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetColor00
static int tolua_ResourceLuaAPI_XMLElement_GetColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetColor'", NULL);
#endif
 {
  Color tolua_ret = (Color)  self->GetColor(name);
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
 tolua_error(tolua_S,"#ferror in function 'GetColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFloat of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetFloat00
static int tolua_ResourceLuaAPI_XMLElement_GetFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFloat'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetFloat(name);
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

/* method: GetDouble of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetDouble00
static int tolua_ResourceLuaAPI_XMLElement_GetDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDouble'", NULL);
#endif
 {
  double tolua_ret = (double)  self->GetDouble(name);
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

/* method: GetUInt of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetUInt00
static int tolua_ResourceLuaAPI_XMLElement_GetUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUInt'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetUInt(name);
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

/* method: GetInt of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetInt00
static int tolua_ResourceLuaAPI_XMLElement_GetInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInt'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetInt(name);
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

/* method: GetUInt64 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetUInt6400
static int tolua_ResourceLuaAPI_XMLElement_GetUInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUInt64'", NULL);
#endif
 {
  unsigned long long tolua_ret = (unsigned long long)  self->GetUInt64(name);
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

/* method: GetInt64 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetInt6400
static int tolua_ResourceLuaAPI_XMLElement_GetInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInt64'", NULL);
#endif
 {
  long long tolua_ret = (long long)  self->GetInt64(name);
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

/* method: GetIntRect of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetIntRect00
static int tolua_ResourceLuaAPI_XMLElement_GetIntRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIntRect'", NULL);
#endif
 {
  IntRect tolua_ret = (IntRect)  self->GetIntRect(name);
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
 tolua_error(tolua_S,"#ferror in function 'GetIntRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIntVector2 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetIntVector200
static int tolua_ResourceLuaAPI_XMLElement_GetIntVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIntVector2'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->GetIntVector2(name);
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
 tolua_error(tolua_S,"#ferror in function 'GetIntVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIntVector3 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetIntVector300
static int tolua_ResourceLuaAPI_XMLElement_GetIntVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIntVector3'", NULL);
#endif
 {
  IntVector3 tolua_ret = (IntVector3)  self->GetIntVector3(name);
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
 tolua_error(tolua_S,"#ferror in function 'GetIntVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRect of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetRect00
static int tolua_ResourceLuaAPI_XMLElement_GetRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRect'", NULL);
#endif
 {
  Rect tolua_ret = (Rect)  self->GetRect(name);
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
 tolua_error(tolua_S,"#ferror in function 'GetRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetQuaternion of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetQuaternion00
static int tolua_ResourceLuaAPI_XMLElement_GetQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetQuaternion'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->GetQuaternion(name);
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
 tolua_error(tolua_S,"#ferror in function 'GetQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVariant of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetVariant00
static int tolua_ResourceLuaAPI_XMLElement_GetVariant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVariant'", NULL);
#endif
 {
  Variant tolua_ret = (Variant)  self->GetVariant();
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
 tolua_error(tolua_S,"#ferror in function 'GetVariant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVariantValue of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetVariantValue00
static int tolua_ResourceLuaAPI_XMLElement_GetVariantValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"VariantType",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  VariantType type = *((VariantType*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVariantValue'", NULL);
#endif
 {
  Variant tolua_ret = (Variant)  self->GetVariantValue(type);
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
 tolua_error(tolua_S,"#ferror in function 'GetVariantValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetResourceRef of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetResourceRef00
static int tolua_ResourceLuaAPI_XMLElement_GetResourceRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetResourceRef'", NULL);
#endif
 {
  ResourceRef tolua_ret = (ResourceRef)  self->GetResourceRef();
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
 tolua_error(tolua_S,"#ferror in function 'GetResourceRef'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetResourceRefList of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetResourceRefList00
static int tolua_ResourceLuaAPI_XMLElement_GetResourceRefList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetResourceRefList'", NULL);
#endif
 {
  ResourceRefList tolua_ret = (ResourceRefList)  self->GetResourceRefList();
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
 tolua_error(tolua_S,"#ferror in function 'GetResourceRefList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVariantMap of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetVariantMap00
static int tolua_ResourceLuaAPI_XMLElement_GetVariantMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVariantMap'", NULL);
#endif
 {
  VariantMap tolua_ret = (VariantMap)  self->GetVariantMap();
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
 tolua_error(tolua_S,"#ferror in function 'GetVariantMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVector2 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetVector200
static int tolua_ResourceLuaAPI_XMLElement_GetVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVector2'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->GetVector2(name);
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
 tolua_error(tolua_S,"#ferror in function 'GetVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVector3 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetVector300
static int tolua_ResourceLuaAPI_XMLElement_GetVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVector3'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetVector3(name);
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
 tolua_error(tolua_S,"#ferror in function 'GetVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVector4 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetVector400
static int tolua_ResourceLuaAPI_XMLElement_GetVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVector4'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->GetVector4(name);
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
 tolua_error(tolua_S,"#ferror in function 'GetVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVector of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetVector00
static int tolua_ResourceLuaAPI_XMLElement_GetVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVector'", NULL);
#endif
 {
  Vector4 tolua_ret = (Vector4)  self->GetVector(name);
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
 tolua_error(tolua_S,"#ferror in function 'GetVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMatrix3 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetMatrix300
static int tolua_ResourceLuaAPI_XMLElement_GetMatrix300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMatrix3'", NULL);
#endif
 {
  Matrix3 tolua_ret = (Matrix3)  self->GetMatrix3(name);
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
 tolua_error(tolua_S,"#ferror in function 'GetMatrix3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMatrix3x4 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetMatrix3x400
static int tolua_ResourceLuaAPI_XMLElement_GetMatrix3x400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMatrix3x4'", NULL);
#endif
 {
  Matrix3x4 tolua_ret = (Matrix3x4)  self->GetMatrix3x4(name);
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
 tolua_error(tolua_S,"#ferror in function 'GetMatrix3x4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMatrix4 of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetMatrix400
static int tolua_ResourceLuaAPI_XMLElement_GetMatrix400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMatrix4'", NULL);
#endif
 {
  Matrix4 tolua_ret = (Matrix4)  self->GetMatrix4(name);
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
 tolua_error(tolua_S,"#ferror in function 'GetMatrix4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFile of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLElement_GetFile00
static int tolua_ResourceLuaAPI_XMLElement_GetFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLElement* self = (const XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFile'", NULL);
#endif
 {
  XMLFile* tolua_ret = (XMLFile*)  self->GetFile();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"XMLFile");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: EMPTY of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_get_XMLElement_EMPTY
static int tolua_get_XMLElement_EMPTY(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)&XMLElement::EMPTY,"const XMLElement");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: null of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_get_XMLElement_null
static int tolua_get_XMLElement_null(lua_State* tolua_S)
{
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'null'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsNull());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_get_XMLElement_name
static int tolua_get_XMLElement_name(lua_State* tolua_S)
{
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: parent of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_get_XMLElement_parent
static int tolua_get_XMLElement_parent(lua_State* tolua_S)
{
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
#endif
 XMLElement tolua_ret = (XMLElement)self->GetParent();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((XMLElement)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(XMLElement));
 tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_get_XMLElement_value
static int tolua_get_XMLElement_value(lua_State* tolua_S)
{
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetValue());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numAttributes of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_get_XMLElement_numAttributes
static int tolua_get_XMLElement_numAttributes(lua_State* tolua_S)
{
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numAttributes'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumAttributes());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: file of class  XMLElement */
#ifndef TOLUA_DISABLE_tolua_get_XMLElement_file_ptr
static int tolua_get_XMLElement_file_ptr(lua_State* tolua_S)
{
  XMLElement* self = (XMLElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'file'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetFile(),"XMLFile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  XMLFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLFile_new00
static int tolua_ResourceLuaAPI_XMLFile_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"XMLFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  XMLFile* tolua_ret = (XMLFile*)  Mtolua_new((XMLFile)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"XMLFile");
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

/* method: new_local of class  XMLFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLFile_new00_local
static int tolua_ResourceLuaAPI_XMLFile_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"XMLFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  XMLFile* tolua_ret = (XMLFile*)  Mtolua_new((XMLFile)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"XMLFile");
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

/* method: delete of class  XMLFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLFile_delete00
static int tolua_ResourceLuaAPI_XMLFile_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLFile* self = (XMLFile*)  tolua_tousertype(tolua_S,1,0);
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

/* method: FromString of class  XMLFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLFile_FromString00
static int tolua_ResourceLuaAPI_XMLFile_FromString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLFile* self = (XMLFile*)  tolua_tousertype(tolua_S,1,0);
  const String source = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FromString'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->FromString(source);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FromString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateRoot of class  XMLFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLFile_CreateRoot00
static int tolua_ResourceLuaAPI_XMLFile_CreateRoot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLFile* self = (XMLFile*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,String::EMPTY));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateRoot'", NULL);
#endif
 {
  XMLElement tolua_ret = (XMLElement)  self->CreateRoot(name);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((XMLElement)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(XMLElement));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateRoot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOrCreateRoot of class  XMLFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLFile_GetOrCreateRoot00
static int tolua_ResourceLuaAPI_XMLFile_GetOrCreateRoot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLFile* self = (XMLFile*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,String::EMPTY));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOrCreateRoot'", NULL);
#endif
 {
  XMLElement tolua_ret = (XMLElement)  self->GetOrCreateRoot(name);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((XMLElement)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(XMLElement));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOrCreateRoot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRoot of class  XMLFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLFile_GetRoot00
static int tolua_ResourceLuaAPI_XMLFile_GetRoot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLFile* self = (XMLFile*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,String::EMPTY));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRoot'", NULL);
#endif
 {
  XMLElement tolua_ret = (XMLElement)  self->GetRoot(name);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((XMLElement)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(XMLElement));
  tolua_pushusertype(tolua_S,tolua_obj,"XMLElement");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRoot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  XMLFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLFile_ToString00
static int tolua_ResourceLuaAPI_XMLFile_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLFile* self = (const XMLFile*)  tolua_tousertype(tolua_S,1,0);
  const String indentation = ((const String)  tolua_tourho3dstring(tolua_S,2,"\t"));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
 {
  String tolua_ret = (String)  self->ToString(indentation);
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

/* method: Patch of class  XMLFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLFile_Patch00
static int tolua_ResourceLuaAPI_XMLFile_Patch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLFile",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"XMLFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  XMLFile* self = (XMLFile*)  tolua_tousertype(tolua_S,1,0);
  XMLFile* patchFile = ((XMLFile*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Patch'", NULL);
#endif
 {
  self->Patch(patchFile);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Patch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Patch of class  XMLFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLFile_Patch01
static int tolua_ResourceLuaAPI_XMLFile_Patch01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"XMLFile",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"XMLElement",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  XMLFile* self = (XMLFile*)  tolua_tousertype(tolua_S,1,0);
  XMLElement patchElement = *((XMLElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Patch'", NULL);
#endif
 {
  self->Patch(patchElement);
 }
 }
 return 0;
tolua_lerror:
 return tolua_ResourceLuaAPI_XMLFile_Patch00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: XMLFileSave of class  XMLFile */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_XMLFile_Save00
static int tolua_ResourceLuaAPI_XMLFile_Save00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const XMLFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const XMLFile* self = (const XMLFile*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String indentation = ((const String)  tolua_tourho3dstring(tolua_S,3,"\t"));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'XMLFileSave'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  XMLFileSave(self,fileName,indentation);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Save'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReleaseAllResources of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_ReleaseAllResources00
static int tolua_ResourceLuaAPI_ResourceCache_ReleaseAllResources00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceCache",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  bool force = ((bool)  tolua_toboolean(tolua_S,2,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReleaseAllResources'", NULL);
#endif
 {
  self->ReleaseAllResources(force);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReleaseAllResources'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReloadResource of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_ReloadResource00
static int tolua_ResourceLuaAPI_ResourceCache_ReloadResource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceCache",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Resource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  Resource* resource = ((Resource*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReloadResource'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->ReloadResource(resource);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReloadResource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReloadResourceWithDependencies of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_ReloadResourceWithDependencies00
static int tolua_ResourceLuaAPI_ResourceCache_ReloadResourceWithDependencies00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceCache",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReloadResourceWithDependencies'", NULL);
#endif
 {
  self->ReloadResourceWithDependencies(fileName);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReloadResourceWithDependencies'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMemoryBudget of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_SetMemoryBudget00
static int tolua_ResourceLuaAPI_ResourceCache_SetMemoryBudget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceCache",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  StringHash type = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
  unsigned long long budget = ((unsigned long long)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMemoryBudget'", NULL);
#endif
 {
  self->SetMemoryBudget(type,budget);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMemoryBudget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMemoryBudget of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_SetMemoryBudget01
static int tolua_ResourceLuaAPI_ResourceCache_SetMemoryBudget01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceCache",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  unsigned long long budget = ((unsigned long long)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMemoryBudget'", NULL);
#endif
 {
  self->SetMemoryBudget(type,budget);
 }
 }
 return 0;
tolua_lerror:
 return tolua_ResourceLuaAPI_ResourceCache_SetMemoryBudget00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAutoReloadResources of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_SetAutoReloadResources00
static int tolua_ResourceLuaAPI_ResourceCache_SetAutoReloadResources00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceCache",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAutoReloadResources'", NULL);
#endif
 {
  self->SetAutoReloadResources(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAutoReloadResources'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetReturnFailedResources of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_SetReturnFailedResources00
static int tolua_ResourceLuaAPI_ResourceCache_SetReturnFailedResources00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceCache",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetReturnFailedResources'", NULL);
#endif
 {
  self->SetReturnFailedResources(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetReturnFailedResources'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSearchPackagesFirst of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_SetSearchPackagesFirst00
static int tolua_ResourceLuaAPI_ResourceCache_SetSearchPackagesFirst00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceCache",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSearchPackagesFirst'", NULL);
#endif
 {
  self->SetSearchPackagesFirst(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSearchPackagesFirst'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFinishBackgroundResourcesMs of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_SetFinishBackgroundResourcesMs00
static int tolua_ResourceLuaAPI_ResourceCache_SetFinishBackgroundResourcesMs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceCache",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  int ms = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFinishBackgroundResourcesMs'", NULL);
#endif
 {
  self->SetFinishBackgroundResourcesMs(ms);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFinishBackgroundResourcesMs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResourceCacheGetFile of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_GetFile00
static int tolua_ResourceLuaAPI_ResourceCache_GetFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceCache",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResourceCacheGetFile'", NULL);
#endif
 {
  tolua_outside File* tolua_ret = (tolua_outside File*)  ResourceCacheGetFile(self,name);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"File");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetResource of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_GetResource00
static int tolua_ResourceLuaAPI_ResourceCache_GetResource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceCache",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
  bool sendEventOnFailure = ((bool)  tolua_toboolean(tolua_S,4,true));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetResource'", NULL);
#endif
 {
  Resource* tolua_ret = (Resource*)  self->GetResource(type,name,sendEventOnFailure);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"Resource");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetResource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetExistingResource of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_GetExistingResource00
static int tolua_ResourceLuaAPI_ResourceCache_GetExistingResource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceCache",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetExistingResource'", NULL);
#endif
 {
  Resource* tolua_ret = (Resource*)  self->GetExistingResource(type,name);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"Resource");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetExistingResource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResourceCacheBackgroundLoadResource of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_BackgroundLoadResource00
static int tolua_ResourceLuaAPI_ResourceCache_BackgroundLoadResource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ResourceCache",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
  bool sendEventOnFailure = ((bool)  tolua_toboolean(tolua_S,4,true));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResourceCacheBackgroundLoadResource'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  ResourceCacheBackgroundLoadResource(self,type,name,sendEventOnFailure);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BackgroundLoadResource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumBackgroundLoadResources of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_GetNumBackgroundLoadResources00
static int tolua_ResourceLuaAPI_ResourceCache_GetNumBackgroundLoadResources00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceCache",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceCache* self = (const ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumBackgroundLoadResources'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumBackgroundLoadResources();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumBackgroundLoadResources'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetResourceDirs of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_GetResourceDirs00
static int tolua_ResourceLuaAPI_ResourceCache_GetResourceDirs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceCache",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceCache* self = (const ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetResourceDirs'", NULL);
#endif
 {
  const Vector<String>& tolua_ret = (const Vector<String>&)  self->GetResourceDirs();
  ToluaPushVector<String>(tolua_S,(void*)&tolua_ret,"String");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetResourceDirs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Exists of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_Exists00
static int tolua_ResourceLuaAPI_ResourceCache_Exists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceCache",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceCache* self = (const ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exists'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Exists(name);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exists'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMemoryBudget of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_GetMemoryBudget00
static int tolua_ResourceLuaAPI_ResourceCache_GetMemoryBudget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceCache",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceCache* self = (const ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  StringHash type = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMemoryBudget'", NULL);
#endif
 {
  unsigned long long tolua_ret = (unsigned long long)  self->GetMemoryBudget(type);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMemoryBudget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMemoryUse of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_GetMemoryUse00
static int tolua_ResourceLuaAPI_ResourceCache_GetMemoryUse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceCache",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceCache* self = (const ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  StringHash type = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMemoryUse'", NULL);
#endif
 {
  unsigned long long tolua_ret = (unsigned long long)  self->GetMemoryUse(type);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMemoryUse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTotalMemoryUse of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_GetTotalMemoryUse00
static int tolua_ResourceLuaAPI_ResourceCache_GetTotalMemoryUse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceCache",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceCache* self = (const ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTotalMemoryUse'", NULL);
#endif
 {
  unsigned long long tolua_ret = (unsigned long long)  self->GetTotalMemoryUse();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTotalMemoryUse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetResourceFileName of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_GetResourceFileName00
static int tolua_ResourceLuaAPI_ResourceCache_GetResourceFileName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceCache",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceCache* self = (const ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetResourceFileName'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetResourceFileName(name);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetResourceFileName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAutoReloadResources of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_GetAutoReloadResources00
static int tolua_ResourceLuaAPI_ResourceCache_GetAutoReloadResources00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceCache",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceCache* self = (const ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAutoReloadResources'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetAutoReloadResources();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAutoReloadResources'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetReturnFailedResources of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_GetReturnFailedResources00
static int tolua_ResourceLuaAPI_ResourceCache_GetReturnFailedResources00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceCache",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceCache* self = (const ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetReturnFailedResources'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetReturnFailedResources();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetReturnFailedResources'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSearchPackagesFirst of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_GetSearchPackagesFirst00
static int tolua_ResourceLuaAPI_ResourceCache_GetSearchPackagesFirst00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceCache",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceCache* self = (const ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSearchPackagesFirst'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetSearchPackagesFirst();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSearchPackagesFirst'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFinishBackgroundResourcesMs of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_GetFinishBackgroundResourcesMs00
static int tolua_ResourceLuaAPI_ResourceCache_GetFinishBackgroundResourcesMs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceCache",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceCache* self = (const ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFinishBackgroundResourcesMs'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetFinishBackgroundResourcesMs();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFinishBackgroundResourcesMs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPreferredResourceDir of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_GetPreferredResourceDir00
static int tolua_ResourceLuaAPI_ResourceCache_GetPreferredResourceDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceCache",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceCache* self = (const ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  const String path = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPreferredResourceDir'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetPreferredResourceDir(path);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPreferredResourceDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SanitateResourceName of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_SanitateResourceName00
static int tolua_ResourceLuaAPI_ResourceCache_SanitateResourceName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceCache",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceCache* self = (const ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SanitateResourceName'", NULL);
#endif
 {
  String tolua_ret = (String)  self->SanitateResourceName(name);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SanitateResourceName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SanitateResourceDirName of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_ResourceCache_SanitateResourceDirName00
static int tolua_ResourceLuaAPI_ResourceCache_SanitateResourceDirName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ResourceCache",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ResourceCache* self = (const ResourceCache*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SanitateResourceDirName'", NULL);
#endif
 {
  String tolua_ret = (String)  self->SanitateResourceDirName(name);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SanitateResourceDirName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: totalMemoryUse of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_get_ResourceCache_unsigned_totalMemoryUse
static int tolua_get_ResourceCache_unsigned_totalMemoryUse(lua_State* tolua_S)
{
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'totalMemoryUse'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTotalMemoryUse());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: autoReloadResources of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_get_ResourceCache_autoReloadResources
static int tolua_get_ResourceCache_autoReloadResources(lua_State* tolua_S)
{
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'autoReloadResources'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetAutoReloadResources());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: autoReloadResources of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_set_ResourceCache_autoReloadResources
static int tolua_set_ResourceCache_autoReloadResources(lua_State* tolua_S)
{
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'autoReloadResources'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAutoReloadResources(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: returnFailedResources of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_get_ResourceCache_returnFailedResources
static int tolua_get_ResourceCache_returnFailedResources(lua_State* tolua_S)
{
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'returnFailedResources'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetReturnFailedResources());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: returnFailedResources of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_set_ResourceCache_returnFailedResources
static int tolua_set_ResourceCache_returnFailedResources(lua_State* tolua_S)
{
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'returnFailedResources'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetReturnFailedResources(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: searchPackagesFirst of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_get_ResourceCache_searchPackagesFirst
static int tolua_get_ResourceCache_searchPackagesFirst(lua_State* tolua_S)
{
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'searchPackagesFirst'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetSearchPackagesFirst());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: searchPackagesFirst of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_set_ResourceCache_searchPackagesFirst
static int tolua_set_ResourceCache_searchPackagesFirst(lua_State* tolua_S)
{
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'searchPackagesFirst'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSearchPackagesFirst(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numBackgroundLoadResources of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_get_ResourceCache_numBackgroundLoadResources
static int tolua_get_ResourceCache_numBackgroundLoadResources(lua_State* tolua_S)
{
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numBackgroundLoadResources'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumBackgroundLoadResources());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: resourceDirs of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_get_ResourceCache_resourceDirs_ref
static int tolua_get_ResourceCache_resourceDirs_ref(lua_State* tolua_S)
{
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resourceDirs'",NULL);
#endif
  ToluaPushVector<String>(tolua_S,(void*)&self->GetResourceDirs(),"String");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: finishBackgroundResourcesMs of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_get_ResourceCache_finishBackgroundResourcesMs
static int tolua_get_ResourceCache_finishBackgroundResourcesMs(lua_State* tolua_S)
{
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'finishBackgroundResourcesMs'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFinishBackgroundResourcesMs());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: finishBackgroundResourcesMs of class  ResourceCache */
#ifndef TOLUA_DISABLE_tolua_set_ResourceCache_finishBackgroundResourcesMs
static int tolua_set_ResourceCache_finishBackgroundResourcesMs(lua_State* tolua_S)
{
  ResourceCache* self = (ResourceCache*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'finishBackgroundResourcesMs'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFinishBackgroundResourcesMs(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetCache */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_GetCache00
static int tolua_ResourceLuaAPI_GetCache00(lua_State* tolua_S)
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
  ResourceCache* tolua_ret = (ResourceCache*)  GetCache();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceCache");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCache'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cache */
#ifndef TOLUA_DISABLE_tolua_get_cache_ptr
static int tolua_get_cache_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetCache(),"ResourceCache");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumLanguages of class  Localization */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Localization_GetNumLanguages00
static int tolua_ResourceLuaAPI_Localization_GetNumLanguages00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Localization",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Localization* self = (const Localization*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumLanguages'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetNumLanguages();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumLanguages'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLanguageIndex of class  Localization */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Localization_GetLanguageIndex00
static int tolua_ResourceLuaAPI_Localization_GetLanguageIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Localization",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Localization* self = (const Localization*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLanguageIndex'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetLanguageIndex();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLanguageIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLanguageIndex of class  Localization */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Localization_GetLanguageIndex01
static int tolua_ResourceLuaAPI_Localization_GetLanguageIndex01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Localization",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Localization* self = (Localization*)  tolua_tousertype(tolua_S,1,0);
  const String language = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLanguageIndex'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetLanguageIndex(language);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_Localization_GetLanguageIndex00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLanguage of class  Localization */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Localization_GetLanguage00
static int tolua_ResourceLuaAPI_Localization_GetLanguage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Localization",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Localization* self = (Localization*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLanguage'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetLanguage();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLanguage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLanguage of class  Localization */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Localization_GetLanguage01
static int tolua_ResourceLuaAPI_Localization_GetLanguage01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Localization",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Localization* self = (Localization*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLanguage'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetLanguage(index);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_ResourceLuaAPI_Localization_GetLanguage00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLanguage of class  Localization */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Localization_SetLanguage00
static int tolua_ResourceLuaAPI_Localization_SetLanguage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Localization",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Localization* self = (Localization*)  tolua_tousertype(tolua_S,1,0);
  const String language = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLanguage'", NULL);
#endif
 {
  self->SetLanguage(language);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLanguage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLanguage of class  Localization */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Localization_SetLanguage01
static int tolua_ResourceLuaAPI_Localization_SetLanguage01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Localization",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Localization* self = (Localization*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLanguage'", NULL);
#endif
 {
  self->SetLanguage(index);
 }
 }
 return 0;
tolua_lerror:
 return tolua_ResourceLuaAPI_Localization_SetLanguage00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Get of class  Localization */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Localization_Get00
static int tolua_ResourceLuaAPI_Localization_Get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Localization",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Localization* self = (Localization*)  tolua_tousertype(tolua_S,1,0);
  const String id = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Get'", NULL);
#endif
 {
  String tolua_ret = (String)  self->Get(id);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
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

/* method: Reset of class  Localization */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Localization_Reset00
static int tolua_ResourceLuaAPI_Localization_Reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Localization",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Localization* self = (Localization*)  tolua_tousertype(tolua_S,1,0);
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

/* method: LoadJSON of class  Localization */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Localization_LoadJSON00
static int tolua_ResourceLuaAPI_Localization_LoadJSON00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Localization",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const JSONValue",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Localization* self = (Localization*)  tolua_tousertype(tolua_S,1,0);
  const JSONValue* source = ((const JSONValue*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadJSON'", NULL);
#endif
 {
  self->LoadJSON(*source);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadJSON'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadJSONFile of class  Localization */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_Localization_LoadJSONFile00
static int tolua_ResourceLuaAPI_Localization_LoadJSONFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Localization",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Localization* self = (Localization*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadJSONFile'", NULL);
#endif
 {
  self->LoadJSONFile(name);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadJSONFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numLanguages of class  Localization */
#ifndef TOLUA_DISABLE_tolua_get_Localization_numLanguages
static int tolua_get_Localization_numLanguages(lua_State* tolua_S)
{
  Localization* self = (Localization*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numLanguages'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumLanguages());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: languageIndex of class  Localization */
#ifndef TOLUA_DISABLE_tolua_get_Localization_languageIndex
static int tolua_get_Localization_languageIndex(lua_State* tolua_S)
{
  Localization* self = (Localization*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'languageIndex'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLanguageIndex());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: language of class  Localization */
#ifndef TOLUA_DISABLE_tolua_get_Localization_language
static int tolua_get_Localization_language(lua_State* tolua_S)
{
  Localization* self = (Localization*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'language'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetLanguage());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetLocalization */
#ifndef TOLUA_DISABLE_tolua_ResourceLuaAPI_GetLocalization00
static int tolua_ResourceLuaAPI_GetLocalization00(lua_State* tolua_S)
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
  Localization* tolua_ret = (Localization*)  GetLocalization();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Localization");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLocalization'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: localization */
#ifndef TOLUA_DISABLE_tolua_get_localization_ptr
static int tolua_get_localization_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetLocalization(),"Localization");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_ResourceLuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"Resource","Resource","",NULL);
 tolua_beginmodule(tolua_S,"Resource");
  tolua_function(tolua_S,"Load",tolua_ResourceLuaAPI_Resource_Load00);
  tolua_function(tolua_S,"Save",tolua_ResourceLuaAPI_Resource_Save00);
  tolua_function(tolua_S,"Load",tolua_ResourceLuaAPI_Resource_Load01);
  tolua_function(tolua_S,"Save",tolua_ResourceLuaAPI_Resource_Save01);
  tolua_function(tolua_S,"GetName",tolua_ResourceLuaAPI_Resource_GetName00);
  tolua_function(tolua_S,"GetNameHash",tolua_ResourceLuaAPI_Resource_GetNameHash00);
  tolua_function(tolua_S,"GetMemoryUse",tolua_ResourceLuaAPI_Resource_GetMemoryUse00);
  tolua_variable(tolua_S,"name",tolua_get_Resource_name,NULL);
  tolua_variable(tolua_S,"nameHash",tolua_get_Resource_nameHash,NULL);
  tolua_variable(tolua_S,"memoryUse",tolua_get_Resource_memoryUse,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"ResourceWithMetadata","ResourceWithMetadata","Resource",NULL);
 tolua_beginmodule(tolua_S,"ResourceWithMetadata");
  tolua_function(tolua_S,"AddMetadata",tolua_ResourceLuaAPI_ResourceWithMetadata_AddMetadata00);
  tolua_function(tolua_S,"RemoveMetadata",tolua_ResourceLuaAPI_ResourceWithMetadata_RemoveMetadata00);
  tolua_function(tolua_S,"RemoveAllMetadata",tolua_ResourceLuaAPI_ResourceWithMetadata_RemoveAllMetadata00);
  tolua_function(tolua_S,"GetMetadata",tolua_ResourceLuaAPI_ResourceWithMetadata_GetMetadata00);
  tolua_function(tolua_S,"HasMetadata",tolua_ResourceLuaAPI_ResourceWithMetadata_HasMetadata00);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"CF_NONE",CF_NONE);
 tolua_constant(tolua_S,"CF_RGBA",CF_RGBA);
 tolua_constant(tolua_S,"CF_DXT1",CF_DXT1);
 tolua_constant(tolua_S,"CF_DXT3",CF_DXT3);
 tolua_constant(tolua_S,"CF_DXT5",CF_DXT5);
 tolua_constant(tolua_S,"CF_ETC1",CF_ETC1);
 tolua_constant(tolua_S,"CF_PVRTC_RGB_2BPP",CF_PVRTC_RGB_2BPP);
 tolua_constant(tolua_S,"CF_PVRTC_RGBA_2BPP",CF_PVRTC_RGBA_2BPP);
 tolua_constant(tolua_S,"CF_PVRTC_RGB_4BPP",CF_PVRTC_RGB_4BPP);
 tolua_constant(tolua_S,"CF_PVRTC_RGBA_4BPP",CF_PVRTC_RGBA_4BPP);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Image","Image","Resource",tolua_collect_Image);
 #else
 tolua_cclass(tolua_S,"Image","Image","Resource",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Image");
  tolua_function(tolua_S,"new",tolua_ResourceLuaAPI_Image_new00);
  tolua_function(tolua_S,"new_local",tolua_ResourceLuaAPI_Image_new00_local);
  tolua_function(tolua_S,".call",tolua_ResourceLuaAPI_Image_new00_local);
  tolua_function(tolua_S,"delete",tolua_ResourceLuaAPI_Image_delete00);
  tolua_function(tolua_S,"SetSize",tolua_ResourceLuaAPI_Image_SetSize00);
  tolua_function(tolua_S,"SetSize",tolua_ResourceLuaAPI_Image_SetSize01);
  tolua_function(tolua_S,"SetPixel",tolua_ResourceLuaAPI_Image_SetPixel00);
  tolua_function(tolua_S,"SetPixel",tolua_ResourceLuaAPI_Image_SetPixel01);
  tolua_function(tolua_S,"SetPixelInt",tolua_ResourceLuaAPI_Image_SetPixelInt00);
  tolua_function(tolua_S,"SetPixelInt",tolua_ResourceLuaAPI_Image_SetPixelInt01);
  tolua_function(tolua_S,"LoadColorLUT",tolua_ResourceLuaAPI_Image_LoadColorLUT00);
  tolua_function(tolua_S,"LoadColorLUT",tolua_ResourceLuaAPI_Image_LoadColorLUT01);
  tolua_function(tolua_S,"FlipHorizontal",tolua_ResourceLuaAPI_Image_FlipHorizontal00);
  tolua_function(tolua_S,"FlipVertical",tolua_ResourceLuaAPI_Image_FlipVertical00);
  tolua_function(tolua_S,"Resize",tolua_ResourceLuaAPI_Image_Resize00);
  tolua_function(tolua_S,"Clear",tolua_ResourceLuaAPI_Image_Clear00);
  tolua_function(tolua_S,"ClearInt",tolua_ResourceLuaAPI_Image_ClearInt00);
  tolua_function(tolua_S,"SaveBMP",tolua_ResourceLuaAPI_Image_SaveBMP00);
  tolua_function(tolua_S,"SavePNG",tolua_ResourceLuaAPI_Image_SavePNG00);
  tolua_function(tolua_S,"SaveTGA",tolua_ResourceLuaAPI_Image_SaveTGA00);
  tolua_function(tolua_S,"SaveJPG",tolua_ResourceLuaAPI_Image_SaveJPG00);
  tolua_function(tolua_S,"SaveDDS",tolua_ResourceLuaAPI_Image_SaveDDS00);
  tolua_function(tolua_S,"SaveWEBP",tolua_ResourceLuaAPI_Image_SaveWEBP00);
  tolua_function(tolua_S,"GetPixel",tolua_ResourceLuaAPI_Image_GetPixel00);
  tolua_function(tolua_S,"GetPixel",tolua_ResourceLuaAPI_Image_GetPixel01);
  tolua_function(tolua_S,"GetPixelInt",tolua_ResourceLuaAPI_Image_GetPixelInt00);
  tolua_function(tolua_S,"GetPixelInt",tolua_ResourceLuaAPI_Image_GetPixelInt01);
  tolua_function(tolua_S,"GetPixelBilinear",tolua_ResourceLuaAPI_Image_GetPixelBilinear00);
  tolua_function(tolua_S,"GetPixelTrilinear",tolua_ResourceLuaAPI_Image_GetPixelTrilinear00);
  tolua_function(tolua_S,"GetWidth",tolua_ResourceLuaAPI_Image_GetWidth00);
  tolua_function(tolua_S,"GetHeight",tolua_ResourceLuaAPI_Image_GetHeight00);
  tolua_function(tolua_S,"GetDepth",tolua_ResourceLuaAPI_Image_GetDepth00);
  tolua_function(tolua_S,"GetComponents",tolua_ResourceLuaAPI_Image_GetComponents00);
  tolua_function(tolua_S,"IsCompressed",tolua_ResourceLuaAPI_Image_IsCompressed00);
  tolua_function(tolua_S,"GetCompressedFormat",tolua_ResourceLuaAPI_Image_GetCompressedFormat00);
  tolua_function(tolua_S,"GetNumCompressedLevels",tolua_ResourceLuaAPI_Image_GetNumCompressedLevels00);
  tolua_function(tolua_S,"GetSubimage",tolua_ResourceLuaAPI_Image_GetSubimage00);
  tolua_function(tolua_S,"SetSubimage",tolua_ResourceLuaAPI_Image_SetSubimage00);
  tolua_function(tolua_S,"IsCubemap",tolua_ResourceLuaAPI_Image_IsCubemap00);
  tolua_function(tolua_S,"IsArray",tolua_ResourceLuaAPI_Image_IsArray00);
  tolua_function(tolua_S,"IsSRGB",tolua_ResourceLuaAPI_Image_IsSRGB00);
  tolua_function(tolua_S,"HasAlphaChannel",tolua_ResourceLuaAPI_Image_HasAlphaChannel00);
  tolua_variable(tolua_S,"width",tolua_get_Image_width,NULL);
  tolua_variable(tolua_S,"height",tolua_get_Image_height,NULL);
  tolua_variable(tolua_S,"depth",tolua_get_Image_depth,NULL);
  tolua_variable(tolua_S,"components",tolua_get_Image_components,NULL);
  tolua_variable(tolua_S,"compressed",tolua_get_Image_compressed,NULL);
  tolua_variable(tolua_S,"compressedFormat",tolua_get_Image_compressedFormat,NULL);
  tolua_variable(tolua_S,"numCompressedLevels",tolua_get_Image_numCompressedLevels,NULL);
  tolua_variable(tolua_S,"cubemap",tolua_get_Image_cubemap,NULL);
  tolua_variable(tolua_S,"array",tolua_get_Image_array,NULL);
  tolua_variable(tolua_S,"sRGB",tolua_get_Image_sRGB,NULL);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"JSON_NULL",JSON_NULL);
 tolua_constant(tolua_S,"JSON_BOOL",JSON_BOOL);
 tolua_constant(tolua_S,"JSON_NUMBER",JSON_NUMBER);
 tolua_constant(tolua_S,"JSON_STRING",JSON_STRING);
 tolua_constant(tolua_S,"JSON_ARRAY",JSON_ARRAY);
 tolua_constant(tolua_S,"JSON_OBJECT",JSON_OBJECT);
 tolua_constant(tolua_S,"JSONNT_NAN",JSONNT_NAN);
 tolua_constant(tolua_S,"JSONNT_INT",JSONNT_INT);
 tolua_constant(tolua_S,"JSONNT_UINT",JSONNT_UINT);
 tolua_constant(tolua_S,"JSONNT_FLOAT_DOUBLE",JSONNT_FLOAT_DOUBLE);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"JSONValue","JSONValue","",tolua_collect_JSONValue);
 #else
 tolua_cclass(tolua_S,"JSONValue","JSONValue","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"JSONValue");
  tolua_function(tolua_S,"new",tolua_ResourceLuaAPI_JSONValue_new00);
  tolua_function(tolua_S,"new_local",tolua_ResourceLuaAPI_JSONValue_new00_local);
  tolua_function(tolua_S,".call",tolua_ResourceLuaAPI_JSONValue_new00_local);
  tolua_function(tolua_S,"new",tolua_ResourceLuaAPI_JSONValue_new01);
  tolua_function(tolua_S,"new_local",tolua_ResourceLuaAPI_JSONValue_new01_local);
  tolua_function(tolua_S,".call",tolua_ResourceLuaAPI_JSONValue_new01_local);
  tolua_function(tolua_S,"new",tolua_ResourceLuaAPI_JSONValue_new02);
  tolua_function(tolua_S,"new_local",tolua_ResourceLuaAPI_JSONValue_new02_local);
  tolua_function(tolua_S,".call",tolua_ResourceLuaAPI_JSONValue_new02_local);
  tolua_function(tolua_S,"new",tolua_ResourceLuaAPI_JSONValue_new03);
  tolua_function(tolua_S,"new_local",tolua_ResourceLuaAPI_JSONValue_new03_local);
  tolua_function(tolua_S,".call",tolua_ResourceLuaAPI_JSONValue_new03_local);
  tolua_function(tolua_S,"new",tolua_ResourceLuaAPI_JSONValue_new04);
  tolua_function(tolua_S,"new_local",tolua_ResourceLuaAPI_JSONValue_new04_local);
  tolua_function(tolua_S,".call",tolua_ResourceLuaAPI_JSONValue_new04_local);
  tolua_function(tolua_S,"new",tolua_ResourceLuaAPI_JSONValue_new05);
  tolua_function(tolua_S,"new_local",tolua_ResourceLuaAPI_JSONValue_new05_local);
  tolua_function(tolua_S,".call",tolua_ResourceLuaAPI_JSONValue_new05_local);
  tolua_function(tolua_S,"new",tolua_ResourceLuaAPI_JSONValue_new06);
  tolua_function(tolua_S,"new_local",tolua_ResourceLuaAPI_JSONValue_new06_local);
  tolua_function(tolua_S,".call",tolua_ResourceLuaAPI_JSONValue_new06_local);
  tolua_function(tolua_S,"delete",tolua_ResourceLuaAPI_JSONValue_delete00);
  tolua_function(tolua_S,"SetBool",tolua_ResourceLuaAPI_JSONValue_SetBool00);
  tolua_function(tolua_S,"SetInt",tolua_ResourceLuaAPI_JSONValue_SetInt00);
  tolua_function(tolua_S,"SetUint",tolua_ResourceLuaAPI_JSONValue_SetUint00);
  tolua_function(tolua_S,"SetFloat",tolua_ResourceLuaAPI_JSONValue_SetFloat00);
  tolua_function(tolua_S,"SetDouble",tolua_ResourceLuaAPI_JSONValue_SetDouble00);
  tolua_function(tolua_S,"SetString",tolua_ResourceLuaAPI_JSONValue_SetString00);
  tolua_function(tolua_S,"SetArray",tolua_ResourceLuaAPI_JSONValue_SetArray00);
  tolua_function(tolua_S,"SetObject",tolua_ResourceLuaAPI_JSONValue_SetObject00);
  tolua_function(tolua_S,"SetVariant",tolua_ResourceLuaAPI_JSONValue_SetVariant00);
  tolua_function(tolua_S,"SetVariantMap",tolua_ResourceLuaAPI_JSONValue_SetVariantMap00);
  tolua_function(tolua_S,"GetValueType",tolua_ResourceLuaAPI_JSONValue_GetValueType00);
  tolua_function(tolua_S,"GetNumberType",tolua_ResourceLuaAPI_JSONValue_GetNumberType00);
  tolua_function(tolua_S,"GetValueTypeName",tolua_ResourceLuaAPI_JSONValue_GetValueTypeName00);
  tolua_function(tolua_S,"GetNumberTypeName",tolua_ResourceLuaAPI_JSONValue_GetNumberTypeName00);
  tolua_function(tolua_S,"IsNull",tolua_ResourceLuaAPI_JSONValue_IsNull00);
  tolua_function(tolua_S,"IsBool",tolua_ResourceLuaAPI_JSONValue_IsBool00);
  tolua_function(tolua_S,"IsNumber",tolua_ResourceLuaAPI_JSONValue_IsNumber00);
  tolua_function(tolua_S,"IsString",tolua_ResourceLuaAPI_JSONValue_IsString00);
  tolua_function(tolua_S,"IsArray",tolua_ResourceLuaAPI_JSONValue_IsArray00);
  tolua_function(tolua_S,"IsObject",tolua_ResourceLuaAPI_JSONValue_IsObject00);
  tolua_function(tolua_S,"GetBool",tolua_ResourceLuaAPI_JSONValue_GetBool00);
  tolua_function(tolua_S,"GetInt",tolua_ResourceLuaAPI_JSONValue_GetInt00);
  tolua_function(tolua_S,"GetUInt",tolua_ResourceLuaAPI_JSONValue_GetUInt00);
  tolua_function(tolua_S,"GetFloat",tolua_ResourceLuaAPI_JSONValue_GetFloat00);
  tolua_function(tolua_S,"GetDouble",tolua_ResourceLuaAPI_JSONValue_GetDouble00);
  tolua_function(tolua_S,"GetString",tolua_ResourceLuaAPI_JSONValue_GetString00);
  tolua_function(tolua_S,"GetArray",tolua_ResourceLuaAPI_JSONValue_GetArray00);
  tolua_function(tolua_S,"GetObject",tolua_ResourceLuaAPI_JSONValue_GetObject00);
  tolua_function(tolua_S,"GetVariant",tolua_ResourceLuaAPI_JSONValue_GetVariant00);
  tolua_function(tolua_S,"GetVariantMap",tolua_ResourceLuaAPI_JSONValue_GetVariantMap00);
  tolua_function(tolua_S,".seti",tolua_ResourceLuaAPI_JSONValue__seti00);
  tolua_function(tolua_S,".geti",tolua_ResourceLuaAPI_JSONValue__geti00);
  tolua_function(tolua_S,".geti",tolua_ResourceLuaAPI_JSONValue__geti01);
  tolua_function(tolua_S,"Push",tolua_ResourceLuaAPI_JSONValue_Push00);
  tolua_function(tolua_S,"Pop",tolua_ResourceLuaAPI_JSONValue_Pop00);
  tolua_function(tolua_S,"Insert",tolua_ResourceLuaAPI_JSONValue_Insert00);
  tolua_function(tolua_S,"Erase",tolua_ResourceLuaAPI_JSONValue_Erase00);
  tolua_function(tolua_S,"Resize",tolua_ResourceLuaAPI_JSONValue_Resize00);
  tolua_function(tolua_S,"Size",tolua_ResourceLuaAPI_JSONValue_Size00);
  tolua_function(tolua_S,"Set",tolua_ResourceLuaAPI_JSONValue_Set00);
  tolua_function(tolua_S,"Get",tolua_ResourceLuaAPI_JSONValue_Get00);
  tolua_function(tolua_S,"Erase",tolua_ResourceLuaAPI_JSONValue_Erase01);
  tolua_function(tolua_S,"Contains",tolua_ResourceLuaAPI_JSONValue_Contains00);
  tolua_function(tolua_S,"Clear",tolua_ResourceLuaAPI_JSONValue_Clear00);
  tolua_variable(tolua_S,"EMPTY",tolua_get_JSONValue_EMPTY,NULL);
  tolua_variable(tolua_S,"emptyArray",tolua_get_JSONValue_emptyArray,NULL);
  tolua_variable(tolua_S,"emptyObject",tolua_get_JSONValue_emptyObject,NULL);
  tolua_variable(tolua_S,"null",tolua_get_JSONValue_null,NULL);
  tolua_variable(tolua_S,"valueType",tolua_get_JSONValue_valueType,NULL);
  tolua_variable(tolua_S,"numberType",tolua_get_JSONValue_numberType,NULL);
  tolua_variable(tolua_S,"valueTypeName",tolua_get_JSONValue_valueTypeName,NULL);
  tolua_variable(tolua_S,"numberTypeName",tolua_get_JSONValue_numberTypeName,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"JSONFile","JSONFile","Resource",tolua_collect_JSONFile);
 #else
 tolua_cclass(tolua_S,"JSONFile","JSONFile","Resource",NULL);
 #endif
 tolua_beginmodule(tolua_S,"JSONFile");
  tolua_function(tolua_S,"new",tolua_ResourceLuaAPI_JSONFile_new00);
  tolua_function(tolua_S,"new_local",tolua_ResourceLuaAPI_JSONFile_new00_local);
  tolua_function(tolua_S,".call",tolua_ResourceLuaAPI_JSONFile_new00_local);
  tolua_function(tolua_S,"delete",tolua_ResourceLuaAPI_JSONFile_delete00);
  tolua_function(tolua_S,"FromString",tolua_ResourceLuaAPI_JSONFile_FromString00);
  tolua_function(tolua_S,"GetRoot",tolua_ResourceLuaAPI_JSONFile_GetRoot00);
  tolua_function(tolua_S,"Save",tolua_ResourceLuaAPI_JSONFile_Save00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"XMLElement","XMLElement","",tolua_collect_XMLElement);
 #else
 tolua_cclass(tolua_S,"XMLElement","XMLElement","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"XMLElement");
  tolua_function(tolua_S,"AppendChild",tolua_ResourceLuaAPI_XMLElement_AppendChild00);
  tolua_function(tolua_S,"CreateChild",tolua_ResourceLuaAPI_XMLElement_CreateChild00);
  tolua_function(tolua_S,"GetOrCreateChild",tolua_ResourceLuaAPI_XMLElement_GetOrCreateChild00);
  tolua_function(tolua_S,"RemoveChild",tolua_ResourceLuaAPI_XMLElement_RemoveChild00);
  tolua_function(tolua_S,"RemoveChild",tolua_ResourceLuaAPI_XMLElement_RemoveChild01);
  tolua_function(tolua_S,"RemoveChildren",tolua_ResourceLuaAPI_XMLElement_RemoveChildren00);
  tolua_function(tolua_S,"RemoveAttribute",tolua_ResourceLuaAPI_XMLElement_RemoveAttribute00);
  tolua_function(tolua_S,"Remove",tolua_ResourceLuaAPI_XMLElement_Remove00);
  tolua_function(tolua_S,"SetValue",tolua_ResourceLuaAPI_XMLElement_SetValue00);
  tolua_function(tolua_S,"SetAttribute",tolua_ResourceLuaAPI_XMLElement_SetAttribute00);
  tolua_function(tolua_S,"SetAttribute",tolua_ResourceLuaAPI_XMLElement_SetAttribute01);
  tolua_function(tolua_S,"SetBool",tolua_ResourceLuaAPI_XMLElement_SetBool00);
  tolua_function(tolua_S,"SetBoundingBox",tolua_ResourceLuaAPI_XMLElement_SetBoundingBox00);
  tolua_function(tolua_S,"SetColor",tolua_ResourceLuaAPI_XMLElement_SetColor00);
  tolua_function(tolua_S,"SetFloat",tolua_ResourceLuaAPI_XMLElement_SetFloat00);
  tolua_function(tolua_S,"SetDouble",tolua_ResourceLuaAPI_XMLElement_SetDouble00);
  tolua_function(tolua_S,"SetUInt",tolua_ResourceLuaAPI_XMLElement_SetUInt00);
  tolua_function(tolua_S,"SetInt",tolua_ResourceLuaAPI_XMLElement_SetInt00);
  tolua_function(tolua_S,"SetUInt64",tolua_ResourceLuaAPI_XMLElement_SetUInt6400);
  tolua_function(tolua_S,"SetInt64",tolua_ResourceLuaAPI_XMLElement_SetInt6400);
  tolua_function(tolua_S,"SetIntRect",tolua_ResourceLuaAPI_XMLElement_SetIntRect00);
  tolua_function(tolua_S,"SetIntVector2",tolua_ResourceLuaAPI_XMLElement_SetIntVector200);
  tolua_function(tolua_S,"SetIntVector3",tolua_ResourceLuaAPI_XMLElement_SetIntVector300);
  tolua_function(tolua_S,"SetRect",tolua_ResourceLuaAPI_XMLElement_SetRect00);
  tolua_function(tolua_S,"SetQuaternion",tolua_ResourceLuaAPI_XMLElement_SetQuaternion00);
  tolua_function(tolua_S,"SetString",tolua_ResourceLuaAPI_XMLElement_SetString00);
  tolua_function(tolua_S,"SetVariant",tolua_ResourceLuaAPI_XMLElement_SetVariant00);
  tolua_function(tolua_S,"SetVariantValue",tolua_ResourceLuaAPI_XMLElement_SetVariantValue00);
  tolua_function(tolua_S,"SetResourceRef",tolua_ResourceLuaAPI_XMLElement_SetResourceRef00);
  tolua_function(tolua_S,"SetResourceRefList",tolua_ResourceLuaAPI_XMLElement_SetResourceRefList00);
  tolua_function(tolua_S,"SetVector2",tolua_ResourceLuaAPI_XMLElement_SetVector200);
  tolua_function(tolua_S,"SetVector3",tolua_ResourceLuaAPI_XMLElement_SetVector300);
  tolua_function(tolua_S,"SetVector4",tolua_ResourceLuaAPI_XMLElement_SetVector400);
  tolua_function(tolua_S,"SetVectorVariant",tolua_ResourceLuaAPI_XMLElement_SetVectorVariant00);
  tolua_function(tolua_S,"SetMatrix3",tolua_ResourceLuaAPI_XMLElement_SetMatrix300);
  tolua_function(tolua_S,"SetMatrix3x4",tolua_ResourceLuaAPI_XMLElement_SetMatrix3x400);
  tolua_function(tolua_S,"SetMatrix4",tolua_ResourceLuaAPI_XMLElement_SetMatrix400);
  tolua_function(tolua_S,"IsNull",tolua_ResourceLuaAPI_XMLElement_IsNull00);
  tolua_function(tolua_S,"NotNull",tolua_ResourceLuaAPI_XMLElement_NotNull00);
  tolua_function(tolua_S,".bool",tolua_ResourceLuaAPI_XMLElement__bool00);
  tolua_function(tolua_S,"GetName",tolua_ResourceLuaAPI_XMLElement_GetName00);
  tolua_function(tolua_S,"HasChild",tolua_ResourceLuaAPI_XMLElement_HasChild00);
  tolua_function(tolua_S,"GetChild",tolua_ResourceLuaAPI_XMLElement_GetChild00);
  tolua_function(tolua_S,"GetNext",tolua_ResourceLuaAPI_XMLElement_GetNext00);
  tolua_function(tolua_S,"GetParent",tolua_ResourceLuaAPI_XMLElement_GetParent00);
  tolua_function(tolua_S,"GetNumAttributes",tolua_ResourceLuaAPI_XMLElement_GetNumAttributes00);
  tolua_function(tolua_S,"HasAttribute",tolua_ResourceLuaAPI_XMLElement_HasAttribute00);
  tolua_function(tolua_S,"GetValue",tolua_ResourceLuaAPI_XMLElement_GetValue00);
  tolua_function(tolua_S,"GetAttribute",tolua_ResourceLuaAPI_XMLElement_GetAttribute00);
  tolua_function(tolua_S,"GetAttributeLower",tolua_ResourceLuaAPI_XMLElement_GetAttributeLower00);
  tolua_function(tolua_S,"GetAttributeUpper",tolua_ResourceLuaAPI_XMLElement_GetAttributeUpper00);
  tolua_function(tolua_S,"GetAttributeNames",tolua_ResourceLuaAPI_XMLElement_GetAttributeNames00);
  tolua_function(tolua_S,"GetBool",tolua_ResourceLuaAPI_XMLElement_GetBool00);
  tolua_function(tolua_S,"GetBoundingBox",tolua_ResourceLuaAPI_XMLElement_GetBoundingBox00);
  tolua_function(tolua_S,"GetColor",tolua_ResourceLuaAPI_XMLElement_GetColor00);
  tolua_function(tolua_S,"GetFloat",tolua_ResourceLuaAPI_XMLElement_GetFloat00);
  tolua_function(tolua_S,"GetDouble",tolua_ResourceLuaAPI_XMLElement_GetDouble00);
  tolua_function(tolua_S,"GetUInt",tolua_ResourceLuaAPI_XMLElement_GetUInt00);
  tolua_function(tolua_S,"GetInt",tolua_ResourceLuaAPI_XMLElement_GetInt00);
  tolua_function(tolua_S,"GetUInt64",tolua_ResourceLuaAPI_XMLElement_GetUInt6400);
  tolua_function(tolua_S,"GetInt64",tolua_ResourceLuaAPI_XMLElement_GetInt6400);
  tolua_function(tolua_S,"GetIntRect",tolua_ResourceLuaAPI_XMLElement_GetIntRect00);
  tolua_function(tolua_S,"GetIntVector2",tolua_ResourceLuaAPI_XMLElement_GetIntVector200);
  tolua_function(tolua_S,"GetIntVector3",tolua_ResourceLuaAPI_XMLElement_GetIntVector300);
  tolua_function(tolua_S,"GetRect",tolua_ResourceLuaAPI_XMLElement_GetRect00);
  tolua_function(tolua_S,"GetQuaternion",tolua_ResourceLuaAPI_XMLElement_GetQuaternion00);
  tolua_function(tolua_S,"GetVariant",tolua_ResourceLuaAPI_XMLElement_GetVariant00);
  tolua_function(tolua_S,"GetVariantValue",tolua_ResourceLuaAPI_XMLElement_GetVariantValue00);
  tolua_function(tolua_S,"GetResourceRef",tolua_ResourceLuaAPI_XMLElement_GetResourceRef00);
  tolua_function(tolua_S,"GetResourceRefList",tolua_ResourceLuaAPI_XMLElement_GetResourceRefList00);
  tolua_function(tolua_S,"GetVariantMap",tolua_ResourceLuaAPI_XMLElement_GetVariantMap00);
  tolua_function(tolua_S,"GetVector2",tolua_ResourceLuaAPI_XMLElement_GetVector200);
  tolua_function(tolua_S,"GetVector3",tolua_ResourceLuaAPI_XMLElement_GetVector300);
  tolua_function(tolua_S,"GetVector4",tolua_ResourceLuaAPI_XMLElement_GetVector400);
  tolua_function(tolua_S,"GetVector",tolua_ResourceLuaAPI_XMLElement_GetVector00);
  tolua_function(tolua_S,"GetMatrix3",tolua_ResourceLuaAPI_XMLElement_GetMatrix300);
  tolua_function(tolua_S,"GetMatrix3x4",tolua_ResourceLuaAPI_XMLElement_GetMatrix3x400);
  tolua_function(tolua_S,"GetMatrix4",tolua_ResourceLuaAPI_XMLElement_GetMatrix400);
  tolua_function(tolua_S,"GetFile",tolua_ResourceLuaAPI_XMLElement_GetFile00);
  tolua_variable(tolua_S,"EMPTY",tolua_get_XMLElement_EMPTY,NULL);
  tolua_variable(tolua_S,"null",tolua_get_XMLElement_null,NULL);
  tolua_variable(tolua_S,"name",tolua_get_XMLElement_name,NULL);
  tolua_variable(tolua_S,"parent",tolua_get_XMLElement_parent,NULL);
  tolua_variable(tolua_S,"value",tolua_get_XMLElement_value,NULL);
  tolua_variable(tolua_S,"numAttributes",tolua_get_XMLElement_numAttributes,NULL);
  tolua_variable(tolua_S,"file",tolua_get_XMLElement_file_ptr,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"XMLFile","XMLFile","Resource",tolua_collect_XMLFile);
 #else
 tolua_cclass(tolua_S,"XMLFile","XMLFile","Resource",NULL);
 #endif
 tolua_beginmodule(tolua_S,"XMLFile");
  tolua_function(tolua_S,"new",tolua_ResourceLuaAPI_XMLFile_new00);
  tolua_function(tolua_S,"new_local",tolua_ResourceLuaAPI_XMLFile_new00_local);
  tolua_function(tolua_S,".call",tolua_ResourceLuaAPI_XMLFile_new00_local);
  tolua_function(tolua_S,"delete",tolua_ResourceLuaAPI_XMLFile_delete00);
  tolua_function(tolua_S,"FromString",tolua_ResourceLuaAPI_XMLFile_FromString00);
  tolua_function(tolua_S,"CreateRoot",tolua_ResourceLuaAPI_XMLFile_CreateRoot00);
  tolua_function(tolua_S,"GetOrCreateRoot",tolua_ResourceLuaAPI_XMLFile_GetOrCreateRoot00);
  tolua_function(tolua_S,"GetRoot",tolua_ResourceLuaAPI_XMLFile_GetRoot00);
  tolua_function(tolua_S,"ToString",tolua_ResourceLuaAPI_XMLFile_ToString00);
  tolua_function(tolua_S,"Patch",tolua_ResourceLuaAPI_XMLFile_Patch00);
  tolua_function(tolua_S,"Patch",tolua_ResourceLuaAPI_XMLFile_Patch01);
  tolua_function(tolua_S,"Save",tolua_ResourceLuaAPI_XMLFile_Save00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"ResourceCache","ResourceCache","",NULL);
 tolua_beginmodule(tolua_S,"ResourceCache");
  tolua_function(tolua_S,"ReleaseAllResources",tolua_ResourceLuaAPI_ResourceCache_ReleaseAllResources00);
  tolua_function(tolua_S,"ReloadResource",tolua_ResourceLuaAPI_ResourceCache_ReloadResource00);
  tolua_function(tolua_S,"ReloadResourceWithDependencies",tolua_ResourceLuaAPI_ResourceCache_ReloadResourceWithDependencies00);
  tolua_function(tolua_S,"SetMemoryBudget",tolua_ResourceLuaAPI_ResourceCache_SetMemoryBudget00);
  tolua_function(tolua_S,"SetMemoryBudget",tolua_ResourceLuaAPI_ResourceCache_SetMemoryBudget01);
  tolua_function(tolua_S,"SetAutoReloadResources",tolua_ResourceLuaAPI_ResourceCache_SetAutoReloadResources00);
  tolua_function(tolua_S,"SetReturnFailedResources",tolua_ResourceLuaAPI_ResourceCache_SetReturnFailedResources00);
  tolua_function(tolua_S,"SetSearchPackagesFirst",tolua_ResourceLuaAPI_ResourceCache_SetSearchPackagesFirst00);
  tolua_function(tolua_S,"SetFinishBackgroundResourcesMs",tolua_ResourceLuaAPI_ResourceCache_SetFinishBackgroundResourcesMs00);
  tolua_function(tolua_S,"GetFile",tolua_ResourceLuaAPI_ResourceCache_GetFile00);
  tolua_function(tolua_S,"GetResource",tolua_ResourceLuaAPI_ResourceCache_GetResource00);
  tolua_function(tolua_S,"GetExistingResource",tolua_ResourceLuaAPI_ResourceCache_GetExistingResource00);
  tolua_function(tolua_S,"BackgroundLoadResource",tolua_ResourceLuaAPI_ResourceCache_BackgroundLoadResource00);
  tolua_function(tolua_S,"GetNumBackgroundLoadResources",tolua_ResourceLuaAPI_ResourceCache_GetNumBackgroundLoadResources00);
  tolua_function(tolua_S,"GetResourceDirs",tolua_ResourceLuaAPI_ResourceCache_GetResourceDirs00);
  tolua_function(tolua_S,"Exists",tolua_ResourceLuaAPI_ResourceCache_Exists00);
  tolua_function(tolua_S,"GetMemoryBudget",tolua_ResourceLuaAPI_ResourceCache_GetMemoryBudget00);
  tolua_function(tolua_S,"GetMemoryUse",tolua_ResourceLuaAPI_ResourceCache_GetMemoryUse00);
  tolua_function(tolua_S,"GetTotalMemoryUse",tolua_ResourceLuaAPI_ResourceCache_GetTotalMemoryUse00);
  tolua_function(tolua_S,"GetResourceFileName",tolua_ResourceLuaAPI_ResourceCache_GetResourceFileName00);
  tolua_function(tolua_S,"GetAutoReloadResources",tolua_ResourceLuaAPI_ResourceCache_GetAutoReloadResources00);
  tolua_function(tolua_S,"GetReturnFailedResources",tolua_ResourceLuaAPI_ResourceCache_GetReturnFailedResources00);
  tolua_function(tolua_S,"GetSearchPackagesFirst",tolua_ResourceLuaAPI_ResourceCache_GetSearchPackagesFirst00);
  tolua_function(tolua_S,"GetFinishBackgroundResourcesMs",tolua_ResourceLuaAPI_ResourceCache_GetFinishBackgroundResourcesMs00);
  tolua_function(tolua_S,"GetPreferredResourceDir",tolua_ResourceLuaAPI_ResourceCache_GetPreferredResourceDir00);
  tolua_function(tolua_S,"SanitateResourceName",tolua_ResourceLuaAPI_ResourceCache_SanitateResourceName00);
  tolua_function(tolua_S,"SanitateResourceDirName",tolua_ResourceLuaAPI_ResourceCache_SanitateResourceDirName00);
  tolua_variable(tolua_S,"totalMemoryUse",tolua_get_ResourceCache_unsigned_totalMemoryUse,NULL);
  tolua_variable(tolua_S,"autoReloadResources",tolua_get_ResourceCache_autoReloadResources,tolua_set_ResourceCache_autoReloadResources);
  tolua_variable(tolua_S,"returnFailedResources",tolua_get_ResourceCache_returnFailedResources,tolua_set_ResourceCache_returnFailedResources);
  tolua_variable(tolua_S,"searchPackagesFirst",tolua_get_ResourceCache_searchPackagesFirst,tolua_set_ResourceCache_searchPackagesFirst);
  tolua_variable(tolua_S,"numBackgroundLoadResources",tolua_get_ResourceCache_numBackgroundLoadResources,NULL);
  tolua_variable(tolua_S,"resourceDirs",tolua_get_ResourceCache_resourceDirs_ref,NULL);
  tolua_variable(tolua_S,"finishBackgroundResourcesMs",tolua_get_ResourceCache_finishBackgroundResourcesMs,tolua_set_ResourceCache_finishBackgroundResourcesMs);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"GetCache",tolua_ResourceLuaAPI_GetCache00);
 tolua_variable(tolua_S,"cache",tolua_get_cache_ptr,NULL);
 tolua_cclass(tolua_S,"Localization","Localization","Object",NULL);
 tolua_beginmodule(tolua_S,"Localization");
  tolua_function(tolua_S,"GetNumLanguages",tolua_ResourceLuaAPI_Localization_GetNumLanguages00);
  tolua_function(tolua_S,"GetLanguageIndex",tolua_ResourceLuaAPI_Localization_GetLanguageIndex00);
  tolua_function(tolua_S,"GetLanguageIndex",tolua_ResourceLuaAPI_Localization_GetLanguageIndex01);
  tolua_function(tolua_S,"GetLanguage",tolua_ResourceLuaAPI_Localization_GetLanguage00);
  tolua_function(tolua_S,"GetLanguage",tolua_ResourceLuaAPI_Localization_GetLanguage01);
  tolua_function(tolua_S,"SetLanguage",tolua_ResourceLuaAPI_Localization_SetLanguage00);
  tolua_function(tolua_S,"SetLanguage",tolua_ResourceLuaAPI_Localization_SetLanguage01);
  tolua_function(tolua_S,"Get",tolua_ResourceLuaAPI_Localization_Get00);
  tolua_function(tolua_S,"Reset",tolua_ResourceLuaAPI_Localization_Reset00);
  tolua_function(tolua_S,"LoadJSON",tolua_ResourceLuaAPI_Localization_LoadJSON00);
  tolua_function(tolua_S,"LoadJSONFile",tolua_ResourceLuaAPI_Localization_LoadJSONFile00);
  tolua_variable(tolua_S,"numLanguages",tolua_get_Localization_numLanguages,NULL);
  tolua_variable(tolua_S,"languageIndex",tolua_get_Localization_languageIndex,NULL);
  tolua_variable(tolua_S,"language",tolua_get_Localization_language,NULL);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"GetLocalization",tolua_ResourceLuaAPI_GetLocalization00);
 tolua_variable(tolua_S,"localization",tolua_get_localization_ptr,NULL);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_ResourceLuaAPI (lua_State* tolua_S) {
 return tolua_ResourceLuaAPI_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif