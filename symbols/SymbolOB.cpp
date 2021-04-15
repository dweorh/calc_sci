#include "SymbolOB.h"
#include "SymbolDivMultiply.h"


dwe::SymbolOB::SymbolOB(void)
{
	init();
	priority = 0;
	direct_to_stack = true;
	number_of_required_arguments = 0;
	skip_calculation = true;
}

void dwe::SymbolOB::setPrevSymbol(Symbol *prev_symbol){
	if( prev_symbol->getType() == symbolType::cb
		|| prev_symbol->getType() == symbolType::number
	){
		appendPreAddonSymbol( new SymbolDivMultiply("*") );
	}
}

dwe::SymbolOB::~SymbolOB(void)
{
}
