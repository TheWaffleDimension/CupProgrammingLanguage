#include <iostream>
#include "tokenizer.h"

using namespace Cup;

int main() {
	std::cout << "Welcome to Cup." << std::endl;

	std::string code = "class HelloWorld\nfunction main()<>\nprint(\"Hello World\")";

	Tokenizer::Tokenizer tokenizer(code);

	while (tokenizer.hasNextToken())
	{
		try {
			std::cout << "Token: " << tokenizer.nextToken().getToken() << std::endl;
		}
		catch (const std::exception &ex) {
			std::cout << ex.what() << std::endl;
			break;
		}
	}

	system("PAUSE");
	return 0;
}