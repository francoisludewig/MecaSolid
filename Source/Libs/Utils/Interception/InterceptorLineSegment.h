#pragma once

namespace Luga {
	namespace Meca {
		namespace Utils {

			class Line;
			class Segment;
			class Interception;
			class Point;

			class InterceptorLineSegment {
			public:
				InterceptorLineSegment();
				virtual ~InterceptorLineSegment();
				Interception Intercept(Line & line, Segment & segment);
			private:
				bool IsPointInSegment(const Point &point, const Segment & segment);
			};

		} /* namespace Utils */
	} /* namespace Meca */
} /* namespace Luga */
