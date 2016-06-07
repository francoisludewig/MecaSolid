#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Point.h"
#include "Basis.h"
#include "Quaternion.h"
#include "Vector.h"
#include "BasisChangerFromBasisToGlobal.h"
#include "../Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;

TEST(BasisChangerFromBasisToGlobal,ChangeVector){
	Point o(1,-3,2);
	Quaternion q(Vector(M_PI/4,M_PI/4,M_PI/4));
	Basis base(o,q);

	Vector u(M_PI,M_PI/5,2*M_PI,base.ID());
	Vector v = u;

	BasisChangerFromBasisToGlobal basisToGlobal;
	basisToGlobal.FromBasis(&base);
	basisToGlobal.ChangeVector(u);

	double x = v.ComponantX()*base.AxisX().ComponantX()
							+ v.ComponantY()*base.AxisY().ComponantX()
							+ v.ComponantZ()*base.AxisZ().ComponantX();

	double y = v.ComponantX()*base.AxisX().ComponantY()
							+ v.ComponantY()*base.AxisY().ComponantY()
							+ v.ComponantZ()*base.AxisZ().ComponantY();

	double z = v.ComponantX()*base.AxisX().ComponantZ()
							+ v.ComponantY()*base.AxisY().ComponantZ()
							+ v.ComponantZ()*base.AxisZ().ComponantZ();

	ASSERT_TRUE(isEquals (x,u.ComponantX()));
	ASSERT_TRUE(isEquals (y,u.ComponantY()));
	ASSERT_TRUE(isEquals (z,u.ComponantZ()));
}


TEST(BasisChangerFromBasisToGlobal,ChangePoint){
	Point o(1,-3,2);
	Quaternion q(Vector(M_PI/4,M_PI/4,M_PI/4));
	Basis base(o,q);

	Point u(M_PI,M_PI/5,2*M_PI);
	u.Id(base.ID());
	Point v = u;

	BasisChangerFromBasisToGlobal basisToGlobal;
	basisToGlobal.FromBasis(&base);
	basisToGlobal.ChangePoint(u);

	double x = base.Origin().CoordinateX()
					+ v.CoordinateX()*base.AxisX().ComponantX()
					+ v.CoordinateY()*base.AxisY().ComponantX()
					+ v.CoordinateZ()*base.AxisZ().ComponantX();

	double y = base.Origin().CoordinateY()
					+ v.CoordinateX()*base.AxisX().ComponantY()
					+ v.CoordinateY()*base.AxisY().ComponantY()
					+ v.CoordinateZ()*base.AxisZ().ComponantY();

	double z = base.Origin().CoordinateZ()
					+ v.CoordinateX()*base.AxisX().ComponantZ()
					+ v.CoordinateY()*base.AxisY().ComponantZ()
					+ v.CoordinateZ()*base.AxisZ().ComponantZ();

	ASSERT_TRUE(isEquals (x,u.CoordinateX()));
	ASSERT_TRUE(isEquals (y,u.CoordinateY()));
	ASSERT_TRUE(isEquals (z,u.CoordinateZ()));
}



