
#include <iostream>
#include <cmath>
#include "../Include/Solid/Solid.h"

#define precision 1E-15

using namespace std;

namespace Meca {
	namespace Libs {
		namespace Basis{

			Solid::Solid():b(),velocity(0,0,0),angularVelocity(0,0,0),force(0,0,0){
				mass = 1;
			}

			Solid::~Solid(){

			}

		}
	}
}
