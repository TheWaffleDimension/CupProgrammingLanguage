#include "parameter.h"


namespace Cup {
	Parameter::Parameter(Type type, std::string name)
	{
		m_type = type;
		m_name = name;
	}


	Parameter::~Parameter()
	{
	}

	std::string Parameter::getName()
	{
		return m_name;
	}

	Type Parameter::getType()
	{
		return m_type;
	}
}
