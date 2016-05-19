
#include "../../Utils/Include/Utils/Quaternion.h"

#include <iostream>
#include <cmath>
#include "../../Utils/Include/Utils/Vector3D.h"

#define precision 1E-15

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			Quaternion::Quaternion() {
				q0 = 1.0;
				q1 = q2 = q3 = 0.0;
			}

			Quaternion::Quaternion(double q0, double q1, double q2, double q3){
				this->q0 = q0;
				this->q1 = q1;
				this->q2 = q2;
				this->q3 = q3;
			}

			Quaternion::Quaternion(const Vector3D & w){
				double a = w.Norme();
				double sa = sin(a/2);
				double ca = cos(a/2);
				q0 = ca;
				q1 = w.X()/a*sa;
				q2 = w.Y()/a*sa;
				q3 = w.Z()/a*sa;
			}

			Quaternion::~Quaternion(){

			}

			double Quaternion::Q0() const{return q0;}
			double Quaternion::Q1() const{return q1;}
			double Quaternion::Q2() const{return q2;}
			double Quaternion::Q3() const{return q3;}

			double Quaternion::Norme(){
				return sqrt(q0*q0+q1*q1+q2*q2+q3*q3);
			}

			void Quaternion::Normalize(){
				double n = Norme();
				q0 /= n;
				q1 /= n;
				q2 /= n;
				q3 /= n;
			}

			void Quaternion::SetValue(double q0, double q1, double q2, double q3){
				this->q0 = q0;
				this->q1 = q1;
				this->q2 = q2;
				this->q3 = q3;
			}

			Quaternion Quaternion::Product(const Quaternion & b) const{
				Quaternion a = *this;
				a.q0 = this->q0*b.Q0() - this->q1*b.Q1() - this->q2*b.Q2() - this->q3*b.Q3();
				a.q1 = this->q0*b.Q1() + this->q1*b.Q0() - this->q2*b.Q3() + this->q3*b.Q2();
				a.q2 = this->q0*b.Q2() + this->q1*b.Q3() + this->q2*b.Q0() - this->q3*b.Q1();
				a.q3 = this->q0*b.Q3() - this->q1*b.Q2() + this->q2*b.Q1() + this->q3*b.Q0();
				return a;
			}


			Quaternion Quaternion::Sum(const Quaternion & b) const{
				Quaternion a = *this;
				a.q0 += b.Q0();
				a.q1 += b.Q1();
				a.q2 += b.Q2();
				a.q3 += b.Q3();
				return a;
			}

			Quaternion Quaternion::Diff(const Quaternion & b) const{
				Quaternion a = *this;
				a.q0 -= b.Q0();
				a.q1 -= b.Q1();
				a.q2 -= b.Q2();
				a.q3 -= b.Q3();
				return a;
			}

			Quaternion Quaternion::operator*(Quaternion const &b){
				return this->Product(b);
			}

			Quaternion Quaternion::operator+(Quaternion const &b){
				return this->Sum(b);
			}

			Quaternion Quaternion::operator-(Quaternion const &b){
				return this->Diff(b);
			}


			Quaternion Quaternion::operator~(){
				Quaternion a = *this;
				a.q1 *= -1;
				a.q2 *= -1;
				a.q3 *= -1;
				return a;
			}

			void Quaternion::operator*=(Quaternion const& b){
				double p0 = this->q0*b.Q0() - this->q1*b.Q1() - this->q2*b.Q2() - this->q3*b.Q3();
				double p1 = this->q0*b.Q1() + this->q1*b.Q0() - this->q2*b.Q3() + this->q3*b.Q2();
				double p2 = this->q0*b.Q2() + this->q1*b.Q3() + this->q2*b.Q0() - this->q3*b.Q1();
				double p3 = this->q0*b.Q3() - this->q1*b.Q2() + this->q2*b.Q1() + this->q3*b.Q0();
				q0 = p0;
				q1 = p1;
				q2 = p2;
				q3 = p3;
			}

			void Quaternion::operator+=(Quaternion const& b){
				q0 += b.Q0();
				q1 += b.Q1();
				q2 += b.Q2();
				q3 += b.Q3();
			}

			void Quaternion::operator-=(Quaternion const& b){
				q0 -= b.Q0();
				q1 -= b.Q1();
				q2 -= b.Q2();
				q3 -= b.Q3();
			}

			istream & operator >> (istream & in, Quaternion & a){
				double q0,q1,q2,q3;
				in >> q0 >> q1 >> q2 >> q3;
				a.SetValue(q0,q1,q2,q3);
				return in;
			}

			ostream & operator << (ostream & out, Quaternion const& a){
				out << scientific << setprecision(15);
				out << a.Q0() << " " << a.Q1() << " " << a.Q2() << " " << a.Q3();
				return out;
			}
		}
	}
}
