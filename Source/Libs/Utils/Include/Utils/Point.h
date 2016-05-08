#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Vector3D;

			class Point {
			public:
				Point();
				Point(double x, double y, double z);
				~Point();
				double X() const;
				double Y() const;
				double Z() const;
				void SetValue(double x, double y, double z);
				void Add(Vector3D const & a);

				Point operator+(Vector3D const &b);
				Vector3D operator-(Point const &b);
				void operator+=(Vector3D const& a);

			private:
				double x,y,z;
			};

			ostream & operator << (ostream & out, Point const& a);
			istream & operator >> (istream & in, Point & a);
		}
	}
}
