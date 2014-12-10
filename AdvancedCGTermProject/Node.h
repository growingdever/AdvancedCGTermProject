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
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>


class Node {
protected:
    glm::vec3 _position;
    glm::vec3 _scale;
    glm::vec3 _rotation;
    glm::vec3 _up;
    glm::vec3 _forward;
    
    glm::quat _quatRoll;
    glm::quat _quatYaw;
    glm::quat _quatPitch;
    
    
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
    
    glm::quat GetRoll() {
        return _quatRoll;
    }
    glm::quat GetYaw() {
        return _quatYaw;
    }
    glm::quat GetPitch() {
        return _quatPitch;
    }
};

#endif /* defined(__AdvancedCGTermProject__Node__) */
