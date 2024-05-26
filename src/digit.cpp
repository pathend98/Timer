#include "digit.h"

using std::string;
using std::map;

map<DLinePosition, Orientation> dLineOrientations = 
{
    {DLinePosition::TOP, Orientation::HORIZONTAL},
    {DLinePosition::TOP_LEFT, Orientation::VERTICAL},
    {DLinePosition::TOP_RIGHT, Orientation::VERTICAL},
    {DLinePosition::MIDDLE, Orientation::HORIZONTAL},
    {DLinePosition::BOTTOM_LEFT, Orientation::VERTICAL},
    {DLinePosition::BOTTOM_RIGHT, Orientation::VERTICAL},
    {DLinePosition::BOTTOM, Orientation::VERTICAL}
};

/**
 * TODO: can use a list / vector here because that's what a map with int keys should be
*/
map<int, map<DLinePosition, bool>> digitDLineConfigurations = 
{
    {0, {
        {DLinePosition::TOP, true}, {DLinePosition::TOP_LEFT, true}, {DLinePosition::TOP_RIGHT, true}, {DLinePosition::MIDDLE, false}, {DLinePosition::BOTTOM_LEFT, true}, {DLinePosition::BOTTOM_RIGHT, true}, {DLinePosition::BOTTOM, true}
    }},
    {1, {
        {DLinePosition::TOP, false}, {DLinePosition::TOP_LEFT, false}, {DLinePosition::TOP_RIGHT, true}, {DLinePosition::MIDDLE, false}, {DLinePosition::BOTTOM_LEFT, false}, {DLinePosition::BOTTOM_RIGHT, true}, {DLinePosition::BOTTOM, false}
    }},
    {2, {
        {DLinePosition::TOP, true}, {DLinePosition::TOP_LEFT, false}, {DLinePosition::TOP_RIGHT, true}, {DLinePosition::MIDDLE, true}, {DLinePosition::BOTTOM_LEFT, true}, {DLinePosition::BOTTOM_RIGHT, false}, {DLinePosition::BOTTOM, true}
    }},
    {3, {
        {DLinePosition::TOP, true}, {DLinePosition::TOP_LEFT, false}, {DLinePosition::TOP_RIGHT, true}, {DLinePosition::MIDDLE, true}, {DLinePosition::BOTTOM_LEFT, false}, {DLinePosition::BOTTOM_RIGHT, true}, {DLinePosition::BOTTOM, true}
    }},
    {4, {
        {DLinePosition::TOP, false}, {DLinePosition::TOP_LEFT, true}, {DLinePosition::TOP_RIGHT, true}, {DLinePosition::MIDDLE, true}, {DLinePosition::BOTTOM_LEFT, false}, {DLinePosition::BOTTOM_RIGHT, true}, {DLinePosition::BOTTOM, false}
    }},
    {5, {
        {DLinePosition::TOP, true}, {DLinePosition::TOP_LEFT, true}, {DLinePosition::TOP_RIGHT, false}, {DLinePosition::MIDDLE, true}, {DLinePosition::BOTTOM_LEFT, false}, {DLinePosition::BOTTOM_RIGHT, true}, {DLinePosition::BOTTOM, true}
    }},
    {6, {
        {DLinePosition::TOP, true}, {DLinePosition::TOP_LEFT, true}, {DLinePosition::TOP_RIGHT, false}, {DLinePosition::MIDDLE, true}, {DLinePosition::BOTTOM_LEFT, true}, {DLinePosition::BOTTOM_RIGHT, true}, {DLinePosition::BOTTOM, true}
    }},
    {7, {
        {DLinePosition::TOP, true}, {DLinePosition::TOP_LEFT, false}, {DLinePosition::TOP_RIGHT, true}, {DLinePosition::MIDDLE, false}, {DLinePosition::BOTTOM_LEFT, false}, {DLinePosition::BOTTOM_RIGHT, true}, {DLinePosition::BOTTOM, false}
    }},
    {8, {
        {DLinePosition::TOP, true}, {DLinePosition::TOP_LEFT, true}, {DLinePosition::TOP_RIGHT, true}, {DLinePosition::MIDDLE, true}, {DLinePosition::BOTTOM_LEFT, true}, {DLinePosition::BOTTOM_RIGHT, true}, {DLinePosition::BOTTOM, true}
    }},
    {9, {
        {DLinePosition::TOP, true}, {DLinePosition::TOP_LEFT, true}, {DLinePosition::TOP_RIGHT, true}, {DLinePosition::MIDDLE, true}, {DLinePosition::BOTTOM_LEFT, false}, {DLinePosition::BOTTOM_RIGHT, true}, {DLinePosition::BOTTOM, true}
    }}
};

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
