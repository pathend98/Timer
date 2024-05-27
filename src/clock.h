#pragma once

#include <vector>
#include <memory>

#include "digit.h"

/**
 * A class to represent a time consisting of seconds and minutes.
*/
class Clock
{
    private:
        // Could also consider using `struct tm` from <time>, but this includes parts which aren't needed here
        int minutes;
        int seconds;
        
        std::vector<std::unique_ptr<Digit>> minuteDigits;
        std::vector<std::unique_ptr<Digit>> secondDigits;

        void setDigits();

    public:
        Clock(int minutes, int seconds);
        Clock();
        std::shared_ptr<std::vector<std::string>> toString() const;
};
