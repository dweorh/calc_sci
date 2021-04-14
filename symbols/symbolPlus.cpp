#include "symbolPlus.h"


symbolPlus::symbolPlus(std::string c)
{
	init();
	priority = 1;
	number_of_required_arguments = 2;
	setValue(c);
}


symbolPlus::~symbolPlus(void)
{
}