#pragma once
#include <map>
#include <fstream>	
#include <string> 
#include <iostream>

extern "C" {
	#include "lua/lua.h"
	#include "lua/lualib.h"
	#include "lua/lauxlib.h"
}

#include <luabind/luabind.hpp>

#define LUAERROR luabind::error& e
#define LUAERRORMSG e

#define DEBUGMODE true

class LUAScriptManager
{
public:
	LUAScriptManager();
	~LUAScriptManager();

	bool loadScript(std::string file, std::string name);
	bool doScript(std::string name);
	bool doScriptFromFile(std::string name);
	bool initLuaState();
	void closeState();
	std::string getErrorMSG(LUAERROR);
	lua_State* getState();

	template <class T>
	void setGlobal(const T & ng, std::string name) {
		luabind::globals(lstate)[name] = ng;
	}

	inline void callFunction(std::string func) {
		luabind::call_function<void>(lstate, func.c_str());
	};

	template <class T>
	inline void callFunction(std::string func, T & arg) {
		try {
			luabind::call_function<void>(lstate, func.c_str(), boost::ref<T>(arg));
		}
		catch (LUAERROR)
		{
			std::string error = getErrorMSG(LUAERRORMSG);
			if(DEBUGMODE) std::cerr << error << std::endl;
		}
	};

	template <class T, class U>
	inline void callFunction(std::string func, T & arg, U & arg2) {
		try {
			luabind::call_function<void>(lstate, func.c_str(), boost::ref<T>(arg), boost::ref<U>(arg2));
		}
		catch (LUAERROR)
		{
			std::string error = getErrorMSG(LUAERRORMSG);
			if (DEBUGMODE) std::cerr << error << std::endl;
		}
	};

	template <class T, class U, class V>
	inline void callFunction(std::string func, T & arg, U & arg2, V & arg3) {
		try {
			luabind::call_function<void>(lstate, func.c_str(), boost::ref<T>(arg), boost::ref<U>(arg2), boost::ref<V>(arg3));
		}
		catch (LUAERROR)
		{
			std::string error = getErrorMSG(LUAERRORMSG);
			if (DEBUGMODE) std::cerr << error << std::endl;
		}
	};

	template <class T, class U, class V, class W>
	inline void callFunction(std::string func, T & arg, U & arg2, V & arg3, W & arg4) {
		try {
			luabind::call_function<void>(lstate, func.c_str(), boost::ref<T>(arg), boost::ref<U>(arg2), boost::ref<V>(arg3), boost::ref<W>(arg4));
		}
		catch (LUAERROR)
		{
			std::string error = getErrorMSG(LUAERRORMSG);
			if (DEBUGMODE) std::cerr << error << std::endl;
		}
	};

private:
	lua_State* lstate;
	std::map< std::string, std::string> scripts;
};

