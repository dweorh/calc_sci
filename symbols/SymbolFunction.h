#pragma once
#include "Symbol.h"
#include "math.h"
namespace dwe
{
	class SymbolFunction : public Symbol
	{
	public:
		double d2r;
		SymbolFunction(std::string);
		~SymbolFunction(void);
		double calculate(double v);
		void setPrevSymbol(Symbol*);
		symbolType::type getType(void) {
			return symbolType::function;
		}
	};
}