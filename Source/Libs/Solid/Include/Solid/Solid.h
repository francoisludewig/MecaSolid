
#pragma

#include <iostream>
#include <iomanip>
#include "Basis.h"
#include "../../../Utils/Include/Utils/Matrix3x3.h"

using namespace std;
using namespace Luga::Meca::Utils;

namespace Luga {
	namespace Meca {
		namespace Solid{

		class Solid{
		public:
			Solid();
			~Solid();

			Basis B() const;
			Vector3D Velocity() const;
			Vector3D AngularVelocity() const;
			Vector3D Force() const;
			Vector3D Momentum() const;
			Matrix3x3 Inertia() const;
			double Mass() const;

			void B(Basis & b);
			void Velocity(Vector3D & v);
			void AngularVelocity(Vector3D w);
			void Force(Vector3D f);
			void Momentum(Vector3D m);
			void Inertia(Matrix3x3 i);
			void Mass(double m);

			void LoadFromIstream(istream & in);


			void UpdateVelocities(double dt);
			void UpdatePosition(double dt);


		private:
			Basis b;
			Vector3D velocity,angularVelocity,force,momentum;
			Vector3D localMomentum;
			Matrix3x3 inertia,interia_1;
			double mass;
		};

		ostream & operator << (ostream & out, Solid const& a);
		istream & operator >> (istream & in, Solid & a);

		}
	}
}
