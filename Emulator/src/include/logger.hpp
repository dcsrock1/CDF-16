#pragma once
#include <iostream> //Included for the string type
#include <fstream>
#include "util.hpp"
#define LOG_FILE "emulator.log"

class Log {
public:
    static void debug(std::string msg) {
        std::cout << "[\033[32mDEBUG\033[0m][" << getDateTime() << "]: " << msg << "\n";
        std::ofstream file;
        file.open(LOG_FILE, std::ios::app);
        file << "[DEBUG][" + getDateTime() + "]:" + msg + "\n";
        file.close();
    }
    static void info(std::string msg) {
        std::cout << "[\033[32mINFO\033[0m][" << getDateTime() << "]: " << msg << "\n";
        std::ofstream file;
        file.open(LOG_FILE, std::ios::app);
        file << "[INFO][" + getDateTime() + "]:" + msg + "\n";
        file.close();
    }

    static void warning(std::string msg) {
        std::cout << "[\033[33mWARNING\033[0m][" << getDateTime() << "]: " << msg << "\n";
        std::ofstream file;
        file.open(LOG_FILE, std::ios::app);
        file << "[WARNING][" + getDateTime() + "]: " + msg + "\n";
        file.close();
    }

    static void error(std::string msg) {
        std::cout << "[\033[31mWARNING\033[0m][" << getDateTime() << "]: " << msg << "\n";
        std::ofstream file;
        file.open(LOG_FILE, std::ios::app);
        file << "[ERROR][" + getDateTime() + "]: " + msg + "\n";
        file.close();
    }
};
