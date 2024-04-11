#include "include/argparse.hpp"
#include <bits/getopt_core.h>
#include <bits/getopt_ext.h>
#include <cstdlib>
#include <iostream>
#include <vector>

void helpMSG() {
    std::cout << "Usage\n    CDF-16-ASM [options] <executable file>\n\nOptions:\n    <assembly source file>    File given to the assembler to be converted to executable byte code\n    -h, --help Displays this help message\n    -l, --log <Log file    Selects the file to log assembler output to (default: \"assembler.log\")\n    -v, --verbose    Tells the program if it should print debug messages or not" << std::endl;
}

ParsedArguments parseArguments(int argc, char* argv[]) {
    ParsedArguments parsedArgs;
    const char* const short_opts = "hvd";
    const option long_opts[] = {
        {"help", no_argument, nullptr, 'h'},
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
            case 'v':
                parsedArgs.verbose = true;
                break;
            case 'd':
                parsedArgs.debug = true;
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
        std::cout << "Error: Assembler requires at least 1 positional argument" << std::endl;
        helpMSG();
        exit(EXIT_FAILURE);
    }
    if (posArgs.size() >= 2) {
        std::cout << "Error: Too many positional arguments were given" << std::endl;
        helpMSG();
        exit(EXIT_FAILURE);
    } else {
        parsedArgs.sourceFile = posArgs[0];
    }

    if (parsedArgs.debug) { std::cout << "\nVerbose: " << (parsedArgs.verbose ? "true" : "false") << std::endl; }

    return parsedArgs;
} 