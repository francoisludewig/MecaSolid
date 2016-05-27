#pragma once


#include <iostream>
#include <iomanip>

#include "Switcher.h"

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class BasisSwitcherFromGlobalToBasis : public Switcher {
			public:
				BasisSwitcherFromGlobalToBasis();
				BasisSwitcherFromGlobalToBasis(Basis * to);
				~BasisSwitcherFromGlobalToBasis();
				virtual void SwithPoint(Point & point) const;
				virtual void SwithVector(Vector3D & vector3d) const;
				virtual void From(Basis *from);
				virtual void To(Basis *to);
			};
		}
	}
}



