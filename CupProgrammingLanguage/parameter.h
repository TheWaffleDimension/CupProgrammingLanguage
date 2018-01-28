#pragma once

#include <string>
#include "type.h"

namespace Cup {
	class Parameter
	{
	public:
		Parameter(Type type, std::string name);
		~Parameter();

		std::string getName();
		Type getType();
	protected:

	private:
		Type m_type;
		std::string m_name;
	};
}
