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
#include "ItemManager.h"
#include "ResourceManager.h"
#include "Creep.h"

using namespace std;


Camera camera;
Player player(camera);
Cube cube(10.0f), cube2(10.0f), cube3(10.0f);
double currentFrame;
double deltaTime;
double lastFrame;
double delta = 50;

Creep creep;


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
    
    
    ResourceManager::GetInstance()->LoadTexture("item1", "Textures/item1.tga");
    
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_TEXTURE_2D);

    
    player.Init(window);
    camera.SetPosition(glm::vec3(0, 20, -80));
    cube.SetColor(glm::vec3(1.0f, 1.0f, 0.0f));
    cube2.SetColor(glm::vec3(0.0f, 0.0f, 1.0f));

    cube2.SetTexture(ResourceManager::GetInstance()->GetTexture("item1"));
    cube3.SetTexture(ResourceManager::GetInstance()->GetTexture("item1"));
    
    creep.InitWithFile("Data/CreepFirst.txt");
    
    return window;
}

void Projection(GLFWwindow *window) {
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    camera.SetViewport(0, 0, width, height);
    camera.Update();
}

void Update(float dt) {
    player.Update(dt);
    ProjectileManager::GetInstance()->Update(dt);
    ItemManager::GetInstance()->Update(dt);
    
    delta -= dt * 10;
}

void Draw() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    cube3.Draw();
    glBindTexture(GL_TEXTURE_2D, 0);
    
    creep.Draw();

    
    glPushMatrix();
    player.Draw();
    glPopMatrix();
    
    glPushMatrix();
    {
        glTranslatef(0, 1.0f, 0);
        glLineWidth(5.0f);
        glBegin(GL_LINES);
        // x-axis
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-100, 0, 0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(100, 0, 0);
        // y-axis
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0, -100, 0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0, 100, 0);
        // z-axis
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0, 0, -100);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0, 0, 100);
        glEnd();
    }
    glPopMatrix();
    
    
    glPushMatrix();
    {
        glScalef(10.0f, 10.0f, 10.0f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
    }
    glPopMatrix();
    
    glPushMatrix();
    {
        glLoadIdentity();
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1000.0f, 0.0f, -1000.0f);
        glVertex3f(1000.0f, 0.0f, -1000.0f);
        glVertex3f(1000.0f, 0.0f, 1000.0f);
        glVertex3f(-1000.0f, 0.0f, 1000.0f);
        glEnd();
    }
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(50, 0, delta);
    cube.Draw();
    glTranslatef(0, 0, 50);
    cube2.Draw();
    glPopMatrix();
    

    glBindTexture(GL_TEXTURE_2D, 0);
    ProjectileManager::GetInstance()->Draw();
    ItemManager::GetInstance()->Draw();
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
        
        Update(deltaTime);
        Projection(window);
        Draw();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}
