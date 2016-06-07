#include "Polygon.h"

#include <iostream>
#include <cmath>
#include "Segment.h"

#define precision 1E-15

namespace Luga {
	namespace Meca {
		namespace Utils{

			Polygon::Polygon():basis(){
				localSegment.push_back(Segment(Point(1,0,0),Point(0,1,0)));
				localSegment.push_back(Segment(Point(0,1,0),Point(0,0,1)));
				localSegment.push_back(Segment(Point(0,0,1),Point(1,0,0)));
			}

			Polygon::Polygon(Basis & b, std::vector<Segment> & p):basis(b),localSegment(p){

			}

			Polygon::~Polygon(){
			}

			void Polygon::UpdateGlobalSegment(){

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
