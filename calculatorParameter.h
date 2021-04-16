#pragma once
#include <string>
#include <algorithm>
#include <vector>
namespace dwe
{
    class CalculatorParameter
    {
    public:
        bool error = false;
        double minVal = 0.0;
        double maxVal = 0.0;
        double curVal = 0.0;
        size_t resolution = 1;
        std::string strVal;
        CalculatorParameter(std::string val);
        ~CalculatorParameter(void);
    };
}