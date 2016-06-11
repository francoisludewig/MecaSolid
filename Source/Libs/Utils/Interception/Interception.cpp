
#include <Interception.h>
#include "../GeometryConcepts/Point.h"
#include "../GeometryConcepts/Plan.h"
#include "../GeometryConcepts/Segment.h"
#include "../GeometryConcepts/Line.h"

namespace Luga {
	namespace Meca {
		namespace Utils {

			Interception::Interception():type(InterceptionEmpty),point(),line(),segment(),plan() {
			}

			Interception::~Interception() {
			}

			Interception::Interception(InterceptionType type):type(type),point(),line(),segment(),plan(){
			}

			void Interception::Type(const InterceptionType type){
				this->type = type;
			}

			void Interception::SetPoint(const Point & pt){
				point = pt;
			}

			void Interception::SetLine(const Line & l){
				line = l;
			}

			void Interception::SetSegment(const Segment & sgt){
				segment = sgt;
			}

			void Interception::SetPlan(const Plan & pl){
				plan = pl;
			}

			InterceptionType Interception::Type() const{
				return type;
			}

			const Point Interception::GetPoint() const{
				return point;
			}

			const Line Interception::GetLine() const{
				return line;
			}
			const Segment Interception::GetSegment() const{
				return segment;
			}

			const Plan Interception::GetPlan() const{
				return plan;
			}

		} /* namespace Utils */
	} /* namespace Meca */
} /* namespace Luga */
