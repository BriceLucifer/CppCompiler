//
// Created by 23766 on 2024/10/4.
//

#ifndef CPPCOMPILER_CHUNK_H
#define CPPCOMPILER_CHUNK_H

#include "common.h"
#include "value.h"

enum class Opcode {
    OP_CONSTANT,
    OP_RETURN ,
};

class Chunk {
public:
    Chunk();
    ~Chunk();
    void writeChunk(uint8_t byte, int line);
    int addConstant(Value value);
    int count;
    std::vector<uint8_t> code;
    std::vector<int> lines;
    ValueArray constants;
};

#endif //CPPCOMPILER_CHUNK_H
