#pragma once
#include <string>
#include <getopt.h>

struct ParsedArguments {
    std::string log = "emulator.log";
    std::string memory = "memory.rom";
    std::string storage = "storage.img";
    std::string flags = "00000000";
    std::string entry = "0";
    bool verbose = false;
    std::string executable;
};

ParsedArguments parseArguments(int argc, char* argv[]);