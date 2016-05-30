#include "lua_SpriteTextureController_auto.hpp"
#include "SpriteTextureController.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_SpriteTextureController_SpriteTextureController_setGrayShader(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::SpriteTextureController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.SpriteTextureController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::SpriteTextureController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_SpriteTextureController_SpriteTextureController_setGrayShader'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Sprite* arg0;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0, "bs.SpriteTextureController:setGrayShader");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SpriteTextureController_SpriteTextureController_setGrayShader'", nullptr);
            return 0;
        }
        cobj->setGrayShader(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.SpriteTextureController:setGrayShader",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SpriteTextureController_SpriteTextureController_setGrayShader'.",&tolua_err);
#endif

    return 0;
}
int lua_SpriteTextureController_SpriteTextureController_setSpriteTexture(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::SpriteTextureController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.SpriteTextureController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::SpriteTextureController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_SpriteTextureController_SpriteTextureController_setSpriteTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Sprite* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.SpriteTextureController:setSpriteTexture");

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 3, "cc.Sprite",&arg1, "bs.SpriteTextureController:setSpriteTexture");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SpriteTextureController_SpriteTextureController_setSpriteTexture'", nullptr);
            return 0;
        }
        cobj->setSpriteTexture(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.SpriteTextureController:setSpriteTexture",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SpriteTextureController_SpriteTextureController_setSpriteTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_SpriteTextureController_SpriteTextureController_createStageTypeSprite(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::SpriteTextureController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.SpriteTextureController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::SpriteTextureController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_SpriteTextureController_SpriteTextureController_createStageTypeSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        StageType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.SpriteTextureController:createStageTypeSprite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SpriteTextureController_SpriteTextureController_createStageTypeSprite'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->createStageTypeSprite(arg0);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.SpriteTextureController:createStageTypeSprite",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SpriteTextureController_SpriteTextureController_createStageTypeSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_SpriteTextureController_SpriteTextureController_addResourcesTexture(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::SpriteTextureController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.SpriteTextureController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::SpriteTextureController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_SpriteTextureController_SpriteTextureController_addResourcesTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SpriteTextureController_SpriteTextureController_addResourcesTexture'", nullptr);
            return 0;
        }
        cobj->addResourcesTexture();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.SpriteTextureController:addResourcesTexture",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SpriteTextureController_SpriteTextureController_addResourcesTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_SpriteTextureController_SpriteTextureController_createGameBackgroundSprite(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::SpriteTextureController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.SpriteTextureController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::SpriteTextureController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_SpriteTextureController_SpriteTextureController_createGameBackgroundSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.SpriteTextureController:createGameBackgroundSprite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SpriteTextureController_SpriteTextureController_createGameBackgroundSprite'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->createGameBackgroundSprite(arg0);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.SpriteTextureController:createGameBackgroundSprite",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SpriteTextureController_SpriteTextureController_createGameBackgroundSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_SpriteTextureController_SpriteTextureController_createGameSpriteWithPath(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::SpriteTextureController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.SpriteTextureController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::SpriteTextureController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_SpriteTextureController_SpriteTextureController_createGameSpriteWithPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.SpriteTextureController:createGameSpriteWithPath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SpriteTextureController_SpriteTextureController_createGameSpriteWithPath'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->createGameSpriteWithPath(arg0);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.SpriteTextureController:createGameSpriteWithPath",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SpriteTextureController_SpriteTextureController_createGameSpriteWithPath'.",&tolua_err);
#endif

    return 0;
}
int lua_SpriteTextureController_SpriteTextureController_createMenuStageTypeSprite(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::SpriteTextureController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.SpriteTextureController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::SpriteTextureController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_SpriteTextureController_SpriteTextureController_createMenuStageTypeSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        StageType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.SpriteTextureController:createMenuStageTypeSprite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SpriteTextureController_SpriteTextureController_createMenuStageTypeSprite'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->createMenuStageTypeSprite(arg0);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.SpriteTextureController:createMenuStageTypeSprite",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SpriteTextureController_SpriteTextureController_createMenuStageTypeSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_SpriteTextureController_SpriteTextureController_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.SpriteTextureController",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SpriteTextureController_SpriteTextureController_getInstance'", nullptr);
            return 0;
        }
        bubble_second::SpriteTextureController* ret = bubble_second::SpriteTextureController::getInstance();
        object_to_luaval<bubble_second::SpriteTextureController>(tolua_S, "bs.SpriteTextureController",(bubble_second::SpriteTextureController*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.SpriteTextureController:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SpriteTextureController_SpriteTextureController_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_SpriteTextureController_SpriteTextureController_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SpriteTextureController)");
    return 0;
}

int lua_register_SpriteTextureController_SpriteTextureController(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.SpriteTextureController");
    tolua_cclass(tolua_S,"SpriteTextureController","bs.SpriteTextureController","",nullptr);

    tolua_beginmodule(tolua_S,"SpriteTextureController");
        tolua_function(tolua_S,"setGrayShader",lua_SpriteTextureController_SpriteTextureController_setGrayShader);
        tolua_function(tolua_S,"setSpriteTexture",lua_SpriteTextureController_SpriteTextureController_setSpriteTexture);
        tolua_function(tolua_S,"createStageTypeSprite",lua_SpriteTextureController_SpriteTextureController_createStageTypeSprite);
        tolua_function(tolua_S,"addResourcesTexture",lua_SpriteTextureController_SpriteTextureController_addResourcesTexture);
        tolua_function(tolua_S,"createGameBackgroundSprite",lua_SpriteTextureController_SpriteTextureController_createGameBackgroundSprite);
        tolua_function(tolua_S,"createGameSpriteWithPath",lua_SpriteTextureController_SpriteTextureController_createGameSpriteWithPath);
        tolua_function(tolua_S,"createMenuStageTypeSprite",lua_SpriteTextureController_SpriteTextureController_createMenuStageTypeSprite);
        tolua_function(tolua_S,"getInstance", lua_SpriteTextureController_SpriteTextureController_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::SpriteTextureController).name();
    g_luaType[typeName] = "bs.SpriteTextureController";
    g_typeCast["SpriteTextureController"] = "bs.SpriteTextureController";
    return 1;
}
TOLUA_API int register_all_SpriteTextureController(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_SpriteTextureController_SpriteTextureController(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

