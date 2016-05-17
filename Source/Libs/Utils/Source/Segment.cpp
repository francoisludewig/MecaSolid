#include <Utils/Segment.h>
#include <Utils/Line.h>
#include <iostream>
#include <cmath>

#define precision 1E-15

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			Segment::Segment():a(),b(1,0,0){
			}

			Segment::Segment(Point a, Point b):a(a),b(b){
			}

			Segment::~Segment(){
			}

			Point Segment::A() const{
				return a;
			}

			Point Segment::B() const{
				return b;
			}

			void Segment::SetA(Point a){
				this->a = a;
			}
			void Segment::SetB(Point b){
				this->b = b;
			}

			Line Segment::GetLine(){
				return Line(a,b-a);
			}

			ostream & operator << (ostream & out, Segment const& a){
				out << scientific << setprecision(15);
				out << a.A() << " " << a.B();
				return out;
			}

			istream & operator >> (istream & in, Segment & a){
				Point x,y;
				in >> x >> y;
				a.SetA(x);
				a.SetB(y);
				return in;
			}

		}
	}
}
