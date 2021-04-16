#include "SymbolFactorial.h"

dwe::SymbolFactorial::SymbolFactorial(std::string c)
{
	init();
	priority = 3;
	number_of_required_arguments = 1;
	setValue(c);
}


dwe::SymbolFactorial::~SymbolFactorial(void)
{
}

double dwe::SymbolFactorial::calculate( double v ){
	return postCalculate((double)factorial(int(v)));
}

int dwe::SymbolFactorial::factorial(int end){
	int result = 1;
	int i = 1;
	while( i <= end){
		result *= i;
		i++;
	}
	return result;
}
