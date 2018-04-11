
#include "Engine.h"

int main(int argc, char* argv[])
{
	//Uncomment to hide console
	//::ShowWindow(::GetConsoleWindow(), SW_HIDE);

	Engine ENG;

	if (ENG.Initalise("./Resources/Scripts/Demo3/startup.lua")){
		ENG.Run();
	}
	else {
		if (DEBUGMODE) std::cerr << "Issue initalising engine. Closing now." << std::endl;
	}

	return 0;
}

