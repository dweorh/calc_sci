#include "symbolDivMultiply.h"

symbolDivMultiply::symbolDivMultiply(string s)
{
	init();
	if( s == "^" )
		priority = 3;
	else
		priority = 2;
	number_of_required_arguments = 2;
	setValue(s);
}

symbolDivMultiply::~symbolDivMultiply(void)
{
}

double symbolDivMultiply::calculate(double v1, double v2){
	string op = getValue();
	double result = 0;
	if( op == "*" )
		result = v1 * v2;
	else if( op == "/" ){
		result = v1 / v2;
	} else if( op == "|" ){ // modulo % was replaced by pipe
		result = fmod(v1,v2);
	}else if( op == "^" )
		result = pow(v1,v2);
	return result;
}