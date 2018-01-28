#include "variable.h"


namespace Cup {
	Variable::Variable(Block::Block* block, Type type, std::string name, Any* value)
	{
		m_block = block;
		m_name = name;
	}

	Variable::~Variable()
	{

	}

	Block::Block* Variable::getBlock()
	{
		return m_block;
	}

	std::string Variable::getName()
	{
		return m_name;
	}
}
