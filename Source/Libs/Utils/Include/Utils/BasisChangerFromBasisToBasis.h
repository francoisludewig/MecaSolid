#pragma once


#include <Utils/BasisChangerFromBasisToGlobal.h>
#include <Utils/BasisChangerFromGlobalToBasis.h>
#include <Utils/BasisChangerImplementation.h>
#include <iostream>
#include <iomanip>


namespace Luga {
	namespace Meca {
		namespace Utils{

			class BasisChangerFromBasisToBasis : public BasisChangerImplementation{
			public:
				BasisChangerFromBasisToBasis();
				BasisChangerFromBasisToBasis(Basis * from, Basis * to);
				~BasisChangerFromBasisToBasis();
				virtual void ChangePoint(Point & point) const;
				virtual void ChangeVector(Vector & vector3d) const;
				virtual void FromBasis(Basis *from);
				virtual void ToBasis(Basis *to);

			private:
				BasisChangerFromGlobalToBasis globalToBasis;
				BasisChangerFromBasisToGlobal basisToGlobal;
			};
		}
	}
}



