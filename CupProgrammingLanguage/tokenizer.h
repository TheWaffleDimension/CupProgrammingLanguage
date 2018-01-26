#pragma once
#pragma once

#include <vector>
#include <regex>
#include <string>
#include <iostream>
#include <algorithm>

#include "strUtils.h"

#include "tokenData.h"
#include "tokenType.h"
#include "token.h"

namespace Cup {
	namespace Tokenizer {
		class Tokenizer
		{
		public:
			Tokenizer(std::string str);
			~Tokenizer();

			Token nextToken();
			bool hasNextToken();
			void pushBack();
		protected:

		private:
			std::vector<TokenData> m_tokenDatas;
			std::string m_str;
			Token m_lastToken;
			bool m_pushBack;
		};
	}
}