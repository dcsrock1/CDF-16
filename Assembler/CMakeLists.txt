cmake_minimum_required(VERSION 3.25) #Sets cmake version to 3.25
project(CDF-16) #Declares the project name as CDF-16

set(INCLUDE_DIR src/include) #Sets include directory as src/include
set(SRC_DIR src) #Sets source directory as src 

file(GLOB HEADER_FILES ${INCLUDE_DIR}/*.hpp) #Initialises the header files 

file(GLOB SOURCE_FILES ${SRC_DIR}/*.cpp) #Initialises the source files

add_executable(CDF-16-ASM ${SOURCE_FILES} ${HEADER_FILES}) #Sets the executable target

target_include_directories(CDF-16-ASM PRIVATE ${INCLUDE_DIR}) #Includes files from include directory
