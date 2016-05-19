#include <Utils/Plan.h>
#include "../../Utils/Include/Utils/Vector3D.h"

#include <iostream>
#include <cmath>

#define precision 1E-15

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			Plan::Plan():b(){
			}

			Plan::~Plan(){
			}

			Plan::Plan(Point p, Vector3D n):b(){
				b.O(p);
				b.E1(n);
			}

			Basis Plan::B() const{
				return b;
			}

			Vector3D Plan::Normal() const {
				return b.E1();
			}

			Point Plan::Origin() const{
				return b.O();
			}

			void Plan::B(Basis b){
				this->b = b;
			}

			void Plan::Normal(Vector3D n){
			}

			void Plan::Origin(Point p){

			}

			ostream & operator << (ostream & out, Plan const& a){
				out << scientific << setprecision(15);
				out << a.B();
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
