#include "include/logger.hpp"
#include "include/memory.hpp"
#include "include/util.hpp"
#include <string>

int main(int argc, char* argv[]) {
    Memory memory;
    memory.loadROM("main.ROM");
    uint64_t cycles = 0;
    uint8_t n = memory.getByte(0xFFFC, 0, cycles);
    std::string a = bths(n);
    info(a);
    memory.setByte(0xFFFC, 0xFC, 0, cycles);
    info(bths(memory.getByte(0xFFFC, 0, cycles)));
}