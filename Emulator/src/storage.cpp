#include "include/storage.hpp"


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
void Storage::reset() {
    
}

