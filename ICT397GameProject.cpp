
#include "Engine.h"

int main(int argc, char* argv[])
{
	//Uncomment to hide console
	//::ShowWindow(::GetConsoleWindow(), SW_HIDE);

	Engine ENG;

	if (ENG.Initalise("./Resources/Scripts/Demo3/startup.lua")){
		ENG.Run();
	}

	return 0;
}

