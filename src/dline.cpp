#include "dline.h"

DLine::DLine(Orientation o) : orientation(o), on(false) {}

void DLine::turnOn()
{
    on = true;
}

void DLine::turnOff()
{
    on = false;
}

bool DLine::isOn()
{
    return on;
}
