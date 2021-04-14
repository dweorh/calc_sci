#include "symbol.h"
symbol::symbol(void)
{
	value.clear();
	init();
}

symbol::symbol(std::string s){
	value = s;
	init();
}

void symbol::init(void){
	direct_to_stack = false;
	direct_to_output = false;
	check_for_function = false;
	is_function = false;
	number_of_required_arguments = 1;
	skip_calculation = false;
	never_on_stack = false;
	is_unary = false;
}

bool symbol::isValueEmpty(void){
	return value.empty();
}

bool symbol::directToStack(void){
	return direct_to_stack;
}
	
bool symbol::directToOutput(void){
	return direct_to_output;
}	
	
int symbol::getPriority(void){
	return priority;
}
	
void symbol::setValue(std::string s){
	value = s;
}
	
double symbol::getDValue(void){
	return d_value;
}

string symbol::getValue(void){
	return value;
}
	
bool symbol::rewind( symbol *oSymbol ){
	return oSymbol->getPriority() >= getPriority();
}
	
bool symbol::addToStack(symbol *oSymbol ){
	return (getPriority() > oSymbol->getPriority() && !neverOnStack());
}
	
bool symbol::checkForFunction(){
	return check_for_function;
}
	
bool symbol::isFunction(){
	return is_function;
}
	
int symbol::numberOfRequiredArguments(){
	return number_of_required_arguments;
}
	
bool symbol::skipCalculation(){
	return skip_calculation;
}
	
bool symbol::neverOnStack(){
	return never_on_stack;
}
	
bool symbol::isUnary(){
	return is_unary;
}


void symbol::setPrevSymbol(symbol*){}
//	abstract public function calculate($aArguments);