//func.cc
//
//Autor: Bartłomiej Sitnik

#include "func.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <climits>


void safetly_input_short(int16_t & s) noexcept(false)
{
    std::string str;
    std::cin >> str;
    if ((str[0]>'9' || str[0]<'0') && str[0] != '-')
            throw std::invalid_argument("Input is not an integer");
    for (unsigned int i = 1; i < str.size(); i++)
        if (str[i]>'9' || str[i]<'0')
            throw std::invalid_argument("Input is not an integer");
    int x = std::stoi(str);
    if (x > INT16_MAX || x < INT16_MIN)
        throw std::invalid_argument("Input does not fit on int16_t");
    s = (int16_t)x;    
}