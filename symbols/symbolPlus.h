#pragma once
#include "symbol.h"
class symbolPlus :
	public symbol
{
public:
	symbolPlus(std::string);
	~symbolPlus(void);
	double calculate( double v1, double v2 ){
		return v1+v2;
	}
	symbolType::type getType(void){
		return symbolType::plus;
	}
};

