#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Utils/BasisId.h"
#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;

TEST(BasisId,Constructor){
	BasisId a;
	ASSERT_EQ (-1,a.Id());
}

TEST(BasisId,Id){
	BasisId a;
	a.Id(17);
	ASSERT_EQ (17,a.Id());
}

TEST(BasisId,IO_Operator){
	BasisId a;
	BasisId b;

	ofstream fichierOut("testBasisId.txt", ios::out | ios::trunc);
	if(fichierOut){
		fichierOut << a;
		fichierOut.close();
	}

	ifstream fichierIn("testBasisId.txt", ios::in);
	if(fichierIn){
		fichierIn >> b;
		fichierIn.close();
	}

	ASSERT_EQ (b.Id(),a.Id());

	remove("testBasisID.txt");
}
