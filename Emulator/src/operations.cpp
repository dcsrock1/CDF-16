#include "include/operations.hpp"
#include "include/logger.hpp"



void Operations::LDAC_IM(CPU& cpu, uint64_t& cycles) {
    logInfo("Executing LDAC immediate instruction...");
    uint16_t operand = cpu.fetchWord(cycles);
    cpu.setAC(operand, cycles);
    logInfo("Executed LDAC immediate instruction");
}

void Operations::LDAC_ZP(CPU& cpu, uint64_t& cycles) {
    logInfo("Executing LDAC zero page instruction...");
    uint16_t operand = cpu.fetchWord(cycles);
    cpu.
}