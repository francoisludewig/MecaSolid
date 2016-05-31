
#include <Utils/BasisChangerFromBasisToBasis.h>
#include <Utils/Vector.h>
#include <iostream>
#include <cmath>
#include "../Include/Utils/Point.h"
#include "../Include/Utils/Basis.h"
#include "../Include/Utils/Line.h"
#include "../Include/Utils/Plan.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			BasisChangerFromBasisToBasis::BasisChangerFromBasisToBasis(){
				this->from = NULL;
				this->to = NULL;
			}

			BasisChangerFromBasisToBasis::BasisChangerFromBasisToBasis(Basis * from, Basis * to){
				this->from = from;
				this->to = to;
			}

			BasisChangerFromBasisToBasis::~BasisChangerFromBasisToBasis(){

			}

			void BasisChangerFromBasisToBasis::ChangePoint(Point & point) const{
				if(from && to && point.Id() == from->ID()){
					basisToGlobal.ChangePoint(point);
					globalToBasis.ChangePoint(point);
				}
			}

			void BasisChangerFromBasisToBasis::ChangeVector(Vector & vector3d) const{
				if(from && to && vector3d.Id() == from->ID()){
					basisToGlobal.ChangeVector(vector3d);
					globalToBasis.ChangeVector(vector3d);
				}
			}

			void BasisChangerFromBasisToBasis::FromBasis(Basis *from){
				this->from = from;
				basisToGlobal.FromBasis(from);
			}

			void BasisChangerFromBasisToBasis::ToBasis(Basis *to){
				this->to = to;
				globalToBasis.ToBasis(to);
			}

		}
	}
}
