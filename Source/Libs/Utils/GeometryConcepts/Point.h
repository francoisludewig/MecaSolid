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
				Point(double x, double y, double z);
				~Point();
				double CoordinateX() const;
				double CoordinateY() const;
				double CoordinateZ() const;
				void SetCoordinates(double x, double y, double z);
				void Translate(Vector const & a);

				Point operator+(Vector const &b) const;
				Vector operator-(Point const &b) const;
				void operator+=(Vector const& a);
			private:
				double coordinateX,coordinateY,coordinateZ;
			};

			std::ostream & operator << (std::ostream & out, Point const& a);
			std::istream & operator >> (std::istream & in, Point & a);
			bool operator== (Point const &pt1, Point const &pt2);
			bool operator!= (Point const &pt1, Point const &pt2);
		}
	}
}
