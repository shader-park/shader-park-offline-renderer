cmake_minimum_required(VERSION 3.0)

project(SP-OfflineRender)

set(CMAKE_CXX_COMPILER x86_64-conda_cos6-linux-gnu-g++)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 -O3")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -Wall -Wextra -Wpedantic -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable -std=c++11 -O3")
endif()

include_directories(external/glm/)

add_executable(render src/generated/full.cpp)
