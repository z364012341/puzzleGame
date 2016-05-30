#include "lua_PuzzleStageDataManager_auto.hpp"
#include "PuzzleStageDataManager.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_PuzzleStageDataManager_PuzzleStageDataManager_getGameTimeWithkey(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::PuzzleStageDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.PuzzleStageDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::PuzzleStageDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_PuzzleStageDataManager_PuzzleStageDataManager_getGameTimeWithkey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.PuzzleStageDataManager:getGameTimeWithkey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PuzzleStageDataManager_PuzzleStageDataManager_getGameTimeWithkey'", nullptr);
            return 0;
        }
        int ret = cobj->getGameTimeWithkey(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.PuzzleStageDataManager:getGameTimeWithkey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PuzzleStageDataManager_PuzzleStageDataManager_getGameTimeWithkey'.",&tolua_err);
#endif

    return 0;
}
int lua_PuzzleStageDataManager_PuzzleStageDataManager_loadPuzzleStageData(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::PuzzleStageDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.PuzzleStageDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::PuzzleStageDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_PuzzleStageDataManager_PuzzleStageDataManager_loadPuzzleStageData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PuzzleStageDataManager_PuzzleStageDataManager_loadPuzzleStageData'", nullptr);
            return 0;
        }
        cobj->loadPuzzleStageData();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.PuzzleStageDataManager:loadPuzzleStageData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PuzzleStageDataManager_PuzzleStageDataManager_loadPuzzleStageData'.",&tolua_err);
#endif

    return 0;
}
int lua_PuzzleStageDataManager_PuzzleStageDataManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.PuzzleStageDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PuzzleStageDataManager_PuzzleStageDataManager_getInstance'", nullptr);
            return 0;
        }
        bubble_second::PuzzleStageDataManager* ret = bubble_second::PuzzleStageDataManager::getInstance();
        object_to_luaval<bubble_second::PuzzleStageDataManager>(tolua_S, "bs.PuzzleStageDataManager",(bubble_second::PuzzleStageDataManager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.PuzzleStageDataManager:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PuzzleStageDataManager_PuzzleStageDataManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_PuzzleStageDataManager_PuzzleStageDataManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PuzzleStageDataManager)");
    return 0;
}

int lua_register_PuzzleStageDataManager_PuzzleStageDataManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.PuzzleStageDataManager");
    tolua_cclass(tolua_S,"PuzzleStageDataManager","bs.PuzzleStageDataManager","",nullptr);

    tolua_beginmodule(tolua_S,"PuzzleStageDataManager");
        tolua_function(tolua_S,"getGameTimeWithkey",lua_PuzzleStageDataManager_PuzzleStageDataManager_getGameTimeWithkey);
        tolua_function(tolua_S,"loadPuzzleStageData",lua_PuzzleStageDataManager_PuzzleStageDataManager_loadPuzzleStageData);
        tolua_function(tolua_S,"getInstance", lua_PuzzleStageDataManager_PuzzleStageDataManager_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::PuzzleStageDataManager).name();
    g_luaType[typeName] = "bs.PuzzleStageDataManager";
    g_typeCast["PuzzleStageDataManager"] = "bs.PuzzleStageDataManager";
    return 1;
}
TOLUA_API int register_all_PuzzleStageDataManager(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_PuzzleStageDataManager_PuzzleStageDataManager(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

