#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include "Utils/Point.h"
#include "Utils/Basis.h"

#include "BasisId.h"

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Point;

			class Polygon : public BasisId {
			public:
				Polygon();
				Polygon(Basis & b, vector<Point> & p);
				~Polygon();

			private:
				vector<Point> localSummit;
				vector<Point> GlobalSummit;
				Basis b;

				void UpdateGlobalSummit();
			};

			ostream & operator << (ostream & out, Polygon const& a);
			istream & operator >> (istream & in, Polygon & a);
		}
	}
}
