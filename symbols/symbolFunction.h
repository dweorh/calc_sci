#pragma once
#include "symbol.h"
#include "math.h"
class symbolFunction : public symbol
{
public:
	double d2r;
	symbolFunction(std::string);
	~symbolFunction(void);
	double calculate(double v);
	void setPrevSymbol(symbol *);
	symbolType::type getType(void){
		return symbolType::function;
	}
};

