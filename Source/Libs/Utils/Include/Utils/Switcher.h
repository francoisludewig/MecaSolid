#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Point;
			class Vector3D;
			class Line;
			class Segment;
			class Plan;
			class Basis;

			class Switcher {
			public:
				Switcher();
				virtual ~Switcher();
				virtual void SwithPoint(Point & point) const = 0;
				virtual void SwithVector(Vector3D & vector3d) const  = 0;
				virtual void SwithLine(Line & line) const;
				virtual void SwithSegment(Segment & segment) const;
				virtual void SwithPlan(Plan & plan) const;
				virtual void From(Basis *from) = 0;
				virtual void To(Basis *to) = 0;
			protected:
				Basis *from,*to;
			};

		}
	}
}



