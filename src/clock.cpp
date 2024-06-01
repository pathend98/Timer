#include "clock.h"

using std::make_unique;
using std::make_shared;
using std::unique_ptr;
using std::shared_ptr;
using std::string;
using std::vector;

// Could be a lambda
void initialiseDigitVector(vector<unique_ptr<Digit>>& digits)
{
    digits.clear();
    digits.reserve(2);

    for (size_t i = 0; i < 2; ++i)
        digits.push_back(make_unique<Digit>());
}

Clock::Clock(const Time time) :
    time(time)
{
    initialiseDigitVector(hourDigits);
    initialiseDigitVector(minuteDigits);
    initialiseDigitVector(secondDigits);
    setDigits();
}

Clock::Clock(const int hours, const int minutes, const int seconds) : Clock(Time{hours, minutes, seconds})
{}

Clock::Clock(const int seconds) : Clock(Time{seconds /3600, (seconds % 3600) / 60, (seconds % 3600) % 60 })
{}

Clock::Clock() : Clock(0, 0, 0)
{}

// Could be a lambda
void setDigitPair(int& digit, vector<unique_ptr<Digit>>& digitPair)
{
    digitPair[0]->setDigit(digit / 10);
    digitPair[1]->setDigit(digit % 10);
}

void Clock::setDigits()
{
    setDigitPair(time.hours, hourDigits);
    setDigitPair(time.minutes, minuteDigits);
    setDigitPair(time.seconds, secondDigits);
}

void Clock::setTime(const Time& t)
{
    time = t;
    setDigits();
}

void Clock::setTime(const int hours, const int minutes, const int seconds)
{
    setTime(Time{hours, minutes, seconds});
}

Time Clock::getTime() const
{
    return time;
}

shared_ptr<vector<string>> joinStringVectors(const vector<shared_ptr<vector<string>>>& stringVectors)
{
    shared_ptr<vector<string>> result = make_shared<vector<string>>();
    result->reserve(7);

    for (size_t i = 0; i < 7; ++i)
        result->push_back("");

    for (const auto& stringVector : stringVectors)
    {   
        for (size_t i = 0; i < stringVector->size(); ++i)
            (*result)[i] += (*stringVector)[i];
    }

    return result;
}

shared_ptr<vector<string>> digitPairToString(const vector<unique_ptr<Digit>>& digitPair)
{
    vector<shared_ptr<vector<string>>> stringVectors;
    stringVectors.reserve(3);
    
    const auto separator = make_shared<vector<string>>();
    separator->reserve(7);
    separator->push_back(" ");
    separator->push_back(" ");
    separator->push_back(" ");
    separator->push_back(" ");
    separator->push_back(" ");
    separator->push_back(" ");
    separator->push_back(" ");

    stringVectors.push_back(digitPair[0]->toString());
    stringVectors.push_back(separator);
    stringVectors.push_back(digitPair[1]->toString());

    return joinStringVectors(stringVectors);
}

shared_ptr<vector<string>> Clock::toString() const
{
    const auto hourStrings = digitPairToString(hourDigits);
    const auto minuteStrings = digitPairToString(minuteDigits);
    const auto secondStrings = digitPairToString(secondDigits);

    const auto separator = make_shared<vector<string>>();
    separator->reserve(7);
    separator->push_back("    ");
    separator->push_back(" ++ ");
    separator->push_back(" ++ ");
    separator->push_back("    ");
    separator->push_back(" ++ ");
    separator->push_back(" ++ ");
    separator->push_back("    ");

    vector<shared_ptr<vector<string>>> stringVectors;
    stringVectors.reserve(5);
    stringVectors.push_back(hourStrings);
    stringVectors.push_back(separator);
    stringVectors.push_back(minuteStrings);
    stringVectors.push_back(separator);
    stringVectors.push_back(secondStrings);

    return joinStringVectors(stringVectors);
}
