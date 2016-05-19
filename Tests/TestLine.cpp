#include <Utils/Line.h>

#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include <Utils/Vector3D.h>
#include <Utils/Point.h>
#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;

TEST(Line,Constructor){
	Line a;
	ASSERT_EQ (0,a.GetPoint().X());
	ASSERT_EQ (0,a.GetPoint().Y());
	ASSERT_EQ (0,a.GetPoint().Z());
	ASSERT_EQ (1./sqrt(3),a.GetVector().X());
	ASSERT_EQ (1./sqrt(3),a.GetVector().Y());
	ASSERT_EQ (1./sqrt(3),a.GetVector().Z());
}

TEST(Line,Constructor2){
	Point a(M_PI,2*M_PI,M_PI/5);
	Vector3D u(M_PI,2*M_PI,M_PI/5);
	Line l(a,u);
	u /= u.Norme();
	ASSERT_EQ (a.X(),l.GetPoint().X());
	ASSERT_EQ (a.Y(),l.GetPoint().Y());
	ASSERT_EQ (a.Z(),l.GetPoint().Z());
	ASSERT_EQ (u.X(),l.GetVector().X());
	ASSERT_EQ (u.Y(),l.GetVector().Y());
	ASSERT_EQ (u.Z(),l.GetVector().Z());
}

TEST(Line,IO_Operator){
	Point a(M_PI,2*M_PI,M_PI/5);
		Vector3D u(M_PI,2*M_PI,M_PI/5);
		Line l(a,u),m;

	ofstream fichierOut("testLine.txt", ios::out | ios::trunc);
	if(fichierOut){
		fichierOut << l;
		fichierOut.close();
	}

	ifstream fichierIn("testLine.txt", ios::in);
	if(fichierIn){
		fichierIn >> m;
		fichierIn.close();
	}

	ASSERT_EQ (m.GetPoint().X(),l.GetPoint().X());
	ASSERT_EQ (m.GetPoint().Y(),l.GetPoint().Y());
	ASSERT_EQ (m.GetPoint().Z(),l.GetPoint().Z());
	ASSERT_EQ (m.GetVector().X(),l.GetVector().X());
	ASSERT_EQ (m.GetVector().Y(),l.GetVector().Y());
	ASSERT_EQ (m.GetVector().Z(),l.GetVector().Z());

	remove("testLine.txt");
}
