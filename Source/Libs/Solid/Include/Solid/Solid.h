#pragma

#include <iostream>
#include <iomanip>
#include <Basis/Basis.h>
#include <Basis/Matrix3x3.h>

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

		private:
			Basis b;
			Vector3D velocity,angularVelocity,force,momentum;
			Matrix3x3 inertia;
			double mass;
		};

		ostream & operator << (ostream & out, Solid const& a);
		istream & operator >> (istream & in, Solid & a);

		}
	}
}
