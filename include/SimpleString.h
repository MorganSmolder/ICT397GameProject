#pragma once

#include <string>

///Simplified std:::string for use with lua - simplifies binding process by only including essential behaviour

class SimpleString
{
public:
	SimpleString();
	SimpleString(std::string in) : data(in) {};

	bool equals(std::string comparator);

private:	
	std::string data;
};
