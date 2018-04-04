#ifndef KBMGL_h
#define KBMGL_h

#include "GL/glut.h"

class kbmInput
{
void specialFunc(void PressFunc(int key, int x, int y));

void specialUpFunc(void ReleaseFunc(int key, int x, int y));

void kbFunc(void processKeys(unsigned char key, int x, int y));

void mouseFunc(void mouseButton(int button, int state, int x, int y));

void motionFunc(void mouseMove(int x, int y));

void ignoreKeyRepeat(int num);

void timer(unsigned int msec, void updateMotion(int value), int ignore);
};

#endif