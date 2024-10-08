#include <iostream>
#include "common.h"
#include "chunk.h"
#include "debug.h"

int main() {
    Chunk chunk;
    int constant = chunk.addConstant(1.2);
    chunk.writeChunk(static_cast<uint8_t>(Opcode::OP_CONSTANT),123);
    chunk.writeChunk(constant,123);

    chunk.writeChunk(static_cast<uint8_t>(Opcode::OP_RETURN), 123);
    disassembleChunk(chunk, "test chunk");
    return 0;
}
