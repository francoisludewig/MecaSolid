#pragma once

#include <iostream>
#include <iomanip>
#include "../Include/Utils/Point.h"

#include "BasisId.h"

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
				void BeginPoint(Point & a);
				void EndPoint(Point & b);
				Line AssiociatedLine() const;

			private:
				Point beginPoint,endPoint;
			};

			std::ostream & operator << (std::ostream & out, Segment const& a);
			std::istream & operator >> (std::istream & in, Segment & a);
		}
	}
}
