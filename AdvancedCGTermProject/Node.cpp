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

#define Forward3 glm::vec3(0, 0, -1)
#define Forward4 glm::vec4(0, 0, -1, 1)
#define Up3 glm::vec3(0, 1, 0)
#define Up4 glm::vec4(0, 1, 0, 1)


Node::Node()
{
    
}

Node::~Node()
{
    
}

bool Node::Init()
{
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

glm::vec3 Node::GetForward()
{
    glm::vec3 forward = glm::rotate(_rotation, Forward3);
    forward = glm::normalize(forward);
    return forward;
}

glm::vec3 Node::GetUp()
{
    glm::vec3 up = glm::rotate(_rotation, Up3);
    up = glm::normalize(up);
    return up;
}

glm::quat Node::GetRotation()
{
    return _rotation;
}

void Node::SetRotation(const glm::quat& rotation)
{
    _rotation = rotation;
    _rotation = glm::normalize(_rotation);
}

void Node::Rotate(const float angle, const glm::vec3 &axis)
{
    _rotation = glm::rotate(_rotation, angle, axis);
}

void Node::RotateX(const float angle)
{
    Rotate(angle, glm::vec3(1, 0, 0));
}

void Node::RotateY(const float angle)
{
    Rotate(angle, glm::vec3(0, 1, 0));
}

void Node::RotateZ(const float angle)
{
    Rotate(angle, glm::vec3(0, 0, 1));
}
