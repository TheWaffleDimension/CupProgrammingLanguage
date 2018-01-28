#include "class.h"



namespace Cup {
	namespace Block {
		Class::Class(std::string name) {
			this->m_name = name;
		}


		Class::~Class()
		{

		}

		void Class::run()
		{
			// Run main method
		}

		std::string Class::getName() {
			return this->m_name;
		}
	}
}