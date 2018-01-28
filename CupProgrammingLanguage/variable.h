#pragma once

#include <string>
#include "value.h"
#include "type.h"
#include "any.h"
#include "block.h"

namespace Cup {
	class Variable : Value
	{
	public:
		Variable::Variable(Block::Block* block, Type type, std::string name, Any* value);
		~Variable();

		Block::Block* getBlock();
		std::string getName();
	protected:

	private:
		Block::Block* m_block;
		std::string m_name;
	};
}
