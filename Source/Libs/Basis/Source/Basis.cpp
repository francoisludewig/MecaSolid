
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
			UnitQuaternion Basis::Q() const{
				return q;
			}


			void Basis::O(Vector3D o){
				this->o = o;
			}

			void Basis::Q(UnitQuaternion q){
				this->q = q;
				UpdateEFromQ();
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
						2*q.Q1()*q.Q1() - 2*q.Q2()*q.Q2());
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
