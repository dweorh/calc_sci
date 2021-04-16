#pragma once
#include "Symbol.h"
namespace dwe
{
	class SymbolPlus :
		public Symbol
	{
	public:
		SymbolPlus(std::string);
		~SymbolPlus(void);
		double calculate(double v1, double v2) {
			return v1 + v2;
		}
		symbolType::type getType(void) {
			return symbolType::plus;
		}
	};
}