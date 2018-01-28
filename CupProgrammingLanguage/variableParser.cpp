#include "variableParser.h"


namespace Cup {
	namespace Parser {
		bool VariableParser::Parser<Block::Block>::shouldParse(std::string line)
		{
			std::smatch res;
			std::regex_search(line, res, std::regex("var [a-zA-Z_][a-zA-Z0-9_]* [a-zA-Z_][a-zA-Z0-9_] = \"?[a-zA-Z_][a-zA-Z0-9_]*\"?"));
			return (res.size() == 1);
		}

		Block::Block* VariableParser::parse(Block::Block* superBlock, Tokenizer::Tokenizer tokenizer)
		{
			tokenizer.nextToken(); // Skip var token
			
			// Get the type
			Type type;
			typeMap tm;
			std::string token = tokenizer.nextToken().getToken();
			for (auto & c : token) c = toupper((unsigned char)c);
			type = tm[token];

			// Get the name.
			std::string name = tokenizer.nextToken().getToken();

			// Skip = token.
			tokenizer.nextToken();

			// Get the value
			Tokenizer::Token v = tokenizer.nextToken();
			Any value;


			if (v.getType() == Tokenizer::TokenType::INTEGER_LITERAL) {
				int val = 0;
				std::stringstream( v.getToken() ) >> val;
				value = val;
			}
			else if (v.getType() == Tokenizer::TokenType::FLOAT_LITERAL) {
				float val = 0;
				std::stringstream(v.getToken()) >> val;
				value = val;
			}
			else if (v.getType() == Tokenizer::TokenType::STRING_LITERAL) {
				value = v.getToken();
			}
			else {
				Variable var = superBlock->getVariable(v.getToken());
				value = var.getValue();
			}

			// Add this variable to the block.
			superBlock->addVariable(Variable(superBlock, type, name, value));
			return nullptr;
		}
	}
}