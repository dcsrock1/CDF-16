#pragma once
#include <string>
#include <cstdint>

constexpr size_t MAX_FILE_SIZE = 65535;

std::string getDateTime();
std::string bths(uint8_t num);
std::string wths(uint16_t num);

