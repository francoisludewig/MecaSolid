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

				Interception Intercept(Line & a, Line & b);

			private:
				bool AreVectorsLinearlyIndependant(const Vector& originAB, Line& a, Line& b);
				bool AreVectorsParallel(Line& a, Line& b);
			};
		}
	}
}
