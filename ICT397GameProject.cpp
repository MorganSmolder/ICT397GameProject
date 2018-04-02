
#include "Engine.h"

int main(int argc, char* argv[])
{
	Engine ENG;

	if (ENG.Initalise("./Resources/Scripts/Demo3/startup.lua")){
		ENG.Run();
	}

	return 0;
}

