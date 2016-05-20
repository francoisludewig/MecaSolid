#include <Utils/Segment.h>
#include "../../Utils/Include/Utils/Polygon.h"

#include <iostream>
#include <cmath>

#define precision 1E-15

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			Polygon::Polygon(){
			}

			Polygon::~Polygon(){
			}



			ostream & operator << (ostream & out, Polygon const& a){
				out << scientific << setprecision(15);
				return out;
			}

			istream & operator >> (istream & in, Polygon & a){
				return in;
			}

		}
	}
}
