#! /bin/bash

echo "Initializing submodules"
cd ..
git submodule init
git submodule update

echo "Create a build directory"
mkdir build
cd build

echo "Compiling the project"
cmake ..
cmake --build .

echo "Building complete"
./epg
