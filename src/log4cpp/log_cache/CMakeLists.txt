cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/cassel/lib)
message("Setting lib file outout path:${PROJECT_SOURCE_DIR}/cassel/lib")

add_library(log_cache SHARED ./log_cache.cpp ./log_cache.h)

target_link_libraries(log_cache log_module level filter4log log2file config4log)