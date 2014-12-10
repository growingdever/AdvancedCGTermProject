//
//  Node.h
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#ifndef __AdvancedCGTermProject__Node__
#define __AdvancedCGTermProject__Node__

#include <glm/glm.hpp>


class Node {
protected:
    glm::vec3 _position;
    glm::vec3 _scale;
    glm::vec3 _rotation;
    glm::vec3 _up;
    glm::vec3 _forward;
    
    
public:
    Node();
    virtual ~Node();
    
    virtual bool Init();
    virtual void Update(float dt);
    virtual void Draw();
    
    glm::vec3 GetPosition();
    virtual void SetPosition(const glm::vec3& pos);
    
    glm::vec3 GetRotation();
    virtual void SetRotation(const glm::vec3& rot);
};

#endif /* defined(__AdvancedCGTermProject__Node__) */
