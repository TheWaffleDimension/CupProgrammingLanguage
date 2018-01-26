#pragma once

#include <regex>
#include "tokenType.h"

namespace Cup {
	namespace Tokenizer {
		class TokenData
		{
		public:
			TokenData(std::regex pattern, TokenType type);
			~TokenData();

			std::regex getPattern();
			TokenType getType();
		protected:

		private:
			std::regex m_pattern;
			TokenType m_type;
		};
	}
}
