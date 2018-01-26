#pragma once

#include <string>
#include "tokenType.h"

namespace Cup {
	namespace Tokenizer {
		class Token
		{
		public:
			Token(std::string token, TokenType type);
			~Token();

			std::string getToken();
			TokenType getType();
		protected:

		private:
			std::string m_token;
			TokenType m_type;
		};

	}
}
