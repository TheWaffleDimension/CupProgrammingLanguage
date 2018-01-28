#pragma once

#include <string>

#include "block.h"

namespace Cup {
	namespace Block {
		class Class : public Block
		{
		public:
			Class(std::string name);
			~Class();

			void run() override;

			std::string getName();
		protected:

		private:
			std::string m_name;
		};
	}
}

