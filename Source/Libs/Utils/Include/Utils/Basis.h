#pragma once

#include <Utils/Segment.h>
#include <iostream>
#include <iomanip>
#include "Utils/Quaternion.h"
#include "Utils/Vector3D.h"
#include "Utils/VectorsQuaternionConverter.h"

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Basis {
			public:
				Basis();
				Basis(Point o, Quaternion q);
				~Basis();

				Point Origin() const;
				Vector3D AxisX() const;
				Vector3D AxisY() const;
				Vector3D AxisZ() const;
				Quaternion Orientation() const;

				void AxisX(Vector3D & e1);
				void Origin(Point & o);
				void Orientation(Quaternion & q);

				void Rotate(Quaternion const & q);
				void Translate(Vector3D const & o);

				void Local(Vector3D & a) const;
				void Global(Vector3D & a) const;


				Point Local(const Point & a) const;
				Point Global(const Point & a) const;

				void LoadFromIstream(istream & in);

				Basis operator*(Quaternion const & q) const;
				Basis operator+(Vector3D const & o) const;

				void operator*=(Quaternion const& q);
				void operator+=(Vector3D const& o);

			private:
				void ConstructAxisYAndZFromX();

				Vector3D axisX,axisY,axisZ;
				Point origin;
				Quaternion orientation;
				VectorsQuaternionConverter vQc;
			};

			ostream & operator << (ostream & out, Basis const& a);
			istream & operator >> (istream & in, Basis & a);
		}
	}
}
