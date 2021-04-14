#pragma once
#include "symbol.h"
class symbolFactorial : public symbol
{
public:
	symbolFactorial(std::string);
	~symbolFactorial(void);
	int factorial(int);
	double calculate(double);
	symbolType::type getType(void){
		return symbolType::factorial;
	}
};

