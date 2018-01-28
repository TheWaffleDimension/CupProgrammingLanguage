#pragma once

#include <type_traits>
#include <string>
#include "tokenizer.h"
#include "block.h"

namespace Cup {
	namespace Parser {
		template<typename T, typename std::enable_if<std::is_base_of<Block::Block, T>::value>::type* = nullptr>
		class Parser
		{
		public:
			virtual bool shouldParse(std::string line) = 0;

			template<typename B, typename std::enable_if<std::is_base_of<Block::Block, T>::value>::type* = nullptr>
			/* Take the superBlock and the tokenizer for this line and return a block of this parser's type */
			T parse(B superBlock, Tokenizer::Tokenizer tokenizer) {};
		protected:

		private:
			T m_type;
		};
	}
}
