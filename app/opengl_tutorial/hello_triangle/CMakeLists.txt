add_executable(hello_triangle run.cpp)
target_link_libraries(hello_triangle PRIVATE frannylib)
set_target_properties(hello_triangle PROPERTIES CXX_STANDARD 17)
