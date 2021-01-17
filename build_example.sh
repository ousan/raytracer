#!/bin/bash

PROJECT_DIR=$(pwd)
LIB_SOURCE_DIR=$PROJECT_DIR/libRaytracer
BUILD_DIR=$LIB_SOURCE_DIR/build
LIB_POST_BUILD_DIR=$PROJECT_DIR/lib

if [[ -d "$BUILD_DIR" ]]
then
    echo "$BUILD_DIR exists on your filesystem."
else
    echo "$BUILD_DIR not exists on your filesystem."
    mkdir $BUILD_DIR
    mkdir $LIB_POST_BUILD_DIR
    cd $BUILD_DIR
    cmake ..
    make
    cp *.a $LIB_POST_BUILD_DIR
fi

cd $PROJECT_DIR
echo "$LIB_POST_BUILD_DIR"
g++ \
-std=c++17 \
example.cpp \
$LIB_POST_BUILD_DIR/libraytracer.a \
-o raytracer \
-IlibRaytracer/inc