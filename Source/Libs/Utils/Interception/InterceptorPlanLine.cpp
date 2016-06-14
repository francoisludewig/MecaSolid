/*
 * InterceptorPlanLine.cpp
 *
 *  Created on: 14 juin 2016
 *      Author: ludewigfrancois
 */

#include <InterceptorPlanLine.h>

#include "Interception.h"
#include "../GeometryConcepts/Plan.h"
#include "../GeometryConcepts/Line.h"
#include "../GeometryConcepts/Point.h"
#include "../Basis/DoubleComparison.h"
#include "InterceptorPlans.h"
#include "InterceptorLines.h"

namespace Luga {
	namespace Meca {
		namespace Utils {

			InterceptorPlanLine::InterceptorPlanLine() {
			}

			InterceptorPlanLine::~InterceptorPlanLine() {
			}

			bool InterceptorPlanLine::IsPointInPlan(const Point & point, const Plan & plan){
				return false;
			}

			Interception InterceptorPlanLine::Intercept(Plan& plan, Line& line){
				// Build a plan which contain line
				Plan linePlan(line.Origin(),line.Direction());
				Vector normal = linePlan.TangentS();
				linePlan.Normal(normal);

				InterceptorPlans interceptorPlans;
				Interception interceptionPlans = interceptorPlans.Intercept(plan,linePlan);

				if(interceptionPlans.Type() == InterceptionEmpty)
					return interceptionPlans;

				if(interceptionPlans.Type() == InterceptionPlan){
					Interception interception(InterceptionLine);
					interception.SetLine(line);
					return interception;
				}

				if(interceptionPlans.Type() == InterceptionLine){
					InterceptorLines interceptorLines;
					return interceptorLines.Intercept(interceptionPlans.GetLine(),line);
				}

				return Interception();
			}

		} /* namespace Utils */
	} /* namespace Meca */
} /* namespace Luga */
