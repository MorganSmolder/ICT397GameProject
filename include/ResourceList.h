#pragma once

#include <map>
#include <string>

class ResourceList
{
	public:
		ResourceList();	
		ResourceList(std::string k1, std::string v1);
		ResourceList(std::string k1, std::string v1, std::string k2, std::string v2);
		ResourceList(std::string k1, std::string v1, std::string k2, std::string v2, std::string k3, std::string v3);
		bool hasResource(std::string key);
		std::string getResource(std::string key);
		bool addResource(std::string k1, std::string v1);

	private:
		std::map<std::string, std::string> resources;
};

