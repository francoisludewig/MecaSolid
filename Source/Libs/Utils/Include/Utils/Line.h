#pragma once

#include <iostream>
#include <iomanip>
#include "../Include/Utils/Point.h"
#include "../Include/Utils/Vector3D.h"
using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Line {
			public:
				Line();
				Line(Point a, Vector3D u);
				~Line();
				Point GetPoint() const;
				Vector3D GetVector() const;
				void SetPoint(Point a);
				void SetVector(Vector3D b);

			private:
				Point a;
				Vector3D u;
			};

			ostream & operator << (ostream & out, Line const& a);
			istream & operator >> (istream & in, Line & a);
		}
	}
}
