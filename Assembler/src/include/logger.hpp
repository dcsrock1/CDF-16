#pragma once
#include <string>

//#define LOG_FILE "assembler.log" //Compile time definition for the log file (likely to change)

static std::string logFile = "assembler.log";

void logDebug(std::string msg); //Debug logging function, prints the message to the console in blue.

void logInfo(std::string msg); //Info logging function, prints the message to the console in green.

void logWarning(std::string msg); //Warning logging function, prints the message to the console in yellow.

void logError(std::string msg); //Error logging function, prints the message to the console in red.