#include <Utils/Segment.h>
#include <Utils/Line.h>
#include <iostream>
#include <cmath>

#define precision 1E-15

using namespace std;

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

			void Segment::BeginPoint(Point a){
				this->beginPoint = a;
			}
			void Segment::EndPoint(Point b){
				this->endPoint = b;
			}

			Line Segment::AssiociatedLine() const{
				return Line(beginPoint,endPoint-beginPoint);
			}

			ostream & operator << (ostream & out, Segment const& a){
				out << scientific << setprecision(15);
				out << a.BeginPoint() << " " << a.EndPoint();
				return out;
			}

			istream & operator >> (istream & in, Segment & a){
				Point x,y;
				in >> x >> y;
				a.BeginPoint(x);
				a.EndPoint(y);
				return in;
			}

		}
	}
}
