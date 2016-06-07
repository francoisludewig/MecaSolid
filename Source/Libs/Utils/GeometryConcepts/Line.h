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
				Line(Point a, Vector u);
				~Line();
				Point Origin() const;
				Vector Direction() const;
				void Origin(Point & a);
				void Direction(Vector & b);

			private:
				Point origin;
				Vector direction;
			};

			std::ostream & operator << (std::ostream & out, Line const& a);
			std::istream & operator >> (std::istream & in, Line & a);
			bool operator== (Line const &line1, Line const &line2);
			bool operator!= (Line const &line1, Line const &line2);
		}
	}
}
