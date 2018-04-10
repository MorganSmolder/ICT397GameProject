#pragma once

#include "GLFW\glfw3.h"

class kbmInput
{
	int getKey(GLFWwindow *window, int key);

	int getMouseButton(GLFWwindow *window, int button);

	void getCursorPos(GLFWwindow *window, double *xpos, double *ypos);

	GLFWkeyfun setCharCallback(GLFWwindow *window, GLFWcharfun keycallback);

	GLFWmousebuttonfun setMouseButtonCallback(GLFWwindow *window, GLFWmousebuttonfun mousebutton);

};