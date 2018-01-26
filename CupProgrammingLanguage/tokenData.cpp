#include "tokenData.h"

namespace Cup {
	namespace Tokenizer {
		TokenData::TokenData(std::regex pattern, TokenType type) :
			m_pattern(pattern),
			m_type(type)
		{

		}


		TokenData::~TokenData()
		{

		}

		std::regex TokenData::getPattern()
		{
			return m_pattern;
		}
		TokenType TokenData::getType()
		{
			return m_type;
		}
	}
}
