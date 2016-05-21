#include <Utils/Line.h>
#include <iostream>
#include <cmath>

#define precision 1E-15

using namespace std;


namespace Luga {
	namespace Meca {
		namespace Utils{

			Line::Line():origin(),direction(1./sqrt(3),1./sqrt(3),1./sqrt(3)){

			}

			Line::Line(Point a, Vector3D u):origin(a){
				u /= u.Norme();
				this->direction = u;
			}

			Line::~Line(){}

			Point Line::Origin() const{
				return origin;
			}

			Vector3D Line::Direction() const{
				return direction;
			}

			void Line::Origin(Point a){
				this->origin = a;
			}
			void Line::Direction(Vector3D u){
				this->direction = u;
				u /= u.Norme();
			}

			ostream & operator << (ostream & out, Line const& a){
				out << scientific << setprecision(15);
				out << a.Origin() << " " << a.Direction();
				return out;
			}

			istream & operator >> (istream & in, Line & a){
				Point x;
				Vector3D y;
				in >> x >> y;
				a.Origin(x);
				a.Direction(y);
				return in;
			}

		}
	}
}
