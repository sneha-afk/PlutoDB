cmake_minimum_required(VERSION 3.10)

project(PlutoDB VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
