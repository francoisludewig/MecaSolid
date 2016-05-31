#include <Utils/Segment.h>
#include <Utils/Vector.h>
#include <iostream>
#include <cmath>

#define precision 1E-15

namespace Luga {
	namespace Meca {
		namespace Utils{

			Point::Point():coordinateX(0),coordinateY(0),coordinateZ(0){
			}

			Point::Point(double x, double y, double z):coordinateX(x),coordinateY(y),coordinateZ(z){

			}

			Point::~Point(){
			}

			double Point::CoordinateX() const{return coordinateX;}
			double Point::CoordinateY() const{return coordinateY;}
			double Point::CoordinateZ() const{return coordinateZ;}

			void Point::SetCoordinates(double x, double y, double z){
				this->coordinateX = x;
				this->coordinateY = y;
				this->coordinateZ = z;
			}

			void Point::Translate(Vector const & a){
				coordinateX += a.ComponantX();
				coordinateY += a.ComponantY();
				coordinateZ += a.ComponantZ();
			}

			Point Point::operator+(Vector const &b) const{
				return Point(b.ComponantX()+coordinateX,b.ComponantY()+coordinateY,b.ComponantZ()+coordinateZ);
			}

			Vector Point::operator-(Point const &b) const{
				return Vector(coordinateX-b.CoordinateX(),coordinateY-b.CoordinateY(),coordinateZ-b.CoordinateZ());
			}

			void Point::operator+=(Vector const& a){
				Translate(a);
			}

			std::ostream & operator << (std::ostream & out, Point const& a){
				out << std::scientific << std::setprecision(15);
				out << a.CoordinateX() << " " << a.CoordinateY() << " " << a.CoordinateZ();
				return out;
			}

			std::istream & operator >> (std::istream & in, Point & a){
				double x,y,z;
				in >> x >> y >> z;
				a.SetCoordinates(x,y,z);
				return in;
			}

		}
	}
}
