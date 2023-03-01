cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/cassel/lib)
message("Setting lib file outout path:${PROJECT_SOURCE_DIR}/cassel/lib")

add_subdirectory(./status)
add_subdirectory(./config)
add_subdirectory(./default)
add_subdirectory(./database)
add_subdirectory(./table)

add_library(cassel_manager SHARED ./cassel_manager.h ./cassel_manager.cpp)

target_link_libraries(cassel_manager op_status op_default op_config op_database op_table)