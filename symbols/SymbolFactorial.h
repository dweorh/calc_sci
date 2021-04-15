#pragma once
#include "Symbol.h"
namespace dwe
{
	class SymbolFactorial : public Symbol
	{
	public:
		SymbolFactorial(std::string);
		~SymbolFactorial(void);
		int factorial(int);
		double calculate(double);
		symbolType::type getType(void) {
			return symbolType::factorial;
		}
	};
}