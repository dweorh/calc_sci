#pragma once
#include <string>
namespace dwe
{
	class CalculatorResult {
	public:
		std::string equation;
		std::string onp;
		std::string result;
		std::string msg;
		bool ok;
		double d_result;
		double curParam;
		int resolution;

		CalculatorResult(void) {
			reset();
		}
		~CalculatorResult(void) {}

		void reset() {
			equation = "";
			onp = "";
			result = "";
			msg = "";
			ok = true;
			d_result = 0.0;
			curParam = 0.0;
			resolution = 0;
		}
	};
}