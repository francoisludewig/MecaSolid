#pragma once

#define precision 1E-15

static bool isEquals(double a, double b){
	std::cout << std::scientific << std::setprecision(15);
	if(!(fabs(a-b) < precision))
		std::cout << a << " != " << b << std::endl;
	return fabs(a-b) < precision;
}

