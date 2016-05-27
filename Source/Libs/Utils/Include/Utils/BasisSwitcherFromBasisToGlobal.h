#pragma once


#include <iostream>
#include <iomanip>

#include "Switcher.h"

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class BasisSwitcherFromBasisToGlobal : public Switcher {
			public:
				BasisSwitcherFromBasisToGlobal();
				BasisSwitcherFromBasisToGlobal(Basis * from);

				~BasisSwitcherFromBasisToGlobal();
				virtual void SwithPoint(Point & point) const;
				virtual void SwithVector(Vector3D & vector3d) const;
				virtual void From(Basis *from);
				virtual void To(Basis *to);
			};

		}
	}
}



