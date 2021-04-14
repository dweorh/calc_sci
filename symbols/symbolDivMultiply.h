#pragma once
#include "symbol.h"
#include "math.h"
class symbolDivMultiply : public symbol
{
protected:
public:
	symbolDivMultiply(string);
	~symbolDivMultiply(void);
	double calculate(double,double);
	symbolType::type getType(void){
		return symbolType::div_multiply;
	}
};