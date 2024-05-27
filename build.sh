#!/bin/bash

CURR_DIR=$(pwd)
BUILD_DIR=${CURR_DIR}/build

if [ ! -d "${BUILD_DIR}"]; then
    mkdir ${BUILD_DIR}
    cd ${BUILD_DIR}
    cmake ../
fi

cd ${BUILD_DIR}

make 