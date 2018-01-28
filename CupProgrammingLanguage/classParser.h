#pragma once

#include <regex>
#include <string>
#include "parser.h"
#include "class.h"

namespace Cup {
	namespace Parser {
		class ClassParser : public Parser<Block::Class>
		{
		public:
			/// @override
			bool Parser<Block::Class>::shouldParse(std::string line);

			/// @override
			Block::Class parse(Block::Block* superBlock, Tokenizer::Tokenizer tokenizer);
		protected:

		private:

		};

	}
}