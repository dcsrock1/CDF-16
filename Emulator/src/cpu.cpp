#include "include/cpu.hpp"
#include "include/gpu.hpp"
#include "include/memory.hpp"
#include "include/storage.hpp"
#include <cstdint>

CPU::CPU(Memory memory, Storage storage, GPU gpu) : memory(memory), storage(storage), gpu(gpu) {
    PC = 0;
    SP = 0;
    SR = 0;
    A = 0;
    B = 0;
    C = 0;
    D = 0;
    memory.reset();
    storage.reset();
    gpu.reset();
}

uint8_t CPU::fetchByte(uint64_t& cycles) {
    return memory.getByte(PC, 0, cycles);
}

uint16_t CPU::fetchWord(uint64_t& cycles) {
    return memory.getWord(PC, 0, cycles);
}

void CPU::reset() {
    PC = 0;
    SP = 0;
    SR = 0;
    A = 0;
    B = 0;
    C = 0;
    D = 0;
    memory.reset();
    storage.reset();
    gpu.reset();
}