add_executable(shaders run.cpp)
target_link_libraries(shaders PRIVATE frannylib)
set_target_properties(shaders PROPERTIES CXX_STANDARD 17)
