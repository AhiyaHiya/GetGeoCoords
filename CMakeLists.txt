cmake_minimum_required(VERSION 3.23)
project(GetGeoCoords VERSION 0.1.0 LANGUAGES C CXX)

# C17 and C++23
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 23)

# Folders for IDEs that support it
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
find_package(Boost REQUIRED COMPONENTS program_options)

# Target declaration
add_executable(GetGeoCoords
    "source/main.cpp"
    "source/ProgramOptions.cpp"
    "source/ProgramOptions.hpp"
)
target_link_libraries(GetGeoCoords
    PRIVATE
    Boost::program_options
)

# Unit test related
include(CTest)
enable_testing()