#pragma once

#include <iostream>
#include <iomanip>

#include "Quaternion.h"
#include "BasisId.h"
#include "Vector.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Matrix : public BasisId {
			public:
				Matrix();
				Matrix(const double & m00, const double & m01,const double & m02,
						  const double & m10, const double & m11,const double & m12,
						  const double & m20, const double & m21,const double & m22);
				~Matrix();

				void Element(const int & i, const int & j , const double & c);
				double Element(const int & i, const int & j) const;
				Vector Line(const int & i) const;
				Vector Column(const int & i) const;
				void Line(const int & i, const Vector & l);
				void Column(const int & i, const Vector & c);
				double Determinant() const;
				Matrix Product(const double & b) const;
				Matrix Div(const double & b) const;

				Matrix MatrixTranspose() const;
				Matrix MatrixAdjoint() const;
				Matrix MatrixInverse() const;

				Matrix operator*(const double &b) const;
				Vector operator*(const Vector &b) const;
				Matrix operator/(const double &b) const;

				void operator*=(const double & a);
				void operator/=(const double & a);
			private:
				double element[3][3];
			};

			std::ostream & operator << (std::ostream & out, Matrix const& a);
			std::istream & operator >> (std::istream & in, Matrix & a);
		}
	}
}
