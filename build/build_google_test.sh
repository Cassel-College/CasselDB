#!/bin/bash

shell_folder=$(dirname $(readlink -f "$0"))
project_path="${shell_folder}/.."
google_test_install_path="${shell_folder}/../lib/googletest"
echo "Set google test install path:${google_test_install_path}"

google_test_path_frame="${shell_folder}/../open_source"
echo "Set google test path frame: ${google_test_path_frame}"
if [ -d "${google_test_path_frame}/googletest" ]
then
    echo "Google Test Frame already exists in source！"
else 
    echo "No Google Test Frame!"
    echo "Begin download google test frame..."
    cd ${google_test_path_frame}
    git clone https://github.com/google/googletest.git
    echo "🐮🍺download google test frame over"

    echo $(pwd)
    echo "Building google test brin package..."
    cd googletest
    mkdir build 
    cd build
    cmake -DCMAKE_INSTALL_PREFIX=${google_test_install_path} ..
    make
    echo "🐮🍺Building google test brin package success."

    if [ ! -d "${project_path}/lib" ]
    then
        mkdir ${project_path}/lib
        mkdir ${project_path}/lib/googletest
    fi
    if [ ! -d "${project_path}/lib/googletest" ]
    then
        mkdir ${project_path}/lib
        mkdir ${project_path}/lib/googletest
    fi

    make install
    echo "🐮🍺Install google test success."
    
    # export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${project_path}/lib
    # export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/github/MyNotion/lib/

    echo "🚮Delete google test source code..."
    if [ "${google_test_path_frame}" != "" ]
    then
        echo "🚮"
        rm -rf ${google_test_path_frame}/googletest
    fi
    echo "🐮🍺Delete google test source code over!"
fi