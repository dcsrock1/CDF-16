#include "include/util.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <cstdint>
#include <cstddef>

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
    return "0x00";
  } else {
    //Create a string stream for the converted family
    std::stringstream stream;
    stream << "0x" << hex(num >> 8) << hex(num & 0xFF);
    return stream.str();
  }
}