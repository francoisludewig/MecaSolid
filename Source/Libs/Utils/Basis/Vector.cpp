/*
 * Vector3D.cpp
 *
 *  Created on: 13 mars 2016
 *      Author: ludewigfrancois
 */

#include "../Basis/Vector.h"
#include "DoubleComparison.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include "../Exceptions/Error.h"

#define epsilon std::numeric_limits<double>::epsilon()

namespace Luga {
	namespace Meca {
		namespace Utils{

			Vector::Vector() {
				componantX = componantY = componantZ = 0.0;
			}

			Vector::Vector(double x,double y, double z){
				this->componantX = x;
				this->componantY = y;
				this->componantZ = z;
			}

			Vector::Vector(int basisId) {
				componantX = componantY = componantZ = 0.0;
				Id(basisId);
			}

			Vector::Vector(double x,double y, double z,int basisId){
				this->componantX = x;
				this->componantY = y;
				this->componantZ = z;
				Id(basisId);
			}

			Vector::~Vector() {
			}

			void Vector::SetComponants(double x, double y, double z){
				this->componantX = x;
				this->componantY = y;
				this->componantZ = z;
			}

			double Vector::Norme() const{
				return sqrt(componantX*componantX+componantY*componantY+componantZ*componantZ);
			}

			void Vector::Normalize(){
				double n = Norme();
				if(n != 0){
					componantX /= n;
					componantY /= n;
					componantZ /= n;
				}
			}

			double Vector::ScalarProduct(const Vector & b) const {
				if(this->Id() != b.Id())
					throw(Error(0,"Scalar product of vectors from different basis !",0));
				double ps = (this->componantX*b.ComponantX()+this->componantY*b.ComponantY()+this->componantZ*b.ComponantZ());
				return ps;
			}

			Vector Vector::Product(const double & b) const{
				Vector a = *this;
				a.componantX *= b;
				a.componantY *= b;
				a.componantZ *= b;
				return a;
			}

			Vector Vector::Division(const double & b) const{
				if(b == 0)
					throw(Error(1,"Dividing by 0 !",0));
				Vector a = *this;
				a.componantX /= b;
				a.componantY /= b;
				a.componantZ /= b;
				return a;
			}

			Vector Vector::Sum(const Vector & b) const{
				if(this->Id() != b.Id())
					throw(Error(0,"Summing vectors from different basis !",0));
				Vector a = *this;
				a.componantX += b.componantX;
				a.componantY += b.componantY;
				a.componantZ += b.componantZ;
				return a;
			}

			Vector Vector::Difference(const Vector & b) const{
				if(this->Id() != b.Id())
					throw(Error(0,"Differencing vectors from different basis !",0));
				Vector a = *this;
				a.componantX -= b.componantX;
				a.componantY -= b.componantY;
				a.componantZ -= b.componantZ;
				return a;
			}

			Vector Vector::CrossProduct(const Vector& b) const {
				if(this->Id() != b.Id())
					throw(Error(0,"Cross product of vectors from different basis !",0));
				Vector a = *this;
				a.componantX = (componantY*b.componantZ-componantZ*b.componantY);
				a.componantY = (componantZ*b.componantX-componantX*b.componantZ);
				a.componantZ = (componantX*b.componantY-componantY*b.componantX);
				return a;
			}

			void Vector::operator+=(Vector const& a){
				if(this->Id() != a.Id())
					throw(Error(0,"Summing vectors from different basis !",0));
				componantX += a.componantX;
				componantY += a.componantY;
				componantZ += a.componantZ;
			}

			void Vector::operator-=(Vector const& a){
				if(this->Id() != a.Id())
					throw(Error(0,"Differencing vectors from different basis !",0));
				componantX -= a.componantX;
				componantY -= a.componantY;
				componantZ -= a.componantZ;
			}

			void Vector::operator*=(double const& a){
				componantX *= a;
				componantY *= a;
				componantZ *= a;
			}

			void Vector::operator/=(double const& a){
				if(a == 0)
					throw(Error(1,"Dividing by 0 !",0));
				componantX /= a;
				componantY /= a;
				componantZ /= a;
			}

			double Vector::operator*(Vector const &b) const{
				return this->ScalarProduct(b);
			}

			Vector Vector::operator^(Vector const &b) const{
				return this->CrossProduct(b);
			}

			Vector Vector::operator*(double const &b) const{
				return this->Product(b);
			}

			Vector Vector::operator/(double const &b) const{
				return this->Division(b);
			}

			Vector Vector::operator+(Vector const &b) const{
				return this->Sum(b);
			}

			Vector Vector::operator-(Vector const &b) const{
				return this->Difference(b);
			}

			std::ostream & operator << (std::ostream & out, Vector const& a){
				out << std::scientific << std::setprecision(15);
				out << a.ComponantX() << " " << a.ComponantY() << " " << a.ComponantZ();
				return out;
			}

			std::istream & operator >> (std::istream & in, Vector & a){
				double x,y,z;
				in >> x >> y >> z;
				a.SetComponants(x,y,z);
				return in;
			}

			Vector operator*(const double & b, Vector const & a){
				return a.Product(b);

			}

			bool operator== (Vector const &vector1, Vector const &vector2){
				if(!DoubleComparison::IsEqual(vector1.ComponantX(),vector2.ComponantX()))
					return false;
				if(!DoubleComparison::IsEqual(vector1.ComponantY(),vector2.ComponantY()))
					return false;
				if(!DoubleComparison::IsEqual(vector1.ComponantZ(),vector2.ComponantZ()))
					return false;
				return true;
			}

			bool operator!= (Vector const &vector1, Vector const &vector2){
				return !(vector1==vector2);
			}

		} /* namespace Basis */
	} /* namespace Libs */
} /* namespace Meca */


