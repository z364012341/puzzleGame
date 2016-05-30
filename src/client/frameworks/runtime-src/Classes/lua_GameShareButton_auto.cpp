#include "lua_GameShareButton_auto.hpp"
#include "GameShareButton.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_GameShareButton_GameShareButton_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GameShareButton",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameShareButton_GameShareButton_create'", nullptr);
            return 0;
        }
        bubble_second::GameShareButton* ret = bubble_second::GameShareButton::create();
        object_to_luaval<bubble_second::GameShareButton>(tolua_S, "bs.GameShareButton",(bubble_second::GameShareButton*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GameShareButton:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameShareButton_GameShareButton_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_GameShareButton_GameShareButton_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameShareButton)");
    return 0;
}

int lua_register_GameShareButton_GameShareButton(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.GameShareButton");
    tolua_cclass(tolua_S,"GameShareButton","bs.GameShareButton","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"GameShareButton");
        tolua_function(tolua_S,"create", lua_GameShareButton_GameShareButton_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::GameShareButton).name();
    g_luaType[typeName] = "bs.GameShareButton";
    g_typeCast["GameShareButton"] = "bs.GameShareButton";
    return 1;
}
TOLUA_API int register_all_GameShareButton(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_GameShareButton_GameShareButton(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

