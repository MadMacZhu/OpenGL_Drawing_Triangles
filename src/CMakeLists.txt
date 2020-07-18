find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW 2.0 REQUIRED)

add_executable(bin_main main.cpp)

target_link_libraries(bin_main 
                      OpenGL::GL glfw GLEW)
