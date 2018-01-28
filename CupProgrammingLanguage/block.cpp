#include "block.h"

namespace Cup {
	namespace Block {
		Block::Block()
		{
			m_superBlock = nullptr;
		}

		Block::Block(Block* superBlock)
		{
			m_superBlock = superBlock;
		}


		Block::~Block()
		{

		}
	}
}
