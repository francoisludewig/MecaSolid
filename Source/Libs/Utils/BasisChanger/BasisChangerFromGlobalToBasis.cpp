
#include "BasisChangerFromGlobalToBasis.h"

#include <iostream>
#include <cmath>
#include "../GeometryConcepts/Point.h"
#include "../Basis/Basis.h"
#include "../Basis/Vector.h"
#include "../GeometryConcepts/Line.h"
#include "../GeometryConcepts/Plan.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			BasisChangerFromGlobalToBasis::BasisChangerFromGlobalToBasis(){
				this->to = NULL;
			}

			BasisChangerFromGlobalToBasis::BasisChangerFromGlobalToBasis(Basis * to){
				this->to = to;
			}

			BasisChangerFromGlobalToBasis::~BasisChangerFromGlobalToBasis(){

			}

			void BasisChangerFromGlobalToBasis::ChangePoint(Point & point) const{
				if(to && point.Id() == -1){
					Vector v = point - to->Origin();
					point.SetCoordinates(to->AxisX()*v,to->AxisY()*v,to->AxisZ()*v);
					point.Id(to->ID());
				}
			}

			void BasisChangerFromGlobalToBasis::ChangeVector(Vector & vector3d) const{
				if(to && vector3d.Id() == -1){
					double x,y,z;
					x = vector3d*to->AxisX();
					y = vector3d*to->AxisY();
					z = vector3d*to->AxisZ();
					vector3d.SetComponants(x,y,z);
					vector3d.Id(to->ID());
				}
			}

			void BasisChangerFromGlobalToBasis::FromBasis(Basis *from){

			}

			void BasisChangerFromGlobalToBasis::ToBasis(Basis *to){
				this->to = to;
			}

		}
	}
}
