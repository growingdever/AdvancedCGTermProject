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
#include "Box3d.h"
#include <glm/glm.hpp>
#include <vector>
#include <string>


class Creep : public Node {
private:
    std::vector< Cube > _cubes;
    std::vector< glm::vec3 > _particleDirs;
    Box3d _boundingBox;
    float _boundingBoxSizeWidth;
    float _boundingBoxSizeHeight;
    float _boundingBoxSizeLength;
    
    bool _isDead = false;
    float _removeTimer = 5.0f;
    float _rotSpeed = 30.0f;
    
public:
    Creep();
    virtual ~Creep();
    virtual bool InitWithFile(std::string path);
    virtual void Update(float dt);
    virtual void Draw();
    
    virtual void Destroy();
    virtual void Divide();

    Box3d BoundingBox();
    bool IsDead() {
        return _isDead;
    }
};

#endif /* defined(__AdvancedCGTermProject__Creep__) */
