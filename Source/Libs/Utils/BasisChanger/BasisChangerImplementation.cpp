
#include "BasisChangerImplementation.h"

#include <iostream>
#include <cmath>
#include "../GeometryConcepts/Point.h"
#include "../Basis/Basis.h"
#include "../Basis/Matrix.h"
#include "../Basis/Vector.h"
#include "../GeometryConcepts/Line.h"
#include "../GeometryConcepts/Plan.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			BasisChangerImplementation::BasisChangerImplementation() : to(NULL), from(NULL){

			}

			BasisChangerImplementation::~BasisChangerImplementation(){

			}

			void BasisChangerImplementation::ChangeLine(Line & line) const{
				Point origin = line.Origin();
				Vector direction = line.Direction();
				ChangePoint(origin);
				ChangeVector(direction);
				line.Origin(origin);
				line.Direction(direction);
			}

			void BasisChangerImplementation::ChangeSegment(Segment & segment) const{
				Point begin = segment.BeginPoint();
				Point end = segment.EndPoint();
				ChangePoint(begin);
				ChangePoint(end);
				segment.BeginPoint(begin);
				segment.EndPoint(end);
			}

			void BasisChangerImplementation::ChangePlan(Plan & plan) const{
				Point origin = plan.Origin();
				Vector normal = plan.Normal();
				ChangePoint(origin);
				ChangeVector(normal);
				plan.Origin(origin);
				plan.Normal(normal);
			}
			//TODO : test in order to validate this approach ! Which theory ?
			void BasisChangerImplementation::ChangeMatrix(Matrix & matrix) const{
				Vector line1 = matrix.Line(0),line2 = matrix.Line(1),line3 = matrix.Line(2);
				ChangeVector(line1);
				ChangeVector(line2);
				ChangeVector(line3);
				matrix.Line(0,line1);
				matrix.Line(1,line2);
				matrix.Line(2,line3);
			}

		}
	}
}
