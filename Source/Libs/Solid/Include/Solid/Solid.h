#pragma

#include <iostream>
#include <iomanip>
#include <Basis/Basis.h>

using namespace std;

namespace Meca {
	namespace Libs {
		namespace Basis{

		class Solid{
		public:
			Solid();
			~Solid();

		private:
			Basis b;
			Vector3D velocity,angularVelocity,force;
			double mass;
		};


		}
	}
}
