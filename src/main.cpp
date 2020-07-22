#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shaders.h"
#include <iostream>
#include <string>
#include <vector>

static unsigned int CompileShader(unsigned int type,
                                  const std::string& source);

static int CreateShader(const std::string& vertex_shader,
                        const std::string& fragment_shader);

int draw(const std::vector<float>& positions);

std::vector<float> positions{
    -0.5f, -0.5f,
    0.0f,  0.5f,
    0.5f, -0.5f
};

int main(){
    int result = draw(positions);
    return result;
}

int draw(const std::vector<float>& positions)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if(glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), 
                 positions.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 
                          sizeof(float) * 2, 0);

    unsigned int shader = CreateShader(shaders::vertex_shader, 
                                       shaders::fragment_shader);
    glUseProgram(shader);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

static unsigned int CompileShader(unsigned int type,
                                  const std::string& source){
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE){
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " <<
                    (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
                  << " shader!" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

static int CreateShader(const std::string& vertex_shader,
                        const std::string& fragment_shader){
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertex_shader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragment_shader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}
