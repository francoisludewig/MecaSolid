#include <Utils/Segment.h>
#include <Utils/Vector.h>

#include <gtest/gtest.h>
#include <cmath>
#include <fstream>


#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;



TEST(Point,Constructor){
	Point a;

	ASSERT_EQ (0,a.CoordinateX());
	ASSERT_EQ (0,a.CoordinateY());
	ASSERT_EQ (0,a.CoordinateZ());
}

TEST(Point,Constructor2){
	Point a(M_PI,2*M_PI,M_PI/5);

	ASSERT_EQ (M_PI, a.CoordinateX());
	ASSERT_EQ (2*M_PI,a.CoordinateY());
	ASSERT_EQ (M_PI/5,a.CoordinateZ());
}


TEST(Point,Calculus){
	Point a(M_PI   ,2*M_PI,M_PI/5);
	Point b(-3*M_PI,M_PI  ,4*M_PI/5);

	Vector c = b-a;

	ASSERT_TRUE(isEquals(-4*M_PI , c.ComponantX()));
	ASSERT_TRUE(isEquals(-M_PI   , c.ComponantY()));
	ASSERT_TRUE(isEquals(3*M_PI/5, c.ComponantZ()));

	Point d = a + c;

	ASSERT_TRUE(isEquals(d.CoordinateX(), b.CoordinateX()));
	ASSERT_TRUE(isEquals(d.CoordinateY(), b.CoordinateY()));
	ASSERT_TRUE(isEquals(d.CoordinateZ(), b.CoordinateZ()));

	a += c;

	ASSERT_TRUE(isEquals(a.CoordinateX(), b.CoordinateX()));
	ASSERT_TRUE(isEquals(a.CoordinateY(), b.CoordinateY()));
	ASSERT_TRUE(isEquals(a.CoordinateZ(), b.CoordinateZ()));
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

	ASSERT_EQ (b.CoordinateX(), a.CoordinateX());
	ASSERT_EQ (b.CoordinateY(), a.CoordinateY());
	ASSERT_EQ (b.CoordinateZ(), a.CoordinateZ());

	remove("testPoint.txt");
}
