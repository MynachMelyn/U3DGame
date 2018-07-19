/*
** Lua binding: UILuaAPI
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
TOLUA_API int tolua_UILuaAPI_open (lua_State* tolua_S);

#include "IO/File.h"
#include "UI/UIElement.h"
#include "UI/UISelectable.h"
#include "UI/BorderImage.h"
#include "UI/Button.h"
#include "UI/CheckBox.h"
#include "UI/Cursor.h"
#include "UI/FileSelector.h"
#include "UI/Font.h"
#include "UI/LineEdit.h"
#include "UI/Menu.h"
#include "UI/MessageBox.h"
#include "UI/ProgressBar.h"
#include "UI/DropDownList.h"
#include "UI/Slider.h"
#include "UI/ScrollBar.h"
#include "UI/ScrollView.h"
#include "UI/ListView.h"
#include "UI/Sprite.h"
#include "UI/Text.h"
#include "UI/Text3D.h"
#include "UI/ToolTip.h"
#include "UI/UI.h"
#include "UI/Window.h"
#include "UI/View3D.h"
#include "UI/UIComponent.h"
#include "UI/UIElement.h"
#include "Scene/Component.h"
#include "Graphics/Material.h"
#include "Graphics/Texture2D.h"
#include "Graphics/StaticModel.h"
using namespace Urho3D;
#pragma warning(disable:4800)

#define TOLUA_DISABLE_tolua_UILuaAPI_UIElement_new00
static int tolua_UILuaAPI_UIElement_new00(lua_State* tolua_S)
{
    return ToluaNewObject<UIElement>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_UIElement_new00_local
static int tolua_UILuaAPI_UIElement_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<UIElement>(tolua_S);
}

static bool UIElementLoadXML(UIElement* element, const String& fileName)
{
    if (!element)
        return false;

    File file(element->GetContext());
    if (!file.Open(fileName, FILE_READ))
        return false;

    return element->LoadXML(file);
}

static bool UIElementSaveXML(const UIElement* element, const String& fileName, const String& indentation)
{
    if (!element)
        return false;

    File file(element->GetContext());
    if (!file.Open(fileName, FILE_WRITE))
        return false;

    return element->SaveXML(file, indentation);
}

static const PODVector<UIElement*>& UIElementGetChildrenWithTag(const UIElement* element, const String& tag, bool recursive = false)
{
    static PODVector<UIElement*> dest;
    element->GetChildrenWithTag(dest, tag, recursive);
    return dest;
}

#define GetStyle GetAppliedStyle
#define SetColorAttr SetColor

#define TOLUA_DISABLE_tolua_UILuaAPI_UISelectable_new00
static int tolua_UILuaAPI_UISelectable_new00(lua_State* tolua_S)
{
    return ToluaNewObject<UISelectable>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_UISelectable_new00_local
static int tolua_UILuaAPI_UISelectable_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<UISelectable>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_new00
static int tolua_UILuaAPI_BorderImage_new00(lua_State* tolua_S)
{
    return ToluaNewObject<BorderImage>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_new00_local
static int tolua_UILuaAPI_BorderImage_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<BorderImage>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_Button_new00
static int tolua_UILuaAPI_Button_new00(lua_State* tolua_S)
{
    return ToluaNewObject<Button>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_Button_new00_local
static int tolua_UILuaAPI_Button_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<Button>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_CheckBox_new00
static int tolua_UILuaAPI_CheckBox_new00(lua_State* tolua_S)
{
    return ToluaNewObject<CheckBox>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_CheckBox_new00_local
static int tolua_UILuaAPI_CheckBox_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<CheckBox>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_Cursor_new00
static int tolua_UILuaAPI_Cursor_new00(lua_State* tolua_S)
{
    return ToluaNewObject<Cursor>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_Cursor_new00_local
static int tolua_UILuaAPI_Cursor_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<Cursor>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_new00
static int tolua_UILuaAPI_FileSelector_new00(lua_State* tolua_S)
{
    return ToluaNewObject<FileSelector>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_new00_local
static int tolua_UILuaAPI_FileSelector_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<FileSelector>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_new00
static int tolua_UILuaAPI_LineEdit_new00(lua_State* tolua_S)
{
    return ToluaNewObject<LineEdit>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_new00_local
static int tolua_UILuaAPI_LineEdit_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<LineEdit>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_Menu_new00
static int tolua_UILuaAPI_Menu_new00(lua_State* tolua_S)
{
    return ToluaNewObject<Menu>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_Menu_new00_local
static int tolua_UILuaAPI_Menu_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<Menu>(tolua_S);
}

#define SetShowPopup ShowPopup

#define TOLUA_DISABLE_tolua_UILuaAPI_MessageBox_new00
static int tolua_UILuaAPI_MessageBox_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MessageBox",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isusertype(tolua_S,4,"XMLFile",1,&tolua_err) ||
 !tolua_isusertype(tolua_S,5,"XMLFile",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String messageString = ((const String)  tolua_tourho3dstring(tolua_S,2,String::EMPTY));
  const String titleString = ((const String)  tolua_tourho3dstring(tolua_S,3,String::EMPTY));
  XMLFile* layoutFile = ((XMLFile*)  tolua_tousertype(tolua_S,4,0));
  XMLFile* styleFile = ((XMLFile*)  tolua_tousertype(tolua_S,5,0));
 {
  MessageBox* tolua_ret = (MessageBox*)  Mtolua_new((MessageBox)(GetContext(tolua_S),messageString,titleString,layoutFile,styleFile));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"MessageBox");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

#define TOLUA_DISABLE_tolua_UILuaAPI_MessageBox_new00_local
static int tolua_UILuaAPI_MessageBox_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MessageBox",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isusertype(tolua_S,4,"XMLFile",1,&tolua_err) ||
 !tolua_isusertype(tolua_S,5,"XMLFile",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String messageString = ((const String)  tolua_tourho3dstring(tolua_S,2,String::EMPTY));
  const String titleString = ((const String)  tolua_tourho3dstring(tolua_S,3,String::EMPTY));
  XMLFile* layoutFile = ((XMLFile*)  tolua_tousertype(tolua_S,4,0));
  XMLFile* styleFile = ((XMLFile*)  tolua_tousertype(tolua_S,5,0));
 {
  MessageBox* tolua_ret = (MessageBox*)  Mtolua_new((MessageBox)(GetContext(tolua_S),messageString,titleString,layoutFile,styleFile));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"MessageBox");
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

#define TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_new00
static int tolua_UILuaAPI_ProgressBar_new00(lua_State* tolua_S)
{
    return ToluaNewObject<ProgressBar>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_new00_local
static int tolua_UILuaAPI_ProgressBar_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<ProgressBar>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_new00
static int tolua_UILuaAPI_DropDownList_new00(lua_State* tolua_S)
{
    return ToluaNewObject<DropDownList>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_new00_local
static int tolua_UILuaAPI_DropDownList_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<DropDownList>(tolua_S);
}

static const PODVector<UIElement*>& DropDownListGetItems(const DropDownList* list)
{
    static PODVector<UIElement*> items;
    items = list->GetItems();
    return items;
}

#define TOLUA_DISABLE_tolua_UILuaAPI_Slider_new00
static int tolua_UILuaAPI_Slider_new00(lua_State* tolua_S)
{
    return ToluaNewObject<Slider>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_Slider_new00_local
static int tolua_UILuaAPI_Slider_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<Slider>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_new00
static int tolua_UILuaAPI_ScrollBar_new00(lua_State* tolua_S)
{
    return ToluaNewObject<ScrollBar>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_new00_local
static int tolua_UILuaAPI_ScrollBar_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<ScrollBar>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_new00
static int tolua_UILuaAPI_ScrollView_new00(lua_State* tolua_S)
{
    return ToluaNewObject<ScrollView>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_new00_local
static int tolua_UILuaAPI_ScrollView_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<ScrollView>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_ListView_new00
static int tolua_UILuaAPI_ListView_new00(lua_State* tolua_S)
{
    return ToluaNewObject<ListView>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_ListView_new00_local
static int tolua_UILuaAPI_ListView_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<ListView>(tolua_S);
}

static const PODVector<UIElement*>& ListViewGetItems(const ListView* listView)
{
    static PODVector<UIElement*> items;
    items = listView->GetItems();
    return items;
}

static const PODVector<UIElement*>& ListViewGetSelectedItems(const ListView* listView)
{
    static PODVector<UIElement*> items;
    items = listView->GetSelectedItems();
    return items;
}

#define TOLUA_DISABLE_tolua_UILuaAPI_Sprite_new00
static int tolua_UILuaAPI_Sprite_new00(lua_State* tolua_S)
{
    return ToluaNewObject<Sprite>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_Sprite_new00_local
static int tolua_UILuaAPI_Sprite_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<Sprite>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_Text_new00
static int tolua_UILuaAPI_Text_new00(lua_State* tolua_S)
{
    return ToluaNewObject<Text>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_Text_new00_local
static int tolua_UILuaAPI_Text_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<Text>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_Text3D_new00
static int tolua_UILuaAPI_Text3D_new00(lua_State* tolua_S)
{
    return ToluaNewObject<Text3D>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_Text3D_new00_local
static int tolua_UILuaAPI_Text3D_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<Text3D>(tolua_S);
}

#define TOLUA_DISABLE_tolua_get_Text3D_color_ref
#define tolua_get_Text3D_color_ref NULL

#define TOLUA_DISABLE_tolua_UILuaAPI_ToolTip_new00
static int tolua_UILuaAPI_ToolTip_new00(lua_State* tolua_S)
{
    return ToluaNewObject<ToolTip>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_ToolTip_new00_local
static int tolua_UILuaAPI_ToolTip_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<ToolTip>(tolua_S);
}

static UIElement* UILoadLayout(UI* ui, File* source, XMLFile* styleFile)
{
    if (!source)
        return 0;

    return ui->LoadLayout(*source, styleFile).Detach();
}

static UIElement* UILoadLayout(UI* ui, const String& fileName, XMLFile* styleFile)
{
    File file(ui->GetContext(), fileName, FILE_READ);
    if (!file.IsOpen())
        return 0;

    return ui->LoadLayout(file, styleFile).Detach();
}

static UIElement* UILoadLayout(UI* ui, XMLFile* source, XMLFile* styleFile)
{
    if (!source)
        return 0;

    return ui->LoadLayout(source, styleFile).Detach();
}

#define TOLUA_DISABLE_tolua_UILuaAPI_GetUI00
static int tolua_UILuaAPI_GetUI00(lua_State* tolua_S)
{
    return ToluaGetSubsystem<UI>(tolua_S);
}

#define TOLUA_DISABLE_tolua_get_ui_ptr
#define tolua_get_ui_ptr tolua_UILuaAPI_GetUI00

#define TOLUA_DISABLE_tolua_UILuaAPI_Window_new00
static int tolua_UILuaAPI_Window_new00(lua_State* tolua_S)
{
    return ToluaNewObject<Window>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_Window_new00_local
static int tolua_UILuaAPI_Window_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<Window>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_View3D_new00
static int tolua_UILuaAPI_View3D_new00(lua_State* tolua_S)
{
    return ToluaNewObject<View3D>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_View3D_new00_local
static int tolua_UILuaAPI_View3D_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<View3D>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_UIComponent_new00
static int tolua_UILuaAPI_UIComponent_new00(lua_State* tolua_S)
{
    return ToluaNewObject<UIComponent>(tolua_S);
}

#define TOLUA_DISABLE_tolua_UILuaAPI_UIComponent_new00_local
static int tolua_UILuaAPI_UIComponent_new00_local(lua_State* tolua_S)
{
    return ToluaNewObjectGC<UIComponent>(tolua_S);
}

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_UIComponent (lua_State* tolua_S)
{
 UIComponent* self = (UIComponent*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_UIElement (lua_State* tolua_S)
{
 UIElement* self = (UIElement*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_FileSelector (lua_State* tolua_S)
{
 FileSelector* self = (FileSelector*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Cursor (lua_State* tolua_S)
{
 Cursor* self = (Cursor*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Text3D (lua_State* tolua_S)
{
 Text3D* self = (Text3D*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_MessageBox (lua_State* tolua_S)
{
 MessageBox* self = (MessageBox*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Button (lua_State* tolua_S)
{
 Button* self = (Button*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_View3D (lua_State* tolua_S)
{
 View3D* self = (View3D*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Window (lua_State* tolua_S)
{
 Window* self = (Window*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_LineEdit (lua_State* tolua_S)
{
 LineEdit* self = (LineEdit*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_ToolTip (lua_State* tolua_S)
{
 ToolTip* self = (ToolTip*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_ListView (lua_State* tolua_S)
{
 ListView* self = (ListView*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_IntRect (lua_State* tolua_S)
{
 IntRect* self = (IntRect*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Vector2 (lua_State* tolua_S)
{
 Vector2* self = (Vector2*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_ScrollBar (lua_State* tolua_S)
{
 ScrollBar* self = (ScrollBar*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Text (lua_State* tolua_S)
{
 Text* self = (Text*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_CheckBox (lua_State* tolua_S)
{
 CheckBox* self = (CheckBox*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_ScrollView (lua_State* tolua_S)
{
 ScrollView* self = (ScrollView*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Sprite (lua_State* tolua_S)
{
 Sprite* self = (Sprite*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Slider (lua_State* tolua_S)
{
 Slider* self = (Slider*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Menu (lua_State* tolua_S)
{
 Menu* self = (Menu*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_DropDownList (lua_State* tolua_S)
{
 DropDownList* self = (DropDownList*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_UISelectable (lua_State* tolua_S)
{
 UISelectable* self = (UISelectable*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_ProgressBar (lua_State* tolua_S)
{
 ProgressBar* self = (ProgressBar*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_BorderImage (lua_State* tolua_S)
{
 BorderImage* self = (BorderImage*) tolua_tousertype(tolua_S,1,0);
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
 tolua_usertype(tolua_S,"FileSelector");
 tolua_usertype(tolua_S,"PODVector<UIElement*>");
 tolua_usertype(tolua_S,"Vector<String>");
 tolua_usertype(tolua_S,"FileSelectorEntry");
 tolua_usertype(tolua_S,"Variant");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"Texture");
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"UI");
 tolua_usertype(tolua_S,"IntRect");
 tolua_usertype(tolua_S,"Viewport");
 tolua_usertype(tolua_S,"Texture2D");
 tolua_usertype(tolua_S,"Scene");
 tolua_usertype(tolua_S,"CheckBox");
 tolua_usertype(tolua_S,"StringHash");
 tolua_usertype(tolua_S,"Sprite");
 tolua_usertype(tolua_S,"Camera");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"View3D");
 tolua_usertype(tolua_S,"UISelectable");
 tolua_usertype(tolua_S,"ListView");
 tolua_usertype(tolua_S,"Resource");
 tolua_usertype(tolua_S,"IntVector2");
 tolua_usertype(tolua_S,"UIComponent");
 tolua_usertype(tolua_S,"XMLFile");
 tolua_usertype(tolua_S,"Serializer");
 tolua_usertype(tolua_S,"ToolTip");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"Window");
 tolua_usertype(tolua_S,"Cursor");
 tolua_usertype(tolua_S,"UIElement");
 tolua_usertype(tolua_S,"Text3D");
 tolua_usertype(tolua_S,"Image");
 tolua_usertype(tolua_S,"Drawable");
 tolua_usertype(tolua_S,"PODVector<unsigned>");
 tolua_usertype(tolua_S,"Button");
 tolua_usertype(tolua_S,"Material");
 tolua_usertype(tolua_S,"HierarchyContainer");
 tolua_usertype(tolua_S,"LineEdit");
 tolua_usertype(tolua_S,"ScrollView");
 tolua_usertype(tolua_S,"ScrollBar");
 tolua_usertype(tolua_S,"StringVector");
 tolua_usertype(tolua_S,"Slider");
 tolua_usertype(tolua_S,"DropDownList");
 tolua_usertype(tolua_S,"Text");
 tolua_usertype(tolua_S,"ProgressBar");
 tolua_usertype(tolua_S,"Animatable");
 tolua_usertype(tolua_S,"MessageBox");
 tolua_usertype(tolua_S,"Font");
 tolua_usertype(tolua_S,"Menu");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"Deserializer");
 tolua_usertype(tolua_S,"File");
 tolua_usertype(tolua_S,"BorderImage");
 tolua_usertype(tolua_S,"XMLElement");
}

/* get function: DD_DISABLED */
#ifndef TOLUA_DISABLE_tolua_get_DD_DISABLED
static int tolua_get_DD_DISABLED(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)DD_DISABLED);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DD_SOURCE */
#ifndef TOLUA_DISABLE_tolua_get_DD_SOURCE
static int tolua_get_DD_SOURCE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)DD_SOURCE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DD_TARGET */
#ifndef TOLUA_DISABLE_tolua_get_DD_TARGET
static int tolua_get_DD_TARGET(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)DD_TARGET);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DD_SOURCE_AND_TARGET */
#ifndef TOLUA_DISABLE_tolua_get_DD_SOURCE_AND_TARGET
static int tolua_get_DD_SOURCE_AND_TARGET(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)DD_SOURCE_AND_TARGET);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_new00
static int tolua_UILuaAPI_UIElement_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  UIElement* tolua_ret = (UIElement*)  Mtolua_new((UIElement)());
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
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

/* method: new_local of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_new00_local
static int tolua_UILuaAPI_UIElement_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  UIElement* tolua_ret = (UIElement*)  Mtolua_new((UIElement)());
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
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

/* method: delete of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_delete00
static int tolua_UILuaAPI_UIElement_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetScreenPosition of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetScreenPosition00
static int tolua_UILuaAPI_UIElement_GetScreenPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScreenPosition'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetScreenPosition();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScreenPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadXML of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_LoadXML00
static int tolua_UILuaAPI_UIElement_LoadXML00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Deserializer",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  Deserializer* source = ((Deserializer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadXML'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->LoadXML(*source);
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

/* method: SaveXML of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SaveXML00
static int tolua_UILuaAPI_UIElement_SaveXML00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Serializer",0,&tolua_err)) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
  Serializer* dest = ((Serializer*)  tolua_tousertype(tolua_S,2,0));
  const String indentation = ((const String)  tolua_tourho3dstring(tolua_S,3,"\t"));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveXML'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SaveXML(*dest,indentation);
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

/* method: UIElementLoadXML of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_LoadXML01
static int tolua_UILuaAPI_UIElement_LoadXML01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UIElementLoadXML'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  UIElementLoadXML(self,fileName);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_UILuaAPI_UIElement_LoadXML00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UIElementSaveXML of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SaveXML01
static int tolua_UILuaAPI_UIElement_SaveXML01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String indentation = ((const String)  tolua_tourho3dstring(tolua_S,3,"\t"));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UIElementSaveXML'", NULL);
#endif
 {
  tolua_outside bool tolua_ret = (tolua_outside bool)  UIElementSaveXML(self,fileName,indentation);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_UILuaAPI_UIElement_SaveXML00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: FilterAttributes of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_FilterAttributes00
static int tolua_UILuaAPI_UIElement_FilterAttributes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"XMLElement",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
  XMLElement* dest = ((XMLElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FilterAttributes'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->FilterAttributes(*dest);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FilterAttributes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetName of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetName00
static int tolua_UILuaAPI_UIElement_SetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetPosition of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetPosition00
static int tolua_UILuaAPI_UIElement_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* position = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
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

/* method: SetPosition of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetPosition01
static int tolua_UILuaAPI_UIElement_SetPosition01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
 {
  self->SetPosition(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_UIElement_SetPosition00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetSize00
static int tolua_UILuaAPI_UIElement_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* size = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
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

/* method: SetSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetSize01
static int tolua_UILuaAPI_UIElement_SetSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
 {
  self->SetSize(width,height);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_UIElement_SetSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWidth of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetWidth00
static int tolua_UILuaAPI_UIElement_SetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWidth'", NULL);
#endif
 {
  self->SetWidth(width);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHeight of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetHeight00
static int tolua_UILuaAPI_UIElement_SetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int height = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHeight'", NULL);
#endif
 {
  self->SetHeight(height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMinSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetMinSize00
static int tolua_UILuaAPI_UIElement_SetMinSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* minSize = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMinSize'", NULL);
#endif
 {
  self->SetMinSize(*minSize);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMinSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMinSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetMinSize01
static int tolua_UILuaAPI_UIElement_SetMinSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMinSize'", NULL);
#endif
 {
  self->SetMinSize(width,height);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_UIElement_SetMinSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMinWidth of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetMinWidth00
static int tolua_UILuaAPI_UIElement_SetMinWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMinWidth'", NULL);
#endif
 {
  self->SetMinWidth(width);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMinWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMinHeight of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetMinHeight00
static int tolua_UILuaAPI_UIElement_SetMinHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int height = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMinHeight'", NULL);
#endif
 {
  self->SetMinHeight(height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMinHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetMaxSize00
static int tolua_UILuaAPI_UIElement_SetMaxSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* maxSize = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxSize'", NULL);
#endif
 {
  self->SetMaxSize(*maxSize);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetMaxSize01
static int tolua_UILuaAPI_UIElement_SetMaxSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxSize'", NULL);
#endif
 {
  self->SetMaxSize(width,height);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_UIElement_SetMaxSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxWidth of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetMaxWidth00
static int tolua_UILuaAPI_UIElement_SetMaxWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxWidth'", NULL);
#endif
 {
  self->SetMaxWidth(width);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxHeight of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetMaxHeight00
static int tolua_UILuaAPI_UIElement_SetMaxHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int height = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxHeight'", NULL);
#endif
 {
  self->SetMaxHeight(height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFixedSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetFixedSize00
static int tolua_UILuaAPI_UIElement_SetFixedSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* size = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFixedSize'", NULL);
#endif
 {
  self->SetFixedSize(*size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFixedSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFixedSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetFixedSize01
static int tolua_UILuaAPI_UIElement_SetFixedSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFixedSize'", NULL);
#endif
 {
  self->SetFixedSize(width,height);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_UIElement_SetFixedSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFixedWidth of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetFixedWidth00
static int tolua_UILuaAPI_UIElement_SetFixedWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFixedWidth'", NULL);
#endif
 {
  self->SetFixedWidth(width);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFixedWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFixedHeight of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetFixedHeight00
static int tolua_UILuaAPI_UIElement_SetFixedHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int height = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFixedHeight'", NULL);
#endif
 {
  self->SetFixedHeight(height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFixedHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAlignment of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetAlignment00
static int tolua_UILuaAPI_UIElement_SetAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  HorizontalAlignment hAlign = ((HorizontalAlignment) (int)  tolua_tonumber(tolua_S,2,0));
  VerticalAlignment vAlign = ((VerticalAlignment) (int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAlignment'", NULL);
#endif
 {
  self->SetAlignment(hAlign,vAlign);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHorizontalAlignment of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetHorizontalAlignment00
static int tolua_UILuaAPI_UIElement_SetHorizontalAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  HorizontalAlignment align = ((HorizontalAlignment) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHorizontalAlignment'", NULL);
#endif
 {
  self->SetHorizontalAlignment(align);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHorizontalAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVerticalAlignment of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetVerticalAlignment00
static int tolua_UILuaAPI_UIElement_SetVerticalAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  VerticalAlignment align = ((VerticalAlignment) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVerticalAlignment'", NULL);
#endif
 {
  self->SetVerticalAlignment(align);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVerticalAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEnableAnchor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetEnableAnchor00
static int tolua_UILuaAPI_UIElement_SetEnableAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEnableAnchor'", NULL);
#endif
 {
  self->SetEnableAnchor(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEnableAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMinAnchor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetMinAnchor00
static int tolua_UILuaAPI_UIElement_SetMinAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* anchor = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMinAnchor'", NULL);
#endif
 {
  self->SetMinAnchor(*anchor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMinAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMinAnchor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetMinAnchor01
static int tolua_UILuaAPI_UIElement_SetMinAnchor01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMinAnchor'", NULL);
#endif
 {
  self->SetMinAnchor(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_UIElement_SetMinAnchor00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxAnchor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetMaxAnchor00
static int tolua_UILuaAPI_UIElement_SetMaxAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* anchor = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxAnchor'", NULL);
#endif
 {
  self->SetMaxAnchor(*anchor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxAnchor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetMaxAnchor01
static int tolua_UILuaAPI_UIElement_SetMaxAnchor01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxAnchor'", NULL);
#endif
 {
  self->SetMaxAnchor(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_UIElement_SetMaxAnchor00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMinOffset of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetMinOffset00
static int tolua_UILuaAPI_UIElement_SetMinOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* offset = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMinOffset'", NULL);
#endif
 {
  self->SetMinOffset(*offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMinOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxOffset of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetMaxOffset00
static int tolua_UILuaAPI_UIElement_SetMaxOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* offset = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxOffset'", NULL);
#endif
 {
  self->SetMaxOffset(*offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPivot of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetPivot00
static int tolua_UILuaAPI_UIElement_SetPivot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* pivot = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPivot'", NULL);
#endif
 {
  self->SetPivot(*pivot);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPivot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPivot of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetPivot01
static int tolua_UILuaAPI_UIElement_SetPivot01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPivot'", NULL);
#endif
 {
  self->SetPivot(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_UIElement_SetPivot00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetClipBorder of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetClipBorder00
static int tolua_UILuaAPI_UIElement_SetClipBorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* rect = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetClipBorder'", NULL);
#endif
 {
  self->SetClipBorder(*rect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetClipBorder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetColor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetColor00
static int tolua_UILuaAPI_UIElement_SetColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetColor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetColor01
static int tolua_UILuaAPI_UIElement_SetColor01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  Corner corner = ((Corner) (int)  tolua_tonumber(tolua_S,2,0));
  const Color* color = ((const Color*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetColor'", NULL);
#endif
 {
  self->SetColor(corner,*color);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_UIElement_SetColor00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPriority of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetPriority00
static int tolua_UILuaAPI_UIElement_SetPriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int priority = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPriority'", NULL);
#endif
 {
  self->SetPriority(priority);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPriority'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOpacity of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetOpacity00
static int tolua_UILuaAPI_UIElement_SetOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  float opacity = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOpacity'", NULL);
#endif
 {
  self->SetOpacity(opacity);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBringToFront of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetBringToFront00
static int tolua_UILuaAPI_UIElement_SetBringToFront00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBringToFront'", NULL);
#endif
 {
  self->SetBringToFront(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBringToFront'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBringToBack of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetBringToBack00
static int tolua_UILuaAPI_UIElement_SetBringToBack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBringToBack'", NULL);
#endif
 {
  self->SetBringToBack(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBringToBack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetClipChildren of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetClipChildren00
static int tolua_UILuaAPI_UIElement_SetClipChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetClipChildren'", NULL);
#endif
 {
  self->SetClipChildren(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetClipChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSortChildren of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetSortChildren00
static int tolua_UILuaAPI_UIElement_SetSortChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSortChildren'", NULL);
#endif
 {
  self->SetSortChildren(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSortChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseDerivedOpacity of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetUseDerivedOpacity00
static int tolua_UILuaAPI_UIElement_SetUseDerivedOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseDerivedOpacity'", NULL);
#endif
 {
  self->SetUseDerivedOpacity(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseDerivedOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEnabled of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetEnabled00
static int tolua_UILuaAPI_UIElement_SetEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetDeepEnabled of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetDeepEnabled00
static int tolua_UILuaAPI_UIElement_SetDeepEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ResetDeepEnabled of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_ResetDeepEnabled00
static int tolua_UILuaAPI_UIElement_ResetDeepEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetEnabledRecursive of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetEnabledRecursive00
static int tolua_UILuaAPI_UIElement_SetEnabledRecursive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetEditable of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetEditable00
static int tolua_UILuaAPI_UIElement_SetEditable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEditable'", NULL);
#endif
 {
  self->SetEditable(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEditable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFocus of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetFocus00
static int tolua_UILuaAPI_UIElement_SetFocus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFocus'", NULL);
#endif
 {
  self->SetFocus(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFocus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSelected of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetSelected00
static int tolua_UILuaAPI_UIElement_SetSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSelected'", NULL);
#endif
 {
  self->SetSelected(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisible of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetVisible00
static int tolua_UILuaAPI_UIElement_SetVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetFocusMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetFocusMode00
static int tolua_UILuaAPI_UIElement_SetFocusMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  FocusMode mode = ((FocusMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFocusMode'", NULL);
#endif
 {
  self->SetFocusMode(mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFocusMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDragDropMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetDragDropMode00
static int tolua_UILuaAPI_UIElement_SetDragDropMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  unsigned mode = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDragDropMode'", NULL);
#endif
 {
  self->SetDragDropMode(mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDragDropMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetStyle of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetStyle00
static int tolua_UILuaAPI_UIElement_SetStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"XMLFile",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const String styleName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  XMLFile* file = ((XMLFile*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetStyle'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetStyle(styleName,file);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetStyle of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetStyle01
static int tolua_UILuaAPI_UIElement_SetStyle01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const XMLElement",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const XMLElement* element = ((const XMLElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetStyle'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetStyle(*element);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_UILuaAPI_UIElement_SetStyle00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetStyleAuto of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetStyleAuto00
static int tolua_UILuaAPI_UIElement_SetStyleAuto00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"XMLFile",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  XMLFile* file = ((XMLFile*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetStyleAuto'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetStyleAuto(file);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetStyleAuto'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDefaultStyle of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetDefaultStyle00
static int tolua_UILuaAPI_UIElement_SetDefaultStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"XMLFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetLayout of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetLayout00
static int tolua_UILuaAPI_UIElement_SetLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  LayoutMode mode = ((LayoutMode) (int)  tolua_tonumber(tolua_S,2,0));
  int spacing = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLayout'", NULL);
#endif
 {
  self->SetLayout(mode,spacing);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLayout of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetLayout01
static int tolua_UILuaAPI_UIElement_SetLayout01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  LayoutMode mode = ((LayoutMode) (int)  tolua_tonumber(tolua_S,2,0));
  int spacing = ((int)  tolua_tonumber(tolua_S,3,0));
  const IntRect* border = ((const IntRect*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLayout'", NULL);
#endif
 {
  self->SetLayout(mode,spacing,*border);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_UIElement_SetLayout00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLayoutMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetLayoutMode00
static int tolua_UILuaAPI_UIElement_SetLayoutMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  LayoutMode mode = ((LayoutMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLayoutMode'", NULL);
#endif
 {
  self->SetLayoutMode(mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLayoutMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLayoutSpacing of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetLayoutSpacing00
static int tolua_UILuaAPI_UIElement_SetLayoutSpacing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int spacing = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLayoutSpacing'", NULL);
#endif
 {
  self->SetLayoutSpacing(spacing);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLayoutSpacing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLayoutBorder of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetLayoutBorder00
static int tolua_UILuaAPI_UIElement_SetLayoutBorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* border = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLayoutBorder'", NULL);
#endif
 {
  self->SetLayoutBorder(*border);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLayoutBorder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLayoutFlexScale of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetLayoutFlexScale00
static int tolua_UILuaAPI_UIElement_SetLayoutFlexScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* scale = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLayoutFlexScale'", NULL);
#endif
 {
  self->SetLayoutFlexScale(*scale);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLayoutFlexScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIndent of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetIndent00
static int tolua_UILuaAPI_UIElement_SetIndent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int indent = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIndent'", NULL);
#endif
 {
  self->SetIndent(indent);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIndent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIndentSpacing of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetIndentSpacing00
static int tolua_UILuaAPI_UIElement_SetIndentSpacing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  int indentSpacing = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIndentSpacing'", NULL);
#endif
 {
  self->SetIndentSpacing(indentSpacing);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIndentSpacing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateLayout of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_UpdateLayout00
static int tolua_UILuaAPI_UIElement_UpdateLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UpdateLayout'", NULL);
#endif
 {
  self->UpdateLayout();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdateLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DisableLayoutUpdate of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_DisableLayoutUpdate00
static int tolua_UILuaAPI_UIElement_DisableLayoutUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DisableLayoutUpdate'", NULL);
#endif
 {
  self->DisableLayoutUpdate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DisableLayoutUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: EnableLayoutUpdate of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_EnableLayoutUpdate00
static int tolua_UILuaAPI_UIElement_EnableLayoutUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'EnableLayoutUpdate'", NULL);
#endif
 {
  self->EnableLayoutUpdate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EnableLayoutUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BringToFront of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_BringToFront00
static int tolua_UILuaAPI_UIElement_BringToFront00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BringToFront'", NULL);
#endif
 {
  self->BringToFront();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BringToFront'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateChild of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_CreateChild00
static int tolua_UILuaAPI_UIElement_CreateChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const String type = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,3,String::EMPTY));
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,4,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateChild'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->CreateChild(type,name,index);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
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

/* method: AddChild of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_AddChild00
static int tolua_UILuaAPI_UIElement_AddChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  UIElement* element = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddChild'", NULL);
#endif
 {
  self->AddChild(element);
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

/* method: InsertChild of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_InsertChild00
static int tolua_UILuaAPI_UIElement_InsertChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  UIElement* element = ((UIElement*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertChild'", NULL);
#endif
 {
  self->InsertChild(index,element);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveChild of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_RemoveChild00
static int tolua_UILuaAPI_UIElement_RemoveChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  UIElement* element = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveChild'", NULL);
#endif
 {
  self->RemoveChild(element,index);
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

/* method: RemoveChildAtIndex of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_RemoveChildAtIndex00
static int tolua_UILuaAPI_UIElement_RemoveChildAtIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveChildAtIndex'", NULL);
#endif
 {
  self->RemoveChildAtIndex(index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveChildAtIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllChildren of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_RemoveAllChildren00
static int tolua_UILuaAPI_UIElement_RemoveAllChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Remove of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_Remove00
static int tolua_UILuaAPI_UIElement_Remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: FindChild of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_FindChild00
static int tolua_UILuaAPI_UIElement_FindChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
  UIElement* element = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindChild'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->FindChild(element);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetParent of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetParent00
static int tolua_UILuaAPI_UIElement_SetParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  UIElement* parent = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,3,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetParent'", NULL);
#endif
 {
  self->SetParent(parent,index);
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

/* method: SetVar of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetVar00
static int tolua_UILuaAPI_UIElement_SetVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Variant",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetInternal of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetInternal00
static int tolua_UILuaAPI_UIElement_SetInternal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetInternal'", NULL);
#endif
 {
  self->SetInternal(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetInternal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTraversalMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetTraversalMode00
static int tolua_UILuaAPI_UIElement_SetTraversalMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  TraversalMode traversalMode = ((TraversalMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTraversalMode'", NULL);
#endif
 {
  self->SetTraversalMode(traversalMode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTraversalMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetElementEventSender of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetElementEventSender00
static int tolua_UILuaAPI_UIElement_SetElementEventSender00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetElementEventSender'", NULL);
#endif
 {
  self->SetElementEventSender(flag);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetElementEventSender'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddTag of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_AddTag00
static int tolua_UILuaAPI_UIElement_AddTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: AddTags of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_AddTags00
static int tolua_UILuaAPI_UIElement_AddTags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: RemoveTag of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_RemoveTag00
static int tolua_UILuaAPI_UIElement_RemoveTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: RemoveAllTags of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_RemoveAllTags00
static int tolua_UILuaAPI_UIElement_RemoveAllTags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetName of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetName00
static int tolua_UILuaAPI_UIElement_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetPosition of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetPosition00
static int tolua_UILuaAPI_UIElement_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetPosition();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
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

/* method: GetSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetSize00
static int tolua_UILuaAPI_UIElement_GetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSize'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetSize();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
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

/* method: GetWidth of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetWidth00
static int tolua_UILuaAPI_UIElement_GetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetHeight of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetHeight00
static int tolua_UILuaAPI_UIElement_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetMinSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetMinSize00
static int tolua_UILuaAPI_UIElement_GetMinSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMinSize'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetMinSize();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMinSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMinWidth of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetMinWidth00
static int tolua_UILuaAPI_UIElement_GetMinWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMinWidth'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetMinWidth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMinWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMinHeight of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetMinHeight00
static int tolua_UILuaAPI_UIElement_GetMinHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMinHeight'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetMinHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMinHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetMaxSize00
static int tolua_UILuaAPI_UIElement_GetMaxSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxSize'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetMaxSize();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxWidth of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetMaxWidth00
static int tolua_UILuaAPI_UIElement_GetMaxWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxWidth'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetMaxWidth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxHeight of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetMaxHeight00
static int tolua_UILuaAPI_UIElement_GetMaxHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxHeight'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetMaxHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsFixedSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_IsFixedSize00
static int tolua_UILuaAPI_UIElement_IsFixedSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsFixedSize'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsFixedSize();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsFixedSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsFixedWidth of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_IsFixedWidth00
static int tolua_UILuaAPI_UIElement_IsFixedWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsFixedWidth'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsFixedWidth();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsFixedWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsFixedHeight of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_IsFixedHeight00
static int tolua_UILuaAPI_UIElement_IsFixedHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsFixedHeight'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsFixedHeight();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsFixedHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetChildOffset of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetChildOffset00
static int tolua_UILuaAPI_UIElement_GetChildOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChildOffset'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetChildOffset();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetChildOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHorizontalAlignment of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetHorizontalAlignment00
static int tolua_UILuaAPI_UIElement_GetHorizontalAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHorizontalAlignment'", NULL);
#endif
 {
  HorizontalAlignment tolua_ret = (HorizontalAlignment)  self->GetHorizontalAlignment();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHorizontalAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVerticalAlignment of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetVerticalAlignment00
static int tolua_UILuaAPI_UIElement_GetVerticalAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVerticalAlignment'", NULL);
#endif
 {
  VerticalAlignment tolua_ret = (VerticalAlignment)  self->GetVerticalAlignment();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVerticalAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEnableAnchor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetEnableAnchor00
static int tolua_UILuaAPI_UIElement_GetEnableAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEnableAnchor'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetEnableAnchor();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEnableAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMinAnchor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetMinAnchor00
static int tolua_UILuaAPI_UIElement_GetMinAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMinAnchor'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetMinAnchor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMinAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxAnchor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetMaxAnchor00
static int tolua_UILuaAPI_UIElement_GetMaxAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxAnchor'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetMaxAnchor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMinOffset of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetMinOffset00
static int tolua_UILuaAPI_UIElement_GetMinOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMinOffset'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetMinOffset();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMinOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxOffset of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetMaxOffset00
static int tolua_UILuaAPI_UIElement_GetMaxOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxOffset'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetMaxOffset();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPivot of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetPivot00
static int tolua_UILuaAPI_UIElement_GetPivot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPivot'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetPivot();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPivot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetClipBorder of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetClipBorder00
static int tolua_UILuaAPI_UIElement_GetClipBorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClipBorder'", NULL);
#endif
 {
  const IntRect& tolua_ret = (const IntRect&)  self->GetClipBorder();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntRect");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClipBorder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetColor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetColor00
static int tolua_UILuaAPI_UIElement_GetColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
  Corner corner = ((Corner) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetColor'", NULL);
#endif
 {
  const Color& tolua_ret = (const Color&)  self->GetColor(corner);
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

/* method: GetPriority of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetPriority00
static int tolua_UILuaAPI_UIElement_GetPriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPriority'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetPriority();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPriority'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOpacity of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetOpacity00
static int tolua_UILuaAPI_UIElement_GetOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOpacity'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetOpacity();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDerivedOpacity of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetDerivedOpacity00
static int tolua_UILuaAPI_UIElement_GetDerivedOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDerivedOpacity'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDerivedOpacity();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDerivedOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBringToFront of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetBringToFront00
static int tolua_UILuaAPI_UIElement_GetBringToFront00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBringToFront'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetBringToFront();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBringToFront'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBringToBack of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetBringToBack00
static int tolua_UILuaAPI_UIElement_GetBringToBack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBringToBack'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetBringToBack();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBringToBack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetClipChildren of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetClipChildren00
static int tolua_UILuaAPI_UIElement_GetClipChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClipChildren'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetClipChildren();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClipChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSortChildren of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetSortChildren00
static int tolua_UILuaAPI_UIElement_GetSortChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSortChildren'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetSortChildren();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSortChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUseDerivedOpacity of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetUseDerivedOpacity00
static int tolua_UILuaAPI_UIElement_GetUseDerivedOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUseDerivedOpacity'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetUseDerivedOpacity();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUseDerivedOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasFocus of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_HasFocus00
static int tolua_UILuaAPI_UIElement_HasFocus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsEnabled of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_IsEnabled00
static int tolua_UILuaAPI_UIElement_IsEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsEnabledSelf of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_IsEnabledSelf00
static int tolua_UILuaAPI_UIElement_IsEnabledSelf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsEditable of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_IsEditable00
static int tolua_UILuaAPI_UIElement_IsEditable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsEditable'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsEditable();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsEditable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsSelected of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_IsSelected00
static int tolua_UILuaAPI_UIElement_IsSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsSelected'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsSelected();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsVisible of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_IsVisible00
static int tolua_UILuaAPI_UIElement_IsVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsVisibleEffective of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_IsVisibleEffective00
static int tolua_UILuaAPI_UIElement_IsVisibleEffective00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsVisibleEffective'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsVisibleEffective();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsVisibleEffective'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsHovering of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_IsHovering00
static int tolua_UILuaAPI_UIElement_IsHovering00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsHovering'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsHovering();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsHovering'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInternal of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_IsInternal00
static int tolua_UILuaAPI_UIElement_IsInternal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInternal'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsInternal();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInternal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasColorGradient of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_HasColorGradient00
static int tolua_UILuaAPI_UIElement_HasColorGradient00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasColorGradient'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasColorGradient();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasColorGradient'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFocusMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetFocusMode00
static int tolua_UILuaAPI_UIElement_GetFocusMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFocusMode'", NULL);
#endif
 {
  FocusMode tolua_ret = (FocusMode)  self->GetFocusMode();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFocusMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDragDropMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetDragDropMode00
static int tolua_UILuaAPI_UIElement_GetDragDropMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDragDropMode'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetDragDropMode();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDragDropMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAppliedStyle of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetAppliedStyle00
static int tolua_UILuaAPI_UIElement_GetAppliedStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAppliedStyle'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetAppliedStyle();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAppliedStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDefaultStyle of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetDefaultStyle00
static int tolua_UILuaAPI_UIElement_GetDefaultStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
  bool recursiveUp = ((bool)  tolua_toboolean(tolua_S,2,true));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDefaultStyle'", NULL);
#endif
 {
  XMLFile* tolua_ret = (XMLFile*)  self->GetDefaultStyle(recursiveUp);
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

/* method: GetLayoutMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetLayoutMode00
static int tolua_UILuaAPI_UIElement_GetLayoutMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLayoutMode'", NULL);
#endif
 {
  LayoutMode tolua_ret = (LayoutMode)  self->GetLayoutMode();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLayoutMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLayoutSpacing of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetLayoutSpacing00
static int tolua_UILuaAPI_UIElement_GetLayoutSpacing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLayoutSpacing'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetLayoutSpacing();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLayoutSpacing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLayoutBorder of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetLayoutBorder00
static int tolua_UILuaAPI_UIElement_GetLayoutBorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLayoutBorder'", NULL);
#endif
 {
  const IntRect& tolua_ret = (const IntRect&)  self->GetLayoutBorder();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntRect");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLayoutBorder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLayoutFlexScale of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetLayoutFlexScale00
static int tolua_UILuaAPI_UIElement_GetLayoutFlexScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLayoutFlexScale'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetLayoutFlexScale();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLayoutFlexScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumChildren of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetNumChildren00
static int tolua_UILuaAPI_UIElement_GetNumChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetDragButtonCombo of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetDragButtonCombo00
static int tolua_UILuaAPI_UIElement_GetDragButtonCombo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDragButtonCombo'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetDragButtonCombo();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDragButtonCombo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDragButtonCount of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetDragButtonCount00
static int tolua_UILuaAPI_UIElement_GetDragButtonCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDragButtonCount'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetDragButtonCount();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDragButtonCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetChild of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetChild00
static int tolua_UILuaAPI_UIElement_GetChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
  const String name = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChild'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetChild(name,recursive);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
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

/* method: GetChild of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetChild01
static int tolua_UILuaAPI_UIElement_GetChild01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChild'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetChild(index);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
tolua_lerror:
 return tolua_UILuaAPI_UIElement_GetChild00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsChildOf of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_IsChildOf00
static int tolua_UILuaAPI_UIElement_IsChildOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
  UIElement* element = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsChildOf'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsChildOf(element);
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

/* method: GetParent of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetParent00
static int tolua_UILuaAPI_UIElement_GetParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetParent'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetParent();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
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

/* method: GetRoot of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetRoot00
static int tolua_UILuaAPI_UIElement_GetRoot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRoot'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetRoot();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
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

/* method: GetDerivedColor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetDerivedColor00
static int tolua_UILuaAPI_UIElement_GetDerivedColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDerivedColor'", NULL);
#endif
 {
  const Color& tolua_ret = (const Color&)  self->GetDerivedColor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Color");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDerivedColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVar of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetVar00
static int tolua_UILuaAPI_UIElement_GetVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"StringHash",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetVars of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetVars00
static int tolua_UILuaAPI_UIElement_GetVars00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: HasTag of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_HasTag00
static int tolua_UILuaAPI_UIElement_HasTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetTags of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetTags00
static int tolua_UILuaAPI_UIElement_GetTags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* method: UIElementGetChildrenWithTag of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetChildrenWithTag00
static int tolua_UILuaAPI_UIElement_GetChildrenWithTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
  const String tag = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UIElementGetChildrenWithTag'", NULL);
#endif
 {
  tolua_outside  const PODVector<UIElement*>& tolua_ret = (tolua_outside  const PODVector<UIElement*>&)  UIElementGetChildrenWithTag(self,tag,recursive);
  ToluaPushPODVector<UIElement*>("",tolua_S,(void*)&tolua_ret,"UIElement");
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

/* method: ScreenToElement of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_ScreenToElement00
static int tolua_UILuaAPI_UIElement_ScreenToElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* screenPosition = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ScreenToElement'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->ScreenToElement(*screenPosition);
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
 tolua_error(tolua_S,"#ferror in function 'ScreenToElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ElementToScreen of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_ElementToScreen00
static int tolua_UILuaAPI_UIElement_ElementToScreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* position = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ElementToScreen'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->ElementToScreen(*position);
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
 tolua_error(tolua_S,"#ferror in function 'ElementToScreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInside of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_IsInside00
static int tolua_UILuaAPI_UIElement_IsInside00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  IntVector2 position = *((IntVector2*)  tolua_tousertype(tolua_S,2,0));
  bool isScreen = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInside'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsInside(position,isScreen);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInside'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInsideCombined of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_IsInsideCombined00
static int tolua_UILuaAPI_UIElement_IsInsideCombined00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  IntVector2 position = *((IntVector2*)  tolua_tousertype(tolua_S,2,0));
  bool isScreen = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInsideCombined'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsInsideCombined(position,isScreen);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInsideCombined'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCombinedScreenRect of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetCombinedScreenRect00
static int tolua_UILuaAPI_UIElement_GetCombinedScreenRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCombinedScreenRect'", NULL);
#endif
 {
  IntRect tolua_ret = (IntRect)  self->GetCombinedScreenRect();
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
 tolua_error(tolua_S,"#ferror in function 'GetCombinedScreenRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SortChildren of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SortChildren00
static int tolua_UILuaAPI_UIElement_SortChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SortChildren'", NULL);
#endif
 {
  self->SortChildren();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SortChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIndent of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetIndent00
static int tolua_UILuaAPI_UIElement_GetIndent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIndent'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetIndent();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIndent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIndentSpacing of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetIndentSpacing00
static int tolua_UILuaAPI_UIElement_GetIndentSpacing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIndentSpacing'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetIndentSpacing();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIndentSpacing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIndentWidth of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetIndentWidth00
static int tolua_UILuaAPI_UIElement_GetIndentWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIndentWidth'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetIndentWidth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIndentWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetChildOffset of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetChildOffset00
static int tolua_UILuaAPI_UIElement_SetChildOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* offset = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetChildOffset'", NULL);
#endif
 {
  self->SetChildOffset(*offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetChildOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHovering of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_SetHovering00
static int tolua_UILuaAPI_UIElement_SetHovering00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHovering'", NULL);
#endif
 {
  self->SetHovering(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHovering'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetColorAttr of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetColor01
static int tolua_UILuaAPI_UIElement_GetColor01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetColorAttr'", NULL);
#endif
 {
  const Color& tolua_ret = (const Color&)  self->GetColorAttr();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Color");
 }
 }
 return 1;
tolua_lerror:
 return tolua_UILuaAPI_UIElement_GetColor00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTraversalMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetTraversalMode00
static int tolua_UILuaAPI_UIElement_GetTraversalMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTraversalMode'", NULL);
#endif
 {
  TraversalMode tolua_ret = (TraversalMode)  self->GetTraversalMode();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTraversalMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsElementEventSender of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_IsElementEventSender00
static int tolua_UILuaAPI_UIElement_IsElementEventSender00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsElementEventSender'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsElementEventSender();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsElementEventSender'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetElementEventSender of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIElement_GetElementEventSender00
static int tolua_UILuaAPI_UIElement_GetElementEventSender00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIElement* self = (const UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetElementEventSender'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetElementEventSender();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetElementEventSender'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: screenPosition of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_screenPosition_ref
static int tolua_get_UIElement_screenPosition_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'screenPosition'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetScreenPosition(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_name
static int tolua_get_UIElement_name(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_name
static int tolua_set_UIElement_name(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: position of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_position_ref
static int tolua_get_UIElement_position_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetPosition(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: position of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_position_ref
static int tolua_set_UIElement_position_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPosition((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: size of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_size
static int tolua_get_UIElement_size(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
#endif
 IntVector2 tolua_ret = (IntVector2)self->GetSize();
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

/* set function: size of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_size
static int tolua_set_UIElement_size(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSize(*((IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_width
static int tolua_get_UIElement_width(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetWidth());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_width
static int tolua_set_UIElement_width(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetWidth(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_height
static int tolua_get_UIElement_height(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetHeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_height
static int tolua_set_UIElement_height(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetHeight(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: minSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_minSize
static int tolua_get_UIElement_minSize(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minSize'",NULL);
#endif
 IntVector2 tolua_ret = (IntVector2)self->GetMinSize();
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

/* set function: minSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_minSize
static int tolua_set_UIElement_minSize(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minSize'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMinSize(*((IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: minWidth of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_minWidth
static int tolua_get_UIElement_minWidth(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minWidth'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMinWidth());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: minWidth of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_minWidth
static int tolua_set_UIElement_minWidth(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minWidth'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMinWidth(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: minHeight of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_minHeight
static int tolua_get_UIElement_minHeight(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minHeight'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMinHeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: minHeight of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_minHeight
static int tolua_set_UIElement_minHeight(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minHeight'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMinHeight(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_maxSize
static int tolua_get_UIElement_maxSize(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxSize'",NULL);
#endif
 IntVector2 tolua_ret = (IntVector2)self->GetMaxSize();
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

/* set function: maxSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_maxSize
static int tolua_set_UIElement_maxSize(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxSize'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxSize(*((IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxWidth of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_maxWidth
static int tolua_get_UIElement_maxWidth(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxWidth'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxWidth());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxWidth of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_maxWidth
static int tolua_set_UIElement_maxWidth(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxWidth'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxWidth(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxHeight of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_maxHeight
static int tolua_get_UIElement_maxHeight(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxHeight'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxHeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxHeight of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_maxHeight
static int tolua_set_UIElement_maxHeight(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxHeight'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxHeight(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fixedSize of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_fixedSize
static int tolua_get_UIElement_fixedSize(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fixedSize'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsFixedSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fixedWidth of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_fixedWidth
static int tolua_get_UIElement_fixedWidth(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fixedWidth'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsFixedWidth());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fixedHeight of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_fixedHeight
static int tolua_get_UIElement_fixedHeight(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fixedHeight'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsFixedHeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: childOffset of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_childOffset_ref
static int tolua_get_UIElement_childOffset_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'childOffset'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetChildOffset(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: childOffset of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_childOffset_ref
static int tolua_set_UIElement_childOffset_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'childOffset'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetChildOffset((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: horizontalAlignment of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_horizontalAlignment
static int tolua_get_UIElement_horizontalAlignment(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'horizontalAlignment'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetHorizontalAlignment());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: horizontalAlignment of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_horizontalAlignment
static int tolua_set_UIElement_horizontalAlignment(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'horizontalAlignment'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetHorizontalAlignment(((HorizontalAlignment) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: verticalAlignment of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_verticalAlignment
static int tolua_get_UIElement_verticalAlignment(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'verticalAlignment'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetVerticalAlignment());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: verticalAlignment of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_verticalAlignment
static int tolua_set_UIElement_verticalAlignment(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'verticalAlignment'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetVerticalAlignment(((VerticalAlignment) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: enableAnchor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_enableAnchor
static int tolua_get_UIElement_enableAnchor(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enableAnchor'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetEnableAnchor());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: enableAnchor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_enableAnchor
static int tolua_set_UIElement_enableAnchor(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enableAnchor'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEnableAnchor(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: minOffset of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_minOffset_ref
static int tolua_get_UIElement_minOffset_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minOffset'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetMinOffset(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: minOffset of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_minOffset_ref
static int tolua_set_UIElement_minOffset_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minOffset'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMinOffset((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxOffset of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_maxOffset_ref
static int tolua_get_UIElement_maxOffset_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxOffset'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetMaxOffset(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxOffset of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_maxOffset_ref
static int tolua_set_UIElement_maxOffset_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxOffset'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxOffset((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: minAnchor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_minAnchor_ref
static int tolua_get_UIElement_minAnchor_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minAnchor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetMinAnchor(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: minAnchor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_minAnchor_ref
static int tolua_set_UIElement_minAnchor_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'minAnchor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMinAnchor((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxAnchor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_maxAnchor_ref
static int tolua_get_UIElement_maxAnchor_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxAnchor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetMaxAnchor(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxAnchor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_maxAnchor_ref
static int tolua_set_UIElement_maxAnchor_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxAnchor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxAnchor((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pivot of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_pivot_ref
static int tolua_get_UIElement_pivot_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pivot'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetPivot(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pivot of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_pivot_ref
static int tolua_set_UIElement_pivot_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pivot'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPivot((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: clipBorder of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_clipBorder
static int tolua_get_UIElement_clipBorder(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'clipBorder'",NULL);
#endif
 IntRect tolua_ret = (IntRect)self->GetClipBorder();
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

/* set function: clipBorder of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_clipBorder
static int tolua_set_UIElement_clipBorder(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'clipBorder'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntRect",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetClipBorder(*((IntRect*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: colorAttr of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_color_ref
static int tolua_get_UIElement_color_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'colorAttr'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetColorAttr(),"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: colorAttr of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_color_ref
static int tolua_set_UIElement_color_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'colorAttr'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetColorAttr((*(Color*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: priority of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_priority
static int tolua_get_UIElement_priority(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'priority'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetPriority());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: priority of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_priority
static int tolua_set_UIElement_priority(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'priority'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPriority(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: opacity of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_opacity
static int tolua_get_UIElement_opacity(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'opacity'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetOpacity());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: opacity of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_opacity
static int tolua_set_UIElement_opacity(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'opacity'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOpacity(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: derivedOpacity of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_derivedOpacity
static int tolua_get_UIElement_derivedOpacity(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'derivedOpacity'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDerivedOpacity());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bringToFront of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_bringToFront
static int tolua_get_UIElement_bringToFront(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bringToFront'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetBringToFront());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bringToFront of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_bringToFront
static int tolua_set_UIElement_bringToFront(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bringToFront'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetBringToFront(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bringToBack of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_bringToBack
static int tolua_get_UIElement_bringToBack(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bringToBack'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetBringToBack());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bringToBack of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_bringToBack
static int tolua_set_UIElement_bringToBack(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bringToBack'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetBringToBack(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: clipChildren of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_clipChildren
static int tolua_get_UIElement_clipChildren(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'clipChildren'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetClipChildren());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: clipChildren of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_clipChildren
static int tolua_set_UIElement_clipChildren(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'clipChildren'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetClipChildren(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sortChildren of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_sortChildren
static int tolua_get_UIElement_sortChildren(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sortChildren'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetSortChildren());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sortChildren of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_sortChildren
static int tolua_set_UIElement_sortChildren(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sortChildren'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSortChildren(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: useDerivedOpacity of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_useDerivedOpacity
static int tolua_get_UIElement_useDerivedOpacity(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useDerivedOpacity'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetUseDerivedOpacity());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: useDerivedOpacity of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_useDerivedOpacity
static int tolua_set_UIElement_useDerivedOpacity(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useDerivedOpacity'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUseDerivedOpacity(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: focus of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_focus
static int tolua_get_UIElement_focus(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'focus'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->HasFocus());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: focus of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_focus
static int tolua_set_UIElement_focus(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'focus'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFocus(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: enabled of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_enabled
static int tolua_get_UIElement_enabled(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enabled'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsEnabled());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: enabled of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_enabled
static int tolua_set_UIElement_enabled(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: enabledSelf of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_enabledSelf
static int tolua_get_UIElement_enabledSelf(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'enabledSelf'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsEnabledSelf());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: editable of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_editable
static int tolua_get_UIElement_editable(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'editable'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsEditable());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: editable of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_editable
static int tolua_set_UIElement_editable(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'editable'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEditable(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: selected of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_selected
static int tolua_get_UIElement_selected(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'selected'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsSelected());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: selected of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_selected
static int tolua_set_UIElement_selected(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'selected'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSelected(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: visible of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_visible
static int tolua_get_UIElement_visible(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'visible'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsVisible());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: visible of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_visible
static int tolua_set_UIElement_visible(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: visibleEffective of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_visibleEffective
static int tolua_get_UIElement_visibleEffective(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'visibleEffective'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsVisibleEffective());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: hovering of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_hovering
static int tolua_get_UIElement_hovering(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hovering'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsHovering());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: hovering of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_hovering
static int tolua_set_UIElement_hovering(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hovering'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetHovering(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: internal of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_internal
static int tolua_get_UIElement_internal(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'internal'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsInternal());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: internal of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_internal
static int tolua_set_UIElement_internal(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'internal'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetInternal(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: colorGradient of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_colorGradient
static int tolua_get_UIElement_colorGradient(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'colorGradient'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->HasColorGradient());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: focusMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_focusMode
static int tolua_get_UIElement_focusMode(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'focusMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFocusMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: focusMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_focusMode
static int tolua_set_UIElement_focusMode(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'focusMode'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFocusMode(((FocusMode) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dragDropMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_dragDropMode
static int tolua_get_UIElement_dragDropMode(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dragDropMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDragDropMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dragDropMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_dragDropMode
static int tolua_set_UIElement_dragDropMode(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dragDropMode'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDragDropMode(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: style of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_style
static int tolua_get_UIElement_style(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'style'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetStyle());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: style of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_style
static int tolua_set_UIElement_style(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'style'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetStyle(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: defaultStyle of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_defaultStyle_ptr
static int tolua_get_UIElement_defaultStyle_ptr(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'defaultStyle'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetDefaultStyle(),"XMLFile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: defaultStyle of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_defaultStyle_ptr
static int tolua_set_UIElement_defaultStyle_ptr(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: layoutMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_layoutMode
static int tolua_get_UIElement_layoutMode(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layoutMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLayoutMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: layoutMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_layoutMode
static int tolua_set_UIElement_layoutMode(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layoutMode'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLayoutMode(((LayoutMode) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: layoutSpacing of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_layoutSpacing
static int tolua_get_UIElement_layoutSpacing(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layoutSpacing'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetLayoutSpacing());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: layoutSpacing of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_layoutSpacing
static int tolua_set_UIElement_layoutSpacing(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layoutSpacing'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLayoutSpacing(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: layoutBorder of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_layoutBorder_ref
static int tolua_get_UIElement_layoutBorder_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layoutBorder'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetLayoutBorder(),"IntRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: layoutBorder of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_layoutBorder_ref
static int tolua_set_UIElement_layoutBorder_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layoutBorder'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntRect",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLayoutBorder((*(IntRect*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: layoutFlexScale of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_layoutFlexScale_ref
static int tolua_get_UIElement_layoutFlexScale_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layoutFlexScale'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetLayoutFlexScale(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: layoutFlexScale of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_layoutFlexScale_ref
static int tolua_set_UIElement_layoutFlexScale_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'layoutFlexScale'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetLayoutFlexScale((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numChildren of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_numChildren
static int tolua_get_UIElement_numChildren(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numChildren'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumChildren());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: parent of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_parent_ptr
static int tolua_get_UIElement_parent_ptr(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
#endif
  ToluaPushObject(tolua_S,(void*)self->GetParent(),"UIElement");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: parent of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_parent_ptr
static int tolua_set_UIElement_parent_ptr(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
 if (!tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetParent(((UIElement*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: root of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_root_ptr
static int tolua_get_UIElement_root_ptr(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'root'",NULL);
#endif
  ToluaPushObject(tolua_S,(void*)self->GetRoot(),"UIElement");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: derivedColor of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_derivedColor_ref
static int tolua_get_UIElement_derivedColor_ref(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'derivedColor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetDerivedColor(),"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: combinedScreenRect of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_combinedScreenRect
static int tolua_get_UIElement_combinedScreenRect(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'combinedScreenRect'",NULL);
#endif
 IntRect tolua_ret = (IntRect)self->GetCombinedScreenRect();
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

/* get function: indent of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_indent
static int tolua_get_UIElement_indent(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'indent'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetIndent());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: indent of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_indent
static int tolua_set_UIElement_indent(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'indent'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetIndent(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: indentSpacing of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_indentSpacing
static int tolua_get_UIElement_indentSpacing(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'indentSpacing'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetIndentSpacing());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: indentSpacing of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_indentSpacing
static int tolua_set_UIElement_indentSpacing(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'indentSpacing'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetIndentSpacing(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: indentWidth of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_indentWidth
static int tolua_get_UIElement_indentWidth(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'indentWidth'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetIndentWidth());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: traversalMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_traversalMode
static int tolua_get_UIElement_traversalMode(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'traversalMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTraversalMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: traversalMode of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_traversalMode
static int tolua_set_UIElement_traversalMode(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'traversalMode'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTraversalMode(((TraversalMode) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: elementEventSender of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_get_UIElement_elementEventSender
static int tolua_get_UIElement_elementEventSender(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'elementEventSender'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsElementEventSender());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: elementEventSender of class  UIElement */
#ifndef TOLUA_DISABLE_tolua_set_UIElement_elementEventSender
static int tolua_set_UIElement_elementEventSender(lua_State* tolua_S)
{
  UIElement* self = (UIElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'elementEventSender'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetElementEventSender(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  UISelectable */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UISelectable_new00
static int tolua_UILuaAPI_UISelectable_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"UISelectable",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  UISelectable* tolua_ret = (UISelectable*)  Mtolua_new((UISelectable)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"UISelectable");
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

/* method: new_local of class  UISelectable */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UISelectable_new00_local
static int tolua_UILuaAPI_UISelectable_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"UISelectable",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  UISelectable* tolua_ret = (UISelectable*)  Mtolua_new((UISelectable)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"UISelectable");
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

/* method: delete of class  UISelectable */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UISelectable_delete00
static int tolua_UILuaAPI_UISelectable_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UISelectable",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UISelectable* self = (UISelectable*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetSelectionColor of class  UISelectable */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UISelectable_SetSelectionColor00
static int tolua_UILuaAPI_UISelectable_SetSelectionColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UISelectable",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UISelectable* self = (UISelectable*)  tolua_tousertype(tolua_S,1,0);
  const Color* color = ((const Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSelectionColor'", NULL);
#endif
 {
  self->SetSelectionColor(*color);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSelectionColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHoverColor of class  UISelectable */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UISelectable_SetHoverColor00
static int tolua_UILuaAPI_UISelectable_SetHoverColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UISelectable",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UISelectable* self = (UISelectable*)  tolua_tousertype(tolua_S,1,0);
  const Color* color = ((const Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHoverColor'", NULL);
#endif
 {
  self->SetHoverColor(*color);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHoverColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSelectionColor of class  UISelectable */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UISelectable_GetSelectionColor00
static int tolua_UILuaAPI_UISelectable_GetSelectionColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UISelectable",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UISelectable* self = (const UISelectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSelectionColor'", NULL);
#endif
 {
  const Color& tolua_ret = (const Color&)  self->GetSelectionColor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Color");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelectionColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHoverColor of class  UISelectable */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UISelectable_GetHoverColor00
static int tolua_UILuaAPI_UISelectable_GetHoverColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UISelectable",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UISelectable* self = (const UISelectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHoverColor'", NULL);
#endif
 {
  const Color& tolua_ret = (const Color&)  self->GetHoverColor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Color");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHoverColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: selectionColor of class  UISelectable */
#ifndef TOLUA_DISABLE_tolua_get_UISelectable_selectionColor_ref
static int tolua_get_UISelectable_selectionColor_ref(lua_State* tolua_S)
{
  UISelectable* self = (UISelectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'selectionColor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetSelectionColor(),"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: selectionColor of class  UISelectable */
#ifndef TOLUA_DISABLE_tolua_set_UISelectable_selectionColor_ref
static int tolua_set_UISelectable_selectionColor_ref(lua_State* tolua_S)
{
  UISelectable* self = (UISelectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'selectionColor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSelectionColor((*(Color*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: hoverColor of class  UISelectable */
#ifndef TOLUA_DISABLE_tolua_get_UISelectable_hoverColor_ref
static int tolua_get_UISelectable_hoverColor_ref(lua_State* tolua_S)
{
  UISelectable* self = (UISelectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hoverColor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetHoverColor(),"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: hoverColor of class  UISelectable */
#ifndef TOLUA_DISABLE_tolua_set_UISelectable_hoverColor_ref
static int tolua_set_UISelectable_hoverColor_ref(lua_State* tolua_S)
{
  UISelectable* self = (UISelectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hoverColor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetHoverColor((*(Color*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_new00
static int tolua_UILuaAPI_BorderImage_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BorderImage",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  BorderImage* tolua_ret = (BorderImage*)  Mtolua_new((BorderImage)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BorderImage");
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

/* method: new_local of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_new00_local
static int tolua_UILuaAPI_BorderImage_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BorderImage",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  BorderImage* tolua_ret = (BorderImage*)  Mtolua_new((BorderImage)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BorderImage");
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

/* method: delete of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_delete00
static int tolua_UILuaAPI_BorderImage_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BorderImage",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetTexture of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_SetTexture00
static int tolua_UILuaAPI_BorderImage_SetTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BorderImage",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Texture",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
  Texture* texture = ((Texture*)  tolua_tousertype(tolua_S,2,0));
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

/* method: SetImageRect of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_SetImageRect00
static int tolua_UILuaAPI_BorderImage_SetImageRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BorderImage",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* rect = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetImageRect'", NULL);
#endif
 {
  self->SetImageRect(*rect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetImageRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFullImageRect of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_SetFullImageRect00
static int tolua_UILuaAPI_BorderImage_SetFullImageRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BorderImage",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFullImageRect'", NULL);
#endif
 {
  self->SetFullImageRect();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFullImageRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBorder of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_SetBorder00
static int tolua_UILuaAPI_BorderImage_SetBorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BorderImage",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* rect = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBorder'", NULL);
#endif
 {
  self->SetBorder(*rect);
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

/* method: SetImageBorder of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_SetImageBorder00
static int tolua_UILuaAPI_BorderImage_SetImageBorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BorderImage",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* rect = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetImageBorder'", NULL);
#endif
 {
  self->SetImageBorder(*rect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetImageBorder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHoverOffset of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_SetHoverOffset00
static int tolua_UILuaAPI_BorderImage_SetHoverOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BorderImage",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* offset = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHoverOffset'", NULL);
#endif
 {
  self->SetHoverOffset(*offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHoverOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHoverOffset of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_SetHoverOffset01
static int tolua_UILuaAPI_BorderImage_SetHoverOffset01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BorderImage",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHoverOffset'", NULL);
#endif
 {
  self->SetHoverOffset(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_BorderImage_SetHoverOffset00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBlendMode of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_SetBlendMode00
static int tolua_UILuaAPI_BorderImage_SetBlendMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BorderImage",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetTiled of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_SetTiled00
static int tolua_UILuaAPI_BorderImage_SetTiled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BorderImage",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTiled'", NULL);
#endif
 {
  self->SetTiled(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTiled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTexture of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_GetTexture00
static int tolua_UILuaAPI_BorderImage_GetTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BorderImage",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BorderImage* self = (const BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTexture'", NULL);
#endif
 {
  Texture* tolua_ret = (Texture*)  self->GetTexture();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture");
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

/* method: GetImageRect of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_GetImageRect00
static int tolua_UILuaAPI_BorderImage_GetImageRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BorderImage",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BorderImage* self = (const BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetImageRect'", NULL);
#endif
 {
  const IntRect& tolua_ret = (const IntRect&)  self->GetImageRect();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntRect");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetImageRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBorder of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_GetBorder00
static int tolua_UILuaAPI_BorderImage_GetBorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BorderImage",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BorderImage* self = (const BorderImage*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetImageBorder of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_GetImageBorder00
static int tolua_UILuaAPI_BorderImage_GetImageBorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BorderImage",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BorderImage* self = (const BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetImageBorder'", NULL);
#endif
 {
  const IntRect& tolua_ret = (const IntRect&)  self->GetImageBorder();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntRect");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetImageBorder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHoverOffset of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_GetHoverOffset00
static int tolua_UILuaAPI_BorderImage_GetHoverOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BorderImage",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BorderImage* self = (const BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHoverOffset'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetHoverOffset();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHoverOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBlendMode of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_GetBlendMode00
static int tolua_UILuaAPI_BorderImage_GetBlendMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BorderImage",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BorderImage* self = (const BorderImage*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsTiled of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_BorderImage_IsTiled00
static int tolua_UILuaAPI_BorderImage_IsTiled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const BorderImage",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const BorderImage* self = (const BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsTiled'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsTiled();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsTiled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: texture of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_get_BorderImage_texture_ptr
static int tolua_get_BorderImage_texture_ptr(lua_State* tolua_S)
{
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texture'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetTexture(),"Texture");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: texture of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_set_BorderImage_texture_ptr
static int tolua_set_BorderImage_texture_ptr(lua_State* tolua_S)
{
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texture'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Texture",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTexture(((Texture*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: imageRect of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_get_BorderImage_imageRect_ref
static int tolua_get_BorderImage_imageRect_ref(lua_State* tolua_S)
{
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageRect'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetImageRect(),"IntRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: imageRect of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_set_BorderImage_imageRect_ref
static int tolua_set_BorderImage_imageRect_ref(lua_State* tolua_S)
{
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageRect'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntRect",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetImageRect((*(IntRect*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: border of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_get_BorderImage_border_ref
static int tolua_get_BorderImage_border_ref(lua_State* tolua_S)
{
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'border'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetBorder(),"IntRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: border of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_set_BorderImage_border_ref
static int tolua_set_BorderImage_border_ref(lua_State* tolua_S)
{
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'border'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntRect",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetBorder((*(IntRect*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: imageBorder of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_get_BorderImage_imageBorder_ref
static int tolua_get_BorderImage_imageBorder_ref(lua_State* tolua_S)
{
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageBorder'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetImageBorder(),"IntRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: imageBorder of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_set_BorderImage_imageBorder_ref
static int tolua_set_BorderImage_imageBorder_ref(lua_State* tolua_S)
{
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageBorder'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntRect",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetImageBorder((*(IntRect*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: hoverOffset of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_get_BorderImage_hoverOffset_ref
static int tolua_get_BorderImage_hoverOffset_ref(lua_State* tolua_S)
{
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hoverOffset'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetHoverOffset(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: hoverOffset of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_set_BorderImage_hoverOffset_ref
static int tolua_set_BorderImage_hoverOffset_ref(lua_State* tolua_S)
{
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hoverOffset'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetHoverOffset((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: blendMode of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_get_BorderImage_blendMode
static int tolua_get_BorderImage_blendMode(lua_State* tolua_S)
{
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blendMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetBlendMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: blendMode of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_set_BorderImage_blendMode
static int tolua_set_BorderImage_blendMode(lua_State* tolua_S)
{
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: tiled of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_get_BorderImage_tiled
static int tolua_get_BorderImage_tiled(lua_State* tolua_S)
{
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tiled'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsTiled());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tiled of class  BorderImage */
#ifndef TOLUA_DISABLE_tolua_set_BorderImage_tiled
static int tolua_set_BorderImage_tiled(lua_State* tolua_S)
{
  BorderImage* self = (BorderImage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tiled'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTiled(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_new00
static int tolua_UILuaAPI_Button_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Button",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Button* tolua_ret = (Button*)  Mtolua_new((Button)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Button");
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

/* method: new_local of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_new00_local
static int tolua_UILuaAPI_Button_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Button",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Button* tolua_ret = (Button*)  Mtolua_new((Button)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Button");
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

/* method: delete of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_delete00
static int tolua_UILuaAPI_Button_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetPressedOffset of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_SetPressedOffset00
static int tolua_UILuaAPI_Button_SetPressedOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* offset = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPressedOffset'", NULL);
#endif
 {
  self->SetPressedOffset(*offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPressedOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPressedOffset of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_SetPressedOffset01
static int tolua_UILuaAPI_Button_SetPressedOffset01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPressedOffset'", NULL);
#endif
 {
  self->SetPressedOffset(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_Button_SetPressedOffset00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDisabledOffset of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_SetDisabledOffset00
static int tolua_UILuaAPI_Button_SetDisabledOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* offset = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDisabledOffset'", NULL);
#endif
 {
  self->SetDisabledOffset(*offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDisabledOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDisabledOffset of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_SetDisabledOffset01
static int tolua_UILuaAPI_Button_SetDisabledOffset01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDisabledOffset'", NULL);
#endif
 {
  self->SetDisabledOffset(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_Button_SetDisabledOffset00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPressedChildOffset of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_SetPressedChildOffset00
static int tolua_UILuaAPI_Button_SetPressedChildOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* offset = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPressedChildOffset'", NULL);
#endif
 {
  self->SetPressedChildOffset(*offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPressedChildOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPressedChildOffset of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_SetPressedChildOffset01
static int tolua_UILuaAPI_Button_SetPressedChildOffset01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPressedChildOffset'", NULL);
#endif
 {
  self->SetPressedChildOffset(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_Button_SetPressedChildOffset00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRepeat of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_SetRepeat00
static int tolua_UILuaAPI_Button_SetRepeat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
  float delay = ((float)  tolua_tonumber(tolua_S,2,0));
  float rate = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRepeat'", NULL);
#endif
 {
  self->SetRepeat(delay,rate);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRepeat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRepeatDelay of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_SetRepeatDelay00
static int tolua_UILuaAPI_Button_SetRepeatDelay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
  float delay = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRepeatDelay'", NULL);
#endif
 {
  self->SetRepeatDelay(delay);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRepeatDelay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRepeatRate of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_SetRepeatRate00
static int tolua_UILuaAPI_Button_SetRepeatRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRepeatRate'", NULL);
#endif
 {
  self->SetRepeatRate(rate);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRepeatRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPressedOffset of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_GetPressedOffset00
static int tolua_UILuaAPI_Button_GetPressedOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Button",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Button* self = (const Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPressedOffset'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetPressedOffset();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPressedOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDisabledOffset of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_GetDisabledOffset00
static int tolua_UILuaAPI_Button_GetDisabledOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Button",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Button* self = (const Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDisabledOffset'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetDisabledOffset();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDisabledOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPressedChildOffset of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_GetPressedChildOffset00
static int tolua_UILuaAPI_Button_GetPressedChildOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Button",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Button* self = (const Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPressedChildOffset'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetPressedChildOffset();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPressedChildOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRepeatDelay of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_GetRepeatDelay00
static int tolua_UILuaAPI_Button_GetRepeatDelay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Button",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Button* self = (const Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRepeatDelay'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRepeatDelay();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRepeatDelay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRepeatRate of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_GetRepeatRate00
static int tolua_UILuaAPI_Button_GetRepeatRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Button",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Button* self = (const Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRepeatRate'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRepeatRate();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRepeatRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsPressed of class  Button */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Button_IsPressed00
static int tolua_UILuaAPI_Button_IsPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Button",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Button* self = (const Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsPressed'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsPressed();
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

/* get function: pressedOffset of class  Button */
#ifndef TOLUA_DISABLE_tolua_get_Button_pressedOffset_ref
static int tolua_get_Button_pressedOffset_ref(lua_State* tolua_S)
{
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pressedOffset'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetPressedOffset(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pressedOffset of class  Button */
#ifndef TOLUA_DISABLE_tolua_set_Button_pressedOffset_ref
static int tolua_set_Button_pressedOffset_ref(lua_State* tolua_S)
{
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pressedOffset'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPressedOffset((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: disabledOffset of class  Button */
#ifndef TOLUA_DISABLE_tolua_get_Button_disabledOffset_ref
static int tolua_get_Button_disabledOffset_ref(lua_State* tolua_S)
{
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'disabledOffset'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetDisabledOffset(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: disabledOffset of class  Button */
#ifndef TOLUA_DISABLE_tolua_set_Button_disabledOffset_ref
static int tolua_set_Button_disabledOffset_ref(lua_State* tolua_S)
{
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'disabledOffset'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDisabledOffset((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pressedChildOffset of class  Button */
#ifndef TOLUA_DISABLE_tolua_get_Button_pressedChildOffset_ref
static int tolua_get_Button_pressedChildOffset_ref(lua_State* tolua_S)
{
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pressedChildOffset'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetPressedChildOffset(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pressedChildOffset of class  Button */
#ifndef TOLUA_DISABLE_tolua_set_Button_pressedChildOffset_ref
static int tolua_set_Button_pressedChildOffset_ref(lua_State* tolua_S)
{
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pressedChildOffset'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPressedChildOffset((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: repeatDelay of class  Button */
#ifndef TOLUA_DISABLE_tolua_get_Button_repeatDelay
static int tolua_get_Button_repeatDelay(lua_State* tolua_S)
{
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'repeatDelay'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRepeatDelay());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: repeatDelay of class  Button */
#ifndef TOLUA_DISABLE_tolua_set_Button_repeatDelay
static int tolua_set_Button_repeatDelay(lua_State* tolua_S)
{
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'repeatDelay'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRepeatDelay(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: repeatRate of class  Button */
#ifndef TOLUA_DISABLE_tolua_get_Button_repeatRate
static int tolua_get_Button_repeatRate(lua_State* tolua_S)
{
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'repeatRate'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRepeatRate());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: repeatRate of class  Button */
#ifndef TOLUA_DISABLE_tolua_set_Button_repeatRate
static int tolua_set_Button_repeatRate(lua_State* tolua_S)
{
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'repeatRate'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRepeatRate(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pressed of class  Button */
#ifndef TOLUA_DISABLE_tolua_get_Button_pressed
static int tolua_get_Button_pressed(lua_State* tolua_S)
{
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pressed'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsPressed());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CheckBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_CheckBox_new00
static int tolua_UILuaAPI_CheckBox_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CheckBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  CheckBox* tolua_ret = (CheckBox*)  Mtolua_new((CheckBox)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CheckBox");
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

/* method: new_local of class  CheckBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_CheckBox_new00_local
static int tolua_UILuaAPI_CheckBox_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CheckBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  CheckBox* tolua_ret = (CheckBox*)  Mtolua_new((CheckBox)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CheckBox");
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

/* method: delete of class  CheckBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_CheckBox_delete00
static int tolua_UILuaAPI_CheckBox_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CheckBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CheckBox* self = (CheckBox*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetChecked of class  CheckBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_CheckBox_SetChecked00
static int tolua_UILuaAPI_CheckBox_SetChecked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CheckBox",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CheckBox* self = (CheckBox*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetChecked'", NULL);
#endif
 {
  self->SetChecked(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetChecked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCheckedOffset of class  CheckBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_CheckBox_SetCheckedOffset00
static int tolua_UILuaAPI_CheckBox_SetCheckedOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CheckBox",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CheckBox* self = (CheckBox*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* rect = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCheckedOffset'", NULL);
#endif
 {
  self->SetCheckedOffset(*rect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCheckedOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCheckedOffset of class  CheckBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_CheckBox_SetCheckedOffset01
static int tolua_UILuaAPI_CheckBox_SetCheckedOffset01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CheckBox",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CheckBox* self = (CheckBox*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCheckedOffset'", NULL);
#endif
 {
  self->SetCheckedOffset(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_CheckBox_SetCheckedOffset00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsChecked of class  CheckBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_CheckBox_IsChecked00
static int tolua_UILuaAPI_CheckBox_IsChecked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CheckBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CheckBox* self = (const CheckBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsChecked'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsChecked();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsChecked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCheckedOffset of class  CheckBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_CheckBox_GetCheckedOffset00
static int tolua_UILuaAPI_CheckBox_GetCheckedOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const CheckBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const CheckBox* self = (const CheckBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCheckedOffset'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetCheckedOffset();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCheckedOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: checked of class  CheckBox */
#ifndef TOLUA_DISABLE_tolua_get_CheckBox_checked
static int tolua_get_CheckBox_checked(lua_State* tolua_S)
{
  CheckBox* self = (CheckBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'checked'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsChecked());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: checked of class  CheckBox */
#ifndef TOLUA_DISABLE_tolua_set_CheckBox_checked
static int tolua_set_CheckBox_checked(lua_State* tolua_S)
{
  CheckBox* self = (CheckBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'checked'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetChecked(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: checkedOffset of class  CheckBox */
#ifndef TOLUA_DISABLE_tolua_get_CheckBox_checkedOffset_ref
static int tolua_get_CheckBox_checkedOffset_ref(lua_State* tolua_S)
{
  CheckBox* self = (CheckBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'checkedOffset'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetCheckedOffset(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: checkedOffset of class  CheckBox */
#ifndef TOLUA_DISABLE_tolua_set_CheckBox_checkedOffset_ref
static int tolua_set_CheckBox_checkedOffset_ref(lua_State* tolua_S)
{
  CheckBox* self = (CheckBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'checkedOffset'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCheckedOffset((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Cursor */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Cursor_new00
static int tolua_UILuaAPI_Cursor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Cursor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Cursor* tolua_ret = (Cursor*)  Mtolua_new((Cursor)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Cursor");
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

/* method: new_local of class  Cursor */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Cursor_new00_local
static int tolua_UILuaAPI_Cursor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Cursor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Cursor* tolua_ret = (Cursor*)  Mtolua_new((Cursor)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Cursor");
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

/* method: delete of class  Cursor */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Cursor_delete00
static int tolua_UILuaAPI_Cursor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Cursor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Cursor* self = (Cursor*)  tolua_tousertype(tolua_S,1,0);
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

/* method: DefineShape of class  Cursor */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Cursor_DefineShape00
static int tolua_UILuaAPI_Cursor_DefineShape00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Cursor",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"Image",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const IntRect",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Cursor* self = (Cursor*)  tolua_tousertype(tolua_S,1,0);
  const String shape = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  Image* image = ((Image*)  tolua_tousertype(tolua_S,3,0));
  const IntRect* imageRect = ((const IntRect*)  tolua_tousertype(tolua_S,4,0));
  const IntVector2* hotSpot = ((const IntVector2*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DefineShape'", NULL);
#endif
 {
  self->DefineShape(shape,image,*imageRect,*hotSpot);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DefineShape'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DefineShape of class  Cursor */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Cursor_DefineShape01
static int tolua_UILuaAPI_Cursor_DefineShape01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Cursor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"Image",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const IntRect",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Cursor* self = (Cursor*)  tolua_tousertype(tolua_S,1,0);
  CursorShape shape = ((CursorShape) (int)  tolua_tonumber(tolua_S,2,0));
  Image* image = ((Image*)  tolua_tousertype(tolua_S,3,0));
  const IntRect* imageRect = ((const IntRect*)  tolua_tousertype(tolua_S,4,0));
  const IntVector2* hotSpot = ((const IntVector2*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DefineShape'", NULL);
#endif
 {
  self->DefineShape(shape,image,*imageRect,*hotSpot);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_Cursor_DefineShape00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetShape of class  Cursor */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Cursor_SetShape00
static int tolua_UILuaAPI_Cursor_SetShape00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Cursor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Cursor* self = (Cursor*)  tolua_tousertype(tolua_S,1,0);
  CursorShape shape = ((CursorShape) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetShape'", NULL);
#endif
 {
  self->SetShape(shape);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetShape'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetShape of class  Cursor */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Cursor_SetShape01
static int tolua_UILuaAPI_Cursor_SetShape01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Cursor",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Cursor* self = (Cursor*)  tolua_tousertype(tolua_S,1,0);
  const String shape = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetShape'", NULL);
#endif
 {
  self->SetShape(shape);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_Cursor_SetShape00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseSystemShapes of class  Cursor */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Cursor_SetUseSystemShapes00
static int tolua_UILuaAPI_Cursor_SetUseSystemShapes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Cursor",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Cursor* self = (Cursor*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseSystemShapes'", NULL);
#endif
 {
  self->SetUseSystemShapes(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseSystemShapes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetShape of class  Cursor */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Cursor_GetShape00
static int tolua_UILuaAPI_Cursor_GetShape00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Cursor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Cursor* self = (const Cursor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetShape'", NULL);
#endif
 {
  String tolua_ret = (String)  self->GetShape();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetShape'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUseSystemShapes of class  Cursor */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Cursor_GetUseSystemShapes00
static int tolua_UILuaAPI_Cursor_GetUseSystemShapes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Cursor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Cursor* self = (const Cursor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUseSystemShapes'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetUseSystemShapes();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUseSystemShapes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: shape of class  Cursor */
#ifndef TOLUA_DISABLE_tolua_get_Cursor_shape
static int tolua_get_Cursor_shape(lua_State* tolua_S)
{
  Cursor* self = (Cursor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'shape'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetShape());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: shape of class  Cursor */
#ifndef TOLUA_DISABLE_tolua_set_Cursor_shape
static int tolua_set_Cursor_shape(lua_State* tolua_S)
{
  Cursor* self = (Cursor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'shape'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetShape(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: useSystemShapes of class  Cursor */
#ifndef TOLUA_DISABLE_tolua_get_Cursor_useSystemShapes
static int tolua_get_Cursor_useSystemShapes(lua_State* tolua_S)
{
  Cursor* self = (Cursor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useSystemShapes'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetUseSystemShapes());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: useSystemShapes of class  Cursor */
#ifndef TOLUA_DISABLE_tolua_set_Cursor_useSystemShapes
static int tolua_set_Cursor_useSystemShapes(lua_State* tolua_S)
{
  Cursor* self = (Cursor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useSystemShapes'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUseSystemShapes(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name_ of class  FileSelectorEntry */
#ifndef TOLUA_DISABLE_tolua_get_FileSelectorEntry_name
static int tolua_get_FileSelectorEntry_name(lua_State* tolua_S)
{
  FileSelectorEntry* self = (FileSelectorEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name_'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->name_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name_ of class  FileSelectorEntry */
#ifndef TOLUA_DISABLE_tolua_set_FileSelectorEntry_name
static int tolua_set_FileSelectorEntry_name(lua_State* tolua_S)
{
  FileSelectorEntry* self = (FileSelectorEntry*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: directory_ of class  FileSelectorEntry */
#ifndef TOLUA_DISABLE_tolua_get_FileSelectorEntry_directory
static int tolua_get_FileSelectorEntry_directory(lua_State* tolua_S)
{
  FileSelectorEntry* self = (FileSelectorEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'directory_'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->directory_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: directory_ of class  FileSelectorEntry */
#ifndef TOLUA_DISABLE_tolua_set_FileSelectorEntry_directory
static int tolua_set_FileSelectorEntry_directory(lua_State* tolua_S)
{
  FileSelectorEntry* self = (FileSelectorEntry*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'directory_'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->directory_ = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_new00
static int tolua_UILuaAPI_FileSelector_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  FileSelector* tolua_ret = (FileSelector*)  Mtolua_new((FileSelector)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"FileSelector");
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

/* method: new_local of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_new00_local
static int tolua_UILuaAPI_FileSelector_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  FileSelector* tolua_ret = (FileSelector*)  Mtolua_new((FileSelector)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"FileSelector");
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

/* method: delete of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_delete00
static int tolua_UILuaAPI_FileSelector_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetDefaultStyle of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_SetDefaultStyle00
static int tolua_UILuaAPI_FileSelector_SetDefaultStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSelector",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"XMLFile",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetTitle of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_SetTitle00
static int tolua_UILuaAPI_FileSelector_SetTitle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSelector",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
  const String text = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTitle'", NULL);
#endif
 {
  self->SetTitle(text);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTitle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetButtonTexts of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_SetButtonTexts00
static int tolua_UILuaAPI_FileSelector_SetButtonTexts00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSelector",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
  const String okText = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  const String cancelText = ((const String)  tolua_tourho3dstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetButtonTexts'", NULL);
#endif
 {
  self->SetButtonTexts(okText,cancelText);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetButtonTexts'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPath of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_SetPath00
static int tolua_UILuaAPI_FileSelector_SetPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSelector",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
  const String path = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPath'", NULL);
#endif
 {
  self->SetPath(path);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFileName of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_SetFileName00
static int tolua_UILuaAPI_FileSelector_SetFileName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSelector",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFileName'", NULL);
#endif
 {
  self->SetFileName(fileName);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFileName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFilters of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_SetFilters00
static int tolua_UILuaAPI_FileSelector_SetFilters00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSelector",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !ToluaIsVector<String>(tolua_S,2,"String",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
  const Vector<String>* filters = ((const Vector<String>*)  ToluaToVector<String>(tolua_S,2,0));
  unsigned defaultIndex = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFilters'", NULL);
#endif
 {
  self->SetFilters(*filters,defaultIndex);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFilters'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDirectoryMode of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_SetDirectoryMode00
static int tolua_UILuaAPI_FileSelector_SetDirectoryMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSelector",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDirectoryMode'", NULL);
#endif
 {
  self->SetDirectoryMode(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDirectoryMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateElements of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_UpdateElements00
static int tolua_UILuaAPI_FileSelector_UpdateElements00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetDefaultStyle of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetDefaultStyle00
static int tolua_UILuaAPI_FileSelector_GetDefaultStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetWindow of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetWindow00
static int tolua_UILuaAPI_FileSelector_GetWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWindow'", NULL);
#endif
 {
  Window* tolua_ret = (Window*)  self->GetWindow();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Window");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTitleText of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetTitleText00
static int tolua_UILuaAPI_FileSelector_GetTitleText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTitleText'", NULL);
#endif
 {
  Text* tolua_ret = (Text*)  self->GetTitleText();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Text");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTitleText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFileList of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetFileList00
static int tolua_UILuaAPI_FileSelector_GetFileList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFileList'", NULL);
#endif
 {
  ListView* tolua_ret = (ListView*)  self->GetFileList();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ListView");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFileList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPathEdit of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetPathEdit00
static int tolua_UILuaAPI_FileSelector_GetPathEdit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPathEdit'", NULL);
#endif
 {
  LineEdit* tolua_ret = (LineEdit*)  self->GetPathEdit();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"LineEdit");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPathEdit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFileNameEdit of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetFileNameEdit00
static int tolua_UILuaAPI_FileSelector_GetFileNameEdit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFileNameEdit'", NULL);
#endif
 {
  LineEdit* tolua_ret = (LineEdit*)  self->GetFileNameEdit();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"LineEdit");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFileNameEdit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFilterList of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetFilterList00
static int tolua_UILuaAPI_FileSelector_GetFilterList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFilterList'", NULL);
#endif
 {
  DropDownList* tolua_ret = (DropDownList*)  self->GetFilterList();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"DropDownList");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFilterList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOKButton of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetOKButton00
static int tolua_UILuaAPI_FileSelector_GetOKButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOKButton'", NULL);
#endif
 {
  Button* tolua_ret = (Button*)  self->GetOKButton();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Button");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOKButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCancelButton of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetCancelButton00
static int tolua_UILuaAPI_FileSelector_GetCancelButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCancelButton'", NULL);
#endif
 {
  Button* tolua_ret = (Button*)  self->GetCancelButton();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Button");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCancelButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCloseButton of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetCloseButton00
static int tolua_UILuaAPI_FileSelector_GetCloseButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetTitle of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetTitle00
static int tolua_UILuaAPI_FileSelector_GetTitle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTitle'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetTitle();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTitle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPath of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetPath00
static int tolua_UILuaAPI_FileSelector_GetPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPath'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetPath();
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

/* method: GetFileName of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetFileName00
static int tolua_UILuaAPI_FileSelector_GetFileName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetFilter of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetFilter00
static int tolua_UILuaAPI_FileSelector_GetFilter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFilter'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetFilter();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFilter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFilterIndex of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetFilterIndex00
static int tolua_UILuaAPI_FileSelector_GetFilterIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFilterIndex'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetFilterIndex();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFilterIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDirectoryMode of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_FileSelector_GetDirectoryMode00
static int tolua_UILuaAPI_FileSelector_GetDirectoryMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const FileSelector",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const FileSelector* self = (const FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDirectoryMode'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetDirectoryMode();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDirectoryMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: defaultStyle of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_defaultStyle_ptr
static int tolua_get_FileSelector_defaultStyle_ptr(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'defaultStyle'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetDefaultStyle(),"XMLFile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: defaultStyle of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_set_FileSelector_defaultStyle_ptr
static int tolua_set_FileSelector_defaultStyle_ptr(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: window of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_window_ptr
static int tolua_get_FileSelector_window_ptr(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'window'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetWindow(),"Window");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: titleText of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_titleText_ptr
static int tolua_get_FileSelector_titleText_ptr(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'titleText'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetTitleText(),"Text");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fileList of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_fileList_ptr
static int tolua_get_FileSelector_fileList_ptr(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fileList'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetFileList(),"ListView");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pathEdit of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_pathEdit_ptr
static int tolua_get_FileSelector_pathEdit_ptr(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pathEdit'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetPathEdit(),"LineEdit");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fileNameEdit of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_fileNameEdit_ptr
static int tolua_get_FileSelector_fileNameEdit_ptr(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fileNameEdit'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetFileNameEdit(),"LineEdit");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: filterList of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_filterList_ptr
static int tolua_get_FileSelector_filterList_ptr(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'filterList'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetFilterList(),"DropDownList");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: OKButton of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_OKButton_ptr
static int tolua_get_FileSelector_OKButton_ptr(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OKButton'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetOKButton(),"Button");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cancelButton of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_cancelButton_ptr
static int tolua_get_FileSelector_cancelButton_ptr(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cancelButton'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetCancelButton(),"Button");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: closeButton of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_closeButton_ptr
static int tolua_get_FileSelector_closeButton_ptr(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'closeButton'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetCloseButton(),"Button");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: title of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_title
static int tolua_get_FileSelector_title(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'title'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetTitle());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: title of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_set_FileSelector_title
static int tolua_set_FileSelector_title(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'title'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTitle(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: path of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_path
static int tolua_get_FileSelector_path(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'path'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetPath());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: path of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_set_FileSelector_path
static int tolua_set_FileSelector_path(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'path'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPath(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fileName of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_fileName
static int tolua_get_FileSelector_fileName(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fileName'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetFileName());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: fileName of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_set_FileSelector_fileName
static int tolua_set_FileSelector_fileName(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fileName'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFileName(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: filter of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_filter
static int tolua_get_FileSelector_filter(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'filter'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetFilter());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: filterIndex of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_filterIndex
static int tolua_get_FileSelector_filterIndex(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'filterIndex'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFilterIndex());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: directoryMode of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_get_FileSelector_directoryMode
static int tolua_get_FileSelector_directoryMode(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'directoryMode'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetDirectoryMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: directoryMode of class  FileSelector */
#ifndef TOLUA_DISABLE_tolua_set_FileSelector_directoryMode
static int tolua_set_FileSelector_directoryMode(lua_State* tolua_S)
{
  FileSelector* self = (FileSelector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'directoryMode'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDirectoryMode(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAbsoluteGlyphOffset of class  Font */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Font_SetAbsoluteGlyphOffset00
static int tolua_UILuaAPI_Font_SetAbsoluteGlyphOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Font",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Font* self = (Font*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* offset = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAbsoluteGlyphOffset'", NULL);
#endif
 {
  self->SetAbsoluteGlyphOffset(*offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAbsoluteGlyphOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScaledGlyphOffset of class  Font */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Font_SetScaledGlyphOffset00
static int tolua_UILuaAPI_Font_SetScaledGlyphOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Font",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Font* self = (Font*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* offset = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScaledGlyphOffset'", NULL);
#endif
 {
  self->SetScaledGlyphOffset(*offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScaledGlyphOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAbsoluteGlyphOffset of class  Font */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Font_GetAbsoluteGlyphOffset00
static int tolua_UILuaAPI_Font_GetAbsoluteGlyphOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Font",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Font* self = (const Font*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAbsoluteGlyphOffset'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetAbsoluteGlyphOffset();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAbsoluteGlyphOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScaledGlyphOffset of class  Font */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Font_GetScaledGlyphOffset00
static int tolua_UILuaAPI_Font_GetScaledGlyphOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Font",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Font* self = (const Font*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScaledGlyphOffset'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetScaledGlyphOffset();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScaledGlyphOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTotalGlyphOffset of class  Font */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Font_GetTotalGlyphOffset00
static int tolua_UILuaAPI_Font_GetTotalGlyphOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Font",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Font* self = (const Font*)  tolua_tousertype(tolua_S,1,0);
  float pointSize = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTotalGlyphOffset'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->GetTotalGlyphOffset(pointSize);
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
 tolua_error(tolua_S,"#ferror in function 'GetTotalGlyphOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFontType of class  Font */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Font_GetFontType00
static int tolua_UILuaAPI_Font_GetFontType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Font",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Font* self = (const Font*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFontType'", NULL);
#endif
 {
  FontType tolua_ret = (FontType)  self->GetFontType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsSDFFont of class  Font */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Font_IsSDFFont00
static int tolua_UILuaAPI_Font_IsSDFFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Font",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Font* self = (const Font*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsSDFFont'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsSDFFont();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsSDFFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: absoluteGlyphOffset of class  Font */
#ifndef TOLUA_DISABLE_tolua_get_Font_absoluteGlyphOffset
static int tolua_get_Font_absoluteGlyphOffset(lua_State* tolua_S)
{
  Font* self = (Font*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'absoluteGlyphOffset'",NULL);
#endif
 IntVector2 tolua_ret = (IntVector2)self->GetAbsoluteGlyphOffset();
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

/* set function: absoluteGlyphOffset of class  Font */
#ifndef TOLUA_DISABLE_tolua_set_Font_absoluteGlyphOffset
static int tolua_set_Font_absoluteGlyphOffset(lua_State* tolua_S)
{
  Font* self = (Font*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'absoluteGlyphOffset'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAbsoluteGlyphOffset(*((IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scaledGlyphOffset of class  Font */
#ifndef TOLUA_DISABLE_tolua_get_Font_scaledGlyphOffset
static int tolua_get_Font_scaledGlyphOffset(lua_State* tolua_S)
{
  Font* self = (Font*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scaledGlyphOffset'",NULL);
#endif
 Vector2 tolua_ret = (Vector2)self->GetScaledGlyphOffset();
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

/* set function: scaledGlyphOffset of class  Font */
#ifndef TOLUA_DISABLE_tolua_set_Font_scaledGlyphOffset
static int tolua_set_Font_scaledGlyphOffset(lua_State* tolua_S)
{
  Font* self = (Font*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scaledGlyphOffset'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetScaledGlyphOffset(*((Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fontType of class  Font */
#ifndef TOLUA_DISABLE_tolua_get_Font_fontType
static int tolua_get_Font_fontType(lua_State* tolua_S)
{
  Font* self = (Font*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fontType'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFontType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_new00
static int tolua_UILuaAPI_LineEdit_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"LineEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  LineEdit* tolua_ret = (LineEdit*)  Mtolua_new((LineEdit)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"LineEdit");
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

/* method: new_local of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_new00_local
static int tolua_UILuaAPI_LineEdit_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"LineEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  LineEdit* tolua_ret = (LineEdit*)  Mtolua_new((LineEdit)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"LineEdit");
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

/* method: delete of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_delete00
static int tolua_UILuaAPI_LineEdit_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LineEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetText of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_SetText00
static int tolua_UILuaAPI_LineEdit_SetText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LineEdit",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
  const String text = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetText'", NULL);
#endif
 {
  self->SetText(text);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCursorPosition of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_SetCursorPosition00
static int tolua_UILuaAPI_LineEdit_SetCursorPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LineEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
  unsigned position = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCursorPosition'", NULL);
#endif
 {
  self->SetCursorPosition(position);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCursorPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCursorBlinkRate of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_SetCursorBlinkRate00
static int tolua_UILuaAPI_LineEdit_SetCursorBlinkRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LineEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCursorBlinkRate'", NULL);
#endif
 {
  self->SetCursorBlinkRate(rate);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCursorBlinkRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxLength of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_SetMaxLength00
static int tolua_UILuaAPI_LineEdit_SetMaxLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LineEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
  unsigned length = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxLength'", NULL);
#endif
 {
  self->SetMaxLength(length);
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

/* method: SetEchoCharacter of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_SetEchoCharacter00
static int tolua_UILuaAPI_LineEdit_SetEchoCharacter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LineEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
  unsigned c = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEchoCharacter'", NULL);
#endif
 {
  self->SetEchoCharacter(c);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEchoCharacter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCursorMovable of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_SetCursorMovable00
static int tolua_UILuaAPI_LineEdit_SetCursorMovable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LineEdit",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCursorMovable'", NULL);
#endif
 {
  self->SetCursorMovable(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCursorMovable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextSelectable of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_SetTextSelectable00
static int tolua_UILuaAPI_LineEdit_SetTextSelectable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LineEdit",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextSelectable'", NULL);
#endif
 {
  self->SetTextSelectable(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextSelectable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextCopyable of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_SetTextCopyable00
static int tolua_UILuaAPI_LineEdit_SetTextCopyable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LineEdit",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextCopyable'", NULL);
#endif
 {
  self->SetTextCopyable(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextCopyable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetText of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_GetText00
static int tolua_UILuaAPI_LineEdit_GetText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const LineEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const LineEdit* self = (const LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetText'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetText();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCursorPosition of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_GetCursorPosition00
static int tolua_UILuaAPI_LineEdit_GetCursorPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const LineEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const LineEdit* self = (const LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCursorPosition'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetCursorPosition();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCursorPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCursorBlinkRate of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_GetCursorBlinkRate00
static int tolua_UILuaAPI_LineEdit_GetCursorBlinkRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const LineEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const LineEdit* self = (const LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCursorBlinkRate'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetCursorBlinkRate();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCursorBlinkRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxLength of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_GetMaxLength00
static int tolua_UILuaAPI_LineEdit_GetMaxLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const LineEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const LineEdit* self = (const LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxLength'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetMaxLength();
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

/* method: GetEchoCharacter of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_GetEchoCharacter00
static int tolua_UILuaAPI_LineEdit_GetEchoCharacter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const LineEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const LineEdit* self = (const LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEchoCharacter'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetEchoCharacter();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEchoCharacter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsCursorMovable of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_IsCursorMovable00
static int tolua_UILuaAPI_LineEdit_IsCursorMovable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const LineEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const LineEdit* self = (const LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsCursorMovable'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsCursorMovable();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsCursorMovable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsTextSelectable of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_IsTextSelectable00
static int tolua_UILuaAPI_LineEdit_IsTextSelectable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const LineEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const LineEdit* self = (const LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsTextSelectable'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsTextSelectable();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsTextSelectable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsTextCopyable of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_IsTextCopyable00
static int tolua_UILuaAPI_LineEdit_IsTextCopyable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const LineEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const LineEdit* self = (const LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsTextCopyable'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsTextCopyable();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsTextCopyable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextElement of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_GetTextElement00
static int tolua_UILuaAPI_LineEdit_GetTextElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const LineEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const LineEdit* self = (const LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextElement'", NULL);
#endif
 {
  Text* tolua_ret = (Text*)  self->GetTextElement();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Text");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCursor of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_LineEdit_GetCursor00
static int tolua_UILuaAPI_LineEdit_GetCursor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const LineEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const LineEdit* self = (const LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCursor'", NULL);
#endif
 {
  BorderImage* tolua_ret = (BorderImage*)  self->GetCursor();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BorderImage");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCursor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: text of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_get_LineEdit_text
static int tolua_get_LineEdit_text(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'text'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetText());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: text of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_set_LineEdit_text
static int tolua_set_LineEdit_text(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'text'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetText(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cursorPosition of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_get_LineEdit_cursorPosition
static int tolua_get_LineEdit_cursorPosition(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cursorPosition'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetCursorPosition());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cursorPosition of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_set_LineEdit_cursorPosition
static int tolua_set_LineEdit_cursorPosition(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cursorPosition'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCursorPosition(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cursorBlinkRate of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_get_LineEdit_cursorBlinkRate
static int tolua_get_LineEdit_cursorBlinkRate(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cursorBlinkRate'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetCursorBlinkRate());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cursorBlinkRate of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_set_LineEdit_cursorBlinkRate
static int tolua_set_LineEdit_cursorBlinkRate(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cursorBlinkRate'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCursorBlinkRate(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxLength of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_get_LineEdit_maxLength
static int tolua_get_LineEdit_maxLength(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxLength'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxLength());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxLength of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_set_LineEdit_maxLength
static int tolua_set_LineEdit_maxLength(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxLength'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxLength(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: echoCharacter of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_get_LineEdit_echoCharacter
static int tolua_get_LineEdit_echoCharacter(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'echoCharacter'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetEchoCharacter());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: echoCharacter of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_set_LineEdit_echoCharacter
static int tolua_set_LineEdit_echoCharacter(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'echoCharacter'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEchoCharacter(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cursorMovable of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_get_LineEdit_cursorMovable
static int tolua_get_LineEdit_cursorMovable(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cursorMovable'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsCursorMovable());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cursorMovable of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_set_LineEdit_cursorMovable
static int tolua_set_LineEdit_cursorMovable(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cursorMovable'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCursorMovable(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: textSelectable of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_get_LineEdit_textSelectable
static int tolua_get_LineEdit_textSelectable(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textSelectable'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsTextSelectable());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: textSelectable of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_set_LineEdit_textSelectable
static int tolua_set_LineEdit_textSelectable(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textSelectable'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTextSelectable(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: textCopyable of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_get_LineEdit_textCopyable
static int tolua_get_LineEdit_textCopyable(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textCopyable'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsTextCopyable());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: textCopyable of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_set_LineEdit_textCopyable
static int tolua_set_LineEdit_textCopyable(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textCopyable'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTextCopyable(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: textElement of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_get_LineEdit_textElement_ptr
static int tolua_get_LineEdit_textElement_ptr(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textElement'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetTextElement(),"Text");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cursor of class  LineEdit */
#ifndef TOLUA_DISABLE_tolua_get_LineEdit_cursor_ptr
static int tolua_get_LineEdit_cursor_ptr(lua_State* tolua_S)
{
  LineEdit* self = (LineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cursor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetCursor(),"BorderImage");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Menu */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Menu_new00
static int tolua_UILuaAPI_Menu_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Menu",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Menu* tolua_ret = (Menu*)  Mtolua_new((Menu)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Menu");
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

/* method: new_local of class  Menu */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Menu_new00_local
static int tolua_UILuaAPI_Menu_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Menu",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Menu* tolua_ret = (Menu*)  Mtolua_new((Menu)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Menu");
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

/* method: delete of class  Menu */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Menu_delete00
static int tolua_UILuaAPI_Menu_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Menu",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Menu* self = (Menu*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetPopup of class  Menu */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Menu_SetPopup00
static int tolua_UILuaAPI_Menu_SetPopup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Menu",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Menu* self = (Menu*)  tolua_tousertype(tolua_S,1,0);
  UIElement* element = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPopup'", NULL);
#endif
 {
  self->SetPopup(element);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPopup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPopupOffset of class  Menu */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Menu_SetPopupOffset00
static int tolua_UILuaAPI_Menu_SetPopupOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Menu",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Menu* self = (Menu*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* offset = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPopupOffset'", NULL);
#endif
 {
  self->SetPopupOffset(*offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPopupOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPopupOffset of class  Menu */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Menu_SetPopupOffset01
static int tolua_UILuaAPI_Menu_SetPopupOffset01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Menu",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Menu* self = (Menu*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPopupOffset'", NULL);
#endif
 {
  self->SetPopupOffset(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_Menu_SetPopupOffset00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ShowPopup of class  Menu */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Menu_ShowPopup00
static int tolua_UILuaAPI_Menu_ShowPopup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Menu",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Menu* self = (Menu*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ShowPopup'", NULL);
#endif
 {
  self->ShowPopup(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ShowPopup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAccelerator of class  Menu */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Menu_SetAccelerator00
static int tolua_UILuaAPI_Menu_SetAccelerator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Menu",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Menu* self = (Menu*)  tolua_tousertype(tolua_S,1,0);
  int key = ((int)  tolua_tonumber(tolua_S,2,0));
  int qualifiers = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAccelerator'", NULL);
#endif
 {
  self->SetAccelerator(key,qualifiers);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAccelerator'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPopup of class  Menu */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Menu_GetPopup00
static int tolua_UILuaAPI_Menu_GetPopup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Menu",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Menu* self = (const Menu*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPopup'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetPopup();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPopup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPopupOffset of class  Menu */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Menu_GetPopupOffset00
static int tolua_UILuaAPI_Menu_GetPopupOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Menu",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Menu* self = (const Menu*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPopupOffset'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetPopupOffset();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPopupOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetShowPopup of class  Menu */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Menu_GetShowPopup00
static int tolua_UILuaAPI_Menu_GetShowPopup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Menu",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Menu* self = (const Menu*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetShowPopup'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetShowPopup();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetShowPopup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAcceleratorKey of class  Menu */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Menu_GetAcceleratorKey00
static int tolua_UILuaAPI_Menu_GetAcceleratorKey00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Menu",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Menu* self = (const Menu*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAcceleratorKey'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetAcceleratorKey();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAcceleratorKey'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAcceleratorQualifiers of class  Menu */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Menu_GetAcceleratorQualifiers00
static int tolua_UILuaAPI_Menu_GetAcceleratorQualifiers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Menu",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Menu* self = (const Menu*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAcceleratorQualifiers'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetAcceleratorQualifiers();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAcceleratorQualifiers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: popup of class  Menu */
#ifndef TOLUA_DISABLE_tolua_get_Menu_popup_ptr
static int tolua_get_Menu_popup_ptr(lua_State* tolua_S)
{
  Menu* self = (Menu*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'popup'",NULL);
#endif
  ToluaPushObject(tolua_S,(void*)self->GetPopup(),"UIElement");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: popup of class  Menu */
#ifndef TOLUA_DISABLE_tolua_set_Menu_popup_ptr
static int tolua_set_Menu_popup_ptr(lua_State* tolua_S)
{
  Menu* self = (Menu*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'popup'",NULL);
 if (!tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPopup(((UIElement*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: popupOffset of class  Menu */
#ifndef TOLUA_DISABLE_tolua_get_Menu_popupOffset_ref
static int tolua_get_Menu_popupOffset_ref(lua_State* tolua_S)
{
  Menu* self = (Menu*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'popupOffset'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetPopupOffset(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: popupOffset of class  Menu */
#ifndef TOLUA_DISABLE_tolua_set_Menu_popupOffset_ref
static int tolua_set_Menu_popupOffset_ref(lua_State* tolua_S)
{
  Menu* self = (Menu*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'popupOffset'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPopupOffset((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: showPopup of class  Menu */
#ifndef TOLUA_DISABLE_tolua_get_Menu_showPopup
static int tolua_get_Menu_showPopup(lua_State* tolua_S)
{
  Menu* self = (Menu*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'showPopup'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetShowPopup());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: showPopup of class  Menu */
#ifndef TOLUA_DISABLE_tolua_set_Menu_showPopup
static int tolua_set_Menu_showPopup(lua_State* tolua_S)
{
  Menu* self = (Menu*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'showPopup'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetShowPopup(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: acceleratorKey of class  Menu */
#ifndef TOLUA_DISABLE_tolua_get_Menu_acceleratorKey
static int tolua_get_Menu_acceleratorKey(lua_State* tolua_S)
{
  Menu* self = (Menu*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'acceleratorKey'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAcceleratorKey());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: acceleratorQualifiers of class  Menu */
#ifndef TOLUA_DISABLE_tolua_get_Menu_acceleratorQualifiers
static int tolua_get_Menu_acceleratorQualifiers(lua_State* tolua_S)
{
  Menu* self = (Menu*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'acceleratorQualifiers'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetAcceleratorQualifiers());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  MessageBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_MessageBox_new00
static int tolua_UILuaAPI_MessageBox_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MessageBox",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isusertype(tolua_S,4,"XMLFile",1,&tolua_err) ||
 !tolua_isusertype(tolua_S,5,"XMLFile",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String messageString = ((const String)  tolua_tourho3dstring(tolua_S,2,String::EMPTY));
  const String titleString = ((const String)  tolua_tourho3dstring(tolua_S,3,String::EMPTY));
  XMLFile* layoutFile = ((XMLFile*)  tolua_tousertype(tolua_S,4,0));
  XMLFile* styleFile = ((XMLFile*)  tolua_tousertype(tolua_S,5,0));
 {
  MessageBox* tolua_ret = (MessageBox*)  Mtolua_new((MessageBox)(messageString,titleString,layoutFile,styleFile));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"MessageBox");
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

/* method: new_local of class  MessageBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_MessageBox_new00_local
static int tolua_UILuaAPI_MessageBox_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MessageBox",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,1,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,3,1,&tolua_err) ||
 !tolua_isusertype(tolua_S,4,"XMLFile",1,&tolua_err) ||
 !tolua_isusertype(tolua_S,5,"XMLFile",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const String messageString = ((const String)  tolua_tourho3dstring(tolua_S,2,String::EMPTY));
  const String titleString = ((const String)  tolua_tourho3dstring(tolua_S,3,String::EMPTY));
  XMLFile* layoutFile = ((XMLFile*)  tolua_tousertype(tolua_S,4,0));
  XMLFile* styleFile = ((XMLFile*)  tolua_tousertype(tolua_S,5,0));
 {
  MessageBox* tolua_ret = (MessageBox*)  Mtolua_new((MessageBox)(messageString,titleString,layoutFile,styleFile));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"MessageBox");
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

/* method: delete of class  MessageBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_MessageBox_delete00
static int tolua_UILuaAPI_MessageBox_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"MessageBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MessageBox* self = (MessageBox*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetTitle of class  MessageBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_MessageBox_SetTitle00
static int tolua_UILuaAPI_MessageBox_SetTitle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"MessageBox",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MessageBox* self = (MessageBox*)  tolua_tousertype(tolua_S,1,0);
  const String text = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTitle'", NULL);
#endif
 {
  self->SetTitle(text);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTitle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMessage of class  MessageBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_MessageBox_SetMessage00
static int tolua_UILuaAPI_MessageBox_SetMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"MessageBox",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MessageBox* self = (MessageBox*)  tolua_tousertype(tolua_S,1,0);
  const String text = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMessage'", NULL);
#endif
 {
  self->SetMessage(text);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTitle of class  MessageBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_MessageBox_GetTitle00
static int tolua_UILuaAPI_MessageBox_GetTitle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const MessageBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const MessageBox* self = (const MessageBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTitle'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetTitle();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTitle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMessage of class  MessageBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_MessageBox_GetMessage00
static int tolua_UILuaAPI_MessageBox_GetMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const MessageBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const MessageBox* self = (const MessageBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMessage'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetMessage();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWindow of class  MessageBox */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_MessageBox_GetWindow00
static int tolua_UILuaAPI_MessageBox_GetWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const MessageBox",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const MessageBox* self = (const MessageBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWindow'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetWindow();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: title of class  MessageBox */
#ifndef TOLUA_DISABLE_tolua_get_MessageBox_title
static int tolua_get_MessageBox_title(lua_State* tolua_S)
{
  MessageBox* self = (MessageBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'title'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetTitle());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: title of class  MessageBox */
#ifndef TOLUA_DISABLE_tolua_set_MessageBox_title
static int tolua_set_MessageBox_title(lua_State* tolua_S)
{
  MessageBox* self = (MessageBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'title'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTitle(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: message of class  MessageBox */
#ifndef TOLUA_DISABLE_tolua_get_MessageBox_message
static int tolua_get_MessageBox_message(lua_State* tolua_S)
{
  MessageBox* self = (MessageBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'message'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetMessage());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: message of class  MessageBox */
#ifndef TOLUA_DISABLE_tolua_set_MessageBox_message
static int tolua_set_MessageBox_message(lua_State* tolua_S)
{
  MessageBox* self = (MessageBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'message'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMessage(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: window of class  MessageBox */
#ifndef TOLUA_DISABLE_tolua_get_MessageBox_window_ptr
static int tolua_get_MessageBox_window_ptr(lua_State* tolua_S)
{
  MessageBox* self = (MessageBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'window'",NULL);
#endif
  ToluaPushObject(tolua_S,(void*)self->GetWindow(),"UIElement");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_new00
static int tolua_UILuaAPI_ProgressBar_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ProgressBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ProgressBar* tolua_ret = (ProgressBar*)  Mtolua_new((ProgressBar)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ProgressBar");
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

/* method: new_local of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_new00_local
static int tolua_UILuaAPI_ProgressBar_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ProgressBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ProgressBar* tolua_ret = (ProgressBar*)  Mtolua_new((ProgressBar)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ProgressBar");
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

/* method: delete of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_delete00
static int tolua_UILuaAPI_ProgressBar_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ProgressBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetOrientation of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_SetOrientation00
static int tolua_UILuaAPI_ProgressBar_SetOrientation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ProgressBar",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
  Orientation orientation = ((Orientation) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOrientation'", NULL);
#endif
 {
  self->SetOrientation(orientation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRange of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_SetRange00
static int tolua_UILuaAPI_ProgressBar_SetRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ProgressBar",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
  float range = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRange'", NULL);
#endif
 {
  self->SetRange(range);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetValue of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_SetValue00
static int tolua_UILuaAPI_ProgressBar_SetValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ProgressBar",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetValue'", NULL);
#endif
 {
  self->SetValue(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChangeValue of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_ChangeValue00
static int tolua_UILuaAPI_ProgressBar_ChangeValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ProgressBar",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChangeValue'", NULL);
#endif
 {
  self->ChangeValue(delta);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChangeValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLoadingPercentStyle of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_SetLoadingPercentStyle00
static int tolua_UILuaAPI_ProgressBar_SetLoadingPercentStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ProgressBar",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
  const String style = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLoadingPercentStyle'", NULL);
#endif
 {
  self->SetLoadingPercentStyle(style);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLoadingPercentStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetShowPercentText of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_SetShowPercentText00
static int tolua_UILuaAPI_ProgressBar_SetShowPercentText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ProgressBar",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
  bool showPercentText = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetShowPercentText'", NULL);
#endif
 {
  self->SetShowPercentText(showPercentText);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetShowPercentText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOrientation of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_GetOrientation00
static int tolua_UILuaAPI_ProgressBar_GetOrientation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ProgressBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ProgressBar* self = (const ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOrientation'", NULL);
#endif
 {
  Orientation tolua_ret = (Orientation)  self->GetOrientation();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRange of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_GetRange00
static int tolua_UILuaAPI_ProgressBar_GetRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ProgressBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ProgressBar* self = (const ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRange'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRange();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetValue of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_GetValue00
static int tolua_UILuaAPI_ProgressBar_GetValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ProgressBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ProgressBar* self = (const ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetValue'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetValue();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: GetKnob of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_GetKnob00
static int tolua_UILuaAPI_ProgressBar_GetKnob00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ProgressBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ProgressBar* self = (const ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetKnob'", NULL);
#endif
 {
  BorderImage* tolua_ret = (BorderImage*)  self->GetKnob();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BorderImage");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetKnob'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLoadingPercentStyle of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_GetLoadingPercentStyle00
static int tolua_UILuaAPI_ProgressBar_GetLoadingPercentStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ProgressBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLoadingPercentStyle'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetLoadingPercentStyle();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLoadingPercentStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetShowPercentText of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ProgressBar_GetShowPercentText00
static int tolua_UILuaAPI_ProgressBar_GetShowPercentText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ProgressBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ProgressBar* self = (const ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetShowPercentText'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetShowPercentText();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetShowPercentText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: orientation of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_get_ProgressBar_orientation
static int tolua_get_ProgressBar_orientation(lua_State* tolua_S)
{
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'orientation'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetOrientation());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: orientation of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_set_ProgressBar_orientation
static int tolua_set_ProgressBar_orientation(lua_State* tolua_S)
{
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'orientation'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOrientation(((Orientation) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: range of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_get_ProgressBar_range
static int tolua_get_ProgressBar_range(lua_State* tolua_S)
{
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'range'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRange());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: range of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_set_ProgressBar_range
static int tolua_set_ProgressBar_range(lua_State* tolua_S)
{
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'range'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRange(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_get_ProgressBar_value
static int tolua_get_ProgressBar_value(lua_State* tolua_S)
{
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetValue());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_set_ProgressBar_value
static int tolua_set_ProgressBar_value(lua_State* tolua_S)
{
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetValue(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: knob of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_get_ProgressBar_knob_ptr
static int tolua_get_ProgressBar_knob_ptr(lua_State* tolua_S)
{
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'knob'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetKnob(),"BorderImage");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: loadingPercentStyle of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_get_ProgressBar_loadingPercentStyle
static int tolua_get_ProgressBar_loadingPercentStyle(lua_State* tolua_S)
{
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loadingPercentStyle'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetLoadingPercentStyle());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: showPercentText of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_get_ProgressBar_showPercentText
static int tolua_get_ProgressBar_showPercentText(lua_State* tolua_S)
{
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'showPercentText'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetShowPercentText());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: showPercentText of class  ProgressBar */
#ifndef TOLUA_DISABLE_tolua_set_ProgressBar_showPercentText
static int tolua_set_ProgressBar_showPercentText(lua_State* tolua_S)
{
  ProgressBar* self = (ProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'showPercentText'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetShowPercentText(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_new00
static int tolua_UILuaAPI_DropDownList_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"DropDownList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  DropDownList* tolua_ret = (DropDownList*)  Mtolua_new((DropDownList)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"DropDownList");
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

/* method: new_local of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_new00_local
static int tolua_UILuaAPI_DropDownList_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"DropDownList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  DropDownList* tolua_ret = (DropDownList*)  Mtolua_new((DropDownList)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"DropDownList");
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

/* method: delete of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_delete00
static int tolua_UILuaAPI_DropDownList_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DropDownList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
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

/* method: AddItem of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_AddItem00
static int tolua_UILuaAPI_DropDownList_AddItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DropDownList",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
  UIElement* item = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddItem'", NULL);
#endif
 {
  self->AddItem(item);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItem of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_InsertItem00
static int tolua_UILuaAPI_DropDownList_InsertItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DropDownList",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  UIElement* item = ((UIElement*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItem'", NULL);
#endif
 {
  self->InsertItem(index,item);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_RemoveItem00
static int tolua_UILuaAPI_DropDownList_RemoveItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DropDownList",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
  UIElement* item = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
 {
  self->RemoveItem(item);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_RemoveItem01
static int tolua_UILuaAPI_DropDownList_RemoveItem01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DropDownList",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
 {
  self->RemoveItem(index);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_DropDownList_RemoveItem00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllItems of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_RemoveAllItems00
static int tolua_UILuaAPI_DropDownList_RemoveAllItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DropDownList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllItems'", NULL);
#endif
 {
  self->RemoveAllItems();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSelection of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_SetSelection00
static int tolua_UILuaAPI_DropDownList_SetSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DropDownList",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSelection'", NULL);
#endif
 {
  self->SetSelection(index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlaceholderText of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_SetPlaceholderText00
static int tolua_UILuaAPI_DropDownList_SetPlaceholderText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DropDownList",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
  const String text = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlaceholderText'", NULL);
#endif
 {
  self->SetPlaceholderText(text);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlaceholderText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetResizePopup of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_SetResizePopup00
static int tolua_UILuaAPI_DropDownList_SetResizePopup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DropDownList",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetResizePopup'", NULL);
#endif
 {
  self->SetResizePopup(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetResizePopup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumItems of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_GetNumItems00
static int tolua_UILuaAPI_DropDownList_GetNumItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DropDownList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DropDownList* self = (const DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumItems'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumItems();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItem of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_GetItem00
static int tolua_UILuaAPI_DropDownList_GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DropDownList",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DropDownList* self = (const DropDownList*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetItem(index);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DropDownListGetItems of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_GetItems00
static int tolua_UILuaAPI_DropDownList_GetItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DropDownList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DropDownList* self = (const DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DropDownListGetItems'", NULL);
#endif
 {
  tolua_outside  const PODVector<UIElement*>& tolua_ret = (tolua_outside  const PODVector<UIElement*>&)  DropDownListGetItems(self);
  ToluaPushPODVector<UIElement*>("",tolua_S,(void*)&tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSelection of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_GetSelection00
static int tolua_UILuaAPI_DropDownList_GetSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DropDownList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DropDownList* self = (const DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSelection'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetSelection();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSelectedItem of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_GetSelectedItem00
static int tolua_UILuaAPI_DropDownList_GetSelectedItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DropDownList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DropDownList* self = (const DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSelectedItem'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetSelectedItem();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelectedItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetListView of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_GetListView00
static int tolua_UILuaAPI_DropDownList_GetListView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DropDownList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DropDownList* self = (const DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetListView'", NULL);
#endif
 {
  ListView* tolua_ret = (ListView*)  self->GetListView();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ListView");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetListView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlaceholder of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_GetPlaceholder00
static int tolua_UILuaAPI_DropDownList_GetPlaceholder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DropDownList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DropDownList* self = (const DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlaceholder'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetPlaceholder();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlaceholder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlaceholderText of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_GetPlaceholderText00
static int tolua_UILuaAPI_DropDownList_GetPlaceholderText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DropDownList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DropDownList* self = (const DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlaceholderText'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetPlaceholderText();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlaceholderText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetResizePopup of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_DropDownList_GetResizePopup00
static int tolua_UILuaAPI_DropDownList_GetResizePopup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DropDownList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DropDownList* self = (const DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetResizePopup'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetResizePopup();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetResizePopup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numItems of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_get_DropDownList_numItems
static int tolua_get_DropDownList_numItems(lua_State* tolua_S)
{
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numItems'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumItems());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: selection of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_get_DropDownList_selection
static int tolua_get_DropDownList_selection(lua_State* tolua_S)
{
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'selection'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSelection());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: selection of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_set_DropDownList_selection
static int tolua_set_DropDownList_selection(lua_State* tolua_S)
{
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'selection'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSelection(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: selectedItem of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_get_DropDownList_selectedItem_ptr
static int tolua_get_DropDownList_selectedItem_ptr(lua_State* tolua_S)
{
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'selectedItem'",NULL);
#endif
  ToluaPushObject(tolua_S,(void*)self->GetSelectedItem(),"UIElement");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: listView of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_get_DropDownList_listView_ptr
static int tolua_get_DropDownList_listView_ptr(lua_State* tolua_S)
{
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'listView'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetListView(),"ListView");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: placeholder of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_get_DropDownList_placeholder_ptr
static int tolua_get_DropDownList_placeholder_ptr(lua_State* tolua_S)
{
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'placeholder'",NULL);
#endif
  ToluaPushObject(tolua_S,(void*)self->GetPlaceholder(),"UIElement");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: placeholderText of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_get_DropDownList_placeholderText
static int tolua_get_DropDownList_placeholderText(lua_State* tolua_S)
{
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'placeholderText'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetPlaceholderText());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: placeholderText of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_set_DropDownList_placeholderText
static int tolua_set_DropDownList_placeholderText(lua_State* tolua_S)
{
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'placeholderText'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPlaceholderText(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: resizePopup of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_get_DropDownList_resizePopup
static int tolua_get_DropDownList_resizePopup(lua_State* tolua_S)
{
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resizePopup'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetResizePopup());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: resizePopup of class  DropDownList */
#ifndef TOLUA_DISABLE_tolua_set_DropDownList_resizePopup
static int tolua_set_DropDownList_resizePopup(lua_State* tolua_S)
{
  DropDownList* self = (DropDownList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resizePopup'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetResizePopup(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Slider */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Slider_new00
static int tolua_UILuaAPI_Slider_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Slider",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Slider* tolua_ret = (Slider*)  Mtolua_new((Slider)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Slider");
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

/* method: new_local of class  Slider */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Slider_new00_local
static int tolua_UILuaAPI_Slider_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Slider",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Slider* tolua_ret = (Slider*)  Mtolua_new((Slider)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Slider");
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

/* method: delete of class  Slider */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Slider_delete00
static int tolua_UILuaAPI_Slider_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Slider",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetOrientation of class  Slider */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Slider_SetOrientation00
static int tolua_UILuaAPI_Slider_SetOrientation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Slider",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
  Orientation orientation = ((Orientation) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOrientation'", NULL);
#endif
 {
  self->SetOrientation(orientation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRange of class  Slider */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Slider_SetRange00
static int tolua_UILuaAPI_Slider_SetRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Slider",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
  float range = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRange'", NULL);
#endif
 {
  self->SetRange(range);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetValue of class  Slider */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Slider_SetValue00
static int tolua_UILuaAPI_Slider_SetValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Slider",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetValue'", NULL);
#endif
 {
  self->SetValue(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChangeValue of class  Slider */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Slider_ChangeValue00
static int tolua_UILuaAPI_Slider_ChangeValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Slider",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChangeValue'", NULL);
#endif
 {
  self->ChangeValue(delta);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChangeValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRepeatRate of class  Slider */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Slider_SetRepeatRate00
static int tolua_UILuaAPI_Slider_SetRepeatRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Slider",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRepeatRate'", NULL);
#endif
 {
  self->SetRepeatRate(rate);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRepeatRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOrientation of class  Slider */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Slider_GetOrientation00
static int tolua_UILuaAPI_Slider_GetOrientation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Slider",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Slider* self = (const Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOrientation'", NULL);
#endif
 {
  Orientation tolua_ret = (Orientation)  self->GetOrientation();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRange of class  Slider */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Slider_GetRange00
static int tolua_UILuaAPI_Slider_GetRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Slider",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Slider* self = (const Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRange'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRange();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetValue of class  Slider */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Slider_GetValue00
static int tolua_UILuaAPI_Slider_GetValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Slider",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Slider* self = (const Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetValue'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetValue();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: GetKnob of class  Slider */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Slider_GetKnob00
static int tolua_UILuaAPI_Slider_GetKnob00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Slider",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Slider* self = (const Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetKnob'", NULL);
#endif
 {
  BorderImage* tolua_ret = (BorderImage*)  self->GetKnob();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BorderImage");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetKnob'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRepeatRate of class  Slider */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Slider_GetRepeatRate00
static int tolua_UILuaAPI_Slider_GetRepeatRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Slider",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Slider* self = (const Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRepeatRate'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRepeatRate();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRepeatRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: orientation of class  Slider */
#ifndef TOLUA_DISABLE_tolua_get_Slider_orientation
static int tolua_get_Slider_orientation(lua_State* tolua_S)
{
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'orientation'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetOrientation());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: orientation of class  Slider */
#ifndef TOLUA_DISABLE_tolua_set_Slider_orientation
static int tolua_set_Slider_orientation(lua_State* tolua_S)
{
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'orientation'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOrientation(((Orientation) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: range of class  Slider */
#ifndef TOLUA_DISABLE_tolua_get_Slider_range
static int tolua_get_Slider_range(lua_State* tolua_S)
{
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'range'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRange());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: range of class  Slider */
#ifndef TOLUA_DISABLE_tolua_set_Slider_range
static int tolua_set_Slider_range(lua_State* tolua_S)
{
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'range'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRange(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  Slider */
#ifndef TOLUA_DISABLE_tolua_get_Slider_value
static int tolua_get_Slider_value(lua_State* tolua_S)
{
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetValue());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  Slider */
#ifndef TOLUA_DISABLE_tolua_set_Slider_value
static int tolua_set_Slider_value(lua_State* tolua_S)
{
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetValue(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: knob of class  Slider */
#ifndef TOLUA_DISABLE_tolua_get_Slider_knob_ptr
static int tolua_get_Slider_knob_ptr(lua_State* tolua_S)
{
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'knob'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetKnob(),"BorderImage");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: repeatRate of class  Slider */
#ifndef TOLUA_DISABLE_tolua_get_Slider_repeatRate
static int tolua_get_Slider_repeatRate(lua_State* tolua_S)
{
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'repeatRate'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRepeatRate());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: repeatRate of class  Slider */
#ifndef TOLUA_DISABLE_tolua_set_Slider_repeatRate
static int tolua_set_Slider_repeatRate(lua_State* tolua_S)
{
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'repeatRate'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRepeatRate(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_new00
static int tolua_UILuaAPI_ScrollBar_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ScrollBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ScrollBar* tolua_ret = (ScrollBar*)  Mtolua_new((ScrollBar)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ScrollBar");
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

/* method: new_local of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_new00_local
static int tolua_UILuaAPI_ScrollBar_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ScrollBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ScrollBar* tolua_ret = (ScrollBar*)  Mtolua_new((ScrollBar)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ScrollBar");
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

/* method: delete of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_delete00
static int tolua_UILuaAPI_ScrollBar_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetOrientation of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_SetOrientation00
static int tolua_UILuaAPI_ScrollBar_SetOrientation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollBar",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
  Orientation orientation = ((Orientation) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOrientation'", NULL);
#endif
 {
  self->SetOrientation(orientation);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRange of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_SetRange00
static int tolua_UILuaAPI_ScrollBar_SetRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollBar",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
  float range = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRange'", NULL);
#endif
 {
  self->SetRange(range);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetValue of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_SetValue00
static int tolua_UILuaAPI_ScrollBar_SetValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollBar",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetValue'", NULL);
#endif
 {
  self->SetValue(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChangeValue of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_ChangeValue00
static int tolua_UILuaAPI_ScrollBar_ChangeValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollBar",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChangeValue'", NULL);
#endif
 {
  self->ChangeValue(delta);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChangeValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScrollStep of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_SetScrollStep00
static int tolua_UILuaAPI_ScrollBar_SetScrollStep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollBar",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
  float step = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScrollStep'", NULL);
#endif
 {
  self->SetScrollStep(step);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScrollStep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetStepFactor of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_SetStepFactor00
static int tolua_UILuaAPI_ScrollBar_SetStepFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollBar",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
  float factor = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetStepFactor'", NULL);
#endif
 {
  self->SetStepFactor(factor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetStepFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StepBack of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_StepBack00
static int tolua_UILuaAPI_ScrollBar_StepBack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StepBack'", NULL);
#endif
 {
  self->StepBack();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StepBack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StepForward of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_StepForward00
static int tolua_UILuaAPI_ScrollBar_StepForward00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StepForward'", NULL);
#endif
 {
  self->StepForward();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StepForward'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOrientation of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_GetOrientation00
static int tolua_UILuaAPI_ScrollBar_GetOrientation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollBar* self = (const ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOrientation'", NULL);
#endif
 {
  Orientation tolua_ret = (Orientation)  self->GetOrientation();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOrientation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRange of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_GetRange00
static int tolua_UILuaAPI_ScrollBar_GetRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollBar* self = (const ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRange'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRange();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetValue of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_GetValue00
static int tolua_UILuaAPI_ScrollBar_GetValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollBar* self = (const ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetValue'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetValue();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: GetScrollStep of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_GetScrollStep00
static int tolua_UILuaAPI_ScrollBar_GetScrollStep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollBar* self = (const ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScrollStep'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetScrollStep();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScrollStep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStepFactor of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_GetStepFactor00
static int tolua_UILuaAPI_ScrollBar_GetStepFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollBar* self = (const ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStepFactor'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetStepFactor();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStepFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEffectiveScrollStep of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_GetEffectiveScrollStep00
static int tolua_UILuaAPI_ScrollBar_GetEffectiveScrollStep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollBar* self = (const ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEffectiveScrollStep'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetEffectiveScrollStep();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEffectiveScrollStep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBackButton of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_GetBackButton00
static int tolua_UILuaAPI_ScrollBar_GetBackButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollBar* self = (const ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBackButton'", NULL);
#endif
 {
  Button* tolua_ret = (Button*)  self->GetBackButton();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Button");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBackButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetForwardButton of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_GetForwardButton00
static int tolua_UILuaAPI_ScrollBar_GetForwardButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollBar* self = (const ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetForwardButton'", NULL);
#endif
 {
  Button* tolua_ret = (Button*)  self->GetForwardButton();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Button");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetForwardButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSlider of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollBar_GetSlider00
static int tolua_UILuaAPI_ScrollBar_GetSlider00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollBar",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollBar* self = (const ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSlider'", NULL);
#endif
 {
  Slider* tolua_ret = (Slider*)  self->GetSlider();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Slider");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSlider'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: orientation of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_get_ScrollBar_orientation
static int tolua_get_ScrollBar_orientation(lua_State* tolua_S)
{
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'orientation'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetOrientation());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: orientation of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_set_ScrollBar_orientation
static int tolua_set_ScrollBar_orientation(lua_State* tolua_S)
{
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'orientation'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOrientation(((Orientation) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: range of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_get_ScrollBar_range
static int tolua_get_ScrollBar_range(lua_State* tolua_S)
{
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'range'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRange());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: range of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_set_ScrollBar_range
static int tolua_set_ScrollBar_range(lua_State* tolua_S)
{
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'range'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRange(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_get_ScrollBar_value
static int tolua_get_ScrollBar_value(lua_State* tolua_S)
{
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetValue());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_set_ScrollBar_value
static int tolua_set_ScrollBar_value(lua_State* tolua_S)
{
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetValue(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scrollStep of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_get_ScrollBar_scrollStep
static int tolua_get_ScrollBar_scrollStep(lua_State* tolua_S)
{
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollStep'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetScrollStep());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scrollStep of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_set_ScrollBar_scrollStep
static int tolua_set_ScrollBar_scrollStep(lua_State* tolua_S)
{
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollStep'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetScrollStep(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: stepFactor of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_get_ScrollBar_stepFactor
static int tolua_get_ScrollBar_stepFactor(lua_State* tolua_S)
{
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'stepFactor'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetStepFactor());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: stepFactor of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_set_ScrollBar_stepFactor
static int tolua_set_ScrollBar_stepFactor(lua_State* tolua_S)
{
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'stepFactor'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetStepFactor(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: effectiveScrollStep of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_get_ScrollBar_effectiveScrollStep
static int tolua_get_ScrollBar_effectiveScrollStep(lua_State* tolua_S)
{
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectiveScrollStep'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetEffectiveScrollStep());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: backButton of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_get_ScrollBar_backButton_ptr
static int tolua_get_ScrollBar_backButton_ptr(lua_State* tolua_S)
{
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'backButton'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetBackButton(),"Button");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: forwardButton of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_get_ScrollBar_forwardButton_ptr
static int tolua_get_ScrollBar_forwardButton_ptr(lua_State* tolua_S)
{
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'forwardButton'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetForwardButton(),"Button");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: slider of class  ScrollBar */
#ifndef TOLUA_DISABLE_tolua_get_ScrollBar_slider_ptr
static int tolua_get_ScrollBar_slider_ptr(lua_State* tolua_S)
{
  ScrollBar* self = (ScrollBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'slider'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetSlider(),"Slider");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_new00
static int tolua_UILuaAPI_ScrollView_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ScrollView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ScrollView* tolua_ret = (ScrollView*)  Mtolua_new((ScrollView)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ScrollView");
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

/* method: new_local of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_new00_local
static int tolua_UILuaAPI_ScrollView_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ScrollView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ScrollView* tolua_ret = (ScrollView*)  Mtolua_new((ScrollView)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ScrollView");
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

/* method: delete of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_delete00
static int tolua_UILuaAPI_ScrollView_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetContentElement of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_SetContentElement00
static int tolua_UILuaAPI_ScrollView_SetContentElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  UIElement* element = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetContentElement'", NULL);
#endif
 {
  self->SetContentElement(element);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetContentElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetViewPosition of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_SetViewPosition00
static int tolua_UILuaAPI_ScrollView_SetViewPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* position = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetViewPosition'", NULL);
#endif
 {
  self->SetViewPosition(*position);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetViewPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetViewPosition of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_SetViewPosition01
static int tolua_UILuaAPI_ScrollView_SetViewPosition01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetViewPosition'", NULL);
#endif
 {
  self->SetViewPosition(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_ScrollView_SetViewPosition00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScrollBarsVisible of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_SetScrollBarsVisible00
static int tolua_UILuaAPI_ScrollView_SetScrollBarsVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  bool horizontal = ((bool)  tolua_toboolean(tolua_S,2,0));
  bool vertical = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScrollBarsVisible'", NULL);
#endif
 {
  self->SetScrollBarsVisible(horizontal,vertical);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScrollBarsVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScrollBarsAutoVisible of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_SetScrollBarsAutoVisible00
static int tolua_UILuaAPI_ScrollView_SetScrollBarsAutoVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScrollBarsAutoVisible'", NULL);
#endif
 {
  self->SetScrollBarsAutoVisible(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScrollBarsAutoVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScrollStep of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_SetScrollStep00
static int tolua_UILuaAPI_ScrollView_SetScrollStep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  float step = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScrollStep'", NULL);
#endif
 {
  self->SetScrollStep(step);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScrollStep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPageStep of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_SetPageStep00
static int tolua_UILuaAPI_ScrollView_SetPageStep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  float step = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPageStep'", NULL);
#endif
 {
  self->SetPageStep(step);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPageStep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScrollDeceleration of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_SetScrollDeceleration00
static int tolua_UILuaAPI_ScrollView_SetScrollDeceleration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  float deceleration = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScrollDeceleration'", NULL);
#endif
 {
  self->SetScrollDeceleration(deceleration);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScrollDeceleration'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScrollSnapEpsilon of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_SetScrollSnapEpsilon00
static int tolua_UILuaAPI_ScrollView_SetScrollSnapEpsilon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  float snap = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScrollSnapEpsilon'", NULL);
#endif
 {
  self->SetScrollSnapEpsilon(snap);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScrollSnapEpsilon'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAutoDisableChildren of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_SetAutoDisableChildren00
static int tolua_UILuaAPI_ScrollView_SetAutoDisableChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  bool disable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAutoDisableChildren'", NULL);
#endif
 {
  self->SetAutoDisableChildren(disable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAutoDisableChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAutoDisableThreshold of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_SetAutoDisableThreshold00
static int tolua_UILuaAPI_ScrollView_SetAutoDisableThreshold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  float amount = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAutoDisableThreshold'", NULL);
#endif
 {
  self->SetAutoDisableThreshold(amount);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAutoDisableThreshold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetViewPosition of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_GetViewPosition00
static int tolua_UILuaAPI_ScrollView_GetViewPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollView* self = (const ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetViewPosition'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetViewPosition();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetViewPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetContentElement of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_GetContentElement00
static int tolua_UILuaAPI_ScrollView_GetContentElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollView* self = (const ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetContentElement'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetContentElement();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetContentElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHorizontalScrollBar of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_GetHorizontalScrollBar00
static int tolua_UILuaAPI_ScrollView_GetHorizontalScrollBar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollView* self = (const ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHorizontalScrollBar'", NULL);
#endif
 {
  ScrollBar* tolua_ret = (ScrollBar*)  self->GetHorizontalScrollBar();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ScrollBar");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHorizontalScrollBar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVerticalScrollBar of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_GetVerticalScrollBar00
static int tolua_UILuaAPI_ScrollView_GetVerticalScrollBar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollView* self = (const ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVerticalScrollBar'", NULL);
#endif
 {
  ScrollBar* tolua_ret = (ScrollBar*)  self->GetVerticalScrollBar();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ScrollBar");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVerticalScrollBar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScrollPanel of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_GetScrollPanel00
static int tolua_UILuaAPI_ScrollView_GetScrollPanel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollView* self = (const ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScrollPanel'", NULL);
#endif
 {
  BorderImage* tolua_ret = (BorderImage*)  self->GetScrollPanel();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BorderImage");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScrollPanel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScrollBarsAutoVisible of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_GetScrollBarsAutoVisible00
static int tolua_UILuaAPI_ScrollView_GetScrollBarsAutoVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollView* self = (const ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScrollBarsAutoVisible'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetScrollBarsAutoVisible();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScrollBarsAutoVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScrollStep of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_GetScrollStep00
static int tolua_UILuaAPI_ScrollView_GetScrollStep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollView* self = (const ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScrollStep'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetScrollStep();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScrollStep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPageStep of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_GetPageStep00
static int tolua_UILuaAPI_ScrollView_GetPageStep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollView* self = (const ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPageStep'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetPageStep();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPageStep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScrollDeceleration of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_GetScrollDeceleration00
static int tolua_UILuaAPI_ScrollView_GetScrollDeceleration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollView* self = (const ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScrollDeceleration'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetScrollDeceleration();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScrollDeceleration'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScrollSnapEpsilon of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_GetScrollSnapEpsilon00
static int tolua_UILuaAPI_ScrollView_GetScrollSnapEpsilon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollView* self = (const ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScrollSnapEpsilon'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetScrollSnapEpsilon();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScrollSnapEpsilon'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAutoDisableChildren of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_GetAutoDisableChildren00
static int tolua_UILuaAPI_ScrollView_GetAutoDisableChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollView* self = (const ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAutoDisableChildren'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetAutoDisableChildren();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAutoDisableChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAutoDisableThreshold of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ScrollView_GetAutoDisableThreshold00
static int tolua_UILuaAPI_ScrollView_GetAutoDisableThreshold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ScrollView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ScrollView* self = (const ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAutoDisableThreshold'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetAutoDisableThreshold();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAutoDisableThreshold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: viewPosition of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_viewPosition_ref
static int tolua_get_ScrollView_viewPosition_ref(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'viewPosition'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetViewPosition(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: viewPosition of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_ScrollView_viewPosition_ref
static int tolua_set_ScrollView_viewPosition_ref(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'viewPosition'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetViewPosition((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: contentElement of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_contentElement_ptr
static int tolua_get_ScrollView_contentElement_ptr(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'contentElement'",NULL);
#endif
  ToluaPushObject(tolua_S,(void*)self->GetContentElement(),"UIElement");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: contentElement of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_ScrollView_contentElement_ptr
static int tolua_set_ScrollView_contentElement_ptr(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'contentElement'",NULL);
 if (!tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetContentElement(((UIElement*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: horizontalScrollBar of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_horizontalScrollBar_ptr
static int tolua_get_ScrollView_horizontalScrollBar_ptr(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'horizontalScrollBar'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetHorizontalScrollBar(),"ScrollBar");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: verticalScrollBar of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_verticalScrollBar_ptr
static int tolua_get_ScrollView_verticalScrollBar_ptr(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'verticalScrollBar'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetVerticalScrollBar(),"ScrollBar");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scrollPanel of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_scrollPanel_ptr
static int tolua_get_ScrollView_scrollPanel_ptr(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollPanel'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetScrollPanel(),"BorderImage");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scrollBarsAutoVisible of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_scrollBarsAutoVisible
static int tolua_get_ScrollView_scrollBarsAutoVisible(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollBarsAutoVisible'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetScrollBarsAutoVisible());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scrollBarsAutoVisible of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_ScrollView_scrollBarsAutoVisible
static int tolua_set_ScrollView_scrollBarsAutoVisible(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollBarsAutoVisible'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetScrollBarsAutoVisible(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: horizontalScrollBarVisible of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_horizontalScrollBarVisible
static int tolua_get_ScrollView_horizontalScrollBarVisible(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'horizontalScrollBarVisible'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetHorizontalScrollBarVisible());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: horizontalScrollBarVisible of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_ScrollView_horizontalScrollBarVisible
static int tolua_set_ScrollView_horizontalScrollBarVisible(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'horizontalScrollBarVisible'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetHorizontalScrollBarVisible(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: verticalScrollBarVisible of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_verticalScrollBarVisible
static int tolua_get_ScrollView_verticalScrollBarVisible(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'verticalScrollBarVisible'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetVerticalScrollBarVisible());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: verticalScrollBarVisible of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_ScrollView_verticalScrollBarVisible
static int tolua_set_ScrollView_verticalScrollBarVisible(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'verticalScrollBarVisible'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetVerticalScrollBarVisible(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scrollStep of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_scrollStep
static int tolua_get_ScrollView_scrollStep(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollStep'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetScrollStep());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scrollStep of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_ScrollView_scrollStep
static int tolua_set_ScrollView_scrollStep(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollStep'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetScrollStep(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pageStep of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_pageStep
static int tolua_get_ScrollView_pageStep(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pageStep'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetPageStep());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pageStep of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_ScrollView_pageStep
static int tolua_set_ScrollView_pageStep(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pageStep'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPageStep(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scrollDeceleration of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_scrollDeceleration
static int tolua_get_ScrollView_scrollDeceleration(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollDeceleration'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetScrollDeceleration());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scrollDeceleration of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_ScrollView_scrollDeceleration
static int tolua_set_ScrollView_scrollDeceleration(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollDeceleration'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetScrollDeceleration(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scrollSnapEpsilon of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_scrollSnapEpsilon
static int tolua_get_ScrollView_scrollSnapEpsilon(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollSnapEpsilon'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetScrollSnapEpsilon());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scrollSnapEpsilon of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_ScrollView_scrollSnapEpsilon
static int tolua_set_ScrollView_scrollSnapEpsilon(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollSnapEpsilon'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetScrollSnapEpsilon(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_new00
static int tolua_UILuaAPI_ListView_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ListView* tolua_ret = (ListView*)  Mtolua_new((ListView)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ListView");
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

/* method: new_local of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_new00_local
static int tolua_UILuaAPI_ListView_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ListView* tolua_ret = (ListView*)  Mtolua_new((ListView)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ListView");
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

/* method: delete of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_delete00
static int tolua_UILuaAPI_ListView_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
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

/* method: UpdateInternalLayout of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_UpdateInternalLayout00
static int tolua_UILuaAPI_ListView_UpdateInternalLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UpdateInternalLayout'", NULL);
#endif
 {
  self->UpdateInternalLayout();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdateInternalLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DisableInternalLayoutUpdate of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_DisableInternalLayoutUpdate00
static int tolua_UILuaAPI_ListView_DisableInternalLayoutUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DisableInternalLayoutUpdate'", NULL);
#endif
 {
  self->DisableInternalLayoutUpdate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DisableInternalLayoutUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: EnableInternalLayoutUpdate of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_EnableInternalLayoutUpdate00
static int tolua_UILuaAPI_ListView_EnableInternalLayoutUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'EnableInternalLayoutUpdate'", NULL);
#endif
 {
  self->EnableInternalLayoutUpdate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EnableInternalLayoutUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddItem of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_AddItem00
static int tolua_UILuaAPI_ListView_AddItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  UIElement* item = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddItem'", NULL);
#endif
 {
  self->AddItem(item);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InsertItem of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_InsertItem00
static int tolua_UILuaAPI_ListView_InsertItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"UIElement",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,4,"UIElement",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  UIElement* item = ((UIElement*)  tolua_tousertype(tolua_S,3,0));
  UIElement* parentItem = ((UIElement*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InsertItem'", NULL);
#endif
 {
  self->InsertItem(index,item,parentItem);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InsertItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_RemoveItem00
static int tolua_UILuaAPI_ListView_RemoveItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  UIElement* item = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
 {
  self->RemoveItem(item,index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_RemoveItem01
static int tolua_UILuaAPI_ListView_RemoveItem01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
 {
  self->RemoveItem(index);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_ListView_RemoveItem00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllItems of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_RemoveAllItems00
static int tolua_UILuaAPI_ListView_RemoveAllItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllItems'", NULL);
#endif
 {
  self->RemoveAllItems();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSelection of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_SetSelection00
static int tolua_UILuaAPI_ListView_SetSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSelection'", NULL);
#endif
 {
  self->SetSelection(index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSelections of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_SetSelections00
static int tolua_UILuaAPI_ListView_SetSelections00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !ToluaIsPODVector<unsigned>(0.f,tolua_S,2,"unsigned",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  const PODVector<unsigned>* indices = ((const PODVector<unsigned>*)  ToluaToPODVector<unsigned>(0.f,tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSelections'", NULL);
#endif
 {
  self->SetSelections(*indices);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSelections'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddSelection of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_AddSelection00
static int tolua_UILuaAPI_ListView_AddSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddSelection'", NULL);
#endif
 {
  self->AddSelection(index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveSelection of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_RemoveSelection00
static int tolua_UILuaAPI_ListView_RemoveSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveSelection'", NULL);
#endif
 {
  self->RemoveSelection(index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToggleSelection of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_ToggleSelection00
static int tolua_UILuaAPI_ListView_ToggleSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToggleSelection'", NULL);
#endif
 {
  self->ToggleSelection(index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToggleSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChangeSelection of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_ChangeSelection00
static int tolua_UILuaAPI_ListView_ChangeSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  int delta = ((int)  tolua_tonumber(tolua_S,2,0));
  bool additive = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChangeSelection'", NULL);
#endif
 {
  self->ChangeSelection(delta,additive);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChangeSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearSelection of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_ClearSelection00
static int tolua_UILuaAPI_ListView_ClearSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearSelection'", NULL);
#endif
 {
  self->ClearSelection();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHighlightMode of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_SetHighlightMode00
static int tolua_UILuaAPI_ListView_SetHighlightMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  HighlightMode mode = ((HighlightMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHighlightMode'", NULL);
#endif
 {
  self->SetHighlightMode(mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHighlightMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMultiselect of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_SetMultiselect00
static int tolua_UILuaAPI_ListView_SetMultiselect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMultiselect'", NULL);
#endif
 {
  self->SetMultiselect(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMultiselect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHierarchyMode of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_SetHierarchyMode00
static int tolua_UILuaAPI_ListView_SetHierarchyMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHierarchyMode'", NULL);
#endif
 {
  self->SetHierarchyMode(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHierarchyMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseIndent of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_SetBaseIndent00
static int tolua_UILuaAPI_ListView_SetBaseIndent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  int baseIndent = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseIndent'", NULL);
#endif
 {
  self->SetBaseIndent(baseIndent);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseIndent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetClearSelectionOnDefocus of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_SetClearSelectionOnDefocus00
static int tolua_UILuaAPI_ListView_SetClearSelectionOnDefocus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetClearSelectionOnDefocus'", NULL);
#endif
 {
  self->SetClearSelectionOnDefocus(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetClearSelectionOnDefocus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSelectOnClickEnd of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_SetSelectOnClickEnd00
static int tolua_UILuaAPI_ListView_SetSelectOnClickEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSelectOnClickEnd'", NULL);
#endif
 {
  self->SetSelectOnClickEnd(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSelectOnClickEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Expand of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_Expand00
static int tolua_UILuaAPI_ListView_Expand00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  bool enable = ((bool)  tolua_toboolean(tolua_S,3,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,4,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Expand'", NULL);
#endif
 {
  self->Expand(index,enable,recursive);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Expand'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToggleExpand of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_ToggleExpand00
static int tolua_UILuaAPI_ListView_ToggleExpand00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ListView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  bool recursive = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToggleExpand'", NULL);
#endif
 {
  self->ToggleExpand(index,recursive);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToggleExpand'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumItems of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_GetNumItems00
static int tolua_UILuaAPI_ListView_GetNumItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumItems'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumItems();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItem of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_GetItem00
static int tolua_UILuaAPI_ListView_GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetItem(index);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ListViewGetItems of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_GetItems00
static int tolua_UILuaAPI_ListView_GetItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ListViewGetItems'", NULL);
#endif
 {
  tolua_outside  const PODVector<UIElement*>& tolua_ret = (tolua_outside  const PODVector<UIElement*>&)  ListViewGetItems(self);
  ToluaPushPODVector<UIElement*>("",tolua_S,(void*)&tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindItem of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_FindItem00
static int tolua_UILuaAPI_ListView_FindItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
  UIElement* item = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindItem'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->FindItem(item);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSelection of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_GetSelection00
static int tolua_UILuaAPI_ListView_GetSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSelection'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetSelection();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSelections of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_GetSelections00
static int tolua_UILuaAPI_ListView_GetSelections00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSelections'", NULL);
#endif
 {
  const PODVector<unsigned>& tolua_ret = (const PODVector<unsigned>&)  self->GetSelections();
  ToluaPushPODVector<unsigned>(0.f,tolua_S,(void*)&tolua_ret,"unsigned");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelections'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CopySelectedItemsToClipboard of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_CopySelectedItemsToClipboard00
static int tolua_UILuaAPI_ListView_CopySelectedItemsToClipboard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CopySelectedItemsToClipboard'", NULL);
#endif
 {
  self->CopySelectedItemsToClipboard();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CopySelectedItemsToClipboard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSelectedItem of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_GetSelectedItem00
static int tolua_UILuaAPI_ListView_GetSelectedItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSelectedItem'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetSelectedItem();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelectedItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ListViewGetSelectedItems of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_GetSelectedItems00
static int tolua_UILuaAPI_ListView_GetSelectedItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ListViewGetSelectedItems'", NULL);
#endif
 {
  tolua_outside  const PODVector<UIElement*>& tolua_ret = (tolua_outside  const PODVector<UIElement*>&)  ListViewGetSelectedItems(self);
  ToluaPushPODVector<UIElement*>("",tolua_S,(void*)&tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelectedItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsSelected of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_IsSelected00
static int tolua_UILuaAPI_ListView_IsSelected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsSelected'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsSelected(index);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsSelected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsExpanded of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_IsExpanded00
static int tolua_UILuaAPI_ListView_IsExpanded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsExpanded'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsExpanded(index);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsExpanded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHighlightMode of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_GetHighlightMode00
static int tolua_UILuaAPI_ListView_GetHighlightMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHighlightMode'", NULL);
#endif
 {
  HighlightMode tolua_ret = (HighlightMode)  self->GetHighlightMode();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHighlightMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMultiselect of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_GetMultiselect00
static int tolua_UILuaAPI_ListView_GetMultiselect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMultiselect'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetMultiselect();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMultiselect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetClearSelectionOnDefocus of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_GetClearSelectionOnDefocus00
static int tolua_UILuaAPI_ListView_GetClearSelectionOnDefocus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClearSelectionOnDefocus'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetClearSelectionOnDefocus();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClearSelectionOnDefocus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSelectOnClickEnd of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_GetSelectOnClickEnd00
static int tolua_UILuaAPI_ListView_GetSelectOnClickEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSelectOnClickEnd'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetSelectOnClickEnd();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelectOnClickEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHierarchyMode of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_GetHierarchyMode00
static int tolua_UILuaAPI_ListView_GetHierarchyMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHierarchyMode'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetHierarchyMode();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHierarchyMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseIndent of class  ListView */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ListView_GetBaseIndent00
static int tolua_UILuaAPI_ListView_GetBaseIndent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ListView",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ListView* self = (const ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseIndent'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetBaseIndent();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseIndent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numItems of class  ListView */
#ifndef TOLUA_DISABLE_tolua_get_ListView_numItems
static int tolua_get_ListView_numItems(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numItems'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumItems());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: selection of class  ListView */
#ifndef TOLUA_DISABLE_tolua_get_ListView_selection
static int tolua_get_ListView_selection(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'selection'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSelection());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: selection of class  ListView */
#ifndef TOLUA_DISABLE_tolua_set_ListView_selection
static int tolua_set_ListView_selection(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'selection'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSelection(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: selectedItem of class  ListView */
#ifndef TOLUA_DISABLE_tolua_get_ListView_selectedItem_ptr
static int tolua_get_ListView_selectedItem_ptr(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'selectedItem'",NULL);
#endif
  ToluaPushObject(tolua_S,(void*)self->GetSelectedItem(),"UIElement");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: highlightMode of class  ListView */
#ifndef TOLUA_DISABLE_tolua_get_ListView_highlightMode
static int tolua_get_ListView_highlightMode(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'highlightMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetHighlightMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: highlightMode of class  ListView */
#ifndef TOLUA_DISABLE_tolua_set_ListView_highlightMode
static int tolua_set_ListView_highlightMode(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'highlightMode'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetHighlightMode(((HighlightMode) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: multiselect of class  ListView */
#ifndef TOLUA_DISABLE_tolua_get_ListView_multiselect
static int tolua_get_ListView_multiselect(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'multiselect'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetMultiselect());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: multiselect of class  ListView */
#ifndef TOLUA_DISABLE_tolua_set_ListView_multiselect
static int tolua_set_ListView_multiselect(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'multiselect'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMultiselect(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: clearSelectionOnDefocus of class  ListView */
#ifndef TOLUA_DISABLE_tolua_get_ListView_clearSelectionOnDefocus
static int tolua_get_ListView_clearSelectionOnDefocus(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'clearSelectionOnDefocus'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetClearSelectionOnDefocus());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: clearSelectionOnDefocus of class  ListView */
#ifndef TOLUA_DISABLE_tolua_set_ListView_clearSelectionOnDefocus
static int tolua_set_ListView_clearSelectionOnDefocus(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'clearSelectionOnDefocus'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetClearSelectionOnDefocus(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: selectOnClickEnd of class  ListView */
#ifndef TOLUA_DISABLE_tolua_get_ListView_selectOnClickEnd
static int tolua_get_ListView_selectOnClickEnd(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'selectOnClickEnd'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetSelectOnClickEnd());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: selectOnClickEnd of class  ListView */
#ifndef TOLUA_DISABLE_tolua_set_ListView_selectOnClickEnd
static int tolua_set_ListView_selectOnClickEnd(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'selectOnClickEnd'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSelectOnClickEnd(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: hierarchyMode of class  ListView */
#ifndef TOLUA_DISABLE_tolua_get_ListView_hierarchyMode
static int tolua_get_ListView_hierarchyMode(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hierarchyMode'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetHierarchyMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: hierarchyMode of class  ListView */
#ifndef TOLUA_DISABLE_tolua_set_ListView_hierarchyMode
static int tolua_set_ListView_hierarchyMode(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hierarchyMode'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetHierarchyMode(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: baseIndent of class  ListView */
#ifndef TOLUA_DISABLE_tolua_get_ListView_baseIndent
static int tolua_get_ListView_baseIndent(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'baseIndent'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetBaseIndent());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: baseIndent of class  ListView */
#ifndef TOLUA_DISABLE_tolua_set_ListView_baseIndent
static int tolua_set_ListView_baseIndent(lua_State* tolua_S)
{
  ListView* self = (ListView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'baseIndent'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetBaseIndent(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_new00
static int tolua_UILuaAPI_Sprite_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Sprite* tolua_ret = (Sprite*)  Mtolua_new((Sprite)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite");
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

/* method: new_local of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_new00_local
static int tolua_UILuaAPI_Sprite_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Sprite* tolua_ret = (Sprite*)  Mtolua_new((Sprite)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite");
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

/* method: delete of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_delete00
static int tolua_UILuaAPI_Sprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetPosition of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_SetPosition00
static int tolua_UILuaAPI_Sprite_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* position = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
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

/* method: SetPosition of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_SetPosition01
static int tolua_UILuaAPI_Sprite_SetPosition01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
 {
  self->SetPosition(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_Sprite_SetPosition00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHotSpot of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_SetHotSpot00
static int tolua_UILuaAPI_Sprite_SetHotSpot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* hotSpot = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
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

/* method: SetHotSpot of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_SetHotSpot01
static int tolua_UILuaAPI_Sprite_SetHotSpot01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHotSpot'", NULL);
#endif
 {
  self->SetHotSpot(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_Sprite_SetHotSpot00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_SetScale00
static int tolua_UILuaAPI_Sprite_SetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* scale = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale'", NULL);
#endif
 {
  self->SetScale(*scale);
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

/* method: SetScale of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_SetScale01
static int tolua_UILuaAPI_Sprite_SetScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale'", NULL);
#endif
 {
  self->SetScale(x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_Sprite_SetScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_SetScale02
static int tolua_UILuaAPI_Sprite_SetScale02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  float scale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale'", NULL);
#endif
 {
  self->SetScale(scale);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_Sprite_SetScale01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRotation of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_SetRotation00
static int tolua_UILuaAPI_Sprite_SetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRotation'", NULL);
#endif
 {
  self->SetRotation(angle);
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

/* method: SetTexture of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_SetTexture00
static int tolua_UILuaAPI_Sprite_SetTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Texture",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  Texture* texture = ((Texture*)  tolua_tousertype(tolua_S,2,0));
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

/* method: SetImageRect of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_SetImageRect00
static int tolua_UILuaAPI_Sprite_SetImageRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* rect = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetImageRect'", NULL);
#endif
 {
  self->SetImageRect(*rect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetImageRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFullImageRect of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_SetFullImageRect00
static int tolua_UILuaAPI_Sprite_SetFullImageRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFullImageRect'", NULL);
#endif
 {
  self->SetFullImageRect();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFullImageRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBlendMode of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_SetBlendMode00
static int tolua_UILuaAPI_Sprite_SetBlendMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetPosition of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_GetPosition00
static int tolua_UILuaAPI_Sprite_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sprite",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sprite* self = (const Sprite*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetHotSpot of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_GetHotSpot00
static int tolua_UILuaAPI_Sprite_GetHotSpot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sprite",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sprite* self = (const Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHotSpot'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetHotSpot();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
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

/* method: GetScale of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_GetScale00
static int tolua_UILuaAPI_Sprite_GetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sprite",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sprite* self = (const Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScale'", NULL);
#endif
 {
  const Vector2& tolua_ret = (const Vector2&)  self->GetScale();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector2");
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

/* method: GetRotation of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_GetRotation00
static int tolua_UILuaAPI_Sprite_GetRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sprite",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sprite* self = (const Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRotation'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRotation();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: GetTexture of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_GetTexture00
static int tolua_UILuaAPI_Sprite_GetTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sprite",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sprite* self = (const Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTexture'", NULL);
#endif
 {
  Texture* tolua_ret = (Texture*)  self->GetTexture();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture");
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

/* method: GetImageRect of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_GetImageRect00
static int tolua_UILuaAPI_Sprite_GetImageRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sprite",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sprite* self = (const Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetImageRect'", NULL);
#endif
 {
  const IntRect& tolua_ret = (const IntRect&)  self->GetImageRect();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntRect");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetImageRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBlendMode of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_GetBlendMode00
static int tolua_UILuaAPI_Sprite_GetBlendMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sprite",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sprite* self = (const Sprite*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetTransform of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Sprite_GetTransform00
static int tolua_UILuaAPI_Sprite_GetTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Sprite",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Sprite* self = (const Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTransform'", NULL);
#endif
 {
  const Matrix3x4& tolua_ret = (const Matrix3x4&)  self->GetTransform();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Matrix3x4");
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

/* get function: position of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_get_Sprite_position_ref
static int tolua_get_Sprite_position_ref(lua_State* tolua_S)
{
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetPosition(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: position of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_set_Sprite_position_ref
static int tolua_set_Sprite_position_ref(lua_State* tolua_S)
{
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPosition((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: hotSpot of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_get_Sprite_hotSpot_ref
static int tolua_get_Sprite_hotSpot_ref(lua_State* tolua_S)
{
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hotSpot'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetHotSpot(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: hotSpot of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_set_Sprite_hotSpot_ref
static int tolua_set_Sprite_hotSpot_ref(lua_State* tolua_S)
{
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hotSpot'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetHotSpot((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scale of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_get_Sprite_scale_ref
static int tolua_get_Sprite_scale_ref(lua_State* tolua_S)
{
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetScale(),"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scale of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_set_Sprite_scale_ref
static int tolua_set_Sprite_scale_ref(lua_State* tolua_S)
{
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetScale((*(Vector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rotation of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_get_Sprite_rotation
static int tolua_get_Sprite_rotation(lua_State* tolua_S)
{
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRotation());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rotation of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_set_Sprite_rotation
static int tolua_set_Sprite_rotation(lua_State* tolua_S)
{
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRotation(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: texture of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_get_Sprite_texture_ptr
static int tolua_get_Sprite_texture_ptr(lua_State* tolua_S)
{
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texture'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetTexture(),"Texture");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: texture of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_set_Sprite_texture_ptr
static int tolua_set_Sprite_texture_ptr(lua_State* tolua_S)
{
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texture'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Texture",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTexture(((Texture*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: imageRect of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_get_Sprite_imageRect_ref
static int tolua_get_Sprite_imageRect_ref(lua_State* tolua_S)
{
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageRect'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetImageRect(),"IntRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: imageRect of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_set_Sprite_imageRect_ref
static int tolua_set_Sprite_imageRect_ref(lua_State* tolua_S)
{
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageRect'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntRect",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetImageRect((*(IntRect*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: blendMode of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_get_Sprite_blendMode
static int tolua_get_Sprite_blendMode(lua_State* tolua_S)
{
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blendMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetBlendMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: blendMode of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_set_Sprite_blendMode
static int tolua_set_Sprite_blendMode(lua_State* tolua_S)
{
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: transform of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_get_Sprite_transform_ref
static int tolua_get_Sprite_transform_ref(lua_State* tolua_S)
{
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'transform'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetTransform(),"Matrix3x4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_new00
static int tolua_UILuaAPI_Text_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Text* tolua_ret = (Text*)  Mtolua_new((Text)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Text");
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

/* method: new_local of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_new00_local
static int tolua_UILuaAPI_Text_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Text* tolua_ret = (Text*)  Mtolua_new((Text)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Text");
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

/* method: delete of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_delete00
static int tolua_UILuaAPI_Text_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetFont of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_SetFont00
static int tolua_UILuaAPI_Text_SetFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  const String fontName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  float size = ((float)  tolua_tonumber(tolua_S,3,DEFAULT_FONT_SIZE));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFont'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetFont(fontName,size);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFont of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_SetFont01
static int tolua_UILuaAPI_Text_SetFont01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Font",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  Font* font = ((Font*)  tolua_tousertype(tolua_S,2,0));
  float size = ((float)  tolua_tonumber(tolua_S,3,DEFAULT_FONT_SIZE));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFont'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetFont(font,size);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_UILuaAPI_Text_SetFont00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFontSize of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_SetFontSize00
static int tolua_UILuaAPI_Text_SetFontSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  float size = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFontSize'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetFontSize(size);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFontSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetText of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_SetText00
static int tolua_UILuaAPI_Text_SetText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  const String text = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetText'", NULL);
#endif
 {
  self->SetText(text);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextAlignment of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_SetTextAlignment00
static int tolua_UILuaAPI_Text_SetTextAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  HorizontalAlignment align = ((HorizontalAlignment) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextAlignment'", NULL);
#endif
 {
  self->SetTextAlignment(align);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRowSpacing of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_SetRowSpacing00
static int tolua_UILuaAPI_Text_SetRowSpacing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  float spacing = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRowSpacing'", NULL);
#endif
 {
  self->SetRowSpacing(spacing);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRowSpacing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWordwrap of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_SetWordwrap00
static int tolua_UILuaAPI_Text_SetWordwrap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWordwrap'", NULL);
#endif
 {
  self->SetWordwrap(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWordwrap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSelection of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_SetSelection00
static int tolua_UILuaAPI_Text_SetSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  unsigned start = ((unsigned)  tolua_tonumber(tolua_S,2,0));
  unsigned length = ((unsigned)  tolua_tonumber(tolua_S,3,M_MAX_UNSIGNED));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSelection'", NULL);
#endif
 {
  self->SetSelection(start,length);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearSelection of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_ClearSelection00
static int tolua_UILuaAPI_Text_ClearSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearSelection'", NULL);
#endif
 {
  self->ClearSelection();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextEffect of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_SetTextEffect00
static int tolua_UILuaAPI_Text_SetTextEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  TextEffect textEffect = ((TextEffect) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextEffect'", NULL);
#endif
 {
  self->SetTextEffect(textEffect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEffectShadowOffset of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_SetEffectShadowOffset00
static int tolua_UILuaAPI_Text_SetEffectShadowOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* offset = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEffectShadowOffset'", NULL);
#endif
 {
  self->SetEffectShadowOffset(*offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEffectShadowOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEffectStrokeThickness of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_SetEffectStrokeThickness00
static int tolua_UILuaAPI_Text_SetEffectStrokeThickness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  int thickness = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEffectStrokeThickness'", NULL);
#endif
 {
  self->SetEffectStrokeThickness(thickness);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEffectStrokeThickness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEffectRoundStroke of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_SetEffectRoundStroke00
static int tolua_UILuaAPI_Text_SetEffectRoundStroke00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  bool roundStroke = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEffectRoundStroke'", NULL);
#endif
 {
  self->SetEffectRoundStroke(roundStroke);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEffectRoundStroke'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEffectColor of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_SetEffectColor00
static int tolua_UILuaAPI_Text_SetEffectColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  const Color* effectColor = ((const Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEffectColor'", NULL);
#endif
 {
  self->SetEffectColor(*effectColor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEffectColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAutoLocalizable of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetAutoLocalizable00
static int tolua_UILuaAPI_Text_GetAutoLocalizable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAutoLocalizable'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetAutoLocalizable();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAutoLocalizable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAutoLocalizable of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_SetAutoLocalizable00
static int tolua_UILuaAPI_Text_SetAutoLocalizable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAutoLocalizable'", NULL);
#endif
 {
  self->SetAutoLocalizable(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAutoLocalizable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFont of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetFont00
static int tolua_UILuaAPI_Text_GetFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFont'", NULL);
#endif
 {
  Font* tolua_ret = (Font*)  self->GetFont();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Font");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFontSize of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetFontSize00
static int tolua_UILuaAPI_Text_GetFontSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFontSize'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetFontSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetText of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetText00
static int tolua_UILuaAPI_Text_GetText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetText'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetText();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextAlignment of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetTextAlignment00
static int tolua_UILuaAPI_Text_GetTextAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextAlignment'", NULL);
#endif
 {
  HorizontalAlignment tolua_ret = (HorizontalAlignment)  self->GetTextAlignment();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRowSpacing of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetRowSpacing00
static int tolua_UILuaAPI_Text_GetRowSpacing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRowSpacing'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRowSpacing();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRowSpacing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWordwrap of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetWordwrap00
static int tolua_UILuaAPI_Text_GetWordwrap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWordwrap'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetWordwrap();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWordwrap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSelectionStart of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetSelectionStart00
static int tolua_UILuaAPI_Text_GetSelectionStart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSelectionStart'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetSelectionStart();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelectionStart'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSelectionLength of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetSelectionLength00
static int tolua_UILuaAPI_Text_GetSelectionLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSelectionLength'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetSelectionLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelectionLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextEffect of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetTextEffect00
static int tolua_UILuaAPI_Text_GetTextEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextEffect'", NULL);
#endif
 {
  TextEffect tolua_ret = (TextEffect)  self->GetTextEffect();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEffectShadowOffset of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetEffectShadowOffset00
static int tolua_UILuaAPI_Text_GetEffectShadowOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEffectShadowOffset'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetEffectShadowOffset();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEffectShadowOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEffectStrokeThickness of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetEffectStrokeThickness00
static int tolua_UILuaAPI_Text_GetEffectStrokeThickness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEffectStrokeThickness'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetEffectStrokeThickness();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEffectStrokeThickness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEffectRoundStroke of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetEffectRoundStroke00
static int tolua_UILuaAPI_Text_GetEffectRoundStroke00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEffectRoundStroke'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetEffectRoundStroke();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEffectRoundStroke'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEffectColor of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetEffectColor00
static int tolua_UILuaAPI_Text_GetEffectColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEffectColor'", NULL);
#endif
 {
  const Color& tolua_ret = (const Color&)  self->GetEffectColor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Color");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEffectColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRowHeight of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetRowHeight00
static int tolua_UILuaAPI_Text_GetRowHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRowHeight'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRowHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRowHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumRows of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetNumRows00
static int tolua_UILuaAPI_Text_GetNumRows00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetNumChars of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetNumChars00
static int tolua_UILuaAPI_Text_GetNumChars00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumChars'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumChars();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumChars'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRowWidth of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetRowWidth00
static int tolua_UILuaAPI_Text_GetRowWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRowWidth'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRowWidth(index);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRowWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCharPosition of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetCharPosition00
static int tolua_UILuaAPI_Text_GetCharPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCharPosition'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->GetCharPosition(index);
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
 tolua_error(tolua_S,"#ferror in function 'GetCharPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCharSize of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetCharSize00
static int tolua_UILuaAPI_Text_GetCharSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCharSize'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->GetCharSize(index);
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
 tolua_error(tolua_S,"#ferror in function 'GetCharSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEffectDepthBias of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_SetEffectDepthBias00
static int tolua_UILuaAPI_Text_SetEffectDepthBias00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  float bias = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEffectDepthBias'", NULL);
#endif
 {
  self->SetEffectDepthBias(bias);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEffectDepthBias'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEffectDepthBias of class  Text */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text_GetEffectDepthBias00
static int tolua_UILuaAPI_Text_GetEffectDepthBias00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text* self = (const Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEffectDepthBias'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetEffectDepthBias();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEffectDepthBias'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: font of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_font_ptr
static int tolua_get_Text_font_ptr(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'font'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetFont(),"Font");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: font of class  Text */
#ifndef TOLUA_DISABLE_tolua_set_Text_font_ptr
static int tolua_set_Text_font_ptr(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'font'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Font",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFont(((Font*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fontSize of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_fontSize
static int tolua_get_Text_fontSize(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fontSize'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFontSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: fontSize of class  Text */
#ifndef TOLUA_DISABLE_tolua_set_Text_fontSize
static int tolua_set_Text_fontSize(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fontSize'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFontSize(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: text of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_text
static int tolua_get_Text_text(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'text'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetText());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: text of class  Text */
#ifndef TOLUA_DISABLE_tolua_set_Text_text
static int tolua_set_Text_text(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'text'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetText(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: textAlignment of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_textAlignment
static int tolua_get_Text_textAlignment(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textAlignment'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTextAlignment());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: textAlignment of class  Text */
#ifndef TOLUA_DISABLE_tolua_set_Text_textAlignment
static int tolua_set_Text_textAlignment(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textAlignment'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTextAlignment(((HorizontalAlignment) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rowSpacing of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_rowSpacing
static int tolua_get_Text_rowSpacing(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rowSpacing'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRowSpacing());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rowSpacing of class  Text */
#ifndef TOLUA_DISABLE_tolua_set_Text_rowSpacing
static int tolua_set_Text_rowSpacing(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rowSpacing'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRowSpacing(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wordwrap of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_wordwrap
static int tolua_get_Text_wordwrap(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'wordwrap'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetWordwrap());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: wordwrap of class  Text */
#ifndef TOLUA_DISABLE_tolua_set_Text_wordwrap
static int tolua_set_Text_wordwrap(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'wordwrap'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetWordwrap(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: autoLocalizable of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_autoLocalizable
static int tolua_get_Text_autoLocalizable(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'autoLocalizable'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetAutoLocalizable());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: autoLocalizable of class  Text */
#ifndef TOLUA_DISABLE_tolua_set_Text_autoLocalizable
static int tolua_set_Text_autoLocalizable(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'autoLocalizable'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAutoLocalizable(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: selectionStart of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_selectionStart
static int tolua_get_Text_selectionStart(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'selectionStart'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSelectionStart());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: selectionLength of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_selectionLength
static int tolua_get_Text_selectionLength(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'selectionLength'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetSelectionLength());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: textEffect of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_textEffect
static int tolua_get_Text_textEffect(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textEffect'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTextEffect());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: textEffect of class  Text */
#ifndef TOLUA_DISABLE_tolua_set_Text_textEffect
static int tolua_set_Text_textEffect(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textEffect'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTextEffect(((TextEffect) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: effectShadowOffset of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_effectShadowOffset_ref
static int tolua_get_Text_effectShadowOffset_ref(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectShadowOffset'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetEffectShadowOffset(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: effectShadowOffset of class  Text */
#ifndef TOLUA_DISABLE_tolua_set_Text_effectShadowOffset_ref
static int tolua_set_Text_effectShadowOffset_ref(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectShadowOffset'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEffectShadowOffset((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: effectStrokeThickness of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_effectStrokeThickness
static int tolua_get_Text_effectStrokeThickness(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectStrokeThickness'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetEffectStrokeThickness());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: effectStrokeThickness of class  Text */
#ifndef TOLUA_DISABLE_tolua_set_Text_effectStrokeThickness
static int tolua_set_Text_effectStrokeThickness(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectStrokeThickness'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEffectStrokeThickness(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: effectRoundStroke of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_effectRoundStroke
static int tolua_get_Text_effectRoundStroke(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectRoundStroke'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetEffectRoundStroke());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: effectRoundStroke of class  Text */
#ifndef TOLUA_DISABLE_tolua_set_Text_effectRoundStroke
static int tolua_set_Text_effectRoundStroke(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectRoundStroke'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEffectRoundStroke(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: effectColor of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_effectColor_ref
static int tolua_get_Text_effectColor_ref(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectColor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetEffectColor(),"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: effectColor of class  Text */
#ifndef TOLUA_DISABLE_tolua_set_Text_effectColor_ref
static int tolua_set_Text_effectColor_ref(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectColor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEffectColor((*(Color*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rowHeight of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_rowHeight
static int tolua_get_Text_rowHeight(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rowHeight'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRowHeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numRows of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_numRows
static int tolua_get_Text_numRows(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numRows'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumRows());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numChars of class  Text */
#ifndef TOLUA_DISABLE_tolua_get_Text_numChars
static int tolua_get_Text_numChars(lua_State* tolua_S)
{
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numChars'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumChars());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_new00
static int tolua_UILuaAPI_Text3D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Text3D* tolua_ret = (Text3D*)  Mtolua_new((Text3D)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Text3D");
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

/* method: new_local of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_new00_local
static int tolua_UILuaAPI_Text3D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Text3D* tolua_ret = (Text3D*)  Mtolua_new((Text3D)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Text3D");
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

/* method: delete of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_delete00
static int tolua_UILuaAPI_Text3D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetFont of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetFont00
static int tolua_UILuaAPI_Text3D_SetFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  const String fontName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  float size = ((float)  tolua_tonumber(tolua_S,3,DEFAULT_FONT_SIZE));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFont'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetFont(fontName,size);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFont of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetFont01
static int tolua_UILuaAPI_Text3D_SetFont01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Font",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  Font* font = ((Font*)  tolua_tousertype(tolua_S,2,0));
  float size = ((float)  tolua_tonumber(tolua_S,3,DEFAULT_FONT_SIZE));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFont'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetFont(font,size);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_UILuaAPI_Text3D_SetFont00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFontSize of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetFontSize00
static int tolua_UILuaAPI_Text3D_SetFontSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  float size = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFontSize'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetFontSize(size);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFontSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaterial of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetMaterial00
static int tolua_UILuaAPI_Text3D_SetMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Material",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  Material* material = ((Material*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaterial'", NULL);
#endif
 {
  self->SetMaterial(material);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetText of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetText00
static int tolua_UILuaAPI_Text3D_SetText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  const String text = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetText'", NULL);
#endif
 {
  self->SetText(text);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAlignment of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetAlignment00
static int tolua_UILuaAPI_Text3D_SetAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  HorizontalAlignment hAlign = ((HorizontalAlignment) (int)  tolua_tonumber(tolua_S,2,0));
  VerticalAlignment vAlign = ((VerticalAlignment) (int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAlignment'", NULL);
#endif
 {
  self->SetAlignment(hAlign,vAlign);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHorizontalAlignment of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetHorizontalAlignment00
static int tolua_UILuaAPI_Text3D_SetHorizontalAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  HorizontalAlignment align = ((HorizontalAlignment) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHorizontalAlignment'", NULL);
#endif
 {
  self->SetHorizontalAlignment(align);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHorizontalAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVerticalAlignment of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetVerticalAlignment00
static int tolua_UILuaAPI_Text3D_SetVerticalAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  VerticalAlignment align = ((VerticalAlignment) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVerticalAlignment'", NULL);
#endif
 {
  self->SetVerticalAlignment(align);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVerticalAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextAlignment of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetTextAlignment00
static int tolua_UILuaAPI_Text3D_SetTextAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  HorizontalAlignment align = ((HorizontalAlignment) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextAlignment'", NULL);
#endif
 {
  self->SetTextAlignment(align);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRowSpacing of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetRowSpacing00
static int tolua_UILuaAPI_Text3D_SetRowSpacing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  float spacing = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRowSpacing'", NULL);
#endif
 {
  self->SetRowSpacing(spacing);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRowSpacing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWordwrap of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetWordwrap00
static int tolua_UILuaAPI_Text3D_SetWordwrap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWordwrap'", NULL);
#endif
 {
  self->SetWordwrap(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWordwrap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextEffect of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetTextEffect00
static int tolua_UILuaAPI_Text3D_SetTextEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  TextEffect textEffect = ((TextEffect) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextEffect'", NULL);
#endif
 {
  self->SetTextEffect(textEffect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEffectShadowOffset of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetEffectShadowOffset00
static int tolua_UILuaAPI_Text3D_SetEffectShadowOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* offset = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEffectShadowOffset'", NULL);
#endif
 {
  self->SetEffectShadowOffset(*offset);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEffectShadowOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEffectStrokeThickness of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetEffectStrokeThickness00
static int tolua_UILuaAPI_Text3D_SetEffectStrokeThickness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  int thickness = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEffectStrokeThickness'", NULL);
#endif
 {
  self->SetEffectStrokeThickness(thickness);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEffectStrokeThickness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEffectRoundStroke of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetEffectRoundStroke00
static int tolua_UILuaAPI_Text3D_SetEffectRoundStroke00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  bool roundStroke = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEffectRoundStroke'", NULL);
#endif
 {
  self->SetEffectRoundStroke(roundStroke);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEffectRoundStroke'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEffectColor of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetEffectColor00
static int tolua_UILuaAPI_Text3D_SetEffectColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  const Color* effectColor = ((const Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEffectColor'", NULL);
#endif
 {
  self->SetEffectColor(*effectColor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEffectColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEffectDepthBias of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetEffectDepthBias00
static int tolua_UILuaAPI_Text3D_SetEffectDepthBias00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  float bias = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEffectDepthBias'", NULL);
#endif
 {
  self->SetEffectDepthBias(bias);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEffectDepthBias'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWidth of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetWidth00
static int tolua_UILuaAPI_Text3D_SetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWidth'", NULL);
#endif
 {
  self->SetWidth(width);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetColor of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetColor00
static int tolua_UILuaAPI_Text3D_SetColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetColor of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetColor01
static int tolua_UILuaAPI_Text3D_SetColor01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  Corner corner = ((Corner) (int)  tolua_tonumber(tolua_S,2,0));
  const Color* color = ((const Color*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetColor'", NULL);
#endif
 {
  self->SetColor(corner,*color);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_Text3D_SetColor00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOpacity of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetOpacity00
static int tolua_UILuaAPI_Text3D_SetOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  float opacity = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOpacity'", NULL);
#endif
 {
  self->SetOpacity(opacity);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFixedScreenSize of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetFixedScreenSize00
static int tolua_UILuaAPI_Text3D_SetFixedScreenSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFixedScreenSize'", NULL);
#endif
 {
  self->SetFixedScreenSize(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFixedScreenSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFaceCameraMode of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_SetFaceCameraMode00
static int tolua_UILuaAPI_Text3D_SetFaceCameraMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  FaceCameraMode mode = ((FaceCameraMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFaceCameraMode'", NULL);
#endif
 {
  self->SetFaceCameraMode(mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFaceCameraMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFont of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetFont00
static int tolua_UILuaAPI_Text3D_GetFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFont'", NULL);
#endif
 {
  Font* tolua_ret = (Font*)  self->GetFont();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Font");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaterial of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetMaterial00
static int tolua_UILuaAPI_Text3D_GetMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaterial'", NULL);
#endif
 {
  Material* tolua_ret = (Material*)  self->GetMaterial();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Material");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFontSize of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetFontSize00
static int tolua_UILuaAPI_Text3D_GetFontSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFontSize'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetFontSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetText of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetText00
static int tolua_UILuaAPI_Text3D_GetText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetText'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetText();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextAlignment of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetTextAlignment00
static int tolua_UILuaAPI_Text3D_GetTextAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextAlignment'", NULL);
#endif
 {
  HorizontalAlignment tolua_ret = (HorizontalAlignment)  self->GetTextAlignment();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHorizontalAlignment of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetHorizontalAlignment00
static int tolua_UILuaAPI_Text3D_GetHorizontalAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHorizontalAlignment'", NULL);
#endif
 {
  HorizontalAlignment tolua_ret = (HorizontalAlignment)  self->GetHorizontalAlignment();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHorizontalAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVerticalAlignment of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetVerticalAlignment00
static int tolua_UILuaAPI_Text3D_GetVerticalAlignment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVerticalAlignment'", NULL);
#endif
 {
  VerticalAlignment tolua_ret = (VerticalAlignment)  self->GetVerticalAlignment();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVerticalAlignment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRowSpacing of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetRowSpacing00
static int tolua_UILuaAPI_Text3D_GetRowSpacing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRowSpacing'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRowSpacing();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRowSpacing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWordwrap of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetWordwrap00
static int tolua_UILuaAPI_Text3D_GetWordwrap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWordwrap'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetWordwrap();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWordwrap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextEffect of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetTextEffect00
static int tolua_UILuaAPI_Text3D_GetTextEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextEffect'", NULL);
#endif
 {
  TextEffect tolua_ret = (TextEffect)  self->GetTextEffect();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEffectShadowOffset of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetEffectShadowOffset00
static int tolua_UILuaAPI_Text3D_GetEffectShadowOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEffectShadowOffset'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetEffectShadowOffset();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEffectShadowOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEffectStrokeThickness of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetEffectStrokeThickness00
static int tolua_UILuaAPI_Text3D_GetEffectStrokeThickness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEffectStrokeThickness'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetEffectStrokeThickness();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEffectStrokeThickness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEffectRoundStroke of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetEffectRoundStroke00
static int tolua_UILuaAPI_Text3D_GetEffectRoundStroke00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEffectRoundStroke'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetEffectRoundStroke();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEffectRoundStroke'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEffectColor of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetEffectColor00
static int tolua_UILuaAPI_Text3D_GetEffectColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEffectColor'", NULL);
#endif
 {
  const Color& tolua_ret = (const Color&)  self->GetEffectColor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Color");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEffectColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEffectDepthBias of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetEffectDepthBias00
static int tolua_UILuaAPI_Text3D_GetEffectDepthBias00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEffectDepthBias'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetEffectDepthBias();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEffectDepthBias'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidth of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetWidth00
static int tolua_UILuaAPI_Text3D_GetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetHeight of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetHeight00
static int tolua_UILuaAPI_Text3D_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetRowHeight of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetRowHeight00
static int tolua_UILuaAPI_Text3D_GetRowHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRowHeight'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRowHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRowHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumRows of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetNumRows00
static int tolua_UILuaAPI_Text3D_GetNumRows00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetNumChars of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetNumChars00
static int tolua_UILuaAPI_Text3D_GetNumChars00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumChars'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumChars();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumChars'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRowWidth of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetRowWidth00
static int tolua_UILuaAPI_Text3D_GetRowWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRowWidth'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetRowWidth(index);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRowWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCharPosition of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetCharPosition00
static int tolua_UILuaAPI_Text3D_GetCharPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCharPosition'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->GetCharPosition(index);
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
 tolua_error(tolua_S,"#ferror in function 'GetCharPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCharSize of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetCharSize00
static int tolua_UILuaAPI_Text3D_GetCharSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCharSize'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->GetCharSize(index);
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
 tolua_error(tolua_S,"#ferror in function 'GetCharSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetColor of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetColor00
static int tolua_UILuaAPI_Text3D_GetColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
  Corner corner = ((Corner) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetColor'", NULL);
#endif
 {
  const Color& tolua_ret = (const Color&)  self->GetColor(corner);
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

/* method: GetOpacity of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetOpacity00
static int tolua_UILuaAPI_Text3D_GetOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOpacity'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetOpacity();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsFixedScreenSize of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_IsFixedScreenSize00
static int tolua_UILuaAPI_Text3D_IsFixedScreenSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsFixedScreenSize'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsFixedScreenSize();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsFixedScreenSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFaceCameraMode of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Text3D_GetFaceCameraMode00
static int tolua_UILuaAPI_Text3D_GetFaceCameraMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Text3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Text3D* self = (const Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFaceCameraMode'", NULL);
#endif
 {
  FaceCameraMode tolua_ret = (FaceCameraMode)  self->GetFaceCameraMode();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFaceCameraMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: font of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_font_ptr
static int tolua_get_Text3D_font_ptr(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'font'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetFont(),"Font");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: font of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_font_ptr
static int tolua_set_Text3D_font_ptr(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'font'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Font",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFont(((Font*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: material of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_material_ptr
static int tolua_get_Text3D_material_ptr(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'material'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetMaterial(),"Material");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: material of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_material_ptr
static int tolua_set_Text3D_material_ptr(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'material'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Material",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaterial(((Material*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fontSize of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_fontSize
static int tolua_get_Text3D_fontSize(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fontSize'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFontSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: fontSize of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_fontSize
static int tolua_set_Text3D_fontSize(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fontSize'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFontSize(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: text of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_text
static int tolua_get_Text3D_text(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'text'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetText());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: text of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_text
static int tolua_set_Text3D_text(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'text'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetText(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: textAlignment of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_textAlignment
static int tolua_get_Text3D_textAlignment(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textAlignment'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTextAlignment());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: textAlignment of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_textAlignment
static int tolua_set_Text3D_textAlignment(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textAlignment'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTextAlignment(((HorizontalAlignment) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: horizontalAlignment of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_horizontalAlignment
static int tolua_get_Text3D_horizontalAlignment(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'horizontalAlignment'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetHorizontalAlignment());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: horizontalAlignment of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_horizontalAlignment
static int tolua_set_Text3D_horizontalAlignment(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'horizontalAlignment'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetHorizontalAlignment(((HorizontalAlignment) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: verticalAlignment of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_verticalAlignment
static int tolua_get_Text3D_verticalAlignment(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'verticalAlignment'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetVerticalAlignment());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: verticalAlignment of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_verticalAlignment
static int tolua_set_Text3D_verticalAlignment(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'verticalAlignment'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetVerticalAlignment(((VerticalAlignment) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rowSpacing of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_rowSpacing
static int tolua_get_Text3D_rowSpacing(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rowSpacing'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRowSpacing());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rowSpacing of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_rowSpacing
static int tolua_set_Text3D_rowSpacing(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rowSpacing'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRowSpacing(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: wordwrap of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_wordwrap
static int tolua_get_Text3D_wordwrap(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'wordwrap'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetWordwrap());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: wordwrap of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_wordwrap
static int tolua_set_Text3D_wordwrap(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'wordwrap'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetWordwrap(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: textEffect of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_textEffect
static int tolua_get_Text3D_textEffect(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textEffect'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetTextEffect());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: textEffect of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_textEffect
static int tolua_set_Text3D_textEffect(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textEffect'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetTextEffect(((TextEffect) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: effectShadowOffset of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_effectShadowOffset_ref
static int tolua_get_Text3D_effectShadowOffset_ref(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectShadowOffset'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetEffectShadowOffset(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: effectShadowOffset of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_effectShadowOffset_ref
static int tolua_set_Text3D_effectShadowOffset_ref(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectShadowOffset'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEffectShadowOffset((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: effectStrokeThickness of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_effectStrokeThickness
static int tolua_get_Text3D_effectStrokeThickness(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectStrokeThickness'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetEffectStrokeThickness());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: effectStrokeThickness of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_effectStrokeThickness
static int tolua_set_Text3D_effectStrokeThickness(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectStrokeThickness'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEffectStrokeThickness(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: effectRoundStroke of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_effectRoundStroke
static int tolua_get_Text3D_effectRoundStroke(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectRoundStroke'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetEffectRoundStroke());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: effectRoundStroke of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_effectRoundStroke
static int tolua_set_Text3D_effectRoundStroke(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectRoundStroke'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEffectRoundStroke(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: effectColor of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_effectColor_ref
static int tolua_get_Text3D_effectColor_ref(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectColor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetEffectColor(),"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: effectColor of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_effectColor_ref
static int tolua_set_Text3D_effectColor_ref(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectColor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEffectColor((*(Color*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: effectDepthBias of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_effectDepthBias
static int tolua_get_Text3D_effectDepthBias(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectDepthBias'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetEffectDepthBias());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: effectDepthBias of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_effectDepthBias
static int tolua_set_Text3D_effectDepthBias(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'effectDepthBias'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetEffectDepthBias(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_width
static int tolua_get_Text3D_width(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetWidth());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_width
static int tolua_set_Text3D_width(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetWidth(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: color of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_color_ref
static int tolua_get_Text3D_color_ref(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'color'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetColor(),"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: color of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_color_ref
static int tolua_set_Text3D_color_ref(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: height of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_height
static int tolua_get_Text3D_height(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetHeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rowHeight of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_rowHeight
static int tolua_get_Text3D_rowHeight(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rowHeight'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetRowHeight());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numRows of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_numRows
static int tolua_get_Text3D_numRows(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numRows'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumRows());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numChars of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_numChars
static int tolua_get_Text3D_numChars(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numChars'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumChars());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: opacity of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_opacity
static int tolua_get_Text3D_opacity(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'opacity'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetOpacity());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: opacity of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_opacity
static int tolua_set_Text3D_opacity(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'opacity'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetOpacity(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fixedScreenSize of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_fixedScreenSize
static int tolua_get_Text3D_fixedScreenSize(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fixedScreenSize'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsFixedScreenSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: fixedScreenSize of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_fixedScreenSize
static int tolua_set_Text3D_fixedScreenSize(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fixedScreenSize'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFixedScreenSize(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: faceCameraMode of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_get_Text3D_faceCameraMode
static int tolua_get_Text3D_faceCameraMode(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'faceCameraMode'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFaceCameraMode());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: faceCameraMode of class  Text3D */
#ifndef TOLUA_DISABLE_tolua_set_Text3D_faceCameraMode
static int tolua_set_Text3D_faceCameraMode(lua_State* tolua_S)
{
  Text3D* self = (Text3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'faceCameraMode'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFaceCameraMode(((FaceCameraMode) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ToolTip */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ToolTip_new00
static int tolua_UILuaAPI_ToolTip_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ToolTip",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ToolTip* tolua_ret = (ToolTip*)  Mtolua_new((ToolTip)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ToolTip");
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

/* method: new_local of class  ToolTip */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ToolTip_new00_local
static int tolua_UILuaAPI_ToolTip_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ToolTip",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  ToolTip* tolua_ret = (ToolTip*)  Mtolua_new((ToolTip)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"ToolTip");
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

/* method: delete of class  ToolTip */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ToolTip_delete00
static int tolua_UILuaAPI_ToolTip_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ToolTip",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ToolTip* self = (ToolTip*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetDelay of class  ToolTip */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ToolTip_SetDelay00
static int tolua_UILuaAPI_ToolTip_SetDelay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ToolTip",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ToolTip* self = (ToolTip*)  tolua_tousertype(tolua_S,1,0);
  float delay = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDelay'", NULL);
#endif
 {
  self->SetDelay(delay);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDelay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDelay of class  ToolTip */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_ToolTip_GetDelay00
static int tolua_UILuaAPI_ToolTip_GetDelay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const ToolTip",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const ToolTip* self = (const ToolTip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDelay'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDelay();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDelay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: delay of class  ToolTip */
#ifndef TOLUA_DISABLE_tolua_get_ToolTip_delay
static int tolua_get_ToolTip_delay(lua_State* tolua_S)
{
  ToolTip* self = (ToolTip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'delay'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDelay());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: delay of class  ToolTip */
#ifndef TOLUA_DISABLE_tolua_set_ToolTip_delay
static int tolua_set_ToolTip_delay(lua_State* tolua_S)
{
  ToolTip* self = (ToolTip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'delay'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDelay(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCursor of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetCursor00
static int tolua_UILuaAPI_UI_SetCursor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Cursor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  Cursor* cursor = ((Cursor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCursor'", NULL);
#endif
 {
  self->SetCursor(cursor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCursor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFocusElement of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetFocusElement00
static int tolua_UILuaAPI_UI_SetFocusElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  UIElement* element = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
  bool byKey = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFocusElement'", NULL);
#endif
 {
  self->SetFocusElement(element,byKey);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFocusElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetModalElement of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetModalElement00
static int tolua_UILuaAPI_UI_SetModalElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  UIElement* modalElement = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
  bool enable = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetModalElement'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SetModalElement(modalElement,enable);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetModalElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_Clear00
static int tolua_UILuaAPI_UI_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
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

/* method: DebugDraw of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_DebugDraw00
static int tolua_UILuaAPI_UI_DebugDraw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  UIElement* element = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DebugDraw'", NULL);
#endif
 {
  self->DebugDraw(element);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DebugDraw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UILoadLayout of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_LoadLayout00
static int tolua_UILuaAPI_UI_LoadLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"File",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"XMLFile",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  File* source = ((File*)  tolua_tousertype(tolua_S,2,0));
  XMLFile* styleFile = ((XMLFile*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UILoadLayout'", NULL);
#endif
 {
  tolua_outside UIElement* tolua_ret = (tolua_outside UIElement*)  UILoadLayout(self,source,styleFile);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UILoadLayout of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_LoadLayout01
static int tolua_UILuaAPI_UI_LoadLayout01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"XMLFile",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  const String fileName = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  XMLFile* styleFile = ((XMLFile*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UILoadLayout'", NULL);
#endif
 {
  tolua_outside UIElement* tolua_ret = (tolua_outside UIElement*)  UILoadLayout(self,fileName,styleFile);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
tolua_lerror:
 return tolua_UILuaAPI_UI_LoadLayout00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UILoadLayout of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_LoadLayout02
static int tolua_UILuaAPI_UI_LoadLayout02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"XMLFile",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"XMLFile",1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  XMLFile* file = ((XMLFile*)  tolua_tousertype(tolua_S,2,0));
  XMLFile* styleFile = ((XMLFile*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UILoadLayout'", NULL);
#endif
 {
  tolua_outside UIElement* tolua_ret = (tolua_outside UIElement*)  UILoadLayout(self,file,styleFile);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
tolua_lerror:
 return tolua_UILuaAPI_UI_LoadLayout01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveLayout of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SaveLayout00
static int tolua_UILuaAPI_UI_SaveLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Serializer",0,&tolua_err)) ||
 !tolua_isusertype(tolua_S,3,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  Serializer* dest = ((Serializer*)  tolua_tousertype(tolua_S,2,0));
  UIElement* element = ((UIElement*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveLayout'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->SaveLayout(*dest,element);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetClipboardText of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetClipboardText00
static int tolua_UILuaAPI_UI_SetClipboardText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  const String text = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetClipboardText'", NULL);
#endif
 {
  self->SetClipboardText(text);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetClipboardText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDoubleClickInterval of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetDoubleClickInterval00
static int tolua_UILuaAPI_UI_SetDoubleClickInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  float interval = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDoubleClickInterval'", NULL);
#endif
 {
  self->SetDoubleClickInterval(interval);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDoubleClickInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxDoubleClickDistance of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetMaxDoubleClickDistance00
static int tolua_UILuaAPI_UI_SetMaxDoubleClickDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  float pixels = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxDoubleClickDistance'", NULL);
#endif
 {
  self->SetMaxDoubleClickDistance(pixels);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxDoubleClickDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDragBeginInterval of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetDragBeginInterval00
static int tolua_UILuaAPI_UI_SetDragBeginInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  float interval = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDragBeginInterval'", NULL);
#endif
 {
  self->SetDragBeginInterval(interval);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDragBeginInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDragBeginDistance of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetDragBeginDistance00
static int tolua_UILuaAPI_UI_SetDragBeginDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  int pixels = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDragBeginDistance'", NULL);
#endif
 {
  self->SetDragBeginDistance(pixels);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDragBeginDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDefaultToolTipDelay of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetDefaultToolTipDelay00
static int tolua_UILuaAPI_UI_SetDefaultToolTipDelay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  float delay = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDefaultToolTipDelay'", NULL);
#endif
 {
  self->SetDefaultToolTipDelay(delay);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDefaultToolTipDelay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxFontTextureSize of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetMaxFontTextureSize00
static int tolua_UILuaAPI_UI_SetMaxFontTextureSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  int size = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxFontTextureSize'", NULL);
#endif
 {
  self->SetMaxFontTextureSize(size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxFontTextureSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetNonFocusedMouseWheel of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetNonFocusedMouseWheel00
static int tolua_UILuaAPI_UI_SetNonFocusedMouseWheel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  bool nonFocusedMouseWheel = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNonFocusedMouseWheel'", NULL);
#endif
 {
  self->SetNonFocusedMouseWheel(nonFocusedMouseWheel);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNonFocusedMouseWheel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseSystemClipboard of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetUseSystemClipboard00
static int tolua_UILuaAPI_UI_SetUseSystemClipboard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseSystemClipboard'", NULL);
#endif
 {
  self->SetUseSystemClipboard(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseSystemClipboard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseScreenKeyboard of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetUseScreenKeyboard00
static int tolua_UILuaAPI_UI_SetUseScreenKeyboard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseScreenKeyboard'", NULL);
#endif
 {
  self->SetUseScreenKeyboard(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseScreenKeyboard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseMutableGlyphs of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetUseMutableGlyphs00
static int tolua_UILuaAPI_UI_SetUseMutableGlyphs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseMutableGlyphs'", NULL);
#endif
 {
  self->SetUseMutableGlyphs(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseMutableGlyphs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetForceAutoHint of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetForceAutoHint00
static int tolua_UILuaAPI_UI_SetForceAutoHint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetForceAutoHint'", NULL);
#endif
 {
  self->SetForceAutoHint(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetForceAutoHint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFontHintLevel of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetFontHintLevel00
static int tolua_UILuaAPI_UI_SetFontHintLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  FontHintLevel level = ((FontHintLevel) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFontHintLevel'", NULL);
#endif
 {
  self->SetFontHintLevel(level);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFontHintLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFontSubpixelThreshold of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetFontSubpixelThreshold00
static int tolua_UILuaAPI_UI_SetFontSubpixelThreshold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  float threshold = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFontSubpixelThreshold'", NULL);
#endif
 {
  self->SetFontSubpixelThreshold(threshold);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFontSubpixelThreshold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFontOversampling of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetFontOversampling00
static int tolua_UILuaAPI_UI_SetFontOversampling00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  int limit = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFontOversampling'", NULL);
#endif
 {
  self->SetFontOversampling(limit);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFontOversampling'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetScale00
static int tolua_UILuaAPI_UI_SetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetWidth of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetWidth00
static int tolua_UILuaAPI_UI_SetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWidth'", NULL);
#endif
 {
  self->SetWidth(width);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHeight of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetHeight00
static int tolua_UILuaAPI_UI_SetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  float height = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHeight'", NULL);
#endif
 {
  self->SetHeight(height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCustomSize of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetCustomSize00
static int tolua_UILuaAPI_UI_SetCustomSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* size = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCustomSize'", NULL);
#endif
 {
  self->SetCustomSize(*size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCustomSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCustomSize of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_SetCustomSize01
static int tolua_UILuaAPI_UI_SetCustomSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCustomSize'", NULL);
#endif
 {
  self->SetCustomSize(width,height);
 }
 }
 return 0;
tolua_lerror:
 return tolua_UILuaAPI_UI_SetCustomSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRoot of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetRoot00
static int tolua_UILuaAPI_UI_GetRoot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRoot'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetRoot();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
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

/* method: GetRootModalElement of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetRootModalElement00
static int tolua_UILuaAPI_UI_GetRootModalElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRootModalElement'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetRootModalElement();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRootModalElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCursor of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetCursor00
static int tolua_UILuaAPI_UI_GetCursor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCursor'", NULL);
#endif
 {
  Cursor* tolua_ret = (Cursor*)  self->GetCursor();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Cursor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCursor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCursorPosition of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetCursorPosition00
static int tolua_UILuaAPI_UI_GetCursorPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCursorPosition'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->GetCursorPosition();
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
 tolua_error(tolua_S,"#ferror in function 'GetCursorPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetElementAt of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetElementAt00
static int tolua_UILuaAPI_UI_GetElementAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* position = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
  bool enabledOnly = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetElementAt'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetElementAt(*position,enabledOnly);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetElementAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetElementAt of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetElementAt01
static int tolua_UILuaAPI_UI_GetElementAt01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  bool enabledOnly = ((bool)  tolua_toboolean(tolua_S,4,true));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetElementAt'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetElementAt(x,y,enabledOnly);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
tolua_lerror:
 return tolua_UILuaAPI_UI_GetElementAt00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFocusElement of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetFocusElement00
static int tolua_UILuaAPI_UI_GetFocusElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFocusElement'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetFocusElement();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFocusElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFrontElement of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetFrontElement00
static int tolua_UILuaAPI_UI_GetFrontElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFrontElement'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetFrontElement();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFrontElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDragElement of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetDragElement00
static int tolua_UILuaAPI_UI_GetDragElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"UI",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
  unsigned index = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDragElement'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetDragElement(index);
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDragElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetClipboardText of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetClipboardText00
static int tolua_UILuaAPI_UI_GetClipboardText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClipboardText'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetClipboardText();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClipboardText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDoubleClickInterval of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetDoubleClickInterval00
static int tolua_UILuaAPI_UI_GetDoubleClickInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDoubleClickInterval'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDoubleClickInterval();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDoubleClickInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxDoubleClickDistance of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetMaxDoubleClickDistance00
static int tolua_UILuaAPI_UI_GetMaxDoubleClickDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxDoubleClickDistance'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetMaxDoubleClickDistance();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxDoubleClickDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDragBeginInterval of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetDragBeginInterval00
static int tolua_UILuaAPI_UI_GetDragBeginInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDragBeginInterval'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDragBeginInterval();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDragBeginInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDragBeginDistance of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetDragBeginDistance00
static int tolua_UILuaAPI_UI_GetDragBeginDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDragBeginDistance'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetDragBeginDistance();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDragBeginDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDefaultToolTipDelay of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetDefaultToolTipDelay00
static int tolua_UILuaAPI_UI_GetDefaultToolTipDelay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDefaultToolTipDelay'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetDefaultToolTipDelay();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDefaultToolTipDelay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxFontTextureSize of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetMaxFontTextureSize00
static int tolua_UILuaAPI_UI_GetMaxFontTextureSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxFontTextureSize'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetMaxFontTextureSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxFontTextureSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsNonFocusedMouseWheel of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_IsNonFocusedMouseWheel00
static int tolua_UILuaAPI_UI_IsNonFocusedMouseWheel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsNonFocusedMouseWheel'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsNonFocusedMouseWheel();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsNonFocusedMouseWheel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUseSystemClipboard of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetUseSystemClipboard00
static int tolua_UILuaAPI_UI_GetUseSystemClipboard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUseSystemClipboard'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetUseSystemClipboard();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUseSystemClipboard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUseScreenKeyboard of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetUseScreenKeyboard00
static int tolua_UILuaAPI_UI_GetUseScreenKeyboard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUseScreenKeyboard'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetUseScreenKeyboard();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUseScreenKeyboard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUseMutableGlyphs of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetUseMutableGlyphs00
static int tolua_UILuaAPI_UI_GetUseMutableGlyphs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUseMutableGlyphs'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetUseMutableGlyphs();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUseMutableGlyphs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetForceAutoHint of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetForceAutoHint00
static int tolua_UILuaAPI_UI_GetForceAutoHint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetForceAutoHint'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetForceAutoHint();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetForceAutoHint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFontHintLevel of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetFontHintLevel00
static int tolua_UILuaAPI_UI_GetFontHintLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFontHintLevel'", NULL);
#endif
 {
  FontHintLevel tolua_ret = (FontHintLevel)  self->GetFontHintLevel();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontHintLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFontSubpixelThreshold of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetFontSubpixelThreshold00
static int tolua_UILuaAPI_UI_GetFontSubpixelThreshold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFontSubpixelThreshold'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetFontSubpixelThreshold();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontSubpixelThreshold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFontOversampling of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetFontOversampling00
static int tolua_UILuaAPI_UI_GetFontOversampling00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFontOversampling'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetFontOversampling();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontOversampling'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasModalElement of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_HasModalElement00
static int tolua_UILuaAPI_UI_HasModalElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasModalElement'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->HasModalElement();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasModalElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsDragging of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_IsDragging00
static int tolua_UILuaAPI_UI_IsDragging00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsDragging'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsDragging();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsDragging'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScale of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetScale00
static int tolua_UILuaAPI_UI_GetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScale'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetScale();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: GetCustomSize of class  UI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UI_GetCustomSize00
static int tolua_UILuaAPI_UI_GetCustomSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UI",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UI* self = (const UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCustomSize'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetCustomSize();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCustomSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: root of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_root_ptr
static int tolua_get_UI_root_ptr(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'root'",NULL);
#endif
  ToluaPushObject(tolua_S,(void*)self->GetRoot(),"UIElement");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rootModalElement of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_rootModalElement_ptr
static int tolua_get_UI_rootModalElement_ptr(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rootModalElement'",NULL);
#endif
  ToluaPushObject(tolua_S,(void*)self->GetRootModalElement(),"UIElement");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cursor of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_cursor_ptr
static int tolua_get_UI_cursor_ptr(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cursor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetCursor(),"Cursor");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cursor of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_cursor_ptr
static int tolua_set_UI_cursor_ptr(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cursor'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Cursor",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCursor(((Cursor*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cursorPosition of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_cursorPosition
static int tolua_get_UI_cursorPosition(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cursorPosition'",NULL);
#endif
 IntVector2 tolua_ret = (IntVector2)self->GetCursorPosition();
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

/* get function: focusElement of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_focusElement_ptr
static int tolua_get_UI_focusElement_ptr(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'focusElement'",NULL);
#endif
  ToluaPushObject(tolua_S,(void*)self->GetFocusElement(),"UIElement");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: frontElement of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_frontElement_ptr
static int tolua_get_UI_frontElement_ptr(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frontElement'",NULL);
#endif
  ToluaPushObject(tolua_S,(void*)self->GetFrontElement(),"UIElement");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: clipboardText of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_clipboardText
static int tolua_get_UI_clipboardText(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'clipboardText'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetClipboardText());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: clipboardText of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_clipboardText
static int tolua_set_UI_clipboardText(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'clipboardText'",NULL);
 if (!tolua_isurho3dstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetClipboardText(((String)  tolua_tourho3dstring(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: doubleClickInterval of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_doubleClickInterval
static int tolua_get_UI_doubleClickInterval(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'doubleClickInterval'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDoubleClickInterval());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: doubleClickInterval of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_doubleClickInterval
static int tolua_set_UI_doubleClickInterval(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'doubleClickInterval'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDoubleClickInterval(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dragBeginInterval of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_dragBeginInterval
static int tolua_get_UI_dragBeginInterval(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dragBeginInterval'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDragBeginInterval());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dragBeginInterval of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_dragBeginInterval
static int tolua_set_UI_dragBeginInterval(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dragBeginInterval'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDragBeginInterval(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dragBeginDistance of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_dragBeginDistance
static int tolua_get_UI_dragBeginDistance(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dragBeginDistance'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDragBeginDistance());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dragBeginDistance of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_dragBeginDistance
static int tolua_set_UI_dragBeginDistance(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dragBeginDistance'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDragBeginDistance(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: defaultToolTipDelay of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_defaultToolTipDelay
static int tolua_get_UI_defaultToolTipDelay(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'defaultToolTipDelay'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetDefaultToolTipDelay());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: defaultToolTipDelay of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_defaultToolTipDelay
static int tolua_set_UI_defaultToolTipDelay(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'defaultToolTipDelay'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDefaultToolTipDelay(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxFontTextureSize of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_maxFontTextureSize
static int tolua_get_UI_maxFontTextureSize(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxFontTextureSize'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetMaxFontTextureSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxFontTextureSize of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_maxFontTextureSize
static int tolua_set_UI_maxFontTextureSize(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxFontTextureSize'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMaxFontTextureSize(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nonFocusedMouseWheel of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_nonFocusedMouseWheel
static int tolua_get_UI_nonFocusedMouseWheel(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nonFocusedMouseWheel'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsNonFocusedMouseWheel());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nonFocusedMouseWheel of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_nonFocusedMouseWheel
static int tolua_set_UI_nonFocusedMouseWheel(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nonFocusedMouseWheel'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetNonFocusedMouseWheel(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: useSystemClipboard of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_useSystemClipboard
static int tolua_get_UI_useSystemClipboard(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useSystemClipboard'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetUseSystemClipboard());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: useSystemClipboard of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_useSystemClipboard
static int tolua_set_UI_useSystemClipboard(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useSystemClipboard'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUseSystemClipboard(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: useScreenKeyboard of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_useScreenKeyboard
static int tolua_get_UI_useScreenKeyboard(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useScreenKeyboard'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetUseScreenKeyboard());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: useScreenKeyboard of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_useScreenKeyboard
static int tolua_set_UI_useScreenKeyboard(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useScreenKeyboard'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUseScreenKeyboard(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: useMutableGlyphs of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_useMutableGlyphs
static int tolua_get_UI_useMutableGlyphs(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useMutableGlyphs'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetUseMutableGlyphs());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: useMutableGlyphs of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_useMutableGlyphs
static int tolua_set_UI_useMutableGlyphs(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'useMutableGlyphs'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetUseMutableGlyphs(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: forceAutoHint of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_forceAutoHint
static int tolua_get_UI_forceAutoHint(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'forceAutoHint'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetForceAutoHint());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: forceAutoHint of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_forceAutoHint
static int tolua_set_UI_forceAutoHint(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'forceAutoHint'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetForceAutoHint(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fontHintLevel of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_fontHintLevel
static int tolua_get_UI_fontHintLevel(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fontHintLevel'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFontHintLevel());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: fontHintLevel of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_fontHintLevel
static int tolua_set_UI_fontHintLevel(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fontHintLevel'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFontHintLevel(((FontHintLevel) (int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fontSubpixelThreshold of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_fontSubpixelThreshold
static int tolua_get_UI_fontSubpixelThreshold(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fontSubpixelThreshold'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFontSubpixelThreshold());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: fontSubpixelThreshold of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_fontSubpixelThreshold
static int tolua_set_UI_fontSubpixelThreshold(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fontSubpixelThreshold'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFontSubpixelThreshold(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fontOversampling of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_fontOversampling
static int tolua_get_UI_fontOversampling(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fontOversampling'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFontOversampling());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: fontOversampling of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_fontOversampling
static int tolua_set_UI_fontOversampling(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fontOversampling'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFontOversampling(((int)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: modalElement of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_modalElement
static int tolua_get_UI_modalElement(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modalElement'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->HasModalElement());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scale of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_scale
static int tolua_get_UI_scale(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetScale());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scale of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_scale
static int tolua_set_UI_scale(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetScale(((float)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: customSize of class  UI */
#ifndef TOLUA_DISABLE_tolua_get_UI_customSize_ref
static int tolua_get_UI_customSize_ref(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'customSize'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetCustomSize(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: customSize of class  UI */
#ifndef TOLUA_DISABLE_tolua_set_UI_customSize_ref
static int tolua_set_UI_customSize_ref(lua_State* tolua_S)
{
  UI* self = (UI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'customSize'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetCustomSize((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetUI */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_GetUI00
static int tolua_UILuaAPI_GetUI00(lua_State* tolua_S)
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
  UI* tolua_ret = (UI*)  GetUI();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"UI");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ui */
#ifndef TOLUA_DISABLE_tolua_get_ui_ptr
static int tolua_get_ui_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetUi(),"UI");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_new00
static int tolua_UILuaAPI_Window_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Window",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Window* tolua_ret = (Window*)  Mtolua_new((Window)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Window");
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

/* method: new_local of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_new00_local
static int tolua_UILuaAPI_Window_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Window",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Window* tolua_ret = (Window*)  Mtolua_new((Window)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Window");
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

/* method: delete of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_delete00
static int tolua_UILuaAPI_Window_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetMovable of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_SetMovable00
static int tolua_UILuaAPI_Window_SetMovable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMovable'", NULL);
#endif
 {
  self->SetMovable(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMovable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetResizable of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_SetResizable00
static int tolua_UILuaAPI_Window_SetResizable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetResizable'", NULL);
#endif
 {
  self->SetResizable(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetResizable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFixedWidthResizing of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_SetFixedWidthResizing00
static int tolua_UILuaAPI_Window_SetFixedWidthResizing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFixedWidthResizing'", NULL);
#endif
 {
  self->SetFixedWidthResizing(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFixedWidthResizing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFixedHeightResizing of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_SetFixedHeightResizing00
static int tolua_UILuaAPI_Window_SetFixedHeightResizing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFixedHeightResizing'", NULL);
#endif
 {
  self->SetFixedHeightResizing(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFixedHeightResizing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetResizeBorder of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_SetResizeBorder00
static int tolua_UILuaAPI_Window_SetResizeBorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  const IntRect* rect = ((const IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetResizeBorder'", NULL);
#endif
 {
  self->SetResizeBorder(*rect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetResizeBorder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetModal of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_SetModal00
static int tolua_UILuaAPI_Window_SetModal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  bool modal = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetModal'", NULL);
#endif
 {
  self->SetModal(modal);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetModal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetModalShadeColor of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_SetModalShadeColor00
static int tolua_UILuaAPI_Window_SetModalShadeColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  const Color* color = ((const Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetModalShadeColor'", NULL);
#endif
 {
  self->SetModalShadeColor(*color);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetModalShadeColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetModalFrameColor of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_SetModalFrameColor00
static int tolua_UILuaAPI_Window_SetModalFrameColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Color",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  const Color* color = ((const Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetModalFrameColor'", NULL);
#endif
 {
  self->SetModalFrameColor(*color);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetModalFrameColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetModalFrameSize of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_SetModalFrameSize00
static int tolua_UILuaAPI_Window_SetModalFrameSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  const IntVector2* size = ((const IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetModalFrameSize'", NULL);
#endif
 {
  self->SetModalFrameSize(*size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetModalFrameSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetModalAutoDismiss of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_SetModalAutoDismiss00
static int tolua_UILuaAPI_Window_SetModalAutoDismiss00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetModalAutoDismiss'", NULL);
#endif
 {
  self->SetModalAutoDismiss(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetModalAutoDismiss'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsMovable of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_IsMovable00
static int tolua_UILuaAPI_Window_IsMovable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Window",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Window* self = (const Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsMovable'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsMovable();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsMovable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsResizable of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_IsResizable00
static int tolua_UILuaAPI_Window_IsResizable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Window",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Window* self = (const Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsResizable'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsResizable();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsResizable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFixedWidthResizing of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_GetFixedWidthResizing00
static int tolua_UILuaAPI_Window_GetFixedWidthResizing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Window",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Window* self = (const Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFixedWidthResizing'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetFixedWidthResizing();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFixedWidthResizing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFixedHeightResizing of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_GetFixedHeightResizing00
static int tolua_UILuaAPI_Window_GetFixedHeightResizing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Window",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Window* self = (const Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFixedHeightResizing'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetFixedHeightResizing();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFixedHeightResizing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetResizeBorder of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_GetResizeBorder00
static int tolua_UILuaAPI_Window_GetResizeBorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Window",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Window* self = (const Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetResizeBorder'", NULL);
#endif
 {
  const IntRect& tolua_ret = (const IntRect&)  self->GetResizeBorder();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntRect");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetResizeBorder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsModal of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_IsModal00
static int tolua_UILuaAPI_Window_IsModal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Window",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Window* self = (const Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsModal'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsModal();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsModal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetModalShadeColor of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_GetModalShadeColor00
static int tolua_UILuaAPI_Window_GetModalShadeColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Window",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Window* self = (const Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetModalShadeColor'", NULL);
#endif
 {
  const Color& tolua_ret = (const Color&)  self->GetModalShadeColor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Color");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetModalShadeColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetModalFrameColor of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_GetModalFrameColor00
static int tolua_UILuaAPI_Window_GetModalFrameColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Window",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Window* self = (const Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetModalFrameColor'", NULL);
#endif
 {
  const Color& tolua_ret = (const Color&)  self->GetModalFrameColor();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Color");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetModalFrameColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetModalFrameSize of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_GetModalFrameSize00
static int tolua_UILuaAPI_Window_GetModalFrameSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Window",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Window* self = (const Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetModalFrameSize'", NULL);
#endif
 {
  const IntVector2& tolua_ret = (const IntVector2&)  self->GetModalFrameSize();
  tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const IntVector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetModalFrameSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetModalAutoDismiss of class  Window */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_Window_GetModalAutoDismiss00
static int tolua_UILuaAPI_Window_GetModalAutoDismiss00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Window",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Window* self = (const Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetModalAutoDismiss'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetModalAutoDismiss();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetModalAutoDismiss'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: movable of class  Window */
#ifndef TOLUA_DISABLE_tolua_get_Window_movable
static int tolua_get_Window_movable(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'movable'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsMovable());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: movable of class  Window */
#ifndef TOLUA_DISABLE_tolua_set_Window_movable
static int tolua_set_Window_movable(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'movable'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMovable(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: resizable of class  Window */
#ifndef TOLUA_DISABLE_tolua_get_Window_resizable
static int tolua_get_Window_resizable(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resizable'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsResizable());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: resizable of class  Window */
#ifndef TOLUA_DISABLE_tolua_set_Window_resizable
static int tolua_set_Window_resizable(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resizable'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetResizable(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fixedWidthResizing of class  Window */
#ifndef TOLUA_DISABLE_tolua_get_Window_fixedWidthResizing
static int tolua_get_Window_fixedWidthResizing(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fixedWidthResizing'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetFixedWidthResizing());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: fixedWidthResizing of class  Window */
#ifndef TOLUA_DISABLE_tolua_set_Window_fixedWidthResizing
static int tolua_set_Window_fixedWidthResizing(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fixedWidthResizing'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFixedWidthResizing(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: fixedHeightResizing of class  Window */
#ifndef TOLUA_DISABLE_tolua_get_Window_fixedHeightResizing
static int tolua_get_Window_fixedHeightResizing(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fixedHeightResizing'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetFixedHeightResizing());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: fixedHeightResizing of class  Window */
#ifndef TOLUA_DISABLE_tolua_set_Window_fixedHeightResizing
static int tolua_set_Window_fixedHeightResizing(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'fixedHeightResizing'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFixedHeightResizing(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: resizeBorder of class  Window */
#ifndef TOLUA_DISABLE_tolua_get_Window_resizeBorder_ref
static int tolua_get_Window_resizeBorder_ref(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resizeBorder'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetResizeBorder(),"IntRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: resizeBorder of class  Window */
#ifndef TOLUA_DISABLE_tolua_set_Window_resizeBorder_ref
static int tolua_set_Window_resizeBorder_ref(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resizeBorder'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntRect",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetResizeBorder((*(IntRect*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: modal of class  Window */
#ifndef TOLUA_DISABLE_tolua_get_Window_modal
static int tolua_get_Window_modal(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modal'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsModal());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: modal of class  Window */
#ifndef TOLUA_DISABLE_tolua_set_Window_modal
static int tolua_set_Window_modal(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modal'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetModal(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: modalShadeColor of class  Window */
#ifndef TOLUA_DISABLE_tolua_get_Window_modalShadeColor_ref
static int tolua_get_Window_modalShadeColor_ref(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modalShadeColor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetModalShadeColor(),"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: modalShadeColor of class  Window */
#ifndef TOLUA_DISABLE_tolua_set_Window_modalShadeColor_ref
static int tolua_set_Window_modalShadeColor_ref(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modalShadeColor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetModalShadeColor((*(Color*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: modalFrameColor of class  Window */
#ifndef TOLUA_DISABLE_tolua_get_Window_modalFrameColor_ref
static int tolua_get_Window_modalFrameColor_ref(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modalFrameColor'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetModalFrameColor(),"Color");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: modalFrameColor of class  Window */
#ifndef TOLUA_DISABLE_tolua_set_Window_modalFrameColor_ref
static int tolua_set_Window_modalFrameColor_ref(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modalFrameColor'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetModalFrameColor((*(Color*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: modalFrameSize of class  Window */
#ifndef TOLUA_DISABLE_tolua_get_Window_modalFrameSize_ref
static int tolua_get_Window_modalFrameSize_ref(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modalFrameSize'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->GetModalFrameSize(),"IntVector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: modalFrameSize of class  Window */
#ifndef TOLUA_DISABLE_tolua_set_Window_modalFrameSize_ref
static int tolua_set_Window_modalFrameSize_ref(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modalFrameSize'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetModalFrameSize((*(IntVector2*)  tolua_tousertype(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: modalAutoDismiss of class  Window */
#ifndef TOLUA_DISABLE_tolua_get_Window_modalAutoDismiss
static int tolua_get_Window_modalAutoDismiss(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modalAutoDismiss'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetModalAutoDismiss());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: modalAutoDismiss of class  Window */
#ifndef TOLUA_DISABLE_tolua_set_Window_modalAutoDismiss
static int tolua_set_Window_modalAutoDismiss(lua_State* tolua_S)
{
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'modalAutoDismiss'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetModalAutoDismiss(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  View3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_View3D_new00
static int tolua_UILuaAPI_View3D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"View3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  View3D* tolua_ret = (View3D*)  Mtolua_new((View3D)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"View3D");
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

/* method: new_local of class  View3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_View3D_new00_local
static int tolua_UILuaAPI_View3D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"View3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  View3D* tolua_ret = (View3D*)  Mtolua_new((View3D)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"View3D");
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

/* method: delete of class  View3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_View3D_delete00
static int tolua_UILuaAPI_View3D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"View3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  View3D* self = (View3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetView of class  View3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_View3D_SetView00
static int tolua_UILuaAPI_View3D_SetView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"View3D",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"Camera",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  View3D* self = (View3D*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  Camera* camera = ((Camera*)  tolua_tousertype(tolua_S,3,0));
  bool ownScene = ((bool)  tolua_toboolean(tolua_S,4,true));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetView'", NULL);
#endif
 {
  self->SetView(scene,camera,ownScene);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFormat of class  View3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_View3D_SetFormat00
static int tolua_UILuaAPI_View3D_SetFormat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"View3D",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  View3D* self = (View3D*)  tolua_tousertype(tolua_S,1,0);
  unsigned format = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFormat'", NULL);
#endif
 {
  self->SetFormat(format);
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

/* method: SetAutoUpdate of class  View3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_View3D_SetAutoUpdate00
static int tolua_UILuaAPI_View3D_SetAutoUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"View3D",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  View3D* self = (View3D*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAutoUpdate'", NULL);
#endif
 {
  self->SetAutoUpdate(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAutoUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: QueueUpdate of class  View3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_View3D_QueueUpdate00
static int tolua_UILuaAPI_View3D_QueueUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"View3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  View3D* self = (View3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'QueueUpdate'", NULL);
#endif
 {
  self->QueueUpdate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'QueueUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFormat of class  View3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_View3D_GetFormat00
static int tolua_UILuaAPI_View3D_GetFormat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const View3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const View3D* self = (const View3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFormat'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetFormat();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFormat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAutoUpdate of class  View3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_View3D_GetAutoUpdate00
static int tolua_UILuaAPI_View3D_GetAutoUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const View3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const View3D* self = (const View3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAutoUpdate'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->GetAutoUpdate();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAutoUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScene of class  View3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_View3D_GetScene00
static int tolua_UILuaAPI_View3D_GetScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const View3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const View3D* self = (const View3D*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetCameraNode of class  View3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_View3D_GetCameraNode00
static int tolua_UILuaAPI_View3D_GetCameraNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const View3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const View3D* self = (const View3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCameraNode'", NULL);
#endif
 {
  Node* tolua_ret = (Node*)  self->GetCameraNode();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCameraNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRenderTexture of class  View3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_View3D_GetRenderTexture00
static int tolua_UILuaAPI_View3D_GetRenderTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const View3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const View3D* self = (const View3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRenderTexture'", NULL);
#endif
 {
  Texture2D* tolua_ret = (Texture2D*)  self->GetRenderTexture();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRenderTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDepthTexture of class  View3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_View3D_GetDepthTexture00
static int tolua_UILuaAPI_View3D_GetDepthTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const View3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const View3D* self = (const View3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDepthTexture'", NULL);
#endif
 {
  Texture2D* tolua_ret = (Texture2D*)  self->GetDepthTexture();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDepthTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetViewport of class  View3D */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_View3D_GetViewport00
static int tolua_UILuaAPI_View3D_GetViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const View3D",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const View3D* self = (const View3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetViewport'", NULL);
#endif
 {
  Viewport* tolua_ret = (Viewport*)  self->GetViewport();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Viewport");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetViewport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: format of class  View3D */
#ifndef TOLUA_DISABLE_tolua_get_View3D_format
static int tolua_get_View3D_format(lua_State* tolua_S)
{
  View3D* self = (View3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'format'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetFormat());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: format of class  View3D */
#ifndef TOLUA_DISABLE_tolua_set_View3D_format
static int tolua_set_View3D_format(lua_State* tolua_S)
{
  View3D* self = (View3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'format'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFormat(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: autoUpdate of class  View3D */
#ifndef TOLUA_DISABLE_tolua_get_View3D_autoUpdate
static int tolua_get_View3D_autoUpdate(lua_State* tolua_S)
{
  View3D* self = (View3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'autoUpdate'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->GetAutoUpdate());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: autoUpdate of class  View3D */
#ifndef TOLUA_DISABLE_tolua_set_View3D_autoUpdate
static int tolua_set_View3D_autoUpdate(lua_State* tolua_S)
{
  View3D* self = (View3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'autoUpdate'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetAutoUpdate(((bool)  tolua_toboolean(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  UIComponent */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIComponent_new00
static int tolua_UILuaAPI_UIComponent_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"UIComponent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  UIComponent* tolua_ret = (UIComponent*)  Mtolua_new((UIComponent)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIComponent");
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

/* method: new_local of class  UIComponent */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIComponent_new00_local
static int tolua_UILuaAPI_UIComponent_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"UIComponent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  UIComponent* tolua_ret = (UIComponent*)  Mtolua_new((UIComponent)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIComponent");
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

/* method: GetRoot of class  UIComponent */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIComponent_GetRoot00
static int tolua_UILuaAPI_UIComponent_GetRoot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIComponent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIComponent* self = (const UIComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRoot'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetRoot();
  ToluaPushObject(tolua_S,(void*)tolua_ret,"UIElement");
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

/* method: GetMaterial of class  UIComponent */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIComponent_GetMaterial00
static int tolua_UILuaAPI_UIComponent_GetMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIComponent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIComponent* self = (const UIComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaterial'", NULL);
#endif
 {
  Material* tolua_ret = (Material*)  self->GetMaterial();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Material");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTexture of class  UIComponent */
#ifndef TOLUA_DISABLE_tolua_UILuaAPI_UIComponent_GetTexture00
static int tolua_UILuaAPI_UIComponent_GetTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const UIComponent",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const UIComponent* self = (const UIComponent*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: root of class  UIComponent */
#ifndef TOLUA_DISABLE_tolua_get_UIComponent_root_ptr
static int tolua_get_UIComponent_root_ptr(lua_State* tolua_S)
{
  UIComponent* self = (UIComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'root'",NULL);
#endif
  ToluaPushObject(tolua_S,(void*)self->GetRoot(),"UIElement");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: material of class  UIComponent */
#ifndef TOLUA_DISABLE_tolua_get_UIComponent_material_ptr
static int tolua_get_UIComponent_material_ptr(lua_State* tolua_S)
{
  UIComponent* self = (UIComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'material'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetMaterial(),"Material");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: texture of class  UIComponent */
#ifndef TOLUA_DISABLE_tolua_get_UIComponent_texture_ptr
static int tolua_get_UIComponent_texture_ptr(lua_State* tolua_S)
{
  UIComponent* self = (UIComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texture'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->GetTexture(),"Texture2D");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_UILuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
 tolua_constant(tolua_S,"HA_LEFT",HA_LEFT);
 tolua_constant(tolua_S,"HA_CENTER",HA_CENTER);
 tolua_constant(tolua_S,"HA_RIGHT",HA_RIGHT);
 tolua_constant(tolua_S,"HA_CUSTOM",HA_CUSTOM);
 tolua_constant(tolua_S,"VA_TOP",VA_TOP);
 tolua_constant(tolua_S,"VA_CENTER",VA_CENTER);
 tolua_constant(tolua_S,"VA_BOTTOM",VA_BOTTOM);
 tolua_constant(tolua_S,"VA_CUSTOM",VA_CUSTOM);
 tolua_constant(tolua_S,"C_TOPLEFT",C_TOPLEFT);
 tolua_constant(tolua_S,"C_TOPRIGHT",C_TOPRIGHT);
 tolua_constant(tolua_S,"C_BOTTOMLEFT",C_BOTTOMLEFT);
 tolua_constant(tolua_S,"C_BOTTOMRIGHT",C_BOTTOMRIGHT);
 tolua_constant(tolua_S,"MAX_UIELEMENT_CORNERS",MAX_UIELEMENT_CORNERS);
 tolua_constant(tolua_S,"O_HORIZONTAL",O_HORIZONTAL);
 tolua_constant(tolua_S,"O_VERTICAL",O_VERTICAL);
 tolua_constant(tolua_S,"FM_NOTFOCUSABLE",FM_NOTFOCUSABLE);
 tolua_constant(tolua_S,"FM_RESETFOCUS",FM_RESETFOCUS);
 tolua_constant(tolua_S,"FM_FOCUSABLE",FM_FOCUSABLE);
 tolua_constant(tolua_S,"FM_FOCUSABLE_DEFOCUSABLE",FM_FOCUSABLE_DEFOCUSABLE);
 tolua_constant(tolua_S,"LM_FREE",LM_FREE);
 tolua_constant(tolua_S,"LM_HORIZONTAL",LM_HORIZONTAL);
 tolua_constant(tolua_S,"LM_VERTICAL",LM_VERTICAL);
 tolua_constant(tolua_S,"TM_BREADTH_FIRST",TM_BREADTH_FIRST);
 tolua_constant(tolua_S,"TM_DEPTH_FIRST",TM_DEPTH_FIRST);
 tolua_variable(tolua_S,"DD_DISABLED",tolua_get_DD_DISABLED,NULL);
 tolua_variable(tolua_S,"DD_SOURCE",tolua_get_DD_SOURCE,NULL);
 tolua_variable(tolua_S,"DD_TARGET",tolua_get_DD_TARGET,NULL);
 tolua_variable(tolua_S,"DD_SOURCE_AND_TARGET",tolua_get_DD_SOURCE_AND_TARGET,NULL);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"UIElement","UIElement","Animatable",tolua_collect_UIElement);
 #else
 tolua_cclass(tolua_S,"UIElement","UIElement","Animatable",NULL);
 #endif
 tolua_beginmodule(tolua_S,"UIElement");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_UIElement_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_UIElement_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_UIElement_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_UIElement_delete00);
  tolua_function(tolua_S,"GetScreenPosition",tolua_UILuaAPI_UIElement_GetScreenPosition00);
  tolua_function(tolua_S,"LoadXML",tolua_UILuaAPI_UIElement_LoadXML00);
  tolua_function(tolua_S,"SaveXML",tolua_UILuaAPI_UIElement_SaveXML00);
  tolua_function(tolua_S,"LoadXML",tolua_UILuaAPI_UIElement_LoadXML01);
  tolua_function(tolua_S,"SaveXML",tolua_UILuaAPI_UIElement_SaveXML01);
  tolua_function(tolua_S,"FilterAttributes",tolua_UILuaAPI_UIElement_FilterAttributes00);
  tolua_function(tolua_S,"SetName",tolua_UILuaAPI_UIElement_SetName00);
  tolua_function(tolua_S,"SetPosition",tolua_UILuaAPI_UIElement_SetPosition00);
  tolua_function(tolua_S,"SetPosition",tolua_UILuaAPI_UIElement_SetPosition01);
  tolua_function(tolua_S,"SetSize",tolua_UILuaAPI_UIElement_SetSize00);
  tolua_function(tolua_S,"SetSize",tolua_UILuaAPI_UIElement_SetSize01);
  tolua_function(tolua_S,"SetWidth",tolua_UILuaAPI_UIElement_SetWidth00);
  tolua_function(tolua_S,"SetHeight",tolua_UILuaAPI_UIElement_SetHeight00);
  tolua_function(tolua_S,"SetMinSize",tolua_UILuaAPI_UIElement_SetMinSize00);
  tolua_function(tolua_S,"SetMinSize",tolua_UILuaAPI_UIElement_SetMinSize01);
  tolua_function(tolua_S,"SetMinWidth",tolua_UILuaAPI_UIElement_SetMinWidth00);
  tolua_function(tolua_S,"SetMinHeight",tolua_UILuaAPI_UIElement_SetMinHeight00);
  tolua_function(tolua_S,"SetMaxSize",tolua_UILuaAPI_UIElement_SetMaxSize00);
  tolua_function(tolua_S,"SetMaxSize",tolua_UILuaAPI_UIElement_SetMaxSize01);
  tolua_function(tolua_S,"SetMaxWidth",tolua_UILuaAPI_UIElement_SetMaxWidth00);
  tolua_function(tolua_S,"SetMaxHeight",tolua_UILuaAPI_UIElement_SetMaxHeight00);
  tolua_function(tolua_S,"SetFixedSize",tolua_UILuaAPI_UIElement_SetFixedSize00);
  tolua_function(tolua_S,"SetFixedSize",tolua_UILuaAPI_UIElement_SetFixedSize01);
  tolua_function(tolua_S,"SetFixedWidth",tolua_UILuaAPI_UIElement_SetFixedWidth00);
  tolua_function(tolua_S,"SetFixedHeight",tolua_UILuaAPI_UIElement_SetFixedHeight00);
  tolua_function(tolua_S,"SetAlignment",tolua_UILuaAPI_UIElement_SetAlignment00);
  tolua_function(tolua_S,"SetHorizontalAlignment",tolua_UILuaAPI_UIElement_SetHorizontalAlignment00);
  tolua_function(tolua_S,"SetVerticalAlignment",tolua_UILuaAPI_UIElement_SetVerticalAlignment00);
  tolua_function(tolua_S,"SetEnableAnchor",tolua_UILuaAPI_UIElement_SetEnableAnchor00);
  tolua_function(tolua_S,"SetMinAnchor",tolua_UILuaAPI_UIElement_SetMinAnchor00);
  tolua_function(tolua_S,"SetMinAnchor",tolua_UILuaAPI_UIElement_SetMinAnchor01);
  tolua_function(tolua_S,"SetMaxAnchor",tolua_UILuaAPI_UIElement_SetMaxAnchor00);
  tolua_function(tolua_S,"SetMaxAnchor",tolua_UILuaAPI_UIElement_SetMaxAnchor01);
  tolua_function(tolua_S,"SetMinOffset",tolua_UILuaAPI_UIElement_SetMinOffset00);
  tolua_function(tolua_S,"SetMaxOffset",tolua_UILuaAPI_UIElement_SetMaxOffset00);
  tolua_function(tolua_S,"SetPivot",tolua_UILuaAPI_UIElement_SetPivot00);
  tolua_function(tolua_S,"SetPivot",tolua_UILuaAPI_UIElement_SetPivot01);
  tolua_function(tolua_S,"SetClipBorder",tolua_UILuaAPI_UIElement_SetClipBorder00);
  tolua_function(tolua_S,"SetColor",tolua_UILuaAPI_UIElement_SetColor00);
  tolua_function(tolua_S,"SetColor",tolua_UILuaAPI_UIElement_SetColor01);
  tolua_function(tolua_S,"SetPriority",tolua_UILuaAPI_UIElement_SetPriority00);
  tolua_function(tolua_S,"SetOpacity",tolua_UILuaAPI_UIElement_SetOpacity00);
  tolua_function(tolua_S,"SetBringToFront",tolua_UILuaAPI_UIElement_SetBringToFront00);
  tolua_function(tolua_S,"SetBringToBack",tolua_UILuaAPI_UIElement_SetBringToBack00);
  tolua_function(tolua_S,"SetClipChildren",tolua_UILuaAPI_UIElement_SetClipChildren00);
  tolua_function(tolua_S,"SetSortChildren",tolua_UILuaAPI_UIElement_SetSortChildren00);
  tolua_function(tolua_S,"SetUseDerivedOpacity",tolua_UILuaAPI_UIElement_SetUseDerivedOpacity00);
  tolua_function(tolua_S,"SetEnabled",tolua_UILuaAPI_UIElement_SetEnabled00);
  tolua_function(tolua_S,"SetDeepEnabled",tolua_UILuaAPI_UIElement_SetDeepEnabled00);
  tolua_function(tolua_S,"ResetDeepEnabled",tolua_UILuaAPI_UIElement_ResetDeepEnabled00);
  tolua_function(tolua_S,"SetEnabledRecursive",tolua_UILuaAPI_UIElement_SetEnabledRecursive00);
  tolua_function(tolua_S,"SetEditable",tolua_UILuaAPI_UIElement_SetEditable00);
  tolua_function(tolua_S,"SetFocus",tolua_UILuaAPI_UIElement_SetFocus00);
  tolua_function(tolua_S,"SetSelected",tolua_UILuaAPI_UIElement_SetSelected00);
  tolua_function(tolua_S,"SetVisible",tolua_UILuaAPI_UIElement_SetVisible00);
  tolua_function(tolua_S,"SetFocusMode",tolua_UILuaAPI_UIElement_SetFocusMode00);
  tolua_function(tolua_S,"SetDragDropMode",tolua_UILuaAPI_UIElement_SetDragDropMode00);
  tolua_function(tolua_S,"SetStyle",tolua_UILuaAPI_UIElement_SetStyle00);
  tolua_function(tolua_S,"SetStyle",tolua_UILuaAPI_UIElement_SetStyle01);
  tolua_function(tolua_S,"SetStyleAuto",tolua_UILuaAPI_UIElement_SetStyleAuto00);
  tolua_function(tolua_S,"SetDefaultStyle",tolua_UILuaAPI_UIElement_SetDefaultStyle00);
  tolua_function(tolua_S,"SetLayout",tolua_UILuaAPI_UIElement_SetLayout00);
  tolua_function(tolua_S,"SetLayout",tolua_UILuaAPI_UIElement_SetLayout01);
  tolua_function(tolua_S,"SetLayoutMode",tolua_UILuaAPI_UIElement_SetLayoutMode00);
  tolua_function(tolua_S,"SetLayoutSpacing",tolua_UILuaAPI_UIElement_SetLayoutSpacing00);
  tolua_function(tolua_S,"SetLayoutBorder",tolua_UILuaAPI_UIElement_SetLayoutBorder00);
  tolua_function(tolua_S,"SetLayoutFlexScale",tolua_UILuaAPI_UIElement_SetLayoutFlexScale00);
  tolua_function(tolua_S,"SetIndent",tolua_UILuaAPI_UIElement_SetIndent00);
  tolua_function(tolua_S,"SetIndentSpacing",tolua_UILuaAPI_UIElement_SetIndentSpacing00);
  tolua_function(tolua_S,"UpdateLayout",tolua_UILuaAPI_UIElement_UpdateLayout00);
  tolua_function(tolua_S,"DisableLayoutUpdate",tolua_UILuaAPI_UIElement_DisableLayoutUpdate00);
  tolua_function(tolua_S,"EnableLayoutUpdate",tolua_UILuaAPI_UIElement_EnableLayoutUpdate00);
  tolua_function(tolua_S,"BringToFront",tolua_UILuaAPI_UIElement_BringToFront00);
  tolua_function(tolua_S,"CreateChild",tolua_UILuaAPI_UIElement_CreateChild00);
  tolua_function(tolua_S,"AddChild",tolua_UILuaAPI_UIElement_AddChild00);
  tolua_function(tolua_S,"InsertChild",tolua_UILuaAPI_UIElement_InsertChild00);
  tolua_function(tolua_S,"RemoveChild",tolua_UILuaAPI_UIElement_RemoveChild00);
  tolua_function(tolua_S,"RemoveChildAtIndex",tolua_UILuaAPI_UIElement_RemoveChildAtIndex00);
  tolua_function(tolua_S,"RemoveAllChildren",tolua_UILuaAPI_UIElement_RemoveAllChildren00);
  tolua_function(tolua_S,"Remove",tolua_UILuaAPI_UIElement_Remove00);
  tolua_function(tolua_S,"FindChild",tolua_UILuaAPI_UIElement_FindChild00);
  tolua_function(tolua_S,"SetParent",tolua_UILuaAPI_UIElement_SetParent00);
  tolua_function(tolua_S,"SetVar",tolua_UILuaAPI_UIElement_SetVar00);
  tolua_function(tolua_S,"SetInternal",tolua_UILuaAPI_UIElement_SetInternal00);
  tolua_function(tolua_S,"SetTraversalMode",tolua_UILuaAPI_UIElement_SetTraversalMode00);
  tolua_function(tolua_S,"SetElementEventSender",tolua_UILuaAPI_UIElement_SetElementEventSender00);
  tolua_function(tolua_S,"AddTag",tolua_UILuaAPI_UIElement_AddTag00);
  tolua_function(tolua_S,"AddTags",tolua_UILuaAPI_UIElement_AddTags00);
  tolua_function(tolua_S,"RemoveTag",tolua_UILuaAPI_UIElement_RemoveTag00);
  tolua_function(tolua_S,"RemoveAllTags",tolua_UILuaAPI_UIElement_RemoveAllTags00);
  tolua_function(tolua_S,"GetName",tolua_UILuaAPI_UIElement_GetName00);
  tolua_function(tolua_S,"GetPosition",tolua_UILuaAPI_UIElement_GetPosition00);
  tolua_function(tolua_S,"GetSize",tolua_UILuaAPI_UIElement_GetSize00);
  tolua_function(tolua_S,"GetWidth",tolua_UILuaAPI_UIElement_GetWidth00);
  tolua_function(tolua_S,"GetHeight",tolua_UILuaAPI_UIElement_GetHeight00);
  tolua_function(tolua_S,"GetMinSize",tolua_UILuaAPI_UIElement_GetMinSize00);
  tolua_function(tolua_S,"GetMinWidth",tolua_UILuaAPI_UIElement_GetMinWidth00);
  tolua_function(tolua_S,"GetMinHeight",tolua_UILuaAPI_UIElement_GetMinHeight00);
  tolua_function(tolua_S,"GetMaxSize",tolua_UILuaAPI_UIElement_GetMaxSize00);
  tolua_function(tolua_S,"GetMaxWidth",tolua_UILuaAPI_UIElement_GetMaxWidth00);
  tolua_function(tolua_S,"GetMaxHeight",tolua_UILuaAPI_UIElement_GetMaxHeight00);
  tolua_function(tolua_S,"IsFixedSize",tolua_UILuaAPI_UIElement_IsFixedSize00);
  tolua_function(tolua_S,"IsFixedWidth",tolua_UILuaAPI_UIElement_IsFixedWidth00);
  tolua_function(tolua_S,"IsFixedHeight",tolua_UILuaAPI_UIElement_IsFixedHeight00);
  tolua_function(tolua_S,"GetChildOffset",tolua_UILuaAPI_UIElement_GetChildOffset00);
  tolua_function(tolua_S,"GetHorizontalAlignment",tolua_UILuaAPI_UIElement_GetHorizontalAlignment00);
  tolua_function(tolua_S,"GetVerticalAlignment",tolua_UILuaAPI_UIElement_GetVerticalAlignment00);
  tolua_function(tolua_S,"GetEnableAnchor",tolua_UILuaAPI_UIElement_GetEnableAnchor00);
  tolua_function(tolua_S,"GetMinAnchor",tolua_UILuaAPI_UIElement_GetMinAnchor00);
  tolua_function(tolua_S,"GetMaxAnchor",tolua_UILuaAPI_UIElement_GetMaxAnchor00);
  tolua_function(tolua_S,"GetMinOffset",tolua_UILuaAPI_UIElement_GetMinOffset00);
  tolua_function(tolua_S,"GetMaxOffset",tolua_UILuaAPI_UIElement_GetMaxOffset00);
  tolua_function(tolua_S,"GetPivot",tolua_UILuaAPI_UIElement_GetPivot00);
  tolua_function(tolua_S,"GetClipBorder",tolua_UILuaAPI_UIElement_GetClipBorder00);
  tolua_function(tolua_S,"GetColor",tolua_UILuaAPI_UIElement_GetColor00);
  tolua_function(tolua_S,"GetPriority",tolua_UILuaAPI_UIElement_GetPriority00);
  tolua_function(tolua_S,"GetOpacity",tolua_UILuaAPI_UIElement_GetOpacity00);
  tolua_function(tolua_S,"GetDerivedOpacity",tolua_UILuaAPI_UIElement_GetDerivedOpacity00);
  tolua_function(tolua_S,"GetBringToFront",tolua_UILuaAPI_UIElement_GetBringToFront00);
  tolua_function(tolua_S,"GetBringToBack",tolua_UILuaAPI_UIElement_GetBringToBack00);
  tolua_function(tolua_S,"GetClipChildren",tolua_UILuaAPI_UIElement_GetClipChildren00);
  tolua_function(tolua_S,"GetSortChildren",tolua_UILuaAPI_UIElement_GetSortChildren00);
  tolua_function(tolua_S,"GetUseDerivedOpacity",tolua_UILuaAPI_UIElement_GetUseDerivedOpacity00);
  tolua_function(tolua_S,"HasFocus",tolua_UILuaAPI_UIElement_HasFocus00);
  tolua_function(tolua_S,"IsEnabled",tolua_UILuaAPI_UIElement_IsEnabled00);
  tolua_function(tolua_S,"IsEnabledSelf",tolua_UILuaAPI_UIElement_IsEnabledSelf00);
  tolua_function(tolua_S,"IsEditable",tolua_UILuaAPI_UIElement_IsEditable00);
  tolua_function(tolua_S,"IsSelected",tolua_UILuaAPI_UIElement_IsSelected00);
  tolua_function(tolua_S,"IsVisible",tolua_UILuaAPI_UIElement_IsVisible00);
  tolua_function(tolua_S,"IsVisibleEffective",tolua_UILuaAPI_UIElement_IsVisibleEffective00);
  tolua_function(tolua_S,"IsHovering",tolua_UILuaAPI_UIElement_IsHovering00);
  tolua_function(tolua_S,"IsInternal",tolua_UILuaAPI_UIElement_IsInternal00);
  tolua_function(tolua_S,"HasColorGradient",tolua_UILuaAPI_UIElement_HasColorGradient00);
  tolua_function(tolua_S,"GetFocusMode",tolua_UILuaAPI_UIElement_GetFocusMode00);
  tolua_function(tolua_S,"GetDragDropMode",tolua_UILuaAPI_UIElement_GetDragDropMode00);
  tolua_function(tolua_S,"GetAppliedStyle",tolua_UILuaAPI_UIElement_GetAppliedStyle00);
  tolua_function(tolua_S,"GetDefaultStyle",tolua_UILuaAPI_UIElement_GetDefaultStyle00);
  tolua_function(tolua_S,"GetLayoutMode",tolua_UILuaAPI_UIElement_GetLayoutMode00);
  tolua_function(tolua_S,"GetLayoutSpacing",tolua_UILuaAPI_UIElement_GetLayoutSpacing00);
  tolua_function(tolua_S,"GetLayoutBorder",tolua_UILuaAPI_UIElement_GetLayoutBorder00);
  tolua_function(tolua_S,"GetLayoutFlexScale",tolua_UILuaAPI_UIElement_GetLayoutFlexScale00);
  tolua_function(tolua_S,"GetNumChildren",tolua_UILuaAPI_UIElement_GetNumChildren00);
  tolua_function(tolua_S,"GetDragButtonCombo",tolua_UILuaAPI_UIElement_GetDragButtonCombo00);
  tolua_function(tolua_S,"GetDragButtonCount",tolua_UILuaAPI_UIElement_GetDragButtonCount00);
  tolua_function(tolua_S,"GetChild",tolua_UILuaAPI_UIElement_GetChild00);
  tolua_function(tolua_S,"GetChild",tolua_UILuaAPI_UIElement_GetChild01);
  tolua_function(tolua_S,"IsChildOf",tolua_UILuaAPI_UIElement_IsChildOf00);
  tolua_function(tolua_S,"GetParent",tolua_UILuaAPI_UIElement_GetParent00);
  tolua_function(tolua_S,"GetRoot",tolua_UILuaAPI_UIElement_GetRoot00);
  tolua_function(tolua_S,"GetDerivedColor",tolua_UILuaAPI_UIElement_GetDerivedColor00);
  tolua_function(tolua_S,"GetVar",tolua_UILuaAPI_UIElement_GetVar00);
  tolua_function(tolua_S,"GetVars",tolua_UILuaAPI_UIElement_GetVars00);
  tolua_function(tolua_S,"HasTag",tolua_UILuaAPI_UIElement_HasTag00);
  tolua_function(tolua_S,"GetTags",tolua_UILuaAPI_UIElement_GetTags00);
  tolua_function(tolua_S,"GetChildrenWithTag",tolua_UILuaAPI_UIElement_GetChildrenWithTag00);
  tolua_function(tolua_S,"ScreenToElement",tolua_UILuaAPI_UIElement_ScreenToElement00);
  tolua_function(tolua_S,"ElementToScreen",tolua_UILuaAPI_UIElement_ElementToScreen00);
  tolua_function(tolua_S,"IsInside",tolua_UILuaAPI_UIElement_IsInside00);
  tolua_function(tolua_S,"IsInsideCombined",tolua_UILuaAPI_UIElement_IsInsideCombined00);
  tolua_function(tolua_S,"GetCombinedScreenRect",tolua_UILuaAPI_UIElement_GetCombinedScreenRect00);
  tolua_function(tolua_S,"SortChildren",tolua_UILuaAPI_UIElement_SortChildren00);
  tolua_function(tolua_S,"GetIndent",tolua_UILuaAPI_UIElement_GetIndent00);
  tolua_function(tolua_S,"GetIndentSpacing",tolua_UILuaAPI_UIElement_GetIndentSpacing00);
  tolua_function(tolua_S,"GetIndentWidth",tolua_UILuaAPI_UIElement_GetIndentWidth00);
  tolua_function(tolua_S,"SetChildOffset",tolua_UILuaAPI_UIElement_SetChildOffset00);
  tolua_function(tolua_S,"SetHovering",tolua_UILuaAPI_UIElement_SetHovering00);
  tolua_function(tolua_S,"GetColor",tolua_UILuaAPI_UIElement_GetColor01);
  tolua_function(tolua_S,"GetTraversalMode",tolua_UILuaAPI_UIElement_GetTraversalMode00);
  tolua_function(tolua_S,"IsElementEventSender",tolua_UILuaAPI_UIElement_IsElementEventSender00);
  tolua_function(tolua_S,"GetElementEventSender",tolua_UILuaAPI_UIElement_GetElementEventSender00);
  tolua_variable(tolua_S,"screenPosition",tolua_get_UIElement_screenPosition_ref,NULL);
  tolua_variable(tolua_S,"name",tolua_get_UIElement_name,tolua_set_UIElement_name);
  tolua_variable(tolua_S,"position",tolua_get_UIElement_position_ref,tolua_set_UIElement_position_ref);
  tolua_variable(tolua_S,"size",tolua_get_UIElement_size,tolua_set_UIElement_size);
  tolua_variable(tolua_S,"width",tolua_get_UIElement_width,tolua_set_UIElement_width);
  tolua_variable(tolua_S,"height",tolua_get_UIElement_height,tolua_set_UIElement_height);
  tolua_variable(tolua_S,"minSize",tolua_get_UIElement_minSize,tolua_set_UIElement_minSize);
  tolua_variable(tolua_S,"minWidth",tolua_get_UIElement_minWidth,tolua_set_UIElement_minWidth);
  tolua_variable(tolua_S,"minHeight",tolua_get_UIElement_minHeight,tolua_set_UIElement_minHeight);
  tolua_variable(tolua_S,"maxSize",tolua_get_UIElement_maxSize,tolua_set_UIElement_maxSize);
  tolua_variable(tolua_S,"maxWidth",tolua_get_UIElement_maxWidth,tolua_set_UIElement_maxWidth);
  tolua_variable(tolua_S,"maxHeight",tolua_get_UIElement_maxHeight,tolua_set_UIElement_maxHeight);
  tolua_variable(tolua_S,"fixedSize",tolua_get_UIElement_fixedSize,NULL);
  tolua_variable(tolua_S,"fixedWidth",tolua_get_UIElement_fixedWidth,NULL);
  tolua_variable(tolua_S,"fixedHeight",tolua_get_UIElement_fixedHeight,NULL);
  tolua_variable(tolua_S,"childOffset",tolua_get_UIElement_childOffset_ref,tolua_set_UIElement_childOffset_ref);
  tolua_variable(tolua_S,"horizontalAlignment",tolua_get_UIElement_horizontalAlignment,tolua_set_UIElement_horizontalAlignment);
  tolua_variable(tolua_S,"verticalAlignment",tolua_get_UIElement_verticalAlignment,tolua_set_UIElement_verticalAlignment);
  tolua_variable(tolua_S,"enableAnchor",tolua_get_UIElement_enableAnchor,tolua_set_UIElement_enableAnchor);
  tolua_variable(tolua_S,"minOffset",tolua_get_UIElement_minOffset_ref,tolua_set_UIElement_minOffset_ref);
  tolua_variable(tolua_S,"maxOffset",tolua_get_UIElement_maxOffset_ref,tolua_set_UIElement_maxOffset_ref);
  tolua_variable(tolua_S,"minAnchor",tolua_get_UIElement_minAnchor_ref,tolua_set_UIElement_minAnchor_ref);
  tolua_variable(tolua_S,"maxAnchor",tolua_get_UIElement_maxAnchor_ref,tolua_set_UIElement_maxAnchor_ref);
  tolua_variable(tolua_S,"pivot",tolua_get_UIElement_pivot_ref,tolua_set_UIElement_pivot_ref);
  tolua_variable(tolua_S,"clipBorder",tolua_get_UIElement_clipBorder,tolua_set_UIElement_clipBorder);
  tolua_variable(tolua_S,"color",tolua_get_UIElement_color_ref,tolua_set_UIElement_color_ref);
  tolua_variable(tolua_S,"priority",tolua_get_UIElement_priority,tolua_set_UIElement_priority);
  tolua_variable(tolua_S,"opacity",tolua_get_UIElement_opacity,tolua_set_UIElement_opacity);
  tolua_variable(tolua_S,"derivedOpacity",tolua_get_UIElement_derivedOpacity,NULL);
  tolua_variable(tolua_S,"bringToFront",tolua_get_UIElement_bringToFront,tolua_set_UIElement_bringToFront);
  tolua_variable(tolua_S,"bringToBack",tolua_get_UIElement_bringToBack,tolua_set_UIElement_bringToBack);
  tolua_variable(tolua_S,"clipChildren",tolua_get_UIElement_clipChildren,tolua_set_UIElement_clipChildren);
  tolua_variable(tolua_S,"sortChildren",tolua_get_UIElement_sortChildren,tolua_set_UIElement_sortChildren);
  tolua_variable(tolua_S,"useDerivedOpacity",tolua_get_UIElement_useDerivedOpacity,tolua_set_UIElement_useDerivedOpacity);
  tolua_variable(tolua_S,"focus",tolua_get_UIElement_focus,tolua_set_UIElement_focus);
  tolua_variable(tolua_S,"enabled",tolua_get_UIElement_enabled,tolua_set_UIElement_enabled);
  tolua_variable(tolua_S,"enabledSelf",tolua_get_UIElement_enabledSelf,NULL);
  tolua_variable(tolua_S,"editable",tolua_get_UIElement_editable,tolua_set_UIElement_editable);
  tolua_variable(tolua_S,"selected",tolua_get_UIElement_selected,tolua_set_UIElement_selected);
  tolua_variable(tolua_S,"visible",tolua_get_UIElement_visible,tolua_set_UIElement_visible);
  tolua_variable(tolua_S,"visibleEffective",tolua_get_UIElement_visibleEffective,NULL);
  tolua_variable(tolua_S,"hovering",tolua_get_UIElement_hovering,tolua_set_UIElement_hovering);
  tolua_variable(tolua_S,"internal",tolua_get_UIElement_internal,tolua_set_UIElement_internal);
  tolua_variable(tolua_S,"colorGradient",tolua_get_UIElement_colorGradient,NULL);
  tolua_variable(tolua_S,"focusMode",tolua_get_UIElement_focusMode,tolua_set_UIElement_focusMode);
  tolua_variable(tolua_S,"dragDropMode",tolua_get_UIElement_dragDropMode,tolua_set_UIElement_dragDropMode);
  tolua_variable(tolua_S,"style",tolua_get_UIElement_style,tolua_set_UIElement_style);
  tolua_variable(tolua_S,"defaultStyle",tolua_get_UIElement_defaultStyle_ptr,tolua_set_UIElement_defaultStyle_ptr);
  tolua_variable(tolua_S,"layoutMode",tolua_get_UIElement_layoutMode,tolua_set_UIElement_layoutMode);
  tolua_variable(tolua_S,"layoutSpacing",tolua_get_UIElement_layoutSpacing,tolua_set_UIElement_layoutSpacing);
  tolua_variable(tolua_S,"layoutBorder",tolua_get_UIElement_layoutBorder_ref,tolua_set_UIElement_layoutBorder_ref);
  tolua_variable(tolua_S,"layoutFlexScale",tolua_get_UIElement_layoutFlexScale_ref,tolua_set_UIElement_layoutFlexScale_ref);
  tolua_variable(tolua_S,"numChildren",tolua_get_UIElement_numChildren,NULL);
  tolua_variable(tolua_S,"parent",tolua_get_UIElement_parent_ptr,tolua_set_UIElement_parent_ptr);
  tolua_variable(tolua_S,"root",tolua_get_UIElement_root_ptr,NULL);
  tolua_variable(tolua_S,"derivedColor",tolua_get_UIElement_derivedColor_ref,NULL);
  tolua_variable(tolua_S,"combinedScreenRect",tolua_get_UIElement_combinedScreenRect,NULL);
  tolua_variable(tolua_S,"indent",tolua_get_UIElement_indent,tolua_set_UIElement_indent);
  tolua_variable(tolua_S,"indentSpacing",tolua_get_UIElement_indentSpacing,tolua_set_UIElement_indentSpacing);
  tolua_variable(tolua_S,"indentWidth",tolua_get_UIElement_indentWidth,NULL);
  tolua_variable(tolua_S,"traversalMode",tolua_get_UIElement_traversalMode,tolua_set_UIElement_traversalMode);
  tolua_variable(tolua_S,"elementEventSender",tolua_get_UIElement_elementEventSender,tolua_set_UIElement_elementEventSender);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"UISelectable","UISelectable","UIElement",tolua_collect_UISelectable);
 #else
 tolua_cclass(tolua_S,"UISelectable","UISelectable","UIElement",NULL);
 #endif
 tolua_beginmodule(tolua_S,"UISelectable");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_UISelectable_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_UISelectable_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_UISelectable_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_UISelectable_delete00);
  tolua_function(tolua_S,"SetSelectionColor",tolua_UILuaAPI_UISelectable_SetSelectionColor00);
  tolua_function(tolua_S,"SetHoverColor",tolua_UILuaAPI_UISelectable_SetHoverColor00);
  tolua_function(tolua_S,"GetSelectionColor",tolua_UILuaAPI_UISelectable_GetSelectionColor00);
  tolua_function(tolua_S,"GetHoverColor",tolua_UILuaAPI_UISelectable_GetHoverColor00);
  tolua_variable(tolua_S,"selectionColor",tolua_get_UISelectable_selectionColor_ref,tolua_set_UISelectable_selectionColor_ref);
  tolua_variable(tolua_S,"hoverColor",tolua_get_UISelectable_hoverColor_ref,tolua_set_UISelectable_hoverColor_ref);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"BorderImage","BorderImage","UIElement",tolua_collect_BorderImage);
 #else
 tolua_cclass(tolua_S,"BorderImage","BorderImage","UIElement",NULL);
 #endif
 tolua_beginmodule(tolua_S,"BorderImage");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_BorderImage_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_BorderImage_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_BorderImage_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_BorderImage_delete00);
  tolua_function(tolua_S,"SetTexture",tolua_UILuaAPI_BorderImage_SetTexture00);
  tolua_function(tolua_S,"SetImageRect",tolua_UILuaAPI_BorderImage_SetImageRect00);
  tolua_function(tolua_S,"SetFullImageRect",tolua_UILuaAPI_BorderImage_SetFullImageRect00);
  tolua_function(tolua_S,"SetBorder",tolua_UILuaAPI_BorderImage_SetBorder00);
  tolua_function(tolua_S,"SetImageBorder",tolua_UILuaAPI_BorderImage_SetImageBorder00);
  tolua_function(tolua_S,"SetHoverOffset",tolua_UILuaAPI_BorderImage_SetHoverOffset00);
  tolua_function(tolua_S,"SetHoverOffset",tolua_UILuaAPI_BorderImage_SetHoverOffset01);
  tolua_function(tolua_S,"SetBlendMode",tolua_UILuaAPI_BorderImage_SetBlendMode00);
  tolua_function(tolua_S,"SetTiled",tolua_UILuaAPI_BorderImage_SetTiled00);
  tolua_function(tolua_S,"GetTexture",tolua_UILuaAPI_BorderImage_GetTexture00);
  tolua_function(tolua_S,"GetImageRect",tolua_UILuaAPI_BorderImage_GetImageRect00);
  tolua_function(tolua_S,"GetBorder",tolua_UILuaAPI_BorderImage_GetBorder00);
  tolua_function(tolua_S,"GetImageBorder",tolua_UILuaAPI_BorderImage_GetImageBorder00);
  tolua_function(tolua_S,"GetHoverOffset",tolua_UILuaAPI_BorderImage_GetHoverOffset00);
  tolua_function(tolua_S,"GetBlendMode",tolua_UILuaAPI_BorderImage_GetBlendMode00);
  tolua_function(tolua_S,"IsTiled",tolua_UILuaAPI_BorderImage_IsTiled00);
  tolua_variable(tolua_S,"texture",tolua_get_BorderImage_texture_ptr,tolua_set_BorderImage_texture_ptr);
  tolua_variable(tolua_S,"imageRect",tolua_get_BorderImage_imageRect_ref,tolua_set_BorderImage_imageRect_ref);
  tolua_variable(tolua_S,"border",tolua_get_BorderImage_border_ref,tolua_set_BorderImage_border_ref);
  tolua_variable(tolua_S,"imageBorder",tolua_get_BorderImage_imageBorder_ref,tolua_set_BorderImage_imageBorder_ref);
  tolua_variable(tolua_S,"hoverOffset",tolua_get_BorderImage_hoverOffset_ref,tolua_set_BorderImage_hoverOffset_ref);
  tolua_variable(tolua_S,"blendMode",tolua_get_BorderImage_blendMode,tolua_set_BorderImage_blendMode);
  tolua_variable(tolua_S,"tiled",tolua_get_BorderImage_tiled,tolua_set_BorderImage_tiled);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Button","Button","BorderImage",tolua_collect_Button);
 #else
 tolua_cclass(tolua_S,"Button","Button","BorderImage",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Button");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_Button_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_Button_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_Button_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_Button_delete00);
  tolua_function(tolua_S,"SetPressedOffset",tolua_UILuaAPI_Button_SetPressedOffset00);
  tolua_function(tolua_S,"SetPressedOffset",tolua_UILuaAPI_Button_SetPressedOffset01);
  tolua_function(tolua_S,"SetDisabledOffset",tolua_UILuaAPI_Button_SetDisabledOffset00);
  tolua_function(tolua_S,"SetDisabledOffset",tolua_UILuaAPI_Button_SetDisabledOffset01);
  tolua_function(tolua_S,"SetPressedChildOffset",tolua_UILuaAPI_Button_SetPressedChildOffset00);
  tolua_function(tolua_S,"SetPressedChildOffset",tolua_UILuaAPI_Button_SetPressedChildOffset01);
  tolua_function(tolua_S,"SetRepeat",tolua_UILuaAPI_Button_SetRepeat00);
  tolua_function(tolua_S,"SetRepeatDelay",tolua_UILuaAPI_Button_SetRepeatDelay00);
  tolua_function(tolua_S,"SetRepeatRate",tolua_UILuaAPI_Button_SetRepeatRate00);
  tolua_function(tolua_S,"GetPressedOffset",tolua_UILuaAPI_Button_GetPressedOffset00);
  tolua_function(tolua_S,"GetDisabledOffset",tolua_UILuaAPI_Button_GetDisabledOffset00);
  tolua_function(tolua_S,"GetPressedChildOffset",tolua_UILuaAPI_Button_GetPressedChildOffset00);
  tolua_function(tolua_S,"GetRepeatDelay",tolua_UILuaAPI_Button_GetRepeatDelay00);
  tolua_function(tolua_S,"GetRepeatRate",tolua_UILuaAPI_Button_GetRepeatRate00);
  tolua_function(tolua_S,"IsPressed",tolua_UILuaAPI_Button_IsPressed00);
  tolua_variable(tolua_S,"pressedOffset",tolua_get_Button_pressedOffset_ref,tolua_set_Button_pressedOffset_ref);
  tolua_variable(tolua_S,"disabledOffset",tolua_get_Button_disabledOffset_ref,tolua_set_Button_disabledOffset_ref);
  tolua_variable(tolua_S,"pressedChildOffset",tolua_get_Button_pressedChildOffset_ref,tolua_set_Button_pressedChildOffset_ref);
  tolua_variable(tolua_S,"repeatDelay",tolua_get_Button_repeatDelay,tolua_set_Button_repeatDelay);
  tolua_variable(tolua_S,"repeatRate",tolua_get_Button_repeatRate,tolua_set_Button_repeatRate);
  tolua_variable(tolua_S,"pressed",tolua_get_Button_pressed,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"CheckBox","CheckBox","BorderImage",tolua_collect_CheckBox);
 #else
 tolua_cclass(tolua_S,"CheckBox","CheckBox","BorderImage",NULL);
 #endif
 tolua_beginmodule(tolua_S,"CheckBox");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_CheckBox_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_CheckBox_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_CheckBox_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_CheckBox_delete00);
  tolua_function(tolua_S,"SetChecked",tolua_UILuaAPI_CheckBox_SetChecked00);
  tolua_function(tolua_S,"SetCheckedOffset",tolua_UILuaAPI_CheckBox_SetCheckedOffset00);
  tolua_function(tolua_S,"SetCheckedOffset",tolua_UILuaAPI_CheckBox_SetCheckedOffset01);
  tolua_function(tolua_S,"IsChecked",tolua_UILuaAPI_CheckBox_IsChecked00);
  tolua_function(tolua_S,"GetCheckedOffset",tolua_UILuaAPI_CheckBox_GetCheckedOffset00);
  tolua_variable(tolua_S,"checked",tolua_get_CheckBox_checked,tolua_set_CheckBox_checked);
  tolua_variable(tolua_S,"checkedOffset",tolua_get_CheckBox_checkedOffset_ref,tolua_set_CheckBox_checkedOffset_ref);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"CS_NORMAL",CS_NORMAL);
 tolua_constant(tolua_S,"CS_IBEAM",CS_IBEAM);
 tolua_constant(tolua_S,"CS_CROSS",CS_CROSS);
 tolua_constant(tolua_S,"CS_RESIZEVERTICAL",CS_RESIZEVERTICAL);
 tolua_constant(tolua_S,"CS_RESIZEDIAGONAL_TOPRIGHT",CS_RESIZEDIAGONAL_TOPRIGHT);
 tolua_constant(tolua_S,"CS_RESIZEHORIZONTAL",CS_RESIZEHORIZONTAL);
 tolua_constant(tolua_S,"CS_RESIZEDIAGONAL_TOPLEFT",CS_RESIZEDIAGONAL_TOPLEFT);
 tolua_constant(tolua_S,"CS_RESIZE_ALL",CS_RESIZE_ALL);
 tolua_constant(tolua_S,"CS_ACCEPTDROP",CS_ACCEPTDROP);
 tolua_constant(tolua_S,"CS_REJECTDROP",CS_REJECTDROP);
 tolua_constant(tolua_S,"CS_BUSY",CS_BUSY);
 tolua_constant(tolua_S,"CS_BUSY_ARROW",CS_BUSY_ARROW);
 tolua_constant(tolua_S,"CS_MAX_SHAPES",CS_MAX_SHAPES);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Cursor","Cursor","BorderImage",tolua_collect_Cursor);
 #else
 tolua_cclass(tolua_S,"Cursor","Cursor","BorderImage",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Cursor");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_Cursor_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_Cursor_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_Cursor_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_Cursor_delete00);
  tolua_function(tolua_S,"DefineShape",tolua_UILuaAPI_Cursor_DefineShape00);
  tolua_function(tolua_S,"DefineShape",tolua_UILuaAPI_Cursor_DefineShape01);
  tolua_function(tolua_S,"SetShape",tolua_UILuaAPI_Cursor_SetShape00);
  tolua_function(tolua_S,"SetShape",tolua_UILuaAPI_Cursor_SetShape01);
  tolua_function(tolua_S,"SetUseSystemShapes",tolua_UILuaAPI_Cursor_SetUseSystemShapes00);
  tolua_function(tolua_S,"GetShape",tolua_UILuaAPI_Cursor_GetShape00);
  tolua_function(tolua_S,"GetUseSystemShapes",tolua_UILuaAPI_Cursor_GetUseSystemShapes00);
  tolua_variable(tolua_S,"shape",tolua_get_Cursor_shape,tolua_set_Cursor_shape);
  tolua_variable(tolua_S,"useSystemShapes",tolua_get_Cursor_useSystemShapes,tolua_set_Cursor_useSystemShapes);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"FileSelectorEntry","FileSelectorEntry","",NULL);
 tolua_beginmodule(tolua_S,"FileSelectorEntry");
  tolua_variable(tolua_S,"name",tolua_get_FileSelectorEntry_name,tolua_set_FileSelectorEntry_name);
  tolua_variable(tolua_S,"directory",tolua_get_FileSelectorEntry_directory,tolua_set_FileSelectorEntry_directory);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"FileSelector","FileSelector","Object",tolua_collect_FileSelector);
 #else
 tolua_cclass(tolua_S,"FileSelector","FileSelector","Object",NULL);
 #endif
 tolua_beginmodule(tolua_S,"FileSelector");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_FileSelector_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_FileSelector_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_FileSelector_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_FileSelector_delete00);
  tolua_function(tolua_S,"SetDefaultStyle",tolua_UILuaAPI_FileSelector_SetDefaultStyle00);
  tolua_function(tolua_S,"SetTitle",tolua_UILuaAPI_FileSelector_SetTitle00);
  tolua_function(tolua_S,"SetButtonTexts",tolua_UILuaAPI_FileSelector_SetButtonTexts00);
  tolua_function(tolua_S,"SetPath",tolua_UILuaAPI_FileSelector_SetPath00);
  tolua_function(tolua_S,"SetFileName",tolua_UILuaAPI_FileSelector_SetFileName00);
  tolua_function(tolua_S,"SetFilters",tolua_UILuaAPI_FileSelector_SetFilters00);
  tolua_function(tolua_S,"SetDirectoryMode",tolua_UILuaAPI_FileSelector_SetDirectoryMode00);
  tolua_function(tolua_S,"UpdateElements",tolua_UILuaAPI_FileSelector_UpdateElements00);
  tolua_function(tolua_S,"GetDefaultStyle",tolua_UILuaAPI_FileSelector_GetDefaultStyle00);
  tolua_function(tolua_S,"GetWindow",tolua_UILuaAPI_FileSelector_GetWindow00);
  tolua_function(tolua_S,"GetTitleText",tolua_UILuaAPI_FileSelector_GetTitleText00);
  tolua_function(tolua_S,"GetFileList",tolua_UILuaAPI_FileSelector_GetFileList00);
  tolua_function(tolua_S,"GetPathEdit",tolua_UILuaAPI_FileSelector_GetPathEdit00);
  tolua_function(tolua_S,"GetFileNameEdit",tolua_UILuaAPI_FileSelector_GetFileNameEdit00);
  tolua_function(tolua_S,"GetFilterList",tolua_UILuaAPI_FileSelector_GetFilterList00);
  tolua_function(tolua_S,"GetOKButton",tolua_UILuaAPI_FileSelector_GetOKButton00);
  tolua_function(tolua_S,"GetCancelButton",tolua_UILuaAPI_FileSelector_GetCancelButton00);
  tolua_function(tolua_S,"GetCloseButton",tolua_UILuaAPI_FileSelector_GetCloseButton00);
  tolua_function(tolua_S,"GetTitle",tolua_UILuaAPI_FileSelector_GetTitle00);
  tolua_function(tolua_S,"GetPath",tolua_UILuaAPI_FileSelector_GetPath00);
  tolua_function(tolua_S,"GetFileName",tolua_UILuaAPI_FileSelector_GetFileName00);
  tolua_function(tolua_S,"GetFilter",tolua_UILuaAPI_FileSelector_GetFilter00);
  tolua_function(tolua_S,"GetFilterIndex",tolua_UILuaAPI_FileSelector_GetFilterIndex00);
  tolua_function(tolua_S,"GetDirectoryMode",tolua_UILuaAPI_FileSelector_GetDirectoryMode00);
  tolua_variable(tolua_S,"defaultStyle",tolua_get_FileSelector_defaultStyle_ptr,tolua_set_FileSelector_defaultStyle_ptr);
  tolua_variable(tolua_S,"window",tolua_get_FileSelector_window_ptr,NULL);
  tolua_variable(tolua_S,"titleText",tolua_get_FileSelector_titleText_ptr,NULL);
  tolua_variable(tolua_S,"fileList",tolua_get_FileSelector_fileList_ptr,NULL);
  tolua_variable(tolua_S,"pathEdit",tolua_get_FileSelector_pathEdit_ptr,NULL);
  tolua_variable(tolua_S,"fileNameEdit",tolua_get_FileSelector_fileNameEdit_ptr,NULL);
  tolua_variable(tolua_S,"filterList",tolua_get_FileSelector_filterList_ptr,NULL);
  tolua_variable(tolua_S,"OKButton",tolua_get_FileSelector_OKButton_ptr,NULL);
  tolua_variable(tolua_S,"cancelButton",tolua_get_FileSelector_cancelButton_ptr,NULL);
  tolua_variable(tolua_S,"closeButton",tolua_get_FileSelector_closeButton_ptr,NULL);
  tolua_variable(tolua_S,"title",tolua_get_FileSelector_title,tolua_set_FileSelector_title);
  tolua_variable(tolua_S,"path",tolua_get_FileSelector_path,tolua_set_FileSelector_path);
  tolua_variable(tolua_S,"fileName",tolua_get_FileSelector_fileName,tolua_set_FileSelector_fileName);
  tolua_variable(tolua_S,"filter",tolua_get_FileSelector_filter,NULL);
  tolua_variable(tolua_S,"filterIndex",tolua_get_FileSelector_filterIndex,NULL);
  tolua_variable(tolua_S,"directoryMode",tolua_get_FileSelector_directoryMode,tolua_set_FileSelector_directoryMode);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"FONT_NONE",FONT_NONE);
 tolua_constant(tolua_S,"FONT_FREETYPE",FONT_FREETYPE);
 tolua_constant(tolua_S,"FONT_BITMAP",FONT_BITMAP);
 tolua_constant(tolua_S,"MAX_FONT_TYPES",MAX_FONT_TYPES);
 tolua_cclass(tolua_S,"Font","Font","Resource",NULL);
 tolua_beginmodule(tolua_S,"Font");
  tolua_function(tolua_S,"SetAbsoluteGlyphOffset",tolua_UILuaAPI_Font_SetAbsoluteGlyphOffset00);
  tolua_function(tolua_S,"SetScaledGlyphOffset",tolua_UILuaAPI_Font_SetScaledGlyphOffset00);
  tolua_function(tolua_S,"GetAbsoluteGlyphOffset",tolua_UILuaAPI_Font_GetAbsoluteGlyphOffset00);
  tolua_function(tolua_S,"GetScaledGlyphOffset",tolua_UILuaAPI_Font_GetScaledGlyphOffset00);
  tolua_function(tolua_S,"GetTotalGlyphOffset",tolua_UILuaAPI_Font_GetTotalGlyphOffset00);
  tolua_function(tolua_S,"GetFontType",tolua_UILuaAPI_Font_GetFontType00);
  tolua_function(tolua_S,"IsSDFFont",tolua_UILuaAPI_Font_IsSDFFont00);
  tolua_variable(tolua_S,"absoluteGlyphOffset",tolua_get_Font_absoluteGlyphOffset,tolua_set_Font_absoluteGlyphOffset);
  tolua_variable(tolua_S,"scaledGlyphOffset",tolua_get_Font_scaledGlyphOffset,tolua_set_Font_scaledGlyphOffset);
  tolua_variable(tolua_S,"fontType",tolua_get_Font_fontType,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"LineEdit","LineEdit","BorderImage",tolua_collect_LineEdit);
 #else
 tolua_cclass(tolua_S,"LineEdit","LineEdit","BorderImage",NULL);
 #endif
 tolua_beginmodule(tolua_S,"LineEdit");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_LineEdit_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_LineEdit_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_LineEdit_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_LineEdit_delete00);
  tolua_function(tolua_S,"SetText",tolua_UILuaAPI_LineEdit_SetText00);
  tolua_function(tolua_S,"SetCursorPosition",tolua_UILuaAPI_LineEdit_SetCursorPosition00);
  tolua_function(tolua_S,"SetCursorBlinkRate",tolua_UILuaAPI_LineEdit_SetCursorBlinkRate00);
  tolua_function(tolua_S,"SetMaxLength",tolua_UILuaAPI_LineEdit_SetMaxLength00);
  tolua_function(tolua_S,"SetEchoCharacter",tolua_UILuaAPI_LineEdit_SetEchoCharacter00);
  tolua_function(tolua_S,"SetCursorMovable",tolua_UILuaAPI_LineEdit_SetCursorMovable00);
  tolua_function(tolua_S,"SetTextSelectable",tolua_UILuaAPI_LineEdit_SetTextSelectable00);
  tolua_function(tolua_S,"SetTextCopyable",tolua_UILuaAPI_LineEdit_SetTextCopyable00);
  tolua_function(tolua_S,"GetText",tolua_UILuaAPI_LineEdit_GetText00);
  tolua_function(tolua_S,"GetCursorPosition",tolua_UILuaAPI_LineEdit_GetCursorPosition00);
  tolua_function(tolua_S,"GetCursorBlinkRate",tolua_UILuaAPI_LineEdit_GetCursorBlinkRate00);
  tolua_function(tolua_S,"GetMaxLength",tolua_UILuaAPI_LineEdit_GetMaxLength00);
  tolua_function(tolua_S,"GetEchoCharacter",tolua_UILuaAPI_LineEdit_GetEchoCharacter00);
  tolua_function(tolua_S,"IsCursorMovable",tolua_UILuaAPI_LineEdit_IsCursorMovable00);
  tolua_function(tolua_S,"IsTextSelectable",tolua_UILuaAPI_LineEdit_IsTextSelectable00);
  tolua_function(tolua_S,"IsTextCopyable",tolua_UILuaAPI_LineEdit_IsTextCopyable00);
  tolua_function(tolua_S,"GetTextElement",tolua_UILuaAPI_LineEdit_GetTextElement00);
  tolua_function(tolua_S,"GetCursor",tolua_UILuaAPI_LineEdit_GetCursor00);
  tolua_variable(tolua_S,"text",tolua_get_LineEdit_text,tolua_set_LineEdit_text);
  tolua_variable(tolua_S,"cursorPosition",tolua_get_LineEdit_cursorPosition,tolua_set_LineEdit_cursorPosition);
  tolua_variable(tolua_S,"cursorBlinkRate",tolua_get_LineEdit_cursorBlinkRate,tolua_set_LineEdit_cursorBlinkRate);
  tolua_variable(tolua_S,"maxLength",tolua_get_LineEdit_maxLength,tolua_set_LineEdit_maxLength);
  tolua_variable(tolua_S,"echoCharacter",tolua_get_LineEdit_echoCharacter,tolua_set_LineEdit_echoCharacter);
  tolua_variable(tolua_S,"cursorMovable",tolua_get_LineEdit_cursorMovable,tolua_set_LineEdit_cursorMovable);
  tolua_variable(tolua_S,"textSelectable",tolua_get_LineEdit_textSelectable,tolua_set_LineEdit_textSelectable);
  tolua_variable(tolua_S,"textCopyable",tolua_get_LineEdit_textCopyable,tolua_set_LineEdit_textCopyable);
  tolua_variable(tolua_S,"textElement",tolua_get_LineEdit_textElement_ptr,NULL);
  tolua_variable(tolua_S,"cursor",tolua_get_LineEdit_cursor_ptr,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Menu","Menu","Button",tolua_collect_Menu);
 #else
 tolua_cclass(tolua_S,"Menu","Menu","Button",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Menu");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_Menu_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_Menu_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_Menu_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_Menu_delete00);
  tolua_function(tolua_S,"SetPopup",tolua_UILuaAPI_Menu_SetPopup00);
  tolua_function(tolua_S,"SetPopupOffset",tolua_UILuaAPI_Menu_SetPopupOffset00);
  tolua_function(tolua_S,"SetPopupOffset",tolua_UILuaAPI_Menu_SetPopupOffset01);
  tolua_function(tolua_S,"ShowPopup",tolua_UILuaAPI_Menu_ShowPopup00);
  tolua_function(tolua_S,"SetAccelerator",tolua_UILuaAPI_Menu_SetAccelerator00);
  tolua_function(tolua_S,"GetPopup",tolua_UILuaAPI_Menu_GetPopup00);
  tolua_function(tolua_S,"GetPopupOffset",tolua_UILuaAPI_Menu_GetPopupOffset00);
  tolua_function(tolua_S,"GetShowPopup",tolua_UILuaAPI_Menu_GetShowPopup00);
  tolua_function(tolua_S,"GetAcceleratorKey",tolua_UILuaAPI_Menu_GetAcceleratorKey00);
  tolua_function(tolua_S,"GetAcceleratorQualifiers",tolua_UILuaAPI_Menu_GetAcceleratorQualifiers00);
  tolua_variable(tolua_S,"popup",tolua_get_Menu_popup_ptr,tolua_set_Menu_popup_ptr);
  tolua_variable(tolua_S,"popupOffset",tolua_get_Menu_popupOffset_ref,tolua_set_Menu_popupOffset_ref);
  tolua_variable(tolua_S,"showPopup",tolua_get_Menu_showPopup,tolua_set_Menu_showPopup);
  tolua_variable(tolua_S,"acceleratorKey",tolua_get_Menu_acceleratorKey,NULL);
  tolua_variable(tolua_S,"acceleratorQualifiers",tolua_get_Menu_acceleratorQualifiers,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"MessageBox","MessageBox","Object",tolua_collect_MessageBox);
 #else
 tolua_cclass(tolua_S,"MessageBox","MessageBox","Object",NULL);
 #endif
 tolua_beginmodule(tolua_S,"MessageBox");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_MessageBox_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_MessageBox_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_MessageBox_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_MessageBox_delete00);
  tolua_function(tolua_S,"SetTitle",tolua_UILuaAPI_MessageBox_SetTitle00);
  tolua_function(tolua_S,"SetMessage",tolua_UILuaAPI_MessageBox_SetMessage00);
  tolua_function(tolua_S,"GetTitle",tolua_UILuaAPI_MessageBox_GetTitle00);
  tolua_function(tolua_S,"GetMessage",tolua_UILuaAPI_MessageBox_GetMessage00);
  tolua_function(tolua_S,"GetWindow",tolua_UILuaAPI_MessageBox_GetWindow00);
  tolua_variable(tolua_S,"title",tolua_get_MessageBox_title,tolua_set_MessageBox_title);
  tolua_variable(tolua_S,"message",tolua_get_MessageBox_message,tolua_set_MessageBox_message);
  tolua_variable(tolua_S,"window",tolua_get_MessageBox_window_ptr,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"ProgressBar","ProgressBar","BorderImage",tolua_collect_ProgressBar);
 #else
 tolua_cclass(tolua_S,"ProgressBar","ProgressBar","BorderImage",NULL);
 #endif
 tolua_beginmodule(tolua_S,"ProgressBar");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_ProgressBar_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_ProgressBar_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_ProgressBar_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_ProgressBar_delete00);
  tolua_function(tolua_S,"SetOrientation",tolua_UILuaAPI_ProgressBar_SetOrientation00);
  tolua_function(tolua_S,"SetRange",tolua_UILuaAPI_ProgressBar_SetRange00);
  tolua_function(tolua_S,"SetValue",tolua_UILuaAPI_ProgressBar_SetValue00);
  tolua_function(tolua_S,"ChangeValue",tolua_UILuaAPI_ProgressBar_ChangeValue00);
  tolua_function(tolua_S,"SetLoadingPercentStyle",tolua_UILuaAPI_ProgressBar_SetLoadingPercentStyle00);
  tolua_function(tolua_S,"SetShowPercentText",tolua_UILuaAPI_ProgressBar_SetShowPercentText00);
  tolua_function(tolua_S,"GetOrientation",tolua_UILuaAPI_ProgressBar_GetOrientation00);
  tolua_function(tolua_S,"GetRange",tolua_UILuaAPI_ProgressBar_GetRange00);
  tolua_function(tolua_S,"GetValue",tolua_UILuaAPI_ProgressBar_GetValue00);
  tolua_function(tolua_S,"GetKnob",tolua_UILuaAPI_ProgressBar_GetKnob00);
  tolua_function(tolua_S,"GetLoadingPercentStyle",tolua_UILuaAPI_ProgressBar_GetLoadingPercentStyle00);
  tolua_function(tolua_S,"GetShowPercentText",tolua_UILuaAPI_ProgressBar_GetShowPercentText00);
  tolua_variable(tolua_S,"orientation",tolua_get_ProgressBar_orientation,tolua_set_ProgressBar_orientation);
  tolua_variable(tolua_S,"range",tolua_get_ProgressBar_range,tolua_set_ProgressBar_range);
  tolua_variable(tolua_S,"value",tolua_get_ProgressBar_value,tolua_set_ProgressBar_value);
  tolua_variable(tolua_S,"knob",tolua_get_ProgressBar_knob_ptr,NULL);
  tolua_variable(tolua_S,"loadingPercentStyle",tolua_get_ProgressBar_loadingPercentStyle,NULL);
  tolua_variable(tolua_S,"showPercentText",tolua_get_ProgressBar_showPercentText,tolua_set_ProgressBar_showPercentText);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"DropDownList","DropDownList","Menu",tolua_collect_DropDownList);
 #else
 tolua_cclass(tolua_S,"DropDownList","DropDownList","Menu",NULL);
 #endif
 tolua_beginmodule(tolua_S,"DropDownList");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_DropDownList_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_DropDownList_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_DropDownList_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_DropDownList_delete00);
  tolua_function(tolua_S,"AddItem",tolua_UILuaAPI_DropDownList_AddItem00);
  tolua_function(tolua_S,"InsertItem",tolua_UILuaAPI_DropDownList_InsertItem00);
  tolua_function(tolua_S,"RemoveItem",tolua_UILuaAPI_DropDownList_RemoveItem00);
  tolua_function(tolua_S,"RemoveItem",tolua_UILuaAPI_DropDownList_RemoveItem01);
  tolua_function(tolua_S,"RemoveAllItems",tolua_UILuaAPI_DropDownList_RemoveAllItems00);
  tolua_function(tolua_S,"SetSelection",tolua_UILuaAPI_DropDownList_SetSelection00);
  tolua_function(tolua_S,"SetPlaceholderText",tolua_UILuaAPI_DropDownList_SetPlaceholderText00);
  tolua_function(tolua_S,"SetResizePopup",tolua_UILuaAPI_DropDownList_SetResizePopup00);
  tolua_function(tolua_S,"GetNumItems",tolua_UILuaAPI_DropDownList_GetNumItems00);
  tolua_function(tolua_S,"GetItem",tolua_UILuaAPI_DropDownList_GetItem00);
  tolua_function(tolua_S,"GetItems",tolua_UILuaAPI_DropDownList_GetItems00);
  tolua_function(tolua_S,"GetSelection",tolua_UILuaAPI_DropDownList_GetSelection00);
  tolua_function(tolua_S,"GetSelectedItem",tolua_UILuaAPI_DropDownList_GetSelectedItem00);
  tolua_function(tolua_S,"GetListView",tolua_UILuaAPI_DropDownList_GetListView00);
  tolua_function(tolua_S,"GetPlaceholder",tolua_UILuaAPI_DropDownList_GetPlaceholder00);
  tolua_function(tolua_S,"GetPlaceholderText",tolua_UILuaAPI_DropDownList_GetPlaceholderText00);
  tolua_function(tolua_S,"GetResizePopup",tolua_UILuaAPI_DropDownList_GetResizePopup00);
  tolua_variable(tolua_S,"numItems",tolua_get_DropDownList_numItems,NULL);
  tolua_variable(tolua_S,"selection",tolua_get_DropDownList_selection,tolua_set_DropDownList_selection);
  tolua_variable(tolua_S,"selectedItem",tolua_get_DropDownList_selectedItem_ptr,NULL);
  tolua_variable(tolua_S,"listView",tolua_get_DropDownList_listView_ptr,NULL);
  tolua_variable(tolua_S,"placeholder",tolua_get_DropDownList_placeholder_ptr,NULL);
  tolua_variable(tolua_S,"placeholderText",tolua_get_DropDownList_placeholderText,tolua_set_DropDownList_placeholderText);
  tolua_variable(tolua_S,"resizePopup",tolua_get_DropDownList_resizePopup,tolua_set_DropDownList_resizePopup);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Slider","Slider","BorderImage",tolua_collect_Slider);
 #else
 tolua_cclass(tolua_S,"Slider","Slider","BorderImage",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Slider");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_Slider_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_Slider_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_Slider_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_Slider_delete00);
  tolua_function(tolua_S,"SetOrientation",tolua_UILuaAPI_Slider_SetOrientation00);
  tolua_function(tolua_S,"SetRange",tolua_UILuaAPI_Slider_SetRange00);
  tolua_function(tolua_S,"SetValue",tolua_UILuaAPI_Slider_SetValue00);
  tolua_function(tolua_S,"ChangeValue",tolua_UILuaAPI_Slider_ChangeValue00);
  tolua_function(tolua_S,"SetRepeatRate",tolua_UILuaAPI_Slider_SetRepeatRate00);
  tolua_function(tolua_S,"GetOrientation",tolua_UILuaAPI_Slider_GetOrientation00);
  tolua_function(tolua_S,"GetRange",tolua_UILuaAPI_Slider_GetRange00);
  tolua_function(tolua_S,"GetValue",tolua_UILuaAPI_Slider_GetValue00);
  tolua_function(tolua_S,"GetKnob",tolua_UILuaAPI_Slider_GetKnob00);
  tolua_function(tolua_S,"GetRepeatRate",tolua_UILuaAPI_Slider_GetRepeatRate00);
  tolua_variable(tolua_S,"orientation",tolua_get_Slider_orientation,tolua_set_Slider_orientation);
  tolua_variable(tolua_S,"range",tolua_get_Slider_range,tolua_set_Slider_range);
  tolua_variable(tolua_S,"value",tolua_get_Slider_value,tolua_set_Slider_value);
  tolua_variable(tolua_S,"knob",tolua_get_Slider_knob_ptr,NULL);
  tolua_variable(tolua_S,"repeatRate",tolua_get_Slider_repeatRate,tolua_set_Slider_repeatRate);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"ScrollBar","ScrollBar","BorderImage",tolua_collect_ScrollBar);
 #else
 tolua_cclass(tolua_S,"ScrollBar","ScrollBar","BorderImage",NULL);
 #endif
 tolua_beginmodule(tolua_S,"ScrollBar");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_ScrollBar_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_ScrollBar_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_ScrollBar_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_ScrollBar_delete00);
  tolua_function(tolua_S,"SetOrientation",tolua_UILuaAPI_ScrollBar_SetOrientation00);
  tolua_function(tolua_S,"SetRange",tolua_UILuaAPI_ScrollBar_SetRange00);
  tolua_function(tolua_S,"SetValue",tolua_UILuaAPI_ScrollBar_SetValue00);
  tolua_function(tolua_S,"ChangeValue",tolua_UILuaAPI_ScrollBar_ChangeValue00);
  tolua_function(tolua_S,"SetScrollStep",tolua_UILuaAPI_ScrollBar_SetScrollStep00);
  tolua_function(tolua_S,"SetStepFactor",tolua_UILuaAPI_ScrollBar_SetStepFactor00);
  tolua_function(tolua_S,"StepBack",tolua_UILuaAPI_ScrollBar_StepBack00);
  tolua_function(tolua_S,"StepForward",tolua_UILuaAPI_ScrollBar_StepForward00);
  tolua_function(tolua_S,"GetOrientation",tolua_UILuaAPI_ScrollBar_GetOrientation00);
  tolua_function(tolua_S,"GetRange",tolua_UILuaAPI_ScrollBar_GetRange00);
  tolua_function(tolua_S,"GetValue",tolua_UILuaAPI_ScrollBar_GetValue00);
  tolua_function(tolua_S,"GetScrollStep",tolua_UILuaAPI_ScrollBar_GetScrollStep00);
  tolua_function(tolua_S,"GetStepFactor",tolua_UILuaAPI_ScrollBar_GetStepFactor00);
  tolua_function(tolua_S,"GetEffectiveScrollStep",tolua_UILuaAPI_ScrollBar_GetEffectiveScrollStep00);
  tolua_function(tolua_S,"GetBackButton",tolua_UILuaAPI_ScrollBar_GetBackButton00);
  tolua_function(tolua_S,"GetForwardButton",tolua_UILuaAPI_ScrollBar_GetForwardButton00);
  tolua_function(tolua_S,"GetSlider",tolua_UILuaAPI_ScrollBar_GetSlider00);
  tolua_variable(tolua_S,"orientation",tolua_get_ScrollBar_orientation,tolua_set_ScrollBar_orientation);
  tolua_variable(tolua_S,"range",tolua_get_ScrollBar_range,tolua_set_ScrollBar_range);
  tolua_variable(tolua_S,"value",tolua_get_ScrollBar_value,tolua_set_ScrollBar_value);
  tolua_variable(tolua_S,"scrollStep",tolua_get_ScrollBar_scrollStep,tolua_set_ScrollBar_scrollStep);
  tolua_variable(tolua_S,"stepFactor",tolua_get_ScrollBar_stepFactor,tolua_set_ScrollBar_stepFactor);
  tolua_variable(tolua_S,"effectiveScrollStep",tolua_get_ScrollBar_effectiveScrollStep,NULL);
  tolua_variable(tolua_S,"backButton",tolua_get_ScrollBar_backButton_ptr,NULL);
  tolua_variable(tolua_S,"forwardButton",tolua_get_ScrollBar_forwardButton_ptr,NULL);
  tolua_variable(tolua_S,"slider",tolua_get_ScrollBar_slider_ptr,NULL);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"ScrollView","ScrollView","UIElement",tolua_collect_ScrollView);
 #else
 tolua_cclass(tolua_S,"ScrollView","ScrollView","UIElement",NULL);
 #endif
 tolua_beginmodule(tolua_S,"ScrollView");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_ScrollView_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_ScrollView_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_ScrollView_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_ScrollView_delete00);
  tolua_function(tolua_S,"SetContentElement",tolua_UILuaAPI_ScrollView_SetContentElement00);
  tolua_function(tolua_S,"SetViewPosition",tolua_UILuaAPI_ScrollView_SetViewPosition00);
  tolua_function(tolua_S,"SetViewPosition",tolua_UILuaAPI_ScrollView_SetViewPosition01);
  tolua_function(tolua_S,"SetScrollBarsVisible",tolua_UILuaAPI_ScrollView_SetScrollBarsVisible00);
  tolua_function(tolua_S,"SetScrollBarsAutoVisible",tolua_UILuaAPI_ScrollView_SetScrollBarsAutoVisible00);
  tolua_function(tolua_S,"SetScrollStep",tolua_UILuaAPI_ScrollView_SetScrollStep00);
  tolua_function(tolua_S,"SetPageStep",tolua_UILuaAPI_ScrollView_SetPageStep00);
  tolua_function(tolua_S,"SetScrollDeceleration",tolua_UILuaAPI_ScrollView_SetScrollDeceleration00);
  tolua_function(tolua_S,"SetScrollSnapEpsilon",tolua_UILuaAPI_ScrollView_SetScrollSnapEpsilon00);
  tolua_function(tolua_S,"SetAutoDisableChildren",tolua_UILuaAPI_ScrollView_SetAutoDisableChildren00);
  tolua_function(tolua_S,"SetAutoDisableThreshold",tolua_UILuaAPI_ScrollView_SetAutoDisableThreshold00);
  tolua_function(tolua_S,"GetViewPosition",tolua_UILuaAPI_ScrollView_GetViewPosition00);
  tolua_function(tolua_S,"GetContentElement",tolua_UILuaAPI_ScrollView_GetContentElement00);
  tolua_function(tolua_S,"GetHorizontalScrollBar",tolua_UILuaAPI_ScrollView_GetHorizontalScrollBar00);
  tolua_function(tolua_S,"GetVerticalScrollBar",tolua_UILuaAPI_ScrollView_GetVerticalScrollBar00);
  tolua_function(tolua_S,"GetScrollPanel",tolua_UILuaAPI_ScrollView_GetScrollPanel00);
  tolua_function(tolua_S,"GetScrollBarsAutoVisible",tolua_UILuaAPI_ScrollView_GetScrollBarsAutoVisible00);
  tolua_function(tolua_S,"GetScrollStep",tolua_UILuaAPI_ScrollView_GetScrollStep00);
  tolua_function(tolua_S,"GetPageStep",tolua_UILuaAPI_ScrollView_GetPageStep00);
  tolua_function(tolua_S,"GetScrollDeceleration",tolua_UILuaAPI_ScrollView_GetScrollDeceleration00);
  tolua_function(tolua_S,"GetScrollSnapEpsilon",tolua_UILuaAPI_ScrollView_GetScrollSnapEpsilon00);
  tolua_function(tolua_S,"GetAutoDisableChildren",tolua_UILuaAPI_ScrollView_GetAutoDisableChildren00);
  tolua_function(tolua_S,"GetAutoDisableThreshold",tolua_UILuaAPI_ScrollView_GetAutoDisableThreshold00);
  tolua_variable(tolua_S,"viewPosition",tolua_get_ScrollView_viewPosition_ref,tolua_set_ScrollView_viewPosition_ref);
  tolua_variable(tolua_S,"contentElement",tolua_get_ScrollView_contentElement_ptr,tolua_set_ScrollView_contentElement_ptr);
  tolua_variable(tolua_S,"horizontalScrollBar",tolua_get_ScrollView_horizontalScrollBar_ptr,NULL);
  tolua_variable(tolua_S,"verticalScrollBar",tolua_get_ScrollView_verticalScrollBar_ptr,NULL);
  tolua_variable(tolua_S,"scrollPanel",tolua_get_ScrollView_scrollPanel_ptr,NULL);
  tolua_variable(tolua_S,"scrollBarsAutoVisible",tolua_get_ScrollView_scrollBarsAutoVisible,tolua_set_ScrollView_scrollBarsAutoVisible);
  tolua_variable(tolua_S,"horizontalScrollBarVisible",tolua_get_ScrollView_horizontalScrollBarVisible,tolua_set_ScrollView_horizontalScrollBarVisible);
  tolua_variable(tolua_S,"verticalScrollBarVisible",tolua_get_ScrollView_verticalScrollBarVisible,tolua_set_ScrollView_verticalScrollBarVisible);
  tolua_variable(tolua_S,"scrollStep",tolua_get_ScrollView_scrollStep,tolua_set_ScrollView_scrollStep);
  tolua_variable(tolua_S,"pageStep",tolua_get_ScrollView_pageStep,tolua_set_ScrollView_pageStep);
  tolua_variable(tolua_S,"scrollDeceleration",tolua_get_ScrollView_scrollDeceleration,tolua_set_ScrollView_scrollDeceleration);
  tolua_variable(tolua_S,"scrollSnapEpsilon",tolua_get_ScrollView_scrollSnapEpsilon,tolua_set_ScrollView_scrollSnapEpsilon);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"HM_NEVER",HM_NEVER);
 tolua_constant(tolua_S,"HM_FOCUS",HM_FOCUS);
 tolua_constant(tolua_S,"HM_ALWAYS",HM_ALWAYS);
 tolua_cclass(tolua_S,"HierarchyContainer","HierarchyContainer","UIElement",NULL);
 tolua_beginmodule(tolua_S,"HierarchyContainer");
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"ListView","ListView","ScrollView",tolua_collect_ListView);
 #else
 tolua_cclass(tolua_S,"ListView","ListView","ScrollView",NULL);
 #endif
 tolua_beginmodule(tolua_S,"ListView");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_ListView_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_ListView_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_ListView_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_ListView_delete00);
  tolua_function(tolua_S,"UpdateInternalLayout",tolua_UILuaAPI_ListView_UpdateInternalLayout00);
  tolua_function(tolua_S,"DisableInternalLayoutUpdate",tolua_UILuaAPI_ListView_DisableInternalLayoutUpdate00);
  tolua_function(tolua_S,"EnableInternalLayoutUpdate",tolua_UILuaAPI_ListView_EnableInternalLayoutUpdate00);
  tolua_function(tolua_S,"AddItem",tolua_UILuaAPI_ListView_AddItem00);
  tolua_function(tolua_S,"InsertItem",tolua_UILuaAPI_ListView_InsertItem00);
  tolua_function(tolua_S,"RemoveItem",tolua_UILuaAPI_ListView_RemoveItem00);
  tolua_function(tolua_S,"RemoveItem",tolua_UILuaAPI_ListView_RemoveItem01);
  tolua_function(tolua_S,"RemoveAllItems",tolua_UILuaAPI_ListView_RemoveAllItems00);
  tolua_function(tolua_S,"SetSelection",tolua_UILuaAPI_ListView_SetSelection00);
  tolua_function(tolua_S,"SetSelections",tolua_UILuaAPI_ListView_SetSelections00);
  tolua_function(tolua_S,"AddSelection",tolua_UILuaAPI_ListView_AddSelection00);
  tolua_function(tolua_S,"RemoveSelection",tolua_UILuaAPI_ListView_RemoveSelection00);
  tolua_function(tolua_S,"ToggleSelection",tolua_UILuaAPI_ListView_ToggleSelection00);
  tolua_function(tolua_S,"ChangeSelection",tolua_UILuaAPI_ListView_ChangeSelection00);
  tolua_function(tolua_S,"ClearSelection",tolua_UILuaAPI_ListView_ClearSelection00);
  tolua_function(tolua_S,"SetHighlightMode",tolua_UILuaAPI_ListView_SetHighlightMode00);
  tolua_function(tolua_S,"SetMultiselect",tolua_UILuaAPI_ListView_SetMultiselect00);
  tolua_function(tolua_S,"SetHierarchyMode",tolua_UILuaAPI_ListView_SetHierarchyMode00);
  tolua_function(tolua_S,"SetBaseIndent",tolua_UILuaAPI_ListView_SetBaseIndent00);
  tolua_function(tolua_S,"SetClearSelectionOnDefocus",tolua_UILuaAPI_ListView_SetClearSelectionOnDefocus00);
  tolua_function(tolua_S,"SetSelectOnClickEnd",tolua_UILuaAPI_ListView_SetSelectOnClickEnd00);
  tolua_function(tolua_S,"Expand",tolua_UILuaAPI_ListView_Expand00);
  tolua_function(tolua_S,"ToggleExpand",tolua_UILuaAPI_ListView_ToggleExpand00);
  tolua_function(tolua_S,"GetNumItems",tolua_UILuaAPI_ListView_GetNumItems00);
  tolua_function(tolua_S,"GetItem",tolua_UILuaAPI_ListView_GetItem00);
  tolua_function(tolua_S,"GetItems",tolua_UILuaAPI_ListView_GetItems00);
  tolua_function(tolua_S,"FindItem",tolua_UILuaAPI_ListView_FindItem00);
  tolua_function(tolua_S,"GetSelection",tolua_UILuaAPI_ListView_GetSelection00);
  tolua_function(tolua_S,"GetSelections",tolua_UILuaAPI_ListView_GetSelections00);
  tolua_function(tolua_S,"CopySelectedItemsToClipboard",tolua_UILuaAPI_ListView_CopySelectedItemsToClipboard00);
  tolua_function(tolua_S,"GetSelectedItem",tolua_UILuaAPI_ListView_GetSelectedItem00);
  tolua_function(tolua_S,"GetSelectedItems",tolua_UILuaAPI_ListView_GetSelectedItems00);
  tolua_function(tolua_S,"IsSelected",tolua_UILuaAPI_ListView_IsSelected00);
  tolua_function(tolua_S,"IsExpanded",tolua_UILuaAPI_ListView_IsExpanded00);
  tolua_function(tolua_S,"GetHighlightMode",tolua_UILuaAPI_ListView_GetHighlightMode00);
  tolua_function(tolua_S,"GetMultiselect",tolua_UILuaAPI_ListView_GetMultiselect00);
  tolua_function(tolua_S,"GetClearSelectionOnDefocus",tolua_UILuaAPI_ListView_GetClearSelectionOnDefocus00);
  tolua_function(tolua_S,"GetSelectOnClickEnd",tolua_UILuaAPI_ListView_GetSelectOnClickEnd00);
  tolua_function(tolua_S,"GetHierarchyMode",tolua_UILuaAPI_ListView_GetHierarchyMode00);
  tolua_function(tolua_S,"GetBaseIndent",tolua_UILuaAPI_ListView_GetBaseIndent00);
  tolua_variable(tolua_S,"numItems",tolua_get_ListView_numItems,NULL);
  tolua_variable(tolua_S,"selection",tolua_get_ListView_selection,tolua_set_ListView_selection);
  tolua_variable(tolua_S,"selectedItem",tolua_get_ListView_selectedItem_ptr,NULL);
  tolua_variable(tolua_S,"highlightMode",tolua_get_ListView_highlightMode,tolua_set_ListView_highlightMode);
  tolua_variable(tolua_S,"multiselect",tolua_get_ListView_multiselect,tolua_set_ListView_multiselect);
  tolua_variable(tolua_S,"clearSelectionOnDefocus",tolua_get_ListView_clearSelectionOnDefocus,tolua_set_ListView_clearSelectionOnDefocus);
  tolua_variable(tolua_S,"selectOnClickEnd",tolua_get_ListView_selectOnClickEnd,tolua_set_ListView_selectOnClickEnd);
  tolua_variable(tolua_S,"hierarchyMode",tolua_get_ListView_hierarchyMode,tolua_set_ListView_hierarchyMode);
  tolua_variable(tolua_S,"baseIndent",tolua_get_ListView_baseIndent,tolua_set_ListView_baseIndent);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Sprite","Sprite","UIElement",tolua_collect_Sprite);
 #else
 tolua_cclass(tolua_S,"Sprite","Sprite","UIElement",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Sprite");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_Sprite_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_Sprite_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_Sprite_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_Sprite_delete00);
  tolua_function(tolua_S,"SetPosition",tolua_UILuaAPI_Sprite_SetPosition00);
  tolua_function(tolua_S,"SetPosition",tolua_UILuaAPI_Sprite_SetPosition01);
  tolua_function(tolua_S,"SetHotSpot",tolua_UILuaAPI_Sprite_SetHotSpot00);
  tolua_function(tolua_S,"SetHotSpot",tolua_UILuaAPI_Sprite_SetHotSpot01);
  tolua_function(tolua_S,"SetScale",tolua_UILuaAPI_Sprite_SetScale00);
  tolua_function(tolua_S,"SetScale",tolua_UILuaAPI_Sprite_SetScale01);
  tolua_function(tolua_S,"SetScale",tolua_UILuaAPI_Sprite_SetScale02);
  tolua_function(tolua_S,"SetRotation",tolua_UILuaAPI_Sprite_SetRotation00);
  tolua_function(tolua_S,"SetTexture",tolua_UILuaAPI_Sprite_SetTexture00);
  tolua_function(tolua_S,"SetImageRect",tolua_UILuaAPI_Sprite_SetImageRect00);
  tolua_function(tolua_S,"SetFullImageRect",tolua_UILuaAPI_Sprite_SetFullImageRect00);
  tolua_function(tolua_S,"SetBlendMode",tolua_UILuaAPI_Sprite_SetBlendMode00);
  tolua_function(tolua_S,"GetPosition",tolua_UILuaAPI_Sprite_GetPosition00);
  tolua_function(tolua_S,"GetHotSpot",tolua_UILuaAPI_Sprite_GetHotSpot00);
  tolua_function(tolua_S,"GetScale",tolua_UILuaAPI_Sprite_GetScale00);
  tolua_function(tolua_S,"GetRotation",tolua_UILuaAPI_Sprite_GetRotation00);
  tolua_function(tolua_S,"GetTexture",tolua_UILuaAPI_Sprite_GetTexture00);
  tolua_function(tolua_S,"GetImageRect",tolua_UILuaAPI_Sprite_GetImageRect00);
  tolua_function(tolua_S,"GetBlendMode",tolua_UILuaAPI_Sprite_GetBlendMode00);
  tolua_function(tolua_S,"GetTransform",tolua_UILuaAPI_Sprite_GetTransform00);
  tolua_variable(tolua_S,"position",tolua_get_Sprite_position_ref,tolua_set_Sprite_position_ref);
  tolua_variable(tolua_S,"hotSpot",tolua_get_Sprite_hotSpot_ref,tolua_set_Sprite_hotSpot_ref);
  tolua_variable(tolua_S,"scale",tolua_get_Sprite_scale_ref,tolua_set_Sprite_scale_ref);
  tolua_variable(tolua_S,"rotation",tolua_get_Sprite_rotation,tolua_set_Sprite_rotation);
  tolua_variable(tolua_S,"texture",tolua_get_Sprite_texture_ptr,tolua_set_Sprite_texture_ptr);
  tolua_variable(tolua_S,"imageRect",tolua_get_Sprite_imageRect_ref,tolua_set_Sprite_imageRect_ref);
  tolua_variable(tolua_S,"blendMode",tolua_get_Sprite_blendMode,tolua_set_Sprite_blendMode);
  tolua_variable(tolua_S,"transform",tolua_get_Sprite_transform_ref,NULL);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"TE_NONE",TE_NONE);
 tolua_constant(tolua_S,"TE_SHADOW",TE_SHADOW);
 tolua_constant(tolua_S,"TE_STROKE",TE_STROKE);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Text","Text","UISelectable",tolua_collect_Text);
 #else
 tolua_cclass(tolua_S,"Text","Text","UISelectable",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Text");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_Text_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_Text_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_Text_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_Text_delete00);
  tolua_function(tolua_S,"SetFont",tolua_UILuaAPI_Text_SetFont00);
  tolua_function(tolua_S,"SetFont",tolua_UILuaAPI_Text_SetFont01);
  tolua_function(tolua_S,"SetFontSize",tolua_UILuaAPI_Text_SetFontSize00);
  tolua_function(tolua_S,"SetText",tolua_UILuaAPI_Text_SetText00);
  tolua_function(tolua_S,"SetTextAlignment",tolua_UILuaAPI_Text_SetTextAlignment00);
  tolua_function(tolua_S,"SetRowSpacing",tolua_UILuaAPI_Text_SetRowSpacing00);
  tolua_function(tolua_S,"SetWordwrap",tolua_UILuaAPI_Text_SetWordwrap00);
  tolua_function(tolua_S,"SetSelection",tolua_UILuaAPI_Text_SetSelection00);
  tolua_function(tolua_S,"ClearSelection",tolua_UILuaAPI_Text_ClearSelection00);
  tolua_function(tolua_S,"SetTextEffect",tolua_UILuaAPI_Text_SetTextEffect00);
  tolua_function(tolua_S,"SetEffectShadowOffset",tolua_UILuaAPI_Text_SetEffectShadowOffset00);
  tolua_function(tolua_S,"SetEffectStrokeThickness",tolua_UILuaAPI_Text_SetEffectStrokeThickness00);
  tolua_function(tolua_S,"SetEffectRoundStroke",tolua_UILuaAPI_Text_SetEffectRoundStroke00);
  tolua_function(tolua_S,"SetEffectColor",tolua_UILuaAPI_Text_SetEffectColor00);
  tolua_function(tolua_S,"GetAutoLocalizable",tolua_UILuaAPI_Text_GetAutoLocalizable00);
  tolua_function(tolua_S,"SetAutoLocalizable",tolua_UILuaAPI_Text_SetAutoLocalizable00);
  tolua_function(tolua_S,"GetFont",tolua_UILuaAPI_Text_GetFont00);
  tolua_function(tolua_S,"GetFontSize",tolua_UILuaAPI_Text_GetFontSize00);
  tolua_function(tolua_S,"GetText",tolua_UILuaAPI_Text_GetText00);
  tolua_function(tolua_S,"GetTextAlignment",tolua_UILuaAPI_Text_GetTextAlignment00);
  tolua_function(tolua_S,"GetRowSpacing",tolua_UILuaAPI_Text_GetRowSpacing00);
  tolua_function(tolua_S,"GetWordwrap",tolua_UILuaAPI_Text_GetWordwrap00);
  tolua_function(tolua_S,"GetSelectionStart",tolua_UILuaAPI_Text_GetSelectionStart00);
  tolua_function(tolua_S,"GetSelectionLength",tolua_UILuaAPI_Text_GetSelectionLength00);
  tolua_function(tolua_S,"GetTextEffect",tolua_UILuaAPI_Text_GetTextEffect00);
  tolua_function(tolua_S,"GetEffectShadowOffset",tolua_UILuaAPI_Text_GetEffectShadowOffset00);
  tolua_function(tolua_S,"GetEffectStrokeThickness",tolua_UILuaAPI_Text_GetEffectStrokeThickness00);
  tolua_function(tolua_S,"GetEffectRoundStroke",tolua_UILuaAPI_Text_GetEffectRoundStroke00);
  tolua_function(tolua_S,"GetEffectColor",tolua_UILuaAPI_Text_GetEffectColor00);
  tolua_function(tolua_S,"GetRowHeight",tolua_UILuaAPI_Text_GetRowHeight00);
  tolua_function(tolua_S,"GetNumRows",tolua_UILuaAPI_Text_GetNumRows00);
  tolua_function(tolua_S,"GetNumChars",tolua_UILuaAPI_Text_GetNumChars00);
  tolua_function(tolua_S,"GetRowWidth",tolua_UILuaAPI_Text_GetRowWidth00);
  tolua_function(tolua_S,"GetCharPosition",tolua_UILuaAPI_Text_GetCharPosition00);
  tolua_function(tolua_S,"GetCharSize",tolua_UILuaAPI_Text_GetCharSize00);
  tolua_function(tolua_S,"SetEffectDepthBias",tolua_UILuaAPI_Text_SetEffectDepthBias00);
  tolua_function(tolua_S,"GetEffectDepthBias",tolua_UILuaAPI_Text_GetEffectDepthBias00);
  tolua_variable(tolua_S,"font",tolua_get_Text_font_ptr,tolua_set_Text_font_ptr);
  tolua_variable(tolua_S,"fontSize",tolua_get_Text_fontSize,tolua_set_Text_fontSize);
  tolua_variable(tolua_S,"text",tolua_get_Text_text,tolua_set_Text_text);
  tolua_variable(tolua_S,"textAlignment",tolua_get_Text_textAlignment,tolua_set_Text_textAlignment);
  tolua_variable(tolua_S,"rowSpacing",tolua_get_Text_rowSpacing,tolua_set_Text_rowSpacing);
  tolua_variable(tolua_S,"wordwrap",tolua_get_Text_wordwrap,tolua_set_Text_wordwrap);
  tolua_variable(tolua_S,"autoLocalizable",tolua_get_Text_autoLocalizable,tolua_set_Text_autoLocalizable);
  tolua_variable(tolua_S,"selectionStart",tolua_get_Text_selectionStart,NULL);
  tolua_variable(tolua_S,"selectionLength",tolua_get_Text_selectionLength,NULL);
  tolua_variable(tolua_S,"textEffect",tolua_get_Text_textEffect,tolua_set_Text_textEffect);
  tolua_variable(tolua_S,"effectShadowOffset",tolua_get_Text_effectShadowOffset_ref,tolua_set_Text_effectShadowOffset_ref);
  tolua_variable(tolua_S,"effectStrokeThickness",tolua_get_Text_effectStrokeThickness,tolua_set_Text_effectStrokeThickness);
  tolua_variable(tolua_S,"effectRoundStroke",tolua_get_Text_effectRoundStroke,tolua_set_Text_effectRoundStroke);
  tolua_variable(tolua_S,"effectColor",tolua_get_Text_effectColor_ref,tolua_set_Text_effectColor_ref);
  tolua_variable(tolua_S,"rowHeight",tolua_get_Text_rowHeight,NULL);
  tolua_variable(tolua_S,"numRows",tolua_get_Text_numRows,NULL);
  tolua_variable(tolua_S,"numChars",tolua_get_Text_numChars,NULL);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"FC_NONE",FC_NONE);
 tolua_constant(tolua_S,"FC_ROTATE_XYZ",FC_ROTATE_XYZ);
 tolua_constant(tolua_S,"FC_ROTATE_Y",FC_ROTATE_Y);
 tolua_constant(tolua_S,"FC_LOOKAT_XYZ",FC_LOOKAT_XYZ);
 tolua_constant(tolua_S,"FC_LOOKAT_Y",FC_LOOKAT_Y);
 tolua_constant(tolua_S,"FC_LOOKAT_MIXED",FC_LOOKAT_MIXED);
 tolua_constant(tolua_S,"FC_DIRECTION",FC_DIRECTION);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Text3D","Text3D","Drawable",tolua_collect_Text3D);
 #else
 tolua_cclass(tolua_S,"Text3D","Text3D","Drawable",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Text3D");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_Text3D_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_Text3D_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_Text3D_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_Text3D_delete00);
  tolua_function(tolua_S,"SetFont",tolua_UILuaAPI_Text3D_SetFont00);
  tolua_function(tolua_S,"SetFont",tolua_UILuaAPI_Text3D_SetFont01);
  tolua_function(tolua_S,"SetFontSize",tolua_UILuaAPI_Text3D_SetFontSize00);
  tolua_function(tolua_S,"SetMaterial",tolua_UILuaAPI_Text3D_SetMaterial00);
  tolua_function(tolua_S,"SetText",tolua_UILuaAPI_Text3D_SetText00);
  tolua_function(tolua_S,"SetAlignment",tolua_UILuaAPI_Text3D_SetAlignment00);
  tolua_function(tolua_S,"SetHorizontalAlignment",tolua_UILuaAPI_Text3D_SetHorizontalAlignment00);
  tolua_function(tolua_S,"SetVerticalAlignment",tolua_UILuaAPI_Text3D_SetVerticalAlignment00);
  tolua_function(tolua_S,"SetTextAlignment",tolua_UILuaAPI_Text3D_SetTextAlignment00);
  tolua_function(tolua_S,"SetRowSpacing",tolua_UILuaAPI_Text3D_SetRowSpacing00);
  tolua_function(tolua_S,"SetWordwrap",tolua_UILuaAPI_Text3D_SetWordwrap00);
  tolua_function(tolua_S,"SetTextEffect",tolua_UILuaAPI_Text3D_SetTextEffect00);
  tolua_function(tolua_S,"SetEffectShadowOffset",tolua_UILuaAPI_Text3D_SetEffectShadowOffset00);
  tolua_function(tolua_S,"SetEffectStrokeThickness",tolua_UILuaAPI_Text3D_SetEffectStrokeThickness00);
  tolua_function(tolua_S,"SetEffectRoundStroke",tolua_UILuaAPI_Text3D_SetEffectRoundStroke00);
  tolua_function(tolua_S,"SetEffectColor",tolua_UILuaAPI_Text3D_SetEffectColor00);
  tolua_function(tolua_S,"SetEffectDepthBias",tolua_UILuaAPI_Text3D_SetEffectDepthBias00);
  tolua_function(tolua_S,"SetWidth",tolua_UILuaAPI_Text3D_SetWidth00);
  tolua_function(tolua_S,"SetColor",tolua_UILuaAPI_Text3D_SetColor00);
  tolua_function(tolua_S,"SetColor",tolua_UILuaAPI_Text3D_SetColor01);
  tolua_function(tolua_S,"SetOpacity",tolua_UILuaAPI_Text3D_SetOpacity00);
  tolua_function(tolua_S,"SetFixedScreenSize",tolua_UILuaAPI_Text3D_SetFixedScreenSize00);
  tolua_function(tolua_S,"SetFaceCameraMode",tolua_UILuaAPI_Text3D_SetFaceCameraMode00);
  tolua_function(tolua_S,"GetFont",tolua_UILuaAPI_Text3D_GetFont00);
  tolua_function(tolua_S,"GetMaterial",tolua_UILuaAPI_Text3D_GetMaterial00);
  tolua_function(tolua_S,"GetFontSize",tolua_UILuaAPI_Text3D_GetFontSize00);
  tolua_function(tolua_S,"GetText",tolua_UILuaAPI_Text3D_GetText00);
  tolua_function(tolua_S,"GetTextAlignment",tolua_UILuaAPI_Text3D_GetTextAlignment00);
  tolua_function(tolua_S,"GetHorizontalAlignment",tolua_UILuaAPI_Text3D_GetHorizontalAlignment00);
  tolua_function(tolua_S,"GetVerticalAlignment",tolua_UILuaAPI_Text3D_GetVerticalAlignment00);
  tolua_function(tolua_S,"GetRowSpacing",tolua_UILuaAPI_Text3D_GetRowSpacing00);
  tolua_function(tolua_S,"GetWordwrap",tolua_UILuaAPI_Text3D_GetWordwrap00);
  tolua_function(tolua_S,"GetTextEffect",tolua_UILuaAPI_Text3D_GetTextEffect00);
  tolua_function(tolua_S,"GetEffectShadowOffset",tolua_UILuaAPI_Text3D_GetEffectShadowOffset00);
  tolua_function(tolua_S,"GetEffectStrokeThickness",tolua_UILuaAPI_Text3D_GetEffectStrokeThickness00);
  tolua_function(tolua_S,"GetEffectRoundStroke",tolua_UILuaAPI_Text3D_GetEffectRoundStroke00);
  tolua_function(tolua_S,"GetEffectColor",tolua_UILuaAPI_Text3D_GetEffectColor00);
  tolua_function(tolua_S,"GetEffectDepthBias",tolua_UILuaAPI_Text3D_GetEffectDepthBias00);
  tolua_function(tolua_S,"GetWidth",tolua_UILuaAPI_Text3D_GetWidth00);
  tolua_function(tolua_S,"GetHeight",tolua_UILuaAPI_Text3D_GetHeight00);
  tolua_function(tolua_S,"GetRowHeight",tolua_UILuaAPI_Text3D_GetRowHeight00);
  tolua_function(tolua_S,"GetNumRows",tolua_UILuaAPI_Text3D_GetNumRows00);
  tolua_function(tolua_S,"GetNumChars",tolua_UILuaAPI_Text3D_GetNumChars00);
  tolua_function(tolua_S,"GetRowWidth",tolua_UILuaAPI_Text3D_GetRowWidth00);
  tolua_function(tolua_S,"GetCharPosition",tolua_UILuaAPI_Text3D_GetCharPosition00);
  tolua_function(tolua_S,"GetCharSize",tolua_UILuaAPI_Text3D_GetCharSize00);
  tolua_function(tolua_S,"GetColor",tolua_UILuaAPI_Text3D_GetColor00);
  tolua_function(tolua_S,"GetOpacity",tolua_UILuaAPI_Text3D_GetOpacity00);
  tolua_function(tolua_S,"IsFixedScreenSize",tolua_UILuaAPI_Text3D_IsFixedScreenSize00);
  tolua_function(tolua_S,"GetFaceCameraMode",tolua_UILuaAPI_Text3D_GetFaceCameraMode00);
  tolua_variable(tolua_S,"font",tolua_get_Text3D_font_ptr,tolua_set_Text3D_font_ptr);
  tolua_variable(tolua_S,"material",tolua_get_Text3D_material_ptr,tolua_set_Text3D_material_ptr);
  tolua_variable(tolua_S,"fontSize",tolua_get_Text3D_fontSize,tolua_set_Text3D_fontSize);
  tolua_variable(tolua_S,"text",tolua_get_Text3D_text,tolua_set_Text3D_text);
  tolua_variable(tolua_S,"textAlignment",tolua_get_Text3D_textAlignment,tolua_set_Text3D_textAlignment);
  tolua_variable(tolua_S,"horizontalAlignment",tolua_get_Text3D_horizontalAlignment,tolua_set_Text3D_horizontalAlignment);
  tolua_variable(tolua_S,"verticalAlignment",tolua_get_Text3D_verticalAlignment,tolua_set_Text3D_verticalAlignment);
  tolua_variable(tolua_S,"rowSpacing",tolua_get_Text3D_rowSpacing,tolua_set_Text3D_rowSpacing);
  tolua_variable(tolua_S,"wordwrap",tolua_get_Text3D_wordwrap,tolua_set_Text3D_wordwrap);
  tolua_variable(tolua_S,"textEffect",tolua_get_Text3D_textEffect,tolua_set_Text3D_textEffect);
  tolua_variable(tolua_S,"effectShadowOffset",tolua_get_Text3D_effectShadowOffset_ref,tolua_set_Text3D_effectShadowOffset_ref);
  tolua_variable(tolua_S,"effectStrokeThickness",tolua_get_Text3D_effectStrokeThickness,tolua_set_Text3D_effectStrokeThickness);
  tolua_variable(tolua_S,"effectRoundStroke",tolua_get_Text3D_effectRoundStroke,tolua_set_Text3D_effectRoundStroke);
  tolua_variable(tolua_S,"effectColor",tolua_get_Text3D_effectColor_ref,tolua_set_Text3D_effectColor_ref);
  tolua_variable(tolua_S,"effectDepthBias",tolua_get_Text3D_effectDepthBias,tolua_set_Text3D_effectDepthBias);
  tolua_variable(tolua_S,"width",tolua_get_Text3D_width,tolua_set_Text3D_width);
  tolua_variable(tolua_S,"color",tolua_get_Text3D_color_ref,tolua_set_Text3D_color_ref);
  tolua_variable(tolua_S,"height",tolua_get_Text3D_height,NULL);
  tolua_variable(tolua_S,"rowHeight",tolua_get_Text3D_rowHeight,NULL);
  tolua_variable(tolua_S,"numRows",tolua_get_Text3D_numRows,NULL);
  tolua_variable(tolua_S,"numChars",tolua_get_Text3D_numChars,NULL);
  tolua_variable(tolua_S,"opacity",tolua_get_Text3D_opacity,tolua_set_Text3D_opacity);
  tolua_variable(tolua_S,"fixedScreenSize",tolua_get_Text3D_fixedScreenSize,tolua_set_Text3D_fixedScreenSize);
  tolua_variable(tolua_S,"faceCameraMode",tolua_get_Text3D_faceCameraMode,tolua_set_Text3D_faceCameraMode);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"ToolTip","ToolTip","UIElement",tolua_collect_ToolTip);
 #else
 tolua_cclass(tolua_S,"ToolTip","ToolTip","UIElement",NULL);
 #endif
 tolua_beginmodule(tolua_S,"ToolTip");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_ToolTip_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_ToolTip_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_ToolTip_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_ToolTip_delete00);
  tolua_function(tolua_S,"SetDelay",tolua_UILuaAPI_ToolTip_SetDelay00);
  tolua_function(tolua_S,"GetDelay",tolua_UILuaAPI_ToolTip_GetDelay00);
  tolua_variable(tolua_S,"delay",tolua_get_ToolTip_delay,tolua_set_ToolTip_delay);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"FONT_HINT_LEVEL_NONE",FONT_HINT_LEVEL_NONE);
 tolua_constant(tolua_S,"FONT_HINT_LEVEL_LIGHT",FONT_HINT_LEVEL_LIGHT);
 tolua_constant(tolua_S,"FONT_HINT_LEVEL_NORMAL",FONT_HINT_LEVEL_NORMAL);
 tolua_cclass(tolua_S,"UI","UI","Object",NULL);
 tolua_beginmodule(tolua_S,"UI");
  tolua_function(tolua_S,"SetCursor",tolua_UILuaAPI_UI_SetCursor00);
  tolua_function(tolua_S,"SetFocusElement",tolua_UILuaAPI_UI_SetFocusElement00);
  tolua_function(tolua_S,"SetModalElement",tolua_UILuaAPI_UI_SetModalElement00);
  tolua_function(tolua_S,"Clear",tolua_UILuaAPI_UI_Clear00);
  tolua_function(tolua_S,"DebugDraw",tolua_UILuaAPI_UI_DebugDraw00);
  tolua_function(tolua_S,"LoadLayout",tolua_UILuaAPI_UI_LoadLayout00);
  tolua_function(tolua_S,"LoadLayout",tolua_UILuaAPI_UI_LoadLayout01);
  tolua_function(tolua_S,"LoadLayout",tolua_UILuaAPI_UI_LoadLayout02);
  tolua_function(tolua_S,"SaveLayout",tolua_UILuaAPI_UI_SaveLayout00);
  tolua_function(tolua_S,"SetClipboardText",tolua_UILuaAPI_UI_SetClipboardText00);
  tolua_function(tolua_S,"SetDoubleClickInterval",tolua_UILuaAPI_UI_SetDoubleClickInterval00);
  tolua_function(tolua_S,"SetMaxDoubleClickDistance",tolua_UILuaAPI_UI_SetMaxDoubleClickDistance00);
  tolua_function(tolua_S,"SetDragBeginInterval",tolua_UILuaAPI_UI_SetDragBeginInterval00);
  tolua_function(tolua_S,"SetDragBeginDistance",tolua_UILuaAPI_UI_SetDragBeginDistance00);
  tolua_function(tolua_S,"SetDefaultToolTipDelay",tolua_UILuaAPI_UI_SetDefaultToolTipDelay00);
  tolua_function(tolua_S,"SetMaxFontTextureSize",tolua_UILuaAPI_UI_SetMaxFontTextureSize00);
  tolua_function(tolua_S,"SetNonFocusedMouseWheel",tolua_UILuaAPI_UI_SetNonFocusedMouseWheel00);
  tolua_function(tolua_S,"SetUseSystemClipboard",tolua_UILuaAPI_UI_SetUseSystemClipboard00);
  tolua_function(tolua_S,"SetUseScreenKeyboard",tolua_UILuaAPI_UI_SetUseScreenKeyboard00);
  tolua_function(tolua_S,"SetUseMutableGlyphs",tolua_UILuaAPI_UI_SetUseMutableGlyphs00);
  tolua_function(tolua_S,"SetForceAutoHint",tolua_UILuaAPI_UI_SetForceAutoHint00);
  tolua_function(tolua_S,"SetFontHintLevel",tolua_UILuaAPI_UI_SetFontHintLevel00);
  tolua_function(tolua_S,"SetFontSubpixelThreshold",tolua_UILuaAPI_UI_SetFontSubpixelThreshold00);
  tolua_function(tolua_S,"SetFontOversampling",tolua_UILuaAPI_UI_SetFontOversampling00);
  tolua_function(tolua_S,"SetScale",tolua_UILuaAPI_UI_SetScale00);
  tolua_function(tolua_S,"SetWidth",tolua_UILuaAPI_UI_SetWidth00);
  tolua_function(tolua_S,"SetHeight",tolua_UILuaAPI_UI_SetHeight00);
  tolua_function(tolua_S,"SetCustomSize",tolua_UILuaAPI_UI_SetCustomSize00);
  tolua_function(tolua_S,"SetCustomSize",tolua_UILuaAPI_UI_SetCustomSize01);
  tolua_function(tolua_S,"GetRoot",tolua_UILuaAPI_UI_GetRoot00);
  tolua_function(tolua_S,"GetRootModalElement",tolua_UILuaAPI_UI_GetRootModalElement00);
  tolua_function(tolua_S,"GetCursor",tolua_UILuaAPI_UI_GetCursor00);
  tolua_function(tolua_S,"GetCursorPosition",tolua_UILuaAPI_UI_GetCursorPosition00);
  tolua_function(tolua_S,"GetElementAt",tolua_UILuaAPI_UI_GetElementAt00);
  tolua_function(tolua_S,"GetElementAt",tolua_UILuaAPI_UI_GetElementAt01);
  tolua_function(tolua_S,"GetFocusElement",tolua_UILuaAPI_UI_GetFocusElement00);
  tolua_function(tolua_S,"GetFrontElement",tolua_UILuaAPI_UI_GetFrontElement00);
  tolua_function(tolua_S,"GetDragElement",tolua_UILuaAPI_UI_GetDragElement00);
  tolua_function(tolua_S,"GetClipboardText",tolua_UILuaAPI_UI_GetClipboardText00);
  tolua_function(tolua_S,"GetDoubleClickInterval",tolua_UILuaAPI_UI_GetDoubleClickInterval00);
  tolua_function(tolua_S,"GetMaxDoubleClickDistance",tolua_UILuaAPI_UI_GetMaxDoubleClickDistance00);
  tolua_function(tolua_S,"GetDragBeginInterval",tolua_UILuaAPI_UI_GetDragBeginInterval00);
  tolua_function(tolua_S,"GetDragBeginDistance",tolua_UILuaAPI_UI_GetDragBeginDistance00);
  tolua_function(tolua_S,"GetDefaultToolTipDelay",tolua_UILuaAPI_UI_GetDefaultToolTipDelay00);
  tolua_function(tolua_S,"GetMaxFontTextureSize",tolua_UILuaAPI_UI_GetMaxFontTextureSize00);
  tolua_function(tolua_S,"IsNonFocusedMouseWheel",tolua_UILuaAPI_UI_IsNonFocusedMouseWheel00);
  tolua_function(tolua_S,"GetUseSystemClipboard",tolua_UILuaAPI_UI_GetUseSystemClipboard00);
  tolua_function(tolua_S,"GetUseScreenKeyboard",tolua_UILuaAPI_UI_GetUseScreenKeyboard00);
  tolua_function(tolua_S,"GetUseMutableGlyphs",tolua_UILuaAPI_UI_GetUseMutableGlyphs00);
  tolua_function(tolua_S,"GetForceAutoHint",tolua_UILuaAPI_UI_GetForceAutoHint00);
  tolua_function(tolua_S,"GetFontHintLevel",tolua_UILuaAPI_UI_GetFontHintLevel00);
  tolua_function(tolua_S,"GetFontSubpixelThreshold",tolua_UILuaAPI_UI_GetFontSubpixelThreshold00);
  tolua_function(tolua_S,"GetFontOversampling",tolua_UILuaAPI_UI_GetFontOversampling00);
  tolua_function(tolua_S,"HasModalElement",tolua_UILuaAPI_UI_HasModalElement00);
  tolua_function(tolua_S,"IsDragging",tolua_UILuaAPI_UI_IsDragging00);
  tolua_function(tolua_S,"GetScale",tolua_UILuaAPI_UI_GetScale00);
  tolua_function(tolua_S,"GetCustomSize",tolua_UILuaAPI_UI_GetCustomSize00);
  tolua_variable(tolua_S,"root",tolua_get_UI_root_ptr,NULL);
  tolua_variable(tolua_S,"rootModalElement",tolua_get_UI_rootModalElement_ptr,NULL);
  tolua_variable(tolua_S,"cursor",tolua_get_UI_cursor_ptr,tolua_set_UI_cursor_ptr);
  tolua_variable(tolua_S,"cursorPosition",tolua_get_UI_cursorPosition,NULL);
  tolua_variable(tolua_S,"focusElement",tolua_get_UI_focusElement_ptr,NULL);
  tolua_variable(tolua_S,"frontElement",tolua_get_UI_frontElement_ptr,NULL);
  tolua_variable(tolua_S,"clipboardText",tolua_get_UI_clipboardText,tolua_set_UI_clipboardText);
  tolua_variable(tolua_S,"doubleClickInterval",tolua_get_UI_doubleClickInterval,tolua_set_UI_doubleClickInterval);
  tolua_variable(tolua_S,"dragBeginInterval",tolua_get_UI_dragBeginInterval,tolua_set_UI_dragBeginInterval);
  tolua_variable(tolua_S,"dragBeginDistance",tolua_get_UI_dragBeginDistance,tolua_set_UI_dragBeginDistance);
  tolua_variable(tolua_S,"defaultToolTipDelay",tolua_get_UI_defaultToolTipDelay,tolua_set_UI_defaultToolTipDelay);
  tolua_variable(tolua_S,"maxFontTextureSize",tolua_get_UI_maxFontTextureSize,tolua_set_UI_maxFontTextureSize);
  tolua_variable(tolua_S,"nonFocusedMouseWheel",tolua_get_UI_nonFocusedMouseWheel,tolua_set_UI_nonFocusedMouseWheel);
  tolua_variable(tolua_S,"useSystemClipboard",tolua_get_UI_useSystemClipboard,tolua_set_UI_useSystemClipboard);
  tolua_variable(tolua_S,"useScreenKeyboard",tolua_get_UI_useScreenKeyboard,tolua_set_UI_useScreenKeyboard);
  tolua_variable(tolua_S,"useMutableGlyphs",tolua_get_UI_useMutableGlyphs,tolua_set_UI_useMutableGlyphs);
  tolua_variable(tolua_S,"forceAutoHint",tolua_get_UI_forceAutoHint,tolua_set_UI_forceAutoHint);
  tolua_variable(tolua_S,"fontHintLevel",tolua_get_UI_fontHintLevel,tolua_set_UI_fontHintLevel);
  tolua_variable(tolua_S,"fontSubpixelThreshold",tolua_get_UI_fontSubpixelThreshold,tolua_set_UI_fontSubpixelThreshold);
  tolua_variable(tolua_S,"fontOversampling",tolua_get_UI_fontOversampling,tolua_set_UI_fontOversampling);
  tolua_variable(tolua_S,"modalElement",tolua_get_UI_modalElement,NULL);
  tolua_variable(tolua_S,"scale",tolua_get_UI_scale,tolua_set_UI_scale);
  tolua_variable(tolua_S,"customSize",tolua_get_UI_customSize_ref,tolua_set_UI_customSize_ref);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"GetUI",tolua_UILuaAPI_GetUI00);
 tolua_variable(tolua_S,"ui",tolua_get_ui_ptr,NULL);
 tolua_constant(tolua_S,"DRAG_NONE",DRAG_NONE);
 tolua_constant(tolua_S,"DRAG_MOVE",DRAG_MOVE);
 tolua_constant(tolua_S,"DRAG_RESIZE_TOPLEFT",DRAG_RESIZE_TOPLEFT);
 tolua_constant(tolua_S,"DRAG_RESIZE_TOP",DRAG_RESIZE_TOP);
 tolua_constant(tolua_S,"DRAG_RESIZE_TOPRIGHT",DRAG_RESIZE_TOPRIGHT);
 tolua_constant(tolua_S,"DRAG_RESIZE_RIGHT",DRAG_RESIZE_RIGHT);
 tolua_constant(tolua_S,"DRAG_RESIZE_BOTTOMRIGHT",DRAG_RESIZE_BOTTOMRIGHT);
 tolua_constant(tolua_S,"DRAG_RESIZE_BOTTOM",DRAG_RESIZE_BOTTOM);
 tolua_constant(tolua_S,"DRAG_RESIZE_BOTTOMLEFT",DRAG_RESIZE_BOTTOMLEFT);
 tolua_constant(tolua_S,"DRAG_RESIZE_LEFT",DRAG_RESIZE_LEFT);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Window","Window","BorderImage",tolua_collect_Window);
 #else
 tolua_cclass(tolua_S,"Window","Window","BorderImage",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Window");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_Window_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_Window_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_Window_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_Window_delete00);
  tolua_function(tolua_S,"SetMovable",tolua_UILuaAPI_Window_SetMovable00);
  tolua_function(tolua_S,"SetResizable",tolua_UILuaAPI_Window_SetResizable00);
  tolua_function(tolua_S,"SetFixedWidthResizing",tolua_UILuaAPI_Window_SetFixedWidthResizing00);
  tolua_function(tolua_S,"SetFixedHeightResizing",tolua_UILuaAPI_Window_SetFixedHeightResizing00);
  tolua_function(tolua_S,"SetResizeBorder",tolua_UILuaAPI_Window_SetResizeBorder00);
  tolua_function(tolua_S,"SetModal",tolua_UILuaAPI_Window_SetModal00);
  tolua_function(tolua_S,"SetModalShadeColor",tolua_UILuaAPI_Window_SetModalShadeColor00);
  tolua_function(tolua_S,"SetModalFrameColor",tolua_UILuaAPI_Window_SetModalFrameColor00);
  tolua_function(tolua_S,"SetModalFrameSize",tolua_UILuaAPI_Window_SetModalFrameSize00);
  tolua_function(tolua_S,"SetModalAutoDismiss",tolua_UILuaAPI_Window_SetModalAutoDismiss00);
  tolua_function(tolua_S,"IsMovable",tolua_UILuaAPI_Window_IsMovable00);
  tolua_function(tolua_S,"IsResizable",tolua_UILuaAPI_Window_IsResizable00);
  tolua_function(tolua_S,"GetFixedWidthResizing",tolua_UILuaAPI_Window_GetFixedWidthResizing00);
  tolua_function(tolua_S,"GetFixedHeightResizing",tolua_UILuaAPI_Window_GetFixedHeightResizing00);
  tolua_function(tolua_S,"GetResizeBorder",tolua_UILuaAPI_Window_GetResizeBorder00);
  tolua_function(tolua_S,"IsModal",tolua_UILuaAPI_Window_IsModal00);
  tolua_function(tolua_S,"GetModalShadeColor",tolua_UILuaAPI_Window_GetModalShadeColor00);
  tolua_function(tolua_S,"GetModalFrameColor",tolua_UILuaAPI_Window_GetModalFrameColor00);
  tolua_function(tolua_S,"GetModalFrameSize",tolua_UILuaAPI_Window_GetModalFrameSize00);
  tolua_function(tolua_S,"GetModalAutoDismiss",tolua_UILuaAPI_Window_GetModalAutoDismiss00);
  tolua_variable(tolua_S,"movable",tolua_get_Window_movable,tolua_set_Window_movable);
  tolua_variable(tolua_S,"resizable",tolua_get_Window_resizable,tolua_set_Window_resizable);
  tolua_variable(tolua_S,"fixedWidthResizing",tolua_get_Window_fixedWidthResizing,tolua_set_Window_fixedWidthResizing);
  tolua_variable(tolua_S,"fixedHeightResizing",tolua_get_Window_fixedHeightResizing,tolua_set_Window_fixedHeightResizing);
  tolua_variable(tolua_S,"resizeBorder",tolua_get_Window_resizeBorder_ref,tolua_set_Window_resizeBorder_ref);
  tolua_variable(tolua_S,"modal",tolua_get_Window_modal,tolua_set_Window_modal);
  tolua_variable(tolua_S,"modalShadeColor",tolua_get_Window_modalShadeColor_ref,tolua_set_Window_modalShadeColor_ref);
  tolua_variable(tolua_S,"modalFrameColor",tolua_get_Window_modalFrameColor_ref,tolua_set_Window_modalFrameColor_ref);
  tolua_variable(tolua_S,"modalFrameSize",tolua_get_Window_modalFrameSize_ref,tolua_set_Window_modalFrameSize_ref);
  tolua_variable(tolua_S,"modalAutoDismiss",tolua_get_Window_modalAutoDismiss,tolua_set_Window_modalAutoDismiss);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"View3D","View3D","Window",tolua_collect_View3D);
 #else
 tolua_cclass(tolua_S,"View3D","View3D","Window",NULL);
 #endif
 tolua_beginmodule(tolua_S,"View3D");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_View3D_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_View3D_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_View3D_new00_local);
  tolua_function(tolua_S,"delete",tolua_UILuaAPI_View3D_delete00);
  tolua_function(tolua_S,"SetView",tolua_UILuaAPI_View3D_SetView00);
  tolua_function(tolua_S,"SetFormat",tolua_UILuaAPI_View3D_SetFormat00);
  tolua_function(tolua_S,"SetAutoUpdate",tolua_UILuaAPI_View3D_SetAutoUpdate00);
  tolua_function(tolua_S,"QueueUpdate",tolua_UILuaAPI_View3D_QueueUpdate00);
  tolua_function(tolua_S,"GetFormat",tolua_UILuaAPI_View3D_GetFormat00);
  tolua_function(tolua_S,"GetAutoUpdate",tolua_UILuaAPI_View3D_GetAutoUpdate00);
  tolua_function(tolua_S,"GetScene",tolua_UILuaAPI_View3D_GetScene00);
  tolua_function(tolua_S,"GetCameraNode",tolua_UILuaAPI_View3D_GetCameraNode00);
  tolua_function(tolua_S,"GetRenderTexture",tolua_UILuaAPI_View3D_GetRenderTexture00);
  tolua_function(tolua_S,"GetDepthTexture",tolua_UILuaAPI_View3D_GetDepthTexture00);
  tolua_function(tolua_S,"GetViewport",tolua_UILuaAPI_View3D_GetViewport00);
  tolua_variable(tolua_S,"format",tolua_get_View3D_format,tolua_set_View3D_format);
  tolua_variable(tolua_S,"autoUpdate",tolua_get_View3D_autoUpdate,tolua_set_View3D_autoUpdate);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"UIComponent","UIComponent","Component",tolua_collect_UIComponent);
 #else
 tolua_cclass(tolua_S,"UIComponent","UIComponent","Component",NULL);
 #endif
 tolua_beginmodule(tolua_S,"UIComponent");
  tolua_function(tolua_S,"new",tolua_UILuaAPI_UIComponent_new00);
  tolua_function(tolua_S,"new_local",tolua_UILuaAPI_UIComponent_new00_local);
  tolua_function(tolua_S,".call",tolua_UILuaAPI_UIComponent_new00_local);
  tolua_function(tolua_S,"GetRoot",tolua_UILuaAPI_UIComponent_GetRoot00);
  tolua_function(tolua_S,"GetMaterial",tolua_UILuaAPI_UIComponent_GetMaterial00);
  tolua_function(tolua_S,"GetTexture",tolua_UILuaAPI_UIComponent_GetTexture00);
  tolua_variable(tolua_S,"root",tolua_get_UIComponent_root_ptr,NULL);
  tolua_variable(tolua_S,"material",tolua_get_UIComponent_material_ptr,NULL);
  tolua_variable(tolua_S,"texture",tolua_get_UIComponent_texture_ptr,NULL);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_UILuaAPI (lua_State* tolua_S) {
 return tolua_UILuaAPI_open(tolua_S);
};
#endif

#if __clang__
#pragma clang diagnostic pop
#endif