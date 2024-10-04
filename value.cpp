//
// Created by 23766 on 2024/10/4.
//

#include "value.h"

ValueArray::ValueArray() : count(0), values( std::vector<Value>() ){}
ValueArray::~ValueArray() = default;
void ValueArray::writeValueArray(Value value) {
    values.push_back(value);
    count++ ;
}

