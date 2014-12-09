//
//  ItemManager.cpp
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 10..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#include "ItemManager.h"
#include "Macro.h"

using namespace std;


ItemManager* ItemManager::_instance;


ItemManager::ItemManager()
{
    
}

ItemManager::~ItemManager()
{
    
}

void ItemManager::Update(float dt)
{
    if( _items.size() <= 0 ) {
        GenerateItem();
    }
    
    for(auto& item : _items) {
        item->Update(dt);
    }
}

void ItemManager::Draw()
{
    for(auto& item : _items) {
        item->Draw();
    }
}

void ItemManager::GenerateItem()
{
    glm::vec3 newPos;
    newPos.x = RandomRangeDouble(-10, 10);
    newPos.z = RandomRangeDouble(-10, 10);
    
    Item *item = new ItemBullet;
    item->SetPosition(newPos);
    _items.push_back(item);
}

void ItemManager::RemoveItem(Item *item)
{
    auto it = _items.begin();
    for( ; it != _items.end(); ++it ) {
        if( (*it) == item ) {
            delete (*it);
            _items.erase(it);
            break;
        }
    }
}

Item* ItemManager::Looting(glm::vec3 position)
{
    for(auto& item : _items) {
        glm::vec3 dist = position - item->GetPosition();
        if( dist.length() <= 10 ) {
            return item;
        }
    }
    
    return NULL;
}