#include <Basis/Quaternion.h>

#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Basis/Vector3D.h"
#include "Resource/DoublePrecision.h"
using namespace std;
using namespace Meca::Libs::Basis;


TEST(Quaternion,Constructor){
	Quaternion a;
	ASSERT_EQ (1,a.Q0());
	ASSERT_EQ (0,a.Q1());
	ASSERT_EQ (0,a.Q2());
	ASSERT_EQ (0,a.Q3());
}

TEST(Quaternion,ConstructorValue){
	Quaternion a(M_PI,2*M_PI,M_PI/2,M_PI/3);
	ASSERT_EQ (M_PI,a.Q0());
	ASSERT_EQ (2*M_PI,a.Q1());
	ASSERT_EQ (M_PI/2,a.Q2());
	ASSERT_EQ (M_PI/3,a.Q3());
}

TEST(Quaternion,ConstructorVector3D){
	Vector3D w(M_PI,0,0);
	Quaternion a(w);

	ASSERT_TRUE(isEquals(0,a.Q0()));
	ASSERT_TRUE(isEquals(1.,a.Q1()));
	ASSERT_TRUE(isEquals(0.,a.Q2()));
	ASSERT_TRUE(isEquals(0.,a.Q3()));
}


TEST(Quaternion,SetValue){
	Quaternion a;
	a.SetValue(0.5,0.5,0.5,0.5);
	ASSERT_EQ (0.5,a.Q0());
	ASSERT_EQ (0.5,a.Q1());
	ASSERT_EQ (0.5,a.Q2());
	ASSERT_EQ (0.5,a.Q3());
}



TEST(Quaternion,multiplication){
	Quaternion a,b,c;
	a.SetValue(M_PI,2*M_PI,M_PI/2,M_PI/3);
	b.SetValue(6*M_PI,M_PI/4.,M_PI/6,M_PI);
	c = a*b;

	ASSERT_EQ (c.Q0(),a.Q0()*b.Q0() - a.Q1()*b.Q1() - a.Q2()*b.Q2() - a.Q3()*b.Q3());
	ASSERT_EQ (c.Q1(),a.Q0()*b.Q1() + a.Q1()*b.Q0() - a.Q2()*b.Q3() + a.Q3()*b.Q2());
	ASSERT_EQ (c.Q2(),a.Q0()*b.Q2() + a.Q1()*b.Q3() + a.Q2()*b.Q0() - a.Q3()*b.Q1());
	ASSERT_EQ (c.Q3(),a.Q0()*b.Q3() - a.Q1()*b.Q2() + a.Q2()*b.Q1() + a.Q3()*b.Q0());
}


TEST(Quaternion,Sum){
	Quaternion a,b,c;
	a.SetValue(M_PI,2*M_PI,M_PI/2,M_PI/3);
	b.SetValue(6*M_PI,M_PI/4.,M_PI/6,M_PI);
	c = a+b;

	ASSERT_EQ (c.Q0(),a.Q0()+b.Q0());
	ASSERT_EQ (c.Q1(),a.Q1()+b.Q1());
	ASSERT_EQ (c.Q2(),a.Q2()+b.Q2());
	ASSERT_EQ (c.Q3(),a.Q3()+b.Q3());
}


TEST(Quaternion,Diff){
	Quaternion a,b,c;
	a.SetValue(M_PI,2*M_PI,M_PI/2,M_PI/3);
	b.SetValue(6*M_PI,M_PI/4.,M_PI/6,M_PI);
	c = a-b;

	ASSERT_EQ (c.Q0(),a.Q0()-b.Q0());
	ASSERT_EQ (c.Q1(),a.Q1()-b.Q1());
	ASSERT_EQ (c.Q2(),a.Q2()-b.Q2());
	ASSERT_EQ (c.Q3(),a.Q3()-b.Q3());
}



TEST(Quaternion,SumOperateurUnaire){
	Quaternion a,b;
	a.SetValue(M_PI,2*M_PI,M_PI/2,M_PI/3);
	b.SetValue(6*M_PI,M_PI/4.,M_PI/6,M_PI);
	a+=b;

	ASSERT_EQ (a.Q0(),7*M_PI);
	ASSERT_EQ (a.Q1(),9*M_PI/4);
	ASSERT_EQ (a.Q2(),2*M_PI/3);
	ASSERT_EQ (a.Q3(),4*M_PI/3);
}


TEST(Quaternion,DiffOperateurUnaire){
	Quaternion a,b;
	a.SetValue(M_PI   , 2*M_PI , M_PI/2 , M_PI/3);
	b.SetValue(6*M_PI , M_PI/4 , M_PI/6 , M_PI);
	a-=b;

	ASSERT_TRUE(isEquals(a.Q0(),-5*M_PI));
	ASSERT_TRUE(isEquals(a.Q1(),7*M_PI/4));
	ASSERT_TRUE(isEquals(a.Q2(),M_PI/3));
	ASSERT_TRUE(isEquals(a.Q3(),-2*M_PI/3));
}




TEST(Quaternion,SumConjugation){
	Quaternion a,c;
	a.SetValue(M_PI,2*M_PI,M_PI/2,M_PI/3);
	c = a+~a;

	ASSERT_EQ (c.Q0(),2*a.Q0());
	ASSERT_EQ (c.Q1(),0);
	ASSERT_EQ (c.Q2(),0);
	ASSERT_EQ (c.Q3(),0);
}


TEST(Quaternion,DiffConjugation){
	Quaternion a,c;
	a.SetValue(M_PI,2*M_PI,M_PI/2,M_PI/3);
	c = a-~a;

	ASSERT_EQ (c.Q0(),0);
	ASSERT_EQ (c.Q1(),2*a.Q1());
	ASSERT_EQ (c.Q2(),2*a.Q2());
	ASSERT_EQ (c.Q3(),2*a.Q3());
}



TEST(Quaternion,multiplicationOperator){
	Quaternion a;
	a.SetValue(0.5,0.5,0.5,0.5);
	Quaternion b,c;

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


TEST(Quaternion,conjuguation){
	Quaternion a;
	a.SetValue(0.5,0.5,0.5,0.5);
	Quaternion b;
	b = ~a;

	ASSERT_EQ (b.Q0(),a.Q0());
	ASSERT_EQ (b.Q1(),-a.Q1());
	ASSERT_EQ (b.Q2(),-a.Q2());
	ASSERT_EQ (b.Q3(),-a.Q3());
}


TEST(Quaternion,conjuguationAndMultiplication){
	Quaternion a;
	a.SetValue(0.5,0.5,0.5,0.5);
	Quaternion b,c;
	b = ~a;
	c = a*b;

	ASSERT_EQ (1,c.Q0());
	ASSERT_EQ (0,c.Q1());
	ASSERT_EQ (0,c.Q2());
	ASSERT_EQ (0,c.Q3());
}



TEST(Quaternion,IO_Operator){
	Quaternion a;
	a.SetValue(M_PI,2*M_PI,M_PI/2,M_PI/3);
	Quaternion b;

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

	ASSERT_TRUE(isEquals(a.Q0(),b.Q0()));
	ASSERT_TRUE(isEquals(a.Q1(),b.Q1()));
	ASSERT_TRUE(isEquals(a.Q2(),b.Q2()));
	ASSERT_TRUE(isEquals(a.Q3(),b.Q3()));

	remove("testUnitQuaternion.txt");
}

