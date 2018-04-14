#pragma once

#include "Identifiers.h"

#define FDATA 'F'
#define CDATA 'C'
#define IDATA 'I'
#define SDATA 'S'
#define VDATA 'V'

#include <string>
#include "vec3.h"

struct Data{
public:
	float fdata;
	char cdata;
	int idata;
	std::string sdata;
	vec3 vdata;
};

class Message
{
public:
	Message();
	Message(std::string instruction);

	void setInstruction(std::string instruuction);
	std::string getInstruction();

	Identifiers & getFrom();
	void setFrom(Identifiers & nid);

	void setfData(float data);
	void setData(char data);
	void setData(int data);
	void setData(std::string data);
	void setData(const vec3 & data);

	Data & getData();

	char getDType();

private:
	char dtype;
	std::string instruction;
	Data mdata;
	Identifiers from;

};

