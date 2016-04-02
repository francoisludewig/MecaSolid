#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

namespace Meca {
	namespace Libs {
		namespace Basis{

			class Vector3D;

			class UnitQuaternion {
			public:
				UnitQuaternion();
				UnitQuaternion(double q0, double q1, double q2, double q3);
				UnitQuaternion(const Vector3D & w);
				~UnitQuaternion();

				double Q0() const;
				double Q1() const;
				double Q2() const;
				double Q3() const;
				void IncrementDelay();
				int DelayBetweenCheck();
				double Norme();
				void SetValue(double q0, double q1, double q2, double q3, bool force = false);

				UnitQuaternion Product(const UnitQuaternion & b) const;
				UnitQuaternion operator*(UnitQuaternion const &b);
				UnitQuaternion operator~();
				void operator*=(UnitQuaternion const& a);
				void Check();
			private:
				void Normalize();
				double q0,q1,q2,q3;
				int delayBetweenCheck,maximumDelay;
			};

			ostream & operator << (ostream & out, UnitQuaternion const& a);
			istream & operator >> (istream & in, UnitQuaternion & a);
		}
	}
}
