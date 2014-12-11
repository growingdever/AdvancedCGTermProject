//
//  CreepManager.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 11..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "CreepManager.h"
#include "Macro.h"
#include "GravityManager.h"
#include "ProjectileManager.h"
#include "Bullet.h"
#include "Box3d.h"
#include <string>
#include <algorithm>


CreepManager* CreepManager::_instance;


CreepManager::CreepManager()
{
    
}

CreepManager::~CreepManager()
{
    
}

void CreepManager::Update(float dt)
{
    if( _nodes.size() < 1 ) {
        CreateCreep();
    }
    
    if( _nodes.size() <= 0 ) {
        return;
    }
    
    auto bullets = ProjectileManager::GetInstance()->GetBullets();
    
    for(auto& node : _nodes) {
        glm::vec3 pos = node->GetPosition();
        Box3d boundingBoxNode = node->BoundingBox();
        for(auto it = bullets.begin(); it != bullets.end(); ++it) {
            Bullet *bullet = it->first;
            Box3d boundingBoxBullet = bullet->BoundingBox();
            if( boundingBoxBullet.Intersection(boundingBoxNode) ) {
                ProjectileManager::GetInstance()->RemoveBullet(bullet);
                node->Destroy();
                return;
            }
        }
        
        glm::vec3 dir = player->GetPosition() - pos;
        dir.y = 0.0f;
        dir = glm::normalize(player->GetPosition() - pos);
        node->SetPosition(pos + dir * 5.0f * dt);

        node->Update(dt);
    }
}

void CreepManager::Draw()
{
    for(auto& node : _nodes) {
        node->Draw();
    }
}

void CreepManager::CreateCreep()
{
    Creep *creep = new Creep;
    std::string path;
    int type = RandomRangeInt(0, 2);
    if( type == 0 ) {
        path = "Data/CreepFirst.txt";
    } else if( type == 1 ) {
        path = "Data/CreepSecond.txt";
    } else {
        path = "Data/CreepThird.txt";
    }

    creep->InitWithFile(path);
//    creep->SetPosition(glm::vec3( RandomRangeDouble(-500, 500), 0, RandomRangeDouble(-500, 500) ));
    _nodes.push_back(creep);
    
    GravityManager::GetInstance()->AddNode(creep);
}

void CreepManager::RemoveCreep(Creep *node)
{
    auto it = std::find(_nodes.begin(), _nodes.end(), node);
    if( it != _nodes.end() ) {
        auto creep = (*it);
        GravityManager::GetInstance()->RemoveNode(creep);
        
        delete creep;
        _nodes.erase(it);
    }
}