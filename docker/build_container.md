# Build Container to build project.

## Images

```shell
docker pull xanonymous/gtest-cpp-essential-env
```

## Create container

```shell
docker run -d --name CasselDB_building -v /home/Code/github/CasselDB:/home/Code/github/CasselDB xanonymous/gtest-cpp-essential-env:latest;
```

## run code in comtainer

```shell
docker exec -it 1c5b9f6c0dee /bin/bash 
```

#### build

```shell
cd /home/Code/github/CasselDB/build && sh build.sh
```

#### running

```shell
cd /home/Code/github/CasselDB/cassel && sh start.sh
```

## Generation CalssDB API doc

### pull docker doxygen image

```shell
docker pull luongnv89/doxygen
```

### build container

```shell
docker run --name Doxygen4CasselDB -v /home/Code/github/CasselDB:/home/Code/github/CasselDB luongnv89/doxygen;
```


### come in container

```shell
cd /home/Code/github/CasselDB
doxygen ./Doxyfile
```

## Show API doc by Nginx

### Download Nginx image

```shell
docker pull nginx
```

### Create Nginx container

```shell
docker run --name CasselDB_API_Doc -p 9095:80 -v /home/Code/github/CasselDB/html:/usr/share/nginx/html:ro -d nginx
```

