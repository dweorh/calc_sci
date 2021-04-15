#include "SymbolPlus.h"


dwe::SymbolPlus::SymbolPlus(std::string c)
{
	init();
	priority = 1;
	number_of_required_arguments = 2;
	setValue(c);
}


dwe::SymbolPlus::~SymbolPlus(void)
{
}