#pragma once

namespace Luga {
	namespace Meca {
		namespace Utils {

			class Plan;
			class Line;
			class Interception;
			class Point;

			class InterceptorPlanLine {
			public:
				InterceptorPlanLine();
				virtual ~InterceptorPlanLine();
				Interception Intercept(Plan& plan, Line& line);
			private:
				bool IsPointInPlan(const Point & point, const Plan & plan);
			};

		} /* namespace Utils */
	} /* namespace Meca */
} /* namespace Luga */
