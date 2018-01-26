#include "token.h"

namespace Cup {
	namespace Tokenizer {

		Token::Token(std::string token, TokenType type) :
			m_token(token),
			m_type(type)
		{

		}


		Token::~Token()
		{

		}

		std::string Token::getToken()
		{
			return m_token;
		}

		TokenType Token::getType()
		{
			return m_type;
		}

} }