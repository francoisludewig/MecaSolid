#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

#include "../Basis/Basis.h"
#include "../Basis/BasisId.h"
#include "BasisId.h"

#include "Segment.h"

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Polygon : public BasisId {
			public:
				Polygon();
				Polygon(Basis & basis, std::vector<Segment> & p);
				~Polygon();

			private:
				std::vector<Segment> localSegment;
				std::vector<Segment> GlobalSegment;
				Basis basis;

				void UpdateGlobalSegment();
			};

			std::ostream & operator << (std::ostream & out, Polygon const& a);
			std::istream & operator >> (std::istream & in, Polygon & a);
		}
	}
}
