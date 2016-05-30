#include "lua_PuzzleLoadingScene_auto.hpp"
#include "PuzzleLoadingScene.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_PuzzleLoadingScene_PuzzleLoadingScene_beginLoading(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::PuzzleLoadingScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.PuzzleLoadingScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::PuzzleLoadingScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_PuzzleLoadingScene_PuzzleLoadingScene_beginLoading'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PuzzleLoadingScene_PuzzleLoadingScene_beginLoading'", nullptr);
            return 0;
        }
        cobj->beginLoading();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.PuzzleLoadingScene:beginLoading",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PuzzleLoadingScene_PuzzleLoadingScene_beginLoading'.",&tolua_err);
#endif

    return 0;
}
int lua_PuzzleLoadingScene_PuzzleLoadingScene_init(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::PuzzleLoadingScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.PuzzleLoadingScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::PuzzleLoadingScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_PuzzleLoadingScene_PuzzleLoadingScene_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PuzzleLoadingScene_PuzzleLoadingScene_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.PuzzleLoadingScene:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PuzzleLoadingScene_PuzzleLoadingScene_init'.",&tolua_err);
#endif

    return 0;
}
int lua_PuzzleLoadingScene_PuzzleLoadingScene_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.PuzzleLoadingScene",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PuzzleLoadingScene_PuzzleLoadingScene_create'", nullptr);
            return 0;
        }
        bubble_second::PuzzleLoadingScene* ret = bubble_second::PuzzleLoadingScene::create();
        object_to_luaval<bubble_second::PuzzleLoadingScene>(tolua_S, "bs.PuzzleLoadingScene",(bubble_second::PuzzleLoadingScene*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.PuzzleLoadingScene:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PuzzleLoadingScene_PuzzleLoadingScene_create'.",&tolua_err);
#endif
    return 0;
}
int lua_PuzzleLoadingScene_PuzzleLoadingScene_createScene(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.PuzzleLoadingScene",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PuzzleLoadingScene_PuzzleLoadingScene_createScene'", nullptr);
            return 0;
        }
        cocos2d::Scene* ret = bubble_second::PuzzleLoadingScene::createScene();
        object_to_luaval<cocos2d::Scene>(tolua_S, "cc.Scene",(cocos2d::Scene*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.PuzzleLoadingScene:createScene",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PuzzleLoadingScene_PuzzleLoadingScene_createScene'.",&tolua_err);
#endif
    return 0;
}
int lua_PuzzleLoadingScene_PuzzleLoadingScene_constructor(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::PuzzleLoadingScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PuzzleLoadingScene_PuzzleLoadingScene_constructor'", nullptr);
            return 0;
        }
        cobj = new bubble_second::PuzzleLoadingScene();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"bs.PuzzleLoadingScene");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.PuzzleLoadingScene:PuzzleLoadingScene",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_PuzzleLoadingScene_PuzzleLoadingScene_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_PuzzleLoadingScene_PuzzleLoadingScene_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PuzzleLoadingScene)");
    return 0;
}

int lua_register_PuzzleLoadingScene_PuzzleLoadingScene(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.PuzzleLoadingScene");
    tolua_cclass(tolua_S,"PuzzleLoadingScene","bs.PuzzleLoadingScene","cc.Layer",nullptr);

    tolua_beginmodule(tolua_S,"PuzzleLoadingScene");
        tolua_function(tolua_S,"new",lua_PuzzleLoadingScene_PuzzleLoadingScene_constructor);
        tolua_function(tolua_S,"beginLoading",lua_PuzzleLoadingScene_PuzzleLoadingScene_beginLoading);
        tolua_function(tolua_S,"init",lua_PuzzleLoadingScene_PuzzleLoadingScene_init);
        tolua_function(tolua_S,"create", lua_PuzzleLoadingScene_PuzzleLoadingScene_create);
        tolua_function(tolua_S,"createScene", lua_PuzzleLoadingScene_PuzzleLoadingScene_createScene);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::PuzzleLoadingScene).name();
    g_luaType[typeName] = "bs.PuzzleLoadingScene";
    g_typeCast["PuzzleLoadingScene"] = "bs.PuzzleLoadingScene";
    return 1;
}
TOLUA_API int register_all_PuzzleLoadingScene(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_PuzzleLoadingScene_PuzzleLoadingScene(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

