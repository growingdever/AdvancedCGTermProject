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
#include <glm/glm.hpp>
#include "Camera.h"
#include "Node.h"
#include "Light.h"


class Player : public Node {
private:
    GLFWwindow *_window;
    Camera &_camera;
    
    Light _light;
    
    int _remainBullet;
    
    
public:
    Player(Camera &camera);
    ~Player();
    
    void Init(GLFWwindow *window);
    virtual void Update(float dt);
    virtual void Draw();
    void KeyEvent(int key, int scancode, int action, int mods);
    
    void Fire();
    void Looting();
    void IncreaseBullet(int count);
    
};

#endif /* defined(__AdvancedCGTermProject__Player__) */
