#pragma once

#include <string>
#include <vector>
#include "any.h"
#include "parser.h"
#include "token.h"
#include "method.h"

namespace Cup {
	namespace Parser {
		class MethodParser : public Parser<Block::Method>
		{
		public:
			/// @override
			bool Parser<Block::Method>::shouldParse(std::string line);

			/// @override
			Block::Method parse(Block::Block* superBlock, Tokenizer::Tokenizer tokenizer);
		};
	}
}
