#pragma once

#include <iostream>
#include <iomanip>
#include "Basis.h"

#include "BasisId.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Plan : public BasisId {
			public:
				Plan();
				Plan(Point p, Vector n);
				~Plan();
				Basis Position() const;
				Vector Normal() const;
				Point Origin() const;

				void Position(Basis b);
				void Normal(Vector n);
				void Origin(Point p);
			private:
				Basis position;
			};

			std::ostream & operator << (std::ostream & out, Plan const& a);
			std::istream & operator >> (std::istream & in, Plan & a);
		}
	}
}
