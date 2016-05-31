#include <Utils/BasisChangerFromBasisToBasis.h>
#include <Utils/Vector.h>

#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Utils/Quaternion.h"
#include "Utils/Basis.h"
#include "Utils/Point.h"
#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;

TEST(BasisChangerFromBasisToBasis,ChangeVector){
	Point o(1,-3,2);
	Quaternion q(Vector(M_PI/4,M_PI/4,M_PI/4));
	Basis from(o,q),to;
	BasisChangerFromBasisToBasis basisToBasis;
	basisToBasis.ToBasis(&to);
	basisToBasis.FromBasis(&from);

	Vector u(M_PI,M_PI/5,2*M_PI,from.ID());
	Vector v = u;

	basisToBasis.ChangeVector(u);

	double x = v.ComponantX()*from.AxisX().ComponantX()
			 + v.ComponantY()*from.AxisY().ComponantX()
			 + v.ComponantZ()*from.AxisZ().ComponantX();

	double y = v.ComponantX()*from.AxisX().ComponantY()
			 + v.ComponantY()*from.AxisY().ComponantY()
			 + v.ComponantZ()*from.AxisZ().ComponantY();

	double z = v.ComponantX()*from.AxisX().ComponantZ()
			+ v.ComponantY()*from.AxisY().ComponantZ()
			+ v.ComponantZ()*from.AxisZ().ComponantZ();

	ASSERT_TRUE(isEquals (x,u.ComponantX()));
	ASSERT_TRUE(isEquals (y,u.ComponantY()));
	ASSERT_TRUE(isEquals (z,u.ComponantZ()));
}

TEST(BasisChangerFromBasisToBasis,ChangePoint){
	Point o(1,-3,2);
	Quaternion q(Vector(M_PI/4,M_PI/4,M_PI/4));
	Basis from(o,q),to;
	BasisChangerFromBasisToBasis basisToBasis;

	basisToBasis.ToBasis(&to);
	basisToBasis.FromBasis(&from);

	Point u(M_PI,M_PI/5,2*M_PI);
	u.Id(from.ID());
	Point v = u;
	basisToBasis.ChangePoint(u);

	double x = from.Origin().CoordinateX()
			+ v.CoordinateX()*from.AxisX().ComponantX()
			+ v.CoordinateY()*from.AxisY().ComponantX()
			+ v.CoordinateZ()*from.AxisZ().ComponantX();

	double y = from.Origin().CoordinateY()
			 + v.CoordinateX()*from.AxisX().ComponantY()
			 + v.CoordinateY()*from.AxisY().ComponantY()
			 + v.CoordinateZ()*from.AxisZ().ComponantY();

	double z = from.Origin().CoordinateZ()
			 + v.CoordinateX()*from.AxisX().ComponantZ()
			 + v.CoordinateY()*from.AxisY().ComponantZ()
			 + v.CoordinateZ()*from.AxisZ().ComponantZ();

	ASSERT_TRUE(isEquals (x,u.CoordinateX()));
	ASSERT_TRUE(isEquals (y,u.CoordinateY()));
	ASSERT_TRUE(isEquals (z,u.CoordinateZ()));
}

