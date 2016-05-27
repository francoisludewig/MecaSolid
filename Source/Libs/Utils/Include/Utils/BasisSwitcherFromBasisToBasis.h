#pragma once


#include <iostream>
#include <iomanip>

#include "BasisSwitcherFromGlobalToBasis.h"
#include "BasisSwitcherFromBasisToGlobal.h"
#include "Switcher.h"

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class BasisSwitcherFromBasisToBasis : public Switcher{
			public:
				BasisSwitcherFromBasisToBasis();
				BasisSwitcherFromBasisToBasis(Basis * from, Basis * to);
				~BasisSwitcherFromBasisToBasis();
				virtual void SwithPoint(Point & point) const;
				virtual void SwithVector(Vector3D & vector3d) const;
				virtual void SwithLine(Line & line) const;
				virtual void SwithSegment(Segment & segment) const;
				virtual void SwithPlan(Plan & plan) const;
				virtual void From(Basis *from);
				virtual void To(Basis *to);

			private:
				BasisSwitcherFromGlobalToBasis globalToBasis;
				BasisSwitcherFromBasisToGlobal basisToGlobal;
			};
		}
	}
}



