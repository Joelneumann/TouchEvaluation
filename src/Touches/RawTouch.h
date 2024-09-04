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

    Touch createTouch(unsigned int shift_count);
    vector<RawTouch> splitByPeek();

    unsigned int getStartIndex() const;
    void setStartIndex(unsigned int start_index);

    //TODO
    static RawTouch buildRawTouch(unsigned int values[], int length, int start_index);
};

#endif // DREA_V2_RAW_TOUCH_H
