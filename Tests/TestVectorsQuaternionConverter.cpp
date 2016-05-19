#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Utils/VectorsQuaternionConverter.h"
#include "Utils/Quaternion.h"
#include "Utils/Vector3D.h"
#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;


TEST(VectorsQuaternionConverter,DefaultQuaternion){
	VectorsQuaternionConverter vqc;
	Quaternion q;
	Vector3D x(0,0,0),y(0,0,0),z(0,0,0);

	vqc.ConvertQuaternionIntoVectors(q,x,y,z);

	ASSERT_EQ (1,x.X());
	ASSERT_EQ (0,x.Y());
	ASSERT_EQ (0,x.Z());

	ASSERT_EQ (0,y.X());
	ASSERT_EQ (1,y.Y());
	ASSERT_EQ (0,y.Z());

	ASSERT_EQ (0,z.X());
	ASSERT_EQ (0,z.Y());
	ASSERT_EQ (1,z.Z());
}


TEST(VectorsQuaternionConverter,DefaultVectors){
	VectorsQuaternionConverter vqc;
	Quaternion q(0,0,0,0);
	Vector3D x(1,0,0),y(0,1,0),z(0,0,1);

	vqc.ConvertVectorsIntoQuaternion(x,y,z,q);

	ASSERT_EQ (1,q.Q0());
	ASSERT_EQ (0,q.Q1());
	ASSERT_EQ (0,q.Q2());
	ASSERT_EQ (0,q.Q3());
}


TEST(VectorsQuaternionConverter,QuatVectorsQuat){
	VectorsQuaternionConverter vqc;
	Quaternion q(M_PI,M_PI/7,-M_PI/5,3*M_PI/2),p;
	Vector3D x,y,z;

	q.Normalize();

	vqc.ConvertQuaternionIntoVectors(q,x,y,z);

	ASSERT_TRUE(isEquals (1,x.Norme()));
	ASSERT_TRUE(isEquals (1,y.Norme()));
	ASSERT_TRUE(isEquals (1,z.Norme()));

	vqc.ConvertVectorsIntoQuaternion(x,y,z,p);

	ASSERT_TRUE(isEquals(q.Q0(),p.Q0()));
	ASSERT_TRUE (isEquals(q.Q1(),p.Q1()));
	ASSERT_TRUE (isEquals(q.Q2(),p.Q2()));
	ASSERT_TRUE (isEquals(q.Q3(),p.Q3()));
}

TEST(VectorsQuaternionConverter,VectorsQuaternionVectors){
	VectorsQuaternionConverter vqc;
	Quaternion q;
	Vector3D x(M_PI/7,0,-3*M_PI/5),y(0,M_PI,0),z = x^y,n,t,s;

	x/= x.Norme();
	y/= y.Norme();
	z/= z.Norme();

	vqc.ConvertVectorsIntoQuaternion(x,y,z,q);
	ASSERT_TRUE(isEquals (1,q.Norme()));
	vqc.ConvertQuaternionIntoVectors(q,n,t,s);

	ASSERT_TRUE(isEquals (1,n.Norme()));
	ASSERT_TRUE(isEquals (1,t.Norme()));
	ASSERT_TRUE(isEquals (1,s.Norme()));

	ASSERT_TRUE(isEquals (x.X(),n.X()));
	ASSERT_TRUE(isEquals (x.Y(),n.Y()));
	ASSERT_TRUE(isEquals (x.Z(),n.Z()));

	ASSERT_TRUE(isEquals (y.X(),t.X()));
	ASSERT_TRUE(isEquals (y.Y(),t.Y()));
	ASSERT_TRUE(isEquals (y.Z(),t.Z()));

	ASSERT_TRUE(isEquals (z.X(),s.X()));
	ASSERT_TRUE(isEquals (z.Y(),s.Y()));
	ASSERT_TRUE(isEquals (z.Z(),s.Z()));
}
