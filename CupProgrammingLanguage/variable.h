#pragma once

#include <string>
#include "value.h"
#include "type.h"
#include "any.h"
#include "block.h"

namespace Cup {
	class Variable
	{
	public:
		Variable::Variable(Block::Block* block, Type type, std::string name, Any* value);
		~Variable();

		Block::Block* getBlock();
		std::string getName();

		Type getType() const;
		Any getValue() const;
		void setValue(Any value);
	protected:

	private:
		Type m_type;
		Any* m_value;
		Block::Block* m_block;
		std::string m_name;
	};
}
