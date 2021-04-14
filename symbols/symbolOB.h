#pragma once
#include "symbol.h"

class symbolOB : public symbol
{
public:
	symbolOB(void);
	~symbolOB(void);
	symbolType::type getType(void){
		return symbolType::ob;
	}
	void setPrevSymbol(symbol *prev_symbol);
};

