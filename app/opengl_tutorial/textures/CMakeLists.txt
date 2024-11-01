add_executable(textures run.cpp)
target_link_libraries(textures PRIVATE frannylib)
set_target_properties(textures PROPERTIES CXX_STANDARD 17)
