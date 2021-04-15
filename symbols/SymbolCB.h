#pragma once
#include "Symbol.h"
#include <typeinfo>
namespace dwe
{
	class SymbolCB : public Symbol
	{
	public:
		SymbolCB(void);
		~SymbolCB(void);
		bool rewind(Symbol*);
		symbolType::type getType(void) {
			return symbolType::cb;
		}
	};
}