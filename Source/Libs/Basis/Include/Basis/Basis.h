#pragma once

#include <iostream>
#include <iomanip>
#include "Vector3D.h"
#include "Quaternion.h"

using namespace std;

namespace Meca {
	namespace Libs {
		namespace Basis{

			class Basis {
			public:
				Basis();
				~Basis();

				Vector3D O() const;
				Vector3D E1() const;
				Vector3D E2() const;
				Vector3D E3() const;
				Quaternion Q() const;

				void O(Vector3D o);
				void Q(Quaternion q);

				void Rotate(Quaternion const & q);
				void Translate(Vector3D const & o);

				void Local(Vector3D & a);
				void Global(Vector3D & a);

				void UpdateEFromQ();
				void LoadFromIstream(istream & in);

				Basis operator*(Quaternion const & q);
				Basis operator+(Vector3D const & o);

				void operator*=(Quaternion const& q);
				void operator+=(Vector3D const& o);
			private:
				Vector3D o,e1,e2,e3;
				Quaternion q;
			};

			ostream & operator << (ostream & out, Basis const& a);
			istream & operator >> (istream & in, Basis & a);
		}
	}
}
