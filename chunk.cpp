//
// Created by 23766 on 2024/10/4.
//

#include "chunk.h"

Chunk::Chunk() :
    count(0),
    code( std::vector<uint8_t>() ),
    constants( ValueArray() ),
    lines( std::vector<int>() ) { }
Chunk::~Chunk() = default;
void Chunk::writeChunk(uint8_t byte, int line) {
    code.push_back(byte);
    lines.push_back(line);
    count ++;
}
int Chunk::addConstant(Value value) {
    constants.writeValueArray(value);
    return constants.count - 1;
}