#include <Utils/Segment.h>

#include <gtest/gtest.h>
#include <cmath>
#include <fstream>


#include "Utils/Point.h"
#include "Utils/Line.h"
#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;


TEST(Segment,Constructor){
	Segment a;

	ASSERT_EQ (0,a.BeginPoint().CoordinateX());
	ASSERT_EQ (0,a.BeginPoint().CoordinateY());
	ASSERT_EQ (0,a.BeginPoint().CoordinateZ());

	ASSERT_EQ (1,a.EndPoint().CoordinateX());
	ASSERT_EQ (0,a.EndPoint().CoordinateY());
	ASSERT_EQ (0,a.EndPoint().CoordinateZ());
}

TEST(Segment,Constructor2){
	Point a(M_PI,2*M_PI,M_PI/5);
	Point b(M_PI/7,3*M_PI,-M_PI/4);
	Segment s(a,b);

	ASSERT_EQ (a.CoordinateX(),s.BeginPoint().CoordinateX());
	ASSERT_EQ (a.CoordinateY(),s.BeginPoint().CoordinateY());
	ASSERT_EQ (a.CoordinateZ(),s.BeginPoint().CoordinateZ());

	ASSERT_EQ (b.CoordinateX(),s.EndPoint().CoordinateX());
	ASSERT_EQ (b.CoordinateY(),s.EndPoint().CoordinateY());
	ASSERT_EQ (b.CoordinateZ(),s.EndPoint().CoordinateZ());
}

TEST(Segment,AssiociatedLine){
	Point a(M_PI,2*M_PI,M_PI/5);
	Point b(M_PI/7,3*M_PI,-M_PI/4);
	Segment s(a,b);
	Line l = s.AssiociatedLine();
	Vector3D u = b-a;
	u /= u.Norme();
	ASSERT_EQ (a.CoordinateX(),l.Origin().CoordinateX());
	ASSERT_EQ (a.CoordinateY(),l.Origin().CoordinateY());
	ASSERT_EQ (a.CoordinateZ(),l.Origin().CoordinateZ());
	ASSERT_EQ (u.ComponantX(),l.Direction().ComponantX());
	ASSERT_EQ (u.ComponantY(),l.Direction().ComponantY());
	ASSERT_EQ (u.ComponantZ(),l.Direction().ComponantZ());
}

TEST(Segment,IO_Operator){
	Point a(M_PI,2*M_PI,M_PI/5);
	Point b(M_PI/7,3*M_PI,-M_PI/4);
	Segment s(a,b),t;

	ofstream fichierOut("testSegment.txt", ios::out | ios::trunc);
	if(fichierOut){
		fichierOut << s;
		fichierOut.close();
	}

	ifstream fichierIn("testSegment.txt", ios::in);
	if(fichierIn){
		fichierIn >> t;
		fichierIn.close();
	}

	ASSERT_EQ (t.BeginPoint().CoordinateX(),s.BeginPoint().CoordinateX());
	ASSERT_EQ (t.BeginPoint().CoordinateY(),s.BeginPoint().CoordinateY());
	ASSERT_EQ (t.BeginPoint().CoordinateZ(),s.BeginPoint().CoordinateZ());

	ASSERT_EQ (t.EndPoint().CoordinateX(),s.EndPoint().CoordinateX());
	ASSERT_EQ (t.EndPoint().CoordinateY(),s.EndPoint().CoordinateY());
	ASSERT_EQ (t.EndPoint().CoordinateZ(),s.EndPoint().CoordinateZ());

	remove("testSegment.txt");
}
