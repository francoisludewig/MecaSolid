
#include <iostream>
#include <cmath>
#include "../Include/Basis/UnitQuaternion.h"
#include "../Include/Basis/Vector3D.h"

#define precision 1E-15

using namespace std;

namespace Meca {
	namespace Libs {
		namespace Basis{

			UnitQuaternion::UnitQuaternion() {
				q0 = 1.0;
				q1 = q2 = q3 = 0.0;
				delayBetweenCheck = 0;
				maximumDelay = 10;
			}

			UnitQuaternion::UnitQuaternion(double q0, double q1, double q2, double q3){
				this->q0 = q0;
				this->q1 = q1;
				this->q2 = q2;
				this->q3 = q3;
				delayBetweenCheck = 0;
				maximumDelay = 10;
				this->Normalize();
			}

			UnitQuaternion::UnitQuaternion(const Vector3D & w){
				double a = w.Norme();
				double sa = sin(a/2);
				double ca = cos(a/2);
				q0 = ca;
				q1 = w.X()/a*sa;
				q2 = w.Y()/a*sa;
				q3 = w.Z()/a*sa;
				delayBetweenCheck = 0;
				maximumDelay = 10;
			}

			UnitQuaternion::~UnitQuaternion(){

			}
			void UnitQuaternion::IncrementDelay(){
				delayBetweenCheck++;
			}

			void UnitQuaternion::Check(){
				if(delayBetweenCheck > maximumDelay)
					Normalize();
			}

			double UnitQuaternion::Q0() const{return q0;}
			double UnitQuaternion::Q1() const{return q1;}
			double UnitQuaternion::Q2() const{return q2;}
			double UnitQuaternion::Q3() const{return q3;}

			void UnitQuaternion::Normalize(){
				double n = sqrt(q0*q0+q1*q1+q2*q2+q3*q3);
				q0 /= n;
				q1 /= n;
				q2 /= n;
				q3 /= n;
				delayBetweenCheck = 0;
			}


			int UnitQuaternion::DelayBetweenCheck(){
				return delayBetweenCheck;
			}

			double UnitQuaternion::Norme(){
				return sqrt(q0*q0+q1*q1+q2*q2+q3*q3);
			}

			void UnitQuaternion::SetValue(double q0, double q1, double q2, double q3, bool force/* = false*/){
				if(force){
					this->q0 = q0;
					this->q1 = q1;
					this->q2 = q2;
					this->q3 = q3;
					Normalize();
				}
				else{
					this->q0 = q0;
					this->q1 = q1;
					this->q2 = q2;
					this->q3 = q3;
					delayBetweenCheck++;
				}
			}

			UnitQuaternion UnitQuaternion::Product(const UnitQuaternion & b) const{
				UnitQuaternion a = *this;
				a.q0 = this->q0*b.Q0() - this->q1*b.Q1() - this->q2*b.Q2() - this->q3*b.Q3();
				a.q1 = this->q0*b.Q1() + this->q1*b.Q0() - this->q2*b.Q3() + this->q3*b.Q2();
				a.q2 = this->q0*b.Q2() + this->q1*b.Q3() + this->q2*b.Q0() - this->q3*b.Q1();
				a.q3 = this->q0*b.Q3() - this->q1*b.Q2() + this->q2*b.Q1() + this->q3*b.Q0();
				a.IncrementDelay();
				return a;
			}

			UnitQuaternion UnitQuaternion::operator*(UnitQuaternion const &b){
				return this->Product(b);
			}

			UnitQuaternion UnitQuaternion::operator~(){
				UnitQuaternion a = *this;
				a.q1 *= -1;
				a.q2 *= -1;
				a.q3 *= -1;
				return a;
			}

			void UnitQuaternion::operator*=(UnitQuaternion const& b){
				double p0 = this->q0*b.Q0() - this->q1*b.Q1() - this->q2*b.Q2() - this->q3*b.Q3();
				double p1 = this->q0*b.Q1() + this->q1*b.Q0() - this->q2*b.Q3() + this->q3*b.Q2();
				double p2 = this->q0*b.Q2() + this->q1*b.Q3() + this->q2*b.Q0() - this->q3*b.Q1();
				double p3 = this->q0*b.Q3() - this->q1*b.Q2() + this->q2*b.Q1() + this->q3*b.Q0();
				q0 = p0;
				q1 = p1;
				q2 = p2;
				q3 = p3;
				delayBetweenCheck++;
			}


			istream & operator >> (istream & in, UnitQuaternion & a){
				double q0,q1,q2,q3;
				in >> q0 >> q1 >> q2 >> q3;
				a.SetValue(q0,q1,q2,q3,true);
				return in;
			}

			ostream & operator << (ostream & out, UnitQuaternion const& a){
				out << scientific << setprecision(15);
				out << a.Q0() << "\t" << a.Q1() << "\t" << a.Q2() << "\t" << a.Q3();
				return out;
			}
		}
	}
}
