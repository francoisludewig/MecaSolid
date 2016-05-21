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

	ASSERT_EQ (1,x.ComponantX());
	ASSERT_EQ (0,x.ComponantY());
	ASSERT_EQ (0,x.ComponantZ());

	ASSERT_EQ (0,y.ComponantX());
	ASSERT_EQ (1,y.ComponantY());
	ASSERT_EQ (0,y.ComponantZ());

	ASSERT_EQ (0,z.ComponantX());
	ASSERT_EQ (0,z.ComponantY());
	ASSERT_EQ (1,z.ComponantZ());
}


TEST(VectorsQuaternionConverter,DefaultVectors){
	VectorsQuaternionConverter vqc;
	Quaternion q(0,0,0,0);
	Vector3D x(1,0,0),y(0,1,0),z(0,0,1);

	vqc.ConvertVectorsIntoQuaternion(x,y,z,q);

	ASSERT_EQ (1,q.ComponantReal());
	ASSERT_EQ (0,q.ComponantI());
	ASSERT_EQ (0,q.ComponantJ());
	ASSERT_EQ (0,q.ComponantK());
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

	ASSERT_TRUE(isEquals(q.ComponantReal(),p.ComponantReal()));
	ASSERT_TRUE (isEquals(q.ComponantI(),p.ComponantI()));
	ASSERT_TRUE (isEquals(q.ComponantJ(),p.ComponantJ()));
	ASSERT_TRUE (isEquals(q.ComponantK(),p.ComponantK()));
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

	ASSERT_TRUE(isEquals (x.ComponantX(),n.ComponantX()));
	ASSERT_TRUE(isEquals (x.ComponantY(),n.ComponantY()));
	ASSERT_TRUE(isEquals (x.ComponantZ(),n.ComponantZ()));

	ASSERT_TRUE(isEquals (y.ComponantX(),t.ComponantX()));
	ASSERT_TRUE(isEquals (y.ComponantY(),t.ComponantY()));
	ASSERT_TRUE(isEquals (y.ComponantZ(),t.ComponantZ()));

	ASSERT_TRUE(isEquals (z.ComponantX(),s.ComponantX()));
	ASSERT_TRUE(isEquals (z.ComponantY(),s.ComponantY()));
	ASSERT_TRUE(isEquals (z.ComponantZ(),s.ComponantZ()));
}
