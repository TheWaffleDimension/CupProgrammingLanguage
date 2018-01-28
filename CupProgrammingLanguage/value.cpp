#include "value.h"


namespace Cup {
	Value::Value()
	{

	}

	Value::Value(Type type, Any value)
	{
		m_type = type;
		m_value = value;
	}


	Value::~Value()
	{
	}

	Type Value::getType() const
	{
		return m_type;
	}

	Any Value::getValue() const
	{
		return m_value;
	}

	void Value::setValue(Any value) {
		m_value = value;
	}
}
