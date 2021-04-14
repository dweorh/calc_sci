#pragma once
#include <string>
using namespace std;
class calculatorResult{
public:
	string equation;
	string onp;
	string result;
	string msg;
	bool ok;
	double d_result;

	calculatorResult(void){
		reset();
	}
	~calculatorResult(void){}

	void reset(){
		equation = "";
		onp = "";
		result = "";
		msg = "";
		ok = true;
		d_result = 0.0;
	}
};