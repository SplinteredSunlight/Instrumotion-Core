#!/bin/bash

set -e

# Create build directory
mkdir -p build
cd build

# Configure CMake
cmake ..

# Build the project
cmake --build .

# Run tests
ctest --output-on-failure

echo "Build and tests completed successfully."
