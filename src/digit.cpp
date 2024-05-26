#include "digit.h"
#include "dlineOrientations.h"
#include "digitDLineConfigurations.h"
#include <vector>

using std::string;
using std::make_unique;

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

/**
 * TODO: clean up this mess
*/
string Digit::toString() const
{
    string verticalLineOn = "====";
    string verticalLineOff = "    ";
    string horizontalLineOn = "|";
    string horizontalLineOff = " ";

    return " " + (dLines.at(DLinePosition::TOP)->isOn() ? verticalLineOn : verticalLineOff) + " \n" 
        + (dLines.at(DLinePosition::TOP_LEFT)->isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (dLines.at(DLinePosition::TOP_RIGHT)->isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + (dLines.at(DLinePosition::TOP_LEFT)->isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (dLines.at(DLinePosition::TOP_RIGHT)->isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + (dLines.at(DLinePosition::TOP_LEFT)->isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (dLines.at(DLinePosition::TOP_RIGHT)->isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + " " + (dLines.at(DLinePosition::MIDDLE)->isOn() ? verticalLineOn : verticalLineOff) + " \n"
        + (dLines.at(DLinePosition::BOTTOM_LEFT)->isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (dLines.at(DLinePosition::BOTTOM_RIGHT)->isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + (dLines.at(DLinePosition::BOTTOM_LEFT)->isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (dLines.at(DLinePosition::BOTTOM_RIGHT)->isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + (dLines.at(DLinePosition::BOTTOM_LEFT)->isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (dLines.at(DLinePosition::BOTTOM_RIGHT)->isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + " " + (dLines.at(DLinePosition::BOTTOM)->isOn() ? verticalLineOn : verticalLineOff) + " \n";
}
