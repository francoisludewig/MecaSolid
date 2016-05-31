#pragma once

#include <iostream>
#include <iomanip>

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Point;
			class Vector;
			class Line;
			class Segment;
			class Plan;
			class Basis;
			class Matrix;

			class BasisChangerImplementation {
			public:
				BasisChangerImplementation();
				virtual ~BasisChangerImplementation();
				virtual void ChangePoint(Point & point) const = 0;
				virtual void ChangeVector(Vector & vector3d) const  = 0;
				virtual void ChangeLine(Line & line) const;
				virtual void ChangeSegment(Segment & segment) const;
				virtual void ChangePlan(Plan & plan) const;
				virtual void ChangePlan(Matrix & matrix) const;
				virtual void FromBasis(Basis *from) = 0;
				virtual void ToBasis(Basis *to) = 0;
			protected:
				Basis *from,*to;
			};

		}
	}
}



