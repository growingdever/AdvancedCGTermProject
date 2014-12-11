//
//  Cube.h
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#ifndef __AdvancedCGTermProject__Cube__
#define __AdvancedCGTermProject__Cube__

#include "Node.h"
#include <GLUT/GLUT.h>
#include <glm/glm.hpp>
#include <vector>

class Cube : public Node {
private:
    GLuint _texture;
    float _length;
    std::vector<glm::vec3> _vertices;
    glm::vec3 _color;
    
    
public:
    Cube(float length);
    Cube(GLuint texture, float length);
    ~Cube();
    
    bool InitWithLength(float length);
    float GetLength() {
        return _length;
    }
    
    virtual void Draw();
    void DrawTextureBinded();
    void DrawTextureUnbinded();
    void VertexByVector3(const glm::vec3& pos);
    
    void SetTexture(GLuint texture);
    glm::vec3 GetColor() {
        return _color;
    }
    void SetColor(const glm::vec3& color);
};


#endif /* defined(__AdvancedCGTermProject__Cube__) */
