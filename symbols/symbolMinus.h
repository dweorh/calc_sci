#pragma once
#include "symbol.h"
#include <typeinfo>
class symbolMinus : public symbol
{
public:
	symbolMinus(std::string);
	~symbolMinus(void);
	void setPrevSymbol(symbol*);
	double calculate(double);
	double calculate(double,double);
	symbolType::type getType(void){
		return symbolType::minus;
	}
};

