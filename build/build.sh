
echo "begin making CasselDB..."

if [ -d "../cassel" ]
then
    echo "Dir cassel was exits..."
    rm -rf ../cassel/*
    echo "Delete files in cassel..."
else
    echo "Dir cassel was not exits..."
    mkdir ../cassel
    echo "Create cassel dir "
fi

if [ -d "../product" ]
then
    echo "Dir product was exits..."
    rm -rf ../product/*
    echo "Delete files in product..."
else
    echo "Dir product was not exits..."
    mkdir ../product
    echo "Create product dir "
fi



this_path=$(dirname $0)
echo "${this_path}"

cmake -H${this_path}/.. -B${this_path}/../product

this_path=$(pwd)

cd ../product&&make

cd ${this_path}

this_path=$(dirname $0)
sh ${this_path}/./create_product_setting/create_start.sh
sh ${this_path}/./create_product_setting/create_configuration.sh

# sh ./clear_build.sh

tar -zcvf ./../CasselDB.tar.gz ./../cassel

