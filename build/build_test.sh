#!/bin/bash

function build_unit_test() {
    echo "--------------------------------------------------------------------"
    path=$1
    echo "Unit Test dir: ${path}"
    build_dir="${path}/build"
    echo "Unit Test Building dir: ${build_dir}"
    echo "Check Unit Test Building dir is exits?"
    if [ ! -d ${build_dir} ]
    then
        echo "Not exits ${build_dir}, create it!"
        mkdir ${build_dir}
    else
        echo "Unit Test Building dir was exits! Clear it!"
        if [ "${build_dir}" != "" ]
        then
            rm -rf ${build_dir}/*
        fi
    fi
    echo "Use CMake building project..."
    if [ -f "${path}/CMakeLists.txt" ] && [ -d ${build_dir} ]
    then
        cmake -H${path} -B${build_dir}
        echo "Building over!"
    else
        if [ -f "${path}/CMakeLists.txt" ]
        then
            echo "No $CMakeLists.txt in ${path}."
        fi
        if [ -d ${build_dir} ]
        then
            echo "No build dir: ${path}."
        fi
    fi
    old_path=$(pwd)
    echo "Make project..."
    if [ -f ${build_dir}/Makefile ]
    then
        cd ${build_dir}&&make
        echo "over!"
        cd ${old_path}
    else
        echo "No Makefile in ${build_dir}."
    fi
    this_path=$(pwd)
    test_dir="${build_dir}/product/test"
    echo "Copy test file from ${test_dir} to ${this_path}/test"
    if [ ! -d test ]
    then
        echo "create dir named test"
        mkdir ./test
    fi
    if [ -d ${test_dir} ] && [ -d ${this_path}/test ]
    then
        cp -r ${test_dir}/* ${this_path}/test
    fi
    echo ${build_dir}
    if [ "${build_dir}" != "/" ]
    then
        echo "Delete Unit Test Building Dir!"
        rm -rf ${build_dir}
    fi
    echo "--------------------------------------------------------------------"
}

build_unit_test "../test/core/create/createFolder"
build_unit_test "../test/core/read/readFile"
build_unit_test "../test/core/select/selectFolder"
