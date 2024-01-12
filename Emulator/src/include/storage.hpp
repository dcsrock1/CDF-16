#pragma once
#include <cstdint>
#include <array>
class Storage {
public:
    uint8_t getByte(uint16_t address, bool bankSelector, uint64_t& cycles);
    uint16_t getWord(uint16_t address, bool bankSelector, uint64_t& cycles);
    void reset();
private:
    std::array<uint8_t, 65536> storageB0, storageB1;
};