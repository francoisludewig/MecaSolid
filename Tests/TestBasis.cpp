#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Basis/Basis.h"
#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Meca::Libs::Basis;


TEST(Basis,Constructor){
	Basis a;
	Quaternion q = a.Q();

	ASSERT_EQ (1,q.Q0());
	ASSERT_EQ (0,q.Q1());
	ASSERT_EQ (0,q.Q2());
	ASSERT_EQ (0,q.Q3());


	Vector3D o = a.O();
	ASSERT_EQ (0,o.X());
	ASSERT_EQ (0,o.Y());
	ASSERT_EQ (0,o.Z());


	Vector3D e1 = a.E1();
	ASSERT_EQ (1,e1.X());
	ASSERT_EQ (0,e1.Y());
	ASSERT_EQ (0,e1.Z());

	Vector3D e2 = a.E2();
	ASSERT_EQ (0,e2.X());
	ASSERT_EQ (1,e2.Y());
	ASSERT_EQ (0,e2.Z());

	Vector3D e3 = a.E3();
	ASSERT_EQ (0,e3.X());
	ASSERT_EQ (0,e3.Y());
	ASSERT_EQ (1,e3.Z());
}

TEST(Basis,translate){
	Basis a;
	Vector3D o;
	o.SetValue(M_PI,-M_PI/3,7*M_PI/6);
	a += o;

	ASSERT_TRUE(isEquals( a.O().X() , o.X() ));
	ASSERT_TRUE(isEquals( a.O().Y() , o.Y() ));
	ASSERT_TRUE(isEquals( a.O().Z() , o.Z() ));
}


TEST(Basis,rotate){
	Basis a,b;
	Vector3D w;
	w.SetValue(0,M_PI,0);
	Quaternion q(w);

	b = a*q;

	ASSERT_TRUE(isEquals( b.E1().X() , -a.E1().X() ));
	ASSERT_TRUE(isEquals( b.E1().Y() , -a.E1().Y() ));
	ASSERT_TRUE(isEquals( b.E1().Z() , -a.E1().Z() ));
	ASSERT_TRUE(isEquals( b.E2().X() , a.E2().X() ));
	ASSERT_TRUE(isEquals( b.E2().Y() , a.E2().Y() ));
	ASSERT_TRUE(isEquals( b.E2().Z() , a.E2().Z() ));
	ASSERT_TRUE(isEquals( b.E3().X() , -a.E3().X() ));
	ASSERT_TRUE(isEquals( b.E3().Y() , -a.E3().Y() ));
	ASSERT_TRUE(isEquals( b.E3().Z() , -a.E3().Z() ));
}


TEST(Basis,IO_Operator){
	Basis a;
	Basis b;

	a.Q(Quaternion(M_PI,2*M_PI,M_PI/2,M_PI/3));
	a.O(Vector3D(2*M_PI,M_PI/2,M_PI/3));

	ofstream fichierOut("testBasis.txt", ios::out | ios::trunc);
	if(fichierOut){
		fichierOut << a;
		fichierOut.close();
	}

	ifstream fichierIn("testBasis.txt", ios::in);
	if(fichierIn){
		fichierIn >> b;
		fichierIn.close();
	}

	Vector3D o_a = a.O();
	Vector3D o_b = b.O();

	ASSERT_TRUE(isEquals (o_a.X(),o_b.X()));
	ASSERT_TRUE(isEquals (o_a.Y(),o_b.Y()));
	ASSERT_TRUE(isEquals (o_a.Z(),o_b.Z()));

	Quaternion q_a = a.Q();
	Quaternion q_b = b.Q();

	ASSERT_TRUE(isEquals (q_a.Q0(),q_b.Q0()));
	ASSERT_TRUE(isEquals (q_a.Q1(),q_b.Q1()));
	ASSERT_TRUE(isEquals (q_a.Q2(),q_b.Q2()));
	ASSERT_TRUE(isEquals (q_a.Q3(),q_b.Q3()));

	remove("testBasis.txt");
}
