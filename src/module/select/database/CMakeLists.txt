cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/cassel/lib)
message("Setting lib file outout path:${PROJECT_SOURCE_DIR}/cassel/lib")

add_library(select_database SHARED ./select_database.cpp ./select_database.h)

target_link_libraries(select_database log_module level log_cache style4log io4log filter4log config4log date_time log select_folder cassel_config data_path)