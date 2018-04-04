#pragma once

#include "SceneManager.h"
#include "vec3.h"
#include "LUAScriptManager.h"
#include "NPC.h"
#include "Identifiers.h"
#include "MessagingBus.h"
#include "ResourceList.h"
#include "AssetManager.h"
#include "AudioEngine.h"
#include "SimpleString.h"
#include "StaticEntity.h"

extern "C" {
	#include "lua/lua.h"
	#include "lua/lualib.h"
	#include "lua/lauxlib.h"
}

#include <luabind/luabind.hpp>


class CtoLUABinder
{
public:
	void bindClasses(lua_State* lstate);
};

