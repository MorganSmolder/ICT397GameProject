#pragma once

#include "SceneManager.h"
#include "LUAScriptManager.h"
#include "Singleton.h"
#include "CtoLUABinder.h"
#include "RenderModuleStubb.h"
#include "AssetManager.h"
#include "AudioEngine.h"
#include "windows.h"
#include "Controls.h"

/**
* @class Engine
*
* @brief Core engine that calls other engines and creates their objects.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class Engine
{
public:
	Engine();
	~Engine();

	/**
	* @brief initalise the engine.
	*
	* @param initscript(string) - The script to setup the engine.
	*
	* @return bool - If the script was run.
	*/
	bool Initalise(std::string initscript);
	
	/** 
	* @brief Run the engine.
	*
	* @return NONE.
	*/
	void Run();

private:
	SceneManager SM; /// Scene manager object.
	LUAScriptManager* LSM; /// Lua script manager.
	RenderModuleStubb* RNDR; /// Render stubb object.
	AssetManager* AMAN; /// Asset manager.
	AudioEngine* AE; /// Audio engine.
	Controls* CONT; /// Control groups.

	bool initaliseScriptingInterface(); /// Flag for interface scripts
	bool initaliseRenderer(); /// Flag for the render.
	bool initaliseUtilityModules(); /// Flag for the utility modules.
	bool initaliseAudioEngine(); /// Flag for the audio.
	bool initaliseControls(); /// Flag for control groups.
};

