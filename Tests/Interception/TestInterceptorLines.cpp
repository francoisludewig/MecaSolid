#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Vector.h"
#include "Line.h"
#include "Point.h"
#include "InterceptorLines.h"
#include "Interception.h"
#include "../Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;

TEST(InterceptorLines,CrossLineWithoutIntersection){
	Line a(Point(0,0,0),Vector(1,1,0));
	Line b(Point(0,0,1),Vector(-1,1,0));
	InterceptorLines interceptorLines;

	Interception interception = interceptorLines.Intercept(a,b);

	ASSERT_EQ (InterceptionEmpty,interception.Type());
}

TEST(InterceptorLines,ParallelLineWithoutIntersection){
	Line a(Point(0,0,0),Vector(-2,-2,0));
	Line b(Point(1,1,1),Vector(1,1,0));
	InterceptorLines interceptorLines;

	Interception interception = interceptorLines.Intercept(a,b);

	ASSERT_EQ (InterceptionEmpty,interception.Type());
}


TEST(InterceptorLines,SameLines){
	Line a(Point(0,0,0),Vector(1,1,0));
	Line b(Point(2,2,0),Vector(-1,-1,0));
	InterceptorLines interceptorLines;

	Interception interception = interceptorLines.Intercept(a,b);

	ASSERT_EQ (InterceptionLine,interception.Type());
	ASSERT_TRUE(a == interception.GetLine());

}

TEST(InterceptorLines,CrossLines){
	Line a(Point(0,0,0),Vector(1,1,0));
	Line b(Point(1,-5,0),Vector(-1,1,0));
	InterceptorLines interceptorLines;

	Interception interception = interceptorLines.Intercept(a,b);

	ASSERT_EQ (InterceptionPoint,interception.Type());
	Point interceptionPoint(-2,-2,0);
	ASSERT_TRUE(interceptionPoint == interception.GetPoint());
}

TEST(InterceptorLines,CrossLinesB){
	Line a(Point(1,1,1),Vector(1,1,1));
	Line b(Point(1,2,1),Vector(1,-1,1));
	InterceptorLines interceptorLines;

	Interception interception = interceptorLines.Intercept(a,b);

	ASSERT_EQ (InterceptionPoint,interception.Type());
	Point interceptionPoint(1.5,1.5,1.5);
	ASSERT_TRUE(interceptionPoint == interception.GetPoint());
}


