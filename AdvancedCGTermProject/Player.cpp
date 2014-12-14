//
//  Player.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "Player.h"
#include "ProjectileManager.h"
#include "ItemManager.h"
#include "Macro.h"

#include <iostream>
using namespace std;


Player::Player(Camera &camera)
: _camera(camera)
, _light(GL_LIGHT1)
{

}

Player::~Player()
{
    
}

void Player::Init(GLFWwindow *window)
{
    _window = window;
    
    _camera.SetMode(FREE);
    _camera.SetPosition(glm::vec3(0, 0, -10));
    _camera.SetLookAt(glm::vec3(0, 0, 0));
    _camera.SetClipping(.01, 500);
    _camera.SetFOV(45);
    _camera.SetMovingScale(0.1f);
    
    if( ! _light.Init() ) {
        // error!
    }
    _light.SetPosition(glm::vec3(0, 0, 50));
    _light.SetAmbient(0.01f, 0.01f, 0.01f);
    _light.SetDiffuse(0.0f, 0.0f, 0.0f);
    _light.SetSpecular(0.0f, 0.0f, 0.0f);
    _light.SetAttenuation(GL_CONSTANT_ATTENUATION, 0.0f);
    _light.SetAttenuation(GL_LINEAR_ATTENUATION, 0.0001f);
    _light.SetAttenuation(GL_QUADRATIC_ATTENUATION, 0.000001f);
}

void Player::Update(float dt)
{
    Node::Update(dt);
    
    if( glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS ) {
        _camera.Move(LEFT);
    }
    if( glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS ) {
        _camera.Move(RIGHT);
    }
    if( glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS ) {
        _camera.Move(FORWARD);
    }
    if( glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS ) {
        _camera.Move(BACK);
    }
    if( glfwGetKey(_window, GLFW_KEY_LEFT) == GLFW_PRESS ) {
        _camera.ChangeHeading( _camera.camera_heading + 0.05f );
    }
    if( glfwGetKey(_window, GLFW_KEY_RIGHT) == GLFW_PRESS ) {
        _camera.ChangeHeading( _camera.camera_heading - 0.05f );
    }
    if( glfwGetKey(_window, GLFW_KEY_UP) == GLFW_PRESS ) {
        _camera.ChangePitch( _camera.camera_pitch + 0.05f );
    }
    if( glfwGetKey(_window, GLFW_KEY_DOWN) == GLFW_PRESS ) {
        _camera.ChangePitch( _camera.camera_pitch - 0.05f );
    }
    
    SetPosition(_camera.camera_position);
    SetRotation(glm::quat(_camera.camera_look_at));
    _light.SetPosition(_camera.camera_position);
}

void Player::Draw()
{
    _light.Draw();
    
    glm::vec3 forward = GetForward();
    glm::vec3 blindPos = GetPosition() + forward * -100.0f;
    
    PrintVector3(forward);
    
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(blindPos.x - 100, blindPos.y - 100, blindPos.z);
    glVertex3f(blindPos.x + 100, blindPos.y - 100, blindPos.z);
    glVertex3f(blindPos.x + 100, blindPos.y + 100, blindPos.z);
    glVertex3f(blindPos.x - 100, blindPos.y + 100, blindPos.z);
    glEnd();
}

void Player::KeyEvent(int key, int scancode, int action, int mods)
{
    if( key == GLFW_KEY_SPACE && action == GLFW_RELEASE ) {
        Fire();
    }
    
    if( key == GLFW_KEY_G && action == GLFW_RELEASE ) {
        Looting();
    }
}

void Player::Fire()
{
    if( _remainBullet <= 0 ) {
        return;
    }
    
    _remainBullet--;
    ProjectileManager::GetInstance()->CreateBullet(_position + _camera.camera_direction * 0.2f, _camera.camera_direction);
}

void Player::Looting()
{
    Item *item = ItemManager::GetInstance()->Looting(GetPosition());
    if( item == NULL ) {
        return;
    }
    
    item->Use(this);
    
    cout << _remainBullet << endl;
}

void Player::IncreaseBullet(int count)
{
    _remainBullet += count;
}