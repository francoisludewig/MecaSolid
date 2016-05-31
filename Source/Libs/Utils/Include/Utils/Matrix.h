#pragma once

#include <Utils/Vector.h>
#include <iostream>
#include <iomanip>

#include "BasisId.h"

#include "../../../Utils/Include/Utils/Quaternion.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Matrix : public BasisId {
			public:
				Matrix();
				Matrix(double m00, double m01,double m02,
						  double m10, double m11,double m12,
						  double m20, double m21,double m22);
				~Matrix();

				void Element(int i, int j , double c);
				double Element(int i, int j) const;
				Vector Line(int i) const;
				Vector Column(int i) const;
				void Line(int i, Vector & l);
				void Column(int i, Vector & c);
				double Determinant() const;
				Matrix Product(const double & b) const;
				Matrix Div(const double & b) const;

				Matrix MatrixTranspose();
				Matrix MatrixAdjoint();
				Matrix MatrixInverse();

				Matrix operator*(double const &b);
				Vector operator*(Vector &b);
				Matrix operator/(double const &b);

				void operator*=(double const& a);
				void operator/=(double const& a);
			private:
				double element[3][3];
			};

			std::ostream & operator << (std::ostream & out, Matrix const& a);
			std::istream & operator >> (std::istream & in, Matrix & a);
		}
	}
}
