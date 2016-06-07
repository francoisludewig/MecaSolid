#pragma once

#include <iostream>
#include <iomanip>

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

		 	class Point;
		 	class Line;
		 	class Segment;
		 	class Plan;

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
				Point GetPoint() const;
				Line GetLine() const;
				Segment GetSegment() const;
				Plan GetPlan() const;
			private:
				InterceptionType type;
				Point* point;
				Line * line;
				Segment *segment;
				Plan *plan;
			};

		} /* namespace Utils */
	} /* namespace Meca */
} /* namespace Luga */
