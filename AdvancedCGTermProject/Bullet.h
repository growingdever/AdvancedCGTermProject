//
//  Bullet.h
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#ifndef __AdvancedCGTermProject__Bullet__
#define __AdvancedCGTermProject__Bullet__

#include "Node.h"
#include "Cube.h"
#include "Box3d.h"


class Bullet : public Node {
private:
    const float SIZE = 1.5f;
    Cube _cube;
    glm::vec3 _dir;
    Box3d _boundingBox;
    
    
public:
    Bullet(glm::vec3 position, glm::vec3 dir);
    virtual ~Bullet();
    
    virtual void Update(float dt);
    virtual void Draw();
    
    Box3d BoundingBox();
    
};

#endif /* defined(__AdvancedCGTermProject__Bullet__) */
