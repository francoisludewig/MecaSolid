#pragma once

#include <iostream>
#include <iomanip>

#include "../Basis/BasisId.h"
#include "Point.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Line;

			class Segment : public BasisId {
			public:
				Segment();
				Segment(Point a, Point b);
				~Segment();
				Point BeginPoint() const;
				Point EndPoint() const;
				void BeginPoint(const Point & a);
				void EndPoint(const Point & b);
				Line AssiociatedLine() const;

			private:
				Point beginPoint,endPoint;
			};

			std::ostream & operator << (std::ostream & out, const Segment & a);
			std::istream & operator >> (std::istream & in, Segment & a);
			bool operator== (const Segment &sg1, const Segment &sg2);
			bool operator!= (const Segment &sg1, const Segment &sg2);
		}
	}
}
