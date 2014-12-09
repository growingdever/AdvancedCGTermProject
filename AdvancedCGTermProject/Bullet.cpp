//
//  Bullet.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "Bullet.h"


Bullet::Bullet(glm::vec3 position, glm::vec3 dir)
: _cube(0.05f)
, _dir( dir )
{
	SetPosition( position );
}

Bullet::~Bullet()
{

}

void Bullet::Update(float dt)
{
    _position += _dir;
}

void Bullet::Draw()
{
    glPushMatrix();
    glTranslatef(_position.x, _position.y, _position.z);
    _cube.Draw();
    glPopMatrix();
}