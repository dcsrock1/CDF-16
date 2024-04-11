#include "include/fileParser.hpp"
#include "include/translationMap.hpp"
#include "include/util.hpp"
#include "include/logger.hpp"
#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <array>

std::vector<uint8_t> translate(std::string file) {
    std::ifstream fileStream(file);
    std::string output;
    if (fileStream.is_open()) {
        fileStream >> output;
    }
    std::vector<std::string> lines;
    lines = splitStringV(output, '\n');
    std::vector<std::array<std::string, 2>> instructionsFormed;
    int i = 1;
    for (const std::string& line : lines) {
        std::array<std::string, 2> newLine = splitStringA(line);
        if ((newLine[0] == "ERROR:10") && (newLine[1] == "ERROR:10")) {
            logError("syntax error, line: " + std::to_string(i));
            exit(1);
        }
        instructionsFormed.push_back(newLine);
        bool valid = false;
        for (const std::array<std::string, 2>& instruction: instructionsFormed) {
            for (const auto& pair : tMap) {
                if (instruction[0] == pair.first) {
                    valid = true;
                    break;
                }
            }
        }
        if (!valid) {
            logError("syntax error, line: " + std::to_string(i));
            exit(1);
        }   
    }   

    std::vector<uint8_t> result;
    for (const std::array<std::string, 2> instruction : instructionsFormed) {
        
    }
    
} 