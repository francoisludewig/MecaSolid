#pragma once

#include <iostream>
#include <iomanip>
#include "Basis.h"

#include "BasisId.h"

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Plan : public BasisId {
			public:
				Plan();
				Plan(Point p, Vector3D n);
				~Plan();
				Basis Position() const;
				Vector3D Normal() const;
				Point Origin() const;

				void Position(Basis b);
				void Normal(Vector3D n);
				void Origin(Point p);
			private:
				Basis position;
			};

			ostream & operator << (ostream & out, Plan const& a);
			istream & operator >> (istream & in, Plan & a);
		}
	}
}
