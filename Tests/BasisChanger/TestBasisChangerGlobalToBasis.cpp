#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Point.h"
#include "Basis.h"
#include "Quaternion.h"
#include "Vector.h"
#include "BasisChangerFromGlobalToBasis.h"
#include "../Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;

TEST(BasisChangerFromGlobalToBasis,ChangeVector){
	Vector u(M_PI,M_PI/5,2*M_PI,-1);
	Vector v = u;
	Point o(1,-3,2);
	Quaternion q(Vector(M_PI/4,M_PI/4,M_PI/4));
	Basis base(o,q);
	BasisChangerFromGlobalToBasis globalToBasis;
	globalToBasis.ToBasis(&base);
	globalToBasis.ChangeVector(u);

	double x = u.ComponantX()*base.AxisX().ComponantX()
							+ u.ComponantY()*base.AxisY().ComponantX()
							+ u.ComponantZ()*base.AxisZ().ComponantX();

	double y = u.ComponantX()*base.AxisX().ComponantY()
							+ u.ComponantY()*base.AxisY().ComponantY()
							+ u.ComponantZ()*base.AxisZ().ComponantY();

	double z = u.ComponantX()*base.AxisX().ComponantZ()
							+ u.ComponantY()*base.AxisY().ComponantZ()
							+ u.ComponantZ()*base.AxisZ().ComponantZ();

	ASSERT_TRUE(isEquals (x,v.ComponantX()));
	ASSERT_TRUE(isEquals (y,v.ComponantY()));
	ASSERT_TRUE(isEquals (z,v.ComponantZ()));
}

TEST(BasisChangerFromGlobalToBasis,ChangePoint){
	Point u(M_PI,M_PI/5,2*M_PI);
	Point v = u;
	Point o(1,-3,2);
	Quaternion q(Vector(M_PI/4,M_PI/4,M_PI/4));
	Basis base(o,q);
	BasisChangerFromGlobalToBasis globalToBasis;
	globalToBasis.ToBasis(&base);
	globalToBasis.ChangePoint(u);

	double x = base.Origin().CoordinateX()
					+ u.CoordinateX()*base.AxisX().ComponantX()
					+ u.CoordinateY()*base.AxisY().ComponantX()
					+ u.CoordinateZ()*base.AxisZ().ComponantX();

	double y = base.Origin().CoordinateY()
					+ u.CoordinateX()*base.AxisX().ComponantY()
					+ u.CoordinateY()*base.AxisY().ComponantY()
					+ u.CoordinateZ()*base.AxisZ().ComponantY();

	double z = base.Origin().CoordinateZ()
					+ u.CoordinateX()*base.AxisX().ComponantZ()
					+ u.CoordinateY()*base.AxisY().ComponantZ()
					+ u.CoordinateZ()*base.AxisZ().ComponantZ();

	ASSERT_TRUE(isEquals (x,v.CoordinateX()));
	ASSERT_TRUE(isEquals (y,v.CoordinateY()));
	ASSERT_TRUE(isEquals (z,v.CoordinateZ()));
}


