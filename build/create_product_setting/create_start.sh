#bin/bash

this_path=`dirname $0`
echo "${this_path}"
file_name="${this_path}/../../cassel/start.sh"

if [ -f "${file_name}" ]
then
    rm -rf "${file_name}"
fi
touch ${file_name}
echo "#!/bin/bash" >> ${file_name}
echo "this_path=\$(dirname \$0)" >> ${file_name}
echo "\${this_path}/bin/CasselDB" >> ${file_name}

