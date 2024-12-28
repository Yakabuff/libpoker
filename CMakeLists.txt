# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(poker VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output directory for build artifacts
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories for header files
include_directories(include)

# Find all source files in the src directory
file(GLOB SOURCES "src/*.cpp")

# Add the executable
# add_executable(libpoker ${SOURCES})

# Create shared library
add_library(poker SHARED ${SOURCES})

# Add Google Test
# Download and include GoogleTest using CMake's FetchContent module
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.12.1.zip
)

# Fetch the content and make GoogleTest available
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add test executable
file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(MyProjectTests ${TEST_SOURCES})

# Link Google Test and the main project library to the test executable
target_link_libraries(MyProjectTests PRIVATE gtest gtest_main)
target_link_libraries(MyProjectTests PRIVATE poker)

# Add Google Test's test discovery
include(GoogleTest)
gtest_discover_tests(MyProjectTests)