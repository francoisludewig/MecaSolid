#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Utils/Matrix3x3.h"
#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;


TEST(Matrix3x3,Constructor){
	Matrix3x3 a;

	ASSERT_EQ (1,a.Componant(0,0));
	ASSERT_EQ (0,a.Componant(0,1));
	ASSERT_EQ (0,a.Componant(0,2));

	ASSERT_EQ (0,a.Componant(1,0));
	ASSERT_EQ (1,a.Componant(1,1));
	ASSERT_EQ (0,a.Componant(1,2));

	ASSERT_EQ (0,a.Componant(2,0));
	ASSERT_EQ (0,a.Componant(2,1));
	ASSERT_EQ (1,a.Componant(2,2));
}

TEST(Matrix3x3,det){
	Matrix3x3 a;

	a.Componant(0,0,-3);
	a.Componant(0,1,5);
	a.Componant(0,2,6);

	a.Componant(1,0,-1);
	a.Componant(1,1,2);
	a.Componant(1,2,2);

	a.Componant(2,0,1);
	a.Componant(2,1,-1);
	a.Componant(2,2,-1);
	ASSERT_EQ (-1,a.Determinant());
}

TEST(Matrix3x3,Transpose){
	Matrix3x3 a,b;

	a.Componant(0,0,-3);
	a.Componant(0,1,5);
	a.Componant(0,2,6);

	a.Componant(1,0,-1);
	a.Componant(1,1,2);
	a.Componant(1,2,2);

	a.Componant(2,0,1);
	a.Componant(2,1,-1);
	a.Componant(2,2,-1);

	b = a.MatrixTranspose();

	ASSERT_EQ (-3,b.Componant(0,0));
	ASSERT_EQ (-1,b.Componant(0,1));
	ASSERT_EQ (1,b.Componant(0,2));

	ASSERT_EQ (5,b.Componant(1,0));
	ASSERT_EQ (2,b.Componant(1,1));
	ASSERT_EQ (-1,b.Componant(1,2));

	ASSERT_EQ (6,b.Componant(2,0));
	ASSERT_EQ (2,b.Componant(2,1));
	ASSERT_EQ (-1,b.Componant(2,2));
}


TEST(Matrix3x3,Inverse){
	Matrix3x3 a,b;

	a.Componant(0,0,-3);
	a.Componant(0,1,5);
	a.Componant(0,2,6);

	a.Componant(1,0,-1);
	a.Componant(1,1,2);
	a.Componant(1,2,2);

	a.Componant(2,0,1);
	a.Componant(2,1,-1);
	a.Componant(2,2,-1);

	b = a.MatrixInverse();

	ASSERT_EQ (0,b.Componant(0,0));
	ASSERT_EQ (1,b.Componant(0,1));
	ASSERT_EQ (2,b.Componant(0,2));

	ASSERT_EQ (-1,b.Componant(1,0));
	ASSERT_EQ (3,b.Componant(1,1));
	ASSERT_EQ (0,b.Componant(1,2));

	ASSERT_EQ (1,b.Componant(2,0));
	ASSERT_EQ (-2,b.Componant(2,1));
	ASSERT_EQ (1,b.Componant(2,2));
}


TEST(Matrix3x3,VectorProductIdentity){
	Matrix3x3 a;
	Vector3D v(M_PI,M_PI/2,M_PI/3);
	Vector3D b = a*v;
	ASSERT_TRUE(isEquals (v.X(),b.X()));
	ASSERT_TRUE(isEquals (v.Y(),b.Y()));
	ASSERT_TRUE(isEquals (v.Z(),b.Z()));
}

TEST(Matrix3x3,VectorProduct){
	Matrix3x3 a(1,2,3,5,4,6,7,-4,-3);
	Vector3D v(M_PI,M_PI/2,M_PI/3);
	Vector3D b = a*v;

	ASSERT_TRUE(isEquals ( 3*M_PI,b.X()));
	ASSERT_TRUE(isEquals ( 9*M_PI,b.Y()));
	ASSERT_TRUE(isEquals (4*M_PI,b.Z()));
}

TEST(Matrix3x3,IO_Operator){
	Matrix3x3 a;
	Matrix3x3 b;


	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			a.Componant(i,j,M_PI*(i+1)/(j+1));
		}
	}
	ofstream fichierOut("testMatrix3x3.txt", ios::out | ios::trunc);
	if(fichierOut){
		fichierOut << a;
		fichierOut.close();
	}

	ifstream fichierIn("testMatrix3x3.txt", ios::in);
	if(fichierIn){
		fichierIn >> b;
		fichierIn.close();
	}

	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			cout << a.Componant(i,j) << " = " << b.Componant(i,j) << endl;
			cout << a.Componant(i,j)-b.Componant(i,j) << endl;
			ASSERT_TRUE(isEquals (a.Componant(i,j),b.Componant(i,j)));
		}
	}
	remove("testMatrix3x3.txt");
}
