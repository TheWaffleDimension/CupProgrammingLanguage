#include <iostream>
#include "tokenizer.h"

using namespace Cup;

int main() {
	std::cout << "Welcome to Cup." << std::endl;

	std::string code = "class HelloWorld\nfunction main(string str)<int>\nprint str\nreturn 0";

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