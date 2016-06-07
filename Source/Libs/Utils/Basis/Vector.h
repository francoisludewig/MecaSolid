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
				Vector(int basisId);
				Vector(double x,double y, double z);
				Vector(double x,double y, double z,int basisId);

				virtual ~Vector();

				void SetComponants(double x, double y, double z);
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

				void operator+=(Vector const& a);
				void operator-=(Vector const& a);
				void operator*=(double const& a);
				void operator/=(double const& a);

				double operator*(Vector const &b) const;
				Vector operator^(Vector const &b) const;
				Vector operator*(double const &b) const;
				Vector operator/(double const &b) const;
				Vector operator+(Vector const &b) const;
				Vector operator-(Vector const &b) const;

			private:
				double componantX,componantY,componantZ;
			};

			std::ostream & operator << (std::ostream & out, Vector const& a);
			std::istream & operator >> (std::istream & in, Vector & a);
			Vector operator*(const double & b, Vector const & a);
			bool operator== (Vector const &vector1, Vector const &vector2);
			bool operator!= (Vector const &vector1, Vector const &vector2);

		}
	}
}

