//
//  Player.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "Player.h"
#include "ProjectileManager.h"

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
    _light.SetEnabled(true);
    _light.SetAmbient(0.3f, 0.3f, 0.3f);
    _light.SetDiffuse(0.2f, 0.2f, 0.2f);
    _light.SetAttenuation(GL_LINEAR_ATTENUATION, 1.5f);
}

void Player::Update(float dt)
{
    _camera.Update();
    _position = _camera.camera_position;
    _light.SetPosition(_position);
    
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
}

void Player::Draw()
{
    _light.Draw();
}

void Player::KeyEvent(int key, int scancode, int action, int mods)
{
    if( key == GLFW_KEY_SPACE && action == GLFW_RELEASE ) {
        Fire();
    }
}

void Player::Fire()
{
    
    ProjectileManager::GetInstance()->CreateBullet(_camera.camera_position + _camera.camera_direction * 0.2f, _camera.camera_direction);
}