//
// Created by Joel Neumann on 18.01.24.
//

#ifndef DREA_V2_RAW_TOUCH_H
#define DREA_V2_RAW_TOUCH_H

#include <vector>
#include "Touch.h"

class RawTouch : public std::vector<unsigned int> {
private:
    unsigned int start_index_ = -1;

public:
    RawTouch() = default;
    explicit RawTouch(unsigned int start_index);

    Touch createTouch(unsigned int shift_count, int max_channels, bool b);
    vector<RawTouch> splitByPeek();

    void setStartIndex(unsigned int start_index);
};

#endif // DREA_V2_RAW_TOUCH_H
