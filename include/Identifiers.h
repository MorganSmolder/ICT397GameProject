#pragma once

#include <string>

/**
* @class Indetifiers
*
* @brief Identifier class for game objects
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class Identifiers
{
public:
	Identifiers();
	Identifiers(std::string type);
	Identifiers(std::string type, std::string name);
	Identifiers(std::string type, std::string name, std::string objectname);

	/**
	* @brief Setter for id.
	*
	* @param id(int) - New id.
	*
	* @return NONE.
	*/
	void setId(int id);

	/**
	* @brief Setter for type.
	*
	* @param type(string) - THe type of game object.
	*
	* @return NONE.
	*/
	void setType(std::string type);

	/**
	* @brief Setter for name of identifier.
	*
	* @param name(string) - The new name of the identigier.
	*
	* @return NONE.
	*/
	void setName(std::string name);

	/**
	* @brief Setter for the object name.
	*
	* @param objectname(string) - The new object name.
	*
	* @return NONE.
	*/
	void setObjectname(std::string objectname);

	int getId() const; /// Game object id.
	std::string getType() const; /// Game object type.
	std::string getName() const; /// Identifier name.
	std::string getObjectname() const; /// Game object name.

	/**
	* @brief Overload function for the < operator with another Identifier.
	*
	* @oaram rhs(Identifier &) - The identifier object being compaired.
	*
	* @return bool - Result of the compairson.
	*/
	bool operator < (const Identifiers & rhs) const;

	/**
	* @brief Overload function for the == operator with another identifier.
	*
	* @param rhs(Identifiers &) - The identifier being compaired.
	*
	* @return bool - Result of the comparison.
	*/
	bool operator == (const Identifiers & rhs) const;

private:
	int id; /// identifier id.
	std::string type; /// Identifier type.
	std::string name; /// Identifier name.
	std::string objectname; /// Objects name.
};

