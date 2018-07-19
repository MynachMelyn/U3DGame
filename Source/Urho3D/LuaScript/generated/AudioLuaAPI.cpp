/*
** Lua binding: AudioLuaAPI
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
TOLUA_API int tolua_AudioLuaAPI_open (lua_State* tolua_S);

#include "Audio/Audio.h"
#include "IO/File.h"
#include "Audio/Sound.h"
#include "Audio/SoundListener.h"
#include "Audio/SoundSource.h"
#include "Audio/SoundSource3D.h"
#define GetRolloffFactor RollAngleoffFactor
using namespace Urho3D;
#pragma warning(disable:4800)

#define TOLUA_DISABLE_tolua_AudioLuaAPI_GetAudio00
static int tolua_AudioLuaAPI_GetAudio00(lua_State* tolua_S)
{
    return ToluaGetSubsystem<Audio>(tolua_S);
}

#define TOLUA_DISABLE_tolua_get_audio_ptr
#define tolua_get_audio_ptr tolua_AudioLuaAPI_GetAudio00

#define TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_new00
static int tolua_AudioLuaAPI_Sound_new00(lua_State* tolua_S)
{
    return ToluaNewObject<Sound>(tolua_S);
}

#define TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_new00_local
static int tolua_AudioLuaAPI_Sound_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<Sound>(tolua_S);
}

static bool SoundLoadRaw(Sound* sound, const String& fileName)
{
    if (!sound)
        return false;

    File file(sound->GetContext());
    if (!file.Open(fileName, FILE_READ))
        return false;

    return sound->LoadRaw(file);
}

static bool SoundLoadWav(Sound* sound, const String& fileName)
{
    if (!sound)
        return false;

    File file(sound->GetContext());
    if (!file.Open(fileName, FILE_READ))
        return false;

    return sound->LoadWav(file);
}

static bool SoundLoadOggVorbis(Sound* sound, const String& fileName)
{
    if (!sound)
        return false;

    File file(sound->GetContext());
    if (!file.Open(fileName, FILE_READ))
        return false;

    return sound->LoadOggVorbis(file);
}

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Sound (lua_State* tolua_S)
{
 Sound* self = (Sound*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Audio");
 tolua_usertype(tolua_S,"PODVector<SoundSource*>");
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"SoundSource3D");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"SoundSource");
 tolua_usertype(tolua_S,"Deserializer");
 tolua_usertype(tolua_S,"SoundListener");
 tolua_usertype(tolua_S,"Sound");
 tolua_usertype(tolua_S,"ResourceWithMetadata");
}

/* get function: SOUND_MASTER */
#ifndef TOLUA_DISABLE_tolua_get_SOUND_MASTER
static int tolua_get_SOUND_MASTER(lua_State* tolua_S)
{
 tolua_pushurho3dstring(tolua_S,(const char*)SOUND_MASTER);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SOUND_EFFECT */
#ifndef TOLUA_DISABLE_tolua_get_SOUND_EFFECT
static int tolua_get_SOUND_EFFECT(lua_State* tolua_S)
{
 tolua_pushurho3dstring(tolua_S,(const char*)SOUND_EFFECT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SOUND_AMBIENT */
#ifndef TOLUA_DISABLE_tolua_get_SOUND_AMBIENT
static int tolua_get_SOUND_AMBIENT(lua_State* tolua_S)
{
 tolua_pushurho3dstring(tolua_S,(const char*)SOUND_AMBIENT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SOUND_VOICE */
#ifndef TOLUA_DISABLE_tolua_get_SOUND_VOICE
static int tolua_get_SOUND_VOICE(lua_State* tolua_S)
{
 tolua_pushurho3dstring(tolua_S,(const char*)SOUND_VOICE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SOUND_MUSIC */
#ifndef TOLUA_DISABLE_tolua_get_SOUND_MUSIC
static int tolua_get_SOUND_MUSIC(lua_State* tolua_S)
{
 tolua_pushurho3dstring(tolua_S,(const char*)SOUND_MUSIC);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMode of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_SetMode00
static int tolua_AudioLuaAPI_Audio_SetMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Audio",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
  int bufferLengthMSec = ((int)  tolua_tonumber(tolua_S,2,0));
  int mixRate = ((int)  tolua_tonumber(tolua_S,3,0));
  bool stereo = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool interpolation = ((bool)  tolua_toboolean(tolua_S,5,true));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMode'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetMode(bufferLengthMSec,mixRate,stereo,interpolation);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Play of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_Play00
static int tolua_AudioLuaAPI_Audio_Play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Audio",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Play'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Play();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Stop of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_Stop00
static int tolua_AudioLuaAPI_Audio_Stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Audio",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Stop'", NULL);
#endif
 {
  self->Stop();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMasterGain of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_SetMasterGain00
static int tolua_AudioLuaAPI_Audio_SetMasterGain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Audio",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  float gain = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMasterGain'", NULL);
#endif
 {
  self->SetMasterGain(type,gain);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMasterGain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PauseSoundType of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_PauseSoundType00
static int tolua_AudioLuaAPI_Audio_PauseSoundType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Audio",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PauseSoundType'", NULL);
#endif
 {
  self->PauseSoundType(type);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PauseSoundType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResumeSoundType of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_ResumeSoundType00
static int tolua_AudioLuaAPI_Audio_ResumeSoundType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Audio",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResumeSoundType'", NULL);
#endif
 {
  self->ResumeSoundType(type);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResumeSoundType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResumeAll of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_ResumeAll00
static int tolua_AudioLuaAPI_Audio_ResumeAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Audio",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResumeAll'", NULL);
#endif
 {
  self->ResumeAll();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResumeAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetListener of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_SetListener00
static int tolua_AudioLuaAPI_Audio_SetListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Audio",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"SoundListener",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
  SoundListener* listener = ((SoundListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetListener'", NULL);
#endif
 {
  self->SetListener(listener);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StopSound of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_StopSound00
static int tolua_AudioLuaAPI_Audio_StopSound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Audio",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Sound",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
  Sound* sound = ((Sound*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StopSound'", NULL);
#endif
 {
  self->StopSound(sound);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StopSound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSampleSize of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_GetSampleSize00
static int tolua_AudioLuaAPI_Audio_GetSampleSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Audio",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Audio* self = (const Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSampleSize'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetSampleSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSampleSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMixRate of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_GetMixRate00
static int tolua_AudioLuaAPI_Audio_GetMixRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Audio",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Audio* self = (const Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMixRate'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetMixRate();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMixRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInterpolation of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_GetInterpolation00
static int tolua_AudioLuaAPI_Audio_GetInterpolation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Audio",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Audio* self = (const Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInterpolation'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetInterpolation();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInterpolation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsStereo of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_IsStereo00
static int tolua_AudioLuaAPI_Audio_IsStereo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Audio",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Audio* self = (const Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsStereo'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsStereo();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsStereo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsPlaying of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_IsPlaying00
static int tolua_AudioLuaAPI_Audio_IsPlaying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Audio",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Audio* self = (const Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsPlaying'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsPlaying();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsPlaying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInitialized of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_IsInitialized00
static int tolua_AudioLuaAPI_Audio_IsInitialized00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Audio",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Audio* self = (const Audio*)  tolua_tousertype(tolua_S,1,0);
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

/* method: HasMasterGain of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_HasMasterGain00
static int tolua_AudioLuaAPI_Audio_HasMasterGain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Audio",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Audio* self = (const Audio*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasMasterGain'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasMasterGain(type);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasMasterGain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMasterGain of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_GetMasterGain00
static int tolua_AudioLuaAPI_Audio_GetMasterGain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Audio",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Audio* self = (const Audio*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMasterGain'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMasterGain(type);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMasterGain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsSoundTypePaused of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_IsSoundTypePaused00
static int tolua_AudioLuaAPI_Audio_IsSoundTypePaused00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Audio",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Audio* self = (const Audio*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsSoundTypePaused'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsSoundTypePaused(type);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsSoundTypePaused'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetListener of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_GetListener00
static int tolua_AudioLuaAPI_Audio_GetListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Audio",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Audio* self = (const Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetListener'", NULL);
#endif
 {
  SoundListener* tolua_ret = (SoundListener*)  self->GetListener();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SoundListener");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSoundSources of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_GetSoundSources00
static int tolua_AudioLuaAPI_Audio_GetSoundSources00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Audio",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Audio* self = (const Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSoundSources'", NULL);
#endif
 {
  const PODVector<SoundSource*>& tolua_ret = (const PODVector<SoundSource*>&)  self->GetSoundSources();
  ToluaPushPODVector<SoundSource*>("",tolua_S,(void*)&tolua_ret,"SoundSource");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSoundSources'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddSoundSource of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_AddSoundSource00
static int tolua_AudioLuaAPI_Audio_AddSoundSource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Audio",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"SoundSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
  SoundSource* soundSource = ((SoundSource*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddSoundSource'", NULL);
#endif
 {
  self->AddSoundSource(soundSource);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddSoundSource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveSoundSource of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_RemoveSoundSource00
static int tolua_AudioLuaAPI_Audio_RemoveSoundSource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Audio",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"SoundSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
  SoundSource* soundSource = ((SoundSource*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveSoundSource'", NULL);
#endif
 {
  self->RemoveSoundSource(soundSource);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveSoundSource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MixOutput of class  Audio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Audio_MixOutput00
static int tolua_AudioLuaAPI_Audio_MixOutput00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Audio",0,&tolua_err) ||
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
  void* dest = ((void*)  tolua_touserdata(tolua_S,2,0));
  unsigned samples = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MixOutput'", NULL);
#endif
 {
  self->MixOutput(dest,samples);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MixOutput'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sampleSize of class  Audio */
#ifndef TOLUA_DISABLE_tolua_get_Audio_sampleSize
static int tolua_get_Audio_sampleSize(lua_State* tolua_S)
{
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sampleSize'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSampleSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mixRate of class  Audio */
#ifndef TOLUA_DISABLE_tolua_get_Audio_mixRate
static int tolua_get_Audio_mixRate(lua_State* tolua_S)
{
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mixRate'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMixRate());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: interpolation of class  Audio */
#ifndef TOLUA_DISABLE_tolua_get_Audio_interpolation
static int tolua_get_Audio_interpolation(lua_State* tolua_S)
{
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'interpolation'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetInterpolation());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: stereo of class  Audio */
#ifndef TOLUA_DISABLE_tolua_get_Audio_stereo
static int tolua_get_Audio_stereo(lua_State* tolua_S)
{
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'stereo'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsStereo());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: playing of class  Audio */
#ifndef TOLUA_DISABLE_tolua_get_Audio_playing
static int tolua_get_Audio_playing(lua_State* tolua_S)
{
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'playing'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsPlaying());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: initialized of class  Audio */
#ifndef TOLUA_DISABLE_tolua_get_Audio_initialized
static int tolua_get_Audio_initialized(lua_State* tolua_S)
{
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'initialized'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsInitialized());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: listener of class  Audio */
#ifndef TOLUA_DISABLE_tolua_get_Audio_listener_ptr
static int tolua_get_Audio_listener_ptr(lua_State* tolua_S)
{
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'listener'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetListener(),"SoundListener");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: listener of class  Audio */
#ifndef TOLUA_DISABLE_tolua_set_Audio_listener_ptr
static int tolua_set_Audio_listener_ptr(lua_State* tolua_S)
{
  Audio* self = (Audio*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'listener'",NULL);
 if (!tolua_isusertype(tolua_S,2,"SoundListener",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetListener(((SoundListener*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetAudio */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_GetAudio00
static int tolua_AudioLuaAPI_GetAudio00(lua_State* tolua_S)
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
  Audio* tolua_ret = (Audio*)  GetAudio();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Audio");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAudio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: audio */
#ifndef TOLUA_DISABLE_tolua_get_audio_ptr
static int tolua_get_audio_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetAudio(),"Audio");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_new00
static int tolua_AudioLuaAPI_Sound_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sound",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Sound* tolua_ret = (Sound*)  Mtolua_new((Sound)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sound");
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

/* method: new_local of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_new00_local
static int tolua_AudioLuaAPI_Sound_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sound",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Sound* tolua_ret = (Sound*)  Mtolua_new((Sound)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sound");
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

/* method: delete of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_delete00
static int tolua_AudioLuaAPI_Sound_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
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

/* method: LoadRaw of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_LoadRaw00
static int tolua_AudioLuaAPI_Sound_LoadRaw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Deserializer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  Deserializer* source = ((Deserializer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadRaw'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->LoadRaw(*source);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadRaw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadWav of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_LoadWav00
static int tolua_AudioLuaAPI_Sound_LoadWav00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Deserializer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  Deserializer* source = ((Deserializer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadWav'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->LoadWav(*source);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadWav'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadOggVorbis of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_LoadOggVorbis00
static int tolua_AudioLuaAPI_Sound_LoadOggVorbis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Deserializer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  Deserializer* source = ((Deserializer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadOggVorbis'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->LoadOggVorbis(*source);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadOggVorbis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SoundLoadRaw of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_LoadRaw01
static int tolua_AudioLuaAPI_Sound_LoadRaw01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SoundLoadRaw'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SoundLoadRaw(self,fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_AudioLuaAPI_Sound_LoadRaw00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SoundLoadWav of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_LoadWav01
static int tolua_AudioLuaAPI_Sound_LoadWav01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SoundLoadWav'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SoundLoadWav(self,fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_AudioLuaAPI_Sound_LoadWav00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SoundLoadOggVorbis of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_LoadOggVorbis01
static int tolua_AudioLuaAPI_Sound_LoadOggVorbis01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SoundLoadOggVorbis'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  SoundLoadOggVorbis(self,fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_AudioLuaAPI_Sound_LoadOggVorbis00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_SetSize00
static int tolua_AudioLuaAPI_Sound_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  unsigned dataSize = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
 {
  self->SetSize(dataSize);
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

/* method: SetData of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_SetData00
static int tolua_AudioLuaAPI_Sound_SetData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  const void* data = ((const void*)  tolua_touserdata(tolua_S,2,0));
  unsigned dataSize = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetData'", NULL);
#endif
 {
  self->SetData(data,dataSize);
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

/* method: SetFormat of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_SetFormat00
static int tolua_AudioLuaAPI_Sound_SetFormat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  unsigned frequency = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  bool sixteenBit = ((bool)  tolua_toboolean(tolua_S,3,0));
  bool stereo = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFormat'", NULL);
#endif
 {
  self->SetFormat(frequency,sixteenBit,stereo);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFormat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLooped of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_SetLooped00
static int tolua_AudioLuaAPI_Sound_SetLooped00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLooped'", NULL);
#endif
 {
  self->SetLooped(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLooped'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLoop of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_SetLoop00
static int tolua_AudioLuaAPI_Sound_SetLoop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  unsigned repeatOffset = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  unsigned endOffset = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLoop'", NULL);
#endif
 {
  self->SetLoop(repeatOffset,endOffset);
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

/* method: FixInterpolation of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_FixInterpolation00
static int tolua_AudioLuaAPI_Sound_FixInterpolation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FixInterpolation'", NULL);
#endif
 {
  self->FixInterpolation();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FixInterpolation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLength of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_GetLength00
static int tolua_AudioLuaAPI_Sound_GetLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sound",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sound* self = (const Sound*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetDataSize of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_GetDataSize00
static int tolua_AudioLuaAPI_Sound_GetDataSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sound",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sound* self = (const Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDataSize'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetDataSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDataSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSampleSize of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_GetSampleSize00
static int tolua_AudioLuaAPI_Sound_GetSampleSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sound",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sound* self = (const Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSampleSize'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetSampleSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSampleSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFrequency of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_GetFrequency00
static int tolua_AudioLuaAPI_Sound_GetFrequency00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sound",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sound* self = (const Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFrequency'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetFrequency();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFrequency'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIntFrequency of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_GetIntFrequency00
static int tolua_AudioLuaAPI_Sound_GetIntFrequency00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sound",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sound* self = (const Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIntFrequency'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetIntFrequency();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIntFrequency'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsLooped of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_IsLooped00
static int tolua_AudioLuaAPI_Sound_IsLooped00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sound",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sound* self = (const Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsLooped'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsLooped();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsLooped'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsSixteenBit of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_IsSixteenBit00
static int tolua_AudioLuaAPI_Sound_IsSixteenBit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sound",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sound* self = (const Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsSixteenBit'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsSixteenBit();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsSixteenBit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsStereo of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_IsStereo00
static int tolua_AudioLuaAPI_Sound_IsStereo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sound",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sound* self = (const Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsStereo'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsStereo();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsStereo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsCompressed of class  Sound */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_Sound_IsCompressed00
static int tolua_AudioLuaAPI_Sound_IsCompressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sound",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sound* self = (const Sound*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: length of class  Sound */
#ifndef TOLUA_DISABLE_tolua_get_Sound_length
static int tolua_get_Sound_length(lua_State* tolua_S)
{
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'length'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLength());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dataSize of class  Sound */
#ifndef TOLUA_DISABLE_tolua_get_Sound_dataSize
static int tolua_get_Sound_dataSize(lua_State* tolua_S)
{
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dataSize'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDataSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sampleSize of class  Sound */
#ifndef TOLUA_DISABLE_tolua_get_Sound_sampleSize
static int tolua_get_Sound_sampleSize(lua_State* tolua_S)
{
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sampleSize'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSampleSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: frequency of class  Sound */
#ifndef TOLUA_DISABLE_tolua_get_Sound_frequency
static int tolua_get_Sound_frequency(lua_State* tolua_S)
{
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frequency'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFrequency());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: intFrequency of class  Sound */
#ifndef TOLUA_DISABLE_tolua_get_Sound_intFrequency
static int tolua_get_Sound_intFrequency(lua_State* tolua_S)
{
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'intFrequency'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetIntFrequency());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: looped of class  Sound */
#ifndef TOLUA_DISABLE_tolua_get_Sound_looped
static int tolua_get_Sound_looped(lua_State* tolua_S)
{
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'looped'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsLooped());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: looped of class  Sound */
#ifndef TOLUA_DISABLE_tolua_set_Sound_looped
static int tolua_set_Sound_looped(lua_State* tolua_S)
{
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'looped'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLooped(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sixteenBit of class  Sound */
#ifndef TOLUA_DISABLE_tolua_get_Sound_sixteenBit
static int tolua_get_Sound_sixteenBit(lua_State* tolua_S)
{
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sixteenBit'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsSixteenBit());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: stereo of class  Sound */
#ifndef TOLUA_DISABLE_tolua_get_Sound_stereo
static int tolua_get_Sound_stereo(lua_State* tolua_S)
{
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'stereo'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsStereo());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: compressed of class  Sound */
#ifndef TOLUA_DISABLE_tolua_get_Sound_compressed
static int tolua_get_Sound_compressed(lua_State* tolua_S)
{
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'compressed'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsCompressed());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Seek of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_Seek00
static int tolua_AudioLuaAPI_SoundSource_Seek00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
  float seekTime = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Seek'", NULL);
#endif
 {
  self->Seek(seekTime);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Seek'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Play of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_Play00
static int tolua_AudioLuaAPI_SoundSource_Play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Sound",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
  Sound* sound = ((Sound*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Play'", NULL);
#endif
 {
  self->Play(sound);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Play of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_Play01
static int tolua_AudioLuaAPI_SoundSource_Play01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Sound",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
  Sound* sound = ((Sound*)  tolua_tousertype(tolua_S,2,0));
  float frequency = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Play'", NULL);
#endif
 {
  self->Play(sound,frequency);
 }
 }
 return 0;
tolua_lerror:
 return tolua_AudioLuaAPI_SoundSource_Play00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Play of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_Play02
static int tolua_AudioLuaAPI_SoundSource_Play02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Sound",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
  Sound* sound = ((Sound*)  tolua_tousertype(tolua_S,2,0));
  float frequency = ((float)  tolua_tonumber(tolua_S,3,0));
  float gain = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Play'", NULL);
#endif
 {
  self->Play(sound,frequency,gain);
 }
 }
 return 0;
tolua_lerror:
 return tolua_AudioLuaAPI_SoundSource_Play01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Play of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_Play03
static int tolua_AudioLuaAPI_SoundSource_Play03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Sound",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
  Sound* sound = ((Sound*)  tolua_tousertype(tolua_S,2,0));
  float frequency = ((float)  tolua_tonumber(tolua_S,3,0));
  float gain = ((float)  tolua_tonumber(tolua_S,4,0));
  float panning = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Play'", NULL);
#endif
 {
  self->Play(sound,frequency,gain,panning);
 }
 }
 return 0;
tolua_lerror:
 return tolua_AudioLuaAPI_SoundSource_Play02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Stop of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_Stop00
static int tolua_AudioLuaAPI_SoundSource_Stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Stop'", NULL);
#endif
 {
  self->Stop();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSoundType of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_SetSoundType00
static int tolua_AudioLuaAPI_SoundSource_SetSoundType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSoundType'", NULL);
#endif
 {
  self->SetSoundType(type);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSoundType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFrequency of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_SetFrequency00
static int tolua_AudioLuaAPI_SoundSource_SetFrequency00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
  float frequency = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFrequency'", NULL);
#endif
 {
  self->SetFrequency(frequency);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFrequency'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetGain of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_SetGain00
static int tolua_AudioLuaAPI_SoundSource_SetGain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
  float gain = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetGain'", NULL);
#endif
 {
  self->SetGain(gain);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetGain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAttenuation of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_SetAttenuation00
static int tolua_AudioLuaAPI_SoundSource_SetAttenuation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
  float attenuation = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAttenuation'", NULL);
#endif
 {
  self->SetAttenuation(attenuation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAttenuation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPanning of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_SetPanning00
static int tolua_AudioLuaAPI_SoundSource_SetPanning00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
  float panning = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPanning'", NULL);
#endif
 {
  self->SetPanning(panning);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPanning'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAutoRemoveMode of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_SetAutoRemoveMode00
static int tolua_AudioLuaAPI_SoundSource_SetAutoRemoveMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
  AutoRemoveMode mode = ((AutoRemoveMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAutoRemoveMode'", NULL);
#endif
 {
  self->SetAutoRemoveMode(mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAutoRemoveMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSound of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_GetSound00
static int tolua_AudioLuaAPI_SoundSource_GetSound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SoundSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SoundSource* self = (const SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSound'", NULL);
#endif
 {
  Sound* tolua_ret = (Sound*)  self->GetSound();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sound");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSoundType of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_GetSoundType00
static int tolua_AudioLuaAPI_SoundSource_GetSoundType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SoundSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SoundSource* self = (const SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSoundType'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetSoundType();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSoundType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTimePosition of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_GetTimePosition00
static int tolua_AudioLuaAPI_SoundSource_GetTimePosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SoundSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SoundSource* self = (const SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTimePosition'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetTimePosition();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimePosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFrequency of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_GetFrequency00
static int tolua_AudioLuaAPI_SoundSource_GetFrequency00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SoundSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SoundSource* self = (const SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFrequency'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetFrequency();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFrequency'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGain of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_GetGain00
static int tolua_AudioLuaAPI_SoundSource_GetGain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SoundSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SoundSource* self = (const SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGain'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetGain();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAttenuation of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_GetAttenuation00
static int tolua_AudioLuaAPI_SoundSource_GetAttenuation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SoundSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SoundSource* self = (const SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttenuation'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAttenuation();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttenuation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPanning of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_GetPanning00
static int tolua_AudioLuaAPI_SoundSource_GetPanning00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SoundSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SoundSource* self = (const SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPanning'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetPanning();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPanning'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAutoRemoveMode of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_GetAutoRemoveMode00
static int tolua_AudioLuaAPI_SoundSource_GetAutoRemoveMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SoundSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SoundSource* self = (const SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAutoRemoveMode'", NULL);
#endif
 {
  AutoRemoveMode tolua_ret = (AutoRemoveMode)  self->GetAutoRemoveMode();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAutoRemoveMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsPlaying of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource_IsPlaying00
static int tolua_AudioLuaAPI_SoundSource_IsPlaying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SoundSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SoundSource* self = (const SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsPlaying'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsPlaying();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsPlaying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sound of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_get_SoundSource_sound_ptr
static int tolua_get_SoundSource_sound_ptr(lua_State* tolua_S)
{
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sound'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetSound(),"Sound");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: soundType of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_get_SoundSource_soundType
static int tolua_get_SoundSource_soundType(lua_State* tolua_S)
{
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'soundType'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetSoundType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: soundType of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_set_SoundSource_soundType
static int tolua_set_SoundSource_soundType(lua_State* tolua_S)
{
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'soundType'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSoundType(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: timePosition of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_get_SoundSource_timePosition
static int tolua_get_SoundSource_timePosition(lua_State* tolua_S)
{
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timePosition'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTimePosition());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: frequency of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_get_SoundSource_frequency
static int tolua_get_SoundSource_frequency(lua_State* tolua_S)
{
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frequency'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFrequency());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: frequency of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_set_SoundSource_frequency
static int tolua_set_SoundSource_frequency(lua_State* tolua_S)
{
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frequency'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFrequency(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: gain of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_get_SoundSource_gain
static int tolua_get_SoundSource_gain(lua_State* tolua_S)
{
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gain'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetGain());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: gain of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_set_SoundSource_gain
static int tolua_set_SoundSource_gain(lua_State* tolua_S)
{
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'gain'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetGain(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: attenuation of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_get_SoundSource_attenuation
static int tolua_get_SoundSource_attenuation(lua_State* tolua_S)
{
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'attenuation'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAttenuation());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: attenuation of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_set_SoundSource_attenuation
static int tolua_set_SoundSource_attenuation(lua_State* tolua_S)
{
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'attenuation'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAttenuation(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: panning of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_get_SoundSource_panning
static int tolua_get_SoundSource_panning(lua_State* tolua_S)
{
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'panning'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetPanning());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: panning of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_set_SoundSource_panning
static int tolua_set_SoundSource_panning(lua_State* tolua_S)
{
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'panning'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPanning(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: autoRemoveMode of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_get_SoundSource_autoRemoveMode
static int tolua_get_SoundSource_autoRemoveMode(lua_State* tolua_S)
{
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'autoRemoveMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAutoRemoveMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: autoRemoveMode of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_set_SoundSource_autoRemoveMode
static int tolua_set_SoundSource_autoRemoveMode(lua_State* tolua_S)
{
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'autoRemoveMode'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAutoRemoveMode(((AutoRemoveMode) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: playing of class  SoundSource */
#ifndef TOLUA_DISABLE_tolua_get_SoundSource_playing
static int tolua_get_SoundSource_playing(lua_State* tolua_S)
{
  SoundSource* self = (SoundSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'playing'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsPlaying());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDistanceAttenuation of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource3D_SetDistanceAttenuation00
static int tolua_AudioLuaAPI_SoundSource3D_SetDistanceAttenuation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
  float nearDistance = ((float)  tolua_tonumber(tolua_S,2,0));
  float farDistance = ((float)  tolua_tonumber(tolua_S,3,0));
  float rolloffFactor = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDistanceAttenuation'", NULL);
#endif
 {
  self->SetDistanceAttenuation(nearDistance,farDistance,rolloffFactor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDistanceAttenuation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAngleAttenuation of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource3D_SetAngleAttenuation00
static int tolua_AudioLuaAPI_SoundSource3D_SetAngleAttenuation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
  float innerAngle = ((float)  tolua_tonumber(tolua_S,2,0));
  float outerAngle = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngleAttenuation'", NULL);
#endif
 {
  self->SetAngleAttenuation(innerAngle,outerAngle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAngleAttenuation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetNearDistance of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource3D_SetNearDistance00
static int tolua_AudioLuaAPI_SoundSource3D_SetNearDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
  float distance = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNearDistance'", NULL);
#endif
 {
  self->SetNearDistance(distance);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNearDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFarDistance of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource3D_SetFarDistance00
static int tolua_AudioLuaAPI_SoundSource3D_SetFarDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
  float distance = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFarDistance'", NULL);
#endif
 {
  self->SetFarDistance(distance);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFarDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetInnerAngle of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource3D_SetInnerAngle00
static int tolua_AudioLuaAPI_SoundSource3D_SetInnerAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInnerAngle'", NULL);
#endif
 {
  self->SetInnerAngle(angle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInnerAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOuterAngle of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource3D_SetOuterAngle00
static int tolua_AudioLuaAPI_SoundSource3D_SetOuterAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOuterAngle'", NULL);
#endif
 {
  self->SetOuterAngle(angle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOuterAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRolloffFactor of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource3D_SetRolloffFactor00
static int tolua_AudioLuaAPI_SoundSource3D_SetRolloffFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
  float factor = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRolloffFactor'", NULL);
#endif
 {
  self->SetRolloffFactor(factor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRolloffFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CalculateAttenuation of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource3D_CalculateAttenuation00
static int tolua_AudioLuaAPI_SoundSource3D_CalculateAttenuation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SoundSource3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CalculateAttenuation'", NULL);
#endif
 {
  self->CalculateAttenuation();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CalculateAttenuation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNearDistance of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource3D_GetNearDistance00
static int tolua_AudioLuaAPI_SoundSource3D_GetNearDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SoundSource3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SoundSource3D* self = (const SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNearDistance'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetNearDistance();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNearDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFarDistance of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource3D_GetFarDistance00
static int tolua_AudioLuaAPI_SoundSource3D_GetFarDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SoundSource3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SoundSource3D* self = (const SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFarDistance'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetFarDistance();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFarDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInnerAngle of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource3D_GetInnerAngle00
static int tolua_AudioLuaAPI_SoundSource3D_GetInnerAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SoundSource3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SoundSource3D* self = (const SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInnerAngle'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetInnerAngle();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInnerAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOuterAngle of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource3D_GetOuterAngle00
static int tolua_AudioLuaAPI_SoundSource3D_GetOuterAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SoundSource3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SoundSource3D* self = (const SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOuterAngle'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetOuterAngle();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOuterAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RollAngleoffFactor of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_AudioLuaAPI_SoundSource3D_RollAngleoffFactor00
static int tolua_AudioLuaAPI_SoundSource3D_RollAngleoffFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const SoundSource3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const SoundSource3D* self = (const SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RollAngleoffFactor'", NULL);
#endif
 {
  float tolua_ret = (float)  self->RollAngleoffFactor();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RollAngleoffFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nearDistance of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_get_SoundSource3D_nearDistance
static int tolua_get_SoundSource3D_nearDistance(lua_State* tolua_S)
{
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nearDistance'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNearDistance());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nearDistance of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_set_SoundSource3D_nearDistance
static int tolua_set_SoundSource3D_nearDistance(lua_State* tolua_S)
{
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nearDistance'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetNearDistance(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: farDistance of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_get_SoundSource3D_farDistance
static int tolua_get_SoundSource3D_farDistance(lua_State* tolua_S)
{
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'farDistance'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFarDistance());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: farDistance of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_set_SoundSource3D_farDistance
static int tolua_set_SoundSource3D_farDistance(lua_State* tolua_S)
{
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'farDistance'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFarDistance(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: innerAngle of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_get_SoundSource3D_innerAngle
static int tolua_get_SoundSource3D_innerAngle(lua_State* tolua_S)
{
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'innerAngle'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetInnerAngle());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: innerAngle of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_set_SoundSource3D_innerAngle
static int tolua_set_SoundSource3D_innerAngle(lua_State* tolua_S)
{
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'innerAngle'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetInnerAngle(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: outerAngle of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_get_SoundSource3D_outerAngle
static int tolua_get_SoundSource3D_outerAngle(lua_State* tolua_S)
{
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'outerAngle'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetOuterAngle());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: outerAngle of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_set_SoundSource3D_outerAngle
static int tolua_set_SoundSource3D_outerAngle(lua_State* tolua_S)
{
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'outerAngle'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOuterAngle(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rolloffFactor of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_get_SoundSource3D_rolloffFactor
static int tolua_get_SoundSource3D_rolloffFactor(lua_State* tolua_S)
{
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rolloffFactor'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRolloffFactor());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rolloffFactor of class  SoundSource3D */
#ifndef TOLUA_DISABLE_tolua_set_SoundSource3D_rolloffFactor
static int tolua_set_SoundSource3D_rolloffFactor(lua_State* tolua_S)
{
  SoundSource3D* self = (SoundSource3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rolloffFactor'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRolloffFactor(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_AudioLuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
 tolua_variable(tolua_S,"SOUND_MASTER",tolua_get_SOUND_MASTER,NULL);
 tolua_variable(tolua_S,"SOUND_EFFECT",tolua_get_SOUND_EFFECT,NULL);
 tolua_variable(tolua_S,"SOUND_AMBIENT",tolua_get_SOUND_AMBIENT,NULL);
 tolua_variable(tolua_S,"SOUND_VOICE",tolua_get_SOUND_VOICE,NULL);
 tolua_variable(tolua_S,"SOUND_MUSIC",tolua_get_SOUND_MUSIC,NULL);
 tolua_cclass(tolua_S,"Audio","Audio","Object",NULL);
 tolua_beginmodule(tolua_S,"Audio");
  tolua_function(tolua_S,"SetMode",tolua_AudioLuaAPI_Audio_SetMode00);
  tolua_function(tolua_S,"Play",tolua_AudioLuaAPI_Audio_Play00);
  tolua_function(tolua_S,"Stop",tolua_AudioLuaAPI_Audio_Stop00);
  tolua_function(tolua_S,"SetMasterGain",tolua_AudioLuaAPI_Audio_SetMasterGain00);
  tolua_function(tolua_S,"PauseSoundType",tolua_AudioLuaAPI_Audio_PauseSoundType00);
  tolua_function(tolua_S,"ResumeSoundType",tolua_AudioLuaAPI_Audio_ResumeSoundType00);
  tolua_function(tolua_S,"ResumeAll",tolua_AudioLuaAPI_Audio_ResumeAll00);
  tolua_function(tolua_S,"SetListener",tolua_AudioLuaAPI_Audio_SetListener00);
  tolua_function(tolua_S,"StopSound",tolua_AudioLuaAPI_Audio_StopSound00);
  tolua_function(tolua_S,"GetSampleSize",tolua_AudioLuaAPI_Audio_GetSampleSize00);
  tolua_function(tolua_S,"GetMixRate",tolua_AudioLuaAPI_Audio_GetMixRate00);
  tolua_function(tolua_S,"GetInterpolation",tolua_AudioLuaAPI_Audio_GetInterpolation00);
  tolua_function(tolua_S,"IsStereo",tolua_AudioLuaAPI_Audio_IsStereo00);
  tolua_function(tolua_S,"IsPlaying",tolua_AudioLuaAPI_Audio_IsPlaying00);
  tolua_function(tolua_S,"IsInitialized",tolua_AudioLuaAPI_Audio_IsInitialized00);
  tolua_function(tolua_S,"HasMasterGain",tolua_AudioLuaAPI_Audio_HasMasterGain00);
  tolua_function(tolua_S,"GetMasterGain",tolua_AudioLuaAPI_Audio_GetMasterGain00);
  tolua_function(tolua_S,"IsSoundTypePaused",tolua_AudioLuaAPI_Audio_IsSoundTypePaused00);
  tolua_function(tolua_S,"GetListener",tolua_AudioLuaAPI_Audio_GetListener00);
  tolua_function(tolua_S,"GetSoundSources",tolua_AudioLuaAPI_Audio_GetSoundSources00);
  tolua_function(tolua_S,"AddSoundSource",tolua_AudioLuaAPI_Audio_AddSoundSource00);
  tolua_function(tolua_S,"RemoveSoundSource",tolua_AudioLuaAPI_Audio_RemoveSoundSource00);
  tolua_function(tolua_S,"MixOutput",tolua_AudioLuaAPI_Audio_MixOutput00);
  tolua_variable(tolua_S,"sampleSize",tolua_get_Audio_sampleSize,NULL);
  tolua_variable(tolua_S,"mixRate",tolua_get_Audio_mixRate,NULL);
  tolua_variable(tolua_S,"interpolation",tolua_get_Audio_interpolation,NULL);
  tolua_variable(tolua_S,"stereo",tolua_get_Audio_stereo,NULL);
  tolua_variable(tolua_S,"playing",tolua_get_Audio_playing,NULL);
  tolua_variable(tolua_S,"initialized",tolua_get_Audio_initialized,NULL);
  tolua_variable(tolua_S,"listener",tolua_get_Audio_listener_ptr,tolua_set_Audio_listener_ptr);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"GetAudio",tolua_AudioLuaAPI_GetAudio00);
 tolua_variable(tolua_S,"audio",tolua_get_audio_ptr,NULL);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Sound","Sound","ResourceWithMetadata",tolua_collect_Sound);
 #else
 tolua_cclass(tolua_S,"Sound","Sound","ResourceWithMetadata",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Sound");
  tolua_function(tolua_S,"new",tolua_AudioLuaAPI_Sound_new00);
  tolua_function(tolua_S,"new_local",tolua_AudioLuaAPI_Sound_new00_local);
  tolua_function(tolua_S,".call",tolua_AudioLuaAPI_Sound_new00_local);
  tolua_function(tolua_S,"delete",tolua_AudioLuaAPI_Sound_delete00);
  tolua_function(tolua_S,"LoadRaw",tolua_AudioLuaAPI_Sound_LoadRaw00);
  tolua_function(tolua_S,"LoadWav",tolua_AudioLuaAPI_Sound_LoadWav00);
  tolua_function(tolua_S,"LoadOggVorbis",tolua_AudioLuaAPI_Sound_LoadOggVorbis00);
  tolua_function(tolua_S,"LoadRaw",tolua_AudioLuaAPI_Sound_LoadRaw01);
  tolua_function(tolua_S,"LoadWav",tolua_AudioLuaAPI_Sound_LoadWav01);
  tolua_function(tolua_S,"LoadOggVorbis",tolua_AudioLuaAPI_Sound_LoadOggVorbis01);
  tolua_function(tolua_S,"SetSize",tolua_AudioLuaAPI_Sound_SetSize00);
  tolua_function(tolua_S,"SetData",tolua_AudioLuaAPI_Sound_SetData00);
  tolua_function(tolua_S,"SetFormat",tolua_AudioLuaAPI_Sound_SetFormat00);
  tolua_function(tolua_S,"SetLooped",tolua_AudioLuaAPI_Sound_SetLooped00);
  tolua_function(tolua_S,"SetLoop",tolua_AudioLuaAPI_Sound_SetLoop00);
  tolua_function(tolua_S,"FixInterpolation",tolua_AudioLuaAPI_Sound_FixInterpolation00);
  tolua_function(tolua_S,"GetLength",tolua_AudioLuaAPI_Sound_GetLength00);
  tolua_function(tolua_S,"GetDataSize",tolua_AudioLuaAPI_Sound_GetDataSize00);
  tolua_function(tolua_S,"GetSampleSize",tolua_AudioLuaAPI_Sound_GetSampleSize00);
  tolua_function(tolua_S,"GetFrequency",tolua_AudioLuaAPI_Sound_GetFrequency00);
  tolua_function(tolua_S,"GetIntFrequency",tolua_AudioLuaAPI_Sound_GetIntFrequency00);
  tolua_function(tolua_S,"IsLooped",tolua_AudioLuaAPI_Sound_IsLooped00);
  tolua_function(tolua_S,"IsSixteenBit",tolua_AudioLuaAPI_Sound_IsSixteenBit00);
  tolua_function(tolua_S,"IsStereo",tolua_AudioLuaAPI_Sound_IsStereo00);
  tolua_function(tolua_S,"IsCompressed",tolua_AudioLuaAPI_Sound_IsCompressed00);
  tolua_variable(tolua_S,"length",tolua_get_Sound_length,NULL);
  tolua_variable(tolua_S,"dataSize",tolua_get_Sound_dataSize,NULL);
  tolua_variable(tolua_S,"sampleSize",tolua_get_Sound_sampleSize,NULL);
  tolua_variable(tolua_S,"frequency",tolua_get_Sound_frequency,NULL);
  tolua_variable(tolua_S,"intFrequency",tolua_get_Sound_intFrequency,NULL);
  tolua_variable(tolua_S,"looped",tolua_get_Sound_looped,tolua_set_Sound_looped);
  tolua_variable(tolua_S,"sixteenBit",tolua_get_Sound_sixteenBit,NULL);
  tolua_variable(tolua_S,"stereo",tolua_get_Sound_stereo,NULL);
  tolua_variable(tolua_S,"compressed",tolua_get_Sound_compressed,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"SoundListener","SoundListener","Component",NULL);
 tolua_beginmodule(tolua_S,"SoundListener");
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"SoundSource","SoundSource","Component",NULL);
 tolua_beginmodule(tolua_S,"SoundSource");
  tolua_function(tolua_S,"Seek",tolua_AudioLuaAPI_SoundSource_Seek00);
  tolua_function(tolua_S,"Play",tolua_AudioLuaAPI_SoundSource_Play00);
  tolua_function(tolua_S,"Play",tolua_AudioLuaAPI_SoundSource_Play01);
  tolua_function(tolua_S,"Play",tolua_AudioLuaAPI_SoundSource_Play02);
  tolua_function(tolua_S,"Play",tolua_AudioLuaAPI_SoundSource_Play03);
  tolua_function(tolua_S,"Stop",tolua_AudioLuaAPI_SoundSource_Stop00);
  tolua_function(tolua_S,"SetSoundType",tolua_AudioLuaAPI_SoundSource_SetSoundType00);
  tolua_function(tolua_S,"SetFrequency",tolua_AudioLuaAPI_SoundSource_SetFrequency00);
  tolua_function(tolua_S,"SetGain",tolua_AudioLuaAPI_SoundSource_SetGain00);
  tolua_function(tolua_S,"SetAttenuation",tolua_AudioLuaAPI_SoundSource_SetAttenuation00);
  tolua_function(tolua_S,"SetPanning",tolua_AudioLuaAPI_SoundSource_SetPanning00);
  tolua_function(tolua_S,"SetAutoRemoveMode",tolua_AudioLuaAPI_SoundSource_SetAutoRemoveMode00);
  tolua_function(tolua_S,"GetSound",tolua_AudioLuaAPI_SoundSource_GetSound00);
  tolua_function(tolua_S,"GetSoundType",tolua_AudioLuaAPI_SoundSource_GetSoundType00);
  tolua_function(tolua_S,"GetTimePosition",tolua_AudioLuaAPI_SoundSource_GetTimePosition00);
  tolua_function(tolua_S,"GetFrequency",tolua_AudioLuaAPI_SoundSource_GetFrequency00);
  tolua_function(tolua_S,"GetGain",tolua_AudioLuaAPI_SoundSource_GetGain00);
  tolua_function(tolua_S,"GetAttenuation",tolua_AudioLuaAPI_SoundSource_GetAttenuation00);
  tolua_function(tolua_S,"GetPanning",tolua_AudioLuaAPI_SoundSource_GetPanning00);
  tolua_function(tolua_S,"GetAutoRemoveMode",tolua_AudioLuaAPI_SoundSource_GetAutoRemoveMode00);
  tolua_function(tolua_S,"IsPlaying",tolua_AudioLuaAPI_SoundSource_IsPlaying00);
  tolua_variable(tolua_S,"sound",tolua_get_SoundSource_sound_ptr,NULL);
  tolua_variable(tolua_S,"soundType",tolua_get_SoundSource_soundType,tolua_set_SoundSource_soundType);
  tolua_variable(tolua_S,"timePosition",tolua_get_SoundSource_timePosition,NULL);
  tolua_variable(tolua_S,"frequency",tolua_get_SoundSource_frequency,tolua_set_SoundSource_frequency);
  tolua_variable(tolua_S,"gain",tolua_get_SoundSource_gain,tolua_set_SoundSource_gain);
  tolua_variable(tolua_S,"attenuation",tolua_get_SoundSource_attenuation,tolua_set_SoundSource_attenuation);
  tolua_variable(tolua_S,"panning",tolua_get_SoundSource_panning,tolua_set_SoundSource_panning);
  tolua_variable(tolua_S,"autoRemoveMode",tolua_get_SoundSource_autoRemoveMode,tolua_set_SoundSource_autoRemoveMode);
  tolua_variable(tolua_S,"playing",tolua_get_SoundSource_playing,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"SoundSource3D","SoundSource3D","SoundSource",NULL);
 tolua_beginmodule(tolua_S,"SoundSource3D");
  tolua_function(tolua_S,"SetDistanceAttenuation",tolua_AudioLuaAPI_SoundSource3D_SetDistanceAttenuation00);
  tolua_function(tolua_S,"SetAngleAttenuation",tolua_AudioLuaAPI_SoundSource3D_SetAngleAttenuation00);
  tolua_function(tolua_S,"SetNearDistance",tolua_AudioLuaAPI_SoundSource3D_SetNearDistance00);
  tolua_function(tolua_S,"SetFarDistance",tolua_AudioLuaAPI_SoundSource3D_SetFarDistance00);
  tolua_function(tolua_S,"SetInnerAngle",tolua_AudioLuaAPI_SoundSource3D_SetInnerAngle00);
  tolua_function(tolua_S,"SetOuterAngle",tolua_AudioLuaAPI_SoundSource3D_SetOuterAngle00);
  tolua_function(tolua_S,"SetRolloffFactor",tolua_AudioLuaAPI_SoundSource3D_SetRolloffFactor00);
  tolua_function(tolua_S,"CalculateAttenuation",tolua_AudioLuaAPI_SoundSource3D_CalculateAttenuation00);
  tolua_function(tolua_S,"GetNearDistance",tolua_AudioLuaAPI_SoundSource3D_GetNearDistance00);
  tolua_function(tolua_S,"GetFarDistance",tolua_AudioLuaAPI_SoundSource3D_GetFarDistance00);
  tolua_function(tolua_S,"GetInnerAngle",tolua_AudioLuaAPI_SoundSource3D_GetInnerAngle00);
  tolua_function(tolua_S,"GetOuterAngle",tolua_AudioLuaAPI_SoundSource3D_GetOuterAngle00);
  tolua_function(tolua_S,"RollAngleoffFactor",tolua_AudioLuaAPI_SoundSource3D_RollAngleoffFactor00);
  tolua_variable(tolua_S,"nearDistance",tolua_get_SoundSource3D_nearDistance,tolua_set_SoundSource3D_nearDistance);
  tolua_variable(tolua_S,"farDistance",tolua_get_SoundSource3D_farDistance,tolua_set_SoundSource3D_farDistance);
  tolua_variable(tolua_S,"innerAngle",tolua_get_SoundSource3D_innerAngle,tolua_set_SoundSource3D_innerAngle);
  tolua_variable(tolua_S,"outerAngle",tolua_get_SoundSource3D_outerAngle,tolua_set_SoundSource3D_outerAngle);
  tolua_variable(tolua_S,"rolloffFactor",tolua_get_SoundSource3D_rolloffFactor,tolua_set_SoundSource3D_rolloffFactor);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_AudioLuaAPI (lua_State* tolua_S) {
 return tolua_AudioLuaAPI_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif