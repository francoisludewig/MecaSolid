#pragma once


#include <iostream>
#include <iomanip>

#include "BasisChangerFromBasisToBasis.h"
#include "BasisChangerFromBasisToGlobal.h"
#include "BasisChangerFromGlobalToBasis.h"
#include "BasisChangerImplementation.h"


namespace Luga {
	namespace Meca {
		namespace Utils{

			enum BasisChangerType{
				None,
				From_Global_To_Basis,
				From_Basis_To_Global,
				From_Basis_To_Basis
			};

			class BasisChanger{
			public:
				BasisChanger();
				~BasisChanger();

				void Type(const BasisChangerType type);
				BasisChangerType Type() const;
				void ChangePoint(Point & point) const;
				void ChangeVector(Vector & vector3d) const;
				void ChangeLine(Line & line) const;
				void ChangeSegment(Segment & segment) const;
				void ChangePlan(Plan & plan) const;
				void ChangeMatrix(Matrix & matrix) const;
				void FromBasis(Basis *from);
				void ToBasis(Basis *to);

			private:
				void UpdateSwitcher();
				void UpdateType();

				Basis *from,*to;
				BasisChangerType type;
				BasisChangerImplementation *switcher;
				BasisChangerFromBasisToBasis basisToBasis;
				BasisChangerFromGlobalToBasis globalToBasis;
				BasisChangerFromBasisToGlobal basisToGlobal;
			};
		}
	}
}



