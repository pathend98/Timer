#pragma once

#include <vector>
#include <unordered_map>

#include "digit.h"

/**
 * Shows for each digit, whether each D-Line is on or off.
 * 
*/
static const std::vector<std::unordered_map<DLinePosition, bool>> digitDLineConfigurations = 
{
    // 0
    {
        {DLinePosition::TOP, true},
        {DLinePosition::TOP_LEFT, true}, {DLinePosition::TOP_RIGHT, true},
        {DLinePosition::MIDDLE, false},
        {DLinePosition::BOTTOM_LEFT, true}, {DLinePosition::BOTTOM_RIGHT, true},
        {DLinePosition::BOTTOM, true}
    },
    // 1
    {
        {DLinePosition::TOP, false},
        {DLinePosition::TOP_LEFT, false}, {DLinePosition::TOP_RIGHT, true},
        {DLinePosition::MIDDLE, false},
        {DLinePosition::BOTTOM_LEFT, false}, {DLinePosition::BOTTOM_RIGHT, true},
        {DLinePosition::BOTTOM, false}
    },
    // 2
    {
        {DLinePosition::TOP, true},
        {DLinePosition::TOP_LEFT, false}, {DLinePosition::TOP_RIGHT, true},
        {DLinePosition::MIDDLE, true}, {DLinePosition::BOTTOM_LEFT, true},
        {DLinePosition::BOTTOM_RIGHT, false},
        {DLinePosition::BOTTOM, true}
    },
    // 3
    {
        {DLinePosition::TOP, true},
        {DLinePosition::TOP_LEFT, false}, {DLinePosition::TOP_RIGHT, true}, 
        {DLinePosition::MIDDLE, true}, 
        {DLinePosition::BOTTOM_LEFT, false}, {DLinePosition::BOTTOM_RIGHT, true},
        {DLinePosition::BOTTOM, true}
    },
    // 4
    {
        {DLinePosition::TOP, false},
        {DLinePosition::TOP_LEFT, true}, {DLinePosition::TOP_RIGHT, true},
        {DLinePosition::MIDDLE, true},
        {DLinePosition::BOTTOM_LEFT, false}, {DLinePosition::BOTTOM_RIGHT, true},
        {DLinePosition::BOTTOM, false}
    },
    // 5
    {
        {DLinePosition::TOP, true},
        {DLinePosition::TOP_LEFT, true}, {DLinePosition::TOP_RIGHT, false},
        {DLinePosition::MIDDLE, true},
        {DLinePosition::BOTTOM_LEFT, false}, {DLinePosition::BOTTOM_RIGHT, true},
        {DLinePosition::BOTTOM, true}
    },
    // 6
    {
        {DLinePosition::TOP, true}, 
        {DLinePosition::TOP_LEFT, true}, {DLinePosition::TOP_RIGHT, false}, 
        {DLinePosition::MIDDLE, true},
        {DLinePosition::BOTTOM_LEFT, true}, {DLinePosition::BOTTOM_RIGHT, true},
        {DLinePosition::BOTTOM, true}
    },
    // 7
    {
        {DLinePosition::TOP, true},
        {DLinePosition::TOP_LEFT, false}, {DLinePosition::TOP_RIGHT, true},
        {DLinePosition::MIDDLE, false},
        {DLinePosition::BOTTOM_LEFT, false}, {DLinePosition::BOTTOM_RIGHT, true},
        {DLinePosition::BOTTOM, false}
    },
    // 8
    {
        {DLinePosition::TOP, true},
        {DLinePosition::TOP_LEFT, true}, {DLinePosition::TOP_RIGHT, true},
        {DLinePosition::MIDDLE, true},
        {DLinePosition::BOTTOM_LEFT, true}, {DLinePosition::BOTTOM_RIGHT, true},
        {DLinePosition::BOTTOM, true}
    },
    // 9
    {
        {DLinePosition::TOP, true},
        {DLinePosition::TOP_LEFT, true}, {DLinePosition::TOP_RIGHT, true},
        {DLinePosition::MIDDLE, true},
        {DLinePosition::BOTTOM_LEFT, false}, {DLinePosition::BOTTOM_RIGHT, true},
        {DLinePosition::BOTTOM, true}
    }
};
