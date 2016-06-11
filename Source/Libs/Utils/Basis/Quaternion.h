#pragma once

#include <iostream>
#include <iomanip>

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Vector;

			class Quaternion {
			public:
				Quaternion();
				Quaternion(const double & q0, const double & q1, const double & q2, const double & q3);
				Quaternion(const Vector & w);
				~Quaternion();

				double ComponantReal() const;
				double ComponantI() const;
				double ComponantJ() const;
				double ComponantK() const;
				double Norme();
				void Normalize();
				void SetComponants(const double & q0, const double & q1, const double & q2, const double & q3);

				Quaternion Product(const Quaternion & b) const;
				Quaternion Sum(const Quaternion & b) const;
				Quaternion Diff(const Quaternion & b) const;
				Quaternion operator*(const Quaternion &b) const;
				Quaternion operator+(const Quaternion &b) const;
				Quaternion operator-(const Quaternion &b) const;
				Quaternion operator~();
				void operator*=(const Quaternion & a);
				void operator+=(const Quaternion & a);
				void operator-=(const Quaternion & a);
			private:
				double componantReal,componantI,componantJ,componantK;
			};

			std::ostream & operator << (std::ostream & out, const Quaternion & a);
			std::istream & operator >> (std::istream & in, Quaternion & a);
		}
	}
}
