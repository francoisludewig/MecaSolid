/*
 * InterceptorSegments.cpp
 *
 *  Created on: 9 juin 2016
 *      Author: ludewigfrancois
 */

#include <InterceptorSegments.h>
#include "Interception.h"
#include "InterceptorLines.h"
#include "../GeometryConcepts/Segment.h"
#include "../GeometryConcepts/Line.h"

namespace Luga {
	namespace Meca {
		namespace Utils {

			InterceptorSegments::InterceptorSegments() {
			}

			InterceptorSegments::~InterceptorSegments() {
			}


			Interception InterceptorSegments::InterceptColinearSegments(const Segment & a, const Segment & b, const Line & commonLine){
				double beginA = (a.BeginPoint()-commonLine.Origin())*commonLine.Direction();
				double endA   = (a.EndPoint()  -commonLine.Origin())*commonLine.Direction();
				double beginB = (b.BeginPoint()-commonLine.Origin())*commonLine.Direction();
				double endB   = (b.EndPoint()  -commonLine.Origin())*commonLine.Direction();

				if(beginA < beginB){
					if(endA < beginB){
						return Interception();
					}
					else{
						if(endA <= endB){
							if(b.BeginPoint() != a.EndPoint()){
								Interception interceptSegment(InterceptionSegment);
								interceptSegment.SetSegment(Segment(b.BeginPoint(),a.EndPoint()));
								return interceptSegment;
							}
							else{
								Interception interceptSegment(InterceptionPoint);
								interceptSegment.SetPoint(b.BeginPoint());
								return interceptSegment;
							}
						}
						else{
							Interception interceptSegment(InterceptionSegment);
							interceptSegment.SetSegment(b);
							return interceptSegment;
						}
					}
				}
				else{
					if(endB < beginA){
						return Interception();
					}
					else{
						if(endB <= endA){
							if(a.BeginPoint() != b.EndPoint()){
								Interception interceptSegment(InterceptionSegment);
								interceptSegment.SetSegment(Segment(a.BeginPoint(),b.EndPoint()));
								return interceptSegment;
							}
							else{
								Interception interceptSegment(InterceptionPoint);
								interceptSegment.SetPoint(a.BeginPoint());
								return interceptSegment;
							}
						}
						else{
							Interception interceptSegment(InterceptionSegment);
							interceptSegment.SetSegment(a);
							return interceptSegment;
						}
					}
				}
			}

			bool InterceptorSegments::IsPointInSegments(const Point & candidate, const Segment & a, const Segment & b){
				double coeff = (candidate-a.BeginPoint())*a.AssiociatedLine().Direction();
				double length = (a.EndPoint()-a.BeginPoint())*a.AssiociatedLine().Direction();
				if(coeff < length){
					coeff = (candidate-b.BeginPoint())*b.AssiociatedLine().Direction();
					length = (b.EndPoint()-b.BeginPoint())*b.AssiociatedLine().Direction();
					if(coeff < length)
						return true;
				}
				return false;
			}

			Interception InterceptorSegments::Intercept(const Segment & a, const Segment & b){
				InterceptorLines interceptorLines;
				Interception interceptionLines = interceptorLines.Intercept(a.AssiociatedLine(),b.AssiociatedLine());
				if(interceptionLines.Type() ==  InterceptionEmpty)
					return Interception();

				if(interceptionLines.Type() ==  InterceptionPoint){
					if(IsPointInSegments(interceptionLines.GetPoint(),a,b))
						return interceptionLines;
					else
						return Interception();
				}

				if(interceptionLines.Type() ==  InterceptionLine){
					return InterceptColinearSegments(a,b,interceptionLines.GetLine());
				}
				return Interception();
			}


		} /* namespace Utils */
	} /* namespace Meca */
} /* namespace Luga */
