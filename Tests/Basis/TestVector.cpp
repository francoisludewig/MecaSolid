#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Vector.h"
#include "Error.h"
#include "../Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;


TEST(Vector,Constructor){
	Vector a;
	ASSERT_EQ (0,a.ComponantX());
	ASSERT_EQ (0,a.ComponantY());
	ASSERT_EQ (0,a.ComponantZ());
}

TEST(Vector,ConstructorValue){
	Vector a(1,2,3);
	ASSERT_EQ (1,a.ComponantX());
	ASSERT_EQ (2,a.ComponantY());
	ASSERT_EQ (3,a.ComponantZ());

	Vector b(M_PI,2*M_PI,M_PI/2);
	ASSERT_EQ (M_PI,b.ComponantX());
	ASSERT_EQ (2*M_PI,b.ComponantY());
	ASSERT_EQ (M_PI/2,b.ComponantZ());
}

TEST(Vector,Norme){
	Vector a(1,2,3);
	ASSERT_EQ (sqrt(14.),a.Norme());
}


TEST(Vector,Normalize){
	Vector a(1,2,3),b = a;
	a.Normalize();
	ASSERT_EQ(1,a.Norme());
	Vector pv = a^b;

	ASSERT_TRUE(pv == Vector(0,0,0));
}

TEST(Vector,ScalarProduct){
	Vector a(1,0,0);
	Vector b(0,1,0);
	Vector c(0,0,1);

	ASSERT_EQ (0,a*b);
	ASSERT_EQ (0,a*c);
	ASSERT_EQ (0,b*c);
	ASSERT_EQ (1,a*a);
	ASSERT_EQ (1,b*b);
	ASSERT_EQ (1,c*c);
}


TEST(Vector,VectorialProduct){
	Vector a(1,0,0);
	Vector b(0,1,0);
	Vector c(0,0,1);

	Vector expectedC = a^b;
	Vector expectedA = b^c;
	Vector expectedB = c^a;

	ASSERT_TRUE(c == expectedC);
	ASSERT_TRUE(a == expectedA);
	ASSERT_TRUE(b == expectedB);
}


TEST(Vector,Product){
	Vector a(1,-2,3);
	Vector b(6,9,-7);

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


TEST(Vector,ProductUnit){
	Vector a(M_PI,2*M_PI,M_PI/2);
	Vector b(a.ComponantY()*a.ComponantZ(),a.ComponantX()*a.ComponantZ(),-2*a.ComponantX()*a.ComponantY());
	a.Normalize();
	b.Normalize();
	Vector c = a^b;

	ASSERT_TRUE(isEquals(0,c*a));
	ASSERT_TRUE(isEquals(0,c*b));
	ASSERT_TRUE(isEquals(1,c.Norme()));
}


TEST(Vector,MultiplicationEqual){
	Vector a(5,17,-57);
	double b = -13;
	Vector c = a*b;
	a *=b;

	ASSERT_TRUE(isEquals(a.ComponantX(),c.ComponantX()));
	ASSERT_TRUE(isEquals(a.ComponantY(),c.ComponantY()));
	ASSERT_TRUE(isEquals(a.ComponantZ(),c.ComponantZ()));
}


TEST(Vector,IO_Operator){
	Vector a(M_PI,2*M_PI,M_PI/2);
	Vector b;

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

TEST(Vector,Sum){
	Vector a(M_PI,2*M_PI,M_PI/2);
	Vector b(7*M_PI,-2*M_PI,-4*M_PI/2);
	Vector c = a+b;

	EXPECT_DOUBLE_EQ (a.ComponantX()+b.ComponantX(),c.ComponantX());
	EXPECT_DOUBLE_EQ (a.ComponantY()+b.ComponantY(),c.ComponantY());
	EXPECT_DOUBLE_EQ (a.ComponantZ()+b.ComponantZ(),c.ComponantZ());
}


TEST(Vector,Diff){
	Vector a(M_PI,2*M_PI,M_PI/2);
	Vector b(7*M_PI,2*M_PI,-4*M_PI/2);
	Vector c = a-b;

	EXPECT_DOUBLE_EQ (a.ComponantX()-b.ComponantX(),c.ComponantX());
	EXPECT_DOUBLE_EQ (a.ComponantY()-b.ComponantY(),c.ComponantY());
	EXPECT_DOUBLE_EQ (a.ComponantZ()-b.ComponantZ(),c.ComponantZ());
}

TEST(Vector,Div){
	Vector a(M_PI,2*M_PI,M_PI/2);
	double b = sqrt(2.);
	Vector c = a/b;

	EXPECT_DOUBLE_EQ (a.ComponantX()/b,c.ComponantX());
	EXPECT_DOUBLE_EQ (a.ComponantY()/b,c.ComponantY());
	EXPECT_DOUBLE_EQ (a.ComponantZ()/b,c.ComponantZ());
}


TEST(Vector,DivEqual){
	Vector a(M_PI,2*M_PI,M_PI/2);
	double b = sqrt(2.);
	Vector c = a/b;
	a /=b;
	EXPECT_DOUBLE_EQ (a.ComponantX(),c.ComponantX());
	EXPECT_DOUBLE_EQ (a.ComponantY(),c.ComponantY());
	EXPECT_DOUBLE_EQ (a.ComponantZ(),c.ComponantZ());
}


TEST(Vector,LinearCombination){
	Vector a(1,0,0);
	Vector b(0,1,0);
	Vector c(0,0,1);

	Vector d = sqrt(3)*a+sqrt(5)*b-sqrt(7)*c;
	EXPECT_DOUBLE_EQ (sqrt(3.0),d.ComponantX());
	EXPECT_DOUBLE_EQ (sqrt(5.0),d.ComponantY());
	EXPECT_DOUBLE_EQ (-sqrt(7.0),d.ComponantZ());
}


TEST(Vector,increment){
	Vector a(M_PI,0,0);
	a += 2*a;
	EXPECT_DOUBLE_EQ (3*M_PI,a.ComponantX());
}


TEST(Vector,decrement){
	Vector a(M_PI,0,0);
	a -= 2*a;
	EXPECT_DOUBLE_EQ (-M_PI,a.ComponantX());
}

TEST(Vector,ScalarDecomposition){
	Vector a(1,0,0);
	Vector b(0,1,0);
	Vector c(0,0,1);
	Vector d(5*M_PI,-7*M_PI,13*M_PI);

	EXPECT_DOUBLE_EQ (5*M_PI,d*a);
	EXPECT_DOUBLE_EQ (-7*M_PI,d*b);
	EXPECT_DOUBLE_EQ (13*M_PI,d*c);
}

TEST(Vector,VectorialRandom){
	Vector a(M_PI,2*M_PI,M_PI/2);
	Vector b(M_PI/6,M_PI/3,M_PI/4);

	Vector pvExpected = a^b;

	EXPECT_DOUBLE_EQ (a.ComponantY()*b.ComponantZ()-a.ComponantZ()*b.ComponantY(),pvExpected.ComponantX());
	EXPECT_DOUBLE_EQ (a.ComponantZ()*b.ComponantX()-a.ComponantX()*b.ComponantZ(),pvExpected.ComponantY());
	EXPECT_DOUBLE_EQ (a.ComponantX()*b.ComponantY()-a.ComponantY()*b.ComponantX(),pvExpected.ComponantZ());
}

TEST(Vector,sumForDifferentBasisId){
	Vector a(M_PI,2*M_PI,M_PI/2,0);
	Vector b(M_PI/6,M_PI/3,M_PI/4,1);
	try{
		Vector c = a+b;
		FAIL();
	}catch(Error & error){
		EXPECT_EQ("Summing vectors from different basis !",error.Message());
	}
}


TEST(Vector,diffForDifferentBasisId){
	Vector a(M_PI,2*M_PI,M_PI/2,0);
	Vector b(M_PI/6,M_PI/3,M_PI/4,1);
	try{
		Vector c = a-b;
		FAIL();
	}catch(Error &error){
		EXPECT_EQ("Differencing vectors from different basis !",error.Message());
	}
}


TEST(Vector,incrSumForDifferentBasisId){
	Vector a(M_PI,2*M_PI,M_PI/2,0);
	Vector b(M_PI/6,M_PI/3,M_PI/4,1);
	Vector c = a;
	try{
		a+=b;
		FAIL();
	}catch(Error &error){
		EXPECT_EQ("Summing vectors from different basis !",error.Message());
		EXPECT_EQ(0,error.Level());
	}
}


TEST(Vector,incrDiffForDifferentBasisId){
	Vector a(M_PI,2*M_PI,M_PI/2,0);
	Vector b(M_PI/6,M_PI/3,M_PI/4,1);
	Vector c = a;
	try{
		a-=b;
		FAIL();
	}catch(Error & error){
		EXPECT_EQ("Differencing vectors from different basis !",error.Message());
	}
}


TEST(Vector,CrossProductForDifferentBasisId){
	Vector a(M_PI,2*M_PI,M_PI/2,0);
	Vector b(M_PI/6,M_PI/3,M_PI/4,1);
	try{
		Vector c = a^b;
		FAIL();
	}catch(Error & error){
		EXPECT_EQ("Cross product of vectors from different basis !",error.Message());
	}
}


TEST(Vector,ScalarProductForDifferentBasisId){
	Vector a(M_PI,2*M_PI,M_PI/2,0);
	Vector b(M_PI/6,M_PI/3,M_PI/4,1);
	try{
		double c = a*b;
		FAIL();
	}catch(Error & error){
		EXPECT_EQ("Scalar product of vectors from different basis !",error.Message());
	}
}

