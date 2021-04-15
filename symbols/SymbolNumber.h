#pragma once
#include "Symbol.h"
namespace dwe
{
	class SymbolNumber : public Symbol
	{
	public:
		SymbolNumber(void);
		SymbolNumber(std::string);
		~SymbolNumber(void);
		double calculate(void);
		void setValue(std::string);
		void setPrevSymbol(Symbol* prev_symbol);
		symbolType::type getType(void) {
			return symbolType::number;
		}
	};
}