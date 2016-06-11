#include "Segment.h"

#include <iostream>
#include <cmath>

#include "Line.h"

#define precision 1E-15

namespace Luga {
	namespace Meca {
		namespace Utils{

			Segment::Segment():beginPoint(),endPoint(1,0,0){
			}

			Segment::Segment(Point a, Point b):beginPoint(a),endPoint(b){
			}

			Segment::~Segment(){
			}

			Point Segment::BeginPoint() const{
				return beginPoint;
			}

			Point Segment::EndPoint() const{
				return endPoint;
			}

			void Segment::BeginPoint(const Point & a){
				this->beginPoint = a;
			}
			void Segment::EndPoint(const Point & b){
				this->endPoint = b;
			}

			Line Segment::AssiociatedLine() const{
				return Line(beginPoint,endPoint-beginPoint);
			}

			std::ostream & operator << (std::ostream & out, const Segment & a){
				out << std::scientific << std::setprecision(15);
				out << a.BeginPoint() << " " << a.EndPoint();
				return out;
			}

			std::istream & operator >> (std::istream & in, Segment & a){
				Point x,y;
				in >> x >> y;
				a.BeginPoint(x);
				a.EndPoint(y);
				return in;
			}

			bool operator== (const Segment &sg1, const Segment &sg2){
				if(sg1.BeginPoint() != sg2.BeginPoint())
					return false;
				if(sg1.EndPoint() != sg2.EndPoint())
					return false;
				return true;
			}

			bool operator!= (const Segment &sg1, const Segment &sg2){
				return !(sg1==sg2);
			}

		}
	}
}
