#pragma once

#define precision pow(10,-15)

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