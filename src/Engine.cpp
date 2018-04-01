#include "Engine.h"

//temporary
Engine* Engine::self = NULL;
	
Engine::Engine() 
{
	LSM = NULL;
	RNDR = NULL;
	AMAN = NULL;
	AE = NULL;
}

Engine::~Engine()
{ 
	if (LSM != NULL) delete LSM;
	LSM = NULL;
	
	if (RNDR != NULL) delete RNDR;
	RNDR = NULL;

	if (AMAN != NULL) delete AMAN;
	AMAN = NULL;

	if (AE != NULL) delete AE;
	AE = NULL;
}

bool Engine::Initalise(std::string initscript){
	if (!initaliseScriptingInterface()) return false;
	if (!initaliseRenderer()) return false;
	if (!initaliseUtilityModules()) return false;
	if (!initaliseAudioEngine()) return false;

	if(!LSM->doScriptFromFile(initscript)) return false;

	LSM->callFunction<SceneManager, LUAScriptManager, AssetManager, AudioEngine>("initGame", SM, *LSM, *AMAN, *AE);

	return true;
}

//Temporarily gimped while mat does rendering
void Engine::Run() {
	float count = 0;
	while (count < 1000000) {
		self->RNDR->startRenderCycle();


		self->SM.update((float)count++);

		self->SM.render();

		self->AE->update();
		
		self->RNDR->endRenderCycle();
	}
}

bool Engine::initaliseScriptingInterface() {
	LSM = Singleton<LUAScriptManager>::getInstance();
	if (!LSM->initLuaState()) return false;
	CtoLUABinder().bindClasses(LSM->getState());

	return true;
}

bool Engine::initaliseRenderer() {
	RNDR = Singleton<RenderModuleStubb>::getInstance();
	if (RNDR == NULL) return false;

	//BAD!!!! temporary while mat does rendering
	RNDR->init(0, NULL);
	RNDR->setKeyCallback();

	return true;
}

bool Engine::initaliseUtilityModules() {
	AMAN = Singleton<AssetManager>::getInstance();
	if (AMAN == NULL) return false;

	return true;
}

bool Engine::initaliseAudioEngine() {
	AE = Singleton<AudioEngine>::getInstance();
	if (AE == NULL) return false;

	AE->initalise();
	
	return true;
}