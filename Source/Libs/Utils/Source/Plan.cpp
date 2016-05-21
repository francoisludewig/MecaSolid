#include <Utils/Plan.h>
#include "../../Utils/Include/Utils/Vector3D.h"

#include <iostream>
#include <cmath>

#define precision 1E-15

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			Plan::Plan():position(){
			}

			Plan::~Plan(){
			}

			Plan::Plan(Point p, Vector3D n):position(){
				position.Origin(p);
				position.AxisX(n);
			}

			Basis Plan::Position() const{
				return position;
			}

			Vector3D Plan::Normal() const {
				return position.AxisX();
			}

			Point Plan::Origin() const{
				return position.Origin();
			}

			void Plan::Position(Basis b){
				this->position = b;
			}

			void Plan::Normal(Vector3D n){
			}

			void Plan::Origin(Point p){

			}

			ostream & operator << (ostream & out, Plan const& a){
				out << scientific << setprecision(15);
				out << a.Position();
				return out;
			}

			istream & operator >> (istream & in, Plan & a){
				Basis b;
				in >> b;
				return in;
			}

		}
	}
}
