//
// Created by vladislav on 06.03.23.
//

#include "utils.h"
#include <cmath>


int ParseNumber(const std::string& str)
{
    int outNumber = 0;
    int numberSize = (str.front() == '0') ? str.size()-1 : str.size();

    for (int i = numberSize-1; i >= 0; --i)
        if (str[i] != '-')
            outNumber += (str[i]-'0') * (int)pow(10, numberSize-i-1);


    return (str.front() == '-') ? -outNumber : outNumber;
}