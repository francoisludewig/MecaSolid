#pragma once

#define precision 1E-15

static bool isEquals(double a, double b){
	/*
	cout << scientific << setprecision(15);
	cout << "IsEquals" << endl;
	cout << a << endl;
	cout << b << endl;
	cout << "--------" << endl;
	*/
	return fabs(a-b) < precision;
}
