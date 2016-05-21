#include "../../Utils/Include/Utils/Matrix3x3.h"

#include <iostream>
#include <cmath>

#define precision 1E-15

using namespace std;

/*! \class Matrix3x3
	\brief In order to represent Inertia matrix
*/

namespace Luga {
	namespace Meca {
		namespace Utils{

			Matrix3x3::Matrix3x3(){
				element[0][0] = 1; element[0][1] = 0; element[0][2] = 0;
			 	element[1][0] = 0; element[1][1] = 1; element[1][2] = 0;
				element[2][0] = 0; element[2][1] = 0; element[2][2] = 1;
			}

			Matrix3x3::~Matrix3x3(){

			}

			Matrix3x3::Matrix3x3(double m00, double m01,double m02,
					  double m10, double m11,double m12,
					  double m20, double m21,double m22){
				element[0][0] = m00; element[0][1] = m01; element[0][2] = m02;
				element[1][0] = m10; element[1][1] = m11; element[1][2] = m12;
				element[2][0] = m20; element[2][1] = m21; element[2][2] = m22;
			}


			void Matrix3x3::Element(int i, int j , double c){
				element[i][j] = c;
			}

			double Matrix3x3::Element(int i, int j) const{
				return element[i][j];
			}

			Vector3D Matrix3x3::Line(int i) const{
				return Vector3D(element[i][0],element[i][1],element[i][2]);
			}

			Vector3D Matrix3x3::Column(int i) const{
				return Vector3D(element[0][i],element[1][i],element[2][i]);
			}

			void Matrix3x3::Line(int i, Vector3D & l){
				element[i][0] = l.ComponantX();
				element[i][1] = l.ComponantY();
				element[i][2] = l.ComponantZ();
			}

			void Matrix3x3::Column(int i, Vector3D & c){
				element[0][i] = c.ComponantX();
				element[1][i] = c.ComponantY();
				element[2][i] = c.ComponantZ();
			}

			double Matrix3x3::Determinant() const{
				return element[0][0]*element[1][1]*element[2][2] + element[0][1]*element[1][2]*element[2][0] + element[0][2]*element[1][0]*element[2][1]
			  - element[0][2]*element[1][1]*element[2][0] - element[1][2]*element[2][1]*element[0][0] - element[2][2]*element[1][0]*element[0][1];
			}

			Matrix3x3 Matrix3x3::MatrixTranspose(){
				Matrix3x3 a;
				Vector3D raw;
				for(int i = 0 ; i < 3 ; i++){
					raw = Line(i);
					a.Column(i,raw);
				}
				return a;
			}

			Matrix3x3 Matrix3x3::MatrixAdjoint(){
				Matrix3x3 a;
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

			Matrix3x3 Matrix3x3::MatrixInverse(){
				Matrix3x3 a;
				double det = Determinant();
				if(det != 0){
					a = MatrixAdjoint().MatrixTranspose();
				}
				a /= det;
				return a;
			}

			Matrix3x3 Matrix3x3::Product(const double & b) const{
				Matrix3x3 a = *this;
				for(int i = 0 ; i < 3 ; i++)
					for(int j = 0 ; j < 3 ; j++)
						a.Element(i,j,a.Element(i,j)*b);
				return a;
			}

			Matrix3x3 Matrix3x3::Div(const double & b) const{
				Matrix3x3 a = *this;
				for(int i = 0 ; i < 3 ; i++)
					for(int j = 0 ; j < 3 ; j++)
						a.Element(i,j,a.Element(i,j)/b);
				return a;
			}

			void Matrix3x3::operator*=(double const& a){
				for(int i = 0 ; i < 3 ; i++)
					for(int j = 0 ; j < 3 ; j++)
						element[i][j]*=a;
			}

			void Matrix3x3::operator/=(double const& a){
				for(int i = 0 ; i < 3 ; i++)
					for(int j = 0 ; j < 3 ; j++)
						element[i][j]/=a;
			}

			Matrix3x3 Matrix3x3::operator*(double const &b){
				return this->Product(b);
			}

			Vector3D Matrix3x3::operator*(Vector3D &b){
				Vector3D a;
				a.ComponantX(element[0][0]*b.ComponantX() + element[0][1]*b.ComponantY() + element[0][2]*b.ComponantZ());
				a.ComponantY(element[1][0]*b.ComponantX() + element[1][1]*b.ComponantY() + element[1][2]*b.ComponantZ());
				a.ComponantZ(element[2][0]*b.ComponantX() + element[2][1]*b.ComponantY() + element[2][2]*b.ComponantZ());
				return a;
			}

			Matrix3x3 Matrix3x3::operator/(double const &b){
				return this->Div(b);
			}

			ostream & operator << (ostream & out, Matrix3x3 const& a){
				out << scientific << setprecision(15);
				for(int i = 0 ; i < 3 ; i++){
					for(int j = 0 ; j < 3 ; j++){
						out << a.Element(i,j) << " ";
					}
					out << "\n";
				}
				return out;
			}

			istream & operator >> (istream & in, Matrix3x3 & a){
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
