#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <shaders.h>
#include <iostream>
#include <string>
#include <vector>

int draw(const std::vector<float>& positions,
         const std::vector<unsigned int>& indices);

void ProcessInput(GLFWwindow* window);

std::vector<float> positions{
    -0.5f, -0.5f,
    0.5f,  -0.5f,
    0.0f,  0.5f,
    1.0f,  1.0f
};

std::vector<unsigned int> indices{
    0, 1, 2,
    2, 1, 3

};

int main(){
    int result = draw(positions, indices);
    return result;
}

int draw(const std::vector<float>& positions, 
         const std::vector<unsigned int>& indices)
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
    
    /* Initiate GLEW */
    glewExperimental = true;
    if(glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    unsigned int vao;
    glGenVertexArrays(1, &vao);

    unsigned int vbo;
    glGenBuffers(1, &vbo);

    unsigned int ebo;
    glGenBuffers(1, &ebo);

    /* Generating shaders */
    unsigned int shader = shaders::CreateShader(shaders::vertex_shader, 
                                       shaders::fragment_shader);
    glUseProgram(shader);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        ProcessInput(window);

        /* Render here */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 1. bind vertex array object
        glBindVertexArray(vao);
        // 2. copy our vertices array in a buffer for OpenGL to use
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), 
                    positions.data(), GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
                    indices.data(), GL_STATIC_DRAW);
        // 3. then set our vertex attributes pointers
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 
                              sizeof(float) * 2, 0);
        glEnableVertexAttribArray(0);
        // 4. draw the object
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void ProcessInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}