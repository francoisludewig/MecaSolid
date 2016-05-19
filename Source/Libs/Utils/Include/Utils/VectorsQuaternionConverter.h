#pragma once

#include <Utils/Segment.h>
#include <iostream>
#include <iomanip>

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Vector3D;
			class Quaternion;

			class VectorsQuaternionConverter {
			public:
				VectorsQuaternionConverter();
				~VectorsQuaternionConverter();
				void ConvertVectorsIntoQuaternion(const Vector3D& e1,const Vector3D& e2,const Vector3D& e3, Quaternion& q) const;
				void ConvertQuaternionIntoVectors(const Quaternion& q, Vector3D& e1, Vector3D& e2, Vector3D& e3) const;
			};

		}
	}
}
