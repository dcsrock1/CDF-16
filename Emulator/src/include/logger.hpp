#pragma once
#include <string>
#define LOG_FILE "emulator.log"


void debug(std::string msg);
void info(std::string msg);
void warning(std::string msg);
void error(std::string msg);