#include "include/argparse.hpp"
#include <bits/getopt_core.h>
#include <bits/getopt_ext.h>
#include <cstdlib>
#include <iostream>
#include <vector>

void helpMSG() {
    std::cout << "Usage\n    CDF-16-EMU [options] <executable file>\n\nOptions:\n    <executable file>    File given to the emulator for execution\n    -h, --help Displays this log message\n    -l, --log <Log file    Selects the file to log emulator output to (default: \"emulator.log\")\n    -m, --memory <ROM file>    Selects the ROM file to be loaded into emulator memory (default: \"memory.rom\")\n    -s, --storage <IMG file>    Selects IMG file to be loaded into emulator storage (default: \"disk.img\")\n    -f, --flags <flags preset>    Sets CPU flags using a 8 bit value e.g. 01001110 (refer to documentation for more info)\n    -e, --entry <memory entry address>    Sets the entry address for the emulator to begin executing from\n    -v, --verbose    Tells the program if it should print debug messages or not" << std::endl;
}

ParsedArguments parseArguments(int argc, char* argv[]) {
    ParsedArguments parsedArgs;
    bool debug = false;
    const char* const short_opts = "hl:m:s:f:e:vd";
    const option long_opts[] = {
        {"help", no_argument, nullptr, 'h'},
        {"log", required_argument, nullptr, 'l'},
        {"memory", required_argument, nullptr, 'm'},
        {"storage", required_argument, nullptr, 's'},
        {"flags", required_argument, nullptr, 'f'},
        {"entry", required_argument, nullptr, 'e'},
        {"verbose", no_argument, nullptr, 'v'},
        {"debug", no_argument, nullptr, 'd'},
        {nullptr, 0, nullptr, 0}
    };

    int opt;
    while ((opt = getopt_long(argc, argv, short_opts, long_opts, nullptr)) != -1) {
        switch (opt) {
            case 'h':
                helpMSG();
                exit(EXIT_SUCCESS);
            case 'l':
                parsedArgs.log = optarg;
                break;
            case 'm':
                parsedArgs.memory = optarg;
                break;
            case 's':
                parsedArgs.storage = optarg;
                break;
            case 'f':
                parsedArgs.flags = optarg;
                break;
            case 'e':
                parsedArgs.entry = optarg;
                break;
            case 'v':
                parsedArgs.verbose = true;
                break;
            case 'd':
                debug = true;
                break;
            case '?':
                std::cout << "Option provided was invalid" << std::endl;
                helpMSG();
                break;
        }
    }
    std::vector<std::string> posArgs;
    // Store remaining non-option arguments
    for (int i = optind; i < argc; ++i) {
        posArgs.emplace_back(argv[i]);
    }
    if (posArgs.size() < 1) {
        std::cout << "Error: Emulator requires at least 1 positional argument" << std::endl;
        helpMSG();
        exit(EXIT_FAILURE);
    }
    if (posArgs.size() >= 2) {
        std::cout << "Error: Too many positional arguments were given" << std::endl;
        helpMSG();
        exit(EXIT_FAILURE);
    } else {
        parsedArgs.executable = posArgs[0];
    }

    if (debug) { std::cout << "Log File: " << parsedArgs.log << "\nMemory ROM file: " << parsedArgs.memory << "\nStorage IMG file: " << parsedArgs.storage << "\nCPU Flags " << parsedArgs.flags << "\nMemory entry point: " << parsedArgs.entry << "\nVerbose: " << (parsedArgs.verbose ? "true" : "false") << std::endl; }

    return parsedArgs;
} 