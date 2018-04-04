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

class Engine
{
public:
	Engine();
	~Engine();
	bool Initalise(std::string initscript);
	
	void Run();

private:
	SceneManager SM;
	LUAScriptManager* LSM;
	RenderModuleStubb* RNDR;
	AssetManager* AMAN;
	AudioEngine* AE;
	Controls* CONT;

	bool initaliseScriptingInterface();
	bool initaliseRenderer();
	bool initaliseUtilityModules();
	bool initaliseAudioEngine();
	bool initaliseControls();
};

