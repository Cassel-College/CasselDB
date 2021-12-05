#!/bin/bash

this_path=$(dirname $0)
echo "${this_path}"

function make_google_test() 
{
    test_path=$1
    if [ "${test_path}" == "" ]
    then
        echo "Is't need a path to making google test!"
    else
        echo "Begin making google test..."
        google_test_path=${this_path}/../${test_path}
        if [ -d "${google_test_path}" ]
        then
            if [ -d "${google_test_path}/build" ]
            then
                rm -rf ${google_test_path}/build
            fi
            if [ ! -d "${google_test_path}/build" ]
            then
                mkdir ${google_test_path}/build
                echo "google test path: ${google_test_path}"
                echo ">>> cmake -H${google_test_path} -B${google_test_path}/build"
                cmake -H${google_test_path} -B${google_test_path}/build
                if [ -f "${google_test_path}/build/Makefile" ]
                then
                    cd ${google_test_path}/build;make
                fi
                echo "Delete Building folder..."
                rm -rf ${google_test_path}/build
            else
                rm -rf ${google_test_path}/build
            fi
        else
            echo "No't exist path: ${google_test_path}."
        fi        
    fi
}

make_google_test "test/core/create/createFolder"