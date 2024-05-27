#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

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
        std::unordered_map<DLinePosition, std::unique_ptr<DLine>> dLines;
        int digit;
        void initialiseDLines();
        void setDLines() const; 
    
    public:
        Digit();
        Digit(const int d);
        void setDigit(const int d);
        std::shared_ptr<std::vector<std::string>> toString() const;
};
