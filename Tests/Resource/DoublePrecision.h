#pragma once

#define epsilon 10*std::numeric_limits<double>::epsilon()

static bool isEquals(double a, double b){
	std::cout << std::scientific << std::setprecision(15);
	double diff = a-b;
	double error = epsilon;
	if(a != 0 && b != 0)
		error *= fabs(std::max(a,b));

	if(diff > error || diff < -error){
		std::cout << "Diff = " << diff << "\n Error = " << error << "\n";
		std::cout << a << " != " << b << std::endl;
		return false;
	}
	return true;
}

