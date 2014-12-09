//
//  main.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include <GLFW/glfw3.h>
#include <GLUT/GLUT.h>
#include <iostream>

#include "Player.h"
#include "Camera.h"
#include "Cube.h"

using namespace std;


Camera camera;
Player player(camera);
Cube cube(1.0f);


static void error_callback(int error, const char* description)
{
    cerr << description;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    
    player.KeyEvent(key, scancode, action, mods);
}

GLFWwindow* Init() {
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        return NULL;
    }
    
    GLFWwindow *window = glfwCreateWindow(800, 600, "Simple example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return NULL;
    }
    
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    
    player.Init(window);
    
    return window;
}

void Projection(GLFWwindow *window) {
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    camera.SetViewport(0, 0, width, height);
}

void Update(GLFWwindow *window) {
    player.Update();
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
    
    cube.Draw();
}


int main(void)
{
    GLFWwindow *window = Init();
    if( ! window ) {
        cerr << "Failed to init" << endl;
        return 0;
    }
    
    while (!glfwWindowShouldClose(window)) {
        Projection(window);
        
        Update(window);
        Draw();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}
