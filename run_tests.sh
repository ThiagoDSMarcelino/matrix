#!/bin/bash

# Clear the terminal
clear

# Run CMake to configure and build the project
cmake -S . -B build
cmake --build build

# Change to the build directory, run tests, and return to the original directory
cd build/ && ctest && cd ..
