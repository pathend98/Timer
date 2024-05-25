#pragma once

#include <string>

#include "dline.h"

class Digit
{
    private:
        DLine top;
        DLine topRight;
        DLine topLeft;
        DLine middle;
        DLine bottomRight;
        DLine bottomLeft;
        DLine bottom;
        int digit;
        void setDlines();
    
    public:
        Digit();
        Digit(int d);
        void setDigit(int d);
        std::string toString();
};
