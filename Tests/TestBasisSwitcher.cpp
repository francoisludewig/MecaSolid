#include <gtest/gtest.h>
#include <cmath>
#include <fstream>

#include "Utils/BasisSwitcher.h"
#include "Utils/Vector3D.h"
#include "Utils/Quaternion.h"
#include "Utils/Basis.h"
#include "Utils/Point.h"
#include "Resource/DoublePrecision.h"

using namespace std;
using namespace Luga::Meca::Utils;

TEST(BasisSwitcher,Status){
	Basis b;
	BasisSwitcher basisSwitcher;

	ASSERT_EQ(None,basisSwitcher.Type());

	basisSwitcher.From(&b);
	ASSERT_EQ(From_Basis_To_Global,basisSwitcher.Type());

	basisSwitcher.To(&b);
	ASSERT_EQ(From_Basis_To_Basis,basisSwitcher.Type());

	basisSwitcher.From(NULL);
	ASSERT_EQ(From_Global_To_Basis,basisSwitcher.Type());

	basisSwitcher.To(NULL);
	ASSERT_EQ(None,basisSwitcher.Type());
}




