#pragma once

#include <iostream>
#include <iomanip>

#include "BasisId.h"

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Vector3D;

			class Point : public BasisId {
			public:
				Point();
				Point(double x, double y, double z);
				~Point();
				double CoordinateX() const;
				double CoordinateY() const;
				double CoordinateZ() const;
				void SetCoordinates(double x, double y, double z);
				void Translate(Vector3D const & a);

				Point operator+(Vector3D const &b) const;
				Vector3D operator-(Point const &b) const;
				void operator+=(Vector3D const& a);
				// TODO Rotate with a reference basis
			private:
				double coordinateX,coordinateY,coordinateZ;
			};

			ostream & operator << (ostream & out, Point const& a);
			istream & operator >> (istream & in, Point & a);
		}
	}
}
