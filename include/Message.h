#pragma once

#include "Identifiers.h"

#define FDATA 'F'
#define CDATA 'C'
#define IDATA 'I'
#define SDATA 'S'
#define VDATA 'V'

#include <string>
//#include "vec3.h"
#include "Maths.h"

/**
* @struct Data
*
* @brief The data container
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
struct Data{
public:
	float fdata;
	char cdata;
	int idata;
	std::string sdata;
	vec3 vdata;
};

/**
* @class LUAScriptManager
*
* @brief Lua script manager
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class Message
{
public:
	Message();
	Message(std::string instruction);

	/**
	* @brief Set the instructs for the message.
	*
	* @param instruuction(string) - The instructions.
	*
	* @return NONE.
	*/
	void setInstruction(std::string instruuction);

	/**
	* @brief Get the instruction for the message.
	*
	* @return string - The instructions.
	*/
	std::string getInstruction();

	/**
	* @brief Get where the message is from.
	*
	* @return Identifiers & - Where the message is from.
	*/
	Identifiers & getFrom();

	/**
	* @brief Set where the message is from.
	*
	* @param nid(Identifiers) - Where the message is from.
	*
	* @return NONE.
	*/
	void setFrom(Identifiers & nid);

	/**
	* @brief Set the float data.
	*
	* @param data(float)
	*
	* @return NONE.
	*/
	void setfData(float data);

	/**
	* @brief Set the char data.
	*
	* @param data(char)
	*
	* @return NONE.
	*/
	void setData(char data);

	/**
	* @brief Set the int data.
	*
	* @param data(int)
	*
	* @return NONE.
	*/
	void setData(int data);

	/**
	* @brief Set the string data.
	*
	* @param data(string)
	*
	* @return NONE.
	*/
	void setData(std::string data);

	/**
	* @brief Set the vec3 data.
	*
	* @param data(vec3)
	*
	* @return NONE.
	*/
	void setData(const vec3 & data);

	/*
	* @brief Get the data from the message
	*
	* @return Data & - The data.
	*/
	Data & getData();

	/**
	* @brief Get the data type.
	*
	* @return char - The type of data.
	*/
	char getDType();

private:
	char dtype; /// The data type.
	std::string instruction; /// The instructions.
	Data mdata; /// The message data.
	Identifiers from; /// Where the message is from.

};

