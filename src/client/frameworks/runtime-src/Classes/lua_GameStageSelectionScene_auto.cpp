#include "lua_GameStageSelectionScene_auto.hpp"
#include "GameStageSelectionScene.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_GameStageSelectionScene_GameStageSelectionScene_getScorllViewOffset(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameStageSelectionScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameStageSelectionScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameStageSelectionScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameStageSelectionScene_GameStageSelectionScene_getScorllViewOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.GameStageSelectionScene:getScorllViewOffset");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameStageSelectionScene_GameStageSelectionScene_getScorllViewOffset'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->getScorllViewOffset(arg0);
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameStageSelectionScene:getScorllViewOffset",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameStageSelectionScene_GameStageSelectionScene_getScorllViewOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_GameStageSelectionScene_GameStageSelectionScene_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GameStageSelectionScene",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameStageSelectionScene_GameStageSelectionScene_create'", nullptr);
            return 0;
        }
        bubble_second::GameStageSelectionScene* ret = bubble_second::GameStageSelectionScene::create();
        object_to_luaval<bubble_second::GameStageSelectionScene>(tolua_S, "bs.GameStageSelectionScene",(bubble_second::GameStageSelectionScene*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GameStageSelectionScene:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameStageSelectionScene_GameStageSelectionScene_create'.",&tolua_err);
#endif
    return 0;
}
int lua_GameStageSelectionScene_GameStageSelectionScene_createScene(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GameStageSelectionScene",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameStageSelectionScene_GameStageSelectionScene_createScene'", nullptr);
            return 0;
        }
        cocos2d::Scene* ret = bubble_second::GameStageSelectionScene::createScene();
        object_to_luaval<cocos2d::Scene>(tolua_S, "cc.Scene",(cocos2d::Scene*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GameStageSelectionScene:createScene",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameStageSelectionScene_GameStageSelectionScene_createScene'.",&tolua_err);
#endif
    return 0;
}
static int lua_GameStageSelectionScene_GameStageSelectionScene_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameStageSelectionScene)");
    return 0;
}

int lua_register_GameStageSelectionScene_GameStageSelectionScene(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.GameStageSelectionScene");
    tolua_cclass(tolua_S,"GameStageSelectionScene","bs.GameStageSelectionScene","cc.Layer",nullptr);

    tolua_beginmodule(tolua_S,"GameStageSelectionScene");
        tolua_function(tolua_S,"getScorllViewOffset",lua_GameStageSelectionScene_GameStageSelectionScene_getScorllViewOffset);
        tolua_function(tolua_S,"create", lua_GameStageSelectionScene_GameStageSelectionScene_create);
        tolua_function(tolua_S,"createScene", lua_GameStageSelectionScene_GameStageSelectionScene_createScene);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::GameStageSelectionScene).name();
    g_luaType[typeName] = "bs.GameStageSelectionScene";
    g_typeCast["GameStageSelectionScene"] = "bs.GameStageSelectionScene";
    return 1;
}
TOLUA_API int register_all_GameStageSelectionScene(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_GameStageSelectionScene_GameStageSelectionScene(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

