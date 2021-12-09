cmake_minimum_required (VERSION 3.16)

project(TestCreateFolder)

set(SRC_DIR ../../../../../src/core/create/createFolder/create_folder.cpp)

set(UNITTESTROOT ../../../../test)
set(project_target test_create_folder)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../../../cassel/test)
message(">>> Setting program path:${PROJECT_SOURCE_DIR}/../../../../cassel/test")

aux_source_directory(SRC_DIR SRC_CODE)

# message(${UNITTESTROOT})
# message(${SRC_DIR})
# message(${PROJECT_SOURCE_DIR})
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/product/test) # 指定可执行文件输出目录

link_directories(../../../../lib/googletest/lib)
include_directories(../../../../lib/googletest/include)

add_executable(${project_target} test_create_folder.h test_create_folder.cpp ${SRC_DIR})

target_link_libraries(${project_target} gtest gtest_main gmock gmock_main)

target_link_libraries(${project_target} pthread)