#pragma once

#include <iostream>
#include <iomanip>

#include "BasisId.h"

#include "../Include/Utils/Point.h"
#include "../Include/Utils/Vector3D.h"
using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Line : public BasisId {
			public:
				Line();
				Line(Point a, Vector3D u);
				~Line();
				Point Origin() const;
				Vector3D Direction() const;
				void Origin(Point a);
				void Direction(Vector3D b);

			private:
				Point origin;
				Vector3D direction;
			};

			ostream & operator << (ostream & out, Line const& a);
			istream & operator >> (istream & in, Line & a);
		}
	}
}
