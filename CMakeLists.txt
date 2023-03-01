cmake_minimum_required(VERSION 3.16)
project(casseldb)

set(CMAKE_CXX_STANDARD 20)

# set(DCMAKE_EXPORT_COMPILE_COMMANDS ON)

message("Create Casssel DB")

message("Setting Include head file dir:${PROJECT_SOURCE_DIR}/src")
include_directories(${PROJECT_SOURCE_DIR}/src)

aux_source_directory(${PROJECT_SOURCE_DIR}/src source_code)
message("Setting source code file dir:${source_code}")

link_directories(${PROJECT_SOURCE_DIR}/cassel/lib)
message("Setting lib path:${PROJECT_SOURCE_DIR}/cassel/lib")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/cassel/bin)
message("Setting program path:${PROJECT_SOURCE_DIR}/cassel/bin")

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
message("Setting sub project path:${PROJECT_SOURCE_DIR}/src")

message("Makeing CasselDB")
add_executable(CasselDB ${source_code})

target_link_libraries(CasselDB version log_module level log_cache style4log io4log filter4log config4log date_time log create_foler read_file select_info_from_list install_path create_database show_database cassel_manager op_default)
