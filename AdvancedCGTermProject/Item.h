//
//  Item.h
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 10..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#ifndef __AdvancedCGTermProject__Item__
#define __AdvancedCGTermProject__Item__

#include "Node.h"
#include "Player.h"
#include "Cube.h"


class Item : public Node {
private:
    Cube _cube;
    
public:
    Item();
    virtual ~Item();
    
    virtual void Draw();
    
    virtual void SetTexture(GLuint texture);
    virtual void Use(Player *player);
};

#endif /* defined(__AdvancedCGTermProject__Item__) */
