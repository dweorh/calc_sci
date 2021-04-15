#pragma once
#include "Symbol.h"
#include <typeinfo>
namespace dwe
{
	class SymbolMinus : public Symbol
	{
	public:
		SymbolMinus(std::string);
		~SymbolMinus(void);
		void setPrevSymbol(Symbol*);
		double calculate(double);
		double calculate(double, double);
		symbolType::type getType(void) {
			return symbolType::minus;
		}
	};
}