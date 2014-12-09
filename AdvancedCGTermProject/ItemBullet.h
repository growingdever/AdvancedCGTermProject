//
//  ItemBullet.h
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 10..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#ifndef __AdvancedCGTermProject__ItemBullet__
#define __AdvancedCGTermProject__ItemBullet__

#include "Item.h"


class ItemBullet : public Item {
public:
    ItemBullet();
    virtual ~ItemBullet();
    
    virtual bool Init();
    virtual void Use(Player *player);
};

#endif /* defined(__AdvancedCGTermProject__ItemBullet__) */
