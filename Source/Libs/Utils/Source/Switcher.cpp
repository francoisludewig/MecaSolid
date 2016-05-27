
#include <iostream>
#include <cmath>
#include "../Include/Utils/Switcher.h"

#include "../Include/Utils/Vector3D.h"
#include "../Include/Utils/Point.h"
#include "../Include/Utils/Basis.h"
#include "../Include/Utils/Line.h"
#include "../Include/Utils/Plan.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			Switcher::Switcher(){
				to = NULL;
				from = NULL;
			}

			Switcher::~Switcher(){

			}

			void Switcher::SwithLine(Line & line) const{
				if(line.Id() == from->ID()){
					Point origin = line.Origin();
					Vector3D direction = line.Direction();
					SwithPoint(origin);
					SwithVector(direction);
					line.Origin(origin);
					line.Direction(direction);
				}
			}

			void Switcher::SwithSegment(Segment & segment) const{
				if(segment.Id() == from->ID()){
					Point begin = segment.BeginPoint();
					Point end = segment.EndPoint();
					SwithPoint(begin);
					SwithPoint(end);
					segment.BeginPoint(begin);
					segment.EndPoint(end);
				}
			}

			void Switcher::SwithPlan(Plan & plan) const{
				if(plan.Id() == from->ID()){
					Point origin = plan.Origin();
					Vector3D normal = plan.Normal();
					SwithPoint(origin);
					SwithVector(normal);
					plan.Origin(origin);
					plan.Normal(normal);
				}
			}

		}
	}
}
