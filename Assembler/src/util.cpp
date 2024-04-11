#include "include/util.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <cstdint>
#include <string>
#include <vector>
#include <array>
#include "include/logger.hpp"

//Function to retrieve the data and time in the format DD/MM/YYYY, hh:mm:ss.
std::string getDateTime() {
    // Get the current time using ctime.
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);
    
    // Format the date and time using a string stream.
    std::ostringstream formattedDateTime;
    formattedDateTime << std::setfill('0') << std::setw(2) << localTime->tm_mday << "/"
                     << std::setw(2) << 1 + localTime->tm_mon << "/"
                     << 1900 + localTime->tm_year << ", "
                     << std::setw(2) << localTime->tm_hour << ":"
                     << std::setw(2) << localTime->tm_min << ":"
                     << std::setw(2) << localTime->tm_sec;
    
    //Return the formatted Date and Time.
    return formattedDateTime.str();
}

struct HexCharStruct
{
  unsigned char c;
  HexCharStruct(unsigned char _c) : c(_c) { }
};

inline std::ostream& operator<<(std::ostream& o, const HexCharStruct& hs)
{
  return (o << std::hex << (int)hs.c);
}

inline HexCharStruct hex(unsigned char _c)
{
  return HexCharStruct(_c);
}
//Convert a unsigned 8 bit integer to a string format 0x<hex value>
std::string bths(uint8_t num) {
    if (!num) {
        return "0x00";
    } else {
        //Create a string stream for the converted family
        std::stringstream stream;
        stream << "0x" << hex(num);
        return stream.str();
    }      
}

//Convert a unsigned 16 bit integer to a string format 0x<hex value>
std::string wths(uint16_t num) {
  if (!num) {
    return "0x0000";
  } else {
    //Create a string stream for the converted family
    std::stringstream stream;
    stream << "0x" << hex(num >> 8) << hex(num & 0xFF);
    return stream.str();
  }
}


std::vector<std::string> splitStringV(const std::string& str, char delimiter) {
  std::vector<std::string> tokens;
  std::istringstream iss(str);
  std::string token;
  while (std::getline(iss, token, delimiter)) {
    if (!token.empty()) {
      tokens.push_back(token);
    }
  }
  return tokens;
}

std::array<std::string, 2> splitStringA(const std::string& str) {
  std::array<std::string, 2> tokens;
  std::istringstream iss(str);
  std::string token;
  uint8_t i = 0;
  while (std::getline(iss, token, ' ')) {
    if (i > 1) {
      logError("instruction split, array error");
      tokens[0] = tokens[1] = "ERROR:10";
      break;
    }
    if (!token.empty()) {
      tokens[i] = token;
      i++;
    }
  }
  return tokens;
}
