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

			Basis B() const;
			Vector3D Velocity() const;
			Vector3D AngularVelocity() const;
			Vector3D Force() const;
			Vector3D Momentum() const;
			double Mass() const;

			void LoadFromIstream(istream & in);

		private:
			Basis b;
			Vector3D velocity,angularVelocity,force,momentum;
			double mass,inertia_1[3][3];
		};

		ostream & operator << (ostream & out, Solid const& a);
		istream & operator >> (istream & in, Solid & a);

		}
	}
}
