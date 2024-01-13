#include "include/storage.hpp"
#include "include/logger.hpp"

//Function to pull a byte from a storage bank
int8_t Storage::getByte(uint16_t address, bool bankSelector, uint64_t& cycles) {
    //Increment cycles by one
    cycles++;
    if (bankSelector) {
        return storageB1.at(address); //Retrieve byte from bank 1
    } else {
        return storageB0.at(address); //Retrieve byte from bank 0
    }
}

//This function is to get word from a specific storage bank
int16_t Storage::getWord(uint16_t address, bool bankSelector, uint64_t& cycles) {
    //Increment cycles by two not one as it is fetching two bytes and formatting them
    cycles += 2;
    if (bankSelector) {
        int16_t mainByte = storageB1.at(address + 1);
        int16_t secondaryByte = storageB1.at(address);
        int16_t result = ((mainByte << 8) | secondaryByte); //Reverse byte order
        return result;
    } else {
        int16_t mainByte = storageB0.at(address + 1);
        int16_t secondaryByte = storageB0.at(address);
        int16_t result = ((mainByte << 8) | secondaryByte); //Reverse byte order
        return result;
    }
}

//Method to set a byte in the storage bank that has been selected
void Storage::setByte(uint16_t address, int8_t data, bool bankSelector, uint64_t& cycles) {
    cycles++; //Increment cycles
    if (bankSelector) {
        storageB1[address] = data; //Bank 1
    } else {
        storageB0[address] = data; //Bank 0
    }
}

//Operation to create a word in a storage bank of your choice
void Storage::setWord(uint16_t address, int16_t data, bool bankSelector, uint64_t& cycles) {
    cycles += 2; //Increment cycles by two, it takes two for two bytes being fetched
    if (bankSelector) {
        storageB1[address] = static_cast<uint8_t>(data >> 8);
        storageB1[address + 1] = static_cast<uint8_t>(data);
    } else {
        storageB0[address] = static_cast<uint8_t>(data >> 8);
        storageB0[address] = static_cast<uint8_t>(data);
    }
}

//Null all bytes in the storage banks
void Storage::erase() {
    logInfo("Starting storage bank erasure...");
    logDebug("Storage erasure of bank 0 starting...");
    storageB0.fill(0); //Clearing bank 0
    logDebug("Storage erasure of bank 1 starting...");
    storageB1.fill(0); //Clearing bank 1
    logInfo("Storage erasure completed");
}

