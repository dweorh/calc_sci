#include "symbolMinus.h"
#include "../common.h"

symbolMinus::symbolMinus(std::string c)
{
	init();
	/* default settings */
	priority = 1;
	number_of_required_arguments = -1; // might be 1 if it's unary symbol or two if it's a part of subtraction
	is_unary = true; //default setting, might be modified in setPrevSymbol method
	never_on_stack = true; //default setting, might be modified in setPrevSymbol method
	setValue(c);
}


symbolMinus::~symbolMinus(void)
{
}

void symbolMinus::setPrevSymbol(symbol *prev_symbol){
	if( prev_symbol->getType() == symbolType::ob
		|| prev_symbol->getType() == symbolType::minus
		|| prev_symbol->getType() == symbolType::plus
		|| prev_symbol->getType() == symbolType::div_multiply
	){
		number_of_required_arguments = 1;
		is_unary = true;
		never_on_stack = true;
	} else {
		number_of_required_arguments = 2;
		is_unary = false;
		never_on_stack = false;
	}	
}
	
double symbolMinus::calculate( double v ){
	return postCalculate( v * (-1.0) );
}	

double symbolMinus::calculate( double v1, double v2 ){
	return postCalculate( v1 - v2 );
}	