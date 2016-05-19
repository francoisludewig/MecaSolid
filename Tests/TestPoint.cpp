#include <Utils/Segment.h>

#include <gtest/gtest.h>
#include <cmath>
#include <fstream>


#include "Utils/Vector3D.h"
#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;



TEST(Point,Constructor){
	Point a;

	ASSERT_EQ (0,a.X());
	ASSERT_EQ (0,a.Y());
	ASSERT_EQ (0,a.Z());
}

TEST(Point,Constructor2){
	Point a(M_PI,2*M_PI,M_PI/5);

	ASSERT_EQ (M_PI, a.X());
	ASSERT_EQ (2*M_PI,a.Y());
	ASSERT_EQ (M_PI/5,a.Z());
}


TEST(Point,Calculus){
	Point a(M_PI   ,2*M_PI,M_PI/5);
	Point b(-3*M_PI,M_PI  ,4*M_PI/5);

	Vector3D c = b-a;

	ASSERT_TRUE(isEquals(-4*M_PI , c.X()));
	ASSERT_TRUE(isEquals(-M_PI   , c.Y()));
	ASSERT_TRUE(isEquals(3*M_PI/5, c.Z()));

	Point d = a + c;

	ASSERT_TRUE(isEquals(d.X(), b.X()));
	ASSERT_TRUE(isEquals(d.Y(), b.Y()));
	ASSERT_TRUE(isEquals(d.Z(), b.Z()));

	a += c;

	ASSERT_TRUE(isEquals(a.X(), b.X()));
	ASSERT_TRUE(isEquals(a.Y(), b.Y()));
	ASSERT_TRUE(isEquals(a.Z(), b.Z()));
}


TEST(Point,IO_Operator){
	Point a(M_PI,2*M_PI,M_PI/5);
	Point b;

	ofstream fichierOut("testPoint.txt", ios::out | ios::trunc);
	if(fichierOut){
		fichierOut << a;
		fichierOut.close();
	}

	ifstream fichierIn("testPoint.txt", ios::in);
	if(fichierIn){
		fichierIn >> b;
		fichierIn.close();
	}

	ASSERT_EQ (b.X(), a.X());
	ASSERT_EQ (b.Y(), a.Y());
	ASSERT_EQ (b.Z(), a.Z());

	remove("testPoint.txt");
}
