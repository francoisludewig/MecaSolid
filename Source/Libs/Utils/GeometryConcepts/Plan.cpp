#include "../GeometryConcepts/Plan.h"
#include "../Basis/Vector.h"
#include "../Basis/Basis.h"

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

			void Plan::Position(Basis & b){
				this->position = b;
			}

			Vector Plan::TangentT() const{
				return position.AxisY();
			}

			Vector Plan::TangentS() const{
			return position.AxisZ();
			}

			void Plan::Normal(Vector & n){
				position.AxisX(n);
			}

			void Plan::Origin(Point & p){
				position.Origin(p);
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

			bool operator== (Plan const &plan1, Plan const &plan2){
				if((plan1.Normal()^plan2.Normal()) != Vector(0,0,0))
					return false;
				if(plan1.Normal()*(plan1.Origin()-plan2.Origin()) != 0)
					return false;
				return true;
			}

			bool operator!= (Plan const &plan1, Plan const &plan2){
				return !(plan1==plan2);
			}

		}
	}
}
