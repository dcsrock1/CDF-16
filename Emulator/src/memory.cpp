#include "include/memory.hpp"
#include "include/logger.hpp"
#include <cstdint>
#include <fstream>
constexpr size_t MAX_FILE_SIZE = 65536;

int8_t Memory::getByte(uint16_t address, bool bankSelector, uint64_t& cycles) {
    cycles++;
    if (bankSelector) {
        return memoryB1.at(address);
    } else {
        return memoryB0.at(address);
    }

}
int16_t Memory::getWord(uint16_t address, bool bankSelector, uint64_t& cycles) {
    cycles += 2;
    if (bankSelector) {
        int16_t mainByte = memoryB1.at(address + 1);
        int16_t secondaryByte = memoryB1.at(address);
        int16_t result = ((mainByte << 8) | secondaryByte); 
        return result;
    } else {
        int16_t mainByte = memoryB0.at(address + 1);
        int16_t secondaryByte = memoryB0.at(address);
        int16_t result = ((mainByte << 8) | secondaryByte);
        return result;
    }
}
void Memory::setByte(uint16_t address, int8_t data, bool bankSelector, uint64_t& cycles) {
    cycles++;
    if (bankSelector) {
        memoryB1[address] = data;
    } else {
        memoryB0[address] = data;
    }
}
void Memory::setWord(uint16_t address, int16_t data, bool bankSelector, uint64_t& cycles) {
    cycles += 2;
    if (bankSelector) {
        memoryB1[address] = static_cast<uint8_t>(data >> 8);
        memoryB1[address + 1] = static_cast<uint8_t>(data);
    }
}

void Memory::loadROM(std::string filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        error("File cannot be opened as it has already been opened by another process");
        exit(1);
    }

    // Determine the file size
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    if (fileSize > MAX_FILE_SIZE) {
        error("ROM file is larger then the internal memory");
        exit(1);
    }

    std::array<char, MAX_FILE_SIZE> bytes;

    // Read the file content into the array
    file.read(bytes.data(), fileSize);

    if (file.bad()) {
        error("Bad bit has been located in ROM file, possibly corrupt file");
        exit(1);
    }

    file.close();
    for (int i = 0; i <= fileSize; i++) {
        memoryB0[i] = bytes[i];
    }
}
