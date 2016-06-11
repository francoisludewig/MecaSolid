#pragma once

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Line;
			class Interception;
			class Vector;

			class InterceptorLines {
			public:
				InterceptorLines();
				virtual ~InterceptorLines();

				Interception Intercept(const Line & a, const Line & b);

			private:
				bool AreVectorsLinearlyIndependant(const Vector& originAB, const Line& a, const Line& b);
				bool AreVectorsParallel(const Line& a, const Line& b);
			};
		}
	}
}
