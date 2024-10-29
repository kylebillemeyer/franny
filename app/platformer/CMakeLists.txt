add_executable(platformer platformer.cpp)
target_link_libraries(platformer PRIVATE frannylib)
set_target_properties(platformer PROPERTIES CXX_STANDARD 17)
