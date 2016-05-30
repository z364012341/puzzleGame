#include "lua_ButtonEffectController_auto.hpp"
#include "ButtonEffectController.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_ButtonEffectController_ButtonEffectController_setButtonsZoomScale(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.ButtonEffectController",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Node* arg0;
        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "bs.ButtonEffectController:setButtonsZoomScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ButtonEffectController_ButtonEffectController_setButtonsZoomScale'", nullptr);
            return 0;
        }
        bubble_second::ButtonEffectController::setButtonsZoomScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.ButtonEffectController:setButtonsZoomScale",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ButtonEffectController_ButtonEffectController_setButtonsZoomScale'.",&tolua_err);
#endif
    return 0;
}
int lua_ButtonEffectController_ButtonEffectController_setButtonZoomScale(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.ButtonEffectController",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::ui::Button* arg0;
        ok &= luaval_to_object<cocos2d::ui::Button>(tolua_S, 2, "ccui.Button",&arg0, "bs.ButtonEffectController:setButtonZoomScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ButtonEffectController_ButtonEffectController_setButtonZoomScale'", nullptr);
            return 0;
        }
        bubble_second::ButtonEffectController::setButtonZoomScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.ButtonEffectController:setButtonZoomScale",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ButtonEffectController_ButtonEffectController_setButtonZoomScale'.",&tolua_err);
#endif
    return 0;
}
static int lua_ButtonEffectController_ButtonEffectController_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ButtonEffectController)");
    return 0;
}

int lua_register_ButtonEffectController_ButtonEffectController(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.ButtonEffectController");
    tolua_cclass(tolua_S,"ButtonEffectController","bs.ButtonEffectController","",nullptr);

    tolua_beginmodule(tolua_S,"ButtonEffectController");
        tolua_function(tolua_S,"setButtonsZoomScale", lua_ButtonEffectController_ButtonEffectController_setButtonsZoomScale);
        tolua_function(tolua_S,"setButtonZoomScale", lua_ButtonEffectController_ButtonEffectController_setButtonZoomScale);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::ButtonEffectController).name();
    g_luaType[typeName] = "bs.ButtonEffectController";
    g_typeCast["ButtonEffectController"] = "bs.ButtonEffectController";
    return 1;
}
TOLUA_API int register_all_ButtonEffectController(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_ButtonEffectController_ButtonEffectController(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

