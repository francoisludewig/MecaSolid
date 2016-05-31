#pragma once

#include <iostream>
#include <iomanip>


namespace Luga {
	namespace Meca {
		namespace Utils{

			class BasisId {
			public:
				BasisId();
				~BasisId();
				void Id(int id);
				int Id() const;
			private:
				int id;
			};

			std::ostream & operator << (std::ostream & out, BasisId const& a);
			std::istream & operator >> (std::istream & in, BasisId & a);
		}
	}
}

