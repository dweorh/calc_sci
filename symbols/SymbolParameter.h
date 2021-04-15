#pragma once
#include "Symbol.h"
namespace dwe
{
	class SymbolParameter : public Symbol
	{
	public:
		SymbolParameter(std::string);
		~SymbolParameter(void);
		double calculate(void);
		void setValue(std::string);
		void setPrevSymbol(Symbol* prev_symbol);
		symbolType::type getType(void) {
			return symbolType::parameter;
		}
	};
}