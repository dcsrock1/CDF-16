#include "include/gpu.hpp"
#include "include/logger.hpp"
#include "include/memory.hpp"
#include "include/storage.hpp"
#include "include/cpu.hpp"
#include "include/util.hpp"
#include <cstdint>

//Main program entry point
int main(int argc, char* argv[]) {
    logInfo("Starting component initialisation");
    Memory memory;
    memory.loadROM("main1.rom", 0);
    logDebug("Memory component initialised");
    Storage storage;
    storage.loadImage("main1.img", 0);
    logDebug("Storage component initialised");
    GPU gpu;
    logDebug("GPU component initialised");
    CPU cpu(memory, storage, gpu);
    logDebug("CPU component initialised");
    logInfo("All components initialised");
}