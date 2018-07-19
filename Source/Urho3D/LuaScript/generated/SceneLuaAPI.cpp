/*
** Lua binding: SceneLuaAPI
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
TOLUA_API int tolua_SceneLuaAPI_open (lua_State* tolua_S);

#include "Scene/ValueAnimation.h"
#include "Scene/ObjectAnimation.h"
#include "Scene/Serializable.h"
#include "Scene/Animatable.h"
#include "Scene/Component.h"
#include "IO/File.h"
#include "LuaScript/LuaFile.h"
#include "LuaScript/LuaScriptInstance.h"
#include "Scene/Node.h"
#include "Resource/ResourceCache.h"
#include "Scene/Scene.h"
#include "Scene/SplinePath.h"
using namespace Urho3D;
#pragma warning(disable:4800)

#define TOLUA_DISABLE_tolua_SceneLuaAPI_ValueAnimation_new00
static int tolua_SceneLuaAPI_ValueAnimation_new00(lua_State* tolua_S)
{
    return ToluaNewObject<ValueAnimation>(tolua_S);
}

#define TOLUA_DISABLE_tolua_SceneLuaAPI_ValueAnimation_new00_local
static int tolua_SceneLuaAPI_ValueAnimation_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<ValueAnimation>(tolua_S);
}

#define TOLUA_DISABLE_tolua_SceneLuaAPI_ObjectAnimation_new00
static int tolua_SceneLuaAPI_ObjectAnimation_new00(lua_State* tolua_S)
{
    return ToluaNewObject<ObjectAnimation>(tolua_S);
}

#define TOLUA_DISABLE_tolua_SceneLuaAPI_ObjectAnimation_new00_local
static int tolua_SceneLuaAPI_ObjectAnimation_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<ObjectAnimation>(tolua_S);
}

#define TOLUA_DISABLE_tolua_SceneLuaAPI_Node_new00
static int tolua_SceneLuaAPI_Node_new00(lua_State* tolua_S)
{
    return ToluaNewObject<Node>(tolua_S);
}

#define TOLUA_DISABLE_tolua_SceneLuaAPI_Node_new00_local
static int tolua_SceneLuaAPI_Node_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<Node>(tolua_S);
}

static bool NodeSaveXML(const Node* node, File* file, const String& indentation)
{
    return file ? node->SaveXML(*file, indentation) : false;
}

static bool NodeSaveJSON(const Node* node, File* file, const String& indentation)
{
    return file ? node->SaveJSON(*file, indentation) : false;
}

#define TOLUA_DISABLE_tolua_SceneLuaAPI_Node_CreateScriptObject00

static int tolua_SceneLuaAPI_Node_CreateScriptObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String scriptObjectType = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NodeCreateScriptObject'", NULL);
#endif
 {
  LuaScriptInstance* instance = self->CreateComponent<LuaScriptInstance>();
  if (!instance)
    lua_pushnil(tolua_S);
  else
  {
    instance->CreateObject(scriptObjectType);
    // Push script object to Lua stack.
    lua_rawgeti(tolua_S, LUA_REGISTRYINDEX, instance->GetScriptObjectRef());
  }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateScriptObject'.",&tolua_err);
 return 0;
#endif
}

#define TOLUA_DISABLE_tolua_SceneLuaAPI_Node_CreateScriptObject01

static int tolua_SceneLuaAPI_Node_CreateScriptObject01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String scriptObjectType = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NodeCreateScriptObject'", NULL);
#endif
 {
  ResourceCache* cache = self->GetSubsystem<ResourceCache>();
  LuaFile* scriptFile = cache->GetResource<LuaFile>(fileName);
  if (!scriptFile)
  {
    lua_pushnil(tolua_S);
    return 1;
  }

  LuaScriptInstance* instance = self->CreateComponent<LuaScriptInstance>();
  if (!instance)
    lua_pushnil(tolua_S);
  else
  {
    instance->CreateObject(scriptFile, scriptObjectType);
    // Push script object to Lua stack.
    lua_rawgeti(tolua_S, LUA_REGISTRYINDEX, instance->GetScriptObjectRef());
  }
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_CreateScriptObject00(tolua_S);
}

#define TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetScriptObject00
static int tolua_SceneLuaAPI_Node_GetScriptObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScriptObject'", NULL);
#endif
 {
  LuaScriptInstance* instance = self->GetComponent<LuaScriptInstance>();
  if (!instance)
    lua_pushnil(tolua_S);
  else
    lua_rawgeti(tolua_S, LUA_REGISTRYINDEX, instance->GetScriptObjectRef());
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScriptObject'.",&tolua_err);
 return 0;
#endif
}

#define TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetScriptObject01
static int tolua_SceneLuaAPI_Node_GetScriptObject01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  const String scriptObjectType = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScriptObject'", NULL);
#endif
 {
 int scriptObjectRef = LUA_REFNIL;

 PODVector<LuaScriptInstance*> instances;
 self->GetComponents<LuaScriptInstance>(instances, false);

 for (unsigned i = 0; i < instances.Size(); ++i)
 {
  if (instances[i]->GetScriptObjectType() == scriptObjectType)
  {
    scriptObjectRef = instances[i]->GetScriptObjectRef();
    break;
  }
 }

 if (scriptObjectRef == LUA_REFNIL)
  lua_pushnil(tolua_S);
 else
  lua_rawgeti(tolua_S, LUA_REGISTRYINDEX, scriptObjectRef);
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_GetScriptObject00(tolua_S);
}

static const PODVector<Component*>& NodeGetComponentsWithType(Node* node, String type, bool recursive)
{
    static PODVector<Component*> result;
    result.Clear();
    node->GetComponents(result, type, recursive);
    return result;
}

static const PODVector<Node*>& NodeGetChildren(Node* node, bool recursive)
{
    static PODVector<Node*> result;
    result.Clear();
    node->GetChildren(result, recursive);
    return result;
}

static const PODVector<Node*>& NodeGetChildrenWithComponent(Node* node, String type, bool recursive)
{
    static PODVector<Node*> result;
    result.Clear();
    node->GetChildrenWithComponent(result, type, recursive);
    return result;
}

static const PODVector<Node*>& NodeGetChildrenWithTag(const Node* node, const String& tag, bool recursive)
{
    static PODVector<Node*> result;
    result.Clear();
    node->GetChildrenWithTag(result, tag, recursive);
    return result;
}

#define TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_new00
static int tolua_SceneLuaAPI_Scene_new00(lua_State* tolua_S)
{
    return ToluaNewObject<Scene>(tolua_S);
}

#define TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_new00_local
static int tolua_SceneLuaAPI_Scene_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<Scene>(tolua_S);
}

static bool SceneLoad(Scene* scene, File* file)
{
    return file ? scene->Load(*file) : false;
}

static bool SceneSave(const Scene* scene, File* file)
{
    return file ? scene->Save(*file) : false;
}

static bool SceneLoad(Scene* scene, const String& fileName)
{
    File file(scene->GetContext(), fileName, FILE_READ);
    return file.IsOpen() && scene->Load(file);
}

static bool SceneSave(const Scene* scene, const String& fileName)
{
    File file(scene->GetContext(), fileName, FILE_WRITE);
    return file.IsOpen() && scene->Save(file);
}

static bool SceneLoadXML(Scene* scene, File* file)
{
    return file ? scene->LoadXML(*file) : false;
}

static bool SceneSaveXML(const Scene* scene, File* file, const String& indentation)
{
    return file ? scene->SaveXML(*file, indentation) : false;
}

static bool SceneLoadXML(Scene* scene, const String& fileName)
{
    File file(scene->GetContext(), fileName, FILE_READ);
    return file.IsOpen() && scene->LoadXML(file);
}

static const PODVector<Node*>& SceneGetNodesWithTag(const Scene* scene, const String& tag)
{
    static PODVector<Node*> result;
    result.Clear();
    scene->GetNodesWithTag(result, tag);
    return result;
}

static bool SceneSaveXML(const Scene* scene, const String& fileName, const String& indentation)
{
    File file(scene->GetContext(), fileName, FILE_WRITE);
    if (!file.IsOpen())
        return false;
    return scene->SaveXML(file, indentation);
}

static bool SceneLoadJSON(Scene* scene, File* file)
{
    return file ? scene->LoadJSON(*file) : false;
}

static bool SceneSaveJSON(const Scene* scene, File* file, const String& indentation)
{
    return file ? scene->SaveJSON(*file, indentation) : false;
}

static bool SceneLoadJSON(Scene* scene, const String& fileName)
{
    File file(scene->GetContext(), fileName, FILE_READ);
    return file.IsOpen() && scene->LoadJSON(file);
}

static bool SceneSaveJSON(const Scene* scene, const String& fileName, const String& indentation)
{
    File file(scene->GetContext(), fileName, FILE_WRITE);
    if (!file.IsOpen())
        return false;
    return scene->SaveJSON(file, indentation);
}

static bool SceneLoadAsync(Scene* scene, const String& fileName, LoadMode mode)
{
    SharedPtr<File> file(new File(scene->GetContext(), fileName, FILE_READ));
    return file->IsOpen() && scene->LoadAsync(file, mode);
}

static bool SceneLoadAsyncXML(Scene* scene, const String& fileName, LoadMode mode)
{
    SharedPtr<File> file(new File(scene->GetContext(), fileName, FILE_READ));
    return file->IsOpen() && scene->LoadAsyncXML(file, mode);
}

static Node* SceneInstantiate(Scene* scene, File* file, const Vector3& position, const Quaternion& rotation, CreateMode mode)
{
    return file ? scene->Instantiate(*file, position, rotation, mode) : 0;
}

static Node* SceneInstantiate(Scene* scene, const String& fileName, const Vector3& position, const Quaternion& rotation, CreateMode mode)
{
    File file(scene->GetContext(), fileName, FILE_READ);
    return file.IsOpen() ? scene->Instantiate(file, position, rotation, mode) : 0;
}

static Node* SceneInstantiateXML(Scene* scene, File* file, const Vector3& position, const Quaternion& rotation, CreateMode mode)
{
    return file ? scene->InstantiateXML(*file, position, rotation, mode) : 0;
}

static Node* SceneInstantiateXML(Scene* scene, const String& fileName, const Vector3& position, const Quaternion& rotation, CreateMode mode)
{
    File file(scene->GetContext(), fileName, FILE_READ);
    return file.IsOpen() ? scene->InstantiateXML(file, position, rotation, mode) : 0;
}

static Node* SceneInstantiateJSON(Scene* scene, const String& fileName, const Vector3& position, const Quaternion& rotation, CreateMode mode)
{
    File file(scene->GetContext(), fileName, FILE_READ);
    return file.IsOpen() ? scene->InstantiateJSON(file, position, rotation, mode) : 0;
}

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Matrix3x4 (lua_State* tolua_S)
{
 Matrix3x4* self = (Matrix3x4*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Scene (lua_State* tolua_S)
{
 Scene* self = (Scene*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_StringHash (lua_State* tolua_S)
{
 StringHash* self = (StringHash*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_ObjectAnimation (lua_State* tolua_S)
{
 ObjectAnimation* self = (ObjectAnimation*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_InterpolationMode (lua_State* tolua_S)
{
 InterpolationMode* self = (InterpolationMode*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_ValueAnimation (lua_State* tolua_S)
{
 ValueAnimation* self = (ValueAnimation*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Vector2 (lua_State* tolua_S)
{
 Vector2* self = (Vector2*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_VariantType (lua_State* tolua_S)
{
 VariantType* self = (VariantType*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Quaternion (lua_State* tolua_S)
{
 Quaternion* self = (Quaternion*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Node (lua_State* tolua_S)
{
 Node* self = (Node*) tolua_tousertype(tolua_S,1,0);
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
 tolua_usertype(tolua_S,"VariantMap");
 tolua_usertype(tolua_S,"Quaternion");
 tolua_usertype(tolua_S,"Resource");
 tolua_usertype(tolua_S,"PODVector<Node*>");
 tolua_usertype(tolua_S,"Animatable");
 tolua_usertype(tolua_S,"InterpolationMode");
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"SplinePath");
 tolua_usertype(tolua_S,"Scene");
 tolua_usertype(tolua_S,"Variant");
 tolua_usertype(tolua_S,"DebugRenderer");
 tolua_usertype(tolua_S,"ObjectAnimation");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"JSONValue");
 tolua_usertype(tolua_S,"VariantType");
 tolua_usertype(tolua_S,"StringVector");
 tolua_usertype(tolua_S,"SceneResolver");
 tolua_usertype(tolua_S,"Deserializer");
 tolua_usertype(tolua_S,"Vector4");
 tolua_usertype(tolua_S,"PODVector<Component*>");
 tolua_usertype(tolua_S,"StringHash");
 tolua_usertype(tolua_S,"Connection");
 tolua_usertype(tolua_S,"Matrix3x4");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"ValueAnimation");
 tolua_usertype(tolua_S,"Serializable");
 tolua_usertype(tolua_S,"File");
 tolua_usertype(tolua_S,"XMLElement");
}

/* method: new of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ValueAnimation_new00
static int tolua_SceneLuaAPI_ValueAnimation_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ValueAnimation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ValueAnimation* tolua_ret = (ValueAnimation*)  Mtolua_new((ValueAnimation)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ValueAnimation");
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

/* method: new_local of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ValueAnimation_new00_local
static int tolua_SceneLuaAPI_ValueAnimation_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ValueAnimation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ValueAnimation* tolua_ret = (ValueAnimation*)  Mtolua_new((ValueAnimation)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ValueAnimation");
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

/* method: delete of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ValueAnimation_delete00
static int tolua_SceneLuaAPI_ValueAnimation_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ValueAnimation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ValueAnimation* self = (ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetInterpolationMethod of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ValueAnimation_SetInterpolationMethod00
static int tolua_SceneLuaAPI_ValueAnimation_SetInterpolationMethod00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ValueAnimation",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ValueAnimation* self = (ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
  InterpMethod method = ((InterpMethod) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInterpolationMethod'", NULL);
#endif
 {
  self->SetInterpolationMethod(method);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInterpolationMethod'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSplineTension of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ValueAnimation_SetSplineTension00
static int tolua_SceneLuaAPI_ValueAnimation_SetSplineTension00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ValueAnimation",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ValueAnimation* self = (ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
  float tension = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSplineTension'", NULL);
#endif
 {
  self->SetSplineTension(tension);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSplineTension'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetValueType of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ValueAnimation_SetValueType00
static int tolua_SceneLuaAPI_ValueAnimation_SetValueType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ValueAnimation",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"VariantType",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ValueAnimation* self = (ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
  VariantType valueType = *((VariantType*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetValueType'", NULL);
#endif
 {
  self->SetValueType(valueType);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetValueType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetKeyFrame of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ValueAnimation_SetKeyFrame00
static int tolua_SceneLuaAPI_ValueAnimation_SetKeyFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ValueAnimation",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ValueAnimation* self = (ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
  float time = ((float)  tolua_tonumber(tolua_S,2,0));
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetKeyFrame'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetKeyFrame(time,*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetKeyFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEventFrame of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ValueAnimation_SetEventFrame00
static int tolua_SceneLuaAPI_ValueAnimation_SetEventFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ValueAnimation",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ValueAnimation* self = (ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
  float time = ((float)  tolua_tonumber(tolua_S,2,0));
  const StringHash* eventType = ((const StringHash*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEventFrame'", NULL);
#endif
 {
  self->SetEventFrame(time,*eventType);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEventFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEventFrame of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ValueAnimation_SetEventFrame01
static int tolua_SceneLuaAPI_ValueAnimation_SetEventFrame01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ValueAnimation",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const StringHash",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  ValueAnimation* self = (ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
  float time = ((float)  tolua_tonumber(tolua_S,2,0));
  const StringHash* eventType = ((const StringHash*)  tolua_tousertype(tolua_S,3,0));
  const VariantMap* eventData = ((const VariantMap*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEventFrame'", NULL);
#endif
 {
  self->SetEventFrame(time,*eventType,*eventData);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_ValueAnimation_SetEventFrame00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInterpolationMethod of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ValueAnimation_GetInterpolationMethod00
static int tolua_SceneLuaAPI_ValueAnimation_GetInterpolationMethod00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ValueAnimation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ValueAnimation* self = (const ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInterpolationMethod'", NULL);
#endif
 {
  InterpMethod tolua_ret = (InterpMethod)  self->GetInterpolationMethod();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInterpolationMethod'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSplineTension of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ValueAnimation_GetSplineTension00
static int tolua_SceneLuaAPI_ValueAnimation_GetSplineTension00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ValueAnimation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ValueAnimation* self = (const ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSplineTension'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetSplineTension();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSplineTension'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetValueType of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ValueAnimation_GetValueType00
static int tolua_SceneLuaAPI_ValueAnimation_GetValueType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ValueAnimation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ValueAnimation* self = (const ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetValueType'", NULL);
#endif
 {
  VariantType tolua_ret = (VariantType)  self->GetValueType();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((VariantType)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"VariantType");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(VariantType));
  tolua_pushusertype(tolua_S,tolua_obj,"VariantType");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
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

/* get function: interpolationMethod of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_get_ValueAnimation_interpolationMethod
static int tolua_get_ValueAnimation_interpolationMethod(lua_State* tolua_S)
{
  ValueAnimation* self = (ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'interpolationMethod'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetInterpolationMethod());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: interpolationMethod of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_set_ValueAnimation_interpolationMethod
static int tolua_set_ValueAnimation_interpolationMethod(lua_State* tolua_S)
{
  ValueAnimation* self = (ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'interpolationMethod'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetInterpolationMethod(((InterpMethod) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: splineTension of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_get_ValueAnimation_splineTension
static int tolua_get_ValueAnimation_splineTension(lua_State* tolua_S)
{
  ValueAnimation* self = (ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'splineTension'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSplineTension());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: splineTension of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_set_ValueAnimation_splineTension
static int tolua_set_ValueAnimation_splineTension(lua_State* tolua_S)
{
  ValueAnimation* self = (ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'splineTension'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSplineTension(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: valueType of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_get_ValueAnimation_valueType
static int tolua_get_ValueAnimation_valueType(lua_State* tolua_S)
{
  ValueAnimation* self = (ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'valueType'",NULL);
#endif
 VariantType tolua_ret = (VariantType)self->GetValueType();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((VariantType)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"VariantType");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(VariantType));
 tolua_pushusertype(tolua_S,tolua_obj,"VariantType");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: valueType of class  ValueAnimation */
#ifndef TOLUA_DISABLE_tolua_set_ValueAnimation_valueType
static int tolua_set_ValueAnimation_valueType(lua_State* tolua_S)
{
  ValueAnimation* self = (ValueAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'valueType'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"VariantType",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetValueType(*((VariantType*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ObjectAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ObjectAnimation_new00
static int tolua_SceneLuaAPI_ObjectAnimation_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ObjectAnimation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ObjectAnimation* tolua_ret = (ObjectAnimation*)  Mtolua_new((ObjectAnimation)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ObjectAnimation");
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

/* method: new_local of class  ObjectAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ObjectAnimation_new00_local
static int tolua_SceneLuaAPI_ObjectAnimation_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ObjectAnimation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ObjectAnimation* tolua_ret = (ObjectAnimation*)  Mtolua_new((ObjectAnimation)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ObjectAnimation");
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

/* method: delete of class  ObjectAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ObjectAnimation_delete00
static int tolua_SceneLuaAPI_ObjectAnimation_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ObjectAnimation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ObjectAnimation* self = (ObjectAnimation*)  tolua_tousertype(tolua_S,1,0);
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

/* method: AddAttributeAnimation of class  ObjectAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ObjectAnimation_AddAttributeAnimation00
static int tolua_SceneLuaAPI_ObjectAnimation_AddAttributeAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ObjectAnimation",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"ValueAnimation",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ObjectAnimation* self = (ObjectAnimation*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  ValueAnimation* attributeAnimation = ((ValueAnimation*)  tolua_tousertype(tolua_S,3,0));
  WrapMode wrapMode = ((WrapMode) (int)  tolua_tonumber(tolua_S,4,WM_LOOP));
  float speed = ((float)  tolua_tonumber(tolua_S,5,1.0f));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddAttributeAnimation'", NULL);
#endif
 {
  self->AddAttributeAnimation(name,attributeAnimation,wrapMode,speed);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddAttributeAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAttributeAnimation of class  ObjectAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ObjectAnimation_RemoveAttributeAnimation00
static int tolua_SceneLuaAPI_ObjectAnimation_RemoveAttributeAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ObjectAnimation",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ObjectAnimation* self = (ObjectAnimation*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAttributeAnimation'", NULL);
#endif
 {
  self->RemoveAttributeAnimation(name);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAttributeAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAttributeAnimation of class  ObjectAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ObjectAnimation_RemoveAttributeAnimation01
static int tolua_SceneLuaAPI_ObjectAnimation_RemoveAttributeAnimation01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ObjectAnimation",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"ValueAnimation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  ObjectAnimation* self = (ObjectAnimation*)  tolua_tousertype(tolua_S,1,0);
  ValueAnimation* attributeAnimation = ((ValueAnimation*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAttributeAnimation'", NULL);
#endif
 {
  self->RemoveAttributeAnimation(attributeAnimation);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_ObjectAnimation_RemoveAttributeAnimation00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAttributeAnimation of class  ObjectAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ObjectAnimation_GetAttributeAnimation00
static int tolua_SceneLuaAPI_ObjectAnimation_GetAttributeAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ObjectAnimation",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ObjectAnimation* self = (const ObjectAnimation*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeAnimation'", NULL);
#endif
 {
  ValueAnimation* tolua_ret = (ValueAnimation*)  self->GetAttributeAnimation(name);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ValueAnimation");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAttributeAnimationWrapMode of class  ObjectAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ObjectAnimation_GetAttributeAnimationWrapMode00
static int tolua_SceneLuaAPI_ObjectAnimation_GetAttributeAnimationWrapMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ObjectAnimation",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ObjectAnimation* self = (const ObjectAnimation*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeAnimationWrapMode'", NULL);
#endif
 {
  WrapMode tolua_ret = (WrapMode)  self->GetAttributeAnimationWrapMode(name);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeAnimationWrapMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAttributeAnimationSpeed of class  ObjectAnimation */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_ObjectAnimation_GetAttributeAnimationSpeed00
static int tolua_SceneLuaAPI_ObjectAnimation_GetAttributeAnimationSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ObjectAnimation",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ObjectAnimation* self = (const ObjectAnimation*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeAnimationSpeed'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAttributeAnimationSpeed(name);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeAnimationSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTemporary of class  Serializable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Serializable_SetTemporary00
static int tolua_SceneLuaAPI_Serializable_SetTemporary00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializable",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializable* self = (Serializable*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTemporary'", NULL);
#endif
 {
  self->SetTemporary(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTemporary'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsTemporary of class  Serializable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Serializable_IsTemporary00
static int tolua_SceneLuaAPI_Serializable_IsTemporary00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Serializable",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Serializable* self = (const Serializable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsTemporary'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsTemporary();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsTemporary'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetInterceptNetworkUpdate of class  Serializable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Serializable_SetInterceptNetworkUpdate00
static int tolua_SceneLuaAPI_Serializable_SetInterceptNetworkUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializable",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializable* self = (Serializable*)  tolua_tousertype(tolua_S,1,0);
  const String attributeName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool enable = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInterceptNetworkUpdate'", NULL);
#endif
 {
  self->SetInterceptNetworkUpdate(attributeName,enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInterceptNetworkUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInterceptNetworkUpdate of class  Serializable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Serializable_GetInterceptNetworkUpdate00
static int tolua_SceneLuaAPI_Serializable_GetInterceptNetworkUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializable",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializable* self = (Serializable*)  tolua_tousertype(tolua_S,1,0);
  const String attributeName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInterceptNetworkUpdate'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetInterceptNetworkUpdate(attributeName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInterceptNetworkUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: temporary of class  Serializable */
#ifndef TOLUA_DISABLE_tolua_get_Serializable_temporary
static int tolua_get_Serializable_temporary(lua_State* tolua_S)
{
  Serializable* self = (Serializable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'temporary'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsTemporary());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: temporary of class  Serializable */
#ifndef TOLUA_DISABLE_tolua_set_Serializable_temporary
static int tolua_set_Serializable_temporary(lua_State* tolua_S)
{
  Serializable* self = (Serializable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'temporary'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTemporary(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAnimationEnabled of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Animatable_SetAnimationEnabled00
static int tolua_SceneLuaAPI_Animatable_SetAnimationEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animatable",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animatable* self = (Animatable*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnimationEnabled'", NULL);
#endif
 {
  self->SetAnimationEnabled(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAnimationEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAnimationTime of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Animatable_SetAnimationTime00
static int tolua_SceneLuaAPI_Animatable_SetAnimationTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animatable",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animatable* self = (Animatable*)  tolua_tousertype(tolua_S,1,0);
  float time = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnimationTime'", NULL);
#endif
 {
  self->SetAnimationTime(time);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAnimationTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetObjectAnimation of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Animatable_SetObjectAnimation00
static int tolua_SceneLuaAPI_Animatable_SetObjectAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animatable",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"ObjectAnimation",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animatable* self = (Animatable*)  tolua_tousertype(tolua_S,1,0);
  ObjectAnimation* objectAnimation = ((ObjectAnimation*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetObjectAnimation'", NULL);
#endif
 {
  self->SetObjectAnimation(objectAnimation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetObjectAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAttributeAnimation of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Animatable_SetAttributeAnimation00
static int tolua_SceneLuaAPI_Animatable_SetAttributeAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animatable",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"ValueAnimation",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animatable* self = (Animatable*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  ValueAnimation* attributeAnimation = ((ValueAnimation*)  tolua_tousertype(tolua_S,3,0));
  WrapMode wrapMode = ((WrapMode) (int)  tolua_tonumber(tolua_S,4,WM_LOOP));
  float speed = ((float)  tolua_tonumber(tolua_S,5,1.0f));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAttributeAnimation'", NULL);
#endif
 {
  self->SetAttributeAnimation(name,attributeAnimation,wrapMode,speed);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAttributeAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAttributeAnimationWrapMode of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Animatable_SetAttributeAnimationWrapMode00
static int tolua_SceneLuaAPI_Animatable_SetAttributeAnimationWrapMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animatable",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animatable* self = (Animatable*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  WrapMode wrapMode = ((WrapMode) (int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAttributeAnimationWrapMode'", NULL);
#endif
 {
  self->SetAttributeAnimationWrapMode(name,wrapMode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAttributeAnimationWrapMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAttributeAnimationSpeed of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Animatable_SetAttributeAnimationSpeed00
static int tolua_SceneLuaAPI_Animatable_SetAttributeAnimationSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animatable",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animatable* self = (Animatable*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  float speed = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAttributeAnimationSpeed'", NULL);
#endif
 {
  self->SetAttributeAnimationSpeed(name,speed);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAttributeAnimationSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAttributeAnimationTime of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Animatable_SetAttributeAnimationTime00
static int tolua_SceneLuaAPI_Animatable_SetAttributeAnimationTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animatable",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animatable* self = (Animatable*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  float time = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAttributeAnimationTime'", NULL);
#endif
 {
  self->SetAttributeAnimationTime(name,time);
 tolua_pushurho3dstring(tolua_S,(const char*)name);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAttributeAnimationTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveObjectAnimation of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Animatable_RemoveObjectAnimation00
static int tolua_SceneLuaAPI_Animatable_RemoveObjectAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animatable",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animatable* self = (Animatable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveObjectAnimation'", NULL);
#endif
 {
  self->RemoveObjectAnimation();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveObjectAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAttributeAnimation of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Animatable_RemoveAttributeAnimation00
static int tolua_SceneLuaAPI_Animatable_RemoveAttributeAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animatable",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animatable* self = (Animatable*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAttributeAnimation'", NULL);
#endif
 {
  self->RemoveAttributeAnimation(name);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAttributeAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnimationEnabled of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Animatable_GetAnimationEnabled00
static int tolua_SceneLuaAPI_Animatable_GetAnimationEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Animatable",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Animatable* self = (const Animatable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnimationEnabled'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetAnimationEnabled();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAnimationEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjectAnimation of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Animatable_GetObjectAnimation00
static int tolua_SceneLuaAPI_Animatable_GetObjectAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Animatable",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Animatable* self = (const Animatable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectAnimation'", NULL);
#endif
 {
  ObjectAnimation* tolua_ret = (ObjectAnimation*)  self->GetObjectAnimation();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ObjectAnimation");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAttributeAnimation of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Animatable_GetAttributeAnimation00
static int tolua_SceneLuaAPI_Animatable_GetAttributeAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Animatable",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Animatable* self = (const Animatable*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeAnimation'", NULL);
#endif
 {
  ValueAnimation* tolua_ret = (ValueAnimation*)  self->GetAttributeAnimation(name);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ValueAnimation");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAttributeAnimationWrapMode of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Animatable_GetAttributeAnimationWrapMode00
static int tolua_SceneLuaAPI_Animatable_GetAttributeAnimationWrapMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Animatable",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Animatable* self = (const Animatable*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeAnimationWrapMode'", NULL);
#endif
 {
  WrapMode tolua_ret = (WrapMode)  self->GetAttributeAnimationWrapMode(name);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeAnimationWrapMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAttributeAnimationSpeed of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Animatable_GetAttributeAnimationSpeed00
static int tolua_SceneLuaAPI_Animatable_GetAttributeAnimationSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Animatable",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Animatable* self = (const Animatable*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeAnimationSpeed'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAttributeAnimationSpeed(name);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeAnimationSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAttributeAnimationTime of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Animatable_GetAttributeAnimationTime00
static int tolua_SceneLuaAPI_Animatable_GetAttributeAnimationTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Animatable",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Animatable* self = (const Animatable*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeAnimationTime'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAttributeAnimationTime(name);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeAnimationTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: animationEnabled of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_get_Animatable_animationEnabled
static int tolua_get_Animatable_animationEnabled(lua_State* tolua_S)
{
  Animatable* self = (Animatable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'animationEnabled'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetAnimationEnabled());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: animationEnabled of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_set_Animatable_animationEnabled
static int tolua_set_Animatable_animationEnabled(lua_State* tolua_S)
{
  Animatable* self = (Animatable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'animationEnabled'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAnimationEnabled(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: objectAnimation of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_get_Animatable_objectAnimation_ptr
static int tolua_get_Animatable_objectAnimation_ptr(lua_State* tolua_S)
{
  Animatable* self = (Animatable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'objectAnimation'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetObjectAnimation(),"ObjectAnimation");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: objectAnimation of class  Animatable */
#ifndef TOLUA_DISABLE_tolua_set_Animatable_objectAnimation_ptr
static int tolua_set_Animatable_objectAnimation_ptr(lua_State* tolua_S)
{
  Animatable* self = (Animatable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'objectAnimation'",NULL);
 if (!tolua_isusertype(tolua_S,2,"ObjectAnimation",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetObjectAnimation(((ObjectAnimation*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEnabled of class  Component */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Component_SetEnabled00
static int tolua_SceneLuaAPI_Component_SetEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEnabled'", NULL);
#endif
 {
  self->SetEnabled(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Remove of class  Component */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Component_Remove00
static int tolua_SceneLuaAPI_Component_Remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Remove'", NULL);
#endif
 {
  self->Remove();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawDebugGeometry of class  Component */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Component_DrawDebugGeometry00
static int tolua_SceneLuaAPI_Component_DrawDebugGeometry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"DebugRenderer",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  DebugRenderer* debug = ((DebugRenderer*)  tolua_tousertype(tolua_S,2,0));
  bool depthTest = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawDebugGeometry'", NULL);
#endif
 {
  self->DrawDebugGeometry(debug,depthTest);
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

/* method: GetID of class  Component */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Component_GetID00
static int tolua_SceneLuaAPI_Component_GetID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Component",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Component* self = (const Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetID'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetID();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsReplicated of class  Component */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Component_IsReplicated00
static int tolua_SceneLuaAPI_Component_IsReplicated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Component",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Component* self = (const Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsReplicated'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsReplicated();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsReplicated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNode of class  Component */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Component_GetNode00
static int tolua_SceneLuaAPI_Component_GetNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Component",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Component* self = (const Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNode'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->GetNode();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScene of class  Component */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Component_GetScene00
static int tolua_SceneLuaAPI_Component_GetScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Component",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Component* self = (const Component*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsEnabled of class  Component */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Component_IsEnabled00
static int tolua_SceneLuaAPI_Component_IsEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Component",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Component* self = (const Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsEnabled'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsEnabled();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsEnabledEffective of class  Component */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Component_IsEnabledEffective00
static int tolua_SceneLuaAPI_Component_IsEnabledEffective00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Component",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Component* self = (const Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsEnabledEffective'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsEnabledEffective();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsEnabledEffective'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetComponent of class  Component */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Component_GetComponent00
static int tolua_SceneLuaAPI_Component_GetComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Component",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Component* self = (const Component*)  tolua_tousertype(tolua_S,1,0);
  StringHash type = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetComponent'", NULL);
#endif
 {
  Component* tolua_ret = (Component*)  self->GetComponent(type);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"Component");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetComponent of class  Component */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Component_GetComponent01
static int tolua_SceneLuaAPI_Component_GetComponent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Component",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Component* self = (const Component*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetComponent'", NULL);
#endif
 {
  Component* tolua_ret = (Component*)  self->GetComponent(type);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"Component");
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Component_GetComponent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ID of class  Component */
#ifndef TOLUA_DISABLE_tolua_get_Component_ID
static int tolua_get_Component_ID(lua_State* tolua_S)
{
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ID'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetID());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: replicated of class  Component */
#ifndef TOLUA_DISABLE_tolua_get_Component_replicated
static int tolua_get_Component_replicated(lua_State* tolua_S)
{
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'replicated'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsReplicated());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: enabled of class  Component */
#ifndef TOLUA_DISABLE_tolua_get_Component_enabled
static int tolua_get_Component_enabled(lua_State* tolua_S)
{
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enabled'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsEnabled());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: enabled of class  Component */
#ifndef TOLUA_DISABLE_tolua_set_Component_enabled
static int tolua_set_Component_enabled(lua_State* tolua_S)
{
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enabled'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEnabled(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: enabledEffective of class  Component */
#ifndef TOLUA_DISABLE_tolua_get_Component_enabledEffective
static int tolua_get_Component_enabledEffective(lua_State* tolua_S)
{
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enabledEffective'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsEnabledEffective());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: node of class  Component */
#ifndef TOLUA_DISABLE_tolua_get_Component_node_ptr
static int tolua_get_Component_node_ptr(lua_State* tolua_S)
{
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'node'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetNode(),"Node");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scene of class  Component */
#ifndef TOLUA_DISABLE_tolua_get_Component_scene_ptr
static int tolua_get_Component_scene_ptr(lua_State* tolua_S)
{
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scene'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetScene(),"Scene");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_new00
static int tolua_SceneLuaAPI_Node_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Node* tolua_ret = (Node*)  Mtolua_new((Node)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
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

/* method: new_local of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_new00_local
static int tolua_SceneLuaAPI_Node_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Node* tolua_ret = (Node*)  Mtolua_new((Node)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
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

/* method: delete of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_delete00
static int tolua_SceneLuaAPI_Node_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
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

/* method: NodeSaveXML of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SaveXML00
static int tolua_SceneLuaAPI_Node_SaveXML00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  File* dest = ((File*)  tolua_tousertype(tolua_S,2,0));
  const String indentation = ((const String)  tolua_tourho3dstring(tolua_S,3,"\t"));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NodeSaveXML'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  NodeSaveXML(self,dest,indentation);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveXML'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NodeSaveJSON of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SaveJSON00
static int tolua_SceneLuaAPI_Node_SaveJSON00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  File* dest = ((File*)  tolua_tousertype(tolua_S,2,0));
  const String indentation = ((const String)  tolua_tourho3dstring(tolua_S,3,"\t"));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NodeSaveJSON'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  NodeSaveJSON(self,dest,indentation);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveJSON'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetName of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetName00
static int tolua_SceneLuaAPI_Node_SetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetName'", NULL);
#endif
 {
  self->SetName(name);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddTag of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_AddTag00
static int tolua_SceneLuaAPI_Node_AddTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String tag = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTag'", NULL);
#endif
 {
  self->AddTag(tag);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddTag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddTags of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_AddTags00
static int tolua_SceneLuaAPI_Node_AddTags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String tags = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  char separator = ((char)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTags'", NULL);
#endif
 {
  self->AddTags(tags,separator);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddTags'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveTag of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_RemoveTag00
static int tolua_SceneLuaAPI_Node_RemoveTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String tag = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveTag'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->RemoveTag(tag);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveTag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllTags of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_RemoveAllTags00
static int tolua_SceneLuaAPI_Node_RemoveAllTags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllTags'", NULL);
#endif
 {
  self->RemoveAllTags();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllTags'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetPosition00
static int tolua_SceneLuaAPI_Node_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetPosition2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetPosition2D00
static int tolua_SceneLuaAPI_Node_SetPosition2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* position = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition2D'", NULL);
#endif
 {
  self->SetPosition2D(*position);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetPosition2D01
static int tolua_SceneLuaAPI_Node_SetPosition2D01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition2D'", NULL);
#endif
 {
  self->SetPosition2D(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_SetPosition2D00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRotation of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetRotation00
static int tolua_SceneLuaAPI_Node_SetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetRotation2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetRotation2D00
static int tolua_SceneLuaAPI_Node_SetRotation2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  float rotation = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRotation2D'", NULL);
#endif
 {
  self->SetRotation2D(rotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRotation2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDirection of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetDirection00
static int tolua_SceneLuaAPI_Node_SetDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* direction = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDirection'", NULL);
#endif
 {
  self->SetDirection(*direction);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetScale00
static int tolua_SceneLuaAPI_Node_SetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  float scale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale'", NULL);
#endif
 {
  self->SetScale(scale);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetScale01
static int tolua_SceneLuaAPI_Node_SetScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale'", NULL);
#endif
 {
  self->SetScale(*scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_SetScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetScale2D00
static int tolua_SceneLuaAPI_Node_SetScale2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* scale = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale2D'", NULL);
#endif
 {
  self->SetScale2D(*scale);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScale2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetScale2D01
static int tolua_SceneLuaAPI_Node_SetScale2D01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale2D'", NULL);
#endif
 {
  self->SetScale2D(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_SetScale2D00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTransform of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetTransform00
static int tolua_SceneLuaAPI_Node_SetTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetTransform of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetTransform01
static int tolua_SceneLuaAPI_Node_SetTransform01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTransform'", NULL);
#endif
 {
  self->SetTransform(*position,*rotation,*scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_SetTransform00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTransform of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetTransform02
static int tolua_SceneLuaAPI_Node_SetTransform02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTransform'", NULL);
#endif
 {
  self->SetTransform(*position,*rotation,scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_SetTransform01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTransform of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetTransform03
static int tolua_SceneLuaAPI_Node_SetTransform03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* transform = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTransform'", NULL);
#endif
 {
  self->SetTransform(*transform);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_SetTransform02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTransform2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetTransform2D00
static int tolua_SceneLuaAPI_Node_SetTransform2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* position = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  float rotation = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTransform2D'", NULL);
#endif
 {
  self->SetTransform2D(*position,rotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTransform2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTransform2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetTransform2D01
static int tolua_SceneLuaAPI_Node_SetTransform2D01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* position = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  float rotation = ((float)  tolua_tonumber(tolua_S,3,0));
  const Vector2* scale = ((const Vector2*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTransform2D'", NULL);
#endif
 {
  self->SetTransform2D(*position,rotation,*scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_SetTransform2D00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTransform2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetTransform2D02
static int tolua_SceneLuaAPI_Node_SetTransform2D02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* position = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  float rotation = ((float)  tolua_tonumber(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTransform2D'", NULL);
#endif
 {
  self->SetTransform2D(*position,rotation,scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_SetTransform2D01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldPosition of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldPosition00
static int tolua_SceneLuaAPI_Node_SetWorldPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetWorldPosition2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldPosition2D00
static int tolua_SceneLuaAPI_Node_SetWorldPosition2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* position = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldPosition2D'", NULL);
#endif
 {
  self->SetWorldPosition2D(*position);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWorldPosition2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldPosition2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldPosition2D01
static int tolua_SceneLuaAPI_Node_SetWorldPosition2D01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldPosition2D'", NULL);
#endif
 {
  self->SetWorldPosition2D(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_SetWorldPosition2D00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldRotation of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldRotation00
static int tolua_SceneLuaAPI_Node_SetWorldRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldRotation'", NULL);
#endif
 {
  self->SetWorldRotation(*rotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWorldRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldRotation2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldRotation2D00
static int tolua_SceneLuaAPI_Node_SetWorldRotation2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  float rotation = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldRotation2D'", NULL);
#endif
 {
  self->SetWorldRotation2D(rotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWorldRotation2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldDirection of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldDirection00
static int tolua_SceneLuaAPI_Node_SetWorldDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* direction = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldDirection'", NULL);
#endif
 {
  self->SetWorldDirection(*direction);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWorldDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldScale of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldScale00
static int tolua_SceneLuaAPI_Node_SetWorldScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  float scale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldScale'", NULL);
#endif
 {
  self->SetWorldScale(scale);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWorldScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldScale of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldScale01
static int tolua_SceneLuaAPI_Node_SetWorldScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldScale'", NULL);
#endif
 {
  self->SetWorldScale(*scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_SetWorldScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldScale2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldScale2D00
static int tolua_SceneLuaAPI_Node_SetWorldScale2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* scale = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldScale2D'", NULL);
#endif
 {
  self->SetWorldScale2D(*scale);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWorldScale2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldScale2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldScale2D01
static int tolua_SceneLuaAPI_Node_SetWorldScale2D01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldScale2D'", NULL);
#endif
 {
  self->SetWorldScale2D(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_SetWorldScale2D00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldTransform of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldTransform00
static int tolua_SceneLuaAPI_Node_SetWorldTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldTransform'", NULL);
#endif
 {
  self->SetWorldTransform(*position,*rotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWorldTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldTransform of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldTransform01
static int tolua_SceneLuaAPI_Node_SetWorldTransform01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldTransform'", NULL);
#endif
 {
  self->SetWorldTransform(*position,*rotation,*scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_SetWorldTransform00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldTransform of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldTransform02
static int tolua_SceneLuaAPI_Node_SetWorldTransform02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldTransform'", NULL);
#endif
 {
  self->SetWorldTransform(*position,*rotation,scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_SetWorldTransform01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldTransform2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldTransform2D00
static int tolua_SceneLuaAPI_Node_SetWorldTransform2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* position = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  float rotation = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldTransform2D'", NULL);
#endif
 {
  self->SetWorldTransform2D(*position,rotation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWorldTransform2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldTransform2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldTransform2D01
static int tolua_SceneLuaAPI_Node_SetWorldTransform2D01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* position = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  float rotation = ((float)  tolua_tonumber(tolua_S,3,0));
  const Vector2* scale = ((const Vector2*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldTransform2D'", NULL);
#endif
 {
  self->SetWorldTransform2D(*position,rotation,*scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_SetWorldTransform2D00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWorldTransform2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetWorldTransform2D02
static int tolua_SceneLuaAPI_Node_SetWorldTransform2D02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* position = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  float rotation = ((float)  tolua_tonumber(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWorldTransform2D'", NULL);
#endif
 {
  self->SetWorldTransform2D(*position,rotation,scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_SetWorldTransform2D01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Translate of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_Translate00
static int tolua_SceneLuaAPI_Node_Translate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* delta = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  TransformSpace space = ((TransformSpace) (int)  tolua_tonumber(tolua_S,3,TS_LOCAL));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Translate'", NULL);
#endif
 {
  self->Translate(*delta,space);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Translate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Translate2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_Translate2D00
static int tolua_SceneLuaAPI_Node_Translate2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* delta = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  TransformSpace space = ((TransformSpace) (int)  tolua_tonumber(tolua_S,3,TS_LOCAL));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Translate2D'", NULL);
#endif
 {
  self->Translate2D(*delta,space);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Translate2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Rotate of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_Rotate00
static int tolua_SceneLuaAPI_Node_Rotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* delta = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  TransformSpace space = ((TransformSpace) (int)  tolua_tonumber(tolua_S,3,TS_LOCAL));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Rotate'", NULL);
#endif
 {
  self->Rotate(*delta,space);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Rotate2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_Rotate2D00
static int tolua_SceneLuaAPI_Node_Rotate2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
  TransformSpace space = ((TransformSpace) (int)  tolua_tonumber(tolua_S,3,TS_LOCAL));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Rotate2D'", NULL);
#endif
 {
  self->Rotate2D(delta,space);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Rotate2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RotateAround of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_RotateAround00
static int tolua_SceneLuaAPI_Node_RotateAround00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* point = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* delta = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  TransformSpace space = ((TransformSpace) (int)  tolua_tonumber(tolua_S,4,TS_LOCAL));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RotateAround'", NULL);
#endif
 {
  self->RotateAround(*point,*delta,space);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RotateAround'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RotateAround2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_RotateAround2D00
static int tolua_SceneLuaAPI_Node_RotateAround2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* point = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  float delta = ((float)  tolua_tonumber(tolua_S,3,0));
  TransformSpace space = ((TransformSpace) (int)  tolua_tonumber(tolua_S,4,TS_LOCAL));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RotateAround2D'", NULL);
#endif
 {
  self->RotateAround2D(*point,delta,space);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RotateAround2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Pitch of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_Pitch00
static int tolua_SceneLuaAPI_Node_Pitch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  TransformSpace space = ((TransformSpace) (int)  tolua_tonumber(tolua_S,3,TS_LOCAL));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Pitch'", NULL);
#endif
 {
  self->Pitch(angle,space);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Pitch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Yaw of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_Yaw00
static int tolua_SceneLuaAPI_Node_Yaw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  TransformSpace space = ((TransformSpace) (int)  tolua_tonumber(tolua_S,3,TS_LOCAL));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Yaw'", NULL);
#endif
 {
  self->Yaw(angle,space);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Yaw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Roll of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_Roll00
static int tolua_SceneLuaAPI_Node_Roll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  TransformSpace space = ((TransformSpace) (int)  tolua_tonumber(tolua_S,3,TS_LOCAL));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Roll'", NULL);
#endif
 {
  self->Roll(angle,space);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Roll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LookAt of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_LookAt00
static int tolua_SceneLuaAPI_Node_LookAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* target = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LookAt'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->LookAt(*target);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LookAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LookAt of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_LookAt01
static int tolua_SceneLuaAPI_Node_LookAt01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* target = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* upAxis = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  TransformSpace space = ((TransformSpace) (int)  tolua_tonumber(tolua_S,4,TS_WORLD));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LookAt'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->LookAt(*target,*upAxis,space);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_LookAt00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Scale of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_Scale00
static int tolua_SceneLuaAPI_Node_Scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  float scale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Scale'", NULL);
#endif
 {
  self->Scale(scale);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Scale of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_Scale01
static int tolua_SceneLuaAPI_Node_Scale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* scale = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Scale'", NULL);
#endif
 {
  self->Scale(*scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_Scale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Scale2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_Scale2D00
static int tolua_SceneLuaAPI_Node_Scale2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* scale = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Scale2D'", NULL);
#endif
 {
  self->Scale2D(*scale);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Scale2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEnabled of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetEnabled00
static int tolua_SceneLuaAPI_Node_SetEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEnabled'", NULL);
#endif
 {
  self->SetEnabled(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDeepEnabled of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetDeepEnabled00
static int tolua_SceneLuaAPI_Node_SetDeepEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDeepEnabled'", NULL);
#endif
 {
  self->SetDeepEnabled(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDeepEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResetDeepEnabled of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_ResetDeepEnabled00
static int tolua_SceneLuaAPI_Node_ResetDeepEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResetDeepEnabled'", NULL);
#endif
 {
  self->ResetDeepEnabled();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResetDeepEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEnabledRecursive of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetEnabledRecursive00
static int tolua_SceneLuaAPI_Node_SetEnabledRecursive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEnabledRecursive'", NULL);
#endif
 {
  self->SetEnabledRecursive(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEnabledRecursive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOwner of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetOwner00
static int tolua_SceneLuaAPI_Node_SetOwner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Connection* owner = ((Connection*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOwner'", NULL);
#endif
 {
  self->SetOwner(owner);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOwner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MarkDirty of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_MarkDirty00
static int tolua_SceneLuaAPI_Node_MarkDirty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MarkDirty'", NULL);
#endif
 {
  self->MarkDirty();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MarkDirty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateChild of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_CreateChild00
static int tolua_SceneLuaAPI_Node_CreateChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,String::EMPTY));
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,3,REPLICATED));
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,4,0));
  bool temporary = ((bool)  tolua_toboolean(tolua_S,5,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateChild'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->CreateChild(name,mode,id,temporary);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
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

/* method: CreateTemporaryChild of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_CreateTemporaryChild00
static int tolua_SceneLuaAPI_Node_CreateTemporaryChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,String::EMPTY));
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,3,REPLICATED));
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateTemporaryChild'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->CreateTemporaryChild(name,mode,id);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateTemporaryChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddChild of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_AddChild00
static int tolua_SceneLuaAPI_Node_AddChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,3,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddChild'", NULL);
#endif
 {
  self->AddChild(node,index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveChild of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_RemoveChild00
static int tolua_SceneLuaAPI_Node_RemoveChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveChild'", NULL);
#endif
 {
  self->RemoveChild(node);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllChildren of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_RemoveAllChildren00
static int tolua_SceneLuaAPI_Node_RemoveAllChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllChildren'", NULL);
#endif
 {
  self->RemoveAllChildren();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveChildren of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_RemoveChildren00
static int tolua_SceneLuaAPI_Node_RemoveChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  bool removeReplicated = ((bool)  tolua_toboolean(tolua_S,2,0));
  bool removeLocal = ((bool)  tolua_toboolean(tolua_S,3,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveChildren'", NULL);
#endif
 {
  self->RemoveChildren(removeReplicated,removeLocal,recursive);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveComponent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_RemoveComponent00
static int tolua_SceneLuaAPI_Node_RemoveComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Component* component = ((Component*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveComponent'", NULL);
#endif
 {
  self->RemoveComponent(component);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveComponent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_RemoveComponent01
static int tolua_SceneLuaAPI_Node_RemoveComponent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  StringHash type = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveComponent'", NULL);
#endif
 {
  self->RemoveComponent(type);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_RemoveComponent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveComponent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_RemoveComponent02
static int tolua_SceneLuaAPI_Node_RemoveComponent02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveComponent'", NULL);
#endif
 {
  self->RemoveComponent(type);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_RemoveComponent01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveComponents of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_RemoveComponents00
static int tolua_SceneLuaAPI_Node_RemoveComponents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  bool removeReplicated = ((bool)  tolua_toboolean(tolua_S,2,0));
  bool removeLocal = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveComponents'", NULL);
#endif
 {
  self->RemoveComponents(removeReplicated,removeLocal);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveComponents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveComponents of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_RemoveComponents01
static int tolua_SceneLuaAPI_Node_RemoveComponents01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveComponents'", NULL);
#endif
 {
  self->RemoveComponents(type);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_RemoveComponents00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllComponents of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_RemoveAllComponents00
static int tolua_SceneLuaAPI_Node_RemoveAllComponents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllComponents'", NULL);
#endif
 {
  self->RemoveAllComponents();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllComponents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReorderComponent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_ReorderComponent00
static int tolua_SceneLuaAPI_Node_ReorderComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Component* component = ((Component*)  tolua_tousertype(tolua_S,2,0));
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReorderComponent'", NULL);
#endif
 {
  self->ReorderComponent(component,index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReorderComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clone of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_Clone00
static int tolua_SceneLuaAPI_Node_Clone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,2,REPLICATED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clone'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->Clone(mode);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
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

/* method: Remove of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_Remove00
static int tolua_SceneLuaAPI_Node_Remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Remove'", NULL);
#endif
 {
  self->Remove();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetParent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetParent00
static int tolua_SceneLuaAPI_Node_SetParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetParent'", NULL);
#endif
 {
  self->SetParent(parent);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVar of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetVar00
static int tolua_SceneLuaAPI_Node_SetVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  StringHash key = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVar'", NULL);
#endif
 {
  self->SetVar(key,*value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddListener of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_AddListener00
static int tolua_SceneLuaAPI_Node_AddListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Component* component = ((Component*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddListener'", NULL);
#endif
 {
  self->AddListener(component);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveListener of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_RemoveListener00
static int tolua_SceneLuaAPI_Node_RemoveListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Component* component = ((Component*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveListener'", NULL);
#endif
 {
  self->RemoveListener(component);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateComponent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_CreateComponent00
static int tolua_SceneLuaAPI_Node_CreateComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,3,REPLICATED));
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateComponent'", NULL);
#endif
 {
  Component* tolua_ret = (Component*)  self->CreateComponent(type,mode,id);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"Component");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOrCreateComponent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetOrCreateComponent00
static int tolua_SceneLuaAPI_Node_GetOrCreateComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,3,REPLICATED));
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOrCreateComponent'", NULL);
#endif
 {
  Component* tolua_ret = (Component*)  self->GetOrCreateComponent(type,mode,id);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"Component");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOrCreateComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CloneComponent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_CloneComponent00
static int tolua_SceneLuaAPI_Node_CloneComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Component* component = ((Component*)  tolua_tousertype(tolua_S,2,0));
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CloneComponent'", NULL);
#endif
 {
  Component* tolua_ret = (Component*)  self->CloneComponent(component,id);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"Component");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CloneComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CloneComponent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_CloneComponent01
static int tolua_SceneLuaAPI_Node_CloneComponent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Component* component = ((Component*)  tolua_tousertype(tolua_S,2,0));
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,3,0));
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CloneComponent'", NULL);
#endif
 {
  Component* tolua_ret = (Component*)  self->CloneComponent(component,mode,id);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"Component");
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_CloneComponent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateScriptObject of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_CreateScriptObject00
static int tolua_SceneLuaAPI_Node_CreateScriptObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String scriptObjectType = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateScriptObject'", NULL);
#endif
 {
  int tolua_ret = (int)  self->CreateScriptObject(scriptObjectType);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateScriptObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateScriptObject of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_CreateScriptObject01
static int tolua_SceneLuaAPI_Node_CreateScriptObject01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String scriptObjectType = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateScriptObject'", NULL);
#endif
 {
  int tolua_ret = (int)  self->CreateScriptObject(fileName,scriptObjectType);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_CreateScriptObject00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScriptObject of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetScriptObject00
static int tolua_SceneLuaAPI_Node_GetScriptObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScriptObject'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetScriptObject();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScriptObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScriptObject of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetScriptObject01
static int tolua_SceneLuaAPI_Node_GetScriptObject01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  const String scriptObjectType = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScriptObject'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetScriptObject(scriptObjectType);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_GetScriptObject00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetID of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetID00
static int tolua_SceneLuaAPI_Node_GetID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetID'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetID();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsReplicated of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_IsReplicated00
static int tolua_SceneLuaAPI_Node_IsReplicated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsReplicated'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsReplicated();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsReplicated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetName00
static int tolua_SceneLuaAPI_Node_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetNameHash of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetNameHash00
static int tolua_SceneLuaAPI_Node_GetNameHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetParent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetParent00
static int tolua_SceneLuaAPI_Node_GetParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetParent'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->GetParent();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
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

/* method: GetScene of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetScene00
static int tolua_SceneLuaAPI_Node_GetScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsChildOf of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_IsChildOf00
static int tolua_SceneLuaAPI_Node_IsChildOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsChildOf'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsChildOf(node);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsChildOf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsEnabled of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_IsEnabled00
static int tolua_SceneLuaAPI_Node_IsEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsEnabled'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsEnabled();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsEnabledSelf of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_IsEnabledSelf00
static int tolua_SceneLuaAPI_Node_IsEnabledSelf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsEnabledSelf'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsEnabledSelf();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsEnabledSelf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOwner of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetOwner00
static int tolua_SceneLuaAPI_Node_GetOwner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOwner'", NULL);
#endif
 {
  Connection* tolua_ret = (Connection*)  self->GetOwner();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Connection");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOwner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPosition of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetPosition00
static int tolua_SceneLuaAPI_Node_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetPosition2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetPosition2D00
static int tolua_SceneLuaAPI_Node_GetPosition2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition2D'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->GetPosition2D();
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
 tolua_error(tolua_S,"#ferror in function 'GetPosition2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRotation of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetRotation00
static int tolua_SceneLuaAPI_Node_GetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetRotation2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetRotation2D00
static int tolua_SceneLuaAPI_Node_GetRotation2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRotation2D'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRotation2D();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRotation2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDirection of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetDirection00
static int tolua_SceneLuaAPI_Node_GetDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDirection'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetDirection();
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
 tolua_error(tolua_S,"#ferror in function 'GetDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUp of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetUp00
static int tolua_SceneLuaAPI_Node_GetUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUp'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetUp();
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
 tolua_error(tolua_S,"#ferror in function 'GetUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRight of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetRight00
static int tolua_SceneLuaAPI_Node_GetRight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRight'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetRight();
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
 tolua_error(tolua_S,"#ferror in function 'GetRight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScale of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetScale00
static int tolua_SceneLuaAPI_Node_GetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScale'", NULL);
#endif
 {
  const Vector3& tolua_ret = (const Vector3&)  self->GetScale();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector3");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScale2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetScale2D00
static int tolua_SceneLuaAPI_Node_GetScale2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScale2D'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->GetScale2D();
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
 tolua_error(tolua_S,"#ferror in function 'GetScale2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTransform of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetTransform00
static int tolua_SceneLuaAPI_Node_GetTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTransform'", NULL);
#endif
 {
  Matrix3x4 tolua_ret = (Matrix3x4)  self->GetTransform();
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
 tolua_error(tolua_S,"#ferror in function 'GetTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldPosition of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetWorldPosition00
static int tolua_SceneLuaAPI_Node_GetWorldPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetWorldPosition2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetWorldPosition2D00
static int tolua_SceneLuaAPI_Node_GetWorldPosition2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldPosition2D'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->GetWorldPosition2D();
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
 tolua_error(tolua_S,"#ferror in function 'GetWorldPosition2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldRotation of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetWorldRotation00
static int tolua_SceneLuaAPI_Node_GetWorldRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldRotation'", NULL);
#endif
 {
  Quaternion tolua_ret = (Quaternion)  self->GetWorldRotation();
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
 tolua_error(tolua_S,"#ferror in function 'GetWorldRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldRotation2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetWorldRotation2D00
static int tolua_SceneLuaAPI_Node_GetWorldRotation2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldRotation2D'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetWorldRotation2D();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWorldRotation2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldDirection of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetWorldDirection00
static int tolua_SceneLuaAPI_Node_GetWorldDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldDirection'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetWorldDirection();
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
 tolua_error(tolua_S,"#ferror in function 'GetWorldDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldUp of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetWorldUp00
static int tolua_SceneLuaAPI_Node_GetWorldUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldUp'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetWorldUp();
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
 tolua_error(tolua_S,"#ferror in function 'GetWorldUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldRight of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetWorldRight00
static int tolua_SceneLuaAPI_Node_GetWorldRight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldRight'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetWorldRight();
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
 tolua_error(tolua_S,"#ferror in function 'GetWorldRight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldScale of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetWorldScale00
static int tolua_SceneLuaAPI_Node_GetWorldScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldScale'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetWorldScale();
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
 tolua_error(tolua_S,"#ferror in function 'GetWorldScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSignedWorldScale of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetSignedWorldScale00
static int tolua_SceneLuaAPI_Node_GetSignedWorldScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSignedWorldScale'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetSignedWorldScale();
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
 tolua_error(tolua_S,"#ferror in function 'GetSignedWorldScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldScale2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetWorldScale2D00
static int tolua_SceneLuaAPI_Node_GetWorldScale2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldScale2D'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->GetWorldScale2D();
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
 tolua_error(tolua_S,"#ferror in function 'GetWorldScale2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldTransform of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetWorldTransform00
static int tolua_SceneLuaAPI_Node_GetWorldTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldTransform'", NULL);
#endif
 {
  const Matrix3x4& tolua_ret = (const Matrix3x4&)  self->GetWorldTransform();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Matrix3x4");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWorldTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LocalToWorld of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_LocalToWorld00
static int tolua_SceneLuaAPI_Node_LocalToWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LocalToWorld'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->LocalToWorld(*position);
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
 tolua_error(tolua_S,"#ferror in function 'LocalToWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LocalToWorld of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_LocalToWorld01
static int tolua_SceneLuaAPI_Node_LocalToWorld01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* vector = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LocalToWorld'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->LocalToWorld(*vector);
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
 return tolua_SceneLuaAPI_Node_LocalToWorld00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: LocalToWorld2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_LocalToWorld2D00
static int tolua_SceneLuaAPI_Node_LocalToWorld2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* vector = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LocalToWorld2D'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->LocalToWorld2D(*vector);
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
 tolua_error(tolua_S,"#ferror in function 'LocalToWorld2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WorldToLocal of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_WorldToLocal00
static int tolua_SceneLuaAPI_Node_WorldToLocal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WorldToLocal'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->WorldToLocal(*position);
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
 tolua_error(tolua_S,"#ferror in function 'WorldToLocal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WorldToLocal of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_WorldToLocal01
static int tolua_SceneLuaAPI_Node_WorldToLocal01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* vector = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WorldToLocal'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->WorldToLocal(*vector);
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
 return tolua_SceneLuaAPI_Node_WorldToLocal00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: WorldToLocal2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_WorldToLocal2D00
static int tolua_SceneLuaAPI_Node_WorldToLocal2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* vector = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WorldToLocal2D'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->WorldToLocal2D(*vector);
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
 tolua_error(tolua_S,"#ferror in function 'WorldToLocal2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsDirty of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_IsDirty00
static int tolua_SceneLuaAPI_Node_IsDirty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsDirty'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsDirty();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsDirty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumChildren of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetNumChildren00
static int tolua_SceneLuaAPI_Node_GetNumChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  bool recursive = ((bool)  tolua_toboolean(tolua_S,2,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumChildren'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumChildren(recursive);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetChild of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetChild00
static int tolua_SceneLuaAPI_Node_GetChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChild'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->GetChild(name,recursive);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
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

/* method: GetChild of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetChild01
static int tolua_SceneLuaAPI_Node_GetChild01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  StringHash nameHash = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChild'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->GetChild(nameHash,recursive);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_GetChild00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetChild of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetChild02
static int tolua_SceneLuaAPI_Node_GetChild02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChild'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->GetChild(index);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_GetChild01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumComponents of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetNumComponents00
static int tolua_SceneLuaAPI_Node_GetNumComponents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumComponents'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumComponents();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumComponents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumNetworkComponents of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetNumNetworkComponents00
static int tolua_SceneLuaAPI_Node_GetNumNetworkComponents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumNetworkComponents'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumNetworkComponents();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumNetworkComponents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasComponent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_HasComponent00
static int tolua_SceneLuaAPI_Node_HasComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  StringHash type = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasComponent'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasComponent(type);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasComponent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_HasComponent01
static int tolua_SceneLuaAPI_Node_HasComponent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasComponent'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasComponent(type);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_HasComponent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVar of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetVar00
static int tolua_SceneLuaAPI_Node_GetVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  StringHash key = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVar'", NULL);
#endif
 {
  const Variant& tolua_ret = (const Variant&)  self->GetVar(key);
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Variant");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVars of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetVars00
static int tolua_SceneLuaAPI_Node_GetVars00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVars'", NULL);
#endif
 {
  const VariantMap& tolua_ret = (const VariantMap&)  self->GetVars();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const VariantMap");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVars'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetComponent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetComponent00
static int tolua_SceneLuaAPI_Node_GetComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetComponent'", NULL);
#endif
 {
  Component* tolua_ret = (Component*)  self->GetComponent(type,recursive);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"Component");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetParentComponent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetParentComponent00
static int tolua_SceneLuaAPI_Node_GetParentComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetParentComponent'", NULL);
#endif
 {
  Component* tolua_ret = (Component*)  self->GetParentComponent(type,recursive);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"Component");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetParentComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NodeGetComponentsWithType of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetComponents00
static int tolua_SceneLuaAPI_Node_GetComponents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NodeGetComponentsWithType'", NULL);
#endif
 {
  tolua_outside  const PODVector<Component*>& tolua_ret = (tolua_outside  const PODVector<Component*>&)  NodeGetComponentsWithType(self,type,recursive);
  ToluaPushPODVector<Component*>("",tolua_S,(void*)&tolua_ret,"Component");
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

/* method: NodeGetChildren of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetChildren00
static int tolua_SceneLuaAPI_Node_GetChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  bool recursive = ((bool)  tolua_toboolean(tolua_S,2,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NodeGetChildren'", NULL);
#endif
 {
  tolua_outside  const PODVector<Node*>& tolua_ret = (tolua_outside  const PODVector<Node*>&)  NodeGetChildren(self,recursive);
  ToluaPushPODVector<Node*>("",tolua_S,(void*)&tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NodeGetChildrenWithComponent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetChildrenWithComponent00
static int tolua_SceneLuaAPI_Node_GetChildrenWithComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NodeGetChildrenWithComponent'", NULL);
#endif
 {
  tolua_outside  const PODVector<Node*>& tolua_ret = (tolua_outside  const PODVector<Node*>&)  NodeGetChildrenWithComponent(self,type,recursive);
  ToluaPushPODVector<Node*>("",tolua_S,(void*)&tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetChildrenWithComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Load of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_Load00
static int tolua_SceneLuaAPI_Node_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Deserializer",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"SceneResolver",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
 !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Deserializer* source = ((Deserializer*)  tolua_tousertype(tolua_S,2,0));
  SceneResolver* resolver = ((SceneResolver*)  tolua_tousertype(tolua_S,3,0));
  bool loadChildren = ((bool)  tolua_toboolean(tolua_S,4,true));
  bool rewriteIDs = ((bool)  tolua_toboolean(tolua_S,5,false));
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,6,REPLICATED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Load'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Load(*source,*resolver,loadChildren,rewriteIDs,mode);
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

/* method: LoadXML of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_LoadXML00
static int tolua_SceneLuaAPI_Node_LoadXML00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const XMLElement",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"SceneResolver",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
 !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const XMLElement* source = ((const XMLElement*)  tolua_tousertype(tolua_S,2,0));
  SceneResolver* resolver = ((SceneResolver*)  tolua_tousertype(tolua_S,3,0));
  bool loadChildren = ((bool)  tolua_toboolean(tolua_S,4,true));
  bool rewriteIDs = ((bool)  tolua_toboolean(tolua_S,5,false));
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,6,REPLICATED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadXML'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->LoadXML(*source,*resolver,loadChildren,rewriteIDs,mode);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadXML'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadJSON of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_LoadJSON00
static int tolua_SceneLuaAPI_Node_LoadJSON00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const JSONValue",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"SceneResolver",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
 !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  const JSONValue* source = ((const JSONValue*)  tolua_tousertype(tolua_S,2,0));
  SceneResolver* resolver = ((SceneResolver*)  tolua_tousertype(tolua_S,3,0));
  bool loadChildren = ((bool)  tolua_toboolean(tolua_S,4,true));
  bool rewriteIDs = ((bool)  tolua_toboolean(tolua_S,5,false));
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,6,REPLICATED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadJSON'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->LoadJSON(*source,*resolver,loadChildren,rewriteIDs,mode);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadJSON'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateChild of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_CreateChild01
static int tolua_SceneLuaAPI_Node_CreateChild01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,3,0));
  bool temporary = ((bool)  tolua_toboolean(tolua_S,4,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateChild'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->CreateChild(id,mode,temporary);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Node_CreateChild00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddComponent of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_AddComponent00
static int tolua_SceneLuaAPI_Node_AddComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  Component* component = ((Component*)  tolua_tousertype(tolua_S,2,0));
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,3,0));
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddComponent'", NULL);
#endif
 {
  self->AddComponent(component,id,mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasTag of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_HasTag00
static int tolua_SceneLuaAPI_Node_HasTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  const String tag = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasTag'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasTag(tag);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasTag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTags of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetTags00
static int tolua_SceneLuaAPI_Node_GetTags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTags'", NULL);
#endif
 {
  const StringVector& tolua_ret = (const StringVector&)  self->GetTags();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const StringVector");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTags'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NodeGetChildrenWithTag of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_GetChildrenWithTag00
static int tolua_SceneLuaAPI_Node_GetChildrenWithTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
  const String tag = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NodeGetChildrenWithTag'", NULL);
#endif
 {
  tolua_outside  const PODVector<Node*>& tolua_ret = (tolua_outside  const PODVector<Node*>&)  NodeGetChildrenWithTag(self,tag,recursive);
  ToluaPushPODVector<Node*>("",tolua_S,(void*)&tolua_ret,"Node");
 tolua_pushurho3dstring(tolua_S,(const char*)tag);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetChildrenWithTag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetID of class  Node */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Node_SetID00
static int tolua_SceneLuaAPI_Node_SetID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetID'", NULL);
#endif
 {
  self->SetID(id);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ID of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_ID
static int tolua_get_Node_ID(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ID'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetID());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: replicated of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_replicated
static int tolua_get_Node_replicated(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'replicated'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsReplicated());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_name
static int tolua_get_Node_name(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_name
static int tolua_set_Node_name(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetName(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nameHash of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_nameHash
static int tolua_get_Node_nameHash(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: parent of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_parent_ptr
static int tolua_get_Node_parent_ptr(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetParent(),"Node");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: parent of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_parent_ptr
static int tolua_set_Node_parent_ptr(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Node",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetParent(((Node*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scene of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_scene_ptr
static int tolua_get_Node_scene_ptr(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scene'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetScene(),"Scene");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: enabled of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_enabled
static int tolua_get_Node_enabled(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enabled'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsEnabled());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: enabled of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_enabled
static int tolua_set_Node_enabled(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enabled'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEnabled(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: enabledSelf of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_enabledSelf
static int tolua_get_Node_enabledSelf(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enabledSelf'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsEnabledSelf());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: owner of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_owner_ptr
static int tolua_get_Node_owner_ptr(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'owner'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetOwner(),"Connection");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: owner of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_owner_ptr
static int tolua_set_Node_owner_ptr(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'owner'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Connection",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOwner(((Connection*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: position of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_position_ref
static int tolua_get_Node_position_ref(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetPosition(),"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: position of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_position_ref
static int tolua_set_Node_position_ref(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: position2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_position2D
static int tolua_get_Node_position2D(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position2D'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->GetPosition2D();
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

/* set function: position2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_position2D
static int tolua_set_Node_position2D(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position2D'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPosition2D(*((Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rotation of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_rotation_ref
static int tolua_get_Node_rotation_ref(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetRotation(),"Quaternion");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rotation of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_rotation_ref
static int tolua_set_Node_rotation_ref(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: rotation2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_rotation2D
static int tolua_get_Node_rotation2D(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation2D'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRotation2D());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rotation2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_rotation2D
static int tolua_set_Node_rotation2D(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation2D'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRotation2D(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: direction of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_direction
static int tolua_get_Node_direction(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'direction'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetDirection();
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

/* set function: direction of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_direction
static int tolua_set_Node_direction(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'direction'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDirection(*((Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: up of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_up
static int tolua_get_Node_up(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'up'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetUp();
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

/* get function: right of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_right
static int tolua_get_Node_right(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'right'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetRight();
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

/* get function: scale of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_scale_ref
static int tolua_get_Node_scale_ref(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetScale(),"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scale of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_scale_ref
static int tolua_set_Node_scale_ref(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetScale((*(Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scale2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_scale2D
static int tolua_get_Node_scale2D(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale2D'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->GetScale2D();
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

/* set function: scale2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_scale2D
static int tolua_set_Node_scale2D(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale2D'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetScale2D(*((Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: transform of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_transform
static int tolua_get_Node_transform(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'transform'",NULL);
#endif
 Matrix3x4 tolua_ret = (Matrix3x4)self->GetTransform();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((Matrix3x4)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix3x4));
 tolua_pushusertype(tolua_S,tolua_obj,"Matrix3x4");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: worldPosition of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_worldPosition
static int tolua_get_Node_worldPosition(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
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

/* set function: worldPosition of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_worldPosition
static int tolua_set_Node_worldPosition(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: worldPosition2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_worldPosition2D
static int tolua_get_Node_worldPosition2D(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldPosition2D'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->GetWorldPosition2D();
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

/* set function: worldPosition2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_worldPosition2D
static int tolua_set_Node_worldPosition2D(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldPosition2D'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetWorldPosition2D(*((Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: worldRotation of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_worldRotation
static int tolua_get_Node_worldRotation(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldRotation'",NULL);
#endif
 Quaternion tolua_ret = (Quaternion)self->GetWorldRotation();
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

/* set function: worldRotation of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_worldRotation
static int tolua_set_Node_worldRotation(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldRotation'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetWorldRotation(*((Quaternion*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: worldRotation2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_worldRotation2D
static int tolua_get_Node_worldRotation2D(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldRotation2D'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetWorldRotation2D());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: worldRotation2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_worldRotation2D
static int tolua_set_Node_worldRotation2D(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldRotation2D'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetWorldRotation2D(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: worldDirection of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_worldDirection
static int tolua_get_Node_worldDirection(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldDirection'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetWorldDirection();
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

/* set function: worldDirection of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_worldDirection
static int tolua_set_Node_worldDirection(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldDirection'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetWorldDirection(*((Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: worldUp of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_worldUp
static int tolua_get_Node_worldUp(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldUp'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetWorldUp();
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

/* get function: worldRight of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_worldRight
static int tolua_get_Node_worldRight(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldRight'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetWorldRight();
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

/* get function: worldScale of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_worldScale
static int tolua_get_Node_worldScale(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldScale'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetWorldScale();
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

/* set function: worldScale of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_worldScale
static int tolua_set_Node_worldScale(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldScale'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetWorldScale(*((Vector3*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: signedWorldScale of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_signedWorldScale
static int tolua_get_Node_signedWorldScale(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'signedWorldScale'",NULL);
#endif
 Vector3 tolua_ret = (Vector3)self->GetSignedWorldScale();
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

/* get function: worldScale2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_worldScale2D
static int tolua_get_Node_worldScale2D(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldScale2D'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->GetWorldScale2D();
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

/* set function: worldScale2D of class  Node */
#ifndef TOLUA_DISABLE_tolua_set_Node_worldScale2D
static int tolua_set_Node_worldScale2D(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldScale2D'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetWorldScale2D(*((Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: worldTransform of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_worldTransform_ref
static int tolua_get_Node_worldTransform_ref(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'worldTransform'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetWorldTransform(),"Matrix3x4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dirty of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_dirty
static int tolua_get_Node_dirty(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dirty'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsDirty());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numComponents of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_numComponents
static int tolua_get_Node_numComponents(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numComponents'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumComponents());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numNetworkComponents of class  Node */
#ifndef TOLUA_DISABLE_tolua_get_Node_numNetworkComponents
static int tolua_get_Node_numNetworkComponents(lua_State* tolua_S)
{
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numNetworkComponents'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumNetworkComponents());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FIRST_REPLICATED_ID */
#ifndef TOLUA_DISABLE_tolua_get_FIRST_REPLICATED_ID
static int tolua_get_FIRST_REPLICATED_ID(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)FIRST_REPLICATED_ID);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LAST_REPLICATED_ID */
#ifndef TOLUA_DISABLE_tolua_get_LAST_REPLICATED_ID
static int tolua_get_LAST_REPLICATED_ID(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)LAST_REPLICATED_ID);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: FIRST_LOCAL_ID */
#ifndef TOLUA_DISABLE_tolua_get_FIRST_LOCAL_ID
static int tolua_get_FIRST_LOCAL_ID(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)FIRST_LOCAL_ID);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LAST_LOCAL_ID */
#ifndef TOLUA_DISABLE_tolua_get_LAST_LOCAL_ID
static int tolua_get_LAST_LOCAL_ID(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)LAST_LOCAL_ID);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_new00
static int tolua_SceneLuaAPI_Scene_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Scene* tolua_ret = (Scene*)  Mtolua_new((Scene)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Scene");
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

/* method: new_local of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_new00_local
static int tolua_SceneLuaAPI_Scene_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Scene* tolua_ret = (Scene*)  Mtolua_new((Scene)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Scene");
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

/* method: delete of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_delete00
static int tolua_SceneLuaAPI_Scene_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SceneLoad of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_Load00
static int tolua_SceneLuaAPI_Scene_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  File* source = ((File*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneLoad'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SceneLoad(self,source);
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

/* method: SceneSave of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_Save00
static int tolua_SceneLuaAPI_Scene_Save00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
  File* dest = ((File*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneSave'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SceneSave(self,dest);
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

/* method: SceneLoad of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_Load01
static int tolua_SceneLuaAPI_Scene_Load01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneLoad'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SceneLoad(self,fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Scene_Load00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneSave of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_Save01
static int tolua_SceneLuaAPI_Scene_Save01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneSave'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SceneSave(self,fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Scene_Save00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneLoadXML of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_LoadXML00
static int tolua_SceneLuaAPI_Scene_LoadXML00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  File* source = ((File*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneLoadXML'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SceneLoadXML(self,source);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadXML'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneSaveXML of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_SaveXML00
static int tolua_SceneLuaAPI_Scene_SaveXML00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
  File* dest = ((File*)  tolua_tousertype(tolua_S,2,0));
  const String indentation = ((const String)  tolua_tourho3dstring(tolua_S,3,"\t"));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneSaveXML'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SceneSaveXML(self,dest,indentation);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveXML'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneLoadXML of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_LoadXML01
static int tolua_SceneLuaAPI_Scene_LoadXML01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneLoadXML'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SceneLoadXML(self,fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Scene_LoadXML00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneSaveXML of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_SaveXML01
static int tolua_SceneLuaAPI_Scene_SaveXML01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String indentation = ((const String)  tolua_tourho3dstring(tolua_S,3,"\t"));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneSaveXML'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SceneSaveXML(self,fileName,indentation);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Scene_SaveXML00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneLoadJSON of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_LoadJSON00
static int tolua_SceneLuaAPI_Scene_LoadJSON00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  File* source = ((File*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneLoadJSON'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SceneLoadJSON(self,source);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadJSON'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneSaveJSON of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_SaveJSON00
static int tolua_SceneLuaAPI_Scene_SaveJSON00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
  File* dest = ((File*)  tolua_tousertype(tolua_S,2,0));
  const String indentation = ((const String)  tolua_tourho3dstring(tolua_S,3,"\t"));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneSaveJSON'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SceneSaveJSON(self,dest,indentation);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveJSON'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneLoadJSON of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_LoadJSON01
static int tolua_SceneLuaAPI_Scene_LoadJSON01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneLoadJSON'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SceneLoadJSON(self,fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Scene_LoadJSON00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneSaveJSON of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_SaveJSON01
static int tolua_SceneLuaAPI_Scene_SaveJSON01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String indentation = ((const String)  tolua_tourho3dstring(tolua_S,3,"\t"));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneSaveJSON'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SceneSaveJSON(self,fileName,indentation);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Scene_SaveJSON00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneInstantiate of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_Instantiate00
static int tolua_SceneLuaAPI_Scene_Instantiate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  File* source = ((File*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,4,0));
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,5,REPLICATED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneInstantiate'", NULL);
#endif
 {
  tolua_outside Node* tolua_ret = (tolua_outside Node*)  SceneInstantiate(self,source,*position,*rotation,mode);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instantiate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneInstantiate of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_Instantiate01
static int tolua_SceneLuaAPI_Scene_Instantiate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,4,0));
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,5,REPLICATED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneInstantiate'", NULL);
#endif
 {
  tolua_outside Node* tolua_ret = (tolua_outside Node*)  SceneInstantiate(self,fileName,*position,*rotation,mode);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Scene_Instantiate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneInstantiateXML of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_InstantiateXML00
static int tolua_SceneLuaAPI_Scene_InstantiateXML00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  File* source = ((File*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,4,0));
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,5,REPLICATED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneInstantiateXML'", NULL);
#endif
 {
  tolua_outside Node* tolua_ret = (tolua_outside Node*)  SceneInstantiateXML(self,source,*position,*rotation,mode);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InstantiateXML'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneInstantiateXML of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_InstantiateXML01
static int tolua_SceneLuaAPI_Scene_InstantiateXML01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,4,0));
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,5,REPLICATED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneInstantiateXML'", NULL);
#endif
 {
  tolua_outside Node* tolua_ret = (tolua_outside Node*)  SceneInstantiateXML(self,fileName,*position,*rotation,mode);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Scene_InstantiateXML00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneInstantiateJSON of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_InstantiateJSON00
static int tolua_SceneLuaAPI_Scene_InstantiateJSON00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Vector3* position = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Quaternion* rotation = ((const Quaternion*)  tolua_tousertype(tolua_S,4,0));
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,5,REPLICATED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneInstantiateJSON'", NULL);
#endif
 {
  tolua_outside Node* tolua_ret = (tolua_outside Node*)  SceneInstantiateJSON(self,fileName,*position,*rotation,mode);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InstantiateJSON'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadAsync of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_LoadAsync00
static int tolua_SceneLuaAPI_Scene_LoadAsync00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  File* file = ((File*)  tolua_tousertype(tolua_S,2,0));
  LoadMode mode = ((LoadMode) (int)  tolua_tonumber(tolua_S,3,LOAD_SCENE_AND_RESOURCES));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadAsync'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->LoadAsync(file,mode);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadAsync'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadAsyncXML of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_LoadAsyncXML00
static int tolua_SceneLuaAPI_Scene_LoadAsyncXML00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  File* file = ((File*)  tolua_tousertype(tolua_S,2,0));
  LoadMode mode = ((LoadMode) (int)  tolua_tonumber(tolua_S,3,LOAD_SCENE_AND_RESOURCES));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadAsyncXML'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->LoadAsyncXML(file,mode);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadAsyncXML'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneLoadAsync of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_LoadAsync01
static int tolua_SceneLuaAPI_Scene_LoadAsync01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  LoadMode mode = ((LoadMode) (int)  tolua_tonumber(tolua_S,3,LOAD_SCENE_AND_RESOURCES));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneLoadAsync'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SceneLoadAsync(self,fileName,mode);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Scene_LoadAsync00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneLoadAsyncXML of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_LoadAsyncXML01
static int tolua_SceneLuaAPI_Scene_LoadAsyncXML01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  LoadMode mode = ((LoadMode) (int)  tolua_tonumber(tolua_S,3,LOAD_SCENE_AND_RESOURCES));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneLoadAsyncXML'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SceneLoadAsyncXML(self,fileName,mode);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Scene_LoadAsyncXML00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: StopAsyncLoading of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_StopAsyncLoading00
static int tolua_SceneLuaAPI_Scene_StopAsyncLoading00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StopAsyncLoading'", NULL);
#endif
 {
  self->StopAsyncLoading();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StopAsyncLoading'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_Clear00
static int tolua_SceneLuaAPI_Scene_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  bool clearReplicated = ((bool)  tolua_toboolean(tolua_S,2,true));
  bool clearLocal = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
 {
  self->Clear(clearReplicated,clearLocal);
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

/* method: SetUpdateEnabled of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_SetUpdateEnabled00
static int tolua_SceneLuaAPI_Scene_SetUpdateEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetTimeScale of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_SetTimeScale00
static int tolua_SceneLuaAPI_Scene_SetTimeScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  float scale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTimeScale'", NULL);
#endif
 {
  self->SetTimeScale(scale);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTimeScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetElapsedTime of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_SetElapsedTime00
static int tolua_SceneLuaAPI_Scene_SetElapsedTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  float time = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetElapsedTime'", NULL);
#endif
 {
  self->SetElapsedTime(time);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetElapsedTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSmoothingConstant of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_SetSmoothingConstant00
static int tolua_SceneLuaAPI_Scene_SetSmoothingConstant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  float constant = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSmoothingConstant'", NULL);
#endif
 {
  self->SetSmoothingConstant(constant);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSmoothingConstant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSnapThreshold of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_SetSnapThreshold00
static int tolua_SceneLuaAPI_Scene_SetSnapThreshold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  float threshold = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSnapThreshold'", NULL);
#endif
 {
  self->SetSnapThreshold(threshold);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSnapThreshold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAsyncLoadingMs of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_SetAsyncLoadingMs00
static int tolua_SceneLuaAPI_Scene_SetAsyncLoadingMs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  int ms = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAsyncLoadingMs'", NULL);
#endif
 {
  self->SetAsyncLoadingMs(ms);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAsyncLoadingMs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNode of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetNode00
static int tolua_SceneLuaAPI_Scene_GetNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNode'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->GetNode(id);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetComponent of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetComponent00
static int tolua_SceneLuaAPI_Scene_GetComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetComponent'", NULL);
#endif
 {
  Component* tolua_ret = (Component*)  self->GetComponent(id);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"Component");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetComponent of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetComponent01
static int tolua_SceneLuaAPI_Scene_GetComponent01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetComponent'", NULL);
#endif
 {
  Component* tolua_ret = (Component*)  self->GetComponent(type,recursive);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"Component");
 }
 }
 return 1;
tolua_lerror:
 return tolua_SceneLuaAPI_Scene_GetComponent00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsReplicatedID of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_IsReplicatedID00
static int tolua_SceneLuaAPI_Scene_IsReplicatedID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned id = ((unsigned)  tolua_tonumber(tolua_S,2,0));
 {
  bool tolua_ret = (bool)  Scene::IsReplicatedID(id);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsReplicatedID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsUpdateEnabled of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_IsUpdateEnabled00
static int tolua_SceneLuaAPI_Scene_IsUpdateEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsAsyncLoading of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_IsAsyncLoading00
static int tolua_SceneLuaAPI_Scene_IsAsyncLoading00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsAsyncLoading'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsAsyncLoading();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsAsyncLoading'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAsyncProgress of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetAsyncProgress00
static int tolua_SceneLuaAPI_Scene_GetAsyncProgress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAsyncProgress'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAsyncProgress();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAsyncProgress'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAsyncLoadMode of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetAsyncLoadMode00
static int tolua_SceneLuaAPI_Scene_GetAsyncLoadMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAsyncLoadMode'", NULL);
#endif
 {
  LoadMode tolua_ret = (LoadMode)  self->GetAsyncLoadMode();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAsyncLoadMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFileName of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetFileName00
static int tolua_SceneLuaAPI_Scene_GetFileName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFileName'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetFileName();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFileName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetChecksum of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetChecksum00
static int tolua_SceneLuaAPI_Scene_GetChecksum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChecksum'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetChecksum();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetChecksum'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTimeScale of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetTimeScale00
static int tolua_SceneLuaAPI_Scene_GetTimeScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTimeScale'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetTimeScale();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimeScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetElapsedTime of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetElapsedTime00
static int tolua_SceneLuaAPI_Scene_GetElapsedTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetSmoothingConstant of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetSmoothingConstant00
static int tolua_SceneLuaAPI_Scene_GetSmoothingConstant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSmoothingConstant'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetSmoothingConstant();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSmoothingConstant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSnapThreshold of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetSnapThreshold00
static int tolua_SceneLuaAPI_Scene_GetSnapThreshold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSnapThreshold'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetSnapThreshold();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSnapThreshold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAsyncLoadingMs of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetAsyncLoadingMs00
static int tolua_SceneLuaAPI_Scene_GetAsyncLoadingMs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAsyncLoadingMs'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetAsyncLoadingMs();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAsyncLoadingMs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVarName of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetVarName00
static int tolua_SceneLuaAPI_Scene_GetVarName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
  StringHash hash = *((StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVarName'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetVarName(hash);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVarName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_Update00
static int tolua_SceneLuaAPI_Scene_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
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

/* method: BeginThreadedUpdate of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_BeginThreadedUpdate00
static int tolua_SceneLuaAPI_Scene_BeginThreadedUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BeginThreadedUpdate'", NULL);
#endif
 {
  self->BeginThreadedUpdate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BeginThreadedUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: EndThreadedUpdate of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_EndThreadedUpdate00
static int tolua_SceneLuaAPI_Scene_EndThreadedUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'EndThreadedUpdate'", NULL);
#endif
 {
  self->EndThreadedUpdate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EndThreadedUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DelayedMarkedDirty of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_DelayedMarkedDirty00
static int tolua_SceneLuaAPI_Scene_DelayedMarkedDirty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  Component* component = ((Component*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DelayedMarkedDirty'", NULL);
#endif
 {
  self->DelayedMarkedDirty(component);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DelayedMarkedDirty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsThreadedUpdate of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_IsThreadedUpdate00
static int tolua_SceneLuaAPI_Scene_IsThreadedUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsThreadedUpdate'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsThreadedUpdate();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsThreadedUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFreeNodeID of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetFreeNodeID00
static int tolua_SceneLuaAPI_Scene_GetFreeNodeID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFreeNodeID'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetFreeNodeID(mode);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFreeNodeID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFreeComponentID of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetFreeComponentID00
static int tolua_SceneLuaAPI_Scene_GetFreeComponentID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  CreateMode mode = ((CreateMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFreeComponentID'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetFreeComponentID(mode);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFreeComponentID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NodeAdded of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_NodeAdded00
static int tolua_SceneLuaAPI_Scene_NodeAdded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NodeAdded'", NULL);
#endif
 {
  self->NodeAdded(node);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NodeAdded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NodeRemoved of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_NodeRemoved00
static int tolua_SceneLuaAPI_Scene_NodeRemoved00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NodeRemoved'", NULL);
#endif
 {
  self->NodeRemoved(node);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NodeRemoved'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ComponentAdded of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_ComponentAdded00
static int tolua_SceneLuaAPI_Scene_ComponentAdded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  Component* component = ((Component*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ComponentAdded'", NULL);
#endif
 {
  self->ComponentAdded(component);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ComponentAdded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ComponentRemoved of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_ComponentRemoved00
static int tolua_SceneLuaAPI_Scene_ComponentRemoved00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  Component* component = ((Component*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ComponentRemoved'", NULL);
#endif
 {
  self->ComponentRemoved(component);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ComponentRemoved'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVarNamesAttr of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_SetVarNamesAttr00
static int tolua_SceneLuaAPI_Scene_SetVarNamesAttr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVarNamesAttr'", NULL);
#endif
 {
  self->SetVarNamesAttr(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVarNamesAttr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVarNamesAttr of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetVarNamesAttr00
static int tolua_SceneLuaAPI_Scene_GetVarNamesAttr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVarNamesAttr'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetVarNamesAttr();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVarNamesAttr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PrepareNetworkUpdate of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_PrepareNetworkUpdate00
static int tolua_SceneLuaAPI_Scene_PrepareNetworkUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PrepareNetworkUpdate'", NULL);
#endif
 {
  self->PrepareNetworkUpdate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PrepareNetworkUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CleanupConnection of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_CleanupConnection00
static int tolua_SceneLuaAPI_Scene_CleanupConnection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Connection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  Connection* connection = ((Connection*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CleanupConnection'", NULL);
#endif
 {
  self->CleanupConnection(connection);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CleanupConnection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MarkNetworkUpdate of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_MarkNetworkUpdate00
static int tolua_SceneLuaAPI_Scene_MarkNetworkUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MarkNetworkUpdate'", NULL);
#endif
 {
  self->MarkNetworkUpdate(node);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MarkNetworkUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MarkNetworkUpdate of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_MarkNetworkUpdate01
static int tolua_SceneLuaAPI_Scene_MarkNetworkUpdate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  Component* component = ((Component*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MarkNetworkUpdate'", NULL);
#endif
 {
  self->MarkNetworkUpdate(component);
 }
 }
 return 0;
tolua_lerror:
 return tolua_SceneLuaAPI_Scene_MarkNetworkUpdate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: MarkReplicationDirty of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_MarkReplicationDirty00
static int tolua_SceneLuaAPI_Scene_MarkReplicationDirty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  Node* node = ((Node*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MarkReplicationDirty'", NULL);
#endif
 {
  self->MarkReplicationDirty(node);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MarkReplicationDirty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SceneGetNodesWithTag of class  Scene */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_Scene_GetNodesWithTag00
static int tolua_SceneLuaAPI_Scene_GetNodesWithTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Scene",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Scene* self = (const Scene*)  tolua_tousertype(tolua_S,1,0);
  const String tag = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SceneGetNodesWithTag'", NULL);
#endif
 {
  tolua_outside  const PODVector<Node*>& tolua_ret = (tolua_outside  const PODVector<Node*>&)  SceneGetNodesWithTag(self,tag);
  ToluaPushPODVector<Node*>("",tolua_S,(void*)&tolua_ret,"Node");
 tolua_pushurho3dstring(tolua_S,(const char*)tag);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNodesWithTag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: updateEnabled of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_updateEnabled
static int tolua_get_Scene_updateEnabled(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'updateEnabled'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsUpdateEnabled());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: updateEnabled of class  Scene */
#ifndef TOLUA_DISABLE_tolua_set_Scene_updateEnabled
static int tolua_set_Scene_updateEnabled(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: asyncLoading of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_asyncLoading
static int tolua_get_Scene_asyncLoading(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'asyncLoading'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsAsyncLoading());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: asyncProgress of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_asyncProgress
static int tolua_get_Scene_asyncProgress(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'asyncProgress'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAsyncProgress());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: asyncLoadMode of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_asyncLoadMode
static int tolua_get_Scene_asyncLoadMode(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'asyncLoadMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAsyncLoadMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fileName of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_fileName
static int tolua_get_Scene_fileName(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fileName'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetFileName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: checksum of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_checksum
static int tolua_get_Scene_checksum(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'checksum'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetChecksum());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: timeScale of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_timeScale
static int tolua_get_Scene_timeScale(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeScale'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTimeScale());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: timeScale of class  Scene */
#ifndef TOLUA_DISABLE_tolua_set_Scene_timeScale
static int tolua_set_Scene_timeScale(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeScale'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTimeScale(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: elapsedTime of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_elapsedTime
static int tolua_get_Scene_elapsedTime(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'elapsedTime'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetElapsedTime());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: elapsedTime of class  Scene */
#ifndef TOLUA_DISABLE_tolua_set_Scene_elapsedTime
static int tolua_set_Scene_elapsedTime(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'elapsedTime'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetElapsedTime(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: smoothingConstant of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_smoothingConstant
static int tolua_get_Scene_smoothingConstant(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'smoothingConstant'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSmoothingConstant());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: smoothingConstant of class  Scene */
#ifndef TOLUA_DISABLE_tolua_set_Scene_smoothingConstant
static int tolua_set_Scene_smoothingConstant(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'smoothingConstant'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSmoothingConstant(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: snapThreshold of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_snapThreshold
static int tolua_get_Scene_snapThreshold(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'snapThreshold'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSnapThreshold());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: snapThreshold of class  Scene */
#ifndef TOLUA_DISABLE_tolua_set_Scene_snapThreshold
static int tolua_set_Scene_snapThreshold(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'snapThreshold'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSnapThreshold(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: asyncLoadingMs of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_asyncLoadingMs
static int tolua_get_Scene_asyncLoadingMs(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'asyncLoadingMs'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAsyncLoadingMs());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: asyncLoadingMs of class  Scene */
#ifndef TOLUA_DISABLE_tolua_set_Scene_asyncLoadingMs
static int tolua_set_Scene_asyncLoadingMs(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'asyncLoadingMs'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAsyncLoadingMs(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: threadedUpdate of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_threadedUpdate
static int tolua_get_Scene_threadedUpdate(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'threadedUpdate'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsThreadedUpdate());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: varNamesAttr of class  Scene */
#ifndef TOLUA_DISABLE_tolua_get_Scene_varNamesAttr
static int tolua_get_Scene_varNamesAttr(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'varNamesAttr'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetVarNamesAttr());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: varNamesAttr of class  Scene */
#ifndef TOLUA_DISABLE_tolua_set_Scene_varNamesAttr
static int tolua_set_Scene_varNamesAttr(lua_State* tolua_S)
{
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'varNamesAttr'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetVarNamesAttr(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddControlPoint of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_SplinePath_AddControlPoint00
static int tolua_SceneLuaAPI_SplinePath_AddControlPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SplinePath",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SplinePath* self = (SplinePath*)  tolua_tousertype(tolua_S,1,0);
  Node* point = ((Node*)  tolua_tousertype(tolua_S,2,0));
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,3,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddControlPoint'", NULL);
#endif
 {
  self->AddControlPoint(point,index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddControlPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveControlPoint of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_SplinePath_RemoveControlPoint00
static int tolua_SceneLuaAPI_SplinePath_RemoveControlPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SplinePath",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SplinePath* self = (SplinePath*)  tolua_tousertype(tolua_S,1,0);
  Node* point = ((Node*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveControlPoint'", NULL);
#endif
 {
  self->RemoveControlPoint(point);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveControlPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearControlPoints of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_SplinePath_ClearControlPoints00
static int tolua_SceneLuaAPI_SplinePath_ClearControlPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SplinePath",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SplinePath* self = (SplinePath*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearControlPoints'", NULL);
#endif
 {
  self->ClearControlPoints();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearControlPoints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetInterpolationMode of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_SplinePath_SetInterpolationMode00
static int tolua_SceneLuaAPI_SplinePath_SetInterpolationMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SplinePath",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"InterpolationMode",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SplinePath* self = (SplinePath*)  tolua_tousertype(tolua_S,1,0);
  InterpolationMode mode = *((InterpolationMode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInterpolationMode'", NULL);
#endif
 {
  self->SetInterpolationMode(mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInterpolationMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_SplinePath_SetPosition00
static int tolua_SceneLuaAPI_SplinePath_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SplinePath",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SplinePath* self = (SplinePath*)  tolua_tousertype(tolua_S,1,0);
  float factor = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
 {
  self->SetPosition(factor);
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

/* method: SetControlledNode of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_SplinePath_SetControlledNode00
static int tolua_SceneLuaAPI_SplinePath_SetControlledNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SplinePath",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SplinePath* self = (SplinePath*)  tolua_tousertype(tolua_S,1,0);
  Node* controlled = ((Node*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetControlledNode'", NULL);
#endif
 {
  self->SetControlledNode(controlled);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetControlledNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInterpolationMode of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_SplinePath_GetInterpolationMode00
static int tolua_SceneLuaAPI_SplinePath_GetInterpolationMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SplinePath",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SplinePath* self = (const SplinePath*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInterpolationMode'", NULL);
#endif
 {
  InterpolationMode tolua_ret = (InterpolationMode)  self->GetInterpolationMode();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((InterpolationMode)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"InterpolationMode");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(InterpolationMode));
  tolua_pushusertype(tolua_S,tolua_obj,"InterpolationMode");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInterpolationMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSpeed of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_SplinePath_GetSpeed00
static int tolua_SceneLuaAPI_SplinePath_GetSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SplinePath",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SplinePath* self = (const SplinePath*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetLength of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_SplinePath_GetLength00
static int tolua_SceneLuaAPI_SplinePath_GetLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SplinePath",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SplinePath* self = (const SplinePath*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetPosition of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_SplinePath_GetPosition00
static int tolua_SceneLuaAPI_SplinePath_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SplinePath",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SplinePath* self = (const SplinePath*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetControlledNode of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_SplinePath_GetControlledNode00
static int tolua_SceneLuaAPI_SplinePath_GetControlledNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SplinePath",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SplinePath* self = (const SplinePath*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetControlledNode'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->GetControlledNode();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetControlledNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPoint of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_SplinePath_GetPoint00
static int tolua_SceneLuaAPI_SplinePath_GetPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SplinePath",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SplinePath* self = (const SplinePath*)  tolua_tousertype(tolua_S,1,0);
  float factor = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPoint'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->GetPoint(factor);
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
 tolua_error(tolua_S,"#ferror in function 'GetPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Move of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_SplinePath_Move00
static int tolua_SceneLuaAPI_SplinePath_Move00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SplinePath",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SplinePath* self = (SplinePath*)  tolua_tousertype(tolua_S,1,0);
  float timeStep = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Move'", NULL);
#endif
 {
  self->Move(timeStep);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Move'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Reset of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_SplinePath_Reset00
static int tolua_SceneLuaAPI_SplinePath_Reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SplinePath",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SplinePath* self = (SplinePath*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsFinished of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_SceneLuaAPI_SplinePath_IsFinished00
static int tolua_SceneLuaAPI_SplinePath_IsFinished00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SplinePath",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SplinePath* self = (const SplinePath*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsFinished'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsFinished();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsFinished'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: interpolationMode of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_get_SplinePath_interpolationMode
static int tolua_get_SplinePath_interpolationMode(lua_State* tolua_S)
{
  SplinePath* self = (SplinePath*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'interpolationMode'",NULL);
#endif
 InterpolationMode tolua_ret = (InterpolationMode)self->GetInterpolationMode();
 #ifdef __cplusplus
 void* tolua_obj = (void*)Mtolua_new((InterpolationMode)(tolua_ret));
 tolua_pushusertype(tolua_S,tolua_obj,"InterpolationMode");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(InterpolationMode));
 tolua_pushusertype(tolua_S,tolua_obj,"InterpolationMode");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 #endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: interpolationMode of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_set_SplinePath_interpolationMode
static int tolua_set_SplinePath_interpolationMode(lua_State* tolua_S)
{
  SplinePath* self = (SplinePath*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'interpolationMode'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"InterpolationMode",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetInterpolationMode(*((InterpolationMode*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: speed of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_get_SplinePath_speed
static int tolua_get_SplinePath_speed(lua_State* tolua_S)
{
  SplinePath* self = (SplinePath*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'speed'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSpeed());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: speed of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_set_SplinePath_speed
static int tolua_set_SplinePath_speed(lua_State* tolua_S)
{
  SplinePath* self = (SplinePath*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: length of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_get_SplinePath_length
static int tolua_get_SplinePath_length(lua_State* tolua_S)
{
  SplinePath* self = (SplinePath*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'length'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLength());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: controlledNode of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_get_SplinePath_controlledNode_ptr
static int tolua_get_SplinePath_controlledNode_ptr(lua_State* tolua_S)
{
  SplinePath* self = (SplinePath*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'controlledNode'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetControlledNode(),"Node");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: controlledNode of class  SplinePath */
#ifndef TOLUA_DISABLE_tolua_set_SplinePath_controlledNode_ptr
static int tolua_set_SplinePath_controlledNode_ptr(lua_State* tolua_S)
{
  SplinePath* self = (SplinePath*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'controlledNode'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Node",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetControlledNode(((Node*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_SceneLuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
 tolua_constant(tolua_S,"IM_NONE",IM_NONE);
 tolua_constant(tolua_S,"IM_LINEAR",IM_LINEAR);
 tolua_constant(tolua_S,"IM_SPLINE",IM_SPLINE);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"ValueAnimation","ValueAnimation","Resource",tolua_collect_ValueAnimation);
 #else
 tolua_cclass(tolua_S,"ValueAnimation","ValueAnimation","Resource",NULL);
 #endif
 tolua_beginmodule(tolua_S,"ValueAnimation");
  tolua_function(tolua_S,"new",tolua_SceneLuaAPI_ValueAnimation_new00);
  tolua_function(tolua_S,"new_local",tolua_SceneLuaAPI_ValueAnimation_new00_local);
  tolua_function(tolua_S,".call",tolua_SceneLuaAPI_ValueAnimation_new00_local);
  tolua_function(tolua_S,"delete",tolua_SceneLuaAPI_ValueAnimation_delete00);
  tolua_function(tolua_S,"SetInterpolationMethod",tolua_SceneLuaAPI_ValueAnimation_SetInterpolationMethod00);
  tolua_function(tolua_S,"SetSplineTension",tolua_SceneLuaAPI_ValueAnimation_SetSplineTension00);
  tolua_function(tolua_S,"SetValueType",tolua_SceneLuaAPI_ValueAnimation_SetValueType00);
  tolua_function(tolua_S,"SetKeyFrame",tolua_SceneLuaAPI_ValueAnimation_SetKeyFrame00);
  tolua_function(tolua_S,"SetEventFrame",tolua_SceneLuaAPI_ValueAnimation_SetEventFrame00);
  tolua_function(tolua_S,"SetEventFrame",tolua_SceneLuaAPI_ValueAnimation_SetEventFrame01);
  tolua_function(tolua_S,"GetInterpolationMethod",tolua_SceneLuaAPI_ValueAnimation_GetInterpolationMethod00);
  tolua_function(tolua_S,"GetSplineTension",tolua_SceneLuaAPI_ValueAnimation_GetSplineTension00);
  tolua_function(tolua_S,"GetValueType",tolua_SceneLuaAPI_ValueAnimation_GetValueType00);
  tolua_variable(tolua_S,"interpolationMethod",tolua_get_ValueAnimation_interpolationMethod,tolua_set_ValueAnimation_interpolationMethod);
  tolua_variable(tolua_S,"splineTension",tolua_get_ValueAnimation_splineTension,tolua_set_ValueAnimation_splineTension);
  tolua_variable(tolua_S,"valueType",tolua_get_ValueAnimation_valueType,tolua_set_ValueAnimation_valueType);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"WM_LOOP",WM_LOOP);
 tolua_constant(tolua_S,"WM_ONCE",WM_ONCE);
 tolua_constant(tolua_S,"WM_CLAMP",WM_CLAMP);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"ObjectAnimation","ObjectAnimation","Resource",tolua_collect_ObjectAnimation);
 #else
 tolua_cclass(tolua_S,"ObjectAnimation","ObjectAnimation","Resource",NULL);
 #endif
 tolua_beginmodule(tolua_S,"ObjectAnimation");
  tolua_function(tolua_S,"new",tolua_SceneLuaAPI_ObjectAnimation_new00);
  tolua_function(tolua_S,"new_local",tolua_SceneLuaAPI_ObjectAnimation_new00_local);
  tolua_function(tolua_S,".call",tolua_SceneLuaAPI_ObjectAnimation_new00_local);
  tolua_function(tolua_S,"delete",tolua_SceneLuaAPI_ObjectAnimation_delete00);
  tolua_function(tolua_S,"AddAttributeAnimation",tolua_SceneLuaAPI_ObjectAnimation_AddAttributeAnimation00);
  tolua_function(tolua_S,"RemoveAttributeAnimation",tolua_SceneLuaAPI_ObjectAnimation_RemoveAttributeAnimation00);
  tolua_function(tolua_S,"RemoveAttributeAnimation",tolua_SceneLuaAPI_ObjectAnimation_RemoveAttributeAnimation01);
  tolua_function(tolua_S,"GetAttributeAnimation",tolua_SceneLuaAPI_ObjectAnimation_GetAttributeAnimation00);
  tolua_function(tolua_S,"GetAttributeAnimationWrapMode",tolua_SceneLuaAPI_ObjectAnimation_GetAttributeAnimationWrapMode00);
  tolua_function(tolua_S,"GetAttributeAnimationSpeed",tolua_SceneLuaAPI_ObjectAnimation_GetAttributeAnimationSpeed00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Serializable","Serializable","Object",NULL);
 tolua_beginmodule(tolua_S,"Serializable");
  tolua_function(tolua_S,"SetTemporary",tolua_SceneLuaAPI_Serializable_SetTemporary00);
  tolua_function(tolua_S,"IsTemporary",tolua_SceneLuaAPI_Serializable_IsTemporary00);
  tolua_function(tolua_S,"SetInterceptNetworkUpdate",tolua_SceneLuaAPI_Serializable_SetInterceptNetworkUpdate00);
  tolua_function(tolua_S,"GetInterceptNetworkUpdate",tolua_SceneLuaAPI_Serializable_GetInterceptNetworkUpdate00);
  tolua_variable(tolua_S,"temporary",tolua_get_Serializable_temporary,tolua_set_Serializable_temporary);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Animatable","Animatable","Serializable",NULL);
 tolua_beginmodule(tolua_S,"Animatable");
  tolua_function(tolua_S,"SetAnimationEnabled",tolua_SceneLuaAPI_Animatable_SetAnimationEnabled00);
  tolua_function(tolua_S,"SetAnimationTime",tolua_SceneLuaAPI_Animatable_SetAnimationTime00);
  tolua_function(tolua_S,"SetObjectAnimation",tolua_SceneLuaAPI_Animatable_SetObjectAnimation00);
  tolua_function(tolua_S,"SetAttributeAnimation",tolua_SceneLuaAPI_Animatable_SetAttributeAnimation00);
  tolua_function(tolua_S,"SetAttributeAnimationWrapMode",tolua_SceneLuaAPI_Animatable_SetAttributeAnimationWrapMode00);
  tolua_function(tolua_S,"SetAttributeAnimationSpeed",tolua_SceneLuaAPI_Animatable_SetAttributeAnimationSpeed00);
  tolua_function(tolua_S,"SetAttributeAnimationTime",tolua_SceneLuaAPI_Animatable_SetAttributeAnimationTime00);
  tolua_function(tolua_S,"RemoveObjectAnimation",tolua_SceneLuaAPI_Animatable_RemoveObjectAnimation00);
  tolua_function(tolua_S,"RemoveAttributeAnimation",tolua_SceneLuaAPI_Animatable_RemoveAttributeAnimation00);
  tolua_function(tolua_S,"GetAnimationEnabled",tolua_SceneLuaAPI_Animatable_GetAnimationEnabled00);
  tolua_function(tolua_S,"GetObjectAnimation",tolua_SceneLuaAPI_Animatable_GetObjectAnimation00);
  tolua_function(tolua_S,"GetAttributeAnimation",tolua_SceneLuaAPI_Animatable_GetAttributeAnimation00);
  tolua_function(tolua_S,"GetAttributeAnimationWrapMode",tolua_SceneLuaAPI_Animatable_GetAttributeAnimationWrapMode00);
  tolua_function(tolua_S,"GetAttributeAnimationSpeed",tolua_SceneLuaAPI_Animatable_GetAttributeAnimationSpeed00);
  tolua_function(tolua_S,"GetAttributeAnimationTime",tolua_SceneLuaAPI_Animatable_GetAttributeAnimationTime00);
  tolua_variable(tolua_S,"animationEnabled",tolua_get_Animatable_animationEnabled,tolua_set_Animatable_animationEnabled);
  tolua_variable(tolua_S,"objectAnimation",tolua_get_Animatable_objectAnimation_ptr,tolua_set_Animatable_objectAnimation_ptr);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"REMOVE_DISABLED",REMOVE_DISABLED);
 tolua_constant(tolua_S,"REMOVE_COMPONENT",REMOVE_COMPONENT);
 tolua_constant(tolua_S,"REMOVE_NODE",REMOVE_NODE);
 tolua_cclass(tolua_S,"Component","Component","Animatable",NULL);
 tolua_beginmodule(tolua_S,"Component");
  tolua_function(tolua_S,"SetEnabled",tolua_SceneLuaAPI_Component_SetEnabled00);
  tolua_function(tolua_S,"Remove",tolua_SceneLuaAPI_Component_Remove00);
  tolua_function(tolua_S,"DrawDebugGeometry",tolua_SceneLuaAPI_Component_DrawDebugGeometry00);
  tolua_function(tolua_S,"GetID",tolua_SceneLuaAPI_Component_GetID00);
  tolua_function(tolua_S,"IsReplicated",tolua_SceneLuaAPI_Component_IsReplicated00);
  tolua_function(tolua_S,"GetNode",tolua_SceneLuaAPI_Component_GetNode00);
  tolua_function(tolua_S,"GetScene",tolua_SceneLuaAPI_Component_GetScene00);
  tolua_function(tolua_S,"IsEnabled",tolua_SceneLuaAPI_Component_IsEnabled00);
  tolua_function(tolua_S,"IsEnabledEffective",tolua_SceneLuaAPI_Component_IsEnabledEffective00);
  tolua_function(tolua_S,"GetComponent",tolua_SceneLuaAPI_Component_GetComponent00);
  tolua_function(tolua_S,"GetComponent",tolua_SceneLuaAPI_Component_GetComponent01);
  tolua_variable(tolua_S,"ID",tolua_get_Component_ID,NULL);
  tolua_variable(tolua_S,"replicated",tolua_get_Component_replicated,NULL);
  tolua_variable(tolua_S,"enabled",tolua_get_Component_enabled,tolua_set_Component_enabled);
  tolua_variable(tolua_S,"enabledEffective",tolua_get_Component_enabledEffective,NULL);
  tolua_variable(tolua_S,"node",tolua_get_Component_node_ptr,NULL);
  tolua_variable(tolua_S,"scene",tolua_get_Component_scene_ptr,NULL);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"REPLICATED",REPLICATED);
 tolua_constant(tolua_S,"LOCAL",LOCAL);
 tolua_constant(tolua_S,"TS_LOCAL",TS_LOCAL);
 tolua_constant(tolua_S,"TS_PARENT",TS_PARENT);
 tolua_constant(tolua_S,"TS_WORLD",TS_WORLD);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Node","Node","Animatable",tolua_collect_Node);
 #else
 tolua_cclass(tolua_S,"Node","Node","Animatable",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Node");
  tolua_function(tolua_S,"new",tolua_SceneLuaAPI_Node_new00);
  tolua_function(tolua_S,"new_local",tolua_SceneLuaAPI_Node_new00_local);
  tolua_function(tolua_S,".call",tolua_SceneLuaAPI_Node_new00_local);
  tolua_function(tolua_S,"delete",tolua_SceneLuaAPI_Node_delete00);
  tolua_function(tolua_S,"SaveXML",tolua_SceneLuaAPI_Node_SaveXML00);
  tolua_function(tolua_S,"SaveJSON",tolua_SceneLuaAPI_Node_SaveJSON00);
  tolua_function(tolua_S,"SetName",tolua_SceneLuaAPI_Node_SetName00);
  tolua_function(tolua_S,"AddTag",tolua_SceneLuaAPI_Node_AddTag00);
  tolua_function(tolua_S,"AddTags",tolua_SceneLuaAPI_Node_AddTags00);
  tolua_function(tolua_S,"RemoveTag",tolua_SceneLuaAPI_Node_RemoveTag00);
  tolua_function(tolua_S,"RemoveAllTags",tolua_SceneLuaAPI_Node_RemoveAllTags00);
  tolua_function(tolua_S,"SetPosition",tolua_SceneLuaAPI_Node_SetPosition00);
  tolua_function(tolua_S,"SetPosition2D",tolua_SceneLuaAPI_Node_SetPosition2D00);
  tolua_function(tolua_S,"SetPosition2D",tolua_SceneLuaAPI_Node_SetPosition2D01);
  tolua_function(tolua_S,"SetRotation",tolua_SceneLuaAPI_Node_SetRotation00);
  tolua_function(tolua_S,"SetRotation2D",tolua_SceneLuaAPI_Node_SetRotation2D00);
  tolua_function(tolua_S,"SetDirection",tolua_SceneLuaAPI_Node_SetDirection00);
  tolua_function(tolua_S,"SetScale",tolua_SceneLuaAPI_Node_SetScale00);
  tolua_function(tolua_S,"SetScale",tolua_SceneLuaAPI_Node_SetScale01);
  tolua_function(tolua_S,"SetScale2D",tolua_SceneLuaAPI_Node_SetScale2D00);
  tolua_function(tolua_S,"SetScale2D",tolua_SceneLuaAPI_Node_SetScale2D01);
  tolua_function(tolua_S,"SetTransform",tolua_SceneLuaAPI_Node_SetTransform00);
  tolua_function(tolua_S,"SetTransform",tolua_SceneLuaAPI_Node_SetTransform01);
  tolua_function(tolua_S,"SetTransform",tolua_SceneLuaAPI_Node_SetTransform02);
  tolua_function(tolua_S,"SetTransform",tolua_SceneLuaAPI_Node_SetTransform03);
  tolua_function(tolua_S,"SetTransform2D",tolua_SceneLuaAPI_Node_SetTransform2D00);
  tolua_function(tolua_S,"SetTransform2D",tolua_SceneLuaAPI_Node_SetTransform2D01);
  tolua_function(tolua_S,"SetTransform2D",tolua_SceneLuaAPI_Node_SetTransform2D02);
  tolua_function(tolua_S,"SetWorldPosition",tolua_SceneLuaAPI_Node_SetWorldPosition00);
  tolua_function(tolua_S,"SetWorldPosition2D",tolua_SceneLuaAPI_Node_SetWorldPosition2D00);
  tolua_function(tolua_S,"SetWorldPosition2D",tolua_SceneLuaAPI_Node_SetWorldPosition2D01);
  tolua_function(tolua_S,"SetWorldRotation",tolua_SceneLuaAPI_Node_SetWorldRotation00);
  tolua_function(tolua_S,"SetWorldRotation2D",tolua_SceneLuaAPI_Node_SetWorldRotation2D00);
  tolua_function(tolua_S,"SetWorldDirection",tolua_SceneLuaAPI_Node_SetWorldDirection00);
  tolua_function(tolua_S,"SetWorldScale",tolua_SceneLuaAPI_Node_SetWorldScale00);
  tolua_function(tolua_S,"SetWorldScale",tolua_SceneLuaAPI_Node_SetWorldScale01);
  tolua_function(tolua_S,"SetWorldScale2D",tolua_SceneLuaAPI_Node_SetWorldScale2D00);
  tolua_function(tolua_S,"SetWorldScale2D",tolua_SceneLuaAPI_Node_SetWorldScale2D01);
  tolua_function(tolua_S,"SetWorldTransform",tolua_SceneLuaAPI_Node_SetWorldTransform00);
  tolua_function(tolua_S,"SetWorldTransform",tolua_SceneLuaAPI_Node_SetWorldTransform01);
  tolua_function(tolua_S,"SetWorldTransform",tolua_SceneLuaAPI_Node_SetWorldTransform02);
  tolua_function(tolua_S,"SetWorldTransform2D",tolua_SceneLuaAPI_Node_SetWorldTransform2D00);
  tolua_function(tolua_S,"SetWorldTransform2D",tolua_SceneLuaAPI_Node_SetWorldTransform2D01);
  tolua_function(tolua_S,"SetWorldTransform2D",tolua_SceneLuaAPI_Node_SetWorldTransform2D02);
  tolua_function(tolua_S,"Translate",tolua_SceneLuaAPI_Node_Translate00);
  tolua_function(tolua_S,"Translate2D",tolua_SceneLuaAPI_Node_Translate2D00);
  tolua_function(tolua_S,"Rotate",tolua_SceneLuaAPI_Node_Rotate00);
  tolua_function(tolua_S,"Rotate2D",tolua_SceneLuaAPI_Node_Rotate2D00);
  tolua_function(tolua_S,"RotateAround",tolua_SceneLuaAPI_Node_RotateAround00);
  tolua_function(tolua_S,"RotateAround2D",tolua_SceneLuaAPI_Node_RotateAround2D00);
  tolua_function(tolua_S,"Pitch",tolua_SceneLuaAPI_Node_Pitch00);
  tolua_function(tolua_S,"Yaw",tolua_SceneLuaAPI_Node_Yaw00);
  tolua_function(tolua_S,"Roll",tolua_SceneLuaAPI_Node_Roll00);
  tolua_function(tolua_S,"LookAt",tolua_SceneLuaAPI_Node_LookAt00);
  tolua_function(tolua_S,"LookAt",tolua_SceneLuaAPI_Node_LookAt01);
  tolua_function(tolua_S,"Scale",tolua_SceneLuaAPI_Node_Scale00);
  tolua_function(tolua_S,"Scale",tolua_SceneLuaAPI_Node_Scale01);
  tolua_function(tolua_S,"Scale2D",tolua_SceneLuaAPI_Node_Scale2D00);
  tolua_function(tolua_S,"SetEnabled",tolua_SceneLuaAPI_Node_SetEnabled00);
  tolua_function(tolua_S,"SetDeepEnabled",tolua_SceneLuaAPI_Node_SetDeepEnabled00);
  tolua_function(tolua_S,"ResetDeepEnabled",tolua_SceneLuaAPI_Node_ResetDeepEnabled00);
  tolua_function(tolua_S,"SetEnabledRecursive",tolua_SceneLuaAPI_Node_SetEnabledRecursive00);
  tolua_function(tolua_S,"SetOwner",tolua_SceneLuaAPI_Node_SetOwner00);
  tolua_function(tolua_S,"MarkDirty",tolua_SceneLuaAPI_Node_MarkDirty00);
  tolua_function(tolua_S,"CreateChild",tolua_SceneLuaAPI_Node_CreateChild00);
  tolua_function(tolua_S,"CreateTemporaryChild",tolua_SceneLuaAPI_Node_CreateTemporaryChild00);
  tolua_function(tolua_S,"AddChild",tolua_SceneLuaAPI_Node_AddChild00);
  tolua_function(tolua_S,"RemoveChild",tolua_SceneLuaAPI_Node_RemoveChild00);
  tolua_function(tolua_S,"RemoveAllChildren",tolua_SceneLuaAPI_Node_RemoveAllChildren00);
  tolua_function(tolua_S,"RemoveChildren",tolua_SceneLuaAPI_Node_RemoveChildren00);
  tolua_function(tolua_S,"RemoveComponent",tolua_SceneLuaAPI_Node_RemoveComponent00);
  tolua_function(tolua_S,"RemoveComponent",tolua_SceneLuaAPI_Node_RemoveComponent01);
  tolua_function(tolua_S,"RemoveComponent",tolua_SceneLuaAPI_Node_RemoveComponent02);
  tolua_function(tolua_S,"RemoveComponents",tolua_SceneLuaAPI_Node_RemoveComponents00);
  tolua_function(tolua_S,"RemoveComponents",tolua_SceneLuaAPI_Node_RemoveComponents01);
  tolua_function(tolua_S,"RemoveAllComponents",tolua_SceneLuaAPI_Node_RemoveAllComponents00);
  tolua_function(tolua_S,"ReorderComponent",tolua_SceneLuaAPI_Node_ReorderComponent00);
  tolua_function(tolua_S,"Clone",tolua_SceneLuaAPI_Node_Clone00);
  tolua_function(tolua_S,"Remove",tolua_SceneLuaAPI_Node_Remove00);
  tolua_function(tolua_S,"SetParent",tolua_SceneLuaAPI_Node_SetParent00);
  tolua_function(tolua_S,"SetVar",tolua_SceneLuaAPI_Node_SetVar00);
  tolua_function(tolua_S,"AddListener",tolua_SceneLuaAPI_Node_AddListener00);
  tolua_function(tolua_S,"RemoveListener",tolua_SceneLuaAPI_Node_RemoveListener00);
  tolua_function(tolua_S,"CreateComponent",tolua_SceneLuaAPI_Node_CreateComponent00);
  tolua_function(tolua_S,"GetOrCreateComponent",tolua_SceneLuaAPI_Node_GetOrCreateComponent00);
  tolua_function(tolua_S,"CloneComponent",tolua_SceneLuaAPI_Node_CloneComponent00);
  tolua_function(tolua_S,"CloneComponent",tolua_SceneLuaAPI_Node_CloneComponent01);
  tolua_function(tolua_S,"CreateScriptObject",tolua_SceneLuaAPI_Node_CreateScriptObject00);
  tolua_function(tolua_S,"CreateScriptObject",tolua_SceneLuaAPI_Node_CreateScriptObject01);
  tolua_function(tolua_S,"GetScriptObject",tolua_SceneLuaAPI_Node_GetScriptObject00);
  tolua_function(tolua_S,"GetScriptObject",tolua_SceneLuaAPI_Node_GetScriptObject01);
  tolua_function(tolua_S,"GetID",tolua_SceneLuaAPI_Node_GetID00);
  tolua_function(tolua_S,"IsReplicated",tolua_SceneLuaAPI_Node_IsReplicated00);
  tolua_function(tolua_S,"GetName",tolua_SceneLuaAPI_Node_GetName00);
  tolua_function(tolua_S,"GetNameHash",tolua_SceneLuaAPI_Node_GetNameHash00);
  tolua_function(tolua_S,"GetParent",tolua_SceneLuaAPI_Node_GetParent00);
  tolua_function(tolua_S,"GetScene",tolua_SceneLuaAPI_Node_GetScene00);
  tolua_function(tolua_S,"IsChildOf",tolua_SceneLuaAPI_Node_IsChildOf00);
  tolua_function(tolua_S,"IsEnabled",tolua_SceneLuaAPI_Node_IsEnabled00);
  tolua_function(tolua_S,"IsEnabledSelf",tolua_SceneLuaAPI_Node_IsEnabledSelf00);
  tolua_function(tolua_S,"GetOwner",tolua_SceneLuaAPI_Node_GetOwner00);
  tolua_function(tolua_S,"GetPosition",tolua_SceneLuaAPI_Node_GetPosition00);
  tolua_function(tolua_S,"GetPosition2D",tolua_SceneLuaAPI_Node_GetPosition2D00);
  tolua_function(tolua_S,"GetRotation",tolua_SceneLuaAPI_Node_GetRotation00);
  tolua_function(tolua_S,"GetRotation2D",tolua_SceneLuaAPI_Node_GetRotation2D00);
  tolua_function(tolua_S,"GetDirection",tolua_SceneLuaAPI_Node_GetDirection00);
  tolua_function(tolua_S,"GetUp",tolua_SceneLuaAPI_Node_GetUp00);
  tolua_function(tolua_S,"GetRight",tolua_SceneLuaAPI_Node_GetRight00);
  tolua_function(tolua_S,"GetScale",tolua_SceneLuaAPI_Node_GetScale00);
  tolua_function(tolua_S,"GetScale2D",tolua_SceneLuaAPI_Node_GetScale2D00);
  tolua_function(tolua_S,"GetTransform",tolua_SceneLuaAPI_Node_GetTransform00);
  tolua_function(tolua_S,"GetWorldPosition",tolua_SceneLuaAPI_Node_GetWorldPosition00);
  tolua_function(tolua_S,"GetWorldPosition2D",tolua_SceneLuaAPI_Node_GetWorldPosition2D00);
  tolua_function(tolua_S,"GetWorldRotation",tolua_SceneLuaAPI_Node_GetWorldRotation00);
  tolua_function(tolua_S,"GetWorldRotation2D",tolua_SceneLuaAPI_Node_GetWorldRotation2D00);
  tolua_function(tolua_S,"GetWorldDirection",tolua_SceneLuaAPI_Node_GetWorldDirection00);
  tolua_function(tolua_S,"GetWorldUp",tolua_SceneLuaAPI_Node_GetWorldUp00);
  tolua_function(tolua_S,"GetWorldRight",tolua_SceneLuaAPI_Node_GetWorldRight00);
  tolua_function(tolua_S,"GetWorldScale",tolua_SceneLuaAPI_Node_GetWorldScale00);
  tolua_function(tolua_S,"GetSignedWorldScale",tolua_SceneLuaAPI_Node_GetSignedWorldScale00);
  tolua_function(tolua_S,"GetWorldScale2D",tolua_SceneLuaAPI_Node_GetWorldScale2D00);
  tolua_function(tolua_S,"GetWorldTransform",tolua_SceneLuaAPI_Node_GetWorldTransform00);
  tolua_function(tolua_S,"LocalToWorld",tolua_SceneLuaAPI_Node_LocalToWorld00);
  tolua_function(tolua_S,"LocalToWorld",tolua_SceneLuaAPI_Node_LocalToWorld01);
  tolua_function(tolua_S,"LocalToWorld2D",tolua_SceneLuaAPI_Node_LocalToWorld2D00);
  tolua_function(tolua_S,"WorldToLocal",tolua_SceneLuaAPI_Node_WorldToLocal00);
  tolua_function(tolua_S,"WorldToLocal",tolua_SceneLuaAPI_Node_WorldToLocal01);
  tolua_function(tolua_S,"WorldToLocal2D",tolua_SceneLuaAPI_Node_WorldToLocal2D00);
  tolua_function(tolua_S,"IsDirty",tolua_SceneLuaAPI_Node_IsDirty00);
  tolua_function(tolua_S,"GetNumChildren",tolua_SceneLuaAPI_Node_GetNumChildren00);
  tolua_function(tolua_S,"GetChild",tolua_SceneLuaAPI_Node_GetChild00);
  tolua_function(tolua_S,"GetChild",tolua_SceneLuaAPI_Node_GetChild01);
  tolua_function(tolua_S,"GetChild",tolua_SceneLuaAPI_Node_GetChild02);
  tolua_function(tolua_S,"GetNumComponents",tolua_SceneLuaAPI_Node_GetNumComponents00);
  tolua_function(tolua_S,"GetNumNetworkComponents",tolua_SceneLuaAPI_Node_GetNumNetworkComponents00);
  tolua_function(tolua_S,"HasComponent",tolua_SceneLuaAPI_Node_HasComponent00);
  tolua_function(tolua_S,"HasComponent",tolua_SceneLuaAPI_Node_HasComponent01);
  tolua_function(tolua_S,"GetVar",tolua_SceneLuaAPI_Node_GetVar00);
  tolua_function(tolua_S,"GetVars",tolua_SceneLuaAPI_Node_GetVars00);
  tolua_function(tolua_S,"GetComponent",tolua_SceneLuaAPI_Node_GetComponent00);
  tolua_function(tolua_S,"GetParentComponent",tolua_SceneLuaAPI_Node_GetParentComponent00);
  tolua_function(tolua_S,"GetComponents",tolua_SceneLuaAPI_Node_GetComponents00);
  tolua_function(tolua_S,"GetChildren",tolua_SceneLuaAPI_Node_GetChildren00);
  tolua_function(tolua_S,"GetChildrenWithComponent",tolua_SceneLuaAPI_Node_GetChildrenWithComponent00);
  tolua_function(tolua_S,"Load",tolua_SceneLuaAPI_Node_Load00);
  tolua_function(tolua_S,"LoadXML",tolua_SceneLuaAPI_Node_LoadXML00);
  tolua_function(tolua_S,"LoadJSON",tolua_SceneLuaAPI_Node_LoadJSON00);
  tolua_function(tolua_S,"CreateChild",tolua_SceneLuaAPI_Node_CreateChild01);
  tolua_function(tolua_S,"AddComponent",tolua_SceneLuaAPI_Node_AddComponent00);
  tolua_function(tolua_S,"HasTag",tolua_SceneLuaAPI_Node_HasTag00);
  tolua_function(tolua_S,"GetTags",tolua_SceneLuaAPI_Node_GetTags00);
  tolua_function(tolua_S,"GetChildrenWithTag",tolua_SceneLuaAPI_Node_GetChildrenWithTag00);
  tolua_function(tolua_S,"SetID",tolua_SceneLuaAPI_Node_SetID00);
  tolua_variable(tolua_S,"ID",tolua_get_Node_ID,NULL);
  tolua_variable(tolua_S,"replicated",tolua_get_Node_replicated,NULL);
  tolua_variable(tolua_S,"name",tolua_get_Node_name,tolua_set_Node_name);
  tolua_variable(tolua_S,"nameHash",tolua_get_Node_nameHash,NULL);
  tolua_variable(tolua_S,"parent",tolua_get_Node_parent_ptr,tolua_set_Node_parent_ptr);
  tolua_variable(tolua_S,"scene",tolua_get_Node_scene_ptr,NULL);
  tolua_variable(tolua_S,"enabled",tolua_get_Node_enabled,tolua_set_Node_enabled);
  tolua_variable(tolua_S,"enabledSelf",tolua_get_Node_enabledSelf,NULL);
  tolua_variable(tolua_S,"owner",tolua_get_Node_owner_ptr,tolua_set_Node_owner_ptr);
  tolua_variable(tolua_S,"position",tolua_get_Node_position_ref,tolua_set_Node_position_ref);
  tolua_variable(tolua_S,"position2D",tolua_get_Node_position2D,tolua_set_Node_position2D);
  tolua_variable(tolua_S,"rotation",tolua_get_Node_rotation_ref,tolua_set_Node_rotation_ref);
  tolua_variable(tolua_S,"rotation2D",tolua_get_Node_rotation2D,tolua_set_Node_rotation2D);
  tolua_variable(tolua_S,"direction",tolua_get_Node_direction,tolua_set_Node_direction);
  tolua_variable(tolua_S,"up",tolua_get_Node_up,NULL);
  tolua_variable(tolua_S,"right",tolua_get_Node_right,NULL);
  tolua_variable(tolua_S,"scale",tolua_get_Node_scale_ref,tolua_set_Node_scale_ref);
  tolua_variable(tolua_S,"scale2D",tolua_get_Node_scale2D,tolua_set_Node_scale2D);
  tolua_variable(tolua_S,"transform",tolua_get_Node_transform,NULL);
  tolua_variable(tolua_S,"worldPosition",tolua_get_Node_worldPosition,tolua_set_Node_worldPosition);
  tolua_variable(tolua_S,"worldPosition2D",tolua_get_Node_worldPosition2D,tolua_set_Node_worldPosition2D);
  tolua_variable(tolua_S,"worldRotation",tolua_get_Node_worldRotation,tolua_set_Node_worldRotation);
  tolua_variable(tolua_S,"worldRotation2D",tolua_get_Node_worldRotation2D,tolua_set_Node_worldRotation2D);
  tolua_variable(tolua_S,"worldDirection",tolua_get_Node_worldDirection,tolua_set_Node_worldDirection);
  tolua_variable(tolua_S,"worldUp",tolua_get_Node_worldUp,NULL);
  tolua_variable(tolua_S,"worldRight",tolua_get_Node_worldRight,NULL);
  tolua_variable(tolua_S,"worldScale",tolua_get_Node_worldScale,tolua_set_Node_worldScale);
  tolua_variable(tolua_S,"signedWorldScale",tolua_get_Node_signedWorldScale,NULL);
  tolua_variable(tolua_S,"worldScale2D",tolua_get_Node_worldScale2D,tolua_set_Node_worldScale2D);
  tolua_variable(tolua_S,"worldTransform",tolua_get_Node_worldTransform_ref,NULL);
  tolua_variable(tolua_S,"dirty",tolua_get_Node_dirty,NULL);
  tolua_variable(tolua_S,"numComponents",tolua_get_Node_numComponents,NULL);
  tolua_variable(tolua_S,"numNetworkComponents",tolua_get_Node_numNetworkComponents,NULL);
 tolua_endmodule(tolua_S);
 tolua_variable(tolua_S,"FIRST_REPLICATED_ID",tolua_get_FIRST_REPLICATED_ID,NULL);
 tolua_variable(tolua_S,"LAST_REPLICATED_ID",tolua_get_LAST_REPLICATED_ID,NULL);
 tolua_variable(tolua_S,"FIRST_LOCAL_ID",tolua_get_FIRST_LOCAL_ID,NULL);
 tolua_variable(tolua_S,"LAST_LOCAL_ID",tolua_get_LAST_LOCAL_ID,NULL);
 tolua_constant(tolua_S,"LOAD_RESOURCES_ONLY",LOAD_RESOURCES_ONLY);
 tolua_constant(tolua_S,"LOAD_SCENE",LOAD_SCENE);
 tolua_constant(tolua_S,"LOAD_SCENE_AND_RESOURCES",LOAD_SCENE_AND_RESOURCES);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Scene","Scene","Node",tolua_collect_Scene);
 #else
 tolua_cclass(tolua_S,"Scene","Scene","Node",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Scene");
  tolua_function(tolua_S,"new",tolua_SceneLuaAPI_Scene_new00);
  tolua_function(tolua_S,"new_local",tolua_SceneLuaAPI_Scene_new00_local);
  tolua_function(tolua_S,".call",tolua_SceneLuaAPI_Scene_new00_local);
  tolua_function(tolua_S,"delete",tolua_SceneLuaAPI_Scene_delete00);
  tolua_function(tolua_S,"Load",tolua_SceneLuaAPI_Scene_Load00);
  tolua_function(tolua_S,"Save",tolua_SceneLuaAPI_Scene_Save00);
  tolua_function(tolua_S,"Load",tolua_SceneLuaAPI_Scene_Load01);
  tolua_function(tolua_S,"Save",tolua_SceneLuaAPI_Scene_Save01);
  tolua_function(tolua_S,"LoadXML",tolua_SceneLuaAPI_Scene_LoadXML00);
  tolua_function(tolua_S,"SaveXML",tolua_SceneLuaAPI_Scene_SaveXML00);
  tolua_function(tolua_S,"LoadXML",tolua_SceneLuaAPI_Scene_LoadXML01);
  tolua_function(tolua_S,"SaveXML",tolua_SceneLuaAPI_Scene_SaveXML01);
  tolua_function(tolua_S,"LoadJSON",tolua_SceneLuaAPI_Scene_LoadJSON00);
  tolua_function(tolua_S,"SaveJSON",tolua_SceneLuaAPI_Scene_SaveJSON00);
  tolua_function(tolua_S,"LoadJSON",tolua_SceneLuaAPI_Scene_LoadJSON01);
  tolua_function(tolua_S,"SaveJSON",tolua_SceneLuaAPI_Scene_SaveJSON01);
  tolua_function(tolua_S,"Instantiate",tolua_SceneLuaAPI_Scene_Instantiate00);
  tolua_function(tolua_S,"Instantiate",tolua_SceneLuaAPI_Scene_Instantiate01);
  tolua_function(tolua_S,"InstantiateXML",tolua_SceneLuaAPI_Scene_InstantiateXML00);
  tolua_function(tolua_S,"InstantiateXML",tolua_SceneLuaAPI_Scene_InstantiateXML01);
  tolua_function(tolua_S,"InstantiateJSON",tolua_SceneLuaAPI_Scene_InstantiateJSON00);
  tolua_function(tolua_S,"LoadAsync",tolua_SceneLuaAPI_Scene_LoadAsync00);
  tolua_function(tolua_S,"LoadAsyncXML",tolua_SceneLuaAPI_Scene_LoadAsyncXML00);
  tolua_function(tolua_S,"LoadAsync",tolua_SceneLuaAPI_Scene_LoadAsync01);
  tolua_function(tolua_S,"LoadAsyncXML",tolua_SceneLuaAPI_Scene_LoadAsyncXML01);
  tolua_function(tolua_S,"StopAsyncLoading",tolua_SceneLuaAPI_Scene_StopAsyncLoading00);
  tolua_function(tolua_S,"Clear",tolua_SceneLuaAPI_Scene_Clear00);
  tolua_function(tolua_S,"SetUpdateEnabled",tolua_SceneLuaAPI_Scene_SetUpdateEnabled00);
  tolua_function(tolua_S,"SetTimeScale",tolua_SceneLuaAPI_Scene_SetTimeScale00);
  tolua_function(tolua_S,"SetElapsedTime",tolua_SceneLuaAPI_Scene_SetElapsedTime00);
  tolua_function(tolua_S,"SetSmoothingConstant",tolua_SceneLuaAPI_Scene_SetSmoothingConstant00);
  tolua_function(tolua_S,"SetSnapThreshold",tolua_SceneLuaAPI_Scene_SetSnapThreshold00);
  tolua_function(tolua_S,"SetAsyncLoadingMs",tolua_SceneLuaAPI_Scene_SetAsyncLoadingMs00);
  tolua_function(tolua_S,"GetNode",tolua_SceneLuaAPI_Scene_GetNode00);
  tolua_function(tolua_S,"GetComponent",tolua_SceneLuaAPI_Scene_GetComponent00);
  tolua_function(tolua_S,"GetComponent",tolua_SceneLuaAPI_Scene_GetComponent01);
  tolua_function(tolua_S,"IsReplicatedID",tolua_SceneLuaAPI_Scene_IsReplicatedID00);
  tolua_function(tolua_S,"IsUpdateEnabled",tolua_SceneLuaAPI_Scene_IsUpdateEnabled00);
  tolua_function(tolua_S,"IsAsyncLoading",tolua_SceneLuaAPI_Scene_IsAsyncLoading00);
  tolua_function(tolua_S,"GetAsyncProgress",tolua_SceneLuaAPI_Scene_GetAsyncProgress00);
  tolua_function(tolua_S,"GetAsyncLoadMode",tolua_SceneLuaAPI_Scene_GetAsyncLoadMode00);
  tolua_function(tolua_S,"GetFileName",tolua_SceneLuaAPI_Scene_GetFileName00);
  tolua_function(tolua_S,"GetChecksum",tolua_SceneLuaAPI_Scene_GetChecksum00);
  tolua_function(tolua_S,"GetTimeScale",tolua_SceneLuaAPI_Scene_GetTimeScale00);
  tolua_function(tolua_S,"GetElapsedTime",tolua_SceneLuaAPI_Scene_GetElapsedTime00);
  tolua_function(tolua_S,"GetSmoothingConstant",tolua_SceneLuaAPI_Scene_GetSmoothingConstant00);
  tolua_function(tolua_S,"GetSnapThreshold",tolua_SceneLuaAPI_Scene_GetSnapThreshold00);
  tolua_function(tolua_S,"GetAsyncLoadingMs",tolua_SceneLuaAPI_Scene_GetAsyncLoadingMs00);
  tolua_function(tolua_S,"GetVarName",tolua_SceneLuaAPI_Scene_GetVarName00);
  tolua_function(tolua_S,"Update",tolua_SceneLuaAPI_Scene_Update00);
  tolua_function(tolua_S,"BeginThreadedUpdate",tolua_SceneLuaAPI_Scene_BeginThreadedUpdate00);
  tolua_function(tolua_S,"EndThreadedUpdate",tolua_SceneLuaAPI_Scene_EndThreadedUpdate00);
  tolua_function(tolua_S,"DelayedMarkedDirty",tolua_SceneLuaAPI_Scene_DelayedMarkedDirty00);
  tolua_function(tolua_S,"IsThreadedUpdate",tolua_SceneLuaAPI_Scene_IsThreadedUpdate00);
  tolua_function(tolua_S,"GetFreeNodeID",tolua_SceneLuaAPI_Scene_GetFreeNodeID00);
  tolua_function(tolua_S,"GetFreeComponentID",tolua_SceneLuaAPI_Scene_GetFreeComponentID00);
  tolua_function(tolua_S,"NodeAdded",tolua_SceneLuaAPI_Scene_NodeAdded00);
  tolua_function(tolua_S,"NodeRemoved",tolua_SceneLuaAPI_Scene_NodeRemoved00);
  tolua_function(tolua_S,"ComponentAdded",tolua_SceneLuaAPI_Scene_ComponentAdded00);
  tolua_function(tolua_S,"ComponentRemoved",tolua_SceneLuaAPI_Scene_ComponentRemoved00);
  tolua_function(tolua_S,"SetVarNamesAttr",tolua_SceneLuaAPI_Scene_SetVarNamesAttr00);
  tolua_function(tolua_S,"GetVarNamesAttr",tolua_SceneLuaAPI_Scene_GetVarNamesAttr00);
  tolua_function(tolua_S,"PrepareNetworkUpdate",tolua_SceneLuaAPI_Scene_PrepareNetworkUpdate00);
  tolua_function(tolua_S,"CleanupConnection",tolua_SceneLuaAPI_Scene_CleanupConnection00);
  tolua_function(tolua_S,"MarkNetworkUpdate",tolua_SceneLuaAPI_Scene_MarkNetworkUpdate00);
  tolua_function(tolua_S,"MarkNetworkUpdate",tolua_SceneLuaAPI_Scene_MarkNetworkUpdate01);
  tolua_function(tolua_S,"MarkReplicationDirty",tolua_SceneLuaAPI_Scene_MarkReplicationDirty00);
  tolua_function(tolua_S,"GetNodesWithTag",tolua_SceneLuaAPI_Scene_GetNodesWithTag00);
  tolua_variable(tolua_S,"updateEnabled",tolua_get_Scene_updateEnabled,tolua_set_Scene_updateEnabled);
  tolua_variable(tolua_S,"asyncLoading",tolua_get_Scene_asyncLoading,NULL);
  tolua_variable(tolua_S,"asyncProgress",tolua_get_Scene_asyncProgress,NULL);
  tolua_variable(tolua_S,"asyncLoadMode",tolua_get_Scene_asyncLoadMode,NULL);
  tolua_variable(tolua_S,"fileName",tolua_get_Scene_fileName,NULL);
  tolua_variable(tolua_S,"checksum",tolua_get_Scene_checksum,NULL);
  tolua_variable(tolua_S,"timeScale",tolua_get_Scene_timeScale,tolua_set_Scene_timeScale);
  tolua_variable(tolua_S,"elapsedTime",tolua_get_Scene_elapsedTime,tolua_set_Scene_elapsedTime);
  tolua_variable(tolua_S,"smoothingConstant",tolua_get_Scene_smoothingConstant,tolua_set_Scene_smoothingConstant);
  tolua_variable(tolua_S,"snapThreshold",tolua_get_Scene_snapThreshold,tolua_set_Scene_snapThreshold);
  tolua_variable(tolua_S,"asyncLoadingMs",tolua_get_Scene_asyncLoadingMs,tolua_set_Scene_asyncLoadingMs);
  tolua_variable(tolua_S,"threadedUpdate",tolua_get_Scene_threadedUpdate,NULL);
  tolua_variable(tolua_S,"varNamesAttr",tolua_get_Scene_varNamesAttr,tolua_set_Scene_varNamesAttr);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"SplinePath","SplinePath","Component",NULL);
 tolua_beginmodule(tolua_S,"SplinePath");
  tolua_function(tolua_S,"AddControlPoint",tolua_SceneLuaAPI_SplinePath_AddControlPoint00);
  tolua_function(tolua_S,"RemoveControlPoint",tolua_SceneLuaAPI_SplinePath_RemoveControlPoint00);
  tolua_function(tolua_S,"ClearControlPoints",tolua_SceneLuaAPI_SplinePath_ClearControlPoints00);
  tolua_function(tolua_S,"SetInterpolationMode",tolua_SceneLuaAPI_SplinePath_SetInterpolationMode00);
  tolua_function(tolua_S,"SetPosition",tolua_SceneLuaAPI_SplinePath_SetPosition00);
  tolua_function(tolua_S,"SetControlledNode",tolua_SceneLuaAPI_SplinePath_SetControlledNode00);
  tolua_function(tolua_S,"GetInterpolationMode",tolua_SceneLuaAPI_SplinePath_GetInterpolationMode00);
  tolua_function(tolua_S,"GetSpeed",tolua_SceneLuaAPI_SplinePath_GetSpeed00);
  tolua_function(tolua_S,"GetLength",tolua_SceneLuaAPI_SplinePath_GetLength00);
  tolua_function(tolua_S,"GetPosition",tolua_SceneLuaAPI_SplinePath_GetPosition00);
  tolua_function(tolua_S,"GetControlledNode",tolua_SceneLuaAPI_SplinePath_GetControlledNode00);
  tolua_function(tolua_S,"GetPoint",tolua_SceneLuaAPI_SplinePath_GetPoint00);
  tolua_function(tolua_S,"Move",tolua_SceneLuaAPI_SplinePath_Move00);
  tolua_function(tolua_S,"Reset",tolua_SceneLuaAPI_SplinePath_Reset00);
  tolua_function(tolua_S,"IsFinished",tolua_SceneLuaAPI_SplinePath_IsFinished00);
  tolua_variable(tolua_S,"interpolationMode",tolua_get_SplinePath_interpolationMode,tolua_set_SplinePath_interpolationMode);
  tolua_variable(tolua_S,"speed",tolua_get_SplinePath_speed,tolua_set_SplinePath_speed);
  tolua_variable(tolua_S,"length",tolua_get_SplinePath_length,NULL);
  tolua_variable(tolua_S,"controlledNode",tolua_get_SplinePath_controlledNode_ptr,tolua_set_SplinePath_controlledNode_ptr);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_SceneLuaAPI (lua_State* tolua_S) {
 return tolua_SceneLuaAPI_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif