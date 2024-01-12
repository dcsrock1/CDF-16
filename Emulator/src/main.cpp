#include "include/gpu.hpp"
#include "include/logger.hpp"
#include "include/memory.hpp"
#include "include/storage.hpp"
#include "include/util.hpp"
#include "include/cpu.hpp"

int main(int argc, char* argv[]) {
    info("Starting object initialisation");
    Memory memory;
    debug("Memory class initialised");
    Storage storage;
    debug("Storage class initialised");
    GPU gpu;
    debug("GPU class initialised");
    CPU cpu(memory, storage, gpu);
    debug("CPU class initialised");
    info("All objects initialised");
}