#pragma once
#include "symbol.h"
class symbolNumber : public symbol
{
public:
	symbolNumber(void);
	symbolNumber(std::string);
	~symbolNumber(void);
	double calculate(void);
	void setValue(string);
	symbolType::type getType(void){
		return symbolType::number;
	}
};

