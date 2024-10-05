//
// Created by 23766 on 2024/10/4.
//

#ifndef CPPCOMPILER_CHUNK_H
#define CPPCOMPILER_CHUNK_H

#include "common.h"
#include "value.h"

enum class Opcode {
    OP_CONSTANT,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_POP,
    OP_GET_LOCAL,
    OP_SET_LOCAL,
    OP_GET_GLOBAL,
    OP_DEFINE_GLOBAL,
    OP_SET_GLOBAL,
    OP_GET_UPVALUE,
    OP_SET_UPVALUE,
    OP_GET_PROPERTY,
    OP_SET_PROPERTY,
    OP_GET_SUPER,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NOT,
    OP_NEGATE,
    OP_PRINT,
    OP_JUMP,
    OP_JUMP_IF_FALSE,
    OP_LOOP,
    OP_CALL,
    OP_INVOKE,
    OP_SUPER_INVOKE,
    OP_CLOSURE,
    OP_CLOSE_UPVALUE,
    OP_RETURN,
    OP_CLASS,
    OP_INHERIT,
    OP_METHOD
};

class Chunk {
public:
    Chunk();
    ~Chunk();
    void writeChunk(uint8_t byte, int line);
    int addConstant(Value value);

    // member
    int count;
    std::vector<uint8_t> code;
    std::vector<int> lines;
    ValueArray constants;
    // 优化了capacity 不需要我们去管
};

#endif //CPPCOMPILER_CHUNK_H
