#pragma once

#include <iostream>
#include <iomanip>

#include "../GeometryConcepts/Point.h"
#include "../GeometryConcepts/Plan.h"
#include "../GeometryConcepts/Segment.h"
#include "../GeometryConcepts/Line.h"

namespace Luga {
	namespace Meca {
		namespace Utils {

			enum InterceptionType{
				InterceptionEmpty,
				InterceptionPoint,
				InterceptionLine,
				InterceptionSegment,
				InterceptionPlan
			};

			class Interception {
			public:
				Interception();
				Interception(InterceptionType type);
				~Interception();
				void Type(const InterceptionType type);
				void SetPoint(const Point & pt);
				void SetLine(const Line & l);
				void SetSegment(const Segment & sgt);
				void SetPlan(const Plan & pl);
				InterceptionType Type() const;
				const Point GetPoint() const;
				const Line GetLine() const;
				const Segment GetSegment() const;
				const Plan GetPlan() const;
			private:
				InterceptionType type;
				Point point;
				Line  line;
				Segment segment;
				Plan plan;
			};

		} /* namespace Utils */
	} /* namespace Meca */
} /* namespace Luga */
