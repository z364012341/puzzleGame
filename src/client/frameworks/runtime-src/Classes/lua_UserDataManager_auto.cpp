#include "lua_UserDataManager_auto.hpp"
#include "UserDataManager.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_UserDataManager_UserDataManager_setBuyPropsKeyAndNumble(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_setBuyPropsKeyAndNumble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ValueMap arg0;

        ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "bs.UserDataManager:setBuyPropsKeyAndNumble");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_setBuyPropsKeyAndNumble'", nullptr);
            return 0;
        }
        cobj->setBuyPropsKeyAndNumble(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:setBuyPropsKeyAndNumble",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_setBuyPropsKeyAndNumble'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_savePuzzleStageData(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_savePuzzleStageData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_savePuzzleStageData'", nullptr);
            return 0;
        }
        cobj->savePuzzleStageData();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:savePuzzleStageData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_savePuzzleStageData'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_cutPropsNumbleWithKey(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_cutPropsNumbleWithKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.UserDataManager:cutPropsNumbleWithKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_cutPropsNumbleWithKey'", nullptr);
            return 0;
        }
        cobj->cutPropsNumbleWithKey(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:cutPropsNumbleWithKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_cutPropsNumbleWithKey'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_setGameMusicEnable(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_setGameMusicEnable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "bs.UserDataManager:setGameMusicEnable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_setGameMusicEnable'", nullptr);
            return 0;
        }
        cobj->setGameMusicEnable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:setGameMusicEnable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_setGameMusicEnable'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_isGameMusicEnable(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_isGameMusicEnable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_isGameMusicEnable'", nullptr);
            return 0;
        }
        bool ret = cobj->isGameMusicEnable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:isGameMusicEnable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_isGameMusicEnable'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_getUserNickname(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_getUserNickname'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_getUserNickname'", nullptr);
            return 0;
        }
        std::string ret = cobj->getUserNickname();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:getUserNickname",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_getUserNickname'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_isUnlockWithStageNumble(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_isUnlockWithStageNumble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.UserDataManager:isUnlockWithStageNumble");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_isUnlockWithStageNumble'", nullptr);
            return 0;
        }
        bool ret = cobj->isUnlockWithStageNumble(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:isUnlockWithStageNumble",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_isUnlockWithStageNumble'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_readDataFile(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_readDataFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_readDataFile'", nullptr);
            return 0;
        }
        cobj->readDataFile();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:readDataFile",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_readDataFile'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_insertPuzzleStageData(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_insertPuzzleStageData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.UserDataManager:insertPuzzleStageData");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "bs.UserDataManager:insertPuzzleStageData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_insertPuzzleStageData'", nullptr);
            return 0;
        }
        cobj->insertPuzzleStageData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:insertPuzzleStageData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_insertPuzzleStageData'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_getPuzzleStageBestScoreWithKey(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_getPuzzleStageBestScoreWithKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.UserDataManager:getPuzzleStageBestScoreWithKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_getPuzzleStageBestScoreWithKey'", nullptr);
            return 0;
        }
        int ret = cobj->getPuzzleStageBestScoreWithKey(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:getPuzzleStageBestScoreWithKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_getPuzzleStageBestScoreWithKey'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_canBuyNewbieGift(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_canBuyNewbieGift'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_canBuyNewbieGift'", nullptr);
            return 0;
        }
        bool ret = cobj->canBuyNewbieGift();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:canBuyNewbieGift",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_canBuyNewbieGift'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_getStagePassCount(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_getStagePassCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_getStagePassCount'", nullptr);
            return 0;
        }
        int ret = cobj->getStagePassCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:getStagePassCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_getStagePassCount'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_saveUserData(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_saveUserData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_saveUserData'", nullptr);
            return 0;
        }
        cobj->saveUserData();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:saveUserData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_saveUserData'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_setPropsNumbleWithKey(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_setPropsNumbleWithKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.UserDataManager:setPropsNumbleWithKey");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "bs.UserDataManager:setPropsNumbleWithKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_setPropsNumbleWithKey'", nullptr);
            return 0;
        }
        cobj->setPropsNumbleWithKey(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:setPropsNumbleWithKey",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_setPropsNumbleWithKey'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_setUserNickname(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_setUserNickname'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.UserDataManager:setUserNickname");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_setUserNickname'", nullptr);
            return 0;
        }
        cobj->setUserNickname(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:setUserNickname",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_setUserNickname'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_setSoundEffect(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_setSoundEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "bs.UserDataManager:setSoundEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_setSoundEffect'", nullptr);
            return 0;
        }
        cobj->setSoundEffect(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:setSoundEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_setSoundEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_getStartNumbleWithLevel(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_getStartNumbleWithLevel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.UserDataManager:getStartNumbleWithLevel");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_getStartNumbleWithLevel'", nullptr);
            return 0;
        }
        int ret = cobj->getStartNumbleWithLevel(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:getStartNumbleWithLevel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_getStartNumbleWithLevel'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_setPresentCell(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_setPresentCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.UserDataManager:setPresentCell");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_setPresentCell'", nullptr);
            return 0;
        }
        cobj->setPresentCell(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:setPresentCell",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_setPresentCell'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_addPropsNumbleWithKey(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_addPropsNumbleWithKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.UserDataManager:addPropsNumbleWithKey");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "bs.UserDataManager:addPropsNumbleWithKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_addPropsNumbleWithKey'", nullptr);
            return 0;
        }
        cobj->addPropsNumbleWithKey(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:addPropsNumbleWithKey",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_addPropsNumbleWithKey'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_getPropsNumbleWithKey(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_getPropsNumbleWithKey'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.UserDataManager:getPropsNumbleWithKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_getPropsNumbleWithKey'", nullptr);
            return 0;
        }
        int ret = cobj->getPropsNumbleWithKey(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:getPropsNumbleWithKey",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_getPropsNumbleWithKey'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_buyNewbieGift(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_buyNewbieGift'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_buyNewbieGift'", nullptr);
            return 0;
        }
        cobj->buyNewbieGift();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:buyNewbieGift",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_buyNewbieGift'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_readPuzzleStageBestScore(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_readPuzzleStageBestScore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_readPuzzleStageBestScore'", nullptr);
            return 0;
        }
        cobj->readPuzzleStageBestScore();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:readPuzzleStageBestScore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_readPuzzleStageBestScore'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_updateStageData(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_updateStageData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.UserDataManager:updateStageData");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "bs.UserDataManager:updateStageData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_updateStageData'", nullptr);
            return 0;
        }
        cobj->updateStageData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:updateStageData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_updateStageData'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_getPresentCell(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_getPresentCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_getPresentCell'", nullptr);
            return 0;
        }
        int ret = cobj->getPresentCell();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:getPresentCell",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_getPresentCell'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_isSoundEffectEnable(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_isSoundEffectEnable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_isSoundEffectEnable'", nullptr);
            return 0;
        }
        bool ret = cobj->isSoundEffectEnable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:isSoundEffectEnable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_isSoundEffectEnable'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_addUnlockStageNumble(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::UserDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UserDataManager_UserDataManager_addUnlockStageNumble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_addUnlockStageNumble'", nullptr);
            return 0;
        }
        cobj->addUnlockStageNumble();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:addUnlockStageNumble",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_addUnlockStageNumble'.",&tolua_err);
#endif

    return 0;
}
int lua_UserDataManager_UserDataManager_getPuzzleAddTimePropKey(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_getPuzzleAddTimePropKey'", nullptr);
            return 0;
        }
        const std::string ret = bubble_second::UserDataManager::getPuzzleAddTimePropKey();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.UserDataManager:getPuzzleAddTimePropKey",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_getPuzzleAddTimePropKey'.",&tolua_err);
#endif
    return 0;
}
int lua_UserDataManager_UserDataManager_getPuzzleSearchPropKey(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_getPuzzleSearchPropKey'", nullptr);
            return 0;
        }
        const std::string ret = bubble_second::UserDataManager::getPuzzleSearchPropKey();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.UserDataManager:getPuzzleSearchPropKey",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_getPuzzleSearchPropKey'.",&tolua_err);
#endif
    return 0;
}
int lua_UserDataManager_UserDataManager_getPuzzleBigEyesPropKey(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_getPuzzleBigEyesPropKey'", nullptr);
            return 0;
        }
        const std::string ret = bubble_second::UserDataManager::getPuzzleBigEyesPropKey();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.UserDataManager:getPuzzleBigEyesPropKey",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_getPuzzleBigEyesPropKey'.",&tolua_err);
#endif
    return 0;
}
int lua_UserDataManager_UserDataManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.UserDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_getInstance'", nullptr);
            return 0;
        }
        bubble_second::UserDataManager* ret = bubble_second::UserDataManager::getInstance();
        object_to_luaval<bubble_second::UserDataManager>(tolua_S, "bs.UserDataManager",(bubble_second::UserDataManager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.UserDataManager:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_UserDataManager_UserDataManager_constructor(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::UserDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UserDataManager_UserDataManager_constructor'", nullptr);
            return 0;
        }
        cobj = new bubble_second::UserDataManager();
        tolua_pushusertype(tolua_S,(void*)cobj,"bs.UserDataManager");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.UserDataManager:UserDataManager",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_UserDataManager_UserDataManager_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_UserDataManager_UserDataManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UserDataManager)");
    return 0;
}

int lua_register_UserDataManager_UserDataManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.UserDataManager");
    tolua_cclass(tolua_S,"UserDataManager","bs.UserDataManager","",nullptr);

    tolua_beginmodule(tolua_S,"UserDataManager");
        tolua_function(tolua_S,"new",lua_UserDataManager_UserDataManager_constructor);
        tolua_function(tolua_S,"setBuyPropsKeyAndNumble",lua_UserDataManager_UserDataManager_setBuyPropsKeyAndNumble);
        tolua_function(tolua_S,"savePuzzleStageData",lua_UserDataManager_UserDataManager_savePuzzleStageData);
        tolua_function(tolua_S,"cutPropsNumbleWithKey",lua_UserDataManager_UserDataManager_cutPropsNumbleWithKey);
        tolua_function(tolua_S,"setGameMusicEnable",lua_UserDataManager_UserDataManager_setGameMusicEnable);
        tolua_function(tolua_S,"isGameMusicEnable",lua_UserDataManager_UserDataManager_isGameMusicEnable);
        tolua_function(tolua_S,"getUserNickname",lua_UserDataManager_UserDataManager_getUserNickname);
        tolua_function(tolua_S,"isUnlockWithStageNumble",lua_UserDataManager_UserDataManager_isUnlockWithStageNumble);
        tolua_function(tolua_S,"readDataFile",lua_UserDataManager_UserDataManager_readDataFile);
        tolua_function(tolua_S,"insertPuzzleStageData",lua_UserDataManager_UserDataManager_insertPuzzleStageData);
        tolua_function(tolua_S,"getPuzzleStageBestScoreWithKey",lua_UserDataManager_UserDataManager_getPuzzleStageBestScoreWithKey);
        tolua_function(tolua_S,"canBuyNewbieGift",lua_UserDataManager_UserDataManager_canBuyNewbieGift);
        tolua_function(tolua_S,"getStagePassCount",lua_UserDataManager_UserDataManager_getStagePassCount);
        tolua_function(tolua_S,"saveUserData",lua_UserDataManager_UserDataManager_saveUserData);
        tolua_function(tolua_S,"setPropsNumbleWithKey",lua_UserDataManager_UserDataManager_setPropsNumbleWithKey);
        tolua_function(tolua_S,"setUserNickname",lua_UserDataManager_UserDataManager_setUserNickname);
        tolua_function(tolua_S,"setSoundEffect",lua_UserDataManager_UserDataManager_setSoundEffect);
        tolua_function(tolua_S,"getStartNumbleWithLevel",lua_UserDataManager_UserDataManager_getStartNumbleWithLevel);
        tolua_function(tolua_S,"setPresentCell",lua_UserDataManager_UserDataManager_setPresentCell);
        tolua_function(tolua_S,"addPropsNumbleWithKey",lua_UserDataManager_UserDataManager_addPropsNumbleWithKey);
        tolua_function(tolua_S,"getPropsNumbleWithKey",lua_UserDataManager_UserDataManager_getPropsNumbleWithKey);
        tolua_function(tolua_S,"buyNewbieGift",lua_UserDataManager_UserDataManager_buyNewbieGift);
        tolua_function(tolua_S,"readPuzzleStageBestScore",lua_UserDataManager_UserDataManager_readPuzzleStageBestScore);
        tolua_function(tolua_S,"updateStageData",lua_UserDataManager_UserDataManager_updateStageData);
        tolua_function(tolua_S,"getPresentCell",lua_UserDataManager_UserDataManager_getPresentCell);
        tolua_function(tolua_S,"isSoundEffectEnable",lua_UserDataManager_UserDataManager_isSoundEffectEnable);
        tolua_function(tolua_S,"addUnlockStageNumble",lua_UserDataManager_UserDataManager_addUnlockStageNumble);
        tolua_function(tolua_S,"getPuzzleAddTimePropKey", lua_UserDataManager_UserDataManager_getPuzzleAddTimePropKey);
        tolua_function(tolua_S,"getPuzzleSearchPropKey", lua_UserDataManager_UserDataManager_getPuzzleSearchPropKey);
        tolua_function(tolua_S,"getPuzzleBigEyesPropKey", lua_UserDataManager_UserDataManager_getPuzzleBigEyesPropKey);
        tolua_function(tolua_S,"getInstance", lua_UserDataManager_UserDataManager_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::UserDataManager).name();
    g_luaType[typeName] = "bs.UserDataManager";
    g_typeCast["UserDataManager"] = "bs.UserDataManager";
    return 1;
}
TOLUA_API int register_all_UserDataManager(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_UserDataManager_UserDataManager(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

