#include "lib_glad/glad.h"
#include "lib_glad/glad.c"
#include <GLFW/glfw3.h>
#include <iostream>


int g_windoiwsSizeX = 640;
int g_windoiwsSizeY = 480;

void glfwWindowsSizeCallback(GLFWwindow* pwindow, int widht, int height)
{
    int g_windoiwsSizeX = widht;
    int g_windoiwsSizeY = height;
    glViewport(0, 0, g_windoiwsSizeX, g_windoiwsSizeY);
}

void glfwKeyCallback(GLFWwindow* pwindow, int key, int scancode, int action, int mode)
{
    if ((key == GLFW_KEY_ESCAPE) && (action == GLFW_PRESS))
    {
        glfwSetWindowShouldClose(pwindow, GL_TRUE);
    }

}
int main(void)
{
    GLFWwindow* pwindow;

    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout <<"Error in initialize the glfw"<< std::endl;
        return -1;
    }


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    /* Create a windowed mode window and its OpenGL context */
    pwindow = glfwCreateWindow(g_windoiwsSizeX, g_windoiwsSizeY, "Lessons_OpenGL", nullptr, nullptr);
    if (!pwindow)
    {
        std::cout<<"Function glfwCreateWindow is failed"<< std::endl;
        glfwTerminate();
        return -1;
    }
    glfwSetWindowSizeCallback(pwindow, glfwWindowsSizeCallback);
    glfwSetKeyCallback(pwindow, glfwKeyCallback);
    /* Make the window's context current */
    glfwMakeContextCurrent(pwindow);

	if (!gladLoadGL())
	{
        std::cout << "Renderer: " << glGetString(GL_RENDERER)<<std::endl;
        std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
		return -1;
	}
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	glClearColor(0, 1, 0, 1);
    
	
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pwindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pwindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}