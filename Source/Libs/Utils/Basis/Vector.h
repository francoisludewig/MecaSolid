#pragma once

#include <iostream>
#include <iomanip>

#include "BasisId.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Vector : public BasisId{
			public:
				Vector();
				Vector(const int & basisId);
				Vector(const double &x,const double &y, const double &z);
				Vector(const double &x,const double &y, const double &z,const int &basisId);

				virtual ~Vector();

				void SetComponants(const double &x, const double &y, const double &z);
				double Norme() const;
				void Normalize();
				double ScalarProduct(const Vector & b) const;
				Vector CrossProduct(const Vector & b) const;
				Vector Product(const double & b) const;
				Vector Division(const double & b) const;
				Vector Sum(const Vector & b) const;
				Vector Difference(const Vector & b) const;

				double ComponantX() const{return componantX;};
				double ComponantY() const{return componantY;};
				double ComponantZ() const{return componantZ;};

				void ComponantX(double x) {this->componantX = x;};
				void ComponantY(double y) {this->componantY = y;};
				void ComponantZ(double z) {this->componantZ = z;};

				void operator+=(const Vector & a);
				void operator-=(const Vector & a);
				void operator*=(const double & a);
				void operator/=(const double & a);

				double operator*(const Vector &b) const;
				Vector operator^(const Vector &b) const;
				Vector operator*(const double &b) const;
				Vector operator/(const double &b) const;
				Vector operator+(const Vector &b) const;
				Vector operator-(const Vector &b) const;

			private:
				double componantX,componantY,componantZ;
			};

			std::ostream & operator << (std::ostream & out, const Vector & a);
			std::istream & operator >> (std::istream & in, Vector & a);
			Vector operator*(const double & b, const Vector & a);
			bool operator== (const Vector &vector1, const Vector &vector2);
			bool operator!= (const Vector &vector1, const Vector &vector2);

		}
	}
}

