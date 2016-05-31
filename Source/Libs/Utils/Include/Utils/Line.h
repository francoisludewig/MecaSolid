#pragma once

#include <Utils/Vector.h>
#include <iostream>
#include <iomanip>

#include "BasisId.h"

#include "../Include/Utils/Point.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Line : public BasisId {
			public:
				Line();
				Line(Point a, Vector u);
				~Line();
				Point Origin() const;
				Vector Direction() const;
				void Origin(Point a);
				void Direction(Vector b);

			private:
				Point origin;
				Vector direction;
			};

			std::ostream & operator << (std::ostream & out, Line const& a);
			std::istream & operator >> (std::istream & in, Line & a);
		}
	}
}
