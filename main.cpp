#include <iostream>
#include <vector>
#include <string>
#include "Calculator.h"
using namespace dwe;
int main()
{
	std::string equation;
	Calculator *calc = nullptr;
	CalculatorResult *calc_result = nullptr;
	bool run = true;
	// bool in_radians = false; // angles in radians

	calc_result = new CalculatorResult();
	calc = new Calculator( calc_result );

	while (run) {
		std::cout << "Equation or leave empty to finish: ";
		std::getline(std::cin, equation);
		if ( equation.length() > 0 ) {
			calc->setEquation(equation);
			if (calc->requireParameter()) {
				std::string param;
				std::cout << "x: ";
				std::getline(std::cin, param);
				calc->setParameter(param);
			}
			calc_result = calc->calculate();

			if( calc_result->ok ){
				std::cout 
					<< calc_result->equation.c_str() << std::endl
					<< "RPN: " << calc_result->onp.c_str() << std::endl
					<< calc_result->result.c_str() << std::endl;
				while (calc_result = calc->nextCalc()) {
					std::cout
						<< calc_result->equation.c_str() << std::endl
						<< "x: " << calc_result->curParam << std::endl
						<< "RPN: " << calc_result->onp.c_str() << std::endl
						<< calc_result->result.c_str() << std::endl;
				}
			} else {
				std::cout << "Error: " << calc_result->msg << std::endl;
			}
		} else {
			run = false;
		}

	}
	
	delete calc;
}