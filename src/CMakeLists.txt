find_package(OpenGL REQUIRED)
add_library(GLEW glew.c)
add_library(shaders shaders.cpp)

add_executable(bin_main main.cpp)

target_link_libraries(bin_main 
                      OpenGL::GL libglfw.so.3 GLEW shaders)
