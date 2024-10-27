cmake_minimum_required(VERSION 3.14...3.22)

project(RasterizeTests LANGUAGES CXX)

# ---- Options ----

option(ENABLE_TEST_COVERAGE "Enable test coverage" OFF)

# ---- Create binary ----

file(GLOB_RECURSE sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} Rasterize)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

enable_testing()

# ---- code coverage ----

if(ENABLE_TEST_COVERAGE)
    target_compile_options(Rasterize PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
    target_link_options(Rasterize PUBLIC -fprofile-arcs -ftest-coverage)
endif()