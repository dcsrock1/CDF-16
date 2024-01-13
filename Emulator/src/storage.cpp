#include "include/storage.hpp"
#include "include/util.hpp"

int8_t Storage::getByte(uint16_t address, bool bankSelector, uint64_t& cycles) {
    cycles++;
    if (bankSelector) {
        return storageB1.at(address);
    } else {
        return storageB0.at(address);
    }

}
int16_t Storage::getWord(uint16_t address, bool bankSelector, uint64_t& cycles) {
    cycles += 2;
    if (bankSelector) {
        int16_t mainByte = storageB1.at(address + 1);
        int16_t secondaryByte = storageB1.at(address);
        int16_t result = ((mainByte << 8) | secondaryByte); 
        return result;
    } else {
        int16_t mainByte = storageB0.at(address + 1);
        int16_t secondaryByte = storageB0.at(address);
        int16_t result = ((mainByte << 8) | secondaryByte);
        return result;
    }
}

void Storage::setByte(uint16_t address, int8_t data, bool bankSelector, uint64_t& cycles) {
    cycles++;
    if (bankSelector) {
        storageB1[address] = data;
    } else {
        storageB0[address] = data;
    }
}
void Storage::setWord(uint16_t address, int16_t data, bool bankSelector, uint64_t& cycles) {
    cycles += 2;
    if (bankSelector) {
        storageB1[address] = static_cast<uint8_t>(data >> 8);
        storageB1[address + 1] = static_cast<uint8_t>(data);
    }
}
void Storage::reset() {
    storageB0.fill(NULL);
    storageB1.fill(NULL);
}

