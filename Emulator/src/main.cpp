#include "include/logger.hpp"

int main(int argc, char* argv[]) {
    Log::debug("DEBUG");
    Log::info("INFO");
    Log::warning("WARNING");
    Log::error("ERROR");
}