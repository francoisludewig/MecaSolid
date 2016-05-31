#include <Utils/Line.h>

#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include <Utils/Point.h>
#include <Utils/Vector.h>

#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;

TEST(Line,Constructor){
	Line a;
	ASSERT_EQ (0,a.Origin().CoordinateX());
	ASSERT_EQ (0,a.Origin().CoordinateY());
	ASSERT_EQ (0,a.Origin().CoordinateZ());
	ASSERT_EQ (1./sqrt(3),a.Direction().ComponantX());
	ASSERT_EQ (1./sqrt(3),a.Direction().ComponantY());
	ASSERT_EQ (1./sqrt(3),a.Direction().ComponantZ());
}

TEST(Line,Constructor2){
	Point a(M_PI,2*M_PI,M_PI/5);
	Vector u(M_PI,2*M_PI,M_PI/5);
	Line l(a,u);
	u /= u.Norme();
	ASSERT_EQ (a.CoordinateX(),l.Origin().CoordinateX());
	ASSERT_EQ (a.CoordinateY(),l.Origin().CoordinateY());
	ASSERT_EQ (a.CoordinateZ(),l.Origin().CoordinateZ());
	ASSERT_EQ (u.ComponantX(),l.Direction().ComponantX());
	ASSERT_EQ (u.ComponantY(),l.Direction().ComponantY());
	ASSERT_EQ (u.ComponantZ(),l.Direction().ComponantZ());
}

TEST(Line,IO_Operator){
	Point a(M_PI,2*M_PI,M_PI/5);
		Vector u(M_PI,2*M_PI,M_PI/5);
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

	ASSERT_EQ (m.Origin().CoordinateX(),l.Origin().CoordinateX());
	ASSERT_EQ (m.Origin().CoordinateY(),l.Origin().CoordinateY());
	ASSERT_EQ (m.Origin().CoordinateZ(),l.Origin().CoordinateZ());
	ASSERT_EQ (m.Direction().ComponantX(),l.Direction().ComponantX());
	ASSERT_EQ (m.Direction().ComponantY(),l.Direction().ComponantY());
	ASSERT_EQ (m.Direction().ComponantZ(),l.Direction().ComponantZ());

	remove("testLine.txt");
}
