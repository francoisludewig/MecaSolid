#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Resource/DoublePrecision.h"
#include "Solid/Solid.h"

using namespace std;
using namespace Luga::Meca::Solid;


TEST(Solid,UpdatePositionTranslation){
	Solid s;
	Vector3D v(M_PI,M_PI/2,M_PI/4);
	double dt = 0.0001;
	s.Velocity(v);
	s.UpdatePosition(dt);

	ASSERT_TRUE(isEquals( s.B().O().X() , M_PI  *dt));
	ASSERT_TRUE(isEquals( s.B().O().Y() , M_PI/2*dt));
	ASSERT_TRUE(isEquals( s.B().O().Z() , M_PI/4*dt));
}


TEST(Solid,UpdateVelocityTranslation){
	Solid s;
	Vector3D f(M_PI,M_PI/2,M_PI/4);
	double mass = 10.;
	double dt = 0.0001;
	s.Force(f);
	s.Mass(mass);
	s.UpdateVelocities(dt);

	ASSERT_TRUE(isEquals( s.Velocity().X() , M_PI  *dt/mass));
	ASSERT_TRUE(isEquals( s.Velocity().Y() , M_PI/2*dt/mass));
	ASSERT_TRUE(isEquals( s.Velocity().Z() , M_PI/4*dt/mass));
}

TEST(Solid,UpdateVelocityAndPositionTranslation){
	Solid s;
	Vector3D f(M_PI,M_PI/2,M_PI/4);
	double mass = 10.;
	double dt = 0.0001;
	s.Force(f);
	s.Mass(mass);

	s.UpdateVelocities(dt);
	s.UpdatePosition(dt);

	ASSERT_TRUE(isEquals( s.Velocity().X() , M_PI  *dt/mass));
	ASSERT_TRUE(isEquals( s.Velocity().Y() , M_PI/2*dt/mass));
	ASSERT_TRUE(isEquals( s.Velocity().Z() , M_PI/4*dt/mass));
	ASSERT_TRUE(isEquals( s.B().O().X(), M_PI  *dt*dt/mass));
	ASSERT_TRUE(isEquals( s.B().O().Y() , M_PI/2*dt*dt/mass));
	ASSERT_TRUE(isEquals( s.B().O().Z() , M_PI/4*dt*dt/mass));
}


TEST(Solid,UpdateVelocityAndPositionTranslationThetaMethod){
	Solid s;
	Vector3D f(M_PI,M_PI/2,M_PI/4);
	double mass = 10.;
	double dt = 0.0001;
	double T = 0;
	s.Force(f);
	s.Mass(mass);

	for(int i = 0 ; i < 10 ; i++){
		T += dt;
		s.UpdatePosition(dt/2.);
		s.UpdateVelocities(dt);
		s.UpdatePosition(dt/2.);
	}

	ASSERT_TRUE(isEquals( s.Velocity().X() , M_PI  *T/mass));
	ASSERT_TRUE(isEquals( s.Velocity().Y() , M_PI/2*T/mass));
	ASSERT_TRUE(isEquals( s.Velocity().Z() , M_PI/4*T/mass));
	ASSERT_TRUE(isEquals( s.B().O().X(), M_PI  *T*T/2./mass));
	ASSERT_TRUE(isEquals( s.B().O().Y() , M_PI/2*T*T/2./mass));
	ASSERT_TRUE(isEquals( s.B().O().Z() , M_PI/4*T*T/2./mass));
}

/*
 * TODO : - Consider particular angle as pi/4, pi/3, pi/6,...
 * 		  - Imagine an example in 3D !!!
*/

TEST(Solid,UpdatePositionRotationX){
	Solid s;
	Vector3D w(M_PI,0.,0.);
	double dt = 1;

	s.AngularVelocity(w);
	s.UpdatePosition(dt);

	ASSERT_TRUE(isEquals( s.AngularVelocity().X() , M_PI));
	ASSERT_TRUE(isEquals( s.AngularVelocity().Y() , 0));
	ASSERT_TRUE(isEquals( s.AngularVelocity().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().Q().Q0() , cos(M_PI/2)));
	ASSERT_TRUE(isEquals( s.B().Q().Q1() , sin(M_PI/2)));
	ASSERT_TRUE(isEquals( s.B().Q().Q2() , 0));
	ASSERT_TRUE(isEquals( s.B().Q().Q3() , 0));

	ASSERT_TRUE(isEquals( s.B().E1().X() , 1));
	ASSERT_TRUE(isEquals( s.B().E1().Y() , 0));
	ASSERT_TRUE(isEquals( s.B().E1().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().E2().X() , 0));
	ASSERT_TRUE(isEquals( s.B().E2().Y() ,-1));
	ASSERT_TRUE(isEquals( s.B().E2().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().E3().X() , 0));
	ASSERT_TRUE(isEquals( s.B().E3().Y() , 0));
	ASSERT_TRUE(isEquals( s.B().E3().Z() ,-1));
}


TEST(Solid,UpdatePositionRotationY){
	Solid s;
	Vector3D w(0 ,M_PI, 0);
	double dt = 1;

	s.AngularVelocity(w);
	s.UpdatePosition(dt);

	ASSERT_TRUE(isEquals( s.AngularVelocity().X() , 0));
	ASSERT_TRUE(isEquals( s.AngularVelocity().Y() , M_PI));
	ASSERT_TRUE(isEquals( s.AngularVelocity().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().Q().Q0() , cos(M_PI/2)));
	ASSERT_TRUE(isEquals( s.B().Q().Q1() , 0));
	ASSERT_TRUE(isEquals( s.B().Q().Q2() , sin(M_PI/2)));
	ASSERT_TRUE(isEquals( s.B().Q().Q3() , 0));

	ASSERT_TRUE(isEquals( s.B().E1().X() , -1));
	ASSERT_TRUE(isEquals( s.B().E1().Y() , 0));
	ASSERT_TRUE(isEquals( s.B().E1().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().E2().X() , 0));
	ASSERT_TRUE(isEquals( s.B().E2().Y() , 1));
	ASSERT_TRUE(isEquals( s.B().E2().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().E3().X() , 0));
	ASSERT_TRUE(isEquals( s.B().E3().Y() , 0));
	ASSERT_TRUE(isEquals( s.B().E3().Z() ,-1));
}

TEST(Solid,UpdatePositionRotationZ){
	Solid s;
	Vector3D w(0 , 0, M_PI);
	double dt = 1;

	s.AngularVelocity(w);
	s.UpdatePosition(dt);

	ASSERT_TRUE(isEquals( s.AngularVelocity().X() , 0));
	ASSERT_TRUE(isEquals( s.AngularVelocity().Y() , 0));
	ASSERT_TRUE(isEquals( s.AngularVelocity().Z() , M_PI));

	ASSERT_TRUE(isEquals( s.B().Q().Q0() , cos(M_PI/2)));
	ASSERT_TRUE(isEquals( s.B().Q().Q1() , 0));
	ASSERT_TRUE(isEquals( s.B().Q().Q2() , 0));
	ASSERT_TRUE(isEquals( s.B().Q().Q3() , sin(M_PI/2)));

	ASSERT_TRUE(isEquals( s.B().E1().X() , -1));
	ASSERT_TRUE(isEquals( s.B().E1().Y() , 0));
	ASSERT_TRUE(isEquals( s.B().E1().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().E2().X() , 0));
	ASSERT_TRUE(isEquals( s.B().E2().Y() , -1));
	ASSERT_TRUE(isEquals( s.B().E2().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().E3().X() , 0));
	ASSERT_TRUE(isEquals( s.B().E3().Y() , 0));
	ASSERT_TRUE(isEquals( s.B().E3().Z() ,1));
}

