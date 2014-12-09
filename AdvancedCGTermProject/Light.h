//
//  Light.h
//  AdvancedCGTermProject
//
//  Created by loki on 2014. 12. 9..
//  Copyright (c) 2014년 loki. All rights reserved.
//

#ifndef __AdvancedCGTermProject__Light__
#define __AdvancedCGTermProject__Light__

#include <GLUT/GLUT.h>
#include "Node.h"


class Light : public Node {
public:
    static const int ATTENUATION_TYPE_CONSTANT = 0;
    static const int ATTENUATION_TYPE_LINEAR = 1;
    static const int ATTENUATION_TYPE_QUADRATIC = 2;

    
private:
    bool enable = false;
	GLuint LightID = 0;
	GLfloat LightAmbient[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat LightDiffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat LightSpecular[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat LightAttenuation[3] = { 1.0f, 0.0f, 0.0f };
	float LightPosition[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

public:
	Light(GLuint id);
	virtual bool Init();
    virtual void Draw();
    virtual void SetPosition(const glm::vec3& vec);
    void SetEnabled(bool enable);
    void SetAmbient(float r, float g, float b, float a = 1.0f);
    void SetDiffuse(float r, float g, float b, float a = 1.0f);
    void SetAttenuation(GLuint attenuationType, float d);

    GLfloat* GetAmbient();
    GLfloat* GetDeffuse();
    GLfloat* GetSpecular();
    GLfloat GetAttenuation(GLuint attenuationType);
};

#endif /* defined(__AdvancedCGTermProject__Light__) */
