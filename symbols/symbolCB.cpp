#include "symbolCB.h"

symbolCB::symbolCB(void)
{
	init();
	priority = 0;
	check_for_function = true;
	number_of_required_arguments = 0;
	skip_calculation = true;
	never_on_stack = true;
}


symbolCB::~symbolCB(void)
{
}

bool symbolCB::rewind( symbol *oSymbol ){
	bool result;
	result = oSymbol->getType() == symbolType::ob ? false : true;
	return result;
}