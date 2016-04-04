#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

namespace Meca {
	namespace Libs {
		namespace Basis{

			class Vector3D;

			class Quaternion {
			public:
				Quaternion();
				Quaternion(double q0, double q1, double q2, double q3);
				Quaternion(const Vector3D & w);
				~Quaternion();

				double Q0() const;
				double Q1() const;
				double Q2() const;
				double Q3() const;
				double Norme();
				void SetValue(double q0, double q1, double q2, double q3);

				Quaternion Product(const Quaternion & b) const;
				Quaternion Sum(const Quaternion & b) const;
				Quaternion Diff(const Quaternion & b) const;
				Quaternion operator*(Quaternion const &b);
				Quaternion operator+(Quaternion const &b);
				Quaternion operator-(Quaternion const &b);
				Quaternion operator~();
				void operator*=(Quaternion const& a);
				void operator+=(Quaternion const& a);
				void operator-=(Quaternion const& a);
			private:
				double q0,q1,q2,q3;
			};

			ostream & operator << (ostream & out, Quaternion const& a);
			istream & operator >> (istream & in, Quaternion & a);
		}
	}
}
