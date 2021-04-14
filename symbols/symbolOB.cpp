#include "symbolOB.h"
#include "symbolDivMultiply.h"


symbolOB::symbolOB(void)
{
	init();
	priority = 0;
	direct_to_stack = true;
	number_of_required_arguments = 0;
	skip_calculation = true;
}

void symbolOB::setPrevSymbol(symbol *prev_symbol){
	if( prev_symbol->getType() == symbolType::cb
		|| prev_symbol->getType() == symbolType::number
	){
		appendPreAddonSymbol( new symbolDivMultiply("*") );
	}
}

symbolOB::~symbolOB(void)
{
}
