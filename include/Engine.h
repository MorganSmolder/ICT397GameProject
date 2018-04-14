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
* @brief Class for handling all other engines and creating their objects
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
	* @brief Initalise the engine.
	*
	* @param initscript - The script to being called to initalise the engine.
	*
	* @return bool - If the engine was initilised.
	*/
	bool Initalise(std::string initscript);
<<<<<<< HEAD
	
=======

	/**
	* @brief The run funtion.
	*/
>>>>>>> origin/particles
	void Run();

private:
	/// Scene manager object.
	SceneManager SM;
	/// Lua script manager.
	LUAScriptManager* LSM;
	/// Renderer.
	RenderModuleStubb* RNDR;
	/// Assest manager object.
	AssetManager* AMAN;
	/// Audio manager object.
	AudioEngine* AE;
<<<<<<< HEAD
=======
	/// Controller object.
>>>>>>> origin/particles
	Controls* CONT;

	/**
	* @brief Initalise the scripting interface.
	*
	* @return bool - If it was initalised.
	*/
	bool initaliseScriptingInterface();

	/**
	* @brief Initalise the renderer.
	*
	* @return bool - If it was initalised.
	*/
	bool initaliseRenderer();

	/**
	* @brief Initalise the utility modules.
	*
	* @return bool - If it was initalised.
	*/
	bool initaliseUtilityModules();

	/**
	* @brief Initalise the audio engine.
	*
	* @return bool - If it was initalised.
	*/
	bool initaliseAudioEngine();
<<<<<<< HEAD
=======

	/**
	* @brief Initalise the controls.
	*
	* @return bool - If it was initalised.
	*/
>>>>>>> origin/particles
	bool initaliseControls();
};

