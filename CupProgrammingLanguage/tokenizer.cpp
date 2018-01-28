#include "tokenizer.h"

namespace Cup {
	namespace Tokenizer {
		Tokenizer::Tokenizer(std::string str) :
			m_lastToken("", TokenType::EMPTY)
		{
			m_tokenDatas.push_back(TokenData(std::regex("^([a-zA-Z_][a-zA-Z0-9_]*)"), TokenType::IDENTIFIER));
			m_tokenDatas.push_back(TokenData(std::regex("^((-)?[0-9]+)"), TokenType::INTEGER_LITERAL));
			m_tokenDatas.push_back(TokenData(std::regex("^([-]?[0-9]*\.?[0-9]+)"), TokenType::FLOAT_LITERAL));
			m_tokenDatas.push_back(TokenData(std::regex("^(\".*\")"), TokenType::STRING_LITERAL));

			std::string tokens[10] = {
				"=",
				"\\(",
				"\\)",
				"\\<",
				"\\>",
				"\\.",
				"\\,"
			};

			for (std::string token : tokens) 
			{
				m_tokenDatas.push_back(TokenData(std::regex("^(" + token + ")"), TokenType::TOKEN));
			}

			std::replace(str.begin(), str.end(), '	', ' ');
			std::replace(str.begin(), str.end(), '\n', ' ');
			m_str = str;
		}


		Tokenizer::~Tokenizer()
		{

		}

		Token Tokenizer::nextToken()
		{
			// Trim any leading whitespace off the front and back of the string.
			trim(m_str);

			// If we should push back to the last token, do so.
			if (m_pushBack)
			{
				m_pushBack = false;
				return m_lastToken;
			}

			// Check is string is empty.
			if (m_str.empty())
			{
				std::cout << "Source string has been emptied!" << std::endl;
				return (m_lastToken = Token("", TokenType::EMPTY));
			}

			std::smatch res;
			for (TokenData data : m_tokenDatas)
			{
				std::regex_search(m_str, res, data.getPattern());

				if (!res.empty())
				{
					std::string token = trim_copy(res[0]);

					m_str = std::regex_replace(m_str, data.getPattern(), "");

					if (data.getType() == TokenType::STRING_LITERAL)
					{
						return (m_lastToken = Token(token.substr(1, token.size() - 2), TokenType::STRING_LITERAL));
					}
					else
					{
						return (m_lastToken = Token(token, data.getType()));
					}
				}
			}


			/// @todo Fix this
			std::cout << "Could not parse " + m_str << std::endl;
			system("PAUSE");
			throw std::exception{ "Error parsing input string" };
		}

		bool Tokenizer::hasNextToken()
		{
			return !m_str.empty();
		}

		void Tokenizer::pushBack()
		{
			if (m_lastToken.getType() != TokenType::EMPTY && m_lastToken.getToken() != "")
			{
				m_pushBack = true;
			}
		}
	}
}