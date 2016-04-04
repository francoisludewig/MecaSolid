#include <Basis/Quaternion.h>
#include <iostream>

#include "Basis/Vector3D.h"

using namespace std;
using namespace Meca::Libs::Basis;

int main()
{
	int x;

	Vector3D a;
	a.SetValue(1,2,3);
	cout << a << endl;

	Quaternion b;
	b.SetValue(1,1,1,1);
	cout << b << endl;

	cout << "Enter an integer value : ";
    cin >> x;
    return 0;
}
