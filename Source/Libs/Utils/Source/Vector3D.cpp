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
				componantX = componantY = componantZ = 0.0;
			}

			Vector3D::Vector3D(double x,double y, double z){
				this->componantX = x;
				this->componantY = y;
				this->componantZ = z;
			}

			Vector3D::Vector3D(int basisId) {
				componantX = componantY = componantZ = 0.0;
				Id(basisId);
			}

			Vector3D::Vector3D(double x,double y, double z,int basisId){
				this->componantX = x;
				this->componantY = y;
				this->componantZ = z;
				Id(basisId);
			}

			Vector3D::~Vector3D() {
			}

			void Vector3D::SetComponants(double x, double y, double z){
				this->componantX = x;
				this->componantY = y;
				this->componantZ = z;
			}

			double Vector3D::Norme() const{
				return sqrt(componantX*componantX+componantY*componantY+componantZ*componantZ);
			}

			void Vector3D::Normalize(){
				double n = Norme();
				componantX /= n;
				componantY /= n;
				componantZ /= n;
			}

			double Vector3D::ScalarProduct(const Vector3D & b) const {
				double ps = (this->componantX*b.ComponantX()+this->componantY*b.ComponantY()+this->componantZ*b.ComponantZ());
				return ps;
			}

			Vector3D Vector3D::Product(const double & b) const{
				Vector3D a = *this;
				a.componantX *= b;
				a.componantY *= b;
				a.componantZ *= b;
				return a;
			}

			Vector3D Vector3D::Division(const double & b) const{
				Vector3D a = *this;
				a.componantX /= b;
				a.componantY /= b;
				a.componantZ /= b;
				return a;
			}

			Vector3D Vector3D::Sum(const Vector3D & b) const{
				Vector3D a = *this;
				if(Id() == b.Id()){
					a.componantX += b.componantX;
					a.componantY += b.componantY;
					a.componantZ += b.componantZ;
				}
				return a;
			}

			Vector3D Vector3D::Difference(const Vector3D & b) const{
				Vector3D a = *this;
				if(Id() == b.Id()){
					a.componantX -= b.componantX;
					a.componantY -= b.componantY;
					a.componantZ -= b.componantZ;
				}
				return a;
			}

			Vector3D Vector3D::VectorialProduct(const Vector3D& b) const {
				Vector3D a = *this;
				if(Id() == b.Id()){
					a.componantX = (componantY*b.componantZ-componantZ*b.componantY);
					a.componantY = (componantZ*b.componantX-componantX*b.componantZ);
					a.componantZ = (componantX*b.componantY-componantY*b.componantX);
				}
				return a;
			}

			void Vector3D::operator+=(Vector3D const& a){
				if(Id() == a.Id()){
					componantX += a.componantX;
					componantY += a.componantY;
					componantZ += a.componantZ;
				}
			}

			void Vector3D::operator-=(Vector3D const& a){
				if(Id() == a.Id()){
					componantX -= a.componantX;
					componantY -= a.componantY;
					componantZ -= a.componantZ;
				}
			}

			void Vector3D::operator*=(double const& a){
				componantX *= a;
				componantY *= a;
				componantZ *= a;
			}

			void Vector3D::operator/=(double const& a){
				componantX /= a;
				componantY /= a;
				componantZ /= a;
			}

			double Vector3D::operator*(Vector3D const &b) const{
				return this->ScalarProduct(b);
			}

			Vector3D Vector3D::operator^(Vector3D const &b) const{
				return this->VectorialProduct(b);
			}

			Vector3D Vector3D::operator*(double const &b) const{
				return this->Product(b);
			}

			Vector3D Vector3D::operator/(double const &b) const{
				return this->Division(b);
			}

			Vector3D Vector3D::operator+(Vector3D const &b) const{
				return this->Sum(b);
			}

			Vector3D Vector3D::operator-(Vector3D const &b) const{
				return this->Difference(b);
			}

			ostream & operator << (ostream & out, Vector3D const& a){
				out << scientific << setprecision(15);
				out << a.ComponantX() << " " << a.ComponantY() << " " << a.ComponantZ();
				return out;
			}

			istream & operator >> (istream & in, Vector3D & a){
				double x,y,z;
				in >> x >> y >> z;
				a.SetComponants(x,y,z);
				return in;
			}

			Vector3D operator*(const double & b, Vector3D const & a){
				return a.Product(b);
			}

		} /* namespace Basis */
	} /* namespace Libs */
} /* namespace Meca */


