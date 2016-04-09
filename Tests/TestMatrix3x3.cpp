#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Basis/Matrix3x3.h"
#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Meca::Libs::Basis;


TEST(Matrix3x3,Constructor){
	Matrix3x3 a;

	ASSERT_EQ (1,a.Componant(0,0));
	ASSERT_EQ (0,a.Componant(0,1));
	ASSERT_EQ (0,a.Componant(0,2));

	ASSERT_EQ (0,a.Componant(1,0));
	ASSERT_EQ (1,a.Componant(1,1));
	ASSERT_EQ (0,a.Componant(1,2));

	ASSERT_EQ (0,a.Componant(2,0));
	ASSERT_EQ (0,a.Componant(2,1));
	ASSERT_EQ (1,a.Componant(2,2));
}

TEST(Matrix3x3,det){
	Matrix3x3 a;

	a.Componant(0,0,-3);
	a.Componant(0,1,5);
	a.Componant(0,2,6);

	a.Componant(1,0,-1);
	a.Componant(1,1,2);
	a.Componant(1,2,2);

	a.Componant(2,0,1);
	a.Componant(2,1,-1);
	a.Componant(2,2,-1);
	ASSERT_EQ (-1,a.Determinant());
}

TEST(Matrix3x3,Transpose){
	Matrix3x3 a,b;

	a.Componant(0,0,-3);
	a.Componant(0,1,5);
	a.Componant(0,2,6);

	a.Componant(1,0,-1);
	a.Componant(1,1,2);
	a.Componant(1,2,2);

	a.Componant(2,0,1);
	a.Componant(2,1,-1);
	a.Componant(2,2,-1);

	b = a.MatrixTranspose();

	ASSERT_EQ (-3,b.Componant(0,0));
	ASSERT_EQ (-1,b.Componant(0,1));
	ASSERT_EQ (1,b.Componant(0,2));

	ASSERT_EQ (5,b.Componant(1,0));
	ASSERT_EQ (2,b.Componant(1,1));
	ASSERT_EQ (-1,b.Componant(1,2));

	ASSERT_EQ (6,b.Componant(2,0));
	ASSERT_EQ (2,b.Componant(2,1));
	ASSERT_EQ (-1,b.Componant(2,2));
}


TEST(Matrix3x3,Inverse){
	Matrix3x3 a,b;

	a.Componant(0,0,-3);
	a.Componant(0,1,5);
	a.Componant(0,2,6);

	a.Componant(1,0,-1);
	a.Componant(1,1,2);
	a.Componant(1,2,2);

	a.Componant(2,0,1);
	a.Componant(2,1,-1);
	a.Componant(2,2,-1);

	b = a.MatrixInverse();

	ASSERT_EQ (0,b.Componant(0,0));
	ASSERT_EQ (1,b.Componant(0,1));
	ASSERT_EQ (2,b.Componant(0,2));

	ASSERT_EQ (-1,b.Componant(1,0));
	ASSERT_EQ (3,b.Componant(1,1));
	ASSERT_EQ (0,b.Componant(1,2));

	ASSERT_EQ (1,b.Componant(2,0));
	ASSERT_EQ (-2,b.Componant(2,1));
	ASSERT_EQ (1,b.Componant(2,2));
}

