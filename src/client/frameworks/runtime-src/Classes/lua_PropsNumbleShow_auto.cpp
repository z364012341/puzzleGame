#include "lua_PropsNumbleShow_auto.hpp"
#include "PropsNumbleShow.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_PropsNumbleShow_PropsNumbleShow_cutPropNumble(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::PropsNumbleShow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.PropsNumbleShow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::PropsNumbleShow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_PropsNumbleShow_PropsNumbleShow_cutPropNumble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PropsNumbleShow_PropsNumbleShow_cutPropNumble'", nullptr);
            return 0;
        }
        bool ret = cobj->cutPropNumble();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.PropsNumbleShow:cutPropNumble",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PropsNumbleShow_PropsNumbleShow_cutPropNumble'.",&tolua_err);
#endif

    return 0;
}
int lua_PropsNumbleShow_PropsNumbleShow_setPropNumble(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::PropsNumbleShow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.PropsNumbleShow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::PropsNumbleShow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_PropsNumbleShow_PropsNumbleShow_setPropNumble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "bs.PropsNumbleShow:setPropNumble");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PropsNumbleShow_PropsNumbleShow_setPropNumble'", nullptr);
            return 0;
        }
        cobj->setPropNumble(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.PropsNumbleShow:setPropNumble",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PropsNumbleShow_PropsNumbleShow_setPropNumble'.",&tolua_err);
#endif

    return 0;
}
int lua_PropsNumbleShow_PropsNumbleShow_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.PropsNumbleShow",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "bs.PropsNumbleShow:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PropsNumbleShow_PropsNumbleShow_create'", nullptr);
            return 0;
        }
        bubble_second::PropsNumbleShow* ret = bubble_second::PropsNumbleShow::create(arg0);
        object_to_luaval<bubble_second::PropsNumbleShow>(tolua_S, "bs.PropsNumbleShow",(bubble_second::PropsNumbleShow*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.PropsNumbleShow:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PropsNumbleShow_PropsNumbleShow_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_PropsNumbleShow_PropsNumbleShow_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PropsNumbleShow)");
    return 0;
}

int lua_register_PropsNumbleShow_PropsNumbleShow(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.PropsNumbleShow");
    tolua_cclass(tolua_S,"PropsNumbleShow","bs.PropsNumbleShow","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"PropsNumbleShow");
        tolua_function(tolua_S,"cutPropNumble",lua_PropsNumbleShow_PropsNumbleShow_cutPropNumble);
        tolua_function(tolua_S,"setPropNumble",lua_PropsNumbleShow_PropsNumbleShow_setPropNumble);
        tolua_function(tolua_S,"create", lua_PropsNumbleShow_PropsNumbleShow_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::PropsNumbleShow).name();
    g_luaType[typeName] = "bs.PropsNumbleShow";
    g_typeCast["PropsNumbleShow"] = "bs.PropsNumbleShow";
    return 1;
}
TOLUA_API int register_all_PropsNumbleShow(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_PropsNumbleShow_PropsNumbleShow(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

