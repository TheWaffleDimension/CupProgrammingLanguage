#pragma once

#include <vector>
#include <string>
#include "variable.h"
#include "any.h"

namespace Cup {
	class Variable;
	namespace Block {
		/* Represents a block of code */
		class Block
		{
		public:
			Block();
			Block(Block* superBlock);
			virtual ~Block();

			virtual void run() = 0;

			void addBlock(Block* block)
			{
				m_subBlocks.push_back(block);
			};

			Block* getSuperBlock() {
				return m_superBlock;
			}

			void addVariable(Variable variable)
			{
				m_variables.push_back(variable);
			};

			Variable getVariable(std::string name)
			{
				// Check the super blocks first.

				for (Variable v : m_variables) {
					if (v.getName() == name)
						return v;
				}

				return Variable{};
			}
		protected:

		private:
			Block* m_superBlock;
			std::vector<Block*> m_subBlocks;
			std::vector<Variable> m_variables;
		};
	}
}
