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
				Basis(const Point & o, const Quaternion & q);
				~Basis();

				int ID() const;

				Point Origin() const;
				Vector AxisX() const;
				Vector AxisY() const;
				Vector AxisZ() const;
				Quaternion Orientation() const;

				void AxisX(const Vector & e1);
				void Origin(const Point & o);
				void Orientation(const Quaternion & q);

				void Rotate(const Quaternion & q);
				void Translate(const Vector & o);

				void Local(Vector & a) const;
				void Global(Vector & a) const;

				Point Local(const Point & a) const;
				Point Global(const Point & a) const;

				void LoadFromIstream(std::istream & in);

				Basis operator*(const Quaternion & q) const;
				Basis operator+(const Vector & o) const;

				void operator*=(const Quaternion & q);
				void operator+=(const Vector & o);

			private:
				void ConstructAxisYAndZFromX();

				Vector axisX,axisY,axisZ;
				Point origin;
				Quaternion orientation;
				VectorsQuaternionConverter vQc;
				int id;
				static int instanceCount;
			};

			std::ostream & operator << (std::ostream & out, const Basis & a);
			std::istream & operator >> (std::istream & in, Basis & a);
		}
	}
}
