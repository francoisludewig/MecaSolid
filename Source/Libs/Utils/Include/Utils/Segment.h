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
				Point A() const;
				Point B() const;
				void SetA(Point a);
				void SetB(Point b);
				Line GetLine();

			private:
				Point a,b;
			};

			ostream & operator << (ostream & out, Segment const& a);
			istream & operator >> (istream & in, Segment & a);
		}
	}
}
