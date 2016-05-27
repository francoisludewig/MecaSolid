#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

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

			ostream & operator << (ostream & out, BasisId const& a);
			istream & operator >> (istream & in, BasisId & a);
		}
	}
}

