#include <Utils/BasisChanger.h>
#include <Utils/Vector.h>

#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Utils/Quaternion.h"
#include "Utils/Basis.h"
#include "Utils/Point.h"
#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;

TEST(BasisChanger,Status){
	Basis b;
	BasisChanger basisSwitcher;

	ASSERT_EQ(None,basisSwitcher.Type());

	basisSwitcher.FromBasis(&b);
	ASSERT_EQ(From_Basis_To_Global,basisSwitcher.Type());

	basisSwitcher.ToBasis(&b);
	ASSERT_EQ(From_Basis_To_Basis,basisSwitcher.Type());

	basisSwitcher.FromBasis(NULL);
	ASSERT_EQ(From_Global_To_Basis,basisSwitcher.Type());

	basisSwitcher.ToBasis(NULL);
	ASSERT_EQ(None,basisSwitcher.Type());
}




