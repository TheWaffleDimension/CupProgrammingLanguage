#include "methodParser.h"


namespace Cup {
	namespace Parser {
		bool MethodParser::Parser<Block::Method>::shouldParse(std::string line)
		{
			std::smatch res;
			std::regex_search(line, res, std::regex("function [a-zA-Z_][a-zA-Z0-9_]*\\(([a-zA-Z_][a-zA-Z0-9_]* [a-zA-Z_][a-zA-Z0-9_]*)*\\)<([a-zA-Z_][a-zA-Z0-9_]* [a-zA-Z_][a-zA-Z0-9_]*)*>"));
			return (res.size() == 1);
		}

		Block::Method MethodParser::parse(Block::Block* superBlock, Tokenizer::Tokenizer tokenizer)
		{
			tokenizer.nextToken(); // Skip the method token
			std::string name = tokenizer.nextToken().getToken(); // Get the name token
			tokenizer.nextToken(); // Skip the ( token

			Tokenizer::Token first = tokenizer.nextToken();
			std::vector<Parameter> params;

			typeMap tm;

			if (!(first.getToken() == ")"))
			{
				std::vector<std::string> paramData;
				paramData.push_back(first.getToken());
				paramData.push_back("");

				while (tokenizer.hasNextToken())
				{
					Tokenizer::Token token = tokenizer.nextToken();

					if (token.getToken() == ")")
						break;

					if (paramData[0] == "") {
						paramData[0] = token.getToken();
					}
					else {
						paramData[1] = token.getToken();

						for (auto & c : paramData[0]) c = toupper((unsigned char)c);
						Type t = tm[paramData[0]];
						params.push_back(Parameter(t, paramData[1]));

						paramData = std::vector<std::string>();
					}
				}
			}

			tokenizer.nextToken(); // Skip first <
			std::string returnToken = tokenizer.nextToken().getToken();
			for (auto & c : returnToken) c = toupper((unsigned char)c);
			Type returnType = tm[returnToken];

			return Block::Method(superBlock, name, returnType, params);
		}
	}
}