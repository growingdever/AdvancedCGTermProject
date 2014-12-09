//
//  Item.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 10..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "Item.h"
#include "ItemManager.h"


Item::Item()
: _cube(5.0f)
{
    
}

Item::~Item()
{
    
}

void Item::Draw()
{
    glPushMatrix();
    {
        glTranslated(_position.x, _position.y, _position.z);
        _cube.Draw();
    }
    glPopMatrix();
}

void Item::Use(Player *player)
{
    ItemManager::GetInstance()->RemoveItem(this);
}