#include "include/cpu.hpp"
#include "include/gpu.hpp"
#include "include/memory.hpp"
#include "include/storage.hpp"
#include <cstdint>

CPU::CPU(Memory memory, Storage storage, GPU gpu) : memory(memory), storage(storage), gpu(gpu) {
    PC = 0;
    SP = 0;
    A = 0;
    B = 0;
    C = 0;
    D = 0;
    flags.default_flags();
    memory.reset();
    gpu.reset();
}

uint8_t CPU::fetchByte(uint64_t& cycles) {
    return memory.getByte(PC, 0, cycles);
}

uint16_t CPU::fetchWord(uint64_t& cycles) {
    return memory.getWord(PC, 0, cycles);
}

void CPU::setFlags(uint8_t value, uint64_t& cycles) {
    
}

void CPU::setA(uint8_t value, uint64_t& cycles) {
    cycles++;
    A = value;
}

void CPU::setB(uint8_t value, uint64_t& cycles) {
    cycles++;
    B = value;
}

void CPU::setC(uint16_t value, uint64_t& cycles) {
    cycles += 2;
    C = value;
}

void CPU::setD(uint16_t value, uint64_t& cycles) {
    cycles += 2;
    D = value;
}

uint8_t CPU::getA(uint64_t& cycles) {
    cycles++;
    return A;
}

uint8_t CPU::getB(uint64_t& cycles) {
    cycles++;
    return B;
}

uint16_t CPU::getC(uint64_t& cycles) {
    cycles++;
    return C;
}

uint16_t CPU::getD(uint64_t& cycles) {
    cycles++;
    return D;
}

void CPU::execute(uint64_t cyclesToExecute) {
    uint64_t cycles = 0;
    while(cyclesToExecute >= cycles) {
        uint8_t ins = fetchByte(cycles);
        switch (ins) {
        case 0x00:
            break;
        case 0x01:
            break;
        case 0x02:
            break;
        case 0x03:
            break;
        }
    }
}

void CPU::reset() {
    PC = 0;
    SP = 0;
    A = 0;
    B = 0;
    C = 0;
    D = 0;
    memory.reset();
    gpu.reset();
}