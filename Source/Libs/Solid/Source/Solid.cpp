
#include <iostream>
#include <cmath>
#include "../Include/Solid/Solid.h"

#define precision 1E-15

using namespace std;

namespace Meca {
	namespace Libs {
		namespace Basis{

			Solid::Solid():b(),velocity(0,0,0),angularVelocity(0,0,0),force(0,0,0),momentum(0,0,0),inertia(){
				mass = 1;
			}

			Solid::~Solid(){

			}

			Basis Solid::B() const{return b;}
			Vector3D Solid::Velocity() const{return velocity;}
			Vector3D Solid::AngularVelocity() const{return angularVelocity;}
			Vector3D Solid::Force() const{return force;}
			Vector3D Solid::Momentum() const{return momentum;}
			Matrix3x3 Solid::Inertia() const{return inertia;}
			double Solid::Mass() const{return mass;}


			void Solid::B(Basis & b){this->b = b;}
			void Solid::Velocity(Vector3D & v) {this->velocity = v;}
			void Solid::AngularVelocity(Vector3D w) {this->angularVelocity = w;}
			void Solid::Force(Vector3D f) {this->force = f;}
			void Solid::Momentum(Vector3D m) {this->momentum = m;}
			void Solid::Inertia(Matrix3x3 i) {this->inertia = i;}
			void Solid::Mass(double m) {this->mass = m;}


			void Solid::LoadFromIstream(istream & in){
				in >> b >> velocity >> angularVelocity >> force >> momentum >> inertia >> mass;
			}

			ostream & operator << (ostream & out, Solid const& a){
				out << a.B() << a.Velocity() << a.AngularVelocity() << a.Force() << a.Momentum() << a.Inertia() << a.Mass();
				return out;
			}

			istream & operator >> (istream & in, Solid & a){
				a.LoadFromIstream(in);
				return in;
			}

		}
	}
}
