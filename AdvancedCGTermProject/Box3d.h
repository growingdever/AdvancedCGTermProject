//
//  Box3d.h
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 11..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#ifndef __AdvancedCGTermProject__Box3d__
#define __AdvancedCGTermProject__Box3d__

#include <glm/glm.hpp>
#include <vector>


class Box3d {
private:
    glm::vec3 _start;
    glm::vec3 _end;
    float _width, _height, _length;
    
public:
    Box3d(glm::vec3 start, glm::vec3 end);
    ~Box3d();
    
    void MoveTo(const glm::vec3& position);
    
    bool Intersection(const Box3d& comp);
    static bool Intersection(const Box3d& box1, const Box3d& box2);
};

#endif /* defined(__AdvancedCGTermProject__Box3d__) */
