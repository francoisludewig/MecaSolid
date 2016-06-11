#include <iostream>
#include <cmath>

#include "../Basis/DoubleComparison.h"
#include "../Basis/Vector.h"
#include "Segment.h"

#define precision 1E-15
#define epsilon std::numeric_limits<double>::epsilon()

namespace Luga {
	namespace Meca {
		namespace Utils{

			Point::Point():coordinateX(0),coordinateY(0),coordinateZ(0){
			}

			Point::Point(const double & x, const double & y, const double & z):coordinateX(x),coordinateY(y),coordinateZ(z){

			}

			Point::~Point(){
			}

			double Point::CoordinateX() const{return coordinateX;}
			double Point::CoordinateY() const{return coordinateY;}
			double Point::CoordinateZ() const{return coordinateZ;}

			void Point::SetCoordinates(const double & x, const double & y, const double & z){
				this->coordinateX = x;
				this->coordinateY = y;
				this->coordinateZ = z;
			}

			void Point::Translate(const Vector & a){
				coordinateX += a.ComponantX();
				coordinateY += a.ComponantY();
				coordinateZ += a.ComponantZ();
			}

			Point Point::operator+(const Vector &b) const{
				return Point(b.ComponantX()+coordinateX,b.ComponantY()+coordinateY,b.ComponantZ()+coordinateZ);
			}

			Vector Point::operator-(const Point &b) const{
				return Vector(coordinateX-b.CoordinateX(),coordinateY-b.CoordinateY(),coordinateZ-b.CoordinateZ());
			}

			void Point::operator+=(const Vector & a){
				Translate(a);
			}

			std::ostream & operator << (std::ostream & out, const Point & a){
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

			bool operator== (Point const &point1, Point const &point2){
				if(!DoubleComparison::IsEqual(point1.CoordinateX(),point2.CoordinateX()))
					return false;
				if(!DoubleComparison::IsEqual(point1.CoordinateY(),point2.CoordinateY()))
					return false;
				if(!DoubleComparison::IsEqual(point1.CoordinateZ(),point2.CoordinateZ()))
					return false;
				return true;
			}

			bool operator!= (Point const &point1, Point const &point2){
				return !(point1==point2);
			}

		}
	}
}
