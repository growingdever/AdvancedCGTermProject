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
: _cube(8.0f)
{
    _cube.SetPosition(glm::vec3(0, _cube.GetLength()/2, 0));
}

Item::~Item()
{
    
}

void Item::Draw()
{
    glPushMatrix();
    {
        glTranslated(_position.x, _position.y + _cube.GetPosition().y, _position.z);
        _cube.Draw();
    }
    glPopMatrix();
}

void Item::SetTexture(GLuint texture)
{
    _cube.SetTexture(texture);
}

void Item::Use(Player *player)
{
    ItemManager::GetInstance()->RemoveItem(this);
}