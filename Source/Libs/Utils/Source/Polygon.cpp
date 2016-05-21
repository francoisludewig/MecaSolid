#include <Utils/Segment.h>
#include "../../Utils/Include/Utils/Polygon.h"

#include <iostream>
#include <cmath>

#define precision 1E-15

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			Polygon::Polygon():b(){
				localSummit.push_back(Point(1,0,0));
				localSummit.push_back(Point(0,1,0));
				localSummit.push_back(Point(0,0,1));
			}

			Polygon::Polygon(Basis & b, vector<Point> & p):b(b),localSummit(p){

			}

			Polygon::~Polygon(){
			}

			void Polygon::UpdateGlobalSummit(){

			}

			ostream & operator << (ostream & out, Polygon const& a){
				out << scientific << setprecision(15);
				return out;
			}

			istream & operator >> (istream & in, Polygon & a){
				return in;
			}

		}
	}
}
