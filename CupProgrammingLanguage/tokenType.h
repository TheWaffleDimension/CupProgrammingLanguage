#pragma once

namespace Cup {
	namespace Tokenizer {
		enum TokenType {
			/* Absolutely nothing */
			EMPTY,

			/* A token. For example: ( ) = , */
			TOKEN,

			/* First character is a letter or underscore, any proceeding characters are alphanumeric or underscore characters. */
			IDENTIFIER,

			/* An int. 1, 2, 3 */
			INTEGER_LITERAL,

			/* A float. 3.14, 4.5, 6.2 */
			FLOAT_LITERAL,

			/* Anything surrounded by double quotes. "Hello World", "1" */
			STRING_LITERAL
		};
	}
}