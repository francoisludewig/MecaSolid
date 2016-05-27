
#include <iostream>
#include <cmath>
#include "../Include/Utils/BasisSwitcherFromBasisToGlobal.h"
#include "../Include/Utils/Vector3D.h"
#include "../Include/Utils/Point.h"
#include "../Include/Utils/Basis.h"
#include "../Include/Utils/Line.h"
#include "../Include/Utils/Plan.h"

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			BasisSwitcherFromBasisToGlobal::BasisSwitcherFromBasisToGlobal(){
				this->from = NULL;
			}

			BasisSwitcherFromBasisToGlobal::BasisSwitcherFromBasisToGlobal(Basis * from){
				this->from = from;
			}

			BasisSwitcherFromBasisToGlobal::~BasisSwitcherFromBasisToGlobal(){

			}

			void BasisSwitcherFromBasisToGlobal::SwithPoint(Point & point) const{
				if(from && point.Id() == from->ID()){
					point = from->Origin() + point.CoordinateX()*from->AxisX() + point.CoordinateY()*from->AxisY() + point.CoordinateZ()*from->AxisZ();
					point.Id(-1);
				}
			}

			void BasisSwitcherFromBasisToGlobal::SwithVector(Vector3D & vector3d) const{
				if(from && vector3d.Id() == from->ID()){
					vector3d = vector3d.ComponantX()*from->AxisX() + vector3d.ComponantY()*from->AxisY() + vector3d.ComponantZ()*from->AxisZ();
					vector3d.Id(-1);
				}
			}

			void BasisSwitcherFromBasisToGlobal::From(Basis *from){
				this->from = from;
			}

			void BasisSwitcherFromBasisToGlobal::To(Basis *to){

			}
		}
	}
}
