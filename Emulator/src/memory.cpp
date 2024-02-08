#include "include/memory.hpp"
#include "include/logger.hpp"
#include "include/util.hpp"
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <cstddef>

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
    if (bankSelector) {
        logInfo("Loading ROM from file into memory bank one...");
    } else {
        logInfo("Loading ROM from file into memory bank zero...");
    }
    std::ifstream file(filename, std::ios::binary);
    //Check if file is open
    logDebug("Running open check on selected ROM file...");
    if (!file.is_open()) {
        logError("ROM file cannot be opened as it has already been opened by another process");
        exit(1);
    } else {
        logDebug("Open check has on ROM file has been completed");
    }
    
    //Determine the file size
    logDebug("Determining the ROM file size...");
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    logDebug("ROM file size determined");
    logDebug("Running size check on selected ROM file...");
    if (fileSize == MAX_FILE_SIZE) {
        logError("ROM file is larger then the internal memory");
        exit(1);
    } else {
        logDebug("Size check on ROM file has been completed");
    }

    std::array<char, MAX_FILE_SIZE> bytes;

    //Read the file content into the array
    logDebug("Reading file content into the array...");
    file.read(bytes.data(), fileSize);
    logDebug("File has been read into array");

    //Bad bit/corruption detection
    logDebug("Running corruption check on ROM file");
    if (file.bad()) {
        logError("Bad bit has been located in ROM file, possibly corrupt file");
        exit(1);
    } else {
        logDebug("Corruption check on ROM file has been completed");
    }
    file.close();
    //Copy contents of bytes array into the memory bank that has been selected
    if (bankSelector) {
        std::copy(std::begin(bytes), std::end(bytes), std::begin(memoryB1));
    } else {
        std::copy(std::begin(bytes), std::end(bytes), std::begin(memoryB0));
    }
    if (bankSelector) {
        logInfo("ROM file loaded into memory bank one");
    } else {
        logInfo("ROM file loaded into memory bank zero");
    }
}

//Function to dump a selected memory bank to a IMG file
void Memory::dumpMem(std::string dumpFile, bool bankSelector) {
    if (bankSelector) {
        logInfo("Creating memory dump file from bank 1...");
    } else {
        logInfo("Creating memory dump file from bank 0...");
    }
    std::ofstream file(dumpFile, std::ios::binary);
    //Check if file is open
    if (!file.is_open()) {
        logError("Memory dump file cannot be opened as it has already been opened by another process");
        exit(1);
    }
    if (bankSelector) {
        logInfo("Writing data to a dump file from memory bank one");
        file.write(reinterpret_cast<const char*>(memoryB1.data()), memoryB1.size());
        logInfo("Dump file for memory bank one has been written");
    } else {
        logInfo("Writing data to a dump file from memory bank zero");
        file.write(reinterpret_cast<const char*>(memoryB0.data()), memoryB0.size());
        logInfo("Dump file for memory bank two has been written");
    }
    file.close();
    if (bankSelector) {
        logInfo("Memory dump file of bank 1 has been created");
    } else {
        logInfo("Memory dump file of bank 0 has been created");
    }
}

//Nulls all bytes in both memory banks
void Memory::reset() {
    logInfo("Starting memory bank reset...");
    logDebug("Nulling memory bank 0...");
    memoryB0.fill(0); //Clear bank 0
    logDebug("Nulling memory bank 1...");
    memoryB1.fill(0); //Clearing bank 1
    logInfo("Memory bank reset complete");
}