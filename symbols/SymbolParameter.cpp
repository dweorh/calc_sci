#include "SymbolParameter.h"
#include "SymbolDivMultiply.h"

dwe::SymbolParameter::SymbolParameter(std::string c)
{
	init();
	number_of_required_arguments = 0;
	priority = 0;
	// direct_to_stack = true;
	// is_function = true;
	direct_to_output = true;
	direct_to_stack = false;
	never_on_stack = true;
	setValue(c);
}

void dwe::SymbolParameter::setValue(std::string s) {
	value = s;
	d_value = atof(s.c_str());
}

dwe::SymbolParameter::~SymbolParameter(void)
{
}

void dwe::SymbolParameter::setPrevSymbol(Symbol* prev_symbol) {
	if (prev_symbol->getType() == symbolType::number) {
		appendPreAddonSymbol(new SymbolDivMultiply("*"));
	}
}

double dwe::SymbolParameter::calculate(void) {
	return postCalculate(getDValue());
}