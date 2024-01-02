#pragma once
#include <string>

#define LOG_FILE "emulator.log" //Compile time definition for the log file (likely to change)


void debug(std::string msg); //Debug logging function, prints the message to the console in blue.

void info(std::string msg); //Info logging function, prints the message to the console in green.

void warning(std::string msg); //Warning logging function, prints the message to the console in yellow.

void error(std::string msg); //Error logging function, prints the message to the console in red.