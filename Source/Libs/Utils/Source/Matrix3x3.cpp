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
				m[0][0] = 1; m[0][1] = 0; m[0][2] = 0;
			 	m[1][0] = 0; m[1][1] = 1; m[1][2] = 0;
				m[2][0] = 0; m[2][1] = 0; m[2][2] = 1;
			}

			Matrix3x3::~Matrix3x3(){

			}

			Matrix3x3::Matrix3x3(double m00, double m01,double m02,
					  double m10, double m11,double m12,
					  double m20, double m21,double m22){
				m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
				m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
				m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
			}


			void Matrix3x3::Componant(int i, int j , double c){
				m[i][j] = c;
			}

			double Matrix3x3::Componant(int i, int j) const{
				return m[i][j];
			}

			Vector3D Matrix3x3::Line(int i) const{
				return Vector3D(m[i][0],m[i][1],m[i][2]);
			}

			Vector3D Matrix3x3::Column(int i) const{
				return Vector3D(m[0][i],m[1][i],m[2][i]);
			}

			void Matrix3x3::Line(int i, Vector3D & l){
				m[i][0] = l.X();
				m[i][1] = l.Y();
				m[i][2] = l.Z();
			}

			void Matrix3x3::Column(int i, Vector3D & c){
				m[0][i] = c.X();
				m[1][i] = c.Y();
				m[2][i] = c.Z();
			}

			double Matrix3x3::Determinant() const{
				return m[0][0]*m[1][1]*m[2][2] + m[0][1]*m[1][2]*m[2][0] + m[0][2]*m[1][0]*m[2][1]
			  - m[0][2]*m[1][1]*m[2][0] - m[1][2]*m[2][1]*m[0][0] - m[2][2]*m[1][0]*m[0][1];
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
				a.Componant(0,0,(m[1][1]*m[2][2]-m[1][2]*m[2][1]));
				a.Componant(0,1,-(m[1][0]*m[2][2]-m[1][2]*m[2][0]));
				a.Componant(0,2,(m[1][0]*m[2][1]-m[1][1]*m[2][0]));

				a.Componant(1,0,-(m[0][1]*m[2][2]-m[0][2]*m[2][1]));
				a.Componant(1,1,(m[0][0]*m[2][2]-m[0][2]*m[2][0]));
				a.Componant(1,2,-(m[0][0]*m[2][1]-m[0][1]*m[2][0]));

				a.Componant(2,0,(m[0][1]*m[1][2]-m[0][2]*m[1][1]));
				a.Componant(2,1,-(m[0][0]*m[1][2]-m[0][2]*m[1][0]));
				a.Componant(2,2,(m[0][0]*m[1][1]-m[1][0]*m[0][1]));
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
						a.Componant(i,j,a.Componant(i,j)*b);
				return a;
			}

			Matrix3x3 Matrix3x3::Div(const double & b) const{
				Matrix3x3 a = *this;
				for(int i = 0 ; i < 3 ; i++)
					for(int j = 0 ; j < 3 ; j++)
						a.Componant(i,j,a.Componant(i,j)/b);
				return a;
			}

			void Matrix3x3::operator*=(double const& a){
				for(int i = 0 ; i < 3 ; i++)
					for(int j = 0 ; j < 3 ; j++)
						m[i][j]*=a;
			}

			void Matrix3x3::operator/=(double const& a){
				for(int i = 0 ; i < 3 ; i++)
					for(int j = 0 ; j < 3 ; j++)
						m[i][j]/=a;
			}

			Matrix3x3 Matrix3x3::operator*(double const &b){
				return this->Product(b);
			}

			Vector3D Matrix3x3::operator*(Vector3D &b){
				Vector3D a;
				a.X(m[0][0]*b.X() + m[0][1]*b.Y() + m[0][2]*b.Z());
				a.Y(m[1][0]*b.X() + m[1][1]*b.Y() + m[1][2]*b.Z());
				a.Z(m[2][0]*b.X() + m[2][1]*b.Y() + m[2][2]*b.Z());
				return a;
			}

			Matrix3x3 Matrix3x3::operator/(double const &b){
				return this->Div(b);
			}

			ostream & operator << (ostream & out, Matrix3x3 const& a){
				out << scientific << setprecision(15);
				for(int i = 0 ; i < 3 ; i++){
					for(int j = 0 ; j < 3 ; j++){
						out << a.Componant(i,j) << " ";
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
						a.Componant(i,j,c);
					}
				}
				return in;
			}

		}
	}
}
