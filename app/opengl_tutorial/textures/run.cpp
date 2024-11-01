// Based on: https://github.com/JoeyDeVries/LearnOpenGL/blob/master/includes/learnopengl/shader_s.h

#include <iostream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <franny/utility/key.h>

#include "franny/geo/matrix.h"
#include "franny/render/shader.h"
#include "franny/render/texture.h"

using namespace std;
using namespace franny::geo;
using namespace franny::render;
using namespace franny::utility;

float mixAmt = .2;

void framebuffer_size_callback(GLFWwindow *window, const int width, const int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow * window, const KeyManager &keyManager) {
    if (keyManager.isKeyDown(GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(window, true);
    if (keyManager.wasKeyPressed(GLFW_KEY_UP)) {
        mixAmt += .05f;
    }
    if (keyManager.wasKeyPressed(GLFW_KEY_DOWN)) {
        mixAmt -= .05f;
    }
}

GLFWwindow *initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        cout << "Failed to initialize GLAD" << endl;
        glfwTerminate();
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    return window;
}

int main() {
    GLFWwindow *window = initWindow();

    glViewport(0, 0, 800, 600);

    KeyManager keyManager = KeyManager(window, set<int> { GLFW_KEY_ESCAPE, GLFW_KEY_UP, GLFW_KEY_DOWN });

    // Initialize shaders
    Shader shader = Shader("shader.vs", "shader.fs");

    // Set up vertices
    float vertices[] = {
         // positions       // colors         // texture coords
         0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.01f, // top right
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // top left
    };
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    // Initialize buffers
    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    const size_t stride = 8 * sizeof(float);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, static_cast<void *>(nullptr));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, reinterpret_cast<void *>(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, reinterpret_cast<void *>(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    Texture texture0 = Texture("container.jpg", GL_RGB, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Texture texture1 = Texture("awesomeface.png", GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

    // Initialize loop
    while (!glfwWindowShouldClose(window)) {
        // Input
        keyManager.process();

        processInput(window, keyManager);

        // Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        texture0.use();
        glActiveTexture(GL_TEXTURE1);
        texture1.use();

        shader.use();
        shader.setInt("texture1", 0);
        shader.setInt("texture2", 1);
        shader.setFloat("mixAmt", mixAmt);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shader.ID);

    glfwTerminate();
    return 0;
}
