//
//  ItemManager.h
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 10..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#ifndef __AdvancedCGTermProject__ItemManager__
#define __AdvancedCGTermProject__ItemManager__

#include <glm/glm.hpp>
#include <vector>

#include "Item.h"
#include "ItemBullet.h"


class ItemManager {
private:
    static ItemManager *_instance;
    
    std::vector<Item*> _items;
    
    
private:
    ItemManager();
    
public:
    static ItemManager* GetInstance() {
        if( _instance == NULL ) {
            _instance = new ItemManager();
        }
        
        return _instance;
    }
    
    ~ItemManager();
    
    void Update(float dt);
    void Draw();
    void GenerateItem();
    void RemoveItem(Item *item);
    Item* Looting(glm::vec3 position);
};


#endif /* defined(__AdvancedCGTermProject__ItemManager__) */
