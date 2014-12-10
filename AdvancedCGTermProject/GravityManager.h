//
//  GravityManager.h
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 11..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#ifndef __AdvancedCGTermProject__GravityManager__
#define __AdvancedCGTermProject__GravityManager__

#include "Node.h"
#include <glm/glm.hpp>
#include <vector>


class GravityManager {
private:
    static GravityManager *_instance;
    
    std::vector<Node*> _nodes;
    
    
private:
    GravityManager();
    
public:
    static GravityManager* GetInstance() {
        if( _instance == NULL ) {
            _instance = new GravityManager();
        }
        
        return _instance;
    }
    
    ~GravityManager();
    
    void Update(float dt);
    void AddNode(Node *node);
    void RemoveNode(Node *node);
};

#endif /* defined(__AdvancedCGTermProject__GravityManager__) */
