#include "method.h"


namespace Cup {
	namespace Block {
		Method::Method(Block* superBlock, std::string name, Type type, std::vector<Parameter> params) :
			m_name(name), m_type(type), m_params(params)
		{

		}


		Method::~Method()
		{

		}

		void Method::run()
		{
			invoke(std::vector<Value>());
		}

		// Invoke the method with the supplied values
		void Method::invoke(std::vector<Value> values)
		{

		}
	}
}
