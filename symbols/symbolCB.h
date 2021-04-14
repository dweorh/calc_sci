#pragma once
#include "symbol.h"
#include <typeinfo>
class symbolCB : public symbol
{
public:
	symbolCB(void);
	~symbolCB(void);
	bool rewind(symbol*);
	symbolType::type getType(void){
		return symbolType::cb;
	}
};