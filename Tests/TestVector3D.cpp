#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Basis/Vector3D.h"
#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Meca::Libs::Basis;


TEST(Vector3D,Constructor){
	Vector3D a;
	ASSERT_EQ (0,a.X());
	ASSERT_EQ (0,a.Y());
	ASSERT_EQ (0,a.Z());
}


TEST(Vector3D,ConstructorValue){
	Vector3D a(1,2,3);
	ASSERT_EQ (1,a.X());
	ASSERT_EQ (2,a.Y());
	ASSERT_EQ (3,a.Z());

	Vector3D b(M_PI,2*M_PI,M_PI/2);
	ASSERT_EQ (M_PI,b.X());
	ASSERT_EQ (2*M_PI,b.Y());
	ASSERT_EQ (M_PI/2,b.Z());
}

TEST(Vector3D,Norme){
	Vector3D a(1,2,3);
	ASSERT_EQ (sqrt(14.),a.Norme());
}

TEST(Vector3D,ScalarProduct){
	Vector3D a(1,0,0);
	Vector3D b(0,1,0);
	Vector3D c(0,0,1);

	ASSERT_EQ (0,a*b);
	ASSERT_EQ (0,a*c);
	ASSERT_EQ (0,b*c);
	ASSERT_EQ (1,a*a);
	ASSERT_EQ (1,b*b);
	ASSERT_EQ (1,c*c);
}


TEST(Vector3D,VectorialProduct){
	Vector3D a(1,0,0);
	Vector3D b(0,1,0);
	Vector3D c(0,0,1);

	Vector3D expectedC = a^b;
	Vector3D expectedA = b^c;
	Vector3D expectedB = c^a;

	ASSERT_EQ (c.X(),expectedC.X());
	ASSERT_EQ (c.Y(),expectedC.Y());
	ASSERT_EQ (c.Z(),expectedC.Z());

	ASSERT_EQ (a.X(),expectedA.X());
	ASSERT_EQ (a.Y(),expectedA.Y());
	ASSERT_EQ (a.Z(),expectedA.Z());

	ASSERT_EQ (b.X(),expectedB.X());
	ASSERT_EQ (b.Y(),expectedB.Y());
	ASSERT_EQ (b.Z(),expectedB.Z());
}


TEST(Vector3D,Product){
	Vector3D a(1,-2,3);
	Vector3D b(6,9,-7);

	ASSERT_TRUE(isEquals(0,a*(a^b)));
	ASSERT_TRUE(isEquals(0,b*(a^b)));
	ASSERT_TRUE(isEquals(0,a*(b^a)));
	ASSERT_TRUE(isEquals(0,b*(b^a)));

	a.SetValue(0,0,0);
	b.SetValue(1,3,1);

	ASSERT_TRUE(isEquals(0,a*(a^b)));
	ASSERT_TRUE(isEquals(0,b*(a^b)));
	ASSERT_TRUE(isEquals(0,a*(b^a)));
	ASSERT_TRUE(isEquals(0,b*(b^a)));
}

TEST(Vector3D,MultiplicationEqual){
	Vector3D a(5,17,-57);
	double b = -13;
	Vector3D c = a*b;
	a *=b;
	ASSERT_TRUE(isEquals(a.X(),c.X()));
	ASSERT_TRUE(isEquals(a.Y(),c.Y()));
	ASSERT_TRUE(isEquals(a.Z(),c.Z()));
}


TEST(Vector3D,IO_Operator){
	Vector3D a(M_PI,2*M_PI,M_PI/2);
	Vector3D b;

	ofstream fichierOut("testVector3D.txt", ios::out | ios::trunc);
	if(fichierOut){
		fichierOut << a;
		fichierOut.close();
	}

	ifstream fichierIn("testVector3D.txt", ios::in);
	if(fichierIn){
		fichierIn >> b;
		fichierIn.close();
	}

	EXPECT_DOUBLE_EQ (a.X(),b.X());
	EXPECT_DOUBLE_EQ (a.Y(),b.Y());
	EXPECT_DOUBLE_EQ (a.Z(),b.Z());

	remove("testVector3D.txt");
}

TEST(Vector3D,Sum){
	Vector3D a(M_PI,2*M_PI,M_PI/2);
	Vector3D b(7*M_PI,-2*M_PI,-4*M_PI/2);
	Vector3D c = a+b;

	EXPECT_DOUBLE_EQ (a.X()+b.X(),c.X());
	EXPECT_DOUBLE_EQ (a.Y()+b.Y(),c.Y());
	EXPECT_DOUBLE_EQ (a.Z()+b.Z(),c.Z());
}


TEST(Vector3D,Diff){
	Vector3D a(M_PI,2*M_PI,M_PI/2);
	Vector3D b(7*M_PI,2*M_PI,-4*M_PI/2);
	Vector3D c = a-b;

	EXPECT_DOUBLE_EQ (a.X()-b.X(),c.X());
	EXPECT_DOUBLE_EQ (a.Y()-b.Y(),c.Y());
	EXPECT_DOUBLE_EQ (a.Z()-b.Z(),c.Z());
}


TEST(Vector3D,Div){
	Vector3D a(M_PI,2*M_PI,M_PI/2);
	double b = sqrt(2.);
	Vector3D c = a/b;

	EXPECT_DOUBLE_EQ (a.X()/b,c.X());
	EXPECT_DOUBLE_EQ (a.Y()/b,c.Y());
	EXPECT_DOUBLE_EQ (a.Z()/b,c.Z());
}


TEST(Vector3D,DivEqual){
	Vector3D a(M_PI,2*M_PI,M_PI/2);
	double b = sqrt(2.);
	Vector3D c = a/b;
	a /=b;
	EXPECT_DOUBLE_EQ (a.X(),c.X());
	EXPECT_DOUBLE_EQ (a.Y(),c.Y());
	EXPECT_DOUBLE_EQ (a.Z(),c.Z());
}


TEST(Vector3D,LinearCombination){
	Vector3D a(1,0,0);
	Vector3D b(0,1,0);
	Vector3D c(0,0,1);

	Vector3D d = sqrt(3)*a+sqrt(5)*b-sqrt(7)*c;
	EXPECT_DOUBLE_EQ (sqrt(3.0),d.X());
	EXPECT_DOUBLE_EQ (sqrt(5.0),d.Y());
	EXPECT_DOUBLE_EQ (-sqrt(7.0),d.Z());
}


TEST(Vector3D,increment){
	Vector3D a(M_PI,0,0);
	a += 2*a;
	EXPECT_DOUBLE_EQ (3*M_PI,a.X());
}


TEST(Vector3D,decrement){
	Vector3D a(M_PI,0,0);
	a -= 2*a;
	EXPECT_DOUBLE_EQ (-M_PI,a.X());
}

TEST(Vector3D,ScalarDecomposition){
	Vector3D a(1,0,0);
	Vector3D b(0,1,0);
	Vector3D c(0,0,1);
	Vector3D d(5*M_PI,-7*M_PI,13*M_PI);

	EXPECT_DOUBLE_EQ (5*M_PI,d*a);
	EXPECT_DOUBLE_EQ (-7*M_PI,d*b);
	EXPECT_DOUBLE_EQ (13*M_PI,d*c);
}

TEST(Vector3D,VectorialRandom){
	Vector3D a(M_PI,2*M_PI,M_PI/2);
	Vector3D b(M_PI/6,M_PI/3,M_PI/4);

	Vector3D pvExpected = a^b;

	EXPECT_DOUBLE_EQ (a.Y()*b.Z()-a.Z()*b.Y(),pvExpected.X());
	EXPECT_DOUBLE_EQ (a.Z()*b.X()-a.X()*b.Z(),pvExpected.Y());
	EXPECT_DOUBLE_EQ (a.X()*b.Y()-a.Y()*b.X(),pvExpected.Z());
}


