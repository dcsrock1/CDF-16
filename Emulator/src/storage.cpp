#include "include/storage.hpp"
#include "include/logger.hpp"
#include "include/util.hpp"
#include <string>

void Storage::loadImage(std::string imageFile, bool bankSelector) {
    std::fstream file(imageFile, std::ios::binary);
    //Check if file is open
    if (!file.is_open()) {
        logError("IMG file cannot be opened as it has already been opened by another process");
        exit(1);
    }

    //Determine the file size
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    if (fileSize > MAX_FILE_SIZE) {
        logError("IMG file is larger then the internal storage");
        exit(1);
    }

    std::array<char, MAX_FILE_SIZE> bytes;

    //Read the file content into the array
    file.read(bytes.data(), fileSize);

    //Bad bit detection
    if (file.bad()) {
        logError("Bad bit has been located in the IMG file, possibly corrupt file");
        exit(1);
    }
    file.close();
    //Copy contents of bytes array into the storage bank that has been selected
    if (bankSelector) {
        std::copy(std::begin(bytes), std::end(bytes), std::begin(storageB1));
    } else {
        std::copy(std::begin(bytes), std::end(bytes), std::begin(storageB0));
    }
}

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

