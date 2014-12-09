//
//  Player.h
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#ifndef __AdvancedCGTermProject__Player__
#define __AdvancedCGTermProject__Player__

#include <GLFW/glfw3.h>
#include "Camera.h"
#include <glm/glm.hpp>

class Player {
private:
    GLFWwindow *_window;
    Camera &_camera;
    glm::vec3 _position;
    
    
public:
    Player(Camera &camera);
    ~Player();
    
    void Init(GLFWwindow *window);
    void Update();
    void KeyEvent(int key, int scancode, int action, int mods);
    
    
};

#endif /* defined(__AdvancedCGTermProject__Player__) */
