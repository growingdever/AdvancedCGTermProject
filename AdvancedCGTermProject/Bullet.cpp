//
//  Bullet.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "Bullet.h"


Bullet::Bullet(glm::vec3 position, glm::vec3 dir)
: _cube(1.5f)
, _dir( dir )
{
    _cube.SetColor(glm::vec3(0.17, 0.11, 0.07));
	SetPosition( position );
}

Bullet::~Bullet()
{

}

void Bullet::Update(float dt)
{
    _position += _dir * 200.0f * dt;
}

void Bullet::Draw()
{
    glPushMatrix();
    glTranslatef(_position.x, _position.y, _position.z);
    _cube.Draw();
    glPopMatrix();
}