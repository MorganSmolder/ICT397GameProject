#pragma once

#include <map>
#include "ResourceList.h"
#include "RenderModuleStubb.h"
#include "LUAScriptManager.h"
#include "SimpleString.h"

class Controls
{
	public:
		Controls();
		~Controls();

		void addControlGroup(unsigned controlgroup);

		void addInitalisedControlGroup(unsigned controlgroup, ResourceList & data);

		bool bindControls(unsigned group, ResourceList & toset);
	
		static bool changeControlGroup(unsigned groupno, RenderModuleStubb* render, Controls* tochange);

	private:
		std::map<int, ResourceList> controls;
		unsigned curgroup;

		static double prevx;
		static double prevy;

		static void bindControls(unsigned groupno, RenderModuleStubb* render, Controls* tochange);
		static void unbindControls(unsigned groupno, RenderModuleStubb* render, Controls* tochange);
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouseCallback(GLFWwindow* window, double x, double y);
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
};