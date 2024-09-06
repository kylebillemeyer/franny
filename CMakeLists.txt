cmake_minimum_required(VERSION 3.29)
project(franny VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

include_directories(external)

add_executable(franny src/main.cpp
        src/level/level.hpp
        src/engine/engine.hpp
        src/entity/Entity.hpp
        src/level/level.cpp
        src/entity/Platform.hpp
        src/entity/Platform.cpp
)
