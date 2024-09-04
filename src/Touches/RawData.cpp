//
// Created by Joel Neumann on 18.01.24.
//

#include "RawData.h"

int RawData::findIndexOfFirstZero() const {
    auto it = std::find(begin(), end(), 0);
    return it != end() ? std::distance(begin(), it) : -1;
}

unsigned int RawData::shiftToFirstZero() {
    int shift = findIndexOfFirstZero();
    if (shift > 0) {
        std::rotate(begin(), begin() + shift, end());
        return shift;
    }

    return 0;
}

RawTouchGroup RawData::getRawTouchGroups() {
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

TouchVector RawData::extractTouches(bool is_circular) {
    if (this->empty()) {
        return {};
    }

    unsigned int shifted = 0;
    if(is_circular){
        shifted = this->shiftToFirstZero();
    }
    RawTouchGroup groups = getRawTouchGroups();
    groups.splitByPeeks();
    return groups.createTouches(shifted, size(), is_circular);
}
