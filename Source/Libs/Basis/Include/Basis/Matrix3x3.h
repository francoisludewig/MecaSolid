#pragma once

#include <iostream>
#include <iomanip>
#include "Vector3D.h"
#include "Quaternion.h"

using namespace std;

namespace Meca {
	namespace Libs {
		namespace Basis{

			class Matrix3x3 {
			public:
				Matrix3x3();
				~Matrix3x3();

				void Componant(int i, int j , double c);
				double Componant(int i, int j);
				Vector3D Line(int i);
				Vector3D Column(int i);
				void Line(int i, Vector3D l);
				void Column(int i, Vector3D c);
				double Determinant();
				Matrix3x3 Product(const double & b) const;
				Matrix3x3 Div(const double & b) const;

				Matrix3x3 MatrixTranspose();
				Matrix3x3 MatrixAdjoint();
				Matrix3x3 MatrixInverse();

				Matrix3x3 operator*(double const &b);
				Matrix3x3 operator/(double const &b);

				void operator*=(double const& a);
				void operator/=(double const& a);
			private:
				double m[3][3];
			};
		}
	}
}
