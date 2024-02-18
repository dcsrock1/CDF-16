#pragma once
#include "memory.hpp"
#include "storage.hpp"
#include "gpu.hpp"
#include "flags.hpp"
#include <cstdint>

//CPU class for initialisation of other classes
//This class will also be used for the main execution loop
class CPU  {
public:
    //Taking arguments as to initialise other sub classes
    CPU(Memory memory, Storage storage, GPU gpu);
    uint8_t fetchByte(uint64_t& cycles);
    uint16_t fetchWord(uint64_t& cycles);
    void execute(uint64_t cyclesToExecute);
    void reset();
private:
    //Definition of class objects
    Memory memory;
    Storage storage;
    GPU gpu;
    Flags flags;
    //CPU registers defined here
    uint16_t PC;
    uint16_t SP;
    uint8_t SR;
    uint8_t A;
    uint8_t B;
    uint16_t C;
    uint16_t D;
};