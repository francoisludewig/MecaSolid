
#include <iostream>
#include <cmath>
#include "../Include/Utils/BasisSwitcher.h"

#define precision 1E-15

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			BasisSwitcher::BasisSwitcher(): type(None), switcher(NULL){

			}

			BasisSwitcher::~BasisSwitcher(){

			}

			void BasisSwitcher::Type(BasisSwitcherType type){
				this->type = type;
				UpdateSwitcher();
			}

			void BasisSwitcher::UpdateSwitcher(){
				switch(type){
				case None:
					switcher = NULL;
					break;
				case From_Global_To_Basis:
					switcher = &globalToBasis;
					break;
				case From_Basis_To_Global:
					switcher = &basisToGlobal;
					break;
				case From_Basis_To_Basis:
					switcher = &basisToBasis;
					break;
				}
			}

			void BasisSwitcher::SwithPoint(Point & point) const{
				switcher->SwithPoint(point);
			}

			void BasisSwitcher::SwithVector(Vector3D & vector3d) const{
				switcher->SwithVector(vector3d);
			}

			void BasisSwitcher::SwithLine(Line & line) const{
				switcher->SwithLine(line);
			}

			void BasisSwitcher::SwithSegment(Segment & segment) const{
				switcher->SwithSegment(segment);
			}

			void BasisSwitcher::SwithPlan(Plan & plan) const{
				switcher->SwithPlan(plan);
			}

			void BasisSwitcher::From(Basis *from){
				this->from = from;
				basisToGlobal.From(from);
				basisToBasis.From(from);
				globalToBasis.From(from);
			}

			void BasisSwitcher::To(Basis *to){
				this->to = to;
				basisToGlobal.To(to);
				basisToBasis.To(to);
				globalToBasis.To(to);
			}

		}
	}
}