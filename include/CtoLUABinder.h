#pragma once

#include "SceneManager.h"
//#include "vec3.h"
#include "Maths.h"
#include "LUAScriptManager.h"
#include "NPC.h"
#include "Identifiers.h"
#include "MessagingBus.h"
#include "ResourceList.h"
#include "AssetManager.h"
#include "AudioEngine.h"
#include "SimpleString.h"
#include "StaticEntity.h"
#include "TerrainObject.h"

extern "C" {
	#include "lua/lua.h"
	#include "lua/lualib.h"
	#include "lua/lauxlib.h"
}

#include <luabind/luabind.hpp>

/**
* @class CtoLUABinder
*
* @brief Binds lua to c.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class CtoLUABinder
{
public:
	/**
	* @brief Bind lua.
	*
	* @param lstate(lua_State*) - The state that lua is in.
	*
	* @return NONE.
	*/
	void bindClasses(lua_State* lstate);
};

