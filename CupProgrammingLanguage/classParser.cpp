#include "classParser.h"


namespace Cup {
	namespace Parser {
		bool ClassParser::Parser<Block::Class>::shouldParse(std::string line)
		{
			std::smatch res;
			std::regex_search(line, res, std::regex("([a-zA-Z_][a-zA-Z0-9_]*)"));
			return (res.size() == 1);
		}


		Block::Class ClassParser::parse(Block::Block* superBlock, Tokenizer::Tokenizer tokenizer)
		{
			tokenizer.nextToken(); // Skip the class token.

			std::string name = tokenizer.nextToken().getToken();
			return Block::Class(name);
		}

	}
}