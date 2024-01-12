#pragma once
#include <array>
#include <cstdint>
#include <string>

class Memory {
public:
    int8_t getByte(uint16_t address, bool bankSelector, uint64_t& cycles);
    int16_t getWord(uint16_t address, bool bankSelector, uint64_t& cycles);
    void setByte(uint16_t address, int8_t data, bool bankSelector, uint64_t& cycles);
    void setWord(uint16_t address, int16_t data, bool bankSelector, uint64_t& cycles);
    void loadROM(std::string filename);
    void reset();
private:
    std::array<int8_t, 65536> memoryB0, memoryB1;
};  