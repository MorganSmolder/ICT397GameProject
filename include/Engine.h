#pragma once

#include "SceneManager.h"
#include "LUAScriptManager.h"
#include "Singleton.h"
#include "CtoLUABinder.h"
#include "Windows.h"
#include "RenderModuleStubb.h"
#include "AssetManager.h"
#include "AudioEngine.h"

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

	bool initaliseScriptingInterface();
	bool initaliseRenderer();
	bool initaliseUtilityModules();
	bool initaliseAudioEngine();
};

