
#include <iostream>
#include <cmath>
#include "../Include/Utils/Basis.h"

#define precision 1E-15

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			Basis::Basis():o(),e1(1,0,0),e2(0,1,0),e3(0,0,1),q(){

			}

			Basis::~Basis(){

			}

			Point Basis::O() const{
				return o;
			}

			Vector3D Basis::E1() const{
				return e1;
			}

			Vector3D Basis::E2() const{
				return e2;
			}

			Vector3D Basis::E3() const{
				return e3;
			}

			Quaternion Basis::Q() const{
				return q;
			}

			void Basis::O(Point & o){
				this->o = o;
			}

			void Basis::Q(Quaternion & q){
				this->q = q;
				vQc.ConvertQuaternionIntoVectors(q,e1,e2,e3);
			}

			void Basis::E1(Vector3D & e1){
				e1.Normalize();
				this->e1 = e1;
				this->ConstructE2AndE3FromE1();
			}

			void Basis::Local(Vector3D & a){
				double x,y,z;
				x = a*e1;
				y = a*e2;
				z = a*e3;
				a.SetValue(x,y,z);
			}

			void Basis::Global(Vector3D & a){
				a = a.X()*e1 + a.Y()*e2 + a.Z()*e3;
			}

			void Basis::Rotate(Quaternion const & q){
				this->q *= q;
				vQc.ConvertQuaternionIntoVectors(this->q,e1,e2,e3);
			}

			void Basis::Translate(Vector3D const & o){
				this->o += o;
			}

			void Basis::LoadFromIstream(istream & in){
				in >> o;
				in >> q;
				vQc.ConvertQuaternionIntoVectors(q,e1,e2,e3);
			}

			Basis Basis::operator*(Quaternion const & q){
				Basis b = *this;
				b.Rotate(q);
				return b;
			}

			Basis Basis::operator+(Vector3D const & o){
				Basis b = *this;
				b.Translate(o);
				return b;
			}

			void Basis::operator*=(Quaternion const& q){
				this->Rotate(q);
			}

			void Basis::operator+=(Vector3D const& o){
				this->Translate(o);
			}

			void Basis::ConstructE2AndE3FromE1(){
				if((e1.X() != 0 || e1.Y() != 0) || (e1.X() != 0 || e1.Z() != 0)  || (e1.Y() != 0 || e1.Z() != 0)){
					e2.X(e1.Y()*e1.Z());
					e2.Y(e1.X()*e1.Z());
					e2.Z(-2*e1.X()*e1.Y());
				}
				else{
					if(e1.X() == 0 || e1.Y() == 0){
						e2.X(e1.Z());
						e2.Y(0);
						e2.Z(0);
					}
					else if(e1.X() == 0 || e1.Z() == 0){
						e2.X(0);
						e2.Y(0);
						e2.Z(e1.Y());
					}
					else if(e1.Y() == 0 || e1.Z() == 0){
						e2.X(0);
						e2.Y(e1.X());
						e2.Z(0);
					}
				}
				e2.Normalize();
				e3 = e1^e2;
			  	vQc.ConvertVectorsIntoQuaternion(e1,e2,e3,q);
			}

			ostream & operator << (ostream & out, Basis const& a){
				out << a.O() << " " << a.Q();
				return out;
			}

			istream & operator >> (istream & in, Basis & a){
				a.LoadFromIstream(in);
				return in;
			}

		}
	}
}
