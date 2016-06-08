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
#include "../GeometryConcepts/Point.h"
#include "../Basis/DoubleComparison.h"

namespace Luga {
	namespace Meca {
		namespace Utils {

			InterceptorPlans::InterceptorPlans() {
			}

			InterceptorPlans::~InterceptorPlans() {
			}

			Point InterceptorPlans::GetIntersectionPoint(const Plan & a, const Plan & b, const Vector & direction){
				Vector AB = b.Origin()-a.Origin();
				Basis baseA = a.Position();
				Basis baseB = b.Position();

				if((baseA.AxisZ()^direction) != Vector(0,0,0)){
					double beta = ( (baseA.AxisY()*baseB.AxisY())*(AB*baseB.AxisY()) + ((baseA.AxisY()*baseB.AxisZ())*(AB*baseB.AxisZ()) - AB*baseA.AxisY()) )
									/ ( (baseA.AxisY()*baseB.AxisY())*(baseA.AxisZ()*baseB.AxisY()) + (baseA.AxisY()*baseB.AxisZ())*(baseA.AxisZ()*baseB.AxisZ()));
					return baseA.Origin() + beta*baseA.AxisZ();
				}
				else{
					double beta = ( (baseA.AxisZ()*baseB.AxisY())*(AB*baseB.AxisY()) + ((baseA.AxisZ()*baseB.AxisZ())*(AB*baseB.AxisZ()) - AB*baseA.AxisZ()) )
								/ ( (baseA.AxisZ()*baseB.AxisY())*(baseA.AxisY()*baseB.AxisY()) + (baseA.AxisY()*baseB.AxisZ())*(baseA.AxisZ()*baseB.AxisZ()));
					return baseA.Origin() + beta*baseA.AxisY();
				}
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

				Line solution(GetIntersectionPoint(a,b,direction),direction);
				interception.Type(InterceptionLine);
				interception.SetLine(solution);
				return interception;
			}

		} /* namespace Utils */
	} /* namespace Meca */
} /* namespace Luga */

