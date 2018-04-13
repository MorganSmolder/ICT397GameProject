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

/**
* @class LUAScriptManager
*
* @brief Lua script manager
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class LUAScriptManager
{
public:
	LUAScriptManager();
	~LUAScriptManager();

	/**
	* @brief Load the script.
	*
	* @param file(string) - The file path.
	* @param name(string) - The file name.
	*
	* @return bool - If the script loaded.
	*/
	bool loadScript(std::string file, std::string name);

	/**
	* @brief Execute the script.
	*
	* @param name(string) - The script name.
	*
	* @return bool - If the script ran.
	*/
	bool doScript(std::string name);

	/**
	* @brief Call a script from a file.
	*
	* @param name(string) - Script name.
	*
	* @return bool - If the script ran.
	*/
	bool doScriptFromFile(std::string name);

	/**
	* @brief Setup for lua state.
	*
	* @return bool - If the setup was successful.
	*/
	bool initLuaState();

	/**
	* @brief CLose the state.
	*
	* @return NONE.
	*/
	void closeState();

	/**
	* @brief Get the type of error message.
	*
	* @param LUAERROR - The type of error.
	*
	* @return string - The error message.
	*/
	std::string getErrorMSG(LUAERROR);

	/**
	* @brief Get the state of the script.
	*
	* @return lua_state* - The pointer to the state type.
	*/
	lua_State* getState();

	/**
	* @brief Set the global.
	*
	* @param ng(const T & ng) - The new global.
	* @param name(string) - The name of the script.
	*
	* @return NONE.
	*/
	template <class T>
	void setGlobal(const T & ng, std::string name) {
		luabind::globals(lstate)[name] = ng;
	}

	/**
	* @brief Overload for the call function.
	*
	* @param func(string) - The name of the function.
	*
	* @return NONE.
	*/
	inline void callFunction(std::string func) {
		luabind::call_function<void>(lstate, func.c_str());
	};

	/**
	* @brief Overload for the call function.
	*
	* @param func(string) - The name of the function.
	* @param arg(T &) - The arguement to be passed as a parameter.
	*/
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

	/**
	* @brief Overload for the call function.
	*
	* @param func(string) - The name of the function.
	* @param arg(T &) - The first arguement.
	* @param arg2(U &) - The second arguement
	*
	* @return NONE.
	*/
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

	/**
	* @brief Overload for the call function.
	*
	* @param func(string) - The name of the function.
	* @param arg(T &) - The first arguement.
	* @param arg2(U &) - The second arguement
	* @param arg3(V &) - The third arguement.
	*
	* @return NONE.
	*/
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

	/**
	* @brief Overload for the call function.
	*
	* @param func(string) - The name of the function.
	* @param arg(T &) - The first arguement.
	* @param arg2(U &) - The second arguement
	* @param arg3(V &) - The third arguement.
	* @param arg4(W &) - The fourth arguement.
	*
	* @return NONE.
	*/
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
	lua_State* lstate; /// Pointer to the lua state.
	std::map< std::string, std::string> scripts; /// A map of the scripts.
};

