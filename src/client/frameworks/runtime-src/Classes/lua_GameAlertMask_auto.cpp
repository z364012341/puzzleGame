#include "lua_GameAlertMask_auto.hpp"
#include "GameAlertMask.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_GameAlertMask_GameAlertMask_backgroundFadeOut(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameAlertMask* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameAlertMask",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameAlertMask*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameAlertMask_GameAlertMask_backgroundFadeOut'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "bs.GameAlertMask:backgroundFadeOut");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAlertMask_GameAlertMask_backgroundFadeOut'", nullptr);
            return 0;
        }
        cobj->backgroundFadeOut(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        double arg0;
        cocos2d::CallFunc* arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "bs.GameAlertMask:backgroundFadeOut");

        ok &= luaval_to_object<cocos2d::CallFunc>(tolua_S, 3, "cc.CallFunc",&arg1, "bs.GameAlertMask:backgroundFadeOut");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAlertMask_GameAlertMask_backgroundFadeOut'", nullptr);
            return 0;
        }
        cobj->backgroundFadeOut(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameAlertMask:backgroundFadeOut",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAlertMask_GameAlertMask_backgroundFadeOut'.",&tolua_err);
#endif

    return 0;
}
int lua_GameAlertMask_GameAlertMask_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GameAlertMask",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAlertMask_GameAlertMask_create'", nullptr);
            return 0;
        }
        bubble_second::GameAlertMask* ret = bubble_second::GameAlertMask::create();
        object_to_luaval<bubble_second::GameAlertMask>(tolua_S, "bs.GameAlertMask",(bubble_second::GameAlertMask*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GameAlertMask:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAlertMask_GameAlertMask_create'.",&tolua_err);
#endif
    return 0;
}
int lua_GameAlertMask_GameAlertMask_createTransparentMask(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GameAlertMask",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameAlertMask_GameAlertMask_createTransparentMask'", nullptr);
            return 0;
        }
        bubble_second::GameAlertMask* ret = bubble_second::GameAlertMask::createTransparentMask();
        object_to_luaval<bubble_second::GameAlertMask>(tolua_S, "bs.GameAlertMask",(bubble_second::GameAlertMask*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GameAlertMask:createTransparentMask",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameAlertMask_GameAlertMask_createTransparentMask'.",&tolua_err);
#endif
    return 0;
}
static int lua_GameAlertMask_GameAlertMask_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameAlertMask)");
    return 0;
}

int lua_register_GameAlertMask_GameAlertMask(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.GameAlertMask");
    tolua_cclass(tolua_S,"GameAlertMask","bs.GameAlertMask","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"GameAlertMask");
        tolua_function(tolua_S,"backgroundFadeOut",lua_GameAlertMask_GameAlertMask_backgroundFadeOut);
        tolua_function(tolua_S,"create", lua_GameAlertMask_GameAlertMask_create);
        tolua_function(tolua_S,"createTransparentMask", lua_GameAlertMask_GameAlertMask_createTransparentMask);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::GameAlertMask).name();
    g_luaType[typeName] = "bs.GameAlertMask";
    g_typeCast["GameAlertMask"] = "bs.GameAlertMask";
    return 1;
}
TOLUA_API int register_all_GameAlertMask(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_GameAlertMask_GameAlertMask(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

