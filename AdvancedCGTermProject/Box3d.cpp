//
//  Box3d.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 11..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "Box3d.h"
#include "Macro.h"


Box3d::Box3d(glm::vec3 start, glm::vec3 end)
: _start(start)
, _end(end)
{
    _width = _end.x - _start.x;
    _height = _end.y - _start.y;
    _length = _end.z - _start.z;
    
    MoveTo(glm::vec3());
}

Box3d::~Box3d()
{
    
}

void Box3d::MoveTo(const glm::vec3& position)
{
    _start.x = position.x - _width/2;
    _start.y = position.y - _height/2;
    _start.z = position.z - _length/2;
    _end.x = position.x + _width/2;
    _end.y = position.y + _height/2;
    _end.z = position.z + _length/2;
}

bool Box3d::Intersection(const Box3d &comp)
{
    return Box3d::Intersection(*this, comp);
}

bool Box3d::Intersection(const Box3d& box1, const Box3d& box2)
{
    return (box1._end.x >= box2._start.x &&
            box1._start.x <= box2._end.x &&
            box1._end.y >= box2._start.y &&
            box1._start.y <= box2._end.y &&
            box1._end.z >= box2._start.z &&
            box1._start.z <= box2._end.z);
}