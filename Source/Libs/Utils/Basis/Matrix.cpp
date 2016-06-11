#include "../Basis/Matrix.h"

#include <iostream>
#include <cmath>
#include <cassert>

#include "../Exceptions/Error.h"

#define precision 1E-15

/*! \class Matrix
	\brief In order to represent Inertia matrix
*/

namespace Luga {
	namespace Meca {
		namespace Utils{

			Matrix::Matrix() : BasisId(){
				element[0][0] = 1; element[0][1] = 0; element[0][2] = 0;
			 	element[1][0] = 0; element[1][1] = 1; element[1][2] = 0;
				element[2][0] = 0; element[2][1] = 0; element[2][2] = 1;
			}

			Matrix::~Matrix(){

			}

			Matrix::Matrix(const double & m00, const double & m01, const double & m02,
					  	   const double & m10, const double & m11, const double & m12,
						   const double & m20, const double & m21, const double & m22) : BasisId(){
				element[0][0] = m00; element[0][1] = m01; element[0][2] = m02;
				element[1][0] = m10; element[1][1] = m11; element[1][2] = m12;
				element[2][0] = m20; element[2][1] = m21; element[2][2] = m22;
			}


			void Matrix::Element(const int & i, const int & j , const double & c){
				element[i][j] = c;
			}

			double Matrix::Element(const int & i, const int & j) const{
				return element[i][j];
			}

			Vector Matrix::Line(const int & i) const{
				return Vector(element[i][0],element[i][1],element[i][2]);
			}

			Vector Matrix::Column(const int & i) const{
				return Vector(element[0][i],element[1][i],element[2][i]);
			}

			void Matrix::Line(const int & i, const Vector & l){
				element[i][0] = l.ComponantX();
				element[i][1] = l.ComponantY();
				element[i][2] = l.ComponantZ();
			}

			void Matrix::Column(const int & i, const Vector & c){
				element[0][i] = c.ComponantX();
				element[1][i] = c.ComponantY();
				element[2][i] = c.ComponantZ();
			}

			double Matrix::Determinant() const{
				return element[0][0]*element[1][1]*element[2][2] + element[0][1]*element[1][2]*element[2][0] + element[0][2]*element[1][0]*element[2][1]
			  - element[0][2]*element[1][1]*element[2][0] - element[1][2]*element[2][1]*element[0][0] - element[2][2]*element[1][0]*element[0][1];
			}

			Matrix Matrix::MatrixTranspose() const{
				Matrix a;
				Vector raw;
				for(int i = 0 ; i < 3 ; i++){
					raw = Line(i);
					a.Column(i,raw);
				}
				return a;
			}

			Matrix Matrix::MatrixAdjoint()const {
				Matrix a;
				a.Element(0,0,(element[1][1]*element[2][2]-element[1][2]*element[2][1]));
				a.Element(0,1,-(element[1][0]*element[2][2]-element[1][2]*element[2][0]));
				a.Element(0,2,(element[1][0]*element[2][1]-element[1][1]*element[2][0]));

				a.Element(1,0,-(element[0][1]*element[2][2]-element[0][2]*element[2][1]));
				a.Element(1,1,(element[0][0]*element[2][2]-element[0][2]*element[2][0]));
				a.Element(1,2,-(element[0][0]*element[2][1]-element[0][1]*element[2][0]));

				a.Element(2,0,(element[0][1]*element[1][2]-element[0][2]*element[1][1]));
				a.Element(2,1,-(element[0][0]*element[1][2]-element[0][2]*element[1][0]));
				a.Element(2,2,(element[0][0]*element[1][1]-element[1][0]*element[0][1]));
				return a;
			}

			Matrix Matrix::MatrixInverse()const {
				Matrix a;
				double det = Determinant();
				if(det != 0){
					a = MatrixAdjoint().MatrixTranspose();
				}
				a /= det;
				return a;
			}

			Matrix Matrix::Product(const double & b) const{
				Matrix a = *this;
				for(int i = 0 ; i < 3 ; i++)
					for(int j = 0 ; j < 3 ; j++)
						a.Element(i,j,a.Element(i,j)*b);
				return a;
			}

			Matrix Matrix::Div(const double & b) const{
				if(b == 0)
					throw(Error(1,"Dividing by 0 !",0));
				Matrix a = *this;
				for(int i = 0 ; i < 3 ; i++)
					for(int j = 0 ; j < 3 ; j++)
						a.Element(i,j,a.Element(i,j)/b);
				return a;
			}

			void Matrix::operator*=(const double & a){
				for(int i = 0 ; i < 3 ; i++)
					for(int j = 0 ; j < 3 ; j++)
						element[i][j]*=a;
			}

			void Matrix::operator/=(const double & a){
				if(a == 0)
					throw(Error(1,"Dividing by 0 !",0));
				for(int i = 0 ; i < 3 ; i++)
					for(int j = 0 ; j < 3 ; j++)
						element[i][j]/=a;
			}

			Matrix Matrix::operator*(const double &b) const {
				Matrix a = *this;
				a.Product(b);
				return a;
			}

			Vector Matrix::operator*(const Vector &b)const{
				Vector a;
				a.ComponantX(element[0][0]*b.ComponantX() + element[0][1]*b.ComponantY() + element[0][2]*b.ComponantZ());
				a.ComponantY(element[1][0]*b.ComponantX() + element[1][1]*b.ComponantY() + element[1][2]*b.ComponantZ());
				a.ComponantZ(element[2][0]*b.ComponantX() + element[2][1]*b.ComponantY() + element[2][2]*b.ComponantZ());
				return a;
			}

			Matrix Matrix::operator/(const double &b) const{
				if(b == 0)
					throw(Error(1,"Dividing by 0 !",0));
				Matrix a = *this;
				a.Div(b);
				return a;
			}

			std::ostream & operator << (std::ostream & out, const Matrix & a){
				out << std::scientific << std::setprecision(15);
				for(int i = 0 ; i < 3 ; i++){
					for(int j = 0 ; j < 3 ; j++){
						out << a.Element(i,j) << " ";
					}
					out << "\n";
				}
				return out;
			}

			std::istream & operator >> (std::istream & in, Matrix & a){
				double c;
				for(int i = 0 ; i < 3 ; i++){
					for(int j = 0 ; j < 3 ; j++){
						in >> c;
						a.Element(i,j,c);
					}
				}
				return in;
			}

		}
	}
}
