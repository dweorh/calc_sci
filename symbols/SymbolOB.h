#pragma once
#include "Symbol.h"
namespace dwe
{
	class SymbolOB : public Symbol
	{
	public:
		SymbolOB(void);
		~SymbolOB(void);
		symbolType::type getType(void) {
			return symbolType::ob;
		}
		void setPrevSymbol(Symbol* prev_symbol);
	};
}