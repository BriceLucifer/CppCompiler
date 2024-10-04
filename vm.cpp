//
// Created by 23766 on 2024/10/4.
//

#include <iostream>
#include "vm.h"
#include "common.h"
#include "debug.h"

static InterpretResult run(VM& vm){
    auto READ_CONSTANT = [&vm](auto byte){
        return vm.chunk->constants.values[byte];
    };
    for (uint8_t byte : vm.ip) {
        disassembleInstruction(*vm.chunk,(int)(vm.ip[0] - vm.chunk->code[0]));
        switch (byte) {
            case static_cast<uint8_t>(Opcode::OP_CONSTANT): {
                Value constant = READ_CONSTANT(byte);
                printValue(constant);
                std::cout << "\n";
                break;
            }
            case static_cast<uint8_t>(Opcode::OP_RETURN):
                return InterpretResult::INTERPRET_OK;
            default:
                continue;
        }
    }
}

VM::VM() :chunk(nullptr), ip(std::vector<uint8_t>()){}
VM::~VM() = default ;
