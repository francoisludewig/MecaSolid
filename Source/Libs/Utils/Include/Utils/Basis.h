#pragma once

#include <Utils/Segment.h>
#include <iostream>
#include <iomanip>
#include "Utils/Quaternion.h"
#include "Utils/Vector3D.h"
#include "Utils/VectorsQuaternionConverter.h"

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Basis {
			public:
				Basis();
				~Basis();

				Point O() const;
				Vector3D E1() const;
				Vector3D E2() const;
				Vector3D E3() const;
				Quaternion Q() const;

				void E1(Vector3D e1);
				void O(Point o);
				void Q(Quaternion q);

				void Rotate(Quaternion const & q);
				void Translate(Vector3D const & o);

				void Local(Vector3D & a);
				void Global(Vector3D & a);

				void LoadFromIstream(istream & in);

				Basis operator*(Quaternion const & q);
				Basis operator+(Vector3D const & o);

				void operator*=(Quaternion const& q);
				void operator+=(Vector3D const& o);

			private:
				//TODO place these functions in another class ? !!!
				void BluidFromE1();

				Vector3D e1,e2,e3;
				Point o;
				Quaternion q;
				VectorsQuaternionConverter vQc;
			};

			ostream & operator << (ostream & out, Basis const& a);
			istream & operator >> (istream & in, Basis & a);
		}
	}
}
