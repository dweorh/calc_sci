#include "symbolFunction.h"
#include "symbolDivMultiply.h"

symbolFunction::symbolFunction(std::string c)
{
	const double M_PI = 3.1415926;
	init();
	priority = 0;
	direct_to_stack = true;
	is_function = true;
	d2r = M_PI/180;
	setValue(c);
}


symbolFunction::~symbolFunction(void)
{

}

void symbolFunction::setPrevSymbol(symbol *prev_symbol){
	if( prev_symbol->getType() == symbolType::cb
		|| prev_symbol->getType() == symbolType::number
	){
		appendPreAddonSymbol( new symbolDivMultiply("*") );
	}
}

double symbolFunction::calculate(double v){
	double result = 0;
	string func = getValue();

	if( func == "abs")
		result = fabs(v);
	else if(func == "asin" || func == "arcsin")
		result = asin(v*d2r);
	else if(func == "acos" || func == "arccos")
		result = acos(v*d2r);
	else if(func == "cos" || func == "cosd")
		result = cos(v*d2r);
	else if(func == "cosh")
		result = cosh(v*d2r);
	else if(func == "ctg")
		result = cos(v*d2r)/sin(v*d2r);
	else if(func == "actg" || func =="arcctg")
		return atan(1/(v*d2r));
	else if(func == "ctgh")
		result = cosh(v*d2r)/sinh(v*d2r);
	else if(func == "log10")
		result = log10(v);
	else if(func == "log2")
		result = log(v)/log(2);
	else if(func == "log" || func== "ln")
		result = log(v);
	else if(func == "sin")
		result = sin(v*d2r);
	else if(func == "sinh")
		result = sinh(v*d2r);
	else if(func == "sind")
		result = sin(v*d2r);
	else if(func == "sqrt")
		result = sqrt(v);
	else if(func == "tan" || func == "tg")
		result = tan(v*d2r);
	else if(func == "tanh" || func == "tgh")
		result = tanh(v*d2r);
	else if(func == "atan" || func == "arctan")
		result = atan(v*d2r);
	result = postCalculate(result);
	return result;
}