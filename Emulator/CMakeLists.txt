cmake_minimum_required(VERSION 3.25)
project(CDF-16) 

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB HEADER_FILES ${INCLUDE_DIR}/*.hpp)

file(GLOB SOURCE_FILES ${SRC_DIR}/*.cpp)

add_executable(CDF-16-EMU ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(CDF-16-EMU PRIVATE ${INCLUDE_DIR})
