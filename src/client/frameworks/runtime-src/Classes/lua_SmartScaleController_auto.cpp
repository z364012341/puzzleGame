#include "lua_SmartScaleController_auto.hpp"
#include "SmartScaleController.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_SmartScaleController_SmartScaleController_getFixedWidthZoom(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::SmartScaleController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.SmartScaleController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::SmartScaleController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_SmartScaleController_SmartScaleController_getFixedWidthZoom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SmartScaleController_SmartScaleController_getFixedWidthZoom'", nullptr);
            return 0;
        }
        double ret = cobj->getFixedWidthZoom();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.SmartScaleController:getFixedWidthZoom",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SmartScaleController_SmartScaleController_getFixedWidthZoom'.",&tolua_err);
#endif

    return 0;
}
int lua_SmartScaleController_SmartScaleController_getPlayAreaZoom(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::SmartScaleController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.SmartScaleController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::SmartScaleController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_SmartScaleController_SmartScaleController_getPlayAreaZoom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SmartScaleController_SmartScaleController_getPlayAreaZoom'", nullptr);
            return 0;
        }
        double ret = cobj->getPlayAreaZoom();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.SmartScaleController:getPlayAreaZoom",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SmartScaleController_SmartScaleController_getPlayAreaZoom'.",&tolua_err);
#endif

    return 0;
}
int lua_SmartScaleController_SmartScaleController_getFixedHeightZoom(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::SmartScaleController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.SmartScaleController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::SmartScaleController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_SmartScaleController_SmartScaleController_getFixedHeightZoom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SmartScaleController_SmartScaleController_getFixedHeightZoom'", nullptr);
            return 0;
        }
        double ret = cobj->getFixedHeightZoom();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.SmartScaleController:getFixedHeightZoom",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SmartScaleController_SmartScaleController_getFixedHeightZoom'.",&tolua_err);
#endif

    return 0;
}
int lua_SmartScaleController_SmartScaleController_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.SmartScaleController",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SmartScaleController_SmartScaleController_getInstance'", nullptr);
            return 0;
        }
        bubble_second::SmartScaleController* ret = bubble_second::SmartScaleController::getInstance();
        object_to_luaval<bubble_second::SmartScaleController>(tolua_S, "bs.SmartScaleController",(bubble_second::SmartScaleController*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.SmartScaleController:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SmartScaleController_SmartScaleController_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_SmartScaleController_SmartScaleController_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SmartScaleController)");
    return 0;
}

int lua_register_SmartScaleController_SmartScaleController(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.SmartScaleController");
    tolua_cclass(tolua_S,"SmartScaleController","bs.SmartScaleController","",nullptr);

    tolua_beginmodule(tolua_S,"SmartScaleController");
        tolua_function(tolua_S,"getFixedWidthZoom",lua_SmartScaleController_SmartScaleController_getFixedWidthZoom);
        tolua_function(tolua_S,"getPlayAreaZoom",lua_SmartScaleController_SmartScaleController_getPlayAreaZoom);
        tolua_function(tolua_S,"getFixedHeightZoom",lua_SmartScaleController_SmartScaleController_getFixedHeightZoom);
        tolua_function(tolua_S,"getInstance", lua_SmartScaleController_SmartScaleController_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::SmartScaleController).name();
    g_luaType[typeName] = "bs.SmartScaleController";
    g_typeCast["SmartScaleController"] = "bs.SmartScaleController";
    return 1;
}
TOLUA_API int register_all_SmartScaleController(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_SmartScaleController_SmartScaleController(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

