//
// Created by 23766 on 2024/10/4.
//

#ifndef CPPCOMPILER_VALUE_H
#define CPPCOMPILER_VALUE_H

#include "common.h"

using Value = double;
class ValueArray{
public:
    int count;
    std::vector<Value> values;
    ValueArray();
    ~ValueArray();
    void writeValueArray(Value value);
};

#endif //CPPCOMPILER_VALUE_H
