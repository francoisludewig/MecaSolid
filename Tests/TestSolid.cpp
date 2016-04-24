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
	ASSERT_TRUE(isEquals( s.B().O().X() , M_PI  *dt*dt/mass));
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


TEST(Solid,UpdatePositionRotationX){
	Solid s;
	Vector3D w(M_PI/6,0.,0.);
	double dt = 1;

	s.AngularVelocity(w);
	s.UpdatePosition(dt);

	ASSERT_TRUE(isEquals( s.AngularVelocity().X() , M_PI/6));
	ASSERT_TRUE(isEquals( s.AngularVelocity().Y() , 0));
	ASSERT_TRUE(isEquals( s.AngularVelocity().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().Q().Q0() , cos(M_PI/12)));
	ASSERT_TRUE(isEquals( s.B().Q().Q1() , sin(M_PI/12)));
	ASSERT_TRUE(isEquals( s.B().Q().Q2() , 0));
	ASSERT_TRUE(isEquals( s.B().Q().Q3() , 0));

	ASSERT_TRUE(isEquals( s.B().E1().X() , 1));
	ASSERT_TRUE(isEquals( s.B().E1().Y() , 0));
	ASSERT_TRUE(isEquals( s.B().E1().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().E2().X() , 0));
	ASSERT_TRUE(isEquals( s.B().E2().Y() ,cos(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().E2().Z() ,sin(M_PI/6)));

	ASSERT_TRUE(isEquals( s.B().E3().X() , 0));
	ASSERT_TRUE(isEquals( s.B().E3().Y() ,-sin(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().E3().Z() , cos(M_PI/6)));
}


TEST(Solid,UpdatePositionRotationY){
	Solid s;
	Vector3D w(0 ,M_PI/6, 0);
	double dt = 1;

	s.AngularVelocity(w);
	s.UpdatePosition(dt);

	ASSERT_TRUE(isEquals( s.AngularVelocity().X() , 0));
	ASSERT_TRUE(isEquals( s.AngularVelocity().Y() , M_PI/6));
	ASSERT_TRUE(isEquals( s.AngularVelocity().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().Q().Q0() , cos(M_PI/12)));
	ASSERT_TRUE(isEquals( s.B().Q().Q1() , 0));
	ASSERT_TRUE(isEquals( s.B().Q().Q2() , sin(M_PI/12)));
	ASSERT_TRUE(isEquals( s.B().Q().Q3() , 0));

	ASSERT_TRUE(isEquals( s.B().E1().X() , cos(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().E1().Y() , 0));
	ASSERT_TRUE(isEquals( s.B().E1().Z() ,-sin(M_PI/6)));

	ASSERT_TRUE(isEquals( s.B().E2().X() , 0));
	ASSERT_TRUE(isEquals( s.B().E2().Y() , 1));
	ASSERT_TRUE(isEquals( s.B().E2().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().E3().X() , sin(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().E3().Y() , 0));
	ASSERT_TRUE(isEquals( s.B().E3().Z() , cos(M_PI/6)));
}

TEST(Solid,UpdatePositionRotationZ){
	Solid s;
	Vector3D w(0 , 0, M_PI/6);
	double dt = 1;

	s.AngularVelocity(w);
	s.UpdatePosition(dt);

	ASSERT_TRUE(isEquals( s.AngularVelocity().X() , 0));
	ASSERT_TRUE(isEquals( s.AngularVelocity().Y() , 0));
	ASSERT_TRUE(isEquals( s.AngularVelocity().Z() , M_PI/6));

	ASSERT_TRUE(isEquals( s.B().Q().Q0() , cos(M_PI/12)));
	ASSERT_TRUE(isEquals( s.B().Q().Q1() , 0));
	ASSERT_TRUE(isEquals( s.B().Q().Q2() , 0));
	ASSERT_TRUE(isEquals( s.B().Q().Q3() , sin(M_PI/12)));

	ASSERT_TRUE(isEquals( s.B().E1().X() , cos(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().E1().Y() , sin(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().E1().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().E2().X() ,-sin(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().E2().Y() , cos(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().E2().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().E3().X() , 0));
	ASSERT_TRUE(isEquals( s.B().E3().Y() , 0));
	ASSERT_TRUE(isEquals( s.B().E3().Z() ,1));
}


TEST(Solid,UpdatePositionRotationXYZ){
	Solid s;
	Vector3D w;
	double dt = 1;

	// Rotation X
	w.SetValue(M_PI,0,0);
	s.AngularVelocity(w);
	s.UpdatePosition(dt);
	// Rotation Y
	w.SetValue(0,M_PI,0);
	s.AngularVelocity(w);
	s.UpdatePosition(dt);
	// Rotation Z
	w.SetValue(0,0,M_PI);
	s.AngularVelocity(w);
	s.UpdatePosition(dt);

	ASSERT_TRUE(isEquals( s.B().E1().X() , 1));
	ASSERT_TRUE(isEquals( s.B().E1().Y() , 0));
	ASSERT_TRUE(isEquals( s.B().E1().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().E2().X() , 0));
	ASSERT_TRUE(isEquals( s.B().E2().Y() , 1));
	ASSERT_TRUE(isEquals( s.B().E2().Z() , 0));

	ASSERT_TRUE(isEquals( s.B().E3().X() , 0));
	ASSERT_TRUE(isEquals( s.B().E3().Y() , 0));
	ASSERT_TRUE(isEquals( s.B().E3().Z() , 1));
}

TEST(Solid,UpdateAngularVelocity){
	Solid s;
	Vector3D M(M_PI,-M_PI/2,M_PI/5);
	Matrix3x3 I(M_PI,0,0,
				0,M_PI,0,
				0,0,M_PI);

	double dt = 1;
	s.Inertia(I);
	s.Momentum(M);
	s.UpdateVelocities(dt);

	ASSERT_TRUE(isEquals(s.AngularVelocity().X(),M.X()*dt/M_PI));
	ASSERT_TRUE(isEquals(s.AngularVelocity().Y(),M.Y()*dt/M_PI));
	ASSERT_TRUE(isEquals(s.AngularVelocity().Z(),M.Z()*dt/M_PI));
}


TEST(Solid,IO_Operator){
	Solid s,t;
	Vector3D w,v;

	// Rotation X
	w.SetValue(M_PI,-M_PI/2,M_PI/4);
	s.AngularVelocity(w);
	// Translation
	v.SetValue(-M_PI,-3*M_PI/2,7*M_PI/4);
	s.Velocity(v);

	s.UpdatePosition(1.);

	ofstream fichierOut("testSolid.txt", ios::out | ios::trunc);
	if(fichierOut){
		fichierOut << s;
		fichierOut.close();
	}

	ifstream fichierIn("testSolid.txt", ios::in);
	if(fichierIn){
		fichierIn >> t;
		fichierIn.close();
	}

	ASSERT_TRUE(isEquals(s.B().Q().Q0(),t.B().Q().Q0()));
	ASSERT_TRUE(isEquals(s.B().Q().Q1(),t.B().Q().Q1()));
	ASSERT_TRUE(isEquals(s.B().Q().Q2(),t.B().Q().Q2()));
	ASSERT_TRUE(isEquals(s.B().Q().Q3(),t.B().Q().Q3()));

	ASSERT_TRUE(isEquals(s.B().O().X(),t.B().O().X()));
	ASSERT_TRUE(isEquals(s.B().O().Y(),t.B().O().Y()));
	ASSERT_TRUE(isEquals(s.B().O().Z(),t.B().O().Z()));

	ASSERT_TRUE(isEquals(s.AngularVelocity().X(),t.AngularVelocity().X()));
	ASSERT_TRUE(isEquals(s.AngularVelocity().Y(),t.AngularVelocity().Y()));
	ASSERT_TRUE(isEquals(s.AngularVelocity().Z(),t.AngularVelocity().Z()));

	ASSERT_TRUE(isEquals(s.Velocity().X(),t.Velocity().X()));
	ASSERT_TRUE(isEquals(s.Velocity().Y(),t.Velocity().Y()));
	ASSERT_TRUE(isEquals(s.Velocity().Z(),t.Velocity().Z()));


	remove("testSolid.txt");
}
