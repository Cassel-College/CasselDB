#!/bin/bash

google_test_source_code="../open_source/googletest"

google_test_lib="../lib/googletest"


echo "Check Google Test Source Code Folder..."
if [ -d ${google_test_source_code} ]
then 
    echo "Google Test Source Code Exits!"
    rm -rf ${google_test_source_code}
    echo "Delete It!"
else
    echo "Google Test Source Code Not Exits!"
fi

echo "Check Google Test lib..."
if [ -d ${google_test_lib} ]
then 
    echo "Google Test lib Exits!"
    rm -rf ${google_test_lib}
    echo "Delete It!"
else
    echo "Google Test Lib Not Exits!"
fi
