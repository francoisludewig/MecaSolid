#pragma once

#include <iostream>
#include <iomanip>

#include "../GeometryConcepts/Segment.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Vector;
			class Quaternion;

			class VectorsQuaternionConverter {
			public:
				VectorsQuaternionConverter();
				~VectorsQuaternionConverter();
				void ConvertVectorsIntoQuaternion(const Vector& e1,const Vector& e2,const Vector& e3, Quaternion& q) const;
				void ConvertQuaternionIntoVectors(const Quaternion& q, Vector& e1, Vector& e2, Vector& e3) const;
			};

		}
	}
}
