#pragma once

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

namespace Luga {
	namespace Meca {
		namespace Utils{

			class DoubleComparison {
			public:
				DoubleComparison();
				~DoubleComparison();

				static bool IsEqual(double a, double b){
					double x;
					if(a == 0)
					x = b;
					else if (b == 0)
						x = a;
					else
						x = (a-b)/a;

					if(std::fabs(x) <= std::numeric_limits<double>::epsilon())
						return true;
					else
						return false;
				}
			};
		}
	}
}

