//
//  ItemBullet.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 10..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "ItemBullet.h"


ItemBullet::ItemBullet()
{
    
}

ItemBullet::~ItemBullet()
{
    
}

bool ItemBullet::Init()
{
    if( ! Item::Init() ) {
        return false;
    }
    
    return true;
}

void ItemBullet::Use(Player *player)
{
    player->IncreaseBullet( 5 );
    
    Item::Use(player);
}