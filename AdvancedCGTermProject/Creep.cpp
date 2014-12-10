//
//  Creep.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 10..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "Creep.h"
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

void Creep::Draw()
{
    glPushMatrix();
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