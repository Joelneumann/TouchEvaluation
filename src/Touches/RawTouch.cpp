//
// Created by Joel Neumann on 18.01.24.
//

#include "RawTouch.h"

RawTouch::RawTouch(unsigned int start_index) : start_index_(start_index) {}

Touch RawTouch::createTouch(unsigned int shift_count, int max_channels, bool is_circular) {
    uint8_t channels = size();
    int pressure = 0;
    unsigned int weighted_index_pressure = 0;

    for (int i = 0; i < size(); ++i) {
        weighted_index_pressure += i * (*this)[i];
        pressure += int((*this)[i]);
    }

    float position = float(weighted_index_pressure) / float(pressure);
    position += float(start_index_) + float(shift_count) + 0.5f;
    if (position >= float(max_channels)) position -= float(max_channels);

    if(is_circular){
        position = position * float(2 * M_PI) / float(max_channels);
    }

    return {position, channels, pressure};
}

std::vector<RawTouch> RawTouch::splitByPeek() {
    vector<RawTouch> group;
    RawTouch current_raw_touch;

    unsigned int new_start_index = start_index_;
    unsigned int peek = 0;
    int peek_index = -1;
    unsigned int last_value = 0;

    for (int i = 0; i < size(); ++i) {
        if (peek_index == -1 || (peek_index == i - 1 && (*this)[i] >= peek)) {// new peek
            peek = (*this)[i];
            peek_index = i;
            last_value = (*this)[i];
        } else if (peek_index < i - 1 && (*this)[i] > last_value) {// new low point
            current_raw_touch.start_index_ = new_start_index;
            group.push_back(current_raw_touch);
            new_start_index += current_raw_touch.size() - 1;
            current_raw_touch.clear();
            current_raw_touch.push_back(last_value);
            peek = 0;
            peek_index = -1;
            last_value = 0;
        } else {// not a peek or a low
            last_value = (*this)[i];
        }
        current_raw_touch.push_back((*this)[i]);
    }

    if (!current_raw_touch.empty()) {
        current_raw_touch.start_index_ = new_start_index;
        group.push_back(current_raw_touch);
    }

    return group;
}

void RawTouch::setStartIndex(unsigned int start_index) {
    start_index_ = start_index;
}