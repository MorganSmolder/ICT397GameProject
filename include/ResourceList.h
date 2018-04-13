#pragma once

#include <map>
#include <string>

/**
* @class ResourceList
*
* @brief The resource list.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class ResourceList
{
	public:
		ResourceList();	
		ResourceList(std::string k1, std::string v1);
		ResourceList(std::string k1, std::string v1, std::string k2, std::string v2);

		/**
		* @brief If the key has resources.
		*
		* @param key(string) - The data being checked.
		*
		* @return bool - If the key has resources.
		*/
		bool hasResource(std::string key);

		/**
		* @brief Get the resources.
		*
		* @param key(string) - The data being checked.
		*
		* @return string - The resources.
		*/
		std::string getResource(std::string key);

		/**
		* @brief Add the resources.
		*
		* @param k1(string) - The first resource.
		* @param k2(string) - The second resource.
		*
		* @return bool - If the resource was added successfully.
		*/
		bool addResource(std::string k1, std::string v1);

	private:
		std::map<std::string, std::string> resources; /// The resources
};

