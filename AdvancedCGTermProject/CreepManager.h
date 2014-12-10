//
//  CreepManager.h
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 11..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#ifndef __AdvancedCGTermProject__CreepManager__
#define __AdvancedCGTermProject__CreepManager__

#include "Creep.h"
#include "Player.h"
#include <glm/glm.hpp>
#include <vector>


class CreepManager {
private:
    static CreepManager *_instance;
    
    Player *player;
    
    std::vector<Creep*> _nodes;
    std::vector<float> _timers;
    
    
private:
    CreepManager();
    
public:
    static CreepManager* GetInstance() {
        if( _instance == NULL ) {
            _instance = new CreepManager();
        }
        
        return _instance;
    }
    
    ~CreepManager();
    
    void SetPlayer(Player *player) {
        this->player = player;
    }
    
    void Update(float dt);
    void Draw();
    void CreateCreep();
    void RemoveCreep(Creep *node);
};


#endif /* defined(__AdvancedCGTermProject__CreepManager__) */
