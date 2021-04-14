#pragma once
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
#include "common.h"
#include "calculatorResult.h"

using namespace std;

class calculator
{
public:
	calculatorResult *result;
	string equation;
	calculator(void);
	calculator(calculatorResult *);
	~calculator(void);
	void setEquation(string);
	vector<string> getTokens(void);
	calculatorResult *calculate(void);

	void deleteInVector(vector<symbol*>* v) {
		while(!v->empty()) {
			delete v->back();
			v->pop_back();
		}
	}
};

