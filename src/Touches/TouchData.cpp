//
// Created by Joel Neumann on 18.01.24.
//

#include "TouchData.h"

int TouchData::findIndexOfFirstZero() const {
    for (int i = 0; i < size(); ++i) {
        if ((*this)[i] == 0) {
            return i;
        }
    }
    return -1;
}

unsigned int TouchData::shiftToFirstZero() {
    int shift = findIndexOfFirstZero();
    if (shift > 0) {
        std::rotate(begin(), begin() + shift, end());
        return shift;
    }
    // TODO: Error handling if (shift == -1)
    return 0;
}

RawTouchGroup TouchData::getRawTouchGroups() {
    RawTouchGroup groups;
    RawTouch current_group;

    for (unsigned int i = 0; i < size(); ++i) {
        if ((*this)[i] != 0) {
            current_group.push_back((*this)[i]);
        } else if (!current_group.empty()) {
            current_group.setStartIndex(i - current_group.size());
            groups.push_back(current_group);
            current_group.clear();
        }
    }

    if (!current_group.empty()) {
        current_group.setStartIndex((size()) - current_group.size());
        groups.push_back(current_group);
    }

    return groups;
}

TouchVector TouchData::extractTouches() {
    if (*this == empty_array) {
        return {};
    }

    unsigned int shifted = shiftToFirstZero();
    RawTouchGroup groups = getRawTouchGroups();
    groups.splitByPeeks();
    return groups.createTouches(shifted);
}
