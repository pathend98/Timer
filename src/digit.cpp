#include "digit.h"
#include "dlineOrientations.h"
#include "digitDLineConfigurations.h"

#include <utility>

using std::string;
using std::make_unique;
using std::make_shared;
using std::shared_ptr;
using std::vector;

Digit::Digit(const int d) : digit(d)
{
    initialiseDLines();
    setDLines();
}

Digit::Digit() : Digit(0) {}

void Digit::initialiseDLines()
{
    dLines.clear();
    for (const auto& [position, orientation] : dLineOrientations)
        dLines[position] = make_unique<DLine>(orientation);
}

void Digit::setDLines() const
{
    const auto& configuration = digitDLineConfigurations[digit];
    for (const auto& [position, dLine] : dLines)
    {
        if (configuration.at(position))
            dLine->turnOn();
        else 
            dLine->turnOff();
    }
}

void Digit::setDigit(const int d)
{
    digit = d;
    setDLines();
}

shared_ptr<vector<string>> getVerticalDLineString(const DLine& dLine)
{
    const string verticalLineOn = "====";
    const string verticalLineOff = "    ";

    auto result = make_shared<vector<string>>();
    result->reserve(1);
    result->push_back(" " + (dLine.isOn() ? verticalLineOn : verticalLineOff) + " ");

    return result;
}

shared_ptr<vector<string>> getHorizontalDLineString(const DLine& left, const DLine& right)
{
    const string horizontalLineOn = "|";
    const string horizontalLineOff = " ";
    const string horizontalLine = (left.isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (right.isOn() ? horizontalLineOn : horizontalLineOff);

    auto result = make_shared<vector<string>>();
    result->reserve(2);
    
    for (size_t i = 0; i < 2; ++i)
        result->push_back(horizontalLine);
    
    return result;
}

/**
 * TODO: clean up this mess
*/
shared_ptr<vector<string>> Digit::toString() const
{
    // The vector is always going to be 9 elements. 
    vector<shared_ptr<vector<string>>> lines;
    lines.reserve(5);
    lines.push_back(getVerticalDLineString(*dLines.at(DLinePosition::TOP)));
    lines.push_back(getHorizontalDLineString(*dLines.at(DLinePosition::TOP_LEFT), *dLines.at(DLinePosition::TOP_RIGHT)));
    lines.push_back(getVerticalDLineString(*dLines.at(DLinePosition::MIDDLE)));
    lines.push_back(getHorizontalDLineString(*dLines.at(DLinePosition::BOTTOM_LEFT), *dLines.at(DLinePosition::BOTTOM_RIGHT)));
    lines.push_back(getVerticalDLineString(*dLines.at(DLinePosition::BOTTOM)));

    shared_ptr<vector<string>> result = make_shared<vector<string>>();
    result->reserve(7);

    for (const auto& line : lines)
        std::move(line->begin(), line->end(), std::back_inserter(*result));

    return result;
}
