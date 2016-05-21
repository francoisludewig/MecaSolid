#pragma once

#include <iostream>
#include <iomanip>
#include "../Include/Utils/Point.h"
using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Line;

			class Segment {
			public:
				Segment();
				Segment(Point a, Point b);
				~Segment();
				Point BeginPoint() const;
				Point EndPoint() const;
				void BeginPoint(Point a);
				void EndPoint(Point b);
				Line AssiociatedLine() const;

			private:
				Point beginPoint,endPoint;
			};

			ostream & operator << (ostream & out, Segment const& a);
			istream & operator >> (istream & in, Segment & a);
		}
	}
}
