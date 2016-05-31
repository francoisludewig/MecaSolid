#pragma once

#include <iostream>
#include <iomanip>

#include "BasisId.h"

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
				// TODO Rotate with a reference basis
			private:
				double coordinateX,coordinateY,coordinateZ;
			};

			std::ostream & operator << (std::ostream & out, Point const& a);
			std::istream & operator >> (std::istream & in, Point & a);
		}
	}
}
