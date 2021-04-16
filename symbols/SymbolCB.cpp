#include "symbolCB.h"

dwe::SymbolCB::SymbolCB(void)
{
	init();
	priority = 0;
	check_for_function = true;
	number_of_required_arguments = 0;
	skip_calculation = true;
	never_on_stack = true;
}


dwe::SymbolCB::~SymbolCB(void)
{
}

bool dwe::SymbolCB::rewind( Symbol *oSymbol ){
	bool result;
	result = oSymbol->getType() == symbolType::ob ? false : true;
	return result;
}