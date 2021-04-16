#include "Symbol.h"
dwe::Symbol::Symbol(void)
{
	value.clear();
	init();
}

dwe::Symbol::Symbol(std::string s){
	value = s;
	init();
}

void dwe::Symbol::init(void){
	direct_to_stack = false;
	direct_to_output = false;
	check_for_function = false;
	is_function = false;
	number_of_required_arguments = 1;
	skip_calculation = false;
	never_on_stack = false;
	is_unary = false;
}

bool dwe::Symbol::isValueEmpty(void){
	return value.empty();
}

bool dwe::Symbol::directToStack(void){
	return direct_to_stack;
}
	
bool dwe::Symbol::directToOutput(void){
	return direct_to_output;
}	
	
int dwe::Symbol::getPriority(void){
	return priority;
}
	
void dwe::Symbol::setValue(std::string s){
	value = s;
}

void dwe::Symbol::setValue(double v) {
	d_value = v;
	value = std::to_string(v);
}

double dwe::Symbol::getDValue(void){
	return d_value;
}

std::string dwe::Symbol::getValue(void){
	return value;
}
	
bool dwe::Symbol::rewind(Symbol *oSymbol ){
	return oSymbol->getPriority() >= getPriority();
}
	
bool dwe::Symbol::addToStack(Symbol *oSymbol ){
	return (getPriority() > oSymbol->getPriority() && !neverOnStack());
}
	
bool dwe::Symbol::checkForFunction(){
	return check_for_function;
}
	
bool dwe::Symbol::isFunction(){
	return is_function;
}
	
int dwe::Symbol::numberOfRequiredArguments(){
	return number_of_required_arguments;
}
	
bool dwe::Symbol::skipCalculation(){
	return skip_calculation;
}
	
bool dwe::Symbol::neverOnStack(){
	return never_on_stack;
}
	
bool dwe::Symbol::isUnary(){
	return is_unary;
}


void dwe::Symbol::setPrevSymbol(Symbol*){}
//	abstract public function calculate($aArguments);