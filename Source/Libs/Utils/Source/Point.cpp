#include "../../Utils/Include/Utils/Point.h"
#include "../../Utils/Include/Utils/Vector3D.h"

#include <iostream>
#include <cmath>

#define precision 1E-15

using namespace std;

/*! \class Point
	\brief In order to represent Inertia matrix
*/

namespace Luga {
	namespace Meca {
		namespace Utils{


			Point::Point():x(0),y(0),z(0){
			}

			Point::Point(double x, double y, double z):x(x),y(y),z(z){

			}

			Point::~Point(){
			}

			double Point::X() const{return x;}
			double Point::Y() const{return y;}
			double Point::Z() const{return z;}

			void Point::SetValue(double x, double y, double z){
				this->x = x;
				this->y = y;
				this->z = z;
			}

			void Point::Add(Vector3D const & a){
				x += a.X();
				y += a.Y();
				z += a.Z();
			}

			Point Point::operator+(Vector3D const &b){
				return Point(b.X()+x,b.Y()+y,b.Z()+z);
			}

			Vector3D Point::operator-(Point const &b){
				return Vector3D(x-b.X(),y-b.Y(),z-b.Z());
			}

			void Point::operator+=(Vector3D const& a){
				Add(a);
			}

			ostream & operator << (ostream & out, Point const& a){
				out << scientific << setprecision(15);
				out << a.X() << " " << a.Y() << " " << a.Z();
				return out;
			}

			istream & operator >> (istream & in, Point & a){
				double x,y,z;
				in >> x >> y >> z;
				a.SetValue(x,y,z);
				return in;
			}

		}
	}
}
