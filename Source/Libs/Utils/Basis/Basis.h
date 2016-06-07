#pragma once

#include <iostream>
#include <iomanip>
#include "../GeometryConcepts/Segment.h"
#include "Quaternion.h"
#include "Vector.h"
#include "VectorsQuaternionConverter.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Basis {
			public:
				Basis();
				Basis(Point o, Quaternion q);
				~Basis();

				int ID() const;

				Point Origin() const;
				Vector AxisX() const;
				Vector AxisY() const;
				Vector AxisZ() const;
				Quaternion Orientation() const;

				void AxisX(Vector & e1);
				void Origin(Point & o);
				void Orientation(Quaternion & q);

				void Rotate(Quaternion const & q);
				void Translate(Vector const & o);

				void Local(Vector & a) const;
				void Global(Vector & a) const;

				Point Local(const Point & a) const;
				Point Global(const Point & a) const;

				void LoadFromIstream(std::istream & in);

				Basis operator*(Quaternion const & q) const;
				Basis operator+(Vector const & o) const;

				void operator*=(Quaternion const& q);
				void operator+=(Vector const& o);

			private:
				void ConstructAxisYAndZFromX();

				Vector axisX,axisY,axisZ;
				Point origin;
				Quaternion orientation;
				VectorsQuaternionConverter vQc;
				int id;
				static int instanceCount;
			};

			std::ostream & operator << (std::ostream & out, Basis const& a);
			std::istream & operator >> (std::istream & in, Basis & a);
		}
	}
}
