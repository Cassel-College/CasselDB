
this_path=$(dirname $0)

test_dir=${this_path}/../../cassel/test

echo "Test Folder: ${test_dir}"
if [ -d "${test_dir}" ]
then
    test_files=$(ls ${test_dir})
    for test_file in ${test_files}
    do
        ./${test_dir}/${test_file}
    done
fi