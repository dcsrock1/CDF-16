#pragma once
#include <cstdint>
#include <array>
#include <fstream>
#include <string>

class Storage {
public:
    int8_t getByte(uint16_t address, bool bankSelector, uint64_t& cycles);
    int16_t getWord(uint16_t address, bool bankSelector, uint64_t& cycles);
    void setByte(uint16_t address, int8_t data, bool bankSelector, uint64_t& cycles);
    void setWord(uint16_t address, int16_t data, bool bankSelector, uint64_t& cycles);
    void erase();
    void loadImage(std::string imageFile, bool bankSelector);
private:
    std::array<uint8_t, 65536> storageB0, storageB1;
};