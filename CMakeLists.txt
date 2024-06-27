cmake_minimum_required(VERSION 3.10)

project(PlutoDB VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/cli.cpp
)
