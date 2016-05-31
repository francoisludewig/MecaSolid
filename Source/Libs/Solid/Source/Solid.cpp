
#include <iostream>
#include <cmath>
#include "../Include/Solid/Solid.h"

#define precision 1E-15

using namespace Luga::Meca::Utils;

namespace Luga {
	namespace Meca {
		namespace Solid{

			Solid::Solid():b(),velocity(0,0,0),angularVelocity(0,0,0),force(0,0,0),momentum(0,0,0),inertia(){
				mass = 1;
			}

			Solid::~Solid(){

			}

			Basis Solid::B() const{return b;}
			Vector Solid::Velocity() const{return velocity;}
			Vector Solid::AngularVelocity() const{return angularVelocity;}
			Vector Solid::Force() const{return force;}
			Vector Solid::Momentum() const{return momentum;}
			Matrix Solid::Inertia() const{return inertia;}
			double Solid::Mass() const{return mass;}


			void Solid::B(Basis & b){this->b = b;}
			void Solid::Velocity(Vector & v) {this->velocity = v;}
			void Solid::AngularVelocity(Vector w) {this->angularVelocity = w;}
			void Solid::Force(Vector f) {this->force = f;}
			void Solid::Momentum(Vector m) {this->momentum = m;}
			void Solid::Inertia(Matrix i){
				this->inertia = i;
				this->interia_1 = inertia.MatrixInverse();
			}
			void Solid::Mass(double m) {this->mass = m;}


			void Solid::UpdateVelocities(double dt){
				velocity += dt*force/mass;
				localMomentum = momentum;
				b.Local(localMomentum);
				angularVelocity += dt*(interia_1*localMomentum);
			}

			void Solid::UpdatePosition(double dt){
				b += dt*velocity;
				b*= Quaternion(angularVelocity*dt);
			}

			void Solid::ResetForceAndMomemtum(){
				force.SetComponants(0,0,0);
				momentum.SetComponants(0,0,0);
			}

			void Solid::LoadFromIstream(std::istream & in){
				in >> b >> velocity >> angularVelocity >> force >> momentum >> inertia >> mass;
			}

			std::ostream & operator << (std::ostream & out, Solid const& a){
				out << a.B() << " " << a.Velocity() << " " << a.AngularVelocity() << " " << a.Force() << " " << a.Momentum() << " " << a.Inertia() << " " << a.Mass();
				return out;
			}

			std::istream & operator >> (std::istream & in, Solid & a){
				a.LoadFromIstream(in);
				return in;
			}

		}
	}
}
