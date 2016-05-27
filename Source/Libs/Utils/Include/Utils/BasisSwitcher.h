#pragma once


#include <iostream>
#include <iomanip>

using namespace std;

#include "Switcher.h"
#include "BasisSwitcherFromBasisToBasis.h"
#include "BasisSwitcherFromGlobalToBasis.h"
#include "BasisSwitcherFromBasisToGlobal.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			enum BasisSwitcherType{
				None,
				From_Global_To_Basis,
				From_Basis_To_Global,
				From_Basis_To_Basis
			};

			class BasisSwitcher : public Switcher{
			public:
				BasisSwitcher();
				~BasisSwitcher();
				void Type(BasisSwitcherType type);

				virtual void SwithPoint(Point & point) const;
				virtual void SwithVector(Vector3D & vector3d) const;
				virtual void SwithLine(Line & line) const;
				virtual void SwithSegment(Segment & segment) const;
				virtual void SwithPlan(Plan & plan) const;
				virtual void From(Basis *from);
				virtual void To(Basis *to);
			private:
				void UpdateSwitcher();

				BasisSwitcherType type;
				Switcher *switcher;
				BasisSwitcherFromBasisToBasis basisToBasis;
				BasisSwitcherFromGlobalToBasis globalToBasis;
				BasisSwitcherFromBasisToGlobal basisToGlobal;
			};
		}
	}
}



