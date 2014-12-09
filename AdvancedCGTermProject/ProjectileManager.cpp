//
//  ProjectileManager.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "ProjectileManager.h"
#include "Bullet.h"

#include <iostream>

using namespace std;

ProjectileManager* ProjectileManager::_instance;


ProjectileManager::ProjectileManager()
{
    
}

ProjectileManager::~ProjectileManager()
{
    
}

void ProjectileManager::Update(float dt)
{
    std::cout << _bullets.size() << std::endl;
    
	int index = -1;
	for(unsigned int i = 0; i < _bullets.size(); i ++) {
		auto& p = _bullets[i];
        p.first->Update(dt);
		p.second -= dt;
		if( p.second < 0.0f ) {
			index = i;
		}
	}

	if( index != -1 ) {
		auto& p = _bullets[index];
		delete p.first;
        _bullets.erase( _bullets.begin() + index );
	}
}

void ProjectileManager::Draw()
{
    for(auto& p : _bullets) {
        p.first->Draw();
    }
}

void ProjectileManager::CreateBullet(glm::vec3 pos, glm::vec3 dir)
{
    glm::vec3 dirVec = dir / 20.0f;
    Bullet *bullet = new Bullet(pos, dirVec);
    auto p = pair<Bullet*, float>(bullet, 5.0f);
    _bullets.push_back(p);
}

const std::vector< std::pair<Bullet*, float> >& ProjectileManager::GetBullets()
{
    return _bullets;
}