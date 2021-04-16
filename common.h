#pragma once
#include <string>
#include <vector>
#include <typeinfo>
#include <cctype>
#include "symbols/Symbol.h"
#include "symbols/SymbolCB.h"
#include "symbols/SymbolDivMultiply.h"
#include "symbols/SymbolFactorial.h"
#include "symbols/SymbolFunction.h"
#include "symbols/SymbolMinus.h"
#include "symbols/SymbolNumber.h"
#include "symbols/SymbolOB.h"
#include "symbols/SymbolPlus.h"
#include "symbols/SymbolParameter.h"

namespace dwe
{
	size_t strpos(const std::string& haystack, const std::string& needle);

	int in_array_str(std::string a[], int size, std::string lookfor);
	int in_array_chr(char a[], int size, char c);
	bool is_number(const std::string& s);

	std::string implode(const std::string& glue, const std::vector<std::string>& pieces);
	Symbol* getSymbol(std::string& c);
	std::vector<std::string> string2Tokens(std::string& s);
	void removeLastTokenFromEquation(std::string& s);
	void rtrim(std::string*, char);
}