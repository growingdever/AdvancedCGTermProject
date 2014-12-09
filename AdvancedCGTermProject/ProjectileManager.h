//
//  ProjectileManager.h
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#ifndef __AdvancedCGTermProject__ProjectileManager__
#define __AdvancedCGTermProject__ProjectileManager__

#include <glm/glm.hpp>
#include <vector>


class Bullet;
class ProjectileManager {
private:
    static ProjectileManager *_instance;
    
    std::vector< std::pair<Bullet*, float> > _bullets;
    
private:
    ProjectileManager();
    
public:
    static ProjectileManager* GetInstance() {
        if( _instance == NULL ) {
            _instance = new ProjectileManager();
        }
        
        return _instance;
    }
    
    ~ProjectileManager();
    
    void Update(float dt);
    void Draw();
    void CreateBullet(glm::vec3 pos, glm::vec3 dir);
    const std::vector< std::pair<Bullet*, float> >& GetBullets();
};

#endif /* defined(__AdvancedCGTermProject__ProjectileManager__) */
