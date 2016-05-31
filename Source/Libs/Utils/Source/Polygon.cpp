#include <Utils/Segment.h>
#include "../../Utils/Include/Utils/Polygon.h"

#include <iostream>
#include <cmath>

#define precision 1E-15

namespace Luga {
	namespace Meca {
		namespace Utils{

			Polygon::Polygon():basis(){
				localSummit.push_back(Point(1,0,0));
				localSummit.push_back(Point(0,1,0));
				localSummit.push_back(Point(0,0,1));
			}

			Polygon::Polygon(Basis & b, std::vector<Point> & p):basis(b),localSummit(p){

			}

			Polygon::~Polygon(){
			}

			void Polygon::UpdateGlobalSummit(){

			}

			std::ostream & operator << (std::ostream & out, Polygon const& a){
				out << std::scientific << std::setprecision(15);
				return out;
			}

			std::istream & operator >> (std::istream & in, Polygon & a){
				return in;
			}

		}
	}
}
