#pragma once
#include "Symbol.h"
#include "math.h"
namespace dwe
{
	class SymbolDivMultiply : public Symbol
	{
	protected:
	public:
		SymbolDivMultiply(std::string);
		~SymbolDivMultiply(void);
		double calculate(double, double);
		symbolType::type getType(void) {
			return symbolType::div_multiply;
		}
	};
}