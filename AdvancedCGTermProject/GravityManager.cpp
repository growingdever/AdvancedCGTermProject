//
//  GravityManager.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 11..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "GravityManager.h"
#include <algorithm>

GravityManager* GravityManager::_instance;


GravityManager::GravityManager()
{
    
}

GravityManager::~GravityManager()
{
    
}

void GravityManager::Update(float dt)
{
    for(auto& node : _nodes) {
        glm::vec3 pos = node->GetPosition();
        pos.y = pos.y * 0.89;
        node->SetPosition(pos);
    }
}

void GravityManager::AddNode(Node *node)
{
    auto it = std::find(_nodes.begin(), _nodes.end(), node);
    if( it == _nodes.end() ) {
        _nodes.push_back(node);
    }
}

void GravityManager::RemoveNode(Node *node)
{
    auto it = std::find(_nodes.begin(), _nodes.end(), node);
    if( it != _nodes.end() ) {
        _nodes.erase(it);
    }
}