/*
 * InterceptorPlans.cpp
 *
 *  Created on: 7 juin 2016
 *      Author: ludewigfrancois
 */

#include <InterceptorPlans.h>
#include "Interception.h"
#include "InterceptorLines.h"
#include "../GeometryConcepts/Plan.h"
#include "../GeometryConcepts/Line.h"
#include "../Basis/DoubleComparison.h"

namespace Luga {
	namespace Meca {
		namespace Utils {

			InterceptorPlans::InterceptorPlans() {
			}

			InterceptorPlans::~InterceptorPlans() {
			}

			void InterceptorPlans::MakeLinesForPointIntersection(const Plan &a, const Plan &b, Line & la, Line & lb, const Vector direction){
				Vector directionA,directionB;
				if(!DoubleComparison::IsEqual(a.Position().AxisY()*direction,0))
					directionA = a.Position().AxisY();
				else
					directionA = a.Position().AxisZ();

				if(!DoubleComparison::IsEqual(b.Position().AxisY()*direction,0))
					directionB = b.Position().AxisY();
				else
					directionB = b.Position().AxisZ();

				la = Line(a.Origin(),directionA);
				lb = Line(b.Origin(),directionB);
			}

			Interception InterceptorPlans::Intercept(Plan& a, Plan& b) {
				Interception interception;
				Vector direction = a.Normal() ^ b.Normal();
				if(direction == Vector(0,0,0)){
					if(a == b){
						interception.Type(InterceptionPlan);
						interception.SetPlan(a);
						return interception;
					}
					else{
						return interception;
					}
				}

				Line la,lb;
				MakeLinesForPointIntersection(a,b,la,lb,direction);

				InterceptorLines interceptorLines;
				Interception interlines = interceptorLines.Intercept(la,lb);
				if(interlines.Type() == InterceptionPoint){
					Line solution(interlines.GetPoint(),direction);
					interception.Type(InterceptionLine);
					interception.SetLine(solution);
					return interception;
				}
				return interception;
			}

		} /* namespace Utils */
	} /* namespace Meca */
} /* namespace Luga */

