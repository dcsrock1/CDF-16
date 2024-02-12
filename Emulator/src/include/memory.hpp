#pragma once
#include <array>
#include <cstdint>
#include <string>

class Memory {
public:
    int8_t getByte(uint16_t address, bool bankSelector, uint64_t& cycles);
    int16_t getWord(uint16_t address, bool bankSelector, uint64_t& cycles);
    void setByte(uint16_t address, uint8_t data, bool bankSelector, uint64_t& cycles);
    void setWord(uint16_t address, uint16_t data, bool bankSelector, uint64_t& cycles);
    void loadROM(std::string romFile, bool bankSelector);
    void dumpMem(std::string dumpFile, bool bankSelector);
    void reset();
private:
    std::array<int8_t, 65536> memoryB0, memoryB1;
};  