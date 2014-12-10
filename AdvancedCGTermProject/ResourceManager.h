//
//  ResourceManager.h
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 10..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#ifndef __AdvancedCGTermProject__ResourceManager__
#define __AdvancedCGTermProject__ResourceManager__

#include <GLUT/GLUT.h>
#include <map>
#include <string>


class ResourceManager {
private:
    static ResourceManager *_instance;
    
    std::map< std::string, GLuint > _textures;
    
private:
    ResourceManager();
    
public:
    static ResourceManager* GetInstance() {
        if( _instance == NULL ) {
            _instance = new ResourceManager();
        }
        
        return _instance;
    }
    
    ~ResourceManager();
    
    void LoadTexture(std::string key, std::string path);
    GLuint GetTexture(std::string key);

private:
    void LoadTGA(std::string key, std::string path);
    
};


#endif /* defined(__AdvancedCGTermProject__ResourceManager__) */
