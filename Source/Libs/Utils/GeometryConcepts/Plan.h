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

				void Position(const Basis & b);
				void Normal(const Vector & n);
				void Origin(const Point & p);
			private:
				Basis position;
			};

			std::ostream & operator << (std::ostream & out, const Plan & a);
			std::istream & operator >> (std::istream & in, Plan & a);
			bool operator== (const Plan &plan1, const Plan &plan2);
			bool operator!= (const Plan &plan1, const Plan &plan2);
		}
	}
}
