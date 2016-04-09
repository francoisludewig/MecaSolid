
#include <iostream>
#include <cmath>
#include "../Include/Basis/Basis.h"

#define precision 1E-15

using namespace std;


namespace Meca {
	namespace Libs {
		namespace Basis{

			Basis::Basis():o(),e1(1,0,0),e2(0,1,0),e3(0,0,1),q(){

			}

			Basis::~Basis(){

			}

			Vector3D Basis::O() const{
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

			void Basis::O(Vector3D o){
				this->o = o;
			}

			void Basis::Q(Quaternion q){
				this->q = q;
				UpdateEFromQ();
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
				UpdateEFromQ();
			}

			void Basis::Translate(Vector3D const & o){
				this->o += o;
			}

			void Basis::LoadFromIstream(istream & in){
				in >> o;
				in >> q;
				UpdateEFromQ();
			}

			void Basis::UpdateEFromQ(){
				e1.SetValue(1 - 2*q.Q2()*q.Q2() - 2*q.Q3()*q.Q3(),
							2*q.Q1()*q.Q2() + 2*q.Q3()*q.Q0(),
							2*q.Q1()*q.Q3() - 2*q.Q2()*q.Q0());

				e2.SetValue(2*q.Q1()*q.Q2() - 2*q.Q3()*q.Q0(),
							1 - 2*q.Q1()*q.Q1() - 2*q.Q3()*q.Q3(),
							2*q.Q2()*q.Q3() + 2*q.Q1()*q.Q0());


				e3.SetValue(2*q.Q1()*q.Q3() + 2*q.Q2()*q.Q0(),
							2*q.Q2()*q.Q3() - 2*q.Q1()*q.Q0(),
							1 - 2*q.Q2()*q.Q2() - 2*q.Q1()*q.Q1());
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

			ostream & operator << (ostream & out, Basis const& a){
				out << a.O() << "\t" << a.Q();
				return out;
			}

			istream & operator >> (istream & in, Basis & a){
				a.LoadFromIstream(in);
				return in;
			}

		}
	}
}
