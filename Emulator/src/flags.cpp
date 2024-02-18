#include "include/flags.hpp"

void Flags::defualt() {
    halt = 0;
    reset = 0;
    memoryBankSelector = 0;
    storageBankSelector = 0;
    keyboardEnable = 0;
    screenEnable = 0;
    interruptEnable = 0;
    interruptTriggered = 0;        
}