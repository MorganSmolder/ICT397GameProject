
#include "Engine.h"

int main(int argc, char* argv[])
{
	Engine ENG;

	ENG.self = &ENG;

	if (ENG.Initalise("./Resources/Scripts/Demo3/startup.lua")){
		//Temporarily switched rendering mechanism to glut callback while mat sorts out glfw.
		//ENG.Run();
	}

	return 0;
}

