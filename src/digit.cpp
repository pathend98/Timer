#include "digit.h"

using std::string;

Digit::Digit(int d) :
    top(Orientation::HORIZONTAL),
    topRight(Orientation::VERTICAL),
    topLeft(Orientation::VERTICAL),
    middle(Orientation::HORIZONTAL),
    bottomRight(Orientation::VERTICAL),
    bottomLeft(Orientation::VERTICAL),
    bottom(Orientation::HORIZONTAL),
    digit(d)
{
    setDlines();
}

Digit::Digit() : Digit(0) {}

/**
 * TODO: Needs a real implementation 
*/
void Digit::setDlines()
{
    top.turnOn();
    topRight.turnOn();
    topLeft.turnOn();
    middle.turnOff();
    bottomRight.turnOn();
    bottomLeft.turnOn();
    bottom.turnOn();
}

void Digit::setDigit(int d)
{
    digit = d;
    setDlines();
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

    return " " + (top.isOn() ? verticalLineOn : verticalLineOff) + " \n" 
        + (topLeft.isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (topRight.isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + (topLeft.isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (topRight.isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + (topLeft.isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (topRight.isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + " " + (middle.isOn() ? verticalLineOn : verticalLineOff) + " \n"
        + (bottomLeft.isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (bottomRight.isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + (bottomLeft.isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (bottomRight.isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + (bottomLeft.isOn() ? horizontalLineOn : horizontalLineOff) + "    " + (bottomRight.isOn() ? horizontalLineOn : horizontalLineOff) + "\n"
        + " " + (bottom.isOn() ? verticalLineOn : verticalLineOff) + " \n";
}
