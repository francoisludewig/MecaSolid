#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Basis/UnitQuaternion.h"
#include "Basis/Vector3D.h"
#include "Resource/DoublePrecision.h"
using namespace std;
using namespace Meca::Libs::Basis;


TEST(UnitQuaternion,Constructor){
	UnitQuaternion a;
	ASSERT_EQ (1,a.Q0());
	ASSERT_EQ (0,a.Q1());
	ASSERT_EQ (0,a.Q2());
	ASSERT_EQ (0,a.Q3());
}

TEST(UnitQuaternion,ConstructorValue){
	UnitQuaternion a(1,1,1,1);
	ASSERT_EQ (0.5,a.Q0());
	ASSERT_EQ (0.5,a.Q1());
	ASSERT_EQ (0.5,a.Q2());
	ASSERT_EQ (0.5,a.Q3());
}

TEST(UnitQuaternion,ConstructorVector3D){
	Vector3D w(M_PI,0,0);
	UnitQuaternion a(w);

	ASSERT_TRUE(isEquals(0,a.Q0()));
	ASSERT_TRUE(isEquals(1.,a.Q1()));
	ASSERT_TRUE(isEquals(0.,a.Q2()));
	ASSERT_TRUE(isEquals(0.,a.Q3()));
}


TEST(UnitQuaternion,multiplication){
	UnitQuaternion a,b,c;
	a.SetValue(M_PI,2*M_PI,M_PI/2,M_PI/3);
	b.SetValue(6*M_PI,M_PI/4.,M_PI/6,M_PI);
	c = a*b;

	ASSERT_EQ (c.Q0(),a.Q0()*b.Q0() - a.Q1()*b.Q1() - a.Q2()*b.Q2() - a.Q3()*b.Q3());
	ASSERT_EQ (c.Q1(),a.Q0()*b.Q1() + a.Q1()*b.Q0() - a.Q2()*b.Q3() + a.Q3()*b.Q2());
	ASSERT_EQ (c.Q2(),a.Q0()*b.Q2() + a.Q1()*b.Q3() + a.Q2()*b.Q0() - a.Q3()*b.Q1());
	ASSERT_EQ (c.Q3(),a.Q0()*b.Q3() - a.Q1()*b.Q2() + a.Q2()*b.Q1() + a.Q3()*b.Q0());

}


TEST(UnitQuaternion,multiplicationOperator){
	UnitQuaternion a;
	a.SetValue(0.5,0.5,0.5,0.5);
	UnitQuaternion b,c;

	c = a*b;
	ASSERT_EQ (c.Q0(),a.Q0());
	ASSERT_EQ (c.Q1(),a.Q1());
	ASSERT_EQ (c.Q2(),a.Q2());
	ASSERT_EQ (c.Q3(),a.Q3());

	c = b*a;
	ASSERT_EQ (c.Q0(),a.Q0());
	ASSERT_EQ (c.Q1(),a.Q1());
	ASSERT_EQ (c.Q2(),a.Q2());
	ASSERT_EQ (c.Q3(),a.Q3());

	a*=b;
	ASSERT_EQ (0.5,a.Q0());
	ASSERT_EQ (0.5,a.Q1());
	ASSERT_EQ (0.5,a.Q2());
	ASSERT_EQ (0.5,a.Q3());
}


TEST(UnitQuaternion,conjuguation){
	UnitQuaternion a;
	a.SetValue(0.5,0.5,0.5,0.5);
	UnitQuaternion b;
	b = ~a;

	ASSERT_EQ (b.Q0(),a.Q0());
	ASSERT_EQ (b.Q1(),-a.Q1());
	ASSERT_EQ (b.Q2(),-a.Q2());
	ASSERT_EQ (b.Q3(),-a.Q3());
}



TEST(UnitQuaternion,conjuguationAndMultiplication){
	UnitQuaternion a;
	a.SetValue(0.5,0.5,0.5,0.5);
	UnitQuaternion b,c;
	b = ~a;
	c = a*b;

	ASSERT_EQ (1,c.Q0());
	ASSERT_EQ (0,c.Q1());
	ASSERT_EQ (0,c.Q2());
	ASSERT_EQ (0,c.Q3());
}



TEST(UnitQuaternion,IO_Operator){
	UnitQuaternion a;
	a.SetValue(M_PI,2*M_PI,M_PI/2,M_PI/3);
	UnitQuaternion b;

	ofstream fichierOut("testUnitQuaternion.txt", ios::out | ios::trunc);
	if(fichierOut){
		fichierOut << a;
		fichierOut.close();
	}

	ifstream fichierIn("testUnitQuaternion.txt", ios::in);
	if(fichierIn){
		fichierIn >> b;
		fichierIn.close();
	}

	EXPECT_DOUBLE_EQ (a.Q0(),b.Q0());
	EXPECT_DOUBLE_EQ (a.Q1(),b.Q1());
	EXPECT_DOUBLE_EQ (a.Q2(),b.Q2());
	EXPECT_DOUBLE_EQ (a.Q3(),b.Q3());

	remove("testUnitQuaternion.txt");
}

