#pragma once

#include "SceneManager.h"
#include "LUAScriptManager.h"
#include "Singleton.h"
#include "CtoLUABinder.h"
#include "RenderModuleStubb.h"
#include "AssetManager.h"
#include "AudioEngine.h"

class Engine
{
public:
	Engine();
	~Engine();
	bool Initalise(std::string initscript);
	
	//Temporarily static ahile mat does rendering
	static void Run();
	
	//tmp while mat does rendering
	static Engine* self;

private:
	SceneManager SM;
	LUAScriptManager* LSM;
	RenderModuleStubb* RNDR;
	AssetManager* AMAN;
	AudioEngine* AE;

	bool initaliseScriptingInterface();
	bool initaliseRenderer();
	bool initaliseUtilityModules();
	bool initaliseAudioEngine();
};

