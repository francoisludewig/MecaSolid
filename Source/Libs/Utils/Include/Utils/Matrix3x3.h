#pragma once

#include <iostream>
#include <iomanip>

#include "BasisId.h"

#include "../../../Utils/Include/Utils/Quaternion.h"
#include "../../../Utils/Include/Utils/Vector3D.h"

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Matrix3x3 : public BasisId {
			public:
				Matrix3x3();
				Matrix3x3(double m00, double m01,double m02,
						  double m10, double m11,double m12,
						  double m20, double m21,double m22);
				~Matrix3x3();

				void Element(int i, int j , double c);
				double Element(int i, int j) const;
				Vector3D Line(int i) const;
				Vector3D Column(int i) const;
				void Line(int i, Vector3D & l);
				void Column(int i, Vector3D & c);
				double Determinant() const;
				Matrix3x3 Product(const double & b) const;
				Matrix3x3 Div(const double & b) const;

				Matrix3x3 MatrixTranspose();
				Matrix3x3 MatrixAdjoint();
				Matrix3x3 MatrixInverse();

				Matrix3x3 operator*(double const &b);
				Vector3D operator*(Vector3D &b);
				Matrix3x3 operator/(double const &b);

				void operator*=(double const& a);
				void operator/=(double const& a);
			private:
				double element[3][3];
			};

			ostream & operator << (ostream & out, Matrix3x3 const& a);
			istream & operator >> (istream & in, Matrix3x3 & a);
		}
	}
}
