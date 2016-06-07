#pragma once

namespace Luga {
	namespace Meca {
		namespace Utils {

			class Interception;
			class Plan;
			class Line;
			class Vector;

			class InterceptorPlans {
			public:
				InterceptorPlans();
				virtual ~InterceptorPlans();
				Interception Intercept(Plan & a, Plan & b);
			private:
				void MakeLinesForPointIntersection(const Plan &a, const Plan &b, Line & la, Line & lb, const Vector direction);
			};

		} /* namespace Utils */
	} /* namespace Meca */
} /* namespace Luga */
