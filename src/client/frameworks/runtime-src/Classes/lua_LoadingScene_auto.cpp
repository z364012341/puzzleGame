#include "lua_LoadingScene_auto.hpp"
#include "LoadingScene.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_LoadingScene_LoadingScene_addBackground(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::LoadingScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.LoadingScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::LoadingScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_LoadingScene_LoadingScene_addBackground'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_LoadingScene_LoadingScene_addBackground'", nullptr);
            return 0;
        }
        cobj->addBackground();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.LoadingScene:addBackground",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_LoadingScene_LoadingScene_addBackground'.",&tolua_err);
#endif

    return 0;
}
int lua_LoadingScene_LoadingScene_beginLoading(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::LoadingScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.LoadingScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::LoadingScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_LoadingScene_LoadingScene_beginLoading'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_LoadingScene_LoadingScene_beginLoading'", nullptr);
            return 0;
        }
        cobj->beginLoading();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.LoadingScene:beginLoading",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_LoadingScene_LoadingScene_beginLoading'.",&tolua_err);
#endif

    return 0;
}
int lua_LoadingScene_LoadingScene_init(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::LoadingScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.LoadingScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::LoadingScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_LoadingScene_LoadingScene_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_LoadingScene_LoadingScene_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.LoadingScene:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_LoadingScene_LoadingScene_init'.",&tolua_err);
#endif

    return 0;
}
int lua_LoadingScene_LoadingScene_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.LoadingScene",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_LoadingScene_LoadingScene_create'", nullptr);
            return 0;
        }
        bubble_second::LoadingScene* ret = bubble_second::LoadingScene::create();
        object_to_luaval<bubble_second::LoadingScene>(tolua_S, "bs.LoadingScene",(bubble_second::LoadingScene*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.LoadingScene:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_LoadingScene_LoadingScene_create'.",&tolua_err);
#endif
    return 0;
}
int lua_LoadingScene_LoadingScene_createScene(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.LoadingScene",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_LoadingScene_LoadingScene_createScene'", nullptr);
            return 0;
        }
        cocos2d::Scene* ret = bubble_second::LoadingScene::createScene();
        object_to_luaval<cocos2d::Scene>(tolua_S, "cc.Scene",(cocos2d::Scene*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.LoadingScene:createScene",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_LoadingScene_LoadingScene_createScene'.",&tolua_err);
#endif
    return 0;
}
int lua_LoadingScene_LoadingScene_constructor(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::LoadingScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_LoadingScene_LoadingScene_constructor'", nullptr);
            return 0;
        }
        cobj = new bubble_second::LoadingScene();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"bs.LoadingScene");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.LoadingScene:LoadingScene",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_LoadingScene_LoadingScene_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_LoadingScene_LoadingScene_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (LoadingScene)");
    return 0;
}

int lua_register_LoadingScene_LoadingScene(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.LoadingScene");
    tolua_cclass(tolua_S,"LoadingScene","bs.LoadingScene","cc.Layer",nullptr);

    tolua_beginmodule(tolua_S,"LoadingScene");
        tolua_function(tolua_S,"new",lua_LoadingScene_LoadingScene_constructor);
        tolua_function(tolua_S,"addBackground",lua_LoadingScene_LoadingScene_addBackground);
        tolua_function(tolua_S,"beginLoading",lua_LoadingScene_LoadingScene_beginLoading);
        tolua_function(tolua_S,"init",lua_LoadingScene_LoadingScene_init);
        tolua_function(tolua_S,"create", lua_LoadingScene_LoadingScene_create);
        tolua_function(tolua_S,"createScene", lua_LoadingScene_LoadingScene_createScene);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::LoadingScene).name();
    g_luaType[typeName] = "bs.LoadingScene";
    g_typeCast["LoadingScene"] = "bs.LoadingScene";
    return 1;
}
TOLUA_API int register_all_LoadingScene(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_LoadingScene_LoadingScene(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

