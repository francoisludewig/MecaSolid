#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Utils/Vector3D.h"
#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;


TEST(Vector3D,Constructor){
	Vector3D a;
	ASSERT_EQ (0,a.ComponantX());
	ASSERT_EQ (0,a.ComponantY());
	ASSERT_EQ (0,a.ComponantZ());
}


TEST(Vector3D,ConstructorValue){
	Vector3D a(1,2,3);
	ASSERT_EQ (1,a.ComponantX());
	ASSERT_EQ (2,a.ComponantY());
	ASSERT_EQ (3,a.ComponantZ());

	Vector3D b(M_PI,2*M_PI,M_PI/2);
	ASSERT_EQ (M_PI,b.ComponantX());
	ASSERT_EQ (2*M_PI,b.ComponantY());
	ASSERT_EQ (M_PI/2,b.ComponantZ());
}

TEST(Vector3D,Norme){
	Vector3D a(1,2,3);
	ASSERT_EQ (sqrt(14.),a.Norme());
}


TEST(Vector3D,Normalize){
	Vector3D a(1,2,3),b = a;
	a.Normalize();
	ASSERT_EQ(1,a.Norme());
	Vector3D pv = a^b;
	ASSERT_EQ(0,pv.ComponantX());
	ASSERT_EQ(0,pv.ComponantY());
	ASSERT_EQ(0,pv.ComponantZ());
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

	ASSERT_EQ (c.ComponantX(),expectedC.ComponantX());
	ASSERT_EQ (c.ComponantY(),expectedC.ComponantY());
	ASSERT_EQ (c.ComponantZ(),expectedC.ComponantZ());

	ASSERT_EQ (a.ComponantX(),expectedA.ComponantX());
	ASSERT_EQ (a.ComponantY(),expectedA.ComponantY());
	ASSERT_EQ (a.ComponantZ(),expectedA.ComponantZ());

	ASSERT_EQ (b.ComponantX(),expectedB.ComponantX());
	ASSERT_EQ (b.ComponantY(),expectedB.ComponantY());
	ASSERT_EQ (b.ComponantZ(),expectedB.ComponantZ());
}


TEST(Vector3D,Product){
	Vector3D a(1,-2,3);
	Vector3D b(6,9,-7);

	ASSERT_TRUE(isEquals(0,a*(a^b)));
	ASSERT_TRUE(isEquals(0,b*(a^b)));
	ASSERT_TRUE(isEquals(0,a*(b^a)));
	ASSERT_TRUE(isEquals(0,b*(b^a)));

	a.SetComponants(0,0,0);
	b.SetComponants(1,3,1);

	ASSERT_TRUE(isEquals(0,a*(a^b)));
	ASSERT_TRUE(isEquals(0,b*(a^b)));
	ASSERT_TRUE(isEquals(0,a*(b^a)));
	ASSERT_TRUE(isEquals(0,b*(b^a)));
}


TEST(Vector3D,ProductUnit){
	Vector3D a(M_PI,2*M_PI,M_PI/2);
	Vector3D b(a.ComponantY()*a.ComponantZ(),a.ComponantX()*a.ComponantZ(),-2*a.ComponantX()*a.ComponantY());
	a.Normalize();
	b.Normalize();
	Vector3D c = a^b;

	ASSERT_TRUE(isEquals(0,c*a));
	ASSERT_TRUE(isEquals(0,c*b));
	ASSERT_TRUE(isEquals(1,c.Norme()));
}


TEST(Vector3D,MultiplicationEqual){
	Vector3D a(5,17,-57);
	double b = -13;
	Vector3D c = a*b;
	a *=b;
	ASSERT_TRUE(isEquals(a.ComponantX(),c.ComponantX()));
	ASSERT_TRUE(isEquals(a.ComponantY(),c.ComponantY()));
	ASSERT_TRUE(isEquals(a.ComponantZ(),c.ComponantZ()));
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

	EXPECT_DOUBLE_EQ (a.ComponantX(),b.ComponantX());
	EXPECT_DOUBLE_EQ (a.ComponantY(),b.ComponantY());
	EXPECT_DOUBLE_EQ (a.ComponantZ(),b.ComponantZ());

	remove("testVector3D.txt");
}

TEST(Vector3D,Sum){
	Vector3D a(M_PI,2*M_PI,M_PI/2);
	Vector3D b(7*M_PI,-2*M_PI,-4*M_PI/2);
	Vector3D c = a+b;

	EXPECT_DOUBLE_EQ (a.ComponantX()+b.ComponantX(),c.ComponantX());
	EXPECT_DOUBLE_EQ (a.ComponantY()+b.ComponantY(),c.ComponantY());
	EXPECT_DOUBLE_EQ (a.ComponantZ()+b.ComponantZ(),c.ComponantZ());
}


TEST(Vector3D,Diff){
	Vector3D a(M_PI,2*M_PI,M_PI/2);
	Vector3D b(7*M_PI,2*M_PI,-4*M_PI/2);
	Vector3D c = a-b;

	EXPECT_DOUBLE_EQ (a.ComponantX()-b.ComponantX(),c.ComponantX());
	EXPECT_DOUBLE_EQ (a.ComponantY()-b.ComponantY(),c.ComponantY());
	EXPECT_DOUBLE_EQ (a.ComponantZ()-b.ComponantZ(),c.ComponantZ());
}


TEST(Vector3D,Div){
	Vector3D a(M_PI,2*M_PI,M_PI/2);
	double b = sqrt(2.);
	Vector3D c = a/b;

	EXPECT_DOUBLE_EQ (a.ComponantX()/b,c.ComponantX());
	EXPECT_DOUBLE_EQ (a.ComponantY()/b,c.ComponantY());
	EXPECT_DOUBLE_EQ (a.ComponantZ()/b,c.ComponantZ());
}


TEST(Vector3D,DivEqual){
	Vector3D a(M_PI,2*M_PI,M_PI/2);
	double b = sqrt(2.);
	Vector3D c = a/b;
	a /=b;
	EXPECT_DOUBLE_EQ (a.ComponantX(),c.ComponantX());
	EXPECT_DOUBLE_EQ (a.ComponantY(),c.ComponantY());
	EXPECT_DOUBLE_EQ (a.ComponantZ(),c.ComponantZ());
}


TEST(Vector3D,LinearCombination){
	Vector3D a(1,0,0);
	Vector3D b(0,1,0);
	Vector3D c(0,0,1);

	Vector3D d = sqrt(3)*a+sqrt(5)*b-sqrt(7)*c;
	EXPECT_DOUBLE_EQ (sqrt(3.0),d.ComponantX());
	EXPECT_DOUBLE_EQ (sqrt(5.0),d.ComponantY());
	EXPECT_DOUBLE_EQ (-sqrt(7.0),d.ComponantZ());
}


TEST(Vector3D,increment){
	Vector3D a(M_PI,0,0);
	a += 2*a;
	EXPECT_DOUBLE_EQ (3*M_PI,a.ComponantX());
}


TEST(Vector3D,decrement){
	Vector3D a(M_PI,0,0);
	a -= 2*a;
	EXPECT_DOUBLE_EQ (-M_PI,a.ComponantX());
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

	EXPECT_DOUBLE_EQ (a.ComponantY()*b.ComponantZ()-a.ComponantZ()*b.ComponantY(),pvExpected.ComponantX());
	EXPECT_DOUBLE_EQ (a.ComponantZ()*b.ComponantX()-a.ComponantX()*b.ComponantZ(),pvExpected.ComponantY());
	EXPECT_DOUBLE_EQ (a.ComponantX()*b.ComponantY()-a.ComponantY()*b.ComponantX(),pvExpected.ComponantZ());
}


