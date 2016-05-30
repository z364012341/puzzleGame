#include "lua_GameStartButton_auto.hpp"
#include "GameStartButton.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_GameStartButton_GameStartButton_getStartButton(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameStartButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameStartButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameStartButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameStartButton_GameStartButton_getStartButton'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameStartButton_GameStartButton_getStartButton'", nullptr);
            return 0;
        }
        cocos2d::ui::Button* ret = cobj->getStartButton();
        object_to_luaval<cocos2d::ui::Button>(tolua_S, "ccui.Button",(cocos2d::ui::Button*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameStartButton:getStartButton",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameStartButton_GameStartButton_getStartButton'.",&tolua_err);
#endif

    return 0;
}
int lua_GameStartButton_GameStartButton_addButtonClickEventListener(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameStartButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"bs.GameStartButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (bubble_second::GameStartButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_GameStartButton_GameStartButton_addButtonClickEventListener'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::function<void (cocos2d::Ref *)> arg0;

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameStartButton_GameStartButton_addButtonClickEventListener'", nullptr);
            return 0;
        }
        cobj->addButtonClickEventListener(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameStartButton:addButtonClickEventListener",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameStartButton_GameStartButton_addButtonClickEventListener'.",&tolua_err);
#endif

    return 0;
}
int lua_GameStartButton_GameStartButton_createButtonContinueForm(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GameStartButton",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameStartButton_GameStartButton_createButtonContinueForm'", nullptr);
            return 0;
        }
        bubble_second::GameStartButton* ret = bubble_second::GameStartButton::createButtonContinueForm();
        object_to_luaval<bubble_second::GameStartButton>(tolua_S, "bs.GameStartButton",(bubble_second::GameStartButton*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GameStartButton:createButtonContinueForm",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameStartButton_GameStartButton_createButtonContinueForm'.",&tolua_err);
#endif
    return 0;
}
int lua_GameStartButton_GameStartButton_createButtonStartForm(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"bs.GameStartButton",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameStartButton_GameStartButton_createButtonStartForm'", nullptr);
            return 0;
        }
        bubble_second::GameStartButton* ret = bubble_second::GameStartButton::createButtonStartForm();
        object_to_luaval<bubble_second::GameStartButton>(tolua_S, "bs.GameStartButton",(bubble_second::GameStartButton*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "bs.GameStartButton:createButtonStartForm",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_GameStartButton_GameStartButton_createButtonStartForm'.",&tolua_err);
#endif
    return 0;
}
int lua_GameStartButton_GameStartButton_constructor(lua_State* tolua_S)
{
    int argc = 0;
    bubble_second::GameStartButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_GameStartButton_GameStartButton_constructor'", nullptr);
            return 0;
        }
        cobj = new bubble_second::GameStartButton();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"bs.GameStartButton");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "bs.GameStartButton:GameStartButton",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_GameStartButton_GameStartButton_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_GameStartButton_GameStartButton_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameStartButton)");
    return 0;
}

int lua_register_GameStartButton_GameStartButton(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"bs.GameStartButton");
    tolua_cclass(tolua_S,"GameStartButton","bs.GameStartButton","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"GameStartButton");
        tolua_function(tolua_S,"new",lua_GameStartButton_GameStartButton_constructor);
        tolua_function(tolua_S,"getStartButton",lua_GameStartButton_GameStartButton_getStartButton);
        tolua_function(tolua_S,"addButtonClickEventListener",lua_GameStartButton_GameStartButton_addButtonClickEventListener);
        tolua_function(tolua_S,"createButtonContinueForm", lua_GameStartButton_GameStartButton_createButtonContinueForm);
        tolua_function(tolua_S,"createButtonStartForm", lua_GameStartButton_GameStartButton_createButtonStartForm);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(bubble_second::GameStartButton).name();
    g_luaType[typeName] = "bs.GameStartButton";
    g_typeCast["GameStartButton"] = "bs.GameStartButton";
    return 1;
}
TOLUA_API int register_all_GameStartButton(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");

	lua_register_GameStartButton_GameStartButton(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

