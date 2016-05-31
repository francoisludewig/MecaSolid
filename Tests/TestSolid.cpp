#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Resource/DoublePrecision.h"
#include "Solid/Solid.h"
#include "Utils/Basis.h"

using namespace std;
using namespace Luga::Meca::Solid;


TEST(Solid,UpdatePositionTranslation){
	Solid s;
	Vector v(M_PI,M_PI/2,M_PI/4);
	double dt = 0.0001;
	s.Velocity(v);
	s.UpdatePosition(dt);

	ASSERT_TRUE(isEquals( s.B().Origin().CoordinateX() , M_PI  *dt));
	ASSERT_TRUE(isEquals( s.B().Origin().CoordinateY() , M_PI/2*dt));
	ASSERT_TRUE(isEquals( s.B().Origin().CoordinateZ() , M_PI/4*dt));
}


TEST(Solid,UpdateVelocityTranslation){
	Solid s;
	Vector f(M_PI,M_PI/2,M_PI/4);
	double mass = 10.;
	double dt = 0.0001;
	s.Force(f);
	s.Mass(mass);
	s.UpdateVelocities(dt);

	ASSERT_TRUE(isEquals( s.Velocity().ComponantX() , M_PI  *dt/mass));
	ASSERT_TRUE(isEquals( s.Velocity().ComponantY() , M_PI/2*dt/mass));
	ASSERT_TRUE(isEquals( s.Velocity().ComponantZ() , M_PI/4*dt/mass));
}

TEST(Solid,UpdateVelocityAndPositionTranslation){
	Solid s;
	Vector f(M_PI,M_PI/2,M_PI/4);
	double mass = 10.;
	double dt = 0.0001;
	s.Force(f);
	s.Mass(mass);

	s.UpdateVelocities(dt);
	s.UpdatePosition(dt);

	ASSERT_TRUE(isEquals( s.Velocity().ComponantX() , M_PI  *dt/mass));
	ASSERT_TRUE(isEquals( s.Velocity().ComponantY() , M_PI/2*dt/mass));
	ASSERT_TRUE(isEquals( s.Velocity().ComponantZ() , M_PI/4*dt/mass));
	ASSERT_TRUE(isEquals( s.B().Origin().CoordinateX() , M_PI  *dt*dt/mass));
	ASSERT_TRUE(isEquals( s.B().Origin().CoordinateY() , M_PI/2*dt*dt/mass));
	ASSERT_TRUE(isEquals( s.B().Origin().CoordinateZ() , M_PI/4*dt*dt/mass));
}


TEST(Solid,UpdateVelocityAndPositionTranslationThetaMethod){
	Solid s;
	Vector f(M_PI,M_PI/2,M_PI/4);
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

	ASSERT_TRUE(isEquals( s.Velocity().ComponantX() , M_PI  *T/mass));
	ASSERT_TRUE(isEquals( s.Velocity().ComponantY() , M_PI/2*T/mass));
	ASSERT_TRUE(isEquals( s.Velocity().ComponantZ() , M_PI/4*T/mass));
	ASSERT_TRUE(isEquals( s.B().Origin().CoordinateX(), M_PI  *T*T/2./mass));
	ASSERT_TRUE(isEquals( s.B().Origin().CoordinateY() , M_PI/2*T*T/2./mass));
	ASSERT_TRUE(isEquals( s.B().Origin().CoordinateZ() , M_PI/4*T*T/2./mass));
}


TEST(Solid,UpdatePositionRotationX){
	Solid s;
	Vector w(M_PI/6,0.,0.);
	double dt = 1;

	s.AngularVelocity(w);
	s.UpdatePosition(dt);

	ASSERT_TRUE(isEquals( s.AngularVelocity().ComponantX() , M_PI/6));
	ASSERT_TRUE(isEquals( s.AngularVelocity().ComponantY() , 0));
	ASSERT_TRUE(isEquals( s.AngularVelocity().ComponantZ() , 0));

	ASSERT_TRUE(isEquals( s.B().Orientation().ComponantReal() , cos(M_PI/12)));
	ASSERT_TRUE(isEquals( s.B().Orientation().ComponantI() , sin(M_PI/12)));
	ASSERT_TRUE(isEquals( s.B().Orientation().ComponantJ() , 0));
	ASSERT_TRUE(isEquals( s.B().Orientation().ComponantK() , 0));

	ASSERT_TRUE(isEquals( s.B().AxisX().ComponantX() , 1));
	ASSERT_TRUE(isEquals( s.B().AxisX().ComponantY() , 0));
	ASSERT_TRUE(isEquals( s.B().AxisX().ComponantZ() , 0));

	ASSERT_TRUE(isEquals( s.B().AxisY().ComponantX() , 0));
	ASSERT_TRUE(isEquals( s.B().AxisY().ComponantY() ,cos(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().AxisY().ComponantZ() ,sin(M_PI/6)));

	ASSERT_TRUE(isEquals( s.B().AxisZ().ComponantX() , 0));
	ASSERT_TRUE(isEquals( s.B().AxisZ().ComponantY() ,-sin(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().AxisZ().ComponantZ() , cos(M_PI/6)));
}


TEST(Solid,UpdatePositionRotationY){
	Solid s;
	Vector w(0 ,M_PI/6, 0);
	double dt = 1;

	s.AngularVelocity(w);
	s.UpdatePosition(dt);

	ASSERT_TRUE(isEquals( s.AngularVelocity().ComponantX() , 0));
	ASSERT_TRUE(isEquals( s.AngularVelocity().ComponantY() , M_PI/6));
	ASSERT_TRUE(isEquals( s.AngularVelocity().ComponantZ() , 0));

	ASSERT_TRUE(isEquals( s.B().Orientation().ComponantReal() , cos(M_PI/12)));
	ASSERT_TRUE(isEquals( s.B().Orientation().ComponantI() , 0));
	ASSERT_TRUE(isEquals( s.B().Orientation().ComponantJ() , sin(M_PI/12)));
	ASSERT_TRUE(isEquals( s.B().Orientation().ComponantK() , 0));

	ASSERT_TRUE(isEquals( s.B().AxisX().ComponantX() , cos(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().AxisX().ComponantY() , 0));
	ASSERT_TRUE(isEquals( s.B().AxisX().ComponantZ() ,-sin(M_PI/6)));

	ASSERT_TRUE(isEquals( s.B().AxisY().ComponantX() , 0));
	ASSERT_TRUE(isEquals( s.B().AxisY().ComponantY() , 1));
	ASSERT_TRUE(isEquals( s.B().AxisY().ComponantZ() , 0));

	ASSERT_TRUE(isEquals( s.B().AxisZ().ComponantX() , sin(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().AxisZ().ComponantY() , 0));
	ASSERT_TRUE(isEquals( s.B().AxisZ().ComponantZ() , cos(M_PI/6)));
}

TEST(Solid,UpdatePositionRotationZ){
	Solid s;
	Vector w(0 , 0, M_PI/6);
	double dt = 1;

	s.AngularVelocity(w);
	s.UpdatePosition(dt);

	ASSERT_TRUE(isEquals( s.AngularVelocity().ComponantX() , 0));
	ASSERT_TRUE(isEquals( s.AngularVelocity().ComponantY() , 0));
	ASSERT_TRUE(isEquals( s.AngularVelocity().ComponantZ() , M_PI/6));

	ASSERT_TRUE(isEquals( s.B().Orientation().ComponantReal() , cos(M_PI/12)));
	ASSERT_TRUE(isEquals( s.B().Orientation().ComponantI() , 0));
	ASSERT_TRUE(isEquals( s.B().Orientation().ComponantJ() , 0));
	ASSERT_TRUE(isEquals( s.B().Orientation().ComponantK() , sin(M_PI/12)));

	ASSERT_TRUE(isEquals( s.B().AxisX().ComponantX() , cos(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().AxisX().ComponantY() , sin(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().AxisX().ComponantZ() , 0));

	ASSERT_TRUE(isEquals( s.B().AxisY().ComponantX() ,-sin(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().AxisY().ComponantY() , cos(M_PI/6)));
	ASSERT_TRUE(isEquals( s.B().AxisY().ComponantZ() , 0));

	ASSERT_TRUE(isEquals( s.B().AxisZ().ComponantX() , 0));
	ASSERT_TRUE(isEquals( s.B().AxisZ().ComponantY() , 0));
	ASSERT_TRUE(isEquals( s.B().AxisZ().ComponantZ() ,1));
}


TEST(Solid,UpdatePositionRotationXYZ){
	Solid s;
	Vector w;
	double dt = 1;

	// Rotation X
	w.SetComponants(M_PI,0,0);
	s.AngularVelocity(w);
	s.UpdatePosition(dt);
	// Rotation Y
	w.SetComponants(0,M_PI,0);
	s.AngularVelocity(w);
	s.UpdatePosition(dt);
	// Rotation Z
	w.SetComponants(0,0,M_PI);
	s.AngularVelocity(w);
	s.UpdatePosition(dt);

	ASSERT_TRUE(isEquals( s.B().AxisX().ComponantX() , 1));
	ASSERT_TRUE(isEquals( s.B().AxisX().ComponantY() , 0));
	ASSERT_TRUE(isEquals( s.B().AxisX().ComponantZ() , 0));

	ASSERT_TRUE(isEquals( s.B().AxisY().ComponantX() , 0));
	ASSERT_TRUE(isEquals( s.B().AxisY().ComponantY() , 1));
	ASSERT_TRUE(isEquals( s.B().AxisY().ComponantZ() , 0));

	ASSERT_TRUE(isEquals( s.B().AxisZ().ComponantX() , 0));
	ASSERT_TRUE(isEquals( s.B().AxisZ().ComponantY() , 0));
	ASSERT_TRUE(isEquals( s.B().AxisZ().ComponantZ() , 1));
}

TEST(Solid,UpdateAngularVelocity){
	Solid s;
	Vector M(M_PI,-M_PI/2,M_PI/5);
	Matrix I(M_PI,0,0,
				0,M_PI,0,
				0,0,M_PI);

	double dt = 1;
	s.Inertia(I);
	s.Momentum(M);
	s.UpdateVelocities(dt);

	ASSERT_TRUE(isEquals(s.AngularVelocity().ComponantX(),M.ComponantX()*dt/M_PI));
	ASSERT_TRUE(isEquals(s.AngularVelocity().ComponantY(),M.ComponantY()*dt/M_PI));
	ASSERT_TRUE(isEquals(s.AngularVelocity().ComponantZ(),M.ComponantZ()*dt/M_PI));
}


TEST(Solid,IO_Operator){
	Solid s,t;
	Vector w,v;

	// Rotation X
	w.SetComponants(M_PI,-M_PI/2,M_PI/4);
	s.AngularVelocity(w);
	// Translation
	v.SetComponants(-M_PI,-3*M_PI/2,7*M_PI/4);
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

	ASSERT_TRUE(isEquals(s.B().Orientation().ComponantReal(),t.B().Orientation().ComponantReal()));
	ASSERT_TRUE(isEquals(s.B().Orientation().ComponantI(),t.B().Orientation().ComponantI()));
	ASSERT_TRUE(isEquals(s.B().Orientation().ComponantJ(),t.B().Orientation().ComponantJ()));
	ASSERT_TRUE(isEquals(s.B().Orientation().ComponantK(),t.B().Orientation().ComponantK()));

	ASSERT_TRUE(isEquals(s.B().Origin().CoordinateX(),t.B().Origin().CoordinateX()));
	ASSERT_TRUE(isEquals(s.B().Origin().CoordinateY(),t.B().Origin().CoordinateY()));
	ASSERT_TRUE(isEquals(s.B().Origin().CoordinateZ(),t.B().Origin().CoordinateZ()));

	ASSERT_TRUE(isEquals(s.AngularVelocity().ComponantX(),t.AngularVelocity().ComponantX()));
	ASSERT_TRUE(isEquals(s.AngularVelocity().ComponantY(),t.AngularVelocity().ComponantY()));
	ASSERT_TRUE(isEquals(s.AngularVelocity().ComponantZ(),t.AngularVelocity().ComponantZ()));

	ASSERT_TRUE(isEquals(s.Velocity().ComponantX(),t.Velocity().ComponantX()));
	ASSERT_TRUE(isEquals(s.Velocity().ComponantY(),t.Velocity().ComponantY()));
	ASSERT_TRUE(isEquals(s.Velocity().ComponantZ(),t.Velocity().ComponantZ()));


	remove("testSolid.txt");
}
