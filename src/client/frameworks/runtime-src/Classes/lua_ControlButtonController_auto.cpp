#include "lua_ControlButtonController_auto.hpp"
#include "ControlButtonController.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"

TOLUA_API int register_all_ControlButtonController(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"bs",0);
	tolua_beginmodule(tolua_S,"bs");


	tolua_endmodule(tolua_S);
	return 1;
}

