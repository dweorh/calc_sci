#pragma once
#include <string>
#include <vector>
using namespace std;

namespace symbolType {
	enum type{
		none = 0,
		cb = 1,
		div_multiply = 2,
		factorial = 3,
		function = 4,
		minus = 5,
		number = 6,
		ob = 7,
		plus = 8
	};
};

class symbol
{
private:
	string _out;
protected:
	int priority;
	int number_of_required_arguments;
	bool direct_to_stack;
	bool direct_to_output;
	bool check_for_function;
	bool is_function;
	bool skip_calculation;
	bool never_on_stack;
	bool is_unary;
	vector<symbol*> unary_operations;
	vector<symbol*> pre_addon_operations; // list of automaticaly added pre symbols
	symbol *prev_symbol;
	string value;
	double d_value;

	void init(void);

public:
	symbol(void);
	symbol(string);
	~symbol(void){
		deleteInVector(&unary_operations);
		//deleteInVector(&pre_addon_operations);
	};
	void deleteInVector(vector<symbol*>* v) {
		while(!v->empty()) {
			delete v->back();
			v->pop_back();
		}
	}

	void setValue(string);
	bool isValueEmpty(void);
	int getPriority(void);
	int numberOfRequiredArguments();
	virtual bool rewind(symbol*);
	bool directToStack(void);
	bool directToOutput(void);
	bool skipCalculation();
	bool neverOnStack();
	bool isUnary();
	bool addToStack(symbol*);
	virtual bool checkForFunction();
	bool isFunction();
	string getRealValue(){/* method mostly for onp(rpn) purposes */
		_out = "";
		for( int i=0; i < (int)unary_operations.size();i++){
			_out.append( unary_operations.at(i)->getRealValue() );
		}
		return _out.append( value );
	}

	vector<symbol*> getPreAddonSymbols(){ return pre_addon_operations; }
	void appendPreAddonSymbol(symbol *obj ){ pre_addon_operations.push_back( obj );	}


	virtual string getValue(void);
	virtual double getDValue(void);
	virtual double calculate(void){ return 0.0; };
	virtual double calculate(double){ return 0.0; };
	virtual double calculate(double,double){ return 0.0; };
	double postCalculate(double v){
		double _v = v;
		for( int i=0; i < (int)unary_operations.size();i++){
			_v = unary_operations.at(i)->calculate(_v);
		}
		return _v;
	}
	void addUnaryOperation( symbol *obj ){
		unary_operations.push_back(obj);
	}
	virtual void setPrevSymbol(symbol*);

	virtual symbolType::type getType(void){
		return symbolType::none;
	}
};