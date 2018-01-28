#pragma once

#include <string>
#include <vector>

#include "type.h"
#include "value.h"
#include "parameter.h"
#include "block.h"

namespace Cup {
	namespace Block {
		class Method : public Block
		{
		public:
			Method(Block* superBlock, std::string name, Type type, std::vector<Parameter> params);
			~Method();

			void run() override;
			void invoke(std::vector<Value> values);
		protected:

		private:
			std::string m_name;
			Type m_type;
			std::vector<Parameter> m_params;
		};
	}
}