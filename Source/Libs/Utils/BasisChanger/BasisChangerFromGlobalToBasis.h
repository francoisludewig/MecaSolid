#pragma once


#include <iostream>
#include <iomanip>

#include "BasisChangerImplementation.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			class BasisChangerFromGlobalToBasis : public BasisChangerImplementation {
			public:
				BasisChangerFromGlobalToBasis();
				BasisChangerFromGlobalToBasis(Basis * to);
				~BasisChangerFromGlobalToBasis();
				virtual void ChangePoint(Point & point) const;
				virtual void ChangeVector(Vector & vector3d) const;
				virtual void FromBasis(Basis *from);
				virtual void ToBasis(Basis *to);
			};
		}
	}
}



