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

			bool InterceptorLines::AreVectorsLinearlyIndependant(const Vector& originAB, const Line& a, const Line& b) {
				Matrix m;
				m.Column(0, a.Direction());
				m.Column(1, b.Direction());
				m.Column(2, originAB);
				return !DoubleComparison::IsEqual(m.Determinant(),0);
			}

			bool InterceptorLines::AreVectorsParallel(const Vector& a, const Vector& b) {
				return (a ^ b) == Vector(0, 0, 0);
			}

			Interception InterceptorLines::Intercept(const Line& a, const Line& b) {
				Interception interception;
				Vector originAB = b.Origin()-a.Origin();
				if(AreVectorsLinearlyIndependant(originAB, a, b))
					return interception;

				if(AreVectorsParallel(a.Direction(), b.Direction())) {
					if(!AreVectorsParallel(a.Direction(), originAB))
						return interception;
					else{
						interception.Type(InterceptionLine);
						interception.SetLine(a);
						return interception;
					}
				}

				double salarProductDirections = a.Direction()*b.Direction();
				double beta = (originAB*b.Direction() - (originAB*a.Direction())*salarProductDirections) / (salarProductDirections*salarProductDirections-1);

				Point inter = b.Origin() + beta*b.Direction();
				interception.SetPoint(inter);
				interception.Type(InterceptionPoint);
				return interception;
			}
		}
	}
}
