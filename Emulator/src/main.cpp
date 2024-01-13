#include "include/gpu.hpp"
#include "include/logger.hpp"
#include "include/memory.hpp"
#include "include/storage.hpp"
#include "include/util.hpp"
#include "include/cpu.hpp"

int main(int argc, char* argv[]) {
    logInfo("Starting object initialisation");
    Memory memory;
    logDebug("Memory class initialised");
    Storage storage;
    logDebug("Storage class initialised");
    GPU gpu;
    logDebug("GPU class initialised");
    CPU cpu(memory, storage, gpu);
    logDebug("CPU class initialised");
    logInfo("All objects initialised");
}