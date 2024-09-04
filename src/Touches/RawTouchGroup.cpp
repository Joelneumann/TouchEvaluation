//
// Created by Joel Neumann on 18.01.24.
//

#include "RawTouchGroup.h"

void RawTouchGroup::splitByPeeks() {
    RawTouchGroup new_groups{};

    for (RawTouch &raw_touch: *this) {
        std::vector<RawTouch> split = raw_touch.splitByPeek();
        new_groups.insert(new_groups.end(), split.begin(), split.end());
    }
    *this = new_groups;
}

TouchVector RawTouchGroup::createTouches(unsigned int shift_count, int max_channels, bool is_circular) {
    TouchVector touches{};
    for (RawTouch &raw_touch: *this) {
        touches.push_back(raw_touch.createTouch(shift_count, max_channels, is_circular));
    }
    return touches;
}
