
#include "BasisChangerFromBasisToGlobal.h"

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

			BasisChangerFromBasisToGlobal::BasisChangerFromBasisToGlobal(){
				this->from = NULL;
			}

			BasisChangerFromBasisToGlobal::BasisChangerFromBasisToGlobal(Basis * from){
				this->from = from;
			}

			BasisChangerFromBasisToGlobal::~BasisChangerFromBasisToGlobal(){

			}

			void BasisChangerFromBasisToGlobal::ChangePoint(Point & point) const{
				if(from && point.Id() == from->ID()){
					point = from->Origin() + point.CoordinateX()*from->AxisX() + point.CoordinateY()*from->AxisY() + point.CoordinateZ()*from->AxisZ();
					point.Id(-1);
				}
			}

			void BasisChangerFromBasisToGlobal::ChangeVector(Vector & vector3d) const{
				if(from && vector3d.Id() == from->ID()){
					vector3d = vector3d.ComponantX()*from->AxisX() + vector3d.ComponantY()*from->AxisY() + vector3d.ComponantZ()*from->AxisZ();
					vector3d.Id(-1);
				}
			}

			void BasisChangerFromBasisToGlobal::FromBasis(Basis *from){
				this->from = from;
			}

			void BasisChangerFromBasisToGlobal::ToBasis(Basis *to){

			}
		}
	}
}
