#include <iostream>
#include <vector>
#include <string>
#include "calculator.h"

int main()
{
	string equation;
	calculator *calc = nullptr;
	calculatorResult *calc_result = nullptr;
	bool run = true;
	// bool in_radians = false; // angles in radians

	calc_result = new calculatorResult();
	calc = new calculator( calc_result );

	while (run) {
		std::cout << "Equation or leave empty to finish: ";
		std::getline(std::cin, equation);
		if ( equation.length() > 0 ) {
			calc->setEquation(equation);
			calc_result = calc->calculate();

			if( calc_result->ok ){
				cout 
					<< calc_result->equation.c_str() << endl 
					<< "RPN: " << calc_result->onp.c_str() << endl 
					<< calc_result->result.c_str() << endl;
			} else {
				cout << "Error: " << calc_result->msg << endl;
			}
		} else {
			run = false;
		}

	}
	
	delete calc;
}