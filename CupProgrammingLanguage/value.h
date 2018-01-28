#pragma once

#include "any.h"
#include "type.h"

namespace Cup {
	class Value
	{
	public:
		Value();
		Value(Type type, Any value);
		~Value();

		Type getType() const;
		Any getValue() const;
		void setValue(Any value);
	protected:

	private:
		Type m_type;
		Any* m_value;
	};
}
