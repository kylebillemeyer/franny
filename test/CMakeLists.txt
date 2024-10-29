option(ENABLE_TEST_COVERAGE "Enable test coverage" OFF)

add_executable(frannytest
        src/main.cpp
        src/geo/matrix.cpp
        src/geo/vec2.cpp
)
target_link_libraries(frannytest frannylib)
set_target_properties(frannytest PROPERTIES CXX_STANDARD 17)

enable_testing()

# ---- code coverage ----

if(ENABLE_TEST_COVERAGE)
    target_compile_options(frannytest PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
    target_link_options(frannytest PUBLIC -fprofile-arcs -ftest-coverage)
endif()