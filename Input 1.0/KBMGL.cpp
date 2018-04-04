#include "KBMGL.h"

void kbmInput::specialFunc(void PressFunc(int key, int x, int y))
{
	glutSpecialFunc(PressFunc);
}

void kbmInput::specialUpFunc(void ReleaseFunc(int key, int x, int y))
{
	glutSpecialUpFunc(ReleaseFunc);
}

void kbmInput::kbFunc(void processKeys(unsigned char key, int x, int y))
{
	glutKeyboardFunc(processKeys);
}

void kbmInput::mouseFunc(void mouseButton(int button, int state, int x, int y))
{
	glutMouseFunc(mouseButton);
}

void kbmInput::motionFunc(void mouseMove(int x, int y))
{
	glutMotionFunc(mouseMove);
}

void kbmInput::ignoreKeyRepeat(int num)
{
	glutIgnoreKeyRepeat(num);
}

void kbmInput::timer(unsigned int msec, void updateMovement(int value), int ignore)
{
	glutTimerFunc(msec, updateMovement, ignore);
}