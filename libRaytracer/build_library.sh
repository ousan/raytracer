#!/bin/bash

LIB_SOURCE_DIR=$(pwd)
BUILD_DIR=$LIB_SOURCE_DIR/build
LIB_POST_BUILD_DIR=$LIB_SOURCE_DIR/lib

echo "DIRECTORIES"
echo $LIB_SOURCE_DIR
echo $BUILD_DIR
echo $LIB_POST_BUILD_DIR
if [[ -d "$BUILD_DIR" ]]
then
    echo "$BUILD_DIR exists on your filesystem."
    rm -rf $BUILD_DIR
fi

mkdir $BUILD_DIR
mkdir $LIB_POST_BUILD_DIR
cd $BUILD_DIR
cmake ..
make
cp *.a $LIB_POST_BUILD_DIR