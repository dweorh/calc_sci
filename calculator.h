#pragma once
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
#include "common.h"
#include "CalculatorResult.h"
#include "CalculatorParameter.h"

namespace dwe 
{
	class Calculator
	{
	public:
		bool requireParam = false;
		std::string equation;
		CalculatorResult* result = nullptr;
		CalculatorParameter* parameter = nullptr;
		std::vector<Symbol*> symbols_cache;
		std::vector<Symbol*> parameters_cache;
		std::vector<std::string> tokens_cache;
		Calculator(void);
		Calculator(CalculatorResult*);
		~Calculator(void);
		void setEquation(std::string);
		bool requireParameter();
		void setParameter(CalculatorParameter*);
		void setParameter(std::string);
		void clearCaches(void);
		std::vector<std::string> getTokens(void);
		std::vector<Symbol*> getSymbols(std::vector<Symbol*>& parameters);
		CalculatorResult* calculate(void);
		CalculatorResult* nextCalc(void);

		void deleteInVector(std::vector<Symbol*>* v) {
			while (!v->empty()) {
				delete v->back();
				v->pop_back();
			}
		}
	};
}