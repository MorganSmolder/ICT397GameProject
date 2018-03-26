#pragma once

#include <string>

class Identifiers
{
public:
	Identifiers();
	Identifiers(std::string type);
	Identifiers(std::string type, std::string name);
	Identifiers(std::string type, std::string name, std::string objectname);

	void setId(int id);
	void setType(std::string type);
	void setName(std::string name);
	void setObjectname(std::string objectname);

	int getId() const;
	std::string getType() const;
	std::string getName() const;
	std::string getObjectname() const;

	bool operator < (const Identifiers & rhs) const;
	bool operator == (const Identifiers & rhs) const;

private:
	int id;
	std::string type;
	std::string name;
	std::string objectname;
};

