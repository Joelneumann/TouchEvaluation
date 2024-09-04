//
// Created by Joel Neumann on 18.01.24.
//

#ifndef DREA_V2_TOUCH_DATA_H
#define DREA_V2_TOUCH_DATA_H

#include "RawTouchGroup.h"
#include "Touch.h"
#include <algorithm>
#include <array>


class TouchData : public std::array<unsigned int, MAX_CHANNELS> {
protected:
    array<unsigned int, MAX_CHANNELS> empty_array = {};

    int findIndexOfFirstZero() const;
    unsigned int shiftToFirstZero();
    RawTouchGroup getRawTouchGroups();

public:
    TouchVector extractTouches();
};

#endif// DREA_V2_TOUCH_DATA_H
