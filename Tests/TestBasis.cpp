#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Utils/Basis.h"
#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;

TEST(Basis,Constructor){
	Basis a;
	Quaternion q = a.Orientation();

	ASSERT_EQ (1,q.ComponantReal());
	ASSERT_EQ (0,q.ComponantI());
	ASSERT_EQ (0,q.ComponantJ());
	ASSERT_EQ (0,q.ComponantK());

	Point o = a.Origin();
	ASSERT_EQ (0,o.CoordinateX());
	ASSERT_EQ (0,o.CoordinateY());
	ASSERT_EQ (0,o.CoordinateZ());


	Vector3D e1 = a.AxisX();
	ASSERT_EQ (1,e1.ComponantX());
	ASSERT_EQ (0,e1.ComponantY());
	ASSERT_EQ (0,e1.ComponantZ());

	Vector3D e2 = a.AxisY();
	ASSERT_EQ (0,e2.ComponantX());
	ASSERT_EQ (1,e2.ComponantY());
	ASSERT_EQ (0,e2.ComponantZ());

	Vector3D e3 = a.AxisZ();
	ASSERT_EQ (0,e3.ComponantX());
	ASSERT_EQ (0,e3.ComponantY());
	ASSERT_EQ (1,e3.ComponantZ());
}

TEST(Basis,ConstructorID){
	Basis a,b,c;

	ASSERT_FALSE(a.ID() == b.ID());
	ASSERT_FALSE(a.ID() == c.ID());
	ASSERT_FALSE(c.ID() == b.ID());
}


TEST(Basis,translate){
	Basis a;
	Vector3D o;
	o.SetComponants(M_PI,-M_PI/3,7*M_PI/6);
	a += o;

	ASSERT_TRUE(isEquals( a.Origin().CoordinateX() , o.ComponantX() ));
	ASSERT_TRUE(isEquals( a.Origin().CoordinateY() , o.ComponantY() ));
	ASSERT_TRUE(isEquals( a.Origin().CoordinateZ() , o.ComponantZ() ));
}


TEST(Basis,rotate){
	Basis a,b;
	Vector3D w;
	w.SetComponants(0,M_PI,0);
	Quaternion q(w);

	b = a*q;

	ASSERT_TRUE(isEquals( b.AxisX().ComponantX() , -a.AxisX().ComponantX() ));
	ASSERT_TRUE(isEquals( b.AxisX().ComponantY() , -a.AxisX().ComponantY() ));
	ASSERT_TRUE(isEquals( b.AxisX().ComponantZ() , -a.AxisX().ComponantZ() ));
	ASSERT_TRUE(isEquals( b.AxisY().ComponantX() , a.AxisY().ComponantX() ));
	ASSERT_TRUE(isEquals( b.AxisY().ComponantY() , a.AxisY().ComponantY() ));
	ASSERT_TRUE(isEquals( b.AxisY().ComponantZ() , a.AxisY().ComponantZ() ));
	ASSERT_TRUE(isEquals( b.AxisZ().ComponantX() , -a.AxisZ().ComponantX() ));
	ASSERT_TRUE(isEquals( b.AxisZ().ComponantY() , -a.AxisZ().ComponantY() ));
	ASSERT_TRUE(isEquals( b.AxisZ().ComponantZ() , -a.AxisZ().ComponantZ() ));

	a*=q;

	ASSERT_TRUE(isEquals( b.AxisX().ComponantX() , a.AxisX().ComponantX() ));
	ASSERT_TRUE(isEquals( b.AxisX().ComponantY() , a.AxisX().ComponantY() ));
	ASSERT_TRUE(isEquals( b.AxisX().ComponantZ() , a.AxisX().ComponantZ() ));
	ASSERT_TRUE(isEquals( b.AxisY().ComponantX() , a.AxisY().ComponantX() ));
	ASSERT_TRUE(isEquals( b.AxisY().ComponantY() , a.AxisY().ComponantY() ));
	ASSERT_TRUE(isEquals( b.AxisY().ComponantZ() , a.AxisY().ComponantZ() ));
	ASSERT_TRUE(isEquals( b.AxisZ().ComponantX() , a.AxisZ().ComponantX() ));
	ASSERT_TRUE(isEquals( b.AxisZ().ComponantY() , a.AxisZ().ComponantY() ));
	ASSERT_TRUE(isEquals( b.AxisZ().ComponantZ() , a.AxisZ().ComponantZ() ));
}


TEST(Basis,LocalGlobal){
	Basis a,b;
	Quaternion q(Vector3D(0,M_PI,0));
	b = a*q;
	Vector3D v(M_PI,M_PI/3,M_PI/7);
	b.Local(v);

	ASSERT_TRUE(isEquals( v.ComponantX() , -M_PI ));
	ASSERT_TRUE(isEquals( v.ComponantY() , M_PI/3 ));
	ASSERT_TRUE(isEquals( v.ComponantZ() , -M_PI/7 ));

	b.Global(v);

	ASSERT_TRUE(isEquals( v.ComponantX() , M_PI ));
	ASSERT_TRUE(isEquals( v.ComponantY() , M_PI/3 ));
	ASSERT_TRUE(isEquals( v.ComponantZ() , M_PI/7 ));
}


TEST(Basis,Construct){
	Basis a;
	Vector3D u(2*M_PI,M_PI/2,M_PI/3);
	a.AxisX(u);
	Vector3D n,t,s;
	n = a.AxisX();
	t = a.AxisY();
	s = a.AxisZ();

	ASSERT_TRUE(isEquals(0,n*t));
	ASSERT_TRUE(isEquals(0,n*s));
	ASSERT_TRUE(isEquals(0,s*t));

	ASSERT_TRUE(isEquals(1,n.Norme()));
	ASSERT_TRUE(isEquals(1,t.Norme()));
	ASSERT_TRUE(isEquals(1,s.Norme()));

}




TEST(Basis,IO_Operator){
	Basis a;
	Basis b;
	Quaternion q(M_PI,2*M_PI,M_PI/2,M_PI/3);
	Point p(2*M_PI,M_PI/2,M_PI/3);
	a.Orientation(q);
	a.Origin(p);

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

	Point o_a = a.Origin();
	Point o_b = b.Origin();

	ASSERT_TRUE(isEquals (o_a.CoordinateX(),o_b.CoordinateX()));
	ASSERT_TRUE(isEquals (o_a.CoordinateY(),o_b.CoordinateY()));
	ASSERT_TRUE(isEquals (o_a.CoordinateZ(),o_b.CoordinateZ()));

	Quaternion q_a = a.Orientation();
	Quaternion q_b = b.Orientation();

	ASSERT_TRUE(isEquals (q_a.ComponantReal(),q_b.ComponantReal()));
	ASSERT_TRUE(isEquals (q_a.ComponantI(),q_b.ComponantI()));
	ASSERT_TRUE(isEquals (q_a.ComponantJ(),q_b.ComponantJ()));
	ASSERT_TRUE(isEquals (q_a.ComponantK(),q_b.ComponantK()));

	remove("testBasis.txt");
}
