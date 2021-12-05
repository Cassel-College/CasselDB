#!/binn/bash

this_path=$(dirname $0)
rm -rf ${this_path}/CMakeCache.txt
rm -rf ${this_path}/CMakeFiles
rm -rf ${this_path}/cmake_install.cmake
rm -rf ${this_path}/compile_commands.json
rm -rf ${this_path}/Makefile
rm -rf ${this_path}/running_google_test.sh
rm -rf ${this_path}/src
rm -rf ${this_path}/.cmake
rm -rf ${this_path}/../cassel
rm -rf ${this_path}/../product