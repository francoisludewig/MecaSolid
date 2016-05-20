/*
 * Vector3D.cpp
 *
 *  Created on: 13 mars 2016
 *      Author: ludewigfrancois
 */

#include "../../Utils/Include/Utils/Vector3D.h"

#include <iostream>
#include <cmath>

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			Vector3D::Vector3D() {
				x = y = z = 0.0;
			}

			Vector3D::Vector3D(double x,double y, double z){
				this->x = x;
				this->y = y;
				this->z = z;
			}

			Vector3D::~Vector3D() {
			}

			void Vector3D::SetValue(double x, double y, double z){
				this->x = x;
				this->y = y;
				this->z = z;
			}

			double Vector3D::Norme() const{
				return sqrt(x*x+y*y+z*z);
			}

			void Vector3D::Normalize(){
				double n = Norme();
				x /= n;
				y /= n;
				z /= n;
			}

			double Vector3D::ScalarProduct(const Vector3D & b) const {
				double ps = (this->x*b.X()+this->y*b.Y()+this->z*b.Z());
				return ps;
			}

			Vector3D Vector3D::Product(const double & b) const{
				Vector3D a = *this;
				a.x *= b;
				a.y *= b;
				a.z *= b;
				return a;
			}

			Vector3D Vector3D::Div(const double & b) const{
				Vector3D a = *this;
				a.x /= b;
				a.y /= b;
				a.z /= b;
				return a;
			}

			Vector3D Vector3D::Sum(const Vector3D & b) const{
				Vector3D a = *this;
				a.x += b.x;
				a.y += b.y;
				a.z += b.z;
				return a;
			}
			Vector3D Vector3D::Diff(const Vector3D & b) const{
				Vector3D a = *this;
				a.x -= b.x;
				a.y -= b.y;
				a.z -= b.z;
				return a;
			}

			Vector3D Vector3D::VectorialProduct(const Vector3D& b) const {
				Vector3D a = *this;
				a.x = (y*b.z-z*b.y);
				a.y = (z*b.x-x*b.z);
				a.z = (x*b.y-y*b.x);
				return a;
			}

			void Vector3D::operator+=(Vector3D const& a){
				x += a.x;
				y += a.y;
				z += a.z;
			}

			void Vector3D::operator-=(Vector3D const& a){
				x -= a.x;
				y -= a.y;
				z -= a.z;
			}

			void Vector3D::operator*=(double const& a){
				x *= a;
				y *= a;
				z *= a;
			}

			void Vector3D::operator/=(double const& a){
				x /= a;
				y /= a;
				z /= a;
			}

			double Vector3D::operator*(Vector3D const &b){
				return this->ScalarProduct(b);
			}

			Vector3D Vector3D::operator^(Vector3D const &b){
				return this->VectorialProduct(b);
			}

			Vector3D Vector3D::operator*(double const &b){
				return this->Product(b);
			}

			Vector3D Vector3D::operator/(double const &b){
				return this->Div(b);
			}

			Vector3D Vector3D::operator+(Vector3D const &b){
				return this->Sum(b);
			}

			Vector3D Vector3D::operator-(Vector3D const &b){
				return this->Diff(b);
			}

			ostream & operator << (ostream & out, Vector3D const& a){
				out << scientific << setprecision(15);
				out << a.X() << " " << a.Y() << " " << a.Z();
				return out;
			}

			istream & operator >> (istream & in, Vector3D & a){
				double x,y,z;
				in >> x >> y >> z;
				a.SetValue(x,y,z);
				return in;
			}

			Vector3D operator*(const double & b, Vector3D const & a){
				return a.Product(b);
			}

		} /* namespace Basis */
	} /* namespace Libs */
} /* namespace Meca */


