//
//  Macro.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 10..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "Macro.h"
#include <iostream>
#include <iomanip>


double Random0to1()
{
    return ((double) rand() / (RAND_MAX));
}

double RandomRangeDouble(double start, double end)
{
    double length = (end - start);
    return Random0to1() * length - length/2;
}

int RandomRangeInt(int start, int end)
{
    int length = (end - start);
    int n = rand() % length;
    
    return n + start;
}

void PrintVector(glm::vec3 vector)
{
    std::cout << std::setw(8) << std::setprecision(3) << vector.x << std::setw(8) << std::setprecision(3) << vector.y << std::setw(8) << std::setprecision(3) << vector.z << std::endl;
}