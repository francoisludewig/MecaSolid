
#include <iostream>
#include <cmath>
#include "../Include/Utils/BasisSwitcherFromBasisToBasis.h"

#include "../Include/Utils/Vector3D.h"
#include "../Include/Utils/Point.h"
#include "../Include/Utils/Basis.h"
#include "../Include/Utils/Line.h"
#include "../Include/Utils/Plan.h"

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			BasisSwitcherFromBasisToBasis::BasisSwitcherFromBasisToBasis(){
				this->from = NULL;
				this->to = NULL;
			}

			BasisSwitcherFromBasisToBasis::BasisSwitcherFromBasisToBasis(Basis * from, Basis * to){
				this->from = from;
				this->to = to;
			}

			BasisSwitcherFromBasisToBasis::~BasisSwitcherFromBasisToBasis(){

			}

			void BasisSwitcherFromBasisToBasis::SwithPoint(Point & point) const{
				if(from && to && point.Id() == from->ID()){
					basisToGlobal.SwithPoint(point);
					globalToBasis.SwithPoint(point);
				}
			}

			void BasisSwitcherFromBasisToBasis::SwithVector(Vector3D & vector3d) const{
				if(from && to && vector3d.Id() == from->ID()){
					basisToGlobal.SwithVector(vector3d);
					globalToBasis.SwithVector(vector3d);
				}
			}

			void BasisSwitcherFromBasisToBasis::SwithLine(Line & line) const{
				if(from && to && line.Id() == from->ID()){
					basisToGlobal.SwithLine(line);
					globalToBasis.SwithLine(line);
				}
			}

			void BasisSwitcherFromBasisToBasis::SwithSegment(Segment & segment) const{
				if(from && to && segment.Id() == from->ID()){
					basisToGlobal.SwithSegment(segment);
					globalToBasis.SwithSegment(segment);
				}
			}

			void BasisSwitcherFromBasisToBasis::SwithPlan(Plan & plan) const{
				if(from && to && plan.Id() == from->ID()){
					basisToGlobal.SwithPlan(plan);
					globalToBasis.SwithPlan(plan);
				}
			}

			void BasisSwitcherFromBasisToBasis::From(Basis *from){
				this->from = from;
				basisToGlobal.From(from);
			}

			void BasisSwitcherFromBasisToBasis::To(Basis *to){
				this->to = to;
				globalToBasis.To(to);
			}

		}
	}
}
