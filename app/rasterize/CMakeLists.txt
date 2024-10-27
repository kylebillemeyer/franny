add_executable(rasterize rasterize.cpp)
target_link_libraries(rasterize PRIVATE frannylib)
set_target_properties(rasterize PROPERTIES CXX_STANDARD 17)
