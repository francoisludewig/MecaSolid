#include "Polygon.h"

#include <iostream>
#include <cmath>
#include "Segment.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			Polygon::Polygon():basis(){
				Segment segment1(Point(1,0,0),Point(0,1,0));
				Segment segment2(Point(0,1,0),Point(0,0,1));
				Segment segment3(Point(0,0,1),Point(1,0,0));
				segment1.Id(basis.ID());
				segment2.Id(basis.ID());
				segment3.Id(basis.ID());
				localSegment.push_back(segment1);
				localSegment.push_back(segment2);
				localSegment.push_back(segment3);
				basisChanger.FromBasis(&basis);
			}

			Polygon::Polygon(Basis & b, std::vector<Segment> & p):basis(b),localSegment(p){

			}

			Polygon::~Polygon(){
			}

			void Polygon::UpdateGlobalSegment(){
				globalSegment = localSegment;
				for(auto segment : globalSegment)
					basisChanger.ChangeSegment(segment);
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
