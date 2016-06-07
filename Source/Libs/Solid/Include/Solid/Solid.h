
#pragma

#include <iostream>
#include <iomanip>
#include "../../../Utils/Basis/Basis.h"
#include "../../../Utils/Basis/Matrix.h"

using namespace Luga::Meca::Utils;

namespace Luga {
	namespace Meca {
		namespace Solid{

		class Solid{
		public:
			Solid();
			~Solid();

			Basis B() const;
			Vector Velocity() const;
			Vector AngularVelocity() const;
			Vector Force() const;
			Vector Momentum() const;
			Matrix Inertia() const;
			double Mass() const;

			void B(Basis & b);
			void Velocity(Vector & v);
			void AngularVelocity(Vector w);
			void Force(Vector f);
			void Momentum(Vector m);
			void Inertia(Matrix i);
			void Mass(double m);

			void LoadFromIstream(std::istream & in);


			void UpdateVelocities(double dt);
			void UpdatePosition(double dt);

			void ResetForceAndMomemtum();

		private:
			Basis b;
			Vector velocity,angularVelocity,force,momentum;
			Vector localMomentum;
			Matrix inertia,interia_1;
			double mass;
		};

		std::ostream & operator << (std::ostream & out, Solid const& a);
		std::istream & operator >> (std::istream & in, Solid & a);

		}
	}
}
