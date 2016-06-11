#pragma once

namespace Luga {
	namespace Meca {
		namespace Utils {

			class Segment;
			class Interception;
			class Line;
			class Point;

			class InterceptorSegments {
			public:
				InterceptorSegments();
				virtual ~InterceptorSegments();
				Interception Intercept(const Segment & a, const Segment & b);
			private:
				Interception InterceptColinearSegments(const Segment & a, const Segment & b, const Line & commonLine);
				bool IsPointInSegments(const Point & candidate, const Segment & a, const Segment & b);

			};

		} /* namespace Utils */
	} /* namespace Meca */
} /* namespace Luga */
