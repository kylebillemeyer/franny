add_library(frannylib STATIC
        glad.c
        stb.cpp
        geo/matrix.cpp
        geo/point2.cpp
        geo/vec2.cpp
        geo/vec3.cpp
        geo/vec4.cpp
        engine/engine.cpp
        entity/level.cpp
        entity/platform.cpp
        render/shader.cpp
        render/texture.cpp
        utility/key.cpp
)
target_include_directories(frannylib PUBLIC ../include)
target_link_libraries(frannylib PUBLIC glfw OpenGL::GL)
set_target_properties(frannylib  PROPERTIES CXX_STANDARD 17)
