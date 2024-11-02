cmake_minimum_required(VERSION 3.15...3.30)

# ---- Project ----

# Note: update this to your new project's name and version
project(
        Franny
        VERSION 1.0
        LANGUAGES CXX C
)

find_package(OpenGL REQUIRED)
#find_package(doctest REQUIRED)

add_subdirectory(lib/glfw-3.4)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(app/platformer)
add_subdirectory(app/rasterize)
add_subdirectory(app/opengl_tutorial/hello_triangle)
add_subdirectory(app/opengl_tutorial/shaders)
add_subdirectory(app/opengl_tutorial/textures)
add_subdirectory(app/opengl_tutorial/transformations)
