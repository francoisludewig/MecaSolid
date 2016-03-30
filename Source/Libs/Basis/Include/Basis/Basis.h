#pragma once

#include <iostream>
#include <iomanip>
#include "Vector3D.h"
#include "UnitQuaternion.h"
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
				UnitQuaternion Q() const;

				void O(Vector3D o);
				void Q(UnitQuaternion q);

				void UpdateEFromQ();
				void LoadFromIstream(istream & in);
			private:
				Vector3D e1,e2,e3,o;
				UnitQuaternion q;
			};

			ostream & operator << (ostream & out, Basis const& a);
			istream & operator >> (istream & in, Basis & a);
		}
	}
}
