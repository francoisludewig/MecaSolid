#include <Utils/Plan.h>
#include "../../Utils/Include/Utils/Vector.h"

#include <iostream>
#include <cmath>

#define precision 1E-15

namespace Luga {
	namespace Meca {
		namespace Utils{

			Plan::Plan():position(){
			}

			Plan::~Plan(){
			}

			Plan::Plan(Point p, Vector n):position(){
				position.Origin(p);
				position.AxisX(n);
			}

			Basis Plan::Position() const{
				return position;
			}

			Vector Plan::Normal() const {
				return position.AxisX();
			}

			Point Plan::Origin() const{
				return position.Origin();
			}

			void Plan::Position(Basis b){
				this->position = b;
			}

			void Plan::Normal(Vector n){
			}

			void Plan::Origin(Point p){

			}

			std::ostream & operator << (std::ostream & out, Plan const& a){
				out << std::scientific << std::setprecision(15);
				out << a.Position();
				return out;
			}

			std::istream & operator >> (std::istream & in, Plan & a){
				Basis b;
				in >> b;
				return in;
			}

		}
	}
}
