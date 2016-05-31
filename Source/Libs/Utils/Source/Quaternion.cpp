
#include <Utils/Vector.h>
#include "../../Utils/Include/Utils/Quaternion.h"

#include <iostream>
#include <cmath>

#define precision 1E-15

namespace Luga {
	namespace Meca {
		namespace Utils{

			Quaternion::Quaternion() {
				componantReal = 1.0;
				componantI = componantJ = componantK = 0.0;
			}

			Quaternion::Quaternion(double q0, double q1, double q2, double q3){
				this->componantReal = q0;
				this->componantI = q1;
				this->componantJ = q2;
				this->componantK = q3;
			}

			Quaternion::Quaternion(const Vector & w){
				double a = w.Norme();
				if(a != 0){
					double sa = sin(a/2);
					double ca = cos(a/2);
					componantReal = ca;
					componantI = w.ComponantX()/a*sa;
					componantJ = w.ComponantY()/a*sa;
					componantK = w.ComponantZ()/a*sa;
				}
			}

			Quaternion::~Quaternion(){

			}

			double Quaternion::ComponantReal() const{return componantReal;}
			double Quaternion::ComponantI() const{return componantI;}
			double Quaternion::ComponantJ() const{return componantJ;}
			double Quaternion::ComponantK() const{return componantK;}

			double Quaternion::Norme(){
				return sqrt(componantReal*componantReal+componantI*componantI+componantJ*componantJ+componantK*componantK);
			}

			void Quaternion::Normalize(){
				double n = Norme();
				if(n != 0){
					componantReal /= n;
					componantI /= n;
					componantJ /= n;
					componantK /= n;
				}
			}

			void Quaternion::SetComponants(double q0, double q1, double q2, double q3){
				this->componantReal = q0;
				this->componantI = q1;
				this->componantJ = q2;
				this->componantK = q3;
			}

			Quaternion Quaternion::Product(const Quaternion & b) const{
				Quaternion a = *this;
				a.componantReal = this->componantReal*b.ComponantReal() - this->componantI*b.ComponantI() - this->componantJ*b.ComponantJ() - this->componantK*b.ComponantK();
				a.componantI = this->componantReal*b.ComponantI() + this->componantI*b.ComponantReal() - this->componantJ*b.ComponantK() + this->componantK*b.ComponantJ();
				a.componantJ = this->componantReal*b.ComponantJ() + this->componantI*b.ComponantK() + this->componantJ*b.ComponantReal() - this->componantK*b.ComponantI();
				a.componantK = this->componantReal*b.ComponantK() - this->componantI*b.ComponantJ() + this->componantJ*b.ComponantI() + this->componantK*b.ComponantReal();
				return a;
			}


			Quaternion Quaternion::Sum(const Quaternion & b) const{
				Quaternion a = *this;
				a.componantReal += b.ComponantReal();
				a.componantI += b.ComponantI();
				a.componantJ += b.ComponantJ();
				a.componantK += b.ComponantK();
				return a;
			}

			Quaternion Quaternion::Diff(const Quaternion & b) const{
				Quaternion a = *this;
				a.componantReal -= b.ComponantReal();
				a.componantI -= b.ComponantI();
				a.componantJ -= b.ComponantJ();
				a.componantK -= b.ComponantK();
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
				a.componantI *= -1;
				a.componantJ *= -1;
				a.componantK *= -1;
				return a;
			}

			void Quaternion::operator*=(Quaternion const& b){
				double p0 = this->componantReal*b.ComponantReal() - this->componantI*b.ComponantI() - this->componantJ*b.ComponantJ() - this->componantK*b.ComponantK();
				double p1 = this->componantReal*b.ComponantI() + this->componantI*b.ComponantReal() - this->componantJ*b.ComponantK() + this->componantK*b.ComponantJ();
				double p2 = this->componantReal*b.ComponantJ() + this->componantI*b.ComponantK() + this->componantJ*b.ComponantReal() - this->componantK*b.ComponantI();
				double p3 = this->componantReal*b.ComponantK() - this->componantI*b.ComponantJ() + this->componantJ*b.ComponantI() + this->componantK*b.ComponantReal();
				componantReal = p0;
				componantI = p1;
				componantJ = p2;
				componantK = p3;
			}

			void Quaternion::operator+=(Quaternion const& b){
				componantReal += b.ComponantReal();
				componantI += b.ComponantI();
				componantJ += b.ComponantJ();
				componantK += b.ComponantK();
			}

			void Quaternion::operator-=(Quaternion const& b){
				componantReal -= b.ComponantReal();
				componantI -= b.ComponantI();
				componantJ -= b.ComponantJ();
				componantK -= b.ComponantK();
			}

			std::istream & operator >> (std::istream & in, Quaternion & a){
				double q0,q1,q2,q3;
				in >> q0 >> q1 >> q2 >> q3;
				a.SetComponants(q0,q1,q2,q3);
				return in;
			}

			std::ostream & operator << (std::ostream & out, Quaternion const& a){
				out << std::scientific << std::setprecision(15);
				out << a.ComponantReal() << " " << a.ComponantI() << " " << a.ComponantJ() << " " << a.ComponantK();
				return out;
			}
		}
	}
}
