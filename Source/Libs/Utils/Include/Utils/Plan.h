#pragma once

#include <iostream>
#include <iomanip>
#include "Basis.h"

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Plan {
			public:
				Plan();
				Plan(Point p, Vector3D n);
				~Plan();
				Basis B() const;
				Vector3D Normal() const;
				Point Origin() const;

				void B(Basis b);
				void Normal(Vector3D n);
				void Origin(Point p);
			private:
				Basis b;
			};

			ostream & operator << (ostream & out, Plan const& a);
			istream & operator >> (istream & in, Plan & a);
		}
	}
}
