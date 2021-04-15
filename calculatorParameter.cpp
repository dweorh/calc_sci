// #pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "CalculatorParameter.h"
#include "common.h"

dwe::CalculatorParameter::CalculatorParameter(std::string val)
{
    std::string parameter = val;
    parameter.erase(std::remove(parameter.begin(), parameter.end(), ' '), parameter.end());
    if (is_number(parameter))
    {
        minVal = atof(parameter.c_str());
        maxVal = minVal;
    } else if (parameter.find(',') != std::string::npos)
    {
        std::stringstream ss(parameter);
        std::vector<std::string> result;

        while( ss.good() )
        {
            std::string substr;
            std::getline( ss, substr, ',' );
            result.push_back( substr );
        }

        if (result.size() >= 2)
        {
            if (is_number(result[0]) && is_number(result[1])) {
                minVal = atof(result[0].c_str());
                maxVal = atof(result[1].c_str());
            }
            if (result.size() == 3) {
                resolution = atoi(result[2].c_str());
            }
        } else {
            error = true;
        }
    } else {
        error = true;
    }
    curVal = minVal;
}


dwe::CalculatorParameter::~CalculatorParameter(void)
{
}