#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Vector.h"
#include "Plan.h"
#include "Point.h"
#include "Line.h"
#include "Basis.h"
#include "InterceptorPlans.h"
#include "Interception.h"
#include "../Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;

TEST(InterceptorPlans,ParallelPlanWithoutIntersection){
	Plan a(Point(0,0,0),Vector(1,1,0));
	Plan b(Point(0,-2,1),Vector(-1,-1,0));
	InterceptorPlans interceptorPlans;

	Interception interception = interceptorPlans.Intercept(a,b);

	ASSERT_EQ (InterceptionEmpty,interception.Type());
}

TEST(InterceptorPlans,SamePlans){
	Plan a(Point(0,0,0),Vector(1,1,0));
	Plan b(Point(0,0,-17),Vector(-1,-1,0));
	InterceptorPlans interceptorPlans;

	Interception interception = interceptorPlans.Intercept(a,b);

	ASSERT_EQ (InterceptionPlan,interception.Type());
	ASSERT_TRUE(a == interception.GetPlan());
}

TEST(InterceptorPlans,CrossPlans){
	Vector normaleA = Vector(1,2,3);
	Basis baseA;
	baseA.AxisX(normaleA);
	Point originA = Point(0,0,0) + (5 * baseA.AxisY() - 7 * baseA.AxisZ());
	Vector normaleB = Vector(3,2,1);
	Basis baseB;
	baseB.AxisX(normaleB);
	Point originB = Point(0,0,0) + (7 * baseB.AxisY() - 5 * baseB.AxisZ());

	Plan a(originA,normaleA);
	Plan b(originB,normaleB);
	InterceptorPlans interceptorPlans;

	Interception interception = interceptorPlans.Intercept(a,b);

	ASSERT_EQ (InterceptionLine,interception.Type());
	Vector excpectedDirection = baseA.AxisX()^baseB.AxisX();
	Vector test_pv = excpectedDirection^(interception.GetLine().Direction());
	ASSERT_TRUE(test_pv == Vector(0,0,0));

	Point intercept = interception.GetLine().Origin();
	Vector interceptA = intercept-a.Origin();
	/*
	 * Test scalar product = 0 is equivalent to test the cosine of the angle between vectors = 0.
	 * In order to do that more generally, the vectors must be normalized before.
    */
	interceptA.Normalize();
	ASSERT_TRUE(isEquals(0,interceptA*a.Normal()));
	Vector interceptB = intercept-b.Origin();
	interceptB.Normalize();
	ASSERT_TRUE(isEquals(0,interceptB*b.Normal()));
}


