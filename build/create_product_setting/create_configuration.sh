#bin/bash

this_path=`dirname $0`
echo "${this_path}"
file_name="${this_path}/../../cassel/configuration.config"

if [ -f "${file_name}" ]
then
    rm -rf "${file_name}"
fi
touch ${file_name}
echo "# install path" >> ${file_name}
echo "install_path=/opt/CasselDB" >> ${file_name}
echo "# data path" >> ${file_name}
echo "data_path=/opt/CasselDB/data" >> ${file_name}