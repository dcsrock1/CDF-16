#pragma once
#include <string>
#include <cstdint>
#include <vector>
#include <array>

constexpr size_t MAX_FILE_SIZE = 65536;

std::string getDateTime();
std::string bths(uint8_t num);
std::string wths(uint16_t num);
std::vector<std::string> splitStringV(const std::string& str, char delimiter);
std::array<std::string, 2> splitStringA(const std::string& str);