/*
 * InterceptorLineSegment.cpp
 *
 *  Created on: 14 juin 2016
 *      Author: ludewigfrancois
 */

#include <InterceptorLineSegment.h>

#include "Interception.h"
#include "InterceptorLines.h"
#include "../GeometryConcepts/Segment.h"
#include "../GeometryConcepts/Line.h"
#include "../GeometryConcepts/Point.h"

namespace Luga {
	namespace Meca {
		namespace Utils {

			InterceptorLineSegment::InterceptorLineSegment() {
			}

			InterceptorLineSegment::~InterceptorLineSegment() {
			}

			bool InterceptorLineSegment::IsPointInSegment(const Point &point, const Segment & segment){
				Vector beginPoint = point - segment.BeginPoint();
				Vector dirSegment = segment.EndPoint() - segment.BeginPoint();
				if(beginPoint.Norme() <= dirSegment.Norme())
					return true;
				return false;
			}

			Interception InterceptorLineSegment::Intercept(Line & line, Segment & segment){
				InterceptorLines interceptorLines;
				Interception lines = interceptorLines.Intercept(line,segment.AssiociatedLine());
				if(lines.Type() == InterceptionEmpty)
					return lines;

				if(lines.Type() == InterceptionLine){
					Interception interception(InterceptionSegment);
					interception.SetSegment(segment);
					return interception;
				}

				if(lines.Type() == InterceptionPoint){
					if(IsPointInSegment(lines.GetPoint(),segment))
						return lines;
				}

				return Interception();
			}

		} /* namespace Utils */
	} /* namespace Meca */
} /* namespace Luga */
