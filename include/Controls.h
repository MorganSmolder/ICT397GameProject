#pragma once

#include <map>
#include "ResourceList.h"
#include "RenderModuleStubb.h"
#include "LUAScriptManager.h"
#include "SimpleString.h"

/**
* @class Controls
*
* @brief Controls for game resources.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class Controls
{
	public:
		Controls();
		~Controls();

		/**
		* @brief Add a empty control group.
		*
		* @param controlgroup(unsigned) - New empty control group.
		*
		* @return NONE.
		*/
		void addControlGroup(unsigned controlgroup);

		/**
		* @brief Add a control group.
		*
		* @param controlgroup(unsigned) - A new control group.
		* @param data(ResourceList &) - The data for the new control group.
		*
		* @return NONE.
		*/
		void addInitalisedControlGroup(unsigned controlgroup, ResourceList & data);

		/**
		* @brief Bind a control group to data.
		*
		* @param group(unsigned) - The control group.
		* @param toset(ResourceList &) - The resources to be bound.
		*
		* @return bool - If the bind occured.
		*/
		bool bindControls(unsigned group, ResourceList & toset);
	
		/**
		* @brief Change the control group of some data.
		*
		* @param groupno(unsigned) - New control group.
		* @param render(RenderModuleStubb*) - The current rendering object.
		* @param tochange(Controls*) - The control group getting changed.
		*
		* @param bool - If the change occured.
		*/
		static bool changeControlGroup(unsigned groupno, RenderModuleStubb* render, Controls* tochange);

	private:
		std::map<int, ResourceList> controls; /// A map containing the ID and resources for each control group.
		unsigned curgroup; /// The current group.

		static double prevx; /// Previous x value.
		static double prevy; /// Previous y value.

		/**
		* @brief Bind controls to control group.
		*
		* @param groupno(unsigned) - The control group.
		* @param render(RenderModuleStubb*) - The current render object.
		* @param tochange(Controls*) - The control object to be bound.
		*
		* @ return NONE.
		*/
		static void bindControls(unsigned groupno, RenderModuleStubb* render, Controls* tochange);

		/**
		* @brief Unbind controls of a control group.
		*
		* @param groupno(unsigned) - The control group.
		* @param render(RenderModuleStubb*) - The current render object.
		* @param tochange(Controls*) - The control object to be unbound.
		*
		* @ return NONE.
		*/
		static void unbindControls(unsigned groupno, RenderModuleStubb* render, Controls* tochange);

		/**
		* @brief Keyboard input function.
		*
		* @param window(GLFWwindow*) - The window being called.
		* @param key(int) - The key being hit.
		* @param scancode(int) - The scan code.
		* @param action(int) - What should happen.
		* @param mods(int) - Any special actions.
		*
		* @ return NONE.
		*/
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

		/**
		* @brief Mouse input function.
		*
		* @param window(GLFWwindow*) - The window being called.
		* @param x(double) - The x coord for the mouse.
		* @param y(double) - The y coord for the mouse.
		*
		* @return NONE.
		*/
		static void mouseCallback(GLFWwindow* window, double x, double y);

		/**
		* @brief Mouse button input.
		* 
		* @param window(GLFWwindow*) - The window being called.
		* @param button(int) - What mouse button is being hit.
		* @param action(int) - The action that should happen.
		* @param mods(int) - Any special actions that should occur.
		*/
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
};