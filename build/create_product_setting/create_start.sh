#bin/bash

file_name="../../cassel/start.sh"

if [ -f "${file_name}" ]
then
    rm -rf "${file_name}"
fi
touch ${file_name}
echo "./bin/CasselDB" >> ${file_name}
