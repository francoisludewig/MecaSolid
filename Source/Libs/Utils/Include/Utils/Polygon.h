#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include "Utils/Point.h"

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Point;

			class Polygon {
			public:
				Polygon();
				~Polygon();

			private:
				vector<Point> summit;
			};

			ostream & operator << (ostream & out, Polygon const& a);
			istream & operator >> (istream & in, Polygon & a);
		}
	}
}
