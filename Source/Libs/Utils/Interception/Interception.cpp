
#include <Interception.h>
#include "../GeometryConcepts/Point.h"
#include "../GeometryConcepts/Plan.h"
#include "../GeometryConcepts/Segment.h"
#include "../GeometryConcepts/Line.h"

namespace Luga {
	namespace Meca {
		namespace Utils {

			Interception::Interception() {
				type = InterceptionEmpty;
				point = NULL;
				line = NULL;
				segment = NULL;
				plan = NULL;
			}

			Interception::~Interception() {
				if(point != NULL)
					delete point;
				if(line != NULL)
					delete line;
				if(segment != NULL)
					delete segment;
				if(plan != NULL)
					delete plan;
			}

			Interception::Interception(InterceptionType type){
				this->type = type;
				point = NULL;
				line = NULL;
				segment = NULL;
				plan = NULL;
			}

			void Interception::Type(const InterceptionType type){
				this->type = type;
			}

			void Interception::SetPoint(const Point & pt){
				point = new Point(pt);
			}

			void Interception::SetLine(const Line & l){
				line = new Line(l);
			}

			void Interception::SetSegment(const Segment & sgt){
				segment = new Segment(sgt);
			}

			void Interception::SetPlan(const Plan & pl){
				plan = new Plan(pl);
			}

			InterceptionType Interception::Type() const{
				return type;
			}

			Point Interception::GetPoint() const{
				return *point;
			}

			Line Interception::GetLine() const{
				return *line;
			}
			Segment Interception::GetSegment() const{
				return *segment;
			}

			Plan Interception::GetPlan() const{
				return *plan;
			}

		} /* namespace Utils */
	} /* namespace Meca */
} /* namespace Luga */
