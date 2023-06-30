cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/cassel/lib)
message("Setting lib file outout path:${PROJECT_SOURCE_DIR}/cassel/lib")

add_library(op_config SHARED ./op_config.cpp ./op_config.h)

target_link_libraries(op_config log_module level log_cache style4log io4log filter4log config4log date_time log base_operation)

