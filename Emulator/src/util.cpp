#include "include/util.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>


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