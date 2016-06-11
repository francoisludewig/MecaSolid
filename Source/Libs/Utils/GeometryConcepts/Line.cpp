#include "../GeometryConcepts/Line.h"

#include <iostream>
#include <cmath>

#define precision 1E-15

namespace Luga {
	namespace Meca {
		namespace Utils{

			Line::Line():origin(),direction(1./sqrt(3),1./sqrt(3),1./sqrt(3)){

			}

			Line::Line(const Point & a, const Vector & u):origin(a){
				this->direction = u;
				this->direction.Normalize();
			}

			Line::~Line(){}

			Point Line::Origin() const{
				return origin;
			}

			Vector Line::Direction() const{
				return direction;
			}

			void Line::Origin(const Point & a){
				this->origin = a;
			}
			void Line::Direction(const Vector & u){
				this->direction = u;
				this->direction.Normalize();
			}

			std::ostream & operator << (std::ostream & out, const Line & a){
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

			bool operator== (const Line  &line1, const Line &line2){
				if((line1.Direction()^line2.Direction()) != Vector(0,0,0))
					return false;

				if((line1.Direction()^(line1.Origin()-line2.Origin())) != Vector(0,0,0))
						return false;
				return true;
			}

			bool operator!= (const Line &line1, const Line &line2){
				return !(line1==line2);
			}

		}
	}
}
