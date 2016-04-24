#pragma once

#define precision 1E-15

static bool isEquals(double a, double b){
	return fabs(a-b) < precision;
}

