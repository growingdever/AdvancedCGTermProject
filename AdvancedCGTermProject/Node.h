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
    glm::quat _rotation;
    
    
public:
    Node();
    virtual ~Node();
    
    virtual bool Init();
    virtual void Update(float dt);
    virtual void Draw();
    
    virtual glm::vec3 GetPosition();
    virtual void SetPosition(const glm::vec3& pos);
    virtual glm::vec3 GetForward();
    virtual glm::vec3 GetUp();
    
    virtual glm::quat GetRotation();
    virtual void SetRotation(const glm::quat& rot);
    virtual void Rotate(const float angle, const glm::vec3& axis);
    virtual void RotateX(const float angle);
    virtual void RotateY(const float angle);
    virtual void RotateZ(const float angle);
};

#endif /* defined(__AdvancedCGTermProject__Node__) */
