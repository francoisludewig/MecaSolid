#pragma once

#include <iostream>
#include <iomanip>
#include "BasisId.h"

#include "../Basis/Basis.h"
#include "../Basis/BasisId.h"

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

				Vector TangentS() const;
				Vector TangentT() const;

				void Position(Basis & b);
				void Normal(Vector & n);
				void Origin(Point & p);
			private:
				Basis position;
			};

			std::ostream & operator << (std::ostream & out, Plan const& a);
			std::istream & operator >> (std::istream & in, Plan & a);
			bool operator== (Plan const &plan1, Plan const &plan2);
			bool operator!= (Plan const &plan1, Plan const &plan2);
		}
	}
}
