//
//  main.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include <GLFW/glfw3.h>
#include <GLUT/GLUT.h>
#include <stdlib.h>
#include <stdio.h>

#include "Camera.h"

using namespace std;


Camera camera;


static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void Projection(GLFWwindow *window) {
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    camera.SetViewport(0, 0, width, height);
}

void Update(GLFWwindow *window) {
    camera.Update();
    
    if( glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS ) {
        camera.Move(LEFT);
    }
    if( glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS ) {
        camera.Move(RIGHT);
    }
    if( glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS ) {
        camera.Move(FORWARD);
    }
    if( glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS ) {
        camera.Move(BACK);
    }
}

void Draw() {
    glMatrixMode(GL_MODELVIEW);
    
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
    
    glLoadIdentity();
    glBegin(GL_QUADS);
    {
        glVertex3f(-1000.0f, 0.0f, -1000.0f);
        glVertex3f(1000.0f, 0.0f, -1000.0f);
        glVertex3f(1000.0f, 0.0f, 1000.0f);
        glVertex3f(-1000.0f, 0.0f, 1000.0f);
    }
    glEnd();
}


int main(void)
{
    GLFWwindow *window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    
    camera.SetMode(FREE);
    camera.SetPosition(glm::vec3(0, 0, -10));
    camera.SetLookAt(glm::vec3(0, 0, 0));
    camera.SetClipping(.01, 500);
    camera.SetFOV(45);
    camera.SetMovingScale(0.01f);
    
    while (!glfwWindowShouldClose(window))
    {
        Projection(window);
        
        Update(window);
        Draw();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
