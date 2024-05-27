#!/bin/bash

CURR_DIR=$(pwd)
BUILD_DIR=${CURR_DIR}/build

if [ ! -d ${BUILD_DIR} ]; then
    echo "call \"build.sh\" first, to build project"
    exit 1
fi

cd ${BUILD_DIR}
./out
