#include <iostream>
#include "Basis/Vector3D.h"
#include "Basis/UnitQuaternion.h"

using namespace std;
using namespace Meca::Libs::Basis;

int main()
{
	int x;

	Vector3D a;
	a.SetValue(1,2,3);
	cout << a << endl;

	UnitQuaternion b;
	b.SetValue(1,1,1,1,true);
	cout << b << endl;

	cout << "Enter an integer value : ";
    cin >> x;
    return 0;
}
