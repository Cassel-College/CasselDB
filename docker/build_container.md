# Build Container to build project.

## Images

```shell
docker pull xanonymous/gtest-cpp-essential-env
```

## Create container

```shell
docker run -d --name cpp_building -v /home/Code/github/CasselDB:/home/Code/github/CasselDB danger89/cmake:latest;
```

## run code in comtainer

```shell
docker exec -it 1c5b9f6c0dee /bin/bash 
```

#### build

```shell
cd /home/Code/github/CasselDB/build && sh build.sh
```
