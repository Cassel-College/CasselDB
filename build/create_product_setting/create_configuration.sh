#bin/bash

this_path=`dirname $0`
echo "${this_path}"
if [ -d "${this_path}/../../cassel/config" ]
then
    echo "${this_path}/../../cassel/config was exist."
else
    echo "${this_path}/../../cassel/config was not exist. create it."
    mkdir -p ${this_path}/../../cassel/config
fi
file_name="${this_path}/../../cassel/config/configuration.conf"

if [ -f "${file_name}" ]
then
    rm -rf "${file_name}"
fi
touch ${file_name}
echo "# install path" >> ${file_name}
echo "install_path=/opt/CasselDB" >> ${file_name}
echo "# data path" >> ${file_name}
echo "data_path=/opt/CasselDB/data" >> ${file_name}