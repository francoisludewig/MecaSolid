
#include <iostream>
#include <cmath>
#include "../Include/Solid/Solid.h"

#define precision 1E-15

using namespace std;

namespace Meca {
	namespace Libs {
		namespace Basis{

			Solid::Solid():b(),velocity(0,0,0),angularVelocity(0,0,0),force(0,0,0),momentum(0,0,0){
				mass = 1;
				inertia_1[0][0] = 1;inertia_1[0][1] = 0;inertia_1[0][2] = 0;
				inertia_1[1][0] = 0;inertia_1[1][1] = 1;inertia_1[1][2] = 0;
				inertia_1[2][0] = 0;inertia_1[2][1] = 0;inertia_1[2][2] = 1;
			}

			Solid::~Solid(){

			}

			Basis Solid::B() const{return b;}
			Vector3D Solid::Velocity() const{return velocity;}
			Vector3D Solid::AngularVelocity() const{return angularVelocity;}
			Vector3D Solid::Force() const{return force;}
			Vector3D Solid::Momentum() const{return momentum;}
			double Solid::Mass() const{return mass;}

			void Solid::LoadFromIstream(istream & in){
				in >> b >> velocity >> angularVelocity >> force >> momentum >> mass;
			}

			ostream & operator << (ostream & out, Solid const& a){
				out << a.B() << a.Velocity() << a.AngularVelocity() << a.Force() << a.Momentum() << a.Mass();
				return out;
			}

			istream & operator >> (istream & in, Solid & a){
				a.LoadFromIstream(in);
				return in;
			}

		}
	}
}
