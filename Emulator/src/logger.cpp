#include "include/logger.hpp"
#include "include/util.hpp"
#include <iostream>
#include <fstream>

void debug(std::string msg) {
    std::cout << "[\033[34mDEBUG\033[0m][" << getDateTime() << "]: " << msg << "\n";
    std::ofstream file;
    file.open(LOG_FILE, std::ios::app);
    file << "[DEBUG][" + getDateTime() + "]:" + msg + "\n";
    file.close();
}

void info(std::string msg) {
    std::cout << "[\033[32mINFO\033[0m][" << getDateTime() << "]: " << msg << "\n";
    std::ofstream file;
    file.open(LOG_FILE, std::ios::app);
    file << "[INFO][" + getDateTime() + "]:" + msg + "\n";
    file.close();
}

void warning(std::string msg) {
    std::cout << "[\033[33mWARNING\033[0m][" << getDateTime() << "]: " << msg << "\n";
    std::ofstream file;
    file.open(LOG_FILE, std::ios::app);
    file << "[WARNING][" + getDateTime() + "]: " + msg + "\n";
    file.close();
}

void error(std::string msg) {
    std::cout << "[\033[31mWARNING\033[0m][" << getDateTime() << "]: " << msg << "\n";
    std::ofstream file;
    file.open(LOG_FILE, std::ios::app);
    file << "[ERROR][" + getDateTime() + "]: " + msg + "\n";
    file.close();
}