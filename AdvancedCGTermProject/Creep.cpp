//
//  Creep.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 10..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "Creep.h"
#include "CreepManager.h"
#include "Macro.h"
#include <glm/glm.hpp>
#include <fstream>
using namespace std;


Creep::Creep()
{
    
}

Creep::~Creep()
{
    
}

bool Creep::InitWithFile(std::string path)
{
    if( ! Node::Init() ) {
        return false;
    }
    
    int n;
    ifstream ifs(path.c_str(), ios::in);
    ifs >> n;
    for( int i = 0; i < n; i ++ ) {
        int size;
        glm::vec3 pos, color;
        ifs >> size;
        ifs >> pos.x >> pos.y >> pos.z;
        ifs >> color.x >> color.y >> color.z;
        
        Cube cube(size);
        cube.SetPosition(pos);
        cube.SetColor(color);
        
        _cubes.push_back(cube);
    }
    
    return true;
}

void Creep::Update(float dt)
{
    Node::Update(dt);
    
    if( _isDead ) {
        for( unsigned int i = 0; i < _cubes.size(); i ++ ) {
            auto &cube = _cubes[i];
            auto pos = cube.GetPosition();
            glm::vec3 &dir = _particleDirs[i];
            dir *= 0.95;
            cube.SetPosition(pos + dir);
        }
        
        _removeTimer -= dt;
        if( _removeTimer < 0 ) {
            CreepManager::GetInstance()->RemoveCreep(this);
        }
    }
}

void Creep::Draw()
{
    glm::vec3 forward = GetForward();
    glm::vec3 up = GetUp();
    
    glm::vec3 p2 = _position + forward * 15.0f;
    glm::vec3 p3 = _position + up * 15.0f;
    
    glPointSize(20.0f);
    
    glBegin(GL_LINES);
    glVertex3f(_position.x, _position.y, _position.z);
    glVertex3f(p2.x, p2.y, p2.z);
    glVertex3f(_position.x, _position.y, _position.z);
    glVertex3f(p3.x, p3.y, p3.z);
    glEnd();
    
    glBegin(GL_POINTS);
    glVertex3f(p2.x, p2.y, p2.z);
    glVertex3f(p3.x, p3.y, p3.z);
    glEnd();
    
    glm::vec3 axis = glm::axis(_rotation);
    float angle = glm::angle(_rotation);
    
    glPushMatrix();
    glRotatef(angle, axis.x, axis.y, axis.z);
    glTranslatef(_position.x, _position.y, _position.z);
    for(auto& cube : _cubes) {
        glm::vec3 pos = cube.GetPosition();
        
        glPushMatrix();
        glTranslatef(pos.x, pos.y, pos.z);
        cube.Draw();
        glPopMatrix();
    }
    glPopMatrix();
}

void Creep::Destroy()
{
    _isDead = true;
    
    for(auto& cube : _cubes) {
        auto pos = cube.GetPosition();
        glm::vec3 dir = glm::normalize(pos - _position);
        dir.x += RandomRangeDouble(-2, 2);
        dir.y += RandomRangeDouble(-2, 2);
        dir.z += RandomRangeDouble(-2, 2);
        dir *= 1.0f;
        _particleDirs.push_back(dir);
    }
}