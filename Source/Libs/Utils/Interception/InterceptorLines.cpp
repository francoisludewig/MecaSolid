/*
 * InterceptorLines.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: root
 */

#include "InterceptorLines.h"
#include "Interception.h"
#include "../Basis/Vector.h"
#include "../Basis/Matrix.h"
#include "../Basis/DoubleComparison.h"
#include "../GeometryConcepts/Point.h"
#include "../GeometryConcepts/Line.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			InterceptorLines::InterceptorLines() {

			}

			InterceptorLines::~InterceptorLines() {
			}

			bool InterceptorLines::AreVectorsLinearlyIndependant(const Vector& originAB, Line& a, Line& b) {
				Matrix m;
				m.Column(0, a.Direction());
				m.Column(1, b.Direction());
				m.Column(2, originAB);
				return !DoubleComparison::IsEqual(m.Determinant(),0);
			}

			bool InterceptorLines::AreVectorsParallel(Line& a, Line& b) {
				return (a.Direction() ^ b.Direction()) == Vector(0, 0, 0);
			}

			Interception InterceptorLines::Intercept(Line& a, Line& b) {
				Interception interception;
				Vector originAB = b.Origin()-a.Origin();
				if(AreVectorsLinearlyIndependant(originAB, a, b))
					return interception;

				if(AreVectorsParallel(a, b)) {
					if(DoubleComparison::IsEqual(originAB*a.Direction(),0))
						return interception;
					else{
						interception.Type(InterceptionLine);
						interception.SetLine(a);
						return interception;
					}
				}

				double salarProductDirections = a.Direction()*b.Direction();
				double beta = (originAB*b.Direction()*salarProductDirections - originAB*b.Direction()) / (1-salarProductDirections*salarProductDirections);
				Point inter = b.Origin() + beta*b.Direction();
				interception.SetPoint(inter);
				interception.Type(InterceptionPoint);
				return interception;
			}
		}
	}
}
