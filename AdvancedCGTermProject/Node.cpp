//
//  Node.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "Node.h"


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

glm::vec3 Node::GetRotation()
{
    return _rotation;
}

void Node::SetRotation(const glm::vec3& vec)
{
    _rotation = vec;
}
