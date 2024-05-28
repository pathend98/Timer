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

Clock::Clock(int hours, int minutes, int seconds) : 
    hours(hours),
    minutes(minutes),
    seconds(seconds)
{
    initialiseDigitVector(hourDigits);
    initialiseDigitVector(minuteDigits);
    initialiseDigitVector(secondDigits);
    setDigits();
}

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
    setDigitPair(hours, hourDigits);
    setDigitPair(minutes, minuteDigits);
    setDigitPair(seconds, secondDigits);
}


shared_ptr<vector<string>> joinStringVectors(const vector<shared_ptr<vector<string>>>& stringVectors)
{
    shared_ptr<vector<string>> result = make_shared<vector<string>>();
    result->reserve(9);

    for (size_t i = 0; i < 9; ++i)
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
