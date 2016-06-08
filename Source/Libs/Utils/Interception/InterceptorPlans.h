#pragma once

namespace Luga {
	namespace Meca {
		namespace Utils {

			class Interception;
			class Plan;
			class Line;
			class Vector;
			class Point;

			class InterceptorPlans {
			public:
				InterceptorPlans();
				virtual ~InterceptorPlans();
				Interception Intercept(Plan & a, Plan & b);
			private:
				Point GetIntersectionPoint(const Plan & a, const Plan & b, const Vector & direction);

			};

		} /* namespace Utils */
	} /* namespace Meca */
} /* namespace Luga */
