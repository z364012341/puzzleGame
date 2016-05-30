#include "lua_PuzzleStoreItemFactory_auto.hpp"
#include "PuzzleStoreItemFactory.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_createItemWithIndex(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::PuzzleStoreItemFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.PuzzleStoreItemFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::PuzzleStoreItemFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_createItemWithIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.PuzzleStoreItemFactory:createItemWithIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_createItemWithIndex'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->createItemWithIndex(arg0);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.PuzzleStoreItemFactory:createItemWithIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_createItemWithIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_createGiftsItemWithIndex(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::PuzzleStoreItemFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.PuzzleStoreItemFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::PuzzleStoreItemFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_createGiftsItemWithIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.PuzzleStoreItemFactory:createGiftsItemWithIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_createGiftsItemWithIndex'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->createGiftsItemWithIndex(arg0);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.PuzzleStoreItemFactory:createGiftsItemWithIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_createGiftsItemWithIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_loadItemData(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::PuzzleStoreItemFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.PuzzleStoreItemFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::PuzzleStoreItemFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_loadItemData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_loadItemData'", nullptr);
            return 0;
        }
        cobj->loadItemData();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.PuzzleStoreItemFactory:loadItemData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_loadItemData'.",&tolua_err);
#endif

    return 0;
}
int lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_getGiftsItemTotal(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::PuzzleStoreItemFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.PuzzleStoreItemFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::PuzzleStoreItemFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_getGiftsItemTotal'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_getGiftsItemTotal'", nullptr);
            return 0;
        }
        int ret = cobj->getGiftsItemTotal();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.PuzzleStoreItemFactory:getGiftsItemTotal",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_getGiftsItemTotal'.",&tolua_err);
#endif

    return 0;
}
int lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_getItemTotal(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::PuzzleStoreItemFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.PuzzleStoreItemFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::PuzzleStoreItemFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_getItemTotal'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_getItemTotal'", nullptr);
            return 0;
        }
        int ret = cobj->getItemTotal();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.PuzzleStoreItemFactory:getItemTotal",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_getItemTotal'.",&tolua_err);
#endif

    return 0;
}
int lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_createNewbieAlert(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::PuzzleStoreItemFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.PuzzleStoreItemFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::PuzzleStoreItemFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_createNewbieAlert'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_createNewbieAlert'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->createNewbieAlert();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.PuzzleStoreItemFactory:createNewbieAlert",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_createNewbieAlert'.",&tolua_err);
#endif

    return 0;
}
int lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.PuzzleStoreItemFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_getInstance'", nullptr);
            return 0;
        }
        bubble_second::PuzzleStoreItemFactory* ret = bubble_second::PuzzleStoreItemFactory::getInstance();
        object_to_luaval<bubble_second::PuzzleStoreItemFactory>(tolua_S, "bs.PuzzleStoreItemFactory",(bubble_second::PuzzleStoreItemFactory*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.PuzzleStoreItemFactory:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PuzzleStoreItemFactory)");
    return 0;
}

int lua_register_PuzzleStoreItemFactory_PuzzleStoreItemFactory(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.PuzzleStoreItemFactory");
    tolua_cclass(tolua_S,"PuzzleStoreItemFactory","bs.PuzzleStoreItemFactory","",nullptr);

    tolua_beginmodule(tolua_S,"PuzzleStoreItemFactory");
        tolua_function(tolua_S,"createItemWithIndex",lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_createItemWithIndex);
        tolua_function(tolua_S,"createGiftsItemWithIndex",lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_createGiftsItemWithIndex);
        tolua_function(tolua_S,"loadItemData",lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_loadItemData);
        tolua_function(tolua_S,"getGiftsItemTotal",lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_getGiftsItemTotal);
        tolua_function(tolua_S,"getItemTotal",lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_getItemTotal);
        tolua_function(tolua_S,"createNewbieAlert",lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_createNewbieAlert);
        tolua_function(tolua_S,"getInstance", lua_PuzzleStoreItemFactory_PuzzleStoreItemFactory_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::PuzzleStoreItemFactory).name();
    g_luaType[typeName] = "bs.PuzzleStoreItemFactory";
    g_typeCast["PuzzleStoreItemFactory"] = "bs.PuzzleStoreItemFactory";
    return 1;
}
TOLUA_API int register_all_PuzzleStoreItemFactory(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_PuzzleStoreItemFactory_PuzzleStoreItemFactory(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

