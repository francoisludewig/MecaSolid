#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Vector3D {
			public:
				Vector3D();
				Vector3D(double x,double y, double z);

				virtual ~Vector3D();

				void SetValue(double x, double y, double z);
				double Norme() const;
				void Normalize();
				double ScalarProduct(const Vector3D & b) const;
				Vector3D VectorialProduct(const Vector3D & b) const;
				Vector3D Product(const double & b) const;
				Vector3D Div(const double & b) const;
				Vector3D Sum(const Vector3D & b) const;
				Vector3D Diff(const Vector3D & b) const;

				double X() const{return x;};
				double Y() const{return y;};
				double Z() const{return z;};

				void X(double x) {this->x = x;};
				void Y(double y) {this->y = y;};
				void Z(double z) {this->z = z;};

				void operator+=(Vector3D const& a);
				void operator-=(Vector3D const& a);
				void operator*=(double const& a);
				void operator/=(double const& a);

				double operator*(Vector3D const &b);
				Vector3D operator^(Vector3D const &b);
				Vector3D operator*(double const &b);
				Vector3D operator/(double const &b);
				Vector3D operator+(Vector3D const &b);
				Vector3D operator-(Vector3D const &b);

			private:
				double x,y,z;
			};

			ostream & operator << (ostream & out, Vector3D const& a);
			istream & operator >> (istream & in, Vector3D & a);
			Vector3D operator*(const double & b, Vector3D const & a);
		}
	}
}

