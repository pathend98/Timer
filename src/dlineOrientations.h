#pragma once

#include <map>
#include "dline.h"
#include "digit.h"

static std::map<DLinePosition, Orientation> dLineOrientations = 
{
    {DLinePosition::TOP, Orientation::HORIZONTAL},
    {DLinePosition::TOP_LEFT, Orientation::VERTICAL},
    {DLinePosition::TOP_RIGHT, Orientation::VERTICAL},
    {DLinePosition::MIDDLE, Orientation::HORIZONTAL},
    {DLinePosition::BOTTOM_LEFT, Orientation::VERTICAL},
    {DLinePosition::BOTTOM_RIGHT, Orientation::VERTICAL},
    {DLinePosition::BOTTOM, Orientation::VERTICAL}
};
