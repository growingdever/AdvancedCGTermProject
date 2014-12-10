//
//  Node.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "Node.h"
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Node::Node()
: _up(0, 1, 0)
, _forward(0, 0, -1)
{
}

Node::~Node()
{
    
}

bool Node::Init()
{
    SetPosition(glm::vec3());
    SetRotation(glm::vec3());

    return true;
}

void Node::Update(float dt)
{
    
}

void Node::Draw()
{
    
}

glm::vec3 Node::GetPosition()
{
    return _position;
}

void Node::SetPosition(const glm::vec3& vec)
{
    _position = vec;
}

glm::vec3 Node::GetRotation()
{
    return _rotation;
}

void Node::SetRotation(const glm::vec3& eulerDegree)
{
    _rotation = eulerDegree;
    if( _rotation.x > 360 ) {
        _rotation.x -= 360;
    } else if( _rotation.x < -360 ) {
        _rotation.x += 360;
    }
    if( _rotation.y > 360 ) {
        _rotation.y -= 360;
    } else if( _rotation.x < -360 ) {
        _rotation.y += 360;
    }
    if( _rotation.z > 360 ) {
        _rotation.z -= 360;
    } else if( _rotation.x < -360 ) {
        _rotation.z += 360;
    }
    
    _quatRoll = glm::angleAxis(eulerDegree.x, glm::vec3(1, 0, 0));
    _quatYaw = glm::angleAxis(eulerDegree.y, glm::vec3(0, 1, 0));
    _quatPitch = glm::angleAxis(eulerDegree.z, glm::vec3(0, 0, 1));
    glm::quat temp = _quatRoll * _quatYaw * _quatPitch;
    
    _forward = glm::vec3(0, 0, -1) * temp;
    _up = glm::vec3(0, 1, 0) * temp;
    
    _forward = glm::normalize(_forward);
    _up = glm::normalize(_up);
}
