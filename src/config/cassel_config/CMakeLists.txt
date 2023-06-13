cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/cassel/lib)
message("Setting lib file outout path:${PROJECT_SOURCE_DIR}/cassel/lib")

add_library(cassel_config SHARED ./cassel_config.cpp ./cassel_config.h)

target_link_libraries(cassel_config log log_module level)