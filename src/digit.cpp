#include "digit.h"
#include "dlineOrientations.h";
#include "digitDLineConfigurations.h"
#include <vector>

using std::string;
using std::map;
using std::vector;

Digit::Digit(int d) :
    digit(d)
{
    initialiseDLines();
    setDLines();
}

Digit::Digit() : Digit(0) {}

void Digit::initialiseDLines()
{
    dLines = map<DLinePosition, DLine*> {};
    for (const auto& [position, orientation] : dLineOrientations)
    {
        dLines[position] = new DLine(orientation);
    }
}

void Digit::setDLines() const
{
    auto configuration = digitDLineConfigurations[digit];
    for (auto [position, dLine] : dLines)
    {
        if (configuration[position]) {
            dLine->turnOn();
        } else {
            dLine->turnOff();
        }
    }
}

void Digit::setDigit(int d)
{
    digit = d;
    setDLines();
}

/**
 * TODO: clean up this mess
*/
string Digit::toString()
{
    string verticalLineOn = "====";
    string verticalLineOff = "    ";
    string horizontalLineOn = "|";
    string horizontalLineOff = " ";

    return " " + (dLines[DLinePosition::TOP]->isOn() ? verticalLineOn : verticalLineOff) + " \n" 
        + (dLines[DLinePosition::TOP_LEFT]->isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (dLines[DLinePosition::TOP_RIGHT]->isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + (dLines[DLinePosition::TOP_LEFT]->isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (dLines[DLinePosition::TOP_RIGHT]->isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + (dLines[DLinePosition::TOP_LEFT]->isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (dLines[DLinePosition::TOP_RIGHT]->isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + " " + (dLines[DLinePosition::MIDDLE]->isOn() ? verticalLineOn : verticalLineOff) + " \n"
        + (dLines[DLinePosition::BOTTOM_LEFT]->isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (dLines[DLinePosition::BOTTOM_RIGHT]->isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + (dLines[DLinePosition::BOTTOM_LEFT]->isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (dLines[DLinePosition::BOTTOM_RIGHT]->isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + (dLines[DLinePosition::BOTTOM_LEFT]->isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (dLines[DLinePosition::BOTTOM_RIGHT]->isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + " " + (dLines[DLinePosition::BOTTOM]->isOn() ? verticalLineOn : verticalLineOff) + " \n";
}
