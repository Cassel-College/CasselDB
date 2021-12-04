
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

cmake -H.. -B../product

cd ../product&&make