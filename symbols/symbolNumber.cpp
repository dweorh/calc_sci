#include "symbolNumber.h"


symbolNumber::symbolNumber(void)
{
	init();
	number_of_required_arguments = 0;
	priority = 0;
	direct_to_output = true;
	direct_to_stack = false;
	never_on_stack = true;
	setValue("0.0");
}

symbolNumber::symbolNumber(string c)
{
	init();
	number_of_required_arguments = 0;
	priority = 0;
	direct_to_output = true;
	direct_to_stack = false;
	never_on_stack = true;
	setValue(c);
}

void symbolNumber::setValue(string s){
	value = s;
	d_value = atof(s.c_str());
}

symbolNumber::~symbolNumber(void)
{
}

double symbolNumber::calculate(void){
	return postCalculate(getDValue());
}