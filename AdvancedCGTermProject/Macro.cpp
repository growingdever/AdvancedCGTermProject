//
//  Macro.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 10..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "Macro.h"


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