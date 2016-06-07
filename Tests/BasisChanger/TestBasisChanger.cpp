#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Point.h"
#include "Basis.h"
#include "Quaternion.h"
#include "Vector.h"
#include "BasisChanger.h"
#include "Matrix.h"
#include "../Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;

TEST(BasisChanger,Status){
	Basis base;
	BasisChanger basisSwitcher;

	ASSERT_EQ(None,basisSwitcher.Type());

	basisSwitcher.FromBasis(&base);
	ASSERT_EQ(From_Basis_To_Global,basisSwitcher.Type());

	basisSwitcher.ToBasis(&base);
	ASSERT_EQ(From_Basis_To_Basis,basisSwitcher.Type());

	basisSwitcher.FromBasis(NULL);
	ASSERT_EQ(From_Global_To_Basis,basisSwitcher.Type());

	basisSwitcher.ToBasis(NULL);
	ASSERT_EQ(None,basisSwitcher.Type());
}

/*
TEST(BasisChanger,Matrix){
	Point o(1,-3,2);
	Quaternion q(Vector(M_PI/4,M_PI/4,M_PI/4));
	Basis base(o,q);
	BasisChanger basisSwitcher;
	basisSwitcher.ToBasis(&base);
	Matrix a;
	a.Element(0,0,-3);
	a.Element(0,1,5);
	a.Element(0,2,6);

	a.Element(1,0,-1);
	a.Element(1,1,2);
	a.Element(1,2,2);

	a.Element(2,0,1);
	a.Element(2,1,-1);
	a.Element(2,2,-1);
	Vector v(1,2,3);
	Vector b = a*v;

	ASSERT_EQ(-1,a.Id());
	ASSERT_EQ(From_Global_To_Basis,basisSwitcher.Type());

	basisSwitcher.ChangeVector(v);
	basisSwitcher.ChangeMatrix(a);
	Vector c = a*v;

	basisSwitcher.FromBasis(&base);
	ASSERT_EQ(From_Basis_To_Basis,basisSwitcher.Type());
	basisSwitcher.ToBasis(NULL);

	ASSERT_EQ(From_Basis_To_Global,basisSwitcher.Type());

	basisSwitcher.ChangeVector(c);

	ASSERT_TRUE(isEquals(b.ComponantX(),c.ComponantX()));
	ASSERT_TRUE(isEquals(b.ComponantY(),c.ComponantY()));
	ASSERT_TRUE(isEquals(b.ComponantZ(),c.ComponantZ()));
}
*/

