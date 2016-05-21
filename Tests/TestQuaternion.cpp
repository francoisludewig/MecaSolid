#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Utils/Quaternion.h"
#include "Utils/Vector3D.h"
#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;


TEST(Quaternion,Constructor){
	Quaternion a;
	ASSERT_EQ (1,a.ComponantReal());
	ASSERT_EQ (0,a.ComponantI());
	ASSERT_EQ (0,a.ComponantJ());
	ASSERT_EQ (0,a.ComponantK());
}

TEST(Quaternion,ConstructorValue){
	Quaternion a(M_PI,2*M_PI,M_PI/2,M_PI/3);
	ASSERT_EQ (M_PI,a.ComponantReal());
	ASSERT_EQ (2*M_PI,a.ComponantI());
	ASSERT_EQ (M_PI/2,a.ComponantJ());
	ASSERT_EQ (M_PI/3,a.ComponantK());
}

TEST(Quaternion,ConstructorVector3D){
	Vector3D w(M_PI,0,0);
	Quaternion a(w);

	ASSERT_TRUE(isEquals(0,a.ComponantReal()));
	ASSERT_TRUE(isEquals(1.,a.ComponantI()));
	ASSERT_TRUE(isEquals(0.,a.ComponantJ()));
	ASSERT_TRUE(isEquals(0.,a.ComponantK()));
}


TEST(Quaternion,SetComponants){
	Quaternion a;
	a.SetComponants(0.5,0.5,0.5,0.5);
	ASSERT_EQ (0.5,a.ComponantReal());
	ASSERT_EQ (0.5,a.ComponantI());
	ASSERT_EQ (0.5,a.ComponantJ());
	ASSERT_EQ (0.5,a.ComponantK());
}



TEST(Quaternion,multiplication){
	Quaternion a,b,c;
	a.SetComponants(M_PI,2*M_PI,M_PI/2,M_PI/3);
	b.SetComponants(6*M_PI,M_PI/4.,M_PI/6,M_PI);
	c = a*b;

	ASSERT_EQ (c.ComponantReal(),a.ComponantReal()*b.ComponantReal() - a.ComponantI()*b.ComponantI() - a.ComponantJ()*b.ComponantJ() - a.ComponantK()*b.ComponantK());
	ASSERT_EQ (c.ComponantI(),a.ComponantReal()*b.ComponantI() + a.ComponantI()*b.ComponantReal() - a.ComponantJ()*b.ComponantK() + a.ComponantK()*b.ComponantJ());
	ASSERT_EQ (c.ComponantJ(),a.ComponantReal()*b.ComponantJ() + a.ComponantI()*b.ComponantK() + a.ComponantJ()*b.ComponantReal() - a.ComponantK()*b.ComponantI());
	ASSERT_EQ (c.ComponantK(),a.ComponantReal()*b.ComponantK() - a.ComponantI()*b.ComponantJ() + a.ComponantJ()*b.ComponantI() + a.ComponantK()*b.ComponantReal());
}


TEST(Quaternion,Sum){
	Quaternion a,b,c;
	a.SetComponants(M_PI,2*M_PI,M_PI/2,M_PI/3);
	b.SetComponants(6*M_PI,M_PI/4.,M_PI/6,M_PI);
	c = a+b;

	ASSERT_EQ (c.ComponantReal(),a.ComponantReal()+b.ComponantReal());
	ASSERT_EQ (c.ComponantI(),a.ComponantI()+b.ComponantI());
	ASSERT_EQ (c.ComponantJ(),a.ComponantJ()+b.ComponantJ());
	ASSERT_EQ (c.ComponantK(),a.ComponantK()+b.ComponantK());
}


TEST(Quaternion,Diff){
	Quaternion a,b,c;
	a.SetComponants(M_PI,2*M_PI,M_PI/2,M_PI/3);
	b.SetComponants(6*M_PI,M_PI/4.,M_PI/6,M_PI);
	c = a-b;

	ASSERT_EQ (c.ComponantReal(),a.ComponantReal()-b.ComponantReal());
	ASSERT_EQ (c.ComponantI(),a.ComponantI()-b.ComponantI());
	ASSERT_EQ (c.ComponantJ(),a.ComponantJ()-b.ComponantJ());
	ASSERT_EQ (c.ComponantK(),a.ComponantK()-b.ComponantK());
}



TEST(Quaternion,SumOperateurUnaire){
	Quaternion a,b;
	a.SetComponants(M_PI,2*M_PI,M_PI/2,M_PI/3);
	b.SetComponants(6*M_PI,M_PI/4.,M_PI/6,M_PI);
	a+=b;

	ASSERT_EQ (a.ComponantReal(),7*M_PI);
	ASSERT_EQ (a.ComponantI(),9*M_PI/4);
	ASSERT_EQ (a.ComponantJ(),2*M_PI/3);
	ASSERT_EQ (a.ComponantK(),4*M_PI/3);
}


TEST(Quaternion,DiffOperateurUnaire){
	Quaternion a,b;
	a.SetComponants(M_PI   , 2*M_PI , M_PI/2 , M_PI/3);
	b.SetComponants(6*M_PI , M_PI/4 , M_PI/6 , M_PI);
	a-=b;

	ASSERT_TRUE(isEquals(a.ComponantReal(),-5*M_PI));
	ASSERT_TRUE(isEquals(a.ComponantI(),7*M_PI/4));
	ASSERT_TRUE(isEquals(a.ComponantJ(),M_PI/3));
	ASSERT_TRUE(isEquals(a.ComponantK(),-2*M_PI/3));
}




TEST(Quaternion,SumConjugation){
	Quaternion a,c;
	a.SetComponants(M_PI,2*M_PI,M_PI/2,M_PI/3);
	c = a+~a;

	ASSERT_EQ (c.ComponantReal(),2*a.ComponantReal());
	ASSERT_EQ (c.ComponantI(),0);
	ASSERT_EQ (c.ComponantJ(),0);
	ASSERT_EQ (c.ComponantK(),0);
}


TEST(Quaternion,DiffConjugation){
	Quaternion a,c;
	a.SetComponants(M_PI,2*M_PI,M_PI/2,M_PI/3);
	c = a-~a;

	ASSERT_EQ (c.ComponantReal(),0);
	ASSERT_EQ (c.ComponantI(),2*a.ComponantI());
	ASSERT_EQ (c.ComponantJ(),2*a.ComponantJ());
	ASSERT_EQ (c.ComponantK(),2*a.ComponantK());
}



TEST(Quaternion,multiplicationOperator){
	Quaternion a;
	a.SetComponants(0.5,0.5,0.5,0.5);
	Quaternion b,c;

	c = a*b;
	ASSERT_EQ (c.ComponantReal(),a.ComponantReal());
	ASSERT_EQ (c.ComponantI(),a.ComponantI());
	ASSERT_EQ (c.ComponantJ(),a.ComponantJ());
	ASSERT_EQ (c.ComponantK(),a.ComponantK());

	c = b*a;
	ASSERT_EQ (c.ComponantReal(),a.ComponantReal());
	ASSERT_EQ (c.ComponantI(),a.ComponantI());
	ASSERT_EQ (c.ComponantJ(),a.ComponantJ());
	ASSERT_EQ (c.ComponantK(),a.ComponantK());

	a*=b;
	ASSERT_EQ (0.5,a.ComponantReal());
	ASSERT_EQ (0.5,a.ComponantI());
	ASSERT_EQ (0.5,a.ComponantJ());
	ASSERT_EQ (0.5,a.ComponantK());
}


TEST(Quaternion,conjuguation){
	Quaternion a;
	a.SetComponants(0.5,0.5,0.5,0.5);
	Quaternion b;
	b = ~a;

	ASSERT_EQ (b.ComponantReal(),a.ComponantReal());
	ASSERT_EQ (b.ComponantI(),-a.ComponantI());
	ASSERT_EQ (b.ComponantJ(),-a.ComponantJ());
	ASSERT_EQ (b.ComponantK(),-a.ComponantK());
}


TEST(Quaternion,conjuguationAndMultiplication){
	Quaternion a;
	a.SetComponants(0.5,0.5,0.5,0.5);
	Quaternion b,c;
	b = ~a;
	c = a*b;

	ASSERT_EQ (1,c.ComponantReal());
	ASSERT_EQ (0,c.ComponantI());
	ASSERT_EQ (0,c.ComponantJ());
	ASSERT_EQ (0,c.ComponantK());
}



TEST(Quaternion,IO_Operator){
	Quaternion a;
	a.SetComponants(M_PI,2*M_PI,M_PI/2,M_PI/3);
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

	ASSERT_TRUE(isEquals(a.ComponantReal(),b.ComponantReal()));
	ASSERT_TRUE(isEquals(a.ComponantI(),b.ComponantI()));
	ASSERT_TRUE(isEquals(a.ComponantJ(),b.ComponantJ()));
	ASSERT_TRUE(isEquals(a.ComponantK(),b.ComponantK()));

	remove("testUnitQuaternion.txt");
}

