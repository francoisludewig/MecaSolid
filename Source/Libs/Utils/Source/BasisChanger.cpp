
#include <Utils/BasisChanger.h>
#include <iostream>
#include <cmath>

namespace Luga {
	namespace Meca {
		namespace Utils{

			BasisChanger::BasisChanger(): from(NULL), to(NULL), type(None), switcher(NULL){

			}

			BasisChanger::~BasisChanger(){

			}

			void BasisChanger::Type(BasisChangerType type){
				this->type = type;
				UpdateSwitcher();
			}

			BasisChangerType BasisChanger::Type(){
				return type;
			}

			void BasisChanger::UpdateSwitcher(){
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

			void BasisChanger::ChangePoint(Point & point) const{
				switcher->ChangePoint(point);
			}

			void BasisChanger::ChangeVector(Vector & vector3d) const{
				switcher->ChangeVector(vector3d);
			}

			void BasisChanger::ChangeLine(Line & line) const{
				switcher->ChangeLine(line);
			}

			void BasisChanger::ChangeSegment(Segment & segment) const{
				switcher->ChangeSegment(segment);
			}

			void BasisChanger::ChangePlan(Plan & plan) const{
				switcher->ChangePlan(plan);
			}

			void BasisChanger::FromBasis(Basis *from){
				this->from = from;
				basisToGlobal.FromBasis(from);
				basisToBasis.FromBasis(from);
				globalToBasis.FromBasis(from);
				if(from != NULL){
					if(to == NULL){
						type = From_Basis_To_Global;
						UpdateSwitcher();
					}
					else{
						type = From_Basis_To_Basis;
						UpdateSwitcher();
					}
				}
				else{
					if(to == NULL){
						type = None;
						UpdateSwitcher();
					}
					else{
						type = From_Global_To_Basis;
						UpdateSwitcher();
					}
				}
			}

			void BasisChanger::ToBasis(Basis *to){
				this->to = to;
				basisToGlobal.ToBasis(to);
				basisToBasis.ToBasis(to);
				globalToBasis.ToBasis(to);
				if(to != NULL){
					if(from == NULL){
						type = From_Global_To_Basis;
						UpdateSwitcher();
					}
					else{
						type = From_Basis_To_Basis;
						UpdateSwitcher();
					}
				}
				else{
					if(from == NULL){
						type = None;
						UpdateSwitcher();
					}
					else{
						type = From_Global_To_Basis;
						UpdateSwitcher();
					}
				}
			}

		}
	}
}
