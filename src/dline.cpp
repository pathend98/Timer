#include "dline.h"
#include <iostream>

DLine::DLine(const Orientation o) : orientation(o), on(false)
{}

void DLine::turnOn()
{
    on = true;
}

void DLine::turnOff()
{
    on = false;
}

bool DLine::isOn() const
{
    return on;
}

Orientation DLine::getOrientation() const
{
    return orientation;
}
