#include "symbolFactorial.h"

symbolFactorial::symbolFactorial(std::string c)
{
	init();
	priority = 3;
	number_of_required_arguments = 1;
	setValue(c);
}


symbolFactorial::~symbolFactorial(void)
{
}

double symbolFactorial::calculate( double v ){
	return postCalculate((double)factorial(int(v)));
}

int symbolFactorial::factorial(int end){
	int result = 1;
	int i = 1;
	while( i <= end){
		result *= i;
		i++;
	}
	return result;
}
