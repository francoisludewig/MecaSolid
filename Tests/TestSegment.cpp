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

	ASSERT_EQ (0,a.A().X());
	ASSERT_EQ (0,a.A().Y());
	ASSERT_EQ (0,a.A().Z());

	ASSERT_EQ (1,a.B().X());
	ASSERT_EQ (0,a.B().Y());
	ASSERT_EQ (0,a.B().Z());
}

TEST(Segment,Constructor2){
	Point a(M_PI,2*M_PI,M_PI/5);
	Point b(M_PI/7,3*M_PI,-M_PI/4);
	Segment s(a,b);

	ASSERT_EQ (a.X(),s.A().X());
	ASSERT_EQ (a.Y(),s.A().Y());
	ASSERT_EQ (a.Z(),s.A().Z());

	ASSERT_EQ (b.X(),s.B().X());
	ASSERT_EQ (b.Y(),s.B().Y());
	ASSERT_EQ (b.Z(),s.B().Z());
}

TEST(Segment,GetLine){
	Point a(M_PI,2*M_PI,M_PI/5);
	Point b(M_PI/7,3*M_PI,-M_PI/4);
	Segment s(a,b);
	Line l = s.GetLine();
	Vector3D u = b-a;
	u /= u.Norme();
	ASSERT_EQ (a.X(),l.GetPoint().X());
	ASSERT_EQ (a.Y(),l.GetPoint().Y());
	ASSERT_EQ (a.Z(),l.GetPoint().Z());
	ASSERT_EQ (u.X(),l.GetVector().X());
	ASSERT_EQ (u.Y(),l.GetVector().Y());
	ASSERT_EQ (u.Z(),l.GetVector().Z());
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

	ASSERT_EQ (t.A().X(),s.A().X());
	ASSERT_EQ (t.A().Y(),s.A().Y());
	ASSERT_EQ (t.A().Z(),s.A().Z());

	ASSERT_EQ (t.B().X(),s.B().X());
	ASSERT_EQ (t.B().Y(),s.B().Y());
	ASSERT_EQ (t.B().Z(),s.B().Z());

	remove("testSegment.txt");
}
