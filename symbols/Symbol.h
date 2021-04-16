#pragma once
#include <string>
#include <vector>


namespace dwe
{
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
			plus = 8,
			parameter = 9
		};
	};

	class Symbol
	{
	private:
		std::string _out;
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
		std::vector<Symbol*> unary_operations;
		std::vector<Symbol*> pre_addon_operations; // list of automaticaly added pre symbols
		Symbol* prev_symbol;
		std::string value;
		double d_value;

		void init(void);

	public:
		Symbol(void);
		Symbol(std::string);
		~Symbol(void) {
			deleteInVector(&unary_operations);
			//deleteInVector(&pre_addon_operations);
		};
		void deleteInVector(std::vector<Symbol*>* v) {
			while (!v->empty()) {
				delete v->back();
				v->pop_back();
			}
		}

		void setValue(std::string);
		void setValue(double);
		bool isValueEmpty(void);
		int getPriority(void);
		int numberOfRequiredArguments();
		virtual bool rewind(Symbol*);
		bool directToStack(void);
		bool directToOutput(void);
		bool skipCalculation();
		bool neverOnStack();
		bool isUnary();
		bool addToStack(Symbol*);
		virtual bool checkForFunction();
		bool isFunction();
		std::string getRealValue() {/* method mostly for onp(rpn) purposes */
			_out = "";
			for (int i = 0; i < (int)unary_operations.size(); i++) {
				_out.append(unary_operations.at(i)->getRealValue());
			}
			return _out.append(value);
		}

		std::vector<Symbol*> getPreAddonSymbols() { return pre_addon_operations; }
		void appendPreAddonSymbol(Symbol* obj) { pre_addon_operations.push_back(obj); }


		virtual std::string getValue(void);
		virtual double getDValue(void);
		virtual double calculate(void) { return 0.0; };
		virtual double calculate(double) { return 0.0; };
		virtual double calculate(double, double) { return 0.0; };
		double postCalculate(double v) {
			double _v = v;
			for (int i = 0; i < (int)unary_operations.size(); i++) {
				_v = unary_operations.at(i)->calculate(_v);
			}
			return _v;
		}
		void addUnaryOperation(Symbol* obj) {
			unary_operations.push_back(obj);
		}
		virtual void setPrevSymbol(Symbol*);

		virtual symbolType::type getType(void) {
			return symbolType::none;
		}
	};
}