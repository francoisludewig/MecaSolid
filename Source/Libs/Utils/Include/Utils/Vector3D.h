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

				void SetComponants(double x, double y, double z);
				double Norme() const;
				void Normalize();
				double ScalarProduct(const Vector3D & b) const;
				Vector3D VectorialProduct(const Vector3D & b) const;
				Vector3D Product(const double & b) const;
				Vector3D Division(const double & b) const;
				Vector3D Sum(const Vector3D & b) const;
				Vector3D Difference(const Vector3D & b) const;

				double ComponantX() const{return componantX;};
				double ComponantY() const{return componantY;};
				double ComponantZ() const{return componantZ;};

				void ComponantX(double x) {this->componantX = x;};
				void ComponantY(double y) {this->componantY = y;};
				void ComponantZ(double z) {this->componantZ = z;};

				void operator+=(Vector3D const& a);
				void operator-=(Vector3D const& a);
				void operator*=(double const& a);
				void operator/=(double const& a);

				double operator*(Vector3D const &b) const;
				Vector3D operator^(Vector3D const &b) const;
				Vector3D operator*(double const &b) const;
				Vector3D operator/(double const &b) const;
				Vector3D operator+(Vector3D const &b) const;
				Vector3D operator-(Vector3D const &b) const;

			private:
				double componantX,componantY,componantZ;
			};

			ostream & operator << (ostream & out, Vector3D const& a);
			istream & operator >> (istream & in, Vector3D & a);
			Vector3D operator*(const double & b, Vector3D const & a);
		}
	}
}

