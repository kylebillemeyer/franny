cmake_minimum_required(VERSION 3.29)
project(franny VERSION 1.0)

#if(NOT EMSCRIPTEN)
#    message(FATAL_ERROR "This example must be compiled with emscripten")
#endif()

set(target "franny")
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s ASSERTIONS=1 -s WASM=1 -s SAFE_HEAP=1")

include_directories(external)
find_package(SDL2 REQUIRED COMPONENTS SDL2)

add_executable(${target} src/main.cpp
        src/entity/Level.hpp
        src/engine/engine.hpp
        src/entity/Entity.hpp
        src/entity/Level.cpp
        src/entity/Platform.hpp
        src/entity/Platform.cpp
        src/engine/Engine.cpp
        src/utility/entity.hpp
        src/utility/string.hpp
)

target_link_libraries(${target} PRIVATE SDL2::SDL2)
#set_target_properties(${target} PROPERTIES OUTPUT_NAME "main")
#set_target_properties(${target} PROPERTIES SUFFIX ".html")
#target_compile_options(${target} PUBLIC "--use-port=sdl2")
#target_link_options(${target} PUBLIC "--use-port=sdl2")
