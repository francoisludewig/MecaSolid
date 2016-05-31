#include <Utils/Line.h>
#include <iostream>
#include <cmath>

#define precision 1E-15

namespace Luga {
	namespace Meca {
		namespace Utils{

			Line::Line():origin(),direction(1./sqrt(3),1./sqrt(3),1./sqrt(3)){

			}

			Line::Line(Point a, Vector u):origin(a){
				u /= u.Norme();
				this->direction = u;
			}

			Line::~Line(){}

			Point Line::Origin() const{
				return origin;
			}

			Vector Line::Direction() const{
				return direction;
			}

			void Line::Origin(Point a){
				this->origin = a;
			}
			void Line::Direction(Vector u){
				this->direction = u;
				u /= u.Norme();
			}

			std::ostream & operator << (std::ostream & out, Line const& a){
				out << std::scientific << std::setprecision(15);
				out << a.Origin() << " " << a.Direction();
				return out;
			}

			std::istream & operator >> (std::istream & in, Line & a){
				Point x;
				Vector y;
				in >> x >> y;
				a.Origin(x);
				a.Direction(y);
				return in;
			}

		}
	}
}
