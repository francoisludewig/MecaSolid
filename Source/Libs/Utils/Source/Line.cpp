#include <Utils/Line.h>
#include <iostream>
#include <cmath>

#define precision 1E-15

using namespace std;


namespace Luga {
	namespace Meca {
		namespace Utils{

			Line::Line():a(),u(1./sqrt(3),1./sqrt(3),1./sqrt(3)){

			}

			Line::Line(Point a, Vector3D u):a(a){
				u /= u.Norme();
				this->u = u;
			}

			Line::~Line(){}

			Point Line::GetPoint() const{
				return a;
			}

			Vector3D Line::GetVector() const{
				return u;
			}

			void Line::SetPoint(Point a){
				this->a = a;
			}
			void Line::SetVector(Vector3D u){
				this->u = u;
				u /= u.Norme();
			}

			ostream & operator << (ostream & out, Line const& a){
				out << scientific << setprecision(15);
				out << a.GetPoint() << " " << a.GetVector();
				return out;
			}

			istream & operator >> (istream & in, Line & a){
				Point x;
				Vector3D y;
				in >> x >> y;
				a.SetPoint(x);
				a.SetVector(y);
				return in;
			}

		}
	}
}
