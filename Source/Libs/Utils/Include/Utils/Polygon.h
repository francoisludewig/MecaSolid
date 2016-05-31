#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include "Utils/Point.h"
#include "Utils/Basis.h"

#include "BasisId.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Point;

			class Polygon : public BasisId {
			public:
				Polygon();
				Polygon(Basis & basis, std::vector<Point> & p);
				~Polygon();

			private:
				std::vector<Point> localSummit;
				std::vector<Point> GlobalSummit;
				Basis basis;

				void UpdateGlobalSummit();
			};

			std::ostream & operator << (std::ostream & out, Polygon const& a);
			std::istream & operator >> (std::istream & in, Polygon & a);
		}
	}
}
