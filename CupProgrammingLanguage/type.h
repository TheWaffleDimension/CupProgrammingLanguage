#pragma once

#include <string>
#include <map>

namespace Cup {
	enum Type {
		STRING, INTEGER, FLOAT
	};

	// String switch paridgam   
	struct typeMap : public std::map<std::string, Type>
	{
		typeMap()
		{
			this->operator[]("STRING") = STRING;
			this->operator[]("INTEGER") = INTEGER;
			this->operator[]("FLOAT") = FLOAT;
		};
		~typeMap() {}
	};
}