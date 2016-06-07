#pragma once


#include <iostream>
#include <iomanip>

#include "BasisChangerFromBasisToGlobal.h"
#include "BasisChangerFromGlobalToBasis.h"
#include "BasisChangerImplementation.h"


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



