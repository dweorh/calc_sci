#include "calculator.h"
#include "symbols/symbol.h"

calculator::calculator(calculatorResult *r){
	result = r;
}

calculator::calculator(void)
{
	result = new calculatorResult();
}


calculator::~calculator(void)
{
	delete result;
}

void calculator::setEquation( string eq ){
	std::string result;
	equation = eq;
	// normalization of the equation
	std::replace(equation.begin(), equation.end(), ',', '.' );
	
	result.resize(equation.size());
	std::remove_copy(equation.begin(), equation.end(), result.begin(), ' ');
	equation = result;

	//std::replace(equation.begin(), equation.end(), ' ', ' ' );
}

vector<string> calculator::getTokens(){
	return string2Tokens(equation);
}

calculatorResult* calculator::calculate(void){
	char result_buffer[250];
	int vector_size;
	double current_number,current_number2, calc_result;
	vector<string> tokens;
	vector<string> onp_simple;
	vector<double> numbers_stack;
	symbol *last_symbol = NULL;
	symbol *current_s = NULL;
	string current_token;
	int brackets_diff = 0; // diff in number of open and close brackets
	vector<symbol*> onp;
	vector<symbol*> symbols;
	vector<symbol*> stack;
	vector<symbol*> pre_addon_symbols;

	result->reset();
	result->equation = equation;
	
	tokens = getTokens();
	
	// reduce unary operators from equation
	vector_size = tokens.size();
	for(int i = 0; i < vector_size; i++){
		current_token = tokens.at(i);
		current_s = getSymbol( tokens.at(i) );
		
		if( current_s->getType() == symbolType::none ){
			result->msg = "wrong symbol: " + current_token;
			result->ok = false;
			return result;
		}
		
		if( last_symbol != NULL ) {
			current_s->setPrevSymbol(last_symbol);
			pre_addon_symbols = current_s->getPreAddonSymbols();
			while(!pre_addon_symbols.empty()){
				symbols.push_back( pre_addon_symbols.front() );
				pre_addon_symbols.erase(pre_addon_symbols.begin());
			}
		}

		if( last_symbol != NULL && (*last_symbol).isUnary() ){
			current_s->addUnaryOperation(last_symbol);
		}
		if( ! current_s->isUnary() ){
			symbols.push_back( current_s );
		}

		last_symbol = current_s;

		if( current_s->getType() == symbolType::ob )
			brackets_diff++;
		else if( current_s->getType() == symbolType::cb )
			brackets_diff--;
	}

	if( brackets_diff != 0 ){
		result->ok = false;
		result->msg = "wrong syntax";
		deleteInVector(&symbols);
		return result;
	}

	// split symbols set to numbers and pure symbols 
	while( !symbols.empty() ){
		current_s = symbols.front();
		symbols.erase(symbols.begin());
		if( current_s->directToOutput() ){ //eg. numbers
			onp.push_back( current_s );
			continue;
		} else if ( current_s->directToStack() ){ //eg. open bracket
			stack.push_back( current_s );
			continue;
		} else {
			if( stack.empty() || (stack.size() > 0 && current_s->addToStack(stack.back()))){
				stack.push_back(current_s);
				continue;
			} else {
				while(!stack.empty()){
					last_symbol = stack.back();
					stack.pop_back();
					if( current_s->rewind(last_symbol) ){
						onp.push_back(last_symbol);
					} else if( current_s->checkForFunction() ){
						delete last_symbol;
						if( stack.size() == 0 ) break;

						last_symbol = stack.back();
						stack.pop_back();
						if( last_symbol->isFunction() )
							onp.push_back(last_symbol);
						else
							stack.push_back(last_symbol);
						break;
					} else {
						stack.push_back(last_symbol);
						break;
					}
				}
			
				if( ! current_s->neverOnStack() ){
					stack.push_back( current_s );
				} else {
					delete current_s;
				}
			}
		}
	}
	while( !stack.empty() ){ // pop rest of symbols from stack
		last_symbol = stack.at(stack.size()-1);
		stack.pop_back();
		onp.push_back(last_symbol);
	}

	vector_size = onp.size();
	for( int i=0; i<vector_size; i++){
		onp_simple.push_back( onp.at(i)->getRealValue() );
	}

	for( int i=0; i<vector_size; i++){
		current_s = onp.at(i);
		if( current_s->skipCalculation() )
			continue;
		if( current_s->numberOfRequiredArguments() > (int)numbers_stack.size()) {
			result->ok = false;
			result->msg = "syntax error, not enough parameters for `" + current_s->getValue() + "`";
			deleteInVector(&onp);
			return result;
		}
		switch( current_s->numberOfRequiredArguments() ){
			case 0: // number itself
				calc_result = current_s->calculate();
				if( isnan( calc_result ) ){
					result->ok = false;
					result->msg = "result is not a number";
					deleteInVector(&onp);
					return result;
				}
				numbers_stack.push_back( calc_result );
			break;
			case 1: // eg. functions
				current_number = numbers_stack.at( numbers_stack.size()-1);
				numbers_stack.pop_back();
				calc_result = current_s->calculate(current_number);
				if( isnan( calc_result ) ){
					result->ok = false;
					result->msg = "result is not a number";
					deleteInVector(&onp);
					return result;
				}
				numbers_stack.push_back( calc_result );
				break;
			case 2: // eg. divide, add etc.
				current_number = numbers_stack.at(numbers_stack.size()-1);
				numbers_stack.pop_back();
				current_number2 = numbers_stack.at(numbers_stack.size()-1);
				numbers_stack.pop_back();
				calc_result = current_s->calculate(current_number2,current_number);

				if( isnan( calc_result ) ){
					result->ok = false;
					result->msg = "result is not a number";
					deleteInVector(&onp);
					return result;
				}
				numbers_stack.push_back( calc_result );
				break;
		}
	}
	current_s = NULL;
	if( numbers_stack.size() > 0 ){
		sprintf(result_buffer,"%f",numbers_stack.at(0));
		result->result = result_buffer;
		rtrim(&result->result, '0');
		rtrim(&result->result, '.');
		result->onp = implode(" ",onp_simple);
		result->d_result = numbers_stack.at(0);
		numbers_stack.pop_back();
	} else {	
		result->ok = false;
		result->msg = "empty result";
	}
	deleteInVector(&onp);
	return result;
}