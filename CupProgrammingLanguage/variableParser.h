#pragma once

#include <string>
#include <sstream>
#include "parser.h"
#include "variable.h"
#include "token.h"
#include "any.h"

namespace Cup {
	namespace Parser {
		class VariableParser : public Parser<Block::Block>
		{
		public:
			bool Parser<Block::Block>::shouldParse(std::string line);
			Block::Block* parse(Block::Block* superBlock, Tokenizer::Tokenizer tokenizer);
		};
	}
}
