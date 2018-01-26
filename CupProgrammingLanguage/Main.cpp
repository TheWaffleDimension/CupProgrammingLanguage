#include <iostream>
#include "tokenizer.h"

using namespace Cup;

int main() {
	std::cout << "Welcome to Cup." << std::endl;

	std::string code = R"(class HelloWorld)" "\n"
					   R"(function main()<>)" "\n"
					   R"(print("Hello World"))";

	Tokenizer::Tokenizer tokenizer(code);

	while (tokenizer.hasNextToken())
	{
		std::cout << "Token: " << tokenizer.nextToken().getToken() << std::endl;
	}

	system("PAUSE");
	return 0;
}