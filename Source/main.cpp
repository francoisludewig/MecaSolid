#include <iostream>
#include "./Libs/Basis/Vector3D.h"

using namespace std;
using namespace Meca::Libs::Basis;

int main()
{
	int x;

	Vector3D a;
	a.SetValue(1,2,3);
	cout << a << endl;

	cout << "Enter an integer value : ";
    cin >> x;
    return 0;
}
