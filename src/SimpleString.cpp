#include "SimpleString.h"

SimpleString::SimpleString()
{
}

bool SimpleString::equals(std::string comparator) {
	return data == comparator;
}
