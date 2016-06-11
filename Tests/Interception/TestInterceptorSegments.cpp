#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Vector.h"
#include "Plan.h"
#include "Point.h"
#include "Line.h"
#include "Basis.h"
#include "InterceptorSegments.h"
#include "Interception.h"
#include "../Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;

TEST(InterceptorSegments,ColinearSegmentsPointAB){
	Segment a(Point(1,1,1),Point(2,2,2));
	Segment b(Point(2,2,2),Point(3,3,3));
	InterceptorSegments interceptorSegments;

	Interception interception = interceptorSegments.Intercept(a,b);

	ASSERT_EQ (InterceptionPoint,interception.Type());

	ASSERT_EQ (Point(2,2,2),interception.GetPoint());
}


TEST(InterceptorSegments,ColinearSegmentsPointBA){
	Segment a(Point(1,1,1),Point(2,2,2));
	Segment b(Point(2,2,2),Point(3,3,3));
	InterceptorSegments interceptorSegments;

	Interception interception = interceptorSegments.Intercept(b,a);

	ASSERT_EQ (InterceptionPoint,interception.Type());
	ASSERT_EQ (Point(2,2,2),interception.GetPoint());
}


TEST(InterceptorSegments,ColinearSegmentsEmpty){
	Segment a(Point(1,1,1),Point(2,2,2));
	Segment b(Point(2.5,2.5,2.5),Point(3,3,3));
	InterceptorSegments interceptorSegments;

	Interception interception = interceptorSegments.Intercept(a,b);
	ASSERT_EQ (InterceptionEmpty,interception.Type());
	interception = interceptorSegments.Intercept(b,a);
		ASSERT_EQ (InterceptionEmpty,interception.Type());
}


TEST(InterceptorSegments,ColinearSegmentsSegmentAB){
	Segment a(Point(1,1,1),Point(2,2,2));
	Segment b(Point(1.5,1.5,1.5),Point(3,3,3));
	InterceptorSegments interceptorSegments;

	Interception interception = interceptorSegments.Intercept(a,b);
	ASSERT_EQ (InterceptionSegment,interception.Type());
	ASSERT_EQ (Point(1.5,1.5,1.5),interception.GetSegment().BeginPoint());
	ASSERT_EQ (Point(2,2,2),interception.GetSegment().EndPoint());
}


TEST(InterceptorSegments,ColinearSegmentsSegmentBA){
	Segment a(Point(1,1,1),Point(2,2,2));
	Segment b(Point(1.5,1.5,1.5),Point(3,3,3));
	InterceptorSegments interceptorSegments;

	Interception interception = interceptorSegments.Intercept(b,a);
	ASSERT_EQ (InterceptionSegment,interception.Type());
	ASSERT_EQ (Point(1.5,1.5,1.5),interception.GetSegment().BeginPoint());
	ASSERT_EQ (Point(2,2,2),interception.GetSegment().EndPoint());
}

TEST(InterceptorSegments,SegmentsSegment_2){
	Segment a(Point(1,1,1),Point(2,2,2));
	Segment b(Point(1,2,1),Point(2,1,2));
	InterceptorSegments interceptorSegments;

	Interception interception = interceptorSegments.Intercept(b,a);
	ASSERT_EQ (InterceptionPoint,interception.Type());
	ASSERT_EQ (Point(1.5,1.5,1.5),interception.GetPoint());
}


