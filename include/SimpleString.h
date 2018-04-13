#pragma once

#include <string>

/**
* @class simpleString
* @brief Simplified std:::string for use with lua - simplifies binding process by only including essential behaviour.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class SimpleString
{
public:
	SimpleString();
	SimpleString(std::string in) : data(in) {};

	/**
	* @brief The equals method.
	*
	* @param comparator(string) - The string to be compaired.
	*
	* @return bool - If the strings are the same.
	*/
	bool equals(std::string comparator);

	/**
	* @brief Convert the string to a double.
	*
	* @return double - The converted double.
	*/
	double toDouble();

	/**
	* @brief Get the data from the string.
	*
	* @return string - The data.
	*/
	std::string getData();

private:	
	std::string data; /// The data from the string.
};

