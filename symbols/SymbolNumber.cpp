#include "SymbolNumber.h"
#include "SymbolDivMultiply.h"


dwe::SymbolNumber::SymbolNumber(void)
{
	init();
	number_of_required_arguments = 0;
	priority = 0;
	direct_to_output = true;
	direct_to_stack = false;
	never_on_stack = true;
	setValue("0.0");
}

dwe::SymbolNumber::SymbolNumber(std::string c)
{
	init();
	number_of_required_arguments = 0;
	priority = 0;
	direct_to_output = true;
	direct_to_stack = false;
	never_on_stack = true;
	setValue(c);
}

void dwe::SymbolNumber::setValue(std::string s){
	value = s;
	d_value = atof(s.c_str());
}

dwe::SymbolNumber::~SymbolNumber(void)
{
}

double dwe::SymbolNumber::calculate(void){
	return postCalculate(getDValue());
}

void dwe::SymbolNumber::setPrevSymbol(Symbol* prev_symbol) {
	if (prev_symbol->getType() == symbolType::number
		|| prev_symbol->getType() == symbolType::parameter) {
		appendPreAddonSymbol(new SymbolDivMultiply("*"));
	}
}