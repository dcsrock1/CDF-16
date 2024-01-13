#include "include/memory.hpp"
#include "include/logger.hpp"
#include "include/util.hpp"
#include <cstdint>
#include <fstream>
#include <cstddef>

constexpr size_t MAX_FILE_SIZE = 65536;

//Function to get byte from memory banks
int8_t Memory::getByte(uint16_t address, bool bankSelector, uint64_t& cycles) {
    //Increment cycles
    cycles++;
    //Determine the correct bank to retrieve the byte from, then return that byte
    if (bankSelector) {
        return memoryB1.at(address); //Return byte from bank 1
    } else {
        return memoryB0.at(address); //Return byte from bank 0
    }

}

//This function is used to retrieve a word from memory
int16_t Memory::getWord(uint16_t address, bool bankSelector, uint64_t& cycles) {
    //Increment cycles by 2 as 2 bytes must be grabbed from memory
    cycles += 2;
    //Check which bank has been selected for use
    if (bankSelector) {
        //Perform a bitwise calculation to flip the bytes to the correct format (Little Endian)
        int16_t mainByte = memoryB1.at(address + 1);
        int16_t secondaryByte = memoryB1.at(address);
        int16_t result = ((mainByte << 8) | secondaryByte); 
        return result;
    } else {
        int16_t mainByte = memoryB0.at(address + 1);
        int16_t secondaryByte = memoryB0.at(address);
        int16_t result = ((mainByte << 8) | secondaryByte);
        //Return result
        return result;
    }
}

//Function to set a single byte in either memory bank
void Memory::setByte(uint16_t address, int8_t data, bool bankSelector, uint64_t& cycles) {
    //Once again increment cycles count
    cycles++;
    //Check which bank has been selected
    if (bankSelector) {
        memoryB1[address] = data;
    } else {
        memoryB0[address] = data;
    }
}

//This set word function is used to, modify the memory in 16 bit sections, it formats the input data into the correct endianness
void Memory::setWord(uint16_t address, int16_t data, bool bankSelector, uint64_t& cycles) {
    cycles += 2;
    if (bankSelector) {
        memoryB1[address] = static_cast<uint8_t>(data >> 8);
        memoryB1[address + 1] = static_cast<uint8_t>(data);
    }
}

//This will load a ROM file into RAM for use by the processor
void Memory::loadROM(std::string filename, bool bankSelector) {
    std::ifstream file(filename, std::ios::binary);
    //Check if file is open
    if (!file.is_open()) {
        logError("Memory file cannot be opened as it has already been opened by another process");
        exit(1);
    }

    //Determine the file size
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    if (fileSize > MAX_FILE_SIZE) {
        logError("ROM file is larger then the internal memory");
        exit(1);
    }

    std::array<char, MAX_FILE_SIZE> bytes;

    //Read the file content into the array
    file.read(bytes.data(), fileSize);

    //Bad bit detection
    if (file.bad()) {
        logError("Bad bit has been located in ROM file, possibly corrupt file");
        exit(1);
    }
    file.close();
    //Copy contents of bytes array into the memory bank that has been selected
    if (bankSelector) {
        std::copy(std::begin(bytes), std::end(bytes), std::begin(memoryB1));
    } else {
        std::copy(std::begin(bytes), std::end(bytes), std::begin(memoryB0));
    }
    
}

void Memory::dumpMem(std::string filenameB0, std::string filenameB1) {
    std::ofstream fileBank0(filenameB0, std::ios::binary);
    std::ofstream fileBank1(filenameB1, std::ios::binary);
    //Check if file is open (Dump file for bank 0)
    if (!fileBank0.is_open()) {
        logError("Memory bank 0 dump file cannot be opened as it has already been opened by another process");
        exit(1);
    }
    //Check if file is open (Dump file for bank 1)
    if (!fileBank1.is_open()) {
        logError("Memory bank 1 dump file cannot be opened as it has already been opened by another process");
    }
}

//Nulls all bytes in both memory banks
void Memory::reset() {
    logInfo("Starting memory bank reset");
    logDebug("Nulling memory bank 0");
    memoryB0.fill(0);
    logDebug("Nulling memory bank 1");
    memoryB1.fill(0);
    logInfo("Memory bank reset complete");
}