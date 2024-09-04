//
// Created by Joel Neumann on 18.01.24.
//

#ifndef DREA_V2_RAW_TOUCH_GROUP_H
#define DREA_V2_RAW_TOUCH_GROUP_H

#include "RawTouch.h"
#include "Touch.h"
#include <vector>

class RawTouchGroup : public std::vector<RawTouch> {
public:
    void splitByPeeks();
    TouchVector createTouches(unsigned int shift_count, int max_channels, bool b);
};

#endif// DREA_V2_RAW_TOUCH_GROUP_H
