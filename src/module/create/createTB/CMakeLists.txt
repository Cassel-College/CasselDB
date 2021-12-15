cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/cassel/lib)
message("Setting lib file outout path:${PROJECT_SOURCE_DIR}/cassel/lib")

add_library(create_table SHARED ./create_table.cpp ./create_table.h)

target_link_libraries(create_table install_path data_path create_file)