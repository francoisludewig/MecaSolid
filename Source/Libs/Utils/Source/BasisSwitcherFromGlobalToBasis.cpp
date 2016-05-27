
#include <iostream>
#include <cmath>
#include "../Include/Utils/BasisSwitcherFromGlobalToBasis.h"
#include "../Include/Utils/Vector3D.h"
#include "../Include/Utils/Point.h"
#include "../Include/Utils/Basis.h"
#include "../Include/Utils/Line.h"
#include "../Include/Utils/Plan.h"

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			BasisSwitcherFromGlobalToBasis::BasisSwitcherFromGlobalToBasis(){
				this->to = NULL;
			}

			BasisSwitcherFromGlobalToBasis::BasisSwitcherFromGlobalToBasis(Basis * to){
				this->to = to;
			}

			BasisSwitcherFromGlobalToBasis::~BasisSwitcherFromGlobalToBasis(){

			}

			void BasisSwitcherFromGlobalToBasis::SwithPoint(Point & point) const{
				if(to && point.Id() == -1){
					Vector3D v = point - to->Origin();
					point.SetCoordinates(to->AxisX()*v,to->AxisY()*v,to->AxisZ()*v);
					point.Id(to->ID());
				}
			}

			void BasisSwitcherFromGlobalToBasis::SwithVector(Vector3D & vector3d) const{
				if(to && vector3d.Id() == -1){
					double x,y,z;
					x = vector3d*to->AxisX();
					y = vector3d*to->AxisY();
					z = vector3d*to->AxisZ();
					vector3d.SetComponants(x,y,z);
					vector3d.Id(to->ID());
				}
			}

			void BasisSwitcherFromGlobalToBasis::From(Basis *from){

			}

			void BasisSwitcherFromGlobalToBasis::To(Basis *to){
				this->to = to;
			}

		}
	}
}
