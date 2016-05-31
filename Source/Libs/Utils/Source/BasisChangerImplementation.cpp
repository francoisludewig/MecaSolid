
#include <Utils/BasisChangerImplementation.h>
#include <Utils/Vector.h>
#include <iostream>
#include <cmath>
#include "../Include/Utils/Point.h"
#include "../Include/Utils/Basis.h"
#include "../Include/Utils/Line.h"
#include "../Include/Utils/Plan.h"
#include "../Include/Utils/Matrix.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			BasisChangerImplementation::BasisChangerImplementation() : to(NULL), from(NULL){

			}

			BasisChangerImplementation::~BasisChangerImplementation(){

			}

			void BasisChangerImplementation::ChangeLine(Line & line) const{
				if(line.Id() == from->ID()){
					Point origin = line.Origin();
					Vector direction = line.Direction();
					ChangePoint(origin);
					ChangeVector(direction);
					line.Origin(origin);
					line.Direction(direction);
				}
			}

			void BasisChangerImplementation::ChangeSegment(Segment & segment) const{
				if(segment.Id() == from->ID()){
					Point begin = segment.BeginPoint();
					Point end = segment.EndPoint();
					ChangePoint(begin);
					ChangePoint(end);
					segment.BeginPoint(begin);
					segment.EndPoint(end);
				}
			}

			void BasisChangerImplementation::ChangePlan(Plan & plan) const{
				if(plan.Id() == from->ID()){
					Point origin = plan.Origin();
					Vector normal = plan.Normal();
					ChangePoint(origin);
					ChangeVector(normal);
					plan.Origin(origin);
					plan.Normal(normal);
				}
			}
			//TODO : test in order to validate this approach ! Which theory ?
			void BasisChangerImplementation::ChangePlan(Matrix & matrix) const{
				if(matrix.Id() == from->ID()){
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
}
