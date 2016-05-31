#pragma once


#include <Utils/BasisChangerFromBasisToBasis.h>
#include <Utils/BasisChangerFromBasisToGlobal.h>
#include <Utils/BasisChangerFromGlobalToBasis.h>
#include <Utils/BasisChangerImplementation.h>
#include <iostream>
#include <iomanip>


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

				void Type(BasisChangerType type);
				BasisChangerType Type();
				void ChangePoint(Point & point) const;
				void ChangeVector(Vector & vector3d) const;
				void ChangeLine(Line & line) const;
				void ChangeSegment(Segment & segment) const;
				void ChangePlan(Plan & plan) const;
				void FromBasis(Basis *from);
				void ToBasis(Basis *to);

			private:
				void UpdateSwitcher();

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



