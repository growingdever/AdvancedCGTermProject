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
#include "ProjectileManager.h"

using namespace std;


Camera camera;
Player player(camera);
Cube cube(1.0f);
double currentFrame;
double deltaTime;
double lastFrame;


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
    
    GLFWwindow *window = glfwCreateWindow(800, 600, "Struggle Cube", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return NULL;
    }
    
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    
    
    player.Init(window);
    
    cube.SetColor(glm::vec3(1.0f, 1.0f, 0.0f));
    
    return window;
}

void Projection(GLFWwindow *window) {
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    camera.SetViewport(0, 0, width, height);
}

void Update(float dt) {
    player.Update(dt);
    ProjectileManager::GetInstance()->Update(dt);
}

void Draw() {
    glMatrixMode(GL_MODELVIEW);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glPushMatrix();
    glTranslatef(0, 0, -1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
    glPopMatrix();
    
    glLoadIdentity();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    {
        glVertex3f(-1000.0f, 0.0f, -1000.0f);
        glVertex3f(1000.0f, 0.0f, -1000.0f);
        glVertex3f(1000.0f, 0.0f, 1000.0f);
        glVertex3f(-1000.0f, 0.0f, 1000.0f);
    }
    glEnd();
    
    cube.Draw();
    
    glPushMatrix();
    ProjectileManager::GetInstance()->Draw();
    glPopMatrix();
    
    player.Draw();
}


int main(void)
{
    GLFWwindow *window = Init();
    if( ! window ) {
        cerr << "Failed to init" << endl;
        return 0;
    }
    
    while (!glfwWindowShouldClose(window)) {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        Projection(window);
        Update(deltaTime);
        Draw();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}
