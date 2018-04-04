#pragma once

#include "glfw-3.2.1\include\GLFW\glfw3.h"

class kbmInput
{
	int getKey(GLFWwindow *window, int key);

	int getMouseButton(GLFWwindow *window, int button);

	void getCursorPos(GLFWwindow *window, double *xpos, double *ypos);

	GLFWkeyfun setCharCallback(GLFWwindow *window, GLFWcharfun keycallback); // See example keyCallback method at bottom

	GLFWmousebuttonfun setMouseButtonCallback(GLFWwindow *window, GLFWmousebuttonfun mousebutton);

/*
	*** EXAMPLE keyCallback Function ***

	void keyCallBack( GLFWwindow* window, int key, int scancode, int action, int mods )
	{
		if( action != GLFW_PRESS ) return;

		switch (k) {
			case GLFW_KEY_Z:
				if( mods & GLFW_MOD_SHIFT )
					view_rotz -= 5.0;
				else
					view_rotz += 5.0;
				break;
			case GLFW_KEY_ESCAPE:
				glfwSetWindowShouldClose(window, GLFW_TRUE);
				break;
			case GLFW_KEY_UP:
				view_rotx += 5.0;
				break;
			case GLFW_KEY_DOWN:
				view_rotx -= 5.0;
				break;
			case GLFW_KEY_LEFT:
				view_roty += 5.0;
				break;
			case GLFW_KEY_RIGHT:
				view_roty -= 5.0;
				break;
			default:
				return;
  }
}
*/
};