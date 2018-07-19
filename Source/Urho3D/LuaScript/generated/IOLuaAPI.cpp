/*
** Lua binding: IOLuaAPI
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
TOLUA_API int tolua_IOLuaAPI_open (lua_State* tolua_S);

#include "IO/Compression.h"
#include "IO/Deserializer.h"
#include "IO/File.h"
#include "IO/FileSystem.h"
#include "IO/Log.h"
#include "IO/NamedPipe.h"
#include "IO/PackageFile.h"
#include "IO/Serializer.h"
#include "IO/VectorBuffer.h"
using namespace Urho3D;
#pragma warning(disable:4800)

static VectorBuffer DeserializerRead(Deserializer* deserializer, unsigned size)
{
    unsigned char* data = new unsigned char[size];
    deserializer->Read(data, size);
    VectorBuffer buffer(data, size);
    delete [] data;
    return buffer;
}

#define TOLUA_DISABLE_tolua_IOLuaAPI_File_new00
static int tolua_IOLuaAPI_File_new00(lua_State* tolua_S)
{
    return ToluaNewObject<File>(tolua_S);
}

#define TOLUA_DISABLE_tolua_IOLuaAPI_File_new00_local
static int tolua_IOLuaAPI_File_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<File>(tolua_S);
}

/* method: new of class  File */
#define TOLUA_DISABLE_tolua_IOLuaAPI_File_new01
static int tolua_IOLuaAPI_File_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  FileMode mode = ((FileMode) (int)  tolua_tonumber(tolua_S,3,FILE_READ));
 {
  File* tolua_ret = (File*)  Mtolua_new((File)(GetContext(tolua_S),fileName,mode));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"File");
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_File_new00(tolua_S);
}

/* method: new_local of class  File */
#define TOLUA_DISABLE_tolua_IOLuaAPI_File_new01_local
static int tolua_IOLuaAPI_File_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  FileMode mode = ((FileMode) (int)  tolua_tonumber(tolua_S,3,FILE_READ));
 {
  File* tolua_ret = (File*)  Mtolua_new((File)(GetContext(tolua_S),fileName,mode));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"File");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_File_new00_local(tolua_S);
}

/* method: new of class  File */
#define TOLUA_DISABLE_tolua_IOLuaAPI_File_new02
static int tolua_IOLuaAPI_File_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"PackageFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  PackageFile* package = ((PackageFile*)  tolua_tousertype(tolua_S,2,0));
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
 {
  File* tolua_ret = (File*)  Mtolua_new((File)(GetContext(tolua_S),package,fileName));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"File");
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_File_new01(tolua_S);
}

/* method: new_local of class  File */
#define TOLUA_DISABLE_tolua_IOLuaAPI_File_new02_local
static int tolua_IOLuaAPI_File_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"PackageFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  PackageFile* package = ((PackageFile*)  tolua_tousertype(tolua_S,2,0));
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
 {
  File* tolua_ret = (File*)  Mtolua_new((File)(GetContext(tolua_S),package,fileName));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"File");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_File_new01_local(tolua_S);
}

#define TOLUA_DISABLE_tolua_IOLuaAPI_GetFileSystem00
static int tolua_IOLuaAPI_GetFileSystem00(lua_State* tolua_S)
{
    return ToluaGetSubsystem<FileSystem>(tolua_S);
}

#define TOLUA_DISABLE_tolua_get_fileSystem_ptr
#define tolua_get_fileSystem_ptr tolua_IOLuaAPI_GetFileSystem00

static const Vector<String>& FileSystemScanDir(const FileSystem* fileSystem, const String pathName, const String filter, unsigned flags, bool recursive)
{
    static Vector<String> result;
    fileSystem->ScanDir(result, pathName, filter, flags, recursive);
    return result;
}

#define TOLUA_DISABLE_tolua_IOLuaAPI_GetLog00
static int tolua_IOLuaAPI_GetLog00(lua_State* tolua_S)
{
    return ToluaGetSubsystem<Log>(tolua_S);
}

#define TOLUA_DISABLE_tolua_get_log_ptr
#define tolua_get_log_ptr tolua_IOLuaAPI_GetLog00

#define TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_new00
static int tolua_IOLuaAPI_NamedPipe_new00(lua_State* tolua_S)
{
    return ToluaNewObject<NamedPipe>(tolua_S);
}

#define TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_new00_local
static int tolua_IOLuaAPI_NamedPipe_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<NamedPipe>(tolua_S);
}

#define TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_new01
static int tolua_IOLuaAPI_NamedPipe_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const String pipeName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool isServer = ((bool)  tolua_toboolean(tolua_S,3,0));
 {
  NamedPipe* tolua_ret = (NamedPipe*)  Mtolua_new((NamedPipe)(GetContext(tolua_S),pipeName,isServer));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"NamedPipe");
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_NamedPipe_new00(tolua_S);
}

#define TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_new01_local
static int tolua_IOLuaAPI_NamedPipe_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const String pipeName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool isServer = ((bool)  tolua_toboolean(tolua_S,3,0));
 {
  NamedPipe* tolua_ret = (NamedPipe*)  Mtolua_new((NamedPipe)(GetContext(tolua_S),pipeName,isServer));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"NamedPipe");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_NamedPipe_new00_local(tolua_S);
}

#define TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_new00
static int tolua_IOLuaAPI_PackageFile_new00(lua_State* tolua_S)
{
    return ToluaNewObject<PackageFile>(tolua_S);
}

#define TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_new00_local
static int tolua_IOLuaAPI_PackageFile_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<PackageFile>(tolua_S);
}

/* method: new of class  PackageFile */
#define TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_new01
static int tolua_IOLuaAPI_PackageFile_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PackageFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  unsigned startOffset = ((unsigned)  tolua_tonumber(tolua_S,3,0));
 {
  PackageFile* tolua_ret = (PackageFile*)  Mtolua_new((PackageFile)(GetContext(tolua_S),fileName,startOffset));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"PackageFile");
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_PackageFile_new00(tolua_S);
}

/* method: new_local of class  PackageFile */
#define TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_new01_local
static int tolua_IOLuaAPI_PackageFile_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PackageFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  unsigned startOffset = ((unsigned)  tolua_tonumber(tolua_S,3,0));
 {
  PackageFile* tolua_ret = (PackageFile*)  Mtolua_new((PackageFile)(GetContext(tolua_S),fileName,startOffset));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"PackageFile");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_PackageFile_new00_local(tolua_S);
}

static unsigned SerializerWrite(Serializer* serializer, const VectorBuffer& buffer)
{
    return serializer->Write(buffer.GetData(), buffer.GetSize());
}

static bool SerializerWriteBuffer(Serializer* serializer, const VectorBuffer& buffer)
{
    return serializer->WriteBuffer(buffer.GetBuffer());
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

static int tolua_collect_Vector4 (lua_State* tolua_S)
{
 Vector4* self = (Vector4*) tolua_tousertype(tolua_S,1,0);
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

static int tolua_collect_NamedPipe (lua_State* tolua_S)
{
 NamedPipe* self = (NamedPipe*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_PackageFile (lua_State* tolua_S)
{
 PackageFile* self = (PackageFile*) tolua_tousertype(tolua_S,1,0);
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

static int tolua_collect_File (lua_State* tolua_S)
{
 File* self = (File*) tolua_tousertype(tolua_S,1,0);
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
 tolua_usertype(tolua_S,"Serializer");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"PackageEntry");
 tolua_usertype(tolua_S,"HashMap<String,PackageEntry>");
 tolua_usertype(tolua_S,"PackageFile");
 tolua_usertype(tolua_S,"FileSystem");
 tolua_usertype(tolua_S,"NamedPipe");
 tolua_usertype(tolua_S,"Log");
 tolua_usertype(tolua_S,"Variant");
 tolua_usertype(tolua_S,"Deserializer");
 tolua_usertype(tolua_S,"Vector<String>");
 tolua_usertype(tolua_S,"VectorBuffer");
 tolua_usertype(tolua_S,"Vector4");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"VariantType");
 tolua_usertype(tolua_S,"IntRect");
 tolua_usertype(tolua_S,"VariantVector");
 tolua_usertype(tolua_S,"StringHash");
 tolua_usertype(tolua_S,"Matrix3");
 tolua_usertype(tolua_S,"ResourceRef");
 tolua_usertype(tolua_S,"IntVector3");
 tolua_usertype(tolua_S,"Quaternion");
 tolua_usertype(tolua_S,"Rect");
 tolua_usertype(tolua_S,"ResourceRefList");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"BoundingBox");
 tolua_usertype(tolua_S,"File");
 tolua_usertype(tolua_S,"Matrix4");
 tolua_usertype(tolua_S,"IntVector2");
}

/* function: CompressVectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_CompressVectorBuffer00
static int tolua_IOLuaAPI_CompressVectorBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* src = ((VectorBuffer*)  tolua_tousertype(tolua_S,1,0));
 {
  VectorBuffer tolua_ret = (VectorBuffer)  CompressVectorBuffer(*src);
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
 tolua_error(tolua_S,"#ferror in function 'CompressVectorBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: DecompressVectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_DecompressVectorBuffer00
static int tolua_IOLuaAPI_DecompressVectorBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* src = ((VectorBuffer*)  tolua_tousertype(tolua_S,1,0));
 {
  VectorBuffer tolua_ret = (VectorBuffer)  DecompressVectorBuffer(*src);
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
 tolua_error(tolua_S,"#ferror in function 'DecompressVectorBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DeserializerRead of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_Read00
static int tolua_IOLuaAPI_Deserializer_Read00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
  unsigned size = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeserializerRead'", NULL);
#endif
 {
  tolua_outside VectorBuffer tolua_ret = (tolua_outside VectorBuffer)  DeserializerRead(self,size);
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

/* method: Seek of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_Seek00
static int tolua_IOLuaAPI_Deserializer_Seek00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
  unsigned position = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Seek'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->Seek(position);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Seek'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SeekRelative of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_SeekRelative00
static int tolua_IOLuaAPI_Deserializer_SeekRelative00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
  int delta = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SeekRelative'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->SeekRelative(delta);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SeekRelative'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_GetName00
static int tolua_IOLuaAPI_Deserializer_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Deserializer* self = (const Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetChecksum of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_GetChecksum00
static int tolua_IOLuaAPI_Deserializer_GetChecksum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetPosition of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_GetPosition00
static int tolua_IOLuaAPI_Deserializer_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Deserializer* self = (const Deserializer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetPosition();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: Tell of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_Tell00
static int tolua_IOLuaAPI_Deserializer_Tell00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Deserializer* self = (const Deserializer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Tell'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->Tell();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Tell'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSize of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_GetSize00
static int tolua_IOLuaAPI_Deserializer_GetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Deserializer* self = (const Deserializer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSize'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: IsEof of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_IsEof00
static int tolua_IOLuaAPI_Deserializer_IsEof00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Deserializer* self = (const Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadInt of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadInt00
static int tolua_IOLuaAPI_Deserializer_ReadInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadInt64 of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadInt6400
static int tolua_IOLuaAPI_Deserializer_ReadInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadInt64'", NULL);
#endif
 {
  long long tolua_ret = (long long)  self->ReadInt64();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadShort of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadShort00
static int tolua_IOLuaAPI_Deserializer_ReadShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadByte of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadByte00
static int tolua_IOLuaAPI_Deserializer_ReadByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadUInt of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadUInt00
static int tolua_IOLuaAPI_Deserializer_ReadUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadUInt64 of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadUInt6400
static int tolua_IOLuaAPI_Deserializer_ReadUInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadUInt64'", NULL);
#endif
 {
  unsigned long long tolua_ret = (unsigned long long)  self->ReadUInt64();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadUInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadUShort of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadUShort00
static int tolua_IOLuaAPI_Deserializer_ReadUShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadUByte of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadUByte00
static int tolua_IOLuaAPI_Deserializer_ReadUByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadBool of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadBool00
static int tolua_IOLuaAPI_Deserializer_ReadBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadFloat of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadFloat00
static int tolua_IOLuaAPI_Deserializer_ReadFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadDouble of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadDouble00
static int tolua_IOLuaAPI_Deserializer_ReadDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadIntRect of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadIntRect00
static int tolua_IOLuaAPI_Deserializer_ReadIntRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadIntVector2 of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadIntVector200
static int tolua_IOLuaAPI_Deserializer_ReadIntVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadIntVector3 of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadIntVector300
static int tolua_IOLuaAPI_Deserializer_ReadIntVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadRect of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadRect00
static int tolua_IOLuaAPI_Deserializer_ReadRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVector2 of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadVector200
static int tolua_IOLuaAPI_Deserializer_ReadVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVector3 of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadVector300
static int tolua_IOLuaAPI_Deserializer_ReadVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadPackedVector3 of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadPackedVector300
static int tolua_IOLuaAPI_Deserializer_ReadPackedVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVector4 of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadVector400
static int tolua_IOLuaAPI_Deserializer_ReadVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadQuaternion of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadQuaternion00
static int tolua_IOLuaAPI_Deserializer_ReadQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadPackedQuaternion of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadPackedQuaternion00
static int tolua_IOLuaAPI_Deserializer_ReadPackedQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadMatrix3 of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadMatrix300
static int tolua_IOLuaAPI_Deserializer_ReadMatrix300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadMatrix3x4 of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadMatrix3x400
static int tolua_IOLuaAPI_Deserializer_ReadMatrix3x400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadMatrix4 of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadMatrix400
static int tolua_IOLuaAPI_Deserializer_ReadMatrix400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadColor of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadColor00
static int tolua_IOLuaAPI_Deserializer_ReadColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadBoundingBox of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadBoundingBox00
static int tolua_IOLuaAPI_Deserializer_ReadBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadString of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadString00
static int tolua_IOLuaAPI_Deserializer_ReadString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadFileID of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadFileID00
static int tolua_IOLuaAPI_Deserializer_ReadFileID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadStringHash of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadStringHash00
static int tolua_IOLuaAPI_Deserializer_ReadStringHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadBuffer of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadBuffer00
static int tolua_IOLuaAPI_Deserializer_ReadBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadResourceRef of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadResourceRef00
static int tolua_IOLuaAPI_Deserializer_ReadResourceRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadResourceRefList of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadResourceRefList00
static int tolua_IOLuaAPI_Deserializer_ReadResourceRefList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVariant of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadVariant00
static int tolua_IOLuaAPI_Deserializer_ReadVariant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVariant of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadVariant01
static int tolua_IOLuaAPI_Deserializer_ReadVariant01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"VariantType",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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
 return tolua_IOLuaAPI_Deserializer_ReadVariant00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadVariantVector of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadVariantVector00
static int tolua_IOLuaAPI_Deserializer_ReadVariantVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVariantMap of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadVariantMap00
static int tolua_IOLuaAPI_Deserializer_ReadVariantMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVLE of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadVLE00
static int tolua_IOLuaAPI_Deserializer_ReadVLE00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadNetID of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadNetID00
static int tolua_IOLuaAPI_Deserializer_ReadNetID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadLine of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Deserializer_ReadLine00
static int tolua_IOLuaAPI_Deserializer_ReadLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Deserializer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: name of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_get_Deserializer_name
static int tolua_get_Deserializer_name(lua_State* tolua_S)
{
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: checksum of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_get_Deserializer_checksum
static int tolua_get_Deserializer_checksum(lua_State* tolua_S)
{
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'checksum'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetChecksum());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: position of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_get_Deserializer_position
static int tolua_get_Deserializer_position(lua_State* tolua_S)
{
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetPosition());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: size of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_get_Deserializer_size
static int tolua_get_Deserializer_size(lua_State* tolua_S)
{
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: eof of class  Deserializer */
#ifndef TOLUA_DISABLE_tolua_get_Deserializer_eof
static int tolua_get_Deserializer_eof(lua_State* tolua_S)
{
  Deserializer* self = (Deserializer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eof'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsEof());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_new00
static int tolua_IOLuaAPI_File_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  File* tolua_ret = (File*)  Mtolua_new((File)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"File");
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

/* method: new_local of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_new00_local
static int tolua_IOLuaAPI_File_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  File* tolua_ret = (File*)  Mtolua_new((File)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"File");
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

/* method: new of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_new01
static int tolua_IOLuaAPI_File_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  FileMode mode = ((FileMode) (int)  tolua_tonumber(tolua_S,3,FILE_READ));
 {
  File* tolua_ret = (File*)  Mtolua_new((File)(fileName,mode));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"File");
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_File_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_new01_local
static int tolua_IOLuaAPI_File_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  FileMode mode = ((FileMode) (int)  tolua_tonumber(tolua_S,3,FILE_READ));
 {
  File* tolua_ret = (File*)  Mtolua_new((File)(fileName,mode));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"File");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_File_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_new02
static int tolua_IOLuaAPI_File_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"PackageFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  PackageFile* package = ((PackageFile*)  tolua_tousertype(tolua_S,2,0));
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
 {
  File* tolua_ret = (File*)  Mtolua_new((File)(package,fileName));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"File");
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_File_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_new02_local
static int tolua_IOLuaAPI_File_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"PackageFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  PackageFile* package = ((PackageFile*)  tolua_tousertype(tolua_S,2,0));
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
 {
  File* tolua_ret = (File*)  Mtolua_new((File)(package,fileName));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"File");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_File_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_delete00
static int tolua_IOLuaAPI_File_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Open of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_Open00
static int tolua_IOLuaAPI_File_Open00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  FileMode mode = ((FileMode) (int)  tolua_tonumber(tolua_S,3,FILE_READ));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Open'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Open(fileName,mode);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Open'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Open of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_Open01
static int tolua_IOLuaAPI_File_Open01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"PackageFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  PackageFile* package = ((PackageFile*)  tolua_tousertype(tolua_S,2,0));
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Open'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Open(package,fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_File_Open00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Close of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_Close00
static int tolua_IOLuaAPI_File_Close00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Close'", NULL);
#endif
 {
  self->Close();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Close'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Flush of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_Flush00
static int tolua_IOLuaAPI_File_Flush00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Flush'", NULL);
#endif
 {
  self->Flush();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Flush'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetName of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_SetName00
static int tolua_IOLuaAPI_File_SetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetMode of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_GetMode00
static int tolua_IOLuaAPI_File_GetMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const File* self = (const File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMode'", NULL);
#endif
 {
  FileMode tolua_ret = (FileMode)  self->GetMode();
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

/* method: IsOpen of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_IsOpen00
static int tolua_IOLuaAPI_File_IsOpen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const File* self = (const File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetHandle of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_GetHandle00
static int tolua_IOLuaAPI_File_GetHandle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const File* self = (const File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHandle'", NULL);
#endif
 {
  void* tolua_ret = (void*)  self->GetHandle();
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHandle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsPackaged of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_IsPackaged00
static int tolua_IOLuaAPI_File_IsPackaged00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const File* self = (const File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsPackaged'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsPackaged();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsPackaged'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DeserializerRead of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_Read00
static int tolua_IOLuaAPI_File_Read00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  unsigned size = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeserializerRead'", NULL);
#endif
 {
  tolua_outside VectorBuffer tolua_ret = (tolua_outside VectorBuffer)  DeserializerRead(self,size);
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

/* method: Seek of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_Seek00
static int tolua_IOLuaAPI_File_Seek00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  unsigned position = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Seek'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->Seek(position);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Seek'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SeekRelative of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_SeekRelative00
static int tolua_IOLuaAPI_File_SeekRelative00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  int delta = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SeekRelative'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->SeekRelative(delta);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SeekRelative'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_GetName00
static int tolua_IOLuaAPI_File_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const File* self = (const File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetChecksum of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_GetChecksum00
static int tolua_IOLuaAPI_File_GetChecksum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetPosition of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_GetPosition00
static int tolua_IOLuaAPI_File_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const File* self = (const File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetPosition();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: Tell of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_Tell00
static int tolua_IOLuaAPI_File_Tell00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const File* self = (const File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Tell'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->Tell();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Tell'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSize of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_GetSize00
static int tolua_IOLuaAPI_File_GetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const File* self = (const File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSize'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: IsEof of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_IsEof00
static int tolua_IOLuaAPI_File_IsEof00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const File* self = (const File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadInt of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadInt00
static int tolua_IOLuaAPI_File_ReadInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadInt64 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadInt6400
static int tolua_IOLuaAPI_File_ReadInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadInt64'", NULL);
#endif
 {
  long long tolua_ret = (long long)  self->ReadInt64();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadShort of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadShort00
static int tolua_IOLuaAPI_File_ReadShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadByte of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadByte00
static int tolua_IOLuaAPI_File_ReadByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadUInt of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadUInt00
static int tolua_IOLuaAPI_File_ReadUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadUInt64 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadUInt6400
static int tolua_IOLuaAPI_File_ReadUInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadUInt64'", NULL);
#endif
 {
  unsigned long long tolua_ret = (unsigned long long)  self->ReadUInt64();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadUInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadUShort of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadUShort00
static int tolua_IOLuaAPI_File_ReadUShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadUByte of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadUByte00
static int tolua_IOLuaAPI_File_ReadUByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadBool of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadBool00
static int tolua_IOLuaAPI_File_ReadBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadFloat of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadFloat00
static int tolua_IOLuaAPI_File_ReadFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadDouble of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadDouble00
static int tolua_IOLuaAPI_File_ReadDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadIntRect of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadIntRect00
static int tolua_IOLuaAPI_File_ReadIntRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadIntVector2 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadIntVector200
static int tolua_IOLuaAPI_File_ReadIntVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadIntVector3 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadIntVector300
static int tolua_IOLuaAPI_File_ReadIntVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadRect of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadRect00
static int tolua_IOLuaAPI_File_ReadRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVector2 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadVector200
static int tolua_IOLuaAPI_File_ReadVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVector3 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadVector300
static int tolua_IOLuaAPI_File_ReadVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadPackedVector3 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadPackedVector300
static int tolua_IOLuaAPI_File_ReadPackedVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVector4 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadVector400
static int tolua_IOLuaAPI_File_ReadVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadQuaternion of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadQuaternion00
static int tolua_IOLuaAPI_File_ReadQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadPackedQuaternion of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadPackedQuaternion00
static int tolua_IOLuaAPI_File_ReadPackedQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadMatrix3 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadMatrix300
static int tolua_IOLuaAPI_File_ReadMatrix300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadMatrix3x4 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadMatrix3x400
static int tolua_IOLuaAPI_File_ReadMatrix3x400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadMatrix4 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadMatrix400
static int tolua_IOLuaAPI_File_ReadMatrix400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadColor of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadColor00
static int tolua_IOLuaAPI_File_ReadColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadBoundingBox of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadBoundingBox00
static int tolua_IOLuaAPI_File_ReadBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadString of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadString00
static int tolua_IOLuaAPI_File_ReadString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadFileID of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadFileID00
static int tolua_IOLuaAPI_File_ReadFileID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadStringHash of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadStringHash00
static int tolua_IOLuaAPI_File_ReadStringHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadBuffer of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadBuffer00
static int tolua_IOLuaAPI_File_ReadBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadResourceRef of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadResourceRef00
static int tolua_IOLuaAPI_File_ReadResourceRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadResourceRefList of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadResourceRefList00
static int tolua_IOLuaAPI_File_ReadResourceRefList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVariant of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadVariant00
static int tolua_IOLuaAPI_File_ReadVariant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVariant of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadVariant01
static int tolua_IOLuaAPI_File_ReadVariant01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"VariantType",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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
 return tolua_IOLuaAPI_File_ReadVariant00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadVariantVector of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadVariantVector00
static int tolua_IOLuaAPI_File_ReadVariantVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVariantMap of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadVariantMap00
static int tolua_IOLuaAPI_File_ReadVariantMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVLE of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadVLE00
static int tolua_IOLuaAPI_File_ReadVLE00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadNetID of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadNetID00
static int tolua_IOLuaAPI_File_ReadNetID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadLine of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_ReadLine00
static int tolua_IOLuaAPI_File_ReadLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SerializerWrite of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_Write00
static int tolua_IOLuaAPI_File_Write00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VectorBuffer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const VectorBuffer* buffer = ((const VectorBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SerializerWrite'", NULL);
#endif
 {
  tolua_outside unsigned tolua_ret = (tolua_outside unsigned)  SerializerWrite(self,*buffer);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Write'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteInt of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteInt00
static int tolua_IOLuaAPI_File_WriteInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteInt'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteInt(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteInt64 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteInt6400
static int tolua_IOLuaAPI_File_WriteInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  long long value = ((long long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteInt64'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteInt64(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteShort of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteShort00
static int tolua_IOLuaAPI_File_WriteShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  short value = ((short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteShort'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteShort(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteShort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteByte of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteByte00
static int tolua_IOLuaAPI_File_WriteByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  signed char value = ((signed char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteByte'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteByte(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteByte'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteUInt of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteUInt00
static int tolua_IOLuaAPI_File_WriteUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteUInt'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteUInt(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteUInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteUInt64 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteUInt6400
static int tolua_IOLuaAPI_File_WriteUInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  unsigned long long value = ((unsigned long long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteUInt64'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteUInt64(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteUInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteUShort of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteUShort00
static int tolua_IOLuaAPI_File_WriteUShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  unsigned short value = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteUShort'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteUShort(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteUShort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteUByte of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteUByte00
static int tolua_IOLuaAPI_File_WriteUByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  unsigned char value = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteUByte'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteUByte(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteUByte'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteBool of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteBool00
static int tolua_IOLuaAPI_File_WriteBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteBool'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteBool(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteFloat of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteFloat00
static int tolua_IOLuaAPI_File_WriteFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteFloat'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteFloat(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteDouble of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteDouble00
static int tolua_IOLuaAPI_File_WriteDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  double value = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteDouble'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteDouble(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteDouble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteIntRect of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteIntRect00
static int tolua_IOLuaAPI_File_WriteIntRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* value = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteIntRect'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteIntRect(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteIntRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteIntVector2 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteIntVector200
static int tolua_IOLuaAPI_File_WriteIntVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* value = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteIntVector2'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteIntVector2(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteIntVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteIntVector3 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteIntVector300
static int tolua_IOLuaAPI_File_WriteIntVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const IntVector3* value = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteIntVector3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteIntVector3(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteIntVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteRect of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteRect00
static int tolua_IOLuaAPI_File_WriteRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const Rect* value = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteRect'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteRect(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVector2 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteVector200
static int tolua_IOLuaAPI_File_WriteVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* value = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVector2'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVector2(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVector3 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteVector300
static int tolua_IOLuaAPI_File_WriteVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* value = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVector3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVector3(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WritePackedVector3 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WritePackedVector300
static int tolua_IOLuaAPI_File_WritePackedVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* value = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float maxAbsCoord = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WritePackedVector3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WritePackedVector3(*value,maxAbsCoord);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WritePackedVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVector4 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteVector400
static int tolua_IOLuaAPI_File_WriteVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* value = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVector4'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVector4(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteQuaternion of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteQuaternion00
static int tolua_IOLuaAPI_File_WriteQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* value = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteQuaternion'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteQuaternion(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WritePackedQuaternion of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WritePackedQuaternion00
static int tolua_IOLuaAPI_File_WritePackedQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* value = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WritePackedQuaternion'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WritePackedQuaternion(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WritePackedQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteMatrix3 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteMatrix300
static int tolua_IOLuaAPI_File_WriteMatrix300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* value = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteMatrix3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteMatrix3(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteMatrix3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteMatrix3x4 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteMatrix3x400
static int tolua_IOLuaAPI_File_WriteMatrix3x400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* value = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteMatrix3x4'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteMatrix3x4(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteMatrix3x4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteMatrix4 of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteMatrix400
static int tolua_IOLuaAPI_File_WriteMatrix400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* value = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteMatrix4'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteMatrix4(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteMatrix4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteColor of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteColor00
static int tolua_IOLuaAPI_File_WriteColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const Color* value = ((const Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteColor'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteColor(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteBoundingBox of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteBoundingBox00
static int tolua_IOLuaAPI_File_WriteBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* value = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteBoundingBox'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteBoundingBox(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteString of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteString00
static int tolua_IOLuaAPI_File_WriteString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteString'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteString(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteFileID of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteFileID00
static int tolua_IOLuaAPI_File_WriteFileID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteFileID'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteFileID(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteFileID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteStringHash of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteStringHash00
static int tolua_IOLuaAPI_File_WriteStringHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const StringHash* value = ((const StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteStringHash'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteStringHash(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteStringHash'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SerializerWriteBuffer of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteBuffer00
static int tolua_IOLuaAPI_File_WriteBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VectorBuffer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const VectorBuffer* buffer = ((const VectorBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SerializerWriteBuffer'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SerializerWriteBuffer(self,*buffer);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteResourceRef of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteResourceRef00
static int tolua_IOLuaAPI_File_WriteResourceRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ResourceRef",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const ResourceRef* value = ((const ResourceRef*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteResourceRef'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteResourceRef(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteResourceRef'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteResourceRefList of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteResourceRefList00
static int tolua_IOLuaAPI_File_WriteResourceRefList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ResourceRefList",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const ResourceRefList* value = ((const ResourceRefList*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteResourceRefList'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteResourceRefList(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteResourceRefList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariant of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteVariant00
static int tolua_IOLuaAPI_File_WriteVariant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariant'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariant(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariantData of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteVariantData00
static int tolua_IOLuaAPI_File_WriteVariantData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariantData'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariantData(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariantData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariantVector of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteVariantVector00
static int tolua_IOLuaAPI_File_WriteVariantVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VariantVector",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const VariantVector* value = ((const VariantVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariantVector'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariantVector(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariantVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariantMap of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteVariantMap00
static int tolua_IOLuaAPI_File_WriteVariantMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const VariantMap* value = ((const VariantMap*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariantMap'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariantMap(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariantMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVLE of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteVLE00
static int tolua_IOLuaAPI_File_WriteVLE00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVLE'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVLE(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVLE'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteNetID of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteNetID00
static int tolua_IOLuaAPI_File_WriteNetID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteNetID'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteNetID(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteNetID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteLine of class  File */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_File_WriteLine00
static int tolua_IOLuaAPI_File_WriteLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"File",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteLine'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteLine(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mode of class  File */
#ifndef TOLUA_DISABLE_tolua_get_File_mode
static int tolua_get_File_mode(lua_State* tolua_S)
{
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: open of class  File */
#ifndef TOLUA_DISABLE_tolua_get_File_open
static int tolua_get_File_open(lua_State* tolua_S)
{
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'open'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsOpen());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: packaged of class  File */
#ifndef TOLUA_DISABLE_tolua_get_File_packaged
static int tolua_get_File_packaged(lua_State* tolua_S)
{
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'packaged'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsPackaged());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  File */
#ifndef TOLUA_DISABLE_tolua_get_File_name
static int tolua_get_File_name(lua_State* tolua_S)
{
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: checksum of class  File */
#ifndef TOLUA_DISABLE_tolua_get_File_checksum
static int tolua_get_File_checksum(lua_State* tolua_S)
{
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'checksum'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetChecksum());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: position of class  File */
#ifndef TOLUA_DISABLE_tolua_get_File_position
static int tolua_get_File_position(lua_State* tolua_S)
{
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetPosition());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: size of class  File */
#ifndef TOLUA_DISABLE_tolua_get_File_size
static int tolua_get_File_size(lua_State* tolua_S)
{
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: eof of class  File */
#ifndef TOLUA_DISABLE_tolua_get_File_eof
static int tolua_get_File_eof(lua_State* tolua_S)
{
  File* self = (File*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eof'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsEof());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCAN_FILES */
#ifndef TOLUA_DISABLE_tolua_get_SCAN_FILES
static int tolua_get_SCAN_FILES(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCAN_FILES);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCAN_DIRS */
#ifndef TOLUA_DISABLE_tolua_get_SCAN_DIRS
static int tolua_get_SCAN_DIRS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCAN_DIRS);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SCAN_HIDDEN */
#ifndef TOLUA_DISABLE_tolua_get_SCAN_HIDDEN
static int tolua_get_SCAN_HIDDEN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)SCAN_HIDDEN);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCurrentDir of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_SetCurrentDir00
static int tolua_IOLuaAPI_FileSystem_SetCurrentDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSystem* self = (FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String pathName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCurrentDir'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetCurrentDir(pathName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCurrentDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateDir of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_CreateDir00
static int tolua_IOLuaAPI_FileSystem_CreateDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSystem* self = (FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String pathName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateDir'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->CreateDir(pathName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetExecuteConsoleCommands of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_SetExecuteConsoleCommands00
static int tolua_IOLuaAPI_FileSystem_SetExecuteConsoleCommands00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSystem",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSystem* self = (FileSystem*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetExecuteConsoleCommands'", NULL);
#endif
 {
  self->SetExecuteConsoleCommands(enable);
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

/* method: SystemCommand of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_SystemCommand00
static int tolua_IOLuaAPI_FileSystem_SystemCommand00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSystem* self = (FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String commandLine = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool redirectStdOutToLog = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SystemCommand'", NULL);
#endif
 {
  int tolua_ret = (int)  self->SystemCommand(commandLine,redirectStdOutToLog);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SystemCommand'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SystemRun of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_SystemRun00
static int tolua_IOLuaAPI_FileSystem_SystemRun00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !ToluaIsVector<String>(tolua_S,3,"String",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSystem* self = (FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Vector<String>* arguments = ((const Vector<String>*)  ToluaToVector<String>(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SystemRun'", NULL);
#endif
 {
  int tolua_ret = (int)  self->SystemRun(fileName,*arguments);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SystemRun'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SystemCommandAsync of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_SystemCommandAsync00
static int tolua_IOLuaAPI_FileSystem_SystemCommandAsync00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSystem* self = (FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String commandLine = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SystemCommandAsync'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->SystemCommandAsync(commandLine);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SystemCommandAsync'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SystemRunAsync of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_SystemRunAsync00
static int tolua_IOLuaAPI_FileSystem_SystemRunAsync00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !ToluaIsVector<String>(tolua_S,3,"String",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSystem* self = (FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const Vector<String>* arguments = ((const Vector<String>*)  ToluaToVector<String>(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SystemRunAsync'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->SystemRunAsync(fileName,*arguments);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SystemRunAsync'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SystemOpen of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_SystemOpen00
static int tolua_IOLuaAPI_FileSystem_SystemOpen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSystem* self = (FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String mode = ((const String)  tolua_tourho3dstring(tolua_S,3,String::EMPTY));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SystemOpen'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SystemOpen(fileName,mode);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SystemOpen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Copy of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_Copy00
static int tolua_IOLuaAPI_FileSystem_Copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSystem* self = (FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String srcFileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String destFileName = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Copy'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Copy(srcFileName,destFileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Rename of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_Rename00
static int tolua_IOLuaAPI_FileSystem_Rename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSystem* self = (FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String srcFileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String destFileName = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Rename'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Rename(srcFileName,destFileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Rename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Delete of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_Delete00
static int tolua_IOLuaAPI_FileSystem_Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSystem* self = (FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Delete(fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLastModifiedTime of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_SetLastModifiedTime00
static int tolua_IOLuaAPI_FileSystem_SetLastModifiedTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSystem* self = (FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  unsigned newTime = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLastModifiedTime'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetLastModifiedTime(fileName,newTime);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLastModifiedTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCurrentDir of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_GetCurrentDir00
static int tolua_IOLuaAPI_FileSystem_GetCurrentDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSystem",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSystem* self = (const FileSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCurrentDir'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetCurrentDir();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCurrentDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetExecuteConsoleCommands of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_GetExecuteConsoleCommands00
static int tolua_IOLuaAPI_FileSystem_GetExecuteConsoleCommands00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSystem",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSystem* self = (const FileSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetExecuteConsoleCommands'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetExecuteConsoleCommands();
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

/* method: HasRegisteredPaths of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_HasRegisteredPaths00
static int tolua_IOLuaAPI_FileSystem_HasRegisteredPaths00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSystem",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSystem* self = (const FileSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasRegisteredPaths'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasRegisteredPaths();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasRegisteredPaths'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CheckAccess of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_CheckAccess00
static int tolua_IOLuaAPI_FileSystem_CheckAccess00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSystem* self = (const FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String pathName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CheckAccess'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->CheckAccess(pathName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CheckAccess'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLastModifiedTime of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_GetLastModifiedTime00
static int tolua_IOLuaAPI_FileSystem_GetLastModifiedTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSystem* self = (const FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLastModifiedTime'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetLastModifiedTime(fileName);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLastModifiedTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FileExists of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_FileExists00
static int tolua_IOLuaAPI_FileSystem_FileExists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSystem* self = (const FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FileExists'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->FileExists(fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FileExists'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DirExists of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_DirExists00
static int tolua_IOLuaAPI_FileSystem_DirExists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSystem* self = (const FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String pathName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DirExists'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->DirExists(pathName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DirExists'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FileSystemScanDir of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_ScanDir00
static int tolua_IOLuaAPI_FileSystem_ScanDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSystem* self = (const FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String pathName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String filter = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
  unsigned flags = ((unsigned)  tolua_tonumber(tolua_S,4,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FileSystemScanDir'", NULL);
#endif
 {
  tolua_outside  const Vector<String>& tolua_ret = (tolua_outside  const Vector<String>&)  FileSystemScanDir(self,pathName,filter,flags,recursive);
  ToluaPushVector<String>(tolua_S,(void*)&tolua_ret,"String");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ScanDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProgramDir of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_GetProgramDir00
static int tolua_IOLuaAPI_FileSystem_GetProgramDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSystem",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSystem* self = (const FileSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProgramDir'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetProgramDir();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProgramDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUserDocumentsDir of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_GetUserDocumentsDir00
static int tolua_IOLuaAPI_FileSystem_GetUserDocumentsDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSystem",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSystem* self = (const FileSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUserDocumentsDir'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetUserDocumentsDir();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUserDocumentsDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAppPreferencesDir of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_GetAppPreferencesDir00
static int tolua_IOLuaAPI_FileSystem_GetAppPreferencesDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSystem",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSystem* self = (const FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const String org = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String app = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAppPreferencesDir'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetAppPreferencesDir(org,app);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAppPreferencesDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTemporaryDir of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_FileSystem_GetTemporaryDir00
static int tolua_IOLuaAPI_FileSystem_GetTemporaryDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSystem",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSystem* self = (const FileSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTemporaryDir'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetTemporaryDir();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTemporaryDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetPath */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_GetPath00
static int tolua_IOLuaAPI_GetPath00(lua_State* tolua_S)
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
  const String fullPath = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  String tolua_ret = (String)  GetPath(fullPath);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetFileName */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_GetFileName00
static int tolua_IOLuaAPI_GetFileName00(lua_State* tolua_S)
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
  const String fullPath = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
 {
  String tolua_ret = (String)  GetFileName(fullPath);
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

/* function: GetExtension */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_GetExtension00
static int tolua_IOLuaAPI_GetExtension00(lua_State* tolua_S)
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
  const String fullPath = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
  bool lowercaseExtension = ((bool)  tolua_toboolean(tolua_S,2,true));
 {
  String tolua_ret = (String)  GetExtension(fullPath,lowercaseExtension);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetExtension'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetFileNameAndExtension */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_GetFileNameAndExtension00
static int tolua_IOLuaAPI_GetFileNameAndExtension00(lua_State* tolua_S)
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
  const String fullPath = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
  bool lowercaseExtension = ((bool)  tolua_toboolean(tolua_S,2,false));
 {
  String tolua_ret = (String)  GetFileNameAndExtension(fullPath,lowercaseExtension);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFileNameAndExtension'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ReplaceExtension */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_ReplaceExtension00
static int tolua_IOLuaAPI_ReplaceExtension00(lua_State* tolua_S)
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
  const String fullPath = ((const String)  tolua_tourho3dstring(tolua_S,1,0));
  const String newExtension = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
 {
  String tolua_ret = (String)  ReplaceExtension(fullPath,newExtension);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReplaceExtension'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: AddTrailingSlash */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_AddTrailingSlash00
static int tolua_IOLuaAPI_AddTrailingSlash00(lua_State* tolua_S)
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
  String tolua_ret = (String)  AddTrailingSlash(pathName);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddTrailingSlash'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: RemoveTrailingSlash */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_RemoveTrailingSlash00
static int tolua_IOLuaAPI_RemoveTrailingSlash00(lua_State* tolua_S)
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
  String tolua_ret = (String)  RemoveTrailingSlash(pathName);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveTrailingSlash'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetParentPath */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_GetParentPath00
static int tolua_IOLuaAPI_GetParentPath00(lua_State* tolua_S)
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
  String tolua_ret = (String)  GetParentPath(pathName);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetParentPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetInternalPath */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_GetInternalPath00
static int tolua_IOLuaAPI_GetInternalPath00(lua_State* tolua_S)
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
  String tolua_ret = (String)  GetInternalPath(pathName);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInternalPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetNativePath */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_GetNativePath00
static int tolua_IOLuaAPI_GetNativePath00(lua_State* tolua_S)
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
  String tolua_ret = (String)  GetNativePath(pathName);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNativePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: IsAbsolutePath */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_IsAbsolutePath00
static int tolua_IOLuaAPI_IsAbsolutePath00(lua_State* tolua_S)
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
  bool tolua_ret = (bool)  IsAbsolutePath(pathName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsAbsolutePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetFileSizeString */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_GetFileSizeString00
static int tolua_IOLuaAPI_GetFileSizeString00(lua_State* tolua_S)
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
  unsigned long long memorySize = ((unsigned long long)  tolua_tonumber(tolua_S,1,0));
 {
  String tolua_ret = (String)  GetFileSizeString(memorySize);
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFileSizeString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetFileSystem */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_GetFileSystem00
static int tolua_IOLuaAPI_GetFileSystem00(lua_State* tolua_S)
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
  FileSystem* tolua_ret = (FileSystem*)  GetFileSystem();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"FileSystem");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFileSystem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fileSystem */
#ifndef TOLUA_DISABLE_tolua_get_fileSystem_ptr
static int tolua_get_fileSystem_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetFileSystem(),"FileSystem");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LOG_TRACE */
#ifndef TOLUA_DISABLE_tolua_get_LOG_TRACE
static int tolua_get_LOG_TRACE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)LOG_TRACE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LOG_DEBUG */
#ifndef TOLUA_DISABLE_tolua_get_LOG_DEBUG
static int tolua_get_LOG_DEBUG(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)LOG_DEBUG);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LOG_INFO */
#ifndef TOLUA_DISABLE_tolua_get_LOG_INFO
static int tolua_get_LOG_INFO(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)LOG_INFO);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LOG_WARNING */
#ifndef TOLUA_DISABLE_tolua_get_LOG_WARNING
static int tolua_get_LOG_WARNING(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)LOG_WARNING);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LOG_ERROR */
#ifndef TOLUA_DISABLE_tolua_get_LOG_ERROR
static int tolua_get_LOG_ERROR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)LOG_ERROR);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LOG_NONE */
#ifndef TOLUA_DISABLE_tolua_get_LOG_NONE
static int tolua_get_LOG_NONE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)LOG_NONE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Open of class  Log */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Log_Open00
static int tolua_IOLuaAPI_Log_Open00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Log",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Log* self = (Log*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Open'", NULL);
#endif
 {
  self->Open(fileName);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Open'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Close of class  Log */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Log_Close00
static int tolua_IOLuaAPI_Log_Close00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Log",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Log* self = (Log*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Close'", NULL);
#endif
 {
  self->Close();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Close'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLevel of class  Log */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Log_SetLevel00
static int tolua_IOLuaAPI_Log_SetLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Log",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Log* self = (Log*)  tolua_tousertype(tolua_S,1,0);
  int level = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLevel'", NULL);
#endif
 {
  self->SetLevel(level);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTimeStamp of class  Log */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Log_SetTimeStamp00
static int tolua_IOLuaAPI_Log_SetTimeStamp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Log",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Log* self = (Log*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTimeStamp'", NULL);
#endif
 {
  self->SetTimeStamp(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTimeStamp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetQuiet of class  Log */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Log_SetQuiet00
static int tolua_IOLuaAPI_Log_SetQuiet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Log",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Log* self = (Log*)  tolua_tousertype(tolua_S,1,0);
  bool quiet = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetQuiet'", NULL);
#endif
 {
  self->SetQuiet(quiet);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetQuiet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLevel of class  Log */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Log_GetLevel00
static int tolua_IOLuaAPI_Log_GetLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Log",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Log* self = (const Log*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLevel'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetLevel();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTimeStamp of class  Log */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Log_GetTimeStamp00
static int tolua_IOLuaAPI_Log_GetTimeStamp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Log",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Log* self = (const Log*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTimeStamp'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetTimeStamp();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
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

/* method: GetLastMessage of class  Log */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Log_GetLastMessage00
static int tolua_IOLuaAPI_Log_GetLastMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Log",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Log* self = (const Log*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLastMessage'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetLastMessage();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLastMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsQuiet of class  Log */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Log_IsQuiet00
static int tolua_IOLuaAPI_Log_IsQuiet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Log",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Log* self = (const Log*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsQuiet'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsQuiet();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsQuiet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Write of class  Log */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Log_Write00
static int tolua_IOLuaAPI_Log_Write00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Log",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int level = ((int)  tolua_tonumber(tolua_S,2,0));
  const String message = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
 {
  Log::Write(level,message);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Write'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteRaw of class  Log */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Log_WriteRaw00
static int tolua_IOLuaAPI_Log_WriteRaw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Log",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String message = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool error = ((bool)  tolua_toboolean(tolua_S,3,false));
 {
  Log::WriteRaw(message,error);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteRaw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: level of class  Log */
#ifndef TOLUA_DISABLE_tolua_get_Log_level
static int tolua_get_Log_level(lua_State* tolua_S)
{
  Log* self = (Log*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'level'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLevel());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: level of class  Log */
#ifndef TOLUA_DISABLE_tolua_set_Log_level
static int tolua_set_Log_level(lua_State* tolua_S)
{
  Log* self = (Log*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'level'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLevel(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: timeStamp of class  Log */
#ifndef TOLUA_DISABLE_tolua_get_Log_timeStamp
static int tolua_get_Log_timeStamp(lua_State* tolua_S)
{
  Log* self = (Log*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeStamp'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetTimeStamp());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: timeStamp of class  Log */
#ifndef TOLUA_DISABLE_tolua_set_Log_timeStamp
static int tolua_set_Log_timeStamp(lua_State* tolua_S)
{
  Log* self = (Log*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeStamp'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTimeStamp(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: quiet of class  Log */
#ifndef TOLUA_DISABLE_tolua_get_Log_quiet
static int tolua_get_Log_quiet(lua_State* tolua_S)
{
  Log* self = (Log*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'quiet'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsQuiet());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: quiet of class  Log */
#ifndef TOLUA_DISABLE_tolua_set_Log_quiet
static int tolua_set_Log_quiet(lua_State* tolua_S)
{
  Log* self = (Log*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'quiet'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetQuiet(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetLog */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_GetLog00
static int tolua_IOLuaAPI_GetLog00(lua_State* tolua_S)
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
  Log* tolua_ret = (Log*)  GetLog();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Log");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: log */
#ifndef TOLUA_DISABLE_tolua_get_log_ptr
static int tolua_get_log_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetLog(),"Log");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_new00
static int tolua_IOLuaAPI_NamedPipe_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  NamedPipe* tolua_ret = (NamedPipe*)  Mtolua_new((NamedPipe)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"NamedPipe");
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

/* method: new_local of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_new00_local
static int tolua_IOLuaAPI_NamedPipe_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  NamedPipe* tolua_ret = (NamedPipe*)  Mtolua_new((NamedPipe)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"NamedPipe");
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

/* method: new of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_new01
static int tolua_IOLuaAPI_NamedPipe_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const String pipeName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool isServer = ((bool)  tolua_toboolean(tolua_S,3,0));
 {
  NamedPipe* tolua_ret = (NamedPipe*)  Mtolua_new((NamedPipe)(pipeName,isServer));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"NamedPipe");
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_NamedPipe_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_new01_local
static int tolua_IOLuaAPI_NamedPipe_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const String pipeName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool isServer = ((bool)  tolua_toboolean(tolua_S,3,0));
 {
  NamedPipe* tolua_ret = (NamedPipe*)  Mtolua_new((NamedPipe)(pipeName,isServer));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"NamedPipe");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_NamedPipe_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_delete00
static int tolua_IOLuaAPI_NamedPipe_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Open of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_Open00
static int tolua_IOLuaAPI_NamedPipe_Open00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const String pipeName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool isServer = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Open'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Open(pipeName,isServer);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Open'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Close of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_Close00
static int tolua_IOLuaAPI_NamedPipe_Close00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Close'", NULL);
#endif
 {
  self->Close();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Close'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsOpen of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_IsOpen00
static int tolua_IOLuaAPI_NamedPipe_IsOpen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NamedPipe* self = (const NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: DeserializerRead of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_Read00
static int tolua_IOLuaAPI_NamedPipe_Read00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  unsigned size = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeserializerRead'", NULL);
#endif
 {
  tolua_outside VectorBuffer tolua_ret = (tolua_outside VectorBuffer)  DeserializerRead(self,size);
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

/* method: GetName of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_GetName00
static int tolua_IOLuaAPI_NamedPipe_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NamedPipe* self = (const NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsEof of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_IsEof00
static int tolua_IOLuaAPI_NamedPipe_IsEof00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const NamedPipe* self = (const NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadInt of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadInt00
static int tolua_IOLuaAPI_NamedPipe_ReadInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadShort of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadShort00
static int tolua_IOLuaAPI_NamedPipe_ReadShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadByte of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadByte00
static int tolua_IOLuaAPI_NamedPipe_ReadByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadUInt of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadUInt00
static int tolua_IOLuaAPI_NamedPipe_ReadUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadUShort of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadUShort00
static int tolua_IOLuaAPI_NamedPipe_ReadUShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadUByte of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadUByte00
static int tolua_IOLuaAPI_NamedPipe_ReadUByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadBool of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadBool00
static int tolua_IOLuaAPI_NamedPipe_ReadBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadFloat of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadFloat00
static int tolua_IOLuaAPI_NamedPipe_ReadFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadDouble of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadDouble00
static int tolua_IOLuaAPI_NamedPipe_ReadDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadIntRect of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadIntRect00
static int tolua_IOLuaAPI_NamedPipe_ReadIntRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadIntVector2 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadIntVector200
static int tolua_IOLuaAPI_NamedPipe_ReadIntVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadIntVector3 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadIntVector300
static int tolua_IOLuaAPI_NamedPipe_ReadIntVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadRect of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadRect00
static int tolua_IOLuaAPI_NamedPipe_ReadRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVector2 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadVector200
static int tolua_IOLuaAPI_NamedPipe_ReadVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVector3 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadVector300
static int tolua_IOLuaAPI_NamedPipe_ReadVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadPackedVector3 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadPackedVector300
static int tolua_IOLuaAPI_NamedPipe_ReadPackedVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVector4 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadVector400
static int tolua_IOLuaAPI_NamedPipe_ReadVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadQuaternion of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadQuaternion00
static int tolua_IOLuaAPI_NamedPipe_ReadQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadPackedQuaternion of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadPackedQuaternion00
static int tolua_IOLuaAPI_NamedPipe_ReadPackedQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadMatrix3 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadMatrix300
static int tolua_IOLuaAPI_NamedPipe_ReadMatrix300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadMatrix3x4 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadMatrix3x400
static int tolua_IOLuaAPI_NamedPipe_ReadMatrix3x400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadMatrix4 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadMatrix400
static int tolua_IOLuaAPI_NamedPipe_ReadMatrix400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadColor of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadColor00
static int tolua_IOLuaAPI_NamedPipe_ReadColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadBoundingBox of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadBoundingBox00
static int tolua_IOLuaAPI_NamedPipe_ReadBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadString of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadString00
static int tolua_IOLuaAPI_NamedPipe_ReadString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadFileID of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadFileID00
static int tolua_IOLuaAPI_NamedPipe_ReadFileID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadStringHash of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadStringHash00
static int tolua_IOLuaAPI_NamedPipe_ReadStringHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadBuffer of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadBuffer00
static int tolua_IOLuaAPI_NamedPipe_ReadBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadResourceRef of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadResourceRef00
static int tolua_IOLuaAPI_NamedPipe_ReadResourceRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadResourceRefList of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadResourceRefList00
static int tolua_IOLuaAPI_NamedPipe_ReadResourceRefList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVariant of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadVariant00
static int tolua_IOLuaAPI_NamedPipe_ReadVariant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVariant of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadVariant01
static int tolua_IOLuaAPI_NamedPipe_ReadVariant01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"VariantType",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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
 return tolua_IOLuaAPI_NamedPipe_ReadVariant00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadVariantVector of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadVariantVector00
static int tolua_IOLuaAPI_NamedPipe_ReadVariantVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVariantMap of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadVariantMap00
static int tolua_IOLuaAPI_NamedPipe_ReadVariantMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVLE of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadVLE00
static int tolua_IOLuaAPI_NamedPipe_ReadVLE00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadNetID of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadNetID00
static int tolua_IOLuaAPI_NamedPipe_ReadNetID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadLine of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_ReadLine00
static int tolua_IOLuaAPI_NamedPipe_ReadLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SerializerWrite of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_Write00
static int tolua_IOLuaAPI_NamedPipe_Write00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VectorBuffer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const VectorBuffer* buffer = ((const VectorBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SerializerWrite'", NULL);
#endif
 {
  tolua_outside unsigned tolua_ret = (tolua_outside unsigned)  SerializerWrite(self,*buffer);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Write'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteInt of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteInt00
static int tolua_IOLuaAPI_NamedPipe_WriteInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteInt'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteInt(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteShort of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteShort00
static int tolua_IOLuaAPI_NamedPipe_WriteShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  short value = ((short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteShort'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteShort(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteShort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteByte of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteByte00
static int tolua_IOLuaAPI_NamedPipe_WriteByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  signed char value = ((signed char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteByte'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteByte(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteByte'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteUInt of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteUInt00
static int tolua_IOLuaAPI_NamedPipe_WriteUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteUInt'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteUInt(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteUInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteUShort of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteUShort00
static int tolua_IOLuaAPI_NamedPipe_WriteUShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  unsigned short value = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteUShort'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteUShort(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteUShort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteUByte of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteUByte00
static int tolua_IOLuaAPI_NamedPipe_WriteUByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  unsigned char value = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteUByte'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteUByte(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteUByte'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteBool of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteBool00
static int tolua_IOLuaAPI_NamedPipe_WriteBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteBool'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteBool(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteFloat of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteFloat00
static int tolua_IOLuaAPI_NamedPipe_WriteFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteFloat'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteFloat(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteDouble of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteDouble00
static int tolua_IOLuaAPI_NamedPipe_WriteDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  double value = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteDouble'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteDouble(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteDouble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteIntRect of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteIntRect00
static int tolua_IOLuaAPI_NamedPipe_WriteIntRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* value = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteIntRect'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteIntRect(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteIntRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteIntVector2 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteIntVector200
static int tolua_IOLuaAPI_NamedPipe_WriteIntVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* value = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteIntVector2'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteIntVector2(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteIntVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteIntVector3 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteIntVector300
static int tolua_IOLuaAPI_NamedPipe_WriteIntVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const IntVector3* value = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteIntVector3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteIntVector3(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteIntVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteRect of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteRect00
static int tolua_IOLuaAPI_NamedPipe_WriteRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const Rect* value = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteRect'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteRect(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVector2 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteVector200
static int tolua_IOLuaAPI_NamedPipe_WriteVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* value = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVector2'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVector2(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVector3 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteVector300
static int tolua_IOLuaAPI_NamedPipe_WriteVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* value = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVector3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVector3(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WritePackedVector3 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WritePackedVector300
static int tolua_IOLuaAPI_NamedPipe_WritePackedVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* value = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float maxAbsCoord = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WritePackedVector3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WritePackedVector3(*value,maxAbsCoord);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WritePackedVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVector4 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteVector400
static int tolua_IOLuaAPI_NamedPipe_WriteVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* value = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVector4'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVector4(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteQuaternion of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteQuaternion00
static int tolua_IOLuaAPI_NamedPipe_WriteQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* value = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteQuaternion'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteQuaternion(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WritePackedQuaternion of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WritePackedQuaternion00
static int tolua_IOLuaAPI_NamedPipe_WritePackedQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* value = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WritePackedQuaternion'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WritePackedQuaternion(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WritePackedQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteMatrix3 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteMatrix300
static int tolua_IOLuaAPI_NamedPipe_WriteMatrix300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* value = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteMatrix3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteMatrix3(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteMatrix3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteMatrix3x4 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteMatrix3x400
static int tolua_IOLuaAPI_NamedPipe_WriteMatrix3x400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* value = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteMatrix3x4'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteMatrix3x4(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteMatrix3x4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteMatrix4 of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteMatrix400
static int tolua_IOLuaAPI_NamedPipe_WriteMatrix400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* value = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteMatrix4'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteMatrix4(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteMatrix4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteColor of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteColor00
static int tolua_IOLuaAPI_NamedPipe_WriteColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const Color* value = ((const Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteColor'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteColor(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteBoundingBox of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteBoundingBox00
static int tolua_IOLuaAPI_NamedPipe_WriteBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* value = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteBoundingBox'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteBoundingBox(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteString of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteString00
static int tolua_IOLuaAPI_NamedPipe_WriteString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteString'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteString(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteFileID of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteFileID00
static int tolua_IOLuaAPI_NamedPipe_WriteFileID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteFileID'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteFileID(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteFileID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteStringHash of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteStringHash00
static int tolua_IOLuaAPI_NamedPipe_WriteStringHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const StringHash* value = ((const StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteStringHash'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteStringHash(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteStringHash'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SerializerWriteBuffer of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteBuffer00
static int tolua_IOLuaAPI_NamedPipe_WriteBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VectorBuffer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const VectorBuffer* buffer = ((const VectorBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SerializerWriteBuffer'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SerializerWriteBuffer(self,*buffer);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteResourceRef of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteResourceRef00
static int tolua_IOLuaAPI_NamedPipe_WriteResourceRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ResourceRef",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const ResourceRef* value = ((const ResourceRef*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteResourceRef'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteResourceRef(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteResourceRef'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteResourceRefList of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteResourceRefList00
static int tolua_IOLuaAPI_NamedPipe_WriteResourceRefList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ResourceRefList",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const ResourceRefList* value = ((const ResourceRefList*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteResourceRefList'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteResourceRefList(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteResourceRefList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariant of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteVariant00
static int tolua_IOLuaAPI_NamedPipe_WriteVariant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariant'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariant(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariantData of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteVariantData00
static int tolua_IOLuaAPI_NamedPipe_WriteVariantData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariantData'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariantData(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariantData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariantVector of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteVariantVector00
static int tolua_IOLuaAPI_NamedPipe_WriteVariantVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VariantVector",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const VariantVector* value = ((const VariantVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariantVector'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariantVector(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariantVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariantMap of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteVariantMap00
static int tolua_IOLuaAPI_NamedPipe_WriteVariantMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const VariantMap* value = ((const VariantMap*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariantMap'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariantMap(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariantMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVLE of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteVLE00
static int tolua_IOLuaAPI_NamedPipe_WriteVLE00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVLE'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVLE(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVLE'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteNetID of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteNetID00
static int tolua_IOLuaAPI_NamedPipe_WriteNetID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteNetID'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteNetID(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteNetID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteLine of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_NamedPipe_WriteLine00
static int tolua_IOLuaAPI_NamedPipe_WriteLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NamedPipe",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteLine'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteLine(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_get_NamedPipe_name
static int tolua_get_NamedPipe_name(lua_State* tolua_S)
{
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: eof of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_get_NamedPipe_eof
static int tolua_get_NamedPipe_eof(lua_State* tolua_S)
{
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eof'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsEof());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: open of class  NamedPipe */
#ifndef TOLUA_DISABLE_tolua_get_NamedPipe_open
static int tolua_get_NamedPipe_open(lua_State* tolua_S)
{
  NamedPipe* self = (NamedPipe*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'open'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsOpen());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: offset_ of class  PackageEntry */
#ifndef TOLUA_DISABLE_tolua_get_PackageEntry_offset
static int tolua_get_PackageEntry_offset(lua_State* tolua_S)
{
  PackageEntry* self = (PackageEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'offset_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->offset_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: offset_ of class  PackageEntry */
#ifndef TOLUA_DISABLE_tolua_set_PackageEntry_offset
static int tolua_set_PackageEntry_offset(lua_State* tolua_S)
{
  PackageEntry* self = (PackageEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'offset_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->offset_ = ((unsigned)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: size_ of class  PackageEntry */
#ifndef TOLUA_DISABLE_tolua_get_PackageEntry_size
static int tolua_get_PackageEntry_size(lua_State* tolua_S)
{
  PackageEntry* self = (PackageEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->size_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: size_ of class  PackageEntry */
#ifndef TOLUA_DISABLE_tolua_set_PackageEntry_size
static int tolua_set_PackageEntry_size(lua_State* tolua_S)
{
  PackageEntry* self = (PackageEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->size_ = ((unsigned)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: checksum_ of class  PackageEntry */
#ifndef TOLUA_DISABLE_tolua_get_PackageEntry_checksum
static int tolua_get_PackageEntry_checksum(lua_State* tolua_S)
{
  PackageEntry* self = (PackageEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'checksum_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->checksum_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: checksum_ of class  PackageEntry */
#ifndef TOLUA_DISABLE_tolua_set_PackageEntry_checksum
static int tolua_set_PackageEntry_checksum(lua_State* tolua_S)
{
  PackageEntry* self = (PackageEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'checksum_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->checksum_ = ((unsigned)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_new00
static int tolua_IOLuaAPI_PackageFile_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PackageFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PackageFile* tolua_ret = (PackageFile*)  Mtolua_new((PackageFile)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"PackageFile");
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

/* method: new_local of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_new00_local
static int tolua_IOLuaAPI_PackageFile_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PackageFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PackageFile* tolua_ret = (PackageFile*)  Mtolua_new((PackageFile)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"PackageFile");
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

/* method: new of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_new01
static int tolua_IOLuaAPI_PackageFile_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PackageFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  unsigned startOffset = ((unsigned)  tolua_tonumber(tolua_S,3,0));
 {
  PackageFile* tolua_ret = (PackageFile*)  Mtolua_new((PackageFile)(fileName,startOffset));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"PackageFile");
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_PackageFile_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_new01_local
static int tolua_IOLuaAPI_PackageFile_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PackageFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  unsigned startOffset = ((unsigned)  tolua_tonumber(tolua_S,3,0));
 {
  PackageFile* tolua_ret = (PackageFile*)  Mtolua_new((PackageFile)(fileName,startOffset));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"PackageFile");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_PackageFile_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_delete00
static int tolua_IOLuaAPI_PackageFile_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PackageFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PackageFile* self = (PackageFile*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Open of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_Open00
static int tolua_IOLuaAPI_PackageFile_Open00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PackageFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PackageFile* self = (PackageFile*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  unsigned startOffset = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Open'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Open(fileName,startOffset);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Open'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Exists of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_Exists00
static int tolua_IOLuaAPI_PackageFile_Exists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PackageFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PackageFile* self = (const PackageFile*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exists'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Exists(fileName);
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

/* method: GetEntry of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_GetEntry00
static int tolua_IOLuaAPI_PackageFile_GetEntry00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PackageFile",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PackageFile* self = (const PackageFile*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEntry'", NULL);
#endif
 {
  const PackageEntry* tolua_ret = (const PackageEntry*)  self->GetEntry(fileName);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"const PackageEntry");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEntry'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEntries of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_GetEntries00
static int tolua_IOLuaAPI_PackageFile_GetEntries00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PackageFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PackageFile* self = (const PackageFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEntries'", NULL);
#endif
 {
  const HashMap<String,PackageEntry>& tolua_ret = (const HashMap<String,PackageEntry>&)  self->GetEntries();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const HashMap<String,PackageEntry>");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEntries'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_GetName00
static int tolua_IOLuaAPI_PackageFile_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PackageFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PackageFile* self = (const PackageFile*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetNameHash of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_GetNameHash00
static int tolua_IOLuaAPI_PackageFile_GetNameHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PackageFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PackageFile* self = (const PackageFile*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetNumFiles of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_GetNumFiles00
static int tolua_IOLuaAPI_PackageFile_GetNumFiles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PackageFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PackageFile* self = (const PackageFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumFiles'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumFiles();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumFiles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTotalSize of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_GetTotalSize00
static int tolua_IOLuaAPI_PackageFile_GetTotalSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PackageFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PackageFile* self = (const PackageFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTotalSize'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetTotalSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTotalSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTotalDataSize of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_GetTotalDataSize00
static int tolua_IOLuaAPI_PackageFile_GetTotalDataSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PackageFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PackageFile* self = (const PackageFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTotalDataSize'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetTotalDataSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTotalDataSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetChecksum of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_GetChecksum00
static int tolua_IOLuaAPI_PackageFile_GetChecksum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PackageFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PackageFile* self = (const PackageFile*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsCompressed of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_PackageFile_IsCompressed00
static int tolua_IOLuaAPI_PackageFile_IsCompressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const PackageFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const PackageFile* self = (const PackageFile*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: name of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_get_PackageFile_name
static int tolua_get_PackageFile_name(lua_State* tolua_S)
{
  PackageFile* self = (PackageFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nameHash of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_get_PackageFile_nameHash
static int tolua_get_PackageFile_nameHash(lua_State* tolua_S)
{
  PackageFile* self = (PackageFile*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: numFiles of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_get_PackageFile_numFiles
static int tolua_get_PackageFile_numFiles(lua_State* tolua_S)
{
  PackageFile* self = (PackageFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numFiles'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumFiles());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: totalSize of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_get_PackageFile_totalSize
static int tolua_get_PackageFile_totalSize(lua_State* tolua_S)
{
  PackageFile* self = (PackageFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'totalSize'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTotalSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: totalDataSize of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_get_PackageFile_totalDataSize
static int tolua_get_PackageFile_totalDataSize(lua_State* tolua_S)
{
  PackageFile* self = (PackageFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'totalDataSize'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTotalDataSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: checksum of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_get_PackageFile_checksum
static int tolua_get_PackageFile_checksum(lua_State* tolua_S)
{
  PackageFile* self = (PackageFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'checksum'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetChecksum());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: compressed of class  PackageFile */
#ifndef TOLUA_DISABLE_tolua_get_PackageFile_compressed
static int tolua_get_PackageFile_compressed(lua_State* tolua_S)
{
  PackageFile* self = (PackageFile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'compressed'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsCompressed());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SerializerWrite of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_Write00
static int tolua_IOLuaAPI_Serializer_Write00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VectorBuffer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const VectorBuffer* buffer = ((const VectorBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SerializerWrite'", NULL);
#endif
 {
  tolua_outside unsigned tolua_ret = (tolua_outside unsigned)  SerializerWrite(self,*buffer);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Write'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteInt of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteInt00
static int tolua_IOLuaAPI_Serializer_WriteInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteInt'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteInt(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteInt64 of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteInt6400
static int tolua_IOLuaAPI_Serializer_WriteInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  long long value = ((long long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteInt64'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteInt64(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteShort of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteShort00
static int tolua_IOLuaAPI_Serializer_WriteShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  short value = ((short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteShort'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteShort(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteShort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteByte of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteByte00
static int tolua_IOLuaAPI_Serializer_WriteByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  signed char value = ((signed char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteByte'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteByte(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteByte'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteUInt of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteUInt00
static int tolua_IOLuaAPI_Serializer_WriteUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteUInt'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteUInt(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteUInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteUInt64 of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteUInt6400
static int tolua_IOLuaAPI_Serializer_WriteUInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  unsigned long long value = ((unsigned long long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteUInt64'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteUInt64(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteUInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteUShort of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteUShort00
static int tolua_IOLuaAPI_Serializer_WriteUShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  unsigned short value = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteUShort'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteUShort(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteUShort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteUByte of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteUByte00
static int tolua_IOLuaAPI_Serializer_WriteUByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  unsigned char value = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteUByte'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteUByte(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteUByte'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteBool of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteBool00
static int tolua_IOLuaAPI_Serializer_WriteBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteBool'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteBool(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteFloat of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteFloat00
static int tolua_IOLuaAPI_Serializer_WriteFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteFloat'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteFloat(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteDouble of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteDouble00
static int tolua_IOLuaAPI_Serializer_WriteDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  double value = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteDouble'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteDouble(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteDouble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteIntRect of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteIntRect00
static int tolua_IOLuaAPI_Serializer_WriteIntRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* value = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteIntRect'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteIntRect(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteIntRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteIntVector2 of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteIntVector200
static int tolua_IOLuaAPI_Serializer_WriteIntVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* value = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteIntVector2'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteIntVector2(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteIntVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteIntVector3 of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteIntVector300
static int tolua_IOLuaAPI_Serializer_WriteIntVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const IntVector3* value = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteIntVector3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteIntVector3(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteIntVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteRect of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteRect00
static int tolua_IOLuaAPI_Serializer_WriteRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const Rect* value = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteRect'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteRect(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVector2 of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteVector200
static int tolua_IOLuaAPI_Serializer_WriteVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* value = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVector2'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVector2(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVector3 of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteVector300
static int tolua_IOLuaAPI_Serializer_WriteVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* value = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVector3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVector3(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WritePackedVector3 of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WritePackedVector300
static int tolua_IOLuaAPI_Serializer_WritePackedVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* value = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float maxAbsCoord = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WritePackedVector3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WritePackedVector3(*value,maxAbsCoord);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WritePackedVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVector4 of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteVector400
static int tolua_IOLuaAPI_Serializer_WriteVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* value = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVector4'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVector4(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteQuaternion of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteQuaternion00
static int tolua_IOLuaAPI_Serializer_WriteQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* value = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteQuaternion'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteQuaternion(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WritePackedQuaternion of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WritePackedQuaternion00
static int tolua_IOLuaAPI_Serializer_WritePackedQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* value = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WritePackedQuaternion'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WritePackedQuaternion(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WritePackedQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteMatrix3 of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteMatrix300
static int tolua_IOLuaAPI_Serializer_WriteMatrix300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* value = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteMatrix3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteMatrix3(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteMatrix3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteMatrix3x4 of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteMatrix3x400
static int tolua_IOLuaAPI_Serializer_WriteMatrix3x400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* value = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteMatrix3x4'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteMatrix3x4(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteMatrix3x4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteMatrix4 of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteMatrix400
static int tolua_IOLuaAPI_Serializer_WriteMatrix400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* value = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteMatrix4'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteMatrix4(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteMatrix4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteColor of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteColor00
static int tolua_IOLuaAPI_Serializer_WriteColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const Color* value = ((const Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteColor'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteColor(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteBoundingBox of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteBoundingBox00
static int tolua_IOLuaAPI_Serializer_WriteBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* value = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteBoundingBox'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteBoundingBox(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteString of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteString00
static int tolua_IOLuaAPI_Serializer_WriteString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteString'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteString(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteFileID of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteFileID00
static int tolua_IOLuaAPI_Serializer_WriteFileID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteFileID'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteFileID(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteFileID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteStringHash of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteStringHash00
static int tolua_IOLuaAPI_Serializer_WriteStringHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const StringHash* value = ((const StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteStringHash'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteStringHash(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteStringHash'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SerializerWriteBuffer of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteBuffer00
static int tolua_IOLuaAPI_Serializer_WriteBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VectorBuffer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const VectorBuffer* buffer = ((const VectorBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SerializerWriteBuffer'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SerializerWriteBuffer(self,*buffer);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteResourceRef of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteResourceRef00
static int tolua_IOLuaAPI_Serializer_WriteResourceRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ResourceRef",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const ResourceRef* value = ((const ResourceRef*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteResourceRef'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteResourceRef(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteResourceRef'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteResourceRefList of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteResourceRefList00
static int tolua_IOLuaAPI_Serializer_WriteResourceRefList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ResourceRefList",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const ResourceRefList* value = ((const ResourceRefList*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteResourceRefList'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteResourceRefList(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteResourceRefList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariant of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteVariant00
static int tolua_IOLuaAPI_Serializer_WriteVariant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariant'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariant(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariantData of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteVariantData00
static int tolua_IOLuaAPI_Serializer_WriteVariantData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariantData'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariantData(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariantData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariantVector of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteVariantVector00
static int tolua_IOLuaAPI_Serializer_WriteVariantVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VariantVector",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const VariantVector* value = ((const VariantVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariantVector'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariantVector(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariantVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariantMap of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteVariantMap00
static int tolua_IOLuaAPI_Serializer_WriteVariantMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const VariantMap* value = ((const VariantMap*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariantMap'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariantMap(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariantMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVLE of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteVLE00
static int tolua_IOLuaAPI_Serializer_WriteVLE00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVLE'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVLE(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVLE'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteNetID of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteNetID00
static int tolua_IOLuaAPI_Serializer_WriteNetID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteNetID'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteNetID(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteNetID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteLine of class  Serializer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_Serializer_WriteLine00
static int tolua_IOLuaAPI_Serializer_WriteLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Serializer",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Serializer* self = (Serializer*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteLine'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteLine(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_new00
static int tolua_IOLuaAPI_VectorBuffer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  VectorBuffer* tolua_ret = (VectorBuffer*)  Mtolua_new((VectorBuffer)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"VectorBuffer");
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

/* method: new_local of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_new00_local
static int tolua_IOLuaAPI_VectorBuffer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  VectorBuffer* tolua_ret = (VectorBuffer*)  Mtolua_new((VectorBuffer)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"VectorBuffer");
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

/* method: new of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_new01
static int tolua_IOLuaAPI_VectorBuffer_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Deserializer",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Deserializer* source = ((Deserializer*)  tolua_tousertype(tolua_S,2,0));
  unsigned size = ((unsigned)  tolua_tonumber(tolua_S,3,0));
 {
  VectorBuffer* tolua_ret = (VectorBuffer*)  Mtolua_new((VectorBuffer)(*source,size));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"VectorBuffer");
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_VectorBuffer_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_new01_local
static int tolua_IOLuaAPI_VectorBuffer_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Deserializer",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Deserializer* source = ((Deserializer*)  tolua_tousertype(tolua_S,2,0));
  unsigned size = ((unsigned)  tolua_tonumber(tolua_S,3,0));
 {
  VectorBuffer* tolua_ret = (VectorBuffer*)  Mtolua_new((VectorBuffer)(*source,size));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"VectorBuffer");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_IOLuaAPI_VectorBuffer_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_delete00
static int tolua_IOLuaAPI_VectorBuffer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetData of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_SetData00
static int tolua_IOLuaAPI_VectorBuffer_SetData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Deserializer",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  Deserializer* source = ((Deserializer*)  tolua_tousertype(tolua_S,2,0));
  unsigned size = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetData'", NULL);
#endif
 {
  self->SetData(*source,size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_Clear00
static int tolua_IOLuaAPI_VectorBuffer_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Resize of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_Resize00
static int tolua_IOLuaAPI_VectorBuffer_Resize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  unsigned size = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Resize'", NULL);
#endif
 {
  self->Resize(size);
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

/* method: GetData of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_GetData00
static int tolua_IOLuaAPI_VectorBuffer_GetData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const VectorBuffer* self = (const VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetData'", NULL);
#endif
 {
  const void* tolua_ret = (const void*)  self->GetData();
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetModifiableData of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_GetModifiableData00
static int tolua_IOLuaAPI_VectorBuffer_GetModifiableData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetModifiableData'", NULL);
#endif
 {
  void* tolua_ret = (void*)  self->GetModifiableData();
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetModifiableData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DeserializerRead of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_Read00
static int tolua_IOLuaAPI_VectorBuffer_Read00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  unsigned size = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeserializerRead'", NULL);
#endif
 {
  tolua_outside VectorBuffer tolua_ret = (tolua_outside VectorBuffer)  DeserializerRead(self,size);
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

/* method: Seek of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_Seek00
static int tolua_IOLuaAPI_VectorBuffer_Seek00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  unsigned position = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Seek'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->Seek(position);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Seek'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SeekRelative of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_SeekRelative00
static int tolua_IOLuaAPI_VectorBuffer_SeekRelative00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  int delta = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SeekRelative'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->SeekRelative(delta);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SeekRelative'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_GetName00
static int tolua_IOLuaAPI_VectorBuffer_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const VectorBuffer* self = (const VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetChecksum of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_GetChecksum00
static int tolua_IOLuaAPI_VectorBuffer_GetChecksum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetPosition of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_GetPosition00
static int tolua_IOLuaAPI_VectorBuffer_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const VectorBuffer* self = (const VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetPosition();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: Tell of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_Tell00
static int tolua_IOLuaAPI_VectorBuffer_Tell00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const VectorBuffer* self = (const VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Tell'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->Tell();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Tell'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSize of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_GetSize00
static int tolua_IOLuaAPI_VectorBuffer_GetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const VectorBuffer* self = (const VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSize'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: IsEof of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_IsEof00
static int tolua_IOLuaAPI_VectorBuffer_IsEof00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const VectorBuffer* self = (const VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadInt of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadInt00
static int tolua_IOLuaAPI_VectorBuffer_ReadInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadInt64 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadInt6400
static int tolua_IOLuaAPI_VectorBuffer_ReadInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadInt64'", NULL);
#endif
 {
  long long tolua_ret = (long long)  self->ReadInt64();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadShort of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadShort00
static int tolua_IOLuaAPI_VectorBuffer_ReadShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadByte of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadByte00
static int tolua_IOLuaAPI_VectorBuffer_ReadByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadUInt of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadUInt00
static int tolua_IOLuaAPI_VectorBuffer_ReadUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadUInt64 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadUInt6400
static int tolua_IOLuaAPI_VectorBuffer_ReadUInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadUInt64'", NULL);
#endif
 {
  unsigned long long tolua_ret = (unsigned long long)  self->ReadUInt64();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadUInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadUShort of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadUShort00
static int tolua_IOLuaAPI_VectorBuffer_ReadUShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadUByte of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadUByte00
static int tolua_IOLuaAPI_VectorBuffer_ReadUByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadBool of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadBool00
static int tolua_IOLuaAPI_VectorBuffer_ReadBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadFloat of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadFloat00
static int tolua_IOLuaAPI_VectorBuffer_ReadFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadDouble of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadDouble00
static int tolua_IOLuaAPI_VectorBuffer_ReadDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadIntRect of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadIntRect00
static int tolua_IOLuaAPI_VectorBuffer_ReadIntRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadIntVector2 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadIntVector200
static int tolua_IOLuaAPI_VectorBuffer_ReadIntVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadIntVector3 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadIntVector300
static int tolua_IOLuaAPI_VectorBuffer_ReadIntVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadRect of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadRect00
static int tolua_IOLuaAPI_VectorBuffer_ReadRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVector2 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadVector200
static int tolua_IOLuaAPI_VectorBuffer_ReadVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVector3 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadVector300
static int tolua_IOLuaAPI_VectorBuffer_ReadVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadPackedVector3 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadPackedVector300
static int tolua_IOLuaAPI_VectorBuffer_ReadPackedVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVector4 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadVector400
static int tolua_IOLuaAPI_VectorBuffer_ReadVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadQuaternion of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadQuaternion00
static int tolua_IOLuaAPI_VectorBuffer_ReadQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadPackedQuaternion of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadPackedQuaternion00
static int tolua_IOLuaAPI_VectorBuffer_ReadPackedQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadMatrix3 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadMatrix300
static int tolua_IOLuaAPI_VectorBuffer_ReadMatrix300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadMatrix3x4 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadMatrix3x400
static int tolua_IOLuaAPI_VectorBuffer_ReadMatrix3x400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadMatrix4 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadMatrix400
static int tolua_IOLuaAPI_VectorBuffer_ReadMatrix400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadColor of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadColor00
static int tolua_IOLuaAPI_VectorBuffer_ReadColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadBoundingBox of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadBoundingBox00
static int tolua_IOLuaAPI_VectorBuffer_ReadBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadString of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadString00
static int tolua_IOLuaAPI_VectorBuffer_ReadString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadFileID of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadFileID00
static int tolua_IOLuaAPI_VectorBuffer_ReadFileID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadStringHash of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadStringHash00
static int tolua_IOLuaAPI_VectorBuffer_ReadStringHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadBuffer of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadBuffer00
static int tolua_IOLuaAPI_VectorBuffer_ReadBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadResourceRef of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadResourceRef00
static int tolua_IOLuaAPI_VectorBuffer_ReadResourceRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadResourceRefList of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadResourceRefList00
static int tolua_IOLuaAPI_VectorBuffer_ReadResourceRefList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVariant of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadVariant00
static int tolua_IOLuaAPI_VectorBuffer_ReadVariant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVariant of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadVariant01
static int tolua_IOLuaAPI_VectorBuffer_ReadVariant01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"VariantType",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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
 return tolua_IOLuaAPI_VectorBuffer_ReadVariant00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadVariantVector of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadVariantVector00
static int tolua_IOLuaAPI_VectorBuffer_ReadVariantVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVariantMap of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadVariantMap00
static int tolua_IOLuaAPI_VectorBuffer_ReadVariantMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadVLE of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadVLE00
static int tolua_IOLuaAPI_VectorBuffer_ReadVLE00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadNetID of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadNetID00
static int tolua_IOLuaAPI_VectorBuffer_ReadNetID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ReadLine of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_ReadLine00
static int tolua_IOLuaAPI_VectorBuffer_ReadLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SerializerWrite of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_Write00
static int tolua_IOLuaAPI_VectorBuffer_Write00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VectorBuffer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const VectorBuffer* buffer = ((const VectorBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SerializerWrite'", NULL);
#endif
 {
  tolua_outside unsigned tolua_ret = (tolua_outside unsigned)  SerializerWrite(self,*buffer);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Write'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteInt of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteInt00
static int tolua_IOLuaAPI_VectorBuffer_WriteInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteInt'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteInt(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteInt64 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteInt6400
static int tolua_IOLuaAPI_VectorBuffer_WriteInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  long long value = ((long long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteInt64'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteInt64(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteShort of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteShort00
static int tolua_IOLuaAPI_VectorBuffer_WriteShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  short value = ((short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteShort'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteShort(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteShort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteByte of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteByte00
static int tolua_IOLuaAPI_VectorBuffer_WriteByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  signed char value = ((signed char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteByte'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteByte(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteByte'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteUInt of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteUInt00
static int tolua_IOLuaAPI_VectorBuffer_WriteUInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteUInt'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteUInt(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteUInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteUInt64 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteUInt6400
static int tolua_IOLuaAPI_VectorBuffer_WriteUInt6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  unsigned long long value = ((unsigned long long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteUInt64'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteUInt64(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteUInt64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteUShort of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteUShort00
static int tolua_IOLuaAPI_VectorBuffer_WriteUShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  unsigned short value = ((unsigned short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteUShort'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteUShort(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteUShort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteUByte of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteUByte00
static int tolua_IOLuaAPI_VectorBuffer_WriteUByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  unsigned char value = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteUByte'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteUByte(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteUByte'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteBool of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteBool00
static int tolua_IOLuaAPI_VectorBuffer_WriteBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteBool'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteBool(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteFloat of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteFloat00
static int tolua_IOLuaAPI_VectorBuffer_WriteFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteFloat'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteFloat(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteDouble of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteDouble00
static int tolua_IOLuaAPI_VectorBuffer_WriteDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  double value = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteDouble'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteDouble(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteDouble'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteIntRect of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteIntRect00
static int tolua_IOLuaAPI_VectorBuffer_WriteIntRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* value = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteIntRect'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteIntRect(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteIntRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteIntVector2 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteIntVector200
static int tolua_IOLuaAPI_VectorBuffer_WriteIntVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* value = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteIntVector2'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteIntVector2(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteIntVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteIntVector3 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteIntVector300
static int tolua_IOLuaAPI_VectorBuffer_WriteIntVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const IntVector3* value = ((const IntVector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteIntVector3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteIntVector3(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteIntVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteRect of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteRect00
static int tolua_IOLuaAPI_VectorBuffer_WriteRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const Rect* value = ((const Rect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteRect'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteRect(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVector2 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteVector200
static int tolua_IOLuaAPI_VectorBuffer_WriteVector200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* value = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVector2'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVector2(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVector3 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteVector300
static int tolua_IOLuaAPI_VectorBuffer_WriteVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* value = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVector3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVector3(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WritePackedVector3 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WritePackedVector300
static int tolua_IOLuaAPI_VectorBuffer_WritePackedVector300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* value = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float maxAbsCoord = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WritePackedVector3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WritePackedVector3(*value,maxAbsCoord);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WritePackedVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVector4 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteVector400
static int tolua_IOLuaAPI_VectorBuffer_WriteVector400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* value = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVector4'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVector4(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteQuaternion of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteQuaternion00
static int tolua_IOLuaAPI_VectorBuffer_WriteQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* value = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteQuaternion'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteQuaternion(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WritePackedQuaternion of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WritePackedQuaternion00
static int tolua_IOLuaAPI_VectorBuffer_WritePackedQuaternion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* value = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WritePackedQuaternion'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WritePackedQuaternion(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WritePackedQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteMatrix3 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteMatrix300
static int tolua_IOLuaAPI_VectorBuffer_WriteMatrix300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3* value = ((const Matrix3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteMatrix3'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteMatrix3(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteMatrix3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteMatrix3x4 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteMatrix3x400
static int tolua_IOLuaAPI_VectorBuffer_WriteMatrix3x400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix3x4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const Matrix3x4* value = ((const Matrix3x4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteMatrix3x4'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteMatrix3x4(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteMatrix3x4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteMatrix4 of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteMatrix400
static int tolua_IOLuaAPI_VectorBuffer_WriteMatrix400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* value = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteMatrix4'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteMatrix4(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteMatrix4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteColor of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteColor00
static int tolua_IOLuaAPI_VectorBuffer_WriteColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const Color* value = ((const Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteColor'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteColor(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteBoundingBox of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteBoundingBox00
static int tolua_IOLuaAPI_VectorBuffer_WriteBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const BoundingBox",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const BoundingBox* value = ((const BoundingBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteBoundingBox'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteBoundingBox(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteString of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteString00
static int tolua_IOLuaAPI_VectorBuffer_WriteString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteString'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteString(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteFileID of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteFileID00
static int tolua_IOLuaAPI_VectorBuffer_WriteFileID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteFileID'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteFileID(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteFileID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteStringHash of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteStringHash00
static int tolua_IOLuaAPI_VectorBuffer_WriteStringHash00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const StringHash* value = ((const StringHash*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteStringHash'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteStringHash(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteStringHash'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SerializerWriteBuffer of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteBuffer00
static int tolua_IOLuaAPI_VectorBuffer_WriteBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VectorBuffer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const VectorBuffer* buffer = ((const VectorBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SerializerWriteBuffer'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SerializerWriteBuffer(self,*buffer);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteResourceRef of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteResourceRef00
static int tolua_IOLuaAPI_VectorBuffer_WriteResourceRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ResourceRef",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const ResourceRef* value = ((const ResourceRef*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteResourceRef'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteResourceRef(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteResourceRef'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteResourceRefList of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteResourceRefList00
static int tolua_IOLuaAPI_VectorBuffer_WriteResourceRefList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ResourceRefList",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const ResourceRefList* value = ((const ResourceRefList*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteResourceRefList'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteResourceRefList(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteResourceRefList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariant of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteVariant00
static int tolua_IOLuaAPI_VectorBuffer_WriteVariant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariant'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariant(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariantData of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteVariantData00
static int tolua_IOLuaAPI_VectorBuffer_WriteVariantData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const Variant* value = ((const Variant*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariantData'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariantData(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariantData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariantVector of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteVariantVector00
static int tolua_IOLuaAPI_VectorBuffer_WriteVariantVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VariantVector",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const VariantVector* value = ((const VariantVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariantVector'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariantVector(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariantVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVariantMap of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteVariantMap00
static int tolua_IOLuaAPI_VectorBuffer_WriteVariantMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VariantMap",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const VariantMap* value = ((const VariantMap*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVariantMap'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVariantMap(*value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVariantMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteVLE of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteVLE00
static int tolua_IOLuaAPI_VectorBuffer_WriteVLE00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteVLE'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteVLE(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteVLE'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteNetID of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteNetID00
static int tolua_IOLuaAPI_VectorBuffer_WriteNetID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  unsigned value = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteNetID'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteNetID(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteNetID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WriteLine of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_IOLuaAPI_VectorBuffer_WriteLine00
static int tolua_IOLuaAPI_VectorBuffer_WriteLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VectorBuffer",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
  const String value = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WriteLine'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->WriteLine(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WriteLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_get_VectorBuffer_name
static int tolua_get_VectorBuffer_name(lua_State* tolua_S)
{
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: checksum of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_get_VectorBuffer_checksum
static int tolua_get_VectorBuffer_checksum(lua_State* tolua_S)
{
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'checksum'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetChecksum());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: position of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_get_VectorBuffer_position
static int tolua_get_VectorBuffer_position(lua_State* tolua_S)
{
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetPosition());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: size of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_get_VectorBuffer_size
static int tolua_get_VectorBuffer_size(lua_State* tolua_S)
{
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: eof of class  VectorBuffer */
#ifndef TOLUA_DISABLE_tolua_get_VectorBuffer_eof
static int tolua_get_VectorBuffer_eof(lua_State* tolua_S)
{
  VectorBuffer* self = (VectorBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eof'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsEof());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_IOLuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
 tolua_function(tolua_S,"CompressVectorBuffer",tolua_IOLuaAPI_CompressVectorBuffer00);
 tolua_function(tolua_S,"DecompressVectorBuffer",tolua_IOLuaAPI_DecompressVectorBuffer00);
 tolua_cclass(tolua_S,"Deserializer","Deserializer","",NULL);
 tolua_beginmodule(tolua_S,"Deserializer");
  tolua_function(tolua_S,"Read",tolua_IOLuaAPI_Deserializer_Read00);
  tolua_function(tolua_S,"Seek",tolua_IOLuaAPI_Deserializer_Seek00);
  tolua_function(tolua_S,"SeekRelative",tolua_IOLuaAPI_Deserializer_SeekRelative00);
  tolua_function(tolua_S,"GetName",tolua_IOLuaAPI_Deserializer_GetName00);
  tolua_function(tolua_S,"GetChecksum",tolua_IOLuaAPI_Deserializer_GetChecksum00);
  tolua_function(tolua_S,"GetPosition",tolua_IOLuaAPI_Deserializer_GetPosition00);
  tolua_function(tolua_S,"Tell",tolua_IOLuaAPI_Deserializer_Tell00);
  tolua_function(tolua_S,"GetSize",tolua_IOLuaAPI_Deserializer_GetSize00);
  tolua_function(tolua_S,"IsEof",tolua_IOLuaAPI_Deserializer_IsEof00);
  tolua_function(tolua_S,"ReadInt",tolua_IOLuaAPI_Deserializer_ReadInt00);
  tolua_function(tolua_S,"ReadInt64",tolua_IOLuaAPI_Deserializer_ReadInt6400);
  tolua_function(tolua_S,"ReadShort",tolua_IOLuaAPI_Deserializer_ReadShort00);
  tolua_function(tolua_S,"ReadByte",tolua_IOLuaAPI_Deserializer_ReadByte00);
  tolua_function(tolua_S,"ReadUInt",tolua_IOLuaAPI_Deserializer_ReadUInt00);
  tolua_function(tolua_S,"ReadUInt64",tolua_IOLuaAPI_Deserializer_ReadUInt6400);
  tolua_function(tolua_S,"ReadUShort",tolua_IOLuaAPI_Deserializer_ReadUShort00);
  tolua_function(tolua_S,"ReadUByte",tolua_IOLuaAPI_Deserializer_ReadUByte00);
  tolua_function(tolua_S,"ReadBool",tolua_IOLuaAPI_Deserializer_ReadBool00);
  tolua_function(tolua_S,"ReadFloat",tolua_IOLuaAPI_Deserializer_ReadFloat00);
  tolua_function(tolua_S,"ReadDouble",tolua_IOLuaAPI_Deserializer_ReadDouble00);
  tolua_function(tolua_S,"ReadIntRect",tolua_IOLuaAPI_Deserializer_ReadIntRect00);
  tolua_function(tolua_S,"ReadIntVector2",tolua_IOLuaAPI_Deserializer_ReadIntVector200);
  tolua_function(tolua_S,"ReadIntVector3",tolua_IOLuaAPI_Deserializer_ReadIntVector300);
  tolua_function(tolua_S,"ReadRect",tolua_IOLuaAPI_Deserializer_ReadRect00);
  tolua_function(tolua_S,"ReadVector2",tolua_IOLuaAPI_Deserializer_ReadVector200);
  tolua_function(tolua_S,"ReadVector3",tolua_IOLuaAPI_Deserializer_ReadVector300);
  tolua_function(tolua_S,"ReadPackedVector3",tolua_IOLuaAPI_Deserializer_ReadPackedVector300);
  tolua_function(tolua_S,"ReadVector4",tolua_IOLuaAPI_Deserializer_ReadVector400);
  tolua_function(tolua_S,"ReadQuaternion",tolua_IOLuaAPI_Deserializer_ReadQuaternion00);
  tolua_function(tolua_S,"ReadPackedQuaternion",tolua_IOLuaAPI_Deserializer_ReadPackedQuaternion00);
  tolua_function(tolua_S,"ReadMatrix3",tolua_IOLuaAPI_Deserializer_ReadMatrix300);
  tolua_function(tolua_S,"ReadMatrix3x4",tolua_IOLuaAPI_Deserializer_ReadMatrix3x400);
  tolua_function(tolua_S,"ReadMatrix4",tolua_IOLuaAPI_Deserializer_ReadMatrix400);
  tolua_function(tolua_S,"ReadColor",tolua_IOLuaAPI_Deserializer_ReadColor00);
  tolua_function(tolua_S,"ReadBoundingBox",tolua_IOLuaAPI_Deserializer_ReadBoundingBox00);
  tolua_function(tolua_S,"ReadString",tolua_IOLuaAPI_Deserializer_ReadString00);
  tolua_function(tolua_S,"ReadFileID",tolua_IOLuaAPI_Deserializer_ReadFileID00);
  tolua_function(tolua_S,"ReadStringHash",tolua_IOLuaAPI_Deserializer_ReadStringHash00);
  tolua_function(tolua_S,"ReadBuffer",tolua_IOLuaAPI_Deserializer_ReadBuffer00);
  tolua_function(tolua_S,"ReadResourceRef",tolua_IOLuaAPI_Deserializer_ReadResourceRef00);
  tolua_function(tolua_S,"ReadResourceRefList",tolua_IOLuaAPI_Deserializer_ReadResourceRefList00);
  tolua_function(tolua_S,"ReadVariant",tolua_IOLuaAPI_Deserializer_ReadVariant00);
  tolua_function(tolua_S,"ReadVariant",tolua_IOLuaAPI_Deserializer_ReadVariant01);
  tolua_function(tolua_S,"ReadVariantVector",tolua_IOLuaAPI_Deserializer_ReadVariantVector00);
  tolua_function(tolua_S,"ReadVariantMap",tolua_IOLuaAPI_Deserializer_ReadVariantMap00);
  tolua_function(tolua_S,"ReadVLE",tolua_IOLuaAPI_Deserializer_ReadVLE00);
  tolua_function(tolua_S,"ReadNetID",tolua_IOLuaAPI_Deserializer_ReadNetID00);
  tolua_function(tolua_S,"ReadLine",tolua_IOLuaAPI_Deserializer_ReadLine00);
  tolua_variable(tolua_S,"name",tolua_get_Deserializer_name,NULL);
  tolua_variable(tolua_S,"checksum",tolua_get_Deserializer_checksum,NULL);
  tolua_variable(tolua_S,"position",tolua_get_Deserializer_position,NULL);
  tolua_variable(tolua_S,"size",tolua_get_Deserializer_size,NULL);
  tolua_variable(tolua_S,"eof",tolua_get_Deserializer_eof,NULL);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"FILE_READ",FILE_READ);
 tolua_constant(tolua_S,"FILE_WRITE",FILE_WRITE);
 tolua_constant(tolua_S,"FILE_READWRITE",FILE_READWRITE);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"File","File","Object",tolua_collect_File);
 #else
 tolua_cclass(tolua_S,"File","File","Object",NULL);
 #endif
 tolua_beginmodule(tolua_S,"File");
  tolua_function(tolua_S,"new",tolua_IOLuaAPI_File_new00);
  tolua_function(tolua_S,"new_local",tolua_IOLuaAPI_File_new00_local);
  tolua_function(tolua_S,".call",tolua_IOLuaAPI_File_new00_local);
  tolua_function(tolua_S,"new",tolua_IOLuaAPI_File_new01);
  tolua_function(tolua_S,"new_local",tolua_IOLuaAPI_File_new01_local);
  tolua_function(tolua_S,".call",tolua_IOLuaAPI_File_new01_local);
  tolua_function(tolua_S,"new",tolua_IOLuaAPI_File_new02);
  tolua_function(tolua_S,"new_local",tolua_IOLuaAPI_File_new02_local);
  tolua_function(tolua_S,".call",tolua_IOLuaAPI_File_new02_local);
  tolua_function(tolua_S,"delete",tolua_IOLuaAPI_File_delete00);
  tolua_function(tolua_S,"Open",tolua_IOLuaAPI_File_Open00);
  tolua_function(tolua_S,"Open",tolua_IOLuaAPI_File_Open01);
  tolua_function(tolua_S,"Close",tolua_IOLuaAPI_File_Close00);
  tolua_function(tolua_S,"Flush",tolua_IOLuaAPI_File_Flush00);
  tolua_function(tolua_S,"SetName",tolua_IOLuaAPI_File_SetName00);
  tolua_function(tolua_S,"GetMode",tolua_IOLuaAPI_File_GetMode00);
  tolua_function(tolua_S,"IsOpen",tolua_IOLuaAPI_File_IsOpen00);
  tolua_function(tolua_S,"GetHandle",tolua_IOLuaAPI_File_GetHandle00);
  tolua_function(tolua_S,"IsPackaged",tolua_IOLuaAPI_File_IsPackaged00);
  tolua_function(tolua_S,"Read",tolua_IOLuaAPI_File_Read00);
  tolua_function(tolua_S,"Seek",tolua_IOLuaAPI_File_Seek00);
  tolua_function(tolua_S,"SeekRelative",tolua_IOLuaAPI_File_SeekRelative00);
  tolua_function(tolua_S,"GetName",tolua_IOLuaAPI_File_GetName00);
  tolua_function(tolua_S,"GetChecksum",tolua_IOLuaAPI_File_GetChecksum00);
  tolua_function(tolua_S,"GetPosition",tolua_IOLuaAPI_File_GetPosition00);
  tolua_function(tolua_S,"Tell",tolua_IOLuaAPI_File_Tell00);
  tolua_function(tolua_S,"GetSize",tolua_IOLuaAPI_File_GetSize00);
  tolua_function(tolua_S,"IsEof",tolua_IOLuaAPI_File_IsEof00);
  tolua_function(tolua_S,"ReadInt",tolua_IOLuaAPI_File_ReadInt00);
  tolua_function(tolua_S,"ReadInt64",tolua_IOLuaAPI_File_ReadInt6400);
  tolua_function(tolua_S,"ReadShort",tolua_IOLuaAPI_File_ReadShort00);
  tolua_function(tolua_S,"ReadByte",tolua_IOLuaAPI_File_ReadByte00);
  tolua_function(tolua_S,"ReadUInt",tolua_IOLuaAPI_File_ReadUInt00);
  tolua_function(tolua_S,"ReadUInt64",tolua_IOLuaAPI_File_ReadUInt6400);
  tolua_function(tolua_S,"ReadUShort",tolua_IOLuaAPI_File_ReadUShort00);
  tolua_function(tolua_S,"ReadUByte",tolua_IOLuaAPI_File_ReadUByte00);
  tolua_function(tolua_S,"ReadBool",tolua_IOLuaAPI_File_ReadBool00);
  tolua_function(tolua_S,"ReadFloat",tolua_IOLuaAPI_File_ReadFloat00);
  tolua_function(tolua_S,"ReadDouble",tolua_IOLuaAPI_File_ReadDouble00);
  tolua_function(tolua_S,"ReadIntRect",tolua_IOLuaAPI_File_ReadIntRect00);
  tolua_function(tolua_S,"ReadIntVector2",tolua_IOLuaAPI_File_ReadIntVector200);
  tolua_function(tolua_S,"ReadIntVector3",tolua_IOLuaAPI_File_ReadIntVector300);
  tolua_function(tolua_S,"ReadRect",tolua_IOLuaAPI_File_ReadRect00);
  tolua_function(tolua_S,"ReadVector2",tolua_IOLuaAPI_File_ReadVector200);
  tolua_function(tolua_S,"ReadVector3",tolua_IOLuaAPI_File_ReadVector300);
  tolua_function(tolua_S,"ReadPackedVector3",tolua_IOLuaAPI_File_ReadPackedVector300);
  tolua_function(tolua_S,"ReadVector4",tolua_IOLuaAPI_File_ReadVector400);
  tolua_function(tolua_S,"ReadQuaternion",tolua_IOLuaAPI_File_ReadQuaternion00);
  tolua_function(tolua_S,"ReadPackedQuaternion",tolua_IOLuaAPI_File_ReadPackedQuaternion00);
  tolua_function(tolua_S,"ReadMatrix3",tolua_IOLuaAPI_File_ReadMatrix300);
  tolua_function(tolua_S,"ReadMatrix3x4",tolua_IOLuaAPI_File_ReadMatrix3x400);
  tolua_function(tolua_S,"ReadMatrix4",tolua_IOLuaAPI_File_ReadMatrix400);
  tolua_function(tolua_S,"ReadColor",tolua_IOLuaAPI_File_ReadColor00);
  tolua_function(tolua_S,"ReadBoundingBox",tolua_IOLuaAPI_File_ReadBoundingBox00);
  tolua_function(tolua_S,"ReadString",tolua_IOLuaAPI_File_ReadString00);
  tolua_function(tolua_S,"ReadFileID",tolua_IOLuaAPI_File_ReadFileID00);
  tolua_function(tolua_S,"ReadStringHash",tolua_IOLuaAPI_File_ReadStringHash00);
  tolua_function(tolua_S,"ReadBuffer",tolua_IOLuaAPI_File_ReadBuffer00);
  tolua_function(tolua_S,"ReadResourceRef",tolua_IOLuaAPI_File_ReadResourceRef00);
  tolua_function(tolua_S,"ReadResourceRefList",tolua_IOLuaAPI_File_ReadResourceRefList00);
  tolua_function(tolua_S,"ReadVariant",tolua_IOLuaAPI_File_ReadVariant00);
  tolua_function(tolua_S,"ReadVariant",tolua_IOLuaAPI_File_ReadVariant01);
  tolua_function(tolua_S,"ReadVariantVector",tolua_IOLuaAPI_File_ReadVariantVector00);
  tolua_function(tolua_S,"ReadVariantMap",tolua_IOLuaAPI_File_ReadVariantMap00);
  tolua_function(tolua_S,"ReadVLE",tolua_IOLuaAPI_File_ReadVLE00);
  tolua_function(tolua_S,"ReadNetID",tolua_IOLuaAPI_File_ReadNetID00);
  tolua_function(tolua_S,"ReadLine",tolua_IOLuaAPI_File_ReadLine00);
  tolua_function(tolua_S,"Write",tolua_IOLuaAPI_File_Write00);
  tolua_function(tolua_S,"WriteInt",tolua_IOLuaAPI_File_WriteInt00);
  tolua_function(tolua_S,"WriteInt64",tolua_IOLuaAPI_File_WriteInt6400);
  tolua_function(tolua_S,"WriteShort",tolua_IOLuaAPI_File_WriteShort00);
  tolua_function(tolua_S,"WriteByte",tolua_IOLuaAPI_File_WriteByte00);
  tolua_function(tolua_S,"WriteUInt",tolua_IOLuaAPI_File_WriteUInt00);
  tolua_function(tolua_S,"WriteUInt64",tolua_IOLuaAPI_File_WriteUInt6400);
  tolua_function(tolua_S,"WriteUShort",tolua_IOLuaAPI_File_WriteUShort00);
  tolua_function(tolua_S,"WriteUByte",tolua_IOLuaAPI_File_WriteUByte00);
  tolua_function(tolua_S,"WriteBool",tolua_IOLuaAPI_File_WriteBool00);
  tolua_function(tolua_S,"WriteFloat",tolua_IOLuaAPI_File_WriteFloat00);
  tolua_function(tolua_S,"WriteDouble",tolua_IOLuaAPI_File_WriteDouble00);
  tolua_function(tolua_S,"WriteIntRect",tolua_IOLuaAPI_File_WriteIntRect00);
  tolua_function(tolua_S,"WriteIntVector2",tolua_IOLuaAPI_File_WriteIntVector200);
  tolua_function(tolua_S,"WriteIntVector3",tolua_IOLuaAPI_File_WriteIntVector300);
  tolua_function(tolua_S,"WriteRect",tolua_IOLuaAPI_File_WriteRect00);
  tolua_function(tolua_S,"WriteVector2",tolua_IOLuaAPI_File_WriteVector200);
  tolua_function(tolua_S,"WriteVector3",tolua_IOLuaAPI_File_WriteVector300);
  tolua_function(tolua_S,"WritePackedVector3",tolua_IOLuaAPI_File_WritePackedVector300);
  tolua_function(tolua_S,"WriteVector4",tolua_IOLuaAPI_File_WriteVector400);
  tolua_function(tolua_S,"WriteQuaternion",tolua_IOLuaAPI_File_WriteQuaternion00);
  tolua_function(tolua_S,"WritePackedQuaternion",tolua_IOLuaAPI_File_WritePackedQuaternion00);
  tolua_function(tolua_S,"WriteMatrix3",tolua_IOLuaAPI_File_WriteMatrix300);
  tolua_function(tolua_S,"WriteMatrix3x4",tolua_IOLuaAPI_File_WriteMatrix3x400);
  tolua_function(tolua_S,"WriteMatrix4",tolua_IOLuaAPI_File_WriteMatrix400);
  tolua_function(tolua_S,"WriteColor",tolua_IOLuaAPI_File_WriteColor00);
  tolua_function(tolua_S,"WriteBoundingBox",tolua_IOLuaAPI_File_WriteBoundingBox00);
  tolua_function(tolua_S,"WriteString",tolua_IOLuaAPI_File_WriteString00);
  tolua_function(tolua_S,"WriteFileID",tolua_IOLuaAPI_File_WriteFileID00);
  tolua_function(tolua_S,"WriteStringHash",tolua_IOLuaAPI_File_WriteStringHash00);
  tolua_function(tolua_S,"WriteBuffer",tolua_IOLuaAPI_File_WriteBuffer00);
  tolua_function(tolua_S,"WriteResourceRef",tolua_IOLuaAPI_File_WriteResourceRef00);
  tolua_function(tolua_S,"WriteResourceRefList",tolua_IOLuaAPI_File_WriteResourceRefList00);
  tolua_function(tolua_S,"WriteVariant",tolua_IOLuaAPI_File_WriteVariant00);
  tolua_function(tolua_S,"WriteVariantData",tolua_IOLuaAPI_File_WriteVariantData00);
  tolua_function(tolua_S,"WriteVariantVector",tolua_IOLuaAPI_File_WriteVariantVector00);
  tolua_function(tolua_S,"WriteVariantMap",tolua_IOLuaAPI_File_WriteVariantMap00);
  tolua_function(tolua_S,"WriteVLE",tolua_IOLuaAPI_File_WriteVLE00);
  tolua_function(tolua_S,"WriteNetID",tolua_IOLuaAPI_File_WriteNetID00);
  tolua_function(tolua_S,"WriteLine",tolua_IOLuaAPI_File_WriteLine00);
  tolua_variable(tolua_S,"mode",tolua_get_File_mode,NULL);
  tolua_variable(tolua_S,"open",tolua_get_File_open,NULL);
  tolua_variable(tolua_S,"packaged",tolua_get_File_packaged,NULL);
  tolua_variable(tolua_S,"name",tolua_get_File_name,NULL);
  tolua_variable(tolua_S,"checksum",tolua_get_File_checksum,NULL);
  tolua_variable(tolua_S,"position",tolua_get_File_position,NULL);
  tolua_variable(tolua_S,"size",tolua_get_File_size,NULL);
  tolua_variable(tolua_S,"eof",tolua_get_File_eof,NULL);
 tolua_endmodule(tolua_S);
 tolua_variable(tolua_S,"SCAN_FILES",tolua_get_SCAN_FILES,NULL);
 tolua_variable(tolua_S,"SCAN_DIRS",tolua_get_SCAN_DIRS,NULL);
 tolua_variable(tolua_S,"SCAN_HIDDEN",tolua_get_SCAN_HIDDEN,NULL);
 tolua_cclass(tolua_S,"FileSystem","FileSystem","Object",NULL);
 tolua_beginmodule(tolua_S,"FileSystem");
  tolua_function(tolua_S,"SetCurrentDir",tolua_IOLuaAPI_FileSystem_SetCurrentDir00);
  tolua_function(tolua_S,"CreateDir",tolua_IOLuaAPI_FileSystem_CreateDir00);
  tolua_function(tolua_S,"SetExecuteConsoleCommands",tolua_IOLuaAPI_FileSystem_SetExecuteConsoleCommands00);
  tolua_function(tolua_S,"SystemCommand",tolua_IOLuaAPI_FileSystem_SystemCommand00);
  tolua_function(tolua_S,"SystemRun",tolua_IOLuaAPI_FileSystem_SystemRun00);
  tolua_function(tolua_S,"SystemCommandAsync",tolua_IOLuaAPI_FileSystem_SystemCommandAsync00);
  tolua_function(tolua_S,"SystemRunAsync",tolua_IOLuaAPI_FileSystem_SystemRunAsync00);
  tolua_function(tolua_S,"SystemOpen",tolua_IOLuaAPI_FileSystem_SystemOpen00);
  tolua_function(tolua_S,"Copy",tolua_IOLuaAPI_FileSystem_Copy00);
  tolua_function(tolua_S,"Rename",tolua_IOLuaAPI_FileSystem_Rename00);
  tolua_function(tolua_S,"Delete",tolua_IOLuaAPI_FileSystem_Delete00);
  tolua_function(tolua_S,"SetLastModifiedTime",tolua_IOLuaAPI_FileSystem_SetLastModifiedTime00);
  tolua_function(tolua_S,"GetCurrentDir",tolua_IOLuaAPI_FileSystem_GetCurrentDir00);
  tolua_function(tolua_S,"GetExecuteConsoleCommands",tolua_IOLuaAPI_FileSystem_GetExecuteConsoleCommands00);
  tolua_function(tolua_S,"HasRegisteredPaths",tolua_IOLuaAPI_FileSystem_HasRegisteredPaths00);
  tolua_function(tolua_S,"CheckAccess",tolua_IOLuaAPI_FileSystem_CheckAccess00);
  tolua_function(tolua_S,"GetLastModifiedTime",tolua_IOLuaAPI_FileSystem_GetLastModifiedTime00);
  tolua_function(tolua_S,"FileExists",tolua_IOLuaAPI_FileSystem_FileExists00);
  tolua_function(tolua_S,"DirExists",tolua_IOLuaAPI_FileSystem_DirExists00);
  tolua_function(tolua_S,"ScanDir",tolua_IOLuaAPI_FileSystem_ScanDir00);
  tolua_function(tolua_S,"GetProgramDir",tolua_IOLuaAPI_FileSystem_GetProgramDir00);
  tolua_function(tolua_S,"GetUserDocumentsDir",tolua_IOLuaAPI_FileSystem_GetUserDocumentsDir00);
  tolua_function(tolua_S,"GetAppPreferencesDir",tolua_IOLuaAPI_FileSystem_GetAppPreferencesDir00);
  tolua_function(tolua_S,"GetTemporaryDir",tolua_IOLuaAPI_FileSystem_GetTemporaryDir00);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"GetPath",tolua_IOLuaAPI_GetPath00);
 tolua_function(tolua_S,"GetFileName",tolua_IOLuaAPI_GetFileName00);
 tolua_function(tolua_S,"GetExtension",tolua_IOLuaAPI_GetExtension00);
 tolua_function(tolua_S,"GetFileNameAndExtension",tolua_IOLuaAPI_GetFileNameAndExtension00);
 tolua_function(tolua_S,"ReplaceExtension",tolua_IOLuaAPI_ReplaceExtension00);
 tolua_function(tolua_S,"AddTrailingSlash",tolua_IOLuaAPI_AddTrailingSlash00);
 tolua_function(tolua_S,"RemoveTrailingSlash",tolua_IOLuaAPI_RemoveTrailingSlash00);
 tolua_function(tolua_S,"GetParentPath",tolua_IOLuaAPI_GetParentPath00);
 tolua_function(tolua_S,"GetInternalPath",tolua_IOLuaAPI_GetInternalPath00);
 tolua_function(tolua_S,"GetNativePath",tolua_IOLuaAPI_GetNativePath00);
 tolua_function(tolua_S,"IsAbsolutePath",tolua_IOLuaAPI_IsAbsolutePath00);
 tolua_function(tolua_S,"GetFileSizeString",tolua_IOLuaAPI_GetFileSizeString00);
 tolua_function(tolua_S,"GetFileSystem",tolua_IOLuaAPI_GetFileSystem00);
 tolua_variable(tolua_S,"fileSystem",tolua_get_fileSystem_ptr,NULL);
 tolua_variable(tolua_S,"LOG_TRACE",tolua_get_LOG_TRACE,NULL);
 tolua_variable(tolua_S,"LOG_DEBUG",tolua_get_LOG_DEBUG,NULL);
 tolua_variable(tolua_S,"LOG_INFO",tolua_get_LOG_INFO,NULL);
 tolua_variable(tolua_S,"LOG_WARNING",tolua_get_LOG_WARNING,NULL);
 tolua_variable(tolua_S,"LOG_ERROR",tolua_get_LOG_ERROR,NULL);
 tolua_variable(tolua_S,"LOG_NONE",tolua_get_LOG_NONE,NULL);
 tolua_cclass(tolua_S,"Log","Log","Object",NULL);
 tolua_beginmodule(tolua_S,"Log");
  tolua_function(tolua_S,"Open",tolua_IOLuaAPI_Log_Open00);
  tolua_function(tolua_S,"Close",tolua_IOLuaAPI_Log_Close00);
  tolua_function(tolua_S,"SetLevel",tolua_IOLuaAPI_Log_SetLevel00);
  tolua_function(tolua_S,"SetTimeStamp",tolua_IOLuaAPI_Log_SetTimeStamp00);
  tolua_function(tolua_S,"SetQuiet",tolua_IOLuaAPI_Log_SetQuiet00);
  tolua_function(tolua_S,"GetLevel",tolua_IOLuaAPI_Log_GetLevel00);
  tolua_function(tolua_S,"GetTimeStamp",tolua_IOLuaAPI_Log_GetTimeStamp00);
  tolua_function(tolua_S,"GetLastMessage",tolua_IOLuaAPI_Log_GetLastMessage00);
  tolua_function(tolua_S,"IsQuiet",tolua_IOLuaAPI_Log_IsQuiet00);
  tolua_function(tolua_S,"Write",tolua_IOLuaAPI_Log_Write00);
  tolua_function(tolua_S,"WriteRaw",tolua_IOLuaAPI_Log_WriteRaw00);
  tolua_variable(tolua_S,"level",tolua_get_Log_level,tolua_set_Log_level);
  tolua_variable(tolua_S,"timeStamp",tolua_get_Log_timeStamp,tolua_set_Log_timeStamp);
  tolua_variable(tolua_S,"quiet",tolua_get_Log_quiet,tolua_set_Log_quiet);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"GetLog",tolua_IOLuaAPI_GetLog00);
 tolua_variable(tolua_S,"log",tolua_get_log_ptr,NULL);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"NamedPipe","NamedPipe","Object",tolua_collect_NamedPipe);
 #else
 tolua_cclass(tolua_S,"NamedPipe","NamedPipe","Object",NULL);
 #endif
 tolua_beginmodule(tolua_S,"NamedPipe");
  tolua_function(tolua_S,"new",tolua_IOLuaAPI_NamedPipe_new00);
  tolua_function(tolua_S,"new_local",tolua_IOLuaAPI_NamedPipe_new00_local);
  tolua_function(tolua_S,".call",tolua_IOLuaAPI_NamedPipe_new00_local);
  tolua_function(tolua_S,"new",tolua_IOLuaAPI_NamedPipe_new01);
  tolua_function(tolua_S,"new_local",tolua_IOLuaAPI_NamedPipe_new01_local);
  tolua_function(tolua_S,".call",tolua_IOLuaAPI_NamedPipe_new01_local);
  tolua_function(tolua_S,"delete",tolua_IOLuaAPI_NamedPipe_delete00);
  tolua_function(tolua_S,"Open",tolua_IOLuaAPI_NamedPipe_Open00);
  tolua_function(tolua_S,"Close",tolua_IOLuaAPI_NamedPipe_Close00);
  tolua_function(tolua_S,"IsOpen",tolua_IOLuaAPI_NamedPipe_IsOpen00);
  tolua_function(tolua_S,"Read",tolua_IOLuaAPI_NamedPipe_Read00);
  tolua_function(tolua_S,"GetName",tolua_IOLuaAPI_NamedPipe_GetName00);
  tolua_function(tolua_S,"IsEof",tolua_IOLuaAPI_NamedPipe_IsEof00);
  tolua_function(tolua_S,"ReadInt",tolua_IOLuaAPI_NamedPipe_ReadInt00);
  tolua_function(tolua_S,"ReadShort",tolua_IOLuaAPI_NamedPipe_ReadShort00);
  tolua_function(tolua_S,"ReadByte",tolua_IOLuaAPI_NamedPipe_ReadByte00);
  tolua_function(tolua_S,"ReadUInt",tolua_IOLuaAPI_NamedPipe_ReadUInt00);
  tolua_function(tolua_S,"ReadUShort",tolua_IOLuaAPI_NamedPipe_ReadUShort00);
  tolua_function(tolua_S,"ReadUByte",tolua_IOLuaAPI_NamedPipe_ReadUByte00);
  tolua_function(tolua_S,"ReadBool",tolua_IOLuaAPI_NamedPipe_ReadBool00);
  tolua_function(tolua_S,"ReadFloat",tolua_IOLuaAPI_NamedPipe_ReadFloat00);
  tolua_function(tolua_S,"ReadDouble",tolua_IOLuaAPI_NamedPipe_ReadDouble00);
  tolua_function(tolua_S,"ReadIntRect",tolua_IOLuaAPI_NamedPipe_ReadIntRect00);
  tolua_function(tolua_S,"ReadIntVector2",tolua_IOLuaAPI_NamedPipe_ReadIntVector200);
  tolua_function(tolua_S,"ReadIntVector3",tolua_IOLuaAPI_NamedPipe_ReadIntVector300);
  tolua_function(tolua_S,"ReadRect",tolua_IOLuaAPI_NamedPipe_ReadRect00);
  tolua_function(tolua_S,"ReadVector2",tolua_IOLuaAPI_NamedPipe_ReadVector200);
  tolua_function(tolua_S,"ReadVector3",tolua_IOLuaAPI_NamedPipe_ReadVector300);
  tolua_function(tolua_S,"ReadPackedVector3",tolua_IOLuaAPI_NamedPipe_ReadPackedVector300);
  tolua_function(tolua_S,"ReadVector4",tolua_IOLuaAPI_NamedPipe_ReadVector400);
  tolua_function(tolua_S,"ReadQuaternion",tolua_IOLuaAPI_NamedPipe_ReadQuaternion00);
  tolua_function(tolua_S,"ReadPackedQuaternion",tolua_IOLuaAPI_NamedPipe_ReadPackedQuaternion00);
  tolua_function(tolua_S,"ReadMatrix3",tolua_IOLuaAPI_NamedPipe_ReadMatrix300);
  tolua_function(tolua_S,"ReadMatrix3x4",tolua_IOLuaAPI_NamedPipe_ReadMatrix3x400);
  tolua_function(tolua_S,"ReadMatrix4",tolua_IOLuaAPI_NamedPipe_ReadMatrix400);
  tolua_function(tolua_S,"ReadColor",tolua_IOLuaAPI_NamedPipe_ReadColor00);
  tolua_function(tolua_S,"ReadBoundingBox",tolua_IOLuaAPI_NamedPipe_ReadBoundingBox00);
  tolua_function(tolua_S,"ReadString",tolua_IOLuaAPI_NamedPipe_ReadString00);
  tolua_function(tolua_S,"ReadFileID",tolua_IOLuaAPI_NamedPipe_ReadFileID00);
  tolua_function(tolua_S,"ReadStringHash",tolua_IOLuaAPI_NamedPipe_ReadStringHash00);
  tolua_function(tolua_S,"ReadBuffer",tolua_IOLuaAPI_NamedPipe_ReadBuffer00);
  tolua_function(tolua_S,"ReadResourceRef",tolua_IOLuaAPI_NamedPipe_ReadResourceRef00);
  tolua_function(tolua_S,"ReadResourceRefList",tolua_IOLuaAPI_NamedPipe_ReadResourceRefList00);
  tolua_function(tolua_S,"ReadVariant",tolua_IOLuaAPI_NamedPipe_ReadVariant00);
  tolua_function(tolua_S,"ReadVariant",tolua_IOLuaAPI_NamedPipe_ReadVariant01);
  tolua_function(tolua_S,"ReadVariantVector",tolua_IOLuaAPI_NamedPipe_ReadVariantVector00);
  tolua_function(tolua_S,"ReadVariantMap",tolua_IOLuaAPI_NamedPipe_ReadVariantMap00);
  tolua_function(tolua_S,"ReadVLE",tolua_IOLuaAPI_NamedPipe_ReadVLE00);
  tolua_function(tolua_S,"ReadNetID",tolua_IOLuaAPI_NamedPipe_ReadNetID00);
  tolua_function(tolua_S,"ReadLine",tolua_IOLuaAPI_NamedPipe_ReadLine00);
  tolua_function(tolua_S,"Write",tolua_IOLuaAPI_NamedPipe_Write00);
  tolua_function(tolua_S,"WriteInt",tolua_IOLuaAPI_NamedPipe_WriteInt00);
  tolua_function(tolua_S,"WriteShort",tolua_IOLuaAPI_NamedPipe_WriteShort00);
  tolua_function(tolua_S,"WriteByte",tolua_IOLuaAPI_NamedPipe_WriteByte00);
  tolua_function(tolua_S,"WriteUInt",tolua_IOLuaAPI_NamedPipe_WriteUInt00);
  tolua_function(tolua_S,"WriteUShort",tolua_IOLuaAPI_NamedPipe_WriteUShort00);
  tolua_function(tolua_S,"WriteUByte",tolua_IOLuaAPI_NamedPipe_WriteUByte00);
  tolua_function(tolua_S,"WriteBool",tolua_IOLuaAPI_NamedPipe_WriteBool00);
  tolua_function(tolua_S,"WriteFloat",tolua_IOLuaAPI_NamedPipe_WriteFloat00);
  tolua_function(tolua_S,"WriteDouble",tolua_IOLuaAPI_NamedPipe_WriteDouble00);
  tolua_function(tolua_S,"WriteIntRect",tolua_IOLuaAPI_NamedPipe_WriteIntRect00);
  tolua_function(tolua_S,"WriteIntVector2",tolua_IOLuaAPI_NamedPipe_WriteIntVector200);
  tolua_function(tolua_S,"WriteIntVector3",tolua_IOLuaAPI_NamedPipe_WriteIntVector300);
  tolua_function(tolua_S,"WriteRect",tolua_IOLuaAPI_NamedPipe_WriteRect00);
  tolua_function(tolua_S,"WriteVector2",tolua_IOLuaAPI_NamedPipe_WriteVector200);
  tolua_function(tolua_S,"WriteVector3",tolua_IOLuaAPI_NamedPipe_WriteVector300);
  tolua_function(tolua_S,"WritePackedVector3",tolua_IOLuaAPI_NamedPipe_WritePackedVector300);
  tolua_function(tolua_S,"WriteVector4",tolua_IOLuaAPI_NamedPipe_WriteVector400);
  tolua_function(tolua_S,"WriteQuaternion",tolua_IOLuaAPI_NamedPipe_WriteQuaternion00);
  tolua_function(tolua_S,"WritePackedQuaternion",tolua_IOLuaAPI_NamedPipe_WritePackedQuaternion00);
  tolua_function(tolua_S,"WriteMatrix3",tolua_IOLuaAPI_NamedPipe_WriteMatrix300);
  tolua_function(tolua_S,"WriteMatrix3x4",tolua_IOLuaAPI_NamedPipe_WriteMatrix3x400);
  tolua_function(tolua_S,"WriteMatrix4",tolua_IOLuaAPI_NamedPipe_WriteMatrix400);
  tolua_function(tolua_S,"WriteColor",tolua_IOLuaAPI_NamedPipe_WriteColor00);
  tolua_function(tolua_S,"WriteBoundingBox",tolua_IOLuaAPI_NamedPipe_WriteBoundingBox00);
  tolua_function(tolua_S,"WriteString",tolua_IOLuaAPI_NamedPipe_WriteString00);
  tolua_function(tolua_S,"WriteFileID",tolua_IOLuaAPI_NamedPipe_WriteFileID00);
  tolua_function(tolua_S,"WriteStringHash",tolua_IOLuaAPI_NamedPipe_WriteStringHash00);
  tolua_function(tolua_S,"WriteBuffer",tolua_IOLuaAPI_NamedPipe_WriteBuffer00);
  tolua_function(tolua_S,"WriteResourceRef",tolua_IOLuaAPI_NamedPipe_WriteResourceRef00);
  tolua_function(tolua_S,"WriteResourceRefList",tolua_IOLuaAPI_NamedPipe_WriteResourceRefList00);
  tolua_function(tolua_S,"WriteVariant",tolua_IOLuaAPI_NamedPipe_WriteVariant00);
  tolua_function(tolua_S,"WriteVariantData",tolua_IOLuaAPI_NamedPipe_WriteVariantData00);
  tolua_function(tolua_S,"WriteVariantVector",tolua_IOLuaAPI_NamedPipe_WriteVariantVector00);
  tolua_function(tolua_S,"WriteVariantMap",tolua_IOLuaAPI_NamedPipe_WriteVariantMap00);
  tolua_function(tolua_S,"WriteVLE",tolua_IOLuaAPI_NamedPipe_WriteVLE00);
  tolua_function(tolua_S,"WriteNetID",tolua_IOLuaAPI_NamedPipe_WriteNetID00);
  tolua_function(tolua_S,"WriteLine",tolua_IOLuaAPI_NamedPipe_WriteLine00);
  tolua_variable(tolua_S,"name",tolua_get_NamedPipe_name,NULL);
  tolua_variable(tolua_S,"eof",tolua_get_NamedPipe_eof,NULL);
  tolua_variable(tolua_S,"open",tolua_get_NamedPipe_open,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"PackageEntry","PackageEntry","",NULL);
 tolua_beginmodule(tolua_S,"PackageEntry");
  tolua_variable(tolua_S,"offset",tolua_get_PackageEntry_offset,tolua_set_PackageEntry_offset);
  tolua_variable(tolua_S,"size",tolua_get_PackageEntry_size,tolua_set_PackageEntry_size);
  tolua_variable(tolua_S,"checksum",tolua_get_PackageEntry_checksum,tolua_set_PackageEntry_checksum);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"PackageFile","PackageFile","Object",tolua_collect_PackageFile);
 #else
 tolua_cclass(tolua_S,"PackageFile","PackageFile","Object",NULL);
 #endif
 tolua_beginmodule(tolua_S,"PackageFile");
  tolua_function(tolua_S,"new",tolua_IOLuaAPI_PackageFile_new00);
  tolua_function(tolua_S,"new_local",tolua_IOLuaAPI_PackageFile_new00_local);
  tolua_function(tolua_S,".call",tolua_IOLuaAPI_PackageFile_new00_local);
  tolua_function(tolua_S,"new",tolua_IOLuaAPI_PackageFile_new01);
  tolua_function(tolua_S,"new_local",tolua_IOLuaAPI_PackageFile_new01_local);
  tolua_function(tolua_S,".call",tolua_IOLuaAPI_PackageFile_new01_local);
  tolua_function(tolua_S,"delete",tolua_IOLuaAPI_PackageFile_delete00);
  tolua_function(tolua_S,"Open",tolua_IOLuaAPI_PackageFile_Open00);
  tolua_function(tolua_S,"Exists",tolua_IOLuaAPI_PackageFile_Exists00);
  tolua_function(tolua_S,"GetEntry",tolua_IOLuaAPI_PackageFile_GetEntry00);
  tolua_function(tolua_S,"GetEntries",tolua_IOLuaAPI_PackageFile_GetEntries00);
  tolua_function(tolua_S,"GetName",tolua_IOLuaAPI_PackageFile_GetName00);
  tolua_function(tolua_S,"GetNameHash",tolua_IOLuaAPI_PackageFile_GetNameHash00);
  tolua_function(tolua_S,"GetNumFiles",tolua_IOLuaAPI_PackageFile_GetNumFiles00);
  tolua_function(tolua_S,"GetTotalSize",tolua_IOLuaAPI_PackageFile_GetTotalSize00);
  tolua_function(tolua_S,"GetTotalDataSize",tolua_IOLuaAPI_PackageFile_GetTotalDataSize00);
  tolua_function(tolua_S,"GetChecksum",tolua_IOLuaAPI_PackageFile_GetChecksum00);
  tolua_function(tolua_S,"IsCompressed",tolua_IOLuaAPI_PackageFile_IsCompressed00);
  tolua_variable(tolua_S,"name",tolua_get_PackageFile_name,NULL);
  tolua_variable(tolua_S,"nameHash",tolua_get_PackageFile_nameHash,NULL);
  tolua_variable(tolua_S,"numFiles",tolua_get_PackageFile_numFiles,NULL);
  tolua_variable(tolua_S,"totalSize",tolua_get_PackageFile_totalSize,NULL);
  tolua_variable(tolua_S,"totalDataSize",tolua_get_PackageFile_totalDataSize,NULL);
  tolua_variable(tolua_S,"checksum",tolua_get_PackageFile_checksum,NULL);
  tolua_variable(tolua_S,"compressed",tolua_get_PackageFile_compressed,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Serializer","Serializer","",NULL);
 tolua_beginmodule(tolua_S,"Serializer");
  tolua_function(tolua_S,"Write",tolua_IOLuaAPI_Serializer_Write00);
  tolua_function(tolua_S,"WriteInt",tolua_IOLuaAPI_Serializer_WriteInt00);
  tolua_function(tolua_S,"WriteInt64",tolua_IOLuaAPI_Serializer_WriteInt6400);
  tolua_function(tolua_S,"WriteShort",tolua_IOLuaAPI_Serializer_WriteShort00);
  tolua_function(tolua_S,"WriteByte",tolua_IOLuaAPI_Serializer_WriteByte00);
  tolua_function(tolua_S,"WriteUInt",tolua_IOLuaAPI_Serializer_WriteUInt00);
  tolua_function(tolua_S,"WriteUInt64",tolua_IOLuaAPI_Serializer_WriteUInt6400);
  tolua_function(tolua_S,"WriteUShort",tolua_IOLuaAPI_Serializer_WriteUShort00);
  tolua_function(tolua_S,"WriteUByte",tolua_IOLuaAPI_Serializer_WriteUByte00);
  tolua_function(tolua_S,"WriteBool",tolua_IOLuaAPI_Serializer_WriteBool00);
  tolua_function(tolua_S,"WriteFloat",tolua_IOLuaAPI_Serializer_WriteFloat00);
  tolua_function(tolua_S,"WriteDouble",tolua_IOLuaAPI_Serializer_WriteDouble00);
  tolua_function(tolua_S,"WriteIntRect",tolua_IOLuaAPI_Serializer_WriteIntRect00);
  tolua_function(tolua_S,"WriteIntVector2",tolua_IOLuaAPI_Serializer_WriteIntVector200);
  tolua_function(tolua_S,"WriteIntVector3",tolua_IOLuaAPI_Serializer_WriteIntVector300);
  tolua_function(tolua_S,"WriteRect",tolua_IOLuaAPI_Serializer_WriteRect00);
  tolua_function(tolua_S,"WriteVector2",tolua_IOLuaAPI_Serializer_WriteVector200);
  tolua_function(tolua_S,"WriteVector3",tolua_IOLuaAPI_Serializer_WriteVector300);
  tolua_function(tolua_S,"WritePackedVector3",tolua_IOLuaAPI_Serializer_WritePackedVector300);
  tolua_function(tolua_S,"WriteVector4",tolua_IOLuaAPI_Serializer_WriteVector400);
  tolua_function(tolua_S,"WriteQuaternion",tolua_IOLuaAPI_Serializer_WriteQuaternion00);
  tolua_function(tolua_S,"WritePackedQuaternion",tolua_IOLuaAPI_Serializer_WritePackedQuaternion00);
  tolua_function(tolua_S,"WriteMatrix3",tolua_IOLuaAPI_Serializer_WriteMatrix300);
  tolua_function(tolua_S,"WriteMatrix3x4",tolua_IOLuaAPI_Serializer_WriteMatrix3x400);
  tolua_function(tolua_S,"WriteMatrix4",tolua_IOLuaAPI_Serializer_WriteMatrix400);
  tolua_function(tolua_S,"WriteColor",tolua_IOLuaAPI_Serializer_WriteColor00);
  tolua_function(tolua_S,"WriteBoundingBox",tolua_IOLuaAPI_Serializer_WriteBoundingBox00);
  tolua_function(tolua_S,"WriteString",tolua_IOLuaAPI_Serializer_WriteString00);
  tolua_function(tolua_S,"WriteFileID",tolua_IOLuaAPI_Serializer_WriteFileID00);
  tolua_function(tolua_S,"WriteStringHash",tolua_IOLuaAPI_Serializer_WriteStringHash00);
  tolua_function(tolua_S,"WriteBuffer",tolua_IOLuaAPI_Serializer_WriteBuffer00);
  tolua_function(tolua_S,"WriteResourceRef",tolua_IOLuaAPI_Serializer_WriteResourceRef00);
  tolua_function(tolua_S,"WriteResourceRefList",tolua_IOLuaAPI_Serializer_WriteResourceRefList00);
  tolua_function(tolua_S,"WriteVariant",tolua_IOLuaAPI_Serializer_WriteVariant00);
  tolua_function(tolua_S,"WriteVariantData",tolua_IOLuaAPI_Serializer_WriteVariantData00);
  tolua_function(tolua_S,"WriteVariantVector",tolua_IOLuaAPI_Serializer_WriteVariantVector00);
  tolua_function(tolua_S,"WriteVariantMap",tolua_IOLuaAPI_Serializer_WriteVariantMap00);
  tolua_function(tolua_S,"WriteVLE",tolua_IOLuaAPI_Serializer_WriteVLE00);
  tolua_function(tolua_S,"WriteNetID",tolua_IOLuaAPI_Serializer_WriteNetID00);
  tolua_function(tolua_S,"WriteLine",tolua_IOLuaAPI_Serializer_WriteLine00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"VectorBuffer","VectorBuffer","",tolua_collect_VectorBuffer);
 #else
 tolua_cclass(tolua_S,"VectorBuffer","VectorBuffer","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"VectorBuffer");
  tolua_function(tolua_S,"new",tolua_IOLuaAPI_VectorBuffer_new00);
  tolua_function(tolua_S,"new_local",tolua_IOLuaAPI_VectorBuffer_new00_local);
  tolua_function(tolua_S,".call",tolua_IOLuaAPI_VectorBuffer_new00_local);
  tolua_function(tolua_S,"new",tolua_IOLuaAPI_VectorBuffer_new01);
  tolua_function(tolua_S,"new_local",tolua_IOLuaAPI_VectorBuffer_new01_local);
  tolua_function(tolua_S,".call",tolua_IOLuaAPI_VectorBuffer_new01_local);
  tolua_function(tolua_S,"delete",tolua_IOLuaAPI_VectorBuffer_delete00);
  tolua_function(tolua_S,"SetData",tolua_IOLuaAPI_VectorBuffer_SetData00);
  tolua_function(tolua_S,"Clear",tolua_IOLuaAPI_VectorBuffer_Clear00);
  tolua_function(tolua_S,"Resize",tolua_IOLuaAPI_VectorBuffer_Resize00);
  tolua_function(tolua_S,"GetData",tolua_IOLuaAPI_VectorBuffer_GetData00);
  tolua_function(tolua_S,"GetModifiableData",tolua_IOLuaAPI_VectorBuffer_GetModifiableData00);
  tolua_function(tolua_S,"Read",tolua_IOLuaAPI_VectorBuffer_Read00);
  tolua_function(tolua_S,"Seek",tolua_IOLuaAPI_VectorBuffer_Seek00);
  tolua_function(tolua_S,"SeekRelative",tolua_IOLuaAPI_VectorBuffer_SeekRelative00);
  tolua_function(tolua_S,"GetName",tolua_IOLuaAPI_VectorBuffer_GetName00);
  tolua_function(tolua_S,"GetChecksum",tolua_IOLuaAPI_VectorBuffer_GetChecksum00);
  tolua_function(tolua_S,"GetPosition",tolua_IOLuaAPI_VectorBuffer_GetPosition00);
  tolua_function(tolua_S,"Tell",tolua_IOLuaAPI_VectorBuffer_Tell00);
  tolua_function(tolua_S,"GetSize",tolua_IOLuaAPI_VectorBuffer_GetSize00);
  tolua_function(tolua_S,"IsEof",tolua_IOLuaAPI_VectorBuffer_IsEof00);
  tolua_function(tolua_S,"ReadInt",tolua_IOLuaAPI_VectorBuffer_ReadInt00);
  tolua_function(tolua_S,"ReadInt64",tolua_IOLuaAPI_VectorBuffer_ReadInt6400);
  tolua_function(tolua_S,"ReadShort",tolua_IOLuaAPI_VectorBuffer_ReadShort00);
  tolua_function(tolua_S,"ReadByte",tolua_IOLuaAPI_VectorBuffer_ReadByte00);
  tolua_function(tolua_S,"ReadUInt",tolua_IOLuaAPI_VectorBuffer_ReadUInt00);
  tolua_function(tolua_S,"ReadUInt64",tolua_IOLuaAPI_VectorBuffer_ReadUInt6400);
  tolua_function(tolua_S,"ReadUShort",tolua_IOLuaAPI_VectorBuffer_ReadUShort00);
  tolua_function(tolua_S,"ReadUByte",tolua_IOLuaAPI_VectorBuffer_ReadUByte00);
  tolua_function(tolua_S,"ReadBool",tolua_IOLuaAPI_VectorBuffer_ReadBool00);
  tolua_function(tolua_S,"ReadFloat",tolua_IOLuaAPI_VectorBuffer_ReadFloat00);
  tolua_function(tolua_S,"ReadDouble",tolua_IOLuaAPI_VectorBuffer_ReadDouble00);
  tolua_function(tolua_S,"ReadIntRect",tolua_IOLuaAPI_VectorBuffer_ReadIntRect00);
  tolua_function(tolua_S,"ReadIntVector2",tolua_IOLuaAPI_VectorBuffer_ReadIntVector200);
  tolua_function(tolua_S,"ReadIntVector3",tolua_IOLuaAPI_VectorBuffer_ReadIntVector300);
  tolua_function(tolua_S,"ReadRect",tolua_IOLuaAPI_VectorBuffer_ReadRect00);
  tolua_function(tolua_S,"ReadVector2",tolua_IOLuaAPI_VectorBuffer_ReadVector200);
  tolua_function(tolua_S,"ReadVector3",tolua_IOLuaAPI_VectorBuffer_ReadVector300);
  tolua_function(tolua_S,"ReadPackedVector3",tolua_IOLuaAPI_VectorBuffer_ReadPackedVector300);
  tolua_function(tolua_S,"ReadVector4",tolua_IOLuaAPI_VectorBuffer_ReadVector400);
  tolua_function(tolua_S,"ReadQuaternion",tolua_IOLuaAPI_VectorBuffer_ReadQuaternion00);
  tolua_function(tolua_S,"ReadPackedQuaternion",tolua_IOLuaAPI_VectorBuffer_ReadPackedQuaternion00);
  tolua_function(tolua_S,"ReadMatrix3",tolua_IOLuaAPI_VectorBuffer_ReadMatrix300);
  tolua_function(tolua_S,"ReadMatrix3x4",tolua_IOLuaAPI_VectorBuffer_ReadMatrix3x400);
  tolua_function(tolua_S,"ReadMatrix4",tolua_IOLuaAPI_VectorBuffer_ReadMatrix400);
  tolua_function(tolua_S,"ReadColor",tolua_IOLuaAPI_VectorBuffer_ReadColor00);
  tolua_function(tolua_S,"ReadBoundingBox",tolua_IOLuaAPI_VectorBuffer_ReadBoundingBox00);
  tolua_function(tolua_S,"ReadString",tolua_IOLuaAPI_VectorBuffer_ReadString00);
  tolua_function(tolua_S,"ReadFileID",tolua_IOLuaAPI_VectorBuffer_ReadFileID00);
  tolua_function(tolua_S,"ReadStringHash",tolua_IOLuaAPI_VectorBuffer_ReadStringHash00);
  tolua_function(tolua_S,"ReadBuffer",tolua_IOLuaAPI_VectorBuffer_ReadBuffer00);
  tolua_function(tolua_S,"ReadResourceRef",tolua_IOLuaAPI_VectorBuffer_ReadResourceRef00);
  tolua_function(tolua_S,"ReadResourceRefList",tolua_IOLuaAPI_VectorBuffer_ReadResourceRefList00);
  tolua_function(tolua_S,"ReadVariant",tolua_IOLuaAPI_VectorBuffer_ReadVariant00);
  tolua_function(tolua_S,"ReadVariant",tolua_IOLuaAPI_VectorBuffer_ReadVariant01);
  tolua_function(tolua_S,"ReadVariantVector",tolua_IOLuaAPI_VectorBuffer_ReadVariantVector00);
  tolua_function(tolua_S,"ReadVariantMap",tolua_IOLuaAPI_VectorBuffer_ReadVariantMap00);
  tolua_function(tolua_S,"ReadVLE",tolua_IOLuaAPI_VectorBuffer_ReadVLE00);
  tolua_function(tolua_S,"ReadNetID",tolua_IOLuaAPI_VectorBuffer_ReadNetID00);
  tolua_function(tolua_S,"ReadLine",tolua_IOLuaAPI_VectorBuffer_ReadLine00);
  tolua_function(tolua_S,"Write",tolua_IOLuaAPI_VectorBuffer_Write00);
  tolua_function(tolua_S,"WriteInt",tolua_IOLuaAPI_VectorBuffer_WriteInt00);
  tolua_function(tolua_S,"WriteInt64",tolua_IOLuaAPI_VectorBuffer_WriteInt6400);
  tolua_function(tolua_S,"WriteShort",tolua_IOLuaAPI_VectorBuffer_WriteShort00);
  tolua_function(tolua_S,"WriteByte",tolua_IOLuaAPI_VectorBuffer_WriteByte00);
  tolua_function(tolua_S,"WriteUInt",tolua_IOLuaAPI_VectorBuffer_WriteUInt00);
  tolua_function(tolua_S,"WriteUInt64",tolua_IOLuaAPI_VectorBuffer_WriteUInt6400);
  tolua_function(tolua_S,"WriteUShort",tolua_IOLuaAPI_VectorBuffer_WriteUShort00);
  tolua_function(tolua_S,"WriteUByte",tolua_IOLuaAPI_VectorBuffer_WriteUByte00);
  tolua_function(tolua_S,"WriteBool",tolua_IOLuaAPI_VectorBuffer_WriteBool00);
  tolua_function(tolua_S,"WriteFloat",tolua_IOLuaAPI_VectorBuffer_WriteFloat00);
  tolua_function(tolua_S,"WriteDouble",tolua_IOLuaAPI_VectorBuffer_WriteDouble00);
  tolua_function(tolua_S,"WriteIntRect",tolua_IOLuaAPI_VectorBuffer_WriteIntRect00);
  tolua_function(tolua_S,"WriteIntVector2",tolua_IOLuaAPI_VectorBuffer_WriteIntVector200);
  tolua_function(tolua_S,"WriteIntVector3",tolua_IOLuaAPI_VectorBuffer_WriteIntVector300);
  tolua_function(tolua_S,"WriteRect",tolua_IOLuaAPI_VectorBuffer_WriteRect00);
  tolua_function(tolua_S,"WriteVector2",tolua_IOLuaAPI_VectorBuffer_WriteVector200);
  tolua_function(tolua_S,"WriteVector3",tolua_IOLuaAPI_VectorBuffer_WriteVector300);
  tolua_function(tolua_S,"WritePackedVector3",tolua_IOLuaAPI_VectorBuffer_WritePackedVector300);
  tolua_function(tolua_S,"WriteVector4",tolua_IOLuaAPI_VectorBuffer_WriteVector400);
  tolua_function(tolua_S,"WriteQuaternion",tolua_IOLuaAPI_VectorBuffer_WriteQuaternion00);
  tolua_function(tolua_S,"WritePackedQuaternion",tolua_IOLuaAPI_VectorBuffer_WritePackedQuaternion00);
  tolua_function(tolua_S,"WriteMatrix3",tolua_IOLuaAPI_VectorBuffer_WriteMatrix300);
  tolua_function(tolua_S,"WriteMatrix3x4",tolua_IOLuaAPI_VectorBuffer_WriteMatrix3x400);
  tolua_function(tolua_S,"WriteMatrix4",tolua_IOLuaAPI_VectorBuffer_WriteMatrix400);
  tolua_function(tolua_S,"WriteColor",tolua_IOLuaAPI_VectorBuffer_WriteColor00);
  tolua_function(tolua_S,"WriteBoundingBox",tolua_IOLuaAPI_VectorBuffer_WriteBoundingBox00);
  tolua_function(tolua_S,"WriteString",tolua_IOLuaAPI_VectorBuffer_WriteString00);
  tolua_function(tolua_S,"WriteFileID",tolua_IOLuaAPI_VectorBuffer_WriteFileID00);
  tolua_function(tolua_S,"WriteStringHash",tolua_IOLuaAPI_VectorBuffer_WriteStringHash00);
  tolua_function(tolua_S,"WriteBuffer",tolua_IOLuaAPI_VectorBuffer_WriteBuffer00);
  tolua_function(tolua_S,"WriteResourceRef",tolua_IOLuaAPI_VectorBuffer_WriteResourceRef00);
  tolua_function(tolua_S,"WriteResourceRefList",tolua_IOLuaAPI_VectorBuffer_WriteResourceRefList00);
  tolua_function(tolua_S,"WriteVariant",tolua_IOLuaAPI_VectorBuffer_WriteVariant00);
  tolua_function(tolua_S,"WriteVariantData",tolua_IOLuaAPI_VectorBuffer_WriteVariantData00);
  tolua_function(tolua_S,"WriteVariantVector",tolua_IOLuaAPI_VectorBuffer_WriteVariantVector00);
  tolua_function(tolua_S,"WriteVariantMap",tolua_IOLuaAPI_VectorBuffer_WriteVariantMap00);
  tolua_function(tolua_S,"WriteVLE",tolua_IOLuaAPI_VectorBuffer_WriteVLE00);
  tolua_function(tolua_S,"WriteNetID",tolua_IOLuaAPI_VectorBuffer_WriteNetID00);
  tolua_function(tolua_S,"WriteLine",tolua_IOLuaAPI_VectorBuffer_WriteLine00);
  tolua_variable(tolua_S,"name",tolua_get_VectorBuffer_name,NULL);
  tolua_variable(tolua_S,"checksum",tolua_get_VectorBuffer_checksum,NULL);
  tolua_variable(tolua_S,"position",tolua_get_VectorBuffer_position,NULL);
  tolua_variable(tolua_S,"size",tolua_get_VectorBuffer_size,NULL);
  tolua_variable(tolua_S,"eof",tolua_get_VectorBuffer_eof,NULL);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_IOLuaAPI (lua_State* tolua_S) {
 return tolua_IOLuaAPI_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif