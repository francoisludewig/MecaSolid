#pragma once

#include <iostream>
#include <iomanip>

#include "../Basis/BasisId.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Vector;

			class Point : public BasisId {
			public:
				Point();
				Point(const double &x, const double &y, const double &z);
				~Point();
				double CoordinateX() const;
				double CoordinateY() const;
				double CoordinateZ() const;
				void SetCoordinates(const double & x, const double & y, const double & z);
				void Translate(const Vector & a);

				Point operator+(const Vector &b) const;
				Vector operator-(const Point &b) const;
				void operator+=(const Vector& a);
			private:
				double coordinateX,coordinateY,coordinateZ;
			};

			std::ostream & operator << (std::ostream & out, const Point & a);
			std::istream & operator >> (std::istream & in, Point & a);
			bool operator== (const Point  &pt1, const Point &pt2);
			bool operator!= (const Point  &pt1, const Point &pt2);
		}
	}
}
