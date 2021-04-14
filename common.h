#pragma once
#include <string>
#include <vector>
#include <typeinfo>
#include <cctype>
#include "symbols/symbol.h"
#include "symbols/symbolCB.h"
#include "symbols/symbolDivMultiply.h"
#include "symbols/symbolFactorial.h"
#include "symbols/symbolFunction.h"
#include "symbols/symbolMinus.h"
#include "symbols/symbolNumber.h"
#include "symbols/symbolOB.h"
#include "symbols/symbolPlus.h"

size_t strpos(const string &haystack, const string &needle);

int in_array_str( string a[], int size, string lookfor );
int in_array_chr( char a[], int size, char c);
bool is_number(const string& s);

string implode( const string &glue, const vector<string> &pieces );
symbol* getSymbol( string &c );
vector<string> string2Tokens( string &s);
void removeLastTokenFromEquation(string &s);
void rtrim(string*,char);
