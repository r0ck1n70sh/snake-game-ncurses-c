#!/bin/bash

CURR_DIR=$(pwd)
BUILD_DIR=${CURR_DIR}/build


if [ ! -d "$BUILD_DIR" ]; then
    mkdir $BUILD_DIR
    cd $BUILD_DIR
    cmake ../
fi

echo BUILD_DIR $BUILD_DIR
cd $BUILD_DIR
make