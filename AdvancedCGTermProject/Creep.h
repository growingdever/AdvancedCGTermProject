//
//  Creep.h
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 10..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#ifndef __AdvancedCGTermProject__Creep__
#define __AdvancedCGTermProject__Creep__

#include "Node.h"
#include "Cube.h"
#include <glm/glm.hpp>
#include <vector>
#include <string>


class Creep : public Node {
private:
    std::vector< Cube > _cubes;
    std::vector< glm::vec3 > _particleDirs;
    
    bool _isDead = false;
    float _removeTimer = 3.0f;
    
public:
    Creep();
    virtual ~Creep();
    virtual bool InitWithFile(std::string path);
    virtual void Update(float dt);
    virtual void Draw();
    
    virtual void Destroy();
};

#endif /* defined(__AdvancedCGTermProject__Creep__) */
