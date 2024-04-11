#pragma once
#include <string>
#include <getopt.h>

struct ParsedArguments {
    bool verbose = false;
    std::string sourceFile;
    bool debug = false;
};

ParsedArguments parseArguments(int argc, char* argv[]);