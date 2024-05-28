#pragma once

#include <vector>
#include <memory>

#include "digit.h"

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

/**
 * A class to represent a time consisting of seconds and minutes.
*/
class Clock
{
    private:
        // Could also consider using `struct tm` from <time>, but this includes parts which aren't needed here
        Time time;
        
        std::vector<std::unique_ptr<Digit>> hourDigits;
        std::vector<std::unique_ptr<Digit>> minuteDigits;
        std::vector<std::unique_ptr<Digit>> secondDigits;

        void setDigits();

    public:
        Clock(const Time time);
        Clock(const int seconds);
        Clock(const int hours, const int minutes, const int seconds);
        Clock();
        void setTime(const Time& t);
        void setTime(const int hours, const int minutes, const int seconds);
        Time getTime() const;
        std::shared_ptr<std::vector<std::string>> toString() const;
};
