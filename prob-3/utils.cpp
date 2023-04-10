//
// Created by vladislav on 06.03.23.
//
#include <cmath>
#include <cstring>


int ParseNumber(const char* str)
{
    int outNumber = 0;
    int numberSize = strlen(str);

    for (int i = numberSize-1; i >= 0; --i)
		if (str[i] != '-')
        	outNumber += (str[i]-'0') * (int)pow(10, numberSize-i-1);


    return (str[0] == '-') ? -outNumber: outNumber;
}