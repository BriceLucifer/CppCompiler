//
// Created by 23766 on 2024/10/4.
//

#ifndef CPPCOMPILER_DEBUG_H
#define CPPCOMPILER_DEBUG_H

#include "chunk.h"

void disassembleChunk(Chunk& chunk, const char* name);
int disassembleInstruction(Chunk& chunk, int offset);
void printValue(Value value);

#endif //CPPCOMPILER_DEBUG_H
