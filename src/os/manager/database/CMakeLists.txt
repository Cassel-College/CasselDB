cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/cassel/lib)
message("Setting lib file outout path:${PROJECT_SOURCE_DIR}/cassel/lib")

add_library(op_database SHARED ./op_database.cpp ./op_database.h)

target_link_libraries(op_database log_module level log_cache style4log io4log filter4log config4log date_time log select_table base_operation create_table simple_ui cassel_config)