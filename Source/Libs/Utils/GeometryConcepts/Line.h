#pragma once

#include <iostream>
#include <iomanip>

#include "../Basis/BasisId.h"
#include "../Basis/Vector.h"
#include "../GeometryConcepts/Point.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Line : public BasisId {
			public:
				Line();
				Line(const Point & a, const Vector & u);
				~Line();
				Point Origin() const;
				Vector Direction() const;
				void Origin(const Point & a);
				void Direction(const Vector & b);

			private:
				Point origin;
				Vector direction;
			};

			std::ostream & operator << (std::ostream & out, const Line & a);
			std::istream & operator >> (std::istream & in, Line & a);
			bool operator== (const Line &line1, const Line &line2);
			bool operator!= (const Line &line1, const Line &line2);
		}
	}
}
