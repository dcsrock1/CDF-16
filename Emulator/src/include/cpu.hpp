#pragma once
#include <cstdint>
#include "memory.hpp"
#include "storage.hpp"
#include "gpu.hpp"

class CPU  {
public:
    CPU(Memory memory, Storage storage, GPU gpu);
    uint8_t fetchByte(uint64_t& cycles);
    uint16_t fetchWord(uint64_t& cycles);
    void reset();
private:
    Memory memory;
    Storage storage;
    GPU gpu;
    uint16_t PC;
    uint16_t SP;
    uint8_t SR;
    uint8_t A;
    uint8_t B;
    uint16_t C;
    uint16_t D;
};