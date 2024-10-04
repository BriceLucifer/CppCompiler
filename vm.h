//
// Created by 23766 on 2024/10/4.
//

#ifndef CPPCOMPILER_VM_H
#define CPPCOMPILER_VM_H

#include <memory>
#include "chunk.h"

class VM {
public:
    Chunk* chunk;
    std::vector<uint8_t> ip;
    VM();
    ~VM();
};

enum class InterpretResult{
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
};


#endif //CPPCOMPILER_VM_H
