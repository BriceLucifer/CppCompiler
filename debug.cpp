//
// Created by 23766 on 2024/10/4.
//
#include <iostream>
#include <iomanip>

#include "debug.h"

static int simpleInstruction(const char* name, int offset){
    std::cout << name << "\n" ;
    return offset + 1;
}

static int constantInstruction(const char* name, Chunk &chunk, int offset){
    uint8_t constant = chunk.code[offset + 1];
    printf_s("%-16s %4d '", name, constant);
    printValue(chunk.constants.values[constant]);
    std::cout << "'\n" ;
    return offset + 2 ;
}

void disassembleChunk(Chunk &chunk, const char *name){
    std::cout << "== " << name << " ==\n" ;
    for (int offset = 0; offset < chunk.count;){
        offset = disassembleInstruction(chunk,offset);
    }
}

int disassembleInstruction(Chunk &chunk, int offset){
    std::cout << std::setw(4) << std::setfill('0') << offset << " ";
    if (offset > 0 && chunk.lines[offset] == chunk.lines[offset -1 ]){
        std::cout << "   |  ";
    }else{
        std::cout << std::setw(4) << chunk.lines[offset] << "  ";
    }
    uint8_t instruction = chunk.code[offset];
    switch (instruction) {
        case static_cast<uint8_t>(Opcode::OP_CONSTANT):
            return constantInstruction("OP_CONSTANT",chunk, offset);
        case static_cast<uint8_t>(Opcode::OP_RETURN) :
            return simpleInstruction("OP_RETURN", offset);
        default:
            std::cout << "Unknown opcode " << instruction << "\n";
            return offset + 1;
    }
}

void printValue(Value value){
    std::cout << std::setprecision(6) << value ;
}
