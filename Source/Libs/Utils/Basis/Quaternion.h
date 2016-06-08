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
				Quaternion(double q0, double q1, double q2, double q3);
				Quaternion(const Vector & w);
				~Quaternion();

				double ComponantReal() const;
				double ComponantI() const;
				double ComponantJ() const;
				double ComponantK() const;
				double Norme();
				void Normalize();
				void SetComponants(double q0, double q1, double q2, double q3);

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
				double componantReal,componantI,componantJ,componantK;
			};

			std::ostream & operator << (std::ostream & out, Quaternion const& a);
			std::istream & operator >> (std::istream & in, Quaternion & a);
		}
	}
}