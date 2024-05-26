#pragma once

#include <map>
#include <string>

#include "dline.h"

enum class DLinePosition
{
    TOP,
    TOP_LEFT,
    TOP_RIGHT,
    MIDDLE,
    BOTTOM_LEFT,
    BOTTOM_RIGHT,
    BOTTOM
};

class Digit
{
    private:
        std::map<DLinePosition, DLine*> dLines;
        int digit;
        void initialiseDLines();
        void setDLines() const; 
    
    public:
        Digit();
        Digit(int d);
        void setDigit(int d);
        std::string toString();
};
